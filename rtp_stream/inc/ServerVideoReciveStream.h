#pragma once
#include <Poco/RefCountedObject.h>
#include <Poco/AutoPtr.h>
#include "ServerRtpStream.h"

namespace vcs
{
class ServerVideoReciveStream : public RtpDataObserver
{
public:
    virtual ~ServerVideoReciveStream() {}
    virtual void getStatics(std::string &statics) = 0;
protected:
    uint32_t _ssrc;
};
}