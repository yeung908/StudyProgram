/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <stdio.h>
#include "webrtc/voice_engine/test/channel_transport/server_channel_transport.h"
#include "webrtc/voice_engine/test/channel_transport/udp_transport.h"
#include "webrtc/voice_server_engine/include/vose_network.h"


namespace webrtc
{
namespace test
{

VoiceServerChannelTransport::VoiceServerChannelTransport(VosENetwork* voe_network,
    int channel)
    : channel_(channel),
    firstRtp_(true),
    back2peer_(true),
    vose_network_(voe_network)
{
    uint8_t socket_threads = 1;
    socket_transport_ = UdpTransport::Create(channel, socket_threads);
    int registered = vose_network_->RegisterExternalTransport(channel,
        *socket_transport_);
#if !defined(WEBRTC_ANDROID) && !defined(WEBRTC_IOS)
    //EXPECT_EQ(0, registered);
#else
    //assert(registered == 0);
#endif
}

VoiceServerChannelTransport::~VoiceServerChannelTransport()
{
    vose_network_->DeRegisterExternalTransport(channel_);
    UdpTransport::Destroy(socket_transport_);
}

int VoiceServerChannelTransport::SetSendDestination(const char* ip_address,
    uint16_t rtp_port)
{
    int ret = -1;
    if (!socket_transport_->SendSocketsInitialized()) {
        ret = socket_transport_->InitializeSendSockets(ip_address, rtp_port);
    } else {
        ret = socket_transport_->SetSendIP(ip_address);
        ret = socket_transport_->SetSendPorts(rtp_port);
    }

    return ret;
}


int VoiceServerChannelTransport::SetLocalPort(uint16_t rtp_port)
{
    return socket_transport_->InitializeSourcePorts(rtp_port);
}

int32_t VoiceServerChannelTransport::SourcePorts(uint16_t& rtpPort, uint16_t& rtcpPort)
{
    return socket_transport_->SourcePorts(rtpPort, rtcpPort);
}

}  // namespace test
}  // namespace webrtc
