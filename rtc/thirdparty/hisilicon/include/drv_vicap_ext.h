/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_vicap.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/08/15
  Description   : 
  History       :
  1.Date        : 2012/08/15
    Author      : c00186004/t00202585
    Modification: Created file
******************************************************************************/

#ifndef __DRV_VICAP_EXT_H__
#define __DRV_VICAP_EXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_drv_vicap.h"

typedef HI_S32  (*FN_VICAP_Create)(HI_DRV_VICAP_CREATE_ATTR_S *pstVicapAttr, HI_HANDLE *phVicap);
typedef HI_S32  (*FN_VICAP_Destroy)(HI_HANDLE hVicap);
typedef HI_S32  (*FN_VICAP_Start)(HI_HANDLE hVicap);
typedef HI_S32  (*FN_VICAP_Stop)(HI_HANDLE hVicap);
typedef HI_S32  (*FN_VICAP_GetOutputAttr)(HI_HANDLE hVicap, HI_DRV_VICAP_OUTPUT_ATTR_S *pstOutAttr);
typedef HI_S32  (*FN_VICAP_SetOutputAttr)(HI_HANDLE hVicap, HI_DRV_VICAP_OUTPUT_ATTR_S *pstOutAttr);
typedef HI_S32  (*FN_VICAP_QueueFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
typedef HI_S32  (*FN_VICAP_DequeueFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
typedef HI_S32  (*FN_VICAP_UserAcquireFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo, HI_U32 u32TimeoutMs);
typedef HI_S32  (*FN_VICAP_UserReleaseFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
typedef HI_S32  (*FN_VICAP_AcquireFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
typedef HI_S32  (*FN_VICAP_ReleaseFrame)(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
typedef HI_S32  (*FN_VICAP_RegistHook)(HI_HANDLE hVicap, HI_HANDLE hDst,PFN_VICAP_CALLBACK pfVicapCallback);
typedef HI_S32  (*FN_VICAP_SetSrcCscType)(HI_HANDLE hVicap, HI_DRV_VICAP_SOURCE_CSC_TYPE_E *pEcscType);
typedef HI_S32  (*FN_VICAP_UpdataDynamicSourceData)(HI_U32 u32VicapId, HI_DRV_VICAP_DYNAMIC_SOURCE_DATA_S *pstDynamicSourceData);


typedef struct
{
    FN_VICAP_Create           pfnVicapCreate;
    FN_VICAP_Destroy          pfnVicapDestroy;
    
    FN_VICAP_Start            pfnVicapStart;
    FN_VICAP_Stop             pfnVicapStop;
    FN_VICAP_GetOutputAttr    pfnVicapGetOutputAttr;
    FN_VICAP_SetOutputAttr    pfnVicapSetOutputAttr;

    FN_VICAP_QueueFrame       pfnVicapQueueFrame;
    FN_VICAP_DequeueFrame     pfnVicapDequeueFrame;
    FN_VICAP_UserAcquireFrame pfnVicapUserAcquireFrame;
    FN_VICAP_UserReleaseFrame pfnVicapUserReleaseFrame;
    FN_VICAP_AcquireFrame     pfnVicapAcquireFrame;
    FN_VICAP_ReleaseFrame     pfnVicapReleaseFrame;
    FN_VICAP_RegistHook       pfnVicapRegistHook;
    FN_VICAP_SetSrcCscType    pfnVicapSetSrcCscType;
    FN_VICAP_UpdataDynamicSourceData    pfnVicapUpdataDynamicSourceData;
} VICAP_EXPORT_FUNC_S;


HI_S32 __init VICAP_DRV_ModInit(HI_VOID);
HI_VOID __exit VICAP_DRV_ModExit(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __DRV_VICAP_EXT_H__ */
