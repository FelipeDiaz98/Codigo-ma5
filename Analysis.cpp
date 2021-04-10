#include "SampleAnalyzer/User/Analyzer/Analysis.h"
#include "SampleAnalyzer/Interfaces/root/RootMainHeaders.h"
#include <TFile.h>
#include <TCanvas.h>
#include <vector>
using namespace MA5;
using namespace std;

// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool Analysis::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
{
  cout << "BEGIN Initialization" << endl;
  // initialize variables, histos
  
  PHYSICS->mcConfig().Reset();

  // definition of the multiparticle "hadronic" 
  PHYSICS->mcConfig().AddHadronicId(1); // down
  PHYSICS->mcConfig().AddHadronicId(2); // up
  PHYSICS->mcConfig().AddHadronicId(3); // strange
  PHYSICS->mcConfig().AddHadronicId(4); // charm
  PHYSICS->mcConfig().AddHadronicId(5); // bottom
  PHYSICS->mcConfig().AddHadronicId(6); // top
  PHYSICS->mcConfig().AddHadronicId(-1);
  PHYSICS->mcConfig().AddHadronicId(-2);
  PHYSICS->mcConfig().AddHadronicId(-3);
  PHYSICS->mcConfig().AddHadronicId(-4); 
  PHYSICS->mcConfig().AddHadronicId(-5);
  PHYSICS->mcConfig().AddHadronicId(21); // gluon(s)

  // definition of the multiparticle "invisible"
  PHYSICS->mcConfig().AddInvisibleId(12); // neutrino_e
  PHYSICS->mcConfig().AddInvisibleId(14); // neutrino_mu
  PHYSICS->mcConfig().AddInvisibleId(16); //neutrino_tau
  PHYSICS->mcConfig().AddInvisibleId(-12);
  PHYSICS->mcConfig().AddInvisibleId(-14);
  PHYSICS->mcConfig().AddInvisibleId(-16);
  
  
  Manager()->AddRegionSelection("myregion");

  // Definition of histograms
  
  //general plots ************************************************************************************

  Manager()->AddHisto("N_Merged", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_N_Merged = new TH1F("N_Merged", "N_Merged", 3, 0.0, 4.0);

  Manager()->AddHisto("N_notMerged", 100, 0.0, 2.0); /*Name, bins, x_initial, x_final*/
  plot_N_notMerged = new TH1F("N_notMerged", "N_notMerged", 100, 0.0, 2.0);

  Manager()->AddHisto("N_partiallyMerged", 100, 0.0, 2.0); /*Name, bins, x_initial, x_final*/
  plot_N_partiallyMerged = new TH1F("N_partiallyMerged", "N_partiallyMerged", 100, 0.0, 2.0);

  Manager()->AddHisto("N_fullyMerged", 100, 0.0, 2.0); /*Name, bins, x_initial, x_final*/
  plot_N_fullyMerged = new TH1F("N_fullyMerged", "N_fullyMerged", 100, 0.0, 2.0);

  Manager()->AddHisto("Smallest_DR", 100, 0.0, 1.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR = new TH1F("Smallest_DR", "Smallest_DR", 100, 0.0, 1.0);
  
  //general plots dijets *****************************************************************************
  
  Manager()->AddHisto("PT_dijet", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet = new TH1F("PT_dijet", "PT_dijet", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet = new TH1F("ETA_dijet", "ETA_dijet", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet = new TH1F("M_dijet", "M_dijet", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet = new TH1F("PHI_dijet", "PHI_dijet", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet = new TH1F("DR_dijet", "DR_dijet", 100, 0.0, 10.0);
  
  //general plots b_dijets ****************************************************************************
  
  Manager()->AddHisto("PT_b_dijet", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet = new TH1F("PT_b_dijet", "PT_b_dijet", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet = new TH1F("ETA_b_dijet", "ETA_b_dijet", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet", 100, 0.0, 200.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet = new TH1F("M_b_dijet", "M_b_dijet", 100, 0.0, 200.0);

  Manager()->AddHisto("PHI_b_dijet", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet = new TH1F("PHI_b_dijet", "PHI_b_dijet", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet = new TH1F("DR_b_dijet", "DR_b_dijet", 100, 0.0, 10.0);
  
  //DIJETS ********************************************************************************************
  //plots of the dijet pairs that are not merged.

  Manager()->AddHisto("PT_dijet_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet_not = new TH1F("PT_dijet_not", "PT_dijet_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet_not = new TH1F("ETA_dijet_not", "ETA_dijet_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet_not = new TH1F("M_dijet_not", "M_dijet_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet_not = new TH1F("PHI_dijet_not", "PHI_dijet_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet_not = new TH1F("DR_dijet_not", "DR_dijet_not", 100, 0.0, 10.0);
  
  //plots of the dijet pairs that are partially merged.

  Manager()->AddHisto("PT_dijet_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet_partially = new TH1F("PT_dijet_partially", "PT_dijet_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet_partially = new TH1F("ETA_dijet_partially", "ETA_dijet_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet_partially = new TH1F("M_dijet_partially", "M_dijet_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet_partially = new TH1F("PHI_dijet_partially", "PHI_dijet_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet_partially = new TH1F("DR_dijet_partially", "DR_dijet_partially", 100, 0.0, 10.0);
  
  //plots of the dijet pairs that are fully merged.

  Manager()->AddHisto("PT_dijet_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet_fully = new TH1F("PT_dijet_fully", "PT_dijet_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet_fully = new TH1F("ETA_dijet_fully", "ETA_dijet_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet_fully = new TH1F("M_dijet_fully", "M_dijet_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet_fully = new TH1F("PHI_dijet_fully", "PHI_dijet_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet_fully = new TH1F("DR_dijet_fully", "DR_dijet_fully", 100, 0.0, 10.0);
  
  //B-DIJETS ******************************************************************************************
  //plots of the b_dijet pairs that are not merged.

  Manager()->AddHisto("PT_b_dijet_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet_not = new TH1F("PT_b_dijet_not", "PT_b_dijet_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet_not = new TH1F("ETA_b_dijet_not", "ETA_b_dijet_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet_not = new TH1F("M_b_dijet_not", "M_b_dijet_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_b_dijet_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet_not = new TH1F("PHI_b_dijet_not", "PHI_b_dijet_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet_not = new TH1F("DR_b_dijet_not", "DR_b_dijet_not", 100, 0.0, 10.0);
  
  //plots of the b_dijet pairs that are partially merged.

  Manager()->AddHisto("PT_b_dijet_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet_partially = new TH1F("PT_b_dijet_partially", "PT_b_dijet_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet_partially = new TH1F("ETA_b_dijet_partially", "ETA_b_dijet_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet_partially = new TH1F("M_b_dijet_partially", "M_b_dijet_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_b_dijet_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet_partially = new TH1F("PHI_b_dijet_partially", "PHI_b_dijet_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet_partially = new TH1F("DR_b_dijet_partially", "DR_b_dijet_partially", 100, 0.0, 10.0);
  
  //plots of the b_dijet pairs that are fully merged.

  Manager()->AddHisto("PT_b_dijet_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet_fully = new TH1F("PT_b_dijet_fully", "PT_b_dijet_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet_fully = new TH1F("ETA_b_dijet_fully", "ETA_b_dijet_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet_fully = new TH1F("M_b_dijet_fully", "M_b_dijet_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_b_dijet_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet_fully = new TH1F("PHI_b_dijet_fully", "PHI_b_dijet_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet_fully = new TH1F("DR_b_dijet_fully", "DR_b_dijet_fully", 100, 0.0, 10.0);
  
  
  
  cout << "END   Initialization" << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void Analysis::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
  cout << "BEGIN Finalization" << endl;
  // saving histos
  
  TFile* Output = new TFile("resultados.root", "RECREATE");
  
  //1 -> solid
  //2 -> dashed
  //3 -> doted
  //4 -> dashed-doted
  
  //general plots ************************************************************************************
  plot_N_Merged->SetLineStyle(1);
  plot_N_notMerged->SetLineStyle(1);
  plot_N_partiallyMerged->SetLineStyle(1);
  plot_N_fullyMerged->SetLineStyle(1);
  plot_Smallest_DR->SetLineStyle(1);
  
  //general plots dijets *****************************************************************************
  plot_PT_dijet->SetLineStyle(1);
  plot_ETA_dijet->SetLineStyle(1);
  plot_M_dijet->SetLineStyle(1);
  plot_PHI_dijet->SetLineStyle(1);
  plot_DR_dijet->SetLineStyle(1);
  
  //general plots b_dijets ****************************************************************************
  plot_PT_b_dijet->SetLineStyle(1);
  plot_ETA_b_dijet->SetLineStyle(1);
  plot_M_b_dijet->SetLineStyle(1);
  plot_PHI_b_dijet->SetLineStyle(1);
  plot_DR_b_dijet->SetLineStyle(1);
  
  //DIJETS ********************************************************************************************
  //plots of the dijet pairs that are not merged.
  plot_PT_dijet_not->SetLineStyle(1);
  plot_ETA_dijet_not->SetLineStyle(1);
  plot_M_dijet_not->SetLineStyle(1);
  plot_PHI_dijet_not->SetLineStyle(1);
  plot_DR_dijet_not->SetLineStyle(1);
  
  //plots of the dijet pairs that are partially merged.
  plot_PT_dijet_partially->SetLineStyle(1);
  plot_ETA_dijet_partially->SetLineStyle(1);
  plot_M_dijet_partially->SetLineStyle(1);
  plot_PHI_dijet_partially->SetLineStyle(1);
  plot_DR_dijet_partially->SetLineStyle(1);
  
  //plots of the dijet pairs that are fully merged.
  plot_PT_dijet_fully->SetLineStyle(1);
  plot_ETA_dijet_fully->SetLineStyle(1);
  plot_M_dijet_fully->SetLineStyle(1);
  plot_PHI_dijet_fully->SetLineStyle(1);
  plot_DR_dijet_fully->SetLineStyle(1);
  
  //B_DIJETS ******************************************************************************************
  //plots of the b_dijet pairs that are not merged.
  plot_PT_b_dijet_not->SetLineStyle(1);
  plot_ETA_b_dijet_not->SetLineStyle(1);
  plot_M_b_dijet_not->SetLineStyle(1);
  plot_PHI_b_dijet_not->SetLineStyle(1);
  plot_DR_b_dijet_not->SetLineStyle(1);
  
  //plots of the b_dijet pairs that are partially merged.
  plot_PT_b_dijet_partially->SetLineStyle(1);
  plot_ETA_b_dijet_partially->SetLineStyle(1);
  plot_M_b_dijet_partially->SetLineStyle(1);
  plot_PHI_b_dijet_partially->SetLineStyle(1);
  plot_DR_b_dijet_partially->SetLineStyle(1);
  
  //plots of the b_dijet pairs that are fully merged.
  plot_PT_b_dijet_fully->SetLineStyle(1);
  plot_ETA_b_dijet_fully->SetLineStyle(1);
  plot_M_b_dijet_fully->SetLineStyle(1);
  plot_PHI_b_dijet_fully->SetLineStyle(1);
  plot_DR_b_dijet_fully->SetLineStyle(1);
  
  
  
  
  
  //general plots ************************************************************************************
  TAxis* a = plot_N_Merged->GetXaxis();
  a->SetBit(TAxis::kLabelsHori); 
  a->SetBinLabel(1,"Not Merged"); 
  a->SetBinLabel(2,"Partially Merged"); 
  a->SetBinLabel(3,"Fully Merged");
  plot_N_Merged->Draw("HIST");
  
  plot_N_notMerged->Draw("HIST");
  plot_N_partiallyMerged->Draw("HIST");
  plot_N_fullyMerged->Draw("HIST");
  plot_Smallest_DR->Draw("HIST");
  
  //general plots dijets *****************************************************************************
  plot_PT_dijet->Draw("HIST");
  plot_ETA_dijet->Draw("HIST");
  plot_M_dijet->Draw("HIST");
  plot_PHI_dijet->Draw("HIST");
  plot_DR_dijet->Draw("HIST");
  
  //general plots b_dijets ***************************************************************************
  plot_PT_b_dijet->Draw("HIST");
  plot_ETA_b_dijet->Draw("HIST");
  plot_M_b_dijet->Draw("HIST");
  plot_PHI_b_dijet->Draw("HIST");
  plot_DR_b_dijet->Draw("HIST");
  
  //DIJETS ********************************************************************************************
  //plots of the dijet pairs that are not merged.
  plot_PT_dijet_not->Draw("HIST");
  plot_ETA_dijet_not->Draw("HIST");
  plot_M_dijet_not->Draw("HIST");
  plot_PHI_dijet_not->Draw("HIST");
  plot_DR_dijet_not->Draw("HIST");
  
  //plots of the dijet pairs that are partially merged.
  plot_PT_dijet_partially->Draw("HIST");
  plot_ETA_dijet_partially->Draw("HIST");
  plot_M_dijet_partially->Draw("HIST");
  plot_PHI_dijet_partially->Draw("HIST");
  plot_DR_dijet_partially->Draw("HIST");
  
  //plots of the dijet pairs that are fully merged.
  plot_PT_dijet_fully->Draw("HIST");
  plot_ETA_dijet_fully->Draw("HIST");
  plot_M_dijet_fully->Draw("HIST");
  plot_PHI_dijet_fully->Draw("HIST");
  plot_DR_dijet_fully->Draw("HIST");
  
  //B_DIJETS ******************************************************************************************
  //plots of the b_dijet pairs that are not merged.
  plot_PT_b_dijet_not->Draw("HIST");
  plot_ETA_b_dijet_not->Draw("HIST");
  plot_M_b_dijet_not->Draw("HIST");
  plot_PHI_b_dijet_not->Draw("HIST");
  plot_DR_b_dijet_not->Draw("HIST");
  
  //plots of the b_dijet pairs that are partially merged.
  plot_PT_b_dijet_partially->Draw("HIST");
  plot_ETA_b_dijet_partially->Draw("HIST");
  plot_M_b_dijet_partially->Draw("HIST");
  plot_PHI_b_dijet_partially->Draw("HIST");
  plot_DR_b_dijet_partially->Draw("HIST");
  
  //plots of the b_dijet pairs that are fully merged.
  plot_PT_b_dijet_fully->Draw("HIST");
  plot_ETA_b_dijet_fully->Draw("HIST");
  plot_M_b_dijet_fully->Draw("HIST");
  plot_PHI_b_dijet_fully->Draw("HIST");
  plot_DR_b_dijet_fully->Draw("HIST");
  
  
  
  
  
  //general plots ************************************************************************************
  plot_N_Merged->Write();
  plot_N_notMerged->Write();
  plot_N_partiallyMerged->Write();
  plot_N_fullyMerged->Write();
  plot_Smallest_DR->Write();
  
  //general plots dijets *****************************************************************************
  plot_PT_dijet->Write();
  plot_ETA_dijet->Write();
  plot_M_dijet->Write();
  plot_PHI_dijet->Write();
  plot_DR_dijet->Write();
  
  //general plots b_dijets ***************************************************************************
  plot_PT_b_dijet->Write();
  plot_ETA_b_dijet->Write();
  plot_M_b_dijet->Write();
  plot_PHI_b_dijet->Write();
  plot_DR_b_dijet->Write();
  
  //DIJETS ********************************************************************************************
  //plots of the dijet pairs that are not merged.
  plot_PT_dijet_not->Write();
  plot_ETA_dijet_not->Write();
  plot_M_dijet_not->Write();
  plot_PHI_dijet_not->Write();
  plot_DR_dijet_not->Write();
  
  //plots of the dijet pairs that are partially merged.
  plot_PT_dijet_partially->Write();
  plot_ETA_dijet_partially->Write();
  plot_M_dijet_partially->Write();
  plot_PHI_dijet_partially->Write();
  plot_DR_dijet_partially->Write();
  
  //plots of the dijet pairs that are fully merged.
  plot_PT_dijet_fully->Write();
  plot_ETA_dijet_fully->Write();
  plot_M_dijet_fully->Write();
  plot_PHI_dijet_fully->Write();
  plot_DR_dijet_fully->Write();
  
  //B_DIJETS ******************************************************************************************
  //plots of the b_dijet pairs that are not merged.
  plot_PT_b_dijet_not->Write();
  plot_ETA_b_dijet_not->Write();
  plot_M_b_dijet_not->Write();
  plot_PHI_b_dijet_not->Write();
  plot_DR_b_dijet_not->Write();
  
  //plots of the b_dijet pairs that are partially merged.
  plot_PT_b_dijet_partially->Write();
  plot_ETA_b_dijet_partially->Write();
  plot_M_b_dijet_partially->Write();
  plot_PHI_b_dijet_partially->Write();
  plot_DR_b_dijet_partially->Write();
  
  //plots of the b_dijet pairs that are fully merged.
  plot_PT_b_dijet_fully->Write();
  plot_ETA_b_dijet_fully->Write();
  plot_M_b_dijet_fully->Write();
  plot_PHI_b_dijet_fully->Write();
  plot_DR_b_dijet_fully->Write();
  
  Output->Close();
   
  cout << "END   Finalization" << endl;
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool Analysis::Execute(SampleFormat& sample, const EventFormat& event)
{
	FinalStateLeptons.clear();
	FinalStateNeutrinos.clear();
	FinalStateJs.clear();
	FinalStateBs.clear();
	notMerged.clear();
	partiallyMerged.clear();
	fullyMerged.clear();
	smallestdr.clear();
	
	//Fill the vectors that contain final state particles.
	for (MAuint32 i = 0 ; i < event.mc()->particles().size(); i++){
		//const MCParticleFormat* particle = event.mc()->particles()[i];
    		ClassifyParticles(&(event.mc()->particles()[i]), FinalStateLeptons, FinalStateNeutrinos, FinalStateJs, FinalStateBs);
    	}
      	
      	//Organizes the final state vectors in terms of their PT (greatest to smallest).
      	
      	/*
      	std::vector<const MCParticleFormat*> tempb1 = SORTER->rankFilter(FinalStateJs,1,PTordering);
      	std::vector<const MCParticleFormat*> tempb2 = SORTER->rankFilter(FinalStateJs,2,PTordering);
      	std::vector<const MCParticleFormat*> tempb3 = SORTER->rankFilter(FinalStateJs,3,PTordering);
      	std::vector<const MCParticleFormat*> tempb4 = SORTER->rankFilter(FinalStateJs,4,PTordering);
      	std::vector<const MCParticleFormat*> nuevosjet;
      	nuevosjet.push_back(tempb1[0]);
      	nuevosjet.push_back(tempb2[0]);
      	nuevosjet.push_back(tempb3[0]);
      	nuevosjet.push_back(tempb4[0]);
      	
      	
      	FinalStateJs.clear();
      	FinalStateJs = nuevosjet;
      	cout << FinalStateJs.size() << endl;
      	*/
      	
      	std::vector<const MCParticleFormat*> nuevosjet;
      	
      	for (MAuint32 i = 0; i < FinalStateJs.size(); i++){
      		
      		std::vector<const MCParticleFormat*> tempj = SORTER->rankFilter(FinalStateJs,i+1,PTordering);
      		nuevosjet.push_back(tempj[0]);
      		tempj.clear();	
      	}
      	FinalStateJs.clear();
      	FinalStateJs = nuevosjet;
      	
      	
      	std::vector<const MCParticleFormat*> nuevosb;
      	
      	for (MAuint32 i = 0; i < FinalStateBs.size(); i++){
      		
      		std::vector<const MCParticleFormat*> tempb = SORTER->rankFilter(FinalStateBs,i+1,PTordering);
      		nuevosb.push_back(tempb[0]);
      		tempb.clear();	
      	}
      	FinalStateBs.clear();
      	FinalStateBs = nuevosb;
      	
      	
      	/*
	FinalStateLeptons=SORTER->rankFilter(FinalStateLeptons,PTordering);
	FinalStateNeutrinos=SORTER->rankFilter(FinalStateNeutrinos,PTordering);
	FinalStateJs=SORTER->rankFilter(FinalStateJs,PTordering);
	FinalStateBs=SORTER->rankFilter(FinalStateBs,PTordering);
	*/
	
	//Reconstructs the events depending on wether the fully-hadronic or semi-leptonic channel is being studied.
	if (FinalStateJs.size() == 4){
		MergedFullyHadronic(FinalStateJs, FinalStateBs, dijet1, dijet2, b_dijet1, b_dijet2);
		//cout << "hadronic" << b_dijet.M() << endl;
	}
	if (FinalStateJs.size() == 2){
		MergedSemiLeptonic(FinalStateJs, FinalStateBs, dijet1, b_dijet1);
	}
	
	Manager()->FillHisto("M_dijet", dijet1.M());
	plot_M_dijet->Fill(dijet1.M());
	
	if (notMerged[0] == false){
		Manager()->FillHisto("M_b_dijet", b_dijet1.M());
		plot_M_b_dijet->Fill(b_dijet1.M());
	}
	
/*	
      if(notMerged[0])
      {
         Manager()->FillHisto("N_Merged", 1);
         plot_N_Merged->Fill(1);
      }
      
      if(partiallyMerged[0])
      {
         Manager()->FillHisto("N_Merged", 2);
         plot_N_Merged->Fill(2);
      }
      
      if(fullyMerged[0])
      {
         Manager()->FillHisto("N_Merged", 3);
         plot_N_Merged->Fill(3);
      }
*/










  return true;
}

