#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_NETEQ_STATS_H
#define WEBRTC_VOICE_SERVER_ENGINE_VOSE_NETEQ_STATS_H

#include "webrtc/common_types.h"

namespace webrtc
{

    class VoiceServerEngine;

    class WEBRTC_DLLEXPORT VosENetEqStats
    {
    public:
        // Factory for the VoENetEqStats sub-API. Increases an internal
        // reference counter if successful. Returns NULL if the API is not
        // supported or if construction fails.
        static VosENetEqStats* GetInterface(VoiceServerEngine* voiceEngine);

        // Releases the VoENetEqStats sub-API and decreases an internal
        // reference counter. Returns the new reference count. This value should
        // be zero for all sub-API:s before the VoiceEngine object can be safely
        // deleted.
        virtual int Release() = 0;

        // Get the "in-call" statistics from NetEQ.
        // The statistics are reset after the query.
        virtual int GetNetworkStatistics(int channel, NetworkStatistics& stats) = 0;

        // Get statistics of calls to AudioCodingModule::PlayoutData10Ms().
        virtual int GetDecodingCallStatistics(
            int channel,
            AudioDecodingCallStats* stats) const = 0;

    protected:
        VosENetEqStats() {}
        virtual ~VosENetEqStats() {}
    };

}  // namespace webrtc

#endif  // #ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_NETEQ_STATS_H
