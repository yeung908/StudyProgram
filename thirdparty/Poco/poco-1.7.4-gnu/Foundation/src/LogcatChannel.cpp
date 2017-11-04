#ifdef POCO_ANDROID
#include "Poco/LogcatChannel.h"
#include <android/log.h>
#include "Poco/Message.h"

namespace Poco {
	LogcatChannel::LogcatChannel(){}
	LogcatChannel::~LogcatChannel() {}
	
	void LogcatChannel::log(const Message& msg)
	{
		android_LogPriority prio = ANDROID_LOG_INFO;
		switch (msg.getPriority()) {
		case Message::PRIO_FATAL:
		case Message::PRIO_CRITICAL:
			prio = ANDROID_LOG_FATAL;
			break;
		case Message::PRIO_WARNING:
			prio = ANDROID_LOG_WARN;
			break;
		case Message::PRIO_ERROR:
			prio = ANDROID_LOG_ERROR;
			break;
		case Message::PRIO_NOTICE:
		case Message::PRIO_INFORMATION:
			prio = ANDROID_LOG_INFO;
			break;
		case Message::PRIO_DEBUG:
			prio = ANDROID_LOG_DEBUG;
			break;
		case Message::PRIO_TRACE:
			prio = ANDROID_LOG_VERBOSE;
			break;
		default:
			break;
		}
		
		__android_log_print(prio, msg.getSource().c_str(), "%s", msg.getText().c_str());
	}
}
#endif