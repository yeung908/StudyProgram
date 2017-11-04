#include "ServerRtpStreamWebrtcImpl.h"

namespace vcs
{
ServerRtpStream* ServerRtpStream::create(int32_t id, const std::string local, uint16_t port)
{
    return new ServerRtpStreamWebrtcImpl(id, local, port);
}
}