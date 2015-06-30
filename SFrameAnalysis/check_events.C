{

  using namespace std;

  gROOT->Reset();

  std::ofstream gout("summary.txt", ios::out);

  TString inputdirectory="/scratch/hh/dust/naf/cms/user/imarches/newSFrame/Semileptonicselection/";

  TString sampleroot="SemileptonicselectionCycle";

  TString inidir="nocutshists";

  TString enddir="etmisshists";

  TString checkhist="N_topjets";

  const Int_t size=19;

  //Data decomposition
  //A 9174469
  //B1 19418475
  //B2 17416621
  //C1 5842983
  //C2 23656317
  //C3 17768502
  //C4 14359079
  //D1 13949179
  //D2 21178825
  //D3 32613931
  //D4 13714603

  TString inputcheck[size]={
    "MC.TTbarsemi",
    "MC.TTbarlept",
    "MC.TTbarhad",
    //    "MC.WJets1",
    //"MC.WJets2",
    "MC.WJets3",
    "MC.WJets4",
    "MC.ZJets1",
    "MC.ZJets2",
    "MC.ZJets3",
    "MC.ZJets4",
    "MC.singleTbars",
    "MC.singleTbart",
    "MC.singleTbartW",
    "MC.singleTs",
    "MC.singleTt",
    "MC.singleTtW",
    "MC.doubleWW",
    "MC.doubleWZ",
    "MC.doubleZZ"
  }


  Int_t inputnumb[size]={
    25232627,
    12024478,
    41293694,
    //   23033944,
    //33950660,
    15422321,
    13111021,
    21492664,
    21524280,
    10503696,
    6290749,
    139604,
    1930185,
    491463,
    259176,
    3748155,
    495559,
    9982151,
    9495339,
    9780255
  }

  TH1F *inicheck;
  TH1F *endcheck;

  gout << "###ID SampleEvents ProcEvents SeleEvents(no b-tag SF) Correction" << endl;

  for(Int_t it=0;it<size;it++){
    
    TString filename=inputdirectory+sampleroot+"."+inputcheck[it]+".root";

    cout << "Opening " << filename << endl;

    TFile *filecheck = new TFile(filename, "READ");
    
    TString inihist=inidir+"/"+checkhist;
    TString endhist=enddir+"/"+checkhist;

    cout << "Ini hist " << inihist << endl;
    cout << "End hist " << endhist << endl;

    TH1F *inicheck=(TH1F*)filecheck->Get(inihist);
    TH1F *endcheck=(TH1F*)filecheck->Get(endhist);

    cout << "Initial entries " << inputnumb[it] << " vs proof entries " << inicheck->GetEntries() << endl;

    if(inputnumb[it]/inicheck->GetEntries()!=1.0){
      cout << "Need correction factor!!!" << endl;
      gout << inputcheck[it] << " " << inputnumb[it] << " " << inicheck->GetEntries() << " " << endcheck->Integral() << " " << inputnumb[it]/inicheck->GetEntries() << " <======" << endl;
    }
    else{
      gout << inputcheck[it] << " " << inputnumb[it] << " " << inicheck->GetEntries() << " " << endcheck->Integral() << " " << inputnumb[it]/inicheck->GetEntries() << " OK!" << endl;
    }

    Float_t selectedevents=endcheck->Integral();

    filecheck->Close();
    delete filecheck;

  }
  
  gout.close();

  gApplication->Terminate();

}
