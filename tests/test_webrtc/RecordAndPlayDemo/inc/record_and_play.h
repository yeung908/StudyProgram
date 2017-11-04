#ifndef RECORD_AND_PLAY_H
#define RECORD_AND_PLAY_H

#include <QMainWindow>
#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/voice_engine/include/voe_file.h"
#include "webrtc/voice_engine/include/voe_hardware.h"
#include "webrtc/voice_engine/include/voe_volume_control.h"
using namespace webrtc;

namespace Ui {
	class RecordAndPlay;
}

class MyObserver :public VoiceEngineObserver
{
public:
	void CallbackOnError(int channel, int errCode)
	{
	}
};

class RecordAndPlay : public QMainWindow
{
	Q_OBJECT

public:
	explicit RecordAndPlay(QWidget *parent = 0);
	~RecordAndPlay();

	void creatVoiceEngine();
	int initialVoiceEngine();
	int setDevice();
	void setChannel();
	int getMicrophoneVolumeValue();
	int getSpeakerVolumeValue();
	int unInitialVoiceEngine();

private:
	Ui::RecordAndPlay *ui;
	MyObserver myObserver;
	int error;
	int audioChannel;

	VoiceEngine* ptrVoEngine;
	VoEBase* ptrVoEBase;
	VoEVolumeControl* ptrVoEVolumeControl;
	VoEFile* ptrVoEFile;
	VoEHardware* ptrVoEHardware;

	private slots:
	void on_pushButtonRecording_clicked();
	void on_pushButtonPlayout_clicked();
	void slotSetMicrophoneVolumeValue(int value);
	void slotSetSpeakerVolumeValue(int value);
};

#endif // RECORD_AND_PLAY_H
