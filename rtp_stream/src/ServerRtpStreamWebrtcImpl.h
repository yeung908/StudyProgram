#pragma once
#include <string>
#include <cstdint>
#include <map>
#include "Poco/Mutex.h"
#include "Poco/Task.h"
#include "Poco/Thread.h"
#include "ServerRtpStream.h"
#include "webrtc/base/asyncpacketsocket.h"
#include "webrtc/base/sigslot.h"
#include "webrtc/base/socketserver.h"

namespace webrtc
{
struct PacketTime;
class RtpHeaderParser;
namespace RTCPUtility
{
class RTCPParserV2;
}
}

namespace vcs
{

class ServerRtpStreamWebrtcImpl : public ServerRtpStream, public Poco::Task, public sigslot::has_slots<>
{
public:
    virtual ~ServerRtpStreamWebrtcImpl();
    
    void registerObserver(uint32_t ssrc, Poco::AutoPtr<RtpDataObserver> obs);
    void deregisterObserver(uint32_t ssrc);

    virtual void start() override;

    virtual void stop() override;

    virtual bool isRunning() const override;

    void OnRTPPacket(rtc::AsyncPacketSocket* socket, const char* data, size_t length,
        const rtc::SocketAddress& remote,
        const rtc::PacketTime& time);

    void OnRTCPPacket(rtc::AsyncPacketSocket* socket, const char* data, size_t length,
        const rtc::SocketAddress& remote,
        const rtc::PacketTime& time);

    uint32_t getRtcpSender(webrtc::RTCPUtility::RTCPParserV2 &parser);

    ServerRtpStreamWebrtcImpl(int32_t id, const std::string local, uint16_t port);

    virtual void sendRTP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort) override;
    virtual void sendRTCP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort) override;

protected:
    ServerRtpStreamWebrtcImpl(const ServerRtpStreamWebrtcImpl&) = delete;

    void IncomingRTPPacket(const int8_t* incomingRtpPacket, const size_t rtpPacketLength, const char* fromIP, const uint16_t fromPort);

    void IncomingRTCPPacket(const int8_t* incomingRtcpPacket, const size_t rtcpPacketLength, const char* fromIP, const uint16_t fromPort);

    virtual void runTask() override;
private:
    Poco::FastMutex                                           _mutex;
    std::map<uint32_t, Poco::AutoPtr<RtpDataObserver>>        _observers;
    webrtc::RtpHeaderParser                                   *_parser;  
    Poco::Thread                                              _tr;
    std::unique_ptr<rtc::SocketServer>                        _socketServer;
    std::unique_ptr<rtc::AsyncPacketSocket>                   _rtpSocket;
    std::unique_ptr<rtc::AsyncPacketSocket>                   _rtcpSocket;
};
}