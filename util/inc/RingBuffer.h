/**
注意：
RingBuffer适用于一个生产者一个消费者的无锁场景。
在多生产者或者多消费者场景，不能够保证线程安全。
*/

#pragma once

#include <atomic>
#include <stdint.h>

namespace vcs
{
class RingBuffer
{
public:
    explicit RingBuffer(uint32_t length);
    virtual ~RingBuffer();

    int32_t read(uint32_t len, int8_t *buf);
    int32_t write(uint32_t len, int8_t *data);
    inline uint32_t size() const { return _size; }
    uint32_t length() const;

    // 使用copy时，不会移动head
    int32_t copy(uint32_t len, int8_t *buf) const;

    int32_t offset(uint32_t len);

    void reset();

private:
    std::atomic<uint32_t> _head;
    std::atomic<uint32_t> _tail;
    uint32_t _len;
    int8_t *_buf;
    std::atomic<uint32_t> _size;
};
}
