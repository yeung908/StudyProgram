#include "webrtc/modules/desktop_capture/android/screen_capturer_android.h"
#include "webrtc/modules/desktop_capture/android/android_capturer_utils.h"
#include "webrtc/modules/desktop_capture/desktop_frame.h"
#include "RtcLoggerWrapper.h"
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

namespace webrtc {

ScreenCapturerAndroid::ScreenCapturerAndroid()
    : graphics_fd_(-1), graphics_framebuffer_(nullptr), map_size_(0),
      callback_(nullptr) {

    AndroidScreenUtils::GetScreenInfo(&width_, &height_, &bytesPerPix_);
}

ScreenCapturerAndroid::~ScreenCapturerAndroid() {
    UnInit();
}

void ScreenCapturerAndroid::Start(Callback* callback) {
    assert(!callback_);
    assert(callback);

    callback_ = callback;
}

void ScreenCapturerAndroid::CaptureFrame() {

    assert(callback_);

    if ( bytesPerPix_ != DesktopFrame::kBytesPerPixel ) {
      callback_->OnCaptureResult(Result::ERROR_PERMANENT, nullptr);
      LOG(LS_ERROR) << "Unsupported screen image depth: " << DesktopFrame::kBytesPerPixel;
      return;
    }

    if ( graphics_fd_ == -1 || nullptr == graphics_framebuffer_ ) {
        if ( Init() != 0 ) {
            callback_->OnCaptureResult(Result::ERROR_PERMANENT, nullptr);
            LOG(LS_ERROR) << "init graphics framebuffer error.";
            return;
        }
    }

    std::unique_ptr<DesktopFrame> frame(
      new BasicDesktopFrame(DesktopSize(width_, height_)));

    int frameSize = DesktopFrame::kBytesPerPixel * frame->size().width() * frame->size().height();

    int iRet = ScreenShot(frame->data(), frameSize);

    if ( 0 != iRet ) {
        LOG(LS_ERROR) << "ScreenShot screen error.";
        callback_->OnCaptureResult(Result::ERROR_PERMANENT, nullptr);
        return;
    }

    callback_->OnCaptureResult(Result::SUCCESS, std::move(frame));
}

int ScreenCapturerAndroid::ScreenShot(uint8_t *pFrame, int frameSize) {

    struct fb_var_screeninfo var_info;
    
    if ( -1 == graphics_fd_ || ioctl(graphics_fd_, FBIOGET_VSCREENINFO, &var_info) < 0) {
        return -1;
    }

    int bytespp =  var_info.bits_per_pixel / 8;
    int offset = (var_info.xoffset + var_info.yoffset * var_info.xres) * bytespp;
    int screen_size = var_info.xres * var_info.yres * bytespp;

    if ( frameSize < screen_size ) {
        return -2;
    }

    memcpy(pFrame, graphics_framebuffer_ + offset, screen_size);
    
    return 0;
}

int ScreenCapturerAndroid::Init() {

    struct fb_var_screeninfo var_info;

    graphics_fd_ = open(AndroidScreenUtils::FRAME_BUFFER_PATH, O_RDONLY);
    if (graphics_fd_ < 0) {
        return -1;
    }

    if (ioctl(graphics_fd_, FBIOGET_VSCREENINFO, &var_info) < 0) {
        close(graphics_fd_);
        graphics_fd_ = -1;
        return -1;
    }

    map_size_ = var_info.xres_virtual * var_info.yres_virtual * (var_info.bits_per_pixel / 8);
    graphics_framebuffer_ = (char *)mmap(0, map_size_, PROT_READ, MAP_SHARED, graphics_fd_, 0);

    if (graphics_framebuffer_ == MAP_FAILED) {
        close(graphics_fd_);
        graphics_fd_ = -1;
        graphics_framebuffer_ = nullptr;
        return -1;
    }

    return 0;
}

void ScreenCapturerAndroid::UnInit() {

    munmap(graphics_framebuffer_, map_size_);
    close(graphics_fd_);
    graphics_fd_ = -1;
    graphics_framebuffer_ = nullptr;
}

} // namespace webrtc
