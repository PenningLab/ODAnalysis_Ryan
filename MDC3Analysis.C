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
//#include "PulseMapping.h"
#include <TFile.h>
#include <TH1F.h>
#include <TH2.h>
#include <TStyle.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

TH1F* CreateSumw2Hist(string hname, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max);
TH1F* Create1DHist(string h1name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max);
TH2F* Create2DHist(string h2name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max,
    double Ybins, double Ybin_min, double Ybin_max);

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

	h_area = CreateSumw2Hist("h_area", "Pulse Area (phd)", "", 1000, 0, maxarea);
	h_coincidence = CreateSumw2Hist("h_coincidence", "Pulse Coincidence", "", 121, 0, 121);
	h_peakamp = CreateSumw2Hist("h_peakamp", "Pulse Peak Amplitude (phd/ns)", "", 250, 0, maxamp);
	// h_phdperpulse = CreateSumw2Hist("h_phdperpulse", "Event Area/Pulse (phd)", "", 1000, 0, 400);
	h_phdCurrent = Create2DHist(
	    "h_phdCurrent", "Pulse Start Time (ns)", "Event Area (phd)", 5000, 0, maxstart, 1000, 0, maxarea);
	for (int i = 0; i < histnames.size(); i++)
	{
		h_timing[i] = CreateSumw2Hist("h_" + histnames[i], histnames[i] + histunits[i], "",
		    std::min(500.0, (histxlimsu[i] - histxlimsl[i]) / histprecision[i]), histxlimsl[i], histxlimsu[i]);
		h_timingVarea[i] = Create2DHist("h_" + histnames[i] + "Varea", histnames[i] + histunits[i], "Area (phd)",
		    std::min(500.0, (histxlimsu[i] - histxlimsl[i]) / histprecision[i]), histxlimsl[i], histxlimsu[i], 1000, 0,
		    maxarea);
		h_timingVcoincidence[i] = Create2DHist("h_" + histnames[i] + "Vcoincidence", histnames[i] + histunits[i],
		    "Coincidence", std::min(500.0, (histxlimsu[i] - histxlimsl[i]) / histprecision[i]), histxlimsl[i],
		    histxlimsu[i], 121, 0, 121);
		/*h_timingVphdperpmt[i] = Create2DHist("h_" + histnames[i] + "Vphdperpmt", histnames[i] + histunits[i],
		    "Area/Coincidence (phd/PMT)", std::min(500.0, (histxlimsu[i] - histxlimsl[i]) / histprecision[i]),
		    histxlimsl[i], histxlimsu[i], 1000, 0, 75);*/
		h_timingVpeakamp[i] = Create2DHist("h_" + histnames[i] + "Vpeakamp", histnames[i] + histunits[i],
		    "Peak Amplitude (phd/ns)", std::min(500.0, (histxlimsu[i] - histxlimsl[i]) / histprecision[i]),
		    histxlimsl[i], histxlimsu[i], 500, 0, maxamp);

		fOutput->Add(h_timing[i]);
		// cout << "Added " << h_timing[i]->GetName() << " to output list" << endl;
		fOutput->Add(h_timingVarea[i]);
		fOutput->Add(h_timingVcoincidence[i]);
		// fOutput->Add(h_timingVphdperpmt[i]);
		fOutput->Add(h_timingVpeakamp[i]);
	}
	fOutput->Add(h_area);
	fOutput->Add(h_coincidence);
	fOutput->Add(h_peakamp);
	// fOutput->Add(h_phdperpulse);
	fOutput->Add(h_phdCurrent);
	// fOutput->Add(eventareas);
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
	if (entry % 1000 == 0)
		cout << "Processing " << entry << endl;
	double eventareas = 0;
	for (int i = 0; i < pulsesODLG_->nPulses; i++)
	{
		eventareas += pulsesODLG_->pulseArea_phd[i];
	}
	if (eventareas > 1 && pulsesODLG_->maxCoincidence > 0)
	{
		h_phdperpulse->Fill(eventareas);
		for (int i = 0; i < pulsesODLG_->nPulses; i++)
		{
			double pasym = 2 * pulsesODLG_->areaFractionTime50_ns[i] - pulsesODLG_->areaFractionTime5_ns[i]
			    - pulsesODLG_->areaFractionTime95_ns[i];
			pasym *= 1.0 / (pulsesODLG_->areaFractionTime95_ns[i] - pulsesODLG_->areaFractionTime5_ns[i]);

			h_peakamp->Fill(pulsesODLG_->peakAmp[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_area->Fill(pulsesODLG_->pulseArea_phd[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_coincidence->Fill(pulsesODLG_->coincidence[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_phdCurrent->Fill(
			    pulsesODLG_->pulseStartTime_ns[i], eventareas, pulsesODLG_->pulseArea_phd[i] / eventareas);

			h_timing[0]->Fill(pulsesODLG_->areaFractionTime1_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[1]->Fill(pulsesODLG_->areaFractionTime5_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[2]->Fill(pulsesODLG_->areaFractionTime10_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[3]->Fill(pulsesODLG_->areaFractionTime25_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[4]->Fill(pulsesODLG_->areaFractionTime50_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[5]->Fill(pulsesODLG_->areaFractionTime75_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[6]->Fill(pulsesODLG_->areaFractionTime90_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[7]->Fill(pulsesODLG_->areaFractionTime95_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[8]->Fill(pulsesODLG_->areaFractionTime99_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[9]->Fill(pulsesODLG_->peakTime_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[10]->Fill(pulsesODLG_->rmsWidth_ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timing[11]->Fill(pulsesODLG_->promptFraction50ns[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			// h_timing[12]->Fill(pasym, pulsesODLG_->pulseArea_phd[i] / eventareas);

			h_timingVarea[0]->Fill(pulsesODLG_->areaFractionTime1_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[1]->Fill(pulsesODLG_->areaFractionTime5_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[2]->Fill(pulsesODLG_->areaFractionTime10_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[3]->Fill(pulsesODLG_->areaFractionTime25_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[4]->Fill(pulsesODLG_->areaFractionTime50_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[5]->Fill(pulsesODLG_->areaFractionTime75_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[6]->Fill(pulsesODLG_->areaFractionTime90_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[7]->Fill(pulsesODLG_->areaFractionTime95_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[8]->Fill(pulsesODLG_->areaFractionTime99_ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[9]->Fill(
			    pulsesODLG_->peakTime_ns[i], pulsesODLG_->pulseArea_phd[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[10]->Fill(
			    pulsesODLG_->rmsWidth_ns[i], pulsesODLG_->pulseArea_phd[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVarea[11]->Fill(pulsesODLG_->promptFraction50ns[i], pulsesODLG_->pulseArea_phd[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			// h_timingVarea[12]->Fill(pasym, pulsesODLG_->pulseArea_phd[i], pulsesODLG_->pulseArea_phd[i] /
			// eventareas);

			h_timingVcoincidence[0]->Fill(pulsesODLG_->areaFractionTime1_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[1]->Fill(pulsesODLG_->areaFractionTime5_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[2]->Fill(pulsesODLG_->areaFractionTime10_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[3]->Fill(pulsesODLG_->areaFractionTime25_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[4]->Fill(pulsesODLG_->areaFractionTime50_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[5]->Fill(pulsesODLG_->areaFractionTime75_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[6]->Fill(pulsesODLG_->areaFractionTime90_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[7]->Fill(pulsesODLG_->areaFractionTime95_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[8]->Fill(pulsesODLG_->areaFractionTime99_ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[9]->Fill(
			    pulsesODLG_->peakTime_ns[i], pulsesODLG_->coincidence[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[10]->Fill(
			    pulsesODLG_->rmsWidth_ns[i], pulsesODLG_->coincidence[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVcoincidence[11]->Fill(pulsesODLG_->promptFraction50ns[i], pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			// h_timingVcoincidence[12]->Fill(
			//    pasym, pulsesODLG_->coincidence[i], pulsesODLG_->pulseArea_phd[i] / eventareas);

			/*
			h_timingVphdperpmt[0]->Fill(pulsesODLG_->areaFractionTime1_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[1]->Fill(pulsesODLG_->areaFractionTime5_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[2]->Fill(pulsesODLG_->areaFractionTime10_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[3]->Fill(pulsesODLG_->areaFractionTime25_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[4]->Fill(pulsesODLG_->areaFractionTime50_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[5]->Fill(pulsesODLG_->areaFractionTime75_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[6]->Fill(pulsesODLG_->areaFractionTime90_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[7]->Fill(pulsesODLG_->areaFractionTime95_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[8]->Fill(pulsesODLG_->areaFractionTime99_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[9]->Fill(pulsesODLG_->peakTime_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[10]->Fill(pulsesODLG_->rmsWidth_ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVphdperpmt[11]->Fill(pulsesODLG_->promptFraction50ns[i],
			    pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			// h_timingVphdperpmt[12]->Fill(pasym, pulsesODLG_->pulseArea_phd[i] / pulsesODLG_->coincidence[i],
			//  pulsesODLG_->pulseArea_phd[i] / eventareas);
			*/

			h_timingVpeakamp[0]->Fill(pulsesODLG_->areaFractionTime1_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[1]->Fill(pulsesODLG_->areaFractionTime5_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[2]->Fill(pulsesODLG_->areaFractionTime10_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[3]->Fill(pulsesODLG_->areaFractionTime25_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[4]->Fill(pulsesODLG_->areaFractionTime50_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[5]->Fill(pulsesODLG_->areaFractionTime75_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[6]->Fill(pulsesODLG_->areaFractionTime90_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[7]->Fill(pulsesODLG_->areaFractionTime95_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[8]->Fill(pulsesODLG_->areaFractionTime99_ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[9]->Fill(
			    pulsesODLG_->peakTime_ns[i], pulsesODLG_->peakAmp[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[10]->Fill(
			    pulsesODLG_->rmsWidth_ns[i], pulsesODLG_->peakAmp[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
			h_timingVpeakamp[11]->Fill(pulsesODLG_->promptFraction50ns[i], pulsesODLG_->peakAmp[i],
			    pulsesODLG_->pulseArea_phd[i] / eventareas);
			// h_timingVpeakamp[12]->Fill(pasym, pulsesODLG_->peakAmp[i], pulsesODLG_->pulseArea_phd[i] / eventareas);
		}
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

	// create output file and store all hists here
	TFile* outfile = new TFile(fOutFileName, "recreate");
	cout << "Writing outputs to file" << endl;
	// eventareas = dynamic_cast<TH1F*>(fOutput->FindObject(hname.c_str()));
	// double scalefrac = (double)fChain->GetEntries();

	for (int i = 0; i < histnames.size(); i++)
	{
		std::string hname = "h_" + histnames[i];
		h_timing[i] = dynamic_cast<TH1F*>(fOutput->FindObject(hname.c_str()));
		h_timing[i]->Scale(1.0 / h_timing[i]->Integral());
		h_timing[i]->Write();

		hname = "h_" + histnames[i] + "Varea";
		h_timingVarea[i] = dynamic_cast<TH2F*>(fOutput->FindObject(hname.c_str()));
		h_timingVarea[i]->Scale(1.0 / h_timingVarea[i]->Integral());
		h_timingVarea[i]->Write();

		hname = "h_" + histnames[i] + "Vcoincidence";
		h_timingVcoincidence[i] = dynamic_cast<TH2F*>(fOutput->FindObject(hname.c_str()));
		h_timingVcoincidence[i]->Scale(1.0 / h_timingVcoincidence[i]->Integral());
		h_timingVcoincidence[i]->Write();

		/*
		hname = "h_" + histnames[i] + "Vphdperpmt";
		h_timingVphdperpmt[i] = dynamic_cast<TH2F*>(fOutput->FindObject(hname.c_str()));
		h_timingVphdperpmt[i]->Scale(1.0 / h_timingVphdperpmt[i]->Integral());
		h_timingVphdperpmt[i]->Write();
		*/

		hname = "h_" + histnames[i] + "Vpeakamp";
		h_timingVpeakamp[i] = dynamic_cast<TH2F*>(fOutput->FindObject(hname.c_str()));
		h_timingVpeakamp[i]->Scale(1.0 / h_timingVpeakamp[i]->Integral());
		h_timingVpeakamp[i]->Write();
	}

	h_area = dynamic_cast<TH1F*>(fOutput->FindObject("h_area"));
	h_area->Scale(1.0 / h_area->Integral());
	h_area->Write();

	h_peakamp = dynamic_cast<TH1F*>(fOutput->FindObject("h_peakamp"));
	h_peakamp->Scale(1.0 / h_peakamp->Integral());
	h_peakamp->Write();

	h_coincidence = dynamic_cast<TH1F*>(fOutput->FindObject("h_coincidence"));
	h_coincidence->Scale(1.0 / h_coincidence->Integral());
	h_coincidence->Write();

	/*
	h_phdperpulse = dynamic_cast<TH1F*>(fOutput->FindObject("h_phdperpulse"));
	h_phdperpulse->Scale(1.0 / h_phdperpulse->Integral());
	h_phdperpulse->Write();
	*/

	h_phdCurrent = dynamic_cast<TH2F*>(fOutput->FindObject("h_phdCurrent"));
	h_phdCurrent->Scale(1.0 / h_phdCurrent->Integral());
	h_phdCurrent->Write();

	outfile->Close();
	// delete outfile;
}

TH2F* Create2DHist(string h2name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max,
    double Ybins, double Ybin_min, double Ybin_max)
{
	TH2F* h = new TH2F(
	    h2name.c_str(), ("#font[132]{" + h2name + "}").c_str(), Xbins, Xbin_min, Xbin_max, Ybins, Ybin_min, Ybin_max);
	h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
	h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
	h->GetXaxis()->SetLabelFont(132);
	h->GetYaxis()->SetLabelFont(132);
	h->Sumw2();
	return h;
}
TH1F* Create1DHist(string h1name, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max)
{
	TH1F* h = new TH1F(h1name.c_str(), ("#font[132]{" + h1name + "}").c_str(), Xbins, Xbin_min, Xbin_max);
	h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
	h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
	h->GetXaxis()->SetLabelFont(132);
	h->GetYaxis()->SetLabelFont(132);
	// h->SetMarkerColor(color);
	// h->SetLineColor(color);
	return h;
}

TH1F* CreateSumw2Hist(string hname, string Xname, string Yname, double Xbins, double Xbin_min, double Xbin_max)
{
	TH1F* h = new TH1F(hname.c_str(), ("#font[132]{" + hname + "}").c_str(), Xbins, Xbin_min, Xbin_max);
	h->SetXTitle(("#font[132]{" + Xname + "}").c_str());
	h->SetYTitle(("#font[132]{" + Yname + "}").c_str());
	h->GetXaxis()->SetLabelFont(132);
	h->GetYaxis()->SetLabelFont(132);
	// h->SetMarkerColor(color);
	// h->SetLineColor(color);
	h->Sumw2();
	return h;
}
