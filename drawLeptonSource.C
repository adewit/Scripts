void drawLeptonSource(){
TFile *f1 = TFile::Open("output/Nov19WithSVFit/DYJetsToLL_M-50-LO_mt_2015.root");
TFile *f2 = TFile::Open("output/Nov19WithSVFit/DYJetsToLL_M-50-LO_et_2015.root");
TFile *f3 = TFile::Open("output/Nov19WithSVFit/TT-ext_em_2015.root");
TFile *f4 = TFile::Open("output/Nov19WithSVFit/TT-ext_tt_2015.root");
TTree *mttree = dynamic_cast<TTree*>(f1->Get("ntuple"));
TTree *ettree = dynamic_cast<TTree*>(f2->Get("ntuple"));
TTree *emtree = dynamic_cast<TTree*>(f3->Get("ntuple"));
TTree *tttree = dynamic_cast<TTree*>(f4->Get("ntuple"));




double iso_1, iso_2, wt;
bool leptonveto, antiele_2, antimu_2, antiele_1,antimu_1, os, db_wp_2, db_wp_1;
unsigned gen_match_1, gen_match_2;
int dm_1, dm_2;

gStyle->SetPaintTextFormat(".1f %%");

mttree->SetBranchAddress("iso_1",&iso_1);
mttree->SetBranchAddress("db_medium_2",&db_wp_2);
mttree->SetBranchAddress("leptonveto",&leptonveto);
mttree->SetBranchAddress("antiele_2",&antiele_2);
mttree->SetBranchAddress("antimu_2",&antimu_2);
mttree->SetBranchAddress("os",&os);
mttree->SetBranchAddress("tau_decay_mode_2",&dm_2);
mttree->SetBranchAddress("gen_match_1",&gen_match_1);
mttree->SetBranchAddress("gen_match_2",&gen_match_2);
mttree->SetBranchAddress("wt",&wt);

TH2F *mt_pairinfo = new TH2F("mt_pairinfo",";Reco #mu;Reco #tau_{h}",6,0.5,6.5,6,0.5,6.5);
mt_pairinfo->GetYaxis()->SetTitleOffset(1.6);

Int_t nVals = mttree->GetEntries();
for(Int_t i=0 ;i<nVals;i++){
mttree->GetEntry(i);
if(iso_1<0.1&&db_wp_2>0.5&&leptonveto<1&&antiele_2>0&&antimu_2>0&&os>0&&dm_2!=5&&dm_2!=6){
//if(leptonveto<1&&antiele_2>0&&antimu_2>0&&os>0){
  mt_pairinfo->Fill(gen_match_1,gen_match_2,wt);
}
}
gStyle->SetPaintTextFormat(".1f %%");
TCanvas *c1 = new TCanvas("c1","c1",0,0,1200,800);
mt_pairinfo->SetStats(0);
mt_pairinfo->GetXaxis()->SetBinLabel(1,"Prompt e");
mt_pairinfo->GetXaxis()->SetBinLabel(2,"Prompt #mu");
mt_pairinfo->GetXaxis()->SetBinLabel(3,"#tau #rightarrow e");
mt_pairinfo->GetXaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
mt_pairinfo->GetXaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
mt_pairinfo->GetXaxis()->SetBinLabel(6,"Jet/PU fake");
//mt_pairinfo->GetXaxis()->SetBinLabel(7,"e from hadron");
//mt_pairinfo->GetXaxis()->SetBinLabel(8,"#mu from hadron");
mt_pairinfo->GetYaxis()->SetBinLabel(1,"Prompt e");
mt_pairinfo->GetYaxis()->SetBinLabel(2,"Prompt #mu");
mt_pairinfo->GetYaxis()->SetBinLabel(3,"#tau #rightarrow e");
mt_pairinfo->GetYaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
mt_pairinfo->GetYaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
mt_pairinfo->GetYaxis()->SetBinLabel(6,"Jet/PU fake");
//mt_pairinfo->GetYaxis()->SetBinLabel(7,"e from hadron");
//mt_pairinfo->GetYaxis()->SetBinLabel(8,"#mu from hadron");
std::cout<<"Mutau integral: "<<mt_pairinfo->Integral()<<std::endl;

mt_pairinfo->Scale(100/mt_pairinfo->Integral());
mt_pairinfo->Draw("TEXT");


ettree->SetBranchAddress("iso_1",&iso_1);
ettree->SetBranchAddress("db_medium_2",&db_wp_2);
ettree->SetBranchAddress("leptonveto",&leptonveto);
ettree->SetBranchAddress("antiele_2",&antiele_2);
ettree->SetBranchAddress("antimu_2",&antimu_2);
ettree->SetBranchAddress("os",&os);
ettree->SetBranchAddress("tau_decay_mode_2",&dm_2);
ettree->SetBranchAddress("gen_match_1",&gen_match_1);
ettree->SetBranchAddress("gen_match_2",&gen_match_2);
ettree->SetBranchAddress("wt",&wt);

TH2F *et_pairinfo = new TH2F("et_pairinfo",";Reco e;Reco #tau_{h}",6,0.5,6.5,6,0.5,6.5);
et_pairinfo->GetXaxis()->SetBinLabel(1,"Prompt e");
et_pairinfo->GetXaxis()->SetBinLabel(2,"Prompt #mu");
et_pairinfo->GetXaxis()->SetBinLabel(3,"#tau #rightarrow e");
et_pairinfo->GetXaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
et_pairinfo->GetXaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
et_pairinfo->GetXaxis()->SetBinLabel(6,"Jet/PU fake");
//et_pairinfo->GetXaxis()->SetBinLabel(7,"e from hadron");
//et_pairinfo->GetXaxis()->SetBinLabel(8,"#mu from hadron");
et_pairinfo->GetYaxis()->SetBinLabel(1,"Prompt e");
et_pairinfo->GetYaxis()->SetBinLabel(2,"Prompt #mu");
et_pairinfo->GetYaxis()->SetBinLabel(3,"#tau #rightarrow e");
et_pairinfo->GetYaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
et_pairinfo->GetYaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
et_pairinfo->GetYaxis()->SetBinLabel(6,"Jet/PU fake");
//et_pairinfo->GetYaxis()->SetBinLabel(7,"e from hadron");
//et_pairinfo->GetYaxis()->SetBinLabel(8,"#mu from hadron");


nVals = ettree->GetEntries();
for(Int_t i=0 ;i<nVals;i++){
ettree->GetEntry(i);
if(iso_1<0.1&&db_wp_2>0.5&&leptonveto<1&&antiele_2>0&&antimu_2>0&&os>0&&dm_2!=5&&dm_2!=6){
//if(leptonveto<1&&antiele_2>0&&antimu_2>0&&os>0){
  et_pairinfo->Fill(gen_match_1,gen_match_2,wt);
}
}
TCanvas *c2 = new TCanvas("c2","c2",0,0,1200,800);
et_pairinfo->SetStats(0);
et_pairinfo->GetYaxis()->SetTitleOffset(1.6);
std::cout<<"Etau integral: "<<et_pairinfo->Integral()<<std::endl;
et_pairinfo->Scale(100./et_pairinfo->Integral());
et_pairinfo->Draw("TEXT");


/*emtree->SetBranchAddress("iso_1",&iso_1);
emtree->SetBranchAddress("iso_2",&iso_2);
emtree->SetBranchAddress("leptonveto",&leptonveto);
emtree->SetBranchAddress("antiele_2",&antiele_2);
emtree->SetBranchAddress("antimu_2",&antimu_2);
emtree->SetBranchAddress("os",&os);
emtree->SetBranchAddress("gen_match_1",&gen_match_1);
emtree->SetBranchAddress("gen_match_2",&gen_match_2);
emtree->SetBranchAddress("wt",&wt);

TH2F *em_pairinfo = new TH2F("em_pairinfo",";Reco e;Reco #mu",6,0.5,6.5,6,0.5,6.5);
em_pairinfo->GetXaxis()->SetBinLabel(1,"Prompt e");
em_pairinfo->GetXaxis()->SetBinLabel(2,"Prompt #mu");
em_pairinfo->GetXaxis()->SetBinLabel(3,"#tau #rightarrow e");
em_pairinfo->GetXaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
em_pairinfo->GetXaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
em_pairinfo->GetXaxis()->SetBinLabel(6,"Jet/PU fake");
//em_pairinfo->GetXaxis()->SetBinLabel(7,"e from hadron");
//em_pairinfo->GetXaxis()->SetBinLabel(8,"#mu from hadron");
em_pairinfo->GetYaxis()->SetBinLabel(1,"Prompt e");
em_pairinfo->GetYaxis()->SetBinLabel(2,"Prompt #mu");
em_pairinfo->GetYaxis()->SetBinLabel(3,"#tau #rightarrow e");
em_pairinfo->GetYaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
em_pairinfo->GetYaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
em_pairinfo->GetYaxis()->SetBinLabel(6,"Jet/PU fake");
//em_pairinfo->GetYaxis()->SetBinLabel(7,"e from hadron");
//em_pairinfo->GetYaxis()->SetBinLabel(8,"#mu from hadron");

nVals = emtree->GetEntries();
for(Int_t i=0 ;i<nVals;i++){
emtree->GetEntry(i);
if(iso_1<0.15&&iso_2<0.15&&leptonveto<1&&os>0){
//if(leptonveto<1&&os>0){
  em_pairinfo->Fill(gen_match_1,gen_match_2,wt);
}
}
TCanvas *c3 = new TCanvas("c3","c3",0,0,1200,800);
em_pairinfo->SetStats(0);
std::cout<<"EMu integral: "<<em_pairinfo->Integral()<<std::endl;
em_pairinfo->GetYaxis()->SetTitleOffset(1.6);
em_pairinfo->Scale(100./em_pairinfo->Integral());
em_pairinfo->Draw("TEXT");
*/



/*tttree->SetBranchAddress("db_tight_1",&db_wp_1);
tttree->SetBranchAddress("db_tight_2",&db_wp_2);
tttree->SetBranchAddress("leptonveto",&leptonveto);
tttree->SetBranchAddress("antiele_2",&antiele_2);
tttree->SetBranchAddress("antimu_2",&antimu_2);
tttree->SetBranchAddress("antiele_1",&antiele_1);
tttree->SetBranchAddress("antimu_1",&antimu_1);
tttree->SetBranchAddress("os",&os);
tttree->SetBranchAddress("gen_match_1",&gen_match_1);
tttree->SetBranchAddress("gen_match_2",&gen_match_2);
tttree->SetBranchAddress("wt",&wt);

TH2F *tt_pairinfo = new TH2F("tt_pairinfo",";Leading reco #tau_{h};Subleading reco #tau_{h}",6,0.5,6.5,6,0.5,6.5);
tt_pairinfo->GetXaxis()->SetBinLabel(1,"Prompt e");
tt_pairinfo->GetXaxis()->SetBinLabel(2,"Prompt #mu");
tt_pairinfo->GetXaxis()->SetBinLabel(3,"#tau #rightarrow e");
tt_pairinfo->GetXaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
tt_pairinfo->GetXaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
tt_pairinfo->GetXaxis()->SetBinLabel(6,"Jet/PU fake");
//tt_pairinfo->GetXaxis()->SetBinLabel(7,"e from hadron");
//tt_pairinfo->GetXaxis()->SetBinLabel(8,"#mu from hadron");
tt_pairinfo->GetYaxis()->SetBinLabel(1,"Prompt e");
tt_pairinfo->GetYaxis()->SetBinLabel(2,"Prompt #mu");
tt_pairinfo->GetYaxis()->SetBinLabel(3,"#tau #rightarrow e");
tt_pairinfo->GetYaxis()->SetBinLabel(4,"#tau #rightarrow #mu");
tt_pairinfo->GetYaxis()->SetBinLabel(5,"#tau #rightarrow #tau_{h}");
tt_pairinfo->GetYaxis()->SetBinLabel(6,"Jet/PU fake");
//tt_pairinfo->GetYaxis()->SetBinLabel(7,"e from hadron");
//tt_pairinfo->GetYaxis()->SetBinLabel(8,"#mu from hadron");


nVals = tttree->GetEntries();
for(Int_t i=0 ;i<nVals;i++){
tttree->GetEntry(i);
if(db_wp_1>0.5&&db_wp_2>0.5&&leptonveto<1&&os>0&&antiele_2>0&&antimu_2>0&&antiele_1>0&&antimu_1>0){
//if(leptonveto<1&&os>0&&antiele_2>0&&antimu_2>0&&antiele_1>0&&antimu_1>0){
  tt_pairinfo->Fill(gen_match_1,gen_match_2,wt);
}
}
TCanvas *c4 = new TCanvas("c4","c4",0,0,1200,800);
tt_pairinfo->GetYaxis()->SetTitleOffset(1.6);
tt_pairinfo->SetStats(0);
std::cout<<"Tautau integral: "<<tt_pairinfo->Integral()<<std::endl;
tt_pairinfo->Scale(100./tt_pairinfo->Integral());
tt_pairinfo->Draw("TEXT");
*/



}



