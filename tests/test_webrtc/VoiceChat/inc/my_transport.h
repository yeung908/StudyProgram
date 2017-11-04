#ifndef MYTRANSPORT_H  
#define MYTRANSPORT_H  

#include <QObject>
#include <QUdpSocket.h>
#include "webrtc/api/call/transport.h"

using namespace webrtc;

class MyTransport :public QObject, public Transport
{
	Q_OBJECT
public:
	MyTransport();
	~MyTransport();
	void setLocalReceiver(int port);
	void stopRecieve();
	void setSendDestination(QString ip, int port);
	void stopSend();
	// Transport functions override  
	bool SendRtp(const uint8_t* packet, size_t length, const PacketOptions& options) override;
	bool SendRtcp(const uint8_t* packet, size_t length) override;

private:
	QUdpSocket * udpsocketSendRTP;
	QUdpSocket * udpsocketSendRTCP;
	QUdpSocket * udpSocketRecvRTP;
	QUdpSocket * udpSocketRecvRTCP;

	QString destIP;
	int destPort;

	bool sendFlag;
	bool recvFlag;

signals:
	void signalRecvRTPData(char *data, int length);
	void signalRecvRTCPData(char *data, int length);
	void signalSendRTPData(char *data, int length);
	void signalSendRTCPData(char *data, int length);

	private slots:
	void slotRTPReadPendingDatagrams();
	void slotRTCPReadPendingDatagrams();
	void slotSendRTPData(char *data, int length);
	void slotSendRTCPData(char *data, int length);
};

#endif // MYTRANSPORT_H