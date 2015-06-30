#ifndef ExampleHists5_H
#define ExampleHists5_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>
#include "TProfile.h"
#include "TH2.h"

// Local include(s):
#include "include/BaseHists.h"
#include "include/BaseCycleContainer.h"

/**
 *   Example class for booking and filling histograms
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

class ExampleHists5 : public BaseHists {

public:
   /// Named constructor
   ExampleHists5(const char* name);

   /// Default destructor
   ~ExampleHists5();

   void Init();

   void Fill();

   void Finish();

private:
 TProfile * shared_profile;
 TProfile * shared_ratio_profile;
 TProfile * shared_profile_cut;
 TProfile * shared_ratio_profile_cut;
 TProfile * shared_profile_subjet;
 TProfile * shared_ratio_profile_subjet;
 TProfile * shared_profile_cut_subjet;
 TProfile * shared_ratio_profile_cut_subjet;
}; // class ExampleHists


#endif // ExampleHists5_H
