#include <string>

#include "webrtc/modules/desktop_capture/android/mtal/include/mtcommon.h"
#include "webrtc/modules/desktop_capture/android/mtal/include/mtvdo.h"
#include "webrtc/modules/desktop_capture/android/mtal/include/mtvdecex.h"
#include "webrtc/modules/desktop_capture/android/mtal/include/mtvss.h"

#ifdef __cplusplus
extern "C" {
#endif

extern BOOL DRV_Init(void);
extern MT_RESULT_T MTVDO_SetMonOutEnable(BOOL fgEnable);
extern MT_RESULT_T MTVDO_SetMonOutSource(MTVDO_MON_OUT_IN_SELECT eSrcsel);
extern MT_RESULT_T MTVDO_SetMonOutOutputWindow(MTVDO_REGION_T *OutRegion);

#ifdef __cplusplus
}
#endif

namespace webrtc {

    class ScreenCaptureMtal {

    public:
        ScreenCaptureMtal(int width, int height, int bytesPerPix);
        ~ScreenCaptureMtal();

        int ScreenShot(uint8_t **pRGBFrame, int *iRGBFrameSize);
        int reInit();
    
    private:
        int init();
        int releaseResources();

        int init_mtvss(int msi);
        int connect_mtvss(int msi);
        void uninit_mtvss(int msi);

    private:
        BOOL bmustong;
        MTVSS_PATH_T capture;

        int iCurImgSrc;
        unsigned char *pRgb32Data;

        int _width;
        int _height;
        int _bytesPerPix;
    };


} // namespace webrtc
