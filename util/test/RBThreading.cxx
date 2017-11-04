#include <iostream>
#include <thread>
#include <chrono>
#include "RingBuffer.h"


using namespace std;
using VCS::RingBuffer;


bool stop = false;

void read(RingBuffer *buf)
{
	int32_t readed = 0;
	int8_t a;
	while (!stop) {
		readed = buf->read(1, &a);
		if (readed) {
			cout << a << endl;
		} else {
			this_thread::yield();
		}
	}
}

void write(RingBuffer *buf)
{
	int8_t data;
	while (!stop) {
		for (int j = 0; j < 256; j++) {
			data = j;
			buf->write(1, &data);
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main(int argc, char **argv)
{
	const int32_t length = 1024;
	RingBuffer buf(length);
	uint8_t key;

	cout << "press any key to stop." << endl;

	thread wtr(write, &buf);
	thread rTr(read, &buf);

	for (int i = 0; i < 1000; i++) {
		this_thread::sleep_for(chrono::milliseconds(20));
	}

	stop = true;

	wtr.join();
	rTr.join();

	return 0;
}

