#include "include/ExampleHists4.h"
#include "include/ObjectHandler.h"
#include "include/EventCalc.h"
#include <iostream>

using namespace std;

ExampleHists4::ExampleHists4(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

ExampleHists4::~ExampleHists4()
{
  // default destructor, does nothing
}

void ExampleHists4::Init()
{
  // book all histograms here

  Book( TH1F( "DR_Mub", ";DR muon-b;Events", 100, 0, 6.28));
  Book( TH1F( "DPhi_Mub", ";DPhi muon-b;Events", 100, 0, 6.28));
  Book( TH1F( "DR_Mutop", ";DR muon-top;Events", 100, 0, 6.28));
  Book( TH1F( "DPhi_Mutop", ";DPhi muon-top;Events", 100, 0, 6.28));
  Book( TH1F( "DR_btop", ";DR b-top;Events", 100, 0, 6.28));
  Book( TH1F( "DPhi_btop", ";DPhi b-top;Events", 100, 0, 6.28));

}

void ExampleHists4::Fill()
{
  // fill the histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  double weight = calc->GetWeight();

  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();

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

  }
  
}

void ExampleHists4::Finish()
{
  // final calculations, like division and addition of certain histograms


}

