#include "my_observer.h"
#include <QDebug>
MyObserver::MyObserver()
{

}

void MyObserver::CallbackOnError(int channel, int err_code)
{
    // Add printf for other error codes here
    if (err_code == VE_TYPING_NOISE_WARNING)
    {
        qDebug()<<"TYPING NOISE DETECTED";
    }
    else if (err_code == VE_TYPING_NOISE_OFF_WARNING)
    {
        qDebug()<<"TYPING NOISE OFF DETECTED";
    }
    else if (err_code == VE_RECEIVE_PACKET_TIMEOUT)
    {
        qDebug()<<"RECEIVE PACKET TIMEOUT";
    }
    else if (err_code == VE_PACKET_RECEIPT_RESTARTED)
    {
        qDebug()<<"PACKET RECEIPT RESTARTED";
    }
    else if (err_code == VE_RUNTIME_PLAY_WARNING)
    {
        qDebug()<<"RUNTIME PLAY WARNING";
    }
    else if (err_code == VE_RUNTIME_REC_WARNING)
    {
        qDebug()<<"RUNTIME REC WARNING";
    }
    else if (err_code == VE_SATURATION_WARNING)
    {
        qDebug()<<"SATURATION WARNING";
    }
    else if (err_code == VE_RUNTIME_PLAY_ERROR)
    {
        qDebug()<<"RUNTIME PLAY ERROR";
    }
    else if (err_code == VE_RUNTIME_REC_ERROR)
    {
        qDebug()<<"RUNTIME RECORD ERROR";
    }
    else if (err_code == VE_REC_DEVICE_REMOVED)
    {
        qDebug()<<"RECORD DEVICE REMOVED";
    }
}
