#include "record_and_play.h"
#include <QtWidgets/QApplication>

#pragma comment(lib, "winmm.lib ")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RecordAndPlay w;
	w.show();
	return a.exec();
}