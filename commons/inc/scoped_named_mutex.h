#pragma once
#include <Poco/NamedMutex.h>

namespace vcs
{
class ScopedNamedMutex
{
public:
    explicit ScopedNamedMutex(const std::string& name)
        : _mtx(name)
    {
        if (!_mtx.tryLock())
        {
            exit(0);
        }
    }
    ~ScopedNamedMutex()
    {
        _mtx.unlock();
    }
private:
    Poco::NamedMutex _mtx;
};
}
