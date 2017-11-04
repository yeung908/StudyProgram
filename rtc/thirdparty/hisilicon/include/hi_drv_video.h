
/******************************************************************************
  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_drv_video.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2012/11/17
Last Modified :
Description   :
Function List :
History       :
******************************************************************************/
#ifndef __HI_DRV_VIDEO_H__
#define __HI_DRV_VIDEO_H__

#include "hi_type.h"
#include "hi_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

typedef enum hiDRV_COLOR_SYS_E
{
    HI_DRV_COLOR_SYS_AUTO = 0,
    HI_DRV_COLOR_SYS_PAL,
    HI_DRV_COLOR_SYS_NTSC,
    HI_DRV_COLOR_SYS_SECAM,
    HI_DRV_COLOR_SYS_PAL_M,
    HI_DRV_COLOR_SYS_PAL_N,
    HI_DRV_COLOR_SYS_PAL_60,
    HI_DRV_COLOR_SYS_NTSC443,
    HI_DRV_COLOR_SYS_NTSC_50,  
    
    HI_DRV_COLOR_SYS_BUTT
} HI_DRV_COLOR_SYS_E;

/**Defines the oversample mode of the current input source.*/
/**CNcomment: 定义当前输入源的过采样模式*/
typedef enum hiDRV_OVERSAMPLE_MODE_E
{
    HI_DRV_OVERSAMPLE_1X = 0,
    HI_DRV_OVERSAMPLE_2X,
    HI_DRV_OVERSAMPLE_4X,   
    HI_DRV_OVERSAMPLE_BUTT,
} HI_DRV_OVERSAMPLE_MODE_E;

typedef enum hiDRV_PIXEL_BITWIDTH_E 
{
    HI_DRV_PIXEL_BITWIDTH_8BIT = 0,
    HI_DRV_PIXEL_BITWIDTH_10BIT,
    HI_DRV_PIXEL_BITWIDTH_12BIT,    
    HI_DRV_PIXEL_BITWIDTH_BUTT,
} HI_DRV_PIXEL_BITWIDTH_E;

typedef enum hiDRV_PIX_FORMAT_E
{
    /* RGB formats */
    HI_DRV_PIX_FMT_RGB332 = 0, /*  8  RGB-3-3-2     */
    HI_DRV_PIX_FMT_RGB444  ,   /* 16  xxxxrrrr ggggbbbb */
    HI_DRV_PIX_FMT_RGB555  ,   /* 16  RGB-5-5-5     */
    HI_DRV_PIX_FMT_RGB565  ,   /* 16  RGB-5-6-5     */
    HI_DRV_PIX_FMT_BGR565  ,   /* 16  RGB-5-6-5     */
    HI_DRV_PIX_FMT_RGB555X ,   /* 16  RGB-5-5-5 BE  */
    HI_DRV_PIX_FMT_RGB565X ,   /* 16  RGB-5-6-5 BE  */
    HI_DRV_PIX_FMT_BGR666  ,   /* 18  BGR-6-6-6   */
    HI_DRV_PIX_FMT_BGR24   ,   /* 24  BGR-8-8-8     */
    HI_DRV_PIX_FMT_RGB24   ,   /* 24  RGB-8-8-8     */
    HI_DRV_PIX_FMT_BGR32   ,   /* 32  BGR-8-8-8-8   */
    HI_DRV_PIX_FMT_RGB32   ,   /* 32  RGB-8-8-8-8   */

    /****** HISI CLUT formats ******/
    HI_DRV_PIX_FMT_CLUT_1BPP,
    HI_DRV_PIX_FMT_CLUT_2BPP,
    HI_DRV_PIX_FMT_CLUT_4BPP,
    HI_DRV_PIX_FMT_CLUT_8BPP,
    HI_DRV_PIX_FMT_ACLUT_44,    
    HI_DRV_PIX_FMT_ACLUT_88,

    /****** HISI 16bit RGB formats ******/
    HI_DRV_PIX_FMT_ARGB4444,
    HI_DRV_PIX_FMT_ABGR4444,     
    HI_DRV_PIX_FMT_RGBA4444,

    HI_DRV_PIX_FMT_ARGB1555,
    HI_DRV_PIX_FMT_ABGR1555,     
    HI_DRV_PIX_FMT_RGBA5551,

    /****** HISI 24bit RGB formats ******/
    HI_DRV_PIX_FMT_ARGB8565,
    HI_DRV_PIX_FMT_ABGR8565,
    HI_DRV_PIX_FMT_RGBA5658,

    HI_DRV_PIX_FMT_ARGB6666,
    HI_DRV_PIX_FMT_RGBA6666,

    /****** HISI 32bit RGB formats ******/
    HI_DRV_PIX_FMT_ARGB8888,
    HI_DRV_PIX_FMT_ABGR8888,
    HI_DRV_PIX_FMT_RGBA8888,

    HI_DRV_PIX_FMT_AYUV8888,
    HI_DRV_PIX_FMT_YUVA8888,

    /* Grey formats */
    HI_DRV_PIX_FMT_GREY    ,    /*  8  Greyscale     */
    HI_DRV_PIX_FMT_Y4      ,    /*  4  Greyscale     */
    HI_DRV_PIX_FMT_Y6      ,    /*  6  Greyscale     */
    HI_DRV_PIX_FMT_Y10     ,    /* 10  Greyscale     */
    HI_DRV_PIX_FMT_Y12     ,    /* 12  Greyscale     */
    HI_DRV_PIX_FMT_Y16     ,    /* 16  Greyscale     */

    /* Grey bit-packed formats */
    HI_DRV_PIX_FMT_Y10BPACK    ,   /* 10  Greyscale bit-packed */

    /* Palette formats */
    HI_DRV_PIX_FMT_PAL8    ,    /*  8  8-bit palette */

    /* Luminance+Chrominance formats */
    HI_DRV_PIX_FMT_YVU410  ,    /*  9  YVU 4:1:0     */
    HI_DRV_PIX_FMT_YVU420  ,    /* 12  YVU 4:2:0     */
    HI_DRV_PIX_FMT_YUYV    ,    /* 16  YUV 4:2:2     */
    HI_DRV_PIX_FMT_YYUV    ,    /* 16  YUV 4:2:2     */
    HI_DRV_PIX_FMT_YVYU    ,    /* 16  YVU 4:2:2 */
    HI_DRV_PIX_FMT_UYVY    ,    /* 16  YUV 4:2:2     */
    HI_DRV_PIX_FMT_VYUY    ,    /* 16  YUV 4:2:2     */
    HI_DRV_PIX_FMT_YUV422P ,    /* 16  YVU422 planar */
    HI_DRV_PIX_FMT_YUV411P ,    /* 16  YVU411 planar */
    HI_DRV_PIX_FMT_Y41P    ,    /* 12  YUV 4:1:1     */
    HI_DRV_PIX_FMT_YUV444  ,    /* 16  xxxxyyyy uuuuvvvv */
    HI_DRV_PIX_FMT_YUV555  ,    /* 16  YUV-5-5-5     */
    HI_DRV_PIX_FMT_YUV565  ,    /* 16  YUV-5-6-5     */
    HI_DRV_PIX_FMT_YUV32   ,    /* 32  YUV-8-8-8-8   */
    HI_DRV_PIX_FMT_YUV410  ,    /*  9  YUV 4:1:0     */
    HI_DRV_PIX_FMT_YUV420  ,    /* 12  YUV 4:2:0     */
    HI_DRV_PIX_FMT_HI240   ,    /*  8  8-bit color   */
    HI_DRV_PIX_FMT_HM12    ,    /*  8  YUV 4:2:0 16x16 macroblocks */
    HI_DRV_PIX_FMT_M420    ,    /* 12  YUV 4:2:0 2 lines y, 
                                   1 line uv interleaved */

    /* two planes -- one Y, one Cr + Cb interleaved  */
    HI_DRV_PIX_FMT_NV08    ,     /*08  Y/CbCr 4:0:0 @*/
    HI_DRV_PIX_FMT_NV80    ,     /*08  Y/CrCb 4:0:0 @*/  
    HI_DRV_PIX_FMT_NV12    ,    /* 12  Y/CbCr 4:2:0  */
    HI_DRV_PIX_FMT_NV21    ,    /* 12  Y/CrCb 4:2:0  */
    HI_DRV_PIX_FMT_NV12_411,    /* 12  Y/CbCr 4:1:1  @*/ 
    HI_DRV_PIX_FMT_NV16    ,    /* 16  Y/CbCr 4:2:2  */
    HI_DRV_PIX_FMT_NV61    ,    /* 16  Y/CrCb 4:2:2  */
    HI_DRV_PIX_FMT_NV16_2X1,    /* 16  Y/CbCr 4:2:2 2X1 @*/                       
    HI_DRV_PIX_FMT_NV61_2X1,    /* 16  Y/CrCb 4:2:2  2X1 @*/
    HI_DRV_PIX_FMT_NV24    ,    /* 24  Y/CbCr 4:4:4  */
    HI_DRV_PIX_FMT_NV42    ,    /* 24  Y/CrCb 4:4:4  */
    HI_DRV_PIX_FMT_NV42_RGB,    /* 24  G/RB 4:4:4  */

    /* two non contiguous planes - one Y, one Cr + Cb interleaved  */
    HI_DRV__PIX_FMT_NV12M  ,    /* 12  Y/CbCr 4:2:0  */
    HI_DRV__PIX_FMT_NV12MT ,    /* 12  Y/CbCr 4:2:0 64x32 macroblocks */

    /* three non contiguous planes - Y, Cb, Cr */
    HI_DRV_PIX_FMT_YUV420M ,    /* 12  YUV420 planar */

    /* Bayer formats - see http://www.siliconimaging.com/RGB%20Bayer.htm */
    HI_DRV_PIX_FMT_SBGGR8  ,    /*  8  BGBG.. GRGR.. */
    HI_DRV_PIX_FMT_SGBRG8  ,    /*  8  GBGB.. RGRG.. */
    HI_DRV_PIX_FMT_SGRBG8  ,    /*  8  GRGR.. BGBG.. */
    HI_DRV_PIX_FMT_SRGGB8  ,    /*  8  RGRG.. GBGB.. */
    HI_DRV_PIX_FMT_SBGGR10 ,    /* 10  BGBG.. GRGR.. */
    HI_DRV_PIX_FMT_SGBRG10 ,    /* 10  GBGB.. RGRG.. */
    HI_DRV_PIX_FMT_SGRBG10 ,    /* 10  GRGR.. BGBG.. */
    HI_DRV_PIX_FMT_SRGGB10 ,    /* 10  RGRG.. GBGB.. */
    HI_DRV_PIX_FMT_SBGGR12 ,    /* 12  BGBG.. GRGR.. */
    HI_DRV_PIX_FMT_SGBRG12 ,    /* 12  GBGB.. RGRG.. */
    HI_DRV_PIX_FMT_SGRBG12 ,    /* 12  GRGR.. BGBG.. */
    HI_DRV_PIX_FMT_SRGGB12 ,    /* 12  RGRG.. GBGB.. */

    /****** HISI Luminance+Chrominance formats ******/

    /****** HISI  contiguoustwo planes -- one Y, one Cr + Cb interleaved ******/
    HI_DRV_PIX_FMT_NV08_CMP,     /*08   Y/CbCr 4:0:0 compressed @*/
    HI_DRV_PIX_FMT_NV80_CMP,     /*08   Y/CrCb 4:0:0 compressed @*/     
    HI_DRV_PIX_FMT_NV12_CMP ,    /* 12  Y/CbCr 4:2:0 compressed */
    HI_DRV_PIX_FMT_NV21_CMP ,    /* 12  Y/CrCb 4:2:0 compressed */
    HI_DRV_PIX_FMT_NV16_CMP ,    /* 16  Y/CbCr 4:2:2 compressed */
    HI_DRV_PIX_FMT_NV61_CMP ,    /* 16  Y/CrCb 4:2:2 compressed */
    HI_DRV_PIX_FMT_NV16_2X1_CMP,    /* 16  Y/CbCr 4:2:2   2X1@*/                      
    HI_DRV_PIX_FMT_NV61_2X1_CMP,    /* 16  Y/CrCb 4:2:2  2X1@*/ 
    HI_DRV_PIX_FMT_NV24_CMP ,    /* 24  Y/CbCr 4:4:4 compressed */
    HI_DRV_PIX_FMT_NV42_CMP ,    /* 24  Y/CrCb 4:4:4 compressed */

    HI_DRV_PIX_FMT_NV12_TILE,    /* 12 tile  */
    HI_DRV_PIX_FMT_NV21_TILE,    /* 21 tile  */
    HI_DRV_PIX_FMT_YUV400_TILE,    /* 21 tile  */

    HI_DRV_PIX_FMT_NV12_TILE_CMP,   /* 12 tile compressed */
    HI_DRV_PIX_FMT_NV21_TILE_CMP,   /* 21 tile compressed */

    /****** HISI three non contiguous planes - Y, Cb, Cr ******/
    HI_DRV_PIX_FMT_YUV400  ,   /*08  YUV400 planar @*/  
    HI_DRV_PIX_FMT_YUV410p  ,   /*10  YUV410 planar @*/                             
    HI_DRV_PIX_FMT_YUV420p ,   /*12  YUV420 planar @*/ 
    HI_DRV_PIX_FMT_YUV411  ,   /*12  YUV411  planar @*/
    HI_DRV_PIX_FMT_YUV422_1X2, /*16  YUV422  planar 1X2 @*/                       
    HI_DRV_PIX_FMT_YUV422_2X1, /*16  YUV422  planar 2X1@*/   
    HI_DRV_PIX_FMT_YUV_444 ,   /*24  YUV444  planar @*/ 

    /****** HISI three non contiguous planes - Y, Cb, Cr ******/

    HI_DRV_PIX_BUTT


}HI_DRV_PIX_FORMAT_E;

typedef enum hiDRV_3D_EYE_E
{
    DRV_3D_LEFT = 0,
    DRV_3D_RIGHT,
    
    DRV_3D_BUTT,
}HI_DRV_3D_EYE_E;



/* video frame filed in buffer */
typedef enum hiDRV_FIELD_MODE_E
{
    HI_DRV_FIELD_TOP = 0,
    HI_DRV_FIELD_BOTTOM,
    HI_DRV_FIELD_ALL,
    HI_DRV_FIELD_BUTT
}HI_DRV_FIELD_MODE_E;

/* video frame type */
typedef enum hiDRV_FRAME_TYPE_E
{
    HI_DRV_FT_NOT_STEREO = 0,
    HI_DRV_FT_SBS,
    HI_DRV_FT_TAB,
    HI_DRV_FT_FPK,
    HI_DRV_FT_FS,
    HI_DRV_FT_BUTT
}HI_DRV_FRAME_TYPE_E;

/* source color space */
typedef enum hiDRV_COLOR_SPACE_E
{
    HI_DRV_CS_UNKNOWN = 0,
    HI_DRV_CS_DEFAULT,
    
    HI_DRV_CS_BT601_YUV_LIMITED,/* ::::Current Used:::: BT.601  */
    HI_DRV_CS_BT601_YUV_FULL,
    HI_DRV_CS_BT601_RGB_LIMITED,
    HI_DRV_CS_BT601_RGB_FULL,
    
    HI_DRV_CS_NTSC1953,
    
    /* These should be useful.  Assume 601 extents. */
    HI_DRV_CS_BT470_SYSTEM_M,    
    HI_DRV_CS_BT470_SYSTEM_BG,

    HI_DRV_CS_BT709_YUV_LIMITED,/* ::::Current Used:::: BT.709 */
    HI_DRV_CS_BT709_YUV_FULL,
    HI_DRV_CS_BT709_RGB_LIMITED,
    HI_DRV_CS_BT709_RGB_FULL,   /* ::::Current Used:::: */

    HI_DRV_CS_BT2020_YUV_LIMITED,/* ::::Current Used:::: BT.2020 */
    HI_DRV_CS_BT2020_YUV_FULL,
    HI_DRV_CS_BT2020_RGB_LIMITED,
    HI_DRV_CS_BT2020_RGB_FULL,   /* ::::Current Used:::: */
    
    HI_DRV_CS_REC709,      /* HD and modern captures. */
    
    HI_DRV_CS_SMPT170M, /* ITU-R 601 -- broadcast NTSC/PAL */
    HI_DRV_CS_SMPT240M, /* 1125-Line (US) HDTV */

    HI_DRV_CS_BT878,    /* broken BT878 extents 
                           (601, luma range 16-253 instead of 16-235) */

    HI_DRV_CS_XVYCC,

    /* I know there will be cameras that send this.  So, this is
     * unspecified chromaticities and full 0-255 on each of the
     * Y'CbCr components
     */
    HI_DRV_CS_JPEG,
    HI_DRV_CS_RGB,
    
    HI_DRV_CS_BUTT
} HI_DRV_COLOR_SPACE_E;

typedef enum hiDRV_GAMMA_TYPE_E
{              
    HI_DRV_GAMMA_TYPE_1886 = 0,
    HI_DRV_GAMMA_TYPE_2084,

    HI_DRV_GAMMA_TYPE_BUTT
} HI_DRV_GAMMA_TYPE_E;

/* frame rotation angle */
typedef enum hiDRV_ROT_ANGLE_E
{
    HI_DRV_ROT_ANGLE_0 = 0,
    HI_DRV_ROT_ANGLE_90,
    HI_DRV_ROT_ANGLE_180,
    HI_DRV_ROT_ANGLE_270,
    HI_DRV_ROT_ANGLE_BUTT
}HI_DRV_ROT_ANGLE_E;

/* driver delay struct */
typedef struct hiDRV_DELAY_S
{
    HI_U32                  u32PanelMemcDelay;        
} HI_DRV_DELAY_S;

/* video frame aspect ratio mode */
typedef enum hiDRV_ASP_RAT_MODE_E
{
    HI_DRV_ASP_RAT_MODE_FULL = 0x0,
    HI_DRV_ASP_RAT_MODE_LETTERBOX,
    HI_DRV_ASP_RAT_MODE_PANANDSCAN,
    HI_DRV_ASP_RAT_MODE_COMBINED,
    HI_DRV_ASP_RAT_MODE_FULL_H,
    HI_DRV_ASP_RAT_MODE_FULL_V,
    HI_DRV_ASP_RAT_MODE_CUSTOMER,
    HI_DRV_ASP_RAT_MODE_TV,
    HI_DRV_ASP_RAT_MODE_P2P,
    HI_DRV_ASP_RAT_MODE_BUTT
}HI_DRV_ASP_RAT_MODE_E;

typedef struct hiDRV_CROP_RECT_S
{
    HI_U32 u32LeftOffset;
    HI_U32 u32TopOffset;
    HI_U32 u32RightOffset;
    HI_U32 u32BottomOffset;
}HI_DRV_CROP_RECT_S;


/* aspect ratio, for monitor or pixel.
  0<= arw <= 256, 0<=arh<=256, and '1/16  <= arw/arh <= 16'.
  e.g., if aspect ratio is 16:9, you can set arw as 16 and arh as 9, 
  OR arw as 160, arh as 90.  
  Exceptive : 
  0:1 means unknown;
  0:2 means display pixel 1:1
  */  
typedef struct hiDRV_ASPECT_RATIO_S
{
    HI_U32 u32ARw;
    HI_U32 u32ARh;
}HI_DRV_ASPECT_RATIO_S;

/* video frame buffer physical address */
typedef struct hiDRV_VID_FRAME_ADDR_S
{
    /* Y address*/
    HI_U32  u32PhyAddr_YHead; /* only for compress format */
    HI_U32  u32PhyAddr_Y;
    HI_U32  u32Stride_Y;

    /* C OR Cb address*/
    HI_U32  u32PhyAddr_CHead;
    HI_U32  u32PhyAddr_C;
    HI_U32  u32Stride_C;

    /* Cr address*/
    HI_U32  u32PhyAddr_CrHead;
    HI_U32  u32PhyAddr_Cr;
    HI_U32  u32Stride_Cr;
}HI_DRV_VID_FRAME_ADDR_S;

typedef enum hiDRV_BUF_ADDR_E
{
    HI_DRV_BUF_ADDR_LEFT  = 0,
    HI_DRV_BUF_ADDR_RIGHT = 1,  /* only for right eye frame of 3D video */
    HI_DRV_BUF_ADDR_MAX
}HI_DRV_BUF_ADDR_E;

#define DEF_HI_DRV_FRAME_INFO_SIZE 128

/* define of how to adjust the TB match */
typedef enum hiDRV_VIDEO_TB_ADJUST_E
{
    HI_DRV_VIDEO_TB_PLAY = 0,
    HI_DRV_VIDEO_TB_REPEAT,
    HI_DRV_VIDEO_TB_DISCARD,
    HI_DRV_VIDEO_TB_BUTT
}HI_DRV_VIDEO_TB_ADJUST_E;


typedef enum hiDRV_SOURCE_E
{              
    HI_DRV_SOURCE_DTV = 0,
    HI_DRV_SOURCE_USB,

    HI_DRV_SOURCE_ATV,
    HI_DRV_SOURCE_SCART,
    HI_DRV_SOURCE_SVIDEO,
    HI_DRV_SOURCE_CVBS,         
    HI_DRV_SOURCE_VGA,
    HI_DRV_SOURCE_YPBPR,
    HI_DRV_SOURCE_HDMI,
    HI_DRV_SOURCE_GRAPHIC,

    HI_DRV_SOURCE_BUTT
} HI_DRV_SOURCE_E;

/* Source Timing Info */
typedef struct hiDRV_VIDEO_ORIGINAL_INFO_S
{
    HI_DRV_SOURCE_E             enSource;       //DTV Default HI_DRV_SOURCE_DTV
    HI_U32                      u32Width;       //source width
    HI_U32                      u32Height;      //source height
    HI_U32                      u32FrmRate;     //source framerate
    HI_DRV_FRAME_TYPE_E         en3dType;       //source 3D Type
    HI_DRV_COLOR_SPACE_E        enSrcColorSpace;//Only use three Type:BT601_YUV_LIMITED,BT709_YUV_LIMITED,BT709_RGB_FULL
    HI_DRV_COLOR_SYS_E          enColorSys;     //DTV Default HI_DRV_COLOR_SYS_AUTO
    HI_BOOL                     bGraphicMode;   //DTV default HI_FALSE
    HI_BOOL                     bInterlace;     //source is Interlace or Progress
    
}HI_DRV_VIDEO_ORIGINAL_INFO_S;

typedef HI_DRV_VIDEO_ORIGINAL_INFO_S      HI_DRV_TIMING_INFO_S ;

typedef enum hiHI_DRV_PULLDOWN_MODE_E
{
	HI_DRV_PULLDOWN_MODE_32 = 0, 
	HI_DRV_PULLDOWN_MODE_2332,
	HI_DRV_PULLDOWN_MODE_2224,
	HI_DRV_PULLDOWN_MODE_64,
	HI_DRV_PULLDOWN_MODE_55,
	HI_DRV_PULLDOWN_MODE_32322,
	HI_DRV_PULLDOWN_MODE_87,
	HI_DRV_PULLDOWN_MODE_11_2_3,
	HI_DRV_PULLDOWN_MODE_22,
	HI_DRV_PULLDOWN_MODE_BUTT
}HI_DRV_PULLDOWN_MODE_E;

typedef struct hiDRV_VIDEO_HDR10_METADATA_STREAM_S
{
    HI_U32                u32DispPrimariesX0;
    HI_U32                u32DispPrimariesY0;
    HI_U32                u32DispPrimariesX1;
    HI_U32                u32DispPrimariesY1;
    HI_U32                u32DispPrimariesX2;
    HI_U32                u32DispPrimariesY2;
    HI_U32                u32WhitePointX;
    HI_U32                u32WhitePointY;
    HI_U32                u32MaxDispMasteringLuminance;
    HI_U32                u32MinDispMasteringLuminance;
    HI_U32                u32MaxContentLightLevel;
    HI_U32                u32MaxFrmAverageLightLevel;
}HI_DRV_VIDEO_HDR10_METADATA_STREAM_S;
typedef struct hiDRV_VIDEO_HDR10_INFO_S
{
    HI_BOOL                              bValid;
    HI_DRV_COLOR_SPACE_E                 enColorSpace;
    HI_DRV_GAMMA_TYPE_E                  enGammaType;
    HI_DRV_VIDEO_HDR10_METADATA_STREAM_S stMetadata;
}HI_DRV_VIDEO_HDR10_INFO_S;
typedef struct hiDRV_VIDEO_FRAME_S
{    
    HI_U32                   u32FrameIndex;                         //frame Index
    /* stBufAddr[1] is right eye for stereo video */
    HI_DRV_VID_FRAME_ADDR_S  stBufAddr[HI_DRV_BUF_ADDR_MAX];
    HI_U32                   u32TunnelPhyAddr;
    HI_HANDLE                hTunnelSrc;
    HI_U32                   u32Width;
    HI_U32                   u32Height;

    //:TODO: ATV set as 0xffffffff
    HI_U32                   u32SrcPts;                             /* 0xffffffff means unknown                  */
    HI_U32                   u32Pts;                                /* 0xffffffff means unknown                  */
    HI_S64                   s64OmxPts;                             /* for OMX */

    //:TODO: ATV don't need , set as 1:1
    HI_U32                   u32AspectWidth;
    HI_U32                   u32AspectHeight;
    HI_U32                   u32FrameRate;                          /* in 1/1000 Hz, 0 means unknown              */

    HI_DRV_PIX_FORMAT_E      ePixFormat;                            //pixel format and store format is the same?
    HI_BOOL                  bProgressive;                          //:TODO:what is this for?
    HI_DRV_FIELD_MODE_E      enFieldMode;                           //:TODO:what is this for?
    HI_BOOL                  bTopFieldFirst;

    HI_BOOL                  bCompressd;
    HI_DRV_PIXEL_BITWIDTH_E  enBitWidth;

    //display region in rectangle (x,y,w,h)
    HI_RECT_S                stDispRect;                            //:TODO:what is this for?

    HI_DRV_FRAME_TYPE_E      eFrmType;                              // 3D storage format in DDR

    HI_U32                   u32Circumrotate;                       //:TODO:what is this for?

    HI_BOOL                  bToFlip_V;                             //only DTV need
    HI_U32                   u32ErrorLevel;                         //???????
    HI_U32                   u32Priv[DEF_HI_DRV_FRAME_INFO_SIZE];   /* must be 0 */ //??????????,????
    /* **********above as unf***************/

    HI_RECT_S                stLbxInfo;
    union{
        HI_DRV_VIDEO_HDR10_INFO_S           stHDR10Info;            /**<HDR10 frame info.*/ /**<CNcomment:  HDR10帧信息*/
    }unHDRInfo;

    /*****************VBI Data**********************/
	HI_BOOL				     bVboKeyFrame;
	HI_BOOL				     bIfmdEnable;
	HI_DRV_PULLDOWN_MODE_E   enFilmMode;
	HI_S32				     s32PhaseOffset;
    /***********************************************/ 
}HI_DRV_VIDEO_FRAME_S;

typedef struct hiDRV_VIDEO_HDR_S
{
    HI_BOOL                 bValid;
    HI_DRV_COLOR_SPACE_E    enColorSpace;
	HI_DRV_GAMMA_TYPE_E     enGammaType;
}HI_DRV_VIDEO_HDR_S;

/*private struct*/
typedef struct hiDRV_VIDEO_PRIVATE_S
{
    
    HI_DRV_VIDEO_ORIGINAL_INFO_S  stVideoOriginalInfo;  //Video original info
    HI_BOOL                 bValid;
    HI_U32                  u32LastFlag;        /*最后一帧标记*/
    HI_DRV_COLOR_SPACE_E    eColorSpace;        //Current Frame ColorSpace, when DTV VPSS will set this, when Atv Vicap will set this
    HI_U32                  u32BufferID;        //Buffer ID
    HI_U32                  u32FrmCnt;
    HI_U32                  u32PlayTime;        
    HI_U32                  u32Fidelity;
    HI_DRV_FIELD_MODE_E     eOriginField;       /*?DEI???,????????????*/
    HI_U32                  u32PrivDispTime;    //This displaytime is for pvr smooth tplay
    HI_DRV_VIDEO_HDR_S      stVideoHDRInfo;
    HI_U32					u32PrivBufPhyAddr;
    HI_U32                  u32Reserve[29];     //Reserve Bytes
}HI_DRV_VIDEO_PRIVATE_S;

#define DEF_HI_DRV_FRAME_PACKAGE_MAX_FRAME_NUMBER 3
//add by l00225186
/*vdec frame include port handle*/
typedef struct hiDRV_VDEC_FRAME_S
{
    HI_HANDLE hport;
    HI_DRV_VIDEO_FRAME_S stFrameVideo;
}HI_DRV_VDEC_FRAME_S;
/* video frame package */
typedef struct hiDRV_VIDEO_FRAME_PACKAGE_S
{
    HI_U32 u32FrmNum;
    HI_DRV_VDEC_FRAME_S stFrame[DEF_HI_DRV_FRAME_PACKAGE_MAX_FRAME_NUMBER];
}HI_DRV_VIDEO_FRAME_PACKAGE_S;

#define DEF_HI_DRV_VIDEO_BUFFER_MAX_NUMBER 16

/* extern frame buffer setting for virtual window, 
   user alloc memory and set this setting to virtual window.*/
typedef struct hiDRV_VIDEO_BUFFER_POOL_S
{
    HI_S32 s32BufNum;
    HI_S32 s32BufStride;
    HI_S32 s32BufHeight;
    HI_U32 u32PhyAddr[DEF_HI_DRV_VIDEO_BUFFER_MAX_NUMBER];
}HI_DRV_VIDEO_BUFFER_POOL_S;

/* VI/VDEC Module information, it could be calllback to win-sourece */
typedef struct hiDRV_PRE_PROCESS_INFO_S
{
    /* self handle */
    HI_HANDLE                   WinHandle;

    HI_U32                      u32LayerNO;
    HI_U32                      u32RegionNO;

    HI_DRV_PIX_FORMAT_E         ePixFmt;//post module expect pixer format

    //if use crop rect, tv always set True and use HI_DRV_CROP_RECT_S */
    HI_BOOL                     bUseCropRect;
    HI_DRV_CROP_RECT_S          stCropRect;
    
    /* (0,0,0,0) means full imgae, not clip */
    HI_RECT_S                   stInRect;  

    /* New Add Fort TV Only:the Rect of video after SCL,Without LBA*/
    HI_RECT_S                   stVideoRect;
    
    /* the Rect of video after SCL+LBA */
    HI_RECT_S                   stOutRect;

    /* TV set 1:1 */
    HI_DRV_ASPECT_RATIO_S       stCustmAR;
    
    /* TV always set FULL*/
    HI_DRV_ASP_RAT_MODE_E       enARCvrs; 

    /* external buffer config */
    HI_BOOL                     bUseExtBuf;
    HI_DRV_VIDEO_BUFFER_POOL_S  stExtBufPool;
    
    /* TV always False */
    HI_BOOL                     bInterlaced;
    
    /* output format resolution, TV always panel Resolution */
    HI_RECT_S                   stScreen; 
    
    /* STB use as output pixel Aspect,TV don't care */
    HI_DRV_ASPECT_RATIO_S       stScreenAR;
    HI_BOOL                     bIn3DMode;
    HI_BOOL                     bTunnelSupport;
    HI_DRV_ROT_ANGLE_E          enRotation;
    HI_BOOL                     bVertFlip;
    HI_BOOL                     bHoriFlip;
    
    /*Display MaxRate:in 1/100 Hz', if 0, full rate*/
    HI_U32                      u32MaxRate;

    /* New Add For TV Only */
    HI_BOOL                     bFrcEnable;
    HI_BOOL                     bMain;
    
    /* is Main Full Screen display */
    HI_BOOL                     bFullScreen;
    HI_BOOL                     bAvOut;
    HI_BOOL                     bLeftEye;
    HI_BOOL                     bNonLinerZME;

}HI_DRV_PRE_PROCESS_INFO_S;

// TODO: to be delete
typedef HI_DRV_PRE_PROCESS_INFO_S HI_DRV_WIN_PRIV_INFO_S;
    

/**Defines the info of not standard video.*/
/**CNcomment: 定义非标视频信号的信息*/
typedef struct hiDRV_VIDEO_NONSTD_INFO_S
{
    HI_BOOL bNonStd;            /* 是否非标 */                            
    HI_U32  u32Height;          /* 非标图像高度 */  
    HI_U32  u32VFreq;           /* 非标输入场频 单位为每千秒场数目，61050表示61.05Hz */
} HI_DRV_VIDEO_NONSTD_INFO_S;


/* Main Window Info */
typedef struct hiDRV_MAIN_WIN_INFO_S
{
    HI_BOOL                     bMainWinVaild;
    HI_BOOL                     bFullScreen;

    HI_DRV_TIMING_INFO_S        stTimingInfo;    
    HI_DRV_VIDEO_NONSTD_INFO_S  stNstdInfo;
    HI_BOOL                     bMemcEnableCtrl;
    HI_BOOL				        bContentChange;//VBI Data
}HI_DRV_MAIN_WIN_INFO_S;


/* 从WINMGR获取的信息,更新到DISP */
typedef struct hiDRV_WIN_FRAME_INFO_S
{
    HI_U32                  u32SrcRate;
    HI_U32                  bKeyFrame;
    HI_RECT_S               stLbxRegion;
    HI_RECT_S               stLbxAddRegion;
    HI_RECT_S               stSubRegion;
    HI_U32                  u32FrameWidth;
    HI_U32                  u32FrameHeight;
    HI_DRV_COLOR_SPACE_E    enTimingColorSpace;
    HI_DRV_COLOR_SPACE_E    enFrameColorSpace;
    HI_DRV_VIDEO_HDR10_INFO_S   stHDR10Info;
    /*****************VBI Data**********************/
    HI_BOOL                 bVboKeyFrame;
    HI_BOOL                 bIfmdEnable;
    HI_DRV_PULLDOWN_MODE_E  enFilmMode;
    HI_S32                  s32PhaseOffset;
    HI_U32                  u32PhyAddr_Y;
    HI_U32                  u32FrameIndex;
    HI_U32                  u32WinState;
    
    /***********************************************/    	
    
}HI_DRV_WIN_FRAME_INFO_S;

typedef struct hiDRV_DISP_EXPECT_INFO_S
{
    HI_BOOL b3dDisplay;
    HI_U32  u32SrcFrmRate;
    HI_U32  u32DispExpectWidth;
    HI_U32  u32DispExpectHeight;
    
}HI_DRV_DISP_EXPECT_INFO_S;


typedef struct taghiDRV_WIN_FRAME_NODE_S
{
    HI_DRV_VIDEO_FRAME_S        stFrame;
    HI_U32                      u32FrameNum;
    HI_DRV_VIDEO_TB_ADJUST_E    enTBAdjust;
    HI_BOOL                     bQueByUser;
}HI_DRV_WIN_FRAME_NODE_S;

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_DRV_VIDEO_H__ */



