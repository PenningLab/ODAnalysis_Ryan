#include "TEveBrowser.h"
#include "TEveManager.h"
#include "TGButton.h"
#include "TGLabel.h"
#include "TGNumberEntry.h"
#include "TGTab.h"

#include "ODChannels.C"
//#include "rqlib/rqlibProjectHeaders.h"

Int_t gEventID = 0;
Int_t gPulseID = 0;
Int_t gNPulses = 0;
Int_t gNEvts = 0;
Int_t gMinCoincidence = 0;
Double_t gMinArea = 0;
Int_t gFlip = 1;

ODChannels* gData = 0;
TGNumberEntryField* gEventNumberEntry = 0;
TGNumberEntryField* gCoincidenceNumberEntry = 0;
TGNumberEntryField* gAreaNumberEntry = 0;
TGLabel* gEventLabel = 0;
TGLabel* gEvent2Label = 0;
TGLabel* gPulseLabel = 0;
TGLabel* gPulse2Label = 0;
TGLabel* gAreaLabel = 0;
TGLabel* gTriggerLabel = 0;
TGLabel* gStartLabel = 0;
// /TGLabel* gSurvivalLabel = 0;
// TGLabel* gCoincidenceLabel = 0;
// bool cutsApplied = false;
// bool fwdsweep = true;
// std::vector<std::int> eventList;

// Forward declaration
bool load_event();
// bool getListofEvents();

//---------------------------------------------------------------------
class EvNavHandler
{
public:
	void Fwd()
	{
		gPulseID = gNPulses;
		do
		{
			if (gPulseID > gNPulses - 1)
			{
				++gEventID;
				gData->GetEntry(gEventID);
				gNPulses = gData->pulsesODLG_nPulses;
				gPulseID = 0;
			}
			else
				++gPulseID;
		} while (!load_event() && (gEventID < gNEvts - 1));
		if (gEventID >= gNEvts - 1)
		{
			printf("At last Event passing cuts.\n");
			gEventID = gNEvts - 1;
		}
	}
	void Bck()
	{
		gPulseID = 0;
		do
		{
			if (gPulseID < 1)
			{
				--gEventID;
				gData->GetEntry(gEventID);
				gNPulses = gData->pulsesODLG_nPulses;
				gPulseID = gNPulses - 1;
			}
			else
				--gPulseID;
		} while (!load_event() && (gEventID > 0));
		if (gEventID <= 0)
		{
			printf("At first Event passing cuts.\n");
			gEventID = 0;
		}
	}

	void FwdPlse()
	{
		do
		{
			++gPulseID;
			if (gPulseID > gNPulses - 1)
				break;
		} while (!load_event());
		if (gPulseID >= gNPulses)
		{
			printf("At last Pulse in Event passing cuts. Skipping to next event.\n");
			Fwd();
		}
	}
	void BckPlse()
	{
		do
		{
			--gPulseID;
			if (gPulseID < 0)
				break;
		} while (!load_event());
		if (gPulseID < 0)
		{
			printf("At first Pulse in Event passing cuts. Going to previous event.\n");
			Bck();
		}
	}

	void GotoEvent()
	{
		gEventID = gEventNumberEntry->GetIntNumber();
		gPulseID = 0;
		if (gEventID < 1)
		{
			std::cout << "Event ID too low! Going to first Event." << std::endl;
			gEventID = 0;
		}
		else if (gEventID > gNEvts)
		{
			std::cout << "Event ID beyond file! Going to last Event." << std::endl;
			gEventID = gNEvts - 1;
		}
		gEventNumberEntry->Clear();
		gData->GetEntry(gEventID);
		gNPulses = gData->pulsesODLG_nPulses;
		load_event();
	}

	void AreaCut()
	{
		gMinArea = gAreaNumberEntry->GetNumber();
		if (gMinArea < 0)
		{
			std::cout << "Cannot have negative minimum area! Setting 0 as minimum." << std::endl;
			gMinArea = 0;
		}
	}

	void CoincidenceCut()
	{
		gMinCoincidence = gCoincidenceNumberEntry->GetIntNumber();
		if (gMinCoincidence < 0)
		{
			std::cout << "Cannot have negative minimum coincidence! Setting 0 as minimum." << std::endl;
			gMinCoincidence = 0;
		}
	}

	/*void ApplyCuts()
	{
	    if (gCoincidenceNumberEntry != 0 || gAreaNumberEntry != 0)
	    {
	        cutsApplied = getListofEvents();
	        // gCoincidenceNumberEntry = 0;
	        // gAreaNumberEntry = 0;
	        // load_event();
	    }

	    else
	        std::cout << "Set at least one Cut parameter before proceding." << std::endl;

	}*/
};

//---------------------------------------------------------------------
void make_gui()
{
	// Create minimal GUI for event navigation.

	TEveBrowser* browser = gEve->GetBrowser();
	browser->StartEmbedding(TRootBrowser::kLeft);

	EvNavHandler* fh = new EvNavHandler;

	TGMainFrame* frmMain = new TGMainFrame(gClient->GetRoot(), 1500, 900);
	frmMain->SetWindowName("XX GUI");
	frmMain->SetCleanup(kDeepCleanup);
	std::cout << "Creating GUI Frames" << std::endl;

	// TString icondir(TString::Format("%s/share/root/icons/", gSystem->Getenv("ROOTSYS")));
	TString icondir(TString::Format("%s/icons/", gSystem->Getenv("ROOTSYS")));
	TGLayoutHints* lh = new TGLayoutHints(kLHintsNormal, 0, 0, 4, 0);

	TGHorizontalFrame* hf = new TGHorizontalFrame(frmMain);
	{
		TGVerticalFrame* vf = new TGVerticalFrame(hf);
		{
			TGPictureButton* b = 0;
			TGLabel* blabel = 0;

			blabel = new TGLabel(vf, " Prev Evt ");
			blabel->SetTextJustify(kTextCenterY);
			b = new TGPictureButton(vf, gClient->GetPicture(icondir + "tb_back.xpm"));
			vf->AddFrame(blabel, lh);
			vf->AddFrame(b);

			b->Connect("Clicked()", "EvNavHandler", fh, "Bck()");
		}
		hf->AddFrame(vf);

		vf = new TGVerticalFrame(hf);
		{
			TGPictureButton* b = 0;
			TGLabel* blabel = 0;

			blabel = new TGLabel(vf, " Next Evt ");
			blabel->SetTextJustify(kTextCenterY);
			b = new TGPictureButton(vf, gClient->GetPicture(icondir + "tb_forw.xpm"));
			vf->AddFrame(blabel, lh);
			vf->AddFrame(b);
			b->Connect("Clicked()", "EvNavHandler", fh, "Fwd()");
		}
		hf->AddFrame(vf);
	}
	frmMain->AddFrame(hf);

	hf = new TGHorizontalFrame(frmMain);
	{
		TGVerticalFrame* vf = new TGVerticalFrame(hf);
		{
			TGPictureButton* b = 0;
			TGLabel* blabel = 0;

			blabel = new TGLabel(vf, " Prev Pulse ");
			blabel->SetTextJustify(kTextCenterY);
			b = new TGPictureButton(vf, gClient->GetPicture(icondir + "tb_back.xpm"));
			vf->AddFrame(blabel, lh);
			vf->AddFrame(b);
			b->Connect("Clicked()", "EvNavHandler", fh, "BckPlse()");
		}

		hf->AddFrame(vf);

		vf = new TGVerticalFrame(hf);
		{
			TGPictureButton* b = 0;
			TGLabel* blabel = 0;

			blabel = new TGLabel(vf, " Next Pulse ");
			blabel->SetTextJustify(kTextCenterY);
			b = new TGPictureButton(vf, gClient->GetPicture(icondir + "tb_forw.xpm"));
			vf->AddFrame(blabel, lh);
			vf->AddFrame(b);
			b->Connect("Clicked()", "EvNavHandler", fh, "FwdPlse()");
		}
		hf->AddFrame(vf);
	}

	frmMain->AddFrame(hf);

	hf = new TGHorizontalFrame(frmMain);
	{
		// ability to jump to event
		TGLabel* eventNbrLabel = new TGLabel(hf, " Go to Event # ");
		gEventNumberEntry = new TGNumberEntryField(hf, 0, 0, TGNumberFormat::kNESInteger,
		    TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 10000000);
		hf->AddFrame(eventNbrLabel, lh);
		hf->AddFrame(gEventNumberEntry);
		gEventNumberEntry->Connect("ReturnPressed()", "EvNavHandler", fh, "GotoEvent()");
	}
	frmMain->AddFrame(hf);

	hf = new TGHorizontalFrame(frmMain);
	{
		// ability to jump to event
		TGLabel* areacutNbrLabel = new TGLabel(hf, " Min Area (phd) ");
		gAreaNumberEntry = new TGNumberEntryField(hf, 0, 0, TGNumberFormat::kNESRealOne,
		    TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 10000000);
		hf->AddFrame(areacutNbrLabel, lh);
		hf->AddFrame(gAreaNumberEntry);
		gAreaNumberEntry->Connect("ReturnPressed()", "EvNavHandler", fh, "AreaCut()");
	}
	frmMain->AddFrame(hf);

	hf = new TGHorizontalFrame(frmMain);
	{
		// ability to jump to event
		TGLabel* coincidencecutNbrLabel = new TGLabel(hf, " Min Coincidence ");
		gCoincidenceNumberEntry = new TGNumberEntryField(hf, 0, 0, TGNumberFormat::kNESInteger,
		    TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 10000000);
		hf->AddFrame(coincidencecutNbrLabel, lh);
		hf->AddFrame(gCoincidenceNumberEntry);
		gCoincidenceNumberEntry->Connect("ReturnPressed()", "EvNavHandler", fh, "CoincidenceCut()");
	}
	frmMain->AddFrame(hf);

	/*hf = new TGHorizontalFrame(frmMain);
	{
	    TGPictureButton* b = 0;
	    TGLabel* blabel = 0;

	    blabel = new TGLabel(vf, " Apply Cuts ");
	    blabel->SetTextJustify(kTextCenterY);
	    b = new TGPictureButton(vf, gClient->GetPicture(icondir + "bld_cut.xpm"));
	    vf->AddFrame(blabel, lh);
	    vf->AddFrame(b);
	    b->Connect("Clicked()", "EvNavHandler", fh, "ApplyCuts()");
	}
	frmMain->AddFrame(hf);*/

	hf = new TGHorizontalFrame(frmMain);
	{
		// Show event number
		TGLabel* evtLabel = new TGLabel(hf, " Event: ");
		gEventLabel = new TGLabel(hf, "-1");
		gEventLabel->SetTextJustify(kTextBottom);
		gEventLabel->SetTextJustify(kTextLeft);
		gEventLabel->SetMargins(0, 20);

		hf->AddFrame(evtLabel, lh);
		hf->AddFrame(gEventLabel, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
		//	hf->AddFrame(hf);

		TGLabel* evt2Label = new TGLabel(hf, " / ");
		gEvent2Label = new TGLabel(hf, "-1");
		gEvent2Label->SetTextJustify(kTextBottom);
		gEvent2Label->SetTextJustify(kTextLeft);
		gEvent2Label->SetMargins(0, 20);

		hf->AddFrame(evt2Label, lh);
		hf->AddFrame(gEvent2Label, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
	}
	frmMain->AddFrame(hf);

	hf = new TGHorizontalFrame(frmMain);
	{
		// Show pulse number
		TGLabel* pulseLabel = new TGLabel(hf, " Pulse: ");
		gPulseLabel = new TGLabel(hf, "-1");
		gPulseLabel->SetTextJustify(kTextBottom);
		gPulseLabel->SetTextJustify(kTextLeft);
		gPulseLabel->SetMargins(0, 20);

		hf->AddFrame(pulseLabel, lh);
		hf->AddFrame(gPulseLabel, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));

		// Show pulse number
		TGLabel* pulse2Label = new TGLabel(hf, " / ");
		gPulse2Label = new TGLabel(hf, "-1");
		gPulse2Label->SetTextJustify(kTextBottom);
		gPulse2Label->SetTextJustify(kTextLeft);
		gPulse2Label->SetMargins(0, 20);

		hf->AddFrame(pulse2Label, lh);
		hf->AddFrame(gPulse2Label, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
	}
	frmMain->AddFrame(hf);
	hf = new TGHorizontalFrame(frmMain);
	{
		// Show channel number
		TGLabel* areaLabel = new TGLabel(hf, " Area (phd): ");
		gAreaLabel = new TGLabel(hf, "-1");
		gAreaLabel->SetTextJustify(kTextBottom);
		gAreaLabel->SetTextJustify(kTextLeft);
		gAreaLabel->SetMargins(0, 20);

		hf->AddFrame(areaLabel, lh);
		hf->AddFrame(gAreaLabel, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
	}
	frmMain->AddFrame(hf);
	// start time
	hf = new TGHorizontalFrame(frmMain);
	{
		// Show channel number
		TGLabel* trigLabel = new TGLabel(hf, " Trigger Time (ns): ");
		gTriggerLabel = new TGLabel(hf, "-1");
		gTriggerLabel->SetTextJustify(kTextBottom);
		gTriggerLabel->SetTextJustify(kTextLeft);
		gTriggerLabel->SetMargins(0, 20);

		hf->AddFrame(trigLabel, lh);
		hf->AddFrame(gTriggerLabel, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
	}
	frmMain->AddFrame(hf);
	// trigger time
	hf = new TGHorizontalFrame(frmMain);
	{
		// Show channel number
		TGLabel* startLabel = new TGLabel(hf, " Start Time (ns): ");
		gStartLabel = new TGLabel(hf, "-1");
		gStartLabel->SetTextJustify(kTextBottom);
		gStartLabel->SetTextJustify(kTextLeft);
		gStartLabel->SetMargins(0, 20);

		hf->AddFrame(startLabel, lh);
		hf->AddFrame(gStartLabel, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
	}
	frmMain->AddFrame(hf);

	frmMain->MapSubwindows();
	frmMain->Resize();
	frmMain->MapWindow();

	//	std::cout << "Window shenanigans" << std::endl;

	browser->StopEmbedding();
	browser->SetTabTitle("Pulse Control", 0);
}
