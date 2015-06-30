#include <iostream>

using namespace std;

// Local include(s):
#include "include/SemileptonicPreselectionHists.h"
#include "include/SemileptonicPreselectionCycle.h"
#include "include/SelectionModules.h"
#include "include/ObjectHandler.h"

ClassImp( SemileptonicPreselectionCycle );

SemileptonicPreselectionCycle::SemileptonicPreselectionCycle()
    : AnalysisCycle()
{

    // constructor, declare additional variables that should be
    // obtained from the steering-xml file

    // set the integrated luminosity per bin for the lumi-yield control plots
    SetIntLumiPerBin(25.);

    DeclareProperty( "ValidationType", m_ValidationType );

    DeclareProperty( "CSVOperatingPoint", m_CSVOperatingPoint );
    DeclareProperty( "BTagEffi_Filename_MC" , m_BTagEffiFilenameMC);
    DeclareProperty( "BTaggingMode" , m_BTaggingMode);
    
}

SemileptonicPreselectionCycle::~SemileptonicPreselectionCycle()
{
    // destructor
}

void SemileptonicPreselectionCycle::BeginCycle() throw( SError )
{
    // Start of the job, general set-up and definition of
    // objects are done here

    // Important: first call BeginCycle of base class
    AnalysisCycle::BeginCycle();

    return;

}

void SemileptonicPreselectionCycle::EndCycle() throw( SError )
{
    // clean-up, info messages and final calculations after the analysis


    // call the base cycle class for all standard methods
    // and a summary of the made selections
    AnalysisCycle::EndCycle();

    return;

}

void SemileptonicPreselectionCycle::BeginInputData( const SInputData& id ) throw( SError )
{
    // declaration of histograms and selections

    // Important: first call BeginInputData of base class
    AnalysisCycle::BeginInputData( id );

    
    
 /*   
    //do b tag
    
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
    
    */
    
    
    
    // -------------------- set up the selections ---------------------------

    Selection* trigger = new Selection("trigger");

    trigger->addSelectionModule(new TriggerSelection("HLT_IsoMu40_eta2p1"));

    RegisterSelection(trigger);

    
    Selection* preselectionNPrimaryVertexSelection = new Selection("preselectionNPrimaryVertexSelection");
    Selection* preselectionNElectronSelection = new Selection("preselectionNElectronSelection");
    Selection* preselectionNMuonSelection = new Selection("preselectionNMuonSelection");
    Selection* preselectionNJetSelection = new Selection("preselectionNJetSelection");//at least two jets with pt>30GeV and eta<2.5
    Selection* preselectionNTopJetSelection = new Selection("preselectionNTopJetSelection");//at least one jet with pt>150GeV and eta<2.5
    
    //Selection* preselection = new Selection("preselection");

    preselectionNPrimaryVertexSelection->addSelectionModule(new NPrimaryVertexSelection(1));
    preselectionNElectronSelection->addSelectionModule(new NElectronSelection(0,0));
    preselectionNMuonSelection->addSelectionModule(new NMuonSelection(1,1));
    preselectionNJetSelection->addSelectionModule(new NJetSelection(2,int_infinity(),30.,2.5));//at least two jets with pt>30GeV and eta<2.5
    preselectionNTopJetSelection->addSelectionModule(new NTopJetSelection(1,int_infinity(),150.,2.5));//at least one jet with pt>150GeV and eta<2.5

    RegisterSelection(preselectionNPrimaryVertexSelection);
    RegisterSelection(preselectionNElectronSelection);
    RegisterSelection(preselectionNMuonSelection);
    RegisterSelection(preselectionNJetSelection);
    RegisterSelection(preselectionNTopJetSelection);

    RegisterHistCollection( new SemileptonicPreselectionHists("histoTriggerSelection") );
    RegisterHistCollection( new SemileptonicPreselectionHists("histoNPrimaryVertexSelection") );
    RegisterHistCollection( new SemileptonicPreselectionHists("histoNElectronSelection") );
    RegisterHistCollection( new SemileptonicPreselectionHists("histoNMuonSelection") );
    RegisterHistCollection( new SemileptonicPreselectionHists("histoNJetSelection") );
    RegisterHistCollection( new SemileptonicPreselectionHists("histoNTopJetSelection") );
    //Selection* nleptbtags = new Selection("nleptbtags");

    //Add again
    //nleptbtags->addSelectionModule(new NMuonBTagSelection(1,int_infinity(),e_CSVM,30.,2.5)); // at least one b-topjet in the muon hemisphere with pt>30GeV and eta<2.5

    //RegisterSelection(nleptbtags);

    //Add again
    //Selection* probesele = new Selection("probesele");

    //if(m_ValidationType == "toptagger"){
      
    //Add again
    //probesele->addSelectionModule(new NAntiMuonSubBTagSelection(1,1,e_CSVM,150.,2.5)); // one b-tagged subjets of topjet in the muon anti-hemisphere with pt>150GeV and eta<2.5
      
    //}

    //if(m_ValidationType == "btagging"){

    //Do not add -> for b-tagging validation
    //probesele->addSelectionModule(new NAntiMuonHEPTopSelection(1,1,150.,2.5)); // at least one top-tagged jet in the muon anti-hemisphere with pt>150GeV and eta<2.5

    //}

    //RegisterSelection(probesele);

    //Add again
    //Selection* htcut = new Selection("htcut");

    //htcut->addSelectionModule(new HTlepCut(150.));
 
    //RegisterSelection(htcut);

    //Add again
    //Selection* etmiss = new Selection("etmiss");

    //RegisterSelection(etmiss);

    //etmiss->addSelectionModule(new METCut(20.));

    //RegisterHistCollection( new SemileptonicPreselectionHists("nocutshists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("triggerhists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("preselectionhists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("nleptbtagshists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("probeselehists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("htcuthists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("etmisshists") );

     // important: initialise histogram collections after their definition
    InitHistos();

    return;
}

void SemileptonicPreselectionCycle::EndInputData( const SInputData& id ) throw( SError )
{
    AnalysisCycle::EndInputData( id );

    return;
}

void SemileptonicPreselectionCycle::BeginInputFile( const SInputData& id ) throw( SError )
{
    // Connect all variables from the Ntuple file with the ones needed for the analysis
    // The variables are commonly stored in the BaseCycleContaincer

    // important: call to base function to connect all variables to Ntuples from the input tree
    AnalysisCycle::BeginInputFile( id );

    return;
}

void SemileptonicPreselectionCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError )
{
    // this is the most important part: here the full analysis happens
    // user should implement selections, filling of histograms and results

    // first step: call Execute event of base class to perform basic consistency checks
    // also, the good-run selection is performed there and the calculator is reset

    AnalysisCycle::ExecuteEvent( id, weight);

    EventCalc* calc = EventCalc::Instance();
    /*if(m_bsf!=NULL) {
      calc->ProduceWeight(m_bsf->GetScaleWeight());
    }*/
    
    Cleaner cleaner;

    static Selection* trigger = GetSelection("trigger");
    static Selection* preselectionNPrimaryVertexSelection = GetSelection("preselectionNPrimaryVertexSelection");
    static Selection* preselectionNElectronSelection = GetSelection("preselectionNElectronSelection");
    static Selection* preselectionNMuonSelection = GetSelection("preselectionNMuonSelection");
    static Selection* preselectionNJetSelection = GetSelection("preselectionNJetSelection");//at least two jets with pt>30GeV and eta<2.5
    static Selection* preselectionNTopJetSelection = GetSelection("preselectionNTopJetSelection");//at least one jet with pt>150GeV and eta<2.5
    //static Selection* preselection = GetSelection("preselection");
    
    
    //static Selection* nleptbtags = GetSelection("nleptbtags");
    //static Selection* probesele = GetSelection("probesele");
    //static Selection* htcut = GetSelection("htcut");
    //static Selection* etmiss = GetSelection("etmiss");

    BaseHists* HistsTriggerSelection = GetHistCollection("histoTriggerSelection");
    BaseHists* HistsNPrimaryVertexSelection = GetHistCollection("histoNPrimaryVertexSelection");
    BaseHists* HistsNElectronSelection = GetHistCollection("histoNElectronSelection");
    BaseHists* HistsNMuonSelection = GetHistCollection("histoNMuonSelection");
    BaseHists* HistsNJetSelection = GetHistCollection("histoNJetSelection");
    BaseHists* HistsNTopJetSelection = GetHistCollection("histoNTopJetSelection");
    
    //BaseHists* Histsnocuts = GetHistCollection("nocutshists");
    //BaseHists* Histstrigger = GetHistCollection("triggerhists");
    //BaseHists* Histspreselection = GetHistCollection("preselectionhists");
    //BaseHists* Histsnleptbtags = GetHistCollection("nleptbtagshists");
    //BaseHists* Histsprobesele = GetHistCollection("probeselehists");
    //BaseHists* Histshtcut = GetHistCollection("htcuthists");
    //BaseHists* Histsetmiss = GetHistCollection("etmisshists");
    
    ObjectHandler* objs = ObjectHandler::Instance();
    BaseCycleContainer* bcc = objs->GetBaseCycleContainer();

    if(bcc->muons) cleaner.MuonCleaner(45,2.1);
    if(bcc->electrons) cleaner.ElectronCleaner(35,2.5);

    //Histsnocuts->Fill();

    //if(!trigger->passSelection()) throw SError( SError::SkipEvent );

    //if(!preselection->passSelection()) throw SError( SError::SkipEvent );
    
    
    if(trigger->passSelection()){HistsTriggerSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
    
    if(preselectionNPrimaryVertexSelection->passSelection()){HistsNPrimaryVertexSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
    
    if(preselectionNElectronSelection->passSelection()){HistsNElectronSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
    
    if(preselectionNMuonSelection->passSelection()){HistsNMuonSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
    
    if(preselectionNJetSelection->passSelection()){HistsNJetSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
    
    if(preselectionNTopJetSelection->passSelection()){HistsNTopJetSelection->Fill();}
    else{throw SError( SError::SkipEvent );}
  
  
  
    /*if(trigger->passSelection())  Histstrigger->Fill();
    else throw SError( SError::SkipEvent );

    if(preselection->passSelection())  Histspreselection->Fill();
    else throw SError( SError::SkipEvent );

    if(nleptbtags->passSelection())  Histsnleptbtags->Fill();
    else throw SError( SError::SkipEvent );

    if(probesele->passSelection())  Histsprobesele->Fill();
    else throw SError( SError::SkipEvent );

    if(htcut->passSelection())  Histshtcut->Fill();
    else throw SError( SError::SkipEvent );

    if(etmiss->passSelection())  Histsetmiss->Fill();
    else throw SError( SError::SkipEvent );
    */

    WriteOutputTree();

    return;
}

