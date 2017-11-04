#include "my_transport.h"  
#include "QDebug"  

MyTransport::MyTransport()
	:destIP(""),
	destPort(0),
	sendFlag(true),
	recvFlag(true)
{
	udpsocketSendRTP = new QUdpSocket();
	udpSocketRecvRTP = new QUdpSocket();
	udpsocketSendRTCP = new QUdpSocket();
	udpSocketRecvRTCP = new QUdpSocket();

	connect(udpSocketRecvRTP, SIGNAL(readyRead()), this, SLOT(slotRTPReadPendingDatagrams()));
	connect(udpSocketRecvRTCP, SIGNAL(readyRead()), this, SLOT(slotRTCPReadPendingDatagrams()));

	connect(this, SIGNAL(signalSendRTPData(char *, int)), this, SLOT(slotSendRTPData(char *, int)));
	connect(this, SIGNAL(signalSendRTCPData(char *, int)), this, SLOT(slotSendRTCPData(char *, int)));
}

MyTransport::~MyTransport()
{
	udpsocketSendRTP->deleteLater();
	udpSocketRecvRTP->deleteLater();
	udpsocketSendRTCP->deleteLater();
	udpSocketRecvRTCP->deleteLater();
}

void MyTransport::setLocalReceiver(int port)
{
	udpSocketRecvRTP->bind(port, QUdpSocket::ShareAddress);
	udpSocketRecvRTCP->bind(port + 1, QUdpSocket::ShareAddress);
	recvFlag = true;
}
void MyTransport::stopRecieve()
{
	udpSocketRecvRTP->abort();
	udpSocketRecvRTCP->abort();
	recvFlag = false;
}
void MyTransport::setSendDestination(QString ip, int port)
{
	destIP = ip;
	destPort = port;
	sendFlag = true;
}
void MyTransport::stopSend()
{
	sendFlag = false;
}
//为何不直接调用udpsocketSendRTP->writeDatagram，而用信号，是因为SendRtp在另一个线程里  
bool MyTransport::SendRtp(const uint8_t* packet, size_t length, const PacketOptions& options)
{
	Q_UNUSED(options);
	if (sendFlag)
		emit signalSendRTPData((char*)packet, length);
	return true;
}
//为何不直接调用udpsocketSendRTCP->writeDatagram，而用信号，是因为SendRtcp在另一个线程里  
bool MyTransport::SendRtcp(const uint8_t* packet, size_t length)
{
	if (sendFlag)
		emit signalSendRTCPData((char*)packet, length);
	return true;
}

void MyTransport::slotSendRTPData(char *data, int length)
{
	udpsocketSendRTP->writeDatagram(data, length, QHostAddress(destIP), destPort);
}
//RTCP端口为RTP端口+1  
void MyTransport::slotSendRTCPData(char *data, int length)
{
	udpsocketSendRTCP->writeDatagram(data, length, QHostAddress(destIP), destPort + 1);
}

void MyTransport::slotRTPReadPendingDatagrams()
{
	QByteArray datagram;
	while (udpSocketRecvRTP->hasPendingDatagrams() && recvFlag)
	{
		datagram.resize(udpSocketRecvRTP->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		int size = udpSocketRecvRTP->readDatagram(
			datagram.data(),
			datagram.size(),
			&sender,
			&senderPort);

		if (size > 0)
		{
			emit signalRecvRTPData(datagram.data(), datagram.size());
		}
	}
}

void MyTransport::slotRTCPReadPendingDatagrams()
{
	QByteArray datagram;
	while (udpSocketRecvRTCP->hasPendingDatagrams() && recvFlag)
	{
		datagram.resize(udpSocketRecvRTCP->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		int size = udpSocketRecvRTCP->readDatagram(
			datagram.data(),
			datagram.size(),
			&sender,
			&senderPort);

		if (size > 0)
		{
			emit signalRecvRTCPData(datagram.data(), datagram.size());
		}
	}
}