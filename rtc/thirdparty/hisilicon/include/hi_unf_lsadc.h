/******************************************************************************

  Copyright (C), 2001-2011, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
File Name     : hi_unf_lsadc.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date  : 2014-02-08
Last Modified by:
Description   : Application programming interfaces (APIs) of the LSADC
Function List :
Change History:
 ******************************************************************************/

#ifndef __HI_UNF_LSADC_H__
#define __HI_UNF_LSADC_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      LSADC */
/** @{ */  /** <!-- [LSADC] */

/**LSADC configure parameters *//**CNcomment:LSADC配置参数  */
typedef struct hiUNF_LSADC_Config_S
{
    HI_U32 u32ChannelMask;          /**<Channel Mask (bit0:channel-A, bit1:channele-B 1:enable 0:disable) *//**CNcomment: Channel Mask */
    HI_U32 u32ActiveBit;            /**<Active bit *//**CNcomment: Active bit */
    HI_U32 u32DataDelta;            /**<data delta *//**CNcomment: data delta */
    HI_U32 u32DeglitchBypass;       /**<deglitch bypass *//**CNcomment: deglitch bypass */
    HI_U32 u32LsadcReset; 		    /**<lsadc reset *//**CNcomment: lsadc reset */
    HI_U32 u32PowerDownMod; 	    /**<power down model *//**CNcomment: power down model */
    HI_U32 u32ModelSel; 		    /**<model sel *//**CNcomment: model sel */
    HI_U32 u32LsadcZero; 		    /**<lsadc zero *//**CNcomment: lsadc zero */
    HI_U32 u32GlitchSample; 	    /**<glitch sample *//**CNcomment: glitch sample */
    HI_U32 u32TimeScan; 		    /**<time scan *//**CNcomment: time scan */
}HI_UNF_LSADC_Config_S, *HI_UNF_LSADC_Config_S_PTR;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      LSADC */
/** @{ */  /** <!-- [LSADC] */

/** 
\brief the whole initialization of the LSADC device. CNcomment:LSADC软件初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_LSADC_Init(HI_VOID);

/** 
\brief the whole deinitialization of the LSADC device. CNcomment:LSADC软件去初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_LSADC_DeInit(HI_VOID);

/** 
\brief Config the LSADC device. CNcomment:配置LSADC设备 CNend
\attention  \n
\param[in] pstLSADCConfig pointer to the lsadc configuration's structure. CNcomment: LSADC配置数据结构指针 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_LSADC_SetConfig(HI_UNF_LSADC_Config_S_PTR pstLSADCConfig);

/** 
\brief Get the configuration of the LSADC device. CNcomment:获取LSADC设备的配置 CNend
\attention  \n
\param[in] pstLSADCConfig Pointer to the lsadc configuration's structure. CNcomment: LSADC配置数据结构指针 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_LSADC_GetConfig(HI_UNF_LSADC_Config_S_PTR pstLSADCConfig);

/** 
\brief Get the value of the LSADC device. CNcomment:获取LSADC设备的值 CNend
\attention  \n
\param[in] u32Channel The channel of LSADC device. CNcomment: 指定LSADC设备的通道号 CNend
\param[out] pu32Value Pointer to the value data of the appinted channel.CNcomment: 指定通道LSADC值的数据指针 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_LSADC_GetValue(HI_U32 u32Channel,HI_U32 *pu32Value);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_LSADC_H__ */



