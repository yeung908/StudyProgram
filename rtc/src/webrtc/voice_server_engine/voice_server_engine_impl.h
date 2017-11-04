/*
*  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
*
*  Use of this source code is governed by a BSD-style license
*  that can be found in the LICENSE file in the root of the source
*  tree. An additional intellectual property rights grant can be found
*  in the file PATENTS.  All contributing project authors may
*  be found in the AUTHORS file in the root of the source tree.
*/

#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOICE_SERVER_ENGINE_IMPL_H
#define WEBRTC_VOICE_SERVER_ENGINE_VOICE_SERVER_ENGINE_IMPL_H

#include <memory>

#include "webrtc/system_wrappers/include/atomic32.h"
#include "webrtc/typedefs.h"
#include "webrtc/voice_server_engine/vose_base_impl.h"
//#include "webrtc/voice_engine/voe_audio_processing_impl.h"
#include "webrtc/voice_server_engine/vose_codec_impl.h"
#include "webrtc/voice_server_engine/vose_file_impl.h"
#include "webrtc/voice_server_engine/vose_neteq_stats_impl.h"
#include "webrtc/voice_server_engine/vose_network_impl.h"
#include "webrtc/voice_server_engine/vose_rtp_rtcp_impl.h"

namespace webrtc
{

    class VoiceServerEngineImpl : public vose::SharedData,  // Must be the first base class
        public VoiceServerEngine,
        //public VoEAudioProcessingImpl,
        public VosECodecImpl,
        public VosEFileImpl,
        public VosENetEqStatsImpl,
        public VosENetworkImpl,
        public VosERTP_RTCPImpl,
        public VosEBaseImpl
    {
    public:
        VoiceServerEngineImpl()
            : SharedData(),
            //VoEAudioProcessingImpl(this),
            VosECodecImpl(this),
            VosEFileImpl(this),
            VosENetEqStatsImpl(this),
            VosENetworkImpl(this),
            VosERTP_RTCPImpl(this),
            VosEBaseImpl(this),
            _ref_count(0)
        {}
        ~VoiceServerEngineImpl() override { assert(_ref_count.Value() == 0); }

        int AddRef();

        // This implements the Release() method for all the inherited interfaces.
        int Release() override;

    protected:
        Atomic32 _ref_count;
    };

}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_VOICE_ENGINE_IMPL_H
