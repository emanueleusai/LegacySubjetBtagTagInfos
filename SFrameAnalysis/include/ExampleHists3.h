#ifndef ExampleHists3_H
#define ExampleHists3_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>
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

class ExampleHists3 : public BaseHists {

public:
   /// Named constructor
   ExampleHists3(const char* name);

   /// Default destructor
   ~ExampleHists3();

   void Init();

   void Fill();

   void Finish();

private:
  std::vector<std::string> histo_flavour;
  std::vector<std::string> histo_flavour_descr;
  std::vector<std::string> histo_type;
  std::vector<std::string> histo_type_descr;
  std::vector<int> histo_nbin;
  std::vector<float> histo_minvalue;
  std::vector<float> histo_maxvalue;
}; // class ExampleHists


#endif // ExampleHists3_H
