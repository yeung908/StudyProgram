#include "ServerRtpTransport.h"
#include "ServerRtpStream.h"

namespace vcs
{
ServerRtpTransport::ServerRtpTransport(ServerRtpStream *stream)
    :stream_(stream), rtpPort_(0)
{
}

bool ServerRtpTransport::SendRtp(const uint8_t* packet, size_t length, const webrtc::PacketOptions& options)
{
    bool ret = false;
    if (stream_ && rtpPort_ != 0)
    {
        stream_->sendRTP(packet, length, ip_.c_str(), rtpPort_);
        ret = true;
    }
    return ret;
}

bool ServerRtpTransport::SendRtcp(const uint8_t* packet, size_t length)
{
    bool ret = false;
    if (stream_ && rtpPort_ != 0)
    {
        stream_->sendRTCP(packet, length, ip_.c_str(), rtcpPort_);
        ret = true;
    }
    return ret;
}
}
