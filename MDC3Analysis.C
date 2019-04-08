#define MDC3Analysis_cxx
// The class definition in MDC3Analysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("MDC3Analysis.C")
// root> T->Process("MDC3Analysis.C","some options")
// root> T->Process("MDC3Analysis.C+")
//

#include "MDC3Analysis.h"
#include <TH2.h>
#include <TStyle.h>

using namespace std;

std::shared_ptr<TH1F> CreateSumw2Hist(
    string hname, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max);
std::shared_ptr<TH1F> Create1DHist(
    string h1name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max);
std::shared_ptr<TH2D> Create2DHist(string h2name, string Xname, string Yname, double Xbins,
    double Xbin_min, double Xbin_max, double Ybins, double Ybin_min, double Ybin_max);

void MDC3Analysis::Begin(TTree* /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
}

void MDC3Analysis::SlaveBegin(TTree* /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();

    for (int i = 0; i < histnames.size(); i++)
    {
        h_timing[i] = CreateSumw2Hist("h_" + histnames[i], histnames[i] + "(ns)", "", 250, 0, 2000);
        h_timingVarea[i] = Create2DHist("h_" + histnames[i] + "Varea", histnames[i] + "(ns)",
            "Area (phd)", 250, 0, 2000, 500, 0, 6000);
        h_timingVcoincidence[i] = Create2DHist("h_" + histnames[i] + "Vcoincidence",
            histnames[i] + "(ns)", "Coincidence", 250, 0, 2000, 121, 0, 121);
        h_timingVphdperpmt[i] = Create2DHist("h_" + histnames[i] + "Vphdperpmt",
            histnames[i] + "(ns)", "Area/Coincidence (phd/PMT)", 250, 0, 2000, 1000, 0, 6000);
        h_timingVpeakamp[i] = Create2DHist("h_" + histnames[i] + "Vpeakamp", histnames[i] + "(ns)",
            "Peak Amplitude (phd/ns)", 250, 0, 2000, 150, 0, 60);

        fOutput->Add(h_timing[i]);
        fOutput->Add(h_timingVarea[i]);
        fOutput->Add(h_timingVcoincidence[i]);
        fOutput->Add(h_timingVphdperpmt[i]);
        fOutput->Add(h_timingVpeakamp[i]);
    }
}

Bool_t MDC3Analysis::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // When processing keyed objects with PROOF, the object is already loaded
    // and is available via the fObject pointer.
    //
    // This function should contain the \"body\" of the analysis. It can contain
    // simple or elaborate selection criteria, run algorithms on the data
    // of the event and typically fill histograms.
    //
    // The processing can be stopped by calling Abort().
    //
    // Use fStatus to set the return value of TTree::Process().
    //
    // The return value is currently not used.

    fReader.SetEntry(entry);
    if (entry % 100000 == 0)
        cout << "Processing " << entry << endl;
    for (int i = 0; i < pulsesODHG_.nPulses; i++)
    {
        h_timing[0]->Fill(pulsesODHG_.areaFractionTime1_ns[i]);
        h_timing[1]->Fill(pulsesODHG_.areaFractionTime5_ns[i]);
        h_timing[2]->Fill(pulsesODHG_.areaFractionTime10_ns[i]);
        h_timing[3]->Fill(pulsesODHG_.areaFractionTime25ns[i]);
        h_timing[4]->Fill(pulsesODHG_.areaFractionTime50_ns[i]);
        h_timing[5]->Fill(pulsesODHG_.areaFractionTime75_ns[i]);
        h_timing[6]->Fill(pulsesODHG_.areaFractionTime90_ns[i]);
        h_timing[7]->Fill(pulsesODHG_.areaFractionTime95_ns[i]);
        h_timing[8]->Fill(pulsesODHG_.areaFractionTime99_ns[i]);
        h_timing[9]->Fill(pulsesODHG_.peakTime_ns[i]);
        h_timing[10]->Fill(pulsesODHG_.rmsWidth_ns[i]);

        h_timingVarea[0]->Fill(pulsesODHG_.areaFractionTime1_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[1]->Fill(pulsesODHG_.areaFractionTime5_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[2]->Fill(pulsesODHG_.areaFractionTime10_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[3]->Fill(pulsesODHG_.areaFractionTime25ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[4]->Fill(pulsesODHG_.areaFractionTime50_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[5]->Fill(pulsesODHG_.areaFractionTime75_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[6]->Fill(pulsesODHG_.areaFractionTime90_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[7]->Fill(pulsesODHG_.areaFractionTime95_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[8]->Fill(pulsesODHG_.areaFractionTime99_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[9]->Fill(pulsesODHG_.peakTime_ns[i], pulsesODHG_.pulseArea_phd[i]);
        h_timingVarea[10]->Fill(pulsesODHG_.rmsWidth_ns[i], pulsesODHG_.pulseArea_phd[i]);

        h_timingVcoincidence[0]->Fill(
            pulsesODHG_.areaFractionTime1_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[1]->Fill(
            pulsesODHG_.areaFractionTime5_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[2]->Fill(
            pulsesODHG_.areaFractionTime10_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[3]->Fill(
            pulsesODHG_.areaFractionTime25ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[4]->Fill(
            pulsesODHG_.areaFractionTime50_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[5]->Fill(
            pulsesODHG_.areaFractionTime75_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[6]->Fill(
            pulsesODHG_.areaFractionTime90_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[7]->Fill(
            pulsesODHG_.areaFractionTime95_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[8]->Fill(
            pulsesODHG_.areaFractionTime99_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[9]->Fill(pulsesODHG_.peakTime_ns[i], pulsesODHG_.coincidence[i]);
        h_timingVcoincidence[10]->Fill(pulsesODHG_.rmsWidth_ns[i], pulsesODHG_.coincidence[i]);

        h_timingvphdperpmt[0]->Fill(pulsesODHG_.areaFractionTime1_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[1]->Fill(pulsesODHG_.areaFractionTime5_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[2]->Fill(pulsesODHG_.areaFractionTime10_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[3]->Fill(pulsesODHG_.areaFractionTime25ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[4]->Fill(pulsesODHG_.areaFractionTime50_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[5]->Fill(pulsesODHG_.areaFractionTime75_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[6]->Fill(pulsesODHG_.areaFractionTime90_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[7]->Fill(pulsesODHG_.areaFractionTime95_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[8]->Fill(pulsesODHG_.areaFractionTime99_ns[i],
            pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[9]->Fill(
            pulsesODHG_.peakTime_ns[i], pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);
        h_timingvphdperpmt[10]->Fill(
            pulsesODHG_.rmsWidth_ns[i], pulsesODHG_.pulseArea_phd[i] / pulsesODHG_.coincidence[i]);

        h_timingVpeakamp[0]->Fill(pulsesODHG_.areaFractionTime1_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[1]->Fill(pulsesODHG_.areaFractionTime5_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[2]->Fill(pulsesODHG_.areaFractionTime10_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[3]->Fill(pulsesODHG_.areaFractionTime25ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[4]->Fill(pulsesODHG_.areaFractionTime50_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[5]->Fill(pulsesODHG_.areaFractionTime75_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[6]->Fill(pulsesODHG_.areaFractionTime90_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[7]->Fill(pulsesODHG_.areaFractionTime95_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[8]->Fill(pulsesODHG_.areaFractionTime99_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[9]->Fill(pulsesODHG_.peakTime_ns[i], pulsesODHG_.peakAmp[i]);
        h_timingVpeakamp[10]->Fill(pulsesODHG_.rmsWidth_ns[i], pulsesODHG_.peakAmp[i]);
    }
    return kTRUE;
}

void MDC3Analysis::SlaveTerminate()
{
    // The SlaveTerminate() function is called after all entries or objects
    // have been processed. When running with PROOF SlaveTerminate() is called
    // on each slave server.
}

void MDC3Analysis::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.

    // create output file and store all hists here plus plot on pdf here
    TFile* outfile = TFile::Open(fOutFileName, "recreate");
    for (int i = 0; i < histnames.size(); i++)
    {
        TString hname = TString("h_") + TString(histnames[i]);
        h_timing[i] = dynamic_pointer_cast<TH1F>(fOutput->FindObject(hname.Data()));
        h_timing[i]->Write();

        hname = TString("h_") + TString(histnames[i]) + TString("Varea");
        h_timingVarea[i] = dynamic_pointer_cast<TH1F>(fOutput->FindObject(hname.Data()));
        h_timingVarea[i]->Write();

        hname = TString("h_") + TString(histnames[i]) + TString("Vcoincidence");
        h_timingVcoincidence[i] = dynamic_pointer_cast<TH1F>(fOutput->FindObject(hname.Data()));
        h_timingVcoincidence[i]->Write();

        hname = TString("h_") + TString(histnames[i]) + TString("Vphdperpmt");
        h_timingVphdperpmt[i] = dynamic_pointer_cast<TH1F>(fOutput->FindObject(hname.Data()));
        h_timingVphdperpmt[i]->Write();

        hname = TString("h_") + TString(histnames[i]) + TString("Vpeakamp");
        h_timingVpeakamp[i] = dynamic_pointer_cast<TH1F>(fOutput->FindObject(hname.Data()));
        h_timingVpeakamp[i]->Write();
    }

    outfile->Close();
    delete outfile;
}

std::shared_ptr<TH2F> Create2DHist(string h2name, string Xname, string Yname, double Xbins,
    double Xbin_min, double Xbin_max, double Ybins, double Ybin_min, double Ybin_max)
{
    std::shared_ptr<TH2F> h(new TH2D(h2name.c_str(), ("#font[132]{" + h2name + "}").c_str(), Xbins,
        Xbin_min, Xbin_max, Ybins, Ybin_min, Ybin_max));
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    return h;
}
std::shared_ptr<TH1F> Create1DHist(
    string h1name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max)
{
    std::shared_ptr<TH1F> h(new TH1F(
        h1name.c_str(), ("#font[132]{" + h1name + "}").c_str(), Xbins, Xbin_min, Xbin_max));
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    // h->SetMarkerColor(color);
    // h->SetLineColor(color);
    return h;
}

std::shared_ptr<TH1F> CreateSumw2Hist(
    string hname, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max)
{
    std::shared_ptr<TH1F> h(
        new TH1F(hname.c_str(), ("#font[132]{" + hname + "}").c_str(), Xbins, Xbin_min, Xbin_max));
    h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
    h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
    h->GetXaxis()->SetLabelFont(132);
    h->GetYaxis()->SetLabelFont(132);
    // h->SetMarkerColor(color);
    // h->SetLineColor(color);
    h->Sumw2();
    return h;
}
