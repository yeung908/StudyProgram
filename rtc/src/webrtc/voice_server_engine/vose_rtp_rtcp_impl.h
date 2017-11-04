#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_RTP_RTCP_IMPL_H
#define WEBRTC_VOICE_SERVER_ENGINE_VOSE_RTP_RTCP_IMPL_H

#include "webrtc/voice_server_engine/include/vose_rtp_rtcp.h"

#include "webrtc/voice_server_engine/shared_data.h"

namespace webrtc
{

    class VosERTP_RTCPImpl : public VosERTP_RTCP
    {
    public:
        // RTCP
        int SetRTCPStatus(int channel, bool enable) override;

        int GetRTCPStatus(int channel, bool& enabled) override;

        int SetRTCP_CNAME(int channel, const char cName[256]) override;

        int GetRemoteRTCP_CNAME(int channel, char cName[256]) override;

        int GetRemoteRTCPData(int channel,
            unsigned int& NTPHigh,
            unsigned int& NTPLow,
            unsigned int& timestamp,
            unsigned int& playoutTimestamp,
            unsigned int* jitter = NULL,
            unsigned short* fractionLost = NULL) override;

        // SSRC
        int SetLocalSSRC(int channel, unsigned int ssrc) override;

        int GetLocalSSRC(int channel, unsigned int& ssrc) override;

        int GetRemoteSSRC(int channel, unsigned int& ssrc) override;

        // RTP Header Extension for Client-to-Mixer Audio Level Indication
        int SetSendAudioLevelIndicationStatus(int channel,
            bool enable,
            unsigned char id) override;
        int SetReceiveAudioLevelIndicationStatus(int channel,
            bool enable,
            unsigned char id) override;

        // Statistics
        int GetRTPStatistics(int channel,
            unsigned int& averageJitterMs,
            unsigned int& maxJitterMs,
            unsigned int& discardedPackets) override;

        int GetRTCPStatistics(int channel, CallStatistics& stats) override;

        int GetRemoteRTCPReportBlocks(
            int channel,
            std::vector<ReportBlock>* report_blocks) override;

        // NACK
        int SetNACKStatus(int channel, bool enable, int maxNoPackets) override;

    protected:
        VosERTP_RTCPImpl(vose::SharedData* shared);
        ~VosERTP_RTCPImpl() override;

    private:
        vose::SharedData* _shared;
    };

}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_VOE_RTP_RTCP_IMPL_H
