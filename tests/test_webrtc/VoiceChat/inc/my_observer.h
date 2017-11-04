#ifndef MYOBSERVER_H
#define MYOBSERVER_H

#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/voice_engine/include/voe_errors.h"

using namespace webrtc;
class MyObserver:public VoiceEngineObserver
{
public:
    MyObserver();
    //实现VoiceEngineObserver的纯虚函数
    virtual void CallbackOnError(int channel, int err_code);

};

#endif // MYOBSERVER_H
