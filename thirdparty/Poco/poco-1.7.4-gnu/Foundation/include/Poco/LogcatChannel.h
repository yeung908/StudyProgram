//
// LogcatChannel.h
//
// $Id: //poco/1.4/Foundation/include/Poco/LogcatChannel.h#1 $
//
// Library: Foundation
// Package: Logging
// Module:  LogcatChannel
//
// Definition of the LogcatChannel class specific to Android.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_LogcatChannel_INCLUDED
#define Foundation_LogcatChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"


namespace Poco {


class Foundation_API LogcatChannel: public Channel
	/// This locat channel works with the Android logcat.
{
public:
	LogcatChannel();
		/// Creates a LogcatChannel.
			
	void log(const Message& msg);
		/// Sens the message's text to the logcat service.
		
protected:
	~LogcatChannel();
};


} // namespace Poco


#endif // Foundation_LogcatChannel_INCLUDED
