/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_VOICE_ENGINE_TEST_CHANNEL_TRANSPORT_SERVER_CHANNEL_TRANSPORT_H_
#define WEBRTC_VOICE_ENGINE_TEST_CHANNEL_TRANSPORT_SERVER_CHANNEL_TRANSPORT_H_
#include <cstdint>

namespace webrtc {

class VosENetwork;

namespace test {

class  UdpTransport;

// Helper class for VoiceEngine tests.
class VoiceServerChannelTransport
{
 public:
     VoiceServerChannelTransport(VosENetwork* voe_network, int channel);

  virtual ~VoiceServerChannelTransport();

  // Specifies the destination port and IP address for a specified channel.
  int SetSendDestination(const char* ip_address, uint16_t rtp_port);

  int SetLocalPort(uint16_t rtp_port);

  int32_t SourcePorts(uint16_t& rtpPort, uint16_t& rtcpPort);

 private:
  int channel_;
  bool firstRtp_;
  bool back2peer_;
  VosENetwork* vose_network_;
  UdpTransport* socket_transport_;
};

}  // namespace test
}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_TEST_CHANNEL_TRANSPORT_CHANNEL_TRANSPORT_H_
