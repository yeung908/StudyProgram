#include "webrtc/system_wrappers/include/file_wrapper.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/voice_server_engine/vose_rtp_rtcp_impl.h"
#include "webrtc/voice_server_engine/voice_server_engine_impl.h"

#include "webrtc/voice_server_engine/channel.h"

namespace webrtc
{
    VosERTP_RTCP* VosERTP_RTCP::GetInterface(VoiceServerEngine* voiceServerEngine)
    {
        if (NULL == voiceServerEngine) {
            return NULL;
        }
        VoiceServerEngineImpl* s = static_cast<VoiceServerEngineImpl*>(voiceServerEngine);
        s->AddRef();
        return s;
    }

    VosERTP_RTCPImpl::VosERTP_RTCPImpl(vose::SharedData* shared) : _shared(shared)
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosERTP_RTCPImpl::VosERTP_RTCPImpl() - ctor");
    }

    VosERTP_RTCPImpl::~VosERTP_RTCPImpl()
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosERTP_RTCPImpl::~VosERTP_RTCPImpl() - dtor");
    }

    int VosERTP_RTCPImpl::SetLocalSSRC(int channel, unsigned int ssrc)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetLocalSSRC(channel=%d, %lu)", channel, ssrc);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "SetLocalSSRC() failed to locate channel");
            return -1;
        }
        return channelPtr->SetLocalSSRC(ssrc);
    }

    int VosERTP_RTCPImpl::GetLocalSSRC(int channel, unsigned int& ssrc)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetLocalSSRC() failed to locate channel");
            return -1;
        }
        return channelPtr->GetLocalSSRC(ssrc);
    }

    int VosERTP_RTCPImpl::GetRemoteSSRC(int channel, unsigned int& ssrc)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRemoteSSRC() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRemoteSSRC(ssrc);
    }

    int VosERTP_RTCPImpl::SetSendAudioLevelIndicationStatus(int channel,
        bool enable,
        unsigned char id)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetSendAudioLevelIndicationStatus(channel=%d, enable=%d,"
            " ID=%u)",
            channel, enable, id);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        if (enable && (id < kVoiceEngineMinRtpExtensionId ||
            id > kVoiceEngineMaxRtpExtensionId)) {
            // [RFC5285] The 4-bit id is the local identifier of this element in
            // the range 1-14 inclusive.
            _shared->SetLastError(
                VE_INVALID_ARGUMENT, kTraceError,
                "SetSendAudioLevelIndicationStatus() invalid ID parameter");
            return -1;
        }

        // Set state and id for the specified channel.
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(
                VE_CHANNEL_NOT_VALID, kTraceError,
                "SetSendAudioLevelIndicationStatus() failed to locate channel");
            return -1;
        }
        return channelPtr->SetSendAudioLevelIndicationStatus(enable, id);
    }

    int VosERTP_RTCPImpl::SetReceiveAudioLevelIndicationStatus(int channel,
        bool enable,
        unsigned char id)
    {
        WEBRTC_TRACE(
            kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetReceiveAudioLevelIndicationStatus(channel=%d, enable=%d, id=%u)",
            channel, enable, id);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        if (enable && (id < kVoiceEngineMinRtpExtensionId ||
            id > kVoiceEngineMaxRtpExtensionId)) {
            // [RFC5285] The 4-bit id is the local identifier of this element in
            // the range 1-14 inclusive.
            _shared->SetLastError(
                VE_INVALID_ARGUMENT, kTraceError,
                "SetReceiveAudioLevelIndicationStatus() invalid id parameter");
            return -1;
        }
        // Set state and id for the specified channel.
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channel_ptr = ch.channel();
        if (channel_ptr == NULL) {
            _shared->SetLastError(
                VE_CHANNEL_NOT_VALID, kTraceError,
                "SetReceiveAudioLevelIndicationStatus() failed to locate channel");
            return -1;
        }
        return channel_ptr->SetReceiveAudioLevelIndicationStatus(enable, id);
    }

    int VosERTP_RTCPImpl::SetRTCPStatus(int channel, bool enable)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetRTCPStatus(channel=%d, enable=%d)", channel, enable);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "SetRTCPStatus() failed to locate channel");
            return -1;
        }
        channelPtr->SetRTCPStatus(enable);
        return 0;
    }

    int VosERTP_RTCPImpl::GetRTCPStatus(int channel, bool& enabled)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRTCPStatus() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRTCPStatus(enabled);
    }

    int VosERTP_RTCPImpl::SetRTCP_CNAME(int channel, const char cName[256])
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetRTCP_CNAME(channel=%d, cName=%s)", channel, cName);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "SetRTCP_CNAME() failed to locate channel");
            return -1;
        }
        return channelPtr->SetRTCP_CNAME(cName);
    }

    int VosERTP_RTCPImpl::GetRemoteRTCP_CNAME(int channel, char cName[256])
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRemoteRTCP_CNAME() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRemoteRTCP_CNAME(cName);
    }

    int VosERTP_RTCPImpl::GetRemoteRTCPData(
        int channel,
        unsigned int& NTPHigh,           // from sender info in SR
        unsigned int& NTPLow,            // from sender info in SR
        unsigned int& timestamp,         // from sender info in SR
        unsigned int& playoutTimestamp,  // derived locally
        unsigned int* jitter,            // from report block 1 in SR/RR
        unsigned short* fractionLost)    // from report block 1 in SR/RR
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRemoteRTCP_CNAME() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRemoteRTCPData(NTPHigh, NTPLow, timestamp,
            playoutTimestamp, jitter, fractionLost);
    }

    int VosERTP_RTCPImpl::GetRTPStatistics(int channel,
        unsigned int& averageJitterMs,
        unsigned int& maxJitterMs,
        unsigned int& discardedPackets)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRTPStatistics() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRTPStatistics(averageJitterMs, maxJitterMs,
            discardedPackets);
    }

    int VosERTP_RTCPImpl::GetRTCPStatistics(int channel, CallStatistics& stats)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRTPStatistics() failed to locate channel");
            return -1;
        }
        return channelPtr->GetRTPStatistics(stats);
    }

    int VosERTP_RTCPImpl::GetRemoteRTCPReportBlocks(
        int channel, std::vector<ReportBlock>* report_blocks)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channel_ptr = ch.channel();
        if (channel_ptr == NULL) {
            _shared->SetLastError(
                VE_CHANNEL_NOT_VALID, kTraceError,
                "GetRemoteRTCPReportBlocks() failed to locate channel");
            return -1;
        }
        return channel_ptr->GetRemoteRTCPReportBlocks(report_blocks);
    }

    int VosERTP_RTCPImpl::SetNACKStatus(int channel, bool enable, int maxNoPackets)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "SetNACKStatus(channel=%d, enable=%d, maxNoPackets=%d)", channel,
            enable, maxNoPackets);

        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "SetNACKStatus() failed to locate channel");
            return -1;
        }
        channelPtr->SetNACKStatus(enable, maxNoPackets);
        return 0;
    }

}  // namespace webrtc
