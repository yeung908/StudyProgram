/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vi_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/15
  Description   : 
  History       :
  1.Date        : 2013/11/15
    Author      : c00186004/w00248302
    Modification: Created file
******************************************************************************/

#ifndef __DRV_VI_IOCTL_H__
#define __DRV_VI_IOCTL_H__

#include "hi_drv_vi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct hiVI_CREATE_S
{
    HI_HANDLE        hVi;
    HI_DRV_VI_ATTR_S stViAttr;
} VI_CREATE_S;

typedef struct hiVI_BUF_ATTR_S
{
    HI_HANDLE            hVi;
    HI_DRV_VI_BUF_ATTR_S stBufAttr;
} VI_BUF_ATTR_S;

typedef struct hiVI_FRAME_S
{
    HI_HANDLE            hVi;
    HI_DRV_VIDEO_FRAME_S stViFrame;
    HI_U32               u32TimeoutMs;
} VI_FRAME_S;

typedef struct hiVI_ATTACH_ATTR_S
{
    HI_HANDLE hVi;
    HI_HANDLE hDest;
} VI_ATTACH_ATTR_S;

typedef struct hiVI_NONSTD_INFO_S
{
    HI_HANDLE                  hVi;
    HI_DRV_VIDEO_NONSTD_INFO_S stNstdInfo;
} VI_NONSTD_INFO_S;

typedef struct hiVI_WIN_INFO_S
{
    HI_HANDLE                 hVi;
    HI_HANDLE                 hDest;
    HI_DRV_PRE_PROCESS_INFO_S stWinInfo;
} VI_WIN_INFO_S;

typedef struct hiVI_VENC_INFO_S
{
    HI_HANDLE hVi;
    HI_HANDLE hDest;
    HI_U32    u32Width;
    HI_U32    u32Height;
} VI_VENC_INFO_S;

typedef struct hiVI_DSTFRMRATE_INFO_S
{
    HI_HANDLE hVi;
    HI_HANDLE hDest;
    HI_U32    u32DstFrmRate;
} VI_DSTFRMRATE_INFO_S;

typedef struct VI_FMT_ENABLE_S
{
    HI_HANDLE hVi;
    HI_BOOL   bEnable;
} VI_FMT_ENABLE_S;

typedef struct VI_FMT_QUERYRESULT_S
{
    HI_HANDLE hVi;
    HI_DRV_FRAME_TYPE_E eframeType;
} VI_FMT_QUERYRESULT_S;

typedef struct VI_SOURCE_CSC_ATTR_S
{
    HI_HANDLE hVi;
    HI_DRV_VI_SOURCE_CSC_TYPE_E eViCscType;
}VI_SOURCE_CSC_ATTR_S;

typedef enum hiIOC_VI_E
{
    IOC_VI_CREATE = 0,
    IOC_VI_DESTROY,    
    IOC_VI_ATTACH,
    IOC_VI_DETACH,
    IOC_VI_START,
    IOC_VI_STOP,
    IOC_VI_QUEUE_FRAME,
    IOC_VI_DEQUEUE_FRAME,    
    IOC_VI_ACQUIRE_FRAME,
    IOC_VI_RELEASE_FRAME,    
    IOC_VI_SET_EXTBUF,    
    IOC_VI_UPDATE_NSTD,
    IOC_VI_UPDATE_WININFO,
    IOC_VI_UPDATE_VENCINFO,
    IOC_VI_UPDATE_DSTFRMRATE,
    IOC_VI_FMTDECTMNG_ENABLE,
    IOC_VI_FMTDECTMNG_QUERYRESULT,
    IOC_VI_SET_SOURCE_CSC_TYPE,
    
    IOC_VI_BUTT,
} IOC_VI_E;

#define CMD_VI_CREATE         _IOWR(HI_ID_VI, IOC_VI_CREATE, VI_CREATE_S)
#define CMD_VI_DESTROY        _IOWR(HI_ID_VI, IOC_VI_DESTROY, HI_HANDLE)

#define CMD_VI_ATTACH         _IOWR(HI_ID_VI, IOC_VI_ATTACH, VI_ATTACH_ATTR_S)
#define CMD_VI_DETACH         _IOWR(HI_ID_VI, IOC_VI_DETACH, VI_ATTACH_ATTR_S)

#define CMD_VI_START          _IOWR(HI_ID_VI, IOC_VI_START, HI_HANDLE)
#define CMD_VI_STOP           _IOWR(HI_ID_VI, IOC_VI_STOP, HI_HANDLE)

#define CMD_VI_QUEUE_FRAME    _IOWR(HI_ID_VI, IOC_VI_QUEUE_FRAME, VI_FRAME_S)
#define CMD_VI_DEQUEUE_FRAME  _IOWR(HI_ID_VI, IOC_VI_DEQUEUE_FRAME, VI_FRAME_S)

#define CMD_VI_ACQUIRE_FRAME  _IOWR(HI_ID_VI, IOC_VI_ACQUIRE_FRAME, VI_FRAME_S)
#define CMD_VI_RELEASE_FRAME  _IOWR(HI_ID_VI, IOC_VI_RELEASE_FRAME, VI_FRAME_S)

#define CMD_VI_SET_EXTBUF     _IOWR(HI_ID_VI, IOC_VI_SET_EXTBUF, VI_BUF_ATTR_S)

#define CMD_VI_UPDATE_NSTD    _IOWR(HI_ID_VI, IOC_VI_UPDATE_NSTD, VI_NONSTD_INFO_S)

/* 调试接口 */
#define CMD_VI_UPDATE_WININFO _IOWR(HI_ID_VI, IOC_VI_UPDATE_WININFO, VI_WIN_INFO_S)
/* 调试接口 */
#define CMD_VI_UPDATE_VENCINFO _IOWR(HI_ID_VI, IOC_VI_UPDATE_VENCINFO, VI_VENC_INFO_S)
/* 调试接口 */
#define CMD_VI_UPDATE_DSTFRMRATE _IOWR(HI_ID_VI, IOC_VI_UPDATE_DSTFRMRATE, VI_DSTFRMRATE_INFO_S)

#define CMD_VI_FMTDECTMNG_ENABLE     _IOWR(HI_ID_VI, IOC_VI_FMTDECTMNG_ENABLE, VI_BUF_ATTR_S)

#define CMD_VI_FMTDECTMNG_QUERYRESULT    _IOWR(HI_ID_VI, IOC_VI_FMTDECTMNG_QUERYRESULT, VI_NONSTD_INFO_S)

/* 调试接口 */
#define CMD_VI_SET_SOURCE_CSC_TYPE     _IOWR(HI_ID_VI, IOC_VI_SET_SOURCE_CSC_TYPE,VI_SOURCE_CSC_ATTR_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif //__DRV_VI_IOCTL_H__