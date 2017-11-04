#include "webrtc/modules/desktop_capture/android/screen_capturer_mtal.h"

namespace webrtc {

ScreenCaptureMtal::ScreenCaptureMtal(int width, int height, int bytesPerPix):
_width(width), _height(height), _bytesPerPix(bytesPerPix) {

    init();
}

ScreenCaptureMtal::~ScreenCaptureMtal() {

    releaseResources();
}

int ScreenCaptureMtal::ScreenShot(uint8_t **pRGBFrame, int *iRGBFrameSize) {

    UINT16 w, h, iImgSrc, color;
    int ret;

    ret = MTVSS_GetVideoInfo(&w, &h, &color, &iImgSrc);
    if(ret != 0) {
        return -1;
    }

    ret = MTVSS_GetFrameBuffer(0, 0, w, h, pRgb32Data);
    if(ret != 0) {
        return -2;
    }

    if(iCurImgSrc != iImgSrc && iCurImgSrc != -1) {
        reInit();
    }
    iCurImgSrc = iImgSrc;

    (*pRGBFrame) = (uint8_t *)pRgb32Data;
    (*iRGBFrameSize) = _width * _height * _bytesPerPix;

    return 0;
}

int ScreenCaptureMtal::reInit() {

    releaseResources();
    init();

    return 0;
}

int ScreenCaptureMtal::init() {

    int ret = 0;
    int msi_on = 0;
    MTVDO_REGION_T rRegionOut;
    MTVDO_REGION_T rRegionSrcr;
    UINT32 raw_width, raw_height;

    int iWidth = _width;
    int iHeight = _height;
    int iBytesPerPix = _bytesPerPix;

    pRgb32Data = (unsigned char *)malloc(iWidth * iHeight * iBytesPerPix);
    if(pRgb32Data == NULL) {
        return -1;
    }

    iCurImgSrc = -1;

    bmustong = FALSE;
    capture = MTVSS_MON_OUT;
    MTVSS_SCREEN_CAPTURE_MODE_T	eCaptureMode;
    MTVDO_REGION_T rgn;

    rgn.u4X = 0;
    rgn.u4Y = 0;
    rgn.u4Width = iWidth;
    rgn.u4Height = iHeight;

    DRV_Init();
    ret = MTVSS_GetScreenCaptureMode(&eCaptureMode);
    if(ret != 0) {
        return -1;
    }

    bmustong = (eCaptureMode == MTVSS_SCREEN_CAPTURE_FROM_OSTG)?TRUE:FALSE;

    if(init_mtvss(msi_on) < 0) {
        return -1;
    }

    if(connect_mtvss(msi_on) < 0) {
        return -1;
    }

    if(TRUE == bmustong) {
        if (!msi_on) {
            ret = MTVDO_SetMonOutEnable(1);
            ret = MTVDO_SetMonOutSource((MTVDO_MON_OUT_IN_SELECT)7);
            ret = MTVDO_SetMonOutOutputWindow(&rgn);
        }
    }
    else {
        if (!msi_on) {

            //Bind OSTG with SUB
            MTVDECEX_SetVideoSrc(MTVDO_SUB, MTVDECEX_SRC_OSDENCODE1);
            ret= MTVDO_SetDisplayOff_Ext(MTVDO_SUB,0x02,TRUE);
            ret = MTVDO_GetPlaneWH(&raw_width, &raw_height);
            rRegionOut.u4X = 0 ;
            rRegionOut.u4Y = 0 ;
            rRegionOut.u4Width = iWidth * 10000 / raw_width;
            rRegionOut.u4Height = iHeight * 10000 / raw_height;

            rRegionSrcr.u4X = 0;
            rRegionSrcr.u4Y = 0;
            rRegionSrcr.u4Width = 10000;
            rRegionSrcr.u4Height = 10000;
            ret = MTVDO_SetOutRegion(MTVDO_SUB, &rRegionOut);
            ret = MTVDO_SetSrcRegion(MTVDO_SUB, &rRegionSrcr);
        }
    }

    /*driver may not init complete*/
    usleep(80*1000);

    if(connect_mtvss(msi_on) < 0) {
        return -1;
    }

    return ret;
}

int ScreenCaptureMtal::releaseResources() {

    uninit_mtvss(0);

    if(pRgb32Data != NULL) {

        free(pRgb32Data);
        pRgb32Data = NULL;
    }

    return 0;
}

int ScreenCaptureMtal::init_mtvss(int msi) {

    MTVSS_Init();
    return  MTVSS_SetColorFormat(0x00020001);
}

int ScreenCaptureMtal::connect_mtvss(int msi) {

    int ret;

    if(TRUE == bmustong) {
        ret = MTVSS_ConnectAll(capture);
    }
    else {
        ret = MTVSS_ConnectAll((MTVSS_PATH_T)MTVDO_SUB);
    }

    return ret;
}

void ScreenCaptureMtal::uninit_mtvss(int msi) {

    int ret = 0;
    if(TRUE == bmustong) {
        ret = MTVSS_DisconnectAll(capture);
    }
    else {
        ret = MTVSS_Disconnect(MTVDO_SUB);

        if (!msi) {

            MTVDO_REGION_T rRegionOut;
            rRegionOut.u4X = 0;
            rRegionOut.u4Y = 0;
            rRegionOut.u4Width = 0;
            rRegionOut.u4Height = 0;

            ret = MTVDO_SetOutRegion(MTVDO_SUB, &rRegionOut);
            ret = MTVDO_SetDisplayOff_Ext(MTVDO_SUB,0x02,FALSE);
            ret = MTVDECEX_SetVideoSrc(MTVDO_SUB, MTVDECEX_SRC_MAX);
        }
    }
}

} // namespace webrtc
