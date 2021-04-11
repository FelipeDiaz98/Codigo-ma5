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
  
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************
  //general plots dijet1 *****************************************************************************

  Manager()->AddHisto("N_Merged1", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_N_Merged1 = new TH1F("N_Merged1", "N_Merged1", 3, 0.0, 4.0);
  
  //general plots dijet1 *****************************************************************************
  
  Manager()->AddHisto("PT_dijet1", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1 = new TH1F("PT_dijet1", "PT_dijet1", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1 = new TH1F("ETA_dijet1", "ETA_dijet1", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1 = new TH1F("M_dijet1", "M_dijet1", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1 = new TH1F("PHI_dijet1", "PHI_dijet1", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1 = new TH1F("DR_dijet1", "DR_dijet1", 100, 0.0, 10.0);
  
  //general plots b_dijet1 ****************************************************************************
  
  Manager()->AddHisto("PT_b_dijet1", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1 = new TH1F("PT_b_dijet1", "PT_b_dijet1", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1 = new TH1F("ETA_b_dijet1", "ETA_b_dijet1", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1 = new TH1F("M_b_dijet1", "M_b_dijet1", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1 = new TH1F("PHI_b_dijet1", "PHI_b_dijet1", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1 = new TH1F("DR_b_dijet1", "DR_b_dijet1", 100, 0.0, 10.0);
  
  //DIJET1 ********************************************************************************************
  //plots of the dijet1 pairs that are not merged.

  Manager()->AddHisto("PT_dijet1_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_not = new TH1F("PT_dijet1_not", "PT_dijet1_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_not = new TH1F("ETA_dijet1_not", "ETA_dijet1_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_not = new TH1F("M_dijet1_not", "M_dijet1_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_not = new TH1F("PHI_dijet1_not", "PHI_dijet1_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_not = new TH1F("DR_dijet1_not", "DR_dijet1_not", 100, 0.0, 10.0);
  
  //plots of the dijet1 pairs that are partially merged.

  Manager()->AddHisto("PT_dijet1_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_partially = new TH1F("PT_dijet1_partially", "PT_dijet1_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_partially = new TH1F("ETA_dijet1_partially", "ETA_dijet1_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_partially = new TH1F("M_dijet1_partially", "M_dijet1_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_partially = new TH1F("PHI_dijet1_partially", "PHI_dijet1_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_partially = new TH1F("DR_dijet1_partially", "DR_dijet1_partially", 100, 0.0, 10.0);
  
  //plots of the dijet1 pairs that are fully merged.

  Manager()->AddHisto("PT_dijet1_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_fully = new TH1F("PT_dijet1_fully", "PT_dijet1_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_fully = new TH1F("ETA_dijet1_fully", "ETA_dijet1_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_fully = new TH1F("M_dijet1_fully", "M_dijet1_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_fully = new TH1F("PHI_dijet1_fully", "PHI_dijet1_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_fully = new TH1F("DR_dijet1_fully", "DR_dijet1_fully", 100, 0.0, 10.0);
  
  //B-DIJET1 ******************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.

  Manager()->AddHisto("PT_b_dijet1_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1_partially = new TH1F("PT_b_dijet1_partially", "PT_b_dijet1_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1_partially = new TH1F("ETA_b_dijet1_partially", "ETA_b_dijet1_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1_partially", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1_partially = new TH1F("M_b_dijet1_partially", "M_b_dijet1_partially", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1_partially = new TH1F("PHI_b_dijet1_partially", "PHI_b_dijet1_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1_partially = new TH1F("DR_b_dijet1_partially", "DR_b_dijet1_partially", 100, 0.0, 10.0);
  
  //plots of the b_dijet1 pairs that are fully merged.

  Manager()->AddHisto("PT_b_dijet1_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1_fully = new TH1F("PT_b_dijet1_fully", "PT_b_dijet1_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1_fully = new TH1F("ETA_b_dijet1_fully", "ETA_b_dijet1_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1_fully", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1_fully = new TH1F("M_b_dijet1_fully", "M_b_dijet1_fully", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1_fully = new TH1F("PHI_b_dijet1_fully", "PHI_b_dijet1_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1_fully = new TH1F("DR_b_dijet1_fully", "DR_b_dijet1_fully", 100, 0.0, 10.0);
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************
  //general plots dijet2 *****************************************************************************
  
  Manager()->AddHisto("N_Merged2", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_N_Merged2 = new TH1F("N_Merged2", "N_Merged2", 3, 0.0, 4.0);

  Manager()->AddHisto("Smallest_DR_dijet", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_dijet = new TH1F("Smallest_DR_dijet", "Smallest_DR_dijet", 2, 0.0, 3.0);
  
  Manager()->AddHisto("Smallest_DR_b_dijet", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_b_dijet = new TH1F("Smallest_DR_b_dijet", "Smallest_DR_b_dijet", 2, 0.0, 3.0);
  
  //general plots dijet2 *****************************************************************************
  
  Manager()->AddHisto("PT_dijet2", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2 = new TH1F("PT_dijet2", "PT_dijet2", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2 = new TH1F("ETA_dijet2", "ETA_dijet2", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2 = new TH1F("M_dijet2", "M_dijet2", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2 = new TH1F("PHI_dijet2", "PHI_dijet2", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2 = new TH1F("DR_dijet2", "DR_dijet2", 100, 0.0, 10.0);
  
  //general plots b_dijet2 ****************************************************************************
  
  Manager()->AddHisto("PT_b_dijet2", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2 = new TH1F("PT_b_dijet2", "PT_b_dijet2", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2 = new TH1F("ETA_b_dijet2", "ETA_b_dijet2", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2 = new TH1F("M_b_dijet2", "M_b_dijet2", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2 = new TH1F("PHI_b_dijet2", "PHI_b_dijet2", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2 = new TH1F("DR_b_dijet2", "DR_b_dijet2", 100, 0.0, 10.0);
  
  //DIJETS ********************************************************************************************
  //plots of the dijet2 pairs that are not merged.

  Manager()->AddHisto("PT_dijet2_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_not = new TH1F("PT_dijet2_not", "PT_dijet2_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_not = new TH1F("ETA_dijet2_not", "ETA_dijet2_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_not = new TH1F("M_dijet2_not", "M_dijet2_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_not = new TH1F("PHI_dijet2_not", "PHI_dijet2_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_not = new TH1F("DR_dijet2_not", "DR_dijet2_not", 100, 0.0, 10.0);
  
  //plots of the dijet2 pairs that are partially merged.

  Manager()->AddHisto("PT_dijet2_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_partially = new TH1F("PT_dijet2_partially", "PT_dijet2_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_partially = new TH1F("ETA_dijet2_partially", "ETA_dijet2_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_partially = new TH1F("M_dijet2_partially", "M_dijet2_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_partially = new TH1F("PHI_dijet2_partially", "PHI_dijet2_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_partially = new TH1F("DR_dijet2_partially", "DR_dijet2_partially", 100, 0.0, 10.0);
  
  //plots of the dijet2 pairs that are fully merged.

  Manager()->AddHisto("PT_dijet2_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_fully = new TH1F("PT_dijet2_fully", "PT_dijet2_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_fully = new TH1F("ETA_dijet2_fully", "ETA_dijet2_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_fully = new TH1F("M_dijet2_fully", "M_dijet2_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_fully = new TH1F("PHI_dijet2_fully", "PHI_dijet2_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_fully = new TH1F("DR_dijet2_fully", "DR_dijet2_fully", 100, 0.0, 10.0);
  
  //B-DIJET2 ******************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.

  Manager()->AddHisto("PT_b_dijet2_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2_partially = new TH1F("PT_b_dijet2_partially", "PT_b_dijet2_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2_partially = new TH1F("ETA_b_dijet2_partially", "ETA_b_dijet2_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2_partially", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2_partially = new TH1F("M_b_dijet2_partially", "M_b_dijet2_partially", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2_partially = new TH1F("PHI_b_dijet2_partially", "PHI_b_dijet2_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2_partially = new TH1F("DR_b_dijet2_partially", "DR_b_dijet2_partially", 100, 0.0, 10.0);
  
  //plots of the b_dijet2 pairs that are fully merged.

  Manager()->AddHisto("PT_b_dijet2_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2_fully = new TH1F("PT_b_dijet2_fully", "PT_b_dijet2_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2_fully = new TH1F("ETA_b_dijet2_fully", "ETA_b_dijet2_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2_fully", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2_fully = new TH1F("M_b_dijet2_fully", "M_b_dijet2_fully", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2_fully = new TH1F("PHI_b_dijet2_fully", "PHI_b_dijet2_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2_fully = new TH1F("DR_b_dijet2_fully", "DR_b_dijet2_fully", 100, 0.0, 10.0);
  
  
  
  
  
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
  
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************
  //general plots dijet1 *****************************************************************************
  plot_N_Merged1->SetLineStyle(1);
  
  //general plots dijet1 *****************************************************************************
  plot_PT_dijet1->SetLineStyle(1);
  plot_ETA_dijet1->SetLineStyle(1);
  plot_M_dijet1->SetLineStyle(1);
  plot_PHI_dijet1->SetLineStyle(1);
  plot_DR_dijet1->SetLineStyle(1);
  
  //general plots b_dijet1 ***************************************************************************
  plot_PT_b_dijet1->SetLineStyle(1);
  plot_ETA_b_dijet1->SetLineStyle(1);
  plot_M_b_dijet1->SetLineStyle(1);
  plot_PHI_b_dijet1->SetLineStyle(1);
  plot_DR_b_dijet1->SetLineStyle(1);
  
  //DIJET1 *******************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->SetLineStyle(1);
  plot_ETA_dijet1_not->SetLineStyle(1);
  plot_M_dijet1_not->SetLineStyle(1);
  plot_PHI_dijet1_not->SetLineStyle(1);
  plot_DR_dijet1_not->SetLineStyle(1);
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->SetLineStyle(1);
  plot_ETA_dijet1_partially->SetLineStyle(1);
  plot_M_dijet1_partially->SetLineStyle(1);
  plot_PHI_dijet1_partially->SetLineStyle(1);
  plot_DR_dijet1_partially->SetLineStyle(1);
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->SetLineStyle(1);
  plot_ETA_dijet1_fully->SetLineStyle(1);
  plot_M_dijet1_fully->SetLineStyle(1);
  plot_PHI_dijet1_fully->SetLineStyle(1);
  plot_DR_dijet1_fully->SetLineStyle(1);
  
  //B_DIJET1 *****************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->SetLineStyle(1);
  plot_ETA_b_dijet1_partially->SetLineStyle(1);
  plot_M_b_dijet1_partially->SetLineStyle(1);
  plot_PHI_b_dijet1_partially->SetLineStyle(1);
  plot_DR_b_dijet1_partially->SetLineStyle(1);
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->SetLineStyle(1);
  plot_ETA_b_dijet1_fully->SetLineStyle(1);
  plot_M_b_dijet1_fully->SetLineStyle(1);
  plot_PHI_b_dijet1_fully->SetLineStyle(1);
  plot_DR_b_dijet1_fully->SetLineStyle(1);
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************
  //general plots dijet2 *****************************************************************************
  plot_N_Merged2->SetLineStyle(1);
  plot_Smallest_DR_dijet->SetLineStyle(1);
  plot_Smallest_DR_b_dijet->SetLineStyle(1);
  
  //general plots dijet2 *****************************************************************************
  plot_PT_dijet2->SetLineStyle(1);
  plot_ETA_dijet2->SetLineStyle(1);
  plot_M_dijet2->SetLineStyle(1);
  plot_PHI_dijet2->SetLineStyle(1);
  plot_DR_dijet2->SetLineStyle(1);
  
  //general plots b_dijet2 ***************************************************************************
  plot_PT_b_dijet2->SetLineStyle(1);
  plot_ETA_b_dijet2->SetLineStyle(1);
  plot_M_b_dijet2->SetLineStyle(1);
  plot_PHI_b_dijet2->SetLineStyle(1);
  plot_DR_b_dijet2->SetLineStyle(1);
  
  //DIJET2 *******************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->SetLineStyle(1);
  plot_ETA_dijet2_not->SetLineStyle(1);
  plot_M_dijet2_not->SetLineStyle(1);
  plot_PHI_dijet2_not->SetLineStyle(1);
  plot_DR_dijet2_not->SetLineStyle(1);
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->SetLineStyle(1);
  plot_ETA_dijet2_partially->SetLineStyle(1);
  plot_M_dijet2_partially->SetLineStyle(1);
  plot_PHI_dijet2_partially->SetLineStyle(1);
  plot_DR_dijet2_partially->SetLineStyle(1);
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->SetLineStyle(1);
  plot_ETA_dijet2_fully->SetLineStyle(1);
  plot_M_dijet2_fully->SetLineStyle(1);
  plot_PHI_dijet2_fully->SetLineStyle(1);
  plot_DR_dijet2_fully->SetLineStyle(1);
  
  //B_DIJET2 *****************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->SetLineStyle(1);
  plot_ETA_b_dijet2_partially->SetLineStyle(1);
  plot_M_b_dijet2_partially->SetLineStyle(1);
  plot_PHI_b_dijet2_partially->SetLineStyle(1);
  plot_DR_b_dijet2_partially->SetLineStyle(1);
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->SetLineStyle(1);
  plot_ETA_b_dijet2_fully->SetLineStyle(1);
  plot_M_b_dijet2_fully->SetLineStyle(1);
  plot_PHI_b_dijet2_fully->SetLineStyle(1);
  plot_DR_b_dijet2_fully->SetLineStyle(1);
  
  
  
  
  
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************
  //general plots dijet1 *****************************************************************************
  TAxis* a = plot_N_Merged1->GetXaxis();
  a->SetBit(TAxis::kLabelsHori); 
  a->SetBinLabel(1,"Not Merged"); 
  a->SetBinLabel(2,"Partially Merged"); 
  a->SetBinLabel(3,"Fully Merged");
  plot_N_Merged1->Draw("HIST");
  
  //general plots dijet1 *****************************************************************************
  plot_PT_dijet1->Draw("HIST");
  plot_ETA_dijet1->Draw("HIST");
  plot_M_dijet1->Draw("HIST");
  plot_PHI_dijet1->Draw("HIST");
  plot_DR_dijet1->Draw("HIST");
  
  //general plots b_dijet1 ***************************************************************************
  plot_PT_b_dijet1->Draw("HIST");
  plot_ETA_b_dijet1->Draw("HIST");
  plot_M_b_dijet1->Draw("HIST");
  plot_PHI_b_dijet1->Draw("HIST");
  plot_DR_b_dijet1->Draw("HIST");
  
  //DIJET1 ********************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->Draw("HIST");
  plot_ETA_dijet1_not->Draw("HIST");
  plot_M_dijet1_not->Draw("HIST");
  plot_PHI_dijet1_not->Draw("HIST");
  plot_DR_dijet1_not->Draw("HIST");
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->Draw("HIST");
  plot_ETA_dijet1_partially->Draw("HIST");
  plot_M_dijet1_partially->Draw("HIST");
  plot_PHI_dijet1_partially->Draw("HIST");
  plot_DR_dijet1_partially->Draw("HIST");
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->Draw("HIST");
  plot_ETA_dijet1_fully->Draw("HIST");
  plot_M_dijet1_fully->Draw("HIST");
  plot_PHI_dijet1_fully->Draw("HIST");
  plot_DR_dijet1_fully->Draw("HIST");
  
  //B_DIJET1 ******************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->Draw("HIST");
  plot_ETA_b_dijet1_partially->Draw("HIST");
  plot_M_b_dijet1_partially->Draw("HIST");
  plot_PHI_b_dijet1_partially->Draw("HIST");
  plot_DR_b_dijet1_partially->Draw("HIST");
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->Draw("HIST");
  plot_ETA_b_dijet1_fully->Draw("HIST");
  plot_M_b_dijet1_fully->Draw("HIST");
  plot_PHI_b_dijet1_fully->Draw("HIST");
  plot_DR_b_dijet1_fully->Draw("HIST");
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************
  //general plots dijet2 *****************************************************************************
  TAxis* b = plot_N_Merged2->GetXaxis();
  b->SetBit(TAxis::kLabelsHori); 
  b->SetBinLabel(1,"Not Merged"); 
  b->SetBinLabel(2,"Partially Merged"); 
  b->SetBinLabel(3,"Fully Merged");
  plot_N_Merged2->Draw("HIST");
  
  TAxis* c = plot_Smallest_DR_dijet->GetXaxis();
  c->SetBit(TAxis::kLabelsHori); 
  c->SetBinLabel(1,"Smallest DR"); 
  c->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_dijet->Draw("HIST");
  
  TAxis* d = plot_Smallest_DR_b_dijet->GetXaxis();
  d->SetBit(TAxis::kLabelsHori); 
  d->SetBinLabel(1,"Smallest DR"); 
  d->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_b_dijet->Draw("HIST");
  
  //general plots dijet2 *****************************************************************************
  plot_PT_dijet2->Draw("HIST");
  plot_ETA_dijet2->Draw("HIST");
  plot_M_dijet2->Draw("HIST");
  plot_PHI_dijet2->Draw("HIST");
  plot_DR_dijet2->Draw("HIST");
  
  //general plots b_dijet2 ***************************************************************************
  plot_PT_b_dijet2->Draw("HIST");
  plot_ETA_b_dijet2->Draw("HIST");
  plot_M_b_dijet2->Draw("HIST");
  plot_PHI_b_dijet2->Draw("HIST");
  plot_DR_b_dijet2->Draw("HIST");
  
  //DIJET2 ********************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->Draw("HIST");
  plot_ETA_dijet2_not->Draw("HIST");
  plot_M_dijet2_not->Draw("HIST");
  plot_PHI_dijet2_not->Draw("HIST");
  plot_DR_dijet2_not->Draw("HIST");
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->Draw("HIST");
  plot_ETA_dijet2_partially->Draw("HIST");
  plot_M_dijet2_partially->Draw("HIST");
  plot_PHI_dijet2_partially->Draw("HIST");
  plot_DR_dijet2_partially->Draw("HIST");
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->Draw("HIST");
  plot_ETA_dijet2_fully->Draw("HIST");
  plot_M_dijet2_fully->Draw("HIST");
  plot_PHI_dijet2_fully->Draw("HIST");
  plot_DR_dijet2_fully->Draw("HIST");
  
  //B_DIJET2 ******************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->Draw("HIST");
  plot_ETA_b_dijet2_partially->Draw("HIST");
  plot_M_b_dijet2_partially->Draw("HIST");
  plot_PHI_b_dijet2_partially->Draw("HIST");
  plot_DR_b_dijet2_partially->Draw("HIST");
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->Draw("HIST");
  plot_ETA_b_dijet2_fully->Draw("HIST");
  plot_M_b_dijet2_fully->Draw("HIST");
  plot_PHI_b_dijet2_fully->Draw("HIST");
  plot_DR_b_dijet2_fully->Draw("HIST");
  
  
  
  
  
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************
  //general plots dijet1 *****************************************************************************
  plot_N_Merged1->Write();
  
  //general plots dijet1 *****************************************************************************
  plot_PT_dijet1->Write();
  plot_ETA_dijet1->Write();
  plot_M_dijet1->Write();
  plot_PHI_dijet1->Write();
  plot_DR_dijet1->Write();
  
  //general plots b_dijet1 ***************************************************************************
  plot_PT_b_dijet1->Write();
  plot_ETA_b_dijet1->Write();
  plot_M_b_dijet1->Write();
  plot_PHI_b_dijet1->Write();
  plot_DR_b_dijet1->Write();
  
  //DIJET1 ********************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->Write();
  plot_ETA_dijet1_not->Write();
  plot_M_dijet1_not->Write();
  plot_PHI_dijet1_not->Write();
  plot_DR_dijet1_not->Write();
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->Write();
  plot_ETA_dijet1_partially->Write();
  plot_M_dijet1_partially->Write();
  plot_PHI_dijet1_partially->Write();
  plot_DR_dijet1_partially->Write();
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->Write();
  plot_ETA_dijet1_fully->Write();
  plot_M_dijet1_fully->Write();
  plot_PHI_dijet1_fully->Write();
  plot_DR_dijet1_fully->Write();
  
  //B_DIJET1 ******************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->Write();
  plot_ETA_b_dijet1_partially->Write();
  plot_M_b_dijet1_partially->Write();
  plot_PHI_b_dijet1_partially->Write();
  plot_DR_b_dijet1_partially->Write();
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->Write();
  plot_ETA_b_dijet1_fully->Write();
  plot_M_b_dijet1_fully->Write();
  plot_PHI_b_dijet1_fully->Write();
  plot_DR_b_dijet1_fully->Write();
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************
  //general plots dijet2 *****************************************************************************
  plot_N_Merged2->Write();
  plot_Smallest_DR_dijet->Write();
  plot_Smallest_DR_b_dijet->Write();
  
  //general plots dijet2 *****************************************************************************
  plot_PT_dijet2->Write();
  plot_ETA_dijet2->Write();
  plot_M_dijet2->Write();
  plot_PHI_dijet2->Write();
  plot_DR_dijet2->Write();
  
  //general plots b_dijet2 ***************************************************************************
  plot_PT_b_dijet2->Write();
  plot_ETA_b_dijet2->Write();
  plot_M_b_dijet2->Write();
  plot_PHI_b_dijet2->Write();
  plot_DR_b_dijet2->Write();
  
  //DIJET2 ********************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->Write();
  plot_ETA_dijet2_not->Write();
  plot_M_dijet2_not->Write();
  plot_PHI_dijet2_not->Write();
  plot_DR_dijet2_not->Write();
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->Write();
  plot_ETA_dijet2_partially->Write();
  plot_M_dijet2_partially->Write();
  plot_PHI_dijet2_partially->Write();
  plot_DR_dijet2_partially->Write();
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->Write();
  plot_ETA_dijet2_fully->Write();
  plot_M_dijet2_fully->Write();
  plot_PHI_dijet2_fully->Write();
  plot_DR_dijet2_fully->Write();
  
  //B_DIJET2 ******************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->Write();
  plot_ETA_b_dijet2_partially->Write();
  plot_M_b_dijet2_partially->Write();
  plot_PHI_b_dijet2_partially->Write();
  plot_DR_b_dijet2_partially->Write();
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->Write();
  plot_ETA_b_dijet2_fully->Write();
  plot_M_b_dijet2_fully->Write();
  plot_PHI_b_dijet2_fully->Write();
  plot_DR_b_dijet2_fully->Write();
  
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
	//general plots dijet1 ************************************************************************************
	//fills N_merged1.
	if(notMerged[0])
	{
		Manager()->FillHisto("N_Merged1", 1);
		plot_N_Merged1->Fill(1);
	}
	
	if(partiallyMerged[0])
	{
		Manager()->FillHisto("N_Merged1", 2);
		plot_N_Merged1->Fill(2);
	}
	
	if(fullyMerged[0])
	{
		Manager()->FillHisto("N_Merged1", 3);
		plot_N_Merged1->Fill(3);
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
  
	//general plots dijet1 *****************************************************************************
	//fils PT_dijet1.
	Manager()->FillHisto("PT_dijet1", dijet1.Pt());
        plot_PT_dijet1->Fill(dijet1.Pt());

	//fils ETA_dijet1.
	Manager()->FillHisto("ETA_dijet1", dijet1.Eta());
        plot_ETA_dijet1->Fill(dijet1.Eta());

	//fils M_dijet1.
	Manager()->FillHisto("M_dijet1", dijet1.M());
        plot_M_dijet1->Fill(dijet1.M());
        
	//fils PHI_dijet1.
	Manager()->FillHisto("PHI_dijet1", dijet1.Phi());
        plot_PHI_dijet1->Fill(dijet1.Phi());
        
	//fils DR_dijet1.
	Manager()->FillHisto("DR_dijet1", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        plot_DR_dijet1->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
	
	//general plots b_dijet1 ***************************************************************************
	if (notMerged[0] == false){
		//fils PT_b_dijet1.
		Manager()->FillHisto("PT_b_dijet1", b_dijet1.Pt());
        	plot_PT_b_dijet1->Fill(b_dijet1.Pt());

		//fils ETA_b_dijet1.
		Manager()->FillHisto("ETA_b_dijet1", b_dijet1.Eta());
        	plot_ETA_b_dijet1->Fill(b_dijet1.Eta());

		//fils M_b_dijet1.
		Manager()->FillHisto("M_b_dijet1", b_dijet1.M());
        	plot_M_b_dijet1->Fill(b_dijet1.M());
        
		//fils PHI_b_dijet1.
		Manager()->FillHisto("PHI_b_dijet1", b_dijet1.Phi());
        	plot_PHI_b_dijet1->Fill(b_dijet1.Phi());
        
		//fils DR_b_dijet1.
		Manager()->FillHisto("DR_b_dijet1", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet1->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
	}
	
	//DIJET1 ********************************************************************************************
  	//plots of the dijet1 pairs that are not merged.
  	if(notMerged[0]){
  		//fils PT_dijet1_not.
		Manager()->FillHisto("PT_dijet1_not", dijet1.Pt());
        	plot_PT_dijet1_not->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_not.
		Manager()->FillHisto("ETA_dijet1_not", dijet1.Eta());
        	plot_ETA_dijet1_not->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_not.
		Manager()->FillHisto("M_dijet1_not", dijet1.M());
        	plot_M_dijet1_not->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_not.
		Manager()->FillHisto("PHI_dijet1_not", dijet1.Phi());
        	plot_PHI_dijet1_not->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_not.
		Manager()->FillHisto("DR_dijet1_not", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_not->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
 
	//plots of the dijet1 pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_dijet1_partially.
		Manager()->FillHisto("PT_dijet1_partially", dijet1.Pt());
        	plot_PT_dijet1_partially->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_partially.
		Manager()->FillHisto("ETA_dijet1_partially", dijet1.Eta());
        	plot_ETA_dijet1_partially->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_partially.
		Manager()->FillHisto("M_dijet1_partially", dijet1.M());
        	plot_M_dijet1_partially->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_partially.
		Manager()->FillHisto("PHI_dijet1_partially", dijet1.Phi());
        	plot_PHI_dijet1_partially->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_partially.
		Manager()->FillHisto("DR_dijet1_partially", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_partially->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
  
	//plots of the dijet1 pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_dijet1_fully.
		Manager()->FillHisto("PT_dijet1_fully", dijet1.Pt());
        	plot_PT_dijet1_fully->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_fully.
		Manager()->FillHisto("ETA_dijet1_fully", dijet1.Eta());
        	plot_ETA_dijet1_fully->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_fully.
		Manager()->FillHisto("M_dijet1_fully", dijet1.M());
        	plot_M_dijet1_fully->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_fully.
		Manager()->FillHisto("PHI_dijet1_fully", dijet1.Phi());
        	plot_PHI_dijet1_fully->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_fully.
		Manager()->FillHisto("DR_dijet1_fully", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_fully->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}

  	//B_DIJET1 ****************************************************************************************** 
	//plots of the b_dijet1 pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_b_dijet1_partially.
		Manager()->FillHisto("PT_b_dijet1_partially", b_dijet1.Pt());
        	plot_PT_b_dijet1_partially->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet1_partially.
		Manager()->FillHisto("ETA_b_dijet1_partially", b_dijet1.Eta());
        	plot_ETA_b_dijet1_partially->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet1_partially.
		Manager()->FillHisto("M_b_dijet1_partially", b_dijet1.M());
        	plot_M_b_dijet1_partially->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet1_partially.
		Manager()->FillHisto("PHI_b_dijet1_partially", b_dijet1.Phi());
        	plot_PHI_b_dijet1_partially->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet1_partially.
		Manager()->FillHisto("DR_b_dijet1_partially", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet1_partially->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}
  
	//plots of the b_dijet1 pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_b_dijet1_fully.
		Manager()->FillHisto("PT_b_dijet1_fully", b_dijet1.Pt());
        	plot_PT_b_dijet1_fully->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet1_fully.
		Manager()->FillHisto("ETA_b_dijet1_fully", b_dijet1.Eta());
        	plot_ETA_b_dijet1_fully->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet1_fully.
		Manager()->FillHisto("M_b_dijet1_fully", b_dijet1.M());
        	plot_M_b_dijet1_fully->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet1_fully.
		Manager()->FillHisto("PHI_b_dijet1_fully", b_dijet1.Phi());
        	plot_PHI_b_dijet1_fully->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet1_fully.
		Manager()->FillHisto("DR_b_dijet1_fully", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet1_fully->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}
  	
  	



  	//MAKES ALL PLOTS FOR THE SECOND DIJET AND B_DIJET PAIRS, ONLY IN THE FULLY HADRONIC CHANNEL.
  	if (FinalStateJs.size() == 4){
  	
	  	//general plots dijet2 ************************************************************************************
		//fills N_merged2.
		if(notMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 1);
			plot_N_Merged2->Fill(1);
		}
	
		if(partiallyMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 2);
			plot_N_Merged2->Fill(2);
		}
	
		if(fullyMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 3);
			plot_N_Merged2->Fill(3);
		}
  	
		//general plots dijet2 *****************************************************************************
		//fils PT_dijet2.
		Manager()->FillHisto("PT_dijet2", dijet2.Pt());
        	plot_PT_dijet2->Fill(dijet2.Pt());
	
		//fils ETA_dijet2.
		Manager()->FillHisto("ETA_dijet2", dijet2.Eta());
        	plot_ETA_dijet2->Fill(dijet2.Eta());
	
		//fils M_dijet2.
		Manager()->FillHisto("M_dijet2", dijet2.M());
        	plot_M_dijet2->Fill(dijet2.M());
        	
		//fils PHI_dijet2.
		Manager()->FillHisto("PHI_dijet2", dijet2.Phi());
        	plot_PHI_dijet2->Fill(dijet2.Phi());
        	
		//fils DR_dijet2.
		Manager()->FillHisto("DR_dijet2", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        	plot_DR_dijet2->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
		
		//general plots b_dijet2 ***************************************************************************
		if (notMerged[1] == false){
			//fils PT_b_dijet2.
			Manager()->FillHisto("PT_b_dijet2", b_dijet2.Pt());
        		plot_PT_b_dijet2->Fill(b_dijet2.Pt());
			
			//fils ETA_b_dijet2.
			Manager()->FillHisto("ETA_b_dijet2", b_dijet2.Eta());
        		plot_ETA_b_dijet2->Fill(b_dijet2.Eta());
		
			//fils M_b_dijet2.
			Manager()->FillHisto("M_b_dijet2", b_dijet2.M());
        		plot_M_b_dijet2->Fill(b_dijet2.M());
        	
			//fils PHI_b_dijet2.
			Manager()->FillHisto("PHI_b_dijet2", b_dijet2.Phi());
        		plot_PHI_b_dijet2->Fill(b_dijet2.Phi());
        	
			//fils DR_b_dijet2.
			Manager()->FillHisto("DR_b_dijet2", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        		plot_DR_b_dijet2->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
		}
		
		//DIJET2 ********************************************************************************************
  		//plots of the dijet2 pairs that are not merged.
  		if(notMerged[1]){
  			//fils PT_dijet2_not.
			Manager()->FillHisto("PT_dijet2_not", dijet2.Pt());
        		plot_PT_dijet2_not->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_not.
			Manager()->FillHisto("ETA_dijet2_not", dijet2.Eta());
        		plot_ETA_dijet2_not->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_not.
			Manager()->FillHisto("M_dijet2_not", dijet2.M());
        		plot_M_dijet2_not->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_not.
			Manager()->FillHisto("PHI_dijet2_not", dijet2.Phi());
        		plot_PHI_dijet2_not->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_not.
			Manager()->FillHisto("DR_dijet2_not", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_not->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
 	
		//plots of the dijet2 pairs that are partially merged.
	  	if(partiallyMerged[1]){
	  		//fils PT_dijet2_partially.
			Manager()->FillHisto("PT_dijet2_partially", dijet2.Pt());
        		plot_PT_dijet2_partially->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_partially.
			Manager()->FillHisto("ETA_dijet2_partially", dijet2.Eta());
        		plot_ETA_dijet2_partially->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_partially.
			Manager()->FillHisto("M_dijet2_partially", dijet2.M());
        		plot_M_dijet2_partially->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_partially.
			Manager()->FillHisto("PHI_dijet2_partially", dijet2.Phi());
        		plot_PHI_dijet2_partially->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_partially.
			Manager()->FillHisto("DR_dijet2_partially", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_partially->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
  	
		//plots of the dijet2 pairs that are fully merged.
  		if(fullyMerged[1]){
  			//fils PT_dijet2_fully.
			Manager()->FillHisto("PT_dijet2_fully", dijet2.Pt());
        		plot_PT_dijet2_fully->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_fully.
			Manager()->FillHisto("ETA_dijet2_fully", dijet2.Eta());
        		plot_ETA_dijet2_fully->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_fully.
			Manager()->FillHisto("M_dijet2_fully", dijet2.M());
        		plot_M_dijet2_fully->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_fully.
			Manager()->FillHisto("PHI_dijet2_fully", dijet2.Phi());
        		plot_PHI_dijet2_fully->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_fully.
			Manager()->FillHisto("DR_dijet2_fully", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_fully->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
	
	  	//B_DIJET2 ****************************************************************************************** 
		//plots of the b_dijet2 pairs that are partially merged.
	  	if(partiallyMerged[1]){
  			//fils PT_b_dijet2_partially.
			Manager()->FillHisto("PT_b_dijet2_partially", b_dijet2.Pt());
        		plot_PT_b_dijet2_partially->Fill(b_dijet2.Pt());
        		
        		//fils ETA_b_dijet2_partially.
			Manager()->FillHisto("ETA_b_dijet2_partially", b_dijet2.Eta());
        		plot_ETA_b_dijet2_partially->Fill(b_dijet2.Eta());
        		
        		//fils M_b_dijet2_partially.
			Manager()->FillHisto("M_b_dijet2_partially", b_dijet2.M());
        		plot_M_b_dijet2_partially->Fill(b_dijet2.M());
        		
        		//fils PHI_b_dijet2_partially.
			Manager()->FillHisto("PHI_b_dijet2_partially", b_dijet2.Phi());
        		plot_PHI_b_dijet2_partially->Fill(b_dijet2.Phi());
        		
        		//fils DR_b_dijet2_partially.
			Manager()->FillHisto("DR_b_dijet2_partially", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        		plot_DR_b_dijet2_partially->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
  		}
  	
		//plots of the b_dijet2 pairs that are fully merged.
	  	if(fullyMerged[1]){
  			//fils PT_b_dijet2_fully.
			Manager()->FillHisto("PT_b_dijet2_fully", b_dijet2.Pt());
        		plot_PT_b_dijet2_fully->Fill(b_dijet2.Pt());
        		
        		//fils ETA_b_dijet2_fully.
			Manager()->FillHisto("ETA_b_dijet2_fully", b_dijet2.Eta());
        		plot_ETA_b_dijet2_fully->Fill(b_dijet2.Eta());
        		
        		//fils M_b_dijet2_fully.
			Manager()->FillHisto("M_b_dijet2_fully", b_dijet2.M());
        		plot_M_b_dijet2_fully->Fill(b_dijet2.M());
        		
        		//fils PHI_b_dijet2_fully.
			Manager()->FillHisto("PHI_b_dijet2_fully", b_dijet2.Phi());
        		plot_PHI_b_dijet2_fully->Fill(b_dijet2.Phi());
        		
        		//fils DR_b_dijet2_fully.
			Manager()->FillHisto("DR_b_dijet2_fully", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        		plot_DR_b_dijet2_fully->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
  		}
  	}
  	
  	



  return true;
}

