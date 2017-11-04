/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_hddec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/08
  Description   : 
  History       :
  1.Date        : 2013/10/08
    Author      : c00186004/x00185802
    Modification: Created file
******************************************************************************/

#ifndef __HI_UNF_HDDEC_H__
#define __HI_UNF_HDDEC_H__

/* add include here */
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/********************************Macro Definition********************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/**VGA source EDID data size */
/**CNcomment:VGA信号源EDID数据长度　*/
#define HI_UNF_HDDEC_EDID_SIZE     128

/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/**HDDEC source type*/
/**CNcomment:HDDEC 信号源类型 */
typedef enum hiUNF_HDDEC_SRC_TYPE_E 
{
	HI_UNF_HDDEC_SRC_VGA = 0,   /**<VGA source *//**<CNcomment: VGA信号源*/
	HI_UNF_HDDEC_SRC_YPBPR,     /**<YPbPr source *//**<CNcomment: YPbPr信号源*/
	
	HI_UNF_HDDEC_SRC_BUTT       /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_HDDEC_SRC_TYPE_E;

/**HDDEC parameters adjust type*/
/**CNcomment:HDDEC参数手动调整类型 */
typedef enum hiUNF_HDDEC_ADJUST_TYPE_E 
{
	HI_UNF_HDDEC_ADJUST_HPOS = 0,  /**<H Position adjust *//**<CNcomment: 水平位置调整*/
	HI_UNF_HDDEC_ADJUST_VPOS,      /**<V Position adjust *//**<CNcomment: 垂直位置调整*/
	HI_UNF_HDDEC_ADJUST_PHASE,     /**<Phase adjust *//**<CNcomment: 相位调整*/
	HI_UNF_HDDEC_ADJUST_CLOCK,     /**<Clock adjust *//**<CNcomment: 时钟调整*/
	
	HI_UNF_HDDEC_ADJUST_TYPE_BUTT  /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_HDDEC_ADJUST_TYPE_E;

/**Adjust state for color calibration and VGA auto adjust*/
/**CNcomment:自动颜色校正的状态/VGA图像自动调整的状态  */
typedef enum hiUNF_HDDEC_ADJUST_STATE_E 
{
	HI_UNF_HDDEC_ADJUST_BEGIN = 0,   /**<Adjust begin *//**<CNcomment: 调整开始*/
	HI_UNF_HDDEC_ADJUST_FINISH,      /**<Adjust finished *//**<CNcomment: 调整完成*/
	HI_UNF_HDDEC_ADJUST_TIMEOUT,     /**<Adjust timeout *//**<CNcomment: 调整超时*/
	HI_UNF_HDDEC_ADJUST_FAIL,        /**<Adjust failed *//**<CNcomment: 调整失败*/
	
	HI_UNF_HDDEC_ADJUST_STATE_BUTT   /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_HDDEC_ADJUST_STATE_E;

/**VGA auto adjust information */
/**CNcomment:VGA图像自动调整的信息 */
typedef struct hiUNF_HDDEC_ADJUST_INFO_S
{
	HI_UNF_HDDEC_ADJUST_STATE_E enAdjustState; /**<Adjust state *//**<CNcomment: 自动调整状态*/
	HI_U32 u32Clock;                           /**<Adjust clock information*//**<CNcomment: 时钟调整信息*/
	HI_U32 u32Phase;                           /**<Adjust phase information*//**<CNcomment: 相位调整信息*/
	HI_U32 u32HPosition;                       /**<Adjust H position information*//**<CNcomment: H位置调整信息*/
	HI_U32 u32VPosition;                       /**<Adjust V position information*//**<CNcomment: V位置调整信息*/
} HI_UNF_HDDEC_ADJUST_INFO_S;

/**Signal timing information */
/**CNcomment:信号时序信息 */
typedef struct hiUNF_HDDEC_TIMING_INFO_S
{
    HI_U32  u32TimingIndex;                /**<Timing ID in the timing table *//**<CNcomment: Timing序号 */
    HI_BOOL bInterlace;                    /**<interlace or progressive *//**<CNcomment: 逐隔行信息 */
    HI_U32  u32Width;                      /**<Standard width *//**<CNcomment: 标准信号一帧的宽度 */
    HI_U32  u32Height;                     /**<Standard height *//**<CNcomment: 标准信号一帧的高度，即隔行信号是两场的高度，逐行信号是一帧的高度 */
    HI_U32  u32FrameRate;                  /**<Standard frame rate *//**<CNcomment: 标准的场频，如果是隔行信号则为场频，如果是逐行信号则为帧率 */
    HI_UNF_VIDEO_FORMAT_E    enPixFmt;     /**<Pixel format *//**<CNcomment: 输入像素格式 RGB444,YUV444/422 */ 
    HI_UNF_COLOR_SPACE_E     enColorSpace; /**<Color space *//**<CNcomment: 彩色空间 */
    HI_UNF_OVERSAMPLE_MODE_E enOversample; /**<Oversample information *//**<CNcomment: 过采样信息 */
    HI_UNF_PIXEL_BITWIDTH_E  enBitWidth;   /**<Bit width information *//**<CNcomment: 位宽信息 */
} HI_UNF_HDDEC_TIMING_INFO_S;

/**Source input pin select */
/**CNcomment:信号输入选择 */
typedef struct hiUNF_HDDEC_SRC_ATTR_S
{
    HI_UNF_HDDEC_SRC_TYPE_E    enSrcType;   /**<Source type *//**<CNcomment: 输入信号源 */
    HI_UNF_INPUT_MUX_E         enRMux;      /**<R/Pr input Pin select *//**<CNcomment: R/Pr信号pin脚号 */
    HI_UNF_INPUT_MUX_E         enGMux;      /**<G/Y input Pin select *//**<CNcomment: G/Y信号pin脚号 */
    HI_UNF_INPUT_MUX_E         enBMux;      /**<B/Pb input Pin select *//**<CNcomment: B/Pb信号pin脚号 */
    HI_UNF_INPUT_MUX_SOG_E     enSogMux;    /**<SOG/SOY input Pin select *//**<CNcomment: SOG/SOY信号pin脚号 */
    HI_UNF_INPUT_MUX_SYNC_E    enSyncMux;   /**<HV Sync input Pin select *//**<CNcomment: VGA分离同步信号pin脚号 */
} HI_UNF_HDDEC_SRC_ATTR_S;

/**Offline input pin select */
/**CNcomment:离线检测输入选择 */
typedef struct hiUNF_HDDEC_OFFLINE_S
{
    HI_UNF_HDDEC_SRC_TYPE_E    enSrcType;     /**<Source type *//**<CNcomment: 输入信号源 */
    HI_UNF_INPUT_MUX_OFFLINE_E enOfflineMux;  /**<Offline input Pin select *//**<CNcomment: 离线信源检测pin脚号 */
    HI_UNF_INPUT_MUX_SYNC_E    enSyncMux;     /**<VGA HV Sync Pin select *//**<CNcomment: VGA分离同步信号pin脚号 */
} HI_UNF_HDDEC_OFFLINE_S;

/**VGA EDID data definition */
/**CNcomment:VGA EDID的大小定义为128Byte*/
typedef struct hiUNF_HDDEC_EDID_S
{
    HI_U8 u8Edid[HI_UNF_HDDEC_EDID_SIZE];   /**VGA EDID data *//**<CNcomment: VGA EDID数据 */
} HI_UNF_HDDEC_EDID_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/** 
\brief the whole initialization of the HDDEC device. CNcomment:HDDEC接口驱动软件初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_Init(HI_VOID);

/** 
\brief deinit the HDDEC device. CNcomment:HDDEC接口去初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_DeInit(HI_VOID);

/** 
\Connect the HDDEC device if source switch to YPbPr or VGA. CNcomment:切换HDDEC信号源（YPbPr或VGA）时连接HDDEC设备 CNend
\attention \n
\param[in] pstSrcAttr Connected source attribute.CNcomment:连接的信号源属性 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_Connect(HI_UNF_HDDEC_SRC_ATTR_S *pstSrcAttr);

/** 
\Disconnect the HDDEC device if  source switch to other source. CNcomment:切换到其他信号源时断开连接HDDEC设备 CNend
\attention \n
\param CNcomment:无 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_DisConnect(HI_VOID);

/* 获取离线信源的信号是否存在，阻塞接口 */

/** 
\Check the signal is  exist or not with the non-current source. CNcomment:获取离线信源的信号是否存在,阻塞返回 CNend
\attention \n
\param[in] pstOffline source offline information. CNcomment:离线检测信号源信息 CNend
\param[out] pbExistSig signal exist information.CNcomment:信号是否存在信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetOfflineSigStatus(HI_UNF_HDDEC_OFFLINE_S *pstOffline, HI_BOOL *pbExistSig);

/** 
\Get the signal status like no signal/unstable/support. CNcomment:读取信号状态（无信号/不稳定/信号稳定） CNend
\attention \n
\param[out] penSigStatus signal status.CNcomment:获取的信号状态 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetSigStatus(HI_UNF_SIG_STATUS_E *penSigStatus);

/** 
\Get the standard timing information of current signal. CNcomment:读取信号标准时序信息 CNend
\attention \n
\param[out] pstTimingInfo signal timing information.CNcomment:获取的信号时序信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetTimingInfo(HI_UNF_HDDEC_TIMING_INFO_S *pstTimingInfo);

/** 
\To check the nonstand signal information. CNcomment:读取非标信息 CNend
\attention \n
\param[out] pstNonStdInfo nonstand signal information.CNcomment:非标信号信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetNonStdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNonStdInfo);

/** 
\To start color calibration CNcomment:启动自动颜色校正 CNend
\attention \n
\param CNcomment:无 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_StartCalib(HI_VOID);

/** 
\Get Color calibration information CNcomment:获取自动颜色校正信息  CNend
\attention \n
\param[out] pstCalibInfo Color calibration information.CNcomment:自动颜色校正信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetCalibInfo(HI_UNF_COLOR_CALIB_INFO_S *pstCalibInfo);

/** 
\Get Color calibration data CNcomment:获取自动颜色校正数据  CNend
\attention \n
\param[out] pstCalibParam Color calibration data.CNcomment:自动颜色校正数据 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/** 
\Set Color calibration data CNcomment:手动设置自动颜色校正  CNend
\attention \n
\param[in] pstCalibParam Color calibration data.CNcomment:设置的颜色校正数据 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_SetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/** 
\To start VGA source auto adjust CNcomment:启动VGA图像自动调整CNend
\attention \n
\param CNcomment:无 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_StartAutoAdjust(HI_VOID);

/** 
\Get VGA auto adjust information CNcomment:获取VGA图像自动调整  CNend
\attention \n
\param[out] pstAdjustInfo VGA auto adjust information.CNcomment:VGA图像自动调整信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustInfo(HI_UNF_HDDEC_ADJUST_INFO_S *pstAdjustInfo);

/** 
\Get adjust type range CNcomment:获取手动调整可调范围  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:调整类型 CNend
\param[out] pstRange adjust type range.CNcomment:手动调整可调范围 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustRange(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_RANGE_S *pstRange);

/** 
\Get adjust type data CNcomment:获取调整参数数值  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:调整类型 CNend
\param[out] pu32Param adjust type data.CNcomment:调整参数数值 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 *pu32Param);

/** 
\Set adjust type data CNcomment:设置调整参数数值  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:调整类型 CNend
\param[in]  u32Param adjust type data.CNcomment:调整参数数值 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_SetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 u32Param);   

/** 
\Update the EDID data CNcomment:更新EDID数据  CNend
\attention \n
\param[out] pstEdid EDID data.CNcomment:EDID数据 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_HDDEC_UpdateEdid(const HI_UNF_HDDEC_EDID_S *pstEdid);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_UNF_HDDEC_H__ */
