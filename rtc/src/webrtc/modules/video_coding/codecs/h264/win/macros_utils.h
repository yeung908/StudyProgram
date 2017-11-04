#ifndef WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_MACROS_UTILS_H
#define WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_MACROS_UTILS_H

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(*(array)))

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&) = delete; \
	void operator==(const TypeName&) = delete

#define EXECUTE_IF_SUCCEEDED(hr, func) \
	if(SUCCEEDED(hr)) hr = (func)

#endif