/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_hddec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/08/15
  Description   : 
  History       :
  1.Date        : 2012/08/15
    Author      : c00186004/t00202585
    Modification: Created file
******************************************************************************/

#ifndef __HI_DRV_HDDEC_H__
#define __HI_DRV_HDDEC_H__

#include <linux/ioctl.h>
#include "hi_unf_hddec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define HI_FATAL_HDDEC(fmt...) HI_FATAL_PRINT(HI_ID_HDDEC, fmt)
#define HI_ERR_HDDEC(fmt...)   HI_ERR_PRINT(HI_ID_HDDEC, fmt)
#define HI_WARN_HDDEC(fmt...)  HI_WARN_PRINT(HI_ID_HDDEC, fmt)
#define HI_INFO_HDDEC(fmt...)  HI_INFO_PRINT(HI_ID_HDDEC, fmt)
#define HI_DEBUG_HDDEC(fmt...) HI_DBG_PRINT(HI_ID_HDDEC, fmt)

typedef struct hiHDDEC_ADJUST_RANGE_S
{
    HI_UNF_HDDEC_ADJUST_TYPE_E enType;
    HI_RANGE_S                 stRangeInfo;
} HDDEC_ADJUST_RANGE_S;

typedef struct hiHDDEC_ADJUST_PARAM_S
{
    HI_UNF_HDDEC_ADJUST_TYPE_E enType;
    HI_U32                     u32Param;
} HDDEC_ADJUST_PARAM_S;

typedef struct hiHDDEC_OFFLINE_PARAM_S
{
    HI_UNF_HDDEC_OFFLINE_S stOffline;
    HI_BOOL                bExistSig;
} HDDEC_OFFLINE_PARAM_S;

/*
 * I O C T L   C O D E S   F O R   H D D E C   D E V I C E S
 */
 
/* 初始化 */
#define HIIOC_HDDEC_CONNECT           _IOW(HI_ID_HDDEC, 0, HI_UNF_HDDEC_SRC_ATTR_S)

/* 去初始化 */
#define HIIOC_HDDEC_DISCONNECT        _IO(HI_ID_HDDEC, 1)

/* 检测当前的decode状态 */
#define HIIOC_HDDEC_G_SIGNAL_STATUS   _IOR(HI_ID_HDDEC, 2, HI_UNF_SIG_STATUS_E)

/* 检测当前的decodeTiming信息 */
#define HIIOC_HDDEC_G_TIMING_INFO     _IOR(HI_ID_HDDEC, 3, HI_UNF_HDDEC_TIMING_INFO_S)

/* 检测当前的decode非标信息 */
#define HIIOC_HDDEC_G_NONSTD_INFO     _IOR(HI_ID_HDDEC, 4, HI_UNF_VIDEO_NONSTD_INFO_S)

/* 启动自动颜色校正 */
#define HIIOC_HDDEC_START_CALIB       _IO(HI_ID_HDDEC, 5)

/* 获取自动颜色校正状态 */
#define HIIOC_HDDEC_G_CALIB_INFO      _IOR(HI_ID_HDDEC, 6, HI_UNF_COLOR_CALIB_INFO_S)

/* 获取自动颜色校正结果 */
#define HIIOC_HDDEC_G_CALIB_PARAM     _IOR(HI_ID_HDDEC, 7, HI_UNF_COLOR_CALIB_PARAM_S)

/* 手动设置自动颜色校正 */
#define HIIOC_HDDEC_S_CALIB_PARAM     _IOW(HI_ID_HDDEC, 8, HI_UNF_COLOR_CALIB_PARAM_S)

/* 启动VGA图像自动调整 */
#define HIIOC_HDDEC_START_ADJUST      _IO(HI_ID_HDDEC, 9)

/* 获取VGA图像自动调整状态 */
#define HIIOC_HDDEC_G_ADJUST_INFO     _IOR(HI_ID_HDDEC, 10, HI_UNF_HDDEC_ADJUST_INFO_S)

/* 获取水平/垂直/相位/时钟可调范围 */
#define HIIOC_HDDEC_G_ADJUST_RANGE    _IOWR(HI_ID_HDDEC, 11, HDDEC_ADJUST_RANGE_S)

/* 获取当前图像水平/垂直/相位/时钟 */
#define HIIOC_HDDEC_G_ADJUST_PARAM    _IOWR(HI_ID_HDDEC, 12, HDDEC_ADJUST_PARAM_S)   

/* 手动调节当前图像水平/垂直/相位/时钟 */
#define HIIOC_HDDEC_S_ADJUST_PARAM    _IOW(HI_ID_HDDEC, 13, HDDEC_ADJUST_PARAM_S) 

/* 更新Edid */
#define HIIOC_HDDEC_U_EDID            _IOW(HI_ID_HDDEC, 14, HI_UNF_HDDEC_EDID_S)

/* 获取Offline离线信号状态 */
#define HIIOC_HDDEC_G_OFFLINE_SIG     _IOWR(HI_ID_HDDEC, 15, HDDEC_OFFLINE_PARAM_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif/* __HI_DRV_HDDEC_H__ */