#include "include/ExampleHists3.h"
#include "include/ObjectHandler.h"
#include "include/EventCalc.h"
#include <iostream>

using namespace std;

ExampleHists3::ExampleHists3(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

ExampleHists3::~ExampleHists3()
{
  // default destructor, does nothing
}

void ExampleHists3::Init()
{
  // book all histograms here

  // missing ET and HT
 /* double* logMET_bins = MakeLogBinning(40, 50, 1200);
  Book( TH1F( "MET_lx", "missing E_{T} [GeV]", 40, logMET_bins ) );
  double* logHT_bins = MakeLogBinning(40, 150, 3000);
  Book( TH1F( "HT_lx", "H_{T} [GeV]", 40, logHT_bins ) );
  double* logHTlep_bins = MakeLogBinning(40, 150, 1200);
  Book( TH1F( "HTlep_lx", "H_{T}^{lep} [GeV]", 40, logHTlep_bins ) );

  // jets
  Book( TH1F( "N_jets_ly", "N^{jets}", 20, 0, 20 ) );
  double* logPtjet1_bins = MakeLogBinning(40, 150, 1500);
  double* logPtjet2_bins = MakeLogBinning(40, 50, 1000);
  double* logPtjet3_bins = MakeLogBinning(40, 50, 500);
  double* logPtjet4_bins = MakeLogBinning(40, 50, 250);
  double* logPtjet1234_bins = MakeLogBinning(40, 150, 3000);
  Book( TH1F( "pt_jet1_lx", "p_{T}^{jet 1} [GeV/c]", 40, logPtjet1_bins ) );
  Book( TH1F( "pt_jet2_lx", "p_{T}^{jet 2} [GeV/c]", 40, logPtjet2_bins ) ); 
  Book( TH1F( "pt_jet3_lx", "p_{T}^{jet 3} [GeV/c]", 40, logPtjet3_bins ) );
  Book( TH1F( "pt_jet4_lx", "p_{T}^{jet 4} [GeV/c]", 40, logPtjet4_bins ) );
  Book( TH1F( "pt_jet1234_lx", "p_{T}^{jet 1+2+3+4} [GeV/c]", 40, logPtjet1234_bins ) );
  Book( TH1F( "eta_jet1", "#eta^{jet 1}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet2", "#eta^{jet 2}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet3", "#eta^{jet 3}", 40, -2.5, 2.5) );
  Book( TH1F( "eta_jet4", "#eta^{jet 4}", 40, -2.5, 2.5) );

  // leptons
  Book( TH1F( "N_mu", "N^{#mu}", 10, 0, 10 ) );
  double* logPtlep_bins = MakeLogBinning(40, 45, 500);
  Book( TH1F( "pt_mu_lx", "p_{T}^{#mu} [GeV/c]", 40, logPtlep_bins ) );
  Book( TH1F( "eta_mu", "#eta^{#mu}", 40, -2.1, 2.1) );
  Book( TH1F( "reliso_mu", "#mu rel. Iso", 40, 0, 0.5) );


  // primary vertices
  Book( TH1F( "N_pv", "N^{PV}", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", "N^{evt}", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", "N^{PV}", 24, 0, 24 ) );*/
  /*Book( TH1F( "tracks_pt", "ip tag info tracks pt (GeV)", 100, 0, 40) );
  Book( TH1F( "csv", "csv", 50, 0, 1) );
  Book( TH1F( "ip3dsig", "ip 3d sig", 100, 0, 10) );
  Book( TH1F( "ip3dval", "ip 3d val", 100, 0, 0.05) );
  Book( TH1F( "fd3dsig", "flight dist 3d sig", 15, 0, 50) );
  Book( TH1F( "fd3dval", "flight dist 3d val", 15, 0, 10) );
  Book( TH1F( "vtxmass", "vertex mass", 30, 0, 5) );*/

  /*std::vector<std::string> histo_flavour;
    std::vector<std::string> histo_flavour_descr;*/
  histo_flavour.clear();
  histo_flavour_descr.clear(); 
  histo_flavour.push_back("b"); histo_flavour_descr.push_back("bottom quarks");
  histo_flavour.push_back("c"); histo_flavour_descr.push_back("charm quarks");
  histo_flavour.push_back("uds"); histo_flavour_descr.push_back("up, down and strange quarks");
  histo_flavour.push_back("g"); histo_flavour_descr.push_back("gluons");
  histo_flavour.push_back("none"); histo_flavour_descr.push_back("no flavour recognized");
  histo_flavour.push_back("data"); histo_flavour_descr.push_back("data");
  
  /*std::vector<std::string> histo_type;
  std::vector<std::string> histo_type_descr;
  std::vector<int> histo_nbin;
  std::vector<int> histo_minvalue;
  std::vector<int> histo_maxvalue;*/
  histo_type.clear();
  histo_type_descr.clear();
  //btag variables
  histo_type.push_back("subCSV"); histo_type_descr.push_back("combined secondary vertex discriminator of the subjet");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(1.);
  histo_type.push_back("subFlavour"); histo_type_descr.push_back("matched flavour of the subjet");
  histo_nbin.push_back(4); histo_minvalue.push_back(0.); histo_maxvalue.push_back(4.);
  //track impact parameter tag info
  histo_type.push_back("subTrackMomentum"); histo_type_descr.push_back("momentum of tracks in the subjet");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(15.);
  histo_type.push_back("subTrackEta"); histo_type_descr.push_back("pseudorapidity of tracks in the subjet");
  histo_nbin.push_back(100); histo_minvalue.push_back(-5.); histo_maxvalue.push_back(5.);
  histo_type.push_back("subTrackEtaRel"); histo_type_descr.push_back("track pseudorapidity, relative to the jet axis");
  histo_nbin.push_back(100); histo_minvalue.push_back(-5.); histo_maxvalue.push_back(5.);
  histo_type.push_back("subTrackDeltaR"); histo_type_descr.push_back("track pseudoangular distance from the jet axis");
  histo_nbin.push_back(100); histo_minvalue.push_back(-1.); histo_maxvalue.push_back(1.);
  histo_type.push_back("subTrackSip3dVal"); histo_type_descr.push_back("track 3D signed impact parameter");
  histo_nbin.push_back(100); histo_minvalue.push_back(-0.1); histo_maxvalue.push_back(0.1);
  histo_type.push_back("subTrackSip3dSig"); histo_type_descr.push_back("track 3D signed impact parameter significance");
  histo_nbin.push_back(100); histo_minvalue.push_back(-35.); histo_maxvalue.push_back(35.);
  histo_type.push_back("subTrackSip2dVal"); histo_type_descr.push_back("track 2D signed impact parameter");
  histo_nbin.push_back(100); histo_minvalue.push_back(-10.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackSip2dSig"); histo_type_descr.push_back("track 2D signed impact parameter significance");
  histo_nbin.push_back(100); histo_minvalue.push_back(-10.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackDecayLenVal"); histo_type_descr.push_back("track decay length");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(25.);
  histo_type.push_back("subTrackChi2"); histo_type_descr.push_back("track fit chi2");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackNTotalHits"); histo_type_descr.push_back("number of valid total hits");
  histo_nbin.push_back(20); histo_minvalue.push_back(0.); histo_maxvalue.push_back(20.);
  histo_type.push_back("subTrackNPixelHits"); histo_type_descr.push_back("number of valid pixel hits");
  histo_nbin.push_back(9); histo_minvalue.push_back(0.); histo_maxvalue.push_back(9.);
  histo_type.push_back("subTrackPtRel"); histo_type_descr.push_back("track transverse momentum, relative to the jet axis");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subTrackPPar"); histo_type_descr.push_back("track parallel momentum, along the jet axis");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subTrackPtRatio"); histo_type_descr.push_back("track transverse momentum, relative to the jet axis, normalized to its energy");
  histo_nbin.push_back(100); histo_minvalue.push_back(-10.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackPParRatio"); histo_type_descr.push_back("track parallel momentum, along the jet axis, normalized to its energy");
  histo_nbin.push_back(100); histo_minvalue.push_back(-10.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackJetDistVal"); histo_type_descr.push_back("minimum track approach distance to jet axis");
  histo_nbin.push_back(100); histo_minvalue.push_back(-0.3); histo_maxvalue.push_back(0.01);
  histo_type.push_back("subTrackJetDistSig"); histo_type_descr.push_back("minimum track approach distance to jet axis significance");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subTrackGhostTrackDistVal"); histo_type_descr.push_back("minimum approach distance to ghost track");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subTrackGhostTrackDistSig"); histo_type_descr.push_back("minimum approach distance to ghost track significance");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subTrackGhostTrackWeight"); histo_type_descr.push_back("weight of track participation in ghost track fit");
  histo_nbin.push_back(100); histo_minvalue.push_back(-1.); histo_maxvalue.push_back(10.);
  //secondary vertex tag info
  histo_type.push_back("subFlightDistance2dVal"); histo_type_descr.push_back("transverse distance between primary and secondary vertex");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subFlightDistance2dSig"); histo_type_descr.push_back("transverse distance significance between primary and secondary vertex");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subFlightDistance3dVal"); histo_type_descr.push_back("distance between primary and secondary vertex");
  histo_nbin.push_back(100); histo_minvalue.push_back(-50.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subFlightDistance3dSig"); histo_type_descr.push_back("distance significance between primary and secondary vertex");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(80.);
  histo_type.push_back("subVertexJetDeltaR"); histo_type_descr.push_back("pseudoangular distance between jet axis and secondary vertex direction");
  histo_nbin.push_back(100); histo_minvalue.push_back(-10.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subJetNSecondaryVertices"); histo_type_descr.push_back("number of reconstructed possible secondary vertices in jet");
  histo_nbin.push_back(8); histo_minvalue.push_back(0.); histo_maxvalue.push_back(8.);
  histo_type.push_back("subVertexNTracks"); histo_type_descr.push_back("number of tracks at secondary vertex");
  histo_nbin.push_back(20); histo_minvalue.push_back(0.); histo_maxvalue.push_back(20.);

  histo_type.push_back("subSecondaryVertex"); histo_type_descr.push_back("secondary vertex uncorrected mass");///////
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subVertexChi2"); histo_type_descr.push_back("secondary vertex chi2");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subVertexNdof"); histo_type_descr.push_back("secondary vertex fit dergrees of frendom");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(50.);
  histo_type.push_back("subVertexNormalizedChi2"); histo_type_descr.push_back("secondary vertex fit normalized chi2");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subVertexTracksSize"); histo_type_descr.push_back("secondary vertex tracks collection size");
  histo_nbin.push_back(50); histo_minvalue.push_back(0.); histo_maxvalue.push_back(50.);
  //JTC SV variables
  histo_type.push_back("subVertexCategoryJTC"); histo_type_descr.push_back("secondary vertex category from jet tag computer");
  histo_nbin.push_back(5); histo_minvalue.push_back(0.); histo_maxvalue.push_back(5.);
  histo_type.push_back("subVertexMassJTC"); histo_type_descr.push_back("secondary vertex corrected mass from jet tag computer");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(8.);
  histo_type.push_back("subVertexEnergyRatioJTC"); histo_type_descr.push_back("ratio of energy at secondary vertex over total energy from JTC");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(10.);
  histo_type.push_back("subTrackSip3dSigAboveCharmJTC"); histo_type_descr.push_back("track 3D signed impact parameter significance of first track lifting mass above charm from JTC");
  histo_nbin.push_back(100); histo_minvalue.push_back(0.); histo_maxvalue.push_back(50.);



  //histo_type.push_back(""); histo_type_descr.push_back("");
  for(unsigned int i=0; i<histo_type.size(); i++)
    {
      for(unsigned int j=0; j<histo_flavour.size(); j++)
	{
	  std::string histo_name;
	  std::string histo_descr;
	  std::stringstream histo_name_stream;
	  std::stringstream histo_descr_stream;
	  //int nbin;
	  //int minvalue;
	  //int maxvalue;
	  histo_name_stream<<histo_type[i]<<"_"<<histo_flavour[j];
	  histo_descr_stream<<histo_type_descr[i]<<" from "<<histo_flavour_descr[j];
	  histo_name = histo_name_stream.str();
	  histo_descr = histo_descr_stream.str();
	  Book( TH1F( histo_name.c_str(), histo_descr.c_str(), histo_nbin[i], histo_minvalue[i], histo_maxvalue[i]) );
	}
    }

}

void ExampleHists3::Fill()
{
  // fill the histograms


  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  //LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  //int run = calc->GetRunNum();
  //  std::cout<<"run number here "<<run<<std::endl;

  //int lumiblock = calc->GetLumiBlock();
  //int Npvs = calc->GetPrimaryVertices()->size();
  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();

  //int NTopJets = bcc-> topjets -> size();
  std::vector<TopJet> * topjets= bcc->topjets;
  //std::vector<TopJet> topjets2= *(bcc->topjets);
  //if (topjets->size()>0) std::cout<<HepTopTag(topjets->at(0))<<std::endl;
  //std::cout<<NTopJets;

  /*
  //loop on topjets in the event
  for (unsigned int i=0;i<topjets->size();i++)
    {
      //METTI IF PER I DATI
      //loop on subjets
      for(unsigned int j=0;j<topjets->at(i).subjets().size();j++)
	{ 
	  Hist("csv")->Fill(topjets->at(i).subCSV().at(j),weight);
	  //loop on ip track tag info
	  for(unsigned int k=0;k<topjets->at(i).subTrackMomentum().at(j).size();k++)
	    {
	      Hist("tracks_pt")->Fill(topjets->at(i).subTrackMomentum().at(j).at(k), weight);
	      Hist("ip3dval")->Fill(topjets->at(i).subTrackSip3dVal().at(j).at(k), weight);
	      Hist("ip3dsig")->Fill(topjets->at(i).subTrackSip3dSig().at(j).at(k), weight);
	    }
	  //loop on ip track tag info
	  for(unsigned int k=0;k<topjets->at(i).subFlightDistance3dVal().at(j).size();k++)
	    {
	      Hist("fd3dsig")->Fill(topjets->at(i).subFlightDistance3dSig().at(j).at(k), weight);
	      Hist("fd3dval")->Fill(topjets->at(i).subFlightDistance3dVal().at(j).at(k), weight);

	    }
	      Hist("vtxmass")->Fill(topjets->at(i).subVertexMassJTC().at(j), weight);
	}
      //loop on sv tag info
    }
  */


//obtain muon collection
  std::vector<Muon>* muons = calc->GetMuons();



  //loop on topjets in the event
  std::string tmps;
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
    
      //loop on subjets
      for(unsigned int subjet_counter=0;subjet_counter<topjets->at(topjet_counter).subjets().size();subjet_counter++)
	{ 
	  int flavour_pdg=topjets->at(topjet_counter).subFlavour().at(subjet_counter);
	  int flavour_index=0;
	  if(!IsRealData)
	  {
	    if ( flavour_pdg == 1 ||flavour_pdg == 2 || flavour_pdg == 3 ||flavour_pdg == -1 ||flavour_pdg == -2 || flavour_pdg == -3 )
	    {
	      flavour_index = 2;//up, down, or strange
	    }
	    else
	    {
	      if(flavour_pdg == 4 || flavour_pdg == -4 )
	      {
		flavour_index = 1;//charm
	      }
	      else
	      {
		if( flavour_pdg == 5 || flavour_pdg == -5 )
		{
		  flavour_index = 0;//bottom
		}
		else
		{
		  if(flavour_pdg == 21 || flavour_pdg == -21)
		  {
		    flavour_index = 3;//gluon
		  }
		  else
		  {
		    flavour_index = 4;//no flavour recognized
		  }
		}
	      }
	    }
	  }
	  else
	  {
	    flavour_index = 5;//data
	  }
	  //std::cout<< topjets->at(topjet_counter).subFlavour().at(subjet_counter)<<"_";
	  //TopJet a=topjets2[0];//.subFlavour().at(subjet_counter);
	  //if(topjets2[topjet_counter].subFlavour()[subjet_counter]!=21){int a=topjets2[topjet_counter].subFlavour()[subjet_counter]; flavour_index=a; std::cout<<topjets2[topjet_counter].subFlavour()[subjet_counter]<<" ";}flavour_index=0;
	  /* switch ((int)topjets2[topjet_counter].subFlavour()[subjet_counter]) 
	    {
	    case 1:
	    case 2:
	    case 3:
	      flavour_index=2;//up, down, or strange
	      break;
	    case 4:
	      flavour_index=1;//charm
	      break;
	    case 5:
	      flavour_index=0;//bottom
	      break;
	    case 21:
	      flavour_index=3;//gluon
	      break;
	    default:
	      {std::cout<<topjets2[topjet_counter].subFlavour()[subjet_counter]<<" ";
		flavour_index=4;break;//no flavour recognized
	      }break;
	      }*/
	  //if (flavour_index==4) std::cout<<topjets->at(topjet_counter).subFlavour().at(subjet_counter)<<" ";
          tmps.assign("subCSV");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subCSV().at(subjet_counter),weight);
          tmps.assign("subFlavour");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subFlavour().at(subjet_counter),weight);

	  //loop on ip track tag info
	  for(unsigned int track_counter=0;track_counter<topjets->at(topjet_counter).subTrackMomentum().at(subjet_counter).size();track_counter++)
	    {
	      tmps.assign("subTrackMomentum");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackMomentum().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackEta");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackEta().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackEtaRel");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackEtaRel().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackDeltaR");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackDeltaR().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackSip3dVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackSip3dVal().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackSip3dSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackSip3dSig().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackSip2dVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackSip2dVal().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackSip2dSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackSip2dSig().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackDecayLenVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackDecayLenVal().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackChi2");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackChi2().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackNTotalHits");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackNTotalHits().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackNPixelHits");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackNPixelHits().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackPtRel");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackPtRel().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackPPar");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackPPar().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackPtRatio");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackPtRatio().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackPParRatio");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackPParRatio().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackJetDistVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackJetDistVal().at(subjet_counter).at(track_counter),weight);
	      //std::cout<<topjets->at(topjet_counter).subTrackJetDistVal().at(subjet_counter).at(track_counter)<<std::endl;
	      tmps.assign("subTrackJetDistSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackJetDistSig().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackGhostTrackDistVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackGhostTrackDistVal().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackGhostTrackDistSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackGhostTrackDistSig().at(subjet_counter).at(track_counter),weight);
	      tmps.assign("subTrackGhostTrackWeight");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackGhostTrackWeight().at(subjet_counter).at(track_counter),weight);
	    }
	  //loop on sv track tag info
	  for(unsigned int sv_counter=0;sv_counter<topjets->at(topjet_counter).subFlightDistance3dVal().at(subjet_counter).size();sv_counter++)
	    {
	      tmps.assign("subFlightDistance2dVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subFlightDistance2dVal().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subFlightDistance2dSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subFlightDistance2dSig().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subFlightDistance3dVal");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subFlightDistance3dVal().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subFlightDistance3dSig");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subFlightDistance3dSig().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subVertexJetDeltaR");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexJetDeltaR().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subSecondaryVertex");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subSecondaryVertex().at(subjet_counter).at(sv_counter).M(),weight);
	      tmps.assign("subVertexChi2");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexChi2().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subVertexNdof");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexNdof().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subVertexNormalizedChi2");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexNormalizedChi2().at(subjet_counter).at(sv_counter),weight);
	      tmps.assign("subVertexTracksSize");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	      Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexTracksSize().at(subjet_counter).at(sv_counter),weight);
	    }
	  tmps.assign("subJetNSecondaryVertices");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subJetNSecondaryVertices().at(subjet_counter),weight);
	  tmps.assign("subVertexNTracks");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexNTracks().at(subjet_counter),weight);
	  //JTC
	  tmps.assign("subVertexCategoryJTC");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexCategoryJTC().at(subjet_counter),weight);
	  tmps.assign("subVertexMassJTC");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexMassJTC().at(subjet_counter),weight);
	  tmps.assign("subVertexEnergyRatioJTC");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subVertexEnergyRatioJTC().at(subjet_counter),weight);
	  tmps.assign("subTrackSip3dSigAboveCharmJTC");tmps.append("_");tmps.append(histo_flavour.at(flavour_index));
	  Hist(tmps.c_str())->Fill(topjets->at(topjet_counter).subTrackSip3dSigAboveCharmJTC().at(subjet_counter),weight);
	}
    }












   //std::cout<<bcc->topjets->at(0)->subjets.size();
 /* Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
    Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }*/

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );
/*
  MET* met = calc->GetMET();
  Hist("MET_lx")->Fill(met->pt(), weight);

  double HT = calc->GetHT();
  Hist("HT_lx")->Fill(HT, weight);

  double HTlep = calc->GetHTlep();
  Hist("HTlep_lx")->Fill(HTlep, weight);

  std::vector<Jet>* jets = calc->GetJets();
  int Njets = jets->size();

  //std::cout<<"run number here "<<NTopJets<<std::endl;

  Hist("N_jets_ly")->Fill(Njets, weight);

  if(Njets>=1){
    Hist("pt_jet1_lx")->Fill(jets->at(0).pt(), weight);
    Hist("eta_jet1")->Fill(jets->at(0).eta(), weight);
  }
  if(Njets>=2){
    Hist("pt_jet2_lx")->Fill(jets->at(1).pt(), weight);
    Hist("eta_jet2")->Fill(jets->at(1).eta(), weight);
  }
  if(Njets>=3){
    Hist("pt_jet3_lx")->Fill(jets->at(2).pt(), weight);
    Hist("eta_jet3")->Fill(jets->at(2).eta(), weight);
  }
  if(Njets>=4){
    Hist("pt_jet4_lx")->Fill(jets->at(3).pt(), weight);
    Hist("pt_jet1234_lx")->Fill(jets->at(0).pt()+jets->at(1).pt()+jets->at(2).pt()+jets->at(3).pt(), weight);
    Hist("eta_jet4")->Fill(jets->at(3).eta(), weight);
  }

*/

  /* std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  std::cout<<Nmuons;*/
 /* Hist("N_mu")->Fill(Nmuons, weight);
  for (int i=0; i<Nmuons; ++i){
    Muon thismu = muons->at(i);
    Hist("pt_mu_lx")->Fill(thismu.pt(), weight);
    Hist("eta_mu")->Fill(thismu.eta(), weight);

    Hist("reliso_mu")->Fill(thismu.relIso(), weight);
  }*/


}

void ExampleHists3::Finish()
{
  // final calculations, like division and addition of certain histograms
 /* EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }*/

}

