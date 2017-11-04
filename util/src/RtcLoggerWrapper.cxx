#include "RtcLoggerWrapper.h"
#include <Poco/Logger.h>
#include <Poco/Token.h>
#include <Poco/StringTokenizer.h>
#include <cstdlib>

namespace vcs
{
void RtcLogSink::OnLogMessage(const std::string& message)
{
    std::string msg = message;
    msg.resize(message.size() - 1);
    size_t headSize = msg.find_first_of(')');
    std::string head = msg.substr(0, headSize);

    Poco::StringTokenizer tokenizer(head, ":");
    std::string file, line, text;
    if (tokenizer.count() >= 2)
    {
        file = tokenizer[0].substr(1);
        line = tokenizer[1].substr(0);
    }

    text = msg.substr(headSize + 2);

    int lineNumber = atoi(line.c_str());

    if (_logger.notice())
    {
        _logger.notice(text, file.c_str(), (int)lineNumber);
    }
}

RtcLogSink::RtcLogSink(const std::string &module)
    :_logger(Poco::Logger::get(module))
{
}
}
