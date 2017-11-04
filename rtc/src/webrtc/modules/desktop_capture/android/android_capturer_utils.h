#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_ANDROID_CAPTURE_UTILS_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_ANDROID_CAPTURE_UTILS_H_

#include "RtcLoggerWrapper.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <string>

namespace webrtc {

class AndroidScreenUtils {

public:
    static int GetScreenInfo(int *w, int *h, int *bytesPerPix) {

        struct fb_var_screeninfo var_info;

        int fd = open(FRAME_BUFFER_PATH, O_RDONLY);
        if (fd < 0) {
            LOG(LS_ERROR) << "open graphics dev error.";
            return -1;
        }
        if (ioctl(fd, FBIOGET_VSCREENINFO, &var_info) < 0) {
            close(fd);
            LOG(LS_ERROR) << "get graphics info error.";
            return -2;
        }

        *w =  var_info.xres;
        *h =  var_info.yres;
        *bytesPerPix = var_info.bits_per_pixel/8;

        close(fd);
        return 0;
    }
public:
      static const char FRAME_BUFFER_PATH[];
};

}

#endif // WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_ANDROID_CAPTURE_UTILS_H_
