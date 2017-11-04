/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vi_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/06/15
  Description   : 
  History       :
  1.Date        : 2014/06/15
    Author      : w00184692
    Modification: Created file
******************************************************************************/

#ifndef __DRV_PDM_IOCTL_H__
#define __DRV_PDM_IOCTL_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct
{
    HI_U32 u32TotalNum;
    HI_U32 u32CurIndex;
} PDM_PANEL_INDEX_S;

typedef struct
{
    HI_U32 u32PanelIndex;
    HI_UNF_PANEL_INFO_S stPanelParam;
} PDM_PANEL_PARAM_S;

typedef struct
{
    HI_U32 u32PanelIndex;
    HI_U32 u32BlPwm;
} PDM_BL_PWM_S;

typedef struct
{
    HI_U32 u32PanelIndex;
    HI_U32 u32PwmMin;
    HI_U32 u32PwmMax;
} PDM_PANEL_BL_PWM_RANGE_S;

typedef struct
{
    HI_U32 u32PanelIndex;
    HI_CHAR acPath[100];
} PDM_CFG_PATH_S;

#define CMD_PDM_GET_PANEL_INDEX	_IOWR('P', 0, PDM_PANEL_INDEX_S)
#define CMD_PDM_SET_PANEL_INDEX	_IOWR('P', 1, HI_U32)
#define CMD_PDM_GET_PANEL_PARAM	_IOWR('P', 2, PDM_PANEL_PARAM_S)
#define CMD_PDM_GET_CFG_PATH	_IOWR('P', 3, PDM_CFG_PATH_S)
#define CMD_PDM_GET_BL_PWM	_IOWR('P', 4, PDM_BL_PWM_S)
#define CMD_PDM_SET_BL_PWM	_IOWR('P', 5, PDM_BL_PWM_S)
#define CMD_PDM_GET_BL_PWMRANGE	_IOWR('P', 6, PDM_PANEL_BL_PWM_RANGE_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif //__DRV_PDM_IOCTL_H__