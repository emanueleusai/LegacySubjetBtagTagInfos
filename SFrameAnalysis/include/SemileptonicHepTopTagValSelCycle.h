// Dear emacs, this is -*- c++ -*-
#ifndef SemileptonicHepTopTagValSelCycle_H
#define SemileptonicHepTopTagValSelCycle_H

// SFrame include(s):
#include "include/AnalysisCycle.h"
#include "FactorizedJetCorrector.h"
#include "include/BTaggingRoutineTopTag.h"
#include "include/TopPtReweight.h"
#include "Cleaner.h"

/**
 *  @short Selection cycle to perform 
 *         pre-selection for Z'->ttbar analysis
 *  @author Thomas Peiffer
 */


class SemileptonicHepTopTagValSelCycle : public AnalysisCycle {

public:
  /// Default constructor
  SemileptonicHepTopTagValSelCycle();
  /// Default destructor
  ~SemileptonicHepTopTagValSelCycle();

  /// Function called at the beginning of the cycle
  void BeginCycle() throw( SError );
  /// Function called at the end of the cycle
  void EndCycle() throw( SError );

  /// Function called at the beginning of a new input data
  void BeginInputData( const SInputData& ) throw( SError );
  /// Function called after finishing to process an input data
  void EndInputData  ( const SInputData& ) throw( SError );

  /// Function called after opening each new input file
  void BeginInputFile( const SInputData& ) throw( SError );

  /// Function called for every event
  void ExecuteEvent( const SInputData&, Double_t ) throw( SError );

private:
  //
  // Put all your private variables here
  //
  
  std::string m_ValidationType;
  std::string m_CSVOperatingPoint;
  std::string m_BTagEffiFilenameMC;
  std::string m_BTaggingMode;
  BTaggingRoutineTopTag * m_bsf;
  TopPtReweight * m_tpr;
  
  /*TH1D * TopPtWeightHisto;
  TH1D * TopPtFullWeightHisto;
  TH2D * TopWeightVsPtHisto;
  TH2D * TopWeightVsGenPtHisto;
  TH1D * EventCount;*/
  
  // Macro adding the functions for dictionary generation
  ClassDef( SemileptonicHepTopTagValSelCycle, 0 );

}; // class SemileptonicHepTopTagValSelCycle

#endif // SemileptonicHepTopTagValSelCycle_H

