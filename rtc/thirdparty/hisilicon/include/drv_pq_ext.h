/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : drv_pq_ext.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/09
  Description   :

******************************************************************************/

#ifndef __DRV_PQ_EXT_H__
#define __DRV_PQ_EXT_H__

#include "hi_type.h"
#include "hi_drv_video.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define ZME_COEF_SIZE_HOR       384/*384为缩放系数占的内存*/
#define ZME_COEF_SIZE_VER       288/*288为缩放系数占的内存*/


/* VPSS视频信息 */
typedef struct hiHI_VPSS_PQ_INFO_S
{ 
    HI_DRV_SOURCE_E  			enInputSrc;         /* 信号源类型 */
    HI_U32                      u32Width;           /* 图像宽度 */
    HI_U32                      u32Height;          /* 图像高度 */  
    HI_U32                      u32FrameRate;       /* 输入帧率 */
    HI_BOOL                     bInterlace;         /* 是否隔行信号 */
    HI_DRV_COLOR_SYS_E     		enColorSys;         /* ATV信号的Color System */
	HI_BOOL      				bMcEnable;   		/*512M版本开关MCDI  的策略满足条件*/ 
} HI_VPSS_PQ_INFO_S;

/*VDP视频信息 */
typedef struct hiHI_VDP_PQ_INFO_S
{ 
    HI_DRV_SOURCE_E  enInputSrc;         /* 信号源类型 */
    HI_U32                      u32Width;           /* 图像宽度 */
    HI_U32                      u32Height;          /* 图像高度 */  
    HI_U32                      u32FrameRate;       /* 输入帧率 */
    HI_BOOL                     bInterlace;         /* 是否隔行信号 */
    HI_BOOL                     b3dType;            /*是否原生3D播放*/   
    HI_BOOL                     bPcTiming;          /* 是否为PC Timing */
    HI_DRV_COLOR_SYS_E     enColorSys;         /* ATV信号的Color System */
} HI_VDP_PQ_INFO_S;

/*4K视频信息 */
typedef struct hiHI_VDP_4K_INFO_S
{ 
    HI_U32                      u32Width;           /* 图像宽度 */
    HI_U32                      u32Height;          /* 图像  高度 */
	HI_U32						u32SrcWidth;		/* 图像 SRC宽度 */
	HI_U32						u32SrcHeight;		/* 图像SRC高度 */
    HI_BOOL                     b3dType;            /*是否3D播放，包括2D转3D和原生3D*/   
    HI_BOOL                     bPcTiming;          /* 是否为PC Timing */
	HI_DRV_PIX_FORMAT_E 		eSrcFmt;			/*  像素格式信息 */
	HI_DRV_COLOR_SPACE_E    	enColorSpace;		/*  色彩空间信息 */
 	HI_DRV_GAMMA_TYPE_E     	enGammaType;		/*  Gamma 类型需求信息*/
} HI_VDP_4K_INFO_S;

typedef struct hiVDP_DHD_INFO_S
{
    HI_BOOL                     bValid;
	HI_DRV_COLOR_SPACE_E        enColorSpace;
	HI_DRV_GAMMA_TYPE_E			enGammaType;
    HI_DRV_VIDEO_HDR10_METADATA_STREAM_S stMetadata;
}HI_VDP_DHD_INFO_S;

/* PQ模块开关信息 */
typedef struct hiPQ_VPSS_MODULE_S
{ 
    HI_BOOL                     bFMD;         /* FMD开关*/
    HI_BOOL                     bTNR;            /*NR开关*/   
    HI_BOOL                     bCCCL;          /*CCCL开关*/
} HI_PQ_VPSS_MODULE_S;

/*色彩空间转换类型*/
typedef enum hiPQ_CSC_MODE_
{
    HI_PQ_CSC_YUV2RGB_601 = 0,       //YCbCr_601 LIMIT-> RGB FULL
    HI_PQ_CSC_YUV2RGB_709,              //YCbCr_709 LIMIT-> RGB FULL
    HI_PQ_CSC_RGB2YUV_601,              // RGB FULL->YCbCr_601 LIMIT  
    HI_PQ_CSC_RGB2YUV_709,              //RGB FULL->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2YUV_709_601,      //YCbCr_709 LIMIT->YCbCr_601 LIMIT
    HI_PQ_CSC_YUV2YUV_601_709,      //YCbCr_601 LIMIT->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2YUV,                      //YCbCr LIMIT->YCbCr LIMIT
    HI_PQ_CSC_YUV2RGB_601_FULL,       //YCbCr_601 FULL-> RGB FULL
    HI_PQ_CSC_YUV2RGB_709_FULL,        //YCbCr_709 FULL-> RGB FULL
    HI_PQ_CSC_RGB2YUV_601_FULL,        // RGB FULL->YCbCr_601 FULL  
    HI_PQ_CSC_RGB2YUV_709_FULL,        //RGB FULL->YCbCr_709 FULL
    HI_PQ_CSC_YUV2YUV_709_601_FULL,      //YCbCr_709 FULL->YCbCr_601 FULL
    HI_PQ_CSC_YUV2YUV_601_709_FULL,      //YCbCr_601 FULL->YCbCr_709 FULL
    HI_PQ_CSC_YUV2YUV_FULL,                      //YCbCr FULL->YCbCr FULL
    HI_PQ_CSC_YUV2YUV_LIMIT2FULL,           //YCbCr  LIMIT->YCbCr  FULL
    HI_PQ_CSC_YUV2YUV_601_709_LIMIT2FULL,           //YCbCr 601 LIMIT->YCbCr 709 FULL
    HI_PQ_CSC_YUV2YUV_709_601_LIMIT2FULL,           //YCbCr 709 LIMIT->YCbCr 601 FULL
    HI_PQ_CSC_YUV2YUV_FULL2LIMIT,                            //YCbCr  FULL->YCbCr  LIMIT
    HI_PQ_CSC_YUV2YUV_601_709_FULL2LIMIT,           //YCbCr 601 FULL->YCbCr 709 LIMIT
    HI_PQ_CSC_YUV2YUV_709_601_FULL2LIMIT,           //YCbCr 709 FULL->YCbCr 601 LIMIT
    HI_PQ_CSC_YUV2RGBL_601,      //YCbCr_601 LIMIT-> RGB LIMIT
    HI_PQ_CSC_YUV2RGBL_709,        //YCbCr_709 LIMIT-> RGB LIMIT
    HI_PQ_CSC_RGBL2YUV_601,        // RGB LIMIT->YCbCr_601 LIMIT  
    HI_PQ_CSC_RGBL2YUV_709,        //RGB LIMIT->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2RGBL_601_FULL,        //YCbCr_601 FULL-> RGB LIMIT
    HI_PQ_CSC_YUV2RGBL_709_FULL,        //YCbCr_709 FULL-> RGB LIMIT
    HI_PQ_CSC_RGBL2YUV_601_FULL,        // RGB LIMIT->YCbCr_601 FULL  
    HI_PQ_CSC_RGBL2YUV_709_FULL,        //RGB LIMIT->YCbCr_709 FULL
    HI_PQ_CSC_RGB2RGBL,                                            //RGB FULL->RGB LIMIT
    HI_PQ_CSC_RGBL2RGB,                                            //RGB LIMIT->RGB FULL
    HI_PQ_CSC_RGBL2RGBL,                                            //RGB LIMIT->RGB LIMIT
    HI_PQ_CSC_RGB2RGB,                                              //RGB FULL->RGB FULL
    HI_PQ_CSC_YUV2RGB_2020,					//YUV 2020 FULL->RGB  2020 FULL
    HI_PQ_CSC_RGB20202YUV709_FULL2LIMIT,
    HI_PQ_CSC_YUV7092RGB2020_LIMIT2FULL,
    HI_PQ_CSC_YUV7092RGB2020_FULL2FULL,
    HI_PQ_CSC_RGB7092YUV2020_FULL2LIMIT,
// 为兼容SR 添加的模式
	HI_PQ_CSC_RGB7092YUV2020_FULL,        //BT709RGBFULL    ->  BT2020YUVFULL
    HI_PQ_CSC_RGB2YUV2020_FULL_LIMIT,     //BT2020RGBFULL   -> BT2020YUVLIMIT
    HI_PQ_CSC_RGB2YUV2020_FULL,           //BT2020RGBFULL   ->  BT2020YUVFULL
    HI_PQ_CSC_YUV2RGB2020_FULL,           //BT2020YUVFULL   ->  BT2020RGBFULL

    HI_PQ_CSC_BUTT
} HI_PQ_CSC_MODE_E;

/*VDP CSC ID*/
typedef enum hiPQ_CSC_ID_E
{
    HI_PQ_VDP_CSC_VP0 = 0,
    HI_PQ_VDP_CSC_VP1,
    HI_PQ_VDP_CSC_V0,
    HI_PQ_VDP_CSC_V1,

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
    HI_PQ_VDP_CSC_V0_PIC,
#endif
    HI_PQ_VDP_CSC_BUTT
} HI_PQ_CSC_ID_E;

/* VDP CSC 属性*/
typedef struct  hiPQ_VDP_CSC_S
{
    HI_BOOL  bCSCEn;
    HI_PQ_CSC_MODE_E  enCSC;
} HI_PQ_VDP_CSC_S;


/*缩放YUV数据结构体444 422 420*/
typedef enum hiPQ_ZME_FORMAT_E
{
    ALG_PIX_FORMAT_SP420 = 0,
    ALG_PIX_FORMAT_SP422,
    ALG_PIX_FORMAT_SP444,
    
    ALG_PIX_FORMAT_BUTT,
}ZME_FORMAT_E;

typedef enum hiPQ_SCALAR_LEVEL_E
{
    HI_PQ_SCALAR_LEVEL_0 = 0,//模糊
    HI_PQ_SCALAR_LEVEL_1,
    HI_PQ_SCALAR_LEVEL_2,
    HI_PQ_SCALAR_LEVEL_3,
    HI_PQ_SCALAR_LEVEL_4,
    HI_PQ_SCALAR_LEVEL_5,//清晰
   HI_PQ_SCALAR_LEVEL_BUTT,
}HI_PQ_SCALAR_LEVEL_E;
/*  SCALER 信息 */
typedef struct  hiPQ_SCALER_S
{
    HI_BOOL bHorizontal;
	HI_BOOL bYUV; 
	HI_BOOL b3Dtype;
    HI_U32 u32YRatio;
    HI_U32 u32CRatio;
    ZME_FORMAT_E enInFmt;
    ZME_FORMAT_E enOutFmt;
} HI_PQ_SCALER_S;

/*DCI直方图结构*/
typedef struct hiPQ_HISTGRAM_S
{
    HI_S32 s32HistGram[32];
}HI_PQ_HISTGRAM_S;

/*DCI最终权重曲线*/
typedef struct hiPQ_DCI_ADJ_LUT_S
{
    HI_S32 s32AdjLUT[33];
}HI_PQ_DCI_ADJ_LUT_S;

/*CSC 矩阵系数结构*/
typedef struct  hiPQ_CSC_COEF_S
{
    HI_S32 csc_coef00;
    HI_S32 csc_coef01;
    HI_S32 csc_coef02;

    HI_S32 csc_coef10;
    HI_S32 csc_coef11;
    HI_S32 csc_coef12;

    HI_S32 csc_coef20;
    HI_S32 csc_coef21;
    HI_S32 csc_coef22;
} HI_PQ_CSC_COEF_S;

typedef struct  hiPQ_CSC_DCCOEF_S
{
    HI_S32 csc_in_dc0;
    HI_S32 csc_in_dc1;
    HI_S32 csc_in_dc2;

    HI_S32 csc_out_dc0;
    HI_S32 csc_out_dc1;
    HI_S32 csc_out_dc2;
} HI_PQ_CSC_DCCOEF_S;

/*DCI统计窗口*/
typedef struct  hiPQ_DCI_WIN_S
{
    HI_U16      u16HStar;
    HI_U16      u16HEnd;
    HI_U16      u16VStar;
    HI_U16      u16VEnd;
} HI_PQ_DCI_WIN_S;

/*DEI直方图信息*/
typedef struct hiPQ_MOTION_HISTGRAM_S
{
    //HI_U32 au32MotionHist[32];
    HI_S32 s32WidthY;
    HI_S32 s32HeightY;
    HI_U32 u32SmallMotionNum; //output of logic,32bit unsigned
    HI_U32 u32SmallMotionSum; //output of logic,32bit unsigned
    HI_U32 u32LargeMotionNum; //output of logic,32bit unsigned
    HI_U32 u32LargeMotionSum; //output of logic,32bit unsigned
    HI_U32 u32MiddlMotionNum; //output of logic,32bit unsigned
    HI_U32 u32MiddlMotionSum; //output of logic,32bit unsigned
}HI_PQ_MOTION_HISTGRAM_S;

/*DEI 全局运动信息*/
typedef struct hiPQ_MOTION_INFO_S
{
    HI_U32 u32GlobalMotion;
    HI_U32 u32AdjustGain;
}HI_PQ_MOTION_INFO_S;

/*DEI API驱动传入的信息*/
typedef struct hiPQ_MOTION_INPUT_S
{
    HI_U32 u32Width;
    HI_U32 u32Height;
	HI_U32 u32HandleNo;
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
	HI_U32 u32Scd;
#endif
	HI_VOID *pstMotionReg;

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
    HI_VOID *pRGMV;
    HI_U32 stride;
#endif 
}HI_PQ_MOTION_INPUT_S;


//tnr global motion api 输入参数结构
typedef struct
{
	HI_U32 u32HdlNo;	//实例的ID
	HI_U32 u32Width;	//输入图像宽度
	HI_U32 u32Height;	//输入图像高度
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
	HI_U32 u32Scd;
#endif
	HI_VOID *pstMotionReg;
}HI_PQ_TNR_MOTION_PARAM_IN_S;

//Tnr global motion result
typedef struct
{
	HI_U32 u32GlobalMotion;
	HI_U32 u32AdjustGain;
}HI_PQ_TNR_MOTION_RESULT_S;

//DB强度值,对应VPSS_DB_WEIGHT寄存器
typedef struct
{
	HI_U8    u8HWeight;		// 6bits [0,63]
    HI_U8    u8VWeight;		// 6bits [0,63]
}HI_PQ_DB_WEIGHT_S;

//image signal type of interlacing or non-interlacing
typedef enum
{
	HI_PQ_DB_INTERLACE = 0,	//经过DEI ,隔行
	HI_PQ_DB_PROGRESSIVE		//不经过DEI ,逐行
}HI_PQ_DB_SIG_TYPE_E;


//DB强度 API的输入参数结构
typedef struct
{	
    HI_U8				u8SCDStr;		 //根据SCD的api计算得出的一个值[0,255]
	HI_U32				u32HdlNo; //实例的ID
	HI_PQ_DB_SIG_TYPE_E	eType;		 //数据源类型，隔行或逐行，是否做DEI
	HI_VOID 	*pstReg;	 //global motion 寄存器地址
	
}HI_PQ_DB_STR_PARAM_IN_S;

/*IFMD软算法所需驱动传入参数，VPSS->PQ*/
typedef struct hi_PQ_IFMD_CALC_S
{	
    //HI_U32	u32Stt_w_addr;//统计信息回写起始地址
    HI_U32  u32HandleNo;
    HI_U32  u32WidthY;
    HI_U32  u32HeightY;
    HI_S32	s32FieldOrder; //顶底场序 顶场优先底场优先
    HI_S32	s32FieldMode; //	顶底场标志???
    HI_U32  u32FrameRate;
	HI_VOID *pstIfmdHardOutReg;//读取ifmd的状态寄存器
}HI_PQ_IFMD_CALC_S;



typedef struct
{
    HI_S32  die_reset;
    HI_S32  die_stop;
    HI_S32  dir_mch;
    HI_S32  die_out_sel;
    HI_S32  jud_en;
    //HI_S32  ChromaVertFltEn;
    /* added by c00190889  */ 
    HI_S32  s32FieldOrder;/* 顶地场序 */
	HI_S32  s32SceneChanged;/* 场景切换信息 */
	HI_S32  s32FilmType;/* 电影模式 */
	HI_U32  u32KeyValue;/* 关键帧 */
} HI_PQ_IFMD_PLAYBACK_S;


/*PFMD软算法所需驱动传入参数，VPSS->PQ*/
typedef struct hi_PQ_PFMD_CALC_S
{	
    HI_U32  u32HandleNo;
    HI_U32  u32WidthY;
    HI_U32  u32HeightY;
	HI_S32	s32FieldOrder; //顶底场序 顶场优先底场优先
    HI_S32	s32FieldMode;
    HI_U32  u32FrameRate;
    HI_VOID *pstpfmdHardOutReg;//读取pfmd的状态寄存器
}HI_PQ_PFMD_CALC_S; 

typedef struct
{
	HI_S32  s32SceneChanged;/* 场景切换信息 */
	HI_S32  s32FilmType;/* 电影模式 */
	HI_U32  u32KeyValue;/* 关键帧 */
} HI_PQ_PFMD_PLAYBACK_S;

 /*TVD更新函数对外接口
 */
  typedef struct
  {    
	  HI_S32 (*pUpdateTvd)(HI_VOID *pstRegTvd); 
  } TVD_UPDATE_FUNC_S;
/*Dim 强度等级*/
typedef enum hiDIM_LEVEL_E
{
    HI_PQ_DIM_LEVEL_LOW = 0,
    HI_PQ_DIM_LEVEL_MID,
    HI_PQ_DIM_LEVEL_HIGH,

    HI_PQ_DIM_LEVEL_BUTT
} HI_PQ_DIM_LEVEL_E;


 /**
 \brief Timming变化后进行VPSS PQ参数更新
 \attention \n
无

 \param[in] *u32HandleNo:VPSS通道号
 \param[in] *pstTimingInfo: Timming Info
 \param[in] *pstVPSSReg:VPSS 虚拟寄存器地址，如果为NULL，则表示销毁该路地址,
 一个handleNo对应一个地址，若地址发生变化，才会重新赋初始值，否则不赋初始值。
 \param[out] *pstPQModule:PQ传给驱动的开关参数

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateVpssPQ(HI_U32 u32HandleNo, HI_VPSS_PQ_INFO_S* pstTimingInfo, HI_VOID *pstVPSSReg, HI_PQ_VPSS_MODULE_S* pstPQModule);

/**
 \brief Timming变化后进行VDP PQ参数更新
 \attention \n
无

 \param[in] u32DisplayId
 \param[in] pstTimingInfo: Timming Info
 \param[in] *pstVDPReg:VDP 虚拟寄存器地址

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateVdpPQ(HI_U32 u32DisplayId, HI_VDP_PQ_INFO_S* pstTimingInfo, HI_VOID *pstVDPReg);
/**
 \brief TVD PQ参数更新
 \attention \n
无

 \param[in] *pstRegTvd:tvd 虚拟寄存器地址
 \retval ::HI_SUCCESS
 */
 extern HI_S32 DRV_PQ_UpdateTvdPQ(HI_VOID *pstRegTvd);
/**
 \brief MEMC PQ参数更新
 \attention \n
无

 \param[in] *pstMeRegMem:MEMC 虚拟寄存器地址
 \param[in] *pstfFiRegMem:MEMC 虚拟寄存器地址
 \param[in] *pstIsrRegMem:MEMC 虚拟寄存器地址

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_UpdateMemcPQ(HI_VOID *pstMeRegMem, HI_VOID *pstfFiRegMem, HI_VOID *pstIsrRegMem);

/**
 \brief 更新4K Timing下的配置
 \attention \n
无

 \param[in] u32DisplayId: display Id
 \param[in] pst4KInfo

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_Update4KSetting(HI_U32 u32DisplayId, HI_VDP_4K_INFO_S* pst4KInfo);

/**
 \brief 更新DHD 的配置
 \attention \n
无

 \param[in] pstDHDInfo

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_UpdateDHDParam(HI_U32 u32DisplayId, HI_VDP_DHD_INFO_S *pstDHDInfo);

/**
 \brief 设置VDP各通道的CSC
 \attention \n
无

 \param[in] enDisplayId:
 \param[in] pstCscMode: 色彩空间

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_UpdateVdpCSC(HI_PQ_CSC_ID_E enDisplayId, HI_PQ_VDP_CSC_S *pstCscMode);

/**
 \brief 更新DCI直方图统计窗口
 \attention \n
无

 \param[in] *pstWin;

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateDCIWin(HI_PQ_DCI_WIN_S *pstWin);

/**
 \brief 设置VPSS scaler系数
 \attention \n
无

 \param[in] pstScalerInfo:缩放信息
 \param[out] pvCoefAddr:缩放系数地址

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetVpssScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief 设置VDP scaler系数
 \attention \n
无

 \param[in] pstScalerInfo:缩放信息
 \param[out] pvCoefAddr:缩放系数地址

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief 设置WBC scaler系数
 \attention \n
无

 \param[in] pstScalerInfo:缩放信息
 \param[out] pvCoefAddr:缩放系数地址

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetWbcScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief 根据强度获取Horizontal scaler缩放系数
 \attention \n
无

 \param[in] enScalarLevel:缩放强度
 \param[out] pvCoefAddr:缩放系数地址

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetHorizontalScalerCoefByLevel(HI_PQ_SCALAR_LEVEL_E enScalarLevel, HI_VOID *pLCoefAddr, HI_VOID *pCCoefAddr);

/**
 \brief 获取CSC系数
 \attention \n
无

 \param[in] enCSCMode:
 \param[out] pstCSCCoef:
 \param[out] pstCSCDCCoef:

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetCSCCoef(HI_PQ_CSC_MODE_E  enCSCMode, HI_PQ_CSC_COEF_S *pstCSCCoef, HI_PQ_CSC_DCCOEF_S *pstCSCDCCoef);

/**
 \brief 获取8bit CSC系数
 \attention \n
无

 \param[in] enCSCMode:
 \param[out] pstCSCCoef:
 \param[out] pstCSCDCCoef:

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_Get8BitCSCCoef(HI_PQ_CSC_MODE_E  enCSCMode, HI_PQ_CSC_COEF_S *pstCSCCoef, HI_PQ_CSC_DCCOEF_S *pstCSCDCCoef);

/**
 \brief 隔行从DEI获取的Global Motion信息
 \attention \n
无

 \param[in] *pstMotionHist:直方图
 \param[out] *pstMotionResult:运动信息

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_GetDeiGlobalMotion(HI_PQ_MOTION_INPUT_S *pstMotionInput,HI_PQ_MOTION_INFO_S *pstMotionResult);


/**
\brief     :Tnr的Global Motion软算法API

\attention :
			本算法参考DEI模块进行移植
			算法提供：裴朝科 p00188942；移植&维护：吕明君 l00268071
			算法内已经将u32GlobalMotion和u32AdjustGain配到相应寄存器中

\param[in] :pstParamIn结构，包含如下元素
			u32HdlNo 实例的ID
			u32Width 输入图像宽度
			u32Height 输入图像高度
			pstMotionReg 寄存器地址

\param[out]:pstMotionResult结构，包含如下元素
			u32GlobalMotion
			u32AdjustGain

\retval    :HI_SUCCESS/HI_FAILURE

*/
extern HI_S32 DRV_PQ_GetTnrGlobalMotion(HI_PQ_TNR_MOTION_PARAM_IN_S *pstParamIn, HI_PQ_TNR_MOTION_RESULT_S *pstMotionResult);


/**
\brief     :根据Global Motion获取DB的自适应强度值API

\attention :函数内对多实例的ID u32HdlNo 不做活动性检测，仅判断阈值
			隔行或者逐行信号源所采用的Global Motion不同；
			算法内已经将输出参数u8HWeight和u8VWeight配到寄存器VPSS_DB_WEIGHT中
			算法提供：晏秀梅 y00224511；移植&维护：吕明君 l00268071

\param[in] :pstParamIn结构，包含如下元素
			u32HdlNo 实例的ID
			u8SCDStr 是根据SCD的api计算得出的一个值[0,255]
			pstReg   global motion 寄存器地址
			eType 数据源类型，隔行或逐行，是否做DEI

\param[out]:pstDBstr  DB强度值。对应寄存器VPSS_DB_WEIGHT，分别为u8HWeight和u8VWeight

\retval    :HI_SUCCESS/HI_FAILURE

*/
extern HI_S32 DRV_PQ_GetAdaptiveDBStrength(HI_PQ_DB_STR_PARAM_IN_S *pstParamIn, HI_PQ_DB_WEIGHT_S *pstDBstr);

extern HI_S32 DRV_PQ_DBApi(HI_U32 u32HandleNo, const HI_VOID *pVpssSWBReg);

/**
 \brief 逐行FMD模式检测
 \attention \n
无

 \param[in] pstVPSSReg: VPSS物理寄存器地址

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_PfmdDetect(HI_PQ_PFMD_CALC_S *pstPfmdCalc,HI_PQ_PFMD_PLAYBACK_S *pstPfmdResult);

/**
 \brief 隔行FMD模式检测
 \attention \n
无

 \param[in] pstVPSSReg: VPSS物理寄存器地址

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_IfmdDect(HI_PQ_IFMD_CALC_S *pstIfmdCalc,HI_PQ_IFMD_PLAYBACK_S *pstIfmdResult);

/**
 \brief 获取DCI直方图
 \attention \n
无

 \param[in] *pstDciHist:0-255

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 DRV_PQ_GetDciHistgram(HI_PQ_HISTGRAM_S *pstDciHist);

/**
 \brief 获取DCI最终权重曲线
 \attention \n
无

 \param[in] *pstDciLut

 \retval ::HI_SUCCESS

 */
 
HI_S32 DRV_PQ_GetDciFinalAdjLut(HI_PQ_DCI_ADJ_LUT_S *pstDciLut);
extern HI_S32 DRV_PQ_SetDimLevel(HI_PQ_DIM_LEVEL_E enDimLevel);

HI_S32 PQ_ModuleInit(HI_VOID);
HI_VOID PQ_ModuleExit(HI_VOID);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __DRV_PQ_EXT_H__ */
