/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_mpi_pq.h
  Version       : Initial Draft
  Author        : y00220178
  Created       : 2013/11/13
  Description   :

******************************************************************************/

#ifndef __HI_MPI_PQ_H__
#define __HI_MPI_PQ_H__

#include "hi_type.h"
#include "hi_unf_pq.h"
#include "hi_drv_pq.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*ACM table结构*/
typedef struct hiMPI_COLOR_PARAM_S
{
    HI_U16 u16Stretch;
    HI_U16 u16ClipRange;
    HI_U16 u16HueGain;         /*表示对Hue的增益，范围0-1023*/
    HI_U16 u16SatGain;         /*表示对Saturation的增益*/
    HI_U16 u16LumaGain;        /*表示对Luma的增益*/
    HI_U16 u16CbCrThre;        /*CbCr的门限值，若低于门限值就不做Color处理*/
    HI_S16 as16Luma[9][13][29]; /*Luma查找表*/
    HI_S16 as16Hue[9][13][29];  /*Hue查找表*/
    HI_S16 as16Sat[9][13][29];  /*Saturation查找表*/
    #if 1
    HI_S16 as16YHSbyH[3][29];           /*YbyH[29],    HbyH[]29,    SbyH[29]     delta  curve*/
    HI_S16 as16YHSbyHSgain[3][29][13];  /*YbyH[29][13],HbyH[29][13],SbyH[29][13] S gain curve*/
    HI_S16 as16YHSbyHYgain[3][29][9];   /*YbyH[29][9], HbyH[29][9], SbyH[29][9]  Y gain curve*/
    #endif
} MPI_COLOR_PARAM_S;

/****  自动白平衡结果参数  ****/
typedef enum hiMPI_WHITE_BALANCE_TMP_E
{
 
   HI_MPI_PQ_WHITE_BALANCE_COOL,
   HI_MPI_PQ_WHITE_BALANCE_STANDARD,
   HI_MPI_PQ_WHITE_BALANCE_WARM,

   HI_MPI_PQ_WHITE_BALANCE_BUTT 
}MPI_WHITE_BALANCE_TMP_E;

typedef struct hiMPI_WHITE_BALANCE_SINGLE_PARAM_S
{
   HI_U32 u32RGain;
   HI_U32 u32GGain;
   HI_U32 u32BGain;
   HI_U32 u32ROffset;
   HI_U32 u32GOffset;
   HI_U32 u32BOffset;  
}MPI_WHITE_BALANCE_SINGLE_PARAM_S;


typedef struct hiMPI_WHITE_BALANCE_PARAM_S
{ 
   MPI_WHITE_BALANCE_SINGLE_PARAM_S astTmpParam[HI_MPI_PQ_WHITE_BALANCE_BUTT];
}MPI_WHITE_BALANCE_PARAM_S;



/**
 \PQ初始化
 \attention \n

 \param[in] pszPath:PQ配置文件路径
 \param[out] 

 \retval ::HI_SUCCESS

 */
HI_S32 HI_MPI_PQ_Init(HI_CHAR* pszPath);

/**
 \PQ去初始化
 \attention \n

 \param[in] 
 \param[out] 

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_DeInit(HI_VOID);

/**
 \brief 获取亮度
 \attention \n
无

 \param[in] pu32Brightness：亮度值,有效范围: 0~255;
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetBrightness(HI_U32 *pu32Brightness);

/**
 \brief 设置亮度
 \attention \n
无

 \param[in] u32Brightness：亮度值,有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetBrightness(HI_U32 u32Brightness);

/**
 \brief 获取对比度
 \attention \n
无

 \param[in] 
 \param[out] pu32Contrast：对比度, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetContrast(HI_U32 *pu32Contrast);

/**
 \brief 设置对比度
 \attention \n
无

 \param[in] u32Contrast：对比度, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetContrast(HI_U32 u32Contrast);

/**
 \brief 获取色调
 \attention \n
无

 \param[in] 
 \param[out] pu32Hue：色调, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetHue(HI_U32 *pu32Hue);

/**
 \brief 设置色调
 \attention \n
无

 \param[in] u32Hue：色调, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetHue(HI_U32 u32Hue);

/**
 \brief 获取饱和度
 \attention \n
无

 \param[out] pu32Saturation：饱和度, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetSaturation(HI_U32 *pu32Saturation);

/**
 \brief 设置饱和度
 \attention \n
无

 \param[in] u32Saturation：饱和度,有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSaturation(HI_U32 u32Saturation);

/**
 \brief 获取降噪强度
 \attention \n
无

 \param[out] pu32NRLevel: 降噪等级, 有效范围: 0~255


 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetNR(HI_U32 *pu32NRLevel);

/**
 \brief 设置降噪强度
 \attention \n
无

 \param[in] u32NRLevel: 降噪等级, 有效范围: 0~255

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetNR(HI_U32 u32NRLevel);

/**
 \brief 获取自动降噪开关状态
 \attention \n
无

 \param[out] pu32OnOff


 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetNRAutoMode(HI_U32 *pu32OnOff);

/**
 \brief 设置降噪自动模式开关
 \attention \n
无

 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetNRAutoMode(HI_U32 u32OnOff);

/**
 \brief 获取SR演示类型
 \attention \n
无

 \param[out] *penType


 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetSRMode(HI_PQ_SR_DEMO_E *penType);

/**
 \brief 设置SR演示类型
 \attention \n
无

 \param[in] enType

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetSRMode(HI_PQ_SR_DEMO_E enType);

/**
 \brief 获取清晰度
 \attention \n
无

 \param[out] pu32Sharpness：清晰度, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetSharpness(HI_U32 *pu32Sharpness);

/**
 \brief 设置清晰度
 \attention \n
无

 \param[in] u32Sharpness：清晰度, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSharpness(HI_U32 u32Sharpness);

/**
 \brief 获取块降噪De-blocking强度
 \attention \n
无

 \param[out] pu32DBlevel：降噪等级, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDeBlocking(HI_U32 *pu32DBlevel);

/**
 \brief 设置块降噪De-blocking强度
 \attention \n
无

 \param[in] u32DBlevel:降噪等级, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDeBlocking(HI_U32 u32DBlevel);

/**
 \brief 获取去除蚊虫噪声de-ringing强度
 \attention \n
无

 \param[out] pu32DRlevel:降噪等级, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDeRinging(HI_U32 *pu32DRlevel);

/**
 \brief 设置去除蚊虫噪声de-ringing强度
 \attention \n
无

 \param[in] u32DRlevel:降噪等级, 有效范围: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDeRinging(HI_U32 u32DRlevel);

/**
 \brief 设置色温参数
 \attention \n
无

 \param[in] pstColorTemp:色温参数
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief 获取色温参数
 \attention \n
无

 \param[in] pstColorTemp：色温参数
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief 获取颜色类型曲线
 \attention \n
无

 \param[out] pu32ColorType

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetColorGain(HI_UNF_PQ_COLOR_TYPE_E *penColorType);

/**
 \brief 设置颜色类型曲线
 \attention \n
无

 \param[in] enColorType

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetColorGain(HI_UNF_PQ_COLOR_TYPE_E enColorType);

/**
 \brief 获取肤色增强
 \attention \n
  无

 \param[out] pu32FleshToneLevel

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetFleshTone(HI_U32 *pu32FleshToneLevel);

/**
 \brief 设置肤色增强
 \attention \n
  无

 \param[in] enFleshToneLevel，参考HI_COLOR_GAIN_E

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetFleshTone( HI_UNF_PQ_FLESHTONE_E enFleshToneLevel);

/**
 \brief 获取六基色类型
 \attention \n
  无

 \param[out] pu32SixBaseColor

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetSixBaseColor(HI_U32 *pu32SixBaseColor);

/**
 \brief 设置六基色类型
 \attention \n
  无

 \param[in] enSixBaseColor

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetSixBaseColor( HI_UNF_PQ_SIX_BASE_COLOR_E enSixBaseColor);

/**
 \brief 获取静态背光强度
 \attention \n
无

 \param[in] none
 \param[out] pu32BackLightLevel

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetBackLight(HI_U32 *pu32BackLightLevel);

/**
 \brief 设置静态背光强度
 \attention \n
无

 \param[in] u32BackLightLevel

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetBackLight(HI_U32 u32BackLightLevel);

/**
 \brief 获取3D Sharpen模式
 \attention \n
无

 \param[out] *pu32OnOff

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_Get3DSharpen(HI_U32 *pu32OnOff);

/**
 \brief 设置3D Sharpen模式
 \attention \n
无

 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_Set3DSharpen(HI_U32 u32OnOff);

/**
 \brief Gamma Table中可能存在多组Gamma曲线,用户可获取Gamma曲线数量; (扩展接口)
 \attention \n
无

 \param[out] *s32Num: Gamma曲线的数量;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetGammaNum(HI_S32 *ps32Num);

/**
 \brief 设置Gamma
 \attention \n
无

 \param[in] s32GammaIndex: Gamma曲线的索引值;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetGamma(HI_S32 s32GammaIndex);

/**
 \brief 设置PQ模块开关
 \attention \n
  无

 \param[in] enFlags
 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 HI_MPI_PQ_SetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 u32OnOff);

/**
 \brief 获取PQ模块开关
 \attention \n
  无

 \param[in] enFlags
 \param[in] pu32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief 获取卖场模式开关
 \attention \n
  无

 \param[in] enFlags
 \param[in] pu32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief 设置卖场模式开关
 \attention \n
无

 \param[in] enFlags
 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 HI_MPI_PQ_SetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 u32OnOff);

/**
 \brief 设置PQ寄存器
 \attention \n
无

 \param[in] u32RegAddr
 \param[in] u32Data

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_WritePQRegister(HI_U32 u32RegAddr,HI_U32 u32Data);

/**
 \brief 获取PQ寄存器
 \attention \n
无

 \param[in] u32RegAddr
 \param[in] *pu32Value

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_ReadPQRegister(HI_U32 u32RegAddr, HI_U32 *pu32Value);

/**
 \brief 获取GAMMA曲线
 \attention \n
  无

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetGammaTable( HI_PQ_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief 设置GAMMA曲线
 \attention \n
  无

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetGammaTable( HI_PQ_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief 获取ACM曲线
 \attention \n
  无

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetAcmTable( MPI_COLOR_PARAM_S *pstColorTable);

/**
 \brief 设置ACM曲线
 \attention \n
  无

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetAcmTable( MPI_COLOR_PARAM_S *pstColorTable);

/**
 \brief 获取DCI曲线
 \attention \n
  无

 \param[in] *pstDCITable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDciTable( HI_PQ_DCI_WGT_S *pstDCITable);

/**
 \brief 设置DCI曲线
 \attention \n
  无

 \param[in] *pstDCITable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDciTable( HI_PQ_DCI_WGT_S *pstDCITable);

/**
 \brief 获取DCI直方图
 \attention \n
  无

 \param[in] *pstDCIHistgram

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetHistgram( HI_PQ_DCI_HISTGRAM_S *pstDCIHistgram);

/**
 \brief 获取DCI最终调整曲线
 \attention \n
  无

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDciFinalLut( HI_PQ_DCI_FINAL_LUT_S *pstData);

/**
 \brief 获取DIM曲线
 \attention \n
  无

 \param[in] *pstDIMTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDimTable( HI_PQ_DIM_LUT_S *pstDIMTable);

/**
 \brief 设置DIM曲线
 \attention \n
  无

 \param[in] *pstDIMTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDimTable( HI_PQ_DIM_LUT_S *pstDIMTable);

/**
 \brief 获取TNR的亮度PixMean-to-Ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的亮度PixMean-to-Ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);


/**
 \brief 获取TNR的色度PixMean-to-Ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的色度PixMean-to-Ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);


/**
 \brief 获取TNR的亮度MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的亮度MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief 获取TNR的色度MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的色度MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief 获取TNR的亮度FINAL MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的亮度FINAL MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief 获取TNR的色度FINAL MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 设置TNR的色度FINAL MotionMapping曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief 获取SNR的pixmean-ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetSNRPixmean2Ratio( HI_PQ_SNR_PIXMEAN_2_RATIO_S *pstSnrData);

/**
 \brief 设置SNR的pixmean-ratio曲线
 \attention \n
  无

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSNRPixmean2Ratio( HI_PQ_SNR_PIXMEAN_2_RATIO_S *pstSnrData);

/**
 \brief 获取SNR的pixdiff-edgestr曲线
 \attention \n
  无

 \param[in] *pstSnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetSNRPixdiff2Edgestr( HI_PQ_SNR_PIXDIFF_2_EDGESTR_S *pstSnrData);

/**
 \brief 设置SNR的pixdiff-edgestr曲线
 \attention \n
  无

 \param[in] *pstSnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSNRPixdiff2Edgestr( HI_PQ_SNR_PIXDIFF_2_EDGESTR_S *pstSnrData);

/**
 \brief 获取CSC的系数
 \attention \n
  无

 \param[in] *pstCscData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetCSCCoef( HI_PQ_CSC_S *pstCscData);

/**
 \brief 设置CSC的系数
 \attention \n
  无

 \param[in] *pstCscData

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetCSCCoef( HI_PQ_CSC_S *pstCscData);

/**
 \brief 获取PFMD的可调参数
 \attention \n
  无

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */
HI_S32 HI_MPI_PQ_GetPfmdParam( HI_PQ_PFMD_DBG_S *pstData);

/**
 \brief 设置PFMD的可调参数
 \attention \n
  无

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetPfmdParam( HI_PQ_PFMD_DBG_S *pstData);

//****Sharpeness AdpGain 对外读写参数接口*/
HI_S32 HI_MPI_PQ_SetSharpAdpGainParam(HI_PQ_SHARPEN_TABLE_S *pstData);

HI_S32 HI_MPI_PQ_GetSharpAdpGainParam(HI_PQ_SHARPEN_TABLE_S *pstData);

HI_S32 HI_MPI_PQ_SetDciWeightParam(HI_PQ_DCI_WEIGHT_S *pstData);
HI_S32 HI_MPI_PQ_GetDciWeightParam(HI_PQ_DCI_WEIGHT_S *pstData);

HI_S32 HI_MPI_PQ_SetWhiteBalanceParam(MPI_WHITE_BALANCE_PARAM_S *pstData);
HI_S32 HI_MPI_PQ_GetWhiteBalanceParam(MPI_WHITE_BALANCE_PARAM_S *pstData);

HI_S32 HI_MPI_PQ_GetSharpenYvalueParam(HI_PQ_SHARPEN_YRATIO_S *pstData);
HI_S32 HI_MPI_PQ_SetSharpenYvalueParam(HI_PQ_SHARPEN_YRATIO_S *pstData);

HI_S32 HI_MPI_PQ_GetTnrFmotionMapping(HI_PQ_TNR_FMOTION_MAPPING_S *pstData);
HI_S32 HI_MPI_PQ_SetTnrFmotionMapping(HI_PQ_TNR_FMOTION_MAPPING_S *pstData);

HI_S32 HI_MPI_PQ_Get2DDimming(HI_PQ_DIM_LUT_S *pstData);
HI_S32 HI_MPI_PQ_Set2DDimming(HI_PQ_DIM_LUT_S *pstData);

//获取自动参考修改TNR FMotion  接口
HI_S32 HI_MPI_PQ_GetAutoFMotion(HI_U32 *pstData);
HI_S32 HI_MPI_PQ_SetAutoFMotion(HI_U32 *pstData);

HI_S32 HI_MPI_PQ_GetAutoNR(HI_U32 *pu32Data);
HI_S32 HI_MPI_PQ_SetAutoNR(HI_U32 *pu32Data);

//av500新增Sharpen   界面调节曲线
HI_S32 HI_MPI_Get4KSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);
HI_S32 HI_MPI_Set4KSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);

HI_S32 HI_MPI_GetFHDSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);
HI_S32 HI_MPI_SetFHDSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);

//设置多套Gamma曲线的Index
HI_S32 HI_MPI_PQ_SetGammaIndex(HI_U32 pu32Data);
HI_S32 HI_MPI_PQ_GetGammaIndex(HI_U32 *pu32Data);

//设置高级清晰度增益
HI_S32 HI_MPI_PQ_SetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_GetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstData);


//设置多套acm曲线的Gain
HI_S32 HI_MPI_PQ_GetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_SetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pu32Data);

//设置多套dci曲线的Gain
HI_S32 HI_MPI_PQ_GetDciGain(HI_UNF_PQ_DCI_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_SetDciGain(HI_UNF_PQ_DCI_GAIN_S *pu32Data);

//强制设置场序
HI_S32 HI_MPI_PQ_GetFieldOrderMode(HI_U32 *u32FieldOrderMode);
HI_S32 HI_MPI_PQ_SetFieldOrderMode(HI_U32 u32FieldOrderMode);

//????HDR ???
HI_S32 HI_MPI_PQ_SetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
HI_S32 HI_MPI_PQ_GetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);

//?????HDR ??
HI_S32 HI_MPI_PQ_GetHdrInfo(HI_UNF_PQ_HDR_INFO_S  *pstHdrInfo);

//设置分段色调下的饱和度
HI_S32 HI_MPI_PQ_SetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

//获取分段色调下的饱和度
HI_S32 HI_MPI_PQ_GetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

//设置分段色调下的色调增益
HI_S32 HI_MPI_PQ_SetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

//获取分段色调下的色调增益
HI_S32 HI_MPI_PQ_GetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

//设置分段色调下的亮度
HI_S32 HI_MPI_PQ_SetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

//获取分段色调下的亮度
HI_S32 HI_MPI_PQ_GetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

//设置CTI Gain
HI_S32 HI_MPI_PQ_SetCtiGain(HI_U32 u32CtiGain);

//获取CTI Gain
HI_S32 HI_MPI_PQ_GetCtiGain(HI_U32 *pu32CtiGain);

//设置NR STR
HI_S32 HI_MPI_PQ_SetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

//获取NR STR
HI_S32 HI_MPI_PQ_GetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

//获取背光统计值
HI_S32 HI_MPI_PQ_GetAvgRGBMax(HI_U32 *pu32AvgRgbMax);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_MPI_PQ_H__ */



