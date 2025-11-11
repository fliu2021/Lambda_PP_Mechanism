#define genEvent_cxx
#include "genEvent.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void genEvent::Loop()
{
//   In a ROOT session, you can do:
//      root> .L genEvent.C
//      root> genEvent t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   TH1D *h_b_distribution =new TH1D("h_b_distribution","h_b_distribution",15,0,15);
   if (fChain == 0) return;

   int N_events = fChain->GetEntriesFast();
   for(int i_event =0 ;i_event < N_events;i_event++){
      fChain->GetEntry(i_event);
      h_b_distribution->Fill(b);
   }
   h_b_distribution->Draw();

  
}
