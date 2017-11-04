#include <string.h>
#include "RingBuffer.h"

using vcs::RingBuffer;

RingBuffer::RingBuffer(uint32_t length) :_head(0), _tail(0), _size(0)
{
    _len = ((length + 7) >> 3) << 3;   //8字节对齐
    _buf = new int8_t[_len + 64];
}

RingBuffer::~RingBuffer()
{
    if (_buf) delete[] _buf;
}

int32_t RingBuffer::read(uint32_t len, int8_t *buf)
{
    int32_t ret = copy(len, buf);
    offset(ret);
    return ret;
}

int32_t RingBuffer::copy(uint32_t len, int8_t *buf) const
{
    int32_t ret = 0;
    if (size() >= len && len > 0 && buf)
    {
        if (_tail > _head)
        {
            memcpy(buf, _buf + _head, len);
        }
        else
        {
            uint32_t tmpLen = _len - _head;
            if (len <= tmpLen)
            {
                memcpy(buf, _buf + _head, len);
            }
            else
            {
                memcpy(buf, _buf + _head, tmpLen);
                memcpy(buf + tmpLen, _buf, len - tmpLen);
            }
        }

        ret = len;
    }

    return ret;
}

int32_t vcs::RingBuffer::offset(uint32_t len)
{
    int32_t ret = 0;
    if (_size.load() >= len)
    {
        _head = (_head.load() + len) % _len;
        ret = len;
    }
    _size -= ret;
    return ret;
}

void vcs::RingBuffer::reset()
{
    _size = _tail = _head = 0;
}

int32_t RingBuffer::write(uint32_t len, int8_t *data)
{
    int32_t ret = 0;
    //当_head等于_tail时，可能是empty，也可能是full.
    //为了简化，使用“_len - size() > len”这个条件阻止RingBuffer出现full的情况。
    if (_len - _size.load() > len && data)
    {
        if (_tail.load() < _head.load())
        {
            memcpy(_buf + _tail.load(), data, len);
        }
        else
        {
            if (_len - _tail.load() >= len)
            {
                memcpy(_buf + _tail.load(), data, len);
            }
            else
            {
                uint32_t tmpLen = _len - _tail.load();
                memcpy(_buf + _tail.load(), data, tmpLen);
                memcpy(_buf, data + tmpLen, len - tmpLen);
            }
        }

        _tail = (_tail.load() + len) % _len;

        ret = len;
        _size += ret;
    }

    return ret;
}

uint32_t RingBuffer::length() const
{
    return _len;
}
