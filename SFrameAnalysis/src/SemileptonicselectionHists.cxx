#include "include/SemileptonicselectionHists.h"
#include "include/ObjectHandler.h"
#include "include/EventCalc.h"
#include <iostream>

using namespace std;

SemileptonicselectionHists::SemileptonicselectionHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

SemileptonicselectionHists::~SemileptonicselectionHists()
{
  // default destructor, does nothing
}

void SemileptonicselectionHists::Init()
{
  // book all histograms here

  m_tpr = new TopPtReweight();
  
  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };

  Book( TH1F( "N_topjets", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1F( "N_mu", ";N^{muons};Events", 5, 0, 5 ) );
  Book( TH1F( "N_pv", ";N^{PV};Events", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", ";N^{evt};Events", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", ";N^{PV};Events", 24, 0, 24 ) );
  Book( TH1D( "DR_Mub", ";DR muon-b;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_Mub", ";DPhi muon-b;Events", 100, 0, 6.28));
  Book( TH1D( "DR_Mutop", ";DR muon-top;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_Mutop", ";DPhi muon-top;Events", 100, 0, 6.28));
  Book( TH1D( "DR_btop", ";DR b-top;Events", 100, 0, 6.28));
  Book( TH1D( "DPhi_btop", ";DPhi b-top;Events", 100, 0, 6.28));
  Book( TH1D( "MassTop", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "Pt_b_sub", ";Pt b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_nonb_sub", ";Pt non-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_tagged_sub", ";Pt non-b-subjet (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_all_sub", ";Pt all subjets (GeV);Events", 17, jetpt_bbins));
  Book( TH1D( "Pt_all_sub_nobin", ";Pt all subjets (GeV);Events", 40, 0, 500));
  Book( TH1D( "Toppt", ";Pt top-jet (GeV);Events", 25, 0, 1000));
  
  Book( TH1D( "m01", ";Inv mass of subjets 0+1 (GeV);Events", 100, 0, 500));
  Book( TH1D( "m02", ";Inv mass of subjets 0+2 (GeV);Events", 100, 0, 500));
  Book( TH1D( "m12", ";Inv mass of subjets 1+2 (GeV);Events", 100, 0, 500));
  Book( TH1D( "mW", ";Inv mass of W (GeV);Events", 100, 0, 500));
  Book( TH1D( "m012", ";Inv mass of subjets 0+1+2 (GeV);Events", 50, 0, 500));
  
  Book( TH1D( "Nevts", ";Passed;Events", 1, 0, 1));
  
  Book( TH1D( "mMuB", ";Inv mass Mu + Btagged jet (GeV);Events", 100, 0, 500));
  Book( TH1D( "dRMuB", ";DeltaR Mu Btagged jet;Events", 100, 0, 2));

  Book( TH1F( "TopPtWeightHisto","TopPtWeightHisto;Weight;Events",500,0.5,2));
  Book( TH1F( "TopPtFullWeightHisto","TopPtFullWeightHisto;Weight;Events",500,0,0.5));
  Book( TH2F( "TopWeightVsPtHisto","TopWeightVsPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000));
  Book( TH2F( "TopWeightVsGenPtHisto","TopWeightVsGenPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000));
  Book( TH1F( "EventCount","EventCount;before - after;Events",2,0,2));
  

}

void SemileptonicselectionHists::Fill()
{
  // fill the histograms


  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();
  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();
  // important: get the event weight
  double weight = calc->GetWeight();
  //std::cout<<weight<<std::endl;
  double ptreweight=m_tpr->GetScaleWeight();
  if (!IsRealData)
  {
    TH2F* TopWeightVsGenPtHisto = (TH2F*)Hist( "TopWeightVsGenPtHisto");
    TTbarGen* Decay = calc->GetTTbarGen();
    GenParticle topgen=Decay->Top();
    GenParticle antitopgen=Decay->Antitop();
    TopWeightVsGenPtHisto->Fill(ptreweight,topgen.pt(),1);
    TopWeightVsGenPtHisto->Fill(ptreweight,antitopgen.pt(),1);
  }
  int tprindex = findTheHighestPtGoodTopJet(bcc);  
  Hist( "TopPtWeightHisto")->Fill(ptreweight);
  Hist( "TopPtFullWeightHisto")->Fill(weight);
  TH2F* TopWeightVsPtHisto = (TH2F*)Hist( "TopWeightVsPtHisto");
  if (tprindex>-1) TopWeightVsPtHisto->Fill(ptreweight,bcc->topjets->at(tprindex).pt(),1);

  Hist( "EventCount")->Fill(0.1,weight);
  
  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();



  Hist("Nevts")->Fill(0.1,weight);
  
  if(!IsRealData){
  //Filling generator-level information for semi-leptonic ttbar events
  TTbarGen* Decay = calc->GetTTbarGen();

  GenParticle topgen=Decay->Top();
  GenParticle antitopgen=Decay->Antitop();
  GenParticle btop=Decay->bTop();
  GenParticle bantitop=Decay->bAntitop();
  int decaytop=abs(Decay->Wdecay1().pdgId());
  int decayantitop=abs(Decay->WMinusdecay1().pdgId());
  int semileptop=0;
  int semilepantitop=0;
  GenParticle muongen;

  if((decaytop==13||decaytop==14)&&decayantitop>0&&decayantitop<=5){
    semileptop=1;
    if(decaytop==13){
      muongen=Decay->Wdecay1();
    }
    if(decaytop==14){
      muongen=Decay->Wdecay2();
    }
  }
  if((decayantitop==13||decayantitop==14)&&decaytop>0&&decaytop<=5){
    semilepantitop=1;
    if(decayantitop==13){
      muongen=Decay->WMinusdecay1();
    }
    if(decaytop==14){
      muongen=Decay->WMinusdecay2();
    }
  }

  if(semileptop){
    Hist("DR_Mub")->Fill(muongen.deltaR(btop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(btop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(antitopgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(antitopgen),weight);
    Hist("DR_btop")->Fill(btop.deltaR(antitopgen),weight);
    Hist("DPhi_btop")->Fill(btop.deltaPhi(antitopgen),weight);
  }

  if(semilepantitop){
    Hist("DR_Mub")->Fill(muongen.deltaR(bantitop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(bantitop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(topgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(topgen),weight);
    Hist("DR_btop")->Fill(bantitop.deltaR(topgen),weight);
    Hist("DPhi_btop")->Fill(bantitop.deltaPhi(topgen),weight);
  }

  }//if Monte Carlo

  Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
  Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );

  //MET* met = calc->GetMET();
  //Hist("MET_lx")->Fill(met->pt(), weight);

  //double HT = calc->GetHT();
  //Hist("HT_lx")->Fill(HT, weight);

  //double HTlep = calc->GetHTlep();
  //Hist("HTlep_lx")->Fill(HTlep, weight);

  int Ntopjets = bcc->topjets->size();
  Hist("N_topjets")->Fill(Ntopjets, weight);

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);

  //for (int i=0; i<Nmuons; ++i){
  //Muon thismu = muons->at(i);
  //Hist("pt_mu_lx")->Fill(thismu.pt(), weight);
  //Hist("eta_mu")->Fill(thismu.eta(), weight);
  //Hist("reliso_mu")->Fill(thismu.relIso(), weight);
  //}

  
  float _maxpt=-1;
  float _theinvmass=-1;
  int _theindex=-1;
  for(unsigned int i=0; i<bcc->jets->size(); ++i) 
  {
    Jet jet = bcc->jets->at(i);
    Muon muon = bcc->muons->at(0);
    bool isbtagged=false;
    //if(m_type==e_CSVL && jet.btag_combinedSecondaryVertex()>0.244) isbtagged=true;
    if(jet.btag_combinedSecondaryVertex()>0.679) isbtagged=true;
    //if(m_type==e_CSVT && jet.btag_combinedSecondaryVertex()>0.898) isbtagged=true;
    /*if(m_type==e_JPL && jet.btag_jetProbability()>0.275) isbtagged=true;
    if(m_type==e_JPM && jet.btag_jetProbability()>0.545) isbtagged=true;
    if(m_type==e_JPT && jet.btag_jetProbability()>0.790) isbtagged=true;*/
    double deltaPhi = jet.deltaPhi( muon );
    double invmass = ( jet.v4() + muon.v4() ).M();
//    bool masswindow = ( ( invmass > m_min_mass ) && ( invmass < m_max_mass ) );
    
    if(jet.pt()>150. && fabs(jet.eta())<2.5 && deltaPhi<2*PI/3 && isbtagged && jet.pt()>_maxpt/*&& masswindow*/)
    {
      _theinvmass=invmass;
      _maxpt=jet.pt();
      _theindex=i;
    }
  }
  if (_theindex>-1)
  {
   Hist("mMuB")->Fill(_theinvmass,weight);
   Hist("dRMuB")->Fill(bcc->jets->at(_theindex).deltaR(bcc->muons->at(0)),weight);
  }
  
  

  std::vector<Particle> subjets_top;
  std::vector<float> btagsub_combinedSecondaryVertex_top;
  std::vector<int> flavorsub_top;
  
  /*double limpt=0;
  int indexjet=-99999;

  int countjets=0;

  std::vector<Particle> subjets_top;
  std::vector<float> btagsub_combinedSecondaryVertex_top;
  std::vector<int> flavorsub_top;

  for(unsigned int i=0; i<bcc->topjets->size(); ++i) {
    int jettagged=0;
    
    subjets_top=bcc->topjets->at(i).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->topjets->at(i).btagsub_combinedSecondaryVertex();
    
    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      float test=btagsub_combinedSecondaryVertex_top[j];

      //if(test>0.244) jettagged=1;
      if(test>0.679) jettagged=1;
      //if(test>0.898) jettagged=1;
      
    }

    //jettagged=0;

    //if(HepTopTag(bcc->topjets->at(i))){

	// jettagged=1;

    //}
      
    if(bcc->muons->size()>0){
      double deltaphi=bcc->topjets->at(i).deltaPhi(bcc->muons->at(0));
    
      if(jettagged&&(deltaphi>(2*PI/3))&&(bcc->topjets->at(i).pt()>150.)&&(fabs(bcc->topjets->at(i).eta())<2.5)){
	
	countjets=countjets+1;

	if(bcc->topjets->at(i).pt()>limpt){

	  indexjet=i;
	  limpt=bcc->topjets->at(i).pt();

	}
    
      }
    }
}//loop over top jets
*/
  int indexjet=findTheHighestPtGoodTopJet(bcc);
    

  
  if(indexjet!=-99999){
  
    LorentzVector allsubjets(0,0,0,0);

    double mjet=0;
    double m012=0;

    for(unsigned int j=0; j < 3; ++j){

        allsubjets += bcc->topjets->at(indexjet).subjets()[j].v4();
    }
  
    if(!allsubjets.isTimelike()) {
        m012=0;
    }
    else{
      m012 = allsubjets.M();
    }
    //Hist("Nevts")->Fill(0.1,weight);
    //uncomments to have mass jet from jet and not from sum subjets
    mjet=bcc->topjets->at(indexjet).v4().M();

    Hist("MassTop")->Fill(mjet,weight);
    Hist("m012")->Fill(m012,weight);

    Hist("Toppt")->Fill(bcc->topjets->at(indexjet).pt(),weight);

    subjets_top=bcc->topjets->at(indexjet).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->topjets->at(indexjet).btagsub_combinedSecondaryVertex();
    flavorsub_top=bcc->topjets->at(indexjet).flavorsub();

    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      //if(j==0){
      Hist("Pt_all_sub")->Fill(subjets_top[j].pt(),weight);
      Hist("Pt_all_sub_nobin")->Fill(subjets_top[j].pt(),weight);
      //}
      if(btagsub_combinedSecondaryVertex_top[j]>0.679){
      
	Hist("Pt_tagged_sub")->Fill(subjets_top[j].pt(),weight);

	if(abs(flavorsub_top[j])==5) Hist("Pt_b_sub")->Fill(subjets_top[j].pt(),weight);
	if(abs(flavorsub_top[j])!=5) Hist("Pt_nonb_sub")->Fill(subjets_top[j].pt(),weight);

      }//loop on subjets

      //heptoptagger variable plots
      if(btagsub_combinedSecondaryVertex_top.size()>=3) 
      {

	std::vector<Particle> subjets = bcc->topjets->at(indexjet).subjets();
	
	double mW = 0;
	if( (subjets[0].v4()+subjets[1].v4()).isTimelike())
	{
	  mW=(subjets[0].v4()+subjets[1].v4()).M();
	  Hist("mW")->Fill(mW,weight);
	}
	
	sort(subjets.begin(), subjets.end(), HigherPt());
	
	double m01 = 0;
	if( (subjets[0].v4()+subjets[1].v4()).isTimelike())
	{
	  m01=(subjets[0].v4()+subjets[1].v4()).M();
	  Hist("m01")->Fill(m01,weight);
	}
	double m02 = 0;
	if( (subjets[0].v4()+subjets[2].v4()).isTimelike() )
	{
	  m02=(subjets[0].v4()+subjets[2].v4()).M();
	  Hist("m02")->Fill(m02,weight);
	}
	double m12 = 0;
	if( (subjets[1].v4()+subjets[2].v4()).isTimelike() )
	{
	  m12 = (subjets[1].v4()+subjets[2].v4()).M();
	  Hist("m12")->Fill(m12,weight);
	}
      }//heptoptagger variable plots
      
    }
    
  }
  
}

void SemileptonicselectionHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }

}

