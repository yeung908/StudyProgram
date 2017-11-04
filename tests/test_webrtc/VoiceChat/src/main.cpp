#include "voice_chat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoiceChat w;
    w.show();

    return a.exec();
}
