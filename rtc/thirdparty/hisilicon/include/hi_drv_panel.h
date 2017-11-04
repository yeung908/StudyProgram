/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_drv_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/11/13
   Description   :
   History       :
   1.Date        : 2013/11/13
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


#ifndef  __HI_DRV_PANEL_H__
#define  __HI_DRV_PANEL_H__
#include "hi_drv_video.h"
#include "hi_drv_disp.h"
#include "hi_debug.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifndef HI_ADVCA_FUNCTION_RELEASE
#define HI_FATAL_PANEL(fmt...) \
            HI_FATAL_PRINT(HI_ID_PANEL, fmt)

#define HI_ERR_PANEL(fmt...) \
            HI_ERR_PRINT(HI_ID_PANEL, fmt)

#define HI_WARN_PANEL(fmt...) \
            HI_WARN_PRINT(HI_ID_PANEL, fmt)

#define HI_INFO_PANEL(fmt...) \
            HI_INFO_PRINT(HI_ID_PANEL, fmt)
#else

#define HI_FATAL_PANEL(fmt...) 
#define HI_ERR_PANEL(fmt...) 
#define HI_WARN_PANEL(fmt...)
#define HI_INFO_PANEL(fmt...)
#endif

#define INDICATOR_HIGH                      (0XFF)
#define INDICATOR_LOW                       (0X00)
#define COMMAND                             (0X01)

#define INDICATOR                           (0XAA)

#define DIMDATACAPACITY                     (1000)

/*************************** Structure Definition ****************************/


/*
* panel index命名规范如下: 屏厂商名字通常是LG/CMO/AUO/SS(三星)     型号:根据实际确定，
* 分辨率有:1920x1080, 1366x768, 1920x1200, 1440x900, 1650x1080,    帧率:通常是60Hz，120Hz，240Hz
* 3D屏输出图像类型通常为:2D,PR,FS,SBS
* PANEL_屏厂商名字_型号_分辨率_帧率_3D屏类型
*/
typedef enum hiPANEL_INDEX_E
{
    HI_PANEL_AUO_21_1920x1080_60Hz_2D = 0,
    HI_PANEL_LG_37_1920x1080_60Hz_2D,
    HI_PANEL_LG_32_1366x768_60Hz_2D,
    HI_PANEL_LG_XXX_1920x1080_60Hz_3D_LR,
    HI_PANEL_LG_XXX_1920x1080_60Hz_3D_SBS,
    HI_PANEL_XXX_1920x1080_60Hz_3D_LR,
    HI_PANEL_V7500_1920x1080_60Hz_3D,
    HI_PANEL_XXX_1920x1080_120Hz_3D_FS,
    HI_PANEL_CMO_V500_1920x1080_60Hz_3D_LR,
    HI_PANEL_V6500_1920x1080_60Hz_3D,
    HI_PANEL_VGA_1366x768_60Hz_2D,
    HI_PANEL_CMO_3840x2160_60Hz_3D_LR,
    HI_PANEL_LG_3840x2160_60Hz_3D_LR,
    HI_PANEL_CSOT_3840x2160_60Hz_3D_FS,
    HI_PANEL_XXX_1366x768_60Hz_3D_LR,
    
    HI_PANEL_MAX
} HI_PANEL_INDEX_E;


/*
 * LVDS共模电压
 */
typedef enum hiDRV_PANEL_LVDS_VOLTAGE_E
{
    HI_DRV_PANEL_LVDS_VOLTAGE_1250MV = 0,
    HI_DRV_PANEL_LVDS_VOLTAGE_1100MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1150MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1200MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1300MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1350MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1400MV,
    HI_DRV_PANEL_LVDS_VOLTAGE_1450MV,

    HI_DRV_PANEL_LVDS_VOLTAGE_BUTT,
} HI_DRV_PANEL_LVDS_VOLTAGE_E;

/*
 * LVDS驱动电流
 */
typedef enum hiDRV_PANEL_LVDS_CURRENT_E
{
    HI_DRV_PANEL_LVDS_CURRENT_200MV = 0,
    HI_DRV_PANEL_LVDS_CURRENT_150MV,
    HI_DRV_PANEL_LVDS_CURRENT_250MV,
    HI_DRV_PANEL_LVDS_CURRENT_300MV,
    HI_DRV_PANEL_LVDS_CURRENT_350MV,
    HI_DRV_PANEL_LVDS_CURRENT_400MV,
    HI_DRV_PANEL_LVDS_CURRENT_450MV,
    HI_DRV_PANEL_LVDS_CURRENT_500MV,

    HI_DRV_PANEL_LVDS_CURRENT_BUTT,
} HI_DRV_PANEL_LVDS_CURRENT_E;


/*
 * LVDS展频频率
 */
typedef enum hiDRV_PANEL_LVDS_SSFREQ_E
{
    HI_DRV_PANEL_LVDS_SSFREQ_93P75KHZ   = 2,
    HI_DRV_PANEL_LVDS_SSFREQ_62P5KHZ    = 3,
    HI_DRV_PANEL_LVDS_SSFREQ_46P875KHZ  = 4,
    HI_DRV_PANEL_LVDS_SSFREQ_37P5KHZ    = 5,

    HI_DRV_PANEL_LVDS_SSFREQ_BUTT,
} HI_DRV_PANEL_LVDS_SSFREQ_E;

/*
 * VB1展频频率
 */
typedef enum hiDRV_PANEL_VBO_SSFREQ_E
{
    HI_DRV_PANEL_VBO_SSFREQ_46P875KHZ   = 2,
    HI_DRV_PANEL_VBO_SSFREQ_31P250KHZ   = 3,
    HI_DRV_PANEL_VBO_SSFREQ_23P438KHZ   = 4,
    HI_DRV_PANEL_VBO_SSFREQ_18P750KHZ   = 5,

    HI_DRV_PANEL_VBO_SSFREQ_BUTT,
} HI_DRV_PANEL_VBO_SSFREQ_E;

typedef struct hiDRV_PANEL_3DATTR_RANGE_S
{
    HI_RANGE_S stDepthRange;
    HI_RANGE_S stViewRange;
    
}HI_DRV_PANEL_3DATTR_RANGE_S;

typedef enum hiDRV_PANEL_FLIP_TYPE_E
{
    HI_DRV_PANEL_FLIP_TYPE_NONE = 0,     /* normal */
    HI_DRV_PANEL_FLIP_TYPE_FLIP,         /* only flip*/
    HI_DRV_PANEL_FLIP_TYPE_MIRROR,       /* only mirror */
	HI_DRV_PANEL_FLIP_TYPE_FLIP_MIRROR,  /* flip and mirror  */
	
    HI_DRV_PANEL_FLIP_TYPE_BUTT,
} HI_DRV_PANEL_FLIP_TYPE_E;


typedef enum hiDRV_PANEL_LINKTYPE_E
{
    HI_DRV_PANEL_LINKTYPE_1LINK = 0,
    HI_DRV_PANEL_LINKTYPE_2LINK,
    HI_DRV_PANEL_LINKTYPE_4LINK,
    HI_DRV_PANEL_LINKTYPE_8LINK,
    
    HI_DRV_PANEL_LINKTYPE_BUTT,
} HI_DRV_PANEL_LINKTYPE_E;

typedef enum hiDRV_PANEL_LVDS_LINKMAP_E
{
    HI_DRV_PANEL_LVDS_LINKMAP_PIXEL0 = 0, /* 输出pixel 0 */
    HI_DRV_PANEL_LVDS_LINKMAP_PIXEL1,     /* 输出pixel 1 */
    HI_DRV_PANEL_LVDS_LINKMAP_PIXEL2,     /* 输出pixel 2 */
    HI_DRV_PANEL_LVDS_LINKMAP_PIXEL3,     /* 输出pixel 3 */

    HI_DRV_PANEL_LVDS_LINKMAP_BUTT,
} HI_DRV_PANEL_LVDS_LINKMAP_E;


typedef struct hiDRV_PANEL_LVDS_LINKMAP_S
{
    HI_DRV_PANEL_LVDS_LINKMAP_E enLink1;
    HI_DRV_PANEL_LVDS_LINKMAP_E enLink2;
    HI_DRV_PANEL_LVDS_LINKMAP_E enLink3;
    HI_DRV_PANEL_LVDS_LINKMAP_E enLink4;
} HI_DRV_PANEL_LVDS_LINKMAP_S;


/*
 * LVDS的数据位宽
 */
typedef enum hiDRV_PANEL_BITWIDTH_E
{
    HI_DRV_PANEL_BITWIDTH_8BIT = 0,
    HI_DRV_PANEL_BITWIDTH_10BIT,
    HI_DRV_PANEL_BITWIDTH_12BIT,

    HI_DRV_PANEL_BITWIDTH_BUTT,
} HI_DRV_PANEL_BITWIDTH_E;

/*
 * LVDS的数据格式
 */
typedef enum hiDRV_PANEL_LVDS_FMT_E
{
    HI_DRV_PANEL_LVDS_FMT_VESA = 0,
    HI_DRV_PANEL_LVDS_FMT_JEIDA,
    HI_DRV_PANEL_LVDS_FMT_FP,

    HI_DRV_PANEL_LVDS_FMT_BUTT,
} HI_DRV_PANEL_LVDS_FMT_E;


/*
 * 输出给屏的数据类型
 */
typedef enum hiDRV_PANEL_PANEL_TYPE_E
{
    HI_DRV_PANEL_TYPE_FHD = 0,       			/* 只支持FHD输出 */
    HI_DRV_PANEL_TYPE_UHD,           			/* 只支持UHD 4k输出 */    
	HI_DRV_PANEL_TYPE_FHD_4K_30_MISC,   		/* 支持FHD 50/60 和UHD24/25/30混合输出 */
	HI_DRV_PANEL_TYPE_FHD_4K_60_MISC,   		/* 支持FHD 50/60 和UHD50/60混合输出 */
	HI_DRV_PANEL_TYPE_4K_30_60_MISC, 	 		/* 支持UHD 24/25/30/50/60混合输出 */
	HI_DRV_PANEL_TYPE_FHD_4K_30_60_MISC,		/* 支持FHD 50/60 和UHD24/25/30/50/60混合输出 */
    
    HI_DRV_PANEL_TYPE_BUTT,
} HI_DRV_PANEL_TYPE_E;

typedef enum hiDRV_PANEL_DIVISION_MODE_E
{
    HI_DRV_PANEL_ONE_DIVISION_NORMAL_MODE,
    HI_DRV_PANEL_ONE_DIVISION_OE_MODE,
    HI_DRV_PANEL_TWO_DIVISION_MODE,

    HI_DRV_PANEL_DIVISION_MODE_BUTT,

} HI_DRV_PANEL_DIVISION_MODE_E;

/*
 *Misc Panel Timming Type
 */
typedef enum hiDRV_PANEL_TIMMING_E
{
    HI_DRV_PANEL_TIMMING_FHD_30Hz = 0,  /* FHD 24/25/30Hz */
	HI_DRV_PANEL_TIMMING_FHD_60Hz,      /* FHD 50/60Hz */
	HI_DRV_PANEL_TIMMING_FHD_120Hz,     /* FHD 100/120Hz */
	HI_DRV_PANEL_TIMMING_4K2K_30Hz,     /* 4K2K 24/25/30Hz */
	HI_DRV_PANEL_TIMMING_4K2K_60Hz,     /* 4K2K 50/60Hz*/	
	HI_DRV_PANEL_TIMMING_4K1K_120Hz,	/* 4K1K 100/120Hz*/	
	
	HI_DRV_PANEL_TIMMING_MAX,
}HI_DRV_PANEL_TIMMING_E;

typedef struct hiDRV_PANEL_TIMING_S
{
    HI_U32 u32PixelClk; //60 000 000 ~ 300 000 000
    HI_U32 u32Htotal;   //1280~ 5000
    HI_U32 u32Vtotal;   //720 ~ 3000
    HI_U16 u16HsyncFP;         /* Hsync 前肩宽度 */ //0~1000
    HI_U16 u16VsyncFP;         /* Vsync 前肩宽度 */ //0~1000
    
}HI_DRV_PANEL_TIMING_S;

typedef struct hiDRV_PANEL_TIMING_OLD_S
{
    HI_U32 u32PixelClk; //60 000 000 ~ 300 000 000
    HI_U32 u32Htotal;   //1280~ 5000
    HI_U32 u32Vtotal;   //720 ~ 3000
    
}HI_DRV_PANEL_TIMING_OLD_S;

typedef struct hiDRV_PANEL_MISC_TIMING_S
{
    HI_U32                u16HsyncWidth;      /* Hsync 宽度 */
    HI_U32                u16VsyncWidth;      /* Vsync 宽度 */
    HI_DRV_PANEL_TIMING_S stTiming60Hz;       /* Panel 输出60Hz/30Hz timing */
    HI_DRV_PANEL_TIMING_S stTiming50Hz;       /* Panel 输出50Hz/25Hz timing */
    HI_DRV_PANEL_TIMING_S stTiming48Hz;       /* Panel 输出48Hz/24Hz timing */  

}HI_DRV_PANEL_MISC_TIMING_S;

typedef struct hiDRV_PANEL_MISC_S
{
	HI_DRV_PANEL_TIMMING_E enTimmingType;   /* Disp 期望混合屏分辨率类型  */
	HI_U32                 u32FrmRate;      /* Disp 期望输出帧率 */
}HI_DRV_PANEL_MISC_S;


typedef enum hiDRV_PANEL_VBO_DATAMODE_E
{
    HI_DRV_PANEL_VBO_DATAMODE_30BIT444 = 0,
    HI_DRV_PANEL_VBO_DATAMODE_36BIT444,
    HI_DRV_PANEL_VBO_DATAMODE_24BIT444,
    HI_DRV_PANEL_VBO_DATAMODE_18BIT444,
    HI_DRV_PANEL_VBO_DATAMODE_24BIT422,
    HI_DRV_PANEL_VBO_DATAMODE_20BIT422,
    HI_DRV_PANEL_VBO_DATAMODE_16BIT422,

    HI_DRV_PANEL_VBO_DATAMODE_BUTT,
} HI_DRV_PANEL_VBO_DATAMODE_E;


typedef enum hiDRV_PANEL_VBO_BYTE_NUM_E
{
    HI_DRV_PANEL_VBO_BYTE_NUM_3 = 3,
    HI_DRV_PANEL_VBO_BYTE_NUM_4 = 4,
    HI_DRV_PANEL_VBO_BYTE_NUM_5 = 5,

    HI_DRV_PANEL_VBO_BYTE_NUM_BUTT,
} HI_DRV_PANEL_VBO_BYTE_NUM;

/*
 * VB1驱动电流
 */
typedef enum hiDRV_PANEL_VBO_CURRENT_E
{
    HI_DRV_PANEL_VBO_CURRENT_300MV = 0,
    HI_DRV_PANEL_VBO_CURRENT_200MV,
    HI_DRV_PANEL_VBO_CURRENT_250MV,
    HI_DRV_PANEL_VBO_CURRENT_350MV,
    HI_DRV_PANEL_VBO_CURRENT_400MV,

    HI_DRV_PANEL_VBO_CURRENT_BUTT,
} HI_DRV_PANEL_VBO_CURRENT_E;

/*
 * VB1预加重
 */
typedef enum hiDRV_PANEL_VBO_EMP_E
{
    HI_DRV_PANEL_VBO_EMP_0DB = 0,
    HI_DRV_PANEL_VBO_EMP_2DB,
    HI_DRV_PANEL_VBO_EMP_3P5DB,
    HI_DRV_PANEL_VBO_EMP_6DB,

    HI_DRV_PANEL_VBO_EMP_BUTT,
} HI_DRV_PANEL_VBO_EMP_E;

/*
*   VBO 源终端调优电阻
*/
typedef enum hiDRV_PANEL_VBO_RESISTOR_E
{
    HI_DRV_PANEL_VBO_RESISTOR_50OHM = 0,
    HI_DRV_PANEL_VBO_RESISTOR_44OHM,
    HI_DRV_PANEL_VBO_RESISTOR_70OHM,
    HI_DRV_PANEL_VBO_RESISTOR_IMPEDANCE,

    HI_DRV_PANEL_VBO_RESISTOR_BUTT,
} HI_DRV_PANEL_VBO_RESISTOR_E;

/*
*   VBO CDR Training 模式
*/
typedef enum hiDRV_PANEL_VBO_TEST_MODE_E
{
    HI_DRV_PANEL_VBO_TEST_MODE_OVERTURN_DATA,
    HI_DRV_PANEL_VBO_TEST_MODE_K285PLUS_DATA,
    HI_DRV_PANEL_VBO_TEST_MODE_K285REDUCE_DATA,
    HI_DRV_PANEL_VBO_TEST_MODE_INCREASE_DATA,
    HI_DRV_PANEL_VBO_TEST_MODE_PRBS10_DATA,

    HI_DRV_PANEL_VBO_TEST_MODE_BUTT,
} HI_DRV_PANEL_VBO_TEST_MODE_E;

typedef enum hiDRV_PANEL_INTFTYPE_E
{
    HI_DRV_PANEL_PANEL_INTFTYPE_LVDS = 0,
    HI_DRV_PANEL_PANEL_INTFTYPE_VBONE,
    HI_DRV_PANEL_PANEL_INTFTYPE_MINLVDS,

    HI_DRV_PANEL_PANEL_INTFTYPE_BUTT,
} HI_DRV_PANEL_INTFTYPE_E;

typedef enum hiDRV_PANEL_LDM_DEMO_MODE_E
{
    HI_DRV_PANEL_LDM_DEMO_OFF,
    HI_DRV_PANEL_LDM_DEMO_HORSELIGHT,
    HI_DRV_PANEL_LDM_DEMO_LEFT_HALF,
    HI_DRV_PANEL_LDM_DEMO_RIGHT_HALF,
    HI_DRV_PANEL_LDM_DEMO_TOP_HALF,
    HI_DRV_PANEL_LDM_DEMO_BOTTOM_HALF,
    
    HI_DRV_PANEL_LDM_DEMO_BUTT
}HI_DRV_PANEL_LDM_DEMO_MODE_E;

typedef struct hiDRV_PANEL_LDM_TABLE_S
{
    HI_U32 u32TableHorNum;
    HI_U32 u32TableVerNum;
    
}DRV_PANEL_LDM_TABLE_S, *DRV_PANEL_LDM_TABLE_PS;

typedef struct hiDRV_PANEL_LOCALDIMMING_S
{
	HI_BOOL                 bLDMSupport;            /**<LocalDimming support *//**CNcomment: LocalDimming支持标志 */
    
    HI_U32                  u32RegGetHorNum;        /**<set to logic horNumber count *//**CNcomment: 设置给逻辑的水平分区个数 */
    HI_U32                  u32RegGetVerNum;        /**<set to logic VerNumber count *//**CNcomment: 设置给逻辑的垂直分区个数 */
    HI_U32                  u32RegGetTotalNum;      /**<Get Ldm Data number from logic *//**CNcomment: 从逻辑获取的总的LocalDimming数据的个数 */
    
    HI_BOOL                 bHorUnregular;          /**<Hor Unregular *//**CNcomment: 是否为水平不规则 */
    HI_U32                  u32ActLdmTableMemCnt;   /**<Unregular Table Count *//**CNcomment: 实际的不规则分区个数 */
    DRV_PANEL_LDM_TABLE_PS  stActLdmTab;          /**<Unregular Table *//**CNcomment: 实际的不规则分区表 */
    HI_U32                  u32ActTotalNum;         /**<Actual LocalDimming Total Count *//**CNcomment: 实际需要的LocalDimming数据个数 */

    HI_U32                  u32ProtHeadLen;         /**<Protocol head Len *//**CNcomment: 协议头长度 */
    HI_U32                  u32ProtTailLen;         /**<Protocol tail Len *//**CNcomment: 协议尾长度 */

    HI_U32                  u32ProtDataLen;         /**<Protocol Data Len *//**CNcomment: 完整的协议数据长度 */
    
}DRV_PANEL_LDM_INFO_S;

/**panel fixate type *//**CNcomment:panel 固定帧率类型*/
typedef enum hiDRV_PANEL_FIXRATE_TYPE_E
{
	HI_DRV_PANEL_FIXRATE_TYPE_NONE	= 0,	 /**<fixrate type is none *//**CNcomment: 不固定输出帧率 */
    HI_DRV_PANEL_FIXRATE_TYPE_FHD_50HZ,		 /**<fixrate type is fhd50 *//**CNcomment: 固定FHD50输出 */
    HI_DRV_PANEL_FIXRATE_TYPE_FHD_60HZ,      /**<fixrate type is fhd60 *//**CNcomment: 固定FHD60输出 */
	HI_DRV_PANEL_FIXRATE_TYPE_UHD_50HZ, 	 /**<fixrate type is uhd50 *//**CNcomment: 固定UHD50输出 */
	HI_DRV_PANEL_FIXRATE_TYPE_UHD_60HZ, 	 /**<fixrate type is uhd60 *//**CNcomment: 固定UHD60输出 */
    
    HI_DRV_PANEL_FIXRATE_TYPE_BUTT,       /**<Invalid value*//**<CNcomment:非法边界值*/
}HI_DRV_PANEL_FIXRATE_TYPE_E;

/**panel Timming Change type *//**CNcomment:panel Timming信息变化方式 */
typedef enum hiDRV_PANEL_TIMING_CHANGE_E
{
    HI_DRV_PANEL_TIMING_CHANGE_INSTANT = 0,  /* Normal mode change, instant change */
    HI_DRV_PANEL_TIMING_CHANGE_GRADUAL_VT,   /* Vtotal change gradual */ 
    HI_DRV_PANEL_TIMING_CHANGE_GRADUAL_HT,   /* Htotal change gradual */
    HI_DRV_PANEL_TIMING_CHANGE_GRADUAL_CLK,  /* PixelClk change gradual*/
    HI_DRV_PANEL_TIMING_CHANGE_BUTT,

}HI_DRV_PANEL_TIMING_CHANGE_E;

typedef struct hiDRV_PANEL_FIX_INFO_S
{
    HI_BOOL bFix;
    HI_U32  u32OutFrmRate;
	HI_DRV_PANEL_TIMMING_E enTimmingType;

}HI_DRV_PANEL_FIX_INFO_S;

typedef struct hiDRV_PANEL_DIM_STRENGTH_RANGE_S
{
    HI_U32 u32MinStrength;
    HI_U32 u32MaxStrength;

}HI_DRV_PANEL_DIM_STRENGTH_RANGE_S;

typedef struct hiDRV_PANEL_VBOATTR_S
{
    HI_BOOL bGroupSwap;                         /* 0：Lane0~3输出RGB0的数据，Lane4~7输出RGB1的数据 */
    HI_BOOL bLeftInternalSwap;                  /* Lane0~3内部的数据互换*/
    HI_BOOL bRightInternalSwap;                 /* Lane4~7内部的数据互换*/
    HI_BOOL bBit0AtHighBit;                     /* Bit0是否在最高位,默认在False */
    HI_DRV_PANEL_VBO_DATAMODE_E enDataMode;     /* Vbone数据格式 */
    HI_DRV_PANEL_VBO_BYTE_NUM   enVb1ByteNum;   /* Vbone每个像素的字节数 */
    HI_DRV_PANEL_VBO_CURRENT_E  enVb1Current;   /* Vbone Swing */
    HI_DRV_PANEL_VBO_EMP_E      enVb1Emphasis;  /* Vbone Pre-emphasis */
    HI_U32                      u32Vb1SpreadRatio; /* Vb1 Spread Ratio from 0 to 31 */
    HI_DRV_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;
        
}HI_DRV_PANEL_VBOATTR_S;



typedef struct hiDRV_PANEL_LVDSATTR_S
{
    HI_U32                       u32LvdsSpreadRatio;    /* 展频的比例(10 表示 1% ) [0-31]*/ //0~ 31
    HI_DRV_PANEL_LVDS_SSFREQ_E   enLvdsSpreadFreq;      /* 展频的频率(单位: KHz) */
    HI_DRV_PANEL_LVDS_FMT_E      enLvdsFmt;             /* LVDS的格式 */
    HI_DRV_PANEL_LVDS_LINKMAP_S  stLvdsLinkMap;         /* LVDS 4个Link的24种组合 */
    HI_DRV_PANEL_LVDS_CURRENT_E  enLvdsDrvCurrent;      /* LVDS 驱动电流 */
    HI_DRV_PANEL_LVDS_VOLTAGE_E  enLvdsComVoltage;      /* LVDS 共模电压 */

        
}HI_DRV_PANEL_LVDSATTR_S;


typedef struct hiDRV_PANEL_INTF_ATTR_S
{   
    HI_BOOL                     bIntfEnable;
    HI_BOOL                     bSpreadEnable;
    
    /* Lvds Intf Attr */
    HI_U32                      u32LvdsSpreadRatio; /* LVDS Spread Ratio from 0 to 31 */
    HI_DRV_PANEL_LVDS_SSFREQ_E  enLvdsSpreadFreq;
    HI_DRV_PANEL_LVDS_CURRENT_E enLvdsDrvCurrent;
    HI_DRV_PANEL_LVDS_VOLTAGE_E enLvdsComVoltage;

    /* Vb1 Intf Attr */
    HI_U32                      u32Vb1SpreadRatio; /* Vb1 Spread Ratio from 0 to 31 */
    HI_DRV_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;
    HI_DRV_PANEL_VBO_CURRENT_E  enVb1Current;
    HI_DRV_PANEL_VBO_EMP_E      enVb1Emphasis;
    
}HI_DRV_PANEL_INTF_ATTR_S;

typedef struct hiDRV_PANEL_OLD_INFO_S
{
    HI_CHAR                     chName[48];         /* Panel Name */
    HI_U32                      u32PanelWidth;      /* Panel 水平分辨率 */ //1280~4096
    HI_U32                      u32PanelHeight;     /* Panel 垂直分辨率 */ //720 ~ 2160
    HI_U32                      u32FrameRateMax;    /* Panel 最大输出帧率 */ //24 ~ 120
    HI_BOOL                     bSupport48Hz;       /* Panel 是否支持48HZ */
    HI_DRV_DISP_STEREO_E        en3DType;           /* 屏的输出类型*/   
    HI_DRV_PANEL_TYPE_E         enResolutionType;   /* 屏的输出分辨率类型*/ 
    HI_DRV_PANEL_INTFTYPE_E     enIntfType;         /* 屏的接口类型*/
    HI_DRV_PANEL_LINKTYPE_E     enPanelLinkType;    /* Panel Link类型 */
    HI_DRV_PANEL_BITWIDTH_E     enPanelBitWidth;    /* Panel的数据位宽 */

    HI_DRV_PANEL_LVDSATTR_S     stLvdsAttr;         /* Lvds参数，仅在LVDS接口的时候使用此参数 */
    HI_DRV_PANEL_VBOATTR_S      stVboAttr;          /* Vb1参数，仅在VBO接口的时候使用此参数 */

    HI_DRV_PANEL_TIMING_OLD_S   stTiming60Hz;       /* Panel 输出60Hz/120Hz timing */
    HI_DRV_PANEL_TIMING_OLD_S   stTiming50Hz;       /* Panel 输出50Hz/100Hz timing */
    HI_DRV_PANEL_TIMING_OLD_S   stTiming48Hz;       /* Panel 输出48Hz/96Hz timing */  
    HI_U32                      u32HsyncWidth;      /* Hsync 宽度 */   //0~1000
    HI_U32                      u32VsyncWidth;      /* Vsync 宽度 */   //0~ 1000
    HI_U32                      u32HsyncFP;         /* Hsync 前肩宽度 */ //0~1000
    HI_U32                      u32VsyncFP;         /* Vsync 前肩宽度 */ //0~1000

    HI_BOOL                     bHSyncOutput;       /* Panel Vsync是否输出，0:为禁止输出  1:为输出 */ 
    HI_BOOL                     bVSyncOutput;       /* Panel Hsync 是否输出，0:为禁止输出  1:为输出 */ 
    HI_BOOL                     bHSyncNegative;     /* Panel Hsync 是否为负极性 */ 
    HI_BOOL                     bVSyncNegative;     /* Panel Vsync 是否为负极性 */
    HI_BOOL                     bDeNegative;        /* Panel DE 是否为负极性 */
    
    HI_BOOL                     bPwmPostive;        /* Panel backlight pwm 是否为正极性 */
    HI_U32                      u32DimmingFreq60hz; /* 背光dimming 在60Hz/120Hz 输出时候的频率 */ //60~ 60000
    HI_U32                      u32DimmingFreq50hz; /* 背光dimming 在50Hz/100Hz输出时候的频率 */ //50~ 60000
    HI_U32                      u32DimmingFreq48hz; /* 背光dimming 在48Hz/96Hz输出时候的频率 */ //48~ 60000
    
    HI_U32                      u32IntfSignalOnDelay;   /* 在给TCON供电之后延时打开接口信号信号的时间 */ //0~ 2000
    HI_U32                      u32BLOnDelay;           /* 在打开接口信号信号之后延时打开背光的时间 */ //0~ 2000
    HI_U32                      u32BLOffDelay;          /* 在关闭背光之后延时关闭接口信号信号的时间 */ //0~ 2000
    HI_U32                      u32IntfSignalOffDelay;  /* 在关闭接口信号信号之后延时关闭TCON供电的时间 */ //0~ 2000

    HI_BOOL                     bFrmRateChangeBlack;    /* 帧率变化时是否黑屏 */
    HI_U32                      u32MuteTime;            /* 黑屏的时间，默认值0~5000 Ms */
 
    HI_BOOL                     bLocalDimmingSupport;   /* 是否支持LocalDimming */
    HI_U32                      u32HorAreaNum;          /* 支持LocalDimming时水平分区的个数 */
    HI_U32                      u32VerAreaNum;          /* 支持LocalDimming时垂直分区的个数 */

    HI_DRV_PANEL_FLIP_TYPE_E    enPanelFlipType;       /* Panel的翻转类型*/
    HI_DRV_PANEL_FIXRATE_TYPE_E enPanelFixRateType;

    HI_DRV_PANEL_TIMING_CHANGE_E enTimChangeType;       /*value is 0,1,2,3*/
    HI_U32                      u32ChangeStep;          /*value >=0*/
    HI_DRV_PANEL_DIVISION_MODE_E enDivisionMode;

    HI_U32                      u32Resove[5];          /* 0~8共9个Reserved 32位变量，默认值0xffffffff */

}HI_DRV_PANEL_OLD_INFO_S;

typedef struct hiDRV_PANEL_INFO_S
{
    HI_CHAR                     chName[48];         /* Panel Name */
    HI_U32                      u32PanelWidth;      /* Panel 水平分辨率 */ //1280~4096
    HI_U32                      u32PanelHeight;     /* Panel 垂直分辨率 */ //720 ~ 2160
    HI_U32                      u32FrameRateMax;    /* Panel 最大输出帧率 */ //24 ~ 120
    HI_BOOL                     bSupport48Hz;       /* Panel 是否支持48HZ */
    HI_DRV_DISP_STEREO_E        en3DType;           /* 屏的输出类型*/   
    HI_DRV_PANEL_TYPE_E         enResolutionType;   /* 屏的输出分辨率类型*/ 
    HI_DRV_PANEL_INTFTYPE_E     enIntfType;         /* 屏的接口类型*/
    HI_DRV_PANEL_LINKTYPE_E     enPanelLinkType;    /* Panel Link类型 */
    HI_DRV_PANEL_BITWIDTH_E     enPanelBitWidth;    /* Panel的数据位宽 */

    HI_DRV_PANEL_LVDSATTR_S     stLvdsAttr;         /* Lvds参数，仅在LVDS接口的时候使用此参数 */
    HI_DRV_PANEL_VBOATTR_S      stVboAttr;          /* Vb1参数，仅在VBO接口的时候使用此参数 */

    HI_DRV_PANEL_TIMING_S       stTiming60Hz;       /* Panel 输出60Hz/120Hz timing */
    HI_DRV_PANEL_TIMING_S       stTiming50Hz;       /* Panel 输出50Hz/100Hz timing */
    HI_DRV_PANEL_TIMING_S       stTiming48Hz;       /* Panel 输出48Hz/96Hz timing */  
    HI_U16                      u16HsyncWidth;      /* Hsync 宽度 */   //0~1000
    HI_U16                      u16VsyncWidth;      /* Vsync 宽度 */   //0~ 1000

    HI_BOOL                     bHSyncOutput;       /* Panel Vsync是否输出，0:为禁止输出  1:为输出 */ 
    HI_BOOL                     bVSyncOutput;       /* Panel Hsync 是否输出，0:为禁止输出  1:为输出 */ 
    HI_BOOL                     bHSyncNegative;     /* Panel Hsync 是否为负极性 */ 
    HI_BOOL                     bVSyncNegative;     /* Panel Vsync 是否为负极性 */
    HI_BOOL                     bDeNegative;        /* Panel DE 是否为负极性 */
    
    HI_BOOL                     bPwmPostive;        /* Panel backlight pwm 是否为正极性 */
    HI_U32                      u32DimmingFreq60hz; /* 背光dimming 在60Hz/120Hz 输出时候的频率 */ //60~ 60000
    HI_U32                      u32DimmingFreq50hz; /* 背光dimming 在50Hz/100Hz输出时候的频率 */ //50~ 60000
    HI_U32                      u32DimmingFreq48hz; /* 背光dimming 在48Hz/96Hz输出时候的频率 */ //48~ 60000
    
    HI_U32                      u32IntfSignalOnDelay;   /* 在给TCON供电之后延时打开接口信号信号的时间 */ //0~ 2000
    HI_U32                      u32BLOnDelay;           /* 在打开接口信号信号之后延时打开背光的时间 */ //0~ 2000
    HI_U32                      u32BLOffDelay;          /* 在关闭背光之后延时关闭接口信号信号的时间 */ //0~ 2000
    HI_U32                      u32IntfSignalOffDelay;  /* 在关闭接口信号信号之后延时关闭TCON供电的时间 */ //0~ 2000

    HI_BOOL                     bFrmRateChangeBlack;    /* 帧率变化时是否黑屏 */
    HI_U32                      u32MuteTime;            /* 黑屏的时间，默认值0~5000 Ms */
 
    HI_BOOL                     bLocalDimmingSupport;   /* 是否支持LocalDimming */
    HI_U32                      u32HorAreaNum;          /* 支持LocalDimming时水平分区的个数 */
    HI_U32                      u32VerAreaNum;          /* 支持LocalDimming时垂直分区的个数 */

    HI_DRV_PANEL_FLIP_TYPE_E    enPanelFlipType;       /* Panel的翻转类型*/
    HI_DRV_PANEL_FIXRATE_TYPE_E enPanelFixRateType;

    HI_DRV_PANEL_TIMING_CHANGE_E enTimChangeType;       /*value is 0,1,2,3*/
    HI_U32                      u32ChangeStep;          /*value >=0*/
    HI_DRV_PANEL_DIVISION_MODE_E enDivisionMode;

    HI_U32                      u32Resove[5];          /* 0~8共9个Reserved 32位变量，默认值0xffffffff */

}HI_DRV_PANEL_INFO_S;

typedef struct hiDRV_PANEL_CFG_S
{
    HI_U32                       u32PanelWidth;    /* Panel 水平分辨率 */
    HI_U32                       u32PanelHeight;   /* Panel 垂直分辨率 */
    HI_U32                       u32OutFrmRate;    /* Panel 最大输出帧率 */
    HI_DRV_DISP_STEREO_E         en3DType;         /* 屏的输出类型*/   
    HI_DRV_PANEL_TIMING_S        stPanelTiming;    /* Panel 输出60Hz/120Hz timing */
    HI_DRV_PANEL_TIMING_CHANGE_E enTimChangeType;
    HI_U32                       u32TimChangeStep;
    HI_U16                       u16HsyncWidth;    /* Hsync 宽度 */
    HI_U16                       u16VsyncWidth;    /* Vsync 宽度 */
    HI_DRV_PANEL_INTFTYPE_E      enIntfType;
    HI_DRV_PANEL_VBO_BYTE_NUM    enVb1ByteNum;
    HI_DRV_PANEL_LINKTYPE_E      enPanelLinkType;
    HI_DRV_PANEL_FLIP_TYPE_E     enPanelFlipType;
    HI_DRV_PANEL_TYPE_E          enResolutionType;
    HI_BOOL                      bFrmRateChangeBlack;   /* 帧率变化时是否黑屏 */
    HI_U32                       u32MuteTime;           /* 黑屏的时间，默认值0~5000 Ms */
    HI_DRV_PANEL_DIVISION_MODE_E enDivisionMode;

}HI_DRV_PANEL_CFG_S;

typedef struct hiDRV_PANEL_3D_SYNC_INFO_S
{
    HI_DRV_3D_EYE_E enCurrentDispEye;
    HI_BOOL         bSyncEn;
	HI_BOOL         bGlassEn;
    
}HI_DRV_PANEL_3D_SYNC_INFO_S;

typedef enum hiDRV_PANEL_ASPECT_E
{
    HI_DRV_PANEL_ASPECT_4_3 = 0,
    HI_DRV_PANEL_ASPECT_16_9,
    HI_DRV_PANEL_ASPECT_14_9,
    HI_DRV_PANEL_ASPECT_21_9,
    HI_DRV_PANEL_ASPECT_16_10,
    
    HI_DRV_PANEL_ASPECT_BUTT,
}HI_DRV_PANEL_ASPECT_E;


typedef struct hiDRV_PANEL_ATTR_S
{   
    HI_U32                  u32Width;
    HI_U32                  u32Height;
    HI_DRV_PANEL_ASPECT_E   enAspect;
    HI_DRV_DISP_STEREO_E    en3dMode;
}HI_DRV_PANEL_ATTR_S;


/*==== Structure Definition end ==== */


/*************************** API declaration ****************************/

HI_S32 HI_DRV_PANEL_Init(HI_VOID);
HI_S32 HI_DRV_PANEL_DeInit(HI_VOID);


/* 如果从文件系统读屏参则上层必须调用此接口设置屏参在文件系统中的path */
HI_S32 HI_DRV_PANEL_SetPath(HI_CHAR* pcPath);

/* 上层通过此接口选择屏参表里面相应的屏参 */
HI_S32 HI_DRV_PANEL_SetIndex(HI_U32 u32Index);

/* 上层通过调用此接口获取屏参表里面屏参的个数 */
HI_S32 HI_DRV_PANEL_GetTotalNum(HI_U32 *pu32TotalNum);

/* MW在初始化的时候要调用此接口设置当前使用的屏参信息 */
HI_S32 HI_DRV_PANEL_SetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);
HI_S32 HI_DRV_PANEL_GetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);

HI_S32 HI_DRV_PANEL_SetTCONPower(HI_BOOL bEnable);
HI_S32 HI_DRV_PANEL_SetBacklightPower(HI_BOOL bEnable);

/* 如果BOOT已点屏MW初始化不能调用SetPowerOn此接口,只有切换屏参和关机才能调用 */
HI_S32 HI_DRV_PANEL_SetPowerOn(HI_BOOL bEnable);
HI_S32 HI_DRV_PANEL_GetPowerOn( HI_BOOL *pbEnable);

HI_S32 HI_DRV_PANEL_SetBacklightEnable(HI_BOOL bEnable);
HI_S32 HI_DRV_PANEL_GetBacklightEnable(HI_BOOL *pbEnable);

HI_S32 HI_DRV_PANEL_SetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr); 
HI_S32 HI_DRV_PANEL_GetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr);

HI_S32 HI_DRV_PANEL_GetPanelAttr(HI_DRV_PANEL_ATTR_S *pstPanelAttr);

HI_S32 HI_DRV_PANEL_Set3dSignal(HI_DRV_PANEL_3D_SYNC_INFO_S *pst3dSyncInfo);

HI_S32 HI_DRV_PANEL_GetPanelCfg(HI_DRV_DISP_EXPECT_INFO_S *pstDispInfo, HI_DRV_PANEL_CFG_S *pstPanelCfg);
HI_S32 HI_DRV_PANEL_SetOutFrmRate(HI_U32 *pu32OutFrmRate);

HI_S32 HI_DRV_PANEL_SetIntfPower(HI_BOOL bPowerOn);

HI_S32 PANEL_DRV_LocalDimmingRegist(HI_VOID);

HI_VOID PANEL_DRV_LocalDimmingUnRegist(HI_VOID);

HI_S32 HI_DRV_PANEL_SetDynamicBLEnable(HI_BOOL bEnable);

HI_S32 HI_DRV_PANEL_GetDynamicBLEnable(HI_BOOL *pbEnable);

HI_S32 HI_DRV_PANEL_GetDimStrengthRange(HI_DRV_PANEL_DIM_STRENGTH_RANGE_S *pstRange);

HI_S32 HI_DRV_PANEL_SetDimStrengthLevel(HI_U32 u32Level);

HI_S32 HI_DRV_PANEL_GetDimStrengthLevel(HI_U32 *pu32Level);

HI_S32 HI_DRV_PANEL_SetLocalDimmingEnable(HI_BOOL bEnable);

HI_S32 HI_DRV_PANEL_GetLocalDimmingEnable(HI_BOOL *pbEnable);

HI_S32  HI_DRV_PANEL_GetDivideBlData(HI_U8 *pu8BlData);

HI_S32 HI_DRV_PANEL_SetLocaDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E enDemoMode);

HI_S32 HI_DRV_PANEL_GetLocaDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E *penDemoMode);

HI_S32 HI_DRV_PANEL_SetBacklightLevel(HI_U32 u32Level);

HI_S32 HI_DRV_PANEL_GetBacklightLevel(HI_U32 *pu32Level);

HI_S32 HI_DRV_PANEL_SetFixOutRate(HI_DRV_PANEL_FIX_INFO_S *pstFixInfo);

HI_S32 HI_DRV_PANEL_GetFixOutRate(HI_DRV_PANEL_FIX_INFO_S *pstFixInfo);

HI_VOID HI_DRV_PANEL_SetPwmCfg(HI_VOID);

HI_VOID HI_DRV_PANEL_SetPwmDisable(HI_VOID);

/*==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
