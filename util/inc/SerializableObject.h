#pragma once
#include <string>
#include <Poco/Dynamic/Struct.h>

namespace vcs
{
class SerializableObject
{
public:
    inline std::string serialize()
    {
        Poco::DynamicStruct str = toStruct();
        return str.toString();
    }
protected:
    virtual Poco::DynamicStruct toStruct() = 0;
    inline void appendObject(Poco::DynamicStruct &str, const std::string &name, SerializableObject *obj)
    {
        if (obj)
        {
            Poco::DynamicStruct val = obj->toStruct();
            str.insert(name, val);
        }
    }
};
}
