#include "webrtc/modules/desktop_capture/android/screen_capturer_uwst.h"
#include "webrtc/modules/desktop_capture/desktop_frame.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "RtcLoggerWrapper.h"
#include <assert.h>

namespace webrtc {

ScreenCapturerUWST::ScreenCapturerUWST(DesktopCapturer* sourceCapturer) 
    : callback_(nullptr), sourceCapturer_(sourceCapturer) {
    
    assert(sourceCapturer);
}

ScreenCapturerUWST::~ScreenCapturerUWST() {
    if ( nullptr != circle_header_ ) {
        circle_Uninit(0);
        circle_header_ = nullptr;
    }
}

void ScreenCapturerUWST::Start(Callback* callback) {
    assert(!callback_);
    assert(callback);

    callback_ = callback;

    sourceCapturer_->Start(callback);
}

void ScreenCapturerUWST::CaptureFrame() {
    assert(callback_);

    if ( !IsUWST() ) {
        sourceCapturer_->CaptureFrame();
        return;
    }

    rtc::scoped_refptr<VideoFrameBuffer>  buffer = GetYuvFromUWST();

    if ( nullptr == buffer ) {
        callback_->OnCaptureResult(Result::ERROR_TEMPORARY, nullptr);
        return;
    }

    std::unique_ptr<webrtc::VideoFrame> i420Frame(
        new webrtc::VideoFrame(buffer, webrtc::kVideoRotation_0, rtc::TimeUTCMicros()));

    callback_->OnCaptureVideoFrame(Result::SUCCESS, std::move(i420Frame));
    
    return;
}

bool ScreenCapturerUWST::IsUWST() {
    if ( nullptr == circle_header_ ) {
        circle_header_ = circleInit(0);
        if ( nullptr == circle_header_) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

rtc::scoped_refptr<VideoFrameBuffer> ScreenCapturerUWST::GetYuvFromUWST() {

    if ( nullptr == circle_header_ ) {
        return nullptr;
    }

    int iWidth = 0;
    int iHeight = 0;
    int iDataType = 0;
    int iYUVFrameSize = 0;

    if ( 0 != getScrennInfo(circle_header_, &iWidth, &iHeight) ) {
        return nullptr;
    }

    rtc::scoped_refptr<VideoFrameBuffer>  buffer = webrtc::I420Buffer::Create(iWidth, iHeight);

    iYUVFrameSize = getYuvData(circle_header_ , (void *)buffer->DataY(), &iDataType);

    if ( ENUM_END == iDataType ) {
        circle_Uninit(0);
        circle_header_ = nullptr;
    }

    if ( 0 == iYUVFrameSize || ENUM_PIC != iDataType ) {
        return nullptr;
    }

    return buffer;
}

}