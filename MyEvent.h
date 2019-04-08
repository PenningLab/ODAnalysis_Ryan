#ifndef MYEVENT_H
#define MYEVENT_H

#include "rqlib/rqlibProjectHeaders.h"
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace DetectorEnum
{
typedef int Detector;

static const Detector kNone = 0x00;

static const Detector kTpcHighGain = 0x01;

static const Detector kTpcLowGain = kTpcHighGain << 1;

static const Detector kSkin = kTpcLowGain << 1;

static const Detector kOuter = kSkin << 1;

static const Detector kOuterHighGain = kOuter;

static const Detector kOuterLowGain = kOuterHighGain << 1;

static const size_t kDetectorCount = 3;

static std::string kNoneString = "None";

static std::string kOuterLGString = "ODLG";

static std::string kOuterHGString = "ODHG";

static std::string kTpcLGString = "TPCLG";

static std::string kTpcHGString = "TPCHG";

static std::string kSkinString = "Skin";

const std::string& toString(Detector detector)
{
    if (kTpcHighGain == detector)
        return kTpcHGString;
    if (kTpcLowGain == detector)
        return kTpcLGString;
    if (kOuterLowGain == detector)
        return kOuterLGString;
    if (kOuterHighGain == detector)
        return kOuterHGString;
    if (kSkin == detector)
        return kSkinString;

    return kNoneString;
}

}; // namespace DetectorEnum

class MyEvent
{
public:
    MyEvent()
    {
    }
    virtual ~MyEvent()
    {
    }
    // TChain*  chain;

    //------------------------------------------------
    // Variable for extraction
    //------------------------------------------------

    std::shared_ptr<RQ::EventHeader> eHead;
    std::shared_ptr<RQ::DetectorPulses> tpcHG;
    std::shared_ptr<RQ::DetectorPulses> tpcLG;
    std::shared_ptr<RQ::DetectorPulses> skin;
    std::shared_ptr<RQ::ODPulses> ODHG;
    std::shared_ptr<RQ::ODPulses> ODLG;
};

#endif // MYEVENT_H
