#include "TAxis.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TMath.h"
#include "TMultiGraph.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"

//#include "ODChannels.h"
//#include "rqlib/rqlibProjectHeaders.h"
#include "ODChannelGui.C"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

TCanvas* gPodCanvas = 0;
// TPad* gMapPad = 0;
// TPad* gWavePad = 0;
TGraph2D* gr_pods;
// TGraph* gr_wave;

//---------------------------------------------------------------------
TGraph2D* channel_map_plots(ODChannels* datum)
{
	// Draw Channel map here
	TString gname = Form("Event %d - Pulse %d", gEventID + 1, gPulseID + 1);
	TString gtitle = Form("Event %d - Pulse %d", gEventID + 1, gPulseID + 1);
	TGraph2D* g = new TGraph2D(20 * 6);
	double chMap[20][6] = { 0 };

	for (int i = 0; i < datum->pulsesODLG_chID[gPulseID].size(); ++i)
	{
		int chID = datum->pulsesODLG_chID[gPulseID][i] - 800;
		if (chID >= 1000)
			chID -= 1000;
		chMap[chID % 20][chID / 20]
		    += datum->pulsesODLG_chPulseArea_phd[gPulseID][i] / datum->pulsesODLG_pulseArea_phd[gPulseID];
	}
	int k = 0;
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 5; j >= 0; --j)
		{
			g->SetPoint(k, i + 1, j + 1, chMap[i][j]);
			++k;
		}
	}
	g->SetNameTitle(gname.Data(), gtitle.Data());
	gStyle->SetPalette(55);
	gStyle->SetOptStat(0);
	// gPad->SetLogz();
	g->SetMarkerStyle(20);
	g->SetMarkerSize(3);
	return g;
}
/*
TGraph* waveform_plots(ODChannels* datum)
{
    // Draw Channel map here
    TString gname = Form("Event %d - Pulse %d Waveform", gEventID, gPulseID);
    // TString gtitle = Form("Event %d - Pulse %d", gEventID, gPulseID);
    // std::shared_ptr<TGraph> g(new TH2D(gname.Data(), gtitle.Data(), 20, 0, 20, 6, 0, 6));
    // std::vector<std::vector<double>> chMap(20, std::vector<double>(6));

    int k = 0;
    TGraph* g = new TGraph();
    double samplewidth
        = (double)(datum->pulsesODLG_pulseEndTime_ns[gPulseID] - datum->pulsesODLG_pulseStartTime_ns[gPulseID])
        / (double)datum->pulsesODLG_pulseWaveform[gPulseID].size();
    // std::cout << "seting data points" << std::endl;
    for (int i = 0; i < datum->pulsesODLG_pulseWaveform[gPulseID].size(); ++i)
    {
        g->SetPoint(i, i * samplewidth, datum->pulsesODLG_pulseWaveform[gPulseID][i]);
    }
    // std::cout << "All data points set" << std::endl;
    g->SetNameTitle(gname, "");
    gStyle->SetPalette(55);
    gStyle->SetOptStat(0);
    g->GetYaxis()->SetTitle("Height (phd/ns)");
    g->GetXaxis()->SetTitle("Time (ns)");
    g->GetYaxis()->SetTitleOffset(0.5);
    g->GetXaxis()->SetTitleOffset(1.0);

    // gPad->SetLogz();
    // g->SetMarkerStyle(20);
    // g->SetMarkerSize(2);
    return g;
}
*/
//---------------------------------------------------------------------
bool load_event()
{
	Long64_t local = gEventID;
	// gData->GetEntry(local);
	Int_t localp = gPulseID;
	if (localp > gData->pulsesODLG_nPulses - 1)
	{
		printf("Pulse %d in Event %d does not exist.\n", gPulseID, gEventID);
		return false;
	}
	if (gData->pulsesODLG_coincidence[localp] < gMinCoincidence || gData->pulsesODLG_pulseArea_phd[localp] < gMinArea)
	{
		printf("Event %d fails cuts.\n", gEventID);
		return false;
	}
	else
	{
		printf("Loading Event %d pulse %d.\n", gEventID, gPulseID);

		// FOR DEFAULT SORTED EVENTS:

		gEventLabel->SetText(Form("%lu", gData->eventHeader_eventID + 1));
		gEvent2Label->SetText(Form("%d", gNEvts));
		gPulseLabel->SetText(Form("%d", gData->pulsesODLG_pulseID[localp] + 1));
		gPulse2Label->SetText(Form("%d", gNPulses));
		gAreaLabel->SetText(Form("%f", gData->pulsesODLG_pulseArea_phd[localp]));
		gTriggerLabel->SetText(Form("%lu", gData->eventHeader_triggerTimeStamp_ns));
		gStartLabel->SetText(Form("%d", gData->pulsesODLG_pulseStartTime_ns[localp]));

		/*if (gPodCanvas != 0)
		    gPodCanvas->Clear();
		if (gMapPad != 0)
		    gMapPad->Clear();
		if (gWavePad != 0)
		    gWavePad->Clear();
		    */

		gPodCanvas->SetName("Pulse");
		gPodCanvas->SetTitle(Form("Event %d - Pulse %d", gEventID, gPulseID));
		gPodCanvas->cd(0);

		// std::cout << "pre Drawing Channel map" << std::endl;
		// printf("Creating hist\n");
		// gMapPad->SetPad();
		// gMapPad->cd(0);
		gr_pods = channel_map_plots(gData);
		// std::cout << "Drawing Channel map" << std::endl;
		gr_pods->Draw("pcolz");
		gPad->SetTheta(90.);
		gPad->SetPhi(0.00);
		// printf("Drawing hist\n");
		gr_pods->GetYaxis()->SetTitle("Z");
		gr_pods->GetXaxis()->SetTitle("Phi (Pi/10)");
		gr_pods->GetYaxis()->SetTitleOffset(-0.5);
		gr_pods->GetXaxis()->SetTitleOffset(1.6);
		gr_pods->GetXaxis()->SetRangeUser(0, 21);
		gr_pods->GetYaxis()->SetRangeUser(0, 7);
		// gMapPad->Update();
		gPodCanvas->cd(0);
		// gMapPad->Draw();
		gPodCanvas->Update();

		// gWavePad->SetPad();
		// gWavePad->cd(0);
		// gr_wave = waveform_plots(gData);
		// std::cout << "Drawing waveform" << std::endl;
		// gr_wave->Draw("al");
		// gWavePad->Update();
		// gPodCanvas->cd(0);
		// gWavePad->Draw();
		// gr_pods->Draw("colz");
		gPodCanvas->Update();
	}
	return true;
}

void ODChannelViewer()
{

	TString filename;
	bool fileFound = false;
	std::cout << "Specify file name: " << std::endl;
	std::cin >> filename;
	// filename = "/yorktown/LZaptst/newtst.root";
	// std::ifstream fileTest(((string)filename).c_str());
	while (!filename.Contains(".root") /*|| !fileTest.good()*/)
	{
		std::cout << "File doesn't exist or doesn't end in .root - please specify "
		             "a different file: "
		          << std::endl;
		std::cin >> filename;
		// fileTest.open(filename);
	}
	// fileTest.close();

	TChain* t_data = new TChain("Events");
	t_data->Add(filename);
	// TTree* t_stageData = (TTree*)f->Get("StageData");

	if (t_data->GetEntries() == 0)
	{
		std::cout << "File does not contain Events data" << std::endl;
		exit(1);
	}
	else
	{
		// std::cout << "Now creating analysis object" << endl;
		gData = new ODChannels(t_data);
		gNEvts = gData->fChain->GetEntries();
		// std::cout << "object built" << endl;
		// gData->Begin(0);
		// gData->Init(t_data);

		// gStageData = new StageData(t_stageData);
		// gStageData = NULL;

		TEveManager::Create();

		make_gui();

		gEve->GetBrowser()->StartEmbedding(1);
		gPodCanvas = new TCanvas();
		gPodCanvas->SetLeftMargin(0.04);
		// gMapPad = new TPad("chmap", "", 0, 0.44, 1.0, 1.0);
		// gMapPad->SetLeftMargin(0.07);
		// gMapPad->SetRightMargin(0.13);
		// gWavePad = new TPad("waveform", "", 0, 0.0, 1.0, 0.44);
		// gWavePad->SetLeftMargin(0.07);

		gEve->GetBrowser()->StopEmbedding("Pulse");

		gEve->GetBrowser()->SetTab(1, 1);

		gEventID = 0;
		gPulseID = 0;
		do
		{
			if (gEventID >= gNEvts - 1)
			{
				std::cout << "No Valid Events in file!" << std::endl;
				break;
			}
			else if (gPulseID >= gNPulses - 1)
			{
				++gEventID;
				gData->GetEntry(gEventID);
				gNPulses = gData->pulsesODLG_nPulses;
				gPulseID = 0;
			}
			else
				++gPulseID;
		} while (!load_event());
	}
}
