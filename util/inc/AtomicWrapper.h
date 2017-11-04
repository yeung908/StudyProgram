#pragma once

namespace vcs
{
template<class T> class AtomicWrapper
{
public:
    AtomicWrapper()
    {
    }
    AtomicWrapper(T value) : _value(value)
    {
    }

    AtomicWrapper& operator=(const T &value)
    {
        {
            Poco::ScopedLock<Poco::FastMutex> lock(_mutex);
            _value = value;
        }

        return *this;
    }

    AtomicWrapper& operator=(const AtomicWrapper& other)
    {
        {
            Poco::ScopedLock<Poco::FastMutex> lock(_mutex);
            _value = other._value;
        }

        return *this;
    }

    void exchange(T value)
    {
        Poco::ScopedLock<Poco::FastMutex> lock(_mutex);
        _value = value;
    }

    T& load()
    {
        Poco::ScopedLock<Poco::FastMutex> lock(_mutex);
        return _value;
    }

private:
    Poco::FastMutex _mutex;
    T               _value;
};
}
