//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 15 18:20:47 2019 by ROOT version 6.16/00
// from TTree Events/LZ Reduced Quantities for an Event from LZap
// found on file: /yorktown/LZaptst/newtst.root
//////////////////////////////////////////////////////////

#ifndef ODChannels_h
#define ODChannels_h

#include <TChain.h>
#include <TFile.h>
#include <TROOT.h>

// Header file for the classes stored in the TTree if any.
#include "rqlib/rqlibProjectHeaders.h"

class ODChannels
{
public:
	TTree* fChain; //! pointer to the analyzed TTree or TChain
	Int_t fCurrent; //! current Tree number in a TChain

	// Fixed size dimensions of array or collections stored in the TTree if any.
	static constexpr Int_t kMaxeventHeader = 1;
	static constexpr Int_t kMaxpulsesTPC = 1;
	static constexpr Int_t kMaxpulsesTPCHG = 1;
	static constexpr Int_t kMaxpulsesTPCLG = 1;
	static constexpr Int_t kMaxpulsesSkin = 1;
	static constexpr Int_t kMaxOLDpulsesODHG = 1;
	static constexpr Int_t kMaxOLDpulsesODLG = 1;
	static constexpr Int_t kMaxpulsesODHG = 1;
	static constexpr Int_t kMaxpulsesODLG = 1;
	static constexpr Int_t kMaxsingleScatters = 1;
	static constexpr Int_t kMaxmultipleScatters = 1;
	static constexpr Int_t kMaxkr83mScatters = 1;
	static constexpr Int_t kMaxotherScatters = 1;
	static constexpr Int_t kMaxpileUpScatters = 1;

	// Declaration of leaf types
	// RQ::EventHeader *eventHeader_;
	UInt_t eventHeader_TObject_fUniqueID;
	UInt_t eventHeader_TObject_fBits;
	ULong_t eventHeader_runID;
	ULong_t eventHeader_eventID;
	string eventHeader_rawFileName;
	ULong_t eventHeader_triggerTimeStamp_s;
	ULong_t eventHeader_triggerTimeStamp_ns;
	// RQ::DetectorPulses *pulsesTPC_;
	UInt_t pulsesTPC_TObject_fUniqueID;
	UInt_t pulsesTPC_TObject_fBits;
	Int_t pulsesTPC_nPulses;
	vector<int> pulsesTPC_pulseID;
	vector<int> pulsesTPC_pulseStartTime_ns;
	vector<int> pulsesTPC_pulseEndTime_ns;
	vector<bool> pulsesTPC_saturated;
	vector<int> pulsesTPC_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesTPC_saturatedChannelIDs;
	vector<float> pulsesTPC_pulseArea_phd;
	vector<float> pulsesTPC_positiveArea_phd;
	vector<float> pulsesTPC_negativeArea_phd;
	vector<float> pulsesTPC_peakAmp;
	vector<int> pulsesTPC_peakTime_ns;
	vector<int> pulsesTPC_areaFractionTime1_ns;
	vector<int> pulsesTPC_areaFractionTime5_ns;
	vector<int> pulsesTPC_areaFractionTime10_ns;
	vector<int> pulsesTPC_areaFractionTime25_ns;
	vector<int> pulsesTPC_areaFractionTime50_ns;
	vector<int> pulsesTPC_areaFractionTime75_ns;
	vector<int> pulsesTPC_areaFractionTime90_ns;
	vector<int> pulsesTPC_areaFractionTime95_ns;
	vector<int> pulsesTPC_areaFractionTime99_ns;
	vector<float> pulsesTPC_pulseAreaNeg50ns_phd;
	vector<float> pulsesTPC_pulseArea50ns_phd;
	vector<float> pulsesTPC_pulseArea100ns_phd;
	vector<float> pulsesTPC_pulseArea200ns_phd;
	vector<float> pulsesTPC_pulseArea500ns_phd;
	vector<float> pulsesTPC_pulseArea1us_phd;
	vector<float> pulsesTPC_pulseArea2us_phd;
	vector<float> pulsesTPC_pulseArea5us_phd;
	vector<float> pulsesTPC_promptFraction50ns;
	vector<int> pulsesTPC_rmsWidth_ns;
	vector<int> pulsesTPC_fwhm_ns;
	vector<float> pulsesTPC_topArea_phd;
	vector<float> pulsesTPC_bottomArea_phd;
	vector<float> pulsesTPC_topBottomAsymmetry;
	vector<int> pulsesTPC_coincidence;
	vector<float> pulsesTPC_s1Probability;
	vector<float> pulsesTPC_s2Probability;
	vector<float> pulsesTPC_singlePEprobability;
	vector<float> pulsesTPC_multiplePEprobability;
	vector<float> pulsesTPC_singleElectronProbability;
	vector<float> pulsesTPC_otherProbability;
	vector<float> pulsesTPC_otherS2Probability;
	vector<int> pulsesTPC_photonCount;
	vector<int> pulsesTPC_topPhotonCount;
	vector<int> pulsesTPC_bottomPhotonCount;
	vector<float> pulsesTPC_s2Xposition_cm;
	vector<float> pulsesTPC_s2Yposition_cm;
	vector<int> pulsesTPC_HGLGpulseID;
	vector<vector<int>> pulsesTPC_chID;
	vector<vector<float>> pulsesTPC_chPulseArea_phd;
	vector<vector<float>> pulsesTPC_chPeakAmp;
	vector<vector<int>> pulsesTPC_chPeakTime_ns;
	vector<vector<bool>> pulsesTPC_chSaturated;
	vector<vector<int>> pulsesTPC_chPhotonCount;
	vector<vector<vector<int>>> pulsesTPC_chPhotonTimes;
	// RQ::DetectorPulses *pulsesTPCHG_;
	UInt_t pulsesTPCHG_TObject_fUniqueID;
	UInt_t pulsesTPCHG_TObject_fBits;
	Int_t pulsesTPCHG_nPulses;
	vector<int> pulsesTPCHG_pulseID;
	vector<int> pulsesTPCHG_pulseStartTime_ns;
	vector<int> pulsesTPCHG_pulseEndTime_ns;
	vector<bool> pulsesTPCHG_saturated;
	vector<int> pulsesTPCHG_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesTPCHG_saturatedChannelIDs;
	vector<float> pulsesTPCHG_pulseArea_phd;
	vector<float> pulsesTPCHG_positiveArea_phd;
	vector<float> pulsesTPCHG_negativeArea_phd;
	vector<float> pulsesTPCHG_peakAmp;
	vector<int> pulsesTPCHG_peakTime_ns;
	vector<int> pulsesTPCHG_areaFractionTime1_ns;
	vector<int> pulsesTPCHG_areaFractionTime5_ns;
	vector<int> pulsesTPCHG_areaFractionTime10_ns;
	vector<int> pulsesTPCHG_areaFractionTime25_ns;
	vector<int> pulsesTPCHG_areaFractionTime50_ns;
	vector<int> pulsesTPCHG_areaFractionTime75_ns;
	vector<int> pulsesTPCHG_areaFractionTime90_ns;
	vector<int> pulsesTPCHG_areaFractionTime95_ns;
	vector<int> pulsesTPCHG_areaFractionTime99_ns;
	vector<float> pulsesTPCHG_pulseAreaNeg50ns_phd;
	vector<float> pulsesTPCHG_pulseArea50ns_phd;
	vector<float> pulsesTPCHG_pulseArea100ns_phd;
	vector<float> pulsesTPCHG_pulseArea200ns_phd;
	vector<float> pulsesTPCHG_pulseArea500ns_phd;
	vector<float> pulsesTPCHG_pulseArea1us_phd;
	vector<float> pulsesTPCHG_pulseArea2us_phd;
	vector<float> pulsesTPCHG_pulseArea5us_phd;
	vector<float> pulsesTPCHG_promptFraction50ns;
	vector<int> pulsesTPCHG_rmsWidth_ns;
	vector<int> pulsesTPCHG_fwhm_ns;
	vector<float> pulsesTPCHG_topArea_phd;
	vector<float> pulsesTPCHG_bottomArea_phd;
	vector<float> pulsesTPCHG_topBottomAsymmetry;
	vector<int> pulsesTPCHG_coincidence;
	vector<float> pulsesTPCHG_s1Probability;
	vector<float> pulsesTPCHG_s2Probability;
	vector<float> pulsesTPCHG_singlePEprobability;
	vector<float> pulsesTPCHG_multiplePEprobability;
	vector<float> pulsesTPCHG_singleElectronProbability;
	vector<float> pulsesTPCHG_otherProbability;
	vector<float> pulsesTPCHG_otherS2Probability;
	vector<int> pulsesTPCHG_photonCount;
	vector<int> pulsesTPCHG_topPhotonCount;
	vector<int> pulsesTPCHG_bottomPhotonCount;
	vector<float> pulsesTPCHG_s2Xposition_cm;
	vector<float> pulsesTPCHG_s2Yposition_cm;
	vector<int> pulsesTPCHG_HGLGpulseID;
	vector<vector<int>> pulsesTPCHG_chID;
	vector<vector<float>> pulsesTPCHG_chPulseArea_phd;
	vector<vector<float>> pulsesTPCHG_chPeakAmp;
	vector<vector<int>> pulsesTPCHG_chPeakTime_ns;
	vector<vector<bool>> pulsesTPCHG_chSaturated;
	vector<vector<int>> pulsesTPCHG_chPhotonCount;
	vector<vector<vector<int>>> pulsesTPCHG_chPhotonTimes;
	// RQ::DetectorPulses *pulsesTPCLG_;
	UInt_t pulsesTPCLG_TObject_fUniqueID;
	UInt_t pulsesTPCLG_TObject_fBits;
	Int_t pulsesTPCLG_nPulses;
	vector<int> pulsesTPCLG_pulseID;
	vector<int> pulsesTPCLG_pulseStartTime_ns;
	vector<int> pulsesTPCLG_pulseEndTime_ns;
	vector<bool> pulsesTPCLG_saturated;
	vector<int> pulsesTPCLG_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesTPCLG_saturatedChannelIDs;
	vector<float> pulsesTPCLG_pulseArea_phd;
	vector<float> pulsesTPCLG_positiveArea_phd;
	vector<float> pulsesTPCLG_negativeArea_phd;
	vector<float> pulsesTPCLG_peakAmp;
	vector<int> pulsesTPCLG_peakTime_ns;
	vector<int> pulsesTPCLG_areaFractionTime1_ns;
	vector<int> pulsesTPCLG_areaFractionTime5_ns;
	vector<int> pulsesTPCLG_areaFractionTime10_ns;
	vector<int> pulsesTPCLG_areaFractionTime25_ns;
	vector<int> pulsesTPCLG_areaFractionTime50_ns;
	vector<int> pulsesTPCLG_areaFractionTime75_ns;
	vector<int> pulsesTPCLG_areaFractionTime90_ns;
	vector<int> pulsesTPCLG_areaFractionTime95_ns;
	vector<int> pulsesTPCLG_areaFractionTime99_ns;
	vector<float> pulsesTPCLG_pulseAreaNeg50ns_phd;
	vector<float> pulsesTPCLG_pulseArea50ns_phd;
	vector<float> pulsesTPCLG_pulseArea100ns_phd;
	vector<float> pulsesTPCLG_pulseArea200ns_phd;
	vector<float> pulsesTPCLG_pulseArea500ns_phd;
	vector<float> pulsesTPCLG_pulseArea1us_phd;
	vector<float> pulsesTPCLG_pulseArea2us_phd;
	vector<float> pulsesTPCLG_pulseArea5us_phd;
	vector<float> pulsesTPCLG_promptFraction50ns;
	vector<int> pulsesTPCLG_rmsWidth_ns;
	vector<int> pulsesTPCLG_fwhm_ns;
	vector<float> pulsesTPCLG_topArea_phd;
	vector<float> pulsesTPCLG_bottomArea_phd;
	vector<float> pulsesTPCLG_topBottomAsymmetry;
	vector<int> pulsesTPCLG_coincidence;
	vector<float> pulsesTPCLG_s1Probability;
	vector<float> pulsesTPCLG_s2Probability;
	vector<float> pulsesTPCLG_singlePEprobability;
	vector<float> pulsesTPCLG_multiplePEprobability;
	vector<float> pulsesTPCLG_singleElectronProbability;
	vector<float> pulsesTPCLG_otherProbability;
	vector<float> pulsesTPCLG_otherS2Probability;
	vector<int> pulsesTPCLG_photonCount;
	vector<int> pulsesTPCLG_topPhotonCount;
	vector<int> pulsesTPCLG_bottomPhotonCount;
	vector<float> pulsesTPCLG_s2Xposition_cm;
	vector<float> pulsesTPCLG_s2Yposition_cm;
	vector<int> pulsesTPCLG_HGLGpulseID;
	vector<vector<int>> pulsesTPCLG_chID;
	vector<vector<float>> pulsesTPCLG_chPulseArea_phd;
	vector<vector<float>> pulsesTPCLG_chPeakAmp;
	vector<vector<int>> pulsesTPCLG_chPeakTime_ns;
	vector<vector<bool>> pulsesTPCLG_chSaturated;
	vector<vector<int>> pulsesTPCLG_chPhotonCount;
	vector<vector<vector<int>>> pulsesTPCLG_chPhotonTimes;
	// RQ::DetectorPulses *pulsesSkin_;
	UInt_t pulsesSkin_TObject_fUniqueID;
	UInt_t pulsesSkin_TObject_fBits;
	Int_t pulsesSkin_nPulses;
	vector<int> pulsesSkin_pulseID;
	vector<int> pulsesSkin_pulseStartTime_ns;
	vector<int> pulsesSkin_pulseEndTime_ns;
	vector<bool> pulsesSkin_saturated;
	vector<int> pulsesSkin_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesSkin_saturatedChannelIDs;
	vector<float> pulsesSkin_pulseArea_phd;
	vector<float> pulsesSkin_positiveArea_phd;
	vector<float> pulsesSkin_negativeArea_phd;
	vector<float> pulsesSkin_peakAmp;
	vector<int> pulsesSkin_peakTime_ns;
	vector<int> pulsesSkin_areaFractionTime1_ns;
	vector<int> pulsesSkin_areaFractionTime5_ns;
	vector<int> pulsesSkin_areaFractionTime10_ns;
	vector<int> pulsesSkin_areaFractionTime25_ns;
	vector<int> pulsesSkin_areaFractionTime50_ns;
	vector<int> pulsesSkin_areaFractionTime75_ns;
	vector<int> pulsesSkin_areaFractionTime90_ns;
	vector<int> pulsesSkin_areaFractionTime95_ns;
	vector<int> pulsesSkin_areaFractionTime99_ns;
	vector<float> pulsesSkin_pulseAreaNeg50ns_phd;
	vector<float> pulsesSkin_pulseArea50ns_phd;
	vector<float> pulsesSkin_pulseArea100ns_phd;
	vector<float> pulsesSkin_pulseArea200ns_phd;
	vector<float> pulsesSkin_pulseArea500ns_phd;
	vector<float> pulsesSkin_pulseArea1us_phd;
	vector<float> pulsesSkin_pulseArea2us_phd;
	vector<float> pulsesSkin_pulseArea5us_phd;
	vector<float> pulsesSkin_promptFraction50ns;
	vector<int> pulsesSkin_rmsWidth_ns;
	vector<int> pulsesSkin_fwhm_ns;
	vector<float> pulsesSkin_topArea_phd;
	vector<float> pulsesSkin_bottomArea_phd;
	vector<float> pulsesSkin_topBottomAsymmetry;
	vector<int> pulsesSkin_coincidence;
	vector<float> pulsesSkin_s1Probability;
	vector<float> pulsesSkin_s2Probability;
	vector<float> pulsesSkin_singlePEprobability;
	vector<float> pulsesSkin_multiplePEprobability;
	vector<float> pulsesSkin_singleElectronProbability;
	vector<float> pulsesSkin_otherProbability;
	vector<float> pulsesSkin_otherS2Probability;
	vector<int> pulsesSkin_photonCount;
	vector<int> pulsesSkin_topPhotonCount;
	vector<int> pulsesSkin_bottomPhotonCount;
	vector<float> pulsesSkin_s2Xposition_cm;
	vector<float> pulsesSkin_s2Yposition_cm;
	vector<int> pulsesSkin_HGLGpulseID;
	vector<vector<int>> pulsesSkin_chID;
	vector<vector<float>> pulsesSkin_chPulseArea_phd;
	vector<vector<float>> pulsesSkin_chPeakAmp;
	vector<vector<int>> pulsesSkin_chPeakTime_ns;
	vector<vector<bool>> pulsesSkin_chSaturated;
	vector<vector<int>> pulsesSkin_chPhotonCount;
	vector<vector<vector<int>>> pulsesSkin_chPhotonTimes;
	// RQ::DetectorPulses *OLDpulsesODHG_;
	UInt_t OLDpulsesODHG_TObject_fUniqueID;
	UInt_t OLDpulsesODHG_TObject_fBits;
	Int_t OLDpulsesODHG_nPulses;
	vector<int> OLDpulsesODHG_pulseID;
	vector<int> OLDpulsesODHG_pulseStartTime_ns;
	vector<int> OLDpulsesODHG_pulseEndTime_ns;
	vector<bool> OLDpulsesODHG_saturated;
	vector<int> OLDpulsesODHG_nSaturatedChannels;
	vector<vector<unsigned int>> OLDpulsesODHG_saturatedChannelIDs;
	vector<float> OLDpulsesODHG_pulseArea_phd;
	vector<float> OLDpulsesODHG_positiveArea_phd;
	vector<float> OLDpulsesODHG_negativeArea_phd;
	vector<float> OLDpulsesODHG_peakAmp;
	vector<int> OLDpulsesODHG_peakTime_ns;
	vector<int> OLDpulsesODHG_areaFractionTime1_ns;
	vector<int> OLDpulsesODHG_areaFractionTime5_ns;
	vector<int> OLDpulsesODHG_areaFractionTime10_ns;
	vector<int> OLDpulsesODHG_areaFractionTime25_ns;
	vector<int> OLDpulsesODHG_areaFractionTime50_ns;
	vector<int> OLDpulsesODHG_areaFractionTime75_ns;
	vector<int> OLDpulsesODHG_areaFractionTime90_ns;
	vector<int> OLDpulsesODHG_areaFractionTime95_ns;
	vector<int> OLDpulsesODHG_areaFractionTime99_ns;
	vector<float> OLDpulsesODHG_pulseAreaNeg50ns_phd;
	vector<float> OLDpulsesODHG_pulseArea50ns_phd;
	vector<float> OLDpulsesODHG_pulseArea100ns_phd;
	vector<float> OLDpulsesODHG_pulseArea200ns_phd;
	vector<float> OLDpulsesODHG_pulseArea500ns_phd;
	vector<float> OLDpulsesODHG_pulseArea1us_phd;
	vector<float> OLDpulsesODHG_pulseArea2us_phd;
	vector<float> OLDpulsesODHG_pulseArea5us_phd;
	vector<float> OLDpulsesODHG_promptFraction50ns;
	vector<int> OLDpulsesODHG_rmsWidth_ns;
	vector<int> OLDpulsesODHG_fwhm_ns;
	vector<float> OLDpulsesODHG_topArea_phd;
	vector<float> OLDpulsesODHG_bottomArea_phd;
	vector<float> OLDpulsesODHG_topBottomAsymmetry;
	vector<int> OLDpulsesODHG_coincidence;
	vector<float> OLDpulsesODHG_s1Probability;
	vector<float> OLDpulsesODHG_s2Probability;
	vector<float> OLDpulsesODHG_singlePEprobability;
	vector<float> OLDpulsesODHG_multiplePEprobability;
	vector<float> OLDpulsesODHG_singleElectronProbability;
	vector<float> OLDpulsesODHG_otherProbability;
	vector<float> OLDpulsesODHG_otherS2Probability;
	vector<int> OLDpulsesODHG_photonCount;
	vector<int> OLDpulsesODHG_topPhotonCount;
	vector<int> OLDpulsesODHG_bottomPhotonCount;
	vector<float> OLDpulsesODHG_s2Xposition_cm;
	vector<float> OLDpulsesODHG_s2Yposition_cm;
	vector<int> OLDpulsesODHG_HGLGpulseID;
	vector<vector<int>> OLDpulsesODHG_chID;
	vector<vector<float>> OLDpulsesODHG_chPulseArea_phd;
	vector<vector<float>> OLDpulsesODHG_chPeakAmp;
	vector<vector<int>> OLDpulsesODHG_chPeakTime_ns;
	vector<vector<bool>> OLDpulsesODHG_chSaturated;
	vector<vector<int>> OLDpulsesODHG_chPhotonCount;
	vector<vector<vector<int>>> OLDpulsesODHG_chPhotonTimes;
	// RQ::DetectorPulses *OLDpulsesODLG_;
	UInt_t OLDpulsesODLG_TObject_fUniqueID;
	UInt_t OLDpulsesODLG_TObject_fBits;
	Int_t OLDpulsesODLG_nPulses;
	vector<int> OLDpulsesODLG_pulseID;
	vector<int> OLDpulsesODLG_pulseStartTime_ns;
	vector<int> OLDpulsesODLG_pulseEndTime_ns;
	vector<bool> OLDpulsesODLG_saturated;
	vector<int> OLDpulsesODLG_nSaturatedChannels;
	vector<vector<unsigned int>> OLDpulsesODLG_saturatedChannelIDs;
	vector<float> OLDpulsesODLG_pulseArea_phd;
	vector<float> OLDpulsesODLG_positiveArea_phd;
	vector<float> OLDpulsesODLG_negativeArea_phd;
	vector<float> OLDpulsesODLG_peakAmp;
	vector<int> OLDpulsesODLG_peakTime_ns;
	vector<int> OLDpulsesODLG_areaFractionTime1_ns;
	vector<int> OLDpulsesODLG_areaFractionTime5_ns;
	vector<int> OLDpulsesODLG_areaFractionTime10_ns;
	vector<int> OLDpulsesODLG_areaFractionTime25_ns;
	vector<int> OLDpulsesODLG_areaFractionTime50_ns;
	vector<int> OLDpulsesODLG_areaFractionTime75_ns;
	vector<int> OLDpulsesODLG_areaFractionTime90_ns;
	vector<int> OLDpulsesODLG_areaFractionTime95_ns;
	vector<int> OLDpulsesODLG_areaFractionTime99_ns;
	vector<float> OLDpulsesODLG_pulseAreaNeg50ns_phd;
	vector<float> OLDpulsesODLG_pulseArea50ns_phd;
	vector<float> OLDpulsesODLG_pulseArea100ns_phd;
	vector<float> OLDpulsesODLG_pulseArea200ns_phd;
	vector<float> OLDpulsesODLG_pulseArea500ns_phd;
	vector<float> OLDpulsesODLG_pulseArea1us_phd;
	vector<float> OLDpulsesODLG_pulseArea2us_phd;
	vector<float> OLDpulsesODLG_pulseArea5us_phd;
	vector<float> OLDpulsesODLG_promptFraction50ns;
	vector<int> OLDpulsesODLG_rmsWidth_ns;
	vector<int> OLDpulsesODLG_fwhm_ns;
	vector<float> OLDpulsesODLG_topArea_phd;
	vector<float> OLDpulsesODLG_bottomArea_phd;
	vector<float> OLDpulsesODLG_topBottomAsymmetry;
	vector<int> OLDpulsesODLG_coincidence;
	vector<float> OLDpulsesODLG_s1Probability;
	vector<float> OLDpulsesODLG_s2Probability;
	vector<float> OLDpulsesODLG_singlePEprobability;
	vector<float> OLDpulsesODLG_multiplePEprobability;
	vector<float> OLDpulsesODLG_singleElectronProbability;
	vector<float> OLDpulsesODLG_otherProbability;
	vector<float> OLDpulsesODLG_otherS2Probability;
	vector<int> OLDpulsesODLG_photonCount;
	vector<int> OLDpulsesODLG_topPhotonCount;
	vector<int> OLDpulsesODLG_bottomPhotonCount;
	vector<float> OLDpulsesODLG_s2Xposition_cm;
	vector<float> OLDpulsesODLG_s2Yposition_cm;
	vector<int> OLDpulsesODLG_HGLGpulseID;
	vector<vector<int>> OLDpulsesODLG_chID;
	vector<vector<float>> OLDpulsesODLG_chPulseArea_phd;
	vector<vector<float>> OLDpulsesODLG_chPeakAmp;
	vector<vector<int>> OLDpulsesODLG_chPeakTime_ns;
	vector<vector<bool>> OLDpulsesODLG_chSaturated;
	vector<vector<int>> OLDpulsesODLG_chPhotonCount;
	vector<vector<vector<int>>> OLDpulsesODLG_chPhotonTimes;
	// RQ::ODPulses    *pulsesODHG_;
	UInt_t pulsesODHG_TObject_fUniqueID;
	UInt_t pulsesODHG_TObject_fBits;
	Int_t pulsesODHG_nPulses;
	Int_t pulsesODHG_maxCoincidence;
	vector<int> pulsesODHG_pulseID;
	vector<int> pulsesODHG_pulseStartTime_ns;
	vector<int> pulsesODHG_pulseEndTime_ns;
	vector<bool> pulsesODHG_saturated;
	vector<int> pulsesODHG_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesODHG_saturatedChannelIDs;
	vector<float> pulsesODHG_pulseArea_phd;
	vector<float> pulsesODHG_positiveArea_phd;
	vector<float> pulsesODHG_negativeArea_phd;
	vector<float> pulsesODHG_peakAmp;
	vector<int> pulsesODHG_peakTime_ns;
	vector<int> pulsesODHG_areaFractionTime1_ns;
	vector<int> pulsesODHG_areaFractionTime5_ns;
	vector<int> pulsesODHG_areaFractionTime10_ns;
	vector<int> pulsesODHG_areaFractionTime25_ns;
	vector<int> pulsesODHG_areaFractionTime50_ns;
	vector<int> pulsesODHG_areaFractionTime75_ns;
	vector<int> pulsesODHG_areaFractionTime90_ns;
	vector<int> pulsesODHG_areaFractionTime95_ns;
	vector<int> pulsesODHG_areaFractionTime99_ns;
	vector<int> pulsesODHG_promptFraction200ns;
	vector<float> pulsesODHG_promptFraction50ns;
	vector<int> pulsesODHG_rmsWidth_ns;
	vector<int> pulsesODHG_fwhm_ns;
	vector<int> pulsesODHG_coincidence;
	vector<float> pulsesODHG_pulseZPosition;
	vector<float> pulsesODHG_pulsePhiPosition;
	vector<float> pulsesODHG_pulseTheta;
	vector<vector<float>> pulsesODHG_pulseWaveform;
	vector<vector<int>> pulsesODHG_chID;
	vector<vector<float>> pulsesODHG_chPulseArea_phd;
	vector<vector<float>> pulsesODHG_chPeakAmp;
	vector<vector<int>> pulsesODHG_chPeakTime_ns;
	vector<vector<bool>> pulsesODHG_chSaturated;
	vector<vector<int>> pulsesODHG_chPhotonCount;
	vector<vector<float>> pulsesODHG_chZPosition;
	vector<vector<float>> pulsesODHG_chPhiPosition;
	// RQ::ODPulses    *pulsesODLG_;
	UInt_t pulsesODLG_TObject_fUniqueID;
	UInt_t pulsesODLG_TObject_fBits;
	Int_t pulsesODLG_nPulses;
	Int_t pulsesODLG_maxCoincidence;
	vector<int> pulsesODLG_pulseID;
	vector<int> pulsesODLG_pulseStartTime_ns;
	vector<int> pulsesODLG_pulseEndTime_ns;
	vector<bool> pulsesODLG_saturated;
	vector<int> pulsesODLG_nSaturatedChannels;
	vector<vector<unsigned int>> pulsesODLG_saturatedChannelIDs;
	vector<float> pulsesODLG_pulseArea_phd;
	vector<float> pulsesODLG_positiveArea_phd;
	vector<float> pulsesODLG_negativeArea_phd;
	vector<float> pulsesODLG_peakAmp;
	vector<int> pulsesODLG_peakTime_ns;
	vector<int> pulsesODLG_areaFractionTime1_ns;
	vector<int> pulsesODLG_areaFractionTime5_ns;
	vector<int> pulsesODLG_areaFractionTime10_ns;
	vector<int> pulsesODLG_areaFractionTime25_ns;
	vector<int> pulsesODLG_areaFractionTime50_ns;
	vector<int> pulsesODLG_areaFractionTime75_ns;
	vector<int> pulsesODLG_areaFractionTime90_ns;
	vector<int> pulsesODLG_areaFractionTime95_ns;
	vector<int> pulsesODLG_areaFractionTime99_ns;
	vector<int> pulsesODLG_promptFraction200ns;
	vector<float> pulsesODLG_promptFraction50ns;
	vector<int> pulsesODLG_rmsWidth_ns;
	vector<int> pulsesODLG_fwhm_ns;
	vector<int> pulsesODLG_coincidence;
	vector<float> pulsesODLG_pulseZPosition;
	vector<float> pulsesODLG_pulsePhiPosition;
	vector<float> pulsesODLG_pulseTheta;
	vector<vector<float>> pulsesODLG_pulseWaveform;
	vector<vector<int>> pulsesODLG_chID;
	vector<vector<float>> pulsesODLG_chPulseArea_phd;
	vector<vector<float>> pulsesODLG_chPeakAmp;
	vector<vector<int>> pulsesODLG_chPeakTime_ns;
	vector<vector<bool>> pulsesODLG_chSaturated;
	vector<vector<int>> pulsesODLG_chPhotonCount;
	vector<vector<float>> pulsesODLG_chZPosition;
	vector<vector<float>> pulsesODLG_chPhiPosition;
	// RQ::SingleScatters *singleScatters_;
	UInt_t singleScatters_TObject_fUniqueID;
	UInt_t singleScatters_TObject_fBits;
	Int_t singleScatters_nSingleScatters;
	vector<int> singleScatters_s1PulseID;
	vector<bool> singleScatters_s1IsHG;
	vector<int> singleScatters_s2PulseID;
	vector<bool> singleScatters_s2IsHG;
	vector<float> singleScatters_driftTime_ns;
	vector<float> singleScatters_s1Area_phd;
	vector<float> singleScatters_s2Area_phd;
	vector<float> singleScatters_s1TopArea_phd;
	vector<float> singleScatters_s1BottomArea_phd;
	vector<float> singleScatters_s1TopCorrectionFactor;
	vector<float> singleScatters_s1BottomCorrectionFactor;
	vector<float> singleScatters_correctedS1TopArea_phd;
	vector<float> singleScatters_correctedS1BottomArea_phd;
	vector<float> singleScatters_correctedS1Area_phd;
	vector<float> singleScatters_s2CorrectionFactor;
	vector<float> singleScatters_correctedS2Area_phd;
	vector<float> singleScatters_x_cm;
	vector<float> singleScatters_y_cm;
	vector<float> singleScatters_xyChi2;
	vector<float> singleScatters_correctedX_cm;
	vector<float> singleScatters_correctedY_cm;
	vector<float> singleScatters_correctedZ_cm;
	vector<float> singleScatters_s1PhotonCount;
	vector<float> singleScatters_correctedS1PhotonCount;
	vector<float> singleScatters_energyER_keV;
	vector<float> singleScatters_energyNR_keV;
	vector<float> singleScatters_skinPromptArea;
	vector<int> singleScatters_nSkinPromptPulses;
	vector<vector<int>> singleScatters_skinPromptPulseIDs;
	vector<float> singleScatters_odPromptArea;
	vector<int> singleScatters_nODPromptPulses;
	vector<vector<int>> singleScatters_odPromptPulseIDs;
	vector<vector<float>> singleScatters_odDelayedAreas;
	vector<int> singleScatters_nODDelayedPulses;
	vector<vector<int>> singleScatters_odDelayedPulseIDs;
	// RQ::MultipleScatters *multipleScatters_;
	UInt_t multipleScatters_TObject_fUniqueID;
	UInt_t multipleScatters_TObject_fBits;
	Int_t multipleScatters_nMultipleScatters;
	vector<int> multipleScatters_s1PulseID;
	vector<bool> multipleScatters_s1IsHG;
	vector<float> multipleScatters_s1Area_phd;
	vector<float> multipleScatters_s1TopArea_phd;
	vector<float> multipleScatters_s1BottomArea_phd;
	vector<int> multipleScatters_nS2s;
	vector<vector<int>> multipleScatters_s2PulseIDs;
	vector<vector<bool>> multipleScatters_s2IsHG;
	vector<vector<float>> multipleScatters_s2Area_phd;
	vector<vector<float>> multipleScatters_s1TopCorrectionFactors;
	vector<vector<float>> multipleScatters_s1BottomCorrectionFactors;
	vector<vector<float>> multipleScatters_correctedS1TopAreas_phd;
	vector<vector<float>> multipleScatters_correctedS1BottomAreas_phd;
	vector<vector<float>> multipleScatters_correctedS1Areas_phd;
	vector<vector<float>> multipleScatters_s2CorrectionFactors;
	vector<vector<float>> multipleScatters_correctedS2Area_phd;
	vector<vector<float>> multipleScatters_driftTime_ns;
	vector<float> multipleScatters_weightedDriftTime_ns;
	vector<vector<float>> multipleScatters_x_cm;
	vector<vector<float>> multipleScatters_y_cm;
	vector<vector<float>> multipleScatters_correctedX_cm;
	vector<vector<float>> multipleScatters_correctedY_cm;
	vector<vector<float>> multipleScatters_correctedZ_cm;
	vector<float> multipleScatters_energyER_keV;
	vector<float> multipleScatters_energyNR_keV;
	// RQ::Kr83mScatters *kr83mScatters_;
	UInt_t kr83mScatters_TObject_fUniqueID;
	UInt_t kr83mScatters_TObject_fBits;
	Int_t kr83mScatters_nKr83mScatters;
	vector<int> kr83mScatters_s1aPulseID;
	vector<float> kr83mScatters_s1aArea_phd;
	vector<int> kr83mScatters_s1bPulseID;
	vector<float> kr83mScatters_s1bArea_phd;
	vector<int> kr83mScatters_s2PulseID;
	vector<float> kr83mScatters_s2Area_phd;
	vector<float> kr83mScatters_driftTime_ns;
	vector<float> kr83mScatters_x_cm;
	vector<float> kr83mScatters_y_cm;
	vector<float> kr83mScatters_correctedX_cm;
	vector<float> kr83mScatters_correctedY_cm;
	vector<float> kr83mScatters_correctedZ_cm;
	vector<float> kr83mScatters_energy_keV;
	// RQ::OtherScatters *otherScatters_;
	UInt_t otherScatters_TObject_fUniqueID;
	UInt_t otherScatters_TObject_fBits;
	Int_t otherScatters_nOtherScatters;
	vector<int> otherScatters_nS1s;
	vector<vector<int>> otherScatters_s1PulseIDs;
	vector<int> otherScatters_nS2s;
	vector<vector<int>> otherScatters_s2PulseIDs;
	vector<int> otherScatters_nSPEs;
	vector<vector<int>> otherScatters_spePulseIDs;
	vector<int> otherScatters_nSEs;
	vector<vector<int>> otherScatters_sePulseIDs;
	vector<int> otherScatters_nOthers;
	vector<vector<int>> otherScatters_otherPulseIDs;
	// RQ::PileUpScatters *pileUpScatters_;
	UInt_t pileUpScatters_TObject_fUniqueID;
	UInt_t pileUpScatters_TObject_fBits;
	Int_t pileUpScatters_nPileUpScatters;
	vector<int> pileUpScatters_nS1;
	vector<vector<int>> pileUpScatters_s1PulseIDs;
	vector<int> pileUpScatters_nS2;
	vector<vector<int>> pileUpScatters_s2PulseIDs;

	// List of branches
	TBranch* b_eventHeader_TObject_fUniqueID; //!
	TBranch* b_eventHeader_TObject_fBits; //!
	TBranch* b_eventHeader_runID; //!
	TBranch* b_eventHeader_eventID; //!
	TBranch* b_eventHeader_rawFileName; //!
	TBranch* b_eventHeader_triggerTimeStamp_s; //!
	TBranch* b_eventHeader_triggerTimeStamp_ns; //!
	TBranch* b_pulsesTPC_TObject_fUniqueID; //!
	TBranch* b_pulsesTPC_TObject_fBits; //!
	TBranch* b_pulsesTPC_nPulses; //!
	TBranch* b_pulsesTPC_pulseID; //!
	TBranch* b_pulsesTPC_pulseStartTime_ns; //!
	TBranch* b_pulsesTPC_pulseEndTime_ns; //!
	TBranch* b_pulsesTPC_saturated; //!
	TBranch* b_pulsesTPC_nSaturatedChannels; //!
	TBranch* b_pulsesTPC_saturatedChannelIDs; //!
	TBranch* b_pulsesTPC_pulseArea_phd; //!
	TBranch* b_pulsesTPC_positiveArea_phd; //!
	TBranch* b_pulsesTPC_negativeArea_phd; //!
	TBranch* b_pulsesTPC_peakAmp; //!
	TBranch* b_pulsesTPC_peakTime_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime1_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime5_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime10_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime25_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime50_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime75_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime90_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime95_ns; //!
	TBranch* b_pulsesTPC_areaFractionTime99_ns; //!
	TBranch* b_pulsesTPC_pulseAreaNeg50ns_phd; //!
	TBranch* b_pulsesTPC_pulseArea50ns_phd; //!
	TBranch* b_pulsesTPC_pulseArea100ns_phd; //!
	TBranch* b_pulsesTPC_pulseArea200ns_phd; //!
	TBranch* b_pulsesTPC_pulseArea500ns_phd; //!
	TBranch* b_pulsesTPC_pulseArea1us_phd; //!
	TBranch* b_pulsesTPC_pulseArea2us_phd; //!
	TBranch* b_pulsesTPC_pulseArea5us_phd; //!
	TBranch* b_pulsesTPC_promptFraction50ns; //!
	TBranch* b_pulsesTPC_rmsWidth_ns; //!
	TBranch* b_pulsesTPC_fwhm_ns; //!
	TBranch* b_pulsesTPC_topArea_phd; //!
	TBranch* b_pulsesTPC_bottomArea_phd; //!
	TBranch* b_pulsesTPC_topBottomAsymmetry; //!
	TBranch* b_pulsesTPC_coincidence; //!
	TBranch* b_pulsesTPC_s1Probability; //!
	TBranch* b_pulsesTPC_s2Probability; //!
	TBranch* b_pulsesTPC_singlePEprobability; //!
	TBranch* b_pulsesTPC_multiplePEprobability; //!
	TBranch* b_pulsesTPC_singleElectronProbability; //!
	TBranch* b_pulsesTPC_otherProbability; //!
	TBranch* b_pulsesTPC_otherS2Probability; //!
	TBranch* b_pulsesTPC_photonCount; //!
	TBranch* b_pulsesTPC_topPhotonCount; //!
	TBranch* b_pulsesTPC_bottomPhotonCount; //!
	TBranch* b_pulsesTPC_s2Xposition_cm; //!
	TBranch* b_pulsesTPC_s2Yposition_cm; //!
	TBranch* b_pulsesTPC_HGLGpulseID; //!
	TBranch* b_pulsesTPC_chID; //!
	TBranch* b_pulsesTPC_chPulseArea_phd; //!
	TBranch* b_pulsesTPC_chPeakAmp; //!
	TBranch* b_pulsesTPC_chPeakTime_ns; //!
	TBranch* b_pulsesTPC_chSaturated; //!
	TBranch* b_pulsesTPC_chPhotonCount; //!
	TBranch* b_pulsesTPC_chPhotonTimes; //!
	TBranch* b_pulsesTPCHG_TObject_fUniqueID; //!
	TBranch* b_pulsesTPCHG_TObject_fBits; //!
	TBranch* b_pulsesTPCHG_nPulses; //!
	TBranch* b_pulsesTPCHG_pulseID; //!
	TBranch* b_pulsesTPCHG_pulseStartTime_ns; //!
	TBranch* b_pulsesTPCHG_pulseEndTime_ns; //!
	TBranch* b_pulsesTPCHG_saturated; //!
	TBranch* b_pulsesTPCHG_nSaturatedChannels; //!
	TBranch* b_pulsesTPCHG_saturatedChannelIDs; //!
	TBranch* b_pulsesTPCHG_pulseArea_phd; //!
	TBranch* b_pulsesTPCHG_positiveArea_phd; //!
	TBranch* b_pulsesTPCHG_negativeArea_phd; //!
	TBranch* b_pulsesTPCHG_peakAmp; //!
	TBranch* b_pulsesTPCHG_peakTime_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime1_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime5_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime10_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime25_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime50_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime75_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime90_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime95_ns; //!
	TBranch* b_pulsesTPCHG_areaFractionTime99_ns; //!
	TBranch* b_pulsesTPCHG_pulseAreaNeg50ns_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea50ns_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea100ns_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea200ns_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea500ns_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea1us_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea2us_phd; //!
	TBranch* b_pulsesTPCHG_pulseArea5us_phd; //!
	TBranch* b_pulsesTPCHG_promptFraction50ns; //!
	TBranch* b_pulsesTPCHG_rmsWidth_ns; //!
	TBranch* b_pulsesTPCHG_fwhm_ns; //!
	TBranch* b_pulsesTPCHG_topArea_phd; //!
	TBranch* b_pulsesTPCHG_bottomArea_phd; //!
	TBranch* b_pulsesTPCHG_topBottomAsymmetry; //!
	TBranch* b_pulsesTPCHG_coincidence; //!
	TBranch* b_pulsesTPCHG_s1Probability; //!
	TBranch* b_pulsesTPCHG_s2Probability; //!
	TBranch* b_pulsesTPCHG_singlePEprobability; //!
	TBranch* b_pulsesTPCHG_multiplePEprobability; //!
	TBranch* b_pulsesTPCHG_singleElectronProbability; //!
	TBranch* b_pulsesTPCHG_otherProbability; //!
	TBranch* b_pulsesTPCHG_otherS2Probability; //!
	TBranch* b_pulsesTPCHG_photonCount; //!
	TBranch* b_pulsesTPCHG_topPhotonCount; //!
	TBranch* b_pulsesTPCHG_bottomPhotonCount; //!
	TBranch* b_pulsesTPCHG_s2Xposition_cm; //!
	TBranch* b_pulsesTPCHG_s2Yposition_cm; //!
	TBranch* b_pulsesTPCHG_HGLGpulseID; //!
	TBranch* b_pulsesTPCHG_chID; //!
	TBranch* b_pulsesTPCHG_chPulseArea_phd; //!
	TBranch* b_pulsesTPCHG_chPeakAmp; //!
	TBranch* b_pulsesTPCHG_chPeakTime_ns; //!
	TBranch* b_pulsesTPCHG_chSaturated; //!
	TBranch* b_pulsesTPCHG_chPhotonCount; //!
	TBranch* b_pulsesTPCHG_chPhotonTimes; //!
	TBranch* b_pulsesTPCLG_TObject_fUniqueID; //!
	TBranch* b_pulsesTPCLG_TObject_fBits; //!
	TBranch* b_pulsesTPCLG_nPulses; //!
	TBranch* b_pulsesTPCLG_pulseID; //!
	TBranch* b_pulsesTPCLG_pulseStartTime_ns; //!
	TBranch* b_pulsesTPCLG_pulseEndTime_ns; //!
	TBranch* b_pulsesTPCLG_saturated; //!
	TBranch* b_pulsesTPCLG_nSaturatedChannels; //!
	TBranch* b_pulsesTPCLG_saturatedChannelIDs; //!
	TBranch* b_pulsesTPCLG_pulseArea_phd; //!
	TBranch* b_pulsesTPCLG_positiveArea_phd; //!
	TBranch* b_pulsesTPCLG_negativeArea_phd; //!
	TBranch* b_pulsesTPCLG_peakAmp; //!
	TBranch* b_pulsesTPCLG_peakTime_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime1_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime5_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime10_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime25_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime50_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime75_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime90_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime95_ns; //!
	TBranch* b_pulsesTPCLG_areaFractionTime99_ns; //!
	TBranch* b_pulsesTPCLG_pulseAreaNeg50ns_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea50ns_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea100ns_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea200ns_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea500ns_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea1us_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea2us_phd; //!
	TBranch* b_pulsesTPCLG_pulseArea5us_phd; //!
	TBranch* b_pulsesTPCLG_promptFraction50ns; //!
	TBranch* b_pulsesTPCLG_rmsWidth_ns; //!
	TBranch* b_pulsesTPCLG_fwhm_ns; //!
	TBranch* b_pulsesTPCLG_topArea_phd; //!
	TBranch* b_pulsesTPCLG_bottomArea_phd; //!
	TBranch* b_pulsesTPCLG_topBottomAsymmetry; //!
	TBranch* b_pulsesTPCLG_coincidence; //!
	TBranch* b_pulsesTPCLG_s1Probability; //!
	TBranch* b_pulsesTPCLG_s2Probability; //!
	TBranch* b_pulsesTPCLG_singlePEprobability; //!
	TBranch* b_pulsesTPCLG_multiplePEprobability; //!
	TBranch* b_pulsesTPCLG_singleElectronProbability; //!
	TBranch* b_pulsesTPCLG_otherProbability; //!
	TBranch* b_pulsesTPCLG_otherS2Probability; //!
	TBranch* b_pulsesTPCLG_photonCount; //!
	TBranch* b_pulsesTPCLG_topPhotonCount; //!
	TBranch* b_pulsesTPCLG_bottomPhotonCount; //!
	TBranch* b_pulsesTPCLG_s2Xposition_cm; //!
	TBranch* b_pulsesTPCLG_s2Yposition_cm; //!
	TBranch* b_pulsesTPCLG_HGLGpulseID; //!
	TBranch* b_pulsesTPCLG_chID; //!
	TBranch* b_pulsesTPCLG_chPulseArea_phd; //!
	TBranch* b_pulsesTPCLG_chPeakAmp; //!
	TBranch* b_pulsesTPCLG_chPeakTime_ns; //!
	TBranch* b_pulsesTPCLG_chSaturated; //!
	TBranch* b_pulsesTPCLG_chPhotonCount; //!
	TBranch* b_pulsesTPCLG_chPhotonTimes; //!
	TBranch* b_pulsesSkin_TObject_fUniqueID; //!
	TBranch* b_pulsesSkin_TObject_fBits; //!
	TBranch* b_pulsesSkin_nPulses; //!
	TBranch* b_pulsesSkin_pulseID; //!
	TBranch* b_pulsesSkin_pulseStartTime_ns; //!
	TBranch* b_pulsesSkin_pulseEndTime_ns; //!
	TBranch* b_pulsesSkin_saturated; //!
	TBranch* b_pulsesSkin_nSaturatedChannels; //!
	TBranch* b_pulsesSkin_saturatedChannelIDs; //!
	TBranch* b_pulsesSkin_pulseArea_phd; //!
	TBranch* b_pulsesSkin_positiveArea_phd; //!
	TBranch* b_pulsesSkin_negativeArea_phd; //!
	TBranch* b_pulsesSkin_peakAmp; //!
	TBranch* b_pulsesSkin_peakTime_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime1_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime5_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime10_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime25_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime50_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime75_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime90_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime95_ns; //!
	TBranch* b_pulsesSkin_areaFractionTime99_ns; //!
	TBranch* b_pulsesSkin_pulseAreaNeg50ns_phd; //!
	TBranch* b_pulsesSkin_pulseArea50ns_phd; //!
	TBranch* b_pulsesSkin_pulseArea100ns_phd; //!
	TBranch* b_pulsesSkin_pulseArea200ns_phd; //!
	TBranch* b_pulsesSkin_pulseArea500ns_phd; //!
	TBranch* b_pulsesSkin_pulseArea1us_phd; //!
	TBranch* b_pulsesSkin_pulseArea2us_phd; //!
	TBranch* b_pulsesSkin_pulseArea5us_phd; //!
	TBranch* b_pulsesSkin_promptFraction50ns; //!
	TBranch* b_pulsesSkin_rmsWidth_ns; //!
	TBranch* b_pulsesSkin_fwhm_ns; //!
	TBranch* b_pulsesSkin_topArea_phd; //!
	TBranch* b_pulsesSkin_bottomArea_phd; //!
	TBranch* b_pulsesSkin_topBottomAsymmetry; //!
	TBranch* b_pulsesSkin_coincidence; //!
	TBranch* b_pulsesSkin_s1Probability; //!
	TBranch* b_pulsesSkin_s2Probability; //!
	TBranch* b_pulsesSkin_singlePEprobability; //!
	TBranch* b_pulsesSkin_multiplePEprobability; //!
	TBranch* b_pulsesSkin_singleElectronProbability; //!
	TBranch* b_pulsesSkin_otherProbability; //!
	TBranch* b_pulsesSkin_otherS2Probability; //!
	TBranch* b_pulsesSkin_photonCount; //!
	TBranch* b_pulsesSkin_topPhotonCount; //!
	TBranch* b_pulsesSkin_bottomPhotonCount; //!
	TBranch* b_pulsesSkin_s2Xposition_cm; //!
	TBranch* b_pulsesSkin_s2Yposition_cm; //!
	TBranch* b_pulsesSkin_HGLGpulseID; //!
	TBranch* b_pulsesSkin_chID; //!
	TBranch* b_pulsesSkin_chPulseArea_phd; //!
	TBranch* b_pulsesSkin_chPeakAmp; //!
	TBranch* b_pulsesSkin_chPeakTime_ns; //!
	TBranch* b_pulsesSkin_chSaturated; //!
	TBranch* b_pulsesSkin_chPhotonCount; //!
	TBranch* b_pulsesSkin_chPhotonTimes; //!
	TBranch* b_OLDpulsesODHG_TObject_fUniqueID; //!
	TBranch* b_OLDpulsesODHG_TObject_fBits; //!
	TBranch* b_OLDpulsesODHG_nPulses; //!
	TBranch* b_OLDpulsesODHG_pulseID; //!
	TBranch* b_OLDpulsesODHG_pulseStartTime_ns; //!
	TBranch* b_OLDpulsesODHG_pulseEndTime_ns; //!
	TBranch* b_OLDpulsesODHG_saturated; //!
	TBranch* b_OLDpulsesODHG_nSaturatedChannels; //!
	TBranch* b_OLDpulsesODHG_saturatedChannelIDs; //!
	TBranch* b_OLDpulsesODHG_pulseArea_phd; //!
	TBranch* b_OLDpulsesODHG_positiveArea_phd; //!
	TBranch* b_OLDpulsesODHG_negativeArea_phd; //!
	TBranch* b_OLDpulsesODHG_peakAmp; //!
	TBranch* b_OLDpulsesODHG_peakTime_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime1_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime5_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime10_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime25_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime50_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime75_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime90_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime95_ns; //!
	TBranch* b_OLDpulsesODHG_areaFractionTime99_ns; //!
	TBranch* b_OLDpulsesODHG_pulseAreaNeg50ns_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea50ns_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea100ns_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea200ns_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea500ns_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea1us_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea2us_phd; //!
	TBranch* b_OLDpulsesODHG_pulseArea5us_phd; //!
	TBranch* b_OLDpulsesODHG_promptFraction50ns; //!
	TBranch* b_OLDpulsesODHG_rmsWidth_ns; //!
	TBranch* b_OLDpulsesODHG_fwhm_ns; //!
	TBranch* b_OLDpulsesODHG_topArea_phd; //!
	TBranch* b_OLDpulsesODHG_bottomArea_phd; //!
	TBranch* b_OLDpulsesODHG_topBottomAsymmetry; //!
	TBranch* b_OLDpulsesODHG_coincidence; //!
	TBranch* b_OLDpulsesODHG_s1Probability; //!
	TBranch* b_OLDpulsesODHG_s2Probability; //!
	TBranch* b_OLDpulsesODHG_singlePEprobability; //!
	TBranch* b_OLDpulsesODHG_multiplePEprobability; //!
	TBranch* b_OLDpulsesODHG_singleElectronProbability; //!
	TBranch* b_OLDpulsesODHG_otherProbability; //!
	TBranch* b_OLDpulsesODHG_otherS2Probability; //!
	TBranch* b_OLDpulsesODHG_photonCount; //!
	TBranch* b_OLDpulsesODHG_topPhotonCount; //!
	TBranch* b_OLDpulsesODHG_bottomPhotonCount; //!
	TBranch* b_OLDpulsesODHG_s2Xposition_cm; //!
	TBranch* b_OLDpulsesODHG_s2Yposition_cm; //!
	TBranch* b_OLDpulsesODHG_HGLGpulseID; //!
	TBranch* b_OLDpulsesODHG_chID; //!
	TBranch* b_OLDpulsesODHG_chPulseArea_phd; //!
	TBranch* b_OLDpulsesODHG_chPeakAmp; //!
	TBranch* b_OLDpulsesODHG_chPeakTime_ns; //!
	TBranch* b_OLDpulsesODHG_chSaturated; //!
	TBranch* b_OLDpulsesODHG_chPhotonCount; //!
	TBranch* b_OLDpulsesODHG_chPhotonTimes; //!
	TBranch* b_OLDpulsesODLG_TObject_fUniqueID; //!
	TBranch* b_OLDpulsesODLG_TObject_fBits; //!
	TBranch* b_OLDpulsesODLG_nPulses; //!
	TBranch* b_OLDpulsesODLG_pulseID; //!
	TBranch* b_OLDpulsesODLG_pulseStartTime_ns; //!
	TBranch* b_OLDpulsesODLG_pulseEndTime_ns; //!
	TBranch* b_OLDpulsesODLG_saturated; //!
	TBranch* b_OLDpulsesODLG_nSaturatedChannels; //!
	TBranch* b_OLDpulsesODLG_saturatedChannelIDs; //!
	TBranch* b_OLDpulsesODLG_pulseArea_phd; //!
	TBranch* b_OLDpulsesODLG_positiveArea_phd; //!
	TBranch* b_OLDpulsesODLG_negativeArea_phd; //!
	TBranch* b_OLDpulsesODLG_peakAmp; //!
	TBranch* b_OLDpulsesODLG_peakTime_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime1_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime5_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime10_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime25_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime50_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime75_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime90_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime95_ns; //!
	TBranch* b_OLDpulsesODLG_areaFractionTime99_ns; //!
	TBranch* b_OLDpulsesODLG_pulseAreaNeg50ns_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea50ns_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea100ns_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea200ns_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea500ns_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea1us_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea2us_phd; //!
	TBranch* b_OLDpulsesODLG_pulseArea5us_phd; //!
	TBranch* b_OLDpulsesODLG_promptFraction50ns; //!
	TBranch* b_OLDpulsesODLG_rmsWidth_ns; //!
	TBranch* b_OLDpulsesODLG_fwhm_ns; //!
	TBranch* b_OLDpulsesODLG_topArea_phd; //!
	TBranch* b_OLDpulsesODLG_bottomArea_phd; //!
	TBranch* b_OLDpulsesODLG_topBottomAsymmetry; //!
	TBranch* b_OLDpulsesODLG_coincidence; //!
	TBranch* b_OLDpulsesODLG_s1Probability; //!
	TBranch* b_OLDpulsesODLG_s2Probability; //!
	TBranch* b_OLDpulsesODLG_singlePEprobability; //!
	TBranch* b_OLDpulsesODLG_multiplePEprobability; //!
	TBranch* b_OLDpulsesODLG_singleElectronProbability; //!
	TBranch* b_OLDpulsesODLG_otherProbability; //!
	TBranch* b_OLDpulsesODLG_otherS2Probability; //!
	TBranch* b_OLDpulsesODLG_photonCount; //!
	TBranch* b_OLDpulsesODLG_topPhotonCount; //!
	TBranch* b_OLDpulsesODLG_bottomPhotonCount; //!
	TBranch* b_OLDpulsesODLG_s2Xposition_cm; //!
	TBranch* b_OLDpulsesODLG_s2Yposition_cm; //!
	TBranch* b_OLDpulsesODLG_HGLGpulseID; //!
	TBranch* b_OLDpulsesODLG_chID; //!
	TBranch* b_OLDpulsesODLG_chPulseArea_phd; //!
	TBranch* b_OLDpulsesODLG_chPeakAmp; //!
	TBranch* b_OLDpulsesODLG_chPeakTime_ns; //!
	TBranch* b_OLDpulsesODLG_chSaturated; //!
	TBranch* b_OLDpulsesODLG_chPhotonCount; //!
	TBranch* b_OLDpulsesODLG_chPhotonTimes; //!
	TBranch* b_pulsesODHG_TObject_fUniqueID; //!
	TBranch* b_pulsesODHG_TObject_fBits; //!
	TBranch* b_pulsesODHG_nPulses; //!
	TBranch* b_pulsesODHG_maxCoincidence; //!
	TBranch* b_pulsesODHG_pulseID; //!
	TBranch* b_pulsesODHG_pulseStartTime_ns; //!
	TBranch* b_pulsesODHG_pulseEndTime_ns; //!
	TBranch* b_pulsesODHG_saturated; //!
	TBranch* b_pulsesODHG_nSaturatedChannels; //!
	TBranch* b_pulsesODHG_saturatedChannelIDs; //!
	TBranch* b_pulsesODHG_pulseArea_phd; //!
	TBranch* b_pulsesODHG_positiveArea_phd; //!
	TBranch* b_pulsesODHG_negativeArea_phd; //!
	TBranch* b_pulsesODHG_peakAmp; //!
	TBranch* b_pulsesODHG_peakTime_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime1_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime5_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime10_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime25_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime50_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime75_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime90_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime95_ns; //!
	TBranch* b_pulsesODHG_areaFractionTime99_ns; //!
	TBranch* b_pulsesODHG_promptFraction200ns; //!
	TBranch* b_pulsesODHG_promptFraction50ns; //!
	TBranch* b_pulsesODHG_rmsWidth_ns; //!
	TBranch* b_pulsesODHG_fwhm_ns; //!
	TBranch* b_pulsesODHG_coincidence; //!
	TBranch* b_pulsesODHG_pulseZPosition; //!
	TBranch* b_pulsesODHG_pulsePhiPosition; //!
	TBranch* b_pulsesODHG_pulseTheta; //!
	TBranch* b_pulsesODHG_pulseWaveform; //!
	TBranch* b_pulsesODHG_chID; //!
	TBranch* b_pulsesODHG_chPulseArea_phd; //!
	TBranch* b_pulsesODHG_chPeakAmp; //!
	TBranch* b_pulsesODHG_chPeakTime_ns; //!
	TBranch* b_pulsesODHG_chSaturated; //!
	TBranch* b_pulsesODHG_chPhotonCount; //!
	TBranch* b_pulsesODHG_chZPosition; //!
	TBranch* b_pulsesODHG_chPhiPosition; //!
	TBranch* b_pulsesODLG_TObject_fUniqueID; //!
	TBranch* b_pulsesODLG_TObject_fBits; //!
	TBranch* b_pulsesODLG_nPulses; //!
	TBranch* b_pulsesODLG_maxCoincidence; //!
	TBranch* b_pulsesODLG_pulseID; //!
	TBranch* b_pulsesODLG_pulseStartTime_ns; //!
	TBranch* b_pulsesODLG_pulseEndTime_ns; //!
	TBranch* b_pulsesODLG_saturated; //!
	TBranch* b_pulsesODLG_nSaturatedChannels; //!
	TBranch* b_pulsesODLG_saturatedChannelIDs; //!
	TBranch* b_pulsesODLG_pulseArea_phd; //!
	TBranch* b_pulsesODLG_positiveArea_phd; //!
	TBranch* b_pulsesODLG_negativeArea_phd; //!
	TBranch* b_pulsesODLG_peakAmp; //!
	TBranch* b_pulsesODLG_peakTime_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime1_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime5_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime10_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime25_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime50_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime75_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime90_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime95_ns; //!
	TBranch* b_pulsesODLG_areaFractionTime99_ns; //!
	TBranch* b_pulsesODLG_promptFraction200ns; //!
	TBranch* b_pulsesODLG_promptFraction50ns; //!
	TBranch* b_pulsesODLG_rmsWidth_ns; //!
	TBranch* b_pulsesODLG_fwhm_ns; //!
	TBranch* b_pulsesODLG_coincidence; //!
	TBranch* b_pulsesODLG_pulseZPosition; //!
	TBranch* b_pulsesODLG_pulsePhiPosition; //!
	TBranch* b_pulsesODLG_pulseTheta; //!
	TBranch* b_pulsesODLG_pulseWaveform; //!
	TBranch* b_pulsesODLG_chID; //!
	TBranch* b_pulsesODLG_chPulseArea_phd; //!
	TBranch* b_pulsesODLG_chPeakAmp; //!
	TBranch* b_pulsesODLG_chPeakTime_ns; //!
	TBranch* b_pulsesODLG_chSaturated; //!
	TBranch* b_pulsesODLG_chPhotonCount; //!
	TBranch* b_pulsesODLG_chZPosition; //!
	TBranch* b_pulsesODLG_chPhiPosition; //!
	TBranch* b_singleScatters_TObject_fUniqueID; //!
	TBranch* b_singleScatters_TObject_fBits; //!
	TBranch* b_singleScatters_nSingleScatters; //!
	TBranch* b_singleScatters_s1PulseID; //!
	TBranch* b_singleScatters_s1IsHG; //!
	TBranch* b_singleScatters_s2PulseID; //!
	TBranch* b_singleScatters_s2IsHG; //!
	TBranch* b_singleScatters_driftTime_ns; //!
	TBranch* b_singleScatters_s1Area_phd; //!
	TBranch* b_singleScatters_s2Area_phd; //!
	TBranch* b_singleScatters_s1TopArea_phd; //!
	TBranch* b_singleScatters_s1BottomArea_phd; //!
	TBranch* b_singleScatters_s1TopCorrectionFactor; //!
	TBranch* b_singleScatters_s1BottomCorrectionFactor; //!
	TBranch* b_singleScatters_correctedS1TopArea_phd; //!
	TBranch* b_singleScatters_correctedS1BottomArea_phd; //!
	TBranch* b_singleScatters_correctedS1Area_phd; //!
	TBranch* b_singleScatters_s2CorrectionFactor; //!
	TBranch* b_singleScatters_correctedS2Area_phd; //!
	TBranch* b_singleScatters_x_cm; //!
	TBranch* b_singleScatters_y_cm; //!
	TBranch* b_singleScatters_xyChi2; //!
	TBranch* b_singleScatters_correctedX_cm; //!
	TBranch* b_singleScatters_correctedY_cm; //!
	TBranch* b_singleScatters_correctedZ_cm; //!
	TBranch* b_singleScatters_s1PhotonCount; //!
	TBranch* b_singleScatters_correctedS1PhotonCount; //!
	TBranch* b_singleScatters_energyER_keV; //!
	TBranch* b_singleScatters_energyNR_keV; //!
	TBranch* b_singleScatters_skinPromptArea; //!
	TBranch* b_singleScatters_nSkinPromptPulses; //!
	TBranch* b_singleScatters_skinPromptPulseIDs; //!
	TBranch* b_singleScatters_odPromptArea; //!
	TBranch* b_singleScatters_nODPromptPulses; //!
	TBranch* b_singleScatters_odPromptPulseIDs; //!
	TBranch* b_singleScatters_odDelayedAreas; //!
	TBranch* b_singleScatters_nODDelayedPulses; //!
	TBranch* b_singleScatters_odDelayedPulseIDs; //!
	TBranch* b_multipleScatters_TObject_fUniqueID; //!
	TBranch* b_multipleScatters_TObject_fBits; //!
	TBranch* b_multipleScatters_nMultipleScatters; //!
	TBranch* b_multipleScatters_s1PulseID; //!
	TBranch* b_multipleScatters_s1IsHG; //!
	TBranch* b_multipleScatters_s1Area_phd; //!
	TBranch* b_multipleScatters_s1TopArea_phd; //!
	TBranch* b_multipleScatters_s1BottomArea_phd; //!
	TBranch* b_multipleScatters_nS2s; //!
	TBranch* b_multipleScatters_s2PulseIDs; //!
	TBranch* b_multipleScatters_s2IsHG; //!
	TBranch* b_multipleScatters_s2Area_phd; //!
	TBranch* b_multipleScatters_s1TopCorrectionFactors; //!
	TBranch* b_multipleScatters_s1BottomCorrectionFactors; //!
	TBranch* b_multipleScatters_correctedS1TopAreas_phd; //!
	TBranch* b_multipleScatters_correctedS1BottomAreas_phd; //!
	TBranch* b_multipleScatters_correctedS1Areas_phd; //!
	TBranch* b_multipleScatters_s2CorrectionFactors; //!
	TBranch* b_multipleScatters_correctedS2Area_phd; //!
	TBranch* b_multipleScatters_driftTime_ns; //!
	TBranch* b_multipleScatters_weightedDriftTime_ns; //!
	TBranch* b_multipleScatters_x_cm; //!
	TBranch* b_multipleScatters_y_cm; //!
	TBranch* b_multipleScatters_correctedX_cm; //!
	TBranch* b_multipleScatters_correctedY_cm; //!
	TBranch* b_multipleScatters_correctedZ_cm; //!
	TBranch* b_multipleScatters_energyER_keV; //!
	TBranch* b_multipleScatters_energyNR_keV; //!
	TBranch* b_kr83mScatters_TObject_fUniqueID; //!
	TBranch* b_kr83mScatters_TObject_fBits; //!
	TBranch* b_kr83mScatters_nKr83mScatters; //!
	TBranch* b_kr83mScatters_s1aPulseID; //!
	TBranch* b_kr83mScatters_s1aArea_phd; //!
	TBranch* b_kr83mScatters_s1bPulseID; //!
	TBranch* b_kr83mScatters_s1bArea_phd; //!
	TBranch* b_kr83mScatters_s2PulseID; //!
	TBranch* b_kr83mScatters_s2Area_phd; //!
	TBranch* b_kr83mScatters_driftTime_ns; //!
	TBranch* b_kr83mScatters_x_cm; //!
	TBranch* b_kr83mScatters_y_cm; //!
	TBranch* b_kr83mScatters_correctedX_cm; //!
	TBranch* b_kr83mScatters_correctedY_cm; //!
	TBranch* b_kr83mScatters_correctedZ_cm; //!
	TBranch* b_kr83mScatters_energy_keV; //!
	TBranch* b_otherScatters_TObject_fUniqueID; //!
	TBranch* b_otherScatters_TObject_fBits; //!
	TBranch* b_otherScatters_nOtherScatters; //!
	TBranch* b_otherScatters_nS1s; //!
	TBranch* b_otherScatters_s1PulseIDs; //!
	TBranch* b_otherScatters_nS2s; //!
	TBranch* b_otherScatters_s2PulseIDs; //!
	TBranch* b_otherScatters_nSPEs; //!
	TBranch* b_otherScatters_spePulseIDs; //!
	TBranch* b_otherScatters_nSEs; //!
	TBranch* b_otherScatters_sePulseIDs; //!
	TBranch* b_otherScatters_nOthers; //!
	TBranch* b_otherScatters_otherPulseIDs; //!
	TBranch* b_pileUpScatters_TObject_fUniqueID; //!
	TBranch* b_pileUpScatters_TObject_fBits; //!
	TBranch* b_pileUpScatters_nPileUpScatters; //!
	TBranch* b_pileUpScatters_nS1; //!
	TBranch* b_pileUpScatters_s1PulseIDs; //!
	TBranch* b_pileUpScatters_nS2; //!
	TBranch* b_pileUpScatters_s2PulseIDs; //!

	ODChannels(TTree* tree = 0);
	virtual ~ODChannels();
	virtual Int_t Cut(Long64_t entry);
	virtual Int_t GetEntry(Long64_t entry);
	virtual Long64_t LoadTree(Long64_t entry);
	virtual void Init(TTree* tree);
	virtual void Loop();
	virtual Bool_t Notify();
	virtual void Show(Long64_t entry = -1);
};

#endif

#ifdef ODChannels_cxx
ODChannels::ODChannels(TTree* tree)
    : fChain(0)
{
	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.
	if (tree == 0)
	{
		TFile* f = (TFile*)gROOT->GetListOfFiles()->FindObject("/yorktown/LZaptst/newtst.root");
		if (!f || !f->IsOpen())
		{
			f = new TFile("/yorktown/LZaptst/newtst.root");
		}
		f->GetObject("Events", tree);
	}
	Init(tree);
}

ODChannels::~ODChannels()
{
	if (!fChain)
		return;
	delete fChain->GetCurrentFile();
}

Int_t ODChannels::GetEntry(Long64_t entry)
{
	// Read contents of entry.
	if (!fChain)
		return 0;
	return fChain->GetEntry(entry);
}
Long64_t ODChannels::LoadTree(Long64_t entry)
{
	// Set the environment to read one entry
	if (!fChain)
		return -5;
	Long64_t centry = fChain->LoadTree(entry);
	if (centry < 0)
		return centry;
	if (fChain->GetTreeNumber() != fCurrent)
	{
		fCurrent = fChain->GetTreeNumber();
		Notify();
	}
	return centry;
}

void ODChannels::Init(TTree* tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	// Set branch addresses and branch pointers
	if (!tree)
		return;
	fChain = tree;
	fCurrent = -1;
	fChain->SetMakeClass(1);

	fChain->SetBranchAddress(
	    "eventHeader.TObject.fUniqueID", &eventHeader_TObject_fUniqueID, &b_eventHeader_TObject_fUniqueID);
	fChain->SetBranchAddress("eventHeader.TObject.fBits", &eventHeader_TObject_fBits, &b_eventHeader_TObject_fBits);
	fChain->SetBranchAddress("eventHeader.runID", &eventHeader_runID, &b_eventHeader_runID);
	fChain->SetBranchAddress("eventHeader.eventID", &eventHeader_eventID, &b_eventHeader_eventID);
	fChain->SetBranchAddress("eventHeader.rawFileName", &eventHeader_rawFileName, &b_eventHeader_rawFileName);
	fChain->SetBranchAddress(
	    "eventHeader.triggerTimeStamp_s", &eventHeader_triggerTimeStamp_s, &b_eventHeader_triggerTimeStamp_s);
	fChain->SetBranchAddress(
	    "eventHeader.triggerTimeStamp_ns", &eventHeader_triggerTimeStamp_ns, &b_eventHeader_triggerTimeStamp_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.TObject.fUniqueID", &pulsesTPC_TObject_fUniqueID, &b_pulsesTPC_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesTPC.TObject.fBits", &pulsesTPC_TObject_fBits, &b_pulsesTPC_TObject_fBits);
	fChain->SetBranchAddress("pulsesTPC.nPulses", &pulsesTPC_nPulses, &b_pulsesTPC_nPulses);
	fChain->SetBranchAddress("pulsesTPC.pulseID", &pulsesTPC_pulseID, &b_pulsesTPC_pulseID);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseStartTime_ns", &pulsesTPC_pulseStartTime_ns, &b_pulsesTPC_pulseStartTime_ns);
	fChain->SetBranchAddress("pulsesTPC.pulseEndTime_ns", &pulsesTPC_pulseEndTime_ns, &b_pulsesTPC_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesTPC.saturated", &pulsesTPC_saturated, &b_pulsesTPC_saturated);
	fChain->SetBranchAddress(
	    "pulsesTPC.nSaturatedChannels", &pulsesTPC_nSaturatedChannels, &b_pulsesTPC_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesTPC.saturatedChannelIDs", &pulsesTPC_saturatedChannelIDs, &b_pulsesTPC_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesTPC.pulseArea_phd", &pulsesTPC_pulseArea_phd, &b_pulsesTPC_pulseArea_phd);
	fChain->SetBranchAddress("pulsesTPC.positiveArea_phd", &pulsesTPC_positiveArea_phd, &b_pulsesTPC_positiveArea_phd);
	fChain->SetBranchAddress("pulsesTPC.negativeArea_phd", &pulsesTPC_negativeArea_phd, &b_pulsesTPC_negativeArea_phd);
	fChain->SetBranchAddress("pulsesTPC.peakAmp", &pulsesTPC_peakAmp, &b_pulsesTPC_peakAmp);
	fChain->SetBranchAddress("pulsesTPC.peakTime_ns", &pulsesTPC_peakTime_ns, &b_pulsesTPC_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime1_ns", &pulsesTPC_areaFractionTime1_ns, &b_pulsesTPC_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime5_ns", &pulsesTPC_areaFractionTime5_ns, &b_pulsesTPC_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime10_ns", &pulsesTPC_areaFractionTime10_ns, &b_pulsesTPC_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime25_ns", &pulsesTPC_areaFractionTime25_ns, &b_pulsesTPC_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime50_ns", &pulsesTPC_areaFractionTime50_ns, &b_pulsesTPC_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime75_ns", &pulsesTPC_areaFractionTime75_ns, &b_pulsesTPC_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime90_ns", &pulsesTPC_areaFractionTime90_ns, &b_pulsesTPC_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime95_ns", &pulsesTPC_areaFractionTime95_ns, &b_pulsesTPC_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.areaFractionTime99_ns", &pulsesTPC_areaFractionTime99_ns, &b_pulsesTPC_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseAreaNeg50ns_phd", &pulsesTPC_pulseAreaNeg50ns_phd, &b_pulsesTPC_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseArea50ns_phd", &pulsesTPC_pulseArea50ns_phd, &b_pulsesTPC_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseArea100ns_phd", &pulsesTPC_pulseArea100ns_phd, &b_pulsesTPC_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseArea200ns_phd", &pulsesTPC_pulseArea200ns_phd, &b_pulsesTPC_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.pulseArea500ns_phd", &pulsesTPC_pulseArea500ns_phd, &b_pulsesTPC_pulseArea500ns_phd);
	fChain->SetBranchAddress("pulsesTPC.pulseArea1us_phd", &pulsesTPC_pulseArea1us_phd, &b_pulsesTPC_pulseArea1us_phd);
	fChain->SetBranchAddress("pulsesTPC.pulseArea2us_phd", &pulsesTPC_pulseArea2us_phd, &b_pulsesTPC_pulseArea2us_phd);
	fChain->SetBranchAddress("pulsesTPC.pulseArea5us_phd", &pulsesTPC_pulseArea5us_phd, &b_pulsesTPC_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.promptFraction50ns", &pulsesTPC_promptFraction50ns, &b_pulsesTPC_promptFraction50ns);
	fChain->SetBranchAddress("pulsesTPC.rmsWidth_ns", &pulsesTPC_rmsWidth_ns, &b_pulsesTPC_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesTPC.fwhm_ns", &pulsesTPC_fwhm_ns, &b_pulsesTPC_fwhm_ns);
	fChain->SetBranchAddress("pulsesTPC.topArea_phd", &pulsesTPC_topArea_phd, &b_pulsesTPC_topArea_phd);
	fChain->SetBranchAddress("pulsesTPC.bottomArea_phd", &pulsesTPC_bottomArea_phd, &b_pulsesTPC_bottomArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPC.topBottomAsymmetry", &pulsesTPC_topBottomAsymmetry, &b_pulsesTPC_topBottomAsymmetry);
	fChain->SetBranchAddress("pulsesTPC.coincidence", &pulsesTPC_coincidence, &b_pulsesTPC_coincidence);
	fChain->SetBranchAddress("pulsesTPC.s1Probability", &pulsesTPC_s1Probability, &b_pulsesTPC_s1Probability);
	fChain->SetBranchAddress("pulsesTPC.s2Probability", &pulsesTPC_s2Probability, &b_pulsesTPC_s2Probability);
	fChain->SetBranchAddress(
	    "pulsesTPC.singlePEprobability", &pulsesTPC_singlePEprobability, &b_pulsesTPC_singlePEprobability);
	fChain->SetBranchAddress(
	    "pulsesTPC.multiplePEprobability", &pulsesTPC_multiplePEprobability, &b_pulsesTPC_multiplePEprobability);
	fChain->SetBranchAddress("pulsesTPC.singleElectronProbability", &pulsesTPC_singleElectronProbability,
	    &b_pulsesTPC_singleElectronProbability);
	fChain->SetBranchAddress("pulsesTPC.otherProbability", &pulsesTPC_otherProbability, &b_pulsesTPC_otherProbability);
	fChain->SetBranchAddress(
	    "pulsesTPC.otherS2Probability", &pulsesTPC_otherS2Probability, &b_pulsesTPC_otherS2Probability);
	fChain->SetBranchAddress("pulsesTPC.photonCount", &pulsesTPC_photonCount, &b_pulsesTPC_photonCount);
	fChain->SetBranchAddress("pulsesTPC.topPhotonCount", &pulsesTPC_topPhotonCount, &b_pulsesTPC_topPhotonCount);
	fChain->SetBranchAddress(
	    "pulsesTPC.bottomPhotonCount", &pulsesTPC_bottomPhotonCount, &b_pulsesTPC_bottomPhotonCount);
	fChain->SetBranchAddress("pulsesTPC.s2Xposition_cm", &pulsesTPC_s2Xposition_cm, &b_pulsesTPC_s2Xposition_cm);
	fChain->SetBranchAddress("pulsesTPC.s2Yposition_cm", &pulsesTPC_s2Yposition_cm, &b_pulsesTPC_s2Yposition_cm);
	fChain->SetBranchAddress("pulsesTPC.HGLGpulseID", &pulsesTPC_HGLGpulseID, &b_pulsesTPC_HGLGpulseID);
	fChain->SetBranchAddress("pulsesTPC.chID", &pulsesTPC_chID, &b_pulsesTPC_chID);
	fChain->SetBranchAddress("pulsesTPC.chPulseArea_phd", &pulsesTPC_chPulseArea_phd, &b_pulsesTPC_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesTPC.chPeakAmp", &pulsesTPC_chPeakAmp, &b_pulsesTPC_chPeakAmp);
	fChain->SetBranchAddress("pulsesTPC.chPeakTime_ns", &pulsesTPC_chPeakTime_ns, &b_pulsesTPC_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesTPC.chSaturated", &pulsesTPC_chSaturated, &b_pulsesTPC_chSaturated);
	fChain->SetBranchAddress("pulsesTPC.chPhotonCount", &pulsesTPC_chPhotonCount, &b_pulsesTPC_chPhotonCount);
	fChain->SetBranchAddress("pulsesTPC.chPhotonTimes", &pulsesTPC_chPhotonTimes, &b_pulsesTPC_chPhotonTimes);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.TObject.fUniqueID", &pulsesTPCHG_TObject_fUniqueID, &b_pulsesTPCHG_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesTPCHG.TObject.fBits", &pulsesTPCHG_TObject_fBits, &b_pulsesTPCHG_TObject_fBits);
	fChain->SetBranchAddress("pulsesTPCHG.nPulses", &pulsesTPCHG_nPulses, &b_pulsesTPCHG_nPulses);
	fChain->SetBranchAddress("pulsesTPCHG.pulseID", &pulsesTPCHG_pulseID, &b_pulsesTPCHG_pulseID);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseStartTime_ns", &pulsesTPCHG_pulseStartTime_ns, &b_pulsesTPCHG_pulseStartTime_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseEndTime_ns", &pulsesTPCHG_pulseEndTime_ns, &b_pulsesTPCHG_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesTPCHG.saturated", &pulsesTPCHG_saturated, &b_pulsesTPCHG_saturated);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.nSaturatedChannels", &pulsesTPCHG_nSaturatedChannels, &b_pulsesTPCHG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.saturatedChannelIDs", &pulsesTPCHG_saturatedChannelIDs, &b_pulsesTPCHG_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesTPCHG.pulseArea_phd", &pulsesTPCHG_pulseArea_phd, &b_pulsesTPCHG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.positiveArea_phd", &pulsesTPCHG_positiveArea_phd, &b_pulsesTPCHG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.negativeArea_phd", &pulsesTPCHG_negativeArea_phd, &b_pulsesTPCHG_negativeArea_phd);
	fChain->SetBranchAddress("pulsesTPCHG.peakAmp", &pulsesTPCHG_peakAmp, &b_pulsesTPCHG_peakAmp);
	fChain->SetBranchAddress("pulsesTPCHG.peakTime_ns", &pulsesTPCHG_peakTime_ns, &b_pulsesTPCHG_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime1_ns", &pulsesTPCHG_areaFractionTime1_ns, &b_pulsesTPCHG_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime5_ns", &pulsesTPCHG_areaFractionTime5_ns, &b_pulsesTPCHG_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime10_ns", &pulsesTPCHG_areaFractionTime10_ns, &b_pulsesTPCHG_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime25_ns", &pulsesTPCHG_areaFractionTime25_ns, &b_pulsesTPCHG_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime50_ns", &pulsesTPCHG_areaFractionTime50_ns, &b_pulsesTPCHG_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime75_ns", &pulsesTPCHG_areaFractionTime75_ns, &b_pulsesTPCHG_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime90_ns", &pulsesTPCHG_areaFractionTime90_ns, &b_pulsesTPCHG_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime95_ns", &pulsesTPCHG_areaFractionTime95_ns, &b_pulsesTPCHG_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.areaFractionTime99_ns", &pulsesTPCHG_areaFractionTime99_ns, &b_pulsesTPCHG_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseAreaNeg50ns_phd", &pulsesTPCHG_pulseAreaNeg50ns_phd, &b_pulsesTPCHG_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea50ns_phd", &pulsesTPCHG_pulseArea50ns_phd, &b_pulsesTPCHG_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea100ns_phd", &pulsesTPCHG_pulseArea100ns_phd, &b_pulsesTPCHG_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea200ns_phd", &pulsesTPCHG_pulseArea200ns_phd, &b_pulsesTPCHG_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea500ns_phd", &pulsesTPCHG_pulseArea500ns_phd, &b_pulsesTPCHG_pulseArea500ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea1us_phd", &pulsesTPCHG_pulseArea1us_phd, &b_pulsesTPCHG_pulseArea1us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea2us_phd", &pulsesTPCHG_pulseArea2us_phd, &b_pulsesTPCHG_pulseArea2us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.pulseArea5us_phd", &pulsesTPCHG_pulseArea5us_phd, &b_pulsesTPCHG_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.promptFraction50ns", &pulsesTPCHG_promptFraction50ns, &b_pulsesTPCHG_promptFraction50ns);
	fChain->SetBranchAddress("pulsesTPCHG.rmsWidth_ns", &pulsesTPCHG_rmsWidth_ns, &b_pulsesTPCHG_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesTPCHG.fwhm_ns", &pulsesTPCHG_fwhm_ns, &b_pulsesTPCHG_fwhm_ns);
	fChain->SetBranchAddress("pulsesTPCHG.topArea_phd", &pulsesTPCHG_topArea_phd, &b_pulsesTPCHG_topArea_phd);
	fChain->SetBranchAddress("pulsesTPCHG.bottomArea_phd", &pulsesTPCHG_bottomArea_phd, &b_pulsesTPCHG_bottomArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.topBottomAsymmetry", &pulsesTPCHG_topBottomAsymmetry, &b_pulsesTPCHG_topBottomAsymmetry);
	fChain->SetBranchAddress("pulsesTPCHG.coincidence", &pulsesTPCHG_coincidence, &b_pulsesTPCHG_coincidence);
	fChain->SetBranchAddress("pulsesTPCHG.s1Probability", &pulsesTPCHG_s1Probability, &b_pulsesTPCHG_s1Probability);
	fChain->SetBranchAddress("pulsesTPCHG.s2Probability", &pulsesTPCHG_s2Probability, &b_pulsesTPCHG_s2Probability);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.singlePEprobability", &pulsesTPCHG_singlePEprobability, &b_pulsesTPCHG_singlePEprobability);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.multiplePEprobability", &pulsesTPCHG_multiplePEprobability, &b_pulsesTPCHG_multiplePEprobability);
	fChain->SetBranchAddress("pulsesTPCHG.singleElectronProbability", &pulsesTPCHG_singleElectronProbability,
	    &b_pulsesTPCHG_singleElectronProbability);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.otherProbability", &pulsesTPCHG_otherProbability, &b_pulsesTPCHG_otherProbability);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.otherS2Probability", &pulsesTPCHG_otherS2Probability, &b_pulsesTPCHG_otherS2Probability);
	fChain->SetBranchAddress("pulsesTPCHG.photonCount", &pulsesTPCHG_photonCount, &b_pulsesTPCHG_photonCount);
	fChain->SetBranchAddress("pulsesTPCHG.topPhotonCount", &pulsesTPCHG_topPhotonCount, &b_pulsesTPCHG_topPhotonCount);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.bottomPhotonCount", &pulsesTPCHG_bottomPhotonCount, &b_pulsesTPCHG_bottomPhotonCount);
	fChain->SetBranchAddress("pulsesTPCHG.s2Xposition_cm", &pulsesTPCHG_s2Xposition_cm, &b_pulsesTPCHG_s2Xposition_cm);
	fChain->SetBranchAddress("pulsesTPCHG.s2Yposition_cm", &pulsesTPCHG_s2Yposition_cm, &b_pulsesTPCHG_s2Yposition_cm);
	fChain->SetBranchAddress("pulsesTPCHG.HGLGpulseID", &pulsesTPCHG_HGLGpulseID, &b_pulsesTPCHG_HGLGpulseID);
	fChain->SetBranchAddress("pulsesTPCHG.chID", &pulsesTPCHG_chID, &b_pulsesTPCHG_chID);
	fChain->SetBranchAddress(
	    "pulsesTPCHG.chPulseArea_phd", &pulsesTPCHG_chPulseArea_phd, &b_pulsesTPCHG_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesTPCHG.chPeakAmp", &pulsesTPCHG_chPeakAmp, &b_pulsesTPCHG_chPeakAmp);
	fChain->SetBranchAddress("pulsesTPCHG.chPeakTime_ns", &pulsesTPCHG_chPeakTime_ns, &b_pulsesTPCHG_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesTPCHG.chSaturated", &pulsesTPCHG_chSaturated, &b_pulsesTPCHG_chSaturated);
	fChain->SetBranchAddress("pulsesTPCHG.chPhotonCount", &pulsesTPCHG_chPhotonCount, &b_pulsesTPCHG_chPhotonCount);
	fChain->SetBranchAddress("pulsesTPCHG.chPhotonTimes", &pulsesTPCHG_chPhotonTimes, &b_pulsesTPCHG_chPhotonTimes);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.TObject.fUniqueID", &pulsesTPCLG_TObject_fUniqueID, &b_pulsesTPCLG_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesTPCLG.TObject.fBits", &pulsesTPCLG_TObject_fBits, &b_pulsesTPCLG_TObject_fBits);
	fChain->SetBranchAddress("pulsesTPCLG.nPulses", &pulsesTPCLG_nPulses, &b_pulsesTPCLG_nPulses);
	fChain->SetBranchAddress("pulsesTPCLG.pulseID", &pulsesTPCLG_pulseID, &b_pulsesTPCLG_pulseID);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseStartTime_ns", &pulsesTPCLG_pulseStartTime_ns, &b_pulsesTPCLG_pulseStartTime_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseEndTime_ns", &pulsesTPCLG_pulseEndTime_ns, &b_pulsesTPCLG_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesTPCLG.saturated", &pulsesTPCLG_saturated, &b_pulsesTPCLG_saturated);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.nSaturatedChannels", &pulsesTPCLG_nSaturatedChannels, &b_pulsesTPCLG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.saturatedChannelIDs", &pulsesTPCLG_saturatedChannelIDs, &b_pulsesTPCLG_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesTPCLG.pulseArea_phd", &pulsesTPCLG_pulseArea_phd, &b_pulsesTPCLG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.positiveArea_phd", &pulsesTPCLG_positiveArea_phd, &b_pulsesTPCLG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.negativeArea_phd", &pulsesTPCLG_negativeArea_phd, &b_pulsesTPCLG_negativeArea_phd);
	fChain->SetBranchAddress("pulsesTPCLG.peakAmp", &pulsesTPCLG_peakAmp, &b_pulsesTPCLG_peakAmp);
	fChain->SetBranchAddress("pulsesTPCLG.peakTime_ns", &pulsesTPCLG_peakTime_ns, &b_pulsesTPCLG_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime1_ns", &pulsesTPCLG_areaFractionTime1_ns, &b_pulsesTPCLG_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime5_ns", &pulsesTPCLG_areaFractionTime5_ns, &b_pulsesTPCLG_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime10_ns", &pulsesTPCLG_areaFractionTime10_ns, &b_pulsesTPCLG_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime25_ns", &pulsesTPCLG_areaFractionTime25_ns, &b_pulsesTPCLG_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime50_ns", &pulsesTPCLG_areaFractionTime50_ns, &b_pulsesTPCLG_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime75_ns", &pulsesTPCLG_areaFractionTime75_ns, &b_pulsesTPCLG_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime90_ns", &pulsesTPCLG_areaFractionTime90_ns, &b_pulsesTPCLG_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime95_ns", &pulsesTPCLG_areaFractionTime95_ns, &b_pulsesTPCLG_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.areaFractionTime99_ns", &pulsesTPCLG_areaFractionTime99_ns, &b_pulsesTPCLG_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseAreaNeg50ns_phd", &pulsesTPCLG_pulseAreaNeg50ns_phd, &b_pulsesTPCLG_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea50ns_phd", &pulsesTPCLG_pulseArea50ns_phd, &b_pulsesTPCLG_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea100ns_phd", &pulsesTPCLG_pulseArea100ns_phd, &b_pulsesTPCLG_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea200ns_phd", &pulsesTPCLG_pulseArea200ns_phd, &b_pulsesTPCLG_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea500ns_phd", &pulsesTPCLG_pulseArea500ns_phd, &b_pulsesTPCLG_pulseArea500ns_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea1us_phd", &pulsesTPCLG_pulseArea1us_phd, &b_pulsesTPCLG_pulseArea1us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea2us_phd", &pulsesTPCLG_pulseArea2us_phd, &b_pulsesTPCLG_pulseArea2us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.pulseArea5us_phd", &pulsesTPCLG_pulseArea5us_phd, &b_pulsesTPCLG_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.promptFraction50ns", &pulsesTPCLG_promptFraction50ns, &b_pulsesTPCLG_promptFraction50ns);
	fChain->SetBranchAddress("pulsesTPCLG.rmsWidth_ns", &pulsesTPCLG_rmsWidth_ns, &b_pulsesTPCLG_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesTPCLG.fwhm_ns", &pulsesTPCLG_fwhm_ns, &b_pulsesTPCLG_fwhm_ns);
	fChain->SetBranchAddress("pulsesTPCLG.topArea_phd", &pulsesTPCLG_topArea_phd, &b_pulsesTPCLG_topArea_phd);
	fChain->SetBranchAddress("pulsesTPCLG.bottomArea_phd", &pulsesTPCLG_bottomArea_phd, &b_pulsesTPCLG_bottomArea_phd);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.topBottomAsymmetry", &pulsesTPCLG_topBottomAsymmetry, &b_pulsesTPCLG_topBottomAsymmetry);
	fChain->SetBranchAddress("pulsesTPCLG.coincidence", &pulsesTPCLG_coincidence, &b_pulsesTPCLG_coincidence);
	fChain->SetBranchAddress("pulsesTPCLG.s1Probability", &pulsesTPCLG_s1Probability, &b_pulsesTPCLG_s1Probability);
	fChain->SetBranchAddress("pulsesTPCLG.s2Probability", &pulsesTPCLG_s2Probability, &b_pulsesTPCLG_s2Probability);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.singlePEprobability", &pulsesTPCLG_singlePEprobability, &b_pulsesTPCLG_singlePEprobability);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.multiplePEprobability", &pulsesTPCLG_multiplePEprobability, &b_pulsesTPCLG_multiplePEprobability);
	fChain->SetBranchAddress("pulsesTPCLG.singleElectronProbability", &pulsesTPCLG_singleElectronProbability,
	    &b_pulsesTPCLG_singleElectronProbability);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.otherProbability", &pulsesTPCLG_otherProbability, &b_pulsesTPCLG_otherProbability);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.otherS2Probability", &pulsesTPCLG_otherS2Probability, &b_pulsesTPCLG_otherS2Probability);
	fChain->SetBranchAddress("pulsesTPCLG.photonCount", &pulsesTPCLG_photonCount, &b_pulsesTPCLG_photonCount);
	fChain->SetBranchAddress("pulsesTPCLG.topPhotonCount", &pulsesTPCLG_topPhotonCount, &b_pulsesTPCLG_topPhotonCount);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.bottomPhotonCount", &pulsesTPCLG_bottomPhotonCount, &b_pulsesTPCLG_bottomPhotonCount);
	fChain->SetBranchAddress("pulsesTPCLG.s2Xposition_cm", &pulsesTPCLG_s2Xposition_cm, &b_pulsesTPCLG_s2Xposition_cm);
	fChain->SetBranchAddress("pulsesTPCLG.s2Yposition_cm", &pulsesTPCLG_s2Yposition_cm, &b_pulsesTPCLG_s2Yposition_cm);
	fChain->SetBranchAddress("pulsesTPCLG.HGLGpulseID", &pulsesTPCLG_HGLGpulseID, &b_pulsesTPCLG_HGLGpulseID);
	fChain->SetBranchAddress("pulsesTPCLG.chID", &pulsesTPCLG_chID, &b_pulsesTPCLG_chID);
	fChain->SetBranchAddress(
	    "pulsesTPCLG.chPulseArea_phd", &pulsesTPCLG_chPulseArea_phd, &b_pulsesTPCLG_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesTPCLG.chPeakAmp", &pulsesTPCLG_chPeakAmp, &b_pulsesTPCLG_chPeakAmp);
	fChain->SetBranchAddress("pulsesTPCLG.chPeakTime_ns", &pulsesTPCLG_chPeakTime_ns, &b_pulsesTPCLG_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesTPCLG.chSaturated", &pulsesTPCLG_chSaturated, &b_pulsesTPCLG_chSaturated);
	fChain->SetBranchAddress("pulsesTPCLG.chPhotonCount", &pulsesTPCLG_chPhotonCount, &b_pulsesTPCLG_chPhotonCount);
	fChain->SetBranchAddress("pulsesTPCLG.chPhotonTimes", &pulsesTPCLG_chPhotonTimes, &b_pulsesTPCLG_chPhotonTimes);
	fChain->SetBranchAddress(
	    "pulsesSkin.TObject.fUniqueID", &pulsesSkin_TObject_fUniqueID, &b_pulsesSkin_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesSkin.TObject.fBits", &pulsesSkin_TObject_fBits, &b_pulsesSkin_TObject_fBits);
	fChain->SetBranchAddress("pulsesSkin.nPulses", &pulsesSkin_nPulses, &b_pulsesSkin_nPulses);
	fChain->SetBranchAddress("pulsesSkin.pulseID", &pulsesSkin_pulseID, &b_pulsesSkin_pulseID);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseStartTime_ns", &pulsesSkin_pulseStartTime_ns, &b_pulsesSkin_pulseStartTime_ns);
	fChain->SetBranchAddress("pulsesSkin.pulseEndTime_ns", &pulsesSkin_pulseEndTime_ns, &b_pulsesSkin_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesSkin.saturated", &pulsesSkin_saturated, &b_pulsesSkin_saturated);
	fChain->SetBranchAddress(
	    "pulsesSkin.nSaturatedChannels", &pulsesSkin_nSaturatedChannels, &b_pulsesSkin_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesSkin.saturatedChannelIDs", &pulsesSkin_saturatedChannelIDs, &b_pulsesSkin_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesSkin.pulseArea_phd", &pulsesSkin_pulseArea_phd, &b_pulsesSkin_pulseArea_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.positiveArea_phd", &pulsesSkin_positiveArea_phd, &b_pulsesSkin_positiveArea_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.negativeArea_phd", &pulsesSkin_negativeArea_phd, &b_pulsesSkin_negativeArea_phd);
	fChain->SetBranchAddress("pulsesSkin.peakAmp", &pulsesSkin_peakAmp, &b_pulsesSkin_peakAmp);
	fChain->SetBranchAddress("pulsesSkin.peakTime_ns", &pulsesSkin_peakTime_ns, &b_pulsesSkin_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime1_ns", &pulsesSkin_areaFractionTime1_ns, &b_pulsesSkin_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime5_ns", &pulsesSkin_areaFractionTime5_ns, &b_pulsesSkin_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime10_ns", &pulsesSkin_areaFractionTime10_ns, &b_pulsesSkin_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime25_ns", &pulsesSkin_areaFractionTime25_ns, &b_pulsesSkin_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime50_ns", &pulsesSkin_areaFractionTime50_ns, &b_pulsesSkin_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime75_ns", &pulsesSkin_areaFractionTime75_ns, &b_pulsesSkin_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime90_ns", &pulsesSkin_areaFractionTime90_ns, &b_pulsesSkin_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime95_ns", &pulsesSkin_areaFractionTime95_ns, &b_pulsesSkin_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.areaFractionTime99_ns", &pulsesSkin_areaFractionTime99_ns, &b_pulsesSkin_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseAreaNeg50ns_phd", &pulsesSkin_pulseAreaNeg50ns_phd, &b_pulsesSkin_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea50ns_phd", &pulsesSkin_pulseArea50ns_phd, &b_pulsesSkin_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea100ns_phd", &pulsesSkin_pulseArea100ns_phd, &b_pulsesSkin_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea200ns_phd", &pulsesSkin_pulseArea200ns_phd, &b_pulsesSkin_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea500ns_phd", &pulsesSkin_pulseArea500ns_phd, &b_pulsesSkin_pulseArea500ns_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea1us_phd", &pulsesSkin_pulseArea1us_phd, &b_pulsesSkin_pulseArea1us_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea2us_phd", &pulsesSkin_pulseArea2us_phd, &b_pulsesSkin_pulseArea2us_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.pulseArea5us_phd", &pulsesSkin_pulseArea5us_phd, &b_pulsesSkin_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.promptFraction50ns", &pulsesSkin_promptFraction50ns, &b_pulsesSkin_promptFraction50ns);
	fChain->SetBranchAddress("pulsesSkin.rmsWidth_ns", &pulsesSkin_rmsWidth_ns, &b_pulsesSkin_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesSkin.fwhm_ns", &pulsesSkin_fwhm_ns, &b_pulsesSkin_fwhm_ns);
	fChain->SetBranchAddress("pulsesSkin.topArea_phd", &pulsesSkin_topArea_phd, &b_pulsesSkin_topArea_phd);
	fChain->SetBranchAddress("pulsesSkin.bottomArea_phd", &pulsesSkin_bottomArea_phd, &b_pulsesSkin_bottomArea_phd);
	fChain->SetBranchAddress(
	    "pulsesSkin.topBottomAsymmetry", &pulsesSkin_topBottomAsymmetry, &b_pulsesSkin_topBottomAsymmetry);
	fChain->SetBranchAddress("pulsesSkin.coincidence", &pulsesSkin_coincidence, &b_pulsesSkin_coincidence);
	fChain->SetBranchAddress("pulsesSkin.s1Probability", &pulsesSkin_s1Probability, &b_pulsesSkin_s1Probability);
	fChain->SetBranchAddress("pulsesSkin.s2Probability", &pulsesSkin_s2Probability, &b_pulsesSkin_s2Probability);
	fChain->SetBranchAddress(
	    "pulsesSkin.singlePEprobability", &pulsesSkin_singlePEprobability, &b_pulsesSkin_singlePEprobability);
	fChain->SetBranchAddress(
	    "pulsesSkin.multiplePEprobability", &pulsesSkin_multiplePEprobability, &b_pulsesSkin_multiplePEprobability);
	fChain->SetBranchAddress("pulsesSkin.singleElectronProbability", &pulsesSkin_singleElectronProbability,
	    &b_pulsesSkin_singleElectronProbability);
	fChain->SetBranchAddress(
	    "pulsesSkin.otherProbability", &pulsesSkin_otherProbability, &b_pulsesSkin_otherProbability);
	fChain->SetBranchAddress(
	    "pulsesSkin.otherS2Probability", &pulsesSkin_otherS2Probability, &b_pulsesSkin_otherS2Probability);
	fChain->SetBranchAddress("pulsesSkin.photonCount", &pulsesSkin_photonCount, &b_pulsesSkin_photonCount);
	fChain->SetBranchAddress("pulsesSkin.topPhotonCount", &pulsesSkin_topPhotonCount, &b_pulsesSkin_topPhotonCount);
	fChain->SetBranchAddress(
	    "pulsesSkin.bottomPhotonCount", &pulsesSkin_bottomPhotonCount, &b_pulsesSkin_bottomPhotonCount);
	fChain->SetBranchAddress("pulsesSkin.s2Xposition_cm", &pulsesSkin_s2Xposition_cm, &b_pulsesSkin_s2Xposition_cm);
	fChain->SetBranchAddress("pulsesSkin.s2Yposition_cm", &pulsesSkin_s2Yposition_cm, &b_pulsesSkin_s2Yposition_cm);
	fChain->SetBranchAddress("pulsesSkin.HGLGpulseID", &pulsesSkin_HGLGpulseID, &b_pulsesSkin_HGLGpulseID);
	fChain->SetBranchAddress("pulsesSkin.chID", &pulsesSkin_chID, &b_pulsesSkin_chID);
	fChain->SetBranchAddress("pulsesSkin.chPulseArea_phd", &pulsesSkin_chPulseArea_phd, &b_pulsesSkin_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesSkin.chPeakAmp", &pulsesSkin_chPeakAmp, &b_pulsesSkin_chPeakAmp);
	fChain->SetBranchAddress("pulsesSkin.chPeakTime_ns", &pulsesSkin_chPeakTime_ns, &b_pulsesSkin_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesSkin.chSaturated", &pulsesSkin_chSaturated, &b_pulsesSkin_chSaturated);
	fChain->SetBranchAddress("pulsesSkin.chPhotonCount", &pulsesSkin_chPhotonCount, &b_pulsesSkin_chPhotonCount);
	fChain->SetBranchAddress("pulsesSkin.chPhotonTimes", &pulsesSkin_chPhotonTimes, &b_pulsesSkin_chPhotonTimes);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.TObject.fUniqueID", &OLDpulsesODHG_TObject_fUniqueID, &b_OLDpulsesODHG_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.TObject.fBits", &OLDpulsesODHG_TObject_fBits, &b_OLDpulsesODHG_TObject_fBits);
	fChain->SetBranchAddress("OLDpulsesODHG.nPulses", &OLDpulsesODHG_nPulses, &b_OLDpulsesODHG_nPulses);
	fChain->SetBranchAddress("OLDpulsesODHG.pulseID", &OLDpulsesODHG_pulseID, &b_OLDpulsesODHG_pulseID);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseStartTime_ns", &OLDpulsesODHG_pulseStartTime_ns, &b_OLDpulsesODHG_pulseStartTime_ns);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseEndTime_ns", &OLDpulsesODHG_pulseEndTime_ns, &b_OLDpulsesODHG_pulseEndTime_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.saturated", &OLDpulsesODHG_saturated, &b_OLDpulsesODHG_saturated);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.nSaturatedChannels", &OLDpulsesODHG_nSaturatedChannels, &b_OLDpulsesODHG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.saturatedChannelIDs", &OLDpulsesODHG_saturatedChannelIDs, &b_OLDpulsesODHG_saturatedChannelIDs);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea_phd", &OLDpulsesODHG_pulseArea_phd, &b_OLDpulsesODHG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.positiveArea_phd", &OLDpulsesODHG_positiveArea_phd, &b_OLDpulsesODHG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.negativeArea_phd", &OLDpulsesODHG_negativeArea_phd, &b_OLDpulsesODHG_negativeArea_phd);
	fChain->SetBranchAddress("OLDpulsesODHG.peakAmp", &OLDpulsesODHG_peakAmp, &b_OLDpulsesODHG_peakAmp);
	fChain->SetBranchAddress("OLDpulsesODHG.peakTime_ns", &OLDpulsesODHG_peakTime_ns, &b_OLDpulsesODHG_peakTime_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime1_ns", &OLDpulsesODHG_areaFractionTime1_ns,
	    &b_OLDpulsesODHG_areaFractionTime1_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime5_ns", &OLDpulsesODHG_areaFractionTime5_ns,
	    &b_OLDpulsesODHG_areaFractionTime5_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime10_ns", &OLDpulsesODHG_areaFractionTime10_ns,
	    &b_OLDpulsesODHG_areaFractionTime10_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime25_ns", &OLDpulsesODHG_areaFractionTime25_ns,
	    &b_OLDpulsesODHG_areaFractionTime25_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime50_ns", &OLDpulsesODHG_areaFractionTime50_ns,
	    &b_OLDpulsesODHG_areaFractionTime50_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime75_ns", &OLDpulsesODHG_areaFractionTime75_ns,
	    &b_OLDpulsesODHG_areaFractionTime75_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime90_ns", &OLDpulsesODHG_areaFractionTime90_ns,
	    &b_OLDpulsesODHG_areaFractionTime90_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime95_ns", &OLDpulsesODHG_areaFractionTime95_ns,
	    &b_OLDpulsesODHG_areaFractionTime95_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.areaFractionTime99_ns", &OLDpulsesODHG_areaFractionTime99_ns,
	    &b_OLDpulsesODHG_areaFractionTime99_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.pulseAreaNeg50ns_phd", &OLDpulsesODHG_pulseAreaNeg50ns_phd,
	    &b_OLDpulsesODHG_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea50ns_phd", &OLDpulsesODHG_pulseArea50ns_phd, &b_OLDpulsesODHG_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea100ns_phd", &OLDpulsesODHG_pulseArea100ns_phd, &b_OLDpulsesODHG_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea200ns_phd", &OLDpulsesODHG_pulseArea200ns_phd, &b_OLDpulsesODHG_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea500ns_phd", &OLDpulsesODHG_pulseArea500ns_phd, &b_OLDpulsesODHG_pulseArea500ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea1us_phd", &OLDpulsesODHG_pulseArea1us_phd, &b_OLDpulsesODHG_pulseArea1us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea2us_phd", &OLDpulsesODHG_pulseArea2us_phd, &b_OLDpulsesODHG_pulseArea2us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.pulseArea5us_phd", &OLDpulsesODHG_pulseArea5us_phd, &b_OLDpulsesODHG_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.promptFraction50ns", &OLDpulsesODHG_promptFraction50ns, &b_OLDpulsesODHG_promptFraction50ns);
	fChain->SetBranchAddress("OLDpulsesODHG.rmsWidth_ns", &OLDpulsesODHG_rmsWidth_ns, &b_OLDpulsesODHG_rmsWidth_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.fwhm_ns", &OLDpulsesODHG_fwhm_ns, &b_OLDpulsesODHG_fwhm_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.topArea_phd", &OLDpulsesODHG_topArea_phd, &b_OLDpulsesODHG_topArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.bottomArea_phd", &OLDpulsesODHG_bottomArea_phd, &b_OLDpulsesODHG_bottomArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.topBottomAsymmetry", &OLDpulsesODHG_topBottomAsymmetry, &b_OLDpulsesODHG_topBottomAsymmetry);
	fChain->SetBranchAddress("OLDpulsesODHG.coincidence", &OLDpulsesODHG_coincidence, &b_OLDpulsesODHG_coincidence);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.s1Probability", &OLDpulsesODHG_s1Probability, &b_OLDpulsesODHG_s1Probability);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.s2Probability", &OLDpulsesODHG_s2Probability, &b_OLDpulsesODHG_s2Probability);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.singlePEprobability", &OLDpulsesODHG_singlePEprobability, &b_OLDpulsesODHG_singlePEprobability);
	fChain->SetBranchAddress("OLDpulsesODHG.multiplePEprobability", &OLDpulsesODHG_multiplePEprobability,
	    &b_OLDpulsesODHG_multiplePEprobability);
	fChain->SetBranchAddress("OLDpulsesODHG.singleElectronProbability", &OLDpulsesODHG_singleElectronProbability,
	    &b_OLDpulsesODHG_singleElectronProbability);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.otherProbability", &OLDpulsesODHG_otherProbability, &b_OLDpulsesODHG_otherProbability);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.otherS2Probability", &OLDpulsesODHG_otherS2Probability, &b_OLDpulsesODHG_otherS2Probability);
	fChain->SetBranchAddress("OLDpulsesODHG.photonCount", &OLDpulsesODHG_photonCount, &b_OLDpulsesODHG_photonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.topPhotonCount", &OLDpulsesODHG_topPhotonCount, &b_OLDpulsesODHG_topPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.bottomPhotonCount", &OLDpulsesODHG_bottomPhotonCount, &b_OLDpulsesODHG_bottomPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.s2Xposition_cm", &OLDpulsesODHG_s2Xposition_cm, &b_OLDpulsesODHG_s2Xposition_cm);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.s2Yposition_cm", &OLDpulsesODHG_s2Yposition_cm, &b_OLDpulsesODHG_s2Yposition_cm);
	fChain->SetBranchAddress("OLDpulsesODHG.HGLGpulseID", &OLDpulsesODHG_HGLGpulseID, &b_OLDpulsesODHG_HGLGpulseID);
	fChain->SetBranchAddress("OLDpulsesODHG.chID", &OLDpulsesODHG_chID, &b_OLDpulsesODHG_chID);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.chPulseArea_phd", &OLDpulsesODHG_chPulseArea_phd, &b_OLDpulsesODHG_chPulseArea_phd);
	fChain->SetBranchAddress("OLDpulsesODHG.chPeakAmp", &OLDpulsesODHG_chPeakAmp, &b_OLDpulsesODHG_chPeakAmp);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.chPeakTime_ns", &OLDpulsesODHG_chPeakTime_ns, &b_OLDpulsesODHG_chPeakTime_ns);
	fChain->SetBranchAddress("OLDpulsesODHG.chSaturated", &OLDpulsesODHG_chSaturated, &b_OLDpulsesODHG_chSaturated);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.chPhotonCount", &OLDpulsesODHG_chPhotonCount, &b_OLDpulsesODHG_chPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODHG.chPhotonTimes", &OLDpulsesODHG_chPhotonTimes, &b_OLDpulsesODHG_chPhotonTimes);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.TObject.fUniqueID", &OLDpulsesODLG_TObject_fUniqueID, &b_OLDpulsesODLG_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.TObject.fBits", &OLDpulsesODLG_TObject_fBits, &b_OLDpulsesODLG_TObject_fBits);
	fChain->SetBranchAddress("OLDpulsesODLG.nPulses", &OLDpulsesODLG_nPulses, &b_OLDpulsesODLG_nPulses);
	fChain->SetBranchAddress("OLDpulsesODLG.pulseID", &OLDpulsesODLG_pulseID, &b_OLDpulsesODLG_pulseID);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseStartTime_ns", &OLDpulsesODLG_pulseStartTime_ns, &b_OLDpulsesODLG_pulseStartTime_ns);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseEndTime_ns", &OLDpulsesODLG_pulseEndTime_ns, &b_OLDpulsesODLG_pulseEndTime_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.saturated", &OLDpulsesODLG_saturated, &b_OLDpulsesODLG_saturated);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.nSaturatedChannels", &OLDpulsesODLG_nSaturatedChannels, &b_OLDpulsesODLG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.saturatedChannelIDs", &OLDpulsesODLG_saturatedChannelIDs, &b_OLDpulsesODLG_saturatedChannelIDs);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea_phd", &OLDpulsesODLG_pulseArea_phd, &b_OLDpulsesODLG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.positiveArea_phd", &OLDpulsesODLG_positiveArea_phd, &b_OLDpulsesODLG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.negativeArea_phd", &OLDpulsesODLG_negativeArea_phd, &b_OLDpulsesODLG_negativeArea_phd);
	fChain->SetBranchAddress("OLDpulsesODLG.peakAmp", &OLDpulsesODLG_peakAmp, &b_OLDpulsesODLG_peakAmp);
	fChain->SetBranchAddress("OLDpulsesODLG.peakTime_ns", &OLDpulsesODLG_peakTime_ns, &b_OLDpulsesODLG_peakTime_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime1_ns", &OLDpulsesODLG_areaFractionTime1_ns,
	    &b_OLDpulsesODLG_areaFractionTime1_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime5_ns", &OLDpulsesODLG_areaFractionTime5_ns,
	    &b_OLDpulsesODLG_areaFractionTime5_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime10_ns", &OLDpulsesODLG_areaFractionTime10_ns,
	    &b_OLDpulsesODLG_areaFractionTime10_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime25_ns", &OLDpulsesODLG_areaFractionTime25_ns,
	    &b_OLDpulsesODLG_areaFractionTime25_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime50_ns", &OLDpulsesODLG_areaFractionTime50_ns,
	    &b_OLDpulsesODLG_areaFractionTime50_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime75_ns", &OLDpulsesODLG_areaFractionTime75_ns,
	    &b_OLDpulsesODLG_areaFractionTime75_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime90_ns", &OLDpulsesODLG_areaFractionTime90_ns,
	    &b_OLDpulsesODLG_areaFractionTime90_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime95_ns", &OLDpulsesODLG_areaFractionTime95_ns,
	    &b_OLDpulsesODLG_areaFractionTime95_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.areaFractionTime99_ns", &OLDpulsesODLG_areaFractionTime99_ns,
	    &b_OLDpulsesODLG_areaFractionTime99_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.pulseAreaNeg50ns_phd", &OLDpulsesODLG_pulseAreaNeg50ns_phd,
	    &b_OLDpulsesODLG_pulseAreaNeg50ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea50ns_phd", &OLDpulsesODLG_pulseArea50ns_phd, &b_OLDpulsesODLG_pulseArea50ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea100ns_phd", &OLDpulsesODLG_pulseArea100ns_phd, &b_OLDpulsesODLG_pulseArea100ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea200ns_phd", &OLDpulsesODLG_pulseArea200ns_phd, &b_OLDpulsesODLG_pulseArea200ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea500ns_phd", &OLDpulsesODLG_pulseArea500ns_phd, &b_OLDpulsesODLG_pulseArea500ns_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea1us_phd", &OLDpulsesODLG_pulseArea1us_phd, &b_OLDpulsesODLG_pulseArea1us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea2us_phd", &OLDpulsesODLG_pulseArea2us_phd, &b_OLDpulsesODLG_pulseArea2us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.pulseArea5us_phd", &OLDpulsesODLG_pulseArea5us_phd, &b_OLDpulsesODLG_pulseArea5us_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.promptFraction50ns", &OLDpulsesODLG_promptFraction50ns, &b_OLDpulsesODLG_promptFraction50ns);
	fChain->SetBranchAddress("OLDpulsesODLG.rmsWidth_ns", &OLDpulsesODLG_rmsWidth_ns, &b_OLDpulsesODLG_rmsWidth_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.fwhm_ns", &OLDpulsesODLG_fwhm_ns, &b_OLDpulsesODLG_fwhm_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.topArea_phd", &OLDpulsesODLG_topArea_phd, &b_OLDpulsesODLG_topArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.bottomArea_phd", &OLDpulsesODLG_bottomArea_phd, &b_OLDpulsesODLG_bottomArea_phd);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.topBottomAsymmetry", &OLDpulsesODLG_topBottomAsymmetry, &b_OLDpulsesODLG_topBottomAsymmetry);
	fChain->SetBranchAddress("OLDpulsesODLG.coincidence", &OLDpulsesODLG_coincidence, &b_OLDpulsesODLG_coincidence);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.s1Probability", &OLDpulsesODLG_s1Probability, &b_OLDpulsesODLG_s1Probability);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.s2Probability", &OLDpulsesODLG_s2Probability, &b_OLDpulsesODLG_s2Probability);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.singlePEprobability", &OLDpulsesODLG_singlePEprobability, &b_OLDpulsesODLG_singlePEprobability);
	fChain->SetBranchAddress("OLDpulsesODLG.multiplePEprobability", &OLDpulsesODLG_multiplePEprobability,
	    &b_OLDpulsesODLG_multiplePEprobability);
	fChain->SetBranchAddress("OLDpulsesODLG.singleElectronProbability", &OLDpulsesODLG_singleElectronProbability,
	    &b_OLDpulsesODLG_singleElectronProbability);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.otherProbability", &OLDpulsesODLG_otherProbability, &b_OLDpulsesODLG_otherProbability);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.otherS2Probability", &OLDpulsesODLG_otherS2Probability, &b_OLDpulsesODLG_otherS2Probability);
	fChain->SetBranchAddress("OLDpulsesODLG.photonCount", &OLDpulsesODLG_photonCount, &b_OLDpulsesODLG_photonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.topPhotonCount", &OLDpulsesODLG_topPhotonCount, &b_OLDpulsesODLG_topPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.bottomPhotonCount", &OLDpulsesODLG_bottomPhotonCount, &b_OLDpulsesODLG_bottomPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.s2Xposition_cm", &OLDpulsesODLG_s2Xposition_cm, &b_OLDpulsesODLG_s2Xposition_cm);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.s2Yposition_cm", &OLDpulsesODLG_s2Yposition_cm, &b_OLDpulsesODLG_s2Yposition_cm);
	fChain->SetBranchAddress("OLDpulsesODLG.HGLGpulseID", &OLDpulsesODLG_HGLGpulseID, &b_OLDpulsesODLG_HGLGpulseID);
	fChain->SetBranchAddress("OLDpulsesODLG.chID", &OLDpulsesODLG_chID, &b_OLDpulsesODLG_chID);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.chPulseArea_phd", &OLDpulsesODLG_chPulseArea_phd, &b_OLDpulsesODLG_chPulseArea_phd);
	fChain->SetBranchAddress("OLDpulsesODLG.chPeakAmp", &OLDpulsesODLG_chPeakAmp, &b_OLDpulsesODLG_chPeakAmp);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.chPeakTime_ns", &OLDpulsesODLG_chPeakTime_ns, &b_OLDpulsesODLG_chPeakTime_ns);
	fChain->SetBranchAddress("OLDpulsesODLG.chSaturated", &OLDpulsesODLG_chSaturated, &b_OLDpulsesODLG_chSaturated);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.chPhotonCount", &OLDpulsesODLG_chPhotonCount, &b_OLDpulsesODLG_chPhotonCount);
	fChain->SetBranchAddress(
	    "OLDpulsesODLG.chPhotonTimes", &OLDpulsesODLG_chPhotonTimes, &b_OLDpulsesODLG_chPhotonTimes);
	fChain->SetBranchAddress(
	    "pulsesODHG.TObject.fUniqueID", &pulsesODHG_TObject_fUniqueID, &b_pulsesODHG_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesODHG.TObject.fBits", &pulsesODHG_TObject_fBits, &b_pulsesODHG_TObject_fBits);
	fChain->SetBranchAddress("pulsesODHG.nPulses", &pulsesODHG_nPulses, &b_pulsesODHG_nPulses);
	fChain->SetBranchAddress("pulsesODHG.maxCoincidence", &pulsesODHG_maxCoincidence, &b_pulsesODHG_maxCoincidence);
	fChain->SetBranchAddress("pulsesODHG.pulseID", &pulsesODHG_pulseID, &b_pulsesODHG_pulseID);
	fChain->SetBranchAddress(
	    "pulsesODHG.pulseStartTime_ns", &pulsesODHG_pulseStartTime_ns, &b_pulsesODHG_pulseStartTime_ns);
	fChain->SetBranchAddress("pulsesODHG.pulseEndTime_ns", &pulsesODHG_pulseEndTime_ns, &b_pulsesODHG_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesODHG.saturated", &pulsesODHG_saturated, &b_pulsesODHG_saturated);
	fChain->SetBranchAddress(
	    "pulsesODHG.nSaturatedChannels", &pulsesODHG_nSaturatedChannels, &b_pulsesODHG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesODHG.saturatedChannelIDs", &pulsesODHG_saturatedChannelIDs, &b_pulsesODHG_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesODHG.pulseArea_phd", &pulsesODHG_pulseArea_phd, &b_pulsesODHG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "pulsesODHG.positiveArea_phd", &pulsesODHG_positiveArea_phd, &b_pulsesODHG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "pulsesODHG.negativeArea_phd", &pulsesODHG_negativeArea_phd, &b_pulsesODHG_negativeArea_phd);
	fChain->SetBranchAddress("pulsesODHG.peakAmp", &pulsesODHG_peakAmp, &b_pulsesODHG_peakAmp);
	fChain->SetBranchAddress("pulsesODHG.peakTime_ns", &pulsesODHG_peakTime_ns, &b_pulsesODHG_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime1_ns", &pulsesODHG_areaFractionTime1_ns, &b_pulsesODHG_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime5_ns", &pulsesODHG_areaFractionTime5_ns, &b_pulsesODHG_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime10_ns", &pulsesODHG_areaFractionTime10_ns, &b_pulsesODHG_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime25_ns", &pulsesODHG_areaFractionTime25_ns, &b_pulsesODHG_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime50_ns", &pulsesODHG_areaFractionTime50_ns, &b_pulsesODHG_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime75_ns", &pulsesODHG_areaFractionTime75_ns, &b_pulsesODHG_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime90_ns", &pulsesODHG_areaFractionTime90_ns, &b_pulsesODHG_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime95_ns", &pulsesODHG_areaFractionTime95_ns, &b_pulsesODHG_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.areaFractionTime99_ns", &pulsesODHG_areaFractionTime99_ns, &b_pulsesODHG_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.promptFraction200ns", &pulsesODHG_promptFraction200ns, &b_pulsesODHG_promptFraction200ns);
	fChain->SetBranchAddress(
	    "pulsesODHG.promptFraction50ns", &pulsesODHG_promptFraction50ns, &b_pulsesODHG_promptFraction50ns);
	fChain->SetBranchAddress("pulsesODHG.rmsWidth_ns", &pulsesODHG_rmsWidth_ns, &b_pulsesODHG_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesODHG.fwhm_ns", &pulsesODHG_fwhm_ns, &b_pulsesODHG_fwhm_ns);
	fChain->SetBranchAddress("pulsesODHG.coincidence", &pulsesODHG_coincidence, &b_pulsesODHG_coincidence);
	fChain->SetBranchAddress("pulsesODHG.pulseZPosition", &pulsesODHG_pulseZPosition, &b_pulsesODHG_pulseZPosition);
	fChain->SetBranchAddress(
	    "pulsesODHG.pulsePhiPosition", &pulsesODHG_pulsePhiPosition, &b_pulsesODHG_pulsePhiPosition);
	fChain->SetBranchAddress("pulsesODHG.pulseTheta", &pulsesODHG_pulseTheta, &b_pulsesODHG_pulseTheta);
	fChain->SetBranchAddress("pulsesODHG.pulseWaveform", &pulsesODHG_pulseWaveform, &b_pulsesODHG_pulseWaveform);
	fChain->SetBranchAddress("pulsesODHG.chID", &pulsesODHG_chID, &b_pulsesODHG_chID);
	fChain->SetBranchAddress("pulsesODHG.chPulseArea_phd", &pulsesODHG_chPulseArea_phd, &b_pulsesODHG_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesODHG.chPeakAmp", &pulsesODHG_chPeakAmp, &b_pulsesODHG_chPeakAmp);
	fChain->SetBranchAddress("pulsesODHG.chPeakTime_ns", &pulsesODHG_chPeakTime_ns, &b_pulsesODHG_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesODHG.chSaturated", &pulsesODHG_chSaturated, &b_pulsesODHG_chSaturated);
	fChain->SetBranchAddress("pulsesODHG.chPhotonCount", &pulsesODHG_chPhotonCount, &b_pulsesODHG_chPhotonCount);
	fChain->SetBranchAddress("pulsesODHG.chZPosition", &pulsesODHG_chZPosition, &b_pulsesODHG_chZPosition);
	fChain->SetBranchAddress("pulsesODHG.chPhiPosition", &pulsesODHG_chPhiPosition, &b_pulsesODHG_chPhiPosition);
	fChain->SetBranchAddress(
	    "pulsesODLG.TObject.fUniqueID", &pulsesODLG_TObject_fUniqueID, &b_pulsesODLG_TObject_fUniqueID);
	fChain->SetBranchAddress("pulsesODLG.TObject.fBits", &pulsesODLG_TObject_fBits, &b_pulsesODLG_TObject_fBits);
	fChain->SetBranchAddress("pulsesODLG.nPulses", &pulsesODLG_nPulses, &b_pulsesODLG_nPulses);
	fChain->SetBranchAddress("pulsesODLG.maxCoincidence", &pulsesODLG_maxCoincidence, &b_pulsesODLG_maxCoincidence);
	fChain->SetBranchAddress("pulsesODLG.pulseID", &pulsesODLG_pulseID, &b_pulsesODLG_pulseID);
	fChain->SetBranchAddress(
	    "pulsesODLG.pulseStartTime_ns", &pulsesODLG_pulseStartTime_ns, &b_pulsesODLG_pulseStartTime_ns);
	fChain->SetBranchAddress("pulsesODLG.pulseEndTime_ns", &pulsesODLG_pulseEndTime_ns, &b_pulsesODLG_pulseEndTime_ns);
	fChain->SetBranchAddress("pulsesODLG.saturated", &pulsesODLG_saturated, &b_pulsesODLG_saturated);
	fChain->SetBranchAddress(
	    "pulsesODLG.nSaturatedChannels", &pulsesODLG_nSaturatedChannels, &b_pulsesODLG_nSaturatedChannels);
	fChain->SetBranchAddress(
	    "pulsesODLG.saturatedChannelIDs", &pulsesODLG_saturatedChannelIDs, &b_pulsesODLG_saturatedChannelIDs);
	fChain->SetBranchAddress("pulsesODLG.pulseArea_phd", &pulsesODLG_pulseArea_phd, &b_pulsesODLG_pulseArea_phd);
	fChain->SetBranchAddress(
	    "pulsesODLG.positiveArea_phd", &pulsesODLG_positiveArea_phd, &b_pulsesODLG_positiveArea_phd);
	fChain->SetBranchAddress(
	    "pulsesODLG.negativeArea_phd", &pulsesODLG_negativeArea_phd, &b_pulsesODLG_negativeArea_phd);
	fChain->SetBranchAddress("pulsesODLG.peakAmp", &pulsesODLG_peakAmp, &b_pulsesODLG_peakAmp);
	fChain->SetBranchAddress("pulsesODLG.peakTime_ns", &pulsesODLG_peakTime_ns, &b_pulsesODLG_peakTime_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime1_ns", &pulsesODLG_areaFractionTime1_ns, &b_pulsesODLG_areaFractionTime1_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime5_ns", &pulsesODLG_areaFractionTime5_ns, &b_pulsesODLG_areaFractionTime5_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime10_ns", &pulsesODLG_areaFractionTime10_ns, &b_pulsesODLG_areaFractionTime10_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime25_ns", &pulsesODLG_areaFractionTime25_ns, &b_pulsesODLG_areaFractionTime25_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime50_ns", &pulsesODLG_areaFractionTime50_ns, &b_pulsesODLG_areaFractionTime50_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime75_ns", &pulsesODLG_areaFractionTime75_ns, &b_pulsesODLG_areaFractionTime75_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime90_ns", &pulsesODLG_areaFractionTime90_ns, &b_pulsesODLG_areaFractionTime90_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime95_ns", &pulsesODLG_areaFractionTime95_ns, &b_pulsesODLG_areaFractionTime95_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.areaFractionTime99_ns", &pulsesODLG_areaFractionTime99_ns, &b_pulsesODLG_areaFractionTime99_ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.promptFraction200ns", &pulsesODLG_promptFraction200ns, &b_pulsesODLG_promptFraction200ns);
	fChain->SetBranchAddress(
	    "pulsesODLG.promptFraction50ns", &pulsesODLG_promptFraction50ns, &b_pulsesODLG_promptFraction50ns);
	fChain->SetBranchAddress("pulsesODLG.rmsWidth_ns", &pulsesODLG_rmsWidth_ns, &b_pulsesODLG_rmsWidth_ns);
	fChain->SetBranchAddress("pulsesODLG.fwhm_ns", &pulsesODLG_fwhm_ns, &b_pulsesODLG_fwhm_ns);
	fChain->SetBranchAddress("pulsesODLG.coincidence", &pulsesODLG_coincidence, &b_pulsesODLG_coincidence);
	fChain->SetBranchAddress("pulsesODLG.pulseZPosition", &pulsesODLG_pulseZPosition, &b_pulsesODLG_pulseZPosition);
	fChain->SetBranchAddress(
	    "pulsesODLG.pulsePhiPosition", &pulsesODLG_pulsePhiPosition, &b_pulsesODLG_pulsePhiPosition);
	fChain->SetBranchAddress("pulsesODLG.pulseTheta", &pulsesODLG_pulseTheta, &b_pulsesODLG_pulseTheta);
	fChain->SetBranchAddress("pulsesODLG.pulseWaveform", &pulsesODLG_pulseWaveform, &b_pulsesODLG_pulseWaveform);
	fChain->SetBranchAddress("pulsesODLG.chID", &pulsesODLG_chID, &b_pulsesODLG_chID);
	fChain->SetBranchAddress("pulsesODLG.chPulseArea_phd", &pulsesODLG_chPulseArea_phd, &b_pulsesODLG_chPulseArea_phd);
	fChain->SetBranchAddress("pulsesODLG.chPeakAmp", &pulsesODLG_chPeakAmp, &b_pulsesODLG_chPeakAmp);
	fChain->SetBranchAddress("pulsesODLG.chPeakTime_ns", &pulsesODLG_chPeakTime_ns, &b_pulsesODLG_chPeakTime_ns);
	fChain->SetBranchAddress("pulsesODLG.chSaturated", &pulsesODLG_chSaturated, &b_pulsesODLG_chSaturated);
	fChain->SetBranchAddress("pulsesODLG.chPhotonCount", &pulsesODLG_chPhotonCount, &b_pulsesODLG_chPhotonCount);
	fChain->SetBranchAddress("pulsesODLG.chZPosition", &pulsesODLG_chZPosition, &b_pulsesODLG_chZPosition);
	fChain->SetBranchAddress("pulsesODLG.chPhiPosition", &pulsesODLG_chPhiPosition, &b_pulsesODLG_chPhiPosition);
	fChain->SetBranchAddress(
	    "singleScatters.TObject.fUniqueID", &singleScatters_TObject_fUniqueID, &b_singleScatters_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "singleScatters.TObject.fBits", &singleScatters_TObject_fBits, &b_singleScatters_TObject_fBits);
	fChain->SetBranchAddress(
	    "singleScatters.nSingleScatters", &singleScatters_nSingleScatters, &b_singleScatters_nSingleScatters);
	fChain->SetBranchAddress("singleScatters.s1PulseID", &singleScatters_s1PulseID, &b_singleScatters_s1PulseID);
	fChain->SetBranchAddress("singleScatters.s1IsHG", &singleScatters_s1IsHG, &b_singleScatters_s1IsHG);
	fChain->SetBranchAddress("singleScatters.s2PulseID", &singleScatters_s2PulseID, &b_singleScatters_s2PulseID);
	fChain->SetBranchAddress("singleScatters.s2IsHG", &singleScatters_s2IsHG, &b_singleScatters_s2IsHG);
	fChain->SetBranchAddress(
	    "singleScatters.driftTime_ns", &singleScatters_driftTime_ns, &b_singleScatters_driftTime_ns);
	fChain->SetBranchAddress("singleScatters.s1Area_phd", &singleScatters_s1Area_phd, &b_singleScatters_s1Area_phd);
	fChain->SetBranchAddress("singleScatters.s2Area_phd", &singleScatters_s2Area_phd, &b_singleScatters_s2Area_phd);
	fChain->SetBranchAddress(
	    "singleScatters.s1TopArea_phd", &singleScatters_s1TopArea_phd, &b_singleScatters_s1TopArea_phd);
	fChain->SetBranchAddress(
	    "singleScatters.s1BottomArea_phd", &singleScatters_s1BottomArea_phd, &b_singleScatters_s1BottomArea_phd);
	fChain->SetBranchAddress("singleScatters.s1TopCorrectionFactor", &singleScatters_s1TopCorrectionFactor,
	    &b_singleScatters_s1TopCorrectionFactor);
	fChain->SetBranchAddress("singleScatters.s1BottomCorrectionFactor", &singleScatters_s1BottomCorrectionFactor,
	    &b_singleScatters_s1BottomCorrectionFactor);
	fChain->SetBranchAddress("singleScatters.correctedS1TopArea_phd", &singleScatters_correctedS1TopArea_phd,
	    &b_singleScatters_correctedS1TopArea_phd);
	fChain->SetBranchAddress("singleScatters.correctedS1BottomArea_phd", &singleScatters_correctedS1BottomArea_phd,
	    &b_singleScatters_correctedS1BottomArea_phd);
	fChain->SetBranchAddress("singleScatters.correctedS1Area_phd", &singleScatters_correctedS1Area_phd,
	    &b_singleScatters_correctedS1Area_phd);
	fChain->SetBranchAddress(
	    "singleScatters.s2CorrectionFactor", &singleScatters_s2CorrectionFactor, &b_singleScatters_s2CorrectionFactor);
	fChain->SetBranchAddress("singleScatters.correctedS2Area_phd", &singleScatters_correctedS2Area_phd,
	    &b_singleScatters_correctedS2Area_phd);
	fChain->SetBranchAddress("singleScatters.x_cm", &singleScatters_x_cm, &b_singleScatters_x_cm);
	fChain->SetBranchAddress("singleScatters.y_cm", &singleScatters_y_cm, &b_singleScatters_y_cm);
	fChain->SetBranchAddress("singleScatters.xyChi2", &singleScatters_xyChi2, &b_singleScatters_xyChi2);
	fChain->SetBranchAddress(
	    "singleScatters.correctedX_cm", &singleScatters_correctedX_cm, &b_singleScatters_correctedX_cm);
	fChain->SetBranchAddress(
	    "singleScatters.correctedY_cm", &singleScatters_correctedY_cm, &b_singleScatters_correctedY_cm);
	fChain->SetBranchAddress(
	    "singleScatters.correctedZ_cm", &singleScatters_correctedZ_cm, &b_singleScatters_correctedZ_cm);
	fChain->SetBranchAddress(
	    "singleScatters.s1PhotonCount", &singleScatters_s1PhotonCount, &b_singleScatters_s1PhotonCount);
	fChain->SetBranchAddress("singleScatters.correctedS1PhotonCount", &singleScatters_correctedS1PhotonCount,
	    &b_singleScatters_correctedS1PhotonCount);
	fChain->SetBranchAddress(
	    "singleScatters.energyER_keV", &singleScatters_energyER_keV, &b_singleScatters_energyER_keV);
	fChain->SetBranchAddress(
	    "singleScatters.energyNR_keV", &singleScatters_energyNR_keV, &b_singleScatters_energyNR_keV);
	fChain->SetBranchAddress(
	    "singleScatters.skinPromptArea", &singleScatters_skinPromptArea, &b_singleScatters_skinPromptArea);
	fChain->SetBranchAddress(
	    "singleScatters.nSkinPromptPulses", &singleScatters_nSkinPromptPulses, &b_singleScatters_nSkinPromptPulses);
	fChain->SetBranchAddress(
	    "singleScatters.skinPromptPulseIDs", &singleScatters_skinPromptPulseIDs, &b_singleScatters_skinPromptPulseIDs);
	fChain->SetBranchAddress(
	    "singleScatters.odPromptArea", &singleScatters_odPromptArea, &b_singleScatters_odPromptArea);
	fChain->SetBranchAddress(
	    "singleScatters.nODPromptPulses", &singleScatters_nODPromptPulses, &b_singleScatters_nODPromptPulses);
	fChain->SetBranchAddress(
	    "singleScatters.odPromptPulseIDs", &singleScatters_odPromptPulseIDs, &b_singleScatters_odPromptPulseIDs);
	fChain->SetBranchAddress(
	    "singleScatters.odDelayedAreas", &singleScatters_odDelayedAreas, &b_singleScatters_odDelayedAreas);
	fChain->SetBranchAddress(
	    "singleScatters.nODDelayedPulses", &singleScatters_nODDelayedPulses, &b_singleScatters_nODDelayedPulses);
	fChain->SetBranchAddress(
	    "singleScatters.odDelayedPulseIDs", &singleScatters_odDelayedPulseIDs, &b_singleScatters_odDelayedPulseIDs);
	fChain->SetBranchAddress("multipleScatters.TObject.fUniqueID", &multipleScatters_TObject_fUniqueID,
	    &b_multipleScatters_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "multipleScatters.TObject.fBits", &multipleScatters_TObject_fBits, &b_multipleScatters_TObject_fBits);
	fChain->SetBranchAddress("multipleScatters.nMultipleScatters", &multipleScatters_nMultipleScatters,
	    &b_multipleScatters_nMultipleScatters);
	fChain->SetBranchAddress("multipleScatters.s1PulseID", &multipleScatters_s1PulseID, &b_multipleScatters_s1PulseID);
	fChain->SetBranchAddress("multipleScatters.s1IsHG", &multipleScatters_s1IsHG, &b_multipleScatters_s1IsHG);
	fChain->SetBranchAddress(
	    "multipleScatters.s1Area_phd", &multipleScatters_s1Area_phd, &b_multipleScatters_s1Area_phd);
	fChain->SetBranchAddress(
	    "multipleScatters.s1TopArea_phd", &multipleScatters_s1TopArea_phd, &b_multipleScatters_s1TopArea_phd);
	fChain->SetBranchAddress(
	    "multipleScatters.s1BottomArea_phd", &multipleScatters_s1BottomArea_phd, &b_multipleScatters_s1BottomArea_phd);
	fChain->SetBranchAddress("multipleScatters.nS2s", &multipleScatters_nS2s, &b_multipleScatters_nS2s);
	fChain->SetBranchAddress(
	    "multipleScatters.s2PulseIDs", &multipleScatters_s2PulseIDs, &b_multipleScatters_s2PulseIDs);
	fChain->SetBranchAddress("multipleScatters.s2IsHG", &multipleScatters_s2IsHG, &b_multipleScatters_s2IsHG);
	fChain->SetBranchAddress(
	    "multipleScatters.s2Area_phd", &multipleScatters_s2Area_phd, &b_multipleScatters_s2Area_phd);
	fChain->SetBranchAddress("multipleScatters.s1TopCorrectionFactors", &multipleScatters_s1TopCorrectionFactors,
	    &b_multipleScatters_s1TopCorrectionFactors);
	fChain->SetBranchAddress("multipleScatters.s1BottomCorrectionFactors", &multipleScatters_s1BottomCorrectionFactors,
	    &b_multipleScatters_s1BottomCorrectionFactors);
	fChain->SetBranchAddress("multipleScatters.correctedS1TopAreas_phd", &multipleScatters_correctedS1TopAreas_phd,
	    &b_multipleScatters_correctedS1TopAreas_phd);
	fChain->SetBranchAddress("multipleScatters.correctedS1BottomAreas_phd",
	    &multipleScatters_correctedS1BottomAreas_phd, &b_multipleScatters_correctedS1BottomAreas_phd);
	fChain->SetBranchAddress("multipleScatters.correctedS1Areas_phd", &multipleScatters_correctedS1Areas_phd,
	    &b_multipleScatters_correctedS1Areas_phd);
	fChain->SetBranchAddress("multipleScatters.s2CorrectionFactors", &multipleScatters_s2CorrectionFactors,
	    &b_multipleScatters_s2CorrectionFactors);
	fChain->SetBranchAddress("multipleScatters.correctedS2Area_phd", &multipleScatters_correctedS2Area_phd,
	    &b_multipleScatters_correctedS2Area_phd);
	fChain->SetBranchAddress(
	    "multipleScatters.driftTime_ns", &multipleScatters_driftTime_ns, &b_multipleScatters_driftTime_ns);
	fChain->SetBranchAddress("multipleScatters.weightedDriftTime_ns", &multipleScatters_weightedDriftTime_ns,
	    &b_multipleScatters_weightedDriftTime_ns);
	fChain->SetBranchAddress("multipleScatters.x_cm", &multipleScatters_x_cm, &b_multipleScatters_x_cm);
	fChain->SetBranchAddress("multipleScatters.y_cm", &multipleScatters_y_cm, &b_multipleScatters_y_cm);
	fChain->SetBranchAddress(
	    "multipleScatters.correctedX_cm", &multipleScatters_correctedX_cm, &b_multipleScatters_correctedX_cm);
	fChain->SetBranchAddress(
	    "multipleScatters.correctedY_cm", &multipleScatters_correctedY_cm, &b_multipleScatters_correctedY_cm);
	fChain->SetBranchAddress(
	    "multipleScatters.correctedZ_cm", &multipleScatters_correctedZ_cm, &b_multipleScatters_correctedZ_cm);
	fChain->SetBranchAddress(
	    "multipleScatters.energyER_keV", &multipleScatters_energyER_keV, &b_multipleScatters_energyER_keV);
	fChain->SetBranchAddress(
	    "multipleScatters.energyNR_keV", &multipleScatters_energyNR_keV, &b_multipleScatters_energyNR_keV);
	fChain->SetBranchAddress(
	    "kr83mScatters.TObject.fUniqueID", &kr83mScatters_TObject_fUniqueID, &b_kr83mScatters_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "kr83mScatters.TObject.fBits", &kr83mScatters_TObject_fBits, &b_kr83mScatters_TObject_fBits);
	fChain->SetBranchAddress(
	    "kr83mScatters.nKr83mScatters", &kr83mScatters_nKr83mScatters, &b_kr83mScatters_nKr83mScatters);
	fChain->SetBranchAddress("kr83mScatters.s1aPulseID", &kr83mScatters_s1aPulseID, &b_kr83mScatters_s1aPulseID);
	fChain->SetBranchAddress("kr83mScatters.s1aArea_phd", &kr83mScatters_s1aArea_phd, &b_kr83mScatters_s1aArea_phd);
	fChain->SetBranchAddress("kr83mScatters.s1bPulseID", &kr83mScatters_s1bPulseID, &b_kr83mScatters_s1bPulseID);
	fChain->SetBranchAddress("kr83mScatters.s1bArea_phd", &kr83mScatters_s1bArea_phd, &b_kr83mScatters_s1bArea_phd);
	fChain->SetBranchAddress("kr83mScatters.s2PulseID", &kr83mScatters_s2PulseID, &b_kr83mScatters_s2PulseID);
	fChain->SetBranchAddress("kr83mScatters.s2Area_phd", &kr83mScatters_s2Area_phd, &b_kr83mScatters_s2Area_phd);
	fChain->SetBranchAddress("kr83mScatters.driftTime_ns", &kr83mScatters_driftTime_ns, &b_kr83mScatters_driftTime_ns);
	fChain->SetBranchAddress("kr83mScatters.x_cm", &kr83mScatters_x_cm, &b_kr83mScatters_x_cm);
	fChain->SetBranchAddress("kr83mScatters.y_cm", &kr83mScatters_y_cm, &b_kr83mScatters_y_cm);
	fChain->SetBranchAddress(
	    "kr83mScatters.correctedX_cm", &kr83mScatters_correctedX_cm, &b_kr83mScatters_correctedX_cm);
	fChain->SetBranchAddress(
	    "kr83mScatters.correctedY_cm", &kr83mScatters_correctedY_cm, &b_kr83mScatters_correctedY_cm);
	fChain->SetBranchAddress(
	    "kr83mScatters.correctedZ_cm", &kr83mScatters_correctedZ_cm, &b_kr83mScatters_correctedZ_cm);
	fChain->SetBranchAddress("kr83mScatters.energy_keV", &kr83mScatters_energy_keV, &b_kr83mScatters_energy_keV);
	fChain->SetBranchAddress(
	    "otherScatters.TObject.fUniqueID", &otherScatters_TObject_fUniqueID, &b_otherScatters_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "otherScatters.TObject.fBits", &otherScatters_TObject_fBits, &b_otherScatters_TObject_fBits);
	fChain->SetBranchAddress(
	    "otherScatters.nOtherScatters", &otherScatters_nOtherScatters, &b_otherScatters_nOtherScatters);
	fChain->SetBranchAddress("otherScatters.nS1s", &otherScatters_nS1s, &b_otherScatters_nS1s);
	fChain->SetBranchAddress("otherScatters.s1PulseIDs", &otherScatters_s1PulseIDs, &b_otherScatters_s1PulseIDs);
	fChain->SetBranchAddress("otherScatters.nS2s", &otherScatters_nS2s, &b_otherScatters_nS2s);
	fChain->SetBranchAddress("otherScatters.s2PulseIDs", &otherScatters_s2PulseIDs, &b_otherScatters_s2PulseIDs);
	fChain->SetBranchAddress("otherScatters.nSPEs", &otherScatters_nSPEs, &b_otherScatters_nSPEs);
	fChain->SetBranchAddress("otherScatters.spePulseIDs", &otherScatters_spePulseIDs, &b_otherScatters_spePulseIDs);
	fChain->SetBranchAddress("otherScatters.nSEs", &otherScatters_nSEs, &b_otherScatters_nSEs);
	fChain->SetBranchAddress("otherScatters.sePulseIDs", &otherScatters_sePulseIDs, &b_otherScatters_sePulseIDs);
	fChain->SetBranchAddress("otherScatters.nOthers", &otherScatters_nOthers, &b_otherScatters_nOthers);
	fChain->SetBranchAddress(
	    "otherScatters.otherPulseIDs", &otherScatters_otherPulseIDs, &b_otherScatters_otherPulseIDs);
	fChain->SetBranchAddress(
	    "pileUpScatters.TObject.fUniqueID", &pileUpScatters_TObject_fUniqueID, &b_pileUpScatters_TObject_fUniqueID);
	fChain->SetBranchAddress(
	    "pileUpScatters.TObject.fBits", &pileUpScatters_TObject_fBits, &b_pileUpScatters_TObject_fBits);
	fChain->SetBranchAddress(
	    "pileUpScatters.nPileUpScatters", &pileUpScatters_nPileUpScatters, &b_pileUpScatters_nPileUpScatters);
	fChain->SetBranchAddress("pileUpScatters.nS1", &pileUpScatters_nS1, &b_pileUpScatters_nS1);
	fChain->SetBranchAddress("pileUpScatters.s1PulseIDs", &pileUpScatters_s1PulseIDs, &b_pileUpScatters_s1PulseIDs);
	fChain->SetBranchAddress("pileUpScatters.nS2", &pileUpScatters_nS2, &b_pileUpScatters_nS2);
	fChain->SetBranchAddress("pileUpScatters.s2PulseIDs", &pileUpScatters_s2PulseIDs, &b_pileUpScatters_s2PulseIDs);
	Notify();
}

Bool_t ODChannels::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}

void ODChannels::Show(Long64_t entry)
{
	// Print contents of entry.
	// If entry is not specified, print current entry
	if (!fChain)
		return;
	fChain->Show(entry);
}
Int_t ODChannels::Cut(Long64_t entry)
{
	// This function may be called from Loop.
	// returns  1 if entry is accepted.
	// returns -1 otherwise.
	return 1;
}
#endif // #ifdef ODChannels_cxx
