// Dear emacs, this is -*- c++ -*-
// $Id: ExampleCycle.h,v 1.3 2012/12/07 14:21:52 peiffer Exp $
#ifndef ExampleCycle4_H
#define ExampleCycle4_H

// SFrame include(s):
#include "include/AnalysisCycle.h"
#include "include/SelectionModules.h"
#include "include/ExampleHists2.h"
#include "include/ObjectHandler.h"
#include "include/HypothesisHists.h"
#include "include/BTaggingRoutineTopTag.h"


/**
 *   @short Example of an analysis cycle
 *
 *          This is an example of an analysis cycle. It can be used
 *          as a template for writing your own analysis. Also should
 *          be used for quick cross checks of the system setup.
 *
 *  @author Roman Kogler
 *  @version $Revision: 1.3 $
 */

class ExampleCycle4 : public AnalysisCycle {

public:
  /// Default constructor
  ExampleCycle4();
  /// Default destructor
  ~ExampleCycle4();

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

  // Macro adding the functions for dictionary generation
  std::string m_CSVOperatingPoint;
  std::string m_BTagEffiFilenameMC;
  std::string m_BTaggingMode;
  BTaggingRoutineTopTag * m_bsf;
  ClassDef( ExampleCycle4, 0 );

}; // class ExampleCycle

#endif // ExampleCycle4_H

