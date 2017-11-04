/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_unf_pq.h
  Version       : Initial Draft
  Author        : l00212594/y00220178
  Created       : 2013/10/29
  Description   :

******************************************************************************/

#ifndef __HI_UNF_PQ_H__
#define __HI_UNF_PQ_H__

#include "hi_type.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PQ*/
/** @{ */  /** <!-- [PQ] */

/**PQ matket mode *//**CNcomment: PQ卖场模式 */
typedef enum hiUNF_PQ_DEMO_E
{
     HI_UNF_PQ_DEMO_DBDR,
     HI_UNF_PQ_DEMO_NR,
     HI_UNF_PQ_DEMO_SHARPNESS,
     HI_UNF_PQ_DEMO_DCI,
     HI_UNF_PQ_DEMO_WCG,
    // HI_UNF_PQ_DEMO_FRC,
     HI_UNF_PQ_DEMO_COLOR,
     HI_UNF_PQ_DEMO_SR,
     HI_UNF_PQ_DEMO_ALL,

     HI_UNF_PQ_DEMO_BUTT
}  HI_UNF_PQ_DEMO_E;

/**PQ on/off module *//**CNcomment: PQ开关模块*/
typedef enum hiUNF_PQ_MODULE_E
{
     HI_UNF_PQ_MODULE_FMD = 0,
     HI_UNF_PQ_MODULE_TNR,
     HI_UNF_PQ_MODULE_SNR,
     HI_UNF_PQ_MODULE_DB,
     HI_UNF_PQ_MODULE_DR,
     HI_UNF_PQ_MODULE_HSHARPNESS,
     HI_UNF_PQ_MODULE_SHARPNESS,
     HI_UNF_PQ_MODULE_CCCL,
     HI_UNF_PQ_MODULE_COLOR_CORING,
     HI_UNF_PQ_MODULE_BLUE_STRETCH,
     HI_UNF_PQ_MODULE_GAMMA,
     HI_UNF_PQ_MODULE_DBC,
     HI_UNF_PQ_MODULE_DCI,
     HI_UNF_PQ_MODULE_COLOR,
     HI_UNF_PQ_MODULE_ES,
     HI_UNF_PQ_MODULE_SR,
     HI_UNF_PQ_MODULE_FRC,
     HI_UNF_PQ_MODULE_WCG,

     HI_UNF_PQ_MODULE_BUTT
}  HI_UNF_PQ_MODULE_E;

/**Color temperature information*//**CNcomment: 色温信息*/
typedef struct hiUNF_PQ_COLOR_TEMP_S
{
    HI_U32 u32RedGain;
    HI_U32 u32GreenGain;
    HI_U32 u32BlueGain;
    HI_U32 u32RedOffset;
    HI_U32 u32GreenOffset;
    HI_U32 u32BlueOffset;
}  HI_UNF_PQ_COLOR_TEMP_S;

/**Flesh tone gain type*//**CNcomment: 肤色增益类型*/
typedef enum hiUNF_PQ_FLESHTONE_E
{
     HI_UNF_PQ_FLESHTONE_GAIN_OFF = 0,
     HI_UNF_PQ_FLESHTONE_GAIN_LOW,
     HI_UNF_PQ_FLESHTONE_GAIN_MID,
     HI_UNF_PQ_FLESHTONE_GAIN_HIGH,

     HI_UNF_PQ_FLESHTONE_GAIN_BUTT
}  HI_UNF_PQ_FLESHTONE_E;

/**Six base color type*//**CNcomment: 六基色类型*/
typedef enum hiUNF_PQ_SIX_BASE_COLOR_E
{
    HI_UNF_PQ_SIX_BASE_COLOR_ALL_ON = 0,
    HI_UNF_PQ_SIX_BASE_COLOR_R_OFF,//红
    HI_UNF_PQ_SIX_BASE_COLOR_G_OFF,//绿
    HI_UNF_PQ_SIX_BASE_COLOR_B_OFF,//蓝
    HI_UNF_PQ_SIX_BASE_COLOR_CYAN_OFF,//青
    HI_UNF_PQ_SIX_BASE_COLOR_MAGENTA_OFF,//紫
    HI_UNF_PQ_SIX_BASE_COLOR_YELLOW_OFF,//黄
    HI_UNF_PQ_SIX_BASE_COLOR_RGB_OFF,//红绿蓝
    HI_UNF_PQ_SIX_BASE_COLOR_CMY_OFF,//青紫黄
    HI_UNF_PQ_SIX_BASE_COLOR_ALL_OFF,//所有颜色关闭

    HI_UNF_PQ_SIX_BASE_COLOR_BUTT
} HI_UNF_PQ_SIX_BASE_COLOR_E;

/**SR demo mode*//**CNcomment: SR演示模式*/
typedef enum hiUNF_PQ_SR_DEMO_E
{
     HI_UNF_PQ_SR_DISABLE  = 0,//关掉SR,只ZME
     HI_UNF_PQ_SR_ENABLE_R,  //  右边SR
     HI_UNF_PQ_SR_ENABLE_L,  //左边SR
     HI_UNF_PQ_SR_ENABLE_A,  //全屏

     HI_UNF_PQ_SR_DEMO_BUTT
}HI_UNF_PQ_SR_DEMO_E;

/**Brightness histgram information*//**CNcomment: 亮度直方图信息*/
typedef struct hiUNF_PQ_DCI_HISTGRAM_S
{
    HI_S32 s32HistGram[32];
}HI_UNF_PQ_DCI_HISTGRAM_S;

/****  自动白平衡结果参数  ****/
typedef enum hiUNF_PQ_WHITE_BALANCE_TMP_E
{
   HI_UNF_PQ_WHITE_BALANCE_COOL,
   HI_UNF_PQ_WHITE_BALANCE_STANDARD,
   HI_UNF_PQ_WHITE_BALANCE_WARM,

   HI_UNF_PQ_WHITE_BALANCE_BUTT
 }HI_UNF_PQ_WHITE_BALANCE_TMP_E;

typedef struct hiUNF_PQ_WHITE_BALANCE_BALANCE_SINGLE_PARAM_S
{  
   HI_U32 u32RGain;
   HI_U32 u32GGain;
   HI_U32 u32BGain;
   HI_U32 u32ROffset;
   HI_U32 u32GOffset;
   HI_U32 u32BOffset;
}HI_UNF_PQ_WHITE_BALANCE_SINGLE_PARAM_S;

typedef struct hiUNF_PQ_WHITE_BALANCE_PARAM_S
{ 
   HI_UNF_PQ_WHITE_BALANCE_SINGLE_PARAM_S astTepParam[HI_UNF_PQ_WHITE_BALANCE_BUTT];
}HI_UNF_PQ_WHITE_BALANCE_PARAM_S;


/**Sharpen GAIN*//**CNcomment: 高级清晰度增益*/
typedef struct hiUNF_PQ_SHARP_GAIN_S
{
	HI_U32 u32LtiGain; //范围[ 0 , 511]
	HI_U32 u32HPeakRatio; //范围[ 0 , 511]
	HI_U32 u32VPeakRatio; //范围[ 0 , 511]
	HI_U32 u32DPeakRatio; //范围[ 0 , 511]
	
}HI_UNF_PQ_SHARP_GAIN_S;

/**Color GAIN*//**CNcomment:Color   增益*/
typedef struct hiUNF_PQ_ACM_GAIN_S
{
	HI_U32 u32LumGain; //范围[ 0 , 1023]
	HI_U32 u32HueGain; //范围[ 0 , 1023]
	HI_U32 u32SatGain; //范围[ 0 , 1023]
	HI_U32 u32Reserved;
}HI_UNF_PQ_ACM_GAIN_S;

/**DCI GAIN*//**CNcomment:Color   增益*/
typedef struct hiUNF_PQ_DCI_GAIN_S
{
	HI_U32 u32LowGain; //范围[ 0 , 63]
	HI_U32 u32MiddleGain; //范围[ 0 , 63]
	HI_U32 u32HighGain; //范围[ 0 , 63]
	HI_U32 u32Reserved;
}HI_UNF_PQ_DCI_GAIN_S;

/* Color Space*//**CNcomment:色域空间*/
typedef enum hiUNF_PQ_COLOR_SPACE_E
{
    HI_UNF_CS_UNKNOWN = 0,
    HI_UNF_CS_DEFAULT,
    HI_UNF_CS_BT601_YUV_LIMITED,/* ::::Current Used:::: BT.601  */
    HI_UNF_CS_BT601_YUV_FULL,
    HI_UNF_CS_BT601_RGB_LIMITED,
    HI_UNF_CS_BT601_RGB_FULL,
    HI_UNF_CS_NTSC1953,
    HI_UNF_CS_BT470_SYSTEM_M,    
    HI_UNF_CS_BT470_SYSTEM_BG,
    HI_UNF_CS_BT709_YUV_LIMITED,/* ::::Current Used:::: BT.709 */
    HI_UNF_CS_BT709_YUV_FULL,
    HI_UNF_CS_BT709_RGB_LIMITED,
    HI_UNF_CS_BT709_RGB_FULL,   /* ::::Current Used:::: */
    
    HI_UNF_CS_BT2020_YUV_LIMITED,/* ::::Current Used:::: BT.2020 */
    HI_UNF_CS_BT2020_YUV_FULL,
    HI_UNF_CS_BT2020_RGB_LIMITED,
    HI_UNF_CS_BT2020_RGB_FULL,   /* ::::Current Used:::: */
    
    HI_UNF_CS_REC709,      /* HD and modern captures. */
    
    HI_UNF_CS_SMPT170M, /* ITU-R 601 -- broadcast NTSC/PAL */
    HI_UNF_CS_SMPT240M, /* 1125-Line (US) HDTV */
    HI_UNF_CS_BT878,    
    HI_UNF_CS_XVYCC,
    HI_UNF_CS_JPEG,
    HI_UNF_CS_RGB,
   
    HI_UNF_CS_BUTT
} HI_UNF_PQ_COLOR_SPACE_E;

/* Gamma Type*//**CNcomment:Gamma 类型*/
typedef enum hiUNF_PQ_GAMMA_TYPE_E
{              
    HI_UNF_GAMMA_TYPE_1886 = 0,
    HI_UNF_GAMMA_TYPE_2084,

    HI_UNF_GAMMA_TYPE_BUTT
} HI_UNF_PQ_GAMMA_TYPE_E;

typedef struct hiUNF_PQ_HDR10_METADATA_S
{
    HI_U32        u32DispPrimariesX0;
    HI_U32        u32DispPrimariesY0;
    HI_U32        u32DispPrimariesX1;
    HI_U32        u32DispPrimariesY1;
    HI_U32        u32DispPrimariesX2;
    HI_U32        u32DispPrimariesY2;
    HI_U32        u32WhitePointX;
    HI_U32        u32WhitePointY;
    HI_U32        u32MaxDispMasteringLuminance;
    HI_U32        u32MinDispMasteringLuminance;
    HI_U32        u32MaxContentLightLevel;
    HI_U32        u32MaxFrmAverageLightLevel;
}HI_UNF_PQ_HDR10_METADATA_S;

/* HDR INFO*//**CNcomment:HDR  信息*/
typedef struct hiUNF_PQ_HDR_INFO_S
{
	HI_UNF_PQ_COLOR_SPACE_E    	eColorSpace;	
    HI_UNF_PQ_GAMMA_TYPE_E     	eGammaType;
    HI_UNF_PQ_HDR10_METADATA_S  stMetadata;
} HI_UNF_PQ_HDR_INFO_S;

/* HDR FIXMODE*//**CNcomment:FIXMODE  信息*/
typedef struct hiUNF_PQ_HDR_FIXMODE_S
{  
   HI_BOOL bFixed;
   HI_UNF_PQ_HDR_INFO_S stHdrInfo;   
}HI_UNF_PQ_HDR_FIXMODE_S;

/* Color Section*//**CNcomment:颜色分段类型 */
typedef enum hiUNF_PQ_COLOR_E
{
    HI_UNF_PQ_COLOR_R,//红
    HI_UNF_PQ_COLOR_G,//绿
   	HI_UNF_PQ_COLOR_B,//蓝
   	HI_UNF_PQ_COLOR_CYAN,//青
    HI_UNF_PQ_COLOR_PURPLE,//紫
    HI_UNF_PQ_COLOR_YELLOW,//黄
	HI_UNF_PQ_COLOR_FLESH,//肤色

    HI_UNF_PQ_COLOR_BUTT
} HI_UNF_PQ_COLOR_E;


/* Color SATGAIN*//**CNcomment:颜色饱和度增益  */
typedef struct hiUNF_PQ_SAT_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_SAT_GAIN_S;

/* Color HUEGAIN*//**CNcomment:颜色色调增益 */
typedef struct hiUNF_PQ_HUE_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_HUE_GAIN_S;

/* Color YGAIN*//**CNcomment:颜色亮度增益  */
typedef struct hiUNF_PQ_BRI_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_BRI_GAIN_S;

/*gamma结构*/
typedef struct hiUNF_GAMMA_TABLE_S
{
    HI_U32 au32R[257];
    HI_U32 au32G[257];
    HI_U32 au32B[257];
} HI_UNF_GAMMA_TABLE_S;

/*NR  str type Y/C*/
typedef enum hiUNF_PQ_NRSTR_E
{
     HI_UNF_PQ_NRSTR_Y = 0,
     HI_UNF_PQ_NRSTR_C,
     HI_UNFPQ_NRSTR_BUTT
} HI_UNF_PQ_NRSTR_E;

typedef struct hiUNF_PQ_NRSTR_GAIN_S
{
	HI_UNF_PQ_NRSTR_E enNRSTR;
	HI_U32 u32Gain;
}HI_UNF_PQ_NRSTR_GAIN_S;

/*COLOR 表类型*/
typedef enum hiUNF_PQ_COLOR_TYPE_E
{
    HI_UNF_PQ_COLOR_NORMAL =0,
    HI_UNF_PQ_COLOR_VIVID,
    HI_UNF_PQ_COLOR_HDR,
    HI_UNF_PQ_COLOR_TYPE_1,
    HI_UNF_PQ_COLOR_TYPE_2,   
    HI_UNF_PQ_COLOR_TYPE_3,
    HI_UNF_PQ_COLOR_TYPE_4,
    HI_UNF_PQ_COLOR_TYPE_5,

    HI_UNF_PQ_COLOR_TYPE_BUTT
} HI_UNF_PQ_COLOR_TYPE_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      PQ  */
/** @{ */  /** <!-- [PQ ] */


/**
 \brief the whole initialization of the PQ device. CNcomment:PQ接口驱动软件初始化 CNend
 \attention \n
 \param[in] pszPath.CNcomment:PQ配置文件路径CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_Init(HI_CHAR* pszPath);

/**
 \brief deinit the PQ device. CNcomment:PQ接口驱动软件去初始化 CNend
 \attention \n
 \param CNcomment:无 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_DeInit(HI_VOID);

/**
 \brief get brightness. CNcomment:获取亮度 CNend
 \attention \n
 \param[out] pu32Brightness.CNcomment:亮度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetBrightness(HI_U32 *pu32Brightness);

/**
 \brief set brightness. CNcomment:设置亮度 CNend
 \attention \n
 \param[in] u32Brightness.CNcomment:亮度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetBrightness(HI_U32 u32Brightness);

/**
 \brief get contrast. CNcomment:获取对比度 CNend
 \attention \n
 \param[out] pu32Contrast.CNcomment:对比值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetContrast(HI_U32 *pu32Contrast);

/**
 \brief set Contrast. CNcomment:设置对比度 CNend
 \attention \n
 \param[in] u32Contrast.CNcomment:对比度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetContrast(HI_U32 u32Contrast);

/**
 \brief get saturation. CNcomment:获取饱和度 CNend
 \attention \n
 \param[out] pu32Saturation.CNcomment:饱和度 值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetSaturation(HI_U32 *pu32Saturation);

/**
 \brief set saturation. CNcomment:设置饱和度 CNend
 \attention \n
 \param[in] u32Saturation.CNcomment:饱和度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetSaturation(HI_U32 u32Saturation);

/**
 \brief get hue. CNcomment:获取色调CNend
 \attention \n
 \param[out] pu32Hue.CNcomment:色调值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetHue(HI_U32 *pu32Hue);

/**
 \brief set hue. CNcomment:设置色调CNend
 \attention \n
 \param[in] u32Hue.CNcomment:色调值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetHue(HI_U32 u32Hue);

/**
 \brief get noise reduction level. CNcomment:获取降噪强度CNend
 \attention \n
 \param[out] pu32NRLevel.CNcomment:降噪强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetNR(HI_U32 *pu32NRLevel);

/**
 \brief set noise reduction level. CNcomment:获取降噪强度CNend
 \attention \n
 \param[in] u32NRLevel.CNcomment:降噪强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetNR(HI_U32 u32NRLevel);

/**
 \brief get  auto noise reduction status. CNcomment:获取自动降噪开关状态CNend
 \attention \n
 \param[out] pu32OnOff.CNcomment:开关状态 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetNRAutoMode(HI_U32 *pu32OnOff);

/**
 \brief set  auto noise reduction status. CNcomment:设置自动降噪开关状态CNend
 \attention \n
 \param[in] u32OnOff.CNcomment:开关状态 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetNRAutoMode(HI_U32 u32OnOff);

/**
 \brief get  SR demo type. CNcomment:获取超分SR演示类型CNend
 \attention \n
 \param[out] penType.CNcomment:演示类型CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetSRMode(HI_UNF_PQ_SR_DEMO_E *penType);

/**
 \brief set  SR demo type. CNcomment:设置超分SR演示类型CNend
 \attention \n
 \param[in] enType.CNcomment:演示类型CCNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetSRMode(HI_UNF_PQ_SR_DEMO_E enType);

/**
 \brief get sharpness level. CNcomment:获取清晰度强度CNend
 \attention \n
 \param[out] pu32Sharpness.CNcomment:清晰度强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetSharpness(HI_U32 *pu32Sharpness);

/**
 \brief set sharpness level. CNcomment:设置清晰度强度CNend
 \attention \n
 \param[in] u32Sharpness.CNcomment:清晰度强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetSharpness(HI_U32 u32Sharpness);

/**
 \brief get de-blocking level. CNcomment:获取块降噪De-blocking强度CNend
 \attention \n
 \param[out] pu32DBlevel.CNcomment:De-blocking强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetDeBlocking(HI_U32 *pu32DBlevel);

/**
 \brief set de-blocking level. CNcomment:设置块降噪De-blocking强度CNend
 \attention \n
 \param[in] u32DBlevel.CNcomment:De-blocking强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetDeBlocking(HI_U32 u32DBlevel);

/**
 \brief get de-ringing level. CNcomment:获取去除蚊虫噪声de-ringing强度CNend
 \attention \n
 \param[out] pu32DRlevel.CNcomment:De-ringing强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetDeRinging(HI_U32 *pu32DRlevel);

/**
 \brief set de-ringing level. CNcomment:设置去除蚊虫噪声de-ringing强度CNend
 \attention \n
 \param[in] u32DRlevel.CNcomment:De-ringing强度值,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetDeRinging(HI_U32 u32DRlevel);

/**
 \brief set color temperature. CNcomment:设置色温值CNend
 \attention \n
 \param[in] pstColorTemp.CNcomment:色温值 ,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief get color temperature. CNcomment:获取色温值CNend
 \attention \n
 \param[out] pstColorTemp.CNcomment:色温值 ,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief get color type. CNcomment:获取颜色曲线类型文件CNend
 \attention \n
 \param[out] pu32ColorType.CNcomment: 参考HI_UNF_PQ_COLOR_TYPE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetColorGain(HI_UNF_PQ_COLOR_TYPE_E *penColorType);

/**
 \brief set color type. CNcomment:动态加载不同颜色曲线类型文件
 \attention \n
 \param[in] enColorType.CNcomment: 参考 HI_UNF_PQ_COLOR_TYPE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetColorGain(HI_UNF_PQ_COLOR_TYPE_E enColorType);
/**
 \brief get flesh tone level. CNcomment:获取肤色增强强度CNend
 \attention \n
 \param[out] pu32FleshToneLevel.CNcomment:强度 ,参考 HI_UNF_PQ_FLESHTONE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetFleshTone(HI_UNF_PQ_FLESHTONE_E *pu32FleshToneLevel);

/**
 \brief set flesh tone level. CNcomment:设置肤色增强强度CNend
 \attention \n
 \param[in] enFleshToneLevel.CNcomment:强度 ,参考 HI_UNF_PQ_FLESHTONE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetFleshTone( HI_UNF_PQ_FLESHTONE_E enFleshToneLevel);

/**
 \brief get six base color demo type. CNcomment:获取六基色演示类型CNend
 \attention \n
 \param[out] pu32SixBaseColor.CNcomment:六基色类型 ,参考 HI_UNF_PQ_SIX_BASE_COLOR_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetSixBaseColor(HI_UNF_PQ_SIX_BASE_COLOR_E *pu32SixBaseColor);

/**
 \brief set six base color demo type. CNcomment:设置六基色演示类型CNend
 \attention \n
 \param[in] enSixBaseColor.CNcomment:六基色类型 ,参考 HI_UNF_PQ_SIX_BASE_COLOR_E CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetSixBaseColor(HI_UNF_PQ_SIX_BASE_COLOR_E enSixBaseColor);

/**
 \brief get back light level. CNcomment:获取背光强度CNend
 \attention \n
 \param[out] pu32BackLightLevel.CNcomment:背光强度 ,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetBackLight(HI_U32 *pu32BackLightLevel);

/**
 \brief set back light level. CNcomment:设置背光强度CNend
 \attention \n
 \param[in] u32BackLightLevel.CNcomment:背光强度 ,有效范围为0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetBackLight(HI_U32 u32BackLightLevel);

/**
 \brief get gamma total number. CNcomment:Gamma Table中可能存在多组Gamma曲线,用户可获取Gamma曲线数量CNend
 \attention \n
 \param[out] s32Num.CNcomment:gamma 个数 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
 
extern HI_S32 HI_UNF_PQ_GetGammaNum(HI_S32 *s32Num);

/**
 \brief set gamma by index. CNcomment:设置gamma CNend
 \attention \n
 \param[in] s32GammaIndex.CNcomment:gamma index CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_SetGamma(HI_S32 s32GammaIndex);

/**
 \brief set all PQ module on/off status. CNcomment:设置各PQ 模块开关 CNend
 \attention \n
 \param[in] enFlags.CNcomment:模块号，参考HI_UNF_PQ_MODULE_E CNend
 \param[in] u32OnOff.CNcomment:开关 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
 
extern HI_S32 HI_UNF_PQ_SetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 u32OnOff);

/**
 \brief get all PQ module on/off status. CNcomment:获取各PQ 模块开关 CNend
 \attention \n
 \param[in] enFlags.CNcomment:模块号，参考HI_UNF_PQ_MODULE_E CNend
 \param[out] u32OnOff.CNcomment:开关状态 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief set all PQ module demo status. CNcomment:设置各PQ 模块卖场模式 CNend
 \attention \n
 \param[in] enFlags.CNcomment:模块号，参考HI_UNF_PQ_DEMO_E CNend
 \param[in] u32OnOff.CNcomment:卖场模式开关 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
 
extern HI_S32 HI_UNF_PQ_SetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 u32OnOff);

/**
 \brief get brightness histgram information. CNcomment:获取亮度直方图信息CNend
 \attention \n
 \param[out] pstDCIHistgram.CNcomment:直方图信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetHistgram( HI_UNF_PQ_DCI_HISTGRAM_S *pstDCIHistgram);

/**
 \brief get average brightness by histgram information. CNcomment:获取平均亮度CNend
 \attention \n
 \param[out] pu32AvrBrigheness().CNcomment:平均亮度CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
 
extern HI_S32 HI_UNF_PQ_GetAvrBrightness(HI_U32 *pu32AvrBrigheness);

/**
 \brief get White balance information. CNcomment:获取自动白平衡结果信息Nend
 \attention \n
 \param[out] pstWhiteBalanceParam.CNcomment:自动白平衡结果信息Nend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetWhiteBalanceParam(HI_UNF_PQ_WHITE_BALANCE_PARAM_S *pstWhiteBalanceParam);

 
  /**
   \brief get average brightness by histgram information. CNcomment:获取Sharpen 的增益CNend
   \attention \n
   \param[out] pstSharpenGain.CNcomment:Sharpen   增益CNend
   \retval HI_SUCCESS	  success.	CNcomment:成功 CNend
   \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
   \see \n
   CNcomment:无 CNend
   */
 extern HI_S32 HI_UNF_PQ_GetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstSharpenGain);

 /**
 \brief get average brightness by histgram information. CNcomment:设置Sharpen  高频 的增益CNend
 \attention \n
 \param[in] pstSharpenGain.CNcomment:Sharpen   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstSharpenGain);

 /**
 \brief get average brightness by histgram information. CNcomment:获取颜色 的增益CNend
 \attention \n
 \param[out] pstAcmGain.CNcomment:ACM   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pstAcmGain);

 /**
 \brief get average brightness by histgram information. CNcomment:设置颜色 的增益CNend
 \attention \n
 \param[in] pstAcmGain.CNcomment:ACM   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pstAcmGain);

 /**
 \brief get average brightness by histgram information. CNcomment:获取对比度 的增益CNend
 \attention \n
 \param[out] pstDciGain.CNcomment:dci  增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetDciGain(HI_UNF_PQ_DCI_GAIN_S *pstDciGain);

/**
 \brief get average brightness by histgram information. CNcomment:设置对比度 的增益CNend
 \attention \n
 \param[in] pstDciGain.CNcomment:DCI   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetDciGain(HI_UNF_PQ_DCI_GAIN_S *pstDciGain);
/**
 \brief get average brightness by histgram information. CNcomment:设置HDR  FIX 模式CNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  FIX 模式CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32  HI_UNF_PQ_SetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
/**
 \brief get average brightness by histgram information. CNcomment:获取HDR  FIX 模式CNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  FIX 模式CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32  HI_UNF_PQ_GetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
/**
 \brief get average brightness by histgram information. CNcomment: 获取HDR  源信息CNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  源信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32  HI_UNF_PQ_GetSrcHdrInfo(HI_UNF_PQ_HDR_INFO_S  *pstHdrInfo);
/**
 \brief Set Saturation gain for section color. CNcomment: 设置分段颜色饱和度增益 信息CNend
 \attention \n
 \param[in] pstSatGain.CNcomment:颜色饱和度增益信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern  HI_S32 HI_UNF_PQ_SetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);
/**
 \brief Get Saturation gain for section color. CNcomment: 获取分段颜色饱和度 信息CNend
 \attention \n
 \param[in] pstSatGain.CNcomment:颜色饱和度增益信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern  HI_S32 HI_UNF_PQ_GetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

/**
 \brief Set HUE gain for section color. CNcomment: 设置分段颜色色调信息CNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  源信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

/**
 \brief Get HUE gain for section color. CNcomment: 获取分段颜色色调信息CNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM 源信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */

extern HI_S32 HI_UNF_PQ_GetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

/**
 \brief Set Y gain for section color. CNcomment: 设置分段颜色亮度信息CNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  源信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

/**
 \brief Get Bright gain for section color. CNcomment: 设置分段颜色亮度信息CNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  源信息CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
HI_S32 HI_UNF_PQ_GetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

/**
 \brief Set gamma table data. CNcomment: 获取GAMMA 表数据CNend
 \attention \n
 \param[in] pstGammaTable.CNcomment:gamma table 数据CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_SetGammaTable(HI_UNF_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief Get gamma table data. CNcomment: 获取GAMMA 表数据CNend
 \attention \n
 \param[in] pstGammaTable.CNcomment:gamma table 数据CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetGammaTable(HI_UNF_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief set cti gain. CNcomment:设置 cti 的增益CNend
 \attention \n
 \param[in] pstCtiGain .CNcomment:Cti   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment: 0~128
 */
extern HI_S32 HI_UNF_PQ_SetCtiGain(HI_U32 u32CtiGain);

/**
 \brief get cti gain. CNcomment:获取 cti 的增益CNend
 \attention \n
 \param[out] pstCtiGain.CNcomment:Cti   增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetCtiGain(HI_U32 *pstCtiGain);

/**
 \brief Set NRStr . CNcomment: 设置降噪增益CNend
 \attention \n
 \param[in] pstNRStr .CNcomment:NR增益 CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment: 0~64
 */
extern HI_S32 HI_UNF_PQ_SetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

/**
 \brief get NRStr.    CNcomment: 获取降噪增益CNend               
 \attention \n
 \param[out] pstNRStr.CNcomment:NR  增益CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

/** 
 \brief get RGBMax。 CNcomment: 获取RGB最大平均值CNend 
 \attention \n
 \param[out] pu32AvgRgbMax.CNcomment:获取RGB最大平均值有效范围为0~255CNend
 \retval HI_SUCCESS     success.  CNcomment:成功 CNend
 \retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
 \see \n
 CNcomment:无 CNend
 */
extern HI_S32 HI_UNF_PQ_GetAvgRGBMax(HI_U32 *pu32AvgRgbMax);
 
/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_PQ_H__ */


