/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_unf_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/10/31
   Description   :
   History       :
   1.Date        : 2013/10/31
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


#ifndef  __HI_UNF_PANEL_H__
#define  __HI_UNF_PANEL_H__

/* add include here */
#include "hi_unf_disp.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PANEL */
/** @{ */  /** <!-- [PANEL] */

/**LVDS voltage *//**CNcomment:LVDS共模电压  */
typedef enum hiUNF_PANEL_LVDS_VOLTAGE_E
{
    HI_UNF_PANEL_LVDS_VOLTAGE_1250MV = 0,   /**<LVDS voltage value 1250MV*/ /**<CNcomment:LVDS 共模电压1250MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1100MV,       /**<LVDS voltage value 1100MV*/ /**<CNcomment:LVDS 共模电压1100MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1150MV,       /**<LVDS voltage value 1150MV*/ /**<CNcomment:LVDS 共模电压1150MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1200MV,       /**<LVDS voltage value 1200MV*/ /**<CNcomment:LVDS 共模电压1200MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1300MV,       /**<LVDS voltage value 1300MV*/ /**<CNcomment:LVDS 共模电压1300MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1350MV,       /**<LVDS voltage value 1350MV*/ /**<CNcomment:LVDS 共模电压1350MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1400MV,       /**<LVDS voltage value 1400MV*/ /**<CNcomment:LVDS 共模电压1400MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1450MV,       /**<LVDS voltage value 1450MV*/ /**<CNcomment:LVDS 共模电压1450MV */

    HI_UNF_PANEL_LVDS_VOLTAGE_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LVDS_VOLTAGE_E;


/**LVDS current *//**CNcomment:LVDS驱动电流  */
typedef enum hiUNF_PANEL_LVDS_CURRENT_E
{
    HI_UNF_PANEL_LVDS_CURRENT_200MV = 0,    /**<LVDS current value 200MV*/ /**<CNcomment:LVDS 驱动电流200MV */
    HI_UNF_PANEL_LVDS_CURRENT_150MV,        /**<LVDS current value 150MV*/ /**<CNcomment:LVDS 驱动电流150MV */
    HI_UNF_PANEL_LVDS_CURRENT_250MV,        /**<LVDS current value 250MV*/ /**<CNcomment:LVDS 驱动电流250MV */
    HI_UNF_PANEL_LVDS_CURRENT_300MV,        /**<LVDS current value 300MV*/ /**<CNcomment:LVDS 驱动电流300MV */
    HI_UNF_PANEL_LVDS_CURRENT_350MV,        /**<LVDS current value 350MV*/ /**<CNcomment:LVDS 驱动电流350MV */
    HI_UNF_PANEL_LVDS_CURRENT_400MV,        /**<LVDS current value 400MV*/ /**<CNcomment:LVDS 驱动电流400MV */
    HI_UNF_PANEL_LVDS_CURRENT_450MV,        /**<LVDS current value 450MV*/ /**<CNcomment:LVDS 驱动电流450MV */
    HI_UNF_PANEL_LVDS_CURRENT_500MV,        /**<LVDS current value 500MV*/ /**<CNcomment:LVDS 驱动电流500MV */

    HI_UNF_PANEL_LVDS_CURRENT_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LVDS_CURRENT_E;


/**LVDS spread frequency *//**CNcomment:LVDS展频频率  */
typedef enum hiUNF_PANEL_LVDS_SSFREQ_E
{
    HI_UNF_PANEL_LVDS_SSFREQ_93P75KHZ   = 2,    /**<LVDS spread frequency 93P75KHZ*/ /**<CNcomment:LVDS展频频率93P75KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_62P5KHZ    = 3,    /**<LVDS spread frequency 62P5KHZ*/ /**<CNcomment:LVDS展频频率62P5KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_46P875KHZ  = 4,    /**<LVDS spread frequency 46P875KHZ*/ /**<CNcomment:LVDS展频频率46P875KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_37P5KHZ    = 5,    /**<LVDS spread frequency 37P5KHZ*/ /**<CNcomment:LVDS展频频率37P5KHZ */

    HI_UNF_PANEL_LVDS_SSFREQ_BUTT,              /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LVDS_SSFREQ_E;

/**VBO spread frequency *//**CNcomment:VBO展频频率  */
typedef enum hiUNF_PANEL_VBO_SSFREQ_E
{
    HI_UNF_PANEL_VBO_SSFREQ_46P875KHZ   = 2,    /**<VBO spread frequency 46P875KHZ*/ /**<CNcomment:VBO展频频率46P875KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_31P250KHZ   = 3,    /**<VBO spread frequency 31P250KHZ*/ /**<CNcomment:VBO展频频率31P250KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_23P438KHZ   = 4,    /**<VBO spread frequency 23P438KHZ*/ /**<CNcomment:VBO展频频率23P438KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_18P750KHZ   = 5,    /**<VBO spread frequency 18P750KHZ*/ /**<CNcomment:VBO展频频率18P750KHZ */

    HI_UNF_PANEL_VBO_SSFREQ_BUTT,               /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_VBO_SSFREQ_E;

typedef struct hiUNF_PANEL_3DATTR_RANGE_S
{
    HI_RANGE_S stDepthRange;
    HI_RANGE_S stViewRange;
    
}HI_UNF_PANEL_3DATTR_RANGE_S;

/**Panel flip type *//**CNcomment:Panel的翻转类型*/
typedef enum hiUNF_PANEL_FLIP_TYPE_E
{
    HI_UNF_PANEL_FLIP_TYPE_NONE = 0,     /**<Panel flip type is none*/ /**<CNcomment: normal */
    HI_UNF_PANEL_FLIP_TYPE_FLIP,         /**<Panel flip type is flip*/ /**<CNcomment: only flip*/
    HI_UNF_PANEL_FLIP_TYPE_MIRROR,       /**<Panel flip type is mirror*/ /**<CNcomment: only mirror */
	HI_UNF_PANEL_FLIP_TYPE_FLIP_MIRROR,  /**<Panel flip type is flip & mirror*/ /**<CNcomment: flip and mirror  */
	
    HI_UNF_PANEL_FLIP_TYPE_BUTT,
} HI_UNF_PANEL_FLIP_TYPE_E;

/**Panel link type *//**CNcomment:Panel的链接类型 */
typedef enum hiUNF_PANEL_LINKTYPE_E
{
    HI_UNF_PANEL_LINKTYPE_1LINK = 0,    /**<Panel link type is 1 link*/ /**<CNcomment:Panel的链接类型为1个Link */
    HI_UNF_PANEL_LINKTYPE_2LINK,        /**<Panel link type is 2 link*/ /**<CNcomment:Panel的链接类型为2个Link */
    HI_UNF_PANEL_LINKTYPE_4LINK,        /**<Panel link type is 4 link*/ /**<CNcomment:Panel的链接类型为4个Link */
    HI_UNF_PANEL_LINKTYPE_8LINK,        /**<Panel link type is 8 link*/ /**<CNcomment:Panel的链接类型为8个Link */
    
    HI_UNF_LVDS_LINKTYPE_BUTT,          /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LINKTYPE_E;

/**LVDS link map *//**CNcomment:Panel 接口为LVDS时每一个Link输出的像素 */
typedef enum hiUNF_PANEL_LVDS_LINKMAP_E
{
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL0 = 0,   /**<output pixel 0 */ /**<CNcomment:输出像素 0+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL1,       /**<output pixel 1 */ /**<CNcomment:输出像素 1+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL2,       /**<output pixel 2 */ /**<CNcomment:输出像素 2+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL3,       /**<output pixel 3 */ /**<CNcomment:输出像素 3+4*n */

    HI_UNF_PANEL_LVDS_LINKMAP_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LVDS_LINKMAP_E;

/**LVDS link map *//**CNcomment:Panel 接口为LVDS时的Link，是输出像素的一个组合 */
typedef struct hiUNF_PANEL_LVDS_LINKMAP_S
{
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink1;    /**<Link 1 */ /**<CNcomment:第1个Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink2;    /**<Link 2 */ /**<CNcomment:第2个Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink3;    /**<Link 3 */ /**<CNcomment:第3个Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink4;    /**<Link 4 */ /**<CNcomment:第4个Link */
} HI_UNF_PANEL_LVDS_LINKMAP_S;


/**LVDS bit width *//**CNcomment:LVDS的数据位宽 */
typedef enum hiUNF_PANEL_BITWIDTH_E
{
    HI_UNF_PANEL_BITWIDTH_8BIT = 0,     /**<bit width is 8 */ /**<CNcomment:位宽为8 */
    HI_UNF_PANEL_BITWIDTH_10BIT,        /**<bit width is 10 */ /**<CNcomment:位宽为10 */
    HI_UNF_PANEL_BITWIDTH_12BIT,        /**<bit width is 12 */ /**<CNcomment:位宽为12 */

    HI_UNF_PANEL_BITWIDTH_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_BITWIDTH_E;


/**LVDS format *//**CNcomment:LVDS的格式 */
typedef enum hiUNF_PANEL_LVDS_FMT_E
{
    HI_UNF_PANEL_LVDS_FMT_VESA = 0,     /**<LVDS format:VESA */ /**<CNcomment:LVDS格式为VESA */
    HI_UNF_PANEL_LVDS_FMT_JEIDA,        /**<LVDS format:JEIDA  */ /**<CNcomment:LVDS格式为JEIDA */
    HI_UNF_PANEL_LVDS_FMT_FP,           /**<LVDS format:FP  */ /**<CNcomment:LVDS格式为FP */

    HI_UNF_PANEL_LVDS_FMT_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_LVDS_FMT_E;


/**Screen data type *//**CNcomment:输出给屏的数据类型 */
typedef enum hiUNF_PANEL_PANEL_TYPE_E
{
    HI_UNF_PANEL_TYPE_FHD = 0,           /**<only support FHD output */ /**<CNcomment:只支持FHD输出 */
    HI_UNF_PANEL_TYPE_4K,                /**<only support UHD output */ /**<CNcomment:只支持UHD 4k输出 */
	  HI_UNF_PANEL_TYPE_FHD_4K_30_MISC,	 /**<support FHD and UHD 30 output */ /**<CNcomment: 支持FHD 50/60 和UHD24/25/30混合输出 */
	  HI_UNF_PANEL_TYPE_FHD_4K_60_MISC,	 /**<support FHD and UHD 60 output */ /**<CNcomment: 支持FHD 50/60 和UHD50/60混合输出 */
	  HI_UNF_PANEL_TYPE_4K_30_60_MISC,	 /**<support UHD Misc output */ /**<CNcomment: 支持UHD 24/25/30/50/60混合输出 */
	  HI_UNF_PANEL_TYPE_FHD_4K_30_60_MISC, /**<support FHD and UHD Misc output */ /**<CNcomment: 支持FHD 50/60 和UHD24/25/30/50/60混合输出 */
    
    HI_UNF_PANEL_TYPE_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_TYPE_E;

/**Panel timing info *//**CNcomment:Panel 的timing信息 */
typedef struct hiUNF_PANEL_TIMING_S
{
    HI_U32 u32PixelClk;     /**<output pixel clock */ /**<CNcomment:输出的像素时钟 */
    HI_U32 u32Htotal;       /**<output Horizontal Frequency */ /**<CNcomment:输出的行频 */
    HI_U32 u32Vtotal;       /**<output Vertical  Frequency */ /**<CNcomment:输出的场频 */
    HI_U16 u16HsyncFP;      /**<hsync fp *//**CNcomment:Hsync 前肩宽度 */
    HI_U16 u16VsyncFP;      /**<vsync fp *//**CNcomment:Vsync 前肩宽度 */
    
}HI_UNF_PANEL_TIMING_S;

/**VBO data mode *//**CNcomment:VBO的数据格式 */
typedef enum hiUNF_PANEL_VBO_DATAMODE_E
{
    HI_UNF_PANEL_VBO_DATAMODE_30BIT444 = 0, /**<VBO data mode is 30BIT444 */ /**<CNcomment:格式为30BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_36BIT444,     /**<VBO data mode is 36BIT444 */ /**<CNcomment:格式为36BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_24BIT444,     /**<VBO data mode is 24BIT444 */ /**<CNcomment:格式为24BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_18BIT444,     /**<VBO data mode is 18BIT444 */ /**<CNcomment:格式为18BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_24BIT422,     /**<VBO data mode is 24BIT422 */ /**<CNcomment:格式为24BIT422 */
    HI_UNF_PANEL_VBO_DATAMODE_20BIT422,     /**<VBO data mode is 20BIT422 */ /**<CNcomment:格式为20BIT422 */
    HI_UNF_PANEL_VBO_DATAMODE_16BIT422,     /**<VBO data mode is 16BIT422 */ /**<CNcomment:格式为16BIT422 */

    HI_UNF_PANEL_VBO_DATAMODE_BUTT,         /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_VBO_DATAMODE_E;

/**VBO pixel byte *//**CNcomment:VBO每个像素占的字节数*/
typedef enum hiUNF_PANEL_VBO_BYTE_NUM_E
{
    HI_UNF_PANEL_VBO_BYTE_NUM_3 = 3,    /**<pixel 3 byte */ /**<CNcomment:每个像素占3个字节 */
    HI_UNF_PANEL_VBO_BYTE_NUM_4 = 4,    /**<pixel 3 byte */ /**<CNcomment:每个像素占4个字节 */
    HI_UNF_PANEL_VBO_BYTE_NUM_5 = 5,    /**<pixel 5 byte */ /**<CNcomment:每个像素占5个字节 */

    HI_UNF_PANEL_VBO_BYTE_NUM_BUTT,     /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_VBO_BYTE_NUM;


/**VBO current *//**CNcomment:VBO驱动电流*/
typedef enum hiUNF_PANEL_VBO_CURRENT_E
{
    HI_UNF_PANEL_VBO_CURRENT_300MV = 0, /**<current is 300MV */ /**<CNcomment:驱动电流为300MV */
    HI_UNF_PANEL_VBO_CURRENT_200MV,     /**<current is 200MV */ /**<CNcomment:驱动电流为200MV */
    HI_UNF_PANEL_VBO_CURRENT_250MV,     /**<current is 250MV */ /**<CNcomment:驱动电流为250MV */
    HI_UNF_PANEL_VBO_CURRENT_350MV,     /**<current is 350MV */ /**<CNcomment:驱动电流为350MV */
    HI_UNF_PANEL_VBO_CURRENT_400MV,     /**<current is 400MV */ /**<CNcomment:驱动电流为400MV */

    HI_UNF_PANEL_VBO_CURRENT_BUTT,      /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_VBO_CURRENT_E;


/**VBO Pre-emphasis *//**CNcomment:VBO预加重*/
typedef enum hiUNF_PANEL_VBO_EMP_E
{
    HI_UNF_PANEL_VBO_EMP_0DB = 0,   /**<Pre-emphasis is 0DB */ /**<CNcomment:预加重为0DB */
    HI_UNF_PANEL_VBO_EMP_2DB,       /**<Pre-emphasis is 3P5DB */ /**<CNcomment:预加重为2DB */
    HI_UNF_PANEL_VBO_EMP_3P5DB,     /**<Pre-emphasis is 3P5DB */ /**<CNcomment:预加重为3P5DB */
    HI_UNF_PANEL_VBO_EMP_6DB,       /**<Pre-emphasis is 6DB */ /**<CNcomment:预加重为6DB */
    HI_UNF_PANEL_VBO_EMP_BUTT,      /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_VBO_EMP_E;


/**Panel interface type *//**CNcomment:Panel 的接口类型*/
typedef enum hiUNF_PANEL_INTFTYPE_E
{
    HI_UNF_PANEL_PANEL_INTFTYPE_LVDS = 0,   /**<interface type is LVDS */ /**<CNcomment:接口类型为LVDS */
    HI_UNF_PANEL_PANEL_INTFTYPE_VBONE,      /**<interface type is VBONE */ /**<CNcomment:接口类型为VBONE */
    HI_UNF_PANEL_PANEL_INTFTYPE_MINLVDS,    /**<interface type is MINLVDS */ /**<CNcomment:接口类型为MINLVDS */

    HI_UNF_PANEL_PANEL_INTFTYPE_BUTT,       /**<Invalid value*//**<CNcomment:非法边界值*/
} HI_UNF_PANEL_INTFTYPE_E;

/**VBO interface attr *//**CNcomment:VBO 的接口属性*/
typedef struct hiUNF_PANEL_VBOATTR_S
{
    HI_BOOL bGroupSwap;                             /**<screen left and right swap */ /**<CNcomment:输出画面左右半屏数据互换 */
    HI_BOOL bLeftInternalSwap;                      /**<screen left internal swap */ /**<CNcomment:Lane0~3内部的数据互换, 即左半屏的奇偶互换 */
    HI_BOOL bRightInternalSwap;                     /**<screen right internal swap */ /**<CNcomment:Lane4~7内部的数据互换, 即右半屏的奇偶互换 */
    HI_BOOL bBit0AtHighBit;                         /**<bit 0 at high bit */ /**<CNcomment:Bit0是否在最高位,默认在False */
    HI_UNF_PANEL_VBO_DATAMODE_E enDataMode;         /**<vbo data format */ /**<CNcomment:Vbone数据格式 */
    HI_UNF_PANEL_VBO_BYTE_NUM   enVb1ByteNum;       /**<vbo pixel byte */ /**<CNcomment:Vbone每个像素的字节数 */
    HI_UNF_PANEL_VBO_CURRENT_E  enVb1Current;       /**<Vbone Swing */ /**<CNcomment:Vbone驱动电流值 */
    HI_UNF_PANEL_VBO_EMP_E      enVb1Emphasis;      /**<Vbone Pre-emphasis */ /**<CNcomment:Vbone预加重 */
    HI_U32                      u32Vb1SpreadRatio;  /**<Vb1 Spread Ratio from 0 to 31 */ /**<CNcomment:Vbone展屏比 */
    HI_UNF_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;    /**<VBO spread frequency */ /**<CNcomment:VBO展频频率 */
    
}HI_UNF_PANEL_VBOATTR_S;


/**LVDS interface attr *//**CNcomment:LVDS 的接口属性*/
typedef struct hiUNF_PANEL_LVDSATTR_S
{
    HI_U32                       u32LvdsSpreadRatio;    /**<Spread Ratio from 0 to 31 */ /**<CNcomment:展频的比例(10 表示 1% ) [0-31] */
    HI_UNF_PANEL_LVDS_SSFREQ_E   enLvdsSpreadFreq;      /**<spread frequency */ /**<CNcomment:展频的频率(单位: KHz) */
    HI_UNF_PANEL_LVDS_FMT_E      enLvdsFmt;             /**<format */ /**<CNcomment:LVDS的格式 */
    HI_UNF_PANEL_LVDS_LINKMAP_S  stLvdsLinkMap;         /**<Lvds link map */ /**<CNcomment:LVDS 4个Link的24种组合 */
    HI_UNF_PANEL_LVDS_CURRENT_E  enLvdsDrvCurrent;      /**<LVDS Swing */ /**<CNcomment:LVDS 驱动电流 */
    HI_UNF_PANEL_LVDS_VOLTAGE_E  enLvdsComVoltage;      /**<LVDS voltage */ /**<CNcomment:LVDS 共模电压 */

        
}HI_UNF_PANEL_LVDSATTR_S;


/**panel interface attr *//**CNcomment:panel 的接口属性*/
typedef struct hiUNF_PANEL_INTF_ATTR_S
{   
    HI_BOOL                     bIntfEnable;        /**<interface enable */ /**<CNcomment:接口使能 */
    HI_BOOL                     bSpreadEnable;      /**<spread enable */ /**<CNcomment展屏使能 */

    HI_U32                      u32LvdsSpreadRatio; /**<Spread Ratio from 0 to 31 */ /**<CNcomment:展频的比例(10 表示 1% ) [0-31] */
    HI_UNF_PANEL_LVDS_SSFREQ_E  enLvdsSpreadFreq;   /**<spread frequency */ /**<CNcomment:展频的频率(单位: KHz) */
    HI_UNF_PANEL_LVDS_CURRENT_E enLvdsDrvCurrent;   /**<LVDS Swing */ /**<CNcomment:LVDS 驱动电流 */
    HI_UNF_PANEL_LVDS_VOLTAGE_E enLvdsComVoltage;   /**<LVDS voltage */ /**<CNcomment:LVDS 共模电压 */
    
    HI_U32                      u32Vb1SpreadRatio;  /**<Vb1 Spread Ratio from 0 to 31 */ /**<CNcomment:Vbone展屏比 */
    HI_UNF_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;    /**<VBO spread frequency */ /**<CNcomment:VBO展频频率 */
    HI_UNF_PANEL_VBO_CURRENT_E  enVb1Current;       /**<Vbone Swing */ /**<CNcomment:Vbone驱动电流值 */
    HI_UNF_PANEL_VBO_EMP_E      enVb1Emphasis;      /**<Vbone Pre-emphasis */ /**<CNcomment:Vbone预加重 */
}HI_UNF_PANEL_INTF_ATTR_S;

/**panel fixate type *//**CNcomment:panel 固定帧率类型*/
typedef enum hiUNF_PANEL_FIXRATE_TYPE_E
{
	HI_UNF_PANEL_FIXRATE_TYPE_NONE	= 0,	 /**<fixrate type is none *//**CNcomment: 不固定输出帧率 */
    HI_UNF_PANEL_FIXRATE_TYPE_FHD_50HZ,		 /**<fixrate type is fhd50 *//**CNcomment: 固定FHD50输出 */
    HI_UNF_PANEL_FIXRATE_TYPE_FHD_60HZ,      /**<fixrate type is fhd60 *//**CNcomment: 固定FHD60输出 */
	HI_UNF_PANEL_FIXRATE_TYPE_UHD_50HZ, 	 /**<fixrate type is uhd50 *//**CNcomment: 固定UHD50输出 */
	HI_UNF_PANEL_FIXRATE_TYPE_UHD_60HZ, 	 /**<fixrate type is uhd60 *//**CNcomment: 固定UHD60输出 */
    
    HI_UNF_PANEL_FIXRATE_TYPE_BUTT,       /**<Invalid value*//**<CNcomment:非法边界值*/
}HI_UNF_PANEL_FIXRATE_TYPE_E;

/**panel Timming Change type *//**CNcomment:panel Timming信息变化方式 */
typedef enum hiUNF_PANEL_TIMING_CHANGE_E
{
    HI_UNF_PANEL_TIMING_CHANGE_INSTANT = 0,  /* Normal mode change, instant change */
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_VT,   /* Vtotal change gradual */ 
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_HT,   /* Htotal change gradual */
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_CLK,  /* PixelClk change gradual*/
    HI_UNF_PANEL_TIMING_CHANGE_BUTT,

}HI_UNF_PANEL_TIMING_CHANGE_E;

/**panel Division Mode *//**CNcomment:panel Division 模式 */
typedef enum hiUNF_PANEL_DIVISION_MODE_E
{
    HI_UNF_PANEL_ONE_DIVISION_NORMAL_MODE,  /* one division normal mode */
    HI_UNF_PANEL_ONE_DIVISION_OE_MODE,      /* one division odd and even mode */
    HI_UNF_PANEL_TWO_DIVISION_MODE,         /* two division mode */

    HI_UNF_PANEL_DIVISION_MODE_BUTT,        /**<Invalid value*//**<CNcomment:非法边界值*/

}HI_UNF_PANEL_DIVISION_MODE_E;


/**panel info *//**CNcomment:panel信息*/
typedef struct hiUNF_PANEL_INFO_S
{
    HI_CHAR                     chName[48];         /**<Panel Name */ /**<CNcomment:名称 */
    HI_U32                      u32PanelWidth;      /**<Panel Width */ /**<CNcomment:Panel 水平分辨率 */
    HI_U32                      u32Panelheight;     /**<Panel height */ /**<CNcomment:Panel 垂直分辨率 */
    HI_U32                      u32FrameRateMax;    /**<output max framerate */ /**<CNcomment:Panel 最大输出帧率 */
    HI_BOOL                     bSupport48Hz;       /**<48hz support */ /**<CNcomment:Panel 是否支持48HZ  */
    HI_UNF_DISP_3D_E            en3DType;           /**<output 3D type */ /**<CNcomment:屏的输出类型 */
    HI_UNF_PANEL_TYPE_E         enResolutionType;   /**<output Resolution type */ /**<CNcomment:屏的输出分辨率类型 */
    HI_UNF_PANEL_INTFTYPE_E     enIntfType;         /**<Panel interface type */ /**<CNcomment:屏的接口类型*/
    HI_UNF_PANEL_LINKTYPE_E     enPanelLinkType;    /**<Panel link type *//**CNcomment:Panel的链接类型 */
    HI_UNF_PANEL_BITWIDTH_E     enPanelBitWidth;    /**<Panel bit width *//**CNcomment:Panel的数据位宽  */
    
    HI_UNF_PANEL_LVDSATTR_S     stLvdsAttr;         /**<LVDS interface attr *//**Lvds参数，仅在Lvds接口的时候使用此参数*/
    HI_UNF_PANEL_VBOATTR_S      stVboAttr;          /**<VBO interface attr *//**Vbo参数，仅在VBO接口的时候使用此参数*/

    HI_UNF_PANEL_TIMING_S       stTiming60Hz;       /**<Panel timing info 60Hz/120Hz *//**CNcomment:Panel 输出60Hz/120Hz timing */
    HI_UNF_PANEL_TIMING_S       stTiming50Hz;       /**<Panel timing info 50Hz/100Hz *//**CNcomment:Panel 输出50Hz/100Hz timing */
    HI_UNF_PANEL_TIMING_S       stTiming48Hz;       /**<Panel timing info 48Hz/96Hz  *//**CNcomment:Panel 输出48Hz/96Hz timing  */
    HI_U16                      u16HsyncWidth;      /**<hsync width *//**CNcomment:Hsync 宽度 */
    HI_U16                      u16VsyncWidth;      /**<vsync width *//**CNcomment:Vsync 宽度 */

    HI_BOOL                     bHSyncOutput;       /**<Panel hsync output *//**CNcomment:Panel Vsync是否输出，0:为禁止输出  1:为输出 */
    HI_BOOL                     bVSyncOutput;       /**<Panel vsync output *//**CNcomment:Panel Hsync 是否输出，0:为禁止输出  1:为输出 */
    HI_BOOL                     bHSyncNegative;     /**<hsync negative *//**CNcomment:Panel Hsync 是否为负极性 */
    HI_BOOL                     bVSyncNegative;     /**<vsync negative *//**CNcomment:Panel Vsync 是否为负极性 */
    HI_BOOL                     bDeNegative;        /**<DE negative *//**CNcomment:Panel DE 是否为负极性 */
        
    HI_BOOL                     bPwmPostive;        /**<Panel backlight pwm postive *//**CNcomment:Panel backlight pwm 是否为正极性 */
    HI_U32                      u32DimmingFreq60hz; /**<dimming frequence 60Hz/120Hz *//**CNcomment:背光dimming 在60Hz/120Hz 输出时候的频率 */
    HI_U32                      u32DimmingFreq50hz; /**<dimming frequence 50Hz/100Hz *//**CNcomment:背光dimming 在50Hz/100Hz 输出时候的频率 */
    HI_U32                      u32DimmingFreq48hz; /**<dimming frequence 48Hz/96Hz *//**CNcomment:背光dimming 在48Hz/96Hz 输出时候的频率 */
    
    HI_U32                      u32IntfSignalOnDelay; /**<open LVDS signal delay *//**CNcomment:在给TCON供电之后延时打开LVDS信号的时间 */
    HI_U32                      u32BLOnDelay;         /**<open backlight delay *//**CNcomment:在打开LVDS信号之后延时打开背光的时间 */
    HI_U32                      u32BLOffDelay;        /**<close LVDS signal delay *//**CNcomment:在关闭背光之后延时关闭LVDS信号的时间 */
    HI_U32                      u32IntfSignalOffDelay;/**<close backlight delay *//**CNcomment: 在关闭LVDS信号之后延时关闭TCON供电的时间 */

    HI_BOOL                     bFrmRateChangeBlack;    /**<framerate change screen mute *//**CNcomment: 帧率变化时是否黑屏 */
    HI_U32                      u32MuteTime;            /**<screen mute time *//**CNcomment: 黑屏的时间，默认值0~5000 Ms */

    HI_BOOL                     bLocalDimmingSupport;   /**<localdimming support *//**CNcomment: 是否支持LocalDimming Ms */
    HI_U32                      u32HorAreaNum;          /**<localdimming horArea number *//**CNcomment: 支持LocalDimming时水平分区的个数 */
    HI_U32                      u32VerAreaNum;          /**<localdimming verArea number *//**CNcomment: 支持LocalDimming时垂直分区的个数 */

    HI_UNF_PANEL_FLIP_TYPE_E    enPanelFlipType;        /**<Panel Flip Type *//**CNcomment: Panel的翻转类型*/
    HI_UNF_PANEL_FIXRATE_TYPE_E enPanelFixRateType;

    HI_UNF_PANEL_TIMING_CHANGE_E enTimChangeType;       /**<Panel Timming change type *//**CNcomment: PanelTimming变化方式*/
    HI_U32                      u32ChangeStep;          /**<Panel Timming change step *//**CNcomment: PanelTimming变化幅度*/

    HI_UNF_PANEL_DIVISION_MODE_E enDivisionMode;        /**<Panel division mode *//**CNcomment: Panel分屏模式*/
        
    HI_U32                      u32Resove[5];          /**<reserved *//**CNcomment: 0~8共9个Reserved 32位变量，默认值0xffffffff */

}HI_UNF_PANEL_INFO_S;


/**panel aspect *//**CNcomment:panel显示的比例模式*/
typedef enum hiUNF_PANEL_ASPECT_E
{
    HI_UNF_PANEL_ASPECT_4_3 = 0,    /**<aspect is 4:3 *//**CNcomment: 4:3 显示 */
    HI_UNF_PANEL_ASPECT_16_9,       /**<aspect is 16:9 *//**CNcomment: 16:9 显示 */
    HI_UNF_PANEL_ASPECT_14_9,       /**<aspect is 14:9 *//**CNcomment: 14:9 显示 */
    HI_UNF_PANEL_ASPECT_21_9,       /**<aspect is 21:9 *//**CNcomment: 21:9 显示 */
    HI_UNF_PANEL_ASPECT_16_10,      /**<aspect is 16:10 *//**CNcomment: 16:10 显示 */
    
    HI_UNF_PANEL_ASPECT_BUTT,       /**<Invalid value*//**<CNcomment:非法边界值*/
}HI_UNF_PANEL_ASPECT_E;


/**panel attr *//**CNcomment:panel属性*/
typedef struct hiUNF_PANEL_ATTR_S
{   
    HI_U32                  u32Width;   /**<Width *//**CNcomment: Panel的宽度 */
    HI_U32                  u32Height;  /**<Height *//**CNcomment: Panel的高度 */
    HI_UNF_PANEL_ASPECT_E   enAspect;   /**<aspect *//**CNcomment: Panel的比例模式 */
    HI_UNF_DISP_3D_E        en3dMode;   /**<3D Mode *//**CNcomment: Panel的3D 模式 */
}HI_UNF_PANEL_ATTR_S;

/*==== Structure Definition end ==== */


/*************************** API declaration ****************************/
/** \addtogroup      PANEL */
/** @{ */  /** <!-- [PANEL] */

/** 
\brief the whole initialization of the PANEL device. CNcomment:PANEL接口驱动软件初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_Init(HI_VOID);

/** 
\brief deinit the PANEL device. CNcomment:PANEL接口去初始化 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_DeInit(HI_VOID);

/** 
\brief set path the PANEL device. CNcomment:PANEL设置屏参在系统中的路径 CNend
\attention \n
\param[in] pcPath: panel param path.CNcomment:屏参的路径 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetPath(HI_CHAR* pcPath);

/** 
\brief set default information the PANEL device. CNcomment:PANEL设置选取系统默认的屏参 CNend
\attention  \n
\param[in] u32Index: panel index. CNcomment:屏参的index CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetIndex(HI_U32 u32Index);

/** 
\brief get default information count the PANEL device. CNcomment:获取PANEL默认的屏参个数 CNend
\attention  \n
\param[out] pu32TotalNum: panel total number save address. CNcomment:屏参个数的存放地址 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetTotalNum(HI_U32 *pu32TotalNum);

/** 
\brief set information the PANEL device. CNcomment:设置屏参信息 CNend
\attention  \n
\param[in] pstPanelInfo: panel info address CNcomment:存放要设置的屏参的信息 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetInfo(HI_UNF_PANEL_INFO_S *pstPanelInfo);

/** 
\brief get information the PANEL device. CNcomment:获取屏参信息 CNend
\attention  \n
\param[out] pstPanelInfo: panel info address CNcomment:存放屏参的信息的地址 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetInfo(HI_UNF_PANEL_INFO_S *pstPanelInfo);

/** 
\brief set power on the PANEL device. CNcomment:给屏供电，如果BOOT已点屏MW初始化不能调用SetPowerOn此接口,只有切换屏参和关机才能调用 CNend
\attention  \n
\param[in] bEnable: power state CNcomment:给屏供电的使能信息 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetPowerOn(HI_BOOL bEnable);

/** 
\brief get power on the PANEL device. CNcomment:获取屏供电状况 CNend
\attention  \n
\param[out] pbEnable: power state CNcomment:屏当前的供电状况CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetPowerOn( HI_BOOL *pbEnable);

/** 
\brief set back light the PANEL device. CNcomment:设置屏的背光 CNend
\attention  \n
\param[in] bEnable: back light state CNcomment:设置屏背光的状态 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetBacklight(HI_BOOL bEnable);

/** 
\brief get back light the PANEL device. CNcomment:获取屏的背光状态 CNend
\attention  \n
\param[out] pbEnable: back light state CNcomment:屏当前背光的状态 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetBacklight(HI_BOOL *pbEnable);

/** 
\brief set interface attr the PANEL device. CNcomment:设置屏的接口信息 CNend
\attention  \n
\param[in] pstIntfAttr: interface attr address CNcomment:要设置的信息 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetIntfAttr(HI_UNF_PANEL_INTF_ATTR_S *pstIntfAttr);

/** 
\brief get interface attr the PANEL device. CNcomment:获取屏的接口信息 CNend
\attention  \n
\param[out] pstIntfAttr: interface attr address CNcomment:存放屏接口信息的地址 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetIntfAttr(HI_UNF_PANEL_INTF_ATTR_S *pstIntfAttr);

/** 
\brief set fix frame rate the PANEL device. CNcomment:设置输出帧率为固定值 CNend
\attention  \n
\param[in] enFixRateType: FixRateType CNcomment:输出帧率类型 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetFixOutRate(HI_UNF_PANEL_FIXRATE_TYPE_E enFixRateType);


/** 
\brief get fix frame rate the PANEL device. CNcomment:获取输出帧率的固定值 CNend
\attention  \n
\param[in] penFixRateType: FixRateType CNcomment:输出帧率类型 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetFixOutRate(HI_UNF_PANEL_FIXRATE_TYPE_E *penFixRateType);

/** 
\brief get attr the PANEL device. CNcomment:获取屏的输出属性 CNend
\attention  \n
\param[out] pstPanelAttr: save panel attr address CNcomment:输出属性的存放地址 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetPanelAttr(HI_UNF_PANEL_ATTR_S *pstPanelAttr);

/** 
\brief print list the PANEL device. CNcomment:输出所有默认屏的信息 CNend
\attention  \n
\param CNcomment:无 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_DumpPanelList(HI_VOID);

/** 
\brief set dynamic backlight enable the PANEL device. CNcomment:设置屏的动态背光使能 CNend
\attention  \n
\param[out] pbEnable: dynamic back light state CNcomment:屏当前动态背光的状态 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetDynamicBLEnable(HI_BOOL bEnable);

//ygf add it because sdk source has implement it, but no interface
HI_S32 HI_UNF_PANEL_GetDynamicBLEnable(HI_BOOL *pbEnable);


/** 
\brief set back light level the PANEL device. CNcomment:设置屏的背光等级 CNend
\attention  \n
\param[in] u32Level: back light level CNcomment:背光的等级 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetBacklightLevel(HI_U32 u32Level);

/** 
\brief set back light level the PANEL device. CNcomment:获取屏的背光等级 CNend
\attention  \n
\param[in] u32Level: back light level CNcomment:背光的等级 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetBacklightLevel(HI_U32 *pu32Level);

/** 
\brief set local dimming the PANEL device. CNcomment:设置屏localdimming开关 CNend
\attention  \n
\param[in] u32Level: local dimming open or close CNcomment:localdimming关闭 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_SetLocalDimmingEn(HI_BOOL bEnable);

/** 
\brief set local dimming the PANEL device. CNcomment:获取屏localdimming开关 CNend
\attention  \n
\param[in] u32Level: local dimming open or close CNcomment:localdimming关闭 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_PANEL_GetLocalDimmingEn(HI_BOOL *pbEnable);

/*==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
