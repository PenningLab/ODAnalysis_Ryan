#ifndef PulseMapping_h
#define PulseMapping_h

#include "rqlib/RQ__DetectorPulses.h"
#include "rqlib/RQ__EventHeader.h"
#include "rqlib/RQ__Kr83mScatters.h"
#include "rqlib/RQ__MultipleScatters.h"
#include "rqlib/RQ__ODPulses.h"
#include "rqlib/RQ__OtherScatters.h"
#include "rqlib/RQ__PileUpScatters.h"
#include "rqlib/RQ__SingleScatters.h"

#include <map>
#include <string>
#include <vector>

namespace PulseMapping
{
enum class paramsOD
{
    kPulseID,
    kPulseStartTime,
    kPulseEndTime,
    kSaturated,
    kSaturatedChannels,
    kPulseArea,
    kPositiveArea,
    kNegativeArea,
    kPeakAmp,
    kPeakTime,
    kAft1,
    kAft5,
    kAft10,
    kAft25,
    kAft50,
    kAft75,
    kAft90,
    kAft95,
    kAft99,
    kPromptFrac200,
    kPromptFrac50,
    kRmsWidth,
    kCoincidence
};
std::map<std::string, paramsOD> paraMapOD { { "pulseID",paramsOD::kPulseID },
    { "pulseStartTime",paramsOD::kPulseStartTime }, { "pulseEndTime",paramsOD::kPulseEndTime },
    { "saturated",paramsOD::kSaturated }, { "saturatedChannels",paramsOD::kSaturatedChannels },
    { "pulseArea",paramsOD::kPulseArea }, { "positiveArea",paramsOD::kPositiveArea },
    { "negativeArea",paramsOD::kNegativeArea }, { "peakAmp",paramsOD::kPeakAmp }, { "peakTime",paramsOD::kPeakTime },
    { "aft1",paramsOD::kAft1 }, { "aft5",paramsOD::kAft5 }, { "aft10",paramsOD::kAft10 }, { "aft25",paramsOD::kAft25 },
    { "aft50",paramsOD::kAft50 }, { "aft75",paramsOD::kAft75 }, { "aft90",paramsOD::kAft90 }, { "aft95",paramsOD::kAft95 },
    { "aft99",paramsOD::kAft99 }, { "promptFrac200",paramsOD::kPromptFrac200 }, { "promtFrac50",paramsOD::kPromptFrac50 },
    { "rmsWidth",paramsOD::kRmsWidth }, { "coincidence",paramsOD::kCoincidence } };
auto getODParam(RQ::ODPulses* pulses, std::string param)
{
    // WARNING::Be VERY careful with types when using this function!!!!!!! Returns
    // ODPulses member param mapped to char* param
    if (paraMapOD.find(param) == paraMapOD.end())
    {
        std::cout << "Failed to find parameter in map." << std::endl;
        return nullptr;
    }
    switch (paraMapOD[param])
    {
    case paramsOD::kPulseID:
        return &(pulses->pulseID);
    case paramsOD::kPulseStartTime:
        return &(pulses->pulseStartTime_ns);
    case paramsOD::kPulseEndTime:
        return &(pulses->pulseEndTime_ns);
    case paramsOD::kSaturated:
        return &(pulses->saturated);
    case paramsOD::kSaturatedChannels:
        return &(pulses->nSaturatedChannels);
    case paramsOD::kPulseArea:
        return &(pulses->pulseArea_phd);
    case paramsOD::kPositiveArea:
        return &(pulses->positiveArea_phd);
    case paramsOD::kNegativeArea:
        return &(pulses->negativeArea_phd);
    case paramsOD::kPeakAmp:
        return &(pulses->peakAmp);
    case paramsOD::kPeakTime:
        return &(pulses->peakTime_ns);
    case paramsOD::kAft1:
        return &(pulses->areaFractionTime1_ns);
    case paramsOD::kAft5:
        return &(pulses->areaFractionTime5_ns);
    case paramsOD::kAft10:
        return &(pulses->areaFractionTime10_ns);
    case paramsOD::kAft25:
        return &(pulses->areaFractionTime25_ns);
    case paramsOD::kAft50:
        return &(pulses->areaFractionTime50_ns);
    case paramsOD::kAft75:
        return &(pulses->areaFractionTime75_ns);
    case paramsOD::kAft90:
        return &(pulses->areaFractionTime90_ns);
    case paramsOD::kAft95:
        return &(pulses->areaFractionTime95_ns);
    case paramsOD::kAft99:
        return &(pulses->areaFractionTime99_ns);
    case paramsOD::kPromptFrac200:
        return &(pulses->promptFraction200ns);
    case paramsOD::kPromptFrac50:
        return &(pulses->promptFraction50ns);
    case paramsOD::kRmsWidth:
        return &(pulses->rmsWidth_ns);
    case paramsOD::kCoincidence:
        return &(pulses->coincidence);
    }
}
}
#endif
