#include "webrtc/modules/desktop_capture/android/screen_capturer_android_510.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/base/timeutils.h"
#include "libyuv.h"
#include "RtcLoggerWrapper.h"
#include <assert.h>
#include <fcntl.h>

#define CAPTURE_SCREENT_WIDTH       1280
#define CAPTURE_SCREENT_HEIGHT      720

namespace webrtc {

ScreenCapturerAndroid510::ScreenCapturerAndroid510()
 : callback_(nullptr), isInitDISP_(false), 
   width_(CAPTURE_SCREENT_WIDTH), height_(CAPTURE_SCREENT_HEIGHT) {
}

ScreenCapturerAndroid510::~ScreenCapturerAndroid510() {
    DeInitDISP();
}

void ScreenCapturerAndroid510::Start(Callback* callback) {
    assert(!callback_);
    assert(callback);
    callback_ = callback;
}

void ScreenCapturerAndroid510::CaptureFrame() {

    assert(callback_);

    if ( !isInitDISP_ ) {
        if ( 0 != InitDISP() ) {
            callback_->OnCaptureVideoFrame(Result::ERROR_PERMANENT, nullptr);
            return;
        }
    }

    rtc::scoped_refptr<VideoFrameBuffer>  buffer = AcquireVideoFrame();

    if ( nullptr == buffer ) {
        callback_->OnCaptureVideoFrame(Result::ERROR_PERMANENT, nullptr);
        return;
    }

    std::unique_ptr<webrtc::VideoFrame> i420Frame(
        new webrtc::VideoFrame(buffer, webrtc::kVideoRotation_0, rtc::TimeUTCMicros()));
    callback_->OnCaptureVideoFrame(Result::SUCCESS, std::move(i420Frame));

    ReleaseVideoFrame();
}

rtc::scoped_refptr<VideoFrameBuffer> ScreenCapturerAndroid510::AcquireVideoFrame() {

    HI_S32 Ret = 0;
    rtc::scoped_refptr<VideoFrameBuffer>  buffer = nullptr;

    Ret = HI_UNF_DISP_AcquireCastFrame(dispCast_, &videoFrameInfo_, 500);

    if ( Ret != HI_SUCCESS ) {
        return nullptr;
    }

    HI_U32 u32Size = videoFrameInfo_.u32Height * videoFrameInfo_.stVideoFrameAddr[0].u32YStride + 
                        videoFrameInfo_.u32Height * videoFrameInfo_.stVideoFrameAddr[0].u32CStride / 2;

    HI_UCHAR *pSrcBuff = (HI_UCHAR *)(HI_MMAP(videoFrameInfo_.stVideoFrameAddr[0].u32YAddr, u32Size));
    buffer = I420Buffer::Create(videoFrameInfo_.u32Width, videoFrameInfo_.u32Height);
    libyuv::NV21ToI420(pSrcBuff, videoFrameInfo_.u32Width, 
                        pSrcBuff + videoFrameInfo_.u32Width * videoFrameInfo_.u32Height, videoFrameInfo_.u32Width,
                        (uint8*)buffer->DataY(), buffer->StrideY(),
                        (uint8*)buffer->DataU(), buffer->StrideU(),
                        (uint8*)buffer->DataV(), buffer->StrideV(),
                        buffer->width(), buffer->height());

    HI_MUNMAP(pSrcBuff);

    return buffer;
}

void ScreenCapturerAndroid510::ReleaseVideoFrame() {
    HI_UNF_DISP_ReleaseCastFrame(dispCast_, &videoFrameInfo_);
}

int ScreenCapturerAndroid510::InitDISP() {

    HI_S32 Ret = 0;

    HI_UNF_DISP_CAST_ATTR_S     stDispCastAttr;
    
    Ret = HI_SYS_Init();

    if ( Ret != HI_SUCCESS ) {
        return -1;
    }

    Ret = HI_UNF_DISP_Init();

    if ( Ret != HI_SUCCESS ) {
        return -1;
    }

    Ret = HI_UNF_DISP_GetDefaultCastAttr(HI_UNF_DISPLAY1, &stDispCastAttr);

    if ( Ret != HI_SUCCESS ) {
        return -1;
    }

    stDispCastAttr.enFormat = HI_UNF_FORMAT_YUV_SEMIPLANAR_420;
    stDispCastAttr.u32Width  = CAPTURE_SCREENT_WIDTH;
    stDispCastAttr.u32Height = CAPTURE_SCREENT_HEIGHT;

    Ret = HI_UNF_DISP_CreateCast(HI_UNF_DISPLAY1, &stDispCastAttr, &dispCast_);

    if ( Ret != HI_SUCCESS ) {
        return -1;
    }

    Ret = HI_UNF_DISP_SetCastEnable(dispCast_, HI_TRUE);

    if ( Ret != HI_SUCCESS ) {
        return -1;
    }

    isInitDISP_ = true;

    return 0;
}

void ScreenCapturerAndroid510::DeInitDISP() {

    if ( !isInitDISP_ ) {
        return;
    }

    HI_UNF_DISP_ReleaseCastFrame(dispCast_, &videoFrameInfo_);
    HI_UNF_DISP_SetCastEnable(dispCast_, HI_FALSE);
    HI_UNF_DISP_DestroyCast(dispCast_);
    HI_UNF_DISP_DeInit();
    HI_SYS_DeInit();
    isInitDISP_ = false;
}

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawWindowCapturer(
      const DesktopCaptureOptions& options) {
    return nullptr;
}

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawScreenCapturer(
    const DesktopCaptureOptions& options) {
    std::unique_ptr<DesktopCapturer> capturer(new ScreenCapturerAndroid510());
    return std::move(capturer);
}

}   // namespace webrtc
