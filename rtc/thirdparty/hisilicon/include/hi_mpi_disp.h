/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : mpi_disp.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/15
  Description   :
  History       :
  1.Date        : 2009/12/15
    Author      : w58735
    Modification: Created file

*******************************************************************************/


#ifndef __MPI_DISP_H__
#define __MPI_DISP_H__

#include "hi_drv_disp.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define CHECK_DISP_INIT()\
do{\
    HI_DISP_LOCK();\
    if (g_DispDevFd < 0)\
    {\
        HI_ERR_DISP("DISP is not init.\n");\
        HI_DISP_UNLOCK();\
        return HI_ERR_DISP_NO_INIT;\
    }\
    HI_DISP_UNLOCK();\
}while(0)


//:TODO: TV and STB COMMON API

HI_S32 HI_MPI_DISP_Init(HI_VOID);
HI_S32 HI_MPI_DISP_DeInit(HI_VOID);   

HI_S32 HI_MPI_DISP_Open(HI_DRV_DISPLAY_E enDisp);
HI_S32 HI_MPI_DISP_Close(HI_DRV_DISPLAY_E enDisp);

HI_S32 HI_MPI_DISP_Suspend(HI_VOID);
HI_S32 HI_MPI_DISP_Resume(HI_VOID);

HI_S32 HI_MPI_DISP_SetEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_MPI_DISP_GetEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable);

//This can be use as 3D L/R Switch
HI_S32 HI_MPI_DISP_SetRightEyeFirst(HI_DRV_DISPLAY_E enDisp, HI_BOOL bRFirst);

HI_S32 HI_MPI_DISP_SetVirtualScreen(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Width,
        HI_U32 u32Height, HI_DISP_VIRTSCREEN_TYPE_E enType);
HI_S32 HI_MPI_DISP_GetVirtualScreen(HI_DRV_DISPLAY_E enDisp, HI_U32 *u32Width,
        HI_U32 *u32Height, HI_DISP_VIRTSCREEN_TYPE_E enType);

//BG Color Related API
HI_S32 HI_MPI_DISP_SetBGColor(HI_DRV_DISPLAY_E eDisp, HI_COLOR_S *pstBGColor);
HI_S32 HI_MPI_DISP_GetBGColor(HI_DRV_DISPLAY_E eDisp, HI_COLOR_S *pstBGColor);

//Miracast Related API
HI_S32 HI_MPI_DISP_CreateCast(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_CAST_CFG_S *pstCfg, HI_HANDLE *phCast);
HI_S32 HI_MPI_DISP_DestroyCast(HI_HANDLE hCast);
HI_S32 HI_MPI_DISP_SetCastEnable(HI_HANDLE hCast, HI_BOOL bEnable);
HI_S32 HI_MPI_DISP_GetCastEnable(HI_HANDLE hCast, HI_BOOL *pbEnable);
HI_S32 HI_MPI_DISP_AcquireCastFrame(HI_HANDLE hCast, HI_DRV_VIDEO_FRAME_S *pstCastFrame);
HI_S32 HI_MPI_DISP_ReleaseCastFrame(HI_HANDLE hCast, HI_DRV_VIDEO_FRAME_S *pstCastFrame);
HI_S32 HI_MPI_DISP_ExtAttach(HI_HANDLE hCast, HI_HANDLE hSink);
HI_S32 HI_MPI_DISP_ExtDeAttach(HI_HANDLE hCast, HI_HANDLE hSink);

//snapshot
HI_S32 HI_MPI_DISP_SetSnapShotAttr(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_SNAPSHOT_ATTR_S *pstSnapAttr);
HI_S32 HI_MPI_DISP_Snapshot_Acquire(HI_DRV_DISPLAY_E enDisp, HI_DRV_VIDEO_FRAME_S * pstFrame);
HI_S32 HI_MPI_DISP_Snapshot_Release(HI_DRV_DISPLAY_E enDisp, HI_DRV_VIDEO_FRAME_S * pstFrame);

HI_S32 HI_MPI_DISP_SetFormat(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_STEREO_E enStereo, HI_DRV_DISP_FMT_E enFormat);
HI_S32 HI_MPI_DISP_GetFormat(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_STEREO_E *penStereo,HI_DRV_DISP_FMT_E *penFormat);
HI_S32 HI_MPI_DISP_SetTiming(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_TIMING_S *pstTiming);
HI_S32 HI_MPI_DISP_GetTiming(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_TIMING_S *pstTiming);


/* 3D Related API, 3D LR Swith use API of STB HI_DRV_DISP_SetRightEyeFirst() */
HI_S32 HI_MPI_DISP_Get3DDepthRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S  *pstDepthRange);
HI_S32 HI_MPI_DISP_Set3DDepthLevel(HI_DRV_DISPLAY_E enDisp, HI_U32      u32DepthLevel);
HI_S32 HI_MPI_DISP_Get3DDepthLevel(HI_DRV_DISPLAY_E enDisp, HI_U32      *pu32DepthLevel);

HI_S32 HI_MPI_DISP_Get3DViewRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S   *pstViewRange);
HI_S32 HI_MPI_DISP_Set3DViewLevel(HI_DRV_DISPLAY_E enDisp, HI_U32       u32ViewLevel);
HI_S32 HI_MPI_DISP_Get3DViewLevel(HI_DRV_DISPLAY_E enDisp, HI_U32       *pu32ViewLevel);

HI_S32 HI_MPI_DISP_SetVideo3DMode(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_3DMODE_E en3DMode);
HI_S32 HI_MPI_DISP_GetVideo3DMode(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_3DMODE_E *pen3DMode);

HI_S32 HI_MPI_DISP_Set3DTo2DMode(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_3DT2D_E en3DTo2DMode);
HI_S32 HI_MPI_DISP_Get3DTo2DMode(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_3DT2D_E *pen3DTo2DMode);


/* Frc Enable and Level Adjust API*/
HI_S32 HI_MPI_DISP_GetMemcRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S *pstRange);

HI_S32 HI_MPI_DISP_SetMemcDemo(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_MPI_DISP_GetMemcDemo(HI_DRV_DISPLAY_E enDisp, HI_U32 *pbEnable);

/* Frc Enable and Level Adjust API*/
HI_S32 HI_MPI_DISP_SetMemcLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 u32FRCLevel);
HI_S32 HI_MPI_DISP_GetMemcLevel(HI_DRV_DISPLAY_E enDisp,  HI_U32 *pu32FRCLevel);

HI_S32 HI_MPI_DISP_SetMemcEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_MPI_DISP_GetMemcEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable);

HI_S32 HI_MPI_DISP_WriteMemcPara(HI_U32 u32RegAddr,HI_U32 u32Data);
HI_S32 HI_MPI_DISP_ReadMemcPara(HI_U32 u32RegAddr, HI_U32 *pu32Value);

/* Flip and Mirror related API */
HI_S32 HI_MPI_DISP_SetFlip(HI_DRV_DISPLAY_E enDisp, HI_BOOL bHorFlip, HI_BOOL bVerFlip);
HI_S32 HI_MPI_DISP_GetFlip(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbHorFlip, HI_BOOL *pbVerFlip);


/* LVDS Test pattern,Color Bar */
HI_S32 HI_MPI_DISP_SetColorBarEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_MPI_DISP_GetColorBarEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable);

HI_S32 HI_MPI_DISP_SetTestPattern(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable, HI_COLOR_S pPatColor);
HI_S32 HI_MPI_DISP_GetTestPattern(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable, HI_COLOR_S *pPatColor);

HI_S32 HI_MPI_DISP_Attach(HI_DRV_DISPLAY_E enMaster, HI_DRV_DISPLAY_E enSlave);
HI_S32 HI_MPI_DISP_Detach(HI_DRV_DISPLAY_E enMaster, HI_DRV_DISPLAY_E enSlave);


HI_S32 HI_MPI_DISP_SetScreenOffset(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_OFFSET_S *pstOffset);
HI_S32 HI_MPI_DISP_GetScreenOffset(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_OFFSET_S *pstOffset);

HI_S32 HI_MPI_DISP_AddIntf(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf);
HI_S32 HI_MPI_DISP_DelIntf(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf);

HI_S32 HI_MPI_DISP_AddVDAC(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf, HI_U32 u32Number);
HI_S32 HI_MPI_DISP_DelVDAC(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf);

/* set aspect ratio */
HI_S32 HI_MPI_DISP_SetAspectRatio(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Ratio_h, HI_U32 u32Ratio_v);
HI_S32 HI_MPI_DISP_GetAspectRatio(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32Ratio_h, HI_U32 *pu32Ratio_v);


/* Macrovision */
HI_S32 HI_MPI_DISP_TestMacrovisionSupport(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbSupport);
HI_S32 HI_MPI_DISP_SetMacrovisionCustomer(HI_DRV_DISPLAY_E enDisp, HI_VOID *pData);
HI_S32 HI_MPI_DISP_SetMacrovision(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MACROVISION_E enMode);
HI_S32 HI_MPI_DISP_GetMacrovision(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MACROVISION_E *penMode);

//cgms-a
HI_S32 HI_MPI_DISP_SetCGMS_A(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_CGMSA_CFG_S *pstCfg);

//vbi
HI_S32 HI_MPI_DISP_CreateVBIChannel(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_VBI_CFG_S *pstCfg, HI_HANDLE *phVbi);
HI_S32 HI_MPI_DISP_DestroyVBIChannel(HI_HANDLE hVbi);
HI_S32 HI_MPI_DISP_SendVbiData(HI_HANDLE hVbi, const HI_DRV_DISP_VBI_DATA_S *pstVbiData);
HI_S32 HI_MPI_DISP_SetWss(HI_DRV_DISPLAY_E enDisp, const HI_DRV_DISP_WSS_DATA_S *pstWssData);

HI_S32 HI_MPI_DISP_SetLayerZorder(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_LAYER_E enLayer, HI_DRV_DISP_ZORDER_E enZFlag);
HI_S32 HI_MPI_DISP_GetLayerZorder(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_LAYER_E enLayer, HI_U32 *pu32Zorder);


HI_S32 HI_MPI_DISP_SetBrightness(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Brightness);
HI_S32 HI_MPI_DISP_GetBrightness(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32Brightness);
HI_S32 HI_MPI_DISP_SetContrast(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Contrast);
HI_S32 HI_MPI_DISP_GetContrast(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32Contrast);
HI_S32 HI_MPI_DISP_SetSaturation(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Saturation);
HI_S32 HI_MPI_DISP_GetSaturation(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32Saturation);
HI_S32 HI_MPI_DISP_SetHuePlus(HI_DRV_DISPLAY_E enDisp, HI_U32 u32HuePlus);
HI_S32 HI_MPI_DISP_GetHuePlus(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32HuePlus);


HI_S32 HI_MPI_DISP_SetCastAttr(HI_HANDLE hCast, HI_DRV_DISP_Cast_Attr_S *pstAttr);
HI_S32 HI_MPI_DISP_GetCastAttr(HI_HANDLE hCast, HI_DRV_DISP_Cast_Attr_S *pstAttr);
HI_S32 HI_MPI_DISP_GetDispInfo(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_DISPLAY_INFO_S *pstDispInfo);

HI_S32 HI_MPI_DISP_GetInkRGB(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INKATTR_S *pstInkAttr , HI_COLOR_S *pstInkRGB);

HI_S32 HI_MPI_DISP_SetChnDelay(HI_DRV_DISPLAY_E enDisp, HI_DRV_DELAY_S *pstDelayAttr);
HI_S32 HI_MPI_DISP_GetChnDelay(HI_DRV_DISPLAY_E enDisp, HI_DRV_DELAY_S *pstDelayAttr);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
