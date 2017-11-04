/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_unf_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/11/13
   Description   :
   History       :
   1.Date        : 2013/11/13
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


/**
 * \file
 **\brief : define PANELLAY module information
 * \brief supply infor about PANELlay.
 */

#ifndef  __DRV_PANEL_EXT_H__
#define  __DRV_PANEL_EXT_H__

#include "hi_type.h"
//#include "hi_unf_panel.h"
#include "hi_drv_panel.h"
#include "hi_drv_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct hiPANEL_EXPORT_FUNC_S
{
    HI_S32  (* FN_PANEL_Cfg3DSig)(HI_DRV_PANEL_3D_SYNC_INFO_S *pst3DSigInfo);
    HI_S32  (* FN_PANEL_GetCfg)(HI_DRV_DISP_EXPECT_INFO_S *pstDispInfo, HI_DRV_PANEL_CFG_S *pstPanelCfg);
    HI_S32  (* FN_PANEL_CheckPanelInfo)(HI_DRV_PANEL_INFO_S *pstPanelInfo);
    HI_S32  (* FN_PANEL_GetPanelInfo)(HI_DRV_PANEL_INFO_S *pstPanelInfo);
    HI_S32  (* FN_PANEL_SetFrmRate)(HI_U32 *pu32OutFrmRate);
    HI_S32  (* FN_PANEL_SetIntfPower)(HI_BOOL bPowerOn);
	HI_VOID	(* FN_PANEL_SetPwmCfg)(HI_VOID);
	// cvte shiqiankun @ 20160324 add to close pwm
	HI_VOID	(* FN_PANEL_SetPwmDisable)(HI_VOID);
	// cvte shiqiankun @ 20160324 add end
    HI_S32  (* FN_PANEL_LocalDimmingFunReg)(HI_VOID);
    HI_VOID (* FN_PANEL_LocalDimmingFunUnReg)(HI_VOID);
    HI_S32  (* FN_PANEL_SetPanelMode)(HI_VOID);
    HI_S32  (* FN_PANEL_ResumePanelCfg)(HI_VOID);
    
}PANEL_EXPORT_FUNC_S;

HI_S32  DRV_PANEL_Register(HI_VOID);
HI_VOID DRV_PANEL_UnRegister(HI_VOID);
HI_S32 PANEL_DRV_ModInit(HI_VOID);
HI_VOID PANEL_DRV_ModExit(HI_VOID);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
