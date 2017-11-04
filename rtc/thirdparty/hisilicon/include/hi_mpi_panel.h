/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_mpi_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/10/31
   Description   :
   History       :
   1.Date        : 2013/10/31
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


#ifndef  __HI_MPI_PANEL_H__
#define  __HI_MPI_PANEL_H__

#include "hi_unf_common.h"
#include "hi_drv_panel.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**Panel Dim strength Range*//**CNcomment:Panel PANEL Dim的强度范围 */
typedef struct hiUNF_PANEL_DIM_STRENGTH_RANGE_S
{
    HI_U32 u32MinStrength;                  /**<Dim strength Min Range */ /**<CNcomment:范围最小值 */
    HI_U32 u32MaxStrength;                  /**<Dim strength Max Range */ /**<CNcomment:范围最大值 */
    
}HI_UNF_PANEL_DIM_STRENGTH_RANGE_S;

/**Panel Dim Demo mode*//**CNcomment:Panel LocalDimming的Demo模式 */
typedef enum hiUNF_PANEL_LDM_DEMO_MODE_E
{
    HI_UNF_PANEL_LDM_DEMO_OFF,              /**<LDM type is off */ /**<CNcomment:Ldm关闭Demo模式 */
    HI_UNF_PANEL_LDM_DEMO_HORSELIGHT,       /**<LDM type is HORSELIGHT */ /**<CNcomment:LdmDemo模式为HORSELIGHT */
    HI_UNF_PANEL_LDM_DEMO_LEFT_HALF,        /**<LDM type is LEFT HALF */ /**<CNcomment:LdmDemo模式为LEFT HALF */
    HI_UNF_PANEL_LDM_DEMO_RIGHT_HALF,       /**<LDM type is RIGHT HALF */ /**<CNcomment:LdmDemo模式为RIGHT HALF */
    HI_UNF_PANEL_LDM_DEMO_TOP_HALF,         /**<LDM type is TOP HALF */ /**<CNcomment:LdmDemo模式为TOP HALF */
    HI_UNF_PANEL_LDM_DEMO_BOTTOM_HALF,      /**<LDM type is BOTTOM HALF */ /**<CNcomment:LdmDemo模式为BOTTOM HALF */
    
    HI_UNF_PANEL_LDM_DEMO_BUTT              /**<Invalid value*//**<CNcomment:非法边界值*/
}HI_UNF_PANEL_LDM_DEMO_MODE_E;


/*************************** API declaration ****************************/
HI_S32 HI_MPI_PANEL_Init(HI_VOID);
HI_S32 HI_MPI_PANEL_DeInit(HI_VOID);

/* 如果从文件系统读屏参则上层必须调用此接口设置屏参在文件系统中的path */
HI_S32 HI_MPI_PANEL_SetPath(HI_CHAR* pcPath);

/* 上层通过此接口选择屏参表里面相应的屏参 */
HI_S32 HI_MPI_PANEL_SetIndex(HI_U32 u32Index);

/* 上层通过调用此接口获取屏参表里面屏参的个数 */
HI_S32 HI_MPI_PANEL_GetTotalNum(HI_U32 *pu32TotalNum);

/* MW在初始化的时候要调用此接口设置当前使用的屏参信息 */
HI_S32 HI_MPI_PANEL_SetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);
HI_S32 HI_MPI_PANEL_GetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);

/* 如果BOOT已点屏MW初始化不能调用SetPowerOn此接口,只有切换屏参和关机才能调用 */
HI_S32 HI_MPI_PANEL_SetPowerOn(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetPowerOn( HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_SetBacklightEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetBacklightEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_SetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr);
HI_S32 HI_MPI_PANEL_GetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr);


HI_S32 HI_MPI_PANEL_SetFixOutRate(HI_DRV_PANEL_FIXRATE_TYPE_E enFixRateType);
HI_S32 HI_MPI_PANEL_GetFixOutRate(HI_DRV_PANEL_FIXRATE_TYPE_E *penFixRateType);

HI_S32 HI_MPI_PANEL_GetPanelAttr(HI_DRV_PANEL_ATTR_S *pstPanelAttr);

HI_S32 HI_MPI_PANEL_SetDynamicBLEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetDynamicBLEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_GetDynamicDimStrengthRange(HI_DRV_PANEL_DIM_STRENGTH_RANGE_S *pstRange);
HI_S32 HI_MPI_PANEL_SetDynamicDimStrengthLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetDynamicDimStrengthLevel(HI_U32 *pu32Level);

HI_S32 HI_MPI_PANEL_SetBacklightLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetBacklightLevel(HI_U32 *pu32Level);
HI_S32 HI_MPI_PANEL_SetLocalDimmingEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetLocalDimmingEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_GetLocalDimmingStrengthRange(HI_DRV_PANEL_DIM_STRENGTH_RANGE_S *pstRange);
HI_S32 HI_MPI_PANEL_SetLocalDimmingStrengthLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetLocalDimmingStrengthLevel(HI_U32 *pu32Level);
HI_S32 HI_MPI_PANEL_SetLocalDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E enDemoMode);
HI_S32 HI_MPI_PANEL_GetLocalDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E *penDemoMode);
HI_S32 HI_MPI_PANEL_GetDivideBlData(HI_U8 *pDivideBlData);

/*==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
