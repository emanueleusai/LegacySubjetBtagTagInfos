#include "include/SelectionModules.h"


TriggerSelection::TriggerSelection(std::string triggername)
{
    m_name=triggername;
}

bool TriggerSelection::pass(BaseCycleContainer *bcc)
{
    for(unsigned int i=0; i<bcc->triggerNames_actualrun.size(); ++i) {
        if(!bcc->triggerNames_actualrun.at(i).find(m_name)) {
            return bcc->triggerResults->at(i);
        }
    }
    std::cout<< "WARNING: trigger not found: " << m_name <<"; reject this event." << std::endl;
    for(unsigned int i=0; i<bcc->triggerNames_actualrun.size(); ++i) {
        std::cout << "   "  << bcc->triggerNames_actualrun.at(i) << std::endl;
    }
    return false;
}

std::string TriggerSelection::description()
{
    return "Trigger: "+m_name;
}

NMuonSelection::NMuonSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NMuonSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->muons->size(); ++i) {
        if(bcc->muons->at(i).pt()>m_ptmin && fabs(bcc->muons->at(i).eta())<m_etamax) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NMuonSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of muons <= %d, with pt>%.1f GeV, abs(eta)<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}

NElectronSelection::NElectronSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}


bool NElectronSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->electrons->size(); ++i) {
        if(bcc->electrons->at(i).pt()>m_ptmin && fabs(bcc->electrons->at(i).eta())<m_etamax) nparticle++; 
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}


std::string NElectronSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of electrons <= %d, with pt>%.1f GeV, abs(eta)<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}


NTauSelection::NTauSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NTauSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->taus->size(); ++i) {
        if(bcc->taus->at(i).pt()>m_ptmin && fabs(bcc->taus->at(i).eta())<m_etamax) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NTauSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of taus <= %d, with pt>%.1f GeV, abs(eta)<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}


NJetSelection::NJetSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NJetSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->jets->size(); ++i) {
        if(bcc->jets->at(i).pt()>m_ptmin && fabs(bcc->jets->at(i).eta())<m_etamax) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NJetSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of jets <= %d, with pt>%.1f GeV, abs(eta)<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}


NTopJetSelection::NTopJetSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NTopJetSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->topjets->size(); ++i) {
        if(bcc->topjets->at(i).pt()>m_ptmin && fabs(bcc->topjets->at(i).eta())<m_etamax) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NTopJetSelection::description()
{
    char s[100];
    sprintf(s, "%d <= N(CA-jets) <= %d, with pt>%.1f GeV, |eta|<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}







NHadTopJetSelection::NHadTopJetSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax, double deltaphi)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
    m_deltaphi=deltaphi;
}

bool NHadTopJetSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->topjets->size(); ++i) {
        if(bcc->topjets->at(i).pt()>m_ptmin && fabs(bcc->topjets->at(i).eta())<m_etamax && bcc->topjets->at(i).deltaPhi(bcc->muons->at(0))>m_deltaphi) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NHadTopJetSelection::description()
{
    char s[100];
    sprintf(s, "%d <= N(CA-jets) <= %d, with pt>%.1f GeV, |eta|<%.1f, |deltaphi(topjet,muon)|<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax,m_deltaphi);

    return s;
}













NAndInvMassMuAK5BtagLeptSelection::NAndInvMassMuAK5BtagLeptSelection(int min_nparticle, int max_nparticle,  double min_mass, double max_mass, double ptmin, E_BtagType type, double etamax, double deltaphi)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
    m_deltaphi=deltaphi;
    m_min_mass=min_mass;
    m_max_mass=max_mass;
    m_type=type;
}

bool NAndInvMassMuAK5BtagLeptSelection::pass(BaseCycleContainer *bcc)
{
  int nparticle=0;
  for(unsigned int i=0; i<bcc->jets->size(); ++i) 
  {
    Jet jet = bcc->jets->at(i);
    Muon muon = bcc->muons->at(0);
    bool isbtagged=false;
    if(m_type==e_CSVL && jet.btag_combinedSecondaryVertex()>0.244) isbtagged=true;
    if(m_type==e_CSVM && jet.btag_combinedSecondaryVertex()>0.679) isbtagged=true;
    if(m_type==e_CSVT && jet.btag_combinedSecondaryVertex()>0.898) isbtagged=true;
    /*if(m_type==e_JPL && jet.btag_jetProbability()>0.275) isbtagged=true;
    if(m_type==e_JPM && jet.btag_jetProbability()>0.545) isbtagged=true;
    if(m_type==e_JPT && jet.btag_jetProbability()>0.790) isbtagged=true;*/
    double deltaPhi = jet.deltaPhi( muon );
    double invmass = ( jet.v4() + muon.v4() ).M();
    bool masswindow = ( ( invmass > m_min_mass ) && ( invmass < m_max_mass ) );
    
    if(jet.pt()>m_ptmin && fabs(jet.eta())<m_etamax && deltaPhi<m_deltaphi && isbtagged && masswindow) nparticle++;
  }
  return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NAndInvMassMuAK5BtagLeptSelection::description()
{
    char s[500];
    sprintf(s, "%d <= N(AK5-jets) <= %d, with pt>%.1f GeV, |eta|<%.1f, |deltaphi(AK5-jet,mu)|<%.1f, %.1f<M_inv(mu,AK5-jet)<%.1f, btag",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax,m_deltaphi,m_min_mass,m_max_mass);

    return s;
}















NPrunedJetSelection::NPrunedJetSelection(int min_nparticle, int max_nparticle, double ptmin, double etamax)
{
    m_min_nparticle=min_nparticle;
    m_max_nparticle=max_nparticle;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NPrunedJetSelection::pass(BaseCycleContainer *bcc)
{
    int nparticle=0;
    for(unsigned int i=0; i<bcc->prunedjets->size(); ++i) {
        if(bcc->prunedjets->at(i).pt()>m_ptmin && fabs(bcc->prunedjets->at(i).eta())<m_etamax) nparticle++;
    }
    return nparticle>=m_min_nparticle && nparticle<=m_max_nparticle;
}

std::string NPrunedJetSelection::description()
{
    char s[100];
    sprintf(s, "%d <= N(pruned jets) <= %d, with pt>%.1f GeV, |eta|<%.1f",m_min_nparticle,m_max_nparticle,m_ptmin,m_etamax);

    return s;
}



NTopTagSelection::NTopTagSelection(int min_ntoptag, int max_ntoptag)
{
    m_min_ntoptag=min_ntoptag;
    m_max_ntoptag=max_ntoptag;
}

bool NTopTagSelection::pass(BaseCycleContainer *bcc)
{

    int ntoptag=0;

    for(unsigned int i=0; i< bcc->topjets->size(); ++i) {
        TopJet topjet =  bcc->topjets->at(i);
        double mmin=0;
        double mjet=0;
        int nsubjets=0;
        if(TopTag(topjet,mjet,nsubjets,mmin)) ntoptag++;
    }
    if(ntoptag<m_min_ntoptag) return false;
    if(ntoptag>m_max_ntoptag) return false;
    return true;

}

std::string NTopTagSelection::description()
{
    char s[100];
    sprintf(s, "%d <= N(top-tags) <= %d",m_min_ntoptag,m_max_ntoptag);
    return s;
}

NWTagSelection::NWTagSelection(int min_nwtag, int max_nwtag)
{
    m_min_nwtag=min_nwtag;
    m_max_nwtag=max_nwtag;
}

bool NWTagSelection::pass(BaseCycleContainer *bcc)
{

    int nwtag=0;

    for(unsigned int i=0; i< bcc->prunedjets->size(); ++i) {
        TopJet prunedjet =  bcc->prunedjets->at(i);
        double mmin=0;
        double mjet=0;
        int nsubjets=0;
        if(WTag(prunedjet,mjet,nsubjets,mmin)) nwtag++;
    }
    if(nwtag<m_min_nwtag) return false;
    if(nwtag>m_max_nwtag) return false;
    return true;

}

std::string NWTagSelection::description()
{
    char s[100];
    sprintf(s, "%d <= N(W-tags) <= %d",m_min_nwtag,m_max_nwtag);
    return s;
}


NBTagSelection::NBTagSelection(int min_nbtag, int max_nbtag, E_BtagType type)
{
    m_min_nbtag=min_nbtag;
    m_max_nbtag=max_nbtag;
    m_type=type;
}

bool NBTagSelection::pass(BaseCycleContainer *bcc)
{
    int nbtag=0;
    for(unsigned int i=0; i<bcc->jets->size(); ++i) {
        if(m_type==e_CSVL && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.244) nbtag++;
        if(m_type==e_CSVM && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.679) nbtag++;
        if(m_type==e_CSVT && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.898) nbtag++;
        if(m_type==e_JPL && bcc->jets->at(i).btag_jetProbability()>0.275) nbtag++;
        if(m_type==e_JPM && bcc->jets->at(i).btag_jetProbability()>0.545) nbtag++;
        if(m_type==e_JPT && bcc->jets->at(i).btag_jetProbability()>0.790) nbtag++;
    }

    if(nbtag<m_min_nbtag) return false;
    if(nbtag>m_max_nbtag) return false;
    return true;
}

std::string NBTagSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of b-tags <= %d",m_min_nbtag,m_max_nbtag);
    return s;
}



NPrimaryVertexSelection::NPrimaryVertexSelection(int min_npv, int max_npv)
{
    m_min_npv=min_npv;
    m_max_npv=max_npv;
}

bool NPrimaryVertexSelection::pass(BaseCycleContainer *bcc)
{

    int npv=bcc->pvs->size();

    if(npv<m_min_npv) return false;
    if(npv>m_max_npv) return false;
    return true;

}

std::string NPrimaryVertexSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of primary vertices <= %d",m_min_npv,m_max_npv);
    return s;
}



HTlepCut::HTlepCut(double min_htlep, double max_htlep)
{
    m_min_htlep = min_htlep;
    m_max_htlep = max_htlep;
}

bool HTlepCut::pass(BaseCycleContainer *bcc)
{
    //double htlep = HTlep(bcc);
    EventCalc* calc = EventCalc::Instance();
    double htlep = calc->GetHTlep();
    if( htlep < m_min_htlep) return false;
    if( htlep > m_max_htlep) return false;
    return true;

}

std::string HTlepCut::description()
{
    char s[100];
    sprintf(s, "%.1f GeV < HTlep < %.1f GeV",m_min_htlep,m_max_htlep);
    return s;
}


METCut::METCut(double min_met, double max_met)
{
    m_min_met = min_met;
    m_max_met = max_met;
}

bool METCut::pass(BaseCycleContainer *bcc)
{
    double MET = bcc->met->pt();
    if( MET < m_min_met) return false;
    if( MET > m_max_met) return false;
    return true;

}

std::string METCut::description()
{
    char s[100];
    sprintf(s, "%.1f GeV < MET < %.1f GeV",m_min_met,m_max_met);
    return s;
}


bool TwoDCut::pass(BaseCycleContainer *bcc)
{

    //make sure that you have cleaned the electron and muon collections: bcc should content only one charged lepton
    //clean jets for pt>25 GeV before calling this routine
    for(unsigned int i=0; i<bcc->electrons->size(); ++i) {
        //std::cout<< deltaRmin(&(bcc->electrons->at(i)), bcc->jets) << "   " << pTrel(&(bcc->electrons->at(i)), bcc->jets) << std::endl;
        if(deltaRmin(&(bcc->electrons->at(i)), bcc->jets)<0.5 && pTrel(&(bcc->electrons->at(i)), bcc->jets)<25)
            return false;
    }
    for(unsigned int i=0; i<bcc->muons->size(); ++i) {
        if(deltaRmin(&(bcc->muons->at(i)), bcc->jets)<0.5 && pTrel(&(bcc->muons->at(i)), bcc->jets)<25)
            return false;
    }

    return true;
}

std::string TwoDCut::description()
{
    char s[100];
    sprintf(s, "2D cut");
    return s;
}

bool TwoDCutMuon::pass(BaseCycleContainer *bcc)
{
    // same as above, but only for muons
    for(unsigned int i=0; i<bcc->muons->size(); ++i) {
        if(deltaRmin(&(bcc->muons->at(i)), bcc->jets)<0.5 && pTrel(&(bcc->muons->at(i)), bcc->jets)<25)
            return false;
    }

    return true;
}

std::string TwoDCutMuon::description()
{
    char s[100];
    sprintf(s, "2D cut");
    return s;
}

bool MuonElectronOSCut::pass(BaseCycleContainer *bcc)
{

    // make sure that you have cleaned the electron and muon collections: bcc should contain at least one muon and one electron
    // this cut looks only at the leading muon and leading electron
    if ( bcc->electrons->size()==0) return false;
    if ( bcc->muons->size()==0) return false;
    
    if (bcc->electrons->at(0).charge() == bcc->muons->at(0).charge()) return false;

    return true;
}

std::string MuonElectronOSCut::description()
{
    char s[100];
    sprintf(s, "Opposite sign of leading muon and leading electron");
    return s;
}

bool TriangularCut::pass(BaseCycleContainer *bcc)
{
    if(bcc->electrons->size()!=1) {
        std::cout << "WARNING: called triangular cut but electron collection contains " << bcc->electrons->size()<< " !=1 entries. Cut is not applied" <<std::endl;
        return true;
    }
    if(bcc->jets->size()<1) {
        std::cout << "WARNING: called triangular cut but jet collection is empty. Cut is not applied" <<std::endl;
        return true;
    }

    double k=1.5/75.;

    Particle METp;
    METp.set_pt(bcc->met->pt());
    METp.set_phi(bcc->met->phi());
    METp.set_eta(0);
    METp.set_energy(0);

    if(METp.deltaPhi(bcc->electrons->at(0)) > k* METp.pt()+1.5) return false;
    if(METp.deltaPhi(bcc->electrons->at(0)) < -1*k* METp.pt()+1.5) return false;
    if(METp.deltaPhi(bcc->jets->at(0)) > k* METp.pt()+1.5) return false;
    if(METp.deltaPhi(bcc->jets->at(0)) < -1*k* METp.pt()+1.5) return false;

    return true;
}

std::string TriangularCut::description()
{
    char s[100];
    sprintf(s, "triangular cut");
    return s;
}

HypothesisDiscriminatorCut::HypothesisDiscriminatorCut(HypothesisDiscriminator* discr, double min_discr, double max_discr)
{
    m_discr=discr;
    m_min_discr = min_discr;
    m_max_discr = max_discr;
}

bool HypothesisDiscriminatorCut::pass(BaseCycleContainer *bcc)
{

    ReconstructionHypothesis *hyp = m_discr->GetBestHypothesis();

    if(!hyp) {
        // std::cout << "WARNING: no hypothesis " << m_discr->GetLabel() << " found, event is rejected." <<std::endl;
        return false;
    }

    double discr_value = hyp->discriminator(m_discr->GetLabel());

    if(discr_value<m_min_discr || discr_value>m_max_discr) return false;

    return true;
}

std::string HypothesisDiscriminatorCut::description()
{
    char s[100];
    sprintf(s, "%.1f < %s discriminator < %.1f",m_min_discr,m_discr->GetLabel().c_str(),m_max_discr);
    return s;
}

HypothesisLeptopPtCut::HypothesisLeptopPtCut(HypothesisDiscriminator* discr, double min_discr, double max_discr)
{
    m_discr=discr;
    m_min_discr = min_discr;
    m_max_discr = max_discr;
}

bool HypothesisLeptopPtCut::pass(BaseCycleContainer *bcc)
{
    ReconstructionHypothesis *hyp = m_discr->GetBestHypothesis();

    if(!hyp) {
        std::cout << "WARNING: no hypothesis " << m_discr->GetLabel() << " found, event is rejected." <<std::endl;
        return false;
    }

    double discr_value = hyp->toplep_v4().Pt();

    if(discr_value<m_min_discr || discr_value>m_max_discr) return false;

    return true;
}

std::string HypothesisLeptopPtCut::description()
{
    char s[100];
    sprintf(s, "%.1f < %s leptop m < %.1f",m_min_discr,m_discr->GetLabel().c_str(),m_max_discr);
    return s;
}

MttbarGenCut::MttbarGenCut(double mttbar_min, double mttbar_max)
{
    m_mttbar_min = mttbar_min;
    m_mttbar_max = mttbar_max;
}

bool MttbarGenCut::pass(BaseCycleContainer *bcc)
{
    EventCalc* calc = EventCalc::Instance();
    if(!calc->GetGenParticles() ) {
        if (!calc->GetTTbarGen()) {
            return true;
        }
    }

    double mttbar_gen = ( calc->GetTTbarGen()->Top().v4() + calc->GetTTbarGen()->Antitop().v4()).M();
    if( mttbar_gen < m_mttbar_min) return false;
    if( mttbar_gen > m_mttbar_max) return false;
    return true;
}

std::string MttbarGenCut::description()
{
    char s[100];
    sprintf(s, "%.1f < MttbarGen < %.1f",m_mttbar_min, m_mttbar_max);
    return s;
}

EventFlavorSelection::EventFlavorSelection(E_EventFlavor flavor)
{
    m_flavor = flavor;
}

bool EventFlavorSelection::pass(BaseCycleContainer *bcc)
{
    std::map<int,int> counter;
    for(unsigned int i=0; i<bcc->jets->size(); ++i) {
        Jet jet = bcc->jets->at(i);
        int flavor = abs(JetFlavor(&jet));
        // std::cout << flavor << " ";
        if (counter.find(flavor) == counter.end())
            counter[flavor] = 1;
        else
            counter[flavor] = counter[flavor] + 1;
    }
    
    // std::cout << std::endl;

    if (m_flavor == e_BFlavor && 
        counter.find(5) != counter.end()) {
        // std::cout << "It is a BFlavor event." << std::endl;
        return true;
    }
    if (m_flavor == e_CFlavor && 
        counter.find(5) == counter.end() &&
        counter.find(4) != counter.end()) {
        // std::cout << "It is a CFlavor event." << std::endl;
        return true;
    }
    if (m_flavor == e_LFlavor && 
        counter.find(5) == counter.end() &&
        counter.find(4) == counter.end()) {
        // std::cout << "It is a LFlavor event." << std::endl;
        return true;
    }

    return false;
}

std::string EventFlavorSelection::description()
{
    char s[100], flavor;
    if (m_flavor == e_BFlavor)
        flavor = 'B';
    else if (m_flavor == e_CFlavor)
        flavor = 'C';
    else
        flavor = 'L';
    sprintf(s, "Filtering by event %c flavor" , flavor);
    return s;
}

EventFilterSelection::EventFilterSelection(const std::string eventfile)
{
  m_evfilter = new EventFilterFromListStandAlone(eventfile);
  m_filename = eventfile;
}

EventFilterSelection::~EventFilterSelection()
{
  delete m_evfilter;
}

bool EventFilterSelection::pass(BaseCycleContainer* bcc)
{
  return m_evfilter->filter(bcc->run, bcc->luminosityBlock, bcc->event);
}

std::string EventFilterSelection::description()
{
  char s[500];
  sprintf(s, "selection of events based on file: %s", m_filename.c_str());
  return s;

}

NAntiMuonSubBTagSelection::NAntiMuonSubBTagSelection(int min_nbtag, int max_nbtag, E_BtagType type, double ptmin, double etamax )
{
    m_min_nbtag=min_nbtag;
    m_max_nbtag=max_nbtag;
    m_type=type;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NAntiMuonSubBTagSelection::pass(BaseCycleContainer *bcc)
{
    int nbtag=0;

    //Assumes to have only one muon

    for(unsigned int i=0; i<bcc->topjets->size(); ++i) {
      int jettagged=0;

      std::vector<Particle> subjets_top;
      std::vector<float> btagsub_combinedSecondaryVertex_top;
      subjets_top=bcc->topjets->at(i).subjets();
      btagsub_combinedSecondaryVertex_top=bcc->topjets->at(i).btagsub_combinedSecondaryVertex();

      for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){

	float test=btagsub_combinedSecondaryVertex_top[j];

	if(m_type==e_CSVL && test>0.244) jettagged=1;
	if(m_type==e_CSVM && test>0.679) jettagged=1;
	if(m_type==e_CSVT && test>0.898) jettagged=1;
	
      }

      if(bcc->muons->size() != 1){
	std::cout << "ATTENTION!!! muon size " << bcc->muons->size() << std::endl;
      }

      double deltaphi=bcc->topjets->at(i).deltaPhi(bcc->muons->at(0));
      
      if(jettagged&&(deltaphi>(2*PI/3))&&(bcc->topjets->at(i).pt()>m_ptmin)&&(fabs(bcc->topjets->at(i).eta())<m_etamax)){

	nbtag++;

      }

    }

    if(nbtag<m_min_nbtag) return false;
    if(nbtag>m_max_nbtag) return false;
    return true;
}

std::string NAntiMuonSubBTagSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of sub-b-tagged top jets in the muon anti-hemisphere <= %d",m_min_nbtag,m_max_nbtag);
    return s;
}

NMuonBTagSelection::NMuonBTagSelection(int min_nbtag, int max_nbtag, E_BtagType type, double ptmin, double etamax )
{
    m_min_nbtag=min_nbtag;
    m_max_nbtag=max_nbtag;
    m_type=type;
    m_ptmin=ptmin;
    m_etamax=etamax;
}

bool NMuonBTagSelection::pass(BaseCycleContainer *bcc)
{
    int nbtag=0;

    //Assumes to have only one muon

    for(unsigned int i=0; i<bcc->jets->size(); ++i) {
      int jettagged=0;
      if(m_type==e_CSVL && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.244) jettagged=1;
      if(m_type==e_CSVM && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.679) jettagged=1;
      if(m_type==e_CSVT && bcc->jets->at(i).btag_combinedSecondaryVertex()>0.898) jettagged=1;

      if(bcc->muons->size() != 1){
	std::cout << "ATTENTION!!! muon size " << bcc->muons->size() << std::endl;
      }

      double deltaphi=bcc->jets->at(i).deltaPhi(bcc->muons->at(0));
      
      if(jettagged&&(deltaphi<(2*PI/3))&&(bcc->jets->at(i).pt()>m_ptmin)&&(fabs(bcc->jets->at(i).eta())<m_etamax)){

	nbtag++;

      }

    }

    if(nbtag<m_min_nbtag) return false;
    if(nbtag>m_max_nbtag) return false;
    return true;
}

std::string NMuonBTagSelection::description()
{
    char s[100];
    sprintf(s, "%d <= number of b-tags in the muon hemisphere <= %d",m_min_nbtag,m_max_nbtag);
    return s;
}






heptoptag_masscut_Selection::heptoptag_masscut_Selection(){}
bool heptoptag_masscut_Selection::pass(BaseCycleContainer *bcc)
{
  int TheGoodTopJet=findTheHighestPtGoodTopJet(bcc);
  if (TheGoodTopJet<0) return false;
  return HepTopTag(bcc->topjets->at(TheGoodTopJet));
}
std::string heptoptag_masscut_Selection::description(){return "HEPTopTag with top mass cut";}

NOheptoptag_masscut_Selection::NOheptoptag_masscut_Selection(){}
bool NOheptoptag_masscut_Selection::pass(BaseCycleContainer *bcc)
{
  int TheGoodTopJet=findTheHighestPtGoodTopJet(bcc);
  if (TheGoodTopJet<0) return false;
  TopJet topjet=bcc->topjets->at(TheGoodTopJet);
  double mjet;
  LorentzVector allsubjets(0,0,0,0);
  for(int j=0; j<topjet.numberOfDaughters(); ++j)
  {
    allsubjets += topjet.subjets()[j].v4();
  }
  if(!allsubjets.isTimelike())
  {
    mjet=0;
    return false;
  }
  mjet = allsubjets.M();
  return ( ( mjet > 115. ) && ( mjet < 250. ) );
}
std::string NOheptoptag_masscut_Selection::description(){return "Top mass cut";}

heptoptag_NOmasscut_Selection::heptoptag_NOmasscut_Selection(){}
bool heptoptag_NOmasscut_Selection::pass(BaseCycleContainer *bcc)
{
  int TheGoodTopJet=findTheHighestPtGoodTopJet(bcc);
  if (TheGoodTopJet<0) return false;
  return HepTopTagNoMassCut(bcc->topjets->at(TheGoodTopJet));
}
std::string heptoptag_NOmasscut_Selection::description(){return "HEPTopTag without top mass cut";}
