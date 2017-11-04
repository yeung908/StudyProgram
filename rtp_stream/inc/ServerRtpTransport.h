#pragma once
#include <string>
#include "webrtc/api/call/transport.h"

namespace vcs
{
class ServerRtpStream;
class ServerRtpTransport : public webrtc::Transport
{
public:
    explicit ServerRtpTransport(ServerRtpStream *stream);

    virtual bool SendRtp(const uint8_t* packet, size_t length, const webrtc::PacketOptions& options) override;

    virtual bool SendRtcp(const uint8_t* packet, size_t length) override;

    inline void SetRemoteAddr(const std::string &ip, uint16_t rtpPort, uint16_t rtcpPort)
    {
        ip_ = ip;
        rtpPort_ = rtpPort;
        rtcpPort_ = rtcpPort;
    }

    inline void GetRemoteAddr(std::string &ip, uint16_t &rtpPort, uint16_t rtcpPort)
    {
        ip = ip_;
        rtpPort = rtpPort_;
        rtcpPort = rtcpPort_;
    }
private:
    ServerRtpStream *stream_;
    std::string ip_;
    uint16_t rtpPort_;
    uint16_t rtcpPort_;
};
}
