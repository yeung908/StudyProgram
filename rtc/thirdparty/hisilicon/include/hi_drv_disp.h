/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_disp.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/15
  Description   :
  History       :
  1.Date        : 2013/11/15
    Author      : z00208650
    Modification: Created file

******************************************************************************/
#ifndef __HI_DRV_DISP_H__
#define __HI_DRV_DISP_H__

#include "hi_type.h"
#include "hi_common.h"
#include "hi_debug.h"
#include "hi_drv_video.h"
//#include "hi_drv_panel.h"

//#include "drv_pq_ext.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif
#ifndef HI_ADVCA_FUNCTION_RELEASE
#if ((!defined __DISP_PLATFORM_BOOT__) && (!defined __VDP_ST__))
#define HI_FATAL_DISP(fmt...) \
            HI_FATAL_PRINT(HI_ID_DISP, fmt)

#define HI_ERR_DISP(fmt...) \
            HI_ERR_PRINT(HI_ID_DISP, fmt)

#define HI_WARN_DISP(fmt...) \
            HI_WARN_PRINT(HI_ID_DISP, fmt)

#define HI_INFO_DISP(fmt...) \
            HI_INFO_PRINT(HI_ID_DISP, fmt)
#else
#define HI_FATAL_DISP(fmt...)        printf(fmt)

#define HI_ERR_DISP(fmt...)           printf(fmt)

#define HI_WARN_DISP(fmt...)          printf(fmt)

#define HI_INFO_DISP(fmt...)          printf(fmt)
#endif
#else

#define HI_FATAL_DISP(fmt...)
#define HI_ERR_DISP(fmt...)
#define HI_WARN_DISP(fmt...)
#define HI_INFO_DISP(fmt...) 
#endif

#define DEF_HI_DRV_DISP_MIRROR_BUFFER_MAX_NUMBER    16
#define DEF_HI_DRV_DISP_MAX_LAYER_NUMBER            8
#define DEF_DISP_CALLBACK_MAX_EVENT                 8

/* display ID */
typedef enum hiDRV_DISPLAY_E
{
    HI_DRV_DISPLAY_0 = 0,
    HI_DRV_DISPLAY_1,
    HI_DRV_DISPLAY_2,
    
    HI_DRV_DISPLAY_BUTT
}HI_DRV_DISPLAY_E;

typedef enum hiDRV_DISP_LAYER_E
{
    HI_DRV_DISP_LAYER_NONE = 0,
    HI_DRV_DISP_LAYER_VIDEO,

    HI_DRV_DISP_LAYER_GFX,
    
    HI_DRV_DISP_LAYER_BUTT
}HI_DRV_DISP_LAYER_E;


typedef enum hiDRV_DISP_ZORDER_E
{
    HI_DRV_DISP_ZORDER_MOVETOP = 0,
    HI_DRV_DISP_ZORDER_MOVEUP,
    HI_DRV_DISP_ZORDER_MOVEBOTTOM,
    HI_DRV_DISP_ZORDER_MOVEDOWN,
    HI_DRV_DISP_ZORDER_BUTT
}HI_DRV_DISP_ZORDER_E;

typedef enum hiDRV_DISP_FMT_E
{
    HI_DRV_DISP_FMT_1080P_60 = 0,         /**<1080p 60 Hz*/
    HI_DRV_DISP_FMT_1080P_50,         /**<1080p 50 Hz*/
    HI_DRV_DISP_FMT_1080P_30,         /**<1080p 30 Hz*/
    HI_DRV_DISP_FMT_1080P_25,         /**<1080p 25 Hz*/
    HI_DRV_DISP_FMT_1080P_24,         /**<1080p 24 Hz*/

    HI_DRV_DISP_FMT_1080i_60,         /**<1080i 60 Hz*/
    HI_DRV_DISP_FMT_1080i_50,         /**<1080i 60 Hz*/

    HI_DRV_DISP_FMT_720P_60,          /**<720p 60 Hz*/
    HI_DRV_DISP_FMT_720P_50,          /**<720p 50 Hz */

    HI_DRV_DISP_FMT_576P_50,          /**<576p 50 Hz*/
    HI_DRV_DISP_FMT_480P_60,          /**<480p 60 Hz*/

    HI_DRV_DISP_FMT_PAL,              /* B D G H I PAL */
    HI_DRV_DISP_FMT_PAL_B,            /* B PAL， Australia */
    HI_DRV_DISP_FMT_PAL_B1,           /* B1 PAL, Hungary */
    HI_DRV_DISP_FMT_PAL_D,            /* D PAL, China */
    HI_DRV_DISP_FMT_PAL_D1,           /* D1 PAL， Poland */
    HI_DRV_DISP_FMT_PAL_G,            /* G PAL， Europe */
    HI_DRV_DISP_FMT_PAL_H,            /* H PAL， Europe */
    HI_DRV_DISP_FMT_PAL_K,            /* K PAL， Europe */
    HI_DRV_DISP_FMT_PAL_I,            /* I PAL，U.K. */
    HI_DRV_DISP_FMT_PAL_N,            /* N PAL, Jamaica/Uruguay */
    HI_DRV_DISP_FMT_PAL_Nc,           /* Nc PAL, Argentina */

    HI_DRV_DISP_FMT_PAL_M,            /* M PAL, 525 lines */
    HI_DRV_DISP_FMT_PAL_60,           /* 60 PAL */
    HI_DRV_DISP_FMT_NTSC,             /* (M)NTSC       */
    HI_DRV_DISP_FMT_NTSC_J,           /* NTSC-J        */
    HI_DRV_DISP_FMT_NTSC_443,          /* (M)PAL        */

    HI_DRV_DISP_FMT_SECAM_SIN,      /**< SECAM_SIN*/
    HI_DRV_DISP_FMT_SECAM_COS,      /**< SECAM_COS*/
    HI_DRV_DISP_FMT_SECAM_L,        /**< France*/
    HI_DRV_DISP_FMT_SECAM_B,        /**< Middle East*/
    HI_DRV_DISP_FMT_SECAM_G,        /**< Middle East*/
    HI_DRV_DISP_FMT_SECAM_D,        /**< Eastern Europe*/
    HI_DRV_DISP_FMT_SECAM_K,        /**< Eastern Europe*/
    HI_DRV_DISP_FMT_SECAM_H,        /**< Line SECAM*/

    HI_DRV_DISP_FMT_1440x576i_50,
    HI_DRV_DISP_FMT_1440x480i_60,

    HI_DRV_DISP_FMT_1080P_24_FP,
    HI_DRV_DISP_FMT_720P_60_FP,
    HI_DRV_DISP_FMT_720P_50_FP,
    
    HI_DRV_DISP_FMT_861D_640X480_60,
    HI_DRV_DISP_FMT_VESA_800X600_60,
    HI_DRV_DISP_FMT_VESA_1024X768_60,
    HI_DRV_DISP_FMT_VESA_1280X720_60,
    HI_DRV_DISP_FMT_VESA_1280X800_60,
    HI_DRV_DISP_FMT_VESA_1280X1024_60,
    HI_DRV_DISP_FMT_VESA_1360X768_60,         //Rowe
    HI_DRV_DISP_FMT_VESA_1366X768_60,
    HI_DRV_DISP_FMT_VESA_1400X1050_60,        //Rowe
    HI_DRV_DISP_FMT_VESA_1440X900_60,
    HI_DRV_DISP_FMT_VESA_1440X900_60_RB,
    HI_DRV_DISP_FMT_VESA_1600X900_60_RB,
    HI_DRV_DISP_FMT_VESA_1600X1200_60,
    HI_DRV_DISP_FMT_VESA_1680X1050_60,       //Rowe
    HI_DRV_DISP_FMT_VESA_1680X1050_60_RB,       //Rowe
    HI_DRV_DISP_FMT_VESA_1920X1080_60,
    HI_DRV_DISP_FMT_VESA_1920X1200_60,
    HI_DRV_DISP_FMT_VESA_1920X1440_60,
    HI_DRV_DISP_FMT_VESA_2048X1152_60,
    HI_DRV_DISP_FMT_VESA_2560X1440_60_RB,
    HI_DRV_DISP_FMT_VESA_2560X1600_60_RB,

    HI_DRV_DISP_FMT_3840X2160_24,/*reserve for extention*/
    HI_DRV_DISP_FMT_3840X2160_25,
    HI_DRV_DISP_FMT_3840X2160_30,
    HI_DRV_DISP_FMT_4096X2160_24,
    //ADD
    HI_DRV_DISP_FMT_CUSTOM,

    HI_DRV_DISP_FMT_BUTT
}HI_DRV_DISP_FMT_E;

typedef enum hiDRV_DISP_VDAC_SIGNAL_E
{
    HI_DRV_DISP_VDAC_NONE = 0,
    HI_DRV_DISP_VDAC_CVBS,
    HI_DRV_DISP_VDAC_Y,
    HI_DRV_DISP_VDAC_PB,
    HI_DRV_DISP_VDAC_PR,
    HI_DRV_DISP_VDAC_SV_Y,
    HI_DRV_DISP_VDAC_SV_C,
    HI_DRV_DISP_VDAC_R,
    HI_DRV_DISP_VDAC_G,
    HI_DRV_DISP_VDAC_B,
    HI_DRV_DISP_VDAC_G_NOSYNC,
    HI_DRV_DISP_VDAC_SIGNAL_BUTT
}HI_DRV_DISP_VDAC_SIGNAL_E;

typedef enum hiDRV_DISP_INTF_ID_E
{
    HI_DRV_DISP_INTF_YPBPR0 = 0,
    HI_DRV_DISP_INTF_RGB0,
    HI_DRV_DISP_INTF_SVIDEO0,
    HI_DRV_DISP_INTF_CVBS0,
    HI_DRV_DISP_INTF_VGA0,

    HI_DRV_DISP_INTF_HDMI0,
    HI_DRV_DISP_INTF_HDMI1,
    HI_DRV_DISP_INTF_HDMI2,

    HI_DRV_DISP_INTF_BT656_0,
    HI_DRV_DISP_INTF_BT656_1,
    HI_DRV_DISP_INTF_BT656_2,

    HI_DRV_DISP_INTF_BT1120_0,
    HI_DRV_DISP_INTF_BT1120_1,
    HI_DRV_DISP_INTF_BT1120_2,

    HI_DRV_DISP_INTF_LCD0,
    HI_DRV_DISP_INTF_LCD1,
    HI_DRV_DISP_INTF_LCD2,

    HI_DRV_DISP_INTF_PANEL,
    HI_DRV_DISP_INTF_AVOUT,

    HI_DRV_DISP_INTF_ID_MAX
}HI_DRV_DISP_INTF_ID_E;

#define HI_DISP_VDAC_MAX_NUMBER 4
#define HI_DISP_VDAC_INVALID_ID 0xff
typedef struct hiDRV_DISP_INTF_S
{
    HI_DRV_DISP_INTF_ID_E   enID;
    HI_DRV_SOURCE_E         enAvoutSource;
    
    HI_U8                   u8VDAC_Y_G;
    HI_U8                   u8VDAC_Pb_B;
    HI_U8                   u8VDAC_Pr_R;
    HI_BOOL                 bDacSync;
}HI_DRV_DISP_INTF_S;

typedef enum hiDRV_DISP_INTF_DATA_FMT
{
    HI_DRV_DISP_INTF_DATA_FMT_YUV422 = 0,
    HI_DRV_DISP_INTF_DATA_FMT_RGB565,
    HI_DRV_DISP_INTF_DATA_FMT_RGB444,
    HI_DRV_DISP_INTF_DATA_FMT_RGB666,
    HI_DRV_DISP_INTF_DATA_FMT_RGB888,
    HI_DRV_DISP_INTF_DATA_FMT_BUTT
}HI_DRV_DISP_INTF_DATA_FMT_E;

typedef struct hiDRV_DISP_TIMING_S
{
    HI_U32  u32VFB;
    HI_U32  u32VBB;
    HI_U32  u32VACT;
    HI_U32  u32HFB;
    HI_U32  u32HBB;
    HI_U32  u32HACT;
    HI_U32  u32VPW;
    HI_U32  u32HPW;
    HI_BOOL bIDV;
    HI_BOOL bIHS;
    HI_BOOL bIVS;
    HI_BOOL bClkReversal;
    HI_U32  u32DataWidth;
    HI_DRV_DISP_INTF_DATA_FMT_E eDataFmt;

    HI_BOOL bDitherEnable;
    HI_U32  u32ClkPara0;
    HI_U32  u32ClkPara1;

    HI_BOOL bInterlace;
    HI_U32  u32PixFreq;
    HI_U32  u32VertFreq;
    HI_U32  u32AspectRatioW;
    HI_U32  u32AspectRatioH;

    HI_BOOL u32bUseGamma;

    HI_U32  u32Reserve0; 
    HI_U32  u32Reserve1; 
}HI_DRV_DISP_TIMING_S;


typedef enum hiDRV_DISP_STEREO_E
{
    HI_DRV_DISP_STEREO_NONE = 0,
    HI_DRV_DISP_STEREO_FPK,
    HI_DRV_DISP_STEREO_SBS_HALF,
    HI_DRV_DISP_STEREO_TAB,
    HI_DRV_DISP_STEREO_FIELD_ALTE,
    HI_DRV_DISP_STEREO_LINE_ALTE_LR,
    HI_DRV_DISP_STEREO_SBS_FULL,
    HI_DRV_DISP_STEREO_L_DEPT,
    HI_DRV_DISP_STEREO_L_DEPT_G_DEPT,
    HI_DRV_DISP_STEREO_LINE_ALTE_RL,
    HI_DRV_DISP_STEREO_BUTT
    
}HI_DRV_DISP_STEREO_E;

typedef struct hiDISP_CROP_S
{
    HI_U32 u32TopOffset;
    HI_U32 u32BottomOffset;
    HI_U32 u32LeftOffset;
    HI_U32 u32RightOffset;
}HI_DRV_DISP_CROP_S;

typedef struct hiDRV_DISP_OFFSET_S
{
    HI_U32 u32Top;
    HI_U32 u32Bottom;
    HI_U32 u32Right; 
    HI_U32 u32Left;
}HI_DRV_DISP_OFFSET_S;

typedef struct hiRESOLUTION_S
{
    HI_U32 u32Width;
    HI_U32 u32Height;
} HI_RESOLUTION_S;

/* New Add for TV Only */

/* 3D转2D左右眼选择 */
typedef enum hiDRV_DISP_3DT2D
{
    HI_DRV_DISP_3DT2D_L,           /* 3D转2D左眼 */
    HI_DRV_DISP_3DT2D_R,           /* 3D转2D右眼 */
    
    HI_DRV_DISP_3DT2D_BUTT,       
} HI_DRV_DISP_3DT2D_E;


typedef enum hiDRV_DISP_3DMODE
{
    HI_DRV_DISP_3DMODE_2D = 0,
    HI_DRV_DISP_3DMODE_2DTO3D,
    HI_DRV_DISP_3DMODE_3D,
    
    HI_DRV_DISP_3DMODE_BUTT    
} HI_DRV_DISP_3DMODE_E;


/* Test Pattern Type */
typedef enum hiDRV_DISP_PATTERN_E
{
    HI_DRV_DISP_PATTERN_BLACK = 0,
    HI_DRV_DISP_PATTERN_WHITE,
    HI_DRV_DISP_PATTERN_RED,
    HI_DRV_DISP_PATTERN_GREEN,
    HI_DRV_DISP_PATTERN_BLUE,
    HI_DRV_DISP_PATTERN_GRAY,
    
    HI_DRV_DISP_PATTERN_BUTT,
} HI_DRV_DISP_PATTERN_E;

typedef enum hiDRV_DISP_SR_POS_E
{
    HI_DRV_DISP_SR_POS_NO = 0,
    HI_DRV_DISP_SR_POS_DHD0,
    HI_DRV_DISP_SR_POS_VP0,
    HI_DRV_DISP_SR_POS_GP0,
    
    HI_DRV_DISP_SR_POS_BUTT,
}HI_DRV_DISP_SR_POS_E;

typedef struct hiDRV_DISP_PATTERN_S
{
    HI_BOOL                bEnable;    /* Test pattern Enable */
    HI_DRV_DISP_PATTERN_E  enPattern;  /* Test Pattern Type */
} HI_DRV_DISP_PATTERN_S;

typedef struct tagDISP_HAL_CAPACITY_S
{
    /*显示通道是否支持  */
    HI_BOOL              bChannelSupport;

    /*回写通道属性  */
    HI_BOOL              bSupportWbc;
    HI_U32               u32WbcMaxSupportWidth;
    HI_U32               u32WbcMaxSupportHeight;
    HI_U32               u32WbcMinSupportWidth;
    HI_U32               u32WbcMinSupportHeight;

    /*SR属性*/
    HI_BOOL              bSupportSR;

    /*MEMC属性*/
    HI_BOOL              bSupportMEMC;

    /*INK属性*/
    HI_BOOL              bSupportINK;    
}DISP_HAL_CAPACITY_S;

typedef struct hiDISP_VBI_INFO_S
{
    HI_BOOL                 bKeyFrm;
    HI_BOOL                 bIfmdEnable;
    HI_BOOL                 bContentChange;
    HI_DRV_PULLDOWN_MODE_E  enFilmMode;
    HI_S32                  s32PhaseOffset;
    HI_U32                  u32OsdBmpWidth;
    HI_U32                  u32OsdBmpHeight;
    HI_U32                  u32HcBmpWidth;
    HI_U32                  u32HcBmpHeight;
    HI_U32                  u32HcPosX;
    HI_U32                  u32HcPosY;
    HI_U32                  u32PhyAddr_Y;
    HI_U32                  u32FrameIndex;
}DISP_VBI_INFO_S;

typedef struct hiDRV_DISP_DISPLAY_INFO_S
{
    HI_BOOL                 bEnable;
    HI_BOOL                 bDispInfoUpdate;
    
    HI_BOOL                 bIsMaster;
    HI_BOOL                 bIsSlave;
    HI_DRV_DISPLAY_E        enAttachedDisp;

    /*DHD state now*/
    HI_BOOL                 bInterlace;
    HI_BOOL                 bIsBottomField;
    HI_U32                  u32Vline;
    HI_BOOL                 b3DRightEye;

    HI_U32                  u32IntTime;

    /*3D config*/
    HI_DRV_DISP_3DMODE_E    en3dMode;
    HI_DRV_DISP_STEREO_E    en3dFormat;
    HI_BOOL                 bRightEyeFirst;
    HI_DRV_3D_EYE_E         enCurrentDispEye; /* 中断记录SG播放时当前是否为左眼显示 */  
    HI_U32                  u32DepthLevel;
    HI_U32                  u32ViewLevel;

    HI_RESOLUTION_S         stVirtualScreen;        
    HI_RESOLUTION_S         stVideoVirtualScreen;        
    HI_DRV_DISP_OFFSET_S    stOffsetInfo;
    HI_RESOLUTION_S         stFmtResolution;
    HI_RESOLUTION_S         stPixelFmtResolution;

    HI_DRV_ASPECT_RATIO_S   stAR;
    HI_U32                  u32RefreshRate;

    HI_U32                  u32Bright;
    HI_U32                  u32Hue;
    HI_U32                  u32Satur;
    HI_U32                  u32Contrst;

    HI_U32                  u32Kr;
    HI_U32                  u32Kg;
    HI_U32                  u32Kb;
    HI_COLOR_S              stBGColor;

    HI_BOOL                 bSrEnable;
    HI_DRV_DISP_SR_POS_E    enSrPosition;
    HI_RESOLUTION_S         stVideoMixResolution;
    HI_RESOLUTION_S         stExpVidMixResolution;
    HI_RESOLUTION_S         stVideoGfxMixResolution;
    HI_RESOLUTION_S         stCourserMixResolution;
    HI_RESOLUTION_S         stPanelResolution;
    HI_U32                  u32MixFrmRate;
    HI_U32                  u32PreMixFrmRate;
    HI_DRV_COLOR_SPACE_E    enMixColorSpace;
    HI_DRV_COLOR_SPACE_E    enVideoMixColorSpace;
    
    HI_U32                  u32FrcDelay;
    HI_BOOL                 bMemcEnable;
    HI_BOOL                 bHorFlip;
    HI_BOOL                 bVerFlip;
    
    HI_BOOL                 bFrameLockEn;
    HI_BOOL                 bOffLine;
    /*record VDP deciding result  */
    HI_BOOL                 bVDPDecMemcEnable;
    
    HI_U32                  u32NowRate;
    HI_U32                  u32AverageRate;
    HI_U32                  u32TotalRate;
    HI_DRV_DELAY_S          stDelayInfo;
    DISP_HAL_CAPACITY_S     stDispCap;
    DISP_VBI_INFO_S         stDispVbiInfo;
    HI_BOOL                 bDispModChg; //for 2D3Dmode change
 
}HI_DRV_DISP_DISPLAY_INFO_S;

typedef enum hiFRAMELOCK_DEBUG_E
{
    FRAMELOCK_DEBUG_INCREASE_ONLY = 0,
    FRAMELOCK_DEBUG_DECREASE_ONLY,
    FRAMELOCK_DEBUG_INCREASE_WAVE,
    FRAMELOCK_DEBUG_DECREASE_WAVE,

    FRAMELOCK_DEBUG_BUTT
} FRAMELOCK_DEBUG_E;

typedef struct
{
    HI_U32         u32PixClock;             //像素时钟
    HI_U32         u32Vtotal;               //
    HI_U32         u32Htotal;

    HI_U32         u32TargetClock;          //目标时钟
    HI_U32         u32CurrentClock;         //粗调时钟
    HI_U32         u32TuneClock;            //微调时钟
    HI_U32         u32RunningClock;         //记录当前实际运行的时钟
   
    HI_U32         u32StartLine;            //开始调整时钟的行数
    HI_U32         u32Tolerance;            //获取目标时钟的容忍门限
    HI_BOOL        bLineTune;               //是否开始按行开始调整时钟
    HI_BOOL        bGetStartline;           //是否获取到开始调整的行数

    HI_BOOL        bSignalStable;           //信号是否稳定

    HI_U32         u32CoarseTuneStep;       //粗调的时钟幅度
    HI_U32         u32FineTuneStep;         //微调的时钟幅度
    
    HI_U32         u32UnchangeCount;        //无信号时的中断统计值

    HI_U32         u32VsyncCapVDPCount;     //vivdp之间的差距统计值
    HI_U32         u32CapFrmCnt;            //vi的行统计值

    HI_U32         u32DistanceLine;         //计算出的vivdp之间的行数差距
    HI_U32         u32ClkSetCount;          //经过framelock调整后设置时钟的次数统计
    HI_BOOL        bForceFrameLockOff;      //强制关闭framelock标志位
    HI_BOOL        bNoneIntFrmRate;         //非整数倍帧率标志

    HI_U32         u32DiffVsyncCapVDPCount; //连续两个中断之间vivdp差距统计值的差值

    HI_U32         u32ClkRate;              //输出帧率和输入帧率之间的倍率，放大10倍

    HI_U32         u32IncCount;             //vivdp之间距离在缩小，统计当前一直在缩小的中断数，获取TargetClk时++
    HI_U32         u32DecCount;             //vivdp之间距离在增大，统计当前一直在增大的中断数，获取TargetClk时--
    HI_U32         u32UncCount;             //vivdp之间距离在稳定，统计当前一直在稳定的中断数，确定TargetClk

    HI_BOOL        bGetTargetClk;           //标志当前已经获取到TargetClk
    HI_BOOL        bTargetClkOutRange;      //非标信号时，标志当前已经获取到的TargetClk超出容忍门限，会导致异常，如低带宽...

    HI_U32         u32TarVsyncCapVDPCount;  //统计vivdp之间距离在缩小或增大时的参考值

    HI_BOOL                     bDebug;                  //调试标志
    HI_U32                      u32DebugCount;           //调试打印次数
    HI_U32                      u32UserSetCount;           //调试打印次数
    HI_BOOL                     bClockSetDebug;

    FRAMELOCK_DEBUG_E           enDebugType;
    HI_BOOL                     bDebugPanel;
    HI_U32                      u32DebugClock;
    HI_U32                      u32IntCount;
}HI_DRV_DISP_FRAMELOCK_S;

/*************** IP protect ***************/
//Macrovision
typedef enum hiDRV_DISP_MACROVISION_E
{
    HI_DRV_DISP_MACROVISION_TYPE0,
    HI_DRV_DISP_MACROVISION_TYPE1,
    HI_DRV_DISP_MACROVISION_TYPE2,
    HI_DRV_DISP_MACROVISION_TYPE3,
    HI_DRV_DISP_MACROVISION_CUSTOMER,
    HI_DRV_DISP_MACROVISION_BUTT
}HI_DRV_DISP_MACROVISION_E;


//CGMS-A
typedef enum hiDRV_DISP_CGMSA_TYPE_E
{
    HI_DRV_DISP_CGMSA_A = 0x00,
    HI_DRV_DISP_CGMSA_B,
    HI_DRV_DISP_CGMSA_TYPE_BUTT
}HI_DRV_DISP_CGMSA_TYPE_E;

typedef enum hiDRV_DISP_CGMSA_MODE_E
{
   HI_DRV_DISP_CGMSA_COPY_FREELY  = 0,
   HI_DRV_DISP_CGMSA_COPY_NO_MORE = 0x01,
   HI_DRV_DISP_CGMSA_COPY_ONCE    = 0x02,
   HI_DRV_DISP_CGMSA_COPY_NEVER   = 0x03,
      
   HI_DRV_DISP_CGMSA_MODE_BUTT
}HI_DRV_DISP_CGMSA_MODE_E;

typedef struct hiDRV_DISP_CGMSA_CFG_S
{
    HI_BOOL                     bEnable;
    HI_DRV_DISP_CGMSA_TYPE_E    enType;
    HI_DRV_DISP_CGMSA_MODE_E    enMode;
}HI_DRV_DISP_CGMSA_CFG_S;


/*************** about VBI ***************/
typedef enum hiDRV_DISP_VBI_TYPE_E
{
    HI_DRV_DISP_VBI_TTX=0,
    HI_DRV_DISP_VBI_CC,
    HI_DRV_DISP_VBI_VCHIP,
    HI_DRV_DISP_VBI_WSS,
    HI_DRV_DISP_VBI_TYPE_BUTT
}HI_DRV_DISP_VBI_TYPE_E;

typedef struct hiDRV_DISP_VBI_CFG_S
{
    HI_DRV_DISP_VBI_TYPE_E  eType;
    HI_U32                  u32InBufferSize;
    HI_U32                  u32WorkBufferSize;
}HI_DRV_DISP_VBI_CFG_S;

typedef struct hiDRV_DISP_VBI_DATA_S
{
    HI_DRV_DISP_VBI_TYPE_E  eType;
    HI_U64                  u64DataAddr;
    HI_U32                  u32DataLen;
}HI_DRV_DISP_VBI_DATA_S;

typedef struct hiDRV_DISP_WSS_DATA_S
{
    HI_BOOL bEnable;
    HI_U16  u16Data;
}HI_DRV_DISP_WSS_DATA_S;

typedef struct hiDRV_DISP_HDMI_S
{
    HI_BOOL bHsyncNegative; 
    HI_BOOL bVsyncNegative; 
    HI_BOOL bDvNegative;    
    HI_S32  s32SyncType;    

    HI_S32  s32CompNumber;  //0,10bit; 1, 20bit; 2, 30bit
    HI_S32  s32DataFmt;     //0:YCbCr;1: RGB
}HI_DRV_DISP_HDMI_S;

typedef struct hiDRV_DISP_SNAPSHOT_ATTR_S
{
    HI_BOOL     bSnapResoSet;
    HI_U32      u32Width;
    HI_U32      u32Height;
} HI_DRV_DISP_SNAPSHOT_ATTR_S;

typedef struct hiDRV_DISP_CAST_CFG_S
{
    /* frame config */
    HI_DRV_PIX_FORMAT_E eFormat; /* Support ... */
    HI_U32              u32Width;
    HI_U32              u32Height;

    HI_U32              u32BufNumber; /* not more than HI_DISP_MIRROR_BUFFER_MAX_NUMBER */
    HI_BOOL             bUserAlloc;  /* TRUE: user alloc buffers; FALSE: enDisp alloc buffers */
    HI_BOOL             bLowDelay;
    HI_U32              u32BufSize;    /* every buffer size in Byte */
    HI_U32              u32BufStride;  /* only for 'bUserAlloc = TRUE' */
    HI_U32              u32BufPhyAddr[DEF_HI_DRV_DISP_MIRROR_BUFFER_MAX_NUMBER]; /* only for 'bUserAlloc = TRUE' */
} HI_DRV_DISP_CAST_CFG_S;


typedef struct hiDRV_DISP_VERSION_S
{
    HI_U32 u32VersionPartL;
    HI_U32 u32VersionPartH;
}HI_DRV_DISP_VERSION_S;



typedef enum hiDRV_DISP_CALLBACK_TYPE_E
{
    /* 中断发起位置，以行有效区为参考，0为第一行，100为最后一行结束 */
    HI_DRV_DISP_C_TYPE_NONE = 0,
    //HI_DRV_DISP_C_SHOW_MODE,
    HI_DRV_DISP_C_INTPOS_0_PERCENT,
    HI_DRV_DISP_C_INTPOS_90_PERCENT,
    HI_DRV_DISP_C_INTPOS_100_PERCENT,
    HI_DRV_DISP_C_DHD0_WBC,
    HI_DRV_DISP_C_GFX_WBC,
    HI_DRV_DISP_C_REG_UP,
    HI_DRV_DISP_C_LOW_BANDWIDTH,
    HI_DRV_DISP_C_TYPE_ALL,
    HI_DRV_DISP_C_TYPE_BUTT
}HI_DRV_DISP_CALLBACK_TYPE_E;

typedef enum hiDRV_DISP_MIXER_POS_E
{
    /* 视频和图形叠加 */
    HI_DRV_DISP_MIXER_VIDEO_GFX = 0,

    /* 鼠标叠加 */
    HI_DRV_DISP_MIXER_CURSOR,

    HI_DRV_DISP_MIXER_BUTT,
}HI_DRV_DISP_MIXER_POS_E;


typedef enum hiDRV_DISP_CALLBACK_EVENT_E
{
    HI_DRV_DISP_C_EVET_NONE = 0,
    HI_DRV_DISP_C_PREPARE_CLOSE,
    //HI_DRV_DISP_C_CLOSE            = 0x2,
    //HI_DRV_DISP_CALLBACK_PREPARE_TO_OPEN,
    HI_DRV_DISP_C_OPEN,
    
    HI_DRV_DISP_C_PREPARE_TO_PEND  = 0x10,
    //HI_DRV_DISP_C_PEND             = 0x20,
    //HI_DRV_DISP_C_PREPARE_TO_RESUME,
    HI_DRV_DISP_C_RESUME,

    HI_DRV_DISP_C_DISPLAY_SETTING_CHANGE = 0x20,
    
    HI_DRV_DISP_C_VT_INT = 0x100,
    HI_DRV_DISP_C_EVENT_BUTT
}HI_DRV_DISP_CALLBACK_EVENT_E;

typedef enum hiDRV_DISP_FIELD_FLAG_E
{
    HI_DRV_DISP_FIELD_PROGRESSIVE = 0,
    HI_DRV_DISP_FIELD_TOP,
    HI_DRV_DISP_FIELD_BOTTOM,
    HI_DRV_DISP_FIELD_FLAG_BUTT
}HI_DRV_DISP_FIELD_FLAG_E;



typedef struct hiDRV_DISP_Cast_Attr_S
{
    HI_S32  s32Width;
    HI_S32  s32Height;    
}HI_DRV_DISP_Cast_Attr_S;

typedef struct hiDRV_DISP_CALLBACK_S
{
    HI_VOID     (* pfDISP_Callback)(HI_HANDLE hDst, HI_DRV_DISP_MIXER_POS_E enMixerPos, 
        const HI_DRV_DISP_DISPLAY_INFO_S *pstDisplayInfo);
    HI_HANDLE   hDst;
}HI_DRV_DISP_CALLBACK_S;

typedef enum  hiDISP_VIRTSCREEN_TYPE_E
{
    HI_DISP_VIRTSCREEN_VIDEO = 0,
    HI_DISP_VIRTSCREEN_GFX,
}HI_DISP_VIRTSCREEN_TYPE_E;

typedef enum hiDRV_DISP_INK_POS_E
{
    HI_DRV_DISP_INK_CSC_F = 0,
    HI_DRV_DISP_INK_CSC_B,
    HI_DRV_DISP_INK_GAMMA_F,
    HI_DRV_DISP_INK_GAMMA_B,
    HI_DRV_DISP_INK_WBC,
 
    HI_DRV_DISP_INK_BUTT,
} DRV_DISP_INK_POS_E;

typedef struct hiHI_DRV_DISP_INKATTR_S
{
    DRV_DISP_INK_POS_E      enInkPos;
    HI_BOOL                 bInkDisplay;
    HI_U32                  u32x;
    HI_U32                  u32y;
} HI_DRV_DISP_INKATTR_S;

typedef struct hiHI_DRV_DISP_INK_S
{
    HI_DRV_DISP_INKATTR_S   stInkAttr;
    HI_DRV_VIDEO_FRAME_S    stFrame;
    HI_COLOR_S              stRGB;
    HI_BOOL                 bFrame;  
    
} HI_DRV_DISP_INK_S;




HI_S32 HI_DRV_DISP_Init(HI_VOID);
HI_S32 HI_DRV_DISP_DeInit(HI_VOID);
HI_S32 HI_DRV_DISP_Suspend(HI_VOID);
HI_S32 HI_DRV_DISP_Resume(HI_VOID);

HI_S32 HI_DRV_DISP_Attach(HI_DRV_DISPLAY_E enDstDisp, HI_DRV_DISPLAY_E enSlave);
HI_S32 HI_DRV_DISP_Detach(HI_DRV_DISPLAY_E enDstDisp, HI_DRV_DISPLAY_E enSlave);
HI_S32 HI_DRV_DISP_SetFormat(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_STEREO_E enStereo, HI_DRV_DISP_FMT_E enEncFmt);
HI_S32 HI_DRV_DISP_GetFormat(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_STEREO_E *penStereo, HI_DRV_DISP_FMT_E *penEncFmt);

HI_S32 HI_DRV_DISP_SetCustomTiming(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_TIMING_S *pstTiming);
HI_S32 HI_DRV_DISP_GetCustomTiming(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_TIMING_S *pstTiming);
HI_S32 HI_DRV_DISP_AddIntf(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf);
HI_S32 HI_DRV_DISP_DelIntf(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INTF_S *pstIntf);

HI_S32 HI_DRV_DISP_Open(HI_DRV_DISPLAY_E enDisp);

HI_S32 HI_DRV_DISP_Close(HI_DRV_DISPLAY_E enDisp);
HI_S32 HI_DRV_DISP_SetEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_DRV_DISP_GetEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable);
HI_S32 HI_DRV_DISP_SetRightEyeFirst(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);

HI_S32 HI_DRV_DISP_SetVirtualScreen(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Width,
        HI_U32 u32Height, HI_DISP_VIRTSCREEN_TYPE_E enType);
HI_S32 HI_DRV_DISP_GetVirtualScreen(HI_DRV_DISPLAY_E enDisp, HI_U32 *u32Width,
        HI_U32 *u32Height, HI_DISP_VIRTSCREEN_TYPE_E enType);
HI_S32 HI_DRV_DISP_SetScreenOffset(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_OFFSET_S *pstScreenoffset);
HI_S32 HI_DRV_DISP_GetScreenOffset(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_OFFSET_S *pstScreenoffset);

HI_S32 HI_DRV_DISP_SetBgColor(HI_DRV_DISPLAY_E enDisp, HI_COLOR_S *pstBgColor);
HI_S32 HI_DRV_DISP_GetBgColor(HI_DRV_DISPLAY_E enDisp, HI_COLOR_S *pstBgColor);


HI_S32 HI_DRV_DISP_SetAspectRatio(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Ratio_h, HI_U32 u32Ratio_v);
HI_S32 HI_DRV_DISP_GetAspectRatio(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32Ratio_h, HI_U32 *pu32Ratio_v);

HI_S32 HI_DRV_DISP_SetLayerZorder(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_LAYER_E enLayer, HI_DRV_DISP_ZORDER_E enZFlag);
HI_S32 HI_DRV_DISP_GetLayerZorder(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_LAYER_E enLayer, HI_U32 *pu32Zorder);

//MiraCast
HI_S32 HI_DRV_DISP_CreateCast (HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_CAST_CFG_S * pstCfg, HI_HANDLE *phCast);
HI_S32 HI_DRV_DISP_DestroyCast(HI_HANDLE hCast);
HI_S32 HI_DRV_DISP_SetCastEnable(HI_HANDLE hCast, HI_BOOL bEnable);
HI_S32 HI_DRV_DISP_GetCastEnable(HI_HANDLE hCast, HI_BOOL *pbEnable);
HI_S32 HI_DRV_DISP_AcquireCastFrame(HI_HANDLE hCast, HI_DRV_VIDEO_FRAME_S *pstCastFrame);
HI_S32 HI_DRV_DISP_ReleaseCastFrame(HI_HANDLE hCast, HI_DRV_VIDEO_FRAME_S *pstCastFrame);
HI_S32 HI_DRV_DISP_ExternalAttach(HI_HANDLE hCast, HI_HANDLE hsink);
HI_S32 HI_DRV_DISP_ExternalDeAttach(HI_HANDLE hCast, HI_HANDLE hsink);
HI_S32 HI_DRV_DISP_SetCastAttr(HI_HANDLE hCast, HI_U32 u32Width, HI_U32 u32Height);
HI_S32 HI_DRV_DISP_GetCastAttr(HI_HANDLE hCast, HI_DRV_DISP_Cast_Attr_S *castAttr);

//snapshot
HI_S32 HI_DRV_DISP_SetSnapShotAttr(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_SNAPSHOT_ATTR_S *pstSnapShotAttr);
HI_S32 HI_DRV_DISP_AcquireSnapshot(HI_DRV_DISPLAY_E enDisp, HI_DRV_VIDEO_FRAME_S* pstSnapShotFrame);//, HI_HANDLE *snapshotHandleOut);
HI_S32 HI_DRV_DISP_ReleaseSnapshot(HI_DRV_DISPLAY_E enDisp, HI_DRV_VIDEO_FRAME_S* pstSnapShotFrame);//, HI_HANDLE snapshotHandle);


//Macrovision
HI_S32 HI_DRV_DISP_TestMacrovisionSupport(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbSupport);
HI_S32 HI_DRV_DISP_SetMacrovisionCustomer(HI_DRV_DISPLAY_E enDisp, HI_VOID *pData);
HI_S32 HI_DRV_DISP_SetMacrovision(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MACROVISION_E enMode);
HI_S32 HI_DRV_DISP_GetMacrovision(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MACROVISION_E *penMode);

//cgms-a
HI_S32 HI_DRV_DISP_SetCGMS_A(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_CGMSA_CFG_S *pstCfg);

//vbi
HI_S32 HI_DRV_DISP_CreateVBIChannel(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_VBI_CFG_S *pstCfg, HI_HANDLE *phVbi);
HI_S32 HI_DRV_DISP_DestroyVBIChannel(HI_HANDLE hVbi);
HI_S32 HI_DRV_DISP_SendVbiData(HI_HANDLE hVbi, HI_DRV_DISP_VBI_DATA_S *pstVbiData);
HI_S32 HI_DRV_DISP_SetWss(HI_HANDLE hVbi, HI_DRV_DISP_WSS_DATA_S *pstWssData);


HI_S32 HI_DRV_DISP_GetInitFlag(HI_BOOL *pbInited);
HI_S32 HI_DRV_DISP_GetVersion(HI_DRV_DISP_VERSION_S *pstVersion);
HI_BOOL HI_DRV_DISP_IsOpened(HI_DRV_DISPLAY_E enDisp);
HI_S32 HI_DRV_DISP_GetSlave(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISPLAY_E *penSlave);
HI_S32 HI_DRV_DISP_GetMaster(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISPLAY_E *penMaster);
HI_S32 HI_DRV_DISP_GetDisplayInfo(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_DISPLAY_INFO_S *pstDisplayInfo);
HI_S32 HI_DRV_DISP_Process(HI_U32 cmd, HI_VOID *arg);
HI_S32 HI_DRV_DISP_RegCallback(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MIXER_POS_E enMixerPos,
    HI_DRV_DISP_CALLBACK_TYPE_E eType, HI_DRV_DISP_CALLBACK_S *pstCB);
HI_S32 HI_DRV_DISP_UnRegCallback(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_MIXER_POS_E enMixerPos,
    HI_DRV_DISP_CALLBACK_TYPE_E eType, HI_DRV_DISP_CALLBACK_S *pstCB);

/* New Add for TV_ONLY_API */

/* 3D Related API, 3D LR Swith use API of STB HI_DRV_DISP_SetRightEyeFirst() */
HI_S32 HI_DRV_DISP_Get3dDepthRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S *pstDepthRange);
HI_S32 HI_DRV_DISP_Set3dDepthLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 u32DepthLevel);
HI_S32 HI_DRV_DISP_Get3dDepthLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32DepthLevel);

HI_S32 HI_DRV_DISP_Get3dViewRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S * pstViewRange);
HI_S32 HI_DRV_DISP_Set3dViewLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 u32ViewLevel);
HI_S32 HI_DRV_DISP_Get3dViewLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 *pu32ViewLevel);

HI_S32 HI_DRV_DISP_SetVideo3dMode(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_3DMODE_E en3dMode);
HI_S32 HI_DRV_DISP_GetVideo3dMode(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_3DMODE_E *pen3dMode);

HI_S32 HI_DRV_DISP_Set3dTo2dMode(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_3DT2D_E en3dTo2dMode);
HI_S32 HI_DRV_DISP_Get3dTo2dMode(HI_DRV_DISPLAY_E enDisp,  HI_DRV_DISP_3DT2D_E *pen3dTo2dMode);


/* Frc Enable and Level Adjust API*/
HI_S32 HI_DRV_DISP_GetMemcRange(HI_DRV_DISPLAY_E enDisp, HI_RANGE_S *pstRange);

HI_S32 HI_DRV_DISP_SetMemcDemo(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_DRV_DISP_GetMemcDemo(HI_DRV_DISPLAY_E enDisp, HI_U32 *pbEnable);

/* Frc Enable and Level Adjust API*/
HI_S32 HI_DRV_DISP_SetMemcLevel(HI_DRV_DISPLAY_E enDisp, HI_U32 u32FRCLevel);
HI_S32 HI_DRV_DISP_GetMemcLevel(HI_DRV_DISPLAY_E enDisp,  HI_U32 *pu32FRCLevel);

HI_S32 HI_DRV_DISP_SetMemcPara(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Addr, HI_U32 u32Value);
HI_S32 HI_DRV_DISP_GetMemcPara(HI_DRV_DISPLAY_E enDisp, HI_U32 u32Addr,  HI_U32 *pu32Value);

HI_S32 HI_DRV_DISP_SetMemcEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_DRV_DISP_GetMemcEnable(HI_DRV_DISPLAY_E enDisp, HI_U32 *pbEnable);

/* Flip and Mirror related API */
HI_S32 HI_DRV_DISP_SetFlip(HI_DRV_DISPLAY_E enDisp, HI_BOOL bHorFlip, HI_BOOL bVerFlip);
HI_S32 HI_DRV_DISP_GetFlip(HI_DRV_DISPLAY_E enDisp, HI_BOOL *bHorFlip, HI_BOOL *bVerFlip);

/* TV Factory mode Test Pattern 由应用层提供??? */
//HI_S32 HI_DRV_DISP_SetTestPattern(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_PATTERN_S *pstPattern);
//HI_S32 HI_DRV_DISP_GetTestPattern(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_PATTERN_S *pstPattern);

/* Interface Test pattern,Color Bar */
HI_S32 HI_DRV_DISP_SetColorBarEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable);
HI_S32 HI_DRV_DISP_GetColorBarEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable);

/* Interface Test pattern, Background color */
HI_S32 HI_DRV_DISP_SetTestPatternEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL bEnable, HI_COLOR_S stPatColor);
HI_S32 HI_DRV_DISP_GetTestPatternEnable(HI_DRV_DISPLAY_E enDisp, HI_BOOL *pbEnable, HI_COLOR_S *pstPatColor);

HI_S32 HI_DRV_DISP_GetInkRGB(HI_DRV_DISPLAY_E enDisp, HI_DRV_DISP_INK_S *pstInk);

HI_S32 HI_DRV_DISP_SetDelayAttr(HI_DRV_DISPLAY_E enDisp, HI_DRV_DELAY_S *pstDelayAttr);
HI_S32 HI_DRV_DISP_GetDelayAttr(HI_DRV_DISPLAY_E enDisp, HI_DRV_DELAY_S *pstDelayAttr);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

