#include "record_and_play.h"
#include "ui_record_and_play.h"
#include <QDebug>

RecordAndPlay::RecordAndPlay(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::RecordAndPlay),
	error(0),
	audioChannel(0),
	ptrVoEngine(NULL),
	ptrVoEBase(NULL),
	ptrVoEVolumeControl(NULL),
	ptrVoEFile(NULL),
	ptrVoEHardware(NULL)
{
	ui->setupUi(this);
	creatVoiceEngine();
	initialVoiceEngine();
	setDevice();
	setChannel();

	connect(ui->horizontalSliderMicrophoneVolume, SIGNAL(valueChanged(int)), this, SLOT(slotSetMicrophoneVolumeValue(int)));
	connect(ui->horizontalSliderSpeakerVolume, SIGNAL(valueChanged(int)), this, SLOT(slotSetSpeakerVolumeValue(int)));

	int vol = getMicrophoneVolumeValue();
	ui->horizontalSliderMicrophoneVolume->setValue(vol);
	ui->lineEditMicrophoneVolumeValue->setText(QString::number(vol));

	vol = getSpeakerVolumeValue();
	ui->horizontalSliderSpeakerVolume->setValue(vol);
	ui->lineEditSpeakerVolumeValue->setText(QString::number(vol));
}

RecordAndPlay::~RecordAndPlay()
{
	delete ui;
	unInitialVoiceEngine();
}

void RecordAndPlay::creatVoiceEngine()
{
	ptrVoEngine = VoiceEngine::Create();
	ptrVoEBase = VoEBase::GetInterface(ptrVoEngine);
	ptrVoEVolumeControl = VoEVolumeControl::GetInterface(ptrVoEngine);
	ptrVoEFile = VoEFile::GetInterface(ptrVoEngine);
	ptrVoEHardware = VoEHardware::GetInterface(ptrVoEngine);
}

int RecordAndPlay::initialVoiceEngine()
{
	error = ptrVoEBase->Init();
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::Init";
		return error;
	}
	error = ptrVoEBase->RegisterVoiceEngineObserver(myObserver);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase:;RegisterVoiceEngineObserver";
		return error;
	}
	char temp[1024];
	error = ptrVoEBase->GetVersion(temp);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::GetVersion";
		return error;
	}

	ui->lineEditVersion->setText(QString(temp));
	return 100;
}

int RecordAndPlay::unInitialVoiceEngine()
{
	//Stop Playout
	error = ptrVoEBase->StopPlayout(audioChannel);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::StopPlayout";
		return error;
	}
	error = ptrVoEFile->StopPlayingFileLocally(audioChannel);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEFile::StopPlayingFileLocally";
		return error;
	}
	//Stop Record
	error = ptrVoEFile->StopRecordingMicrophone();
	if (error != 0)
	{
		qDebug() << "ERROR in VoEFile::StopRecordingMicrophone";
		return error;
	}

	//Delete Channel
	error = ptrVoEBase->DeleteChannel(audioChannel);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::DeleteChannel";
		return error;
	}
	//DeRegister observer
	ptrVoEBase->DeRegisterVoiceEngineObserver();
	error = ptrVoEBase->Terminate();
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::Terminate";
		return error;
	}

	if (ptrVoEBase)
	{
		ptrVoEBase->Release();
	}

	if (ptrVoEVolumeControl)
	{
		ptrVoEVolumeControl->Release();
	}

	if (ptrVoEFile)
	{
		ptrVoEFile->Release();
	}

	if (ptrVoEHardware)
	{
		ptrVoEHardware->Release();
	}

	bool flag = VoiceEngine::Delete(ptrVoEngine);
	if (!flag)
	{
		qDebug() << "ERROR in VoiceEngine::Delete";
		return -1;
	}
	return 100;
}

int RecordAndPlay::setDevice()
{
	int rNum(-1), pNum(-1);
	error = ptrVoEHardware->GetNumOfRecordingDevices(rNum);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEHardware::GetNumOfRecordingDevices";
		return error;
	}
	error = ptrVoEHardware->GetNumOfPlayoutDevices(pNum);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEHardware::GetNumOfPlayoutDevices";
		return error;
	}

	char name[128] = { 0 };
	char guid[128] = { 0 };

	for (int j = 0; j < rNum; ++j)
	{
		error = ptrVoEHardware->GetRecordingDeviceName(j, name, guid);
		if (error != 0)
		{
			qDebug() << "ERROR in VoEHardware::GetRecordingDeviceName";
			return error;
		}
		ui->comboBoxRecordingDevice->addItem(QString(name));
	}

	for (int j = 0; j < pNum; ++j)
	{
		error = ptrVoEHardware->GetPlayoutDeviceName(j, name, guid);
		if (error != 0)
		{
			qDebug() << "ERROR in VoEHardware::GetPlayoutDeviceName";
			return error;
		}
		ui->comboBoxPlayoutDevice->addItem(QString(name));
	}

	error = ptrVoEHardware->SetRecordingDevice(ui->comboBoxRecordingDevice->currentIndex());
	if (error != 0)
	{
		qDebug() << "ERROR in VoEHardware::SetRecordingDevice";
		return error;
	}

	error = ptrVoEHardware->SetPlayoutDevice(ui->comboBoxPlayoutDevice->currentIndex());
	if (error != 0)
	{
		qDebug() << "ERROR in VoEHardware::SetPlayoutDevice";
		return error;
	}

	return 100;
}

void RecordAndPlay::setChannel()
{
	audioChannel = ptrVoEBase->CreateChannel();
	if (audioChannel < 0)
	{
		qDebug() << "ERROR in VoEBase::CreateChannel";
	}
	error = ptrVoEBase->StartPlayout(audioChannel);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEBase::StartPlayout";
	}
}

int RecordAndPlay::getMicrophoneVolumeValue()
{
	unsigned int vol = 999;
	error = ptrVoEVolumeControl->GetMicVolume(vol);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEVolume::GetMicVolume";
		return 0;
	}
	if ((vol > 255) || (vol < 0))
	{
		qDebug() << "ERROR in GetMicVolume";
		return 0;
	}
	return vol;
}

int RecordAndPlay::getSpeakerVolumeValue()
{
	unsigned int vol = 999;
	error = ptrVoEVolumeControl->GetSpeakerVolume(vol);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEVolume::GetSpeakerVolume";
		return 0;
	}
	if ((vol > 255) || (vol < 0))
	{
		qDebug() << "ERROR in GetSpeakerVolume";
		return 0;
	}
	return vol;
}

void RecordAndPlay::on_pushButtonRecording_clicked()
{
	static bool flag = true;
	if (flag)
	{
		//å½•åˆ¶éº¦å…‹é£Žçš„éŸ³é¢‘ï¼Œé»˜è®¤é‡‡æ ·çŽ‡æ˜?000HZ
		error = ptrVoEFile->StartRecordingMicrophone("RecordingMicrophone.pcm");
		if (error != 0)
		{
			qDebug() << "ERROR in VoEFile::StartRecordingMicrophone";
		}
		else
		{
			ui->pushButtonRecording->setText(QStringLiteral("Í£Ö¹Â¼Òô"));
		}
	}
	else
	{
		error = ptrVoEFile->StopRecordingMicrophone();
		if (error != 0)
		{
			qDebug() << "ERROR in VoEFile::StopRecordingMicrophone";
		}
		else
		{
			ui->pushButtonRecording->setText(QStringLiteral("¿ªÊ¼Â¼Òô"));
		}
	}

	flag = !flag;
}

void RecordAndPlay::on_pushButtonPlayout_clicked()
{
	static bool flag = true;
	if (flag)
	{
		error = ptrVoEFile->StartPlayingFileLocally(audioChannel, "RecordingMicrophone.pcm");
		if (error != 0)
		{
			qDebug() << "ERROR in VoEFile::StartPlayingFileLocally";
		}
		else
		{
			ui->pushButtonPlayout->setText(QStringLiteral("Í£Ö¹²¥·Å"));
		}
	}
	else
	{
		error = ptrVoEFile->StopPlayingFileLocally(audioChannel);
		if (error != 0)
		{
			qDebug() << "ERROR in VoEFile::StopPlayingFileLocally";
		}
		else
		{
			ui->pushButtonPlayout->setText(QStringLiteral("¿ªÊ¼²¥·Å"));
		}
	}

	flag = !flag;
}

void RecordAndPlay::slotSetMicrophoneVolumeValue(int value)
{
	error = ptrVoEVolumeControl->SetMicVolume(value);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEVolume::SetMicVolume";
	}
	else
	{
		ui->lineEditMicrophoneVolumeValue->setText(QString::number(value));
	}
}
void RecordAndPlay::slotSetSpeakerVolumeValue(int value)
{
	error = ptrVoEVolumeControl->SetSpeakerVolume(value);
	if (error != 0)
	{
		qDebug() << "ERROR in VoEVolume::SetSpeakerVolume";
	}
	else
	{
		ui->lineEditSpeakerVolumeValue->setText(QString::number(value));
	}
}