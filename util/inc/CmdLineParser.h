#pragma once
#include <string>
#include <Poco/StringTokenizer.h>
#include <Poco/DynamicStruct.h>

class CmdLineParser
{
public:
    explicit CmdLineParser(const std::string &cmdl) : _source(cmdl)
    {
        Poco::StringTokenizer st(cmdl, " ", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
        if (st.count())
        {
            _cmd = *(st.begin());
            Poco::StringTokenizer::Iterator it = st.begin();
            ++it;
            for (; it != st.end(); it++)
            {
                Poco::StringTokenizer ist(*it, "=", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
                int cnt = (int)ist.count();
                if (1 == cnt)
                {
                    _args.insert<std::string>(ist[0], "");
                }
                else
                {
                    for (int i = 0; i < cnt - 1; i++)
                    {
                        _args.insert<std::string>(ist[i], ist[cnt - 1]);
                    }
                }
            }
        }
    }

    inline std::string cmd() const
    {
        return _cmd;
    }

    template<class T>
    T get(const std::string &arg) const
    {
        T t;
        Poco::DynamicStruct::ConstIterator it = _args.find(arg);
        if (it != _args.end())
        {
            t = it->second.convert<T>();
        }

        return t;
    }

    bool has(const std::string &arg) const
    {
        Poco::DynamicStruct::ConstIterator it = _args.find(arg);
        return  it != _args.end();
    }

    std::string get(const std::string &arg) const
    {
        std::string ret;
        Poco::DynamicStruct::ConstIterator it = _args.find(arg);
        if (it != _args.end())
        {
            ret = it->second.toString();
        }

        return ret;
    }

    bool isNumeric(const std::string &arg) const
    {
        bool ret = false;
        Poco::DynamicStruct::ConstIterator it = _args.find(arg);
        if (it != _args.end())
        {
            ret = it->second.isNumeric();
        }

        return ret;
    }

    size_t size() const
    {
        return _args.size();
    }

    std::string source() const
    {
        return _source;
    }

private:
    std::string _cmd;
    Poco::DynamicStruct _args;
    std::string _source;
};
