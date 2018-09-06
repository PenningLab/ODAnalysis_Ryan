//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Aug  4 18:04:23 2018 by ROOT version 6.08/00
// from TChain Events/Events
//////////////////////////////////////////////////////////

#ifndef ODAnalysis_h
#define ODAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile2D.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"

#include <vector>

#include "MyEvent.h"

/*
  #ifdef __CINT__
  #pragma link C++ class MyEvent+;
  #pragma link C++ class MyDetectorPulses+;
  #pragma link C++ class MySingleScatter+;
  #pragma link C++ class MySingleScatters+;
  #endif
*/


class ODAnalysis : public TSelector {
 public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    TString fOutFileName;

    unsigned int eventID;
    std::vector<int>  pulseArea;

    MyEvent e;

    TH1F* h_pulseArea_phd_ODHG_int_1us=0;
    TH1F* h_pulseArea_phd_ODHG_int_2us=0;
    TH1F* h_pulseArea_phd_ODHG_int_3us=0;
    TH1F* h_pulseArea_phd_ODHG_int_30us=0;
    TH1F* h_pulseArea_phd_ODHG_int_130us=0;
    TH1F* h_pulseArea_phd_ODHG_int_230us=0;
    TH1F* h_pulseArea_phd_ODHG_int_330us=0;
    TH1F* h_pulseArea_phd_ODHG_int_500us=0;

    TH1F* h_pulseArea_phd_ODHG_int_1000us=0;
    TH1F* h_pulseArea_phd_ODHG_int_1500us=0;
    TH1F* h_pulseArea_phd_ODHG_int_2000us=0;
    TH1F* h_pulseArea_phd_ODHG_int_2500us=0;
    TH1F* h_pulseArea_phd_ODHG_int_3000us=0;
    TH1F* h_pulseArea_phd_ODHG_int_3700us=0;

    float pulse15u;

    //ODAnalysis(TTree * /*tree*/ =0);
    virtual ~ODAnalysis() { }
    virtual Int_t   Version() const { return 2; }
    virtual void    Begin(TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
    virtual void    Init(TTree *tree);
    virtual Bool_t  Notify();
    virtual Bool_t  Process(Long64_t entry);
    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
    virtual void    SetOption(const char *option) { fOption = option; }
    virtual void    SetObject(TObject *obj) { fObject = obj; }
    virtual void    SetInputList(TList *input) { fInput = input; }
    virtual TList  *GetOutputList() const { return fOutput; }
    virtual void    SlaveTerminate();
    virtual void    Terminate();

    // Custom load methods
    void LoadEventBranches();
    void LoadDetectorPulsesBranches(TString detectorName, MyDetectorPulses & det);
    void LoadMCTruthBranches();
    void SetOutputName(TString fileName) { fOutFileName = fileName; }

    ClassDef(ODAnalysis,0);
};

#endif

#ifdef ODAnalysis_cxx


//________________________________________________________
void ODAnalysis::Init(TTree *tree)
{
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).

    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fChain->SetMakeClass(1);
    fChain->GetFriend("RQMCTruth")->SetMakeClass(1);
    fChain->SetBranchStatus("*",0);

    LoadEventBranches();
    LoadDetectorPulsesBranches("ODHG", e.ODHG);
    LoadDetectorPulsesBranches("ODLG", e.ODLG);
    LoadMCTruthBranches();
}

//________________________________________________________
Bool_t ODAnalysis::Notify()
{
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.

    return kTRUE;
}

//________________________________________________________
void ODAnalysis::LoadEventBranches()
{
    fChain->SetBranchStatus( "eventHeader.eventID", 1);
    fChain->SetBranchAddress("eventHeader.eventID", &e.eventID);
    fChain->SetBranchStatus( "eventHeader.triggerTimeStamp_s", 1);
    fChain->SetBranchAddress("eventHeader.triggerTimeStamp_s", &e.trgTime_s);
    fChain->SetBranchStatus( "eventHeader.triggerTimeStamp_ns", 1);
    fChain->SetBranchAddress("eventHeader.triggerTimeStamp_ns", &e.trgTime_ns);
    fChain->SetBranchStatus( "eventHeader.rawFileName", 1);
    fChain->SetBranchAddress("eventHeader.rawFileName", &e.rawFileName);
}

//________________________________________________________
void ODAnalysis::LoadDetectorPulsesBranches(TString detectorName, MyDetectorPulses & det)
{
    TString detString = detectorName;
    fChain->SetBranchStatus( "pulses"+detString+".nPulses", 1);
    fChain->SetBranchAddress("pulses"+detString+".nPulses", &det.nPulses);
    fChain->SetBranchStatus( "pulses"+detString+".pulseID", 1);
    fChain->SetBranchAddress("pulses"+detString+".pulseID", &det.pulseID);
    fChain->SetBranchStatus( "pulses"+detString+".pulseStartTime_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".pulseStartTime_ns", &det.pulseStartTime);
    fChain->SetBranchStatus( "pulses"+detString+".pulseEndTime_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".pulseEndTime_ns", &det.pulseEndTime);
    fChain->SetBranchStatus( "pulses"+detString+".pulseArea_phd", 1);
    fChain->SetBranchAddress("pulses"+detString+".pulseArea_phd", &det.pulseArea);
    fChain->SetBranchStatus( "pulses"+detString+".topArea_phd", 1);
    fChain->SetBranchAddress("pulses"+detString+".topArea_phd", &det.pulseAreaTop);
    fChain->SetBranchStatus( "pulses"+detString+".bottomArea_phd", 1);
    fChain->SetBranchAddress("pulses"+detString+".bottomArea_phd", &det.pulseAreaBot);
    fChain->SetBranchStatus( "pulses"+detString+".peakAmp", 1);
    fChain->SetBranchAddress("pulses"+detString+".peakAmp", &det.peakAmp);
    fChain->SetBranchStatus( "pulses"+detString+".peakTime_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".peakTime_ns", &det.peakTime);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime1_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime1_ns", &det.aft1);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime5_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime5_ns", &det.aft5);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime25_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime25_ns", &det.aft25);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime50_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime50_ns", &det.aft50);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime75_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime75_ns", &det.aft75);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime95_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime95_ns", &det.aft95);
    fChain->SetBranchStatus( "pulses"+detString+".areaFractionTime99_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".areaFractionTime99_ns", &det.aft99);
    fChain->SetBranchStatus( "pulses"+detString+".topBottomAsymmetry", 1);
    fChain->SetBranchAddress("pulses"+detString+".topBottomAsymmetry", &det.tba);
    fChain->SetBranchStatus( "pulses"+detString+".promptFraction50ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".promptFraction50ns", &det.promptFrac50ns);
    fChain->SetBranchStatus( "pulses"+detString+".pulseArea200ns_phd", 1);
    fChain->SetBranchAddress("pulses"+detString+".pulseArea200ns_phd", &det.pulseArea200ns);
    fChain->SetBranchStatus( "pulses"+detString+".rmsWidth_ns", 1);
    fChain->SetBranchAddress("pulses"+detString+".rmsWidth_ns", &det.rmsWidth);
    fChain->SetBranchStatus( "pulses"+detString+".coincidence", 1);
    fChain->SetBranchAddress("pulses"+detString+".coincidence", &det.coincidence);
    fChain->SetBranchStatus( "pulses"+detString+".s1Probability", 1);
    fChain->SetBranchAddress("pulses"+detString+".s1Probability", &det.s1prob);
    fChain->SetBranchStatus( "pulses"+detString+".s2Probability", 1);
    fChain->SetBranchAddress("pulses"+detString+".s2Probability", &det.s2prob);
    fChain->SetBranchStatus( "pulses"+detString+".singlePEprobability", 1);
    fChain->SetBranchAddress("pulses"+detString+".singlePEprobability", &det.speProb);
    fChain->SetBranchStatus( "pulses"+detString+".multiplePEprobability", 1);
    fChain->SetBranchAddress("pulses"+detString+".multiplePEprobability", &det.mpeProb);
    fChain->SetBranchStatus( "pulses"+detString+".singleElectronProbability", 1);
    fChain->SetBranchAddress("pulses"+detString+".singleElectronProbability", &det.seProb);
    fChain->SetBranchStatus( "pulses"+detString+".otherProbability", 1);
    fChain->SetBranchAddress("pulses"+detString+".otherProbability", &det.otherProb);
    fChain->SetBranchStatus( "pulses"+detString+".otherS2Probability", 1);
    fChain->SetBranchAddress("pulses"+detString+".otherS2Probability", &det.otherS2prob);
    fChain->SetBranchStatus( "pulses"+detString+".saturated", 1);
    fChain->SetBranchAddress("pulses"+detString+".saturated", &det.saturated);
    fChain->SetBranchStatus( "pulses"+detString+".s2Xposition_cm", 1);
    fChain->SetBranchAddress("pulses"+detString+".s2Xposition_cm", &det.xPos);
    fChain->SetBranchStatus( "pulses"+detString+".s2Yposition_cm", 1);
    fChain->SetBranchAddress("pulses"+detString+".s2Yposition_cm", &det.yPos);
    fChain->SetBranchStatus( "pulses"+detString+".HGLGpulseID", 1);
    fChain->SetBranchAddress("pulses"+detString+".HGLGpulseID", &det.HGLGpulseID);
    fChain->SetBranchStatus( "pulses"+detString+".chSaturated", 1);
    fChain->SetBranchAddress("pulses"+detString+".chSaturated", &det.chSaturated);

}

//________________________________________________________
void ODAnalysis::LoadMCTruthBranches()
{
    fChain->SetBranchStatus( "mcTruthEvent.parentParticle",1);
    fChain->SetBranchAddress("mcTruthEvent.parentParticle", &e.parentParticle);

    fChain->SetBranchStatus( "mcTruthPulses.firstPheTime_ns", 1);
    fChain->SetBranchAddress("mcTruthPulses.firstPheTime_ns", &e.mcPulseFirstPheTime_ns);

    fChain->SetBranchStatus( "mcTruthPulses.lastPheTime_ns", 1);
    fChain->SetBranchAddress("mcTruthPulses.lastPheTime_ns", &e.mcPulseLastPheTime_ns);

    fChain->SetBranchStatus( "mcTruthPulses.pheCount", 1);
    fChain->SetBranchAddress("mcTruthPulses.pheCount", &e.mcPulsePheCount);

    fChain->SetBranchStatus( "mcTruthVertices.volumeName", 1);
    fChain->SetBranchAddress("mcTruthVertices.volumeName", &e.mcVtxVolumeName);

    fChain->SetBranchStatus( "mcTruthVertices.energyDep_keV", 1);
    fChain->SetBranchAddress("mcTruthVertices.energyDep_keV", &e.mcVtxEnergyDep);

    fChain->SetBranchStatus( "mcTruthVertices.rawS2Photons", 1);
    fChain->SetBranchAddress("mcTruthVertices.rawS2Photons", &e.mcVtxRawS2photons);

    fChain->SetBranchStatus( "mcTruthVertices.artifactPulseIndices", 1);
    fChain->SetBranchAddress("mcTruthVertices.artifactPulseIndices", &e.mcArtifactPulseIndices);
}


#endif // #ifdef ODAnalysis_cxx
