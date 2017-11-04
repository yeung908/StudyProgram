/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_hddec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/08
  Description   : 
  History       :
  1.Date        : 2013/10/08
    Author      : c00186004
    Modification: Created file
******************************************************************************/

#ifndef __HI_MPI_HDDEC_H__
#define __HI_MPI_HDDEC_H__

#include "hi_unf_hddec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* HDDEC初始化 */
HI_S32 HI_MPI_HDDEC_Init(HI_VOID);

/* HDDEC去初始化 */
HI_S32 HI_MPI_HDDEC_DeInit(HI_VOID);

/* 更新edid */
HI_S32 HI_MPI_HDDEC_UpdateEdid(const HI_UNF_HDDEC_EDID_S *pstEdid);

/* 信源连接 */
HI_S32 HI_MPI_HDDEC_Connect(HI_UNF_HDDEC_SRC_ATTR_S *pstSrcAttr);

/* 断开连接 */
HI_S32 HI_MPI_HDDEC_DisConnect(HI_VOID);

/* 获取离线信源的信号是否存在，阻塞接口 */
HI_S32 HI_MPI_HDDEC_GetOfflineSigStatus(HI_UNF_HDDEC_OFFLINE_S *pstOffline, HI_BOOL *pbExistSig);

/* 检测当前的decode状态 */
HI_S32 HI_MPI_HDDEC_GetSigStatus(HI_UNF_SIG_STATUS_E *penSigStatus);

/* 检测当前的decodeTiming信息 */
HI_S32 HI_MPI_HDDEC_GetTimingInfo(HI_UNF_HDDEC_TIMING_INFO_S *pstTimingInfo);

/* 检测当前的decode非标信息 */
HI_S32 HI_MPI_HDDEC_GetNonStdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNonStdInfo);

/* 启动自动颜色校正 */
HI_S32 HI_MPI_HDDEC_StartCalib(HI_VOID);

/* 获取自动颜色校正状态 */
HI_S32 HI_MPI_HDDEC_GetCalibInfo(HI_UNF_COLOR_CALIB_INFO_S *pstCalibInfo);

/* 获取手动设置自动颜色校正参数 */
HI_S32 HI_MPI_HDDEC_GetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/* 手动设置自动颜色校正 */
HI_S32 HI_MPI_HDDEC_SetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/* 启动VGA图像自动调整 */
HI_S32 HI_MPI_HDDEC_StartAutoAdjust(HI_VOID);

/* 获取VGA图像自动调整状态 */
HI_S32 HI_MPI_HDDEC_GetAdjustInfo(HI_UNF_HDDEC_ADJUST_INFO_S *pstAdjustInfo);

/* 获取手动调整可调范围 */
HI_S32 HI_MPI_HDDEC_GetAdjustRange(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_RANGE_S *pstRange);

/* 获取调整的参数 */
HI_S32 HI_MPI_HDDEC_GetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 *pu32Param);

/* 设置手动调整参数*/
HI_S32 HI_MPI_HDDEC_SetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 u32Param);   

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_MPI_HDDEC_H__ */

