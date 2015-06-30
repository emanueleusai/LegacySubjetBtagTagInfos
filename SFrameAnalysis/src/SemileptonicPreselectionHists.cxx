#include "include/SemileptonicPreselectionHists.h"
#include "include/ObjectHandler.h"
#include "include/EventCalc.h"
#include <iostream>

using namespace std;

SemileptonicPreselectionHists::SemileptonicPreselectionHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

SemileptonicPreselectionHists::~SemileptonicPreselectionHists()
{
  // default destructor, does nothing
}

void SemileptonicPreselectionHists::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };

  Book( TH1F( "N_topjets", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1F( "N_mu", ";N^{muons};Events", 5, 0, 5 ) );
  Book( TH1F( "N_pv", ";N^{PV};Events", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", ";N^{evt};Events", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", ";N^{PV};Events", 24, 0, 24 ) );

}

void SemileptonicPreselectionHists::Fill()
{
  // fill the histograms


  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();

  /*

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

  */

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

  /*

  double limpt=0;
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

    jettagged=0;

    if(HepTopTag(bcc->topjets->at(i))){

	 jettagged=1;

    }
      
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
  
  if(indexjet!=-99999){
  
    LorentzVector allsubjets(0,0,0,0);

    double mjet=0;

    for(unsigned int j=0; j < 3; ++j){

        allsubjets += bcc->topjets->at(indexjet).subjets()[j].v4();
    }
  
    if(!allsubjets.isTimelike()) {
        mjet=0;
    }
    else{
      mjet = allsubjets.M();
    }

    Hist("MassTop")->Fill(mjet,weight);

    Hist("Toppt")->Fill(bcc->topjets->at(indexjet).pt(),weight);

    subjets_top=bcc->topjets->at(indexjet).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->topjets->at(indexjet).btagsub_combinedSecondaryVertex();
    flavorsub_top=bcc->topjets->at(indexjet).flavorsub();

    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      if(abs(flavorsub_top[j])==5) Hist("Pt_b_sub")->Fill(subjets_top[j].pt(),weight);
       
    }
  
  }
  
  */

}

void SemileptonicPreselectionHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }

}

