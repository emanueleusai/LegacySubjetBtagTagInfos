from ROOT import TFile,TH1F,THStack,TCanvas,TLegend,gROOT,kRed,kBlue,kGreen,kViolet,kGray,kBlack,kOrange,gStyle,kTRUE,TPaveStats

gROOT.SetBatch()
#gStyle.SetOptStat(111000010)
gStyle.SetOptStat('ioue')
#setup
flavour_names = ["b","c","uds","g","none"]
flavour_colors = [kRed,8,kBlue,kOrange-3,kGray]
process_names = ["MC.TTbarsemi"]
histogram_names = ["subCSV","subFlavour","subTrackMomentum","subTrackEta","subTrackEtaRel","subTrackDeltaR","subTrackSip3dVal","subTrackSip3dSig","subTrackSip2dVal","subTrackSip2dSig","subTrackDecayLenVal","subTrackChi2","subTrackNTotalHits","subTrackNPixelHits","subTrackPtRel","subTrackPPar","subTrackPtRatio","subTrackPParRatio","subTrackJetDistVal","subTrackJetDistSig","subTrackGhostTrackDistVal","subTrackGhostTrackDistSig","subTrackGhostTrackWeight","subFlightDistance2dVal","subFlightDistance2dSig","subFlightDistance3dVal","subFlightDistance3dSig","subVertexJetDeltaR","subJetNSecondaryVertices","subVertexNTracks","subSecondaryVertex","subVertexChi2","subVertexNdof","subVertexNormalizedChi2","subVertexTracksSize","subVertexCategoryJTC","subVertexMassJTC","subVertexEnergyRatioJTC","subTrackSip3dSigAboveCharmJTC"]
histogram_descriptions = ["combined secondary vertex discriminator of the subjet","matched flavour of the subjet","momentum of tracks in the subjet","pseudorapidity of tracks in the subjet","track pseudorapidity, relative to the jet axis","track pseudoangular distance from the jet axis","track 3D signed impact parameter","track 3D signed impact parameter significance","track 2D signed impact parameter","track 2D signed impact parameter significance","track decay length","track fit chi2","number of valid total hits","number of valid pixel hits","track transverse momentum, relative to the jet axis","track parallel momentum, along the jet axis","track transverse momentum, relative to the jet axis, normalized to its energy","track parallel momentum, along the jet axis, normalized to its energy","minimum track approach distance to jet axis","minimum track approach distance to jet axis significance","minimum approach distance to ghost track","minimum approach distance to ghost track significance","weight of track\
participation in ghost track fit","transverse distance between primary and secondary vertex","transverse distance significance between primary and secondary vertex","distance between primary and secondary vertex","distance significance between primary and secondary vertex","pseudoangular distance between jet axis and secondary vertex direction","number of reconstructed possible secondary vertices in jet","number of tracks at secondary vertex","secondary vertex uncorrected mass","secondary vertex chi2","secondary vertex fit dergrees of frendom","secondary vertex fit normalized chi2","secondary vertex tracks collection size","secondary vertex category from jet tag computer","secondary vertex corrected mass from jet tag computer","ratio of energy at secondary vertex over total energy from JTC","track 3D signed impact parameter significance of first track lifting mass above charm from JTC"]
yaxis_tracks = 'N of tracks'
yaxis_vertices = 'N of vertices'
yaxis_subjets = 'N of subjets'
histogram_yaxes = [yaxis_subjets for i in range(2)] + [yaxis_tracks for i in range(21)] + [yaxis_vertices for i in range(5)] + [yaxis_subjets] + [yaxis_vertices for i in range(6)] + [yaxis_vertices for i in range(4)]
histogram_xaxes = ["CSV discriminator", "particle ID", "p [GeV/c]", "#eta", "#Delta#eta(track,jet axis)", "#Delta#phi(track,jet axis)", "IP [cm]", "IP/#sigma_{IP}", "IP_{2D} [cm]", "IP_{2D}/#sigma_{IP_{2D}}", "L_{d} [cm]", "#chi^2_{track}", "N_{hits}", "N_{pixel hits}"," "," "," "," ","d [cm]"," "," "," "," ", "dist_T(SV_1,SV_2) [cm]", "dist_T/#sigma_{dist_T}(SV_1,SV_2)", "dist(SV_1,SV_2) [cm]", "dist/#sigma_{dist}(PV,SV)", "#Delta#phi", "N of vertices", "N tracks", "inv. mass [GeV/c^2]", "#chi^2_{SV}", "N_{dof}", "#chi^2/N_{dof}(SV)", "N tracks", "category", "inv. mass [GeV/c^{2}]", "E_{SV}/E_{tot}", "IP/#sigma_{IP}"]
files_path = "/scratch/hh/dust/naf/cms/user/usai/"
files_name_base = "ExampleCycle2"
cut_name = "NoCuts"

#get the files

#ttbar_file = TFile("/scratch/hh/dust/naf/cms/user/usai/ExampleCycle2.MC.TTbar.root","READ")
#ttbar_file.Get("NoCuts/subCSV_b")
#ttbar_histos = []

files_list=[]
for process_name in process_names:
    files_list.append(TFile(files_path+"/"+files_name_base+"."+process_name+".root"))

outfile=TFile("stackhistos.root", "RECREATE")


input_histos=[]
output_histos=[]
output_canvases=[]
for histo_file,process_name in zip(files_list,process_names):
    tmp_process_sublist=[]
    stack_process_sublist=[]
    stackcanvas_process_sublist=[]
    for histogram_name,histogram_description,histogram_yaxis,histogram_xaxis in zip(histogram_names,histogram_descriptions,histogram_yaxes,histogram_xaxes):
      tmp_histogram_sublist=[]
      tmp_stack=THStack(histogram_name+'_'+process_name.split('.')[-1]+'_'+'Stack','')
      tmp_legend=TLegend(0.905,0.6,0.995,0.9)#,histogram_name+'_'+process_name.split('.')[-1]+'_'+'CanvasLegend',histogram_name+' '+process_name.split('.')[-1])
      for flavour_name,flavour_color in zip(flavour_names,flavour_colors):
	#tmp_canvas_single=TCanvas(histogram_name+"_"+flavour_name+'_Canvas','')
	tmp_histogram_sublist.append(histo_file.Get(cut_name+"/"+histogram_name+"_"+flavour_name))#.Clone())
	tmp_histogram_sublist[-1].SetFillColor(flavour_color)
	#if flavour_name == 'g': tmp_histogram_sublist[-1].SetFillStyle(3001)
	tmp_histogram_sublist[-1].SetLineColor(kBlack)
	tmp_histogram_sublist[-1].SetMarkerColor(flavour_color)
	#tmp_histogram_sublist[-1].SetStats(kTRUE)
	#tmp_histogram_sublist[-1].Draw()
	#tmp_canvas_single.Write()
	#tmp_canvas_single.SaveAs(histogram_name+"_"+flavour_name+'_Canvas.pdf')
	tmp_stack.Add(tmp_histogram_sublist[-1])
	tmp_legend.AddEntry(tmp_histogram_sublist[-1],flavour_name,'f')
      tmp_process_sublist.append(tmp_histogram_sublist)
      stack_process_sublist.append(tmp_stack) 
      tmp_canvas=TCanvas(histogram_name+'_'+process_name.split('.')[-1]+'_'+'CanvasStack','')
      #tmp_canvas.cd()
      #tmp_histogram_sublist[-1].Draw('histo')
      tmp_stack.Draw('histo')
      tmp_stack.GetXaxis().SetTitle(histogram_xaxis)
      tmp_stack.GetYaxis().SetTitle(histogram_yaxis)
      tmp_stack.SetTitle(histogram_description)
      tmp_legend.Draw()
      #tmp_canvas.BuildLegend(0.2,0.2,0.8,0.8)#tmp_legend.Draw()
      #autolegend=tmp_canvas.BuildLegend()
      stackcanvas_process_sublist.append(tmp_canvas)
 #     outfile.Cd()
      if histogram_name in ["subTrackNPixelHits","subTrackMomentum","subTrackJetDistVal","subTrackDecayLenVal","subTrackSip3dVal","subTrackSip3dSig","subJetNSecondaryVertices","subCSV"]:
	tmp_canvas.SetLogy()
      tmp_canvas.Write()
      if histogram_name in ["subTrackNPixelHits","subTrackMomentum","subTrackJetDistVal","subTrackDecayLenVal","subTrackSip3dVal","subTrackSip3dSig","subFlightDistance3dSig","subVertexMassJTC","subJetNSecondaryVertices","subVertexNTracks","subCSV"]:
	tmp_canvas.SaveAs(histogram_name+'_'+process_name.split('.')[-1]+'_'+'CanvasStack.pdf')
      #tmp_stack.Write()
    input_histos.append(tmp_process_sublist)
    output_histos.append(stack_process_sublist)
    output_canvases.append(stackcanvas_process_sublist)
#            ttbar_histos.append()



outfile.Close()
#histos=[]
#loop sui processi
#tmp_process_sublist=[]#conterra' tutti i flavour per un dato processo
#loop flavour
#tmp_flavour_sublist=[]#conterra' tutti gli histo per un dato flavour


#tmp_process_sublist.append()
#fine loop flavour
#histos.append(tmp_process_sublist)#pusha il processo con tutti i flavour nella lista processi
#fine loop processo

#histos[process][flavour][histogram][][]

#parton stack

#merge files 

#process stack
