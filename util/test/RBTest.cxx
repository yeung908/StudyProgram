#include <gtest/gtest.h>
#include "RingBuffer.h"

using VCS::RingBuffer;

class RBTest :public testing::Test
{
protected:
	static void SetUpTestCase() {
		rBuf = new RingBuffer(2043);
	}
	static void TearDownTestCase() {
		delete rBuf;
	}

	static RingBuffer *rBuf;
};
RingBuffer *RBTest::rBuf = NULL;


TEST_F(RBTest, CheckLength)
{
	GTEST_ASSERT_EQ(rBuf->length(), 2048);
}

TEST_F(RBTest, CheckSize)
{
	GTEST_ASSERT_EQ(rBuf->size(), 0);
}

TEST_F(RBTest, WriteNull)
{
	int32_t writed = rBuf->write(100, NULL);
	GTEST_ASSERT_EQ(writed, 0);
	GTEST_ASSERT_EQ(rBuf->size(), 0);
}

TEST_F(RBTest, WriteFull)
{
	int8_t * data = new int8_t[2048];
	int32_t writed = rBuf->write(2048, data);
	GTEST_ASSERT_EQ(writed, 0);
	GTEST_ASSERT_EQ(rBuf->size(), 0);
	delete[] data;
}

TEST_F(RBTest, WriteHalf)
{
	int8_t *data = new int8_t[1024];
	int32_t writed = rBuf->write(1024, data);
	GTEST_ASSERT_EQ(writed, 1024);
	GTEST_ASSERT_EQ(rBuf->size(), 1024);

	writed = rBuf->write(1024, data);
	GTEST_ASSERT_EQ(writed, 0);
	GTEST_ASSERT_EQ(rBuf->size(), 1024);

	int32_t readed = rBuf->read(1, data);
	GTEST_ASSERT_EQ(readed, 1);
	GTEST_ASSERT_EQ(rBuf->size(), 1023);

	writed = rBuf->write(1024, data);
	GTEST_ASSERT_EQ(writed, 1024);
	GTEST_ASSERT_EQ(rBuf->size(), 2047);

	delete[] data;
}

TEST_F(RBTest, Ñ­»·¶ÁÐ´)
{
	int8_t *data = new int8_t[256];
	for (int i = 0; i < 256; i++) data[i] = 8;

	int8_t *buf = new int8_t[2048];

	int32_t writed, readed;
	readed = rBuf->read(2048, buf);
	GTEST_ASSERT_EQ(readed, 0);
	GTEST_ASSERT_EQ(rBuf->size(), 2047);

	for (int i = 0; i < 12; i++) {
		readed = rBuf->read(256, buf);
		GTEST_ASSERT_EQ(readed, 256);
		GTEST_ASSERT_EQ(rBuf->size(), 1791);

		writed = rBuf->write(256, data);
		GTEST_ASSERT_EQ(writed, 256);
		GTEST_ASSERT_EQ(rBuf->size(), 2047);
	}


	for (int i = 0; i < 2048; i++) {
		buf[i] = 0;
	}

	readed = rBuf->read(2047, buf);
	GTEST_ASSERT_EQ(readed, 2047);
	GTEST_ASSERT_EQ(rBuf->size(), 0);
	
	for (int i = 0; i < 2047; i++) {
		GTEST_ASSERT_EQ(buf[i], 8);
	}
}