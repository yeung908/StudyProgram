/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_pq.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/15
  Description   : 
******************************************************************************/

#ifndef __HI_DRV_PQ_H__
#define __HI_DRV_PQ_H__

#include <linux/ioctl.h>
#include "hi_module.h"

#include "hi_type.h"
#include "hi_debug.h"
#include "hi_drv_video.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */


#define HI_FATAL_PQ(fmt...) HI_TRACE(HI_LOG_LEVEL_FATAL, HI_ID_PQ, fmt)
#define HI_ERR_PQ(fmt...)   HI_TRACE(HI_LOG_LEVEL_ERROR, HI_ID_PQ, fmt)
#define HI_WARN_PQ(fmt...)  HI_TRACE(HI_LOG_LEVEL_WARNING, HI_ID_PQ, fmt)
#define HI_INFO_PQ(fmt...)  HI_TRACE(HI_LOG_LEVEL_INFO, HI_ID_PQ, fmt)
#define HI_DEBUG_PQ(fmt...) HI_TRACE(HI_LOG_LEVEL_ERROR, HI_ID_PQ, fmt)

#define GAMMA_NUM 257
#define SDK_CSC_COLOR_TEMP 1

/* 卖场模式 */
typedef enum hiPQ_DEMO_E
{
     HI_PQ_DEMO_DBDR,
     HI_PQ_DEMO_NR,
     HI_PQ_DEMO_SHARPNESS,
     HI_PQ_DEMO_DCI,
     HI_PQ_DEMO_WCG,
    // HI_PQ_DEMO_FRC,
     HI_PQ_DEMO_COLOR,
     HI_PQ_DEMO_SR,
     HI_PQ_DEMO_ALL,

     HI_PQ_DEMO_BUTT
}  HI_PQ_DEMO_E;

/* PQ模块*/
typedef enum hiHIPQ_MODULE_E
{
     HI_PQ_MODULE_FMD = 0,
     HI_PQ_MODULE_TNR,
     HI_PQ_MODULE_SNR,
     HI_PQ_MODULE_DB,
     HI_PQ_MODULE_DR,
     HI_PQ_MODULE_HSHARPNESS,
     HI_PQ_MODULE_SHARPNESS,
     HI_PQ_MODULE_CCCL,
     HI_PQ_MODULE_COLOR_CORING,
     HI_PQ_MODULE_BLUE_STRETCH,
     HI_PQ_MODULE_GAMMA,
     HI_PQ_MODULE_DBC,
     HI_PQ_MODULE_DCI,
     HI_PQ_MODULE_COLOR,
     HI_PQ_MODULE_ES,
     HI_PQ_MODULE_SR,
     HI_PQ_MODULE_FRC,
     HI_PQ_MODULE_WCG,
     HI_PQ_MODULE_HDR,
     HI_PQ_MODULE_DCI_ALG,

     HI_PQ_MODULE_BUTT
}  HI_PQ_MODULE_E;

/*肤色增益类型*/
typedef enum hiPQ_FLESHTONE_E
{
     HI_PQ_FLESHTONE_GAIN_OFF = 0,
     HI_PQ_FLESHTONE_GAIN_LOW,
     HI_PQ_FLESHTONE_GAIN_MID,
     HI_PQ_FLESHTONE_GAIN_HIGH,

     HI_PQ_FLESHTONE_GAIN_BUTT
}  HI_PQ_FLESHTONE_E;

/*六基色演示类型*/
typedef enum hiPQ_SIX_BASE_COLOR_E
{
    HI_PQ_SIX_BASE_COLOR_ALL_ON = 0,
    HI_PQ_SIX_BASE_COLOR_R_OFF,//红
    HI_PQ_SIX_BASE_COLOR_G_OFF,//绿
    HI_PQ_SIX_BASE_COLOR_B_OFF,//蓝
    HI_PQ_SIX_BASE_COLOR_CYAN_OFF,//青
    HI_PQ_SIX_BASE_COLOR_MAGENTA_OFF,//紫
    HI_PQ_SIX_BASE_COLOR_YELLOW_OFF,//黄
    HI_PQ_SIX_BASE_COLOR_RGB_OFF,//红绿蓝
    HI_PQ_SIX_BASE_COLOR_CMY_OFF,//青紫黄
    HI_PQ_SIX_BASE_COLOR_ALL_OFF,
    HI_PQ_SIX_BASE_COLOR_BUTT
} HI_PQ_SIX_BASE_COLOR_E;

/*pq 颜色分段*/
typedef enum hiPQ_COLOR_E
{
    HI_PQ_COLOR_R,//红
    HI_PQ_COLOR_G,//绿
    HI_PQ_COLOR_B,//蓝
    HI_PQ_COLOR_CYAN,//青
    HI_PQ_COLOR_PURPLE,//紫
    HI_PQ_COLOR_YELLOW,//黄
	HI_PQ_COLOR_FLESH,//肤色

    HI_PQ_COLOR_BUTT
} HI_PQ_COLOR_E;


/* 分段色调进行饱和度增强结构体 */
typedef struct hiPQ_COLOR_SECTION_SATGAIN_S
{
	HI_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_PQ_COLOR_SECTION_SATGAIN_S;

/* 分段色调进行色调增强结构体 */
typedef struct hiPQ_COLOR_SECTION_HUEGAIN_S
{
	HI_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_PQ_COLOR_SECTION_HUEGAIN_S;

/* 分段色调进行亮度增强结构体 */
typedef struct hiPQ_COLOR_SECTION_BRIGAIN_S
{
	HI_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_PQ_COLOR_SECTION_BRIGAIN_S;

/*NR  str type Y/C*/
typedef enum hiPQ_NR_TMK_E
{
     HI_PQ_NR_TMK_Y = 0,
     HI_PQ_NR_TMK_C,

	 HI_PQ_NR_TMK_BUTT

} HI_PQ_NR_TMK_E;

typedef struct hiPQ_NR_TMK_S
{
	HI_PQ_NR_TMK_E enNRTmk;
	HI_U32 u32Gain;
}HI_PQ_NR_TMK_S;

/*色温设定*/
typedef struct hiPQ_COLOR_TEMP_S
{
    HI_S16 s16RedGain;
    HI_S16 s16GreenGain;
    HI_S16 s16BlueGain;
    HI_S16 s16RedOffset;
    HI_S16 s16GreenOffset;
    HI_S16 s16BlueOffset;
}  HI_PQ_COLOR_TEMP_S;

/*ACM 表类型*/
typedef enum hiPQ_COLOR_TYPE_E
{
    HI_PQ_COLOR_NORMAL =0,
    HI_PQ_COLOR_VIVID,
    HI_PQ_COLOR_HDR,
    HI_PQ_COLOR_TYPE_1 =3,
    HI_PQ_COLOR_TYPE_2 =4,
    HI_PQ_COLOR_TYPE_3 =5,
    HI_PQ_COLOR_TYPE_4 =6,
    HI_PQ_COLOR_TYPE_5 =7,

    HI_PQ_COLOR_TYPE_BUTT
} HI_PQ_COLOR_TYPE_E;


/*PQ文件路径*/
typedef struct hiPQ_PATH_S
{
    HI_CHAR cPqPath[128];
}HI_PQ_PATE_S;

/*
 * CSC属性
 */
 /*
typedef struct  hiPQ_CSC_S
{
    HI_BOOL  bVPCSCEn;
    HI_PQ_CSC_MODE_E  enVPCSC;
} HI_PQ_CSC_S;
*/

/*
 * 模块开关属性
 */
typedef struct hiPQ_MODULE_S
{
    HI_PQ_MODULE_E enModule;
    HI_U32 u32OnOff; /*开关*/
} HI_PQ_MODULE_S;

/*
 * 卖场模式属性
 */
typedef struct hiPQ_DEMO_S
{
    HI_PQ_DEMO_E enModule;
    HI_BOOL bOnOff; /*开关*/
} HI_PQ_DEMO_S;

/*
 * 寄存器属性
 */
typedef struct hiPQ_REGISTER_S
{
    HI_U32  u32RegAddr;   /*寄存器 地址*/
    HI_U32  u32RegValue;   /*寄存器值*/
} HI_PQ_REGISTER_S;

/*gamma结构*/
typedef struct PQ_GAMMA_TABLE_S
{
    HI_U16 au16R[GAMMA_NUM];
    HI_U16 au16G[GAMMA_NUM];
    HI_U16 au16B[GAMMA_NUM];
    HI_U16   u16Reserve;
} HI_PQ_GAMMA_TABLE_S;

/*GAIN参数结构*/
typedef struct hiPQ_COLOR_GAIN_S
{
    HI_U16 u16Stretch;
    HI_U16 u16ClipRange;
    HI_U16 u16HueGain;      
    HI_U16 u16SatGain;        
    HI_U16 u16LumaGain;    
    HI_U16 u16CbCrThre;     
} HI_PQ_COLOR_GAIN_S;

/*luma table结构*/
typedef struct hiPQ_COLOR_LUMA_S
{
    HI_S16 as16Luma[9][13][29]; /*Luma查找表*/
} HI_PQ_COLOR_LUMA_S;

/*HUE table结构*/
typedef struct hiPQ_COLOR_HUE_S
{
    HI_S16 as16Hue[9][13][29];  /*Hue查找表*/
} HI_PQ_COLOR_HUE_S;

/*SAT table结构*/
typedef struct hiPQ_COLOR_SAT_S
{
    HI_S16 as16Sat[9][13][29];  /*Saturation查找表*/
} HI_PQ_COLOR_SAT_S;

/*Color 主表结构*/
typedef struct hiPQ_YHSBYH_S
{
    HI_S16 as16YHSbyH[3][29];           /*YbyH[29],    HbyH[]29,    SbyH[29]     delta  curve*/
} HI_PQ_YHSBYH_S;

/*Color Sat Gain附表结构*/
typedef struct hiPQ_SAT_GAIN_S
{
    HI_S16 as16YHSbyHSgain[3][29][13];  /*YbyH[29][13],HbyH[29][13],SbyH[29][13] S gain curve*/
} HI_PQ_SAT_GAIN_S;

/*Color Y Gain附表结构*/
typedef struct hiPQ_Y_GAIN_S
{
    HI_S16 as16YHSbyHYgain[3][29][9];   /*YbyH[29][9], HbyH[29][9], SbyH[29][9]  Y gain curve*/
} HI_PQ_Y_GAIN_S;

/*DCI曲线配置表*/
typedef struct hiPQ_DCI_WGT_S
{
    HI_S16 s16WgtCoef0[33];
    HI_S16 s16WgtCoef1[33];
    HI_S16 s16WgtCoef2[33];
    HI_U16 u16Gain0;
    HI_U16 u16Gain1;
    HI_U16 u16Gain2;
}HI_PQ_DCI_WGT_S;

/*DCI直方图结构*/
typedef struct hiPQ_DCI_HISTGRAM_S
{
    HI_S32 s32HistGram[32];
}HI_PQ_DCI_HISTGRAM_S;

/*DCI最终权重曲线*/
typedef struct hiPQ_DCI_FINAL_LUT_S
{
    HI_S32 s32AdjLUT[33];
}HI_PQ_DCI_FINAL_LUT_S;

/*DIM 曲线*/
typedef struct hiPQ_DIM_LUT_S
{
    //HI_U32     u32CoreLow;
    //HI_U32     u32CoreMid;
    //HI_U32     u32CoreHigh;
        
    HI_U32     u32X0Low;   //0D bin0统计结果分段调整阈值0
    HI_U32     u32X1Low;
    HI_U32     u32X2Low;
    HI_U32     u32X0Mid;
    HI_U32     u32X1Mid;
    HI_U32     u32X2Mid;
    HI_U32     u32X0High;
    HI_U32     u32X1High;
    HI_U32     u32X2High;
    
    HI_U32     u32G0Low;   //0D bin统计结果调整偏置0
    HI_U32     u32G1Low;
    HI_U32     u32G2Low;
    HI_U32     u32G3Low;
    HI_U32     u32G0Mid;
    HI_U32     u32G1Mid;
    HI_U32     u32G2Mid;
    HI_U32     u32G3Mid;
    HI_U32     u32G0High;
    HI_U32     u32G1High;
    HI_U32     u32G2High;
    HI_U32     u32G3High;
    
    HI_U32     u32K0Low;    //0D bin0统计结果调整增益0
    HI_U32     u32K1Low;
    HI_U32     u32K2Low;
    HI_U32     u32K3Low;
    HI_U32     u32K0Mid;
    HI_U32     u32K1Mid;
    HI_U32     u32K2Mid;
    HI_U32     u32K3Mid;
    HI_U32     u32K0High;
    HI_U32     u32K1High;
    HI_U32     u32K2High;
    HI_U32     u32K3High;
}HI_PQ_DIM_LUT_S;

/*TNR通用结构*/
typedef struct hiPQ_TNR_S
{
	HI_S32 s32MappingMax;   
	HI_S32 s32MappingMin;    
	HI_S32 s32MappingR[5];
	HI_S32 s32MappingT[6];	
	HI_S32 s32MappingK[4];
}HI_PQ_TNR_S;

//******Sharpen AdpGain   结构******************//
typedef struct hiPQ_SHARPEN_S
{
	HI_U16 u16AdpGainGrid0;
    HI_U16 u16AdpGainGrid1;
   
    HI_U16 u16AdpGainGrid2;
    HI_U16 u16AdpGainGrid3;

    HI_S16 s16AdpGainK1;
    HI_S16 s16AdpGainK2;

    HI_S16 GAdpGainMinL;
    HI_S16 GAdpGainMinH;
   
    HI_S16 GAdpGainMax;
    HI_S16 Reserved;
}HI_PQ_SHARPEN_S;

#if defined(CHIP_TYPE_hi3751v600)||defined(CHIP_TYPE_hi3751lv500)
typedef struct hiPQ_SHARPEN_TABLE_S
{
	HI_PQ_SHARPEN_S CurveH1;
    HI_PQ_SHARPEN_S CurveH2;
    HI_PQ_SHARPEN_S CurveH3;
    HI_PQ_SHARPEN_S CurveH4;
    HI_PQ_SHARPEN_S CurveV1;
    HI_PQ_SHARPEN_S CurveV2;
    HI_PQ_SHARPEN_S CurveV3;
    HI_PQ_SHARPEN_S CurveD1;
    HI_PQ_SHARPEN_S CurveD2;
    HI_PQ_SHARPEN_S CurveD3;
}HI_PQ_SHARPEN_TABLE_S;
#endif

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
typedef struct hiPQ_SHARPEN_TABLE_S
{
    HI_PQ_SHARPEN_S CurveFHD;
	HI_PQ_SHARPEN_S Curve4K;
}HI_PQ_SHARPEN_TABLE_S;
#endif

//******Sharpen Limit Ctrl   结构******************//
typedef struct hiPQ_SHARPEN_LIMITLUT_S
{
	HI_S16   s16LimPos0;
    HI_S16   s16LimPos1; 
	
    HI_S16   s16LimNeg0;
    HI_S16   s16LimNeg1;

    HI_S16   s16LimitRatio;
    HI_S16  s16BoundPos;
    HI_S16  s16BoundNeg;
	HI_S16  s16Reserved;

}HI_PQ_SHARPEN_LIMITLUT_S;

typedef struct hiPQ_SHARPEN_LIMITLUT_GROUP_S
{
    HI_PQ_SHARPEN_LIMITLUT_S CurveH1;
    HI_PQ_SHARPEN_LIMITLUT_S CurveH2;
    HI_PQ_SHARPEN_LIMITLUT_S CurveH3;
    HI_PQ_SHARPEN_LIMITLUT_S CurveV1;
    HI_PQ_SHARPEN_LIMITLUT_S CurveV2;
    HI_PQ_SHARPEN_LIMITLUT_S CurveD1;
    HI_PQ_SHARPEN_LIMITLUT_S CurveD2;
    HI_PQ_SHARPEN_LIMITLUT_S CurveD3;
}HI_PQ_SHARPEN_LIMITLUT_GROUP_S;

/*SNR的pixmean-ratio结构*/
typedef struct hiPQ_SNR_PIXMEAN_2_RATIO_S
{
    HI_U8 u8EdgeMaxRatio;  
    HI_U8 u8EdgeMinRatio;  
    HI_U8 u8EdgeOriRatio;    
    HI_U8 u8Reserve;             
    HI_U16 u16EdgeMeanTh[8];   
    HI_U8 u8EdgeMeanK[8];         
    HI_U16 u16PixMeanRatio[8]; 
}HI_PQ_SNR_PIXMEAN_2_RATIO_S;

/*SNR 的pixdiff-edgestr结构*/
typedef struct hiPQ_SNR_PIXDIFF_2_EDGESTR_S
{
    HI_U8 u8EdgeOriStrength;     
    HI_U8 u8EdgeMaxStrength;   
    HI_U8 u8EdgeMinStrength;   
    HI_U8 u8Reserve1;            
    HI_U16 u16EdgeStrTh[3]; 
    HI_U16 u16Reserve2;        
    HI_U8 u8EdgeStrK[3];       
    HI_U8 u8Reserve3;            
    HI_U8 u8EdgeStr[3];    
    HI_U8 u8Reserve4;       
}HI_PQ_SNR_PIXDIFF_2_EDGESTR_S;

/*PQ工具调试可用参数*/
typedef struct hiPQ_PFMD_DBG_S
{	
  HI_S32  s32FilmDetectionEn[9];//开关   
  HI_S32  s32PMODE_COUNTER_THRD[2][9];//入锁阈值
  HI_S32  s32PMODE_UNLOCKCOUNTER_THRD[2][9]; //退锁阈值
}HI_PQ_PFMD_DBG_S;


typedef struct
{
    HI_U16 PixValAdjGain;
    HI_U16 HFVarCore;
    HI_U16 HFVarGain1;
    HI_U16 HFVarGain2;
    HI_U16 BordAdjGain;
    HI_U16 GradSubRatio;
    HI_U16 SWPixValAdjGain;
    HI_U16 SWHFVarCore;
    HI_U16 SWHFVarGain1;
    HI_U16 SWHFVarGain2;
    //HI_U16 HFDiffCore;
    //HI_U16 HFDiffGain1;
   // HI_U16 HFDiffGain2;
} HI_PQ_DB_DynmcPara;


typedef struct hiPQ_DBM_DBG_S
{	
	HI_U32  u32NumberWindow;
	HI_U32  u32KeyFrm;
	HI_U32  u32FrmWinTemp;
	HI_U32  u32FrmSatWinTemp;
	HI_U32  u32MinBlkNumHy[4];
	HI_U32  u32MinBlkNumHc[4];
	HI_U32  u32MinBlkNumVy[4];
	HI_U32  u32BordCntThreshouldHy[4];
	HI_U32  u32BordCntThreshouldHc[4];
	HI_U32  u32BordCntThreshouldVy[4];

	HI_U32	u32DetSizeHy;
	HI_U32	u32CntBordHy;
	HI_U32	u32UseSizeHy;
	HI_U32	u32UseCntBordHy;

	HI_U32	u32DetSizeHc;
	HI_U32	u32CntBordHc;
	HI_U32	u32UseSizeHc;
	HI_U32	u32UseCntBordHc;

	HI_U32	u32DetSizeVy;
	HI_U32	u32CntBordVy;
	HI_U32	u32UseSizeVy;
	HI_U32	u32UseCntBordVy;
	
	HI_U8 u8DeltaLumStrong[16];	//LUMA_HOR p0-p15

       HI_U8 u8DeltaLumUltraStrong[16]; 

	HI_U8 u8FadeLut1[12];
	HI_U8 u8FadeLut1_sp[12];
	HI_U8 u8FadeLut2[12];
	HI_U8 u8FadeLut3[12];
	   
	//HI_U8 	u8MinBlkSize[4];
	//HI_U8 	u8HY_RtnBDTxt[4];
	//HI_U8 	u8HY_MaxBlkSize[4];
	//HI_U8 	u8HY_RDX8BinLut[4][7];
	HI_PQ_DB_DynmcPara stBDbFilterLut[9];
}HI_PQ_DBM_DBG_S;



/*CSC 系数结构*/
typedef struct hiPQ_CSC_PARAM_S
{
    HI_S32 csc_type;
    HI_S32 csc_coef00;//CSC系数...
    HI_S32 csc_coef01;
    HI_S32 csc_coef02;
    HI_S32 csc_coef10;
    HI_S32 csc_coef11;
    HI_S32 csc_coef12;
    HI_S32 csc_coef20;
    HI_S32 csc_coef21;
    HI_S32 csc_coef22;
    HI_S32 csc_in_dc0;
    HI_S32 csc_in_dc1;
    HI_S32 csc_in_dc2;
    HI_S32 csc_out_dc0;
    HI_S32 csc_out_dc1;
    HI_S32 csc_out_dc2;
}HI_PQ_CSC_PARAM_S;

/*CSC 结构*/
typedef struct hiPQ_CSC_S
{
    HI_PQ_CSC_PARAM_S stCSCCoef[3];//0:V0,1:V1,2:VP   对于AV500: 0:V0,1:V0_PIC,2:VP ;
}HI_PQ_CSC_S;

/*SR演示模式*/
typedef enum hiPQ_SR_DEMO_E
{
     HI_PQ_SR_DISABLE  = 0,//关掉SR,只ZME
     HI_PQ_SR_ENABLE_R,  //  右边SR
     HI_PQ_SR_ENABLE_L,  //左边SR
     HI_PQ_SR_ENABLE_A,  //全屏

     HI_PQ_SR_DEMO_BUTT
}HI_PQ_SR_DEMO_E;

/**** DCI 内部weight 调试曲线 ****/
typedef struct hiPQ_DCI_WEIGHT_S
{
   HI_S16 s16LowWeightLUT[32];
   HI_S16 s16MiddleWeightLUT[32];
   HI_S16 s16HighWeightLUT[32];
}HI_PQ_DCI_WEIGHT_S;

/* Sharpen μ?YValue-Ratio ?ú??  */
typedef struct hiPQ_SHARPEN_YRATIO_S
{
   HI_U16 u16sharpen_yratio_thr0;
   HI_U16 u16sharpen_yratio_thr1;
   HI_U16 u16sharpen_yratio_thr2;
   HI_U16 u16sharpen_yratio_thr3;
   HI_U16 u16sharpen_yratio_slp1;
   HI_U16 u16sharpen_yratio_slp2;
}HI_PQ_SHARPEN_YRATIO_S;

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
typedef struct hiPQ_SHARPEN_YRATIOGROUP_S
{
   HI_PQ_SHARPEN_YRATIO_S Curvefhd;
   HI_PQ_SHARPEN_YRATIO_S Curve4k;
   
}HI_PQ_SHARPEN_YRATIOGROUP_S;
#endif

typedef struct hiPQ_SHARPEN_GAIN_S
{
    HI_U32 u32LtiGain;
    HI_U32 u32HPeakRatio;
    HI_U32 u32VPeakRatio;
    HI_U32 u32DPeakRatio;
}HI_PQ_SHARPEN_GAIN_S;

/**Color GAIN*//**CNcomment:Color   增益*/
typedef struct hiPQ_ACM_GAIN_S
{
	HI_U32 u16LumGain;
	HI_U32 u16HueGain;
	HI_U32 u16SatGain;
	HI_U32 u16Reserved;
}HI_PQ_ACM_GAIN_S;

/**Color GAIN*//**CNcomment:Color   增益*/
typedef struct hiPQ_DCI_GAIN_S
{
	HI_U32 u16LowGain;
	HI_U32 u16MiddleGain;
	HI_U32 u16HighGain;
	HI_U32 u16Reserved;
}HI_PQ_DCI_GAIN_S;

typedef struct hiDRV_PQ_HDR_INFO_S
{
	HI_DRV_COLOR_SPACE_E    	eColorSpace;	
    HI_DRV_GAMMA_TYPE_E     	eGammaType;
    HI_DRV_VIDEO_HDR10_METADATA_STREAM_S stMetadata;
} HI_DRV_PQ_HDR_INFO_S;

/* HDR FIXMODE*//**CNcomment:FIXMODE  信息*/
typedef struct hiDRV_PQ_HDR_FIXMODE_S
{  
   HI_BOOL bFixed;
   HI_DRV_PQ_HDR_INFO_S stHdrInfo;   
}HI_DRV_PQ_HDR_FIXMODE_S;


/* TNR ??ó|μ?FMtion- Mapping?ú?? */
typedef struct hiPQ_TNR_FMOTION_MAPPING_S
{
   HI_S16 s16YFmotion[32];
   HI_S16 s16CFmotion[32];
}HI_PQ_TNR_FMOTION_MAPPING_S;

/*ó??§?ó?ú*/
#define HIIOC_PQ_S_COLORTEMP            				_IOW(HI_ID_PQ, 1, HI_PQ_COLOR_TEMP_S)        			 		/* 设置色温参数*/
#define HIIOC_PQ_G_COLORTEMP       			 			_IOR(HI_ID_PQ, 2, HI_PQ_COLOR_TEMP_S)             				/* 获取色温参数*/

#define HIIOC_PQ_S_BRIGHTNESS       					_IOW(HI_ID_PQ, 3, HI_U32)         								/* 设置BRIGHTNESS level*/
#define HIIOC_PQ_G_BRIGHTNESS        					_IOR(HI_ID_PQ, 4, HI_U32)             							/* 获取BRIGHTNESS level*/

#define HIIOC_PQ_S_CONTRAST       						_IOW(HI_ID_PQ, 5, HI_U32)         								/* 设置CONTRAST level*/
#define HIIOC_PQ_G_CONTRAST        						_IOR(HI_ID_PQ, 6, HI_U32)             							/* 获取CONTRAST level*/

#define HIIOC_PQ_S_SATURATION       					_IOW(HI_ID_PQ, 7, HI_U32)         								/* 设置SATURATION level*/
#define HIIOC_PQ_G_SATURATION        					_IOR(HI_ID_PQ, 8, HI_U32)             							/* 获取SATURATION level*/

#define HIIOC_PQ_S_HUE       							_IOW(HI_ID_PQ, 9, HI_U32)         								/* 设置HUE level*/
#define HIIOC_PQ_G_HUE        							_IOR(HI_ID_PQ, 10, HI_U32)             							/* 获取HUE level*/

#define HIIOC_PQ_S_NR       							_IOW(HI_ID_PQ, 11, HI_U32)         								/* 设置NR level*/
#define HIIOC_PQ_G_NR        							_IOR(HI_ID_PQ, 12, HI_U32)             							/* 获取NR level*/

#define HIIOC_PQ_S_SHARPNESS            				_IOW(HI_ID_PQ, 13, HI_U32)         								/* 设置SHARPNESS level*/
#define HIIOC_PQ_G_SHARPNESS          	 				_IOR(HI_ID_PQ, 14, HI_U32)             							/* 获取SHARPNESS level*/

#define HIIOC_PQ_S_DB            						_IOW(HI_ID_PQ, 15, HI_U32)         								/* 设置De-blocking level*/
#define HIIOC_PQ_G_DB           						_IOR(HI_ID_PQ, 16, HI_U32)             							/* 获取De-blocking level*/

#define HIIOC_PQ_S_DR            						_IOW(HI_ID_PQ, 17, HI_U32)         								/* 设置De-Ring level*/
#define HIIOC_PQ_G_DR           						_IOR(HI_ID_PQ, 18, HI_U32)             							/* 获取De-Ring level*/

#define HIIOC_PQ_S_COLOR_TYPE            				_IOW(HI_ID_PQ, 19, HI_PQ_COLOR_TYPE_E)         								/* 设置Color gain level*/
#define HIIOC_PQ_G_COLOR_TYPE           				_IOR(HI_ID_PQ, 20, HI_PQ_COLOR_TYPE_E)             							/* 获取Color gain level*/

#define HIIOC_PQ_S_FLESHTONE            				_IOW(HI_ID_PQ, 21, HI_PQ_FLESHTONE_E)         					/* 设置FleshTone level*/
#define HIIOC_PQ_G_FLESHTONE           					_IOR(HI_ID_PQ, 22, HI_PQ_FLESHTONE_E)             				/* 获取FleshTone level*/

#define HIIOC_PQ_S_BACKLIGHT            				_IOW(HI_ID_PQ, 23, HI_U32)         								/* 设置BackLight level*/
#define HIIOC_PQ_G_BACKLIGHT           					_IOR(HI_ID_PQ, 24, HI_U32)             							/* 获取BackLight level*/

#define HIIOC_PQ_S_GAMMAIDX            					_IOW(HI_ID_PQ, 25, HI_S32)         								/* 设置GAMMA index*/
#define HIIOC_PQ_G_GAMMANUM           					_IOR(HI_ID_PQ, 26, HI_S32)            					 		/* 获取GAMMA num*/

#define HIIOC_PQ_S_MODULE            					_IOW(HI_ID_PQ, 27, HI_PQ_MODULE_S)         						/* 设置各算法模块开关*/
#define HIIOC_PQ_G_MODULE           					_IOWR(HI_ID_PQ, 28, HI_PQ_MODULE_S)             				/* 获取各算法模块开关*/

#define HIIOC_PQ_S_DEMO            						_IOW(HI_ID_PQ, 29, HI_PQ_DEMO_S)         						/* 设置各算法模块卖场模式开关*/
#define HIIOC_PQ_G_DEMO            						_IOWR(HI_ID_PQ, 37, HI_PQ_DEMO_S)         						/* 获取各算法模块卖场模式开关*/

#define HIIOC_PQ_S_SIXBASECOLOR            				_IOW(HI_ID_PQ, 30, HI_PQ_SIX_BASE_COLOR_E)         				/* 设置 六基色类型*/
#define HIIOC_PQ_G_SIXBASECOLOR          				_IOR(HI_ID_PQ, 31, HI_PQ_SIX_BASE_COLOR_E)            			/* 获取六基色类型*/

#define HIIOC_PQ_S_PQ_PATH            					_IOW(HI_ID_PQ, 32, HI_PQ_PATE_S)         						/* 设置 PQ文件路径*/

#define HIIOC_PQ_S_NR_AUTO            					_IOW(HI_ID_PQ, 33, HI_U32)         								/* 设置NR自动模式*/
#define HIIOC_PQ_G_NR_AUTO           					_IOR(HI_ID_PQ, 34, HI_U32)           							/* 获取NR自动模式*/

#define HIIOC_PQ_S_SR_DEMO            					_IOW(HI_ID_PQ, 35, HI_PQ_SR_DEMO_E)         					/* 设置SR演示模式*/
#define HIIOC_PQ_G_SR_DEMO           					_IOR(HI_ID_PQ, 36, HI_PQ_SR_DEMO_E)           					/* 获取SR演示模式*/

/*调试接口*/
#define HIIOC_PQ_S_3DSHARP            					_IOW(HI_ID_PQ, 40, HI_U32)         								/* 设置3D SHARP mode*/
#define HIIOC_PQ_G_3DSHARP           					_IOR(HI_ID_PQ, 41, HI_U32)           							/* 获取3D SHARP mode*/

#define HIIOC_PQ_S_CSC_COEF            					_IOW(HI_ID_PQ, 42, HI_PQ_CSC_S)         						/* 设置CSC 系数*/
#define HIIOC_PQ_G_CSC_COEF           					_IOR(HI_ID_PQ, 43, HI_PQ_CSC_S)           						/* 获取CSC 系数*/

#define HIIOC_PQ_S_REGISTER         					_IOW(HI_ID_PQ, 44, HI_PQ_REGISTER_S)							/* 写寄存器*/
#define HIIOC_PQ_G_REGISTER          					_IOWR(HI_ID_PQ, 45, HI_PQ_REGISTER_S)       					/*读寄存器*/

#define HIIOC_PQ_S_GAMMA         						_IOW(HI_ID_PQ, 46, HI_PQ_GAMMA_TABLE_S)							/* 写GAMMA曲线*/
#define HIIOC_PQ_G_GAMMA          						_IOR(HI_ID_PQ, 47, HI_PQ_GAMMA_TABLE_S)       					/*读GAMMA曲线*/

#define HIIOC_PQ_S_DCI        							_IOW(HI_ID_PQ, 48, HI_PQ_DCI_WGT_S)               				/*写DCI曲线*/
#define HIIOC_PQ_G_DCI      							_IOR(HI_ID_PQ, 49, HI_PQ_DCI_WGT_S)            					/*读DCI曲线*/  

#define HIIOC_PQ_S_ACM_GAIN         					_IOW(HI_ID_PQ, 50, HI_PQ_COLOR_GAIN_S)              			/*写COLOR GAIN曲线*/
#define HIIOC_PQ_G_ACM_GAIN      						_IOR(HI_ID_PQ, 51, HI_PQ_COLOR_GAIN_S)            				/*读COLOR GAIN曲线*/  

#define HIIOC_PQ_S_ACM_LUMA         					_IOW(HI_ID_PQ, 52, HI_PQ_COLOR_LUMA_S)               			/*写COLOR LUMA曲线*/
#define HIIOC_PQ_G_ACM_LUMA      						_IOR(HI_ID_PQ, 53, HI_PQ_COLOR_LUMA_S)           	 			/*读COLOR LUMA曲线*/  

#define HIIOC_PQ_S_ACM_HUE         						_IOW(HI_ID_PQ, 54, HI_PQ_COLOR_HUE_S)               			/*写COLOR HUE曲线*/
#define HIIOC_PQ_G_ACM_HUE      						_IOR(HI_ID_PQ, 55, HI_PQ_COLOR_HUE_S)            				/*读COLOR HUE曲线*/  

#define HIIOC_PQ_S_ACM_SAT         						_IOW(HI_ID_PQ, 56, HI_PQ_COLOR_SAT_S)               			/*写COLOR SAT曲线*/
#define HIIOC_PQ_G_ACM_SAT      						_IOR(HI_ID_PQ, 57, HI_PQ_COLOR_SAT_S)            				/*读COLOR SAT曲线*/  

#define HIIOC_PQ_G_DCI_HIST      						_IOR(HI_ID_PQ, 58, HI_PQ_DCI_HISTGRAM_S)            			/*读DCI直方图*/  
#define HIIOC_PQ_G_DCI_FINAL_LUT      					_IOR(HI_ID_PQ, 59, HI_PQ_DCI_FINAL_LUT_S)            			/*读DCI最终调整曲线*/  

#define HIIOC_PQ_S_DIM       							_IOW(HI_ID_PQ, 60, HI_PQ_DIM_LUT_S)               				/*写DIM映射曲线*/
#define HIIOC_PQ_G_DIM      							_IOR(HI_ID_PQ, 61, HI_PQ_DIM_LUT_S)            					/*读DIM映射曲线*/

#define HIIOC_PQ_S_TNR_Y_PIXMEAN_2_RATIO        		_IOW(HI_ID_PQ, 62, HI_PQ_TNR_S)               					/*写TNR的亮度PixMean-to-Ratio*/
#define HIIOC_PQ_G_TNR_Y_PIXMEAN_2_RATIO      			_IOR(HI_ID_PQ, 63, HI_PQ_TNR_S)            						/*读TNR的亮度PixMean-to-Ratio*/

#define HIIOC_PQ_S_TNR_C_PIXMEAN_2_RATIO       			_IOW(HI_ID_PQ, 64, HI_PQ_TNR_S)               					/*写TNR 色度PixMean-to-Ratio映射曲线*/
#define HIIOC_PQ_G_TNR_C_PIXMEAN_2_RATIO      			_IOR(HI_ID_PQ, 65, HI_PQ_TNR_S)            						/*读TNR 色度PixMean-to-Ratio映射曲线*/

#define HIIOC_PQ_S_TNR_Y_MOTION_MAPPING       			_IOW(HI_ID_PQ, 66, HI_PQ_TNR_S)              		 			/*写TNR亮度MotionMapping曲线*/
#define HIIOC_PQ_G_TNR_Y_MOTION_MAPPING      			_IOR(HI_ID_PQ, 67, HI_PQ_TNR_S)            						/*读TNR亮度MotionMapping曲线*/

#define HIIOC_PQ_S_TNR_C_MOTION_MAPPING       			_IOW(HI_ID_PQ, 68, HI_PQ_TNR_S)               					/*写TNR色度MotionMapping曲线*/
#define HIIOC_PQ_G_TNR_C_MOTION_MAPPING      			_IOR(HI_ID_PQ, 69, HI_PQ_TNR_S)            						/*读TNR色度MotionMapping曲线*/

#define HIIOC_PQ_S_TNR_Y_FINAL_MOTION_MAPPING       	_IOW(HI_ID_PQ, 70, HI_PQ_TNR_S)              	 				/*写TNR亮度FINAL MotionMapping曲线*/
#define HIIOC_PQ_G_TNR_Y_FINAL_MOTION_MAPPING      		_IOR(HI_ID_PQ, 71, HI_PQ_TNR_S)            						/*读TNR亮度FINAL MotionMapping曲线*/

#define HIIOC_PQ_S_TNR_C_FINAL_MOTION_MAPPING       	_IOW(HI_ID_PQ, 72, HI_PQ_TNR_S)               					/*写TNR色度FINAL MotionMapping曲线*/
#define HIIOC_PQ_G_TNR_C_FINAL_MOTION_MAPPING      		_IOR(HI_ID_PQ, 73, HI_PQ_TNR_S)            						/*读TNR色度FINAL MotionMapping曲线*/

#define HIIOC_PQ_S_SNR_PIXMEAN_2_RATIO       			_IOW(HI_ID_PQ, 74, HI_PQ_SNR_PIXMEAN_2_RATIO_S)               	/*写SNR 的pixmean-ratio映射曲线*/
#define HIIOC_PQ_G_SNR_PIXMEAN_2_RATIO      			_IOR(HI_ID_PQ, 75, HI_PQ_SNR_PIXMEAN_2_RATIO_S)            		/*读SNR 的pixmean-ratio映射曲线*/

#define HIIOC_PQ_S_SNR_PIXDIFF_2_EDGESTR       			_IOW(HI_ID_PQ, 76, HI_PQ_SNR_PIXDIFF_2_EDGESTR_S)               /*写SNR 的pixdiff-edgestr映射曲线*/
#define HIIOC_PQ_G_SNR_PIXDIFF_2_EDGESTR     			_IOR(HI_ID_PQ, 77, HI_PQ_SNR_PIXDIFF_2_EDGESTR_S)            	/*读SNR 的pixdiff-edgestr映射曲线*/

#define HIIOC_PQ_S_ACM_YSH_BY_H         				_IOW(HI_ID_PQ, 78, HI_PQ_YHSBYH_S)               				/*写COLOR YHS BY H曲线*/
#define HIIOC_PQ_G_ACM_YSH_BY_H     					_IOR(HI_ID_PQ, 79, HI_PQ_YHSBYH_S)            					/*读COLOR YHS BY H曲线*/  

#define HIIOC_PQ_S_ACM_SAT_GAIN         				_IOW(HI_ID_PQ, 80, HI_PQ_SAT_GAIN_S)              				/*写COLOR SAT GIAN曲线*/
#define HIIOC_PQ_G_ACM_SAT_GAIN      					_IOR(HI_ID_PQ, 81, HI_PQ_SAT_GAIN_S)            				/*读COLOR SAT GIAN曲线*/  

#define HIIOC_PQ_S_ACM_Y_GAIN         					_IOW(HI_ID_PQ, 82, HI_PQ_Y_GAIN_S)               				/*写COLOR Y GIAN曲线*/
#define HIIOC_PQ_G_ACM_Y_GAIN      						_IOR(HI_ID_PQ, 83, HI_PQ_Y_GAIN_S)            					/*读COLOR Y GIAN曲线*/  

#define HIIOC_PQ_S_PFMD_PARAM         					_IOW(HI_ID_PQ, 84, HI_PQ_PFMD_DBG_S)               				/*写PFMD参数*/
#define HIIOC_PQ_G_PFMD_PARAM      						_IOR(HI_ID_PQ, 85, HI_PQ_PFMD_DBG_S)            				/*读PFMD参数*/  

#define HIIOC_PQ_S_SHARPEN_ADPGAIN   					_IOW(HI_ID_PQ, 86, HI_PQ_SHARPEN_TABLE_S)            			/*写  Sharpen  AdpGain 曲线*/
#define HIIOC_PQ_G_SHARPEN_ADPGAIN   					_IOR(HI_ID_PQ, 87, HI_PQ_SHARPEN_TABLE_S)            			/* 读 Sharpen  AdpGain  曲线*/

#define HIIOC_PQ_S_DCI_WEIGHT  							_IOW(HI_ID_PQ, 88, HI_PQ_DCI_WEIGHT_S)             				/*写 DCI_WEIGHT 曲线*/
#define HIIOC_PQ_G_DCI_WEIGHT  							_IOR(HI_ID_PQ, 89, HI_PQ_DCI_WEIGHT_S)             				/* 读 DCI_WEIGHT  曲线*/

#if defined(CHIP_TYPE_hi3751v600)||defined(CHIP_TYPE_hi3751lv500)
#define HIIOC_PQ_S_SHARPEN_YRATIO   					_IOW(HI_ID_PQ, 90, HI_PQ_SHARPEN_YRATIO_S)    	 				/* 写 Sharpen YVALUE-Ratio?ú?? */
#define HIIOC_PQ_G_SHARPEN_YRATIO   					_IOR(HI_ID_PQ, 91, HI_PQ_SHARPEN_YRATIO_S)     					/*读 Sharpen YVALUE-Ratio?ú?? */
#endif
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
#define HIIOC_PQ_S_SHARPEN_YRATIO   					_IOW(HI_ID_PQ, 90, HI_PQ_SHARPEN_YRATIOGROUP_S)     			/* 写 Sharpen YVALUE-Ratio?ú?? */
#define HIIOC_PQ_G_SHARPEN_YRATIO   					_IOR(HI_ID_PQ, 91, HI_PQ_SHARPEN_YRATIOGROUP_S)    	 			/*读 Sharpen YVALUE-Ratio?ú?? */
#endif
#define HIIOC_PQ_S_TNR_FMOTION_MAPPING     				_IOW(HI_ID_PQ, 92, HI_PQ_TNR_FMOTION_MAPPING_S)  				/* 写 TNR   YFMotion  Mapping 曲线 */
#define HIIOC_PQ_G_TNR_FMOTION_MAPPING     				_IOR(HI_ID_PQ, 93, HI_PQ_TNR_FMOTION_MAPPING_S)  				/* 读   TNR   YFMotion  Mapping 曲线 */

#define HIIOC_PQ_S_2D_DIMMING       					_IOW(HI_ID_PQ, 94, HI_PQ_DIM_LUT_S)  							/* 写 2D  DIMMING   曲线 */
#define HIIOC_PQ_G_2D_DIMMING       					_IOR(HI_ID_PQ, 95, HI_PQ_DIM_LUT_S)  							/* 读 2D  DIMMING   曲线 */

#define HIIOC_PQ_S_AUTOFMOTION     						_IOW(HI_ID_PQ, 96, HI_BOOL)
#define HIIOC_PQ_G_AUTOFMOTION     						_IOR(HI_ID_PQ, 97, HI_BOOL)

#define HIIOC_PQ_S_AUTONR          						_IOW(HI_ID_PQ, 98, HI_BOOL)
#define HIIOC_PQ_G_AUTONR         		 				_IOR(HI_ID_PQ, 99, HI_BOOL)

#define HIIOC_PQ_S_4KSHARPEN_LIMITCTRL  			   _IOW(HI_ID_PQ, 100, HI_PQ_SHARPEN_LIMITLUT_GROUP_S)   			/* 写SHARPEN_LIMITCTRL    曲线 */
#define HIIOC_PQ_G_4KSHARPEN_LIMITCTRL  			   _IOR(HI_ID_PQ, 101, HI_PQ_SHARPEN_LIMITLUT_GROUP_S)				/* 读SHARPEN_LIMITCTRL   曲线 */

#define HIIOC_PQ_S_FHDSHARPEN_LIMITCTRL  			   _IOW(HI_ID_PQ, 102, HI_PQ_SHARPEN_LIMITLUT_GROUP_S)   			/* 写SHARPEN_LIMITCTRL    曲线 */
#define HIIOC_PQ_G_FHDSHARPEN_LIMITCTRL  			   _IOR(HI_ID_PQ, 103, HI_PQ_SHARPEN_LIMITLUT_GROUP_S)				/* 读SHARPEN_LIMITCTRL   曲线 */

#define HIIOC_PQ_S_DBM_PARAM         					_IOW(HI_ID_PQ, 104, HI_PQ_DBM_DBG_S)               				/*写DBM参数*/
#define HIIOC_PQ_G_DBM_PARAM      						_IOR(HI_ID_PQ, 105, HI_PQ_DBM_DBG_S)            				/*读DBM参数*/  

#define HIIOC_PQ_S_GAMMA_INDEX							_IOW(HI_ID_PQ, 106, HI_U32)						 				/*写GAMMA INDEX参数*/
#define HIIOC_PQ_G_GAMMA_INDEX							_IOR(HI_ID_PQ, 107, HI_U32)						 				/*写GAMMA INDEX参数*/

#define HIIOC_PQ_S_SHARPEN_GAIN							_IOW(HI_ID_PQ, 108, HI_PQ_SHARPEN_GAIN_S)						/*写Sharpen Gain 参数*/
#define HIIOC_PQ_G_SHARPEN_GAIN							_IOR(HI_ID_PQ, 109, HI_PQ_SHARPEN_GAIN_S)						/*读Sharpen Gain 参数*/

#define HIIOC_PQ_S_ACM_GAIN_GROUP						_IOW(HI_ID_PQ, 110, HI_PQ_ACM_GAIN_S)						 	/*写ACM Gain 参数*/
#define HIIOC_PQ_G_ACM_GAIN_GROUP						_IOR(HI_ID_PQ, 111, HI_PQ_ACM_GAIN_S)						 	/*读ACM Gain 参数*/

#define HIIOC_PQ_S_DCI_GAIN								_IOW(HI_ID_PQ, 112, HI_PQ_DCI_GAIN_S)						 	/*写DCI Gain 参数*/
#define HIIOC_PQ_G_DCI_GAIN								_IOR(HI_ID_PQ, 113, HI_PQ_DCI_GAIN_S)						 	/*读DCI Gain 参数*/

#define HIIOC_PQ_S_FIELDORDER_MODE						_IOW(HI_ID_PQ, 114, HI_U32)						 				/*写Field order mode 参数*/
#define HIIOC_PQ_G_FIELDORDER_MODE						_IOR(HI_ID_PQ, 115, HI_U32)						 				/*读Field order mode 参数*/

#define HIIOC_PQ_S_HDR_MODE								_IOW(HI_ID_PQ, 116, HI_DRV_PQ_HDR_FIXMODE_S)						 				/*写HDR mode 参数*/
#define HIIOC_PQ_G_HDR_MODE								_IOR(HI_ID_PQ, 117, HI_DRV_PQ_HDR_FIXMODE_S)						 				/*读HDR  mode 参数*/

#define HIIOC_PQ_G_HDR_INFO								_IOR(HI_ID_PQ, 118, HI_DRV_PQ_HDR_INFO_S)						 				/*读HDR  INFO 参数*/

#define HIIOC_PQ_S_COLOR_SATGAIN						_IOW(HI_ID_PQ, 119, HI_PQ_COLOR_SECTION_SATGAIN_S)				/*写Color sat gain 参数*/
#define HIIOC_PQ_G_COLOR_SATGAIN						_IOWR(HI_ID_PQ, 120, HI_PQ_COLOR_SECTION_SATGAIN_S)				/*读Color sat gain 参数*/

#define HIIOC_PQ_S_COLOR_HUEGAIN						_IOW(HI_ID_PQ, 121, HI_PQ_COLOR_SECTION_HUEGAIN_S)				/*写Color hue gain 参数*/
#define HIIOC_PQ_G_COLOR_HUEGAIN						_IOWR(HI_ID_PQ, 122, HI_PQ_COLOR_SECTION_HUEGAIN_S)				/*读Color hue gain 参数*/

#define HIIOC_PQ_S_COLOR_BRIGAIN						_IOW(HI_ID_PQ, 123, HI_PQ_COLOR_SECTION_BRIGAIN_S)				/*写Color bri gain 参数*/
#define HIIOC_PQ_G_COLOR_BRIGAIN						_IOWR(HI_ID_PQ, 124, HI_PQ_COLOR_SECTION_BRIGAIN_S)				/*读Color bri gain 参数*/

#define HIIOC_PQ_S_CTIGAIN						         _IOW(HI_ID_PQ, 125, HI_U32)				                     /*写Cti gain*/
#define HIIOC_PQ_G_CTIGAIN						         _IOR(HI_ID_PQ, 126, HI_U32)				                     /*读Cti gain*/

#define HIIOC_PQ_S_NRSTR						         _IOW(HI_ID_PQ, 127, HI_PQ_NR_TMK_S)				                     /*写NR str*/
#define HIIOC_PQ_G_NRSTR						         _IOR(HI_ID_PQ, 128, HI_PQ_NR_TMK_S)				                     /*读NR str*/
#define HIIOC_PQ_G_FINALLED						         _IOR(HI_ID_PQ, 129, HI_U32 )				                     /*读LED*/

 #ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /* __HI_DRV_PQ_H__ */
