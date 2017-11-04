/******************************************************************************

  Copyright (C), 2001-2011, HiSilicon Technologies Co., Ltd.
******************************************************************************
 File Name     : hi_unf_sif.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
******************************************************************************/
#ifndef __HI_UNF_SIF_H__
#define __HI_UNF_SIF_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/********************************Macro Definition*****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */

#define HI_UNF_SIF_STANDARD_NUM_MAX HI_UNF_SIF_STANDARD_UNKNOW

/** @} */  /** <!-- ==== Macro Definition end ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */

//============================================================
// AUDIO_ATV RELATIONAL API FUNCTION
//============================================================
///< Audio SIF Standard Type

/**Audio Standard Type of An SIF*/
/**CNcomment:音频第二伴音中频制式*/
typedef enum hiUNF_SIF_STANDARD_TYPE_E
{
    HI_UNF_SIF_STANDARD_BG = 0x00,                  /**<Audio standard BG*/ /**<CNcomment:音频伴音制式BG*/
    HI_UNF_SIF_STANDARD_BG_A2,                      /**<Audio standard BG A2*/ /**<CNcomment:音频伴音制式BG A2*/
    HI_UNF_SIF_STANDARD_BG_NICAM,                   /**<Audio standard BG NICAM*//**<CNcomment:音频伴音制式BG NICAM*/
    HI_UNF_SIF_STANDARD_I,                          /**<Audio standard I*/ /**<CNcomment:音频伴音制式I*/
    HI_UNF_SIF_STANDARD_DK,                         /**<Audio standard DK*/ /**<CNcomment:音频伴音制式DK*/
    HI_UNF_SIF_STANDARD_DK1_A2,                     /**<Audio standard DK1 A2*/ /**<CNcomment:音频伴音制式DK1 A2*/
    HI_UNF_SIF_STANDARD_DK2_A2,                     /**<Audio standard DK2 A2*/ /**<CNcomment:音频伴音制式DK2 A2*/
    HI_UNF_SIF_STANDARD_DK3_A2,                     /**<Audio standard DK3 A2*/ /**<CNcomment:音频伴音制式DK3 A2*/
    HI_UNF_SIF_STANDARD_DK_NICAM,                   /**<Audio standard DK NICAM*/ /**<CNcomment:音频伴音制式DK NICAM*/
    HI_UNF_SIF_STANDARD_L,                          /**<Audio standard L*/ /**<CNcomment:音频伴音制式L*/
    HI_UNF_SIF_STANDARD_M,                          /**<Audio standard M*/ /**<CNcomment:音频伴音制式M*/
    HI_UNF_SIF_STANDARD_M_BTSC,                     /**<Audio standard M BTSC*/ /**<CNcomment:音频伴音制式M BTSC*/
    HI_UNF_SIF_STANDARD_M_A2,                       /**<Audio standard M A2*/ /**<CNcomment:音频伴音制式M A2*/
    HI_UNF_SIF_STANDARD_M_EIA_J,                    /**<Audio standard M EIA J*/ /**<CNcomment:音频伴音制式M EIA J*/
    HI_UNF_SIF_STANDARD_NOTSTANDARD,
    HI_UNF_SIF_STANDARD_UNKNOW
} HI_UNF_SIF_STANDARD_TYPE_E;

/**Audio mode type*/
/**CNcomment:音频伴音模式*/
typedef enum hiUNF_SIF_OUTMODE_E
{
    HI_UNF_SIF_OUTMODE_MONO = 0x00,                 /**<Audio Mode MONO*/ /**<CNcomment:音频伴音模式MONO*/
    HI_UNF_SIF_OUTMODE_STEREO,                      /**<Audio Mode G Stereo*/ /**<CNcomment:音频伴音模式Stereo*/
    HI_UNF_SIF_OUTMODE_DUAL_A,                      /**<Audio Mode Dual A*/ /**<CNcomment:音频伴音模式Dual A*/
    HI_UNF_SIF_OUTMODE_DUAL_B,                      /**<Audio Mode Dual B*/ /**<CNcomment:音频伴音模式Dual B*/
    HI_UNF_SIF_OUTMODE_DUAL_AB,                     /**<Audio Mode Dual AB*/ /**<CNcomment:音频伴音模式Dual AB*/    
    HI_UNF_SIF_OUTMODE_BTSC_MONO,                   /**<Audio Mode BTSC MONO*/ /**<CNcomment:音频伴音模式BTSC MONO*/
    HI_UNF_SIF_OUTMODE_BTSC_STEREO,                 /**<Audio Mode BTSC STEREO*/ /**<CNcomment:音频伴音模式BTSC STEREO*/
    HI_UNF_SIF_OUTMODE_BTSC_SAP,                    /**<Audio Mode BTSC SAP*/ /**<CNcomment:音频伴音模式BTSC SAP*/
    HI_UNF_SIF_OUTMODE_NICAM_FORCED_MONO,           /**<Audio Mode NICAM Forced MONO*/ /**<CNcomment:音频伴音模式Forced Mono*/
    HI_UNF_SIF_OUTMODE_NICAM_MONO,                  /**<Audio Mode NICAM MONO*/ /**<CNcomment:音频伴音模式NICAM MONO*/
    HI_UNF_SIF_OUTMODE_NICAM_STEREO,                /**<Audio Mode NICAM Stereo*/ /**<CNcomment:音频伴音模式NICAM Stereo*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_A,                /**<Audio Mode NICAM DUAL A*/ /**<CNcomment:音频伴音模式NICAM DUAL A*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_B,                /**<Audio Mode NICAM DUAL B*/ /**<CNcomment:音频伴音模式NICAM DUAL B*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_AB,               /**<Audio Mode NICAM DUAL AB*/ /**<CNcomment:音频伴音模式NICAM DUAL AB*/
    HI_UNF_SIF_OUTMODE_BUTT
} HI_UNF_SIF_OUTMODE_E;

/**Audio Carrier Status of An Sif*/
/**CNcomment:音频载波状态*/
typedef enum hiUNF_SIF_AAOS_MODE_E 
{
    HI_UNF_SIF_AAOS_MODE_MONO = 0,                 /**<Audio AAOS Status MONO*/ /**<CNcomment:音频载波状态MONO*/
    HI_UNF_SIF_AAOS_MODE_STEREO,                   /**<Audio AAOS Status STEREO*/ /**<CNcomment:音频载波状态STEREO*/
    HI_UNF_SIF_AAOS_MODE_DUAL,                     /**<Audio AAOS Status DUAL*/ /**<CNcomment:音频载波状态DUAL*/
    HI_UNF_SIF_AAOS_MODE_MONO_SAP,                 /**<Audio AAOS Status MONO_SAP*/ /**<CNcomment:音频载波状态MONO_SAP*/
    HI_UNF_SIF_AAOS_MODE_STEREO_SAP,               /**<Audio AAOS Status STEREO_SAP*/ /**<CNcomment:音频载波状态STEREO_SAP*/
    HI_UNF_SIF_AAOS_MODE_NICAM_MONO,               /**<Audio AAOS Status NICAM_MONO*/ /**<CNcomment:音频载波状态NICAM_MONO*/
    HI_UNF_SIF_AAOS_MODE_NICAM_STEREO,             /**<Audio AAOS Status NICAM_STEREO*/ /**<CNcomment:音频载波状态NICAM_STEREO*/
    HI_UNF_SIF_AAOS_MODE_NICAM_DUAL,               /**<Audio AAOS Status NICAM_DUAL*/ /**<CNcomment:音频载波状态NICAM_DUAL*/
    HI_UNF_SIF_AAOS_MODE_NICAM_FM_MOMO,            /**<Audio AAOS Status NICAM_FM_MOMO*/ /**<CNcomment:音频载波状态NICAM_FM_MOMO*/
    HI_UNF_SIF_AAOS_MODE_BUTT
} HI_UNF_SIF_AAOS_MODE_E;

/**Atuo Standard Detect Ctl of an SIF*/
/**CNcomment:自动制式检测控制参数*/
typedef enum hiUNF_SIF_SYSCTL_E
{
    HI_UNF_SIF_SYSCTL_BTSC = 0,                     /**<Audio Detect Ctl BTSC*/ /**<CNcomment:音频制式检测控制BTSC,America M*/
    HI_UNF_SIF_SYSCTL_EIAJ,                         /**<Audio Detect Ctl EIA J*/ /**<CNcomment:音频制式检测控制EIAJ,Japan M*/
    HI_UNF_SIF_SYSCTL_M_KOREA,                      /**<Audio Detect Ctl Korea*/ /**<CNcomment:音频制式检测控制FM Korea,Korea M*/
    HI_UNF_SIF_SYSCTL_PAL_SUM,                      /**<Audio Detect Ctl PAL*/ /**<CNcomment:音频制式检测控制PAL*/
    HI_UNF_SIF_SYSCTL_SECAM_L,                      /**<Audio Detect Ctl L/L'*/ /**<CNcomment:音频制式检测控制L/L'*/
    HI_UNF_SIF_SYSCTL_FM_US,                        /**<Audio Detect Ctl FM-Stereo Radio US*/ /**<CNcomment:音频制式检测控制FM-Stereo Radio US*/
    HI_UNF_SIF_SYSCTL_FM_EUROPE,                    /**<Audio Detect Ctl FM-Stereo Radio Europe*/ /**<CNcomment:音频制式检测控制FM-Stereo Radio Europe'*/
    HI_UNF_SIF_SYSCTL_BUTT
} HI_UNF_SIF_SYSCTL_E;

/**AIF decoder mode*/
/**CNcomment:AIF模式*/
typedef enum hiUNF_SIF_AIF_MODE_E
{
    HI_UNF_SIF_AIF_MODE_INTERNEL = 0,               /**<AIF decoder mode internel*/ /**<CNcomment:AIF decoder模式 内置*/
    HI_UNF_SIF_AIF_MODE_EXTERN,                     /**<AIF decoder mode external*/ /**<CNcomment:AIF decoder模式 外置*/
    HI_UNF_SIF_AIF_MODE_BUTT
} HI_UNF_SIF_AIF_MODE_E;

/**Freqency error threshold of an SIF*/
/**CNcomment:频率偏移阈值*/
typedef enum hiUNF_SIF_FREQ_ERR_THRESHOLD_E
{
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_10K = 0,          /**<Freqency error threshold 10K*/ /**<CNcomment:频率偏移阈值 10K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_20K,              /**<Freqency error threshold 20K*/ /**<CNcomment:频率偏移阈值 20K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_27K,              /**<Freqency error threshold 27K*/ /**<CNcomment:频率偏移阈值 27K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_30K,              /**<Freqency error threshold 30K*/ /**<CNcomment:频率偏移阈值 30K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_40K,              /**<Freqency error threshold 40K*/ /**<CNcomment:频率偏移阈值 40K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_50K,              /**<Freqency error threshold 50K*/ /**<CNcomment:频率偏移阈值 50K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_BUTT
} HI_UNF_SIF_FREQ_ERR_THRESHOLD_E;

/*Over Devaiton Parameter of an SIF*/
/**CNcomment:过调制*/
typedef enum hiUNF_SIF_OVER_DEVIATION_E 
{
    HI_UNF_SIF_OVER_DEVIATION_50K  = 0x0,           /**<Over Devaiton 50K*/  /**<CNcomment:过调制 50K*/
    HI_UNF_SIF_OVER_DEVIATION_100K,                 /**<Over Devaiton 100K*/ /**<CNcomment:过调制 100K*/
    HI_UNF_SIF_OVER_DEVIATION_200K,                 /**<Over Devaiton 200K*/ /**<CNcomment:过调制 200K*/
    HI_UNF_SIF_OVER_DEVIATION_384K,                 /**<Over Devaiton 384K*/ /**<CNcomment:过调制 384K*/
    HI_UNF_SIF_OVER_DEVIATION_540K,                 /**<Over Devaiton 500K*/ /**<CNcomment:过调制 500K*/
    HI_UNF_SIF_OVER_DEVIATION_BUTT
} HI_UNF_SIF_OVER_DEVIATION_E;

/*Open Parameters of an SIF*/
/**CNcomment:Open参数*/
typedef struct
{
    HI_UNF_SIF_AIF_MODE_E enAIFMode;                /* internal/external aif *//**<CNcomment:内置外置AIF，关系到时钟的方案*/
} HI_UNF_SIF_OPENPARMS_S;

/*Attributes of an SIF */
/**CNcomment:SIF模块属性*/
typedef struct
{
    HI_BOOL bAutoMute;                              /**<Auto Mute*/ /**<CNcomment:自动静音*/
    HI_U32  u32PrescaleLevel;                       /**<Prescale level*/ /**<CNcomment:前置增益水平*/
    HI_UNF_SIF_OUTMODE_E            enOutMode;      /**<SIF output mode*/ /**<CNcomment:SIF信号输出模式*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_E enFreqThreshold;/**<Freqency error Threshold*/ /**<CNcomment:频率偏移阈值*/
    HI_U32 u32CarriMgntudeThreshold;                /**<Carrier Magnitude Threshold*/ /**<CNcomment:载波幅度阈值*/
    HI_U32 u32CarriFMQualThreshold;                 /**<FM Quality Threshold*/ /**<CNcomment:FM质量阈值*/
    HI_U32 u32CarriAMNoiseThreshold;                /**<AM Noise Threshold*/ /**<CNcomment:AM噪声阈值*/
    HI_U32 u32CarriNICAMNoiseThreshold;             /**<NICAM Noise Threshold*/ /**<CNcomment:NICAM噪声阈值*/
} HI_UNF_SIF_ATTR_S;

/*Attributes of Carrier */
/**CNcomment:载波属性 */
typedef struct
{
    HI_UNF_SIF_STANDARD_TYPE_E  enStandardType;    /**<Standard Type*/ /**<CNcomment:载波伴音制式*/
    HI_U32 u32CarrierFreq;                         /**<Carrier Frequency*/ /**<CNcomment:载波频率*/
}HI_UNF_SIF_CARRIER_ATTR_S;

/*ID of an SIF device*/
/**CNcomment:SIF序号*/
typedef enum
{
    HI_UNF_SIF_ID_0 = 0,       /* ID 0f SIF 0*//**<CNcomment:SIF0*/
    HI_UNF_SIF_ID_BUTT
} HI_UNF_SIF_ID_E;

/*Priority list of standard*/
/**CNcomment:制式的优先级列表*/
typedef struct hiHI_UNF_SIF_STANDARD_PRIORITY_LIST_S
{
    HI_U32 u32ListLen;
    HI_UNF_SIF_STANDARD_TYPE_E enPriorityList[HI_UNF_SIF_STANDARD_NUM_MAX];
} HI_UNF_SIF_STANDARD_PRIORITY_LIST_S;

/** @}*/  /** <!-- ==== Structure Definition End ====*/

/******************************* API Declaration *****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */


/** 
\brief Get Basic Audio Standard. CNcomment:获取音频基本伴音制式 CNend
\attention \n
\param[in] enOriginalStandard     Audio SIF Standard Type  CNcomment:音频第二伴音中频制式 CNend
\param[out] penBasicStandard      Audio SIF Standard Type  CNcomment:音频第二伴音中频基本制式 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_ERR_SIF_INVALID_ID	 The parameter enSound is invalid. CNcomment:无效Sound ID CNend
\retval ::HI_ERR_SIF_NULL_PTR     The pointer is null. CNcomment:指针参数为空 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_MapBasicAudioStandard(HI_UNF_SIF_STANDARD_TYPE_E enOriginalStandard,
                                           HI_UNF_SIF_STANDARD_TYPE_E *penBasicStandard);

/** 
\brief Initializes an SIF device. CNcomment:初始化SIF模块 CNend
\attention \n
Before calling the SIF module, you must call this application programming interface (API). CNcomment:调用SIF模块要求首先调用该接口 CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Init(HI_VOID);

/** 
\brief Deinitializes an SIF device. CNcomment:去初始化设备 CNend
\attention \n
N/A
\param N/A
\retval ::HI_SUCCESS Success CNcomment:成功 CNend 
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_DeInit(HI_VOID);

/** 
\brief Open an SIF device. CNcomment:打开SIF设备 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] pstOpenPara     Prameter of an SIF device CNcomment:SIF设备参数 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Open(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OPENPARMS_S *pstOpenPara);

/** 
\brief Close an SIF device. CNcomment:关闭SIF设备 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Close(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Set The Attribute SIF device. CNcomment:设置SIF设备属性 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] pstSifAttr      Attribute of an SIF device CNcomment:SIF设备属性 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Get The Default Attribute SIF device. CNcomment:获取SIF设备默认属性 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] pstSifAttr     Default Attribute of an SIF device CNcomment:SIF设备属性 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetDefaultAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Get The Attribute SIF device. CNcomment:获取SIF设备属性 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] pstSifAttr     Attribute of an SIF device CNcomment:SIF设备属性 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Start The SIF device. CNcomment:启动SIF设备 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Start(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Stop The SIF device. CNcomment:停止SIF设备 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Stop(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Set The Audio Standard. CNcomment:设置音频伴音制式 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] enSifStandard   Audio Standard of an SIF device CNcomment:SIF音频伴音制式 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E enSifStandard);

/** 
\brief Start The Auto Standard Detect. CNcomment:启动自动制式检测 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] enSifDetCtl     Auto Standard Detect of an SIF device CNcomment:SIF自动制式检测控制 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_StartAutoStandardDetection(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_SYSCTL_E enSifDetCtl);

/** 
\brief Get The Audio Standard Detect Complete Flag. CNcomment:获取自动制式检测完成标志 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] pbAsdComplete  Audio Standard Detect Complete Flag of an SIF device CNcomment:SIF模块制式检测完成标志 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetDetectComplete(HI_UNF_SIF_ID_E enSIf, HI_BOOL *pbAsdComplete);

/** 
\brief Get The Audio Standard . CNcomment:获取伴音制式 CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] penSifStandard  Audio Standard of an SIF device CNcomment:SIF模块音频伴音制式 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetUserSettingStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E *penSifStandard);

/** 
\brief Get The Result of Auto Standard Detect. CNcomment:获取自动制式检测结果 CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] penSifAutoStandard  The Result of Auto Standard Detect of an SIF device CNcomment:SIF模块自动伴音制式检测结果 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetAutoDetectStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E *penSifAutoStandard);

/** 
\brief Set Audio Mode of SIF. CNcomment:设置音频伴音模式 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] enSifOutmode    Aduio Standard of an SIF device CNcomment:SIF模块伴音模式 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetSoundMode(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OUTMODE_E enSifOutmode);

/** 
\brief Get Audio Mode of SIF. CNcomment:获取音频伴音模式 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF设备号 CNend
\param[out] penSifOutmode  Aduio Mode of an SIF device CNcomment:SIF模块伴音模式 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetSoundMode(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_AAOS_MODE_E *penSifOutmode);

/** 
\brief Set Over Demulation Parameter of SIF. CNcomment:设置音频过调制参数 CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] enOverDeviation  Over Devation Parameter of an SIF device CNcomment:SIF模块过调制参数 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetOverDeviation(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OVER_DEVIATION_E enOverDeviation);

/** 
\brief Set Carrier Shift Parameter of SIF. CNcomment:设置音频频移 CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] u32CarriShift    Carrier Shift Parameter of an SIF device CNcomment:SIF模块频移参数 CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetCarriShift(HI_UNF_SIF_ID_E enSIf, HI_U32 u32CarriShift);

/**
\brief Get The Audio carrier attribution. CNcomment:获取伴音载波属性 CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] pstCarrierAttr    Attribution of Audio Carrier CNcomment:伴音载波属性CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetStandardTry(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_CARRIER_ATTR_S *pstCarrierAttr);

/**
\brief Set the standard list for try interface. CNcomment:设置制式识别优先级列表给Try接口 CNend
\attention \n
N/A
\param[in] enSIf             ID of an SIF device CNcomment:SIF设备号 CNend
\param[in] pstPriorityList   STANDARD PRIORITY LIST CNcomment:制式优先级列表CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE FAILURE CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SIF_SetStandardTryPriority(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_PRIORITY_LIST_S *pstPriorityList);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_UNF_SIF_H__ */
