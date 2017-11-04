#include <Poco/ScopedLock.h>
#include <Poco/Environment.h>
#include "ServerRtpStreamWebrtcImpl.h"
#include "webrtc/modules/rtp_rtcp/include/rtp_header_parser.h"
#include "webrtc/modules/rtp_rtcp/source/rtcp_utility.h"
#include "webrtc/base/physicalsocketserver.h"
#include "webrtc/base/asyncudpsocket.h"
#include "structure.h"

using Poco::ScopedLock;
using Poco::FastMutex;
using webrtc::RTPHeader;
using namespace webrtc::RTCPUtility;

namespace vcs
{
void ServerRtpStreamWebrtcImpl::IncomingRTPPacket(const int8_t* incomingRtpPacket, const size_t rtpPacketLength, const char* fromIP, const uint16_t fromPort)
{
    webrtc::RTPHeader header;
    if (_parser->Parse((const uint8_t*)incomingRtpPacket, rtpPacketLength, &header))
    {
        ScopedLock<FastMutex> lock(_mutex);
        auto it = _observers.find(header.ssrc);
        if (it != _observers.end())
        {
            it->second->onRtpPacket((const uint8_t*)incomingRtpPacket, rtpPacketLength, fromIP, fromPort);
        }
        else if((it = _observers.find(header.ssrc + SSRC_VIDEO - SSRC_VIDEO_FEC)) != _observers.end()) // fec packet
        {
            it->second->onRtpPacket((const uint8_t*)incomingRtpPacket, rtpPacketLength, fromIP, fromPort);
        }
    }
}

void ServerRtpStreamWebrtcImpl::IncomingRTCPPacket(const int8_t* incomingRtcpPacket, const size_t rtcpPacketLength, const char* fromIP, const uint16_t fromPort)
{
    RTCPParserV2 parser(reinterpret_cast<const uint8_t*>(incomingRtcpPacket), rtcpPacketLength, false);

    uint32_t sender = getRtcpSender(parser);

    if (sender > 0)
    {
        ScopedLock<FastMutex> lock(_mutex);
        auto it = _observers.find(sender);
        if (it != _observers.end())
        {
            it->second->onRtcpPacket((const uint8_t*)incomingRtcpPacket, rtcpPacketLength, fromIP, fromPort);
        }
    }
}

ServerRtpStreamWebrtcImpl::~ServerRtpStreamWebrtcImpl()
{
    stop();
}

void ServerRtpStreamWebrtcImpl::registerObserver(uint32_t ssrc, Poco::AutoPtr<RtpDataObserver> obs)
{
    ScopedLock<FastMutex> lock(_mutex);
    _observers[ssrc] = obs;
}

void ServerRtpStreamWebrtcImpl::deregisterObserver(uint32_t ssrc)
{
    ScopedLock<FastMutex> lock(_mutex);
    _observers.erase(ssrc);
}

ServerRtpStreamWebrtcImpl::ServerRtpStreamWebrtcImpl(int32_t id, const std::string local, uint16_t port)
    :Poco::Task("ServerRtpStreamWebrtcImpl")
{
    uint8_t threads = Poco::Environment::processorCount();
    _parser = webrtc::RtpHeaderParser::Create();
    _socketServer.reset(rtc::PhysicalSocketServer::CreateDefault().release());
    _rtpSocket.reset(rtc::AsyncUDPSocket::Create(_socketServer.get(), rtc::SocketAddress(local, port)));
    _rtcpSocket.reset(rtc::AsyncUDPSocket::Create(_socketServer.get(), rtc::SocketAddress(local, port + 1)));
    _rtpSocket->SignalReadPacket.connect(this, &ServerRtpStreamWebrtcImpl::OnRTPPacket);
    _rtcpSocket->SignalReadPacket.connect(this, &ServerRtpStreamWebrtcImpl::OnRTCPPacket);
}

uint32_t ServerRtpStreamWebrtcImpl::getRtcpSender(RTCPParserV2 &parser)
{
    RTCPPacketTypes type = RTCPPacketTypes::kInvalid;

    uint32_t sender_ssrc = 0;

    do
    {
        type = parser.Iterate();
        const RTCPPacket &packet = parser.Packet();
        switch (type)
        {
        case webrtc::RTCPUtility::RTCPPacketTypes::kRr:
            sender_ssrc = packet.RR.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kSr:
            sender_ssrc = packet.SR.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kSdes:
            sender_ssrc = packet.CName.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kBye:
            sender_ssrc = packet.BYE.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kExtendedIj:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kExtendedIjItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbNack:
            sender_ssrc = packet.NACK.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbNackItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbPli:
            sender_ssrc = packet.PLI.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbRpsi:
            sender_ssrc = packet.RPSI.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbRpsiItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbSli:
            sender_ssrc = packet.SLI.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbSliItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbApp:
            sender_ssrc = packet.PSFBAPP.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbRemb:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbRembItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbTmmbr:
            sender_ssrc = packet.TMMBR.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbTmmbrItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbTmmbn:
            sender_ssrc = packet.TMMBN.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbTmmbnItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbFir:
            sender_ssrc = packet.FIR.SenderSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kPsfbFirItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kRtpfbSrReq:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kXrHeader:
            sender_ssrc = packet.XR.OriginatorSSRC;
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kXrReceiverReferenceTime:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kXrDlrrReportBlock:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kXrDlrrReportBlockItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kXrVoipMetric:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kApp:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kAppItem:
            break;
        case webrtc::RTCPUtility::RTCPPacketTypes::kTransportFeedback:
            break;
        default:
            break;
        }

        if (sender_ssrc != 0)
        {
            break;
        }
    } while (parser.LengthLeft() > 0 && type != RTCPPacketTypes::kInvalid);

    return sender_ssrc;
}

void ServerRtpStreamWebrtcImpl::sendRTP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort)
{
    rtc::PacketOptions option;
    _rtpSocket->SendTo(packet, length, rtc::SocketAddress(dstHost, dstPort), option);
}

void ServerRtpStreamWebrtcImpl::runTask()
{
    while (!isCancelled()) {
        _socketServer->Wait(10, true);
        Poco::Thread::sleep(0);
    }
}

void ServerRtpStreamWebrtcImpl::start()
{
    if (!_tr.isRunning() && !isCancelled()) {
        _tr.start(*this);
    }
}

void ServerRtpStreamWebrtcImpl::stop()
{
    cancel();
    _tr.join();
}

bool ServerRtpStreamWebrtcImpl::isRunning() const
{
    return _tr.isRunning();
}

void ServerRtpStreamWebrtcImpl::OnRTPPacket(rtc::AsyncPacketSocket* socket, const char* data, size_t length, const rtc::SocketAddress& remote, const rtc::PacketTime& time)
{
    IncomingRTPPacket((const int8_t*)data, length, remote.ipaddr().ToString().c_str(), remote.port());
}

void ServerRtpStreamWebrtcImpl::OnRTCPPacket(rtc::AsyncPacketSocket* socket, const char* data, size_t length, const rtc::SocketAddress& remote, const rtc::PacketTime& time)
{
    IncomingRTCPPacket((const int8_t*)data, length, remote.ipaddr().ToString().c_str(), remote.port());
}

void ServerRtpStreamWebrtcImpl::sendRTCP(const uint8_t* packet, size_t length, const char* dstHost, const uint16_t dstPort)
{
    rtc::PacketOptions option;
    _rtcpSocket->SendTo(packet, length, rtc::SocketAddress(dstHost, dstPort), option);
}

}