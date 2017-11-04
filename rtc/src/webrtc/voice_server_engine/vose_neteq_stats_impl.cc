/*
*  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
*
*  Use of this source code is governed by a BSD-style license
*  that can be found in the LICENSE file in the root of the source
*  tree. An additional intellectual property rights grant can be found
*  in the file PATENTS.  All contributing project authors may
*  be found in the AUTHORS file in the root of the source tree.
*/

#include "webrtc/voice_server_engine/vose_neteq_stats_impl.h"

#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/voice_server_engine/voice_server_engine_impl.h"

namespace webrtc
{

    VosENetEqStats* VosENetEqStats::GetInterface(VoiceServerEngine* voiceEngine)
    {
        if (NULL == voiceEngine) {
            return NULL;
        }
        VoiceServerEngineImpl* s = static_cast<VoiceServerEngineImpl*>(voiceEngine);
        s->AddRef();
        return s;
    }

    VosENetEqStatsImpl::VosENetEqStatsImpl(vose::SharedData* shared)
        : _shared(shared)
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosENetEqStatsImpl::VosENetEqStatsImpl() - ctor");
    }

    VosENetEqStatsImpl::~VosENetEqStatsImpl()
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosENetEqStatsImpl::~VosENetEqStatsImpl() - dtor");
    }

    int VosENetEqStatsImpl::GetNetworkStatistics(int channel,
        NetworkStatistics& stats)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetNetworkStatistics() failed to locate channel");
            return -1;
        }

        return channelPtr->GetNetworkStatistics(stats);
    }

    int VosENetEqStatsImpl::GetDecodingCallStatistics(
        int channel, AudioDecodingCallStats* stats) const
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "GetDecodingCallStatistics() failed to locate "
                "channel");
            return -1;
        }

        channelPtr->GetDecodingCallStatistics(stats);
        return 0;
    }

}  // namespace webrtc
