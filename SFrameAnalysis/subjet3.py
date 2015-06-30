from ROOT import TFile,TH1F,THStack,TCanvas,TLegend,TLatex,gROOT,kRed,kBlue,kGreen,kGray,kBlack,kOrange,gStyle,kTRUE,kFALSE,TLine
import sys
#setup
gROOT.SetBatch()
gStyle.SetOptStat('ioue')
#physics_names_mc = ['QCD','WW,WZ,ZZ','single-Top','Z+Jets','W+Jets','TTbarlept','TTbarhad','TTbarsemi']

process_names_mc = []
subprocess_names_mc = []
#QCD
#process_names_mc.append('QCD')
#subprocess_names_mc.append(["MC.QCD1000","MC.QCD120to170","MC.QCD170to300","MC.QCD300to470","MC.QCD470to600","MC.QCD50to80","MC.QCD600to800","MC.QCD800to1000","MC.QCD80to120"])
#WW,WZ,ZZ
process_names_mc.append('WW,WZ,ZZ')
subprocess_names_mc.append(["MC.doubleWW","MC.doubleWZ","MC.doubleZZ"])
#single-Top
process_names_mc.append('single-Top')
subprocess_names_mc.append(["MC.singleTbars","MC.singleTbart","MC.singleTbartW","MC.singleTs","MC.singleTt","MC.singleTtW"])
#Z+Jets
process_names_mc.append('Z+Jets')
subprocess_names_mc.append(["MC.ZJets1","MC.ZJets2","MC.ZJets3","MC.ZJets4"])
#W+Jets
process_names_mc.append('W+Jets')
subprocess_names_mc.append(["MC.WJets1","MC.WJets2","MC.WJets3","MC.WJets4"])
#TTbarlept
process_names_mc.append('TTbarlept')
subprocess_names_mc.append(["MC.TTbarlept"])
#TTbarhad
process_names_mc.append('TTbarhad')
subprocess_names_mc.append(["MC.TTbarhad"])
#TTbarsemi
process_names_mc.append('TTbarsemi')
subprocess_names_mc.append(["MC.TTbarsemi"])

total_subprocess_names_mc=[]
for i in range(len(process_names_mc)):
  for j in range(len(subprocess_names_mc[i])):
    total_subprocess_names_mc.append(subprocess_names_mc[i][j])

process_name_data = 'data'
subprocess_name_data = "DATA.DATA"

#process_colors = [2,3,4,5,6,7,8,9]
process_colors = [3,4,5,6,7,8,9]
histogram_names = []
histogram_descriptions = []
histogram_yaxes = []
histogram_xaxes = []

#N_topjets
histogram_names.append('N_topjets')
histogram_descriptions.append('N^{jets}')
histogram_yaxes.append('Events')
histogram_xaxes.append('N^{jets}')
#N_mu
histogram_names.append('N_mu')
histogram_descriptions.append('N^{muons}')
histogram_yaxes.append('Events')
histogram_xaxes.append('N^{muons}')
#N_pv
histogram_names.append('N_pv')
histogram_descriptions.append('N^{PV}')
histogram_yaxes.append('Events')
histogram_xaxes.append('N^{PV}')
#N_events_perLumiBin
histogram_names.append('N_events_perLumiBin')
histogram_descriptions.append('N^{evt}')
histogram_yaxes.append('Events')
histogram_xaxes.append('N^{evt}')
#N_pv_perLumiBin
histogram_names.append('N_pv_perLumiBin')
histogram_descriptions.append('N^{PV}')
histogram_yaxes.append('Events')
histogram_xaxes.append('N^{PV}')
#DR_Mub
histogram_names.append('DR_Mub')
histogram_descriptions.append('DR muon-b')
histogram_yaxes.append('Events')
histogram_xaxes.append('DR muon-b')
#DPhi_Mub
histogram_names.append('DPhi_Mub')
histogram_descriptions.append('DPhi muon-b')
histogram_yaxes.append('Events')
histogram_xaxes.append('DPhi muon-b')
#DR_Mutop
histogram_names.append('DR_Mutop')
histogram_descriptions.append('DR muon-top')
histogram_yaxes.append('Events')
histogram_xaxes.append('DR muon-top')
#DPhi_Mutop
histogram_names.append('DPhi_Mutop')
histogram_descriptions.append('DPhi muon-top')
histogram_yaxes.append('Events')
histogram_xaxes.append('DPhi muon-top')
#DR_btop
histogram_names.append('DR_btop')
histogram_descriptions.append('DR b-top')
histogram_yaxes.append('Events')
histogram_xaxes.append('DR b-top')
#DPhi_btop
histogram_names.append('DPhi_btop')
histogram_descriptions.append('DPhi b-top')
histogram_yaxes.append('Events')
histogram_xaxes.append('DPhi b-top')
#MassTop
histogram_names.append('MassTop')
histogram_descriptions.append('Top jet mass (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Top jet mass (GeV)')
#Pt_b_sub
histogram_names.append('Pt_b_sub')
histogram_descriptions.append('Pt b-subjet (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt b-subjet (GeV)')
#Pt_nonb_sub
histogram_names.append('Pt_nonb_sub')
histogram_descriptions.append('Pt non-b-subjet (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt non-b-subjet (GeV)')
#Pt_tagged_sub
histogram_names.append('Pt_tagged_sub')
histogram_descriptions.append('Pt non-b-subjet (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt non-b-subjet (GeV)')
#Pt_all_sub
histogram_names.append('Pt_all_sub')
histogram_descriptions.append('Pt all subjets (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt all subjets (GeV)')
#Pt_all_sub_nobin
histogram_names.append('Pt_all_sub_nobin')
histogram_descriptions.append('Pt all subjets (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt all subjets (GeV)')
#Toppt
histogram_names.append('Toppt')
histogram_descriptions.append('Pt top-jet (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Pt top-jet (GeV)')
#m01
histogram_names.append('m01')
histogram_descriptions.append('Inv mass of subjets 0+1 (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass of subjets 0+1 (GeV)')
#m02
histogram_names.append('m02')
histogram_descriptions.append('Inv mass of subjets 0+2 (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass of subjets 0+2 (GeV)')
#m12
histogram_names.append('m12')
histogram_descriptions.append('Inv mass of subjets 1+2 (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass of subjets 1+2 (GeV)')
#mW
histogram_names.append('mW')
histogram_descriptions.append('Inv mass of W (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass of W (GeV)')
#m012
histogram_names.append('m012')
histogram_descriptions.append('Inv mass of subjets 0+1+2 (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass of subjets 0+1+2 (GeV)')
#mMuB
histogram_names.append('mMuB')
histogram_descriptions.append('Inv mass Mu + Btagged jet (GeV)')
histogram_yaxes.append('Events')
histogram_xaxes.append('Inv mass Mu + Btagged jet (GeV)')
#dRMuB
histogram_names.append('dRMuB')
histogram_descriptions.append('DeltaR Mu Btagged jet')
histogram_yaxes.append('Events')
histogram_xaxes.append('DeltaR Mu Btagged jet')
#Nevts
histogram_names.append('Nevts')
histogram_descriptions.append('Number of events passed')
histogram_yaxes.append('Events')
histogram_xaxes.append('Passed')
#EventCount
histogram_names.append('EventCount')
histogram_descriptions.append('EventCount')
histogram_yaxes.append('Events')
histogram_xaxes.append('')

files_path = "/scratch/hh/dust/naf/cms/user/usai/heptoptagval/"
files_name_base = "SemileptonicHepTopTagValSelCycle"

cut_names = ["nocutshists","nleptbtagshists","probeselehists","htcuthists","etmisshists","njetshists","masswindowhists","heptoptag_masscut_hists","NOheptoptag_NOmasscut_hists","NOheptoptag_masscut_hists","heptoptag_NOmasscut_hists","heptoptag_NOmasscut__NOheptoptag_masscut_hists","pt200hists","pt250hists","pt300hists","before_tpr_hists","after_tpr_hists"]

#get the files
files_list_mc=[]
for process_name_index in range(len(process_names_mc)):
  process_name=process_names_mc[process_name_index]
  subprocess_sublist=[]
  for subprocess_name_index in range(len(subprocess_names_mc[process_name_index])):
    subprocess_name=subprocess_names_mc[process_name_index][subprocess_name_index]
    subprocess_sublist.append(TFile(files_path+"/"+files_name_base+"."+subprocess_name+".root"))
  files_list_mc.append(subprocess_sublist)
file_data=TFile(files_path+"/"+files_name_base+"."+subprocess_name_data+".root")
#structure: files_list_mc[process_name_index][subprocess_name_index]

#open output file
outfile=TFile("heptoptagvalhistos.root", "RECREATE")

#get mc histos
input_histos_mc=[]
for process_name_index in range(len(process_names_mc)):
  process_name=process_names_mc[process_name_index]
  subprocess_sublist=[]
  for subprocess_name_index in range(len(subprocess_names_mc[process_name_index])):
    subprocess_name=subprocess_names_mc[process_name_index][subprocess_name_index]
    histo_sublist=[]
    for histogram_name_index in range(len(histogram_names)):
      histogram_name=histogram_names[histogram_name_index]
      cut_sublist=[]
      for cut_name_index in range(len(cut_names)):
	cut_name=cut_names[cut_name_index]
	cut_sublist.append(files_list_mc[process_name_index][subprocess_name_index].Get(cut_name+"/"+histogram_name))
      histo_sublist.append(cut_sublist)
    subprocess_sublist.append(histo_sublist)
  input_histos_mc.append(subprocess_sublist)
#structure: input_histos_mc[process_name_index][subprocess_name_index][histogram_name_index][cut_name_index]

#get data histos
input_histos_data=[]
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  tmp_histogram_sublist=[]
  for cut_name_index in range(len(cut_names)):
    cut_name=cut_names[cut_name_index]
    tmp_histogram_sublist.append(file_data.Get(cut_name+"/"+histogram_name))#.Clone())
    tmp_histogram_sublist[-1].SetLineColor(kBlack)
    tmp_histogram_sublist[-1].SetLineWidth(2)
    tmp_histogram_sublist[-1].SetMarkerColor(kBlack)
    #tmp_histogram_sublist[-1].Sumw2()
    #tmp_histogram_sublist[-1].Write()
  input_histos_data.append(tmp_histogram_sublist)
#structure: input_histos_data[histogram_name_index][cut_name_index]

#merge mc histos
input_merged_mc=[]
for process_name_index in range(len(process_names_mc)):
  process_name=process_names_mc[process_name_index]
  histo_sublist=[]
  for histogram_name_index in range(len(histogram_names)):
    histogram_name=histogram_names[histogram_name_index]
    cut_sublist=[]
    for cut_name_index in range(len(cut_names)):
      cut_name=cut_names[cut_name_index]
      merged_histo=input_histos_mc[process_name_index][0][histogram_name_index][cut_name_index].Clone(process_name+'_'+histogram_name+'_'+cut_name+'_Merge')
      if len(subprocess_names_mc[process_name_index])>1:
	for subprocess_name_index in range(1,len(subprocess_names_mc[process_name_index])):
	    merged_histo.Add(input_histos_mc[process_name_index][subprocess_name_index][histogram_name_index][cut_name_index])
      process_color=process_colors[process_name_index]
      merged_histo.SetFillColor(process_color)
      merged_histo.SetLineColor(kBlack)
      merged_histo.SetMarkerColor(process_color)
      cut_sublist.append(merged_histo)
    histo_sublist.append(cut_sublist)
  input_merged_mc.append(histo_sublist)
#structure: input_merged_mc[process_name_index][histogram_name_index][cut_name_index]

#stack mc histos
stacked_mc=[]
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  cut_sublist=[]
  for cut_name_index in range(len(cut_names)):
    cut_name=cut_names[cut_name_index]
    stack_histo=THStack(histogram_name+'_'+cut_name+'_Stack','')
    for process_name_index in range(len(process_names_mc)):
      stack_histo.Add(input_merged_mc[process_name_index][histogram_name_index][cut_name_index])
    cut_sublist.append(stack_histo)
  stacked_mc.append(cut_sublist)
#structure: stacked_mc[histogram_name_index][cut_name_index]

#add mc histos for pull
added_mc=[]
added_mc_signal=[]
added_mc_background=[]
added_mc_SoverB=[]
added_mc_DoverMC=[]
signal_name='TTbarsemi'
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  cut_sublist=[]
  cut_sublist_signal=[]
  cut_sublist_background=[]
  cut_sublist_SoverB=[]
  cut_sublist_DoverMC=[]
  for cut_name_index in range(len(cut_names)):
    cut_name=cut_names[cut_name_index]
    added_histo=input_merged_mc[0][histogram_name_index][cut_name_index].Clone(histogram_name+'_'+cut_name+'_Add')
    added_histo_background=input_merged_mc[0][histogram_name_index][cut_name_index].Clone(histogram_name+'_'+cut_name+'_Background_Add')
    if len(process_names_mc)>1:
      for process_name_index in range(1,len(process_names_mc)):
	added_histo.Add(input_merged_mc[process_name_index][histogram_name_index][cut_name_index])
	if process_names_mc[process_name_index]==signal_name:
	  added_histo_signal=input_merged_mc[process_name_index][histogram_name_index][cut_name_index].Clone(histogram_name+'_'+cut_name+'_Signal_Add')
	else:
	  added_histo_background.Add(input_merged_mc[process_name_index][histogram_name_index][cut_name_index])
    added_histo_SoverB=added_histo_signal.Clone(histogram_name+'_'+cut_name+'_SoverB_Add')
    added_histo_SoverB.Divide(added_histo_background)
    added_histo_DoverMC=input_histos_data[histogram_name_index][cut_name_index].Clone(histogram_name+'_'+cut_name+'_DoverMC_Add')
    added_histo_DoverMC.Divide(added_histo)
    cut_sublist.append(added_histo)
    cut_sublist_signal.append(added_histo_signal)
    cut_sublist_background.append(added_histo_background)
    cut_sublist_SoverB.append(added_histo_SoverB)
    cut_sublist_DoverMC.append(added_histo_DoverMC)
    if histogram_name=='Nevts' and cut_name in ["heptoptag_masscut_hists","NOheptoptag_NOmasscut_hists","NOheptoptag_masscut_hists","heptoptag_NOmasscut_hists","heptoptag_NOmasscut__NOheptoptag_masscut_hists"]:
      added_histo_SoverB.Write()
      added_histo_DoverMC.Write()
      canvas=TCanvas(histogram_name+'_'+cut_name+'_Info')
      SoverBvalue=added_histo_SoverB.GetBinContent(1)
      SoverBerror=added_histo_SoverB.GetBinError(1)
      DoverMCvalue=added_histo_DoverMC.GetBinContent(1)
      DoverMCerror=added_histo_DoverMC.GetBinError(1)
      latex=TLatex()
      #latex.DrawLatex(0.1,0.8,"#frac{S}{B}="+('%.3f' % SoverBvalue)+'#pm'+('%.3f' % SoverBerror))
      #latex.DrawLatex(0.1,0.6,"#frac{DATA}{MC}="+('%.3f' % DoverMCvalue)+'#pm'+('%.3f' % DoverMCerror))
      latex.DrawLatex(0.1,0.8,"#frac{S}{B}="+str(SoverBvalue)+'#pm'+str(SoverBerror))
      latex.DrawLatex(0.1,0.6,"#frac{DATA}{MC}="+str(DoverMCvalue)+'#pm'+str(DoverMCerror))
      latex.Draw()
      canvas.Write()
  added_mc.append(cut_sublist)
  added_mc_signal.append(cut_sublist_signal)
  added_mc_background.append(cut_sublist_background)
  added_mc_SoverB.append(cut_sublist_SoverB)
  added_mc_DoverMC.append(cut_sublist_DoverMC)
#structure: added_mc[histogram_name_index][cut_name_index]

#calculate SF
nevts_index=histogram_names.index('Nevts')
index_nn=cut_names.index("NOheptoptag_NOmasscut_hists")
index_yy=cut_names.index("heptoptag_masscut_hists")
index_ny=cut_names.index("NOheptoptag_masscut_hists")
index_yn=cut_names.index("heptoptag_NOmasscut_hists")
index_yn_ny=cut_names.index("heptoptag_NOmasscut__NOheptoptag_masscut_hists")

SF_yn_over_nn=added_mc_DoverMC[nevts_index][index_yn].Clone('SF_yn_over_nn')
SF_ny_over_nn=added_mc_DoverMC[nevts_index][index_ny].Clone('SF_ny_over_nn')
SF_yy_over_nn=added_mc_DoverMC[nevts_index][index_yy].Clone('SF_yy_over_nn')
SF_yn_ny_over_yn=added_mc_DoverMC[nevts_index][index_yn_ny].Clone('SF_yn_ny_over_yn')
SF_yn_over_nn.Divide(added_mc_DoverMC[nevts_index][index_nn])
SF_ny_over_nn.Divide(added_mc_DoverMC[nevts_index][index_nn])
SF_yy_over_nn.Divide(added_mc_DoverMC[nevts_index][index_nn])
SF_yn_ny_over_yn.Divide(added_mc_DoverMC[nevts_index][index_yn])
SF_string_base='#left|#frac{DATA}{MC}#right|_{%s}=%.3f#pm%.3f'
DoMC_string_base='#left|#frac{DATA}{MC}#right|_{%s}=%.3f#pm%.3f'
DoMC_nn_string=DoMC_string_base%('No cuts',added_mc_DoverMC[nevts_index][index_nn].GetBinContent(1),added_mc_DoverMC[nevts_index][index_nn].GetBinError(1))
DoMC_yn_string=DoMC_string_base%('HTT no mass',added_mc_DoverMC[nevts_index][index_yn].GetBinContent(1),added_mc_DoverMC[nevts_index][index_yn].GetBinError(1))
DoMC_ny_string=DoMC_string_base%('mass only',added_mc_DoverMC[nevts_index][index_ny].GetBinContent(1),added_mc_DoverMC[nevts_index][index_ny].GetBinError(1))
DoMC_yy_string=DoMC_string_base%('HTT with mass',added_mc_DoverMC[nevts_index][index_yy].GetBinContent(1),added_mc_DoverMC[nevts_index][index_yy].GetBinError(1))
DoMC_yn_ny_string=DoMC_string_base%('HTT && mass',added_mc_DoverMC[nevts_index][index_yn_ny].GetBinContent(1),added_mc_DoverMC[nevts_index][index_yn_ny].GetBinError(1))

DoMCcanvas=TCanvas('Scale_Factors')
DoMClatex=TLatex()
DoMClatex.DrawLatex(0.02,0.8,DoMC_nn_string)
DoMClatex.DrawLatex(0.52,0.8,DoMC_yy_string)
DoMClatex.DrawLatex(0.02,0.5,DoMC_yn_string)
DoMClatex.DrawLatex(0.52,0.5,DoMC_ny_string)
DoMClatex.DrawLatex(0.02,0.2,DoMC_yn_ny_string)
DoMClatex.Draw()
DoMCcanvas.Write()

#make pull
pulls=[]
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  cut_sublist=[]
  for cut_name_index in range(len(cut_names)):
    cut_name=cut_names[cut_name_index]
    pull=input_histos_data[histogram_name_index][cut_name_index].Clone(histogram_name+'_'+cut_name+'_Pull')
    pull.Divide(added_mc[histogram_name_index][cut_name_index])
    pull.SetStats(kFALSE)
    pull.SetTitle('')
    pull.GetYaxis().SetLabelSize(0.22)
    pull.GetYaxis().SetTitle("Data / MC")
    pull.GetYaxis().SetTitleSize(0.22)
    pull.GetYaxis().SetTitleOffset(0.23)
    pull.GetYaxis().SetRangeUser(0.5,1.7)
    pull.GetYaxis().SetNdivisions(3,2,0)
    pull.GetXaxis().SetLabelSize(0.22)
    pull.GetXaxis().SetTitle(histogram_xaxes[histogram_name_index])
    pull.GetXaxis().SetTitleSize(0.22)
    pull.GetXaxis().SetTitleOffset(0.9)
    pull.SetLineColor(kBlue+2)
    pull.SetLineWidth(2)
    cut_sublist.append(pull)
  pulls.append(cut_sublist)
#structure: pulls[histogram_name_index][cut_name_index]

#make legend
legend=TLegend(0.9,0.295,0.999,0.93)
for process_name_index in range(len(process_names_mc)):
  legend.AddEntry(input_merged_mc[process_name_index][0][0],process_names_mc[process_name_index],'f')
legend.AddEntry(input_histos_data[0][0],process_name_data,'lpe')
cmslabel=TLatex(0.3,0.87,"CMS Preliminary #sqrt{s} = 8TeV  15.9 fb^{-1}")
cmslabel.SetNDC()

#compare mc and data
canvases=[]
for histogram_name_index in range(len(histogram_names)):
  histogram_name=histogram_names[histogram_name_index]
  cut_sublist=[]
  for cut_name_index in range(len(cut_names)):
    cut_name=cut_names[cut_name_index]
    tmp_canvas=TCanvas(histogram_name+'_'+cut_name+'_Canvas','')
    tmp_canvas.Divide(1,2)
    top_pad=tmp_canvas.GetPad(1)
    bottom_pad=tmp_canvas.GetPad(2)
    top_pad.SetPad( 0.0, 0.25, 1.0, 1.0 )
    bottom_pad.SetPad( 0.0, 0.0, 1.0, 0.25 )
    top_pad.SetTopMargin(0.07)
    #top_pad.SetBottomMargin(0.03)
    top_pad.SetBottomMargin(0.0)#0.013)
    top_pad.SetLeftMargin(0.12)
    top_pad.SetRightMargin(0.1)
    #bottom_pad.SetTopMargin(0.03)
    bottom_pad.SetTopMargin(0.0)
    bottom_pad.SetBottomMargin(0.42)
    bottom_pad.SetLeftMargin(0.12)
    bottom_pad.SetRightMargin(0.1)
    tmp_canvas.cd(1)
    stacked_mc[histogram_name_index][cut_name_index].Draw("hist")
    input_histos_data[histogram_name_index][cut_name_index].Draw("same")
    legend.Draw()
    #stacked_mc[histogram_name_index].GetXaxis().SetTitle(histogram_xaxes[histogram_name_index])
    stacked_mc[histogram_name_index][cut_name_index].GetYaxis().SetTitle(histogram_yaxes[histogram_name_index])
    stacked_mc[histogram_name_index][cut_name_index].GetXaxis().SetTitle('')
    stacked_mc[histogram_name_index][cut_name_index].GetXaxis().SetLabelOffset(9999)
    stacked_mc[histogram_name_index][cut_name_index].GetXaxis().SetLabelSize(0)
    stacked_mc[histogram_name_index][cut_name_index].SetTitle(histogram_descriptions[histogram_name_index])
    stacked_mc[histogram_name_index][cut_name_index].GetYaxis().SetTitleSize(0.07)
    stacked_mc[histogram_name_index][cut_name_index].GetYaxis().SetLabelSize(0.07)
    stacked_mc[histogram_name_index][cut_name_index].GetYaxis().SetTitleOffset(0.9)
    cmslabel.Draw()
    tmp_canvas.cd(2)
    pulls[histogram_name_index][cut_name_index].Draw()
    line1=TLine(stacked_mc[histogram_name_index][cut_name_index].GetXaxis().GetXmin(),1.0,stacked_mc[histogram_name_index][cut_name_index].GetXaxis().GetXmax(),1.0)
    line1.SetLineStyle(2)
    line1.Draw()
    line2=TLine(stacked_mc[histogram_name_index][cut_name_index].GetXaxis().GetXmin(),2.0,stacked_mc[histogram_name_index][cut_name_index].GetXaxis().GetXmax(),2.0)
    line2.SetLineStyle(2)
    line2.Draw()
    canvases.append(tmp_canvas)
    #if (histogram_name in ['Toppt','MassTop','Pt_all_sub','m01','mW','m012']) and cut_name=="masswindowhists":
    #  tmp_canvas.SaveAs('z'+histogram_name+'_'+'Canvas.png')
      #tmp_canvas.SaveAs('z'+histogram_name+'_'+'Canvas.pdf')
    if histogram_name in ['Toppt','MassTop','Pt_all_sub','EventCount'] and cut_name in ["njetshists","masswindowhists","heptoptag_masscut_hists","NOheptoptag_NOmasscut_hists","NOheptoptag_masscut_hists","heptoptag_NOmasscut_hists","heptoptag_NOmasscut__NOheptoptag_masscut_hists","pt200hists","pt250hists","pt300hists","before_tpr_hists","after_tpr_hists"]:
      tmp_canvas.Write()
      #if histogram_name in ["subTrackNPixelHits","subTrackMomentum","subTrackJetDistVal","subTrackDecayLenVal","subTrackSip3dVal","subTrackSip3dSig","subJetNSecondaryVertices","subCSV","subFlightDistance3dSig"]:
      # top_pad.SetLogy()
  
#close file  
outfile.Close()
#sys.exit('ok') 
