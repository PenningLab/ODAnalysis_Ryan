//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr  5 15:43:21 2019 by ROOT version 6.17/01
// from TTree Events/LZ Reduced Quantities for an Event from LZap
// found on file: /yorktown/Cerenkov/lzap_scin.root
//////////////////////////////////////////////////////////

#ifndef MDC3Analysis_h
#define MDC3Analysis_h

#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TROOT.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>
#include <map>
#include <memory>
#include <vector>

// Headers needed by this particular selector
#include "rqlib/RQ__EventHeader.h"

#include "rqlib/RQ__DetectorPulses.h"

#include "rqlib/RQ__ODPulses.h"

#include "rqlib/RQ__SingleScatters.h"

#include "rqlib/RQ__MultipleScatters.h"

#include "rqlib/RQ__Kr83mScatters.h"

#include "rqlib/RQ__OtherScatters.h"

#include "rqlib/RQ__PileUpScatters.h"

class MDC3Analysis : public TSelector
{
public:
	TTreeReader fReader; //! the tree reader
	TTree* fChain = 0; //! pointer to the analyzed TTree or TChain
	TString fOutFileName;

	// Output histograms (OD only for now)
	std::vector<std::string> histnames { "aft1", "aft5", "aft10", "aft25", "aft50", "aft75", "aft90", "aft95", "aft99",
		"peakTime", "rmsWidth", "promptFrac50" };
	std::vector<std::string> histunits { "(ns)", "(ns)", "(ns)", "(ns)", "(ns)", "(ns)", "(ns)", "(ns)", "(ns)", "(ns)",
		"(ns)", "" };
	std::vector<double> histprecision { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 1, 0.01, 0.01 };
	std::vector<double> histxlimsu { 800, 800, 800, 800, 1000, 1000, 1200, 1400, 2200, 1000, 2000, 1.1, 1 };
	std::vector<double> histxlimsl { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1 };
	/*
	    struct outHists
	    {
	        outHists()
	            : h_timing(std::vector<TH1F*>(13))
	            , h_timingVarea(std::vector<TH2F*>(13))
	            , h_timingVpeakamp(std::vector<TH2F*>(13))
	            , h_timingVphdperpmt(std::vector<TH2F*>(13))
	            , h_timingVcoincidence(std::vector<TH2F*>(13))
	            , h_phdCurrent(0)
	            , h_area(0)
	            , h_coincidence(0)
	            , h_peakamp(0)
	            , h_phdperpulse(0)
	        {
	        }
	        std::vector<TH1F*> h_timing; // aft1, aft5, aft10, aft25, aft50, aft75, aft90, aft95, aft99, peakTime,
	   rmsWidth std::vector<TH2F*> h_timingVarea; std::vector<TH2F*> h_timingVcoincidence; std::vector<TH2F*>
	   h_timingVphdperpmt; std::vector<TH2F*> h_timingVpeakamp; TH2F* h_phdCurrent; TH1F* h_area; TH1F* h_coincidence;
	        TH1F* h_peakamp;
	        TH1F* h_phdperpulse;
	    };

	    std::map<std::string, outHists> woop;
	*/
	std::vector<TH1F*> h_timing
	    = std::vector<TH1F*>(12); // aft1, aft5, aft10, aft25, aft50, aft75, aft90, aft95, aft99, peakTime, rmsWidth
	std::vector<TH2F*> h_timingVarea = std::vector<TH2F*>(12);
	std::vector<TH2F*> h_timingVcoincidence = std::vector<TH2F*>(12);
	std::vector<TH2F*> h_timingVphdperpmt = std::vector<TH2F*>(12);
	std::vector<TH2F*> h_timingVpeakamp = std::vector<TH2F*>(12);
	TH2F* h_phdCurrent = 0;
	TH1F* h_area = 0;
	TH1F* h_coincidence = 0;
	TH1F* h_peakamp = 0;
	TH1F* h_phdperpulse = 0;

	// TH2F* h_ass = 0;

	// Readers to access the data (delete the ones you do not need).
	TTreeReaderValue<RQ::EventHeader> eventHeader_ = { fReader, "eventHeader." };
	/*
	TTreeReaderValue<RQ::DetectorPulses> pulsesTPCHG_ = { fReader, "pulsesTPCHG." };
	TTreeReaderValue<RQ::DetectorPulses> pulsesTPCLG_ = { fReader, "pulsesTPCLG." };
	TTreeReaderValue<RQ::DetectorPulses> pulsesSkin_ = { fReader, "pulsesSkin." };
	*/
	TTreeReaderValue<RQ::ODPulses> pulsesODHG_ = { fReader, "pulsesODHG." };
	TTreeReaderValue<RQ::ODPulses> pulsesODLG_ = { fReader, "pulsesODLG." };
	/*
	        TTreeReaderValue<RQ::SingleScatters> singleScatters_ = { fReader, "singleScatters." };
	    TTreeReaderValue<RQ::MultipleScatters> multipleScatters_ = { fReader, "multipleScatters." };
	    TTreeReaderValue<RQ::Kr83mScatters> kr83mScatters_ = { fReader, "kr83mScatters." };
	    TTreeReaderValue<RQ::OtherScatters> otherScatters_ = { fReader, "otherScatters." };
	    TTreeReaderValue<RQ::PileUpScatters> pileUpScatters_ = { fReader, "pileUpScatters." };
	*/
	// MDC3Analysis(TTree* /*tree*/ = 0){}
	virtual ~MDC3Analysis()
	{
	}
	virtual Int_t Version() const
	{
		return 2;
	}
	virtual void Begin(TTree* tree);
	virtual void SlaveBegin(TTree* tree);
	virtual void Init(TTree* tree);
	virtual Bool_t Notify();
	virtual Bool_t Process(Long64_t entry);
	virtual Int_t GetEntry(Long64_t entry, Int_t getall = 0)
	{
		return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0;
	}
	virtual void SetOption(const char* option)
	{
		fOption = option;
	}
	virtual void SetObject(TObject* obj)
	{
		fObject = obj;
	}
	virtual void SetInputList(TList* input)
	{
		fInput = input;
	}
	virtual TList* GetOutputList() const
	{
		return fOutput;
	}
	virtual void SlaveTerminate();
	virtual void Terminate();

	// Custom functions
	void SetOutputName(TString fileName)
	{
		fOutFileName = fileName;
	}

	ClassDef(MDC3Analysis, 0);
};

#endif

#ifdef MDC3Analysis_cxx
void MDC3Analysis::Init(TTree* tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the reader is initialized.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).
	if (!tree)
		return;
	fChain = tree;
	fReader.SetTree(tree);
}

Bool_t MDC3Analysis::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}

#endif // #ifdef MDC3Analysis_cxx
