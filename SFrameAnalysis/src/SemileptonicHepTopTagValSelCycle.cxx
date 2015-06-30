#include <iostream>

using namespace std;

// Local include(s):
#include "include/SemileptonicselectionHists.h"
#include "include/BTagEffHistsHadTop.h"
#include "include/SemileptonicHepTopTagValSelCycle.h"
#include "include/SelectionModules.h"
#include "include/ObjectHandler.h"

ClassImp( SemileptonicHepTopTagValSelCycle );

SemileptonicHepTopTagValSelCycle::SemileptonicHepTopTagValSelCycle()
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

SemileptonicHepTopTagValSelCycle::~SemileptonicHepTopTagValSelCycle()
{
    // destructor
}

void SemileptonicHepTopTagValSelCycle::BeginCycle() throw( SError )
{
    // Start of the job, general set-up and definition of
    // objects are done here

    // Important: first call BeginCycle of base class
    AnalysisCycle::BeginCycle();

    return;

}

void SemileptonicHepTopTagValSelCycle::EndCycle() throw( SError )
{
    // clean-up, info messages and final calculations after the analysis


    // call the base cycle class for all standard methods
    // and a summary of the made selections
    AnalysisCycle::EndCycle();

    return;

}

void SemileptonicHepTopTagValSelCycle::BeginInputData( const SInputData& id ) throw( SError )
{
    // declaration of histograms and selections

    // Important: first call BeginInputData of base class
    AnalysisCycle::BeginInputData( id );

    
    
    /*TopPtWeightHisto = new TH1D("TopPtWeightHisto","TopPtWeightHisto;Weight;Events",500,0.5,2);
    TopPtFullWeightHisto = new TH1D("TopPtFullWeightHisto","TopPtFullWeightHisto;Weight;Events",500,0.5,2);
    TopWeightVsPtHisto = new TH2D("TopWeightVsPtHisto","TopWeightVsPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000);
    TopWeightVsGenPtHisto = new TH2D("TopWeightVsGenPtHisto","TopWeightVsGenPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000);
    EventCount = new TH1D("EventCount","EventCount;before - after;Events",2,0,2);*/
    
    
    //do b tag
    
    bool dobtag = false;
    if(m_BTagEffiFilenameMC.size()>0)
    {
      m_BTagEffiFilenameMC += ".";
      m_BTagEffiFilenameMC += id.GetType();
      m_BTagEffiFilenameMC += ".";
      m_BTagEffiFilenameMC += id.GetVersion();
      m_BTagEffiFilenameMC += "_2.root";
      dobtag=true;
    }

    if(id.GetType()=="DATA" || id.GetType()=="Data" || id.GetType()=="data") dobtag=false;

    m_bsf = NULL;
   
    if(dobtag)
    {
      std::cout << m_BTagEffiFilenameMC << std::endl;
      m_bsf = new BTaggingRoutineTopTag(atof(m_CSVOperatingPoint.c_str()), m_BTaggingMode, m_BTagEffiFilenameMC);
    }
    
    m_tpr = new TopPtReweight();
    
    
    
    // -------------------- set up the selections ---------------------------
   /*
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

    RegisterHistCollection( new SemileptonicselectionHists("histoTriggerSelection") );
    RegisterHistCollection( new SemileptonicselectionHists("histoNPrimaryVertexSelection") );
    RegisterHistCollection( new SemileptonicselectionHists("histoNElectronSelection") );
    RegisterHistCollection( new SemileptonicselectionHists("histoNMuonSelection") );
    RegisterHistCollection( new SemileptonicselectionHists("histoNJetSelection") );
    RegisterHistCollection( new SemileptonicselectionHists("histoNTopJetSelection") );
    */
    
    
    
    
    Selection* nleptbtags = new Selection("nleptbtags");

    //Add again
    nleptbtags->addSelectionModule(new NMuonBTagSelection(1,int_infinity(),e_CSVM,30.,2.5)); // at least one b-topjet in the muon hemisphere with pt>30GeV and eta<2.5

    RegisterSelection(nleptbtags);

    //Add again
    Selection* probesele = new Selection("probesele");

    //if(m_ValidationType == "toptagger"){
      
    //Add again
    probesele->addSelectionModule(new NAntiMuonSubBTagSelection(1,1,e_CSVM,150.,2.5)); // one b-tagged subjets of topjet in the muon anti-hemisphere with pt>150GeV and eta<2.5
      
    //}

    //if(m_ValidationType == "btagging"){

    //Do not add -> for b-tagging validation
    //probesele->addSelectionModule(new NAntiMuonHEPTopSelection(1,1,150.,2.5)); // at least one top-tagged jet in the muon anti-hemisphere with pt>150GeV and eta<2.5

    //}

    RegisterSelection(probesele);

    //Add again
    Selection* htcut = new Selection("htcut");

    htcut->addSelectionModule(new HTlepCut(150.));
 
    RegisterSelection(htcut);

    //Add again
    Selection* etmiss = new Selection("etmiss");

    RegisterSelection(etmiss);

    etmiss->addSelectionModule(new METCut(20.));

    //new
    Selection* njets = new Selection("njets");

    RegisterSelection(njets);
    
    njets->addSelectionModule(new NHadTopJetSelection(1,1,150.,2.5,2*PI/3));//
    
    //new
    Selection* masswindow = new Selection("masswindow");

    RegisterSelection(masswindow);
    
    masswindow->addSelectionModule(/*new NHadTopJetSelection(1,1,150.,2.5,2*PI/3)*/new NAndInvMassMuAK5BtagLeptSelection(1,int_infinity(),80.,150.,150.,e_CSVM,2.5,2*PI/3));//
    
    
    //NAndInvMassMuAK5BtagLeptSelection(int min_nparticle, int max_nparticle,  double min_mass, double max_mass, double ptmin, E_BtagType type, double etamax, double deltaphi)
    
    
    // hep top tag & mass cut combinations
    Selection* heptoptag_masscut = new Selection("heptoptag_masscut");
    RegisterSelection(heptoptag_masscut);
    heptoptag_masscut->addSelectionModule(new heptoptag_masscut_Selection());//
    
    Selection* NOheptoptag_masscut = new Selection("NOheptoptag_masscut");
    RegisterSelection(NOheptoptag_masscut);
    NOheptoptag_masscut->addSelectionModule(new NOheptoptag_masscut_Selection());//
    
    Selection* heptoptag_NOmasscut = new Selection("heptoptag_NOmasscut");
    RegisterSelection(heptoptag_NOmasscut);
    heptoptag_NOmasscut->addSelectionModule(new heptoptag_NOmasscut_Selection());//
    
    Selection* pt200 = new Selection("pt200");
    RegisterSelection(pt200);
    pt200->addSelectionModule(new NHadTopJetSelection(1,1,200.,2.5,2*PI/3));// 
    
    Selection* pt250 = new Selection("pt250");
    RegisterSelection(pt250);
    pt250->addSelectionModule(new NHadTopJetSelection(1,1,250.,2.5,2*PI/3));// 
    
    Selection* pt300 = new Selection("pt300");
    RegisterSelection(pt300);
    pt300->addSelectionModule(new NHadTopJetSelection(1,1,300.,2.5,2*PI/3));// 
    
    RegisterHistCollection( new SemileptonicselectionHists("nocutshists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("triggerhists") );
    //RegisterHistCollection( new SemileptonicPreselectionHists("preselectionhists") );
    RegisterHistCollection( new SemileptonicselectionHists("nleptbtagshists") );
    RegisterHistCollection( new SemileptonicselectionHists("probeselehists") );
    RegisterHistCollection( new SemileptonicselectionHists("htcuthists") );
    RegisterHistCollection( new SemileptonicselectionHists("etmisshists") );
    RegisterHistCollection( new SemileptonicselectionHists("njetshists") );
    RegisterHistCollection( new SemileptonicselectionHists("masswindowhists") );
    
    RegisterHistCollection( new SemileptonicselectionHists("heptoptag_masscut_hists") );
    RegisterHistCollection( new SemileptonicselectionHists("NOheptoptag_NOmasscut_hists") );
    RegisterHistCollection( new SemileptonicselectionHists("NOheptoptag_masscut_hists") );
    RegisterHistCollection( new SemileptonicselectionHists("heptoptag_NOmasscut_hists") );
    RegisterHistCollection( new SemileptonicselectionHists("heptoptag_NOmasscut__NOheptoptag_masscut_hists") );

    RegisterHistCollection( new SemileptonicselectionHists("pt200hists") );
    RegisterHistCollection( new SemileptonicselectionHists("pt250hists") );
    RegisterHistCollection( new SemileptonicselectionHists("pt300hists") );
    
    RegisterHistCollection( new SemileptonicselectionHists("before_tpr_hists") );
    RegisterHistCollection( new SemileptonicselectionHists("after_tpr_hists") );
      
    RegisterHistCollection( new BTagEffHistsHadTop("specialSFeffi") );
    
     // important: initialise histogram collections after their definition
    InitHistos();

    return;
}

void SemileptonicHepTopTagValSelCycle::EndInputData( const SInputData& id ) throw( SError )
{
    AnalysisCycle::EndInputData( id );
    /*TFile * f = new TFile("topptweightcrosscheck.root","RECREATE");
    TopPtWeightHisto->Write();
    TopPtFullWeightHisto->Write();
    TopWeightVsPtHisto->Write();
    TopWeightVsGenPtHisto->Write();
    EventCount->Write();
    f->Close();
    delete f;*/
    return;
}

void SemileptonicHepTopTagValSelCycle::BeginInputFile( const SInputData& id ) throw( SError )
{
    // Connect all variables from the Ntuple file with the ones needed for the analysis
    // The variables are commonly stored in the BaseCycleContaincer

    // important: call to base function to connect all variables to Ntuples from the input tree
    AnalysisCycle::BeginInputFile( id );

    return;
}

void SemileptonicHepTopTagValSelCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError )
{
    // this is the most important part: here the full analysis happens
    // user should implement selections, filling of histograms and results

    // first step: call Execute event of base class to perform basic consistency checks
    // also, the good-run selection is performed there and the calculator is reset
    
    BaseHists* Hists_before_tpr = GetHistCollection("before_tpr_hists");
    BaseHists* Hists_after_tpr = GetHistCollection("after_tpr_hists");
    
    AnalysisCycle::ExecuteEvent( id, weight);
    EventCalc* calc = EventCalc::Instance();
    ObjectHandler* objs = ObjectHandler::Instance();
    BaseCycleContainer* bcc = objs->GetBaseCycleContainer();
    bool IsRealData = calc->IsRealData();
    double weight1=calc->GetWeight();
    //std::cout<<"weight1: "<<calc->GetWeight()<<std::endl;
    if(m_bsf!=NULL) {
      calc->ProduceWeight(m_bsf->GetScaleWeight());
    }//else{cout<<"what";}
    double weight2=calc->GetWeight();
    Hists_before_tpr->Fill();
    //std::cout<<"weight2: "<<calc->GetWeight()<<std::endl;
    if((!IsRealData) && (id.GetVersion()=="TTbarlept" || id.GetVersion()=="TTbarhad" || id.GetVersion()=="TTbarsemi")) {
      calc->ProduceWeight(m_tpr->GetScaleWeight());
    }
    double weight3=calc->GetWeight();
    Hists_after_tpr->Fill();
    //std::cout<<"weight3: "<<calc->GetWeight()<<std::endl<<std::endl;
    //std::cout<<"weight from ratio: "<<weight3/weight2<<std::endl;
    /*TTbarGen* Decay = calc->GetTTbarGen();
    GenParticle topgen=Decay->Top();
    GenParticle antitopgen=Decay->Antitop();
    TopPtWeightHisto->Fill(m_bsf->GetScaleWeight());
    TopPtFullWeightHisto->Fill(calc->GetWeight());
    int tprindex = findTheHighestPtGoodTopJet(bcc);
    if (tprindex>-1) TopWeightVsPtHisto->Fill(bcc->topjets->at(tprindex).pt(),m_bsf->GetScaleWeight());
    TopWeightVsGenPtHisto->Fill(topgen.pt(),m_bsf->GetScaleWeight());
    TopWeightVsGenPtHisto->Fill(antitopgen.pt(),m_bsf->GetScaleWeight());
    EventCount->Fill(0.1,weight2);
    EventCount->Fill(1.1,weight3);*/
    Cleaner cleaner;
    //std::cout<<std::endl;
    //static Selection* trigger = GetSelection("trigger");
    //static Selection* preselectionNPrimaryVertexSelection = GetSelection("preselectionNPrimaryVertexSelection");
    //static Selection* preselectionNElectronSelection = GetSelection("preselectionNElectronSelection");
    //static Selection* preselectionNMuonSelection = GetSelection("preselectionNMuonSelection");
    //static Selection* preselectionNJetSelection = GetSelection("preselectionNJetSelection");//at least two jets with pt>30GeV and eta<2.5
    //static Selection* preselectionNTopJetSelection = GetSelection("preselectionNTopJetSelection");//at least one jet with pt>150GeV and eta<2.5
    //static Selection* preselection = GetSelection("preselection");
    
    
    static Selection* nleptbtags = GetSelection("nleptbtags");
    static Selection* probesele = GetSelection("probesele");
    static Selection* htcut = GetSelection("htcut");
    static Selection* etmiss = GetSelection("etmiss");
    static Selection* njets = GetSelection("njets");
    static Selection* masswindow = GetSelection("masswindow");
    
    static Selection* heptoptag_masscut = GetSelection("heptoptag_masscut");
    static Selection* NOheptoptag_masscut = GetSelection("NOheptoptag_masscut");
    static Selection* heptoptag_NOmasscut = GetSelection("heptoptag_NOmasscut");
    
    static Selection* pt200 = GetSelection("pt200");
    static Selection* pt250 = GetSelection("pt250");
    static Selection* pt300 = GetSelection("pt300");

    //BaseHists* HistsTriggerSelection = GetHistCollection("histoTriggerSelection");
    //BaseHists* HistsNPrimaryVertexSelection = GetHistCollection("histoNPrimaryVertexSelection");
    //BaseHists* HistsNElectronSelection = GetHistCollection("histoNElectronSelection");
    //BaseHists* HistsNMuonSelection = GetHistCollection("histoNMuonSelection");
    //BaseHists* HistsNJetSelection = GetHistCollection("histoNJetSelection");
    //BaseHists* HistsNTopJetSelection = GetHistCollection("histoNTopJetSelection");
    
    BaseHists* Histsnocuts = GetHistCollection("nocutshists");
    //BaseHists* Histstrigger = GetHistCollection("triggerhists");
    //BaseHists* Histspreselection = GetHistCollection("preselectionhists");
    BaseHists* Histsnleptbtags = GetHistCollection("nleptbtagshists");
    BaseHists* Histsprobesele = GetHistCollection("probeselehists");
    BaseHists* Histshtcut = GetHistCollection("htcuthists");
    BaseHists* Histsetmiss = GetHistCollection("etmisshists");
    BaseHists* Histsnjets = GetHistCollection("njetshists");
    BaseHists* Histsmasswindow = GetHistCollection("masswindowhists");
    
    BaseHists* Hists_heptoptag_masscut = GetHistCollection("heptoptag_masscut_hists");
    BaseHists* Hists_NOheptoptag_NOmasscut = GetHistCollection("NOheptoptag_NOmasscut_hists");
    BaseHists* Hists_NOheptoptag_masscut = GetHistCollection("NOheptoptag_masscut_hists");
    BaseHists* Hists_heptoptag_NOmasscut = GetHistCollection("heptoptag_NOmasscut_hists");
    BaseHists* Hists_heptoptag_NOmasscut__NOheptoptag_masscut = GetHistCollection("heptoptag_NOmasscut__NOheptoptag_masscut_hists");
    
    BaseHists* Histspt200 = GetHistCollection("pt200hists");
    BaseHists* Histspt250 = GetHistCollection("pt250hists");
    BaseHists* Histspt300 = GetHistCollection("pt300hists");
    
    BaseHists* specialSFeffi = GetHistCollection("specialSFeffi");

    if(bcc->muons) cleaner.MuonCleaner(45,2.1);
    if(bcc->electrons) cleaner.ElectronCleaner(35,2.5);

    Histsnocuts->Fill();

    //if(!trigger->passSelection()) throw SError( SError::SkipEvent );

    //if(!preselection->passSelection()) throw SError( SError::SkipEvent );
    
    /*
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
    */
  
  
    /*if(trigger->passSelection())  Histstrigger->Fill();
    else throw SError( SError::SkipEvent );

    if(preselection->passSelection())  Histspreselection->Fill();
    else throw SError( SError::SkipEvent );*/

    if(nleptbtags->passSelection())  Histsnleptbtags->Fill();
    else throw SError( SError::SkipEvent );
    
    if(njets->passSelection())  Histsnjets->Fill();
    else throw SError( SError::SkipEvent );
    
    //pt top cuts
    if(pt200->passSelection())  Histspt200->Fill();
    else throw SError( SError::SkipEvent );
    if(pt250->passSelection())  Histspt250->Fill();
    if(pt300->passSelection())  Histspt300->Fill();
    
    specialSFeffi->Fill();
    
    if(probesele->passSelection())  Histsprobesele->Fill();
    else throw SError( SError::SkipEvent );

    if(htcut->passSelection())  Histshtcut->Fill();
    else throw SError( SError::SkipEvent );

    if(etmiss->passSelection())  Histsetmiss->Fill();
    else throw SError( SError::SkipEvent );
    

    
    //we lose too much signal with this cut + data/mc gets around 80% (why?)
    if(masswindow->passSelection())  Histsmasswindow->Fill();
    //else throw SError( SError::SkipEvent );
    

    
    //next cuts are in parallel (= no skip event if not passed)
    //no hep top tag no mass cut
    Hists_NOheptoptag_NOmasscut->Fill();
    //hep top tagger with no mass cut
    if(heptoptag_NOmasscut->passSelection())  Hists_heptoptag_NOmasscut->Fill();
    //mass cut only
    if(NOheptoptag_masscut->passSelection())  Hists_NOheptoptag_masscut->Fill();
    //normal hep top tagger with mass cut
    if(heptoptag_masscut->passSelection())  Hists_heptoptag_masscut->Fill();
    //normal hep top tagger and mass cut separately
    if(heptoptag_NOmasscut->passSelection() && NOheptoptag_masscut->passSelection())  Hists_heptoptag_NOmasscut__NOheptoptag_masscut->Fill();
    

    WriteOutputTree();

    return;
}

