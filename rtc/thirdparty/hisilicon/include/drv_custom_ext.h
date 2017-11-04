/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_custom_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/06/15
  Description   : 
  History       :
  1.Date        : 2014/06/15
    Author      : w00184692
    Modification: Created file
******************************************************************************/

#ifndef _DRV_CUSTOM_EXT_H
#define _DRV_CUSTOM_EXT_H

#include "hi_type.h"
#include "hi_drv_panel.h"

HI_S32 CUSTOM_DRV_ModuleInit(HI_VOID);
HI_VOID CUSTOM_DRV_ModuleExit(HI_VOID);

//typedef HI_S32 (*FN_DRV_CUSTOM_GetPanelIndex)(HI_U32 *pu32Index);
//typedef HI_S32 (*FN_DRV_CUSTOM_SetPanelIndex)(HI_U32 u32Index);
typedef HI_S32 (*FN_DRV_CUSTOM_SetPanelPower)(HI_BOOL bPowerOn);
typedef HI_S32 (*FN_DRV_CUSTOM_SetPanelBlPower)(HI_BOOL bPowerOn);
typedef HI_S32 (*FN_DRV_CUSTOM_SetPanelTCONPower)(HI_BOOL bPowerOn);
typedef HI_S32 (*FN_DRV_CUSTOM_SetPanelMode)(HI_DRV_PANEL_TIMMING_E enTimmingType);
typedef HI_S32 (*FN_DRV_CUSTOM_GetLdmCustomInfo)(DRV_PANEL_LDM_TABLE_PS *pstLdmTab, 
    HI_U32 *pu32TabCnt, HI_U32 *pu32ProtHeadLen, HI_U32 *pu32ProtTailLen);
typedef HI_S32 (*FN_DRV_CUSTOM_GetLdmProtocolInfo)(HI_U8 *pu8DimData, 
    HI_U32 u32ProtHeadLen, HI_U32 u32ActTotalNum);

typedef struct
{
 //   FN_DRV_CUSTOM_GetPanelIndex     pfnGetPanelIndex;
//    FN_DRV_CUSTOM_SetPanelIndex     pfnSetPanelIndex;
    FN_DRV_CUSTOM_SetPanelPower         pfnSetPanelPower;
    FN_DRV_CUSTOM_SetPanelBlPower       pfnSetPanelBlPower;
    FN_DRV_CUSTOM_SetPanelTCONPower     pfnSetPanelTconPower;
	FN_DRV_CUSTOM_SetPanelMode          pfnSetPanelMode;
    FN_DRV_CUSTOM_GetLdmCustomInfo      pfnGetLdmCustomInfo;
    FN_DRV_CUSTOM_GetLdmProtocolInfo    pfnGetLdmProtocolInfo;

} CUSTOM_EXT_FUNC_S;

#endif
