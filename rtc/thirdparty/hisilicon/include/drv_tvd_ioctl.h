/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_tvd_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/28
  Description   : 
  History       :
  1.Date        : 2013/10/28
    Author      : t00202585/z00185248
    Modification: Created file
******************************************************************************/
#ifndef __DRV_TVD_IOCTL_H__
#define __DRV_TVD_IOCTL_H__

#include <linux/ioctl.h>
#include "hi_type.h"

typedef struct hiTVD_OFFLINE_PARAM_S
{
    HI_UNF_TVD_OFFLINE_S   stOffline;
    HI_BOOL                bSigExist;
} TVD_OFFLINE_PARAM_S;

typedef enum hiTVD_INKMODE_E
{
	TVD_INKMODE_OFF = 0,
	TVD_INKMODE_2D_UP_BURST,
	TVD_INKMODE_2D_DOWN_BURST,
	TVD_INKMODE_2D_3LINES_BURST,
	TVD_INKMODE_2D_HORIZONTAL_DIFF ,
	TVD_INKMODE_2D_VERTICAL_UP_DIFF,
	TVD_INKMODE_2D_VERTICAL_DOWN_DIFF,
	TVD_INKMODE_2D_HORIZONTAL_LUMA_CORING_DIFF,
	TVD_INKMODE_2D_HORIZONTAL_CHROMA_CORING_DIFF,
	TVD_INKMODE_2D_VERTICAL_CORING_DIFF,
	TVD_INKMODE_2D_EDGE,
	TVD_INKMODE_2D_VERTICAL_LUMA_BLEND_RATIO,
	TVD_INKMODE_2D_VERTICAL_CHROMA_BLEND_RATIO,
	TVD_INKMODE_2D_UP_5P_MAX_DIFF,
	TVD_INKMODE_2D_DOWN_5P_MAX_DIFF,
	TVD_INKMODE_2D_UP_INVERSE_PHASE_CVBS_5P_MAX_DIFF,
	TVD_INKMODE_2D_DOWN_INVERSE_PHASE_CVBS_5P_MAX_DIFF,
	TVD_INKMODE_2D_UP_SAME_PHASE_CVBS_5P_MAX_DIFF,
	TVD_INKMODE_2D_DOWN_SAME_PHASE_CVBS_5P_MAX_DIFF,
	TVD_INKMODE_2D_UP_INVERSE_PHASE_CVBS_5P_MIN_DIFF,
	TVD_INKMODE_2D_DOWN_INVERSE_PHASE_CVBS_5P_MIN_DIFF,
	TVD_INKMODE_2D_CVBS,
	TVD_INKMODE_2D_DELAY_1LINE_CVBS,
	TVD_INKMODE_2D_DELAY_2LINES_CVBS,
	TVD_INKMODE_2D_DELAY_3LINES_CVBS,

	TVD_INKMODE_3D_BURST,
	TVD_INKMODE_3D_EDGE,
	TVD_INKMODE_3D_LUMA_MOTION,
	TVD_INKMODE_3D_CHROMA_MOTION,
	TVD_INKMODE_3D_CVBS_MOTION,
	TVD_INKMODE_3D_TOTAL_MOTION,
	TVD_INKMODE_3D_3_5_MAX_MOTION,
	TVD_INKMODE_3D_EDGE_RESTRAIN_MOTION,
	TVD_INKMODE_3D_FRAME_MOTION,
	TVD_INKMODE_3D_WEIGHT_ALPHA,
	TVD_INKMODE_3D_DELAY_2LINES_CVBS,
	TVD_INKMODE_3D_DELAY_1LINE_CVBS,
	TVD_INKMODE_3D_DELAY_1FRAME_1LINE_CVBS,
	TVD_INKMODE_3D_DELAY_2FRAMES_1LINE_CVBS,
	TVD_INKMODE_3D_DELAY_3FRAMES_1LINE_CVBS,
	TVD_INKMODE_3D_HORIZONTAL_DIFF,

	TVD_INKMODE_BUTT
} TVD_INKMODE_E;

typedef enum hiTVD_SELECT_QTCDATA_E
{
	TVD_QTC_OFF = 0,
	TVD_QTCDATA_LUMAGAIN,
	TVD_QTCDATA_AGC_ERROR_LINEAR,
	TVD_QTCDATA_TIP_LEVEL,
	TVD_QTCDATA_BLANK_LEVEL,
	TVD_QTCDATA_CDTO_ERR,
	TVD_QTCDATA_PHASE_ERR,
	TVD_QTCDATA_DEMOD_PALNC,
	TVD_QTCDATA_DEMOD_PALM,
	TVD_QTCDATA_DEMOD_358,
	TVD_QTCDATA_DEMOD_443,

	TVD_QTCDATA_EQUATOR_CVBS_12BIT,
	TVD_QTCDATA_EQUATOR_CVBS_60BIT,

	TVD_QTCDATA_BUTT
} TVD_SELECT_QTCDATA_E;

typedef struct hiTVD_CMD_ATTR_S
{
    HI_U32   u32CmdType;
    HI_U32   u32Attr1;
    HI_U32   u32Attr2;
} TVD_CMD_ATTR_S;

#define HIIOC_TVD_CONNECT           _IOW('T', 0, HI_UNF_TVD_SRC_ATTR_S)     /* 连接TVD */
#define HIIOC_TVD_DISCONNECT        _IO('T',  1)                            /* 断开TVD */
#define HIIOC_TVD_G_STATUS          _IOR('T', 2, HI_UNF_SIG_STATUS_E)       /* 获取TVD信号状态 */
#define HIIOC_TVD_G_TIMING_INFO     _IOR('T', 3, HI_UNF_TVD_TIMING_INFO_S)  /* 获取信号格式 */
#define HIIOC_TVD_S_COLORSYS        _IOW('T', 4, HI_UNF_COLOR_SYS_E)        /* 设置TVD彩色制式 */
#define HIIOC_TVD_G_COLORSYS        _IOR('T', 5, HI_UNF_COLOR_SYS_E)        /* 获取TVD彩色制式 */
#define HIIOC_TVD_G_SIGNAL_LOCK     _IOR('T', 6, HI_BOOL)                   /* 获取信号是否锁定 */
#define HIIOC_TVD_G_NOISE_LEVEL     _IOR('T', 7, HI_U32)                    /* 获取信号噪声水平 */
#define HIIOC_TVD_G_MARCOVISION     _IOR('T', 8, HI_BOOL)                   /* 获取是否有Macrovision */
#define HIIOC_TVD_G_NSTD_INFO       _IOR('T', 9, HI_UNF_VIDEO_NONSTD_INFO_S)/* 获取非标信号信息 */
#define HIIOC_TVD_G_H_RANGE         _IOR('T', 10,HI_RANGE_S)                /* 获取水平调整范围 */
#define HIIOC_TVD_S_H_POS           _IOW('T', 11,HI_U32)                    /* 设置水平位置 */
#define HIIOC_TVD_G_H_POS           _IOR('T', 12,HI_U32)                    /* 获取水平位置 */
#define HIIOC_TVD_G_V_RANGE         _IOR('T', 13,HI_RANGE_S)                /* 获取垂直调整范围 */
#define HIIOC_TVD_S_V_POS           _IOW('T', 14,HI_U32)                    /* 设置垂直位置 */
#define HIIOC_TVD_G_V_POS           _IOR('T', 15,HI_U32)                    /* 获取垂直位置 */
#define HIIOC_TVD_S_PEDSTAL         _IOW('T', 16,HI_BOOL)                   /* 设置Pedstal是否打开 */
#define HIIOC_TVD_S_COLORFILTER     _IOW('T', 17,HI_UNF_TVD_SYS_FILTER_S)   /* 设置TVD彩色制式过滤属性 */
#define HIIOC_TVD_G_COLORFILTER     _IOR('T', 18,HI_UNF_TVD_SYS_FILTER_S)   /* 获取TVD彩色制式过滤属性 */
#define HIIOC_TVD_EN_MONITOR        _IOW('T', 19,HI_BOOL)                   /* 使能禁用Monitor */
#define HIIOC_TVD_S_COMB_MODE       _IOW('T', 20,HI_UNF_TVD_COMB_MODE_E)    /* CombFilter工作模式 */
#define HIIOC_TVD_G_625_MODE        _IOR('T', 21,HI_BOOL)                   /* 获取当前信号是否是625行 */
#define HIIOC_TVD_G_OFFLINE_STATUS  _IOWR('T',22,TVD_OFFLINE_PARAM_S)       /* 获取离线检测信号状态 */
#define HIIOC_TVD_S_WORK_MODE       _IOW('T', 23, HI_UNF_TVD_WORK_MODE_E)   /* 设置TVD工作模式 */
#define HIIOC_TVD_S_INK_MODE        _IOW('T', 24, TVD_INKMODE_E)            /* 设置TVD Ink模式 */
#define HIIOC_TVD_G_INK_MODE        _IOR('T', 25, TVD_INKMODE_E)            /* 获取TVD Ink模式 */
#define HIIOC_TVD_EN_QTC        	_IOW('T', 26, TVD_SELECT_QTCDATA_E)     /* 设置QTC */
#define HIIOC_TVD_G_QTC_STATE       _IOR('T', 27, HI_BOOL)       			/* 获取QTC状态 */
#define HIIOC_TVD_G_QTC_BUF_ADDR    _IOR('T', 28, HI_U32)       			/* 获取QTC Buffer 地址 */
#define HIIOC_TVD_HANDLE_CMD        _IOWR('T', 29, TVD_CMD_ATTR_S)  	    /* 设置TVD状态的函数接口 */

#endif
