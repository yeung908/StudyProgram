#ifndef WEBRTC_MODULES_UTILITY_INCLUDE_ANDROID_VERSION_HELPER_H_
#define WEBRTC_MODULES_UTILITY_INCLUDE_ANDROID_VERSION_HELPER_H_

namespace webrtc
{
	namespace MAXHUB {
		static const char *kMainBoardMTK5508 = "MTK5508";
		static const char *kMainBoardRK3399 = "3399";
		static const char *kMainBoardHISI510 = "510";
	}
    int AndroidSDKVersion();
    std::string GetAndroidBoardName();
}

#endif