/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vfe_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/08/15
  Description   : 
  History       :
  1.Date        : 2012/08/15
    Author      : c00186004/t00202585/x00185802
    Modification: Created file
******************************************************************************/

#ifndef __DRV_VFE_EXT_H__
#define __DRV_VFE_EXT_H__

#include "hi_drv_vfe.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct
{    
    HI_S32 (*pfnVfeInit)(HI_VOID);
    HI_S32 (*pfnVfeDeInit)(HI_VOID);
    HI_S32 (*pfnVfeConnect)(HI_HANDLE *phVfe, HI_DRV_VFE_SOURCE_ATTR_S *psSource);
    HI_S32 (*pfnVfeDisconnect)(HI_HANDLE hVfe);
    HI_S32 (*pfnVfeSetPllAttr)(HI_HANDLE hVfe, HI_DRV_VFE_PLL_ATTR_S *pstPllAttr);
    HI_S32 (*pfnVfeGetPllAttr)(HI_HANDLE hVfe, HI_DRV_VFE_PLL_ATTR_S *pstPllAttr);
    HI_S32 (*pfnVfeSetClamp)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_CLAMP_ATTR_S *pstClamp);
    HI_S32 (*pfnVfeGetClamp)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_CLAMP_ATTR_S *pstClamp);
    HI_S32 (*pfnVfeSetSyncType)(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_TYPE_E enSyncType, HI_BOOL bSepSyncInv);
    HI_S32 (*pfnVfeGetSyncType)(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_TYPE_E *penSyncType);
    HI_S32 (*pfnVfeSetGain)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 u32Gain);
    HI_S32 (*pfnVfeGetGain)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 *pu32Gain);
    HI_S32 (*pfnVfeSetOffset)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 u32Offset);
    HI_S32 (*pfnVfeGetOffset)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 *pu32Offset);
    HI_S32 (*pfnVfeSetSifGain)(HI_HANDLE hVfe, HI_U32 u32SifGain);
    HI_S32 (*pfnVfeGetSifGain)(HI_HANDLE hVfe, HI_U32 *pu32SifGain);
    HI_S32 (*pfnVfeSetSifOffset)(HI_HANDLE hVfe, HI_U32 u32SifOffset);
    HI_S32 (*pfnVfeGetSifOffset)(HI_HANDLE hVfe, HI_U32 *pu32SifOffset);  
    HI_S32 (*pfnVfeSetHTotal)(HI_HANDLE hVfe, HI_U32 u32Htotal);
    HI_S32 (*pfnVfeGetHTotal)(HI_HANDLE hVfe, HI_U32 *pu32Htotal);    
    HI_S32 (*pfnVfeSetPhase)(HI_HANDLE hVfe, HI_U32 u32Phase);
    HI_S32 (*pfnVfeGetPhase)(HI_HANDLE hVfe, HI_U32 *pu32Phase);
    HI_S32 (*pfnVfeSetSlicerLevel)(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_CHN_TYPE_E enSyncChn, HI_U32 u32Level);
    HI_S32 (*pfnVfeGetSlicerLevel)(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_CHN_TYPE_E enSyncChn, HI_U32 *pu32Level);
    HI_S32 (*pfnVfeSetLpfAttr)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_LPF_FILTER_ATTR_U *pstLpfAttr);
    HI_S32 (*pfnVfeGetLpfAttr)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_LPF_FILTER_ATTR_U *pstLpfAttr);
    HI_S32 (*pfnVfePowerCtrl)(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_BOOL bEnable);
    HI_S32 (*pfnVfeSetVideoOutGain)(HI_DRV_VFE_VIDEO_OUT_CHN_E enVideoOutChn, HI_U32 u32Gain);
    HI_S32 (*pfnVfeCfgVideoOut)(HI_DRV_VFE_VIDEO_OUT_CHN_E enVideoOutChn, HI_BOOL bEnable);   
    HI_S32 (*pfnVfeSetOfflineSlicerLevel)(HI_U32 u32Level);      
    HI_S32 (*pfnVfeCheckOfflineSigStatus)(HI_DRV_VFE_OFFLINE_ATTR_S *psOfflineAttr, HI_BOOL *pbSigStable, HI_BOOL bSyncTypeCheck);  
    HI_U32 (*pfnVfeGetCvbsSampleRate)(HI_VOID);
    HI_S32 (*pfnVfeCfgHddecCrgReg)(HI_BOOL bInit);
    HI_S32 (*pfnVfeSetAdcCal)(HI_VOID);
	HI_S32 (*pfnVfeSetApllCfg7)(HI_U32 u32ApllCfg1, HI_U32 u32ApllCfg2);
} VFE_EXPORT_FUNC_S;

HI_S32 VFE_ModInit(HI_VOID);
HI_VOID VFE_ModExit(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __DRV_VFE_EXT_H__ */

