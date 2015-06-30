from ROOT import TH1F,TFile,kRed,kBlue,kGreen,kGray,kBlack,kOrange,TLegend,TCanvas,gROOT

#f=TFile("/scratch/hh/dust/naf/cms/user/usai/ExampleCycle2.MC.TTbarsemi.root","read")
#outfile=TFile("weight.root", "RECREATE")
#wb=f.Get('NoCuts/weight_b').Clone()
#wb.Divide(f.Get('BeforeNoCuts/weight_b'))
#wb.Write()
gROOT.SetBatch()
f2=TFile("/afs/naf.desy.de/user/u/usai/scratch/sw/SFrame/SFrameAnalysis/subjethistos_beforenocut.root","read")
f1=TFile("/afs/naf.desy.de/user/u/usai/scratch/sw/SFrame/SFrameAnalysis/subjethistos_nocut.root","read")

histogram_names = ["subCSV","subFlavour","subTrackMomentum","subTrackEta","subTrackEtaRel","subTrackDeltaR","subTrackSip3dVal","subTrackSip3dSig","subTrackSip2dVal","subTrackSip2dSig","subTrackDecayLenVal","subTrackChi2","subTrackNTotalHits","subTrackNPixelHits","subTrackPtRel","subTrackPPar","subTrackPtRatio","subTrackPParRatio","subTrackJetDistVal","subTrackJetDistSig","subTrackGhostTrackDistVal","subTrackGhostTrackDistSig","subTrackGhostTrackWeight","subFlightDistance2dVal","subFlightDistance2dSig","subFlightDistance3dVal","subFlightDistance3dSig","subVertexJetDeltaR","subJetNSecondaryVertices","subVertexNTracks","subSecondaryVertex","subVertexChi2","subVertexNdof","subVertexNormalizedChi2","subVertexTracksSize","subVertexCategoryJTC","subVertexMassJTC","subVertexEnergyRatioJTC","subTrackSip3dSigAboveCharmJTC"]
histogram_descriptions = ["combined secondary vertex discriminator of the subjet","matched flavour of the subjet","momentum of tracks in the subjet","pseudorapidity of tracks in the subjet","track pseudorapidity, relative to the jet axis","track pseudoangular distance from the jet axis","track 3D signed impact parameter","track 3D signed impact parameter significance","track 2D signed impact parameter","track 2D signed impact parameter significance","track decay length","track fit chi2","number of valid total hits","number of valid pixel hits","track transverse momentum, relative to the jet axis","track parallel momentum, along the jet axis","track transverse momentum, relative to the jet axis, normalized to its energy","track parallel momentum, along the jet axis, normalized to its energy","minimum track approach distance to jet axis","minimum track approach distance to jet axis significance","minimum approach distance to ghost track","minimum approach distance to ghost track significance","weight of track\
participation in ghost track fit","transverse distance between primary and secondary vertex","transverse distance significance between primary and secondary vertex","distance between primary and secondary vertex","distance significance between primary and secondary vertex","pseudoangular distance between jet axis and secondary vertex direction","number of reconstructed possible secondary vertices in jet","number of tracks at secondary vertex","secondary vertex uncorrected mass","secondary vertex chi2","secondary vertex fit dergrees of frendom","secondary vertex fit normalized chi2","secondary vertex tracks collection size","secondary vertex category from jet tag computer","secondary vertex corrected mass from jet tag computer","ratio of energy at secondary vertex over total energy from JTC","track 3D signed impact parameter significance of first track lifting mass above charm from JTC"]
outfile=TFile("weight.root", "RECREATE")
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  h1=f1.Get(histogram_name+'_Add')
  h1.SetTitle(histogram_descriptions[histogram_name_index])
  h2=f2.Get(histogram_name+'_Add')
  h2.SetTitle(histogram_descriptions[histogram_name_index])
  h3=f2.Get(histogram_name+'_data')
  h3.SetTitle(histogram_descriptions[histogram_name_index])
  h4=h1.Clone(histogram_name+"_Ratio")
  h4.SetTitle(histogram_descriptions[histogram_name_index]+' SF ratio')
  h4.Divide(h2)
  h4.Write()
  h4canvas=TCanvas(histogram_name+'_h4',histogram_name+'_h4')
  h4.Draw()
  if histogram_name in ["subTrackMomentum","subTrackSip3dSig","subFlightDistance3dSig","subCSV"]: #["subTrackNPixelHits","subTrackMomentum","subTrackJetDistVal","subTrackDecayLenVal","subTrackSip3dVal","subTrackSip3dSig","subFlightDistance3dSig","subVertexMassJTC","subJetNSecondaryVertices","subVertexNTracks","subCSV"]:
    h4canvas.SaveAs(histogram_name+'_'+'Ratio.pdf')
  canvas=TCanvas(histogram_name,histogram_name)
  h1.SetLineColor(kBlue)
  h2.SetLineColor(kRed)
  h3.SetLineColor(kBlack)
  legend=TLegend(0.935,0.55,0.995,0.93)
  legend.AddEntry(h1,'btag sf','lpe')
  legend.AddEntry(h2,'no sf','lpe')
  legend.AddEntry(h3,'data','lpe')
  h1.Draw()
  h2.Draw('SAME')
  h3.Draw('SAME')
  legend.Draw()
  canvas.Write()
  if histogram_name in ["subTrackMomentum","subTrackSip3dSig","subFlightDistance3dSig","subCSV"]: #["subTrackNPixelHits","subTrackMomentum","subTrackJetDistVal","subTrackDecayLenVal","subTrackSip3dVal","subTrackSip3dSig","subFlightDistance3dSig","subVertexMassJTC","subJetNSecondaryVertices","subVertexNTracks","subCSV"]:
    canvas.SaveAs(histogram_name+'_'+'Same.pdf')