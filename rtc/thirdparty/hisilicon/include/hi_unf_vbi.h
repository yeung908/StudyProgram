/******************************************************************************

  Copyright (C), 2015-2050, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
 File Name     : hi_unf_vbi.h
 Version       : Initial draft
 Author        : HiSilicon multimedia software group
 Created       : 2015-07-01
 Description   : Application programming interfaces (APIs) of the external chip software (ECS)
  History       :
  1.Date        : 2015-07-01
    Author      : yinxiaohui WX218173
    Modification: Created file
    
 ******************************************************************************/
 
#ifndef __HI_UNF_VBI_H__
#define __HI_UNF_VBI_H__

/* add include here */
#include "hi_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define VBI_DATA_MAX    4096
#define VBI_DATA_SIZE   0x10000//4096/

/********************************Macro Definition********************************/
/** \addtogroup      VBI */
/** @{ */  /** <!--VBI */

/** Signal type of the vbi*/
/** CNcomment:VBI信号类型*/
typedef enum    hiVBI_SIG_TYPE_E
{
    HI_UNF_VBI_TYPE_CC_VChip = 0  , /**<Closed Caption*/           /**<CNcomment:CC格式*/
    HI_UNF_VBI_TYPE_TT ,            /**<Teletext*/                 /**<CNcomment:图文电视*/
    HI_UNF_VBI_TYPE_WSS  ,          /**<Widescreen Signalling*/    /**<CNcomment:宽银幕信号*/
    HI_UNF_VBI_TYPE_VPS  ,          /**<VPS*/                    /**<CNcomment:VPS格式*/

    HI_UNF_VBI_TYPE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_SIG_TYPE_E;

/** Source type of the vbi*/
/** CNcomment:VBI信号来源*/
typedef enum    hiVBI_SRC_TYPE_E
{
    HI_UNF_VBI_SRC_TYPE_HDDEC = 0  ,     /**<source form hddec*/       /**<CNcomment:输入源是Ypbpr模式*/
    HI_UNF_VBI_SRC_TYPE_TVD ,            /**<source form tvd*/         /**<CNcomment:输入源是cvbs模式*/

    HI_UNF_VBI_SRC_TYPE_BUTT             /**<Invalid value*/            /**<CNcomment:非法边界值*/
}HI_UNF_VBI_SRC_TYPE_E;

/**VBI source attribute */
/**CNcomment:VBI输入信号属性 */
typedef struct hiUNF_VBI_SRC_ATTR_S
{
    HI_UNF_VBI_SIG_TYPE_E  enType;             /**<VBI input signal type *//**CNcomment: VBI输入信号类型 */
    HI_UNF_VBI_SRC_TYPE_E  enSrcType;          /**<VBI input source type *//**CNcomment: VBI输入源类型 */
} HI_UNF_VBI_SRC_ATTR_S;

/**============================CC data type=============================*/
/** CNcomment:CC数据类型分类 */
typedef enum hiUNF_VBI_CC_DATA_TYPE_E
{
    HI_UNF_VBI_CC_DATA_TYPE_608,        /**<CC608*//**<CNcomment:CC608数据 */
    HI_UNF_VBI_CC_DATA_TYPE_708,        /**<CC708*//**<CNcomment:CC708数据 */
    HI_UNF_VBI_CC_DATA_TYPE_ARIB,       /**<ARIB CC*//**<CNcomment:ARIB CC数据 */

    HI_UNF_VBI_CC_DATA_TYPE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_DATA_TYPE_E;

/**CC608 data type*//** CNcomment:CC608在line 21的数据类型分类 */
typedef enum hiUNF_VBI_CC_608_DATATYPE_E
{
    HI_UNF_VBI_CC_608_DATATYPE_CC1,       /**<CC1*//**<CNcomment:CC1 */
    HI_UNF_VBI_CC_608_DATATYPE_CC2,       /**<CC2*//**<CNcomment:CC2 */
    HI_UNF_VBI_CC_608_DATATYPE_CC3,       /**<CC3*//**<CNcomment:CC3 */
    HI_UNF_VBI_CC_608_DATATYPE_CC4,       /**<CC4*//**<CNcomment:CC4 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT1,     /**<TEXT1*//**<CNcomment:TEXT1 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT2,     /**<TEXT2*//**<CNcomment:TEXT2 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT3,     /**<TEXT3*//**<CNcomment:TEXT3 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT4,     /**<TEXT4*//**<CNcomment:TEXT4 */

    HI_UNF_VBI_CC_608_DATATYPE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_608_DATATYPE_E;

/**standard color*//** CNcomment:标准颜色 */
typedef enum hiUNF_VBI_CC_COLOR_E
{
    HI_UNF_VBI_CC_COLOR_DEFAULT=0x00000000,       /**<default color*//**<CNcomment:默认颜色 */
    HI_UNF_VBI_CC_COLOR_BLACK=0xff000000,         /**<black*//**<CNcomment:黑色 */
    HI_UNF_VBI_CC_COLOR_WHITE=0xffffffff,         /**<white*//**<CNcomment:白色 */
    HI_UNF_VBI_CC_COLOR_RED=0xffff0000,           /**<red*//**<CNcomment:红色 */
    HI_UNF_VBI_CC_COLOR_GREEN=0xff00ff00,         /**<green*//**<CNcomment:绿色 */
    HI_UNF_VBI_CC_COLOR_BLUE=0xff0000ff,          /**<blue*//**<CNcomment:蓝色 */
    HI_UNF_VBI_CC_COLOR_YELLOW=0xffffff00,        /**<yellow*//**<CNcomment:黄色 */
    HI_UNF_VBI_CC_COLOR_MAGENTA=0xffff00ff,       /**<magenta*//**<CNcomment:品红 */
    HI_UNF_VBI_CC_COLOR_CYAN=0xff00ffff,          /**<cyan*//**<CNcomment:青色 */
}HI_UNF_VBI_CC_COLOR_E;

/**opacity*//** CNcomment:透明度 */
typedef enum hiUNF_VBI_CC_OPACITY_E
{
    HI_UNF_VBI_CC_OPACITY_DEFAULT,         /**<default*//**<CNcomment:默认透明度 */
    HI_UNF_VBI_CC_OPACITY_SOLID,           /**<opaque*//**<CNcomment:不透明 */
    HI_UNF_VBI_CC_OPACITY_FLASH,           /**<flash*//**<CNcomment:闪烁 */
    HI_UNF_VBI_CC_OPACITY_TRANSLUCENT,     /**<translucent*//**<CNcomment:半透明 */
    HI_UNF_VBI_CC_OPACITY_TRANSPARENT,     /**<transparent*//**<CNcomment:透明 */

    HI_UNF_VBI_CC_OPACITY_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_OPACITY_E;

/**justify*//** CNcomment:排版*/
typedef enum hiUNF_VBI_CC_JUSTIFY_E
{
    HI_UNF_VBI_CC_JUSTIFY_LEFT,        /**<left*//**<CNcomment:居左 */
    HI_UNF_VBI_CC_JUSTIFY_RIGHT,       /**<rigth*//**<CNcomment:居右 */
    HI_UNF_VBI_CC_JUSTIFY_CENTER,      /**<center*//**<CNcomment:居中 */
    HI_UNF_VBI_CC_JUSTIFY_FULL,        /**<full*//**<CNcomment:两端对齐 */
    HI_UNF_VBI_CC_JUSTIFY_BUTT
}HI_UNF_VBI_CC_JUSTIFY_E;


/**font style*//** CNcomment:字体风格 */
typedef enum hiUNF_VBI_CC_FONTSTYLE_E
{
    HI_UNF_VBI_CC_FONTSTYLE_DEFAULT,         /**<default*//**<CNcomment:默认字体风格 */
    HI_UNF_VBI_CC_FONTSTYLE_NORMAL,          /**<normal*//**<CNcomment:正常 */
    HI_UNF_VBI_CC_FONTSTYLE_ITALIC,          /**<italic*//**<CNcomment:斜体 */
    HI_UNF_VBI_CC_FONTSTYLE_UNDERLINE,       /**<underline*//**<CNcomment:下划线 */
    HI_UNF_VBI_CC_FONTSTYLE_ITALIC_UNDERLINE,/**<italic&underline*//**<CNcomment:斜体并且带下滑线 */

    HI_UNF_VBI_CC_FONTSTYLE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_FONTSTYLE_E;

/**display format of caption display screen*//** CNcomment:显示窗口的显示模式 */
typedef enum hiUNF_VBI_VBI_CC_DF_E
{
    HI_UNF_VBI_CC_DF_720X480,       /**<caption display screen is 720*480*//**<CNcomment:显示窗口的宽高是720*480 */
    HI_UNF_VBI_CC_DF_720X576,       /**<caption display screen is 720*576*//**<CNcomment:显示窗口的宽高是720*576 */
    HI_UNF_VBI_CC_DF_960X540,       /**<caption display screen is 960*540*//**<CNcomment:显示窗口的宽高是960*540 */
    HI_UNF_VBI_CC_DF_1280X720,      /**<caption display screen is 1280*720*//**<CNcomment:显示窗口的宽高是1280*720 */
    HI_UNF_VBI_CC_DF_1920X1080,     /**<caption display screen is 1920*1080*//**<CNcomment:显示窗口的宽高是1920*1080 */

    HI_UNF_VBI_CC_DF_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
} HI_UNF_VBI_CC_DF_E;

/**CC display operation*//** CNcomment:CC显示操作 */
typedef enum hiUNF_VBI_CC_OPT_E
{
     HI_UNF_VBI_CC_OPT_DRAWTEXT = 0x1, /**<draw text *//**<CNcomment:绘制文本 */
     HI_UNF_VBI_CC_OPT_DRAWBITMAP,     /**<draw bitmap *//**<CNcomment:绘制位图 */
     HI_UNF_VBI_CC_OPT_FILLRECT,       /**<fill rect *//**<CNcomment:填充矩形区域 */
     HI_UNF_VBI_CC_OPT_BUTT
} HI_UNF_VBI_CC_OPT_E;

/**CC rect*//** CNcomment:定义CC矩形区域*/
typedef struct hiUNF_VBI_CC_RECT_S
{
    HI_U16 x;           /**<x cordinate *//**<CNcomment:矩形左上角的x坐标 */
    HI_U16 y;           /**<y cordinate *//**<CNcomment:矩形左上角的y坐标 */
    HI_U16 width;       /**<rect width *//**<CNcomment:矩形的宽度 */
    HI_U16 height;      /**<rect heigth *//**<CNcomment:矩形的高度 */
}HI_UNF_VBI_CC_RECT_S;

/**CC color components*//** CNcomment:CC像素颜色结构 */
typedef struct hiUNF_VBI_CC_COLOR_S
{
    HI_U8 u8Blue;       /**<blue component *//**<CNcomment:B分量颜色值 */
    HI_U8 u8Green;      /**<green component *//**<CNcomment:G分量颜色值 */
    HI_U8 u8Red;        /**<red component *//**<CNcomment:R分量颜色值 */
    HI_U8 u8Alpha;      /**<alpha component *//**<CNcomment:透明度，值为0为透明，0xFF为不透明 */
} HI_UNF_VBI_CC_COLOR_S;

/**font size*//** CNcomment:字体大小 */
typedef enum hiUNF_VBI_CC_FONTSIZE_E
{
    HI_UNF_VBI_CC_FONTSIZE_DEFAULT,       /**<default font size *//**<CNcomment:默认字体大小 */
    HI_UNF_VBI_CC_FONTSIZE_SMALL,         /**<small*//**<CNcomment:小 */
    HI_UNF_VBI_CC_FONTSIZE_STANDARD,      /**<standard*//**<CNcomment:标准 */
    HI_UNF_VBI_CC_FONTSIZE_LARGE,         /**<large*//**<CNcomment:大 */

    HI_UNF_VBI_CC_FONTSIZE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
} HI_UNF_VBI_CC_FONTSIZE_E;

/**font edge type*//** CNcomment:字体边缘类型 */
typedef enum hiUNF_VBI_CC_EdgeType_E
{
    HI_UNF_VBI_CC_EDGETYPE_DEFAULT,            /**<default *//**<CNcomment:默认字体边缘类型 */
    HI_UNF_VBI_CC_EDGETYPE_NONE,               /**<none edge type *//**<CNcomment:没有边缘 */
    HI_UNF_VBI_CC_EDGETYPE_RAISED,             /**<raised *//**<CNcomment:边缘突起 */
    HI_UNF_VBI_CC_EDGETYPE_DEPRESSED,          /**<depressed *//**<CNcomment:边缘凹下 */
    HI_UNF_VBI_CC_EDGETYPE_UNIFORM,            /**<uniform *//**<CNcomment:边缘统一 */
    HI_UNF_VBI_CC_EDGETYPE_LEFT_DROP_SHADOW,   /**<left drop shadow *//**<CNcomment:左下阴影 */
    HI_UNF_VBI_CC_EDGETYPE_RIGHT_DROP_SHADOW,  /**<right drop shadow *//**<CNcomment:右下阴影 */

    HI_UNF_VBI_CC_EDGETYPE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_EdgeType_E;

/**CC data with text format*//** CNcomment:文本格式的CC数据 */
typedef struct hiUNF_VBI_CC_TEXT_S
{
    HI_U16                 *pu16Text;    /**<cc data,2 bytes,unicode *//**<CNcomment:cc数据，unicode编码，2个字节 */
    HI_U8                  u8TextLen;    /**<cc data length *//**<CNcomment:要显示的cc数据长度 */

    HI_UNF_VBI_CC_COLOR_S      stFgColor;    /**<cc foregroud color*//**<CNcomment:要显示的cc数据前景色 */
    HI_UNF_VBI_CC_COLOR_S      stBgColor;    /**<cc backgroud color*//**<CNcomment:要显示的cc数据字体背景色 */
    HI_UNF_VBI_CC_COLOR_S      stEdgeColor;   /**<cc edge color*//**<CNcomment:要显示的cc数据字体边缘颜色*/

    HI_U8                  u8Justify;    /*see HI_UNF_CC_JUSTIFY_E,used when decode cc708*//**<CNcomment:cc数据显示时的排版方式 */
    HI_U8                  u8WordWrap;   /*see HI_UNF_CC_WORDWRAP_E,used when decode cc708*//**<CNcomment:自动换行 */
    HI_UNF_VBI_CC_FONTSTYLE_E  enFontStyle;  /*font style ,see HI_UNF_CC_FONTSTYLE_E*//**<CNcomment:要显示的cc数据的字体风格 */
    HI_UNF_VBI_CC_FONTSIZE_E   enFontSize;   /*font size ,see HI_UNF_CC_FONTSIZE_E*//**<CNcomment:要显示的cc数据的字体大小 */
    HI_UNF_VBI_CC_EdgeType_E    enEdgetype;  /**<cc edge type*//**<CNcomment:要显示的cc数据字体边缘类型*/
} HI_UNF_VBI_CC_TEXT_S;

/**CC data with bitmap format*//** CNcomment:位图格式的CC数据 */
typedef struct hiUNF_VBI_CC_BITMAP_S
{
    HI_S32                 s32BitWidth;         /**<bit width, is 2/4/8/16/24/32 *//**<CNcomment:位宽,值是2/4/8/16/24/32 */
    HI_U8                  *pu8BitmapData;      /**<pixel data *//**<CNcomment:图像数据 */
    HI_U32                 u32BitmapDataLen;    /**<length of pixel data *//**<CNcomment:图像数据长度 */
    HI_UNF_VBI_CC_COLOR_S      astPalette[256];     /**<palette data *//**<CNcomment:调色板数据 */
    HI_U32                 u32PaletteLen;       /**<length of palette data *//**<CNcomment:调色板数据长度 */
} HI_UNF_VBI_CC_BITMAP_S;

/**parameter of fill rect*//** CNcomment:填充矩形区域的参数 */
typedef struct hiUNF_VBI_CC_FILLRECT_S
{
    HI_UNF_VBI_CC_COLOR_S      stColor;      /**<color *//**<CNcomment:颜色值 */
} HI_UNF_VBI_CC_FILLRECT_S;

/**CC608 config param *//** CNcomment:CC608 配置信息参数 */
/**CC608 just support 8 stardard colors*//**CNcomment:CC608只支持8种标准颜色*/
typedef struct hiUNF_VBI_CC_608_CONFIGPARAM_S
{
    HI_UNF_VBI_CC_608_DATATYPE_E    enCC608DataType;        /**<CC608 data type *//**<CNcomment:配置cc608数据类型 */
    HI_U32                      u32CC608TextColor;      /**<CC608 text color *//**<CNcomment:配置cc608字体颜色 */
    HI_UNF_VBI_CC_OPACITY_E         enCC608TextOpac;        /**<CC608 text opacity *//**<CNcomment:配置cc608字体透明度 */
    HI_U32                      u32CC608BgColor;        /**<CC608 background color *//**<CNcomment:配置cc608背景色 */
    HI_UNF_VBI_CC_OPACITY_E         enCC608BgOpac;          /**<CC608 background opacity *//**<CNcomment:配置cc608背景透明度 */
    HI_UNF_VBI_CC_FONTSTYLE_E       enCC608FontStyle;       /**<CC608 font style *//**<CNcomment:配置cc608字体风格 */
    HI_UNF_VBI_CC_DF_E              enCC608DispFormat;      /**<CC608 display format of caption display screen *//**<CNcomment:配置cc608显示模式 */
    HI_BOOL                     bLeadingTailingSpace;   /**< CC608 leading/tailing space flag*//**<CNcomment: 是否显示leading/tailing space*/
} HI_UNF_VBI_CC_608_CONFIGPARAM_S;

/**font name*/
/** CNcomment:字体样式 */
typedef enum  hiUNF_VBI_CC_FONTNAME_E
{
    HI_UNF_VBI_CC_FN_DEFAULT,                  /**<default *//**<CNcomment:默认字体样式 */
    HI_UNF_VBI_CC_FN_MONOSPACED,               /**<monospaced*//**<CNcomment:monospaced字体 */
    HI_UNF_VBI_CC_FN_PROPORT,                  /**<proport*//**<CNcomment:proport字体 */
    HI_UNF_VBI_CC_FN_MONOSPACED_NO_SERIAFS,    /**<monospaced with no seriafs*//**<CNcomment:monospaced字体(无衬线) */
    HI_UNF_VBI_CC_FN_PROPORT_NO_SERIAFS,       /**<proport with no seriafs*//**<CNcomment:proport字体(无衬线) */
    HI_UNF_VBI_CC_FN_CASUAL,                   /**<casual*//**<CNcomment:casual字体 */
    HI_UNF_VBI_CC_FN_CURSIVE,                  /**<cursive*//**<CNcomment:cursive字体 */
    HI_UNF_VBI_CC_FN_SMALL_CAPITALS,           /**<small capitals*//**<CNcomment:小写字体 */

    HI_UNF_VBI_CC_FN_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_FONTNAME_E;

/**708CC service channel*//** CNcomment:708CC的服务通道号*/
typedef enum hiUNF_VBI_CC_708_SERVICE_NUM_E
{
    HI_UNF_VBI_CC_708_SERVICE1 = 0x1, /**<708CC service 1*//**<CNcomment:708CC服务1 */
    HI_UNF_VBI_CC_708_SERVICE2,       /**<708CC service 2*//**<CNcomment:708CC服务2 */
    HI_UNF_VBI_CC_708_SERVICE3,       /**<708CC service 3*//**<CNcomment:708CC服务3 */
    HI_UNF_VBI_CC_708_SERVICE4,       /**<708CC service 4*//**<CNcomment:708CC服务4 */
    HI_UNF_VBI_CC_708_SERVICE5,       /**<708CC service 5*//**<CNcomment:708CC服务5 */
    HI_UNF_VBI_CC_708_SERVICE6,       /**<708CC service 6*//**<CNcomment:708CC服务6 */

    HI_UNF_VBI_CC_708_SERVICE_BUTT      /**<Invalid value*/            /**<CNcomment:非法值*/
}HI_UNF_VBI_CC_708_SERVICE_NUM_E;

/**CC708 config param *//** CNcomment:CC708 配置信息参数 */
/**CC708 support 64 colors.one of RGB color components can be 0x00,0x5f,0xaf,0xff*//**CNcomment:CC708支持64种颜色,一个RGB分量能取的值有0x00,0x5f,0xaf,0xff共4种*/
typedef struct hiUNF_VBI_CC_708_CONFIGPARAM_S
{
    HI_UNF_VBI_CC_708_SERVICE_NUM_E enCC708ServiceNum;      /**<CC708 service number *//**<CNcomment:配置cc708服务通道号 */
    HI_UNF_VBI_CC_FONTNAME_E        enCC708FontName;        /**<CC708 font name *//**<CNcomment:配置cc708字体 */
    HI_UNF_VBI_CC_FONTSTYLE_E       enCC708FontStyle;       /**<CC708 font style *//**<CNcomment:配置cc708字体风格 */
    HI_UNF_VBI_CC_FONTSIZE_E        enCC708FontSize;        /**<CC708 font size *//**<CNcomment:配置cc708字体大小 */
    HI_U32                      u32CC708TextColor;      /**<CC708 text color *//**<CNcomment:配置cc708字体颜色 */
    HI_UNF_VBI_CC_OPACITY_E         enCC708TextOpac;        /**<CC708 text opacity *//**<CNcomment:配置cc708字体透明度 */
    HI_U32                      u32CC708BgColor;        /**<CC708 background color *//**<CNcomment:配置cc708背景颜色 */
    HI_UNF_VBI_CC_OPACITY_E         enCC708BgOpac;          /**<CC708 background opacity *//**<CNcomment:配置cc708背景透明度 */
    HI_U32                      u32CC708WinColor;       /**<CC708 window color *//**<CNcomment:配置cc708窗口颜色 */
    HI_UNF_VBI_CC_OPACITY_E         enCC708WinOpac;         /**<CC708 window opacity *//**<CNcomment:配置cc708窗口透明度 */
    HI_UNF_VBI_CC_EdgeType_E        enCC708TextEdgeType;    /**<CC708 text egde type *//**<CNcomment:配置cc708字体边缘类型 */
    HI_U32                      u32CC708TextEdgeColor;  /**<CC708 text edge color *//**<CNcomment:配置cc708字体边缘颜色 */
    HI_UNF_VBI_CC_DF_E              enCC708DispFormat;      /**<CC708 display format of caption display screen *//**<CNcomment:配置cc708显示模式 */
} HI_UNF_VBI_CC_708_CONFIGPARAM_S;

/**ARIB CC config param *//** CNcomment:ARIB CC 配置信息参数 */
typedef struct hiUNF_VBI_CC_ARIB_CONFIGPARAM_S
{
    HI_U32      u32BufferSize;   /**<size of buffer which used to cache pes data,Recommends its value is 64K ~ 512K.note:This value can only be set when created,does not support dynamic setting*/
                                 /**<CNcomment:缓存PES数据的缓冲区大小，取值为64k~512K。注意:这个值只能在创建时设置，不支持动态设置*/
} HI_UNF_VBI_CC_ARIB_CONFIGPARAM_S;

/**CC data attribution */
/** CNcomment:CC属性信息 */
typedef struct hiUNF_VBI_CC_ATTR_S
{
    HI_UNF_VBI_CC_DATA_TYPE_E enCCDataType;   /**<cc data type *//**<CNcomment:cc数据类型 */
    union
    {
        HI_UNF_VBI_CC_608_CONFIGPARAM_S  stCC608ConfigParam;   /**<CC608 config param *//**<CNcomment:CC608 配置信息参数 */
        HI_UNF_VBI_CC_708_CONFIGPARAM_S  stCC708ConfigParam;   /**<CC708 config param *//**<CNcomment:CC708 配置信息参数 */
        HI_UNF_VBI_CC_ARIB_CONFIGPARAM_S stCCARIBConfigParam;  /**<ARIB CC config param *//**<CNcomment:ARIB CC 配置信息参数 */
    } unConfig;
} HI_UNF_VBI_CC_ATTR_S;

/** CNcomment:VBI信号信息*/
typedef struct hiUNF_VBI_ATTR_S
{
    HI_UNF_VBI_SIG_TYPE_E enVbiType;                /**<Signal transmission type*/    /**<CNcomment:信号类型*/

    union
    {
        HI_UNF_VBI_CC_ATTR_S         stCC;         /**<Signal info of cc*/    /**<CNcomment:closed caption配置信息*/
        HI_UNF_VBI_CC_ATTR_S         stTT;         /**<Signal info of tt*/     /**<CNcomment:Teletext 配置信息*/
        HI_UNF_VBI_CC_ATTR_S         stWSS;        /* wss配置参数*/
        HI_UNF_VBI_CC_ATTR_S         stVPS;        /* vps配置参数参数*/
    } unAttr;
} HI_UNF_VBI_ATTR_S;

/**CC data*/
/** CNcomment:CC信号数据信息*/
typedef struct hiUNF_VBI_CC_DATA_S
{
    HI_BOOL boddevenflag;         /**<parity field flag*/ /**<CNcomment:奇偶场 标志位*/
	HI_U16 u16VbiData;            /**<cc data   */ /**<CNcomment:cc数据*/
    HI_U32 u32LineCnt;            /**<Line Count  */ /**<CNcomment:cc行计数*/
    HI_U32 u32VSyncCnt;           /**<Vsync Count  */ /**<CNcomment:cc场中断计数*/
	HI_U32 u32DataSize ;          /**<cc data  size  */ /**<CNcomment:cc数据大小*/
}HI_UNF_VBI_CC_DATA_S;

/** CNcomment:TT信号数据信息*/
typedef struct hiUNF_VBI_TT_DATA_S
{
   HI_U32 u32BufPhyAddr;            /**<Teletxt Signal buffer physical address*/    /**<CNcomment:信号缓存申请到的首地址*/
   HI_U32 u32BufSize;               /**<Teletxt Signal buffer size*/    /**<CNcomment:信号缓存大小*/
   HI_U32 u32PreBufWritePhyAddr;    /**<Previous  buffer physical address*/    /**<CNcomment:之前写的物理地址*/
   HI_U32 u32BufWritePhyAddr;       /**<Current buffer physical address*/    /**<CNcomment:当前写的物理地址*/
}HI_UNF_VBI_TT_DATA_S;

/** CNcomment:WSS信号数据信息*/
typedef struct hiUNF_VBI_WSS_DATA_S
{
   HI_U32 u32Data;            /**<wss data*/    /**<CNcomment WSS 信号数据*/
}HI_UNF_VBI_WSS_DATA_S;

/** CNcomment:VPS信号数据信息*/
typedef struct hiUNF_VBI_VPS_DATA_S
{
   HI_U32 u32Data;            /**<vps data*/    /**<CNcomment VPS 信号数据*/
}HI_UNF_VBI_VPS_DATA_S;

typedef struct hiUNF_VBI_TT_INFO_S
{
    HI_BOOL boddevenflag;         /**<parity field flag*/ /**<CNcomment:奇偶场 标志位*/

    HI_U32 u32LineCnt;            /**<tt line count*/ /**<CNcomment:TT 信号行计数*/
    HI_U32 u32VSyncCnt;           /**<tt Vsync count*/ /**<CNcomment:TT 信号场计数*/
}HI_UNF_VBI_TT_INFO_S;

/** CNcomment:VBI信号信息*/
typedef struct hiUNF_VBI_SIGNALINFO_S
{
    HI_UNF_VBI_SIG_TYPE_E enVbiType;                /**<Signal transmission type*/    /**<CNcomment:信号类型*/

    union
    {
        HI_UNF_VBI_CC_DATA_S         stCC;         /**<Signal info of cc*/    /**<CNcomment:信号信息*/
        HI_UNF_VBI_TT_DATA_S         stTT;         /**<Signal info of tt*/     /**<CNcomment:信号信息*/
        HI_UNF_VBI_WSS_DATA_S        stWSS;        /* wss信号信息*/
        HI_UNF_VBI_VPS_DATA_S        stVPS;        /* vps信号参数*/
    } unSignalInfo;
} HI_UNF_VBI_SIGNALINFO_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      VBI */
/** @{ */  /** <!-- [VBI] */
/**
\brief Initialize VBI module. CNcomment: 初始化VBI模块。CNend
\attention \n
none. CNcomment: 无。CNend
\retval ::HI_SUCCESS initialize success. CNcomment: 初始化成功。CNend
\retval ::HI_FAILURE initialize failure. CNcomment: 初始化失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_Init(HI_VOID);


/**
\brief DeInitialize VBI module. CNcomment: 去初始化VBI模块。CNend
\attention \n
none. CNcomment: 无。CNend
\retval ::HI_SUCCESS deinitialize success. CNcomment: 去初始化成功。CNend
\retval ::HI_FAILURE deinitialize failure. CNcomment: 去初始化失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_DeInit(HI_VOID);


/**
\brief start VBI module. CNcomment: 开始VBI模块。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  enType  Signal type of the VBI. CNcomment: VBI 信号类型CNend
\param[in]  enSrcType Select VBI WorkMode for TVD or HDDEC.CNcomment:选择VBI的数据源来自TVD的CVBS信号或者来自HDDEC的高清信号CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_Connect(HI_UNF_VBI_SRC_ATTR_S *pstSrcAttr);


/**
\brief stop VBI module. CNcomment: 结束VBI模块。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  hVBI  VBI handle. CNcomment: 模块句柄。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_DisConnect(HI_VOID);


/**
\brief reset VBI module. CNcomment: 复位VBI模块。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  hVBI  VBI handle. CNcomment: 模块句柄。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_Reset(HI_VOID);


/**
\brief Get VBI Signal Information . CNcomment:获取VBI信号信息。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  pstVbiAttr  cc signal information structure. CNcomment:VBI 信号信息结构体。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_GetSignalInfo(HI_UNF_VBI_SIGNALINFO_S *pstVbiAttr);


/**
\brief Get VBI Signal Information . CNcomment:获取CC Buffer数据。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  pstVbiAttr  cc signal information structure. CNcomment:VBI 信号信息结构体。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_AcquireCCBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_CC_DATA_S **pstCCData);

	
/**
\brief Get VBI Signal Information . CNcomment:获取TT Buffer 数据。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  u32AcquireNum  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\param[in]  pu32AcquiredNum  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\param[in]  pu8Data  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_AcquireTTBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_U8 *pu8Data);

/**
\brief Get VBI Signal Information . CNcomment:获取TT Buffer 信息。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  u32AcquireNum  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\param[in]  pu32AcquiredNum  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\param[in]  pstTTData  tt signal information structure. CNcomment:VBI 信号信息结构体。CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_AcquireTTInfoBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_TT_INFO_S **pstTTData);

/**
\brief set VBI attribution before connect vbi module. CNcomment:获取VBI模块字节字序反转的属性。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  bDataInvEn  cc attribution flag. CNcomment数据是否字序翻转标志CNend
\param[in]  bByteInvEn  cc attribution flag. CNcomment数据是否字节翻转标志CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_SetDataInvEN(HI_BOOL bDataInvEn,HI_BOOL bByteInvEn);


/**
\brief Get data byte invert attribution in VBI module. CNcomment: 获取VBI模块字节字序反转的属性。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  bDataInvEn  cc attribution flag. CNcomment数据是否字序翻转标志CNend
\param[in]  bByteInvEn  cc attribution flag. CNcomment数据是否字节翻转标志CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_GetDataInvEN(HI_BOOL *bDataInvEn,HI_BOOL *bByteInvEn);

/**
\brief set VBI attribution before connect vbi module. CNcomment:设置VBI模块QTC采数使能。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  bQtcEn  tt attribution flag. CNcomment:QTC是否采数使能标志位CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_SetQtcEn(HI_BOOL bQtcEn);

/**
\brief set VBI attribution before connect vbi module. CNcomment:获取VBI模块QTC采数是否使能。CNend
\attention \n
none. CNcomment: 无。CNend
\param[in]  bQtcEn  tt attribution flag. CNcomment:QTC是否采数使能标志位CNend
\retval ::HI_SUCCESS success. CNcomment: 成功。CNend
\retval ::HI_FAILURE failure. CNcomment: 失败。CNend
\see \n
none. CNcomment: 无。CNend
*/
HI_S32 HI_UNF_VBI_GetQtcEn(HI_BOOL *bQtcEn);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_VBI_H__ */

