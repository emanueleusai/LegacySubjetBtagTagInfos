#ifndef BTagEffHistsTopTag_H
#define BTagEffHistsTopTag_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>

// Local include(s):
#include "include/BaseHists.h"
#include "include/BaseCycleContainer.h"
#include "include/Utils.h"

/**
 *   Class for booking and filling btag histograms
 *
 *   
 *   @version $Revision: 1.1 $
 */

class BTagEffHistsTopTag : public BaseHists {

public:
   /// Named constructor
   BTagEffHistsTopTag(const char*,float csv = 0.679);

   /// Default destructor
   ~BTagEffHistsTopTag();

   void Init();

   void Fill();

   void Finish();
   

private:

  E_BtagType m_type;
  float m_CSVOperatingPoint;

}; // class BTagEffHistsTopTag

#endif // BTagEffHistsTopTag_H

