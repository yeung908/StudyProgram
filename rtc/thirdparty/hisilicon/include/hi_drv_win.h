/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_win.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/17
  Description   :
  History       :
  1.Date        : 2009/12/17
    Author      : w58735
    Modification: Created file

******************************************************************************/

#ifndef __HI_DRV_WIN_H__
#define __HI_DRV_WIN_H__

#include "hi_drv_video.h"
#include "hi_drv_disp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif


#ifndef HI_ADVCA_FUNCTION_RELEASE
#ifndef     __VDP_ST__
#define HI_FATAL_WIN(fmt...) \
            HI_FATAL_PRINT(HI_ID_VO, fmt)

#define HI_ERR_WIN(fmt...) \
            HI_ERR_PRINT(HI_ID_VO, fmt)

#define HI_WARN_WIN(fmt...) \
            HI_WARN_PRINT(HI_ID_VO, fmt)

#define HI_INFO_WIN(fmt...) \
            HI_INFO_PRINT(HI_ID_VO, fmt)
#else
#define HI_FATAL_WIN(fmt...) \
            printf(fmt)

#define HI_ERR_WIN(fmt...) \
            printf(fmt)

#define HI_WARN_WIN(fmt...) \
            printf(fmt)

#define HI_INFO_WIN(fmt...) \
            printf(fmt)
#endif
#else

#define HI_FATAL_WIN(fmt...) 
#define HI_ERR_WIN(fmt...) 
#define HI_WARN_WIN(fmt...)
#define HI_INFO_WIN(fmt...)
#endif

#define DEF_MAX_WIN_NUM_ON_SINGLE_DISP 16
#define DEF_MAX_WIN_NUM_ON_VIRTUAL_DISP 16

/* window type */
typedef enum hiDRV_WIN_TYPE_E
{
    HI_DRV_WIN_ACTIVE_SINGLE = 0,
    HI_DRV_WIN_VITUAL_SINGLE,
    HI_DRV_WIN_ACTIVE_MAIN_AND_SLAVE,
    HI_DRV_WIN_ACTIVE_SLAVE,
    HI_DRV_WIN_BUTT
}HI_DRV_WIN_TYPE_E;


/* window swtich mode, in reset mode */
typedef enum hiDRV_WIN_SWITCH_E
{
    HI_DRV_WIN_SWITCH_LAST = 0,
    HI_DRV_WIN_SWITCH_BLACK = 1,
    HI_DRV_WIN_SWITCH_BUTT
} HI_DRV_WIN_SWITCH_E;


typedef struct hiDRV_WIN_NONLINEAR_SCL_S
{
    HI_BOOL     bEnable;
    HI_U32      u32SrcWidth;
    HI_U32      u32DstWidth;
} HI_DRV_WIN_NONLINEAR_SCL_S;



/**enum define about Window Type */
/**CNcomment:定义Window类型枚举*/
typedef enum hiDRV_WIN_CHANNEL_E
{
    HI_DRV_WIN_CHANNEL_AUTO = 0,
    HI_DRV_WIN_CHANNEL_MAIN,
    HI_DRV_WIN_CHANNEL_SUB,

    HI_DRV_WIN_CHANNEL_BUTT,    
}HI_DRV_WIN_CHANNEL_E;


/* window attribute */
typedef struct hiDRV_WIN_ATTR_S
{
    HI_BOOL                     bVirtual;
    HI_DRV_DISPLAY_E            enDisp;
    
    /* Channel type: Main/Sub/Auto, when Auto Driver will alocated Video Layer Automatically */
    HI_DRV_WIN_CHANNEL_E        enChannelType;

    HI_DRV_ASPECT_RATIO_S       stCustmAR;
    HI_DRV_ASP_RAT_MODE_E       enARCvrs;
    HI_BOOL                     bUseCropRect;
    HI_RECT_S                   stInRect;
    HI_DRV_CROP_RECT_S          stCropRect;
    HI_RECT_S                   stOutRect;

    /* only for virtual window */
    HI_BOOL                     bUserAllocBuffer;
    HI_U32                      u32BufNumber; /* [1,16] */
    HI_DRV_PIX_FORMAT_E         enDataFormat;

    /* New Add For TV Only:TV Real Display Region */
    HI_RECT_S                   stVideoRect; 
    
    /* New Add for TV NonLinear config */
    HI_DRV_WIN_NONLINEAR_SCL_S   stNonLinearInfo;

    /*just for window type  */
    HI_U32                      u32LayerID;
    
}HI_DRV_WIN_ATTR_S;

/* window information */
typedef struct hiDRV_WIN_INFO_S
{
    HI_DRV_WIN_TYPE_E   eType;

    HI_HANDLE           hPrim;
    HI_HANDLE           hSec;
}HI_DRV_WIN_INFO_S;

typedef HI_S32 (*PFN_GET_FRAME_CALLBACK)(HI_HANDLE hHd, HI_DRV_VIDEO_FRAME_S *pstFrm);
typedef HI_S32 (*PFN_PUT_FRAME_CALLBACK)(HI_HANDLE hHd, HI_DRV_VIDEO_FRAME_S *pstFrm);
typedef HI_S32 (*PFN_GET_WIN_INFO_CALLBACK)(HI_HANDLE hHd, HI_DRV_PRE_PROCESS_INFO_S *pstWin);

/* source information.
   window will get / release frame or send private info to sourec
   by function pointer */
typedef struct hiDRV_WIN_SRC_INFO_S
{
    HI_HANDLE hSrc;
    HI_HANDLE hAttachSrc;

#if 0
    PFN_GET_FRAME_CALLBACK pfAcqFrame;
    PFN_PUT_FRAME_CALLBACK pfRlsFrame;
    PFN_GET_WIN_INFO_CALLBACK pfSendWinInfo;
#endif

    HI_U32    u32Resrve0;
    HI_U32    u32Resrve1;
}HI_DRV_WIN_SRC_INFO_S;

/* window current play information, player gets it and adjust Audio and Video
   play rate */
typedef struct hiDRV_WIN_PLAY_INFO_S
{
    HI_U32    u32DelayTime; /* in ms */
    HI_U32    u32DispRate;  /* in 1/100 Hz */
    HI_U32    u32FrameNumInBufQn;
    HI_DRV_VIDEO_FRAME_S    newest_playframeinfo;    
    HI_BOOL   bTBMatch;  /* for interlace frame display on interlace timing */
}HI_DRV_WIN_PLAY_INFO_S;

typedef struct hiDRV_WIN_INTF_S
{
    HI_VOID* pfAcqFrame;
    HI_VOID* pfRlsFrame;
    HI_VOID* pfSetWinAttr;

    HI_U32    u32Resrve0;
    HI_U32    u32Resrve1;
}HI_DRV_WIN_INTF_S;

/**define the freeze mode enumeration.*/
/**CNcomment:定义Freeze模式枚举*/
typedef enum hiDRV_WIN_OWNER_E
{
    HI_DRV_WIN_OWNER_DTV = 0,
    HI_DRV_WIN_OWNER_ATV,
    HI_DRV_WIN_OWNER_MEDIA,
    HI_DRV_WIN_OWNER_BUTT
}HI_DRV_WIN_OWNER_E;

/**define window owner attribute.*/
/**CNcomment:定义window的owner属性*/
typedef struct hiDRV_WIN_OWNER_S
{
    HI_DRV_WIN_OWNER_E enWinHandleOwner;
}HI_DRV_WIN_OWNER_S;



HI_S32 HI_DRV_WIN_Create(HI_DRV_WIN_ATTR_S *pWinAttr, HI_HANDLE *phWindow);
HI_S32 HI_DRV_WIN_Destroy(HI_HANDLE hWindow);
HI_S32 HI_DRV_WIN_SetAttr(HI_HANDLE hWin, HI_DRV_WIN_ATTR_S *pWinAttr);
HI_S32 HI_DRV_WIN_SetSize(HI_HANDLE hWin, HI_U32 u32Width, HI_U32 u32Height);
HI_S32 HI_DRV_WIN_GetAttr(HI_HANDLE hWin, HI_DRV_WIN_ATTR_S *pWinAttr);
HI_S32 HI_DRV_WIN_GetInfo(HI_HANDLE hWindow, HI_DRV_WIN_INFO_S *pInfo);
HI_S32 HI_DRV_WIN_SetSource(HI_HANDLE hWindow, HI_DRV_WIN_SRC_INFO_S *pstSrc);//Window承接
HI_S32 HI_DRV_WIN_GetSource(HI_HANDLE hWin, HI_DRV_WIN_SRC_INFO_S *pstSrc);//Window承接
HI_S32 HI_DRV_WIN_SetEnable(HI_HANDLE hWindow, HI_BOOL bEnable);
HI_S32 HI_DRV_WIN_GetEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);
HI_S32 HI_DRV_WIN_QFrame(HI_HANDLE hWindow, HI_DRV_WIN_FRAME_NODE_S *pstNode);
HI_S32 HI_DRV_WIN_QULSFrame(HI_HANDLE hWindow, HI_DRV_WIN_FRAME_NODE_S
        *pstNode);
HI_S32 HI_DRV_WIN_DQFrame(HI_HANDLE hWindow, HI_DRV_VIDEO_FRAME_S *pFrame);
HI_S32 HI_DRV_WIN_QSyncFrame(HI_HANDLE hWindow, HI_DRV_VIDEO_FRAME_S *pstFrame, HI_U32 *pu32FenceFd);

HI_S32 HI_DRV_WIN_GetPlayInfo(HI_HANDLE hWindow, HI_DRV_WIN_PLAY_INFO_S *pInfo);//Window承接
HI_S32 HI_DRV_WIN_SetZorder(HI_HANDLE hWin, HI_LAYER_ZORDER_E ZFlag);
HI_S32 HI_DRV_WIN_GetZorder(HI_HANDLE hWin, HI_U32 *pu32Zorder);

HI_S32 HI_DRV_WIN_Reset(HI_HANDLE hWindow, HI_DRV_WIN_SWITCH_E enMode);
HI_S32 HI_DRV_WIN_GetPlayInfo(HI_HANDLE hWindow, HI_DRV_WIN_PLAY_INFO_S *pstInfo);

HI_S32 HI_DRV_WIN_SendFrame(HI_HANDLE hWindow, HI_DRV_VIDEO_FRAME_S *pFrame);
HI_S32 HI_DRV_WIN_Freeze(HI_HANDLE hWin, HI_BOOL bEnable,  HI_DRV_WIN_SWITCH_E eRst);//Window承接
HI_S32 HI_DRV_WIN_GetLatestFrameInfo(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *frame_info);//Window承接
HI_S32 HI_DRV_WIN_Reset(HI_HANDLE hWindow, HI_DRV_WIN_SWITCH_E enSwitch);
HI_S32 HI_DRV_WIN_Pause(HI_HANDLE hWin, HI_BOOL bEnable);
HI_S32 HI_DRV_WIN_SetStepMode(HI_HANDLE hWin, HI_BOOL bStepMode);
HI_S32 HI_DRV_WIN_SetStepPlay(HI_HANDLE hWin);
HI_S32 HI_DRV_WIN_SetExtBuffer(HI_HANDLE hWin, HI_DRV_VIDEO_BUFFER_POOL_S* pstBuf);
HI_S32 HI_DRV_WIN_AcquireFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);//Window承接
HI_S32 HI_DRV_WIN_ReleaseFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);//Window承接
HI_S32 HI_DRV_WIN_SetQuick(HI_HANDLE hWin, HI_BOOL bEnable);//Window承接
HI_S32 HI_DRV_WIN_CapturePicture(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pstPic);
HI_S32 HI_DRV_WIN_CapturePictureRelease(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pstPic);
HI_S32 HI_DRV_WIN_SetRotation(HI_HANDLE hWin, HI_DRV_ROT_ANGLE_E enRotation);
HI_S32 HI_DRV_WIN_GetRotation(HI_HANDLE hWin, HI_DRV_ROT_ANGLE_E *penRotation);
HI_S32 HI_DRV_WIN_SetFlip(HI_HANDLE hWin, HI_BOOL bHoriFlip, HI_BOOL bVertFlip);
HI_S32 HI_DRV_WIN_GetFlip(HI_HANDLE hWin, HI_BOOL *pbHoriFlip, HI_BOOL *pbVertFlip);
HI_S32 HI_DRV_WIN_SendFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);//Window承接
//HI_S32 HI_DRV_WIN_UpdatePqData(HI_U32 u32UpdateType, PQ_PARAM_S* pstPqParam);
HI_S32 HI_DRV_WIN_Init(HI_VOID);
HI_S32 HI_DRV_WIN_DeInit(HI_VOID);


/* New Add For TV */
HI_S32 HI_DRV_WIN_SetTimingInfo(HI_HANDLE hWin, HI_DRV_TIMING_INFO_S *pstTimingInfo);
HI_S32 HI_DRV_WIN_SetNstdInfo(HI_HANDLE hWin, HI_DRV_VIDEO_NONSTD_INFO_S *pstNstdInfo);

//HI_S32 HI_DRV_WIN_SetNoStdInfo(HI_HANDLE hWin, HI_DRV_TIMING_INFO_S *pstTimingInfo);
HI_S32 HI_DRV_WIN_GetPreProcess(HI_HANDLE hWin, HI_DRV_PRE_PROCESS_INFO_S *pstPreProcess);
HI_S32 HI_DRV_WIN_SetPreDelay(HI_HANDLE hWin, HI_U32 u32PreDelay);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_DRV_WIN_H__ */


