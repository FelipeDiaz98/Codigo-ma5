#ifndef analysis_Analysis_h
#define analysis_Analysis_h

#include "SampleAnalyzer/Process/Analyzer/AnalyzerBase.h"
#include <TH1F.h>
#include <TFile.h>
#include <vector>
#include <boost/tuple/tuple.hpp>

namespace MA5
{
class Analysis : public AnalyzerBase
{
  INIT_ANALYSIS(Analysis,"Analysis")

//fullyHadronic: 
//dijets: pt, m, dR, eta, phi, notmerged, partiallymerged, fullymerged, smallestdr.

  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************
  //general plots dijet1 *****************************************************************************
  TH1F* plot_N_Merged1;
  
  //general plots dijet1 *****************************************************************************
  TH1F* plot_PT_dijet1;
  TH1F* plot_ETA_dijet1;
  TH1F* plot_M_dijet1;
  TH1F* plot_PHI_dijet1;
  TH1F* plot_DR_dijet1;
  
  //general plots b_dijet1 ***************************************************************************
  TH1F* plot_PT_b_dijet1;
  TH1F* plot_ETA_b_dijet1;
  TH1F* plot_M_b_dijet1;
  TH1F* plot_PHI_b_dijet1;
  TH1F* plot_DR_b_dijet1;
  
  //DIJET1 *******************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  TH1F* plot_PT_dijet1_not;
  TH1F* plot_ETA_dijet1_not;
  TH1F* plot_M_dijet1_not;
  TH1F* plot_PHI_dijet1_not;
  TH1F* plot_DR_dijet1_not;
  
  //plots of the dijet1 pairs that are partially merged.
  TH1F* plot_PT_dijet1_partially;
  TH1F* plot_ETA_dijet1_partially;
  TH1F* plot_M_dijet1_partially;
  TH1F* plot_PHI_dijet1_partially;
  TH1F* plot_DR_dijet1_partially;
  
  //plots of the dijet1 pairs that are fully merged.
  TH1F* plot_PT_dijet1_fully;
  TH1F* plot_ETA_dijet1_fully;
  TH1F* plot_M_dijet1_fully;
  TH1F* plot_PHI_dijet1_fully;
  TH1F* plot_DR_dijet1_fully;
  
  //B_DIJET1 *****************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  TH1F* plot_PT_b_dijet1_partially;
  TH1F* plot_ETA_b_dijet1_partially;
  TH1F* plot_M_b_dijet1_partially;
  TH1F* plot_PHI_b_dijet1_partially;
  TH1F* plot_DR_b_dijet1_partially;
  
  //plots of the b_dijet1 pairs that are fully merged.
  TH1F* plot_PT_b_dijet1_fully;
  TH1F* plot_ETA_b_dijet1_fully;
  TH1F* plot_M_b_dijet1_fully;
  TH1F* plot_PHI_b_dijet1_fully;
  TH1F* plot_DR_b_dijet1_fully;
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************
  //general plots dijet2 *****************************************************************************
  TH1F* plot_N_Merged2;
  TH1F* plot_Smallest_DR_dijet;
  TH1F* plot_Smallest_DR_b_dijet;
  
  //general plots dijet2 *****************************************************************************
  TH1F* plot_PT_dijet2;
  TH1F* plot_ETA_dijet2;
  TH1F* plot_M_dijet2;
  TH1F* plot_PHI_dijet2;
  TH1F* plot_DR_dijet2;
  
  //general plots b_dijet2 ***************************************************************************
  TH1F* plot_PT_b_dijet2;
  TH1F* plot_ETA_b_dijet2;
  TH1F* plot_M_b_dijet2;
  TH1F* plot_PHI_b_dijet2;
  TH1F* plot_DR_b_dijet2;
  
  //DIJET2 *******************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  TH1F* plot_PT_dijet2_not;
  TH1F* plot_ETA_dijet2_not;
  TH1F* plot_M_dijet2_not;
  TH1F* plot_PHI_dijet2_not;
  TH1F* plot_DR_dijet2_not;
  
  //plots of the dijet2 pairs that are partially merged.
  TH1F* plot_PT_dijet2_partially;
  TH1F* plot_ETA_dijet2_partially;
  TH1F* plot_M_dijet2_partially;
  TH1F* plot_PHI_dijet2_partially;
  TH1F* plot_DR_dijet2_partially;
  
  //plots of the dijet2 pairs that are fully merged.
  TH1F* plot_PT_dijet2_fully;
  TH1F* plot_ETA_dijet2_fully;
  TH1F* plot_M_dijet2_fully;
  TH1F* plot_PHI_dijet2_fully;
  TH1F* plot_DR_dijet2_fully;
  
  //B_DIJET2 *****************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  TH1F* plot_PT_b_dijet2_partially;
  TH1F* plot_ETA_b_dijet2_partially;
  TH1F* plot_M_b_dijet2_partially;
  TH1F* plot_PHI_b_dijet2_partially;
  TH1F* plot_DR_b_dijet2_partially;
  
  //plots of the b_dijet2 pairs that are fully merged.
  TH1F* plot_PT_b_dijet2_fully;
  TH1F* plot_ETA_b_dijet2_fully;
  TH1F* plot_M_b_dijet2_fully;
  TH1F* plot_PHI_b_dijet2_fully;
  TH1F* plot_DR_b_dijet2_fully;
  
  
   
  /*
  TH1F* plot_deltaR_b1b2;
  TH1F* plot_PT_leptons;
  TH1F* plot_ETA_leptons;
  TH1F* plot_PT_b1;
  TH1F* plot_MET;
  TH1F* plot_sdETA_b1b2;

  TH1F* plot_PT_b_not_used;
  TH1F* plot_ETA_b_not_used;
  TH1F* plot_sdPHI_lMET;
  */

 public:
  virtual bool Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters);
  virtual void Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files);
  virtual bool Execute(SampleFormat& sample, const EventFormat& event);

 private:
 
 	//Arrays of all final state particles.
 	std::vector<const MCParticleFormat*> FinalStateLeptons;
 	std::vector<const MCParticleFormat*> FinalStateNeutrinos;
 	std::vector<const MCParticleFormat*> FinalStateJs;
 	std::vector<const MCParticleFormat*> FinalStateBs;
 	//Indexes of the different final state jets: 4 for the fully-hadronic channel and 2 for the semi-leptonic channel. Pairs are always indentified as (j1,j2) and (j3,j4) in fully-hadronic.
 	MAuint32 index_j1;
 	MAuint32 index_j2;
 	MAuint32 index_j3;
 	MAuint32 index_j4;
	//Indexes of the different final state b quarks: Always 2 for both channels. Pairs are always indentified as (j1,j2,b1) and (j3,j4,b2) for the fully-hadronic.
	//In the semi-leptonic, index_b2 makes reference to the b quark not used (the one coming from the leptonic decaying top).
 	MAuint32 index_b1;
 	MAuint32 index_b2;
 	//Four-momentum of the reconstructed W (dijet) and top quark (b_dijet). The second pair is only used in the fully-hadronic.
 	MALorentzVector dijet1;
 	MALorentzVector b_dijet1;
 	MALorentzVector dijet2;
 	MALorentzVector b_dijet2;
 	//Vectors that state wether the dijets and b_dijets were producted not, partially or fully merged. Both (only first) components used in fully-hadronic (semi-leptonic) channel.
 	std::vector<bool> notMerged;
 	std::vector<bool> partiallyMerged;
 	std::vector<bool> fullyMerged;
 	//Vector that states in the first (second) component if the dijets (b_dijets) are the possible pairs that minimize the dR. Only used for fully-hadronic. 
 	std::vector<bool> smallestdr;
 	
 	
 	
 	
 	
 	//Indicates if the particle given is a final state lepton.
 	bool IsFinalState_lepton(const MCParticleFormat* particle){
 	
 		bool final_state = false;
 		if ((particle != 0) && (PHYSICS->Id->IsFinalState(particle))){
 			if ((particle->pdgid()==15) || (particle->pdgid()==13) || (particle->pdgid()==11) || (particle->pdgid()==-15) || (particle->pdgid()==-13) || (particle->pdgid()==-11)){
 				final_state = true;
 			}
 		}
 		return final_state;
 	}

	//Indicates if the particle given is a final state neutrino.
 	bool IsFinalState_neutrino(const MCParticleFormat* particle){
 	
 		bool final_state = false;
 		if ((particle != 0) && (PHYSICS->Id->IsFinalState(particle))){
 			if ((particle->pdgid()==16) || (particle->pdgid()==14) || (particle->pdgid()==12) || (particle->pdgid()==-16) || (particle->pdgid()==-14) || (particle->pdgid()==-12)){
 				final_state = true;
 			}
 		}
 		return final_state;
 	}
 	
 	//Indicates if the particle given is a final state quark b.
 	bool IsFinalState_b(const MCParticleFormat* particle){
 	
 		bool final_state = false;
 		if ((particle != 0) && (PHYSICS->Id->IsFinalState(particle))){
 			if ((particle->pdgid()==5) || (particle->pdgid()==-5)){
 				final_state = true;
 			}
 		}
 		return final_state;
 	}
 	
 	//Indicates if the particle given is a final state jet.
 	bool IsFinalState_j(const MCParticleFormat* particle){
 	
 		bool final_state = false;
 		if ((particle != 0) && (PHYSICS->Id->IsFinalState(particle))){
 			if ((particle->pdgid()==1) || (particle->pdgid()==2) || (particle->pdgid()==3) || (particle->pdgid()==4) || (particle->pdgid()==-1) || (particle->pdgid()==-2) || (particle->pdgid()==-3) || (particle->pdgid()==-4)){
 				final_state = true;
 			}
 		}
 		return final_state;
 	}
 	
 	//Fills the vectors of final state particles classified by wether they are leptons, neutrinos, js or bs.
 	void ClassifyParticles(const MCParticleFormat* particle, std::vector<const MCParticleFormat*> &FinalStateLeptons, std::vector<const MCParticleFormat*> &FinalStateNeutrinos, std::vector<const MCParticleFormat*> &FinalStateJs, std::vector<const MCParticleFormat*> &FinalStateBs){
 	
 		if (IsFinalState_lepton(particle) == true){
 			FinalStateLeptons.push_back(particle);
 		}
 		if (IsFinalState_neutrino(particle) == true){
 			FinalStateNeutrinos.push_back(particle);
 		}
 		if (IsFinalState_b(particle) == true){
 			FinalStateBs.push_back(particle);
 		}
 		if (IsFinalState_j(particle) == true){
 			FinalStateJs.push_back(particle);
 		}
 	}
 	
 	//Returns the indexes not use for dijet reconstruction. The first pair of dijet comes from the pair with index (0, index).
 	boost::tuple<int, int> RemainingIndexes(int index){
 		
 		if (index == 1){
 			return boost::make_tuple(2,3);
 		}
 		if (index == 2){
 			return boost::make_tuple(1,3);
 		}
 		else{
 			return boost::make_tuple(1,2);
 		}
 	}
 	
 	//Define selection criteria for selection of dijet pairs for W and t reconstruction, the pairs of jets and bs must be PT ordered. Index2 and index5 are the PT index
 	//of the jet that acompanies the greatest PT jet in the first dijet pair , and the PT index of the b that acompanies this first dijet pair.
 	boost::tuple<int, int> ReconstructedEvent(std::vector<const MCParticleFormat*> jets, std::vector<const MCParticleFormat*> b){
 	
		MAuint32 index2 = 0;
		Double_t best_Err = 999999.9;
		Double_t Mt = 172.76;
		Double_t MW = 80.379;
		
		for (MAuint32 i = 1; i < jets.size(); i++){
		
				MAuint32 indextemp1;
				MAuint32 indextemp2;
				MALorentzVector jtemp1 = jets[0]->momentum();
				MALorentzVector jtemp2 = jets[i]->momentum();
				Double_t Err1 = (abs((jtemp1 + jtemp2).M() - MW))*100/MW;
				boost::tie(indextemp1, indextemp2) = RemainingIndexes(i);
				MALorentzVector jtemp3 = jets[indextemp1]->momentum();
				MALorentzVector jtemp4 = jets[indextemp2]->momentum();
				Double_t Err2 = (abs((jtemp3 + jtemp4).M() - MW))*100/MW;
	 				
				if (Err1 + Err2 < best_Err){
					best_Err = Err1 + Err2;
					index2 = i;
				}
		}
		
		MAuint32 index5 = 0;
		Double_t best_Err_b = 999999.9;
		MALorentzVector dijet1 = jets[0]->momentum() + jets[index2]->momentum();
		MAuint32 index3;
		MAuint32 index4;
		boost::tie(index3, index4) = RemainingIndexes(index2);
		MALorentzVector dijet2 = jets[index3]->momentum() + jets[index4]->momentum();
		
		for (MAuint32 j = 0; j < b.size(); j++){
	
				MALorentzVector b_dijet1 = b[j]->momentum() + dijet1;
				MALorentzVector b_dijet2 = b[1-j]->momentum() + dijet2;
				Double_t Err3 = (abs(b_dijet1.M() - Mt))*100/Mt;
				Double_t Err4 = (abs(b_dijet2.M() - Mt))*100/Mt;
	 				
				if (Err3 + Err4 < best_Err_b){
					best_Err_b = Err3 + Err4;
					index5 = j;
				}	
		}
		return boost::make_tuple(index2,index5);
 	}
 	
 	//Checks if the dijets (0, index) and the remaining others, are the ones with the smallest sum of dR. Same for the b_dijet (0, index, b_index) and the rest.
 	std::vector<bool> SmallestDR(std::vector<const MCParticleFormat*> jets, std::vector<const MCParticleFormat*> b, int index, int b_index){
	
		std::vector<bool> smallest;
		smallest.push_back(true);
		smallest.push_back(true);
		MALorentzVector jet1 = jets[0]->momentum();
		MALorentzVector jet2 = jets[index]->momentum();
		MAuint32 index3;
		MAuint32 index4;
		boost::tie(index3, index4) = RemainingIndexes(index);
		MALorentzVector jet3 = jets[index3]->momentum();
		MALorentzVector jet4 = jets[index4]->momentum();
		Double_t best_dR = jet1.DeltaR(jet2) + jet3.DeltaR(jet4);
		
		for (MAuint32 i = 1; i < jets.size(); i++){
		
			if (smallest[0] != false){
				MAuint32 indextemp1;
				MAuint32 indextemp2;
				MALorentzVector jtemp1 = jets[0]->momentum();
				MALorentzVector jtemp2 = jets[i]->momentum();
				boost::tie(indextemp1, indextemp2) = RemainingIndexes(i);
				MALorentzVector jtemp3 = jets[indextemp1]->momentum();
				MALorentzVector jtemp4 = jets[indextemp2]->momentum();
				Double_t dR = jtemp1.DeltaR(jtemp2) + jtemp3.DeltaR(jtemp4);
	 			
	 			if (jets[i] != jets[index]){	
					if (dR < best_dR){
						smallest[0] = false;
					}
				}
			}
		}
		
		MALorentzVector dijet1 = (jet1 + jet2);
		MALorentzVector b1 = b[b_index]->momentum();
		MALorentzVector dijet2 = (jet3 + jet4);
		MALorentzVector b2 = b[1 - b_index]->momentum();
		Double_t b_dR = b1.DeltaR(dijet1) + b2.DeltaR(dijet2);
		Double_t temp_b_dR = b1.DeltaR(dijet2) + b2.DeltaR(dijet1);
	 			
		if (temp_b_dR < b_dR){
			smallest[1] = false;
		}
		return smallest;
	}
 	
 	//Defines the two dijets and b_dijets coming from the fully hadronic channel using the criteria defined in ReconstructedEvent, checking if they are not, partially or fully merged.
	//The two components of the bool vectors notMerged, partiallyMerged, fullyMerged and smallestdr are used (each component for each pair), b_used is not used (all bs are used).
	//Remember jets has 4 jets in this channel.
 	void MergedFullyHadronic(std::vector<const MCParticleFormat*> jets, std::vector<const MCParticleFormat*> b, MA5::MALorentzVector &dijet1, MA5::MALorentzVector &dijet2, MA5::MALorentzVector &b_dijet1, MA5::MALorentzVector &b_dijet2){
 		
		index_j1 = 0;
		boost::tie(index_j2, index_b1) = ReconstructedEvent(jets, b);
		std::vector<int> indexesj;
		indexesj.push_back(index_j1);
		indexesj.push_back(index_j2);
		boost::tie(index_j3, index_j4) = RemainingIndexes(index_j2);
		indexesj.push_back(index_j3);
		indexesj.push_back(index_j4);
		
		std::vector<int> indexesb;
		indexesb.push_back(index_b1);
		index_b2 = 1 - index_b1;
		indexesb.push_back(index_b2);
		
		smallestdr = SmallestDR(jets, b, index_j2, index_b1);
		dijet1 = MALorentzVector();
		b_dijet1 = MALorentzVector();
		dijet2 = MALorentzVector();
		b_dijet2 = MALorentzVector();
		
		for (MAuint32 i = 0; i < 2; i++){
		
			MALorentzVector jet1 = jets[indexesj[2*i]]->momentum();
			MALorentzVector jet2 = jets[indexesj[(2*i) + 1]]->momentum();
			MALorentzVector dijet = jet1 + jet2;
			
			Double_t dR_dijet = jet1.DeltaR(jet2);
			
			if (i == 0){
				dijet1 = dijet;
			}
			if (i == 1){
				dijet2 = dijet;
			}
 		
			if (dR_dijet > 0.8){
				notMerged.push_back(true);
				partiallyMerged.push_back(false);
				fullyMerged.push_back(false);
			}
	
			else{
				notMerged.push_back(false);
				MALorentzVector p_b = b[indexesb[i]]->momentum();
				MALorentzVector b_dijet = p_b + dijet;
				Double_t dR_bdijet = p_b.DeltaR(dijet);
			
				if (i == 0){
					b_dijet1 = b_dijet;
				}
				if (i == 1){
					b_dijet2 = b_dijet;
				}
				if (dR_bdijet > 1.0){
					fullyMerged.push_back(false);
					partiallyMerged.push_back(true);
				}
				else{
					fullyMerged.push_back(true);
					partiallyMerged.push_back(false);
				}
			}
		}
	}
	
	//Defines the dijet and b_dijet coming from the semi leptonic channel searching for the smallest dr between the dijet and bs (2), checking if they are not, partially or fully merged.
	//Only the first component of the bool vectors notMerged, partiallyMerged and fullyMerged are used, smallestdr is not used (as there is only one possible pair).
	//Rememeber jets now only has 2 jets.
	void MergedSemiLeptonic(std::vector<const MCParticleFormat*> jets, std::vector<const MCParticleFormat*> b, MA5::MALorentzVector &dijet1, MA5::MALorentzVector &b_dijet1){
	
		index_j1 = 0;
		index_j2 = 1;
		MALorentzVector jet1 = jets[index_j1]->momentum();
		MALorentzVector jet2 = jets[index_j2]->momentum();
		
		dijet1 = MALorentzVector();
		b_dijet1 = MALorentzVector();
		dijet1 = jet1 + jet2;
		Double_t dR_dijet = jet1.DeltaR(jet2);
 		
		if (dR_dijet > 0.8){
			notMerged.push_back(true);
			partiallyMerged.push_back(false);
			fullyMerged.push_back(false);
		}
	
		else{
			notMerged.push_back(false);
			Double_t best_dR = 999999.9;
			for (MAuint32 i = 0; i < b.size(); i++){
				const MALorentzVector p_b = b[i]->momentum();
				Double_t dR = p_b.DeltaR(dijet1);
				if (dR < best_dR){
					best_dR = dR;
					index_b1 = i;
				}
			}	
		
			index_b2 = 1 - index_b1;
			b_dijet1 = b[index_b1]->momentum() + dijet1;
			
			if (best_dR > 1.0){
				fullyMerged.push_back(false);
				partiallyMerged.push_back(true);
			}
			else{
				fullyMerged.push_back(true);
				partiallyMerged.push_back(false);
			}
		}
	}
	

	//Organizes the final state vectors in terms of their PT (greatest to smallest).
      	void OrganizeByPT(std::vector<const MCParticleFormat*> &initialVector){
      		
      		std::vector<const MCParticleFormat*> newVector;
      		for (MAuint32 i = 0; i < initialVector.size(); i++){
      		
      			std::vector<const MCParticleFormat*> temporalVector = SORTER->rankFilter(initialVector,i+1,PTordering);
      			newVector.push_back(temporalVector[0]);
      			temporalVector.clear();	
      		}
      		initialVector.clear();
      		initialVector = newVector;	
      	}
	
		
};
}

#endif
