#ifndef VOICE_CHAT_H
#define VOICE_CHAT_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include "my_observer.h"
#include "my_transport.h"

#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/voice_engine/include/voe_hardware.h"
#include "webrtc/voice_engine/include/voe_network.h"
#include "webrtc/voice_engine/include/voe_volume_control.h"

using namespace webrtc;

namespace Ui {
class VoiceChat;
}

class VoiceChat : public QMainWindow
{
    Q_OBJECT

public:
    explicit VoiceChat(QWidget *parent = 0);
    ~VoiceChat();

private:
	void CreateVoiceEngine();
	int InitialVoiceEngine();
	int SetDevice();
	void SetChannel();
	void SetNetwork();
	int GetMicrophoneVolumeValue();
	int GetSpeakerVolumeValue();
	int UnInitialVoiceEngine();

private:
    Ui::VoiceChat*         ui;
	MyObserver             _myObserver;
	MyTransport*           _myTransport;
	int                    _error;
	int                    _audioChannel;

	VoiceEngine*           _ptrVoEngine;
	VoEBase*               _ptrVoEBase;
	VoENetwork*            _ptrVoENetwork;
	VoEVolumeControl*      _ptrVoEVolumeControl;
	VoEHardware*           _ptrVoEHardware;

	private slots:
	void on_pushButtonSend_clicked();
	void on_pushButtonReceive_clicked();
	void slotSetMicrophoneVolumeValue(int value);
	void slotSetSpeakerVolumeValue(int value);
	void slotRecvRTPData(char *data, int length);
	void slotRecvRTCPData(char *data, int length);
};

#endif // VOICE_CHAT_H
