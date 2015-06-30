// $Id: ExampleCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>

using namespace std;

// Local include(s):
#include "include/ExampleCycle2.h"
#include "include/BTagEffHistsTopTag.h"
#include "TFile.h"

ClassImp( ExampleCycle2 );

ExampleCycle2::ExampleCycle2()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(500.);
  DeclareProperty( "CSVOperatingPoint", m_CSVOperatingPoint );
  DeclareProperty( "BTagEffi_Filename_MC" , m_BTagEffiFilenameMC);
  DeclareProperty( "BTaggingMode" , m_BTaggingMode);

}

ExampleCycle2::~ExampleCycle2() 
{
  // destructor
}

void ExampleCycle2::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void ExampleCycle2::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void ExampleCycle2::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );
  
   aa= new TH1F("weight ratio","weight ratio",200,0,2);
 
  
  bool dobtag = false;
  if(m_BTagEffiFilenameMC.size()>0)
  {
    m_BTagEffiFilenameMC += ".";
    m_BTagEffiFilenameMC += id.GetType();
    m_BTagEffiFilenameMC += ".";
    m_BTagEffiFilenameMC += id.GetVersion();
    m_BTagEffiFilenameMC += ".root";
    dobtag=true;
  }

  if(id.GetType()=="DATA" || id.GetType()=="Data" || id.GetType()=="data") dobtag=false;

  m_bsf = NULL;
   
  if(dobtag)
  {
    std::cout << m_BTagEffiFilenameMC << std::endl;
    m_bsf = new BTaggingRoutineTopTag(atof(m_CSVOperatingPoint.c_str()), m_BTaggingMode, m_BTagEffiFilenameMC);
  }
  
  

  // -------------------- set up the selections ---------------------------

  //Selection* BSel = new Selection( "BSelection");
  //BSel->addSelectionModule(new NBTagSelection(1)); //at least one b tag
  
  //Selection* B24Sel = new Selection( "B24Selection");
  //B24Sel->addSelectionModule(new NBTagSelection(2,4)); //at least one b tag

  //Selection* NoBSel = new Selection( "NoBSelection");
  //NoBSel->addSelectionModule(new NBTagSelection(0,0)); //no b tags

  //Selection* chi2_selection= new Selection("chi2_selection");
  //static Chi2Discriminator* m_chi2discr = new Chi2Discriminator();
  //chi2_selection->addSelectionModule(new HypothesisDiscriminatorCut( m_chi2discr, -1*double_infinity(), 10));
  //chi2_selection->addSelectionModule(new MttbarGenCut(0,700));

  //Selection* TopSel = new Selection("TopSelection");
  //DO NOT use trigger selection in PROOF mode at the moment
  //TopSel->addSelectionModule(new TriggerSelection("HLT_PFJet320_v"));
  //TopSel->addSelectionModule(new NTopJetSelection(1,int_infinity(),350,2.5));
  //TopSel->addSelectionModule(new NTopTagSelection(1,int_infinity()));


  //RegisterSelection(BSel);
  //RegisterSelection(B24Sel);
  //RegisterSelection(NoBSel);
  //RegisterSelection(TopSel);
  //RegisterSelection(chi2_selection);

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  RegisterHistCollection( new ExampleHists2("NoCuts") );
  RegisterHistCollection( new ExampleHists2("BeforeNoCuts") );

  //RegisterHistCollection( new BTagEffHistsTopTag("BTagEff",atof(m_CSVOperatingPoint.c_str())) );
  
  
  
  //RegisterHistCollection( new HypothesisHists("Chi2_NoCuts", m_chi2discr ) );

  //histograms with and without b tagging
  //RegisterHistCollection( new ExampleHists("BTag") );
  //RegisterHistCollection( new ExampleHists("B24Tag") );
  //RegisterHistCollection( new ExampleHists("NoBTag") );
  //RegisterHistCollection( new HypothesisHists("Chi2_BTag", m_chi2discr ) );
  //RegisterHistCollection( new HypothesisHists("Chi2_NoBTag", m_chi2discr ) );

  // histograms after the top selection
  //RegisterHistCollection( new ExampleHists("TopSel") );
  //RegisterHistCollection( new HypothesisHists("Chi2_TopSel", m_chi2discr ) );

  // important: initialise histogram collections after their definition
  InitHistos();

  return;

}

void ExampleCycle2::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  //if(!(id.GetType()=="DATA" || id.GetType()=="Data" || id.GetType()=="data")) m_bsf->SaveHistos();
  TFile * aaa = new TFile("wratio.root","RECREATE");
  aa->Write();
  aaa->Close();
  
  return;

}

void ExampleCycle2::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void ExampleCycle2::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
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
  BaseHists* HistsNoCuts = GetHistCollection("NoCuts");
  BaseHists* HistsBeforeNoCuts = GetHistCollection("BeforeNoCuts");
  //BaseHists* BTagEff_Hists = GetHistCollection("BTagEff");
  
  
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
  
 /* if (!IsRealData)
  {
    BTagEff_Hists->Fill();
  }*/
  float oldweight=calc->GetWeight();
  HistsBeforeNoCuts->Fill();

  //if((m_bsf!=NULL) && (!IsRealData)) 
  if(m_bsf!=NULL) {
    calc->ProduceWeight(m_bsf->GetScaleWeight());
  }
  //if (!IsRealData) std::cout<<"scale: "<<calc->GetWeight()<<std::endl<<std::endl;
  float newweight=calc->GetWeight();
  
  aa->Fill(newweight/oldweight);

  HistsNoCuts->Fill();
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


