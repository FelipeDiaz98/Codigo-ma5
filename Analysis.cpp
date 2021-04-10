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

  Manager()->AddHisto("Smallest_DR_dijet", 100, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_dijet = new TH1F("Smallest_DR_dijet", "Smallest_DR_dijet", 100, 0.0, 3.0);
  
  Manager()->AddHisto("Smallest_DR_b_dijet", 100, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_b_dijet = new TH1F("Smallest_DR_b_dijet", "Smallest_DR_b_dijet", 100, 0.0, 3.0);
  
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
  plot_Smallest_DR_dijet->SetLineStyle(1);
  plot_Smallest_DR_b_dijet->SetLineStyle(1);
  
  //general plots dijets *****************************************************************************
  plot_PT_dijet->SetLineStyle(1);
  plot_ETA_dijet->SetLineStyle(1);
  plot_M_dijet->SetLineStyle(1);
  plot_PHI_dijet->SetLineStyle(1);
  plot_DR_dijet->SetLineStyle(1);
  
  //general plots b_dijets ***************************************************************************
  plot_PT_b_dijet->SetLineStyle(1);
  plot_ETA_b_dijet->SetLineStyle(1);
  plot_M_b_dijet->SetLineStyle(1);
  plot_PHI_b_dijet->SetLineStyle(1);
  plot_DR_b_dijet->SetLineStyle(1);
  
  //DIJETS *******************************************************************************************
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
  
  //B_DIJETS *****************************************************************************************
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
  
  TAxis* b = plot_Smallest_DR_dijet->GetXaxis();
  b->SetBit(TAxis::kLabelsHori); 
  b->SetBinLabel(1,"Smallest DR"); 
  b->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_dijet->Draw("HIST");
  
  TAxis* c = plot_Smallest_DR_b_dijet->GetXaxis();
  c->SetBit(TAxis::kLabelsHori); 
  c->SetBinLabel(1,"Smallest DR"); 
  c->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_b_dijet->Draw("HIST");
  
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
  plot_Smallest_DR_dijet->Write();
  plot_Smallest_DR_b_dijet->Write();
  
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

	//Clear all vectors.
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
    		ClassifyParticles(&(event.mc()->particles()[i]), FinalStateLeptons, FinalStateNeutrinos, FinalStateJs, FinalStateBs);
    	}
      	
      	//Organize the final state particles by their PT.
      	OrganizeByPT(FinalStateLeptons);
      	OrganizeByPT(FinalStateNeutrinos);
      	OrganizeByPT(FinalStateJs);
	OrganizeByPT(FinalStateBs);
      	
	//Reconstruct the events depending on wether the fully-hadronic or semi-leptonic channel is being studied.
	if (FinalStateJs.size() == 4){
		MergedFullyHadronic(FinalStateJs, FinalStateBs, dijet1, dijet2, b_dijet1, b_dijet2);
	}
	if (FinalStateJs.size() == 2){
		MergedSemiLeptonic(FinalStateJs, FinalStateBs, dijet1, b_dijet1);
	}
	
	
	
	
	
	//FILLING THE HISTOGRAMS.
	//general plots ************************************************************************************
	//fills N_merged.
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

	//fills Smallest_DR_dijet.
	if ((FinalStateJs.size() == 4) && (smallestdr[0] == true)){
		Manager()->FillHisto("Smallest_DR_dijet", 1);
		plot_Smallest_DR_dijet->Fill(1);
	}
	if ((FinalStateJs.size() == 4) && (smallestdr[0] == false)){
		Manager()->FillHisto("Smallest_DR_dijet", 2);
		plot_Smallest_DR_dijet->Fill(2);
	}
	
	//fills Smallest_DR_b_dijet.
	if ((FinalStateJs.size() == 4) && (smallestdr[1] == true)){
		Manager()->FillHisto("Smallest_DR_b_dijet", 1);
		plot_Smallest_DR_b_dijet->Fill(1);
	}
	if ((FinalStateJs.size() == 4) && (smallestdr[1] == false)){
		Manager()->FillHisto("Smallest_DR_b_dijet", 2);
		plot_Smallest_DR_b_dijet->Fill(2);
	}
  
	//general plots dijets *****************************************************************************
	//fils PT_dijet.
	Manager()->FillHisto("PT_dijet", dijet1.Pt());
        plot_PT_dijet->Fill(dijet1.Pt());

	//fils ETA_dijet.
	Manager()->FillHisto("ETA_dijet", dijet1.Eta());
        plot_ETA_dijet->Fill(dijet1.Eta());

	//fils M_dijet.
	Manager()->FillHisto("M_dijet", dijet1.M());
        plot_M_dijet->Fill(dijet1.M());
        
	//fils PHI_dijet.
	Manager()->FillHisto("PHI_dijet", dijet1.Phi());
        plot_PHI_dijet->Fill(dijet1.Phi());
        
	//fils DR_dijet.
	Manager()->FillHisto("DR_dijet", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        plot_DR_dijet->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
	
	//general plots b_dijets ***************************************************************************
	if (notMerged[0] == false){
		//fils PT_b_dijet.
		Manager()->FillHisto("PT_b_dijet", b_dijet1.Pt());
        	plot_PT_b_dijet->Fill(b_dijet1.Pt());

		//fils ETA_b_dijet.
		Manager()->FillHisto("ETA_b_dijet", b_dijet1.Eta());
        	plot_ETA_b_dijet->Fill(b_dijet1.Eta());

		//fils M_b_dijet.
		Manager()->FillHisto("M_b_dijet", b_dijet1.M());
        	plot_M_b_dijet->Fill(b_dijet1.M());
        
		//fils PHI_b_dijet.
		Manager()->FillHisto("PHI_b_dijet", b_dijet1.Phi());
        	plot_PHI_b_dijet->Fill(b_dijet1.Phi());
        
		//fils DR_b_dijet.
		Manager()->FillHisto("DR_b_dijet", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
	}
	
	//DIJETS ********************************************************************************************
  	//plots of the dijet pairs that are not merged.
  	if(notMerged[0]){
  		//fils PT_dijet_not.
		Manager()->FillHisto("PT_dijet_not", dijet1.Pt());
        	plot_PT_dijet_not->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet_not.
		Manager()->FillHisto("ETA_dijet_not", dijet1.Eta());
        	plot_ETA_dijet_not->Fill(dijet1.Eta());
        	
        	//fils M_dijet_not.
		Manager()->FillHisto("M_dijet_not", dijet1.M());
        	plot_M_dijet_not->Fill(dijet1.M());
        	
        	//fils PHI_dijet_not.
		Manager()->FillHisto("PHI_dijet_not", dijet1.Phi());
        	plot_PHI_dijet_not->Fill(dijet1.Phi());
        	
        	//fils DR_dijet_not.
		Manager()->FillHisto("DR_dijet_not", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet_not->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
 
	//plots of the dijet pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_dijet_partially.
		Manager()->FillHisto("PT_dijet_partially", dijet1.Pt());
        	plot_PT_dijet_partially->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet_partially.
		Manager()->FillHisto("ETA_dijet_partially", dijet1.Eta());
        	plot_ETA_dijet_partially->Fill(dijet1.Eta());
        	
        	//fils M_dijet_partially.
		Manager()->FillHisto("M_dijet_partially", dijet1.M());
        	plot_M_dijet_partially->Fill(dijet1.M());
        	
        	//fils PHI_dijet_partially.
		Manager()->FillHisto("PHI_dijet_partially", dijet1.Phi());
        	plot_PHI_dijet_partially->Fill(dijet1.Phi());
        	
        	//fils DR_dijet_partially.
		Manager()->FillHisto("DR_dijet_partially", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet_partially->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
  
	//plots of the dijet pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_dijet_fully.
		Manager()->FillHisto("PT_dijet_fully", dijet1.Pt());
        	plot_PT_dijet_fully->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet_fully.
		Manager()->FillHisto("ETA_dijet_fully", dijet1.Eta());
        	plot_ETA_dijet_fully->Fill(dijet1.Eta());
        	
        	//fils M_dijet_fully.
		Manager()->FillHisto("M_dijet_fully", dijet1.M());
        	plot_M_dijet_fully->Fill(dijet1.M());
        	
        	//fils PHI_dijet_fully.
		Manager()->FillHisto("PHI_dijet_fully", dijet1.Phi());
        	plot_PHI_dijet_fully->Fill(dijet1.Phi());
        	
        	//fils DR_dijet_fully.
		Manager()->FillHisto("DR_dijet_fully", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet_fully->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}

  	//B_DIJETS ****************************************************************************************** 
	//plots of the b_dijet pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_b_dijet_partially.
		Manager()->FillHisto("PT_b_dijet_partially", b_dijet1.Pt());
        	plot_PT_b_dijet_partially->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet_partially.
		Manager()->FillHisto("ETA_b_dijet_partially", b_dijet1.Eta());
        	plot_ETA_b_dijet_partially->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet_partially.
		Manager()->FillHisto("M_b_dijet_partially", b_dijet1.M());
        	plot_M_b_dijet_partially->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet_partially.
		Manager()->FillHisto("PHI_b_dijet_partially", b_dijet1.Phi());
        	plot_PHI_b_dijet_partially->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet_partially.
		Manager()->FillHisto("DR_b_dijet_partially", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet_partially->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}
  
	//plots of the b_dijet pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_b_dijet_fully.
		Manager()->FillHisto("PT_b_dijet_fully", b_dijet1.Pt());
        	plot_PT_b_dijet_fully->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet_fully.
		Manager()->FillHisto("ETA_b_dijet_fully", b_dijet1.Eta());
        	plot_ETA_b_dijet_fully->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet_fully.
		Manager()->FillHisto("M_b_dijet_fully", b_dijet1.M());
        	plot_M_b_dijet_fully->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet_fully.
		Manager()->FillHisto("PHI_b_dijet_fully", b_dijet1.Phi());
        	plot_PHI_b_dijet_fully->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet_fully.
		Manager()->FillHisto("DR_b_dijet_fully", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet_fully->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}


  return true;
}

