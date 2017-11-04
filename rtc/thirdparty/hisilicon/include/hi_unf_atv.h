/******************************************************************************

  Copyright (C), 2001-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_atv.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/6
  Description   :
  History       :
  1.Date        : 2013/10/6
    Author      : ATV
    Modification: Created file

*******************************************************************************/
#ifndef __HI_UNF_ATV_H__
#define __HI_UNF_ATV_H__

/* add include here */
#include "hi_type.h"
#include "hi_common.h"
#include "hi_unf_common.h"
#include "hi_unf_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      ATV */
/** @{ */  /** <!-- [ATV] */

/**Defines input source type enum*/
/**CNcomment:定义输入源类别枚举*/
typedef enum hiUNF_INPUT_SOURCE_TYPE_E
{
    HI_UNF_INPUT_SOURCE_DTV = 0,    
    HI_UNF_INPUT_SOURCE_USB,
        
    HI_UNF_INPUT_SOURCE_ATV,
    HI_UNF_INPUT_SOURCE_SCART,
    HI_UNF_INPUT_SOURCE_SVIDEO,
    HI_UNF_INPUT_SOURCE_CVBS,
    HI_UNF_INPUT_SOURCE_VGA,
    HI_UNF_INPUT_SOURCE_YPBPR,
    HI_UNF_INPUT_SOURCE_HDMI,
 
    HI_UNF_INPUT_SOURCE_BUTT
} HI_UNF_INPUT_SOURCE_TYPE_E;

/**Defines NonStandard image infomation num*/
/**CNcomment: 定义非标信号信息枚举*/
typedef struct hiUNF_VIDEO_NONSTD_INFO_S
{
    HI_BOOL bNonStd;            /**<NonStd or not *//**<CNcomment: 是否非标*/                          
    HI_U32  u32Height;          /**<height of NonStd *//**<CNcomment: 非标图像高度*/   
    HI_U32  u32VFreq;           /**<field frequency,use number of fields per 1000 secend as unit,for example,61050 is 60.5Hz *//**<CNcomment: 非标输入场频 单位为每千秒场数目，例如61050表示61.05Hz*/ 
} HI_UNF_VIDEO_NONSTD_INFO_S;

/**Defines TV format enum*/
/**CNcomment: 定义电视制式枚举*/
typedef enum hiUNF_COLOR_SYS_E
{
    HI_UNF_COLOR_SYS_AUTO = 0,
    HI_UNF_COLOR_SYS_PAL,
    HI_UNF_COLOR_SYS_NTSC,
    HI_UNF_COLOR_SYS_SECAM,
    HI_UNF_COLOR_SYS_PAL_M,
    HI_UNF_COLOR_SYS_PAL_N,
    HI_UNF_COLOR_SYS_PAL_60,
    HI_UNF_COLOR_SYS_NTSC443,
    HI_UNF_COLOR_SYS_NTSC_50,
    
    HI_UNF_COLOR_SYS_BUTT
} HI_UNF_COLOR_SYS_E;

/**Defines source type enum*/
/**CNcomment: 定义输入源枚举*/
typedef enum hiUNF_SOURCE_TYPE_E
{
    HI_UNF_SOURCE_TVD = 0,
    HI_UNF_SOURCE_HDDEC,
    HI_UNF_SOURCE_HDMI,
    HI_UNF_SOURCE_EXTERN,           /**<extern interface*//**<CNcomment: 外部接口*/
    
    HI_UNF_SOURCE_TYPE_BUTT
} HI_UNF_SOURCE_TYPE_E;

/**Defines the state of the color calibration.*/
/**CNcomment: 定义色彩校正的状态 */
typedef enum hiUNF_COLOR_CALIB_STATE_E 
{
	HI_UNF_COLOR_CALIB_BEGIN = 0, /**<Color calibration begin*//**<CNcomment:颜色校正开始 */
	HI_UNF_COLOR_CALIB_FINISH,    /**<Color calibration finished*//**<CNcomment:颜色校正完成 */
	HI_UNF_COLOR_CALIB_TIMEOUT,   /**<Color calibration timeout*//**<CNcomment:颜色校正超时出错*/
	HI_UNF_COLOR_CALIB_FAIL,	    /**<Color calibration failed*//**<CNcomment:颜色校正失败 */
	HI_UNF_COLOR_CALIB_BUTT       /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_COLOR_CALIB_STATE_E;

/**Defines the result data of the color calibration.*/
/**CNcomment: 定义颜色校正的结果数据 */
typedef struct hiUNF_COLOR_CALIB_PARAM_S 
{
    HI_U32 u32RGain;           /**<R Gain*/ /**<CNcomment:R通道增益*/
    HI_U32 u32GGain;           /**<G Gain*/ /**<CNcomment:G通道增益*/
    HI_U32 u32BGain;           /**<B Gain*/ /**<CNcomment:B通道增益*/
    HI_U32 u32ROffset;         /**<R Offset*/ /**<CNcomment:R通道偏移*/
    HI_U32 u32GOffset;         /**<G Offset*/ /**<CNcomment:G通道偏移*/
    HI_U32 u32BOffset;         /**<B Offset*/ /**<CNcomment:B通道偏移*/
} HI_UNF_COLOR_CALIB_PARAM_S;

/**Defines the info of the color calibration.*/
/**CNcomment: 定义颜色校正的信息 */
typedef struct hiUNF_COLOR_CALIB_INFO_S 
{
    HI_UNF_COLOR_CALIB_STATE_E   enCalibState;   /**<Color calibration state */ /**<CNcomment:颜色校正状态信息 */
    HI_UNF_COLOR_CALIB_PARAM_S   stCalibParam;   /**<Color calibration parmeters */ /**<CNcomment:颜色校正参数 */
} HI_UNF_COLOR_CALIB_INFO_S;

/**Input signal Pin definition.*/
/**CNcomment: 信号输入引脚定义 */
typedef enum hiUNF_INPUT_MUX_E
{
    HI_UNF_INPUT_MUX_CVBS0 = 0, /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF复用选择脚*/
    HI_UNF_INPUT_MUX_CVBS1,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF复用选择脚*/
    HI_UNF_INPUT_MUX_CVBS2,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF复用选择脚*/
    HI_UNF_INPUT_MUX_CVBS3,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF复用选择脚*/

    HI_UNF_INPUT_MUX_R,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_PR0,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_PR1,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    
    HI_UNF_INPUT_MUX_G,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_Y0,        /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_Y1,        /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/

    HI_UNF_INPUT_MUX_B,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_PB0,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/
    HI_UNF_INPUT_MUX_PB1,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B复用选择脚*/

    HI_UNF_INPUT_MUX_BUTT,      /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_INPUT_MUX_E;

/**SOG Pin definition.*/
/**CNcomment: SOG信号输入引脚定义 */
typedef enum hiUNF_INPUT_MUX_SOG_E 
{
    HI_UNF_INPUT_MUX_SOG = 0,    /**<SOG Pin */  /**<CNcomment:SOG引脚 */
    HI_UNF_INPUT_MUX_SOY0,       /**<SOY0 Pin */ /**<CNcomment:SOY0引脚 */
    HI_UNF_INPUT_MUX_SOY1,       /**<SOY1 Pin */ /**<CNcomment:SOY1引脚 */

    HI_UNF_INPUT_MUX_SOG_BUTT,   /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_INPUT_MUX_SOG_E;

/**HV separate SYNC Pin definition.*/
/**CNcomment: HV分离同步输入引脚选择 */
typedef enum hiUNF_INPUT_MUX_SYNC_E 
{
    HI_UNF_INPUT_MUX_SYNC_HVS0 = 0,  /**<HVS0 Pin */  /**<CNcomment:HVS0引脚 */
    HI_UNF_INPUT_MUX_SYNC_HVS1,      /**<HVS1 Pin */  /**<CNcomment:HVS1引脚 */
 
    HI_UNF_INPUT_MUX_SYNC_BUTT,      /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_INPUT_MUX_SYNC_E;

/**Offline Pin definition*/
/**CNcomment: HV分离同步输入引脚选择 */
typedef enum hiUNF_INPUT_MUX_OFFLINE_E 
{
    HI_UNF_INPUT_MUX_OFFLINE_SOG = 0,     /**<Offline SOG Pin */  /**<CNcomment:离线检测SOG脚*/
    HI_UNF_INPUT_MUX_OFFLINE_SOY0,        /**<Offline SOY0 Pin */  /**<CNcomment:离线检测SOY0脚*/
    HI_UNF_INPUT_MUX_OFFLINE_SOY1,        /**<Offline SOY1 Pin */  /**<CNcomment:离线检测SOY1脚*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS0,       /**<Offline CVBS0 Pin */  /**<CNcomment:离线检测CVBS0脚*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS1,       /**<Offline CVBS1 Pin */  /**<CNcomment:离线检测CVBS1脚*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS2,       /**<Offline CVBS2 Pin */  /**<CNcomment:离线检测CVBS2脚*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS3,       /**<Offline CVBS3 Pin */  /**<CNcomment:离线检测CVBS3脚*/ 
    //HI_UNF_INPUT_MUX_OFFLINE_SCART_0,   /**<Offline SCART0 Pin */  /**<CNcomment:离线检测SCART0脚*/
    //HI_UNF_INPUT_MUX_OFFLINE_SCART_1,   /**<Offline SCART1 Pin */  /**<CNcomment:离线检测SCART1脚*/

    HI_UNF_INPUT_MUX_OFFLINE_BUTT,        /**<Invalid value*/ /**<CNcomment:非法边界值*/
} HI_UNF_INPUT_MUX_OFFLINE_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ATV_ H*/


