/*----------------------------------------------------------------------------*
 * Copyright Statement:                                                       *
 *                                                                            *
 *   This software/firmware and related documentation ("MediaTek Software")   *
 * are protected under international and related jurisdictions'copyright laws *
 * as unpublished works. The information contained herein is confidential and *
 * proprietary to MediaTek Inc. Without the prior written permission of       *
 * MediaTek Inc., any reproduction, modification, use or disclosure of        *
 * MediaTek Software, and information contained herein, in whole or in part,  *
 * shall be strictly prohibited.                                              *
 * MediaTek Inc. Copyright (C) 2010. All rights reserved.                     *
 *                                                                            *
 *   BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND     *
 * AGREES TO THE FOLLOWING:                                                   *
 *                                                                            *
 *   1)Any and all intellectual property rights (including without            *
 * limitation, patent, copyright, and trade secrets) in and to this           *
 * Software/firmware and related documentation ("MediaTek Software") shall    *
 * remain the exclusive property of MediaTek Inc. Any and all intellectual    *
 * property rights (including without limitation, patent, copyright, and      *
 * trade secrets) in and to any modifications and derivatives to MediaTek     *
 * Software, whoever made, shall also remain the exclusive property of        *
 * MediaTek Inc.  Nothing herein shall be construed as any transfer of any    *
 * title to any intellectual property right in MediaTek Software to Receiver. *
 *                                                                            *
 *   2)This MediaTek Software Receiver received from MediaTek Inc. and/or its *
 * representatives is provided to Receiver on an "AS IS" basis only.          *
 * MediaTek Inc. expressly disclaims all warranties, expressed or implied,    *
 * including but not limited to any implied warranties of merchantability,    *
 * non-infringement and fitness for a particular purpose and any warranties   *
 * arising out of course of performance, course of dealing or usage of trade. *
 * MediaTek Inc. does not provide any warranty whatsoever with respect to the *
 * software of any third party which may be used by, incorporated in, or      *
 * supplied with the MediaTek Software, and Receiver agrees to look only to   *
 * such third parties for any warranty claim relating thereto.  Receiver      *
 * expressly acknowledges that it is Receiver's sole responsibility to obtain *
 * from any third party all proper licenses contained in or delivered with    *
 * MediaTek Software.  MediaTek is not responsible for any MediaTek Software  *
 * releases made to Receiver's specifications or to conform to a particular   *
 * standard or open forum.                                                    *
 *                                                                            *
 *   3)Receiver further acknowledge that Receiver may, either presently       *
 * and/or in the future, instruct MediaTek Inc. to assist it in the           *
 * development and the implementation, in accordance with Receiver's designs, *
 * of certain softwares relating to Receiver's product(s) (the "Services").   *
 * Except as may be otherwise agreed to in writing, no warranties of any      *
 * kind, whether express or implied, are given by MediaTek Inc. with respect  *
 * to the Services provided, and the Services are provided on an "AS IS"      *
 * basis. Receiver further acknowledges that the Services may contain errors  *
 * that testing is important and it is solely responsible for fully testing   *
 * the Services and/or derivatives thereof before they are used, sublicensed  *
 * or distributed. Should there be any third party action brought against     *
 * MediaTek Inc. arising out of or relating to the Services, Receiver agree   *
 * to fully indemnify and hold MediaTek Inc. harmless.  If the parties        *
 * mutually agree to enter into or continue a business relationship or other  *
 * arrangement, the terms and conditions set forth herein shall remain        *
 * effective and, unless explicitly stated otherwise, shall prevail in the    *
 * event of a conflict in the terms in any agreements entered into between    *
 * the parties.                                                               *
 *                                                                            *
 *   4)Receiver's sole and exclusive remedy and MediaTek Inc.'s entire and    *
 * cumulative liability with respect to MediaTek Software released hereunder  *
 * will be, at MediaTek Inc.'s sole discretion, to replace or revise the      *
 * MediaTek Software at issue.                                                *
 *                                                                            *
 *   5)The transaction contemplated hereunder shall be construed in           *
 * accordance with the laws of Singapore, excluding its conflict of laws      *
 * principles.  Any disputes, controversies or claims arising thereof and     *
 * related thereto shall be settled via arbitration in Singapore, under the   *
 * then current rules of the International Chamber of Commerce (ICC).  The    *
 * arbitration shall be conducted in English. The awards of the arbitration   *
 * shall be final and binding upon both parties and shall be entered and      *
 * enforceable in any court of competent jurisdiction.                        *
 *---------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * $RCSfile: mtvdo.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtvdo.h
 *  This header file declares exported APIs of Video (VDO) module.
 */

#ifndef MT_VDO_H
#define MT_VDO_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mttype.h"
//#include "u_drv_cust.h"  

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
/**Command type of video MTAL interface
*/
typedef enum
{
    VDO_GET_SCAN_MODE = 0,                  ///< Get scan mode
    VDO_SET_GET_3D_IMG_SAFTY,               ///< Set and get 3D image safety
    VDO_GET_3D_FMT_CAP,                     ///< Get 3D format capability
    VDO_GET_3D_CTRL_CAP,                    ///< Get 3D control capability 
    VDO_GET_3D_NAV_MODE,                    ///< Get 3D navigation mode
    VDO_GET_3D_DONE_BY_MJC,                 ///< Get flag of 3D-done-by-MJC
    VDO_GET_MIN_SRC_REGION_WIDTH,           ///< Get minimum width of source region
    VDO_GET_MIN_SRC_REGION_HEIGHT,          ///< Get minimum height of source region
    VDO_GET_TDTV_GETTAG3D,                  ///< Get 3D format detected by decoder
    VDO_GET_TDTV_GETDECTAG3D,               ///< Get 3D format detected by multimedia decoder
    VDO_SET_PENTOUCH_MODE,                  ///< Set Pentouch mode
    VDO_GET_MUTE_STATUS,                    ///< Get video mute status
} MTVDO_VDO_TYPE_T;

/**The video plane mode
*/
#define VDO_MODE_NORMAL             0       ///< normal mode, video out
#define VDO_MODE_BG                 1       ///< background mode, mute
#define VDO_MODE_UNKNOWN            2       ///< Unknown type

/**SRM TV mode
*/
typedef enum
{
    MTVDO_SRM_TV_MODE_TYPE_NORMAL = 0,      ///< Set as single mode
    MTVDO_SRM_TV_MODE_TYPE_PIP,             ///< Set as PIP mode
    MTVDO_SRM_TV_MODE_TYPE_POP,             ///< Set as POP mode
    MTVDO_SRM_TV_MODE_TYPE_SCART_OUT_ON,    ///< Turn on scart out
    MTVDO_SRM_TV_MODE_TYPE_SCART_OUT_OFF,   ///< Turn off scart out
    MTVDO_SRM_TV_MODE_TYPE_LAST_VALID_ENTRY ///< Unknown type
} MTVDO_SRM_TV_MODE_T;

/** PQ argument type
*/
typedef enum
{
    VDO_PQ_RGB_GAIN_OFST = 0,           ///< RGB gain/offset
    VDO_PQ_RGB_GAIN,                    ///< RGB gain
    VDO_PQ_RGB_OFST1,                   ///< RGB offset1 before RGB gain
    VDO_PQ_RGB_OFST2,                   ///< RGB offset1 after RGB gain
    VDO_PQ_EXP_COLOR,                   ///< Expert color control for luma/saturation/hue
    VDO_PQ_XVYCC,                       ///< xvYCC
    VDO_PQ_XVRGB_GAIN,                  ///< xvYCC 3x3 gain matrix
    VDO_PQ_ADAP_LUMA_CURVE_MANUAL,      ///< Adaptive luma curve manual control mode
    VDO_PQ_ADAP_LUMA_CURVE,             ///< Adaptive luma curve
    VDO_PQ_MATRIX_INPUT,                ///< Input 3x3 matrix control
    VDO_PQ_MATRIX_OUTPUT,               ///< Output 3x3 matrix control
    VDO_PQ_GAMMA_CURVE,                 ///< Gamma curve control: 8-bit table
    VDO_PQ_GAMMA_CURVE_EX,              ///< Gamma curve control: 12-bit table
    VDO_PQ_SCE,                         ///< SCE update curve from default table
    VDO_PQ_SCE_PARTIAL_START_IDX,       ///< SCE set partial update start index
    VDO_PQ_SCE_PARTIAL,                 ///< SCE partial update curve
    VDO_PQ_YLEV_SHARP,                  ///< TDSharp Y-level sharpness
    VDO_PQ_BOB_MODE,                    ///< De-interlace bob mode
    VDO_PQ_FILM_ON_OFF,                 ///< De-interlace film mode 
    VDO_PQ_CHROMA_CORING,               ///< Chroma-coring control
    VDO_PQ_RGB_PATTERN,                 ///< RGB test pattern
    VDO_PQ_SCE_PATTERN,                 ///< YCbCr test pattern
    VDO_PQ_MJC_FBCK_CURVE,              ///< MJC fall-back curve
    VDO_PQ_DIR_SET,                     ///< Direct set value to register
    VDO_PQ_DIR_GET,                     ///< Direct read value from register
    VDO_PQ_LUMA_INFO_GET,               ///< Get luma related information of video content
    VDO_PQ_CHROMA_INFO_GET,             ///< Get chroma related information of video content
    VDO_PQ_FILM_STATUS_GET,             ///< Get film mode status
    VDO_PQ_SCE_INPUT_CAP_GET,           ///< Get pixel value captured form SCE input stage
    VDO_PQ_SCE_OUTPUT_CAP_GET,          ///< Get pixel value captured form SCE output stage
    VDO_PQ_OSTG_CAP_GET,                ///< Get pixel value captured form output stage
    VDO_PQ_SET_OD_TABLE,                ///< OD table control
    VDO_PQ_SET_PCID_TABLE,              ///< PCID table control
    VDO_PQ_APL_CURVE,                   ///< APL curve control
    VDO_PQ_CONTRAST_SKIN_CURVE,         ///< Adaptive luma curve for skin tone
    VDO_PQ_COLOR_CURVE,                 ///< SCE partical update curve
    VDO_PQ_MOTION_LEVEL_GET,            ///< Get video motion level
    VDO_PQ_PICTURE_MODE,                ///< Picture mode control
    VDO_PQ_TD_DISPARITY,                ///< Get 3D disparity of video content
    VDO_PQ_TD_DEPTH_CONTROL,            ///< 3D depth control
    VDO_PQ_FRC_FRAME_DELAY,             ///< Get FRC frame delay
    VDO_PQ_SET_OD_PCID_SEL,             ///< OD PCID mode select
    VDO_PQ_SET_OD_SWAP_LINE,            ///< OD swap line control
    VDO_PQ_PEDESTAL_SET,                ///< Input 3x3 matrix pedestal
    VDO_PQ_VGA_COLOR_SPACE_SET,         ///< VGA color space control
    VDO_PQ_LCDIM_LIGHTPROF_TABLE,       ///< Local dimming light profile table
    VDO_PQ_LCDIM_GAIN_TABLE,            ///< Local dimming gain table
    VDO_PQ_SET_OD_ENABLE,               ///< OD table enable
    VDO_PQ_SET_FB_ENABLE,               ///< OD FB table enable
    VDO_PQ_SET_PCID_ENABLE,             ///< OD PCID enable
    VDO_PQ_SET_FB_TABLE,                ///< OD FB table control
    VDO_PQ_SET_COLOR_FILTER,            ///< Set color filter
    VDO_PQ_SET_PRE_PATTERN,             ///< Set pre-proc pattern
    VDO_PQ_NS                           ///< total pq items
} MTVDO_PQ_TYPE_T;

/** 3D format type
*/
typedef enum
{
    MTVDO_TAG3D_2D = 0,                     ///< 2D 
    MTVDO_TAG3D_MVC,                        ///< Multi-View Codec 
    MTVDO_TAG3D_FP,                         ///< Frame Packing
    MTVDO_TAG3D_FS,                         ///< Frame Sequential 
    MTVDO_TAG3D_TB,                         ///< Top-and-bottom 
    MTVDO_TAG3D_SBS,                        ///< Side-by-side
    MTVDO_TAG3D_REALD,                      ///< RealD
    MTVDO_TAG3D_SENSIO,                     ///< Sensio
    MTVDO_TAG3D_LI,                         ///< Line Interleave
    MTVDO_TAG3D_CB,                         ///< Checker Board
    MTVDO_TAG3D_DA,                         ///< Dot Alternative
    MTVDO_TAG3D_TTDO,                       ///< 2D-to-3D only
    MTVDO_TAG3D_NOT_SUPPORT
} MTVDO_TAG3D_TYPE_T;

/**Video plane call back function type id.
*/
typedef enum
{
    VDO_CB_FUNC_SRC_CHG_IND,                ///< Source Change Notify
    VDO_CB_FUNC_DISP_SUPPORT_IND,           ///< Scaler display mode not support notify
    VDO_CB_FUNC_PTS_IND,                    ///< PTS Reach Notify
    VDO_CB_FUNC_AFD_IND,                    ///< AFD/Aspect Ratio Change Notify
    VDO_CB_FUNC_UNMUTE_IND,                 ///< UnMute Status Change Notify
    VDO_CB_FUNC_LIPSYNC_IND,                ///< Lip Sync Notify    
    VDO_CB_FUNC_MM_COND_IND,                ///< Vdp Condition Notify for MM
    VDO_CB_FUNC_MM_STEP_FIN_IND,            ///< Vdp Step Forward finish for MM
    VDO_CB_FUNC_MM_SEEK_FIN_IND,            ///< Vdp Seek finish for MM
    VDO_CB_FUNC_REPEAT_DROP_IND,            ///< Vdp repeat or drop    
    VDO_CB_FUNC_LIPSYNC_OK_TO_NG_IND,       ///< Vdp Lip Sync OK to NG notify
    VDO_CB_FUNC_LIPSYNC_NG_TO_OK_IND,       ///< Vdp Lip Sync NG to OK notify   
    VDO_CB_FUNC_SRC_CHG_IND_2,              ///< Source Change Notify
    VDO_CB_FUNC_AFD_IND_2,                  ///< AFD/Aspect Ratio Change Notify
    VDO_CB_FUNC_PLAY_DONE_IND,              ///< Vdp Play Done Notify
    VDO_CB_FUNC_OUT_VSYNC_IND,              ///< Output v-sync. Notify
    VDO_CB_FUNC_VSS_FIN_IND,                ///< VSS finish notify DEBUG
    VDO_CB_FUNC_TDNAVI_IND,                 ///< TDNavi New content detected notify
    VDO_CB_FUNC_SRC_CHG_MW_IND,             ///< Source Change Notify for MW
    VDO_CB_FUNC_SRC_RANGE_CHG_IND,          ///< Source Range Change Notify
    VDO_CB_FUNC_OUT_RANGE_CHG_IND,          ///< Output Range Change Notify
    VDO_CB_FUNC_RES_CHG_ING,                ///< Resolution Chagne Notify
    VDO_CB_FUNC_BIT_TATE_CHG_ING,
    VDO_CB_FUNC_VSS_420_IND,                /// < VSS in venc path  finish notify
    VDO_CB_FUNC_NS
}MTVDO_CB_FUNC_ENUM_T;

/**3D format
*/
typedef enum
{
    MTVDO_3D_MODE_OFF  = 0, ///< Force 3D off
    MTVDO_3D_MODE_AUTO = 1, ///< Auto mode
    MTVDO_3D_MODE_TTD  = 2, ///< 2D -> 3D Conversion
    MTVDO_3D_MODE_FS   = 3, ///< Frame Seq
    MTVDO_3D_MODE_SBS  = 4, ///< Side by Side    
    MTVDO_3D_MODE_TB   = 5, ///< Top Bottom    
    MTVDO_3D_MODE_RD   = 6, ///< Reald
    MTVDO_3D_MODE_SS   = 7, ///< Sensio    
    MTVDO_3D_MODE_LI   = 8, ///< Line Interleave
    MTVDO_3D_MODE_DA   = 9, ///< Dot Alternative    
    MTVDO_3D_MODE_CB   =10, ///< Checker Board
    MTVDO_3D_MODE_END
} MTVDO_3D_PACKING;

/** RGB gain/offset factors
*/
typedef struct 
{
    UINT16 u2RGain;     ///< R gain
    UINT16 u2GGain;     ///< G gain
    UINT16 u2BGain;     ///< B gain
    UINT16 u2ROffset;   ///< R offset
    UINT16 u2GOffset;   ///< G offset
    UINT16 u2BOffset;   ///< B offset
} MTVDO_PQ_RGB_GAIN_OFST_T;

/** RGB gain factors
*/
typedef struct 
{
    UINT16 u2RGain;      ///< R gain
    UINT16 u2GGain;      ///< G gain
    UINT16 u2BGain;      ///< B gain
} MTVDO_PQ_RGB_GAIN_T;

/** RGB offset factors
*/
typedef struct
{
    UINT16 u2ROffset;   ///< R offset
    UINT16 u2GOffset;   ///< G offset
    UINT16 u2BOffset;   ///< B offset
} MTVDO_PQ_RGB_OFST_T;

/** RGB test pattern factors
*/
typedef struct 
{
    UINT8 u1Enable;     ///< Enable RGB pattern
    UINT16 u2R;         ///< R level
    UINT16 u2G;         ///< G level
    UINT16 u2B;         ///< B levle
} MTVDO_PQ_RGB_PATTERN_T;

/** YCbCr test pattern factors
*/
typedef struct 
{
    UINT8 u1Enable;     ///< Enable YCbCr pattern
    UINT16 u2Y;         ///< Y level
    UINT16 u2Cb;        ///< Cb level
    UINT16 u2Cr;        ///< Cr level
} MTVDO_PQ_SCE_PATTERN_T;

/** Film mode control by module
*/
enum
{ 
    ENUM_DI_FILM = 0,                   ///< DI film 
    ENUM_MJC_FILM = 1,                  ///< MJC film
};

/** Film mode type
*/
enum
{ 
    ENUM_22_FILM = 0,                   ///< 22 film
    ENUM_32_FILM = 1,                   ///< 32 film
    ENUM_UC_FILM = 2                    ///< Universal cadence
};

/** Color space
*/
enum
{ 
    ENUM_COLORSPACE_FORCE_RGB = 0,      ///< Force RGB
    ENUM_COLORSPACE_FORCE_YCBCR = 1,    ///< Force YCbCr
    ENUM_COLORSPACE_AUTO = 2,           ///< Auto mode
};

/** Flip/Mirror control
*/
enum
{ 
    ENUM_FLIP_TYPE = 0,                 ///< Flip
    ENUM_MIRROR_TYPE = 1,               ///< Mirror
};

/** Film mode control factors
*/
typedef struct 
{
    UINT8 u1Module;                     ///< Module select: DI/MJC
    UINT8 u1FilmType;                   ///< Film mode type select
    UINT8 u1OnOff;                      ///< Enable control
} MTVDO_PQ_FILM_ONOFF_T;

/** Chroma-coring control factors
*/
typedef struct 
{
    UINT8 u1Enable;                     ///< Enable control
    UINT8 u1YBound;                     ///< Y level boundary
    UINT8 u1CbTbl[16];                  ///< Cb table
    UINT8 u1CrTbl[16];                  ///< Cr table
} MTVDO_PQ_CHROMA_CORING_T;

/** Luma information from video content
*/
typedef struct 
{
    UINT8 u1LumaMaxL;           ///< Maximum luma level of L-frame
    UINT8 u1LumaMaxR;           ///< Maximum luma level of R-frame
    UINT8 u1LumaMinL;           ///< Minimum luma level of L-frame
    UINT8 u1LumaMinR;           ///< Minimum luma level of R-frame
    UINT8 u1APLL;               ///< Average pixel level of L-frame
    UINT8 u1APLR;               ///< Average pixel level of R-frame
    UINT16 u2LumaHistL[32];     ///< Luma histogram of L-frame
    UINT16 u2LumaHistR[32];     ///< Luma histogram of R-frame
} MTVDO_PQ_LUMA_INFO_T;

/** Chroma information from video content
*/
typedef struct 
{
    UINT16 u2ChromaHistL[8];    ///< Saturation histogram of L-frame
    UINT16 u2ChromaHistR[8];    ///< Saturation histogram of R-frame
    UINT16 u2HueHistL[8];       ///< Hue histogram of L-frame
    UINT16 u2HueHistR[8];       ///< Hue histogram of R-frame
    UINT16 u2WindowL[3];        ///< Saturation-hue 2D window of L-frame
    UINT16 u2WindowR[3];        ///< Saturation-hue 2D window of R-frame
} MTVDO_PQ_CHROMA_INFO_T;

/** Pixel value capture factors
*/
typedef struct 
{
    UINT16 u2PosX;          ///< AP prepared position. API will not modify it.
    UINT16 u2PosY;          ///< AP prepared position. API will not modify it.
    UINT16 u2ValCh[3];      ///< API will return the pixel value
} MTVDO_PQ_CAPTURE_T;

typedef struct 
{
    UINT8 u1Module;         ///< AP prepared type: 0 (DI) or 1(MJC)
    UINT8 u1Result;         ///< return result: 0 (Video), 1 (3:2), 2 (2:2) 
} MTVDO_PQ_FILM_STATUS_T;

/** xvYCC control factors
*/
typedef struct 
{
    UINT8 u1OnOff;          ///< xvYCC enable control
    UINT8 u1GammaOnOff;     ///< Gamma/anti-gamma control
    UINT16 u2Matrix[9];     ///< 3x3 gain matrix control
} MTVDO_PQ_XVYCC_T;

/** PQ exp color
*/
typedef struct 
{
    UINT8 u1Color;          ///< M, R, Y, G, C, B
    UINT8 u1Module;         ///< Luma, Sat, Hue
    UINT8 u1Value;          ///< 0 ~ 0xFF
} MTVDO_PQ_EXP_COLOR_T;

/** MJC fallback curve
*/
typedef struct
{
    UINT8 arMJCQMap[2][16];     ///< MJC Quality mapping
    UINT16 arMJCQTbl[7][16];    ///< arMJCQTbl[5] is reserved
} MTVDO_PQ_MJC_FBCK_CURVE_T;

/** Color engine control factors
*/
typedef struct
{
    UINT8 u1Index;          ///< Partial update index: 0:luma, 1:saturation, 2:hue, 3:LCMP
    UINT8 u1SCETbl[336];    ///< Partical update table
} MTVDO_PQ_COLOR_CURVE_T;

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
#define MTVDO_MAX_REGION    10000   ///< Maximum value of source/output region

/**Video plane region (source/output).
*/
typedef struct
{
    UINT32 u4X;        	///< start position in x direction (u4X/1000 = start pixel/total pixel)
    UINT32 u4Y;        	///< start position in y direction (u4Y/1000 = start pixel/total pixel)
    UINT32 u4Width;  	///< width in percentage (u4Width/1000 = region width/total width)
    UINT32 u4Height; 	///< height in percentage (u4Width/1000 = region height/total width)
}MTVDO_REGION_T;

/**Video plane overscan region.
*/
typedef struct
{
    UINT32 u4Top;      	///< overscan percentage on top side (u4Top%)
    UINT32 u4Bottom;	///< overscan percentage on top side (u4Bottom%)
    UINT32 u4Left;     	///< overscan percentage on top side (u4Left%)
    UINT32 u4Right;   	///< overscan percentage on top side (u4Right%)
}MTVDO_OVERSCAN_REGION_T;

/** Brief of VDP_NONLINEAR_PRM_T
 *  Video plane nonlinear scaler factors.
 */
typedef struct
{
    UINT32 u4Start;             ///< Start point of non-linear area
    UINT32 u4End;               ///< End point of non-linear area
    UINT32 u4Slope;             ///< Non-linear slope
    UINT32 u4MiddlePoint;       ///< Middle of non-linear area
    UINT32 u4SrcMiddieRatio;    ///< Start point of non-linear area
    UINT32 u4OutMiddleRatio;    ///< End point of non-linear area
} MTVDO_NONLINEAR_PRM_T;




/** Brief of MTVDO_NONLINEAR_MODE_ENUM_T
 *  Video plane nonlinear scaler factors.
 */
typedef enum
{
    MTVDO_NONLINEAR_OFF,        ///< Turn off non-linear
    MTVDO_NONLINEAR_AUTO,       ///< Non-linear auto mode
    MTVDO_NONLINEAR_AUTO_1,     ///< Non-linear auto mode 2
    MTVDO_NONLINEAR_MANUAL,     ///< Manual non-linear mode
    MTVDO_NONLINEAR_ON,         ///< Turn on non-linear mode
    MTVDO_NEW_NONLINEAR_ON,     ///< Turn on new non-linear mode
    MTVDO_NEW_NONLINEAR         ///< Setup new non-linear parameters and turn on
} MTVDO_NONLINEAR_MODE_ENUM_T;

/**  Scalar dram data format
*/
typedef struct
{
	UINT32 u4VR;                ///< Scaler V or R data
	UINT32 u4UB;                ///< Scaler U or B data
	UINT32 u4YG;                ///< Scaler Y or G data
}MTVDO_SCLAR_BUFFER_DATA;

/*
*  for LX dump dram
*/
typedef struct
{
	UINT16 u2UB;                ///< U or B data
	UINT16 u2YG;                ///< Y or G data
	UINT16 u2VR;                ///< V or R data
}MTVDO_LGDDI_BUFFER_DATA;

/**Video callback structure
*/
typedef struct
{
    UINT32 u4Arg1;              ///< Argument 1 of callback function
    UINT32 u4Arg2;              ///< Argument 2 of callback function
    UINT32 u4Arg3;              ///< Argument 3 of callback function
    UINT32 u4Arg4;              ///< Argument 4 of callback function
    UINT32 u4Arg5;              ///< Argument 5 of callback function
    UINT32 u4Arg6;              ///< Argument 6 of callback function
    UINT32 u4Arg7;              ///< Argument 7 of callback function
}MTVDO_CB_T;

/**Monitor out input source
*/

typedef enum {
    MTVDO_MON_OUT_MIXER         =0,
    MTVDO_MON_OUT_MAIN_FSC_OUT  =1,
    MTVDO_MON_OUT_SUB_FSC_OUT   =2,
    MTVDO_MON_OUT_MAIN_MIB_OUT  =3,
    MTVDO_MON_OUT_SUB_MIB_OUT   =4,
    MTVDO_MON_OUT_MAIN_PREDOWN  =5,
    MTVDO_MON_OUT_SUB_PREDOWN   =6,   
    MTVDO_MON_OUT_PANEL         =7,
    MTVDO_FSC_SUB_TO_TVE        =8,
}MTVDO_MON_OUT_IN_SELECT;

/**Source change notify function type
*/
typedef void (*MTVDO_SRC_CHG_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    UINT32 u4SrcWidth, 
    UINT32 u4SrcHeight, 
    UINT32 u4OutWidth, 
    UINT32 u4OutHeight,
    UINT32 u4FrameRate,
    UINT32 u4Interlace
);

/**Resolution reach notify function type
*/
typedef void (*MTVDO_RES_CHG_NOTIFY)(
    MTVDO_PATH_T eVdpId,
    UINT32 u4Arg1,
    UINT32 u4Arg2
	);

typedef void (*MTVDO_BIT_RATE_CHG_NOTIFY)(
    MTVDO_PATH_T eVdpId,
    UINT32 u4Arg1,
    UINT32 u4Arg2
    );
/**PTS reach notify function type
*/
typedef void (*MTVDO_PTS_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    UINT32 u4Pts, 
    UINT32 u4Arg
);

/**AFD/Aspect Ratio change notify function type
*/
typedef void (*MTVDO_AFD_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    UINT32 u4Afd, 
    UINT32 u4AspectRatio
);

/**PLAYDONE change notify function type
*/
typedef void (*MTVDO_PLAYDONE_NOTIFY)
(
    MTVDO_PATH_T eVdpId,
    UINT32 u4Arg1,
    UINT32 u4Arg2 
);

/**UnMute status change notify function type
*/
typedef void (*MTVDO_UNMUTE_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    BOOL fgEnable
);


/**Lip sync notify function type
*/
typedef void (*MTVDO_LIPSYNC_NOTIFY)
(
    void
);

/**output V sync notify function type
*/
typedef void (*MTVDO_OUT_VSYNC_NOTIFY)
(
    void
);

/**Function type of VSS notification
*/
typedef void (*MTVDO_VSS_NOTIFY)
(
    void
);

/**TDNAVI notify function type
*/
typedef void (*MTVDO_TDNAVI_NOTIFY)
(
    MTVDO_PATH_T eVdpId,
    MTVDO_TAG3D_TYPE_T e3DTag    
);

/**Video plane argument.
*/
typedef enum
{
    MTVDO_ARG_BRIGHTNESS = 0,           ///< Brightness
    MTVDO_ARG_CONTRAST,                 ///< Contrast
    MTVDO_ARG_HUE,                      ///< Hue
    MTVDO_ARG_SATURATION,               ///< Saturation
    MTVDO_ARG_CTI,                      ///< CTI
    MTVDO_ARG_SHARPNESS,	            ///< Sharpness
    MTVDO_ARG_SHARPNESS_H,              ///< Sharpness: horizontal direction
    MTVDO_ARG_SHARPNESS_V,              ///< Sharpness: vertical direction
    MTVDO_ARG_LTI,                      ///< LTI
    MTVDO_ARG_R_GAIN,                   ///< R gain
    MTVDO_ARG_G_GAIN,                   ///< G gain
    MTVDO_ARG_B_GAIN,                   ///< B gain
    MTVDO_ARG_R_OFFSET,                 ///< R offset
    MTVDO_ARG_G_OFFSET,                 ///< G offset
    MTVDO_ARG_B_OFFSET,                 ///< B offset
    MTVDO_ARG_NR,                       ///< Noise reduction
    MTVDO_ARG_GAMMA,                    ///< Gamma
    MTVDO_ARG_WHITE_PEAK_LMT,           ///< AGC white peak limit
    MTVDO_ARG_SCE,                      ///< SCE color engine
    MTVDO_ARG_SKIN_COLOR,               ///< Skin color level
    MTVDO_ARG_ADAPTIVE_LUMA,            ///< Adaptive luma
    MTVDO_ARG_BACK_LIGHT_LVL,           ///< Backlight level
    MTVDO_ARG_ADAPTIVE_BACK_LIGHT,      ///< Adaptive backlight
    MTVDO_ARG_3D_NR,                    ///< 3D noise reduction
    MTVDO_ARG_DEMO,                     ///< PQ demo mode
    MTVDO_ARG_DI_FILM_MODE,             ///< De-interlace film mode
    MTVDO_ARG_DI_MA,                    ///< De-interlace mation adaptive
    MTVDO_ARG_DI_EDGE_PRESERVE,         ///< De-interlace edge preserve
    MTVDO_ARG_MJC_MODE,                 ///< MJC mode control
    MTVDO_ARG_MJC_EFFECT,               ///< MJC effect control
    MTVDO_ARG_MJC_DEMO,                 ///< MJC demo mode
    MTVDO_ARG_XVYCC,                    ///< XVYCC
    MTVDO_ARG_WCG,                      ///< Wide color gamut
    MTVDO_ARG_GAME_MODE,                ///< Game mode
    MTVDO_ARG_BLUE_STRETCH,             ///< Blue stretch
    MTVDO_ARG_MPEG_NR,                  ///< MPEG moise reduction
    MTVDO_ARG_BLACK_STRETCH,            ///< Adaptive luma black stretch
    MTVDO_ARG_WHITE_STRETCH,            ///< Adaptive luma white stretch
    MTVDO_ARG_SHARPNESS_ON_OFF,         ///< Sharpness on/off control
    MTVDO_ARG_SUPERRESOLUTION_ON_OFF,	///< Super-resolution
    MTVDO_ARG_OPC_CURVE,                ///< OPC curve
    MTVDO_ARG_LCDIM,                    ///< Local dimming
    MTVDO_ARG_TDTV_PACKING,             ///< 3D pacing format control
    MTVDO_ARG_TDTV_INVERSE,             ///< 3D L/R inverse control
    MTVDO_ARG_TDTV_DEPTH,               ///< 3D depth
    MTVDO_ARG_TDTV_3D_TO_2D,            ///< 3D to 2D
    MTVDO_ARG_TDTV_FPR,                 ///< 3D full PR function
    MTVDO_ARG_TDTV_PROTRUDE,            ///< 3D protrude
    MTVDO_ARG_TDTV_DISTANCE,            ///< 3D image safety distance
    MTVDO_ARG_TDTV_OSD_DEPTH,           ///< 3D OSD depth
    MTVDO_ARG_NS
} MTVDO_ARG_TYPE_T;

/** Unmute type
*/
typedef enum
{
	MTVDO_NO_SIGNAL_UNMUTE = 0,         ///< Disable AP mute when no-signal
	MTVDO_NO_SIGNAL2_UNMUTE,            ///< Disable AP mute when no-signal case 2
	MTVDO_ATV_CHG_CH_UNMUTE,            ///< Disable AP mute when channel change
	MTVDO_ATV_PVR_UNMUTE                ///< Disable AP mute when ATV PVR
} MTVDO_FORCE_UNMUTE_T;

/** Capability type
*/
typedef enum {
	MTVDO_FREEZABLE_CAP=0,	            ///< Freezable
	MTVDO_OVERSCAN_CAP,	                ///< Overscan support
	MTVDO_NONLINEAR_SCALING_CAP,	    ///< Non-linear scaling support
	MTVDO_DOTBYDOT_CAP,	                ///< Dot-by-dot support
	MTVDO_MJC3D_CAP,	                ///< MJC 3D support
	MTVDO_ASP_RATIO_CAP                 ///< Aspect ratio support
}MTVDO_CAPABILITY_T;

/** SRM mode
*/
typedef enum {
	MTVDO_MM_MODE_OFF=0,	            ///< MM mode
	MTVDO_MM_VIDEO_MODE,	            ///< Normal video mode
	MTVDO_MM_THUMBNAIL_MODE,	        ///< Thumbnail mode
}MTVDO_SRM_MODE_T;

/** Mute condition
*/
typedef enum {
	MTVDO_DISP_FMT_MUTE=0,	            ///< Display format mute
	MTVDO_AP_MUTE,	                    ///< AP mute
}MTVDO_MUTE_T;

typedef enum
{
	MTVDO_MUTE_MODULE_INFO_TYPE = 0,         ///<get mute module info for one module
	MTVDO_AUTO_MUTE_TYPE=1
} MTVDO_MUTE_FUNC_T;

typedef struct _strucMTALVideoMuteInfo
{
	UINT8 eModuleId;   // Mute module ID
	UINT8	u1Path;		        // Video path
    UINT32  u4InvalidMask;           // Valid module
	UINT32	u4Delay;	        // Unmute delay counter
} MTVDO_MUTE_MODULE_INFO;

/** 3D LR order control
*/
typedef enum {
    MTVDO_LR_NORMAL  = 0,               ///< Follow original LR order
    MTVDO_LR_INVERSE = 1                ///< Inverse LR order
}MTVDO_LR;

/** 3D-to-2D control type
*/
typedef enum {
    MTVDO_3D_2_2D_OFF = 0,              ///< Turn off 3D-to-2D
    MTVDO_3D_2_2D_L   = 1,              ///< Turn on 3D-to-2D L part
    MTVDO_3D_2_2D_R   = 2               ///< Turn on 3D-to-2D R part
}MTVDO_3D_2_2D;

/** 3D navigation parameters
*/
typedef enum
{
    MTVDO_NAVI_DTH,                     ///< 3D navigation parameter, DTH
    MTVDO_NAVI_TOO_FEW_THR,             ///< 3D navigation parameter, TOO FEW
    MTVDO_NAVI_AMBIGUO1_THR,            ///< 3D navigation parameter, ambiguous 1 threshold
    MTVDO_NAVI_AMBIGUO2_THR             ///< 3D navigation parameter, ambiguous 2 threshold
} MTVDO_NAVI_PARAM_T;

/** FBM mode
*/
typedef enum
{
	MTVDO_FBM_MMMODE =0,                ///< FBM MM mode
	MTVDO_FBM_TVMODE,                   ///< FBM TV mode
	MTVDO_FBM_NETMODE                   ///< FBM net mode
} MTVDO_FBM_MODE_T;


/** UI range control factors.
*/
typedef struct 
{
    INT32 i4Min;                        ///< UI min value mapping to HW value
    INT32 i4Max;                        ///< UI max value mapping to HW value
    INT32 i4Dft;                        ///< UI default value mapping to HW value
} MTVDO_UI_RANGE_T;

/**Video scaling argument
*/
typedef struct 
{
    UINT8 bPath;            ///< Video plane ID
    UINT8 bType;            ///< Type
    UINT8 bMode;            ///< Mode
} MTVDO_SCALING_ARG_T;

/**Video Timing Info.
*/
typedef struct
{
    UINT32 u4HTotal;        ///< HTotal
    UINT32 u4VTotal;        ///< VTotal
    UINT32 u4FrameRate;     ///< Frame Rate
    UINT32 u4HStart;        ///< H start position
    UINT32 u4VStart;        ///< V start position
    UINT32 u4ActiveWidth;   ///< Active Width
    UINT32 u4ActiveHeight;  ///< Active Height
    UINT32 u4Interlace;     ///< Is interlace or progressive
    UINT32 u4Phase;         ///< sampling phase
}MTVDO_TIMING_INFO_T;

/**Video Aspect Ratio Info.
*/
typedef struct
{
    UINT32 u4ParWidth;      ///< Pixel Aspect Ratio - Width
    UINT32 u4ParHeight;     ///< Pixel Aspect Ratio - Height
    UINT32 u4DarWidth;      ///< Display Aspect Ratio - Width
    UINT32 u4DarHeight;     ///< Display Aspect Ratio - Height
    UINT32 u4IdcInfo;       ///< Aspect ratio IDC
    UINT32 u4Afd;           ///< Aspect ratio AFD
}MTVDO_ASPECTRATIO_T;

/**
*  TV tuner mode
*/
enum
{
    MTVDO_CHANGE_CHANNEL_MODE,      ///< Channel change
    MTVDO_SCAN_MODE,                ///< Scanning mode
    MTVDO_FINE_TUNE_MODE            ///< Finetune mode
};

/**
*  data format of frame or field 
*/
typedef struct
{
    BOOL fgIs10bit;                 ///< 10 bit or 8 bit
    BOOL fgIs422;                   ///< 422 mode or 420 mode
    BOOL fgIsInterlace;             ///< Interlacing or progressive
    BOOL fgIsTopField;              ///< Top or bottom field
    BOOL fgIsYUV;                   ///< YUV format or RGB format
    BOOL fgIsPredown;               ///< Pre-down is enabled or not
}MTVDO_FRAME_FORMAT_DATA;

/**
*  Video buffer
*/
typedef struct
{
    UINT32 u4Addr;                  ///< Address of video buffer
    UINT32 u4Size;                  ///< Size of video buffer
}MTVDO_VIDEO_BUFFER;

/**
*  for LG dump dram
*/
typedef struct
{
	UINT16 u2UB;                    ///< U or B data
	UINT16 u2YG;                    ///< Y or G data
	UINT16 u2VR;                    ///< V or R data
}MTVDO_DDI_PIXEL_DATA;

/**
*  Pscan data mode
*/
typedef enum
{
    MTVDO_PSCAN_DEFAULT,            ///< PSCAN default mode
    MTVDO_PSCAN_INPUT_SYNC_YC3D,    ///< Input sync mode
    MTVDO_PSCAN_OUTPUT_SYNC_YC3D,   ///< Ouptput sync mode
    MTVDO_PSCAN_INPUT_SYNC_BOB,     ///< Input sync mode with BOB
    MTVDO_PSCAN_OUTPUT_SYNC_BOB,    ///< Output sync mode with BOB
    MTVDO_PSCAN_UNKNOWN,            ///< Unknown
}MTVDO_PSCAN_MODE_T;

/**
*  Display Off Application
*/
typedef enum
{
    MTVDO_DISPLAY_OFF_SCARTOUT,
    MTVDO_DISPLAY_OFF_VENC,
    MTVDO_DISPLAY_OFF_VSS,
    MTVDO_DISPLAY_OFF_MAX,
}MTVDO_DISPLAY_OFF_APP;

/**
*  Scaler INT inoformation
*/
typedef struct
{
    UINT8 dram_from;            ///< Information of DRAM from 
    UINT8 u1ColorMode;          ///< Color mode
    UINT8 u1BitRes;             ///< Bit resolution

    //UINT8 HBlockNum;
    //UINT8 BlockSize;
    UINT8 BlockMode;            ///< Block mode
    UINT8 FrameNum;             ///< Number of frame buffer
    UINT32 YMsbAddr;            ///< MSB of Y address
    UINT32 YLsbAddr;            ///< LSB of Y address
    UINT32 UMsbAddr;            ///< MSB of U address
    UINT32 ULsbAddr;            ///< LSB of U address
    UINT32 VMsbAddr;            ///< MSB of V address
    UINT32 VLsbAddr;            ///< LSB of V address
    UINT32 PictureWidth;        ///< Width of picture
    UINT32 PictureHeight;       ///< Height of picture
    UINT32 DramPitch;           ///< DRAM pitch

    BOOL   bDramSnakeMapping;   ///< Snake mapping

}MTVDO_SCALER_INT_T;

/**
*  DI display information.
*/
typedef struct
{
    UINT8  dram_from;           ///< Information of DRAM from
    UINT8  u1BlockMode;         ///< Block mode
    UINT8  u1OutMode;           ///< Output mode
    UINT8  u1BitRes;            ///< Bit resolution
    UINT8  u1ColorMode;         ///< Color mode
    UINT8  u1AFBottom;          ///< Bottom of AF
    UINT8  u1AFYUVIndex;        ///< YUV index of AF
    UINT16 u2Width;             ///< Width of display information
    UINT16 u2Height;            ///< Height of display information
    UINT16 u2DramPitch;         ///< DRAM pitch
	
    UINT8  u1YFrameNum;         ///< 1W1R:Y=2  1W4R:Y=5 FLIP_MIRROR_1W1R:Y=3 FLIP_MIRROR_CBOB_1W4R:Y=6
    UINT8  u1CFrameNUm;         ///< 1W1R:C=2  1W4R:C=5 FLIP_MIRROR_1W1R:C=3 FLIP_MIRROR_CBOB_1W4R:C=5
    UINT8  u1DramFlipMirror;    ///< 1 : means pscan write dram flip/mirror  ; 0 : means scaler read flip mirror
    UINT8  u1CfgFlipMirror;     ///< 0: means normal ; 1 : means mirror ; 2 : means flip ; 3 : means flip & mirror 
	
    UINT32 u4YStartMSBAddr;     ///< MSB of Y starting address
    UINT32 u4YStartLSBAddr;     ///< LSB of Y starting address
    UINT32 u4UStartMSBAddr;     ///< MSB of U starting address
    UINT32 u4UStartLSBAddr;     ///< LSB of U starting address
    UINT32 u4VStartMSBAddr;     ///< MSB of V starting address
    UINT32 u4VStartLSBAddr;     ///< LSB of V starting address

}MTVDO_DI_DISP_INFO_T;

/**
*  B2R display information.
*/
typedef struct
{
    UINT8  dram_from;           ///< DRAM from

    UINT8  u1OutMode;           ///< 0 Progress mode;1 interlace mode
    UINT8  u1BlockMode;         ///< 0:64x32 ; 1:16x32 ; others: raster mode

    UINT32 u4Pitch;             ///< Line Size of buffer
    UINT32 u4YStart;            ///< Y address
    UINT32 u4CStart;            ///< C address
    UINT32 u4With;              ///< active  width
    UINT32 u4Height;            ///< active  height

} MTVDO_B2R_DISP_INFO_T;

/**
*  Video capture information.
*/
typedef union
{
    MTVDO_SCALER_INT_T    scaler_inf;   ///< Scaler information
    MTVDO_B2R_DISP_INFO_T B2R_inf;      ///< B2R information
    MTVDO_DI_DISP_INFO_T  DI_inf;       ///< De-interlacer information
} MTVDO_DRAM_INFO_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
/**Initialize VDO module.
*@param void
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Init(void);

/**Stop VDO module.
*@param void
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Stop(void); 

/**Reset VDO module.
*@param eVdpId                     Video plane id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Reset(MTVDO_PATH_T eVdpId);

/**VDO set video plane enable.
*@param eVdpId                     Video plane id.
*@param fgEnable                   Enable/Disable.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetEnable(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO query video plane enable/disable status.
*@param eVdpId                     Video plane id.
*@param pucEnable                  0:disable, 1:enable.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetEnable(MTVDO_PATH_T eVdpId, UCHAR *pucEnable);

/**VDO set video plane mode.
*@param eVdpId                     Video plane id.
*@param ucMode                     VDO_MODE_NORMAL or VDO_MODE_BG.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMode(MTVDO_PATH_T eVdpId, UCHAR ucMode);

/**VDO query video plane mode.
*@param eVdpId                     Video plane id.
*@param pucMode                    VDO_MODE_NORMAL or VDO_MODE_BG.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMode(MTVDO_PATH_T eVdpId, UCHAR *pucMode);

/**VDO set video plane with freeze feature.
*@param eVdpId                     Video plane id.
*@param fgEnable                   Enable/disable freeze function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFreeze(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO query video plane with freeze feature.
*@param eVdpId                     Video plane id.
*@param pucFreeze                  0:disable, 1:freeze feature enable.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTVDO_GetFreeze(MTVDO_PATH_T eVdpId, UCHAR *pucFreeze);

/**VDO set nonlinear parameters.
*@param eVdpId                     Video plane id.
*@param eMode                      MTVDO_NONLINEAR_OFF/ MTVDO_NONLINEAR_AUTO/MTVDO_NONLINEAR_MANUAL
*@param ePrm			    OFF: NULL, AUTO:slope and end factor, MANUAL: begin, end, middle, slope should be specified.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetNonLinearMode(MTVDO_PATH_T eVdpId,MTVDO_NONLINEAR_MODE_ENUM_T eMode, MTVDO_NONLINEAR_PRM_T *ePrm);

/**VDO set video plane dot by dot.
*@param eVdpId                     Video plane id.
*@param fgEnable                   Enable/disable dot by dot function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetDotByDot(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO set video quality item.
*@param eVdpId                     Video plane id.
*@param ucArg                      The color item.
*@param i2Value                    The value of the color item.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetArg(MTVDO_PATH_T eVdpId, MTVDO_ARG_TYPE_T eArgType, INT16 i2Value);

/**VDO query video quality item setting.
*@param eVdpId                     Video plane id.
*@param ucArg                      The color item.
*@param pi2Value                   The value of the color item.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetArg(MTVDO_PATH_T eVdpId, MTVDO_ARG_TYPE_T eArgType, INT16 *pi2Value);

/**VDO set overscan region.
*@param eVdpId                     Video plane id.
*@param rRegion                    Overscan percentage setting.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetOverScan(MTVDO_PATH_T eVdpId, MTVDO_OVERSCAN_REGION_T *prRegion);

/**VDO get overscan region.
*@param eVdpId                     Video plane id.
*@param prRegion                   Overscan percentage setting.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetOverScan(MTVDO_PATH_T eVdpId, MTVDO_OVERSCAN_REGION_T *prRegion);

/**VDO set source region.
*@param eVdpId                     Video plane id.
*@param rSrcRegion                 Source region description.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetSrcRegion(MTVDO_PATH_T eVdpId, MTVDO_REGION_T* prSrcRegion);

/**VDO query source region.
*@param eVdpId                     Video plane id.
*@param prSrcRegion                Source region description.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetSrcRegion(MTVDO_PATH_T eVdpId, MTVDO_REGION_T *prSrcRegion);

/**VDO set output region.
*@param eVdpId                     Video plane id.
*@param rOutRegion                 Output region description.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetOutRegion(MTVDO_PATH_T eVdpId, MTVDO_REGION_T* prOutRegion);

/**VDO query output region.
*@param eVdpId                     Video plane id.
*@param rOutRegion                 Output region description.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetOutRegion(MTVDO_PATH_T eVdpId, MTVDO_REGION_T *prOutRegion);

/**VDO set background color.
*@param eVdpId                     Video plane id.
*@param u4BgColor                  The color in RGB color mode, 1 byte per color component.(e.g. Red: 0xFF0000).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetBg(MTVDO_PATH_T eVdpId, UINT32 u4BgColor);

/**VDO query background color.
*@param eVdpId                     Video plane id.
*@param u4BgColor                  The color in RGB color mode, 1 byte per color component.(e.g. Red: 0xFF0000).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetBg(MTVDO_PATH_T eVdpId, UINT32 *pu4BgColor);

/**VDO call back function register.
*@param eFuncType                  The call back function type.
*@param u4FuncPtr                  The call back function pointer.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_RegCbFunc(MTVDO_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1, UINT32 u4Arg2);

/**VDO set game mode on/off.
*@param eVdpId                     Video plane id.
*@param fgEnable                   Enable/disable game mode.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetGameMode(UINT32 u4VdpId, BOOL fgEnable);

/**VDO set 3D game mode on/off.
*@param eVdpId                     Video plane id.
*@param fgOnOff                    Enable/disable 3D game mode.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Set3DGameMode(UINT32 u4VdpId, BOOL fgEnable);

/**VDO get DTV playback unmute status.
*@param pfgEnable                  TRUE: Unmute, FALSE: Mute.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetUnMuteStatus (MTVDO_PATH_T eVdpId, BOOL *pfgEnable);

/**VDO get mute status of video path.
*@param eVdpId                     Video plane id.
*@param pu4OnOff                   Pointer of mute status.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetVideoMuteStatus(MTVDO_PATH_T eVdpId, UINT32 * pu4OnOff);

/**VDO MTVDO_Scalar_EnableGetBuffer
* calling sequence: Enable GetBuffer -> GetBufferAvg -> Disable GetBuffer
*@param fgEnable                    TRUE/FALSE.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Scalar_EnableGetBuffer(BOOL fgEnable);

/**VDO get mute status of video path.
*@param eVdpId                     Video plane id.
*@param pu4OnOff                   Pointer of mute status.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetVideoMuteStatus(MTVDO_PATH_T eVdpId, UINT32 * pu4OnOff);

/**VDO scalar : Get the average data of scalar frame buffer.
* calling sequence: GetBufferOn -> GetBufferAvg -> GetBufferOff
*@param prRegion            the region of frame Buffer.
*@param prData                     the average data of prRegion in frame buffer.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_Scalar_GetBufferAvg(MTVDO_REGION_T *prRegion, MTVDO_SCLAR_BUFFER_DATA *prData);

/**VDO get timing information.
*@param eVdpId                     Video plane id.
*@param prInfo                    Timing information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTimingInfo(MTVDO_PATH_T eVdpId, MTVDO_TIMING_INFO_T *prInfo);

/**VDO get aspect ratio information.
*@param eVdpId                     Video plane id.
*@param prAspectRatio              Aspect ratio information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetAspectRatio(MTVDO_PATH_T eVdpId, MTVDO_ASPECTRATIO_T *prAspectRatio);

/**VDO Enable/Disable Factory mode (CVBS output with OSD) 
*@param fgEnable                     Factory mode Enable/Disable.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFactoryMode(BOOL fgEnable);

/**VDO Set Auto Mute On or Off
*@param MTVDO_GetMuteModuleInfo : 
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMuteModuleInfo(MTVDO_MUTE_MODULE_INFO* pModule, MTVDO_MUTE_FUNC_T eMuteFuncType, BOOL fgEnable);

/**VDO Set Mute On or Off
*@param eVdpId : 0: MAIN; 1: SUB
*@param eMuteType : 0: DISP_FMT_MUTE;1: AP MUTE 
*@param u4UnMuteDelay : MUTE  TIME
*@param bReplaceByLongerDelay : ReplaceByLongerDelay
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetVideoMute(MTVDO_PATH_T eVdpId, MTVDO_MUTE_T eMuteType, UINT32 u4UnMuteDelay, BOOL bReplaceByLongerDelay);

/**VDO Set Auto Mute On or Off
*@param fgAutoMuteOff : TRUE: Auto Mute On; FALSE: Auto Mute Off
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetAutoMuteOnOff(BOOL fgAutoMuteOff);

/**VDO & OSD Set Auto Mute On or Off
*@param fgAutoBlkOff : TRUE: Auto Mute On; FALSE: Auto Mute Off
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetAutoBlkOnOff(BOOL fgAutoBlkOff);

/**VDO Set Scaler Pixel Based control On or Off
*@param fgEnable : TRUE: Pixel Based Control On; FALSE: Pixel Based Control Off
*@retval MTR_OK 				   Success.
*@retval MTR_NOT_OK 			   Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetScalerPixelBased(BOOL fgEnable); // drmyung 081226

/**VDO Set xvYcc Inner Pattern Gen
*@param bOnOff : on / off xvycc pattern gen
*@param wPatGenR : xvycc pattern gen r value
*@param wPatGenG : xvycc pattern gen g value
*@param wPatGenB : xvycc pattern gen b value
*@retval MTR_OK 				   Success.
*@retval MTR_NOT_OK 			   Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetxvYccInnerPatternGen(UINT8 bOnOff, UINT16 wPatGenR, UINT16 wPatGenG, UINT16 wPatGenB);

/**VDO Set scan mode
*@param pscan                   Enable/Disable scan mode.
*@retval MTR_OK                 Success.
*@retval MTR_NOT_OK             Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetScanMode(UINT32 *pscan);

/**VDO Get scan mode
*@param pu4ScanMode             Value of scan mode.
*@retval MTR_OK                 Success.
*@retval MTR_NOT_OK             Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetScanMode(UINT32 *pu4ScanMode);

/**VDO Set pre-down scaling factor
*@param  eVdpId		   path
*@param  u4Factor	   pre-down scaling factor to set
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/    
EXTERN MT_RESULT_T MTVDO_SetDSFactor(MTVDO_PATH_T eVdpId, UINT32 u4Factor);

/**VDO Set PQ interface
*@param  eVdpId                 path
*@param  ePqType                PQ type to set
*@param  pvPqSetInfo            PQ data structure to set
*@param  u4Size                 size of the passing PQ data structure
*@retval MTR_OK                 Success.
*@retval MTR_NOT_OK             Set fail.
*@retval MTR_NOT_SUPPORTED      Not supported function
*@retval MTR_PARAMETER_ERROR    read-only type
*/
EXTERN MT_RESULT_T MTVDO_SetPQ(MTVDO_PATH_T eVdpId, MTVDO_PQ_TYPE_T ePqType, const void* pvPqSetInfo, UINT32 u4Size);

/**VDO Get PQ interface
*@param  eVdpId                 path
*@param  ePqType                PQ type to get
*@param  pvPqGetInfo            PQ data structure to get
*@param  u4Size                 size of the PQ data structure for retrieving
*@retval MTR_OK                 Success.
*@retval MTR_NOT_OK             Get fail.
*@retval MTR_NOT_SUPPORTED      Not supported function.
*@retval MTR_PARAMETER_ERROR    Not support for read.
*/
EXTERN MT_RESULT_T MTVDO_GetPQ(MTVDO_PATH_T eVdpId, MTVDO_PQ_TYPE_T ePqType, void* pvPqGetInfo, UINT32 u4Size);

/**VDO configure MJC motion compensation on/off
*@param fgOnOff                     Compensation on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCMotionCompensationOnOff(UINT8 fgOnOff);

/**VDO configure MJC demo bar color
*@param fgOnOff                     Demo bar on/off.
*@param r                           Red color.
*@param g                           Green color.
*@param b                           Blue color.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCDemoBar(UINT8 fgOnOff, UINT8 r, UINT8 g, UINT8 b);

/**VDO initialize MJC
*@param void                        Void.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCInitialize(void);

/**VDO reset MJC software
*@param void                        Void.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCResetSW(void);

/**VDO configure MJC video blocking
*@param fgOnOff                     Blocking on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCVideoBlock(BOOL fgOnOff);

/**VDO configure MJC effect level
*@param bLevel                      Effect level.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCEffectLevel(UINT8 bLevel);

/**VDO configure MJC judder level
*@param bLevel                      Judder level.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCJudderLevel(UINT8 bLevel);

/**VDO configure MJC blur level
*@param bLevel                      Blur level.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCBlurLevel(UINT8 bLevel);

/**VDO configure MJC motion compensation
*@param blurLevel                   Blur level.
*@param judderLevel                 Judder level.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCMotionCompensation(UINT8 blurLevel, UINT8 judderLevel, UINT8 fgRealCinema);

/**VDO get MJC firmware version
*@param pMajorVersion               Major version.
*@param pSubVersion                 Sub version.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMJCFirmwareVersion(UINT8 * pMajorVersion, UINT8 * pSubVersion);

/**VDO set MJC demo mode
*@param fgOnOff                     Demo enable/disable.
*@param bMode                       Demo mode.
*@param wCenter                     Center position.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCDemoMode(BOOL fgOnOff, UINT8 bMode, UINT16 wCenter);

/**VDO set MJC bypass window area
*@param bWindow                     Set bypass window index.
*@param rRegion                     Region information.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMJCBypassWindow(UINT8 bWindow, MTVDO_REGION_T rRegion);

/**VDO set output window
*@param eVdpId                      Video plane ID.
*@param prOutRegion                 Output region.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetOutputWindow(MTVDO_PATH_T eVdpId, MTVDO_REGION_T *prOutRegion);

/**VDO set SRM TV mode
*@param eMode                       TV mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SRM_SetTvMode(MTVDO_SRM_TV_MODE_T eMode);

/**VDO get panel width and height
*@param pWidth                      Width.
*@param pHeight                     Height.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetPlaneWH(UINT32 *pWidth,UINT32 *pHeight);

/**VDO set 3D packing
*@param eVdpId                      Video plane ID.
*@param i2Value                     Packing value.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVPacking(MTVDO_PATH_T eVdpId ,INT16 i2Value);

/**VDO get 3D packing
*@param eVdpId                      Video plane ID.
*@param pi2Value                    Packing.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVPacking(MTVDO_PATH_T eVdpId, INT16 *pi2Value);

/**VDO set 3D-to-2D status
*@param eVdpId                      Video plane ID.
*@param e3D22DMode                  Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTV3D22D(MTVDO_PATH_T eVdpId,MTVDO_3D_2_2D e3D22DMode);

/**VDO get 3D-to-2D status
*@param eVdpId                      Video plane ID.
*@param pi2Value                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTV3D22D(MTVDO_PATH_T eVdpId, INT16 *pi2Value);

/**VDO get 3D format
*@param eVdpId                      Video plane ID.
*@param pu4Value                    3D format.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVGetTag3D(MTVDO_PATH_T eVdpId,UINT32 *pu4Value);

/**VDO get 3D navigation result
*@param eVdpId                      Video plane ID.
*@param pu4Value                    Navigation result.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVGetNaviTag3D(MTVDO_PATH_T eVdpId, UINT32 *pu4Value);

/**VDO configure 3D navigation mode
*@param i2NaviMode                  Navigation mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVNaviMode(INT16 i2NaviMode);

/**VDO enable/disable depth control
*@param u1OnOff                     Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVDCOnOff(UINT8 u1OnOff);

/**VDO set 3D protrude
*@param eVdpId                      Video plane ID.
*@param i2Protrude                  3D protrude.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVProtrude(MTVDO_PATH_T eVdpId, INT16 i2Protrude);

/**VDO get 3D protrude
*@param eVdpId                      Video plane ID.
*@param pi2Value                    3D protrude.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVProtrude(MTVDO_PATH_T eVdpId, INT16 *pi2Value);

/**VDO set 3D distance
*@param eVdpId                      Video plane ID.
*@param i2Distance                  3D distance.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVDistance(MTVDO_PATH_T eVdpId, INT16 i2Distance);

/**VDO get 3D distance
*@param eVdpId                      Video plane ID.
*@param pi2Value                    3D distance.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVDistance(MTVDO_PATH_T eVdpId, INT16 *pi2Value);

/**VDO set 3D OSD depth
*@param eVdpId                      Video plane ID.
*@param i2OSDDepth                  Configured value.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVOSDDepth(MTVDO_PATH_T eVdpId, INT16 i2OSDDepth);

/**VDO get 3D OSD depth
*@param eVdpId                      Video plane ID.
*@param pi2Value                    Returned value.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVOSDDepth(MTVDO_PATH_T eVdpId, INT16 *pi2Value);

/**VDO set 3DTV panel
*@param type                        Type
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVPanel(UINT8 type);

/**VDO get status of side-by-side full type
*@param pu4IsConentFull             Is side-by-side full type or not.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_IsSBSContentFull(UINT32* pu4IsConentFull);

/**VDO force FRC mute on/off
*@param fgFRCMuteOff                On/Off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFRCMuteOnOff(BOOL fgFRCMuteOff);

/**VDO get frame rate
*@param pu4FrameRate                Frame rate.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetFrameRate(UINT32* pu4FrameRate);

/**VDO get 3D LR order
*@param eVdpId                      Video plane ID.
*@param pu4Value                    LR order.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetTDTVGet3DLROrder(MTVDO_PATH_T eVdpId, UINT32 *pu4Value);

/**VDO 3D mode display automatically
*@param fgOnOff                     Enable/Disabe.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTV3DAutoDisplay(BOOL fgOnOff);

/**VDO SRM force PSCAN display mode
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Enable/Disabe.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SRM_ForcePscanDispMode(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO SRM force DRAM mode
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Enable/Disabe.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SRM_ForceDramMode(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO get DI format information
*@param eVdpId                      Video plane ID.
*@param prData                      Frame format information.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_DI_GetFormatInfo(MTVDO_PATH_T eVdpId, MTVDO_FRAME_FORMAT_DATA *prData);

/**VDO freeze DI frame buffer
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Disable/Enable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFreezeDIFrameBuffer(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO get FBM mode
*@param u4Mode                      FBM mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetFBMMode(UINT32 *u4Mode);

/**VDO get DRAM pixels
*@param eVdpId                      Video plane ID.
*@param prRegion                    Region information.
*@param pu4DumpAddr                 Dumped address.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_DI_GetDramPixels(MTVDO_PATH_T eVdpId, MTVDO_REGION_T *prRegion, UINT32 **pu4DumpAddr);

/**VDO enable DI DRAM dump
*@param eVdpId                      Video plane ID.
*@param fgIsEnable                  Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_EnableDIDramDump(MTVDO_PATH_T eVdpId, BOOL fgIsEnable);

/**VDO DI write DRAM pixel
*@param eVdpId                      Video plane ID.
*@param prRegion                    Region area.
*@param prData                      Pointer of data.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_DI_WriteDramPixels(MTVDO_PATH_T eVdpId, MTVDO_REGION_T *prRegion, MTVDO_LGDDI_BUFFER_DATA *prData);

/**VDO set flip and mirror
*@param fgMirrorEn                  Mirror on/off.
*@param fgFlipEn                    Flip on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFlipMirror(BOOL fgMirrorEn, BOOL fgFlipEn);

/**VDO enable/disable OD
*@param u1OnOff                     Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_EnableOverDriver(UINT8 u1OnOff);

/**VDO enable/disable PCID
*@param u1OnOff                     Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_EnablePCID(UINT8 u1OnOff);

/**VDO enable/disable FB
*@param u1OnOff                     Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_EnableFB(UINT8 u1OnOff);

/**VDO inversse 3D L/R indicator
*@param eVdpId                      Video plane ID.
*@param i2Value                     L/R inverse on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVLRInverse(MTVDO_PATH_T eVdpId,INT16 i2Value);

/**VDO set 3D depth
*@param eVdpId                      Video plane ID.
*@param i2Value                     3D depth value.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVDepth(MTVDO_PATH_T eVdpId,INT16 i2Value);

/**VDO get frame delay
*@param eVdpId                      Video plane ID.
*@param pu4FrameDelay               Frame delay.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetFrameDelay(MTVDO_PATH_T eVdpId, INT32* pu4FrameDelay);

/**VDO set 3D navigation parameters
*@param eVdpId                      Video plane ID.
*@param u4Param                     Parameter index.
*@param u4Value                     Control value.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetTDTVNaviParam(MTVDO_PATH_T eVdpId, UINT32 u4Param, UINT32 u4Value);

/**VDO set VGA mode.
*@param bMode                       VGA mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetVgaMode(UINT8 bMode);

/**VDO set HDMI mode.
*@param bMode                       HDMI mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetHdmiMode(UINT8 bMode);

/**VDO set all mute module on/off.
*@param fgMute                      Mute on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetAllMute(BOOL fgMute);

/**VDO initialize local dimming.
*@param pTableParam                 Table paramters.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDimInitialization(INT32 pTableParam);

/**VDO enable/disable local dimming.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDimEn(BOOL fgEnable);

/**VDO enable/disable LcDS.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDSEn(BOOL fgEnable);

/**VDO set local dimming LUT index.
*@param u1Index                     LUT index.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDimLUTIdx(UINT8 u1Index);

/**VDO set local dimming demo mode.
*@param bType                       Demo mode.
*@param bCtrl                       Control setting.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDimDemoMode(UINT8 bType, BOOL bCtrl);

/**VDO bypass pre-processor.
*@param eVdpId                      Video plane ID.
*@param fgIsBypass                  Bypass/Enabled.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_BYPASS_PREPROC(MTVDO_PATH_T eVdpId, BOOL fgIsBypass);

/**VDO set OD table.
*@param pODTbl                      OD table.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetODTable(UINT8 *pODTbl);

/**VDO set OD extend table.
*@param pODTbl                      OD table.
*@param u4Size                      Size of OD table.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetODTableEX(UINT8 *pODTbl, UINT32 u4Size);

/**VDO set FB table.
*@param pFBTbl                      Table.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetFBTable(UINT8 *pFBTbl);

/**VDO set PCID table.
*@param pPCIDTbl                    Table index.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetPCIDTable(UINT8 *pPCIDTbl);

/**VDO resume SRM module.
*@param void                        void.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SRMResume(void);

/**VDO set SPI hearder.
*@param bMask                       Header bit mask.
*@param bOnOff                      bit on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLcDimSpiCommand(UINT8 bMask, BOOL bOnOff);

/**VDO sub-path scaler display off.
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetDisplayOff(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**VDO sub-path scaler display off.
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Enable/Disable.
*@param u4DispOffModule             Display off module
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetDisplayOff_Ext(MTVDO_PATH_T eVdpId,UINT32 u4DispOffModule, BOOL fgEnable);
/**VDO set sub-scaler clone mode.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetSubCloneMode(BOOL fgEnable);

/**VDO set scaling factor of vertical down scaler.
*@param eVdpId                      Video plane ID.
*@param u4Factor			        Scaling factor.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetVerticalDSFactor(MTVDO_PATH_T eVdpId, UINT32 u4Factor);

/**VDO Interface for MTAL to get status from kernel space.
*@param eVdpId                      Video plane ID.
*@param eVdoType			        MTAL command type.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Get(MTVDO_PATH_T eVdpId, MTVDO_VDO_TYPE_T eVdoType, void* pvVdoGetInfo, UINT32 u4Size);

/**VDO Interface for MTAL to set command to kernel space.
*@param eVdpId                      Video plane ID.
*@param eVdoType			        MTAL command type.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Set(MTVDO_PATH_T eVdpId, MTVDO_VDO_TYPE_T eVdoType, const void* pvVdoSetInfo, UINT32 u4Size);

/**Interface for MW to know the 3D format detected by decoder.
*@param ePath                       Video plane ID.
*@param peTag3d			            3D format.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_TDTV_GetTag3D(MTVDO_PATH_T ePath, MTTDTV_TAG3D_TYPE_T *peTag3d);

/**Interface to configure Pentouch mode.
*@param fgOnOff                     Pentouch mode on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetPentouchMode(UINT32 fgOnOff);

/**Interface for MW to know the 3D format detected by multi-media.
*@param ePath                       Video plane ID.
*@param peTag3d			            3D format.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_TDTV_GetDecTag3D(MTTDTV_DEC_MOD_TYPE eModule, MTTDTV_TAG3D_TYPE_T *peTag3d);

#ifdef __cplusplus
}
#endif

#endif //MT_VDO_H
