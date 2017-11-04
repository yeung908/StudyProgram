#pragma once
#include <string>
#include <cstdint>
#include <map>
#include "Poco/Mutex.h"
#include "Poco/RefCountedObject.h"
#include "Poco/AutoPtr.h"

namespace vcs
{
class RtpDataObserver : public Poco::RefCountedObject
{
public:
    virtual void onRtpPacket(const uint8_t* packet, size_t length, const char* fromIP, const uint16_t fromPort) = 0;
    virtual void onRtcpPacket(const uint8_t* packet, size_t length, const char* fromIP, const uint16_t fromPort) = 0;
};

class ServerRtpStream
{
public:
    virtual ~ServerRtpStream() {};
    
    static ServerRtpStream* create(int32_t id, const std::string local, uint16_t port);

    virtual void registerObserver(uint32_t ssrc, Poco::AutoPtr<RtpDataObserver> obs) = 0;
    virtual void deregisterObserver(uint32_t ssrc) = 0;

    virtual void sendRTP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort) = 0;
    virtual void sendRTCP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort) = 0;

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual bool isRunning() const = 0;
};
}