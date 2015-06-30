// $Id: ExampleCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>

using namespace std;

// Local include(s):
#include "include/ExampleCycle4.h"
#include "include/ExampleHists4.h"

ClassImp( ExampleCycle4 );

ExampleCycle4::ExampleCycle4()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(500.);
  DeclareProperty( "CSVOperatingPoint", m_CSVOperatingPoint );
  DeclareProperty( "BTagEffi_Filename_MC" , m_BTagEffiFilenameMC);
  DeclareProperty( "BTaggingMode" , m_BTaggingMode);

}

ExampleCycle4::~ExampleCycle4() 
{
  // destructor
}

void ExampleCycle4::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void ExampleCycle4::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void ExampleCycle4::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections

  AnalysisCycle::BeginInputData( id );
  
 

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  //RegisterHistCollection( new ExampleHists2("NoCuts") );
  RegisterHistCollection( new ExampleHists4("NoCuts") );
  

  InitHistos();

  return;

}

void ExampleCycle4::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void ExampleCycle4::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void ExampleCycle4::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight );

  // get the selections
  //static Selection* BSel = GetSelection("BSelection");
  //static Selection* B24Sel = GetSelection("B24Selection");
  //static Selection* NoBSel = GetSelection("NoBSelection");
  //static Selection* TopSel = GetSelection("TopSelection");
  //static Selection* chi2_selection = GetSelection("chi2_selection");

  // get the histogram collections
  //BaseHists* HistsNoCuts = GetHistCollection("NoCuts");
  BaseHists* Hists4 = GetHistCollection("NoCuts");
  
  
  //BaseHists* HistsBTag = GetHistCollection("BTag");
  //BaseHists* HistsB24Tag = GetHistCollection("B24Tag");
  //BaseHists* HistsNoBTag = GetHistCollection("NoBTag");
  //BaseHists* HistsTopSel = GetHistCollection("TopSel");
  
  //BaseHists* Chi2_HistsNoCuts = GetHistCollection("Chi2_NoCuts");
  //BaseHists* Chi2_HistsBTag = GetHistCollection("Chi2_BTag");
  //BaseHists* Chi2_HistsNoBTag = GetHistCollection("Chi2_NoBTag");
  //BaseHists* Chi2_HistsTopSel = GetHistCollection("Chi2_TopSel");

  //if(!chi2_selection->passSelection())  throw SError( SError::SkipEvent );

  //EventCalc* calc = EventCalc::Instance();
  //if(calc->GetJets()->size()>=12){
  //std::cout << "run: " << calc->GetRunNum() << "   lb: " << calc->GetLumiBlock() << "  event: " << calc->GetEventNum() << "   N(jets): " << calc->GetJets()->size() << std::endl;
  //}

  // start the analysis
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  //if (!IsRealData) std::cout<<"no scale: "<<calc->GetWeight()<<std::endl;
  // b tagging scale factor
  
//  if (!IsRealData)
//  {
    Hists4->Fill();
 // }
  
  
  /*if(m_bsf!=NULL && !IsRealData) {
    calc->ProduceWeight(m_bsf->GetScaleWeight());
  }*/
  //if (!IsRealData) std::cout<<"scale: "<<calc->GetWeight()<<std::endl<<std::endl;


  //HistsNoCuts->Fill();
  //Chi2_HistsNoCuts->Fill();

  //if(BSel->passSelection()){
  //HistsBTag->Fill();
  //Chi2_HistsBTag->Fill();
  //}
  //if(B24Sel->passSelection()){
  //HistsB24Tag->Fill();
  //}  
  //if(NoBSel->passSelection()){
  //HistsNoBTag->Fill();  
  //Chi2_HistsNoBTag->Fill();
  //}
  
  //if(!TopSel->passSelection())  throw SError( SError::SkipEvent );

  //HistsTopSel->Fill();
  //Chi2_HistsTopSel->Fill();
  
  return;
  
}


