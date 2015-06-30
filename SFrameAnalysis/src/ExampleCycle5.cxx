// $Id: ExampleCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

#include <iostream>

using namespace std;

// Local include(s):
#include "include/ExampleCycle5.h"
#include "include/ExampleHists5.h"

ClassImp( ExampleCycle5 );

ExampleCycle5::ExampleCycle5()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(500.);
  DeclareProperty( "CSVOperatingPoint", m_CSVOperatingPoint );
  DeclareProperty( "BTagEffi_Filename_MC" , m_BTagEffiFilenameMC);
  DeclareProperty( "BTaggingMode" , m_BTaggingMode);

}

ExampleCycle5::~ExampleCycle5() 
{
  // destructor
}

void ExampleCycle5::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void ExampleCycle5::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  AnalysisCycle::EndCycle();

  return;

}

void ExampleCycle5::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections

  AnalysisCycle::BeginInputData( id );
  
 

  // ---------------- set up the histogram collections --------------------

  // histograms without any cuts
  //RegisterHistCollection( new ExampleHists2("NoCuts") );
  RegisterHistCollection( new ExampleHists5("NoCuts") );
  

  InitHistos();

  return;

}

void ExampleCycle5::EndInputData( const SInputData& id ) throw( SError ) 
{
  AnalysisCycle::EndInputData( id );
  return;

}

void ExampleCycle5::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void ExampleCycle5::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight );


  BaseHists* Hists5 = GetHistCollection("NoCuts");
  
  // start the analysis
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();

    Hists5->Fill();

  
  

  return;
  
}


