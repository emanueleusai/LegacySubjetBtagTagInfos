#include "include/ExampleHists5.h"
#include "include/ObjectHandler.h"
#include "include/EventCalc.h"
#include <iostream>

using namespace std;

ExampleHists5::ExampleHists5(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

ExampleHists5::~ExampleHists5()
{
  // default destructor, does nothing
}

void ExampleHists5::Init()
{
  // book all histograms here
  Book( TH1F( "shared", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "shared_high", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "shared_low", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "sharedratio", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_low", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_high", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_double", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  
  Book( TH1F( "shared_cut", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "shared_high_cut", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "shared_low_cut", "Shared tracks per subjet", 100, 0, 100));
  Book( TH1F( "sharedratio_cut", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_low_cut", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_high_cut", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  Book( TH1F( "sharedratio_double_cut", "Shared tracks / Total tracks in the subjet", 100, 0, 1));
  
  Book( TH1F( "topjet_pt", "pT distribution of topjets", 100, 0, 1000));
  Book( TH1F( "subjet_pt", "pT distribution of subjets", 100, 0, 1000));
  
  shared_profile = new TProfile("shared_profile","Average shared tracks vs. pT",10,0,1000);
  shared_ratio_profile = new TProfile("shared_ratio_profile","Average shared tracks ratio vs. pT",10,0,1000);
  shared_profile_cut = new TProfile("shared_profile_cut","Average shared tracks vs. pT",10,0,1000);
  shared_ratio_profile_cut = new TProfile("shared_ratio_profile_cut","Average shared tracks ratio vs. pT",10,0,1000);
  shared_profile_subjet = new TProfile("shared_profile_subjet","Average shared tracks vs. pT",10,0,1000);
  shared_ratio_profile_subjet = new TProfile("shared_ratio_profile_subjet","Average shared tracks ratio vs. pT",10,0,1000);
  shared_profile_cut_subjet = new TProfile("shared_profile_cut_subjet","Average shared tracks vs. pT",10,0,1000);
  shared_ratio_profile_cut_subjet = new TProfile("shared_ratio_profile_cut_subjet","Average shared tracks ratio vs. pT",10,0,1000);
}

void ExampleHists5::Fill()
{
  // fill the histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  double weight = calc->GetWeight();
  std::vector<Muon>* muons = calc->GetMuons();

  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();
  std::vector<TopJet> * topjets= bcc->topjets;
  if(!IsRealData)
  {
    for (unsigned int topjet_counter=0;topjet_counter<topjets->size();topjet_counter++)
    {
      
          //check muon and topjet are in opposite emispheres
    double deltaphi=topjets->at(topjet_counter).deltaPhi(muons->at(0));
    //check that the TopJet is HEPTopTagged
    int jettagged=0;
    if(HepTopTag(topjets->at(topjet_counter)))
    {
      jettagged=1;
    }
    //go to next topjet if this jet is not good
    if(!(jettagged&&(deltaphi>(2*PI/3))&&(topjets->at(topjet_counter).pt()>150.)&&(fabs(topjets->at(topjet_counter).eta())<2.5))) continue;
    
    
    
      
      TopJet topjet = topjets->at(topjet_counter);
      Hist("topjet_pt")->Fill(topjet.pt());
      if (topjet.subjets().size()==3)
      {
	for(unsigned int subjet_counter=0;subjet_counter<topjet.subjets().size();subjet_counter++)
	{
	  Hist("subjet_pt")->Fill(topjet.subjets().at(subjet_counter).pt());
	}
	for(unsigned int subjet_counter1=0;subjet_counter1<topjet.subjets().size()-1;subjet_counter1++)
	{
	  for(unsigned int subjet_counter2=subjet_counter1+1;subjet_counter2<topjet.subjets().size();subjet_counter2++)
	  {
	    int counter=0;
	    int counter_cut=0;
	    for(unsigned int track_counter1=0;track_counter1<topjet.subTrackMomentum().at(subjet_counter1).size();track_counter1++)
	    {
	      //if (fabs(topjet.subTrackDeltaR().at(subjet_counter1).at(track_counter1))>0.3) continue;
	      for(unsigned int track_counter2=0;track_counter2<topjet.subTrackMomentum().at(subjet_counter2).size();track_counter2++)
	      {
		//if (fabs(topjet.subTrackDeltaR().at(subjet_counter2).at(track_counter2))>0.3) continue;
		if(
		  fabs(topjet.subTrackMomentum().at(subjet_counter1).at(track_counter1)-topjet.subTrackMomentum().at(subjet_counter2).at(track_counter2))<0.00001 &&
		  fabs(topjet.subTrackEta().at(subjet_counter1).at(track_counter1)-topjet.subTrackEta().at(subjet_counter2).at(track_counter2))<0.00001
		)
		{
		  counter++;
		  if((fabs(topjet.subTrackDeltaR().at(subjet_counter1).at(track_counter1))<0.3)&&(fabs(topjet.subTrackDeltaR().at(subjet_counter2).at(track_counter2))<0.3))
		  {
		    counter_cut++;
		  }
		}//check conditions
	      }//second track
	    }//first track
	    Hist("sharedratio")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    Hist("sharedratio_double")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    Hist("sharedratio_double")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter2).size());
	    Hist("shared")->Fill(counter);
	    if (topjet.pt()>350.0) Hist("shared_high")->Fill(counter); else Hist("shared_low")->Fill(counter);
	    if (topjet.pt()>350.0) Hist("sharedratio_high")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter1).size()); else Hist("sharedratio_low")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    
	    Hist("sharedratio_cut")->Fill(counter_cut*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    Hist("sharedratio_double_cut")->Fill(counter_cut*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    Hist("sharedratio_double_cut")->Fill(counter_cut*1.0/topjet.subTrackMomentum().at(subjet_counter2).size());
	    Hist("shared_cut")->Fill(counter_cut);
	    if (topjet.pt()>350.0) Hist("shared_high_cut")->Fill(counter_cut); else Hist("shared_low_cut")->Fill(counter_cut);
	    if (topjet.pt()>350.0) Hist("sharedratio_high_cut")->Fill(counter_cut*1.0/topjet.subTrackMomentum().at(subjet_counter1).size()); else Hist("sharedratio_low_cut")->Fill(counter_cut*1.0/topjet.subTrackMomentum().at(subjet_counter1).size());
	    //Hist("shared")->Fill(counter*1.0/topjet.subTrackMomentum().at(subjet_counter2).size());
	    
	    float n_total_tracks=1.0*topjet.subTrackMomentum().at(subjet_counter1).size();
	    float topjet_pt=topjet.pt();
	    float subjet_pt=topjet.subjets().at(subjet_counter1).pt();
	    if(topjet_pt>=1000.0) topjet_pt=990.;
	    if(subjet_pt>=1000.0) subjet_pt=990.;
	    if (n_total_tracks>0)
	    {
	      shared_profile->Fill(topjet_pt,counter);
	      shared_ratio_profile->Fill(topjet_pt,counter/n_total_tracks);
	      shared_profile_cut->Fill(topjet_pt,counter_cut);
	      shared_ratio_profile_cut->Fill(topjet_pt,counter_cut/n_total_tracks);
	      
	      shared_profile_subjet->Fill(subjet_pt,counter);
	      shared_ratio_profile_subjet->Fill(subjet_pt,counter/n_total_tracks);
	      shared_profile_cut_subjet->Fill(subjet_pt,counter_cut);
	      shared_ratio_profile_cut_subjet->Fill(subjet_pt,counter_cut/n_total_tracks);
	    }


	  }//second subjet  
	}//first subjet
      }//check subjet number
      else
      {
	std::cout<<"this should not happen"<<std::endl;
      }//check subjet number
    }//topjet
  }//realdata
  
}

void ExampleHists5::Finish()
{
  // final calculations, like division and addition of certain histograms
  TFile * f = new TFile("sharedprofiles.root","RECREATE");
  shared_profile->Write();
  shared_ratio_profile->Write();
  shared_profile_cut->Write();
  shared_ratio_profile_cut->Write();
  shared_profile_subjet->Write();
  shared_ratio_profile_subjet->Write();
  shared_profile_cut_subjet->Write();
  shared_ratio_profile_cut_subjet->Write();
  f->Close();

}

