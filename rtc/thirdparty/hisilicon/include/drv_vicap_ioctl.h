/******************************************************************************

  Copyright (C), 2013-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vicap_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/08/15
  Description   : 
  History       :
  1.Date        : 2013/11/27
    Author      : w00248302/c00186004
    Modification: Created file
******************************************************************************/

#ifndef __DRV_VICAP_IOCTL_H__
#define __DRV_VICAP_IOCTL_H__

#include "hi_drv_vicap.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct hiVICAP_CREATE_S
{
    HI_HANDLE           hVicap;
    HI_DRV_VICAP_CREATE_ATTR_S stVicapAttr;
} VICAP_CREATE_S;

typedef struct hiVICAP_OUTPUT_ATTR_S
{
    HI_HANDLE                  hVicap;
    HI_DRV_VICAP_OUTPUT_ATTR_S stVicapOutAttr;
} VICAP_OUTPUT_ATTR_S;

typedef struct hiVICAP_FRAME_S
{
    HI_HANDLE            hVicap;
    HI_DRV_VIDEO_FRAME_S stVicapFrame;
    HI_U32               u32TimeoutMs;
} VICAP_FRAME_S;

typedef enum hiIOC_VICAP_E
{
    IOC_VICAP_CREATE = 0,
    IOC_VICAP_DESTROY,    
    IOC_VICAP_START,
    IOC_VICAP_STOP,
    IOC_VICAP_GETOUTPUTATTR,
    IOC_VICAP_SETOUTPUTATTR,
    IOC_VICAP_ACQUIREFRAME,
    IOC_VICAP_RELEASEFRAME,
    IOC_VICAP_USERACQUIREFRAME,
    IOC_VICAP_USERRELEASEFRAME,
    
    IOC_VICAP_BUTT,
} IOC_VICAP_E;

#define CMD_VICAP_CREATE            _IOWR(HI_ID_VICAP, IOC_VICAP_CREATE, VICAP_CREATE_S)
#define CMD_VICAP_DESTROY           _IOWR(HI_ID_VICAP, IOC_VICAP_DESTROY, HI_HANDLE)

#define CMD_VICAP_START             _IOWR(HI_ID_VICAP, IOC_VICAP_START, HI_HANDLE)
#define CMD_VICAP_STOP              _IOWR(HI_ID_VICAP, IOC_VICAP_STOP, HI_HANDLE)

#define CMD_VICAP_GETOUTPUTATTR     _IOWR(HI_ID_VICAP, IOC_VICAP_GETOUTPUTATTR, VICAP_OUTPUT_ATTR_S)
#define CMD_VICAP_SETOUTPUTATTR     _IOWR(HI_ID_VICAP, IOC_VICAP_SETOUTPUTATTR, VICAP_OUTPUT_ATTR_S)

#define CMD_VICAP_ACQUIREFRAME      _IOWR(HI_ID_VICAP, IOC_VICAP_ACQUIREFRAME, VICAP_FRAME_S)
#define CMD_VICAP_RELEASEFRAME      _IOWR(HI_ID_VICAP, IOC_VICAP_RELEASEFRAME, VICAP_FRAME_S)

#define CMD_VICAP_USERACQUIREFRAME  _IOWR(HI_ID_VICAP, IOC_VICAP_USERACQUIREFRAME, VICAP_FRAME_S)
#define CMD_VICAP_USERRELEASEFRAME  _IOWR(HI_ID_VICAP, IOC_VICAP_USERRELEASEFRAME, VICAP_FRAME_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif //__DRV_VICAP_IOCTL_H__
