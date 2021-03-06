// Dear emacs, this is -*- c++ -*-
// $Id: Analysis_LinkDef.h,v 1.24 2013/02/01 12:39:01 peiffer Exp $
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;

// Add the declarations of your cycles, and any other classes for which you
// want to generate a dictionary, here. The usual format is:
//
// #pragma link C++ class MySuperClass+;

#pragma link C++ class AnalysisCycle+;
#pragma link C++ class PileUpHistoCycle+;
//#pragma link C++ class LeptoquarkCycle+;
//#pragma link C++ class LeptoquarkPreSelectionCycle+;
#pragma link C++ class TauEffiCycle+;
#pragma link C++ class ExampleCycle+;
#pragma link C++ class ExampleCycle2+;
#pragma link C++ class ExampleCycle3+;
#pragma link C++ class ExampleCycle4+;
#pragma link C++ class ExampleCycle5+;
#pragma link C++ class EventFilterFromListStandAlone+;

#pragma link C++ class TopJetHists;
#pragma link C++ class JetHists;
#pragma link C++ class EventHists;
#pragma link C++ class ElectronHists;
#pragma link C++ class MuonHists;
#pragma link C++ class BTagEffHists;
#pragma link C++ class BTagEffHistsTopTag+;
#pragma link C++ class BTaggingRoutineTopTag+;
#pragma link C++ class TopPtReweight+;
#pragma link C++ class BTagEffHistsHadTop+;
#pragma link C++ class SemileptonicPreselectionCycle+;
#pragma link C++ class SemileptonicHepTopTagValSelCycle+;

#pragma link C++ class JetLeptonCleanerCycle+;
#pragma link C++ class ZprimePreSelectionCycle+;
#pragma link C++ class ZprimeSelectionCycle+;
#pragma link C++ class ZprimePostSelectionCycle+;
#pragma link C++ class TriggerEffiCycle+;
#pragma link C++ class ZprimeSelectionTrigTestCycle+;
#pragma link C++ class ZprimeSelectionDataTrigTestCycle+;
//#pragma link C++ class ZSelectionCycle+;
#pragma link C++ class ZprimeEleTrigCycle+;
#pragma link C++ class PDFWeightsCycle+;
#endif // __CINT__
