#ifndef SemileptonicPreselectionHists_H
#define SemileptonicPreselectionHists_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>
#include "TH2.h"

// Local include(s):
#include "include/BaseHists.h"
#include "include/BaseCycleContainer.h"

/**
 *   SemileptonicPreselection class for booking and filling histograms
 *
 *   This class books and fills a collection of histograms.
 *   It should have a unique name, such that the histograms
 *   of multiple instances of this class are ordered in the
 *   output file. 
 *   Always sort your histograms and used methods topically.
 *   This example collection can be used for data and reconstructed
 *   MC events.
 *   
 *   @version $Revision: 1.2 $
 */

class SemileptonicPreselectionHists : public BaseHists {

public:
   /// Named constructor
   SemileptonicPreselectionHists(const char* name);

   /// Default destructor
   ~SemileptonicPreselectionHists();

   void Init();

   void Fill();

   void Finish();

private:

}; // class SemileptonicPreselectionHists


#endif // SemileptonicPreselectionHists_H
