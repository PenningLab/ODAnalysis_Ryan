#define ODAnalysis_cxx

#include "ODAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <TFile.h>

#include <iostream>

using namespace std;

// Function declarations
void deriveDetRQs(MyEvent & e, MyDetectorPulses & defdet, MyDetectorPulses & newdet);
void deriveMctRQs(MyEvent & e);
void buildSS(MyEvent & e);
void buildMS(MyEvent & e);
bool sortinrev(const pair<float,int> &a,
               const pair<float,int> &b);
bool comp_pair(const pair<float,int> &a,
               const pair<float,int> &b);
pair < MyDetectorPulses, int > det(MyEvent & e, int p);
void ODPosition();
TH1F* CreateSumw2Hist(string hname,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max);
TH1F* Create1DHist(string h1name,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max);
TH2D* Create2DHist(string h2name,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max,double Ybins, double Ybin_min, double Ybin_max);
//TVector3 CentroidFit(vector <double>&v);

// TPC geometry
static const float kTPCradius = 145.6/2.; //[cm]
static const float kTPCheight = 145.6;    //[cm]

// Fiducial Volume cuts
static const float kRmax =  68.8;   //[cm]
static const float kZmin =   2.0;   //[cm]
static const float kZmax = 132.6;   //[cm]

static const int nPulseClasses = 8;
enum PulseClass : unsigned int
{
    OTHER,
    OTHERS2,
    SE,
    SPE,
    MPE,
    S1,
    S2,
    ALL
};

const vector<PulseClass> allPulseClasses()
{
    vector<PulseClass> allClasses;
    allClasses.push_back(PulseClass::OTHER);
    allClasses.push_back(PulseClass::OTHERS2);
    allClasses.push_back(PulseClass::SE);
    allClasses.push_back(PulseClass::SPE);
    allClasses.push_back(PulseClass::MPE);
    allClasses.push_back(PulseClass::S1);
    allClasses.push_back(PulseClass::S2);
    allClasses.push_back(PulseClass::ALL);
    return allClasses;
}

const TString pulseClassToString(PulseClass clazz)
{
    if      (clazz == PulseClass::OTHER)   return "Other";
    else if (clazz == PulseClass::OTHERS2) return "OtherS2";
    else if (clazz == PulseClass::SE)      return "SE";
    else if (clazz == PulseClass::SPE)     return "SPE";
    else if (clazz == PulseClass::MPE)     return "MPE";
    else if (clazz == PulseClass::S1)      return "S1";
    else if (clazz == PulseClass::S2)      return "S2";
    else if (clazz == PulseClass::ALL)     return "All";
    else return "None";
}

//________________________________________________________
void Loggify(TAxis* axis) {
    int bins = axis->GetNbins();

    Axis_t from = TMath::Log10(axis->GetXmin());
    Axis_t to = TMath::Log10(axis->GetXmax());
    Axis_t width = (to - from) / bins;
    Axis_t *new_bins = new Axis_t[bins + 1];

    for (int i = 0; i <= bins; i++) new_bins[i] = TMath::Power(10, from + i * width);
    axis->Set(bins, new_bins);
    delete[] new_bins;
}
void LoggifyX(TH1* h)  { Loggify(h->GetXaxis()); }
void LoggifyXY(TH2* h) { Loggify(h->GetXaxis()); Loggify(h->GetYaxis()); }
void LoggifyX(TH2* h)  { Loggify(h->GetXaxis()); }
void LoggifyY(TH2* h)  { Loggify(h->GetYaxis()); }

//________________________________________________________
void ODAnalysis::Begin(TTree * /*tree*/)
{
    TString option = GetOption();
}

//________________________________________________________
void ODAnalysis::SlaveBegin(TTree * /*tree*/)
{

    TString option = GetOption();

    e = MyEvent();

    h_pulseArea_phd_ODHG_int_1us = Create1DHist("pulseArea_phd_ODHG_int_1us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_2us = Create1DHist("pulseArea_phd_ODHG_int_2us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_3us = Create1DHist("pulseArea_phd_ODHG_int_3us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_30us = Create1DHist("pulseArea_phd_ODHG_int_30us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_130us = Create1DHist("pulseArea_phd_ODHG_int_130us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_230us = Create1DHist("pulseArea_phd_ODHG_int_230us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_330us = Create1DHist("pulseArea_phd_ODHG_int_330us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_500us = Create1DHist("pulseArea_phd_ODHG_int_500us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);

    h_pulseArea_phd_ODHG_int_1000us = Create1DHist("pulseArea_phd_ODHG_int_1000us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_1500us = Create1DHist("pulseArea_phd_ODHG_int_1500us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_2000us = Create1DHist("pulseArea_phd_ODHG_int_2000us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_2500us = Create1DHist("pulseArea_phd_ODHG_int_2500us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_3000us = Create1DHist("pulseArea_phd_ODHG_int_3000us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);
    h_pulseArea_phd_ODHG_int_3700us = Create1DHist("pulseArea_phd_ODHG_int_3700us"," pulse area (phd)"," Counts (/phd)",3000,0,3000);

    fOutput->Add(h_pulseArea_phd_ODHG_int_1us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_2us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_3us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_30us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_130us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_230us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_330us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_500us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_1000us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_1500us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_2000us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_2500us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_3000us);
    fOutput->Add(h_pulseArea_phd_ODHG_int_3700us);



}//SlaveBegin

//________________________________________________________
// Define cuts
bool CXTPC(MyEvent const& e) { return e.tpcHG.nPulses > 0; }
bool CXnS1only(MyEvent const& e) {
    bool isS1only = true;
    for (int p=0; p<e.tpcHG.nPulses; ++p) {
    if (e.tpcHG.s2prob[p]==1)
      isS1only = false;
    }
    return !isS1only;
}

bool CXOtherS2notBiggest (MyEvent const& e) {
    if (e.tpc.maxPulseClass == PulseClass::OTHERS2) return false;
    return true; }

bool CXPPT(MyEvent const& e) {
    for (size_t p=0; p<e.mcPulseLength.size(); ++p) {
    if (e.mcPulseLength[p] > 1e6)
      return false;
    }
    return true;
}

bool CXMC4MeV(MyEvent const& e) {
    for (size_t v=0; v<e.mcVtxEnergyDep.size(); ++v) {
    if (e.mcVtxEnergyDep[v] > 4000 && (e.mcVtxVolumeName[v] == "LiquidXenonTarget" ||
    			       e.mcVtxVolumeName[v] == "LiquidSkinXenon" ||
    			       e.mcVtxVolumeName[v] == "ReverseFieldRegion" ||
    			       e.mcVtxVolumeName[v] == "LiquidSkinXenonBank")) {
      return false;
    }
    if (e.mcVtxVolumeName[v] == "LiquidXenonTarget" &&
    e.mcVtxRawS2photons[v] == 0) {
      return false;
    }
    }
    return true;
}

bool CXHE(MyEvent const& e) { return e.tpc.maxS1area > 150; }
bool CXLE(MyEvent const& e) { return e.tpc.maxS1area < 600; }
bool CXS1first(MyEvent const& e) {
    // check that there is an S1 (otherwise, this cut makes no sense)
    if (e.tpc.maxS1pulseID == -1) return false;
    // check that s1pulseID < s2pulseID
    if (e.tpc.maxS1pulseID > e.tpc.maxS2pulseID) return false;
    // No S2, SE, OtherS2 allowed before S1 (what about Other???)
    for (int p=0; p<e.tpc.maxS1pulseID; ++p) {
    if (e.tpc.pulseClass[p] == PulseClass::S2 ||
        e.tpc.pulseClass[p] == PulseClass::SE ||
        e.tpc.pulseClass[p] == PulseClass::OTHERS2 ||
    e.tpc.pulseClass[p] == PulseClass::OTHER)
      return false;
    }
    return true;
}

bool CXFiducial(MyEvent const& e) { return e.ss.corrRpos < kRmax && e.ss.zPos > kZmin && e.ss.zPos < kZmax; }
bool CXKr83 (MyEvent const& e){
    if (e.tpc.maxS1pulseID <0 || e.tpc.maxS2pulseID < 0) return false;

    const float x1 = 1.1e2;
    const float x2 = 2.2e2;
    const float x3 = 9e2;
    const float x4 = 3e2;
    const float y1 = 4e5;
    const float y2 = 5e4;
    const float y3 = 1.3e4;
    const float y4 = 2.3e5;
    const float logx1 = TMath::Log10(x1);
    const float logx2 = TMath::Log10(x2);
    const float logx3 = TMath::Log10(x3);
    const float logx4 = TMath::Log10(x4);
    const float logy1 = TMath::Log10(y1);
    const float logy2 = TMath::Log10(y2);
    const float logy3 = TMath::Log10(y3);
    const float logy4 = TMath::Log10(y4);
    const float xx = e.tpc.maxS1area;
    const float yy = e.tpc.maxS2area;

    const float mt = (logy2-logy1)/(logx2-logx1);
    const float bt = logy1-mt*logx1;
    bool line_top =  TMath::Log10(yy) > mt*TMath::Log10(xx)+bt;

    const float ml = (logy2-logy3)/(logx2-logx3);
    const float bl = logy3-ml*logx3;
    bool line_left =  TMath::Log10(yy) > ml*TMath::Log10(xx)+bl;

    const float mb = (logy3-logy4)/(logx3-logx4);
    const float bb = logy4-mb*logx4;
    bool line_bot =  TMath::Log10(yy) < mb*TMath::Log10(xx)+bb;

    const float mr = (logy1-logy4)/(logx1-logx4);
    const float br = logy4-mr*logx4;
    bool line_right =  TMath::Log10(yy) < mr*TMath::Log10(xx)+br;

    return line_top && line_left && line_bot && line_right;
}

bool CXXe131 (MyEvent const& e){
    if (e.tpc.maxS1pulseID <0 || e.tpc.maxS2pulseID < 0) return false;

    const float x1 = 9.5e2;
    const float x2 = 4e2;
    const float x3 = 8e2;
    const float x4 = 3e3;
    const float y1 = 1.1e6;
    const float y2 = 1.3e6;
    const float y3 = 3.5e5;
    const float y4 = 1e5;
    const float logx1 = TMath::Log10(x1);
    const float logx2 = TMath::Log10(x2);
    const float logx3 = TMath::Log10(x3);
    const float logx4 = TMath::Log10(x4);
    const float logy1 = TMath::Log10(y1);
    const float logy2 = TMath::Log10(y2);
    const float logy3 = TMath::Log10(y3);
    const float logy4 = TMath::Log10(y4);
    const float xx = e.tpc.maxS1area;
    const float yy = e.tpc.maxS2area;

    const float mt = (logy2-logy1)/(logx2-logx1);
    const float bt = logy1-mt*logx1;
    bool line_top =  TMath::Log10(yy) < mt*TMath::Log10(xx)+bt;

    const float ml = (logy2-logy3)/(logx2-logx3);
    const float bl = logy3-ml*logx3;
    bool line_left =  TMath::Log10(yy) > ml*TMath::Log10(xx)+bl;

    const float mb = (logy3-logy4)/(logx3-logx4);
    const float bb = logy4-mb*logx4;
    bool line_bot =  TMath::Log10(yy) > mb*TMath::Log10(xx)+bb;

    const float mr = (logy1-logy4)/(logx1-logx4);
    const float br = logy4-mr*logx4;
    bool line_right =  TMath::Log10(yy) < mr*TMath::Log10(xx)+br;

    return line_top && line_left && line_bot && line_right;
    }

    bool CXSSsubS2H2W(MyEvent const& e, int n) {
    //cout << n << " " << e.tpc.subS2pulses[n].second << " " << e.tpc.subS2pulses.size() << endl;
    if (e.tpc.maxS1pulseID<0 || e.tpc.maxS2pulseID<0) return false; // If there is no S1 or S2, it is not any kind of scatter
    if (e.tpc.maxS2pulseID > -1 && e.tpc.subS2pulses[n].second<0) return true; // If there is a first S2, but no second S2, it must be a single scatter
    if (e.tpc.subS2pulses[n].second<0) return false;
    const float x1 = 1e-1;
    const float x2 = 3e-2;
    const float y1 = 5e-4;
    const float y2 = 4e-2;
    const float logx1 = TMath::Log10(x1);
    const float logx2 = TMath::Log10(x2);
    const float logy1 = TMath::Log10(y1);
    const float logy2 = TMath::Log10(y2);
    const float m = (logy2-logy1)/(logx2-logx1);
    const float b = logy1-m*logx1;
    const float xx = e.tpc.subS2pulses[n].first/e.tpc.maxS2area;
    const float yy = e.tpc.height2length[e.tpc.subS2pulses[n].second];
    return TMath::Log10(yy) < m*TMath::Log10(xx)+b;
}
bool CXMSsubS2H2W(MyEvent const& e, int n) {
    if (e.tpc.maxS1pulseID<0 || e.tpc.maxS2pulseID<0) return false;
    if (e.tpc.subS2pulses[n].second<0) return false;
    return !CXSSsubS2H2W(e,n);
}


//________________________________________________________
Bool_t ODAnalysis::Process(Long64_t entry)
{

    //if (entry < 50000) return kTRUE;

    GetEntry(entry);
    if (entry%100000==0) cout << "Processing "<<entry<<endl;
    //cout << entry << endl;

    //----------------------------------
    // Build derived RQs from input RQs
    deriveDetRQs(e, e.ODHG, e.OD);
    //cout << "Finished deriving det RQs" << endl;
    deriveMctRQs(e);
    //cout << "Finished deriving mct RQs" << endl;

    //----------------------------------
    // Define cut booleans
    /*const bool cxTPC = CXTPC(e);
    const bool cxnS1only = CXnS1only(e);
    const bool cxPPT = CXPPT(e);
    const bool cxMC4MeV = CXMC4MeV(e);
    const bool cxOtherS2notBiggest = CXOtherS2notBiggest(e);
    const bool cxHE = CXHE(e);
    const bool cxLE = CXLE(e);
    const bool cxS1first = CXS1first(e);
    const bool qual = cxPPT && cxTPC && cxnS1only && cxS1first && cxOtherS2notBiggest && cxMC4MeV;
    const bool cxSSsubS2H2W = CXSSsubS2H2W(e,0);
    const bool cxMSsubS2H2W = CXMSsubS2H2W(e,0);
    const bool cxSS =  qual && cxSSsubS2H2W;
    const bool cxMS = qual && cxMSsubS2H2W;
    const bool cxKr83 = CXKr83(e);
    const bool cxXe131 = CXXe131(e);
    //cout << "Finished cuts" << endl;

    if (cxSS) buildSS(e);
    //cout << "Built SS" << endl;
    if (cxMS) buildMS(e);
    //cout << "Built MS" << endl;
    bool cxFiducial = false;
    if (cxSS) cxFiducial = CXFiducial(e);
    */
    //PPT cut
    const bool cxPPT = CXPPT(e);
    float pulse15u = 0;
    if (cxPPT){
        h_pulseArea_phd_ODHG_int_1us->Fill(e.OD.PulseArea1us);
        h_pulseArea_phd_ODHG_int_2us->Fill(e.OD.PulseArea2us);
        h_pulseArea_phd_ODHG_int_3us->Fill(e.OD.PulseArea3us);
        h_pulseArea_phd_ODHG_int_30us->Fill(e.OD.PulseArea30us);
        h_pulseArea_phd_ODHG_int_130us->Fill(e.OD.PulseArea130us);
        h_pulseArea_phd_ODHG_int_230us->Fill(e.OD.PulseArea230us);
        h_pulseArea_phd_ODHG_int_330us->Fill(e.OD.PulseArea330us);
        h_pulseArea_phd_ODHG_int_500us->Fill(e.OD.PulseArea500us);
        h_pulseArea_phd_ODHG_int_1000us->Fill(e.OD.PulseArea1000us);
        h_pulseArea_phd_ODHG_int_1500us->Fill(e.OD.PulseArea1500us);
        h_pulseArea_phd_ODHG_int_2000us->Fill(e.OD.PulseArea2000us);
        h_pulseArea_phd_ODHG_int_2500us->Fill(e.OD.PulseArea2500us);
        h_pulseArea_phd_ODHG_int_3000us->Fill(e.OD.PulseArea3000us);
        h_pulseArea_phd_ODHG_int_3700us->Fill(e.OD.PulseArea3700us);

    }//if statement





    return kTRUE;
}

//________________________________________________________
void ODAnalysis::SlaveTerminate()
{
}

//________________________________________________________
void ODAnalysis::Terminate()
{

    TFile* outfile = TFile::Open(fOutFileName,"recreate");

    h_pulseArea_phd_ODHG_int_1us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_1us"));
    h_pulseArea_phd_ODHG_int_1us->Write();

    h_pulseArea_phd_ODHG_int_2us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_2us"));
    h_pulseArea_phd_ODHG_int_2us->Write();

    h_pulseArea_phd_ODHG_int_3us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_3us"));
    h_pulseArea_phd_ODHG_int_3us->Write();

    h_pulseArea_phd_ODHG_int_30us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_30us"));
    h_pulseArea_phd_ODHG_int_30us->Write();

    h_pulseArea_phd_ODHG_int_130us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_130us"));
    h_pulseArea_phd_ODHG_int_130us->Write();

    h_pulseArea_phd_ODHG_int_230us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_230us"));
    h_pulseArea_phd_ODHG_int_230us->Write();

    h_pulseArea_phd_ODHG_int_330us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_330us"));
    h_pulseArea_phd_ODHG_int_330us->Write();

    h_pulseArea_phd_ODHG_int_500us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_500us"));
    h_pulseArea_phd_ODHG_int_500us->Write();

    h_pulseArea_phd_ODHG_int_1000us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_1000us"));
    h_pulseArea_phd_ODHG_int_1000us->Write();

    h_pulseArea_phd_ODHG_int_1500us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_1500us"));
    h_pulseArea_phd_ODHG_int_1500us->Write();

    h_pulseArea_phd_ODHG_int_2000us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_2000us"));
    h_pulseArea_phd_ODHG_int_2000us->Write();

    h_pulseArea_phd_ODHG_int_2500us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_2500us"));
    h_pulseArea_phd_ODHG_int_2500us->Write();

    h_pulseArea_phd_ODHG_int_3000us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_3000us"));
    h_pulseArea_phd_ODHG_int_3000us->Write();

    h_pulseArea_phd_ODHG_int_3700us = dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_3700us"));
    h_pulseArea_phd_ODHG_int_3700us->Write();




    //(dynamic_cast<TH1F*>(fOutput->FindObject("pulseArea_phd_ODHG_int_1us")))->Write();

    outfile->Close();
}

//____________________________________
// Make a decision on whether to use HG or LG based on whether or not the pulse is saturated
pair <MyDetectorPulses, int> det(MyEvent & e, int p) {
    int chsSat = accumulate(e.tpcHG.chSaturated[p].begin(),e.tpcHG.chSaturated[p].end(), 0);
    //cout << "chsSat: " << chsSat << endl;
    if (chsSat == 0) return make_pair(e.tpcHG,p);
    //cout << "Not crazy saturated" << endl;
    if (p > 0) {
    if (chsSat == 1 & e.tpc.pulseClass[p-1]==PulseClass::S2 & e.tpcHG.saturated[p-1]) return make_pair(e.tpcHG,p);
    }
    //cout << "Not sorta saturated - use lg then" << endl;
    //cout << "p " << p << " LG " << e.tpcHG.HGLGpulseID[p] << endl;
    if (e.tpcHG.HGLGpulseID[p] == -1) return make_pair(e.tpcHG,p);
    return make_pair(e.tpcLG,e.tpcHG.HGLGpulseID[p]);
}

//________________________________________________________
// Build derived RQs for detector
void deriveDetRQs(MyEvent & e, MyDetectorPulses & defdet, MyDetectorPulses & newdet) {


    newdet.PulseArea1us = 0;
    newdet.PulseArea2us = 0;
    newdet.PulseArea3us = 0;
    newdet.PulseArea30us = 0;
    newdet.PulseArea130us = 0;
    newdet.PulseArea230us = 0;
    newdet.PulseArea330us = 0;
    newdet.PulseArea500us = 0;
    newdet.PulseArea1000us = 0;
    newdet.PulseArea1500us = 0;
    newdet.PulseArea2000us = 0;
    newdet.PulseArea2500us = 0;
    newdet.PulseArea3000us = 0;
    newdet.PulseArea3700us = 0;
    //cout << "Resized again" << endl;
    for (int p=0; p<defdet.nPulses; ++p) {

        if (e.ODHG.pulseStartTime[p]<1500)newdet.PulseArea1us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<2000)newdet.PulseArea2us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<3000)newdet.PulseArea3us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<30000)newdet.PulseArea30us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<130000)newdet.PulseArea130us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<230000)newdet.PulseArea230us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<330000)newdet.PulseArea330us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<500000)newdet.PulseArea500us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<1000000)newdet.PulseArea1000us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<1500000)newdet.PulseArea1500us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<2000000)newdet.PulseArea2000us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<2500000)newdet.PulseArea2500us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<3000000)newdet.PulseArea3000us+=e.ODHG.pulseArea[p];
        if (e.ODHG.pulseStartTime[p]<3700000)newdet.PulseArea3700us+=e.ODHG.pulseArea[p];

    }
}
//______________________________________


//________________________________________________________
// Build derived RQs for MCT
void deriveMctRQs(MyEvent & e) {
    e.mcPulseLength.resize(e.mcPulseFirstPheTime_ns.size());
    for (size_t p=0; p<e.mcPulseFirstPheTime_ns.size(); ++p) {
    e.mcPulseLength[p] = e.mcPulseLastPheTime_ns[p] - e.mcPulseFirstPheTime_ns[p];
    }
}

//________________________________________________________
// Build single scatters and corrections
// Assumes maxS1pulseID and maxS2pulseID are the S1 and S2
float correctS1(float pulseAreaTop, float pulseAreaBot, float driftTime) {
    double toppars[6]={1.35352e+00,2.53625e-06,-1.99506e-11,4.52959e-17,-4.72829e-23,1.85961e-29};
    double botpars[6]={4.88547e-01,1.48639e-06,-2.74680e-12,7.58603e-18,-8.49328e-24,3.71999e-30};
    const float s1top = pulseAreaTop;
    const float s1bot = pulseAreaBot;
    double s1topCorrFactor = 0;
    double s1botCorrFactor = 0;
    for(int i=0; i<6; i++) {
        s1topCorrFactor+=toppars[i]*TMath::Power(driftTime,i);
        s1botCorrFactor+=botpars[i]*TMath::Power(driftTime,i);
    }
    return s1top/s1topCorrFactor + s1bot/s1botCorrFactor;
}

float correctS2(time_t trgTime_s, float s2area, float driftTime) {

    float lifetimes[32] = {860., 870., 880.,  890., 905., 905., 920., 915., 930., 925.,
                         945., 940., 950., 1000.,1000.,1000.,1000.,1000.,1000.,1000.,
                         1000.,1000.,1000.,1000.,1000.,1000.,1000.,1000.,1000.,1000.,1000.,1000.}; //[us]

    time_t stamp = trgTime_s;
    tm* timePtr = gmtime(&stamp);
    int day = timePtr->tm_mday;
    int month = timePtr->tm_mon;

    int lifetime = 1000.;
    if (month==3)
    lifetime = lifetimes[day-1];
    return s2area*TMath::Exp(driftTime/1000./lifetime);
}

float correctRpos(float rPos, float driftTime) {

    double r2pars[6]={5671.1,-0.0175672,7.86025e-08,-1.77335e-13,1.9308e-19,-8.16797e-26};
    double r2_0 =0;
    for(int i=0; i<6; i++)
    r2_0+=r2pars[i]*TMath::Power(driftTime,i);

    double rPosCorrFactor = rPos*rPos/r2_0;
    return TMath::Sqrt(kTPCradius*kTPCradius*rPosCorrFactor);
}

void buildSS(MyEvent & e) {
    e.ss.s1pulseID = e.tpc.maxS1pulseID;
    e.ss.s2pulseID = e.tpc.maxS2pulseID;
    pair < MyDetectorPulses, int > detS1 = det(e,e.ss.s1pulseID);
    pair < MyDetectorPulses, int > detS2 = det(e,e.ss.s2pulseID);
    e.ss.s1area = detS1.first.pulseArea[detS1.second];
    e.ss.s2area = detS2.first.pulseArea[detS2.second];
    e.ss.driftTime = ((detS2.first.pulseStartTime[detS2.second] + detS2.first.aft5[detS2.second]) -
                    (detS1.first.pulseStartTime[detS1.second] + detS1.first.aft5[detS1.second]));
    e.ss.corrS1area = correctS1(detS1.first.pulseAreaTop[detS1.second], detS1.first.pulseAreaBot[detS1.second], e.ss.driftTime);
    e.ss.corrS2area = correctS2(e.trgTime_s, e.ss.s2area, e.ss.driftTime);
    e.ss.xPos = detS2.first.xPos[detS2.second];
    e.ss.yPos = detS2.first.yPos[detS2.second];
    e.ss.zPos = kTPCheight*(1.-e.ss.driftTime/1e3/880.);
    e.ss.rPos = TMath::Sqrt(e.ss.xPos*e.ss.xPos + e.ss.yPos*e.ss.yPos);
    e.ss.corrRpos = correctRpos(e.ss.rPos, e.ss.driftTime);
}

void buildMS(MyEvent & e) {
    //cout << "Building MS" << endl;
    e.ms.s1pulseID = e.tpc.maxS1pulseID;
    pair < MyDetectorPulses, int > detS1 = det(e,e.ms.s1pulseID);
    e.ms.s1area = detS1.first.pulseArea[detS1.second];

    //cout << "S1: " << e.ms.s1pulseID << " " << e.ms.s1area << endl;

    e.ms.s2pulseIDs.clear();
    e.ms.s2areas.clear();
    e.ms.driftTimes.clear();
    e.ms.corrS2areas.clear();
    e.ms.xPos.clear();
    e.ms.yPos.clear();
    e.ms.zPos.clear();
    e.ms.rPos.clear();
    e.ms.corrRpos.clear();

    e.ms.s2pulseIDs.push_back(e.tpc.maxS2pulseID);
    e.ms.s2areas.push_back(e.tpc.maxS2area);

    //cout << "S2: " << e.ms.s2pulseIDs[0] << " " << e.ms.s2areas[0] << endl;

    for (size_t p=0; p<e.tpc.subS2pulses.size(); ++p) {
    //cout << "In for loop" << endl;
    if (CXMSsubS2H2W(e,p)) {
      //cout << "In if" << endl;
      e.ms.s2pulseIDs.push_back(e.tpc.subS2pulses[p].second);
      //cout << "Pushed pulse ID" << endl;
      e.ms.s2areas.push_back(e.tpc.subS2pulses[p].first);
      //cout << "S2: " << e.tpc.subS2pulses[p].second << " " << e.tpc.subS2pulses[p].first << endl;
    }
    }

    //cout << "Did sub S2s" << endl;

    e.ms.wDriftTime = 0;
    float totS2area = 0;
    for (size_t p=0; p<e.ms.s2areas.size(); ++p) {
    pair < MyDetectorPulses, int > detS2 = det(e,e.ms.s2pulseIDs[p]);
    e.ms.driftTimes.push_back((detS2.first.pulseStartTime[detS2.second] + detS2.first.aft5[detS2.second]) -
    		       (detS1.first.pulseStartTime[detS1.second] + detS1.first.aft5[detS1.second]));
    e.ms.wDriftTime += e.ms.driftTimes[p] * e.ms.s2areas[p];
    totS2area += e.ms.s2areas[p];
    e.ms.corrS2areas.push_back(correctS2(e.trgTime_s, e.ms.s2areas[p], e.ms.driftTimes[p]));
    e.ms.xPos.push_back(detS2.first.xPos[detS2.second]);
    e.ms.yPos.push_back(detS2.first.yPos[detS2.second]);
    e.ms.zPos.push_back(kTPCheight*(1.-e.ms.driftTimes[p]/1e3/880.));
    e.ms.rPos.push_back(TMath::Sqrt(e.ms.xPos[p]*e.ms.xPos[p] + e.ms.yPos[p]*e.ms.yPos[p]));
    e.ms.corrRpos.push_back(correctRpos(e.ms.rPos[p], e.ms.driftTimes[p]));
    }
    e.ms.wDriftTime = e.ms.wDriftTime / totS2area;

    //cout << "Did drift time, corrections, and positions" << endl;

    e.ms.corrS1area = correctS1(detS1.first.pulseAreaTop[detS1.second], detS1.first.pulseAreaBot[detS1.second], e.ms.wDriftTime);

}

//________________________________________________________
bool sortinrev(const pair<float,int> &a,
               const pair<float,int> &b)
{
       return (a.first > b.first);
}

bool comp_pair(const pair<float,int> &a,
               const pair<float,int> &b)
{
       return (a.first < b.first);
}
/*void ODPosition(){
    int column;
    std::ifstream data("ODPMT_position.txt");
    if (!data.is_open())
    {
        std::exit(EXIT_FAILURE);
    }
    else {
        cout<<" File opened successfully !"<<endl;
    }
    string str;
    //getline(data,str);
    while (getline(data,str)){
        istringstream iss(str);
        string token;
        column =0;
        //cout<<" output is : "<<str<<endl;
        //getchar();
        while (std::getline(iss, token, ','))
        {

            // process each token
            if (column == 0){
                double index = atoi(token.c_str());//c_str is needed to convert string to const char* previously (the function requires it)
                cout<<" PMT index : "<<index<<endl;
            }
            else if (column == 1){
                double Xp = atof(token.c_str());//c_str is needed to convert string to const char* previously (the function requires it)
                cout<<" PMT index : "<<Xp<<endl;
                ODPMTX.push_back(Xp);
            }
            else if (column == 2){
                double Yp = atof(token.c_str());//c_str is needed to convert string to const char* previously (the function requires it)
                cout<<" PMT index : "<<Yp<<endl;
                ODPMTY.push_back(Yp);
            }
            else if (column == 3){
                double Zp = atof(token.c_str());//c_str is needed to convert string to const char* previously (the function requires it)
                cout<<" PMT index : "<<Zp<<endl;
                ODPMTZ.push_back(Zp);
            }
            // accumulate columns
            column++;
            //cout << token << " ";
        }
        //cout<<" How many columns in this file : "<<column<<endl;
        //cout << endl;
    }
}*/
/*TVector3 CentroidFit(vector <double> &v){
    double totalQ = 0;
    TVector3 centroid(0.0,0.0,0.0);
    for (int i=0;i<120;i++){
        int pmtidx = i+800;
        TVector3 pmtv(ODPMTX[i],ODPMTY[i],ODPMTZ[i]);
        double Qpow = 0.0;
        //cout<<" for PMT : "<<pmtidx<<" QPE : "<<v[i]<<endl;
        Qpow = pow(v[i], 2);
        if (isfinite(Qpow) == 0){
            continue;
        }
        totalQ += Qpow;
        centroid += Qpow*pmtv;
    }
    //cout<<" Total Q is : "<<totalQ<<endl;
    centroid *= 1.0/totalQ;
    return centroid;

}*/
TH2D* Create2DHist(string h2name,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max,double Ybins, double Ybin_min, double Ybin_max){
    TH2D* h = new TH2D(h2name.c_str(),("#font[132]{" + h2name + "}").c_str(),Xbins,Xbin_min,Xbin_max,Ybins,Ybin_min,Ybin_max);
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    return h;

}
TH1F* Create1DHist(string h1name,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max){
    TH1F* h = new TH1F(h1name.c_str(),("#font[132]{" + h1name + "}").c_str(),Xbins,Xbin_min,Xbin_max);
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    //h->SetMarkerColor(color);
    //h->SetLineColor(color);
    return h;

}
TH1F* CreateSumw2Hist(string hname,string Xname,string Yname, double Xbins, double Xbin_min, double Xbin_max){
    TH1F* h = new TH1F(hname.c_str(),("#font[132]{" + hname + "}").c_str(),Xbins,Xbin_min,Xbin_max);
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    //h->SetMarkerColor(color);
    //h->SetLineColor(color);
    h->Sumw2();
    return h;

}
