#pragma once
#include <string>
#include "webrtc/base/logging.h"

namespace Poco
{
class Logger;
}

namespace vcs
{
class RtcLogSink : public rtc::LogSink
{
public:
    explicit RtcLogSink(const std::string &module = "rtc");

    virtual void OnLogMessage(const std::string& message) override;

private:
    Poco::Logger &_logger;
};
}
