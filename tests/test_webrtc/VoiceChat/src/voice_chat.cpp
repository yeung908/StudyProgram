#include "voice_chat.h"
#include "ui_voice_chat.h"

VoiceChat::VoiceChat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoiceChat),
	_error(0),
	_ptrVoEngine(NULL),
	_ptrVoEBase(NULL),
	_ptrVoEVolumeControl(NULL),
	_ptrVoENetwork(NULL),
	_ptrVoEHardware(NULL)
{
    ui->setupUi(this);
	CreateVoiceEngine();
	InitialVoiceEngine();
	SetDevice();
	SetChannel();
	SetNetwork();

	connect(
		ui->horizontalSliderMicrophoneVolume,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(slotSetMicrophoneVolumeValue(int))
	);
	connect(
		ui->horizontalSliderSpeakerVolume,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(slotSetSpeakerVolumeValue(int))
	);
	
	int vol = GetMicrophoneVolumeValue();
	ui->horizontalSliderMicrophoneVolume->setValue(vol);
	ui->lineEditMicrophoneVolumeValue->setText(QString::number(vol));

	vol = GetSpeakerVolumeValue();
	ui->horizontalSliderSpeakerVolume->setValue(vol);
	ui->lineEditSpeakerVolumeValue->setText(QString::number(vol));
}

VoiceChat::~VoiceChat()
{
    delete ui;
	UnInitialVoiceEngine();
}

void VoiceChat::CreateVoiceEngine()
{
	_ptrVoEngine = VoiceEngine::Create();            //创建VoiceEngine
	_ptrVoEBase = VoEBase::GetInterface(_ptrVoEngine);    //创建VoeBase,所有Voe相关操作通过这个共有类
	_ptrVoEVolumeControl = VoEVolumeControl::GetInterface(_ptrVoEngine);   //
	_ptrVoEHardware = VoEHardware::GetInterface(_ptrVoEngine);
	_ptrVoENetwork = VoENetwork::GetInterface(_ptrVoEngine);
}

int VoiceChat::InitialVoiceEngine()
{
	_error = _ptrVoEBase->Init();           //创建整个Voe处理线程
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::Init";
		return _error;
	}
	_error = _ptrVoEBase->RegisterVoiceEngineObserver(_myObserver);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::RegisterVoiceEngineObserver";
		return _error;
	}
	char temp[1024];
	_error = _ptrVoEBase->GetVersion(temp);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::GetVersion";
		return _error;
	}
	ui->lineEditVersion->setText(QString(temp));
	return 100;
}

int VoiceChat::UnInitialVoiceEngine()
{
	//stop playout
	_error = _ptrVoEBase->StopPlayout(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::StopPlayout";
		return _error;
	}
	//DeRegister
	_error = _ptrVoENetwork->DeRegisterExternalTransport(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoENetwork::DeRegisterExternalTransport";
		return _error;
	}
	//Delete Channel
	_error = _ptrVoEBase->DeleteChannel(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::DeleteChannel";
		return _error;
	}
	//DeRegister observer
	_ptrVoEBase->DeRegisterVoiceEngineObserver();
	_error = _ptrVoEBase->Terminate();
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::Terminate";
		return _error;
	}
	if (_ptrVoEBase)
	{
		_ptrVoEBase->Release();
	}
	if (_ptrVoEVolumeControl)
	{
		_ptrVoEVolumeControl->Release();
	}
	if (_ptrVoEHardware)
	{
		_ptrVoEHardware->Release();
	}
	bool flag = VoiceEngine::Delete(_ptrVoEngine);
	if (!flag)
	{
		qDebug() << "ERROR in VoiceEngine::Delete";
		return -1;
	}
	return 100;
}

int VoiceChat::SetDevice()
{
	int rNum = -1;           //recording device num
	int pNum = -1;           //playout device num
	_error = _ptrVoEHardware->GetNumOfRecordingDevices(rNum);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEHardware::GetNumOfRecordingDevices";
		return _error;
	}
	_error = _ptrVoEHardware->GetNumOfPlayoutDevices(pNum);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEHardware::GetNumOfRecordingDevices";
		return _error;
	}
	char name[128] = { 0 };
	char guid[128] = { 0 };
	for (int j = 0;j < rNum;++j)
	{
		_error = _ptrVoEHardware->GetRecordingDeviceName(j, name, guid);
		if (_error != 0)
		{
			qDebug() << "ERROR in VoEHardware::GetRecordingDeviceName";
			return _error;
		}
		ui->comboBoxRecordingDevice->addItem(QString(name));
	}

	for (int j = 0;j < pNum;++j)
	{
		_error = _ptrVoEHardware->GetPlayoutDeviceName(j, name, guid);
		if (_error != 0)
		{
			qDebug() << "ERROR in VoEHardware::GetPlayoutDeviceName";
			return _error;
		}
		ui->comboBoxPlayoutDevice->addItem(QString(name));
	}
	_error = _ptrVoEHardware->SetRecordingDevice(ui->comboBoxRecordingDevice->currentIndex());
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEHardware::SetRecordingDevice";
		return _error;
	}

	_error = _ptrVoEHardware->SetPlayoutDevice(ui->comboBoxPlayoutDevice->currentIndex());
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEHardware::SetPlayoutDevice";
		return _error;
	}

	return 100;
}

void VoiceChat::SetChannel()
{
	_audioChannel = _ptrVoEBase->CreateChannel();
	if (_audioChannel < 0)
	{
		qDebug() << "ERROR in VoEBase::CreateChannel";
	}
	//允许接收
	_error = _ptrVoEBase->StartReceive(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::StartReceive";
	}
	//允许播放
	_error = _ptrVoEBase->StartPlayout(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::StartPlayout";
	}
	//允许发送
	_error = _ptrVoEBase->StartSend(_audioChannel);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEBase::StartSend";
	}
}

void VoiceChat::SetNetwork()
{
	_myTransport = new MyTransport();
	_error = _ptrVoENetwork->RegisterExternalTransport(_audioChannel, *_myTransport);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEHardware::RegisterExternalTransport";
	}
	connect(_myTransport, SIGNAL(signalRecvRTPData(char*, int)), this, SLOT(slotRecvRTPData(char*, int)));
	connect(_myTransport, SIGNAL(signalRecvRTCPData(char*, int)), this, SLOT(slotRecvRTCPData(char*, int)));
}

int VoiceChat::GetMicrophoneVolumeValue()
{
	unsigned int vol = 999;
	_error = _ptrVoEVolumeControl->GetMicVolume(vol);
	if (_error != 0)
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

int VoiceChat::GetSpeakerVolumeValue()
{
	unsigned int vol = 999;
	_error = _ptrVoEVolumeControl->GetSpeakerVolume(vol);
	if (_error != 0)
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

void VoiceChat::slotSetMicrophoneVolumeValue(int value)
{
	_error = _ptrVoEVolumeControl->SetMicVolume(value);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEVolume::SetMicVolume";
	}
	else
	{
		ui->lineEditMicrophoneVolumeValue->setText(QString::number(value));
	}
}
void VoiceChat::slotSetSpeakerVolumeValue(int value)
{
	_error = _ptrVoEVolumeControl->SetSpeakerVolume(value);
	if (_error != 0)
	{
		qDebug() << "ERROR in VoEVolume::SetSpeakerVolume";
	}
	else
	{
		ui->lineEditSpeakerVolumeValue->setText(QString::number(value));
	}
}

void VoiceChat::slotRecvRTPData(char *data, int length)
{
	_ptrVoENetwork->ReceivedRTPPacket(_audioChannel, data, length, PacketTime());
}

void VoiceChat::slotRecvRTCPData(char *data, int length)
{
	_ptrVoENetwork->ReceivedRTCPPacket(_audioChannel, data, length);
}

void VoiceChat::on_pushButtonSend_clicked()
{
	static bool flag = true;
	if (flag)
	{
		_myTransport->setSendDestination(ui->lineEditDestIP->text(), ui->lineEditDestPort->text().toInt());
		ui->pushButtonSend->setText(QStringLiteral("停止"));
	}
	else
	{
		_myTransport->stopSend();
		ui->pushButtonSend->setText(QStringLiteral("开始"));
	}
	flag = !flag;
}

void VoiceChat::on_pushButtonReceive_clicked()
{
	static bool flag = true;
	if (flag)
	{
		_myTransport->setLocalReceiver(ui->lineEditLocalPort->text().toInt());
		ui->pushButtonReceive->setText(QStringLiteral("停止"));
	}
	else
	{
		_myTransport->stopRecieve();
		ui->pushButtonReceive->setText(QStringLiteral("开始"));
	}
	flag = !flag;
}
