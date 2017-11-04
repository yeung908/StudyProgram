/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_tvd.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/09/25
  Description   : 
  History       :
  1.Date        : 2013/09/25
    Author      : t00202585/x00185802
    Modification: Created file
******************************************************************************/
#ifndef __HI_UNF_TVD_H__
#define __HI_UNF_TVD_H__

/* add include here */
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      TVD */
/** @{ */  /** <!-- [TVD] */

/**TVD work mode *//**CNcomment:TVD工作模式  */
typedef enum hiUNF_TVD_WORK_MODE_E
{
    HI_UNF_TVD_WORK_MODE_NORMAL = 0,   /**<TVD work mode normal*/ /**<CNcomment:TVD正常工作模式 */
    HI_UNF_TVD_WORK_MODE_CHAN_SCAN,    /**<TVD RF channel scan mode*/ /**<CNcomment:TVD RF搜台模式 */
	
    HI_UNF_TVD_WORK_MODE_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_TVD_WORK_MODE_E;

/**TVD comb filter mode*//**CNcomment:TVD梳状滤波器模式  */
typedef enum hiUNF_TVD_COMB_MODE_E
{
    HI_UNF_TVD_COMB_ADAP = 0,          /**<TVD adaptive comb filter*/ /**<CNcomment:TVD自适应梳状滤波器 */
    HI_UNF_TVD_COMB_FORCE_3D,          /**<TVD 3D comb filter*/ /**<CNcomment:TVD 3D梳状滤波器 */
    HI_UNF_TVD_COMB_FORCE_2D,          /**<TVD 2D comb filter*/ /**<CNcomment:TVD 2D梳状滤波器 */
    HI_UNF_TVD_COMB_FORCE_1D,          /**<TVD 1D comb filter*/ /**<CNcomment:TVD 1D梳状滤波器 */
    HI_UNF_TVD_COMB_BUTT               /**<Invalid value*//**<CNcomment:非法边界值*/
}HI_UNF_TVD_COMB_MODE_E;

/**TVD source type*//**CNcomment:TVD信号源类型  */
typedef enum hiUNF_TVD_SRC_TYPE_E 
{
    HI_UNF_TVD_SRC_RF_INTER = 0,       /**<RF source with Internal AIF*/ /**<CNcomment:RF信号源（内置AIF） */
    HI_UNF_TVD_SRC_RF_EXTRA,           /**<RF source with extra AIF*/ /**<CNcomment:RF信号源（外置AIF） */
    HI_UNF_TVD_SRC_AV,                 /**<Compsite video source*/ /**<CNcomment:复合视频 */
    HI_UNF_TVD_SRC_SVIDEO,             /**<S-VIDEO source*/ /**<CNcomment:色差信号源 */
    HI_UNF_TVD_SRC_SCART_FULL,         /**<Full SCART source*/ /**<CNcomment:Full SCART信号源 */
    HI_UNF_TVD_SRC_SCART_HALF,         /**<Half SCART source*/ /**<CNcomment:Half SCART信号源 */
    HI_UNF_TVD_SRC_BUTT                /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_TVD_SRC_TYPE_E;

/**TVD adjust position type *//**CNcomment:TVD 调节位置类型 */
typedef enum hiUNF_TVD_POS_TYPE_E
{
    HI_UNF_TVD_POS_H = 0,              /**<TVD adjust H position*/ /**<CNcomment:调节行起始位置 */
    HI_UNF_TVD_POS_V,                  /**<TVD adjust V position*/ /**<CNcomment:调节场起始位置 */
    HI_UNF_TVD_POS_BUTT                /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_TVD_POS_TYPE_E;

/**TVD timing information*/
/**CNcomment:TVD 信号时序信息 */
typedef struct hiUNF_TVD_TIMING_INFO_S 
{
    HI_BOOL             bInterlace;    /**<Flag of progressive or interlance *//**CNcomment:逐隔行标志 */
    HI_U32              u32Width;      /**<Active width of input standard signal *//**CNcomment:信号标准有效像素宽度 */
    HI_U32              u32Height;     /**<Active height of input standard signal *//**CNcomment:信号标准有效像素高度 */
    HI_U32              u32FrameRate;  /**<Frame Rate，fields per second *//**CNcomment:场频 单位为每秒场数目，60表示60Hz */
    
    HI_UNF_OVERSAMPLE_MODE_E     enOversample;   /**<Oversample information *//**CNcomment:过采样信息 */
    HI_UNF_PIXEL_BITWIDTH_E      enBitWidth;     /**<Sample bit width *//**CNcomment:位宽信息 */
    HI_UNF_VIDEO_FORMAT_E        enPixelFmt;     /**<Pixel format *//**CNcomment:像素格式 */
} HI_UNF_TVD_TIMING_INFO_S;

/**SCART mux select*/
/**CNcomment:SCART输入信号复用选择*/
typedef struct hiUNF_TVD_SCART_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS信号pin脚号 */
    HI_UNF_INPUT_MUX_E    enRMux;    /**<R input pin select *//**CNcomment:R信号pin脚号 */
    HI_UNF_INPUT_MUX_E    enGMux;    /**<G input pin select *//**CNcomment:G信号pin脚号 */
    HI_UNF_INPUT_MUX_E    enBMux;    /**<B input pin select *//**CNcomment:B信号pin脚号 */
} HI_UNF_TVD_SCART_MUX_S;

/**S-VIDEO mux select*/
/**CNcomment:S-Video输入信号复用选择*/
typedef struct hiUNF_TVD_SVIDEO_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enSYMux;  /**<S-VIDEO Y input pin select *//**CNcomment:S-VIDEO Y信号pin脚号 */
    HI_UNF_INPUT_MUX_E    enSCMux;  /**<S-VIDEO C input pin select *//**CNcomment:S-VIDEO C信号pin脚号 */
} HI_UNF_TVD_SVIDEO_MUX_S;

/**CVBS mux select*/
/**CNcomment:CVBS输入信号复用选择*/
typedef struct hiUNF_TVD_CVBS_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS信号pin脚号 */
} HI_UNF_TVD_CVBS_MUX_S;

/**RF with extra AIF mux select*/
/**CNcomment:外置AIF RF信号复用选择*/
typedef struct hiUNF_TVD_EXT_RF_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS信号pin脚号 */
    HI_UNF_INPUT_MUX_E    enSifMux;  /**<SIF input pin select *//**CNcomment:外置AIF的SIF信号pin脚号 */
} HI_UNF_TVD_EXT_RF_MUX_S;

/**TVD source attribute */
/**CNcomment:TVD输入信号属性 */
typedef struct hiUNF_TVD_SRC_ATTR_S
{
    HI_UNF_TVD_SRC_TYPE_E  enType;             /**<TVD input source type *//**CNcomment: TVD输入信号类型 */
    union
    {
        HI_UNF_TVD_SCART_MUX_S  stScartMux;    /**<For SCART source *//**CNcomment: SCART信号选择 */
        HI_UNF_TVD_SVIDEO_MUX_S stSVideoMux;   /**<For S-VIDEO source *//**CNcomment: S-VIDEO信号选择 */
        HI_UNF_TVD_CVBS_MUX_S   stCvbsMux;     /**<For RF and CVBS source *//**CNcomment: RF和CVBS信号选择 */
        HI_UNF_TVD_EXT_RF_MUX_S stExtRfMux;    /**<For ext RF source *//**CNcomment: 外置AIF的RF信号选择 */
    } unMuxInfo;
} HI_UNF_TVD_SRC_ATTR_S;

/**TVD offline information definition*/
/**CNcomment:TVD离线检测信息定义 */
typedef struct hiUNF_TVD_OFFLINE_S
{
    HI_UNF_TVD_SRC_TYPE_E      enType;          /**<TVD input source type *//**CNcomment: TVD输入信号类型 */
    HI_UNF_INPUT_MUX_OFFLINE_E enOfflineMux;    /**<TVD input offline pin select *//**CNcomment: TVD离线检测输入pin脚选择 */
} HI_UNF_TVD_OFFLINE_S;

/**TVD color system filter definition */
/**CNcomment:TVD彩色制式过滤定义 */
typedef struct hiUNF_TVD_SYS_FILTER_S
{
    HI_BOOL         bDisPalM;           /**<Disable PAL-M in RF source *//**CNcomment: 过滤掉PAL-M彩色制式 */
    HI_BOOL         bDisPalN;           /**<Disable PAL-N in RF source *//**CNcomment: 过滤掉PAL-N彩色制式 */
    HI_BOOL         bDisSecam;          /**<Disable SECAM in RF source *//**CNcomment: 过滤掉SECAM彩色制式 */
    HI_BOOL         bDisPal60;          /**<Disable PAL-60 in RF source *//**CNcomment: 过滤掉PAL-60彩色制式 */
    HI_BOOL         bDisNtsc443;        /**<Disable NTSC443 in RF source *//**CNcomment: 过滤掉NTSC443彩色制式 */
} HI_UNF_TVD_SYS_FILTER_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      TVD */
/** @{ */  /** <!-- [TVD] */

/** 
\brief the whole initialization of the TVD device. CNcomment:TVD接口驱动软件初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_Init(HI_VOID);

/** 
\brief deinit the TVD device. CNcomment:TVD接口去初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_DeInit(HI_VOID);

/** 
\Connect the TVD device if source switch to RF or AV. CNcomment:切换TVD信号源（RF或AV）时连接TVD设备 CNend
\attention \n
\param[in] pstSrcAttr Connected source attribute.CNcomment:连接的信号源属性 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_Connect(HI_UNF_TVD_SRC_ATTR_S *pstSrcAttr);

/** 
\Disconnect the TVD device if  source switch to other source. CNcomment:切换到其他信号源时断开连接TVD设备 CNend
\attention \n
\param CNcomment:无 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_DisConnect(HI_VOID);

/** 
\Get the signal status like no signal/unstable/support. CNcomment:读取信号状态（无信号/不稳定/信号稳定） CNend
\attention \n
\param[out] penSignalStatus signal status.CNcomment:获取的信号状态 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetSigStatus(HI_UNF_SIG_STATUS_E *penSignalStatus);

/** 
\Get the standard timing information of current signal. CNcomment:读取信号标准时序信息 CNend
\attention \n
\param[out] pstTimingInfo signal timing information.CNcomment:获取的信号时序信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetStdTimingInfo(HI_UNF_TVD_TIMING_INFO_S *pstTimingInfo);

/** 
\Set the TVD color system. CNcomment:设置TVD彩色制式 CNend
\attention \n
\param[in] enColorSys color system.CNcomment:彩色制式 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetColorSys(HI_UNF_COLOR_SYS_E enColorSys);

/** 
\Get the color system of current system. CNcomment:读取彩色制式信息 CNend
\attention \n
\param[out] penColorSys color system.CNcomment:彩色制式 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetColorSys(HI_UNF_COLOR_SYS_E *penColorSys);

/** 
\To check the signal is locked or not in autosearch. CNcomment:读取信号锁定信息 CNend
\attention \n
\param[out] pbLock locked or not.CNcomment:锁定信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetSignalLock(HI_BOOL *pbLock);

/** 
\Get the Noise level of signal. CNcomment:读取噪声测量值 CNend
\attention \n
\param[out] pu32Level noise level.CNcomment:噪声测量值 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetNoiseLevel(HI_U32 *pu32Level);

/** 
\To check the signal is Macrovision copyright or not. CNcomment:读取Macrovision版权信息 CNend
\attention \n
\param[out] pbStatus Macrovision copyright information.CNcomment:Macrovision版权信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetMacrovisionStatus(HI_BOOL *pbStatus);

/** 
\To check the nonstand signal information. CNcomment:读取非标信息 CNend
\attention \n
\param[out] pstNstdInfo nonstand signal information.CNcomment:非标信号信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetNstdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);

/** 
\Get the range of H/V adjust. CNcomment:读取H/V调整范围 CNend
\attention \n
\param[in] enType  adjust type，H or V. CNcomment:调节位置类型 CNend
\param[out] pstRange adjust range.CNcomment:调节范围 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetRange(HI_UNF_TVD_POS_TYPE_E enType, HI_RANGE_S *pstRange);

/** 
\Get the current H/V position of tvd output. CNcomment:读取TVD输出的H/V位置信息 CNend
\attention \n
\param[in] enType position type. CNcomment:位置信息类型 CNend
\param[out] pu32Pos position information.CNcomment:位置信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 *pu32Pos);

/** 
\Set the H/V position of tvd output. CNcomment:设置TVD输出的H/V位置 CNend
\attention \n
\param[in] enType position type. CNcomment:位置信息类型 CNend
\param[in] u32Pos position information.CNcomment:位置信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 u32Pos);

/** 
\Check the signal is exist or not with the non-current source. CNcomment:读取TVD源离线检测状态 CNend
\attention \n
\param[in] pstOffline source offline information. CNcomment:离线检测信号源信息 CNend
\param[out] pbStatus signal exist information.CNcomment:信号是否存在信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetOfflineDetStatus(HI_UNF_TVD_OFFLINE_S *pstOffline, HI_BOOL *pbStatus);

/** 
\Enable/disable the Pedestal setting for NTSC/PAL M. CNcomment:设置NTSC/PAL M制式黑电平7.5IRE CNend
\attention \n
\param[in] bEnable HI_TRUE:enable, HI_FALSE:disable.CNcomment:HI_TRUE:使能, HI_FALSE:关闭 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetPedestal(HI_BOOL bEnable);

/** 
\Set color system filter. CNcomment:设置彩色制式过滤 CNend
\attention \n
\param[in] pstSysFilter color system filter information.CNcomment:彩色制式过滤信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);

/** 
\Get color system filter. CNcomment读取彩色制式过滤 CNend
\attention \n
\param[in] pstSysFilter color system filter information.CNcomment:彩色制式过滤信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_GetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);

/** 
\turn on/off the TVD main thread for debug usage. CNcomment关闭/打开 TVD 主线程用于调试  CNend
\attention \n
\param[in] bEnable HI_TRUE:enable, HI_FALSE:disable.CNcomment:HI_TRUE:使能, HI_FALSE:关闭 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_EnMonitor(HI_BOOL bEnable);

/** 
\Set the comb working mode like 3d/2d. CNcomment:设置梳状滤波器工作模式 CNend
\attention \n
\param[in] enMode the comb working mode.CNcomment:梳状滤波器工作模式 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetCombMode(HI_UNF_TVD_COMB_MODE_E enMode);

/** 
\Get the signal 625 lines information,For ATV Rf scan signal. CNcomment:读取信号是否是625行 CNend
\attention \n
\param[out] pbIs625 625 lines information.CNcomment:625行信息 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_Get625Mode(HI_BOOL *pbIs625);

/** 
\Set the TVD working mode. CNcomment:设置TVD工作模式 CNend
\attention \n
\param[in] enWorkMode the TVD working mode.CNcomment:TVD工作模式 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_SetWorkMode(HI_UNF_TVD_WORK_MODE_E enWorkMode);

/**
\Set the TVD/AIF Non-std Set. CNcomment:TVD/AIF 非标设置 CNend
\attention \n
\param[in] u32CmdType  Cmd type. CNcomment:命令类型
\param[in] pu32Attr1   Cmd Attr1.CNcomment:命令属性1 CNend
\param[in] pu32Attr2   Cmd Attr2.CNcomment:命令属性2 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_TVD_HandleCmd(HI_U32 u32CmdType, HI_U32 *pu32Attr1, HI_U32 *pu32Attr2);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_TVD_H__ */

