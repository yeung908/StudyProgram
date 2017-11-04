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
 * $RCSfile: mtvdecex.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 
/** @file MTVDECEX.h
 *  This header file declares exported APIs of external VDEC module.
 */

#ifndef MT_VDECEX_H
#define MT_VDECEX_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
   
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
// HDCP2 key
#define MTVDECEX_HDCP2_KEY_LEN 862

// HDCP key
#define MTVDECEX_HDMI_HDCP_KEY_LEN 320
// EDID key
#define MTVDECEX_HDMI_EDID_LEN 260   // 256 + 4 bytes PA address
#define MTVDECEX_VGA_EDID_LEN 256
#define MTVDECEX_HDMI_SOURCE_KSV_LEN 5


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
typedef enum
{
    VDECEX_GET_SET_HDMI_COLOR_MODE = 0,
    VDECEX_SET_SCPOS_PORCH    
} MTVDO_VDECEX_TYPE_T;

/** Input Source Types
*/
typedef enum 
{
	   MTVDECEX_SRC_ATV1,
	   MTVDECEX_SRC_DTV1,
	   MTVDECEX_SRC_DTV2,
	   MTVDECEX_SRC_DTV3,
	   MTVDECEX_SRC_DTV4,
	   MTVDECEX_SRC_CVBS1,
	   MTVDECEX_SRC_CVBS2,
	   MTVDECEX_SRC_CVBS3,
	   MTVDECEX_SRC_CVBS4,	   
	   MTVDECEX_SRC_SV1,
	   MTVDECEX_SRC_SV2,
	   MTVDECEX_SRC_SV3,
	   MTVDECEX_SRC_COMP1,
	   MTVDECEX_SRC_COMP2,
	   MTVDECEX_SRC_COMP3,
	   MTVDECEX_SRC_COMP4,
	   MTVDECEX_SRC_HDMI1,
	   MTVDECEX_SRC_HDMI2,
	   MTVDECEX_SRC_HDMI3,
	   MTVDECEX_SRC_HDMI4,
	   MTVDECEX_SRC_HDMI5,	   
	   MTVDECEX_SRC_PC1,
	   MTVDECEX_SRC_SCART1,
	   MTVDECEX_SRC_SCART2,
	   MTVDECEX_SRC_SCART3,
	   MTVDECEX_SRC_SCART4,
	   MTVDECEX_SRC_DT1,
	   MTVDECEX_SRC_DT2,
	   MTVDECEX_SRC_ATD1,
	   MTVDECEX_SRC_OSDENCODE1,         ///< Output stage to sub including OSD
	   MTVDECEX_SRC_OSTGENC,            ///< Output stage to sub without OSD
	   MTVDECEX_SRC_MAX
}MTVDECEX_SRC_T;

/** ATV/CVBS Video Color system
*/
typedef enum {
  MTVDECEX_CS_PAL_N,
  MTVDECEX_CS_PAL,
  MTVDECEX_CS_PAL_M,
  MTVDECEX_CS_NTSC358,
  MTVDECEX_CS_SECAM,
  MTVDECEX_CS_PAL_60,
  MTVDECEX_CS_UNSTABLE,
  MTVDECEX_CS_NTSC443,
  MTVDECEX_CS_AUTO,
  MTVDECEX_CS_NONE,
  MTVDECEX_CS_MAX
}MTVDECEX_CS_T;

/* Video Decoders */
typedef enum
{
    MTVDO_DEC_NA=0,    /* SV_VD_NA must be 0 */
    MTVDO_DEC_TVD3D,
    MTVDO_DEC_YPBPR,
    MTVDO_DEC_VGA,
    MTVDO_DEC_DVI,
    MTVDO_DEC_MPEGHD, // Add for 5371
    MTVDO_DEC_MPEGSD,
    MTVDO_DEC_MAX
}MTVDO_DEC_TYPE_T;

/* Video Signal Status */
typedef enum
{
	MTVDECEX_VDO_NOSIGNAL		= 0,
	MTVDECEX_VDO_NOSUPPORT,
	MTVDECEX_VDO_UNKNOWN,		// Still doing mode detect
	MTVDECEX_VDO_STABLE
}MTVDECEX_SIG_STATUS;

/** VGA ambiguous timing information
*/
typedef struct
{
    UINT8                    u1CandiIdx;
    UINT8                    u1RefreshRate;   	/* [OUT] vertical frequency */
    UINT16                  u2Width; 			/* [OUT] horizontal resolution */
    UINT16                  u2Height; 		/* [OUT] vertical resolution */
}   MTVDECEX_VGA_AMBIG_TIMING_T;

/** TVD CAGC information
*/
typedef struct
{
	UINT8		u1MCAGC_EN;		/* manual CAGC enable bit */
	UINT8		u1MCAGC;			/* manual CAGC value */
	UINT32		u4Bound;			/* CAGC bound */
	UINT8		u1L_Step;			/* CAGC L Step */
	UINT8		u1S_Step;			/* CAGC S Step */
}   MTVDECEX_CAGC_PRM_T;

typedef struct
{
	UINT8 u1VpresGain;
	UINT8 u1VlockRatio;
}MTVDECEX_SCANADJ_INFO_T;

/** API to get/set eaten porch accrording to current video timing.
*/
typedef enum 
{
	MTVDECEX_HPORCH_CURRENT,
	MTVDECEX_HPORCH_DEFAULT,
	MTVDECEX_HPORCH_MIN,
	MTVDECEX_HPORCH_MAX,
	MTVDECEX_VPORCH_CURRENT,
	MTVDECEX_VPORCH_DEFAULT,
	MTVDECEX_VPORCH_MIN,
	MTVDECEX_VPORCH_MAX
} MTVDECEX_PORCH_TYPE_T;

typedef enum 
{
	MTVDECEX_PORCHTUNE_DEC = 1,
 	MTVDECEX_PORCHTUNE_SCPOS =2 ,
 	MTVDECEX_PORCHTUNE_MIXED = 3
} MTVDECEX_PORCHTUNE_TYPE_T;

/** VGA colck information types
*/
typedef enum 
{
	MTVDECEX_VGA_CLOCK_MIN,
	MTVDECEX_VGA_CLOCK_CURRENT,
	MTVDECEX_VGA_CLOCK_MAX
}MTVDECEX_CLOCK_TYPE_T;

/** VGA phase information types
*/
typedef enum 
{
	MTVDECEX_VGA_PHASE_MIN,
	MTVDECEX_VGA_PHASE_CURRENT,
	MTVDECEX_VGA_PHASE_MAX
}MTVDECEX_PHASE_TYPE_T;


typedef struct
{
     UINT8  ui2_av1_status;
     UINT8  ui2_av2_status;
     UINT8  ui2_ypbpr1_status;	 
	 UINT8  ui2_hdmi1_status;
	 UINT8  ui2_hdmi2_status;
	 UINT8  ui2_hdmi3_status;
	 UINT8  ui2_hdmi4_status;
	 UINT8  ui2_vga_status;
} MTVDECEX_TV_DEC_SOURCE_STATUS_T;
typedef struct
{
    UINT8 au1HDMI_KSV[MTVDECEX_HDMI_SOURCE_KSV_LEN];
}MTVDECEX_SOURCE_KSV_T;


/**
 * Hdcp key.
 *
*/
typedef struct
{
    UINT8 au1Hdcp2Key[MTVDECEX_HDCP2_KEY_LEN];
}MTVDECEX_HDCP2_KEY_T;

/**
 * Hdcp key.
 *
*/
typedef struct
{
    UINT8 au1HdcpKey[MTVDECEX_HDMI_HDCP_KEY_LEN];
}MTVDECEX_HDCP_KEY_T;

/**
 * HDMI EDID data.
 *
*/
typedef struct
{
    UINT8 au1HdmiEdid[MTVDECEX_HDMI_EDID_LEN]; 
}MTVDECEX_HDMI_EDID_T;

/**
 * HDMI VGA data.
 *
*/
typedef struct
{
    UINT8 au1VgaEdid[MTVDECEX_VGA_EDID_LEN];
}MTVDECEX_VGA_EDID_T;

/** HDMI mode
*/
typedef enum {
    MTVDECEX_HDMI_NO_SIGNAL = 0,
    MTVDECEX_HDMI_HDMI,
    MTVDECEX_HDMI_DVI,
    MTVDECEX_HDMI_MODE_MAX
}MTVDECEX_HDMI_MODE_T;

/** HDMI aspect ratio
*/
typedef enum {
    MTVDECEX_HDMI_ARATIO_NODATA = 0,
    MTVDECEX_HDMI_ARATIO_4_3,
    MTVDECEX_HDMI_ARATIO_16_9,
    MTVDECEX_HDMI_ARATIO_RESERVED,
    MTVDECEX_HDMI_ARATIO_MAX
}MTVDECEX_HDMI_ARATIO_T;

/** HDMI Deep mode
*/
typedef enum {
    MTVDECEX_HDMI_DEEPCOLOR_8BIT = 0,
    MTVDECEX_HDMI_DEEPCOLOR_10BIT,
    MTVDECEX_HDMI_DEEPCOLOR_12BIT,
    MTVDECEX_HDMI_DEEPCOLOR_16BIT,
    MTVDECEX_HDMI_DEEPCOLOR_MAX
}MTVDECEX_HDMI_DEEPCOLOR_MODE_T;

/** HDMI Audio type
*/
typedef enum {
    MTVDECEX_HDMI_AUDIOTYPE_PCM = 0,
    MTVDECEX_HDMI_AUDIOTYPE_NONEPCM ,
    MTVDECEX_HDMI_AUDIOTYPE_MAX
}MTVDECEX_HDMI_AUDIOTYPE_T;

/** HDMI Audio Frequency
*/
typedef enum {
    MTVDECEX_HDMI_AUDIOFREQUENCY_32K = 0,
    MTVDECEX_HDMI_AUDIOFREQUENCY_44K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_48K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_88K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_96K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_176K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_192K,
    MTVDECEX_HDMI_AUDIOFREQUENCY_NOTINDICATED,
    MTVDECEX_HDMI_AUDIOFREQUENCY_UNKNOWN,
    MTVDECEX_HDMI_AUDIOFREQUENCY_MAX
}MTVDECEX_HDMI_AUDIOFREQUENCY_T;

/** HDMI HDMI audio length
*/
typedef enum {
    MTVDECEX_HDMI_AUDIOLENGTH_16BITS = 0,
    MTVDECEX_HDMI_AUDIOLENGTH_17BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_18BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_19BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_20BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_21BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_22BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_23BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_24BITS,
    MTVDECEX_HDMI_AUDIOLENGTH_UNKNOWN,
    MTVDECEX_HDMI_AUDIOLENGTH_MAX
}MTVDECEX_HDMI_AUDIOLENGTH_T;


/** HDMI Color mode
*/
typedef enum {
    MTVDECEX_HDMI_MODE_AUTO,
    MTVDECEX_HDMI_MODE_GRAPHIC,
    MTVDECEX_HDMI_MODE_VIDEO

}MTVDECEX_HDMI_COLOR_MODE_T;
typedef enum {
    MTVDECEX_HDMI_MHL_DEVICE_CONNECTED,
    MTVDECEX_HDMI_MHL_DEVICE_NOT_EXIST
}MTVDECEX_HDMI_MHL_MODE_T;
typedef struct
{
    //UINT32 u4HdmiPort;
	UINT32 enable;
}MTVDECEX_HDMI_VIDEO_MODE_T;


/**Video callback structure
*/
typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3;
    UINT32 u4Arg4;
    UINT32 u4Arg5;
    UINT32 u4Arg6;
    UINT32 u4Arg7;    
}MTVDECEX_CB_T;

/**Video plane call back function type id.
*/
typedef enum
{
    MTVDECEX_CB_FUNC_SIG_CHG,    ///Signal change notify
    MTVDECEX_CB_FUNC_SIG_CHG_2,	 ///Signal change notify
    MTVDECEX_CB_FUNC_VGA_AUTO, 		//auto done notify
    MTVDECEX_CB_FUNC_AUTO_COLOR,
    MTVDECEX_CB_FUNC_RESOLUTION_CHG,
    MTVDECEX_CB_FUNC_COMP_SIG_CHG,
    MTVDECEX_CB_FUNC_COLOR_SYSTEM,  
    MTVDECEX_CB_FUNC_MV_CHG,
    MTVDECEX_CB_FUNC_AUTO_DETECT_SRC,
    MTVDECEX_CB_FUNC_ANA_SIG_CHG,   //Tuner analog tvd notify
    MTVDECEX_CB_FUNC_VGA_AUTO_PRG,	 //auto progress notify 
    
}MTVDECEX_CB_FUNC_ENUM_T;

/**TVD ADC channel id
*/
typedef enum
{
	TVDADC_CHANNEL_A,
	TVDADC_CHANNEL_B
} MTVDEC_TVD_CHANNEL_T;

/** TVD lock status
*/
typedef enum {
    MTVDECEX_TVD_VPRES = 0,
    MTVDECEX_TVD_VLOCK,
    MTVDECEX_TVD_HLOCK,
    MTVDECEX_TVD_LLOCK,
    MTVDECEX_TVD_NRLVL,
    MTVDECEX_TVD_NASTA,
    MTVDECEX_TVD_CHSCAN_LOCK,
    MTVDECEX_TVD_VIDEO_STABLE
}MTVDECEX_TVD_STATUS_T;

/** TVD SECAM setting
*/
typedef struct 
{
	union
	{
		UINT32 u4Secam01;
		
		struct 
		{
    			UINT32 		MTTVD_YSEL			:	3;			//22604H          [2:0]
    			UINT32 		MTTVD_HDEMPH_BYPASS	:	1;//22604H          [3]
    			UINT32 		MTTVD_CSEL			:	3;			//22604H          [6:4]
    			UINT32 		MTTVD_LDEMPH_BYPASS			:	1;		//22604H          [7]
    			UINT32 		MTTVD_DOT_REDUCE	:	1;	//22604H          [8]
    			UINT32 		MTTVD_MLEN_SEL		:	1;		//22604H          [9]
    			UINT32 		MTTVD_MSTART_SEL		:	2;	//22604H          [11:10]
    			UINT32 		MTTVD_PDIFF_THR		:	4;		//22604H          [15:12]
    			UINT32 		MTTVD_PDIFFCLIP_EN	:	1;	//22604H          [16]
    			UINT32 		MTTVD_DBDR_THR	:	2;	//22604H          [18:17]
    			UINT32						:	2;
    			UINT32 		MTTVD_BLENDING_SEL	:	2;	//22604H          [22:21]
    			UINT32 		MTTVD_SDEC_SEL		:	1;		//22604H          [23]
    			UINT32 		MTTVD_CAGC_EN		:	1;		//22604H          [24]
    			UINT32 		MTTVD_BPRES_SEL		:	2;		//22604H          [26:25]
    			UINT32 						:	5;		//22604H          [31:27]
		} rSecam01;
	}uSecam01;
} MTVDECEX_TVD_SECAM_T;

/** Video signal status callback function
*/
typedef VOID (*MTVDECEX_PFN_SIG_NFY_CB)(
    MTVDO_PATH_T					ePath,
    MTVDECEX_SIG_STATUS			eSigStatus,
    //UINT8						u1SigSkip
    UINT16						u2SrcWidth,
    UINT16						u2SrcHeight,
    UINT16						u2FrameRate,
    UINT16						u2IsInterlace
);

/** VGA atuo  progress callback function
*/
typedef VOID (*MTVDECEX_PFN_VGA_AUTO_PRG_CB)(
    MTVDO_PATH_T ePath,
    UINT8		u1Progress
);
/** VGA atuo  finish callback function
*/
typedef VOID (*MTVDECEX_PFN_VGA_AUTO_CB)(
    MTVDO_PATH_T ePath,
    UINT8		u1Progress
);

/** Atuo color finish callback function
*/
typedef VOID (*MTVDECEX_PFN_AUTOCOLOR_CB)(
    MTVDO_PATH_T ePath,
    UINT8		u1Success
);

/** Resolution change callback function
*/
typedef VOID (*MTVDECEX_PFN_RESOLUTION_CHG_CB)(
    MTVDO_PATH_T ePath,
    UINT8	u1SigState
);

/** S-first finish callback function
*/
typedef VOID (*MTVDECEX_PFN_COMP_SIG_CHG_CB)(
    MTVDO_PATH_T epath,
    UINT8	ui4_drv_status
);

/** color system callback function
*/
typedef VOID (*MTVDECEX_PFN_COLOR_SYSTEM_CB)(
    MTVDO_PATH_T ePath,
    UINT8 u1SigState
);

/** MV change callback function
*/
typedef VOID (*MTVDECEX_PFN_MV_CHG_CB)(
    MTVDO_PATH_T ePath, 
    BOOL fgStatus
);

/** Atuo detect source callback function
*/
typedef VOID (*MTVDECEX_PFN_AUTO_DETECT_SRC_CB)(
    UINT8 u1SrcIndex, 
    UINT8 u1SrcStatus
);

/** Tuner analog tvd notify
*/
typedef VOID (*MTVDECEX_PFN_TUNER_ANA_TVD_CB)(
    UINT8 u1SrcIndex, 
    UINT8 u1SrcStatus
);
typedef VOID (*MTVDECEX_HDMI_CB)(
    UINT8 u1EventID, 
    UINT8 *u1UserData
);
//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Video
//-----------------------------------------------------------------------------


/**
 * @check if current input source is PC timing
 * @param  ePath :main/sub path (MTVDO_MAIN, / MTVDO_SUB)
 * @param  *pfgPcTiming :TRUE(PC timing)  or FALSE(Video timing)
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 */
EXTERN MT_RESULT_T MTVDECEX_IsPCTiming(MTVDO_PATH_T ePath, BOOL *pfgPcTiming);

/**
 * @check if current input source is oversample timing
 * @param  ePath :main/sub path (MTVDO_MAIN, / MTVDO_SUB)
 * @param  *pfgOversampleTiming :TRUE(oversample timing)  or FALSE(non-oversample timing)
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 */
EXTERN MT_RESULT_T MTVDECEX_IsOversampleTiming(MTVDO_PATH_T ePath, BOOL *pfgOversampleTiming);

/**
 * @set application parameters of h_proch and active width to be dependent to driver oversample or not
 * @param  u4OnOff :TRUE(dependent)  or FALSE(independent)
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 */
EXTERN MT_RESULT_T MTVDECEX_SetOversampleDependent(UINT32 u4OnOff);

/**
 * @get application parameters of h_proch and active width to be dependent to driver oversample or not
 * @param  *pu4OnOff :TRUE(dependent)  or FALSE(independent)
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 */
EXTERN MT_RESULT_T MTVDECEX_GetOversampleDependent(UINT32 *pu4OnOff);

/**
 * Trigger the action to select video input source.
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_SUB)
 * @param eSrc Select the video input source.
 * @code
     typedef enum 
     {
            MTVDECEX_SRC_ATV1,
            MTVDECEX_SRC_DTV1,
            MTVDECEX_SRC_DTV2,
            MTVDECEX_SRC_DTV3,
            MTVDECEX_SRC_DTV4,
            MTVDECEX_SRC_CVBS1,
            MTVDECEX_SRC_CVBS2,
            MTVDECEX_SRC_CVBS3,
            MTVDECEX_SRC_CVBS4,     
            MTVDECEX_SRC_SV1,
            MTVDECEX_SRC_SV2,
            MTVDECEX_SRC_SV3,
            MTVDECEX_SRC_COMP1,
            MTVDECEX_SRC_COMP2,
            MTVDECEX_SRC_COMP3,
            MTVDECEX_SRC_COMP4,
            MTVDECEX_SRC_HDMI1,
            MTVDECEX_SRC_HDMI2,
            MTVDECEX_SRC_HDMI3,
            MTVDECEX_SRC_HDMI4,
            MTVDECEX_SRC_HDMI5,     
            MTVDECEX_SRC_PC1,
            MTVDECEX_SRC_SCART1,
            MTVDECEX_SRC_SCART2,
            MTVDECEX_SRC_SCART3,
            MTVDECEX_SRC_SCART4,
            MTVDECEX_SRC_DT1,
            MTVDECEX_SRC_DT2,
            MTVDECEX_SRC_ATD1,
            MTVDECEX_SRC_MAX
     }MTVDECEX_SRC_T;
 * @endcode 
 * @return The exit status of this api.
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 * @retval MTR_PARAMETER_NOCHANGE
 */
EXTERN MT_RESULT_T MTVDECEX_SetVideoSrc(MTVDO_PATH_T ePath, MTVDECEX_SRC_T eSrc);

/**
 * Set the video sources of main and sub.
 *
 * @param eMainSrc Main video input source. 
 * @param eSubSrc Sub video input source. 
 * @return The exit status of this api.
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 * @retval MTR_PARAMETER_NOCHANGE
 */
EXTERN MT_RESULT_T MTVDECEX_SetMainSubSrc(MTVDECEX_SRC_T eMainSrc, MTVDECEX_SRC_T eSubSrc);

/**
 * Set Video Position  
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param ePorchType 
 	MTVDECEX_HPORCH_CURRENT,
	MTVDECEX_VPORCH_CURRENT,
 * @param u2Value The value of porch.	
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetPorch(MTVDO_PATH_T ePath, MTVDECEX_PORCH_TYPE_T ePorchType, UINT16 u2Value);

/**
 * Get Video Position  
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param ePorchType 
 	MTVDECEX_HPORCH_CURRENT,
	MTVDECEX_HPORCH_DEFAULT,
	MTVDECEX_HPORCH_MIN,
	MTVDECEX_HPORCH_MAX,
	MTVDECEX_VPORCH_CURRENT,
	MTVDECEX_VPORCH_DEFAULT,
	MTVDECEX_VPORCH_MIN,
	MTVDECEX_VPORCH_MAX
   @param u2Value The porch value
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetPorch(MTVDO_PATH_T ePath, MTVDECEX_PORCH_TYPE_T ePorchType, UINT16 *pu2Value);

/**
 * Get input video frame rate
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value Frame rate
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoRefreshRate(MTVDO_PATH_T ePath, UINT16 *pu2Value);

/**
 * Get input video width
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value input video width
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoInputWidth(MTVDO_PATH_T ePath, UINT16 *pu2Value);

/**
 * Get input video height
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value input video height
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoInputHeight(MTVDO_PATH_T ePath, UINT16 *pu2Value);


/**
* @brief Register video signal change/ VGA auto/Auto color callback function
* @eFuncType
        MTVDECEX_CB_FUNC_SIG_CHG
        MTVDECEX_CB_FUNC_VGA_AUTO
        MTVDECEX_CB_FUNC_AUTO_COLOR
        MTVDECEX_CB_FUNC_RESOLUTION_CHG
        MTVDECEX_CB_FUNC_COMP_SIG_CHG
        MTVDECEX_CB_FUNC_COLOR_SYSTEM  
        MTVDECEX_CB_FUNC_MV_CHG,
        MTVDECEX_CB_FUNC_AUTO_DETECT_SRC,
        MTVDECEX_CB_FUNC_ANA_SIG_CHG,   //Tuner analog tvd notify
* @param pfnFct input video signal decteion done callback function 
* @param u4Arg1 reserved
* @retval MTR_OK        Success.
* @retval MTR_NOT_OK    Fail.
* case : MTVDECEX_CB_FUNC_SIG_CHG for all signal input expect for DTV SRC
*/
EXTERN MT_RESULT_T MTVDECEX_RegCbFunc(MTVDECEX_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);
EXTERN MT_RESULT_T MTVDECEX_UnRegCbFunc(MTVDECEX_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);



EXTERN MT_RESULT_T MTVDECEX_IsMhlSignal(UINT8 * pu1Value);

//-----------------------------------------------------------------------------
// HDTV
//-----------------------------------------------------------------------------

/**
 * Trigger Auto state machine entry,auto phase, auto clock and auto position. When VGA auto process finish, driver will call back to AP.
 * Do it when path is VGA
 * @param VOID
 * @retval MTR_OK                    Begin to execute VGA auto.
 * @retval MTR_NOT_OK            Cannot execute VGA auto.
 */
EXTERN MT_RESULT_T MTVDECEX_StartVgaAuto(VOID);

/**
 * Force VGA auto stop.
 * Do it when path is VGA
 * @param VOID
 * @retval MTR_OK                    Begin to stop VGA auto.
 * @retval MTR_NOT_OK            Cannot stop VGA auto.
 */
EXTERN MT_RESULT_T MTVDECEX_StopVgaAuto(VOID);

/**
 * Trigger Auto Color state machine (VGA or YPbPr). When auto color process finish, driver will call back to AP.
 * @param VOID
 * @retval MTR_OK                    Begin to execute auto color process.
 * @retval MTR_NOT_OK            Cannot execute auto color process.
 */
EXTERN MT_RESULT_T MTVDECEX_StartAutoColor(VOID);

/**
 * Manual adjust ADC sampling Phase only used in YPbPr and VGA input source.
 *
 * @param u1Value Default 16, range 0- 31
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetPhase(UINT8 u1Value);

/**
 * Get ADC sampling Phase and only used in YPbPr and VGA input source.
 * @param ePhaseType
  	MTVDECEX_VGA_PHASE_MIN=0,
	MTVDECEX_VGA_PHASE_CURRENT,
	MTVDECEX_VGA_PHASE_MAX=31
 * @param u1Value phase value 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetPhase(MTVDECEX_PHASE_TYPE_T ePhaseType,UINT8 *pu1Value);

/**
 * Manual adjust correct sample clock and only used in YPbPr and VGA input source.
 *
 * @param u2Value Default 127, range 0- 255
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetClock(UINT16 u2Value);

/**
 * Get correct sample clock and only used in YPbPr and VGA input source.
 *
 * @param eClockType
 	MTVDECEX_VGA_CLOCK_MIN=0,
	MTVDECEX_VGA_CLOCK_CURRENT,
	MTVDECEX_VGA_CLOCK_MAX=255
   @param pu2Value The result of sample clock	
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetClock(MTVDECEX_CLOCK_TYPE_T eClockType,UINT16 *pu2Value);

/**
 * Enable/Disable to set the ambiguous vga mode with the previous user select
 * mode
 *
 * @param fgUserSel SV_FALSE to disable, otherwise to enable
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_SetAmbiguousUserSel(BOOL fgUserSel);

/**
 * Get number of items of ambiguous VGA in current VGA timing group
 *
 * @param pu1AmbiguousTimingNum If current timing is not ambiguous, the return value will be 1. Otherwise, it will be the total number of current ambiguous VGA timing. 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_GetAmbiguousTimingNum(UINT8 * pu1AmbiguousTimingNum);

/**
 * Query certain or current VGA timing details.
 *
 * @param u1OptionIdx index of ambiguous timing and start from 1
 * @param prAmbigVgaTimingInfo structure pointer of struct type "MTVDECEX_AMBIG_VGA_TIMING_T"
 * @Param u1TimingNum
 * @return NONE. It will return 1. index in current group, 2. V freq, 3. H resolution, 4. V resolution
 * @retval MTR_OK          Success.
 * @retval MTR_NOT_OK  Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_QueryAmbiguousTiming(UINT8 u1OptionIdx, MTVDECEX_VGA_AMBIG_TIMING_T* prAmbigVgaTimingInfo, UINT8 u1TimingNum);

/**
 * Set VGA timing according to input ambiguous timing index.
 *
 * @param u1OptionIdx Set ambiguous timging decision  and start from 1
 * @param fgSetDefault Set u1OptionIdx timing as default. 
 * @retval MTR_OK       Success.
 * @retval MTR_NOT_OK   Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_SetAmbiguousIndex(UINT8 u1OptionIdx, BOOL fgSetDefault);

/**
 * Get current VGA ambiguous index
 *
 * @param pu1CurrentAmbiguousIndex VGA ambiguous timing index
 * @retval MTR_OK       Success.
 * @retval MTR_NOT_OK   Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_GetCurrentAmbiguousIndex(UINT8 *pu1CurrentAmbiguousIndex);



//-----------------------------------------------------------------------------
// HDMI
//-----------------------------------------------------------------------------

/**
 * @VGA EDID On/Off control
 * @param  u1Port                    VGA port
 * @param  u1Value            	     1:enable  0:disable
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_EdidOnOffCtrl( UINT8 u1Port, UINT8 u1Value);

/**
 * @VGA Set EDID Data
 * @param  u4Value            	     Pointer of EDID data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_SetEdidData(MTVDECEX_VGA_EDID_T* u4Value);


/**
 * @VGA Get EDID Data
 * @param  u4Value            	     Pointer of EDID data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_GetEdidData(MTVDECEX_VGA_EDID_T* u4Value);


/**
 * Time period of HPD low which is used to reset player. 
 * @param u4Value The low period of HPD in millisecond.
 * @retval MTR_OK        Success.
 * @retval MTR_NOT_OK    Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_SetHPDAdjust(UINT32 u4Value);

/**
 * @Get HDMI infoFrame data
 * @param peFrame Pointer of info-frame data.
 * @param u1FrameType The type of infoFram.
 	HDMI_InfoFrame_AVI/ 	HDMI_InfoFrame_SPD/	HDMI_InfoFrame_AUDIO/ HDMI_InfoFrame_MPEG/
	HDMI_InfoFrame_UNREC/ HDMI_InfoFrame_GAMUT/ HDMI_InfoFrame_ACP
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetInfoFrame(const MTVDECEX_HDMI_INFOFRAME* prFrame ,UINT8 u1FrameType );

/**
 * @Get HDMI mode
 * @param peMode                HDMI mode
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetMode(MTVDECEX_HDMI_MODE_T* peMode);
/**
 * @Get SPDUPstatus
 * @param upsta                upstatus
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetSPDUpSta(UINT8* upsta);
/**
 * @Get SPDUPstatuschange
 * @param upstachg                upstatuschange
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetSPDUpStaChg(UINT8* upstachg);
/**
 * @Get SPDsvstastatus
 * @param svsta                svstatus
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetSPDSvSta(UINT8* svsta);
/**
 * @Get SPDsvstastatuschange
 * @param svstachg                svstatuschange
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetSPDSvStaChg(UINT8* svstachg);


EXTERN MT_RESULT_T MTVDECEX_HDMI_GetSPD4KpsSta(UINT8* u14KpsSta);

/**
 * @Get HDMI aspect ratio
 * @param peRatio                HDMI aspect ratio
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetAspectRatio(MTVDECEX_HDMI_ARATIO_T* peRatio);

/**
 * @Get HDMI Deep color mode
 * @param peDeepColorMode                HDMI Deep color mode
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetDeepColorMode(MTVDECEX_HDMI_DEEPCOLOR_MODE_T* peDeepColorMode);
/**
 * @Get HDMI audio PCM mode 
 * @param pePCM                HDMI audio PCM mode
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_IsPCM(MTVDECEX_HDMI_AUDIOTYPE_T* pePCM);

/**
 * @Get HDMI audio Frequency
 * @param peAUDIOFreq                HDMI audio Frequency
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetAudioFrequency(MTVDECEX_HDMI_AUDIOFREQUENCY_T* peAUDIOFreq);

/**
 * @Get HDMI Audio bit width
 * @param peBitWidth                 HDMI Audio bit width
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetAudioBitWidth(MTVDECEX_HDMI_AUDIOLENGTH_T* peBitWidth);

/**
 * @Get HDMI Audio category code
 * @param pu4CategoryCode            Categorycode
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetAudioCategoryCode(UINT8* pu1CategoryCode);

/**
 * @Init HDMI/CCIR
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
 EXTERN MT_RESULT_T MTVDECEX_HDMI_FastInit(void);


EXTERN MT_RESULT_T MTVDECEX_HDMI_Init(void);
 
/**
 * @Init HDMI Uninit
 * @retval MTR_OK					  Success.
 * @retval MTR_NOT_OK				  Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_UnInit(void);

/**
 * @HDMI Open
 * @retval MTR_OK					  Success.
 * @retval MTR_NOT_OK				  Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_Open(void);

/**
 * @HDMI Close
 * @retval MTR_OK					  Success.
 * @retval MTR_NOT_OK				  Fail.
*/
EXTERN MT_RESULT_T MTVDECEX_HDMI_Close(void);

/**
  * @HDMI Connect: choose one hdmi port to connect
  * @retval MTR_OK 				   Success.
  * @retval MTR_NOT_OK 			   Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_Connect(UINT8 eport);
 /**
 @Set HDMI color mode
 * @param  eVdpId            	     MAIN/PIP
 * @param  eMode            	     AUTO/GRAPHIC/VIDEO
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_SetColorMode(MTVDO_PATH_T eVdpId, MTVDECEX_HDMI_COLOR_MODE_T eMode);

/**
 * @Get color system of current HDMI input signal
 * @param pColorDomain     
       0 (RGB domain)
       1 (YCBCR domain)
       2 (xvYCC domain)
       3 (DVI-RGB domain)
       4 (unknown domain)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetColorDomain(MTPQL_HDMI_COLOR_DOMAIN_T* pColorDomain);

/**
 * @Set HDCP key
 * @param  u4Value            	     Pointer of HDCP key data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_SetHdcpKey(MTVDECEX_HDCP_KEY_T* u4Value);

/**
 * @HDMI Set EDID Data
 * @param  u4Value            	     Pointer of EDID data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_SetEdidData(MTVDECEX_HDMI_EDID_T* u4Value);
EXTERN MT_RESULT_T MTVDECEX_HDMI_SetEdidDataByPort(UINT8 port,MTVDECEX_HDMI_EDID_T* u4Value);

/**
 * @HDMI EDID On/Off control
 * @param  u1Port                    HDMI port
 * @param  u1Value            	     1:enable  0:disable
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_EdidOnOffCtrl( UINT8 u1Port, UINT8 u1Value);


/**
 * @Get HDCP key
 * @param  u4Value            	     Pointer of HDCP key data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetHdcpKey(MTVDECEX_HDCP_KEY_T* u4Value);

/**
 * @HDMI Get EDID Data
 * @param  u1Port                    HDMI port number
 * @param  u4Value            	     Pointer of EDID data
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetEdidData(UINT8 u1Port, MTVDECEX_HDMI_EDID_T* u4Value);

/**
 * @HDMI Get HDCP status
 * @param  pu1Value            	     1:decryption success   0:decryption fail
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetHDCPStatus(UINT8 *pu1Value);

/**
 * @HDMI Get Scan info
 * @param  pu1Value            	     0:no data 1:overscanned  2:undersanned
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetScanInfo(UINT8 *pu1Value);

/**
 * @HDMI Get Aspect Ratio
 * @param  pu1Value            	     8:same as picture  9:4:3(center)  10:16:9(center)  14:9(center) 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetAFD(UINT8 *pu1Value);

/**
 * @HDMI Get input type
 * @param  pu1Value            	     1:RGB  0:YCBCR
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetInputType(UINT8 *pu1Value);

/**
 * @HDMI support audio or not
 * @param  pu1Value            	     1:support  0:not support
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
 
EXTERN MT_RESULT_T MTVDECEX_HDMI_W2D_SetVideoMode(MTVDECEX_HDMI_VIDEO_MODE_T *phdmiVideoMode);
EXTERN MT_RESULT_T MTVDECEX_HDMI_IsSupportAudio(UINT8 *pu1Value);

EXTERN MT_RESULT_T MTVDECEX_HDMI_MHL_ReadWriteBurst(char *mhl_msg);

EXTERN MT_RESULT_T MTVDECEX_HDMI_SendMSCMsg(UINT8 rcp);

EXTERN MT_RESULT_T MTVDECEX_HDMI_MHL_IsMode(MTVDECEX_HDMI_MHL_MODE_T* pIsMhlMode);
/**
 * @Get HDMI color mode
 * @param  eVdpId            				 MAIN/PIP
 * @param  peMode            				 AUTO/GRAPHIC/VIDEO
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_HDMI_GetColorMode(MTVDO_PATH_T eVdpId, MTVDECEX_HDMI_COLOR_MODE_T *peMode);

EXTERN MT_RESULT_T MTVDECEX_GetSrcDetectStatus(MTVDECEX_TV_DEC_SOURCE_STATUS_T *peStatus);

//-----------------------------------------------------------------------------
// TVD
//-----------------------------------------------------------------------------

/**
 * @Set TVD manual Gain
 * @param u4Value                on/off
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 * MTVDECEX_TVD_SetMAGC set 1 => use manual analog and digital gain according to the setting MTVDECEX_TVD_SetAGCDigitalGain/       MTVDECEX_TVD_SetAGCAnalogGain
 * MTVDECEX_TVD_SetMAGC set 0 => use auto AGC control for CVBS signal amplitude
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetMAGC(UINT32 u4Value);

/**
 * @Set TVD Analog Gain
 * @param eChannelSel          TVD ADC channel
 * @param u4Value                TVD analog gain
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 * TVD will control CVBS input amplitude according to CVBS sync height. It has analog and digital gain for this AGC control.
 * We also allow user stop auto AGC control and use manual analog and digital gain.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_Set2ChPgaGain(MTVDEC_TVD_CHANNEL_T eChannelSel, UINT32 u4Value);

/**
 * @Set TVD Digital Gain
 * @param u4Value                TVD digital gain (only for CHA)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 * TVD will control CVBS input amplitude according to CVBS sync height. It has analog and digital gain for this AGC control.
 * We also allow user stop auto AGC control and use manual analog and digital gain.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetAGCDigitalGain(UINT32 u4Value);

/**
 * @Set TVD PGA offset
 * @param eChannelSel          TVD ADC channel
 * @param u4Value                TVD target blank level (only for CHA)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_Set2ChClampLevel(MTVDEC_TVD_CHANNEL_T eChannelSel, UINT32 u4Value);

/**
 * @Set TVD CAGC Parameter
 * @param prPrm MTVDECEX_CAGC_PRM_T    
    u1MCAGC_EN;		manual CAGC enable bit 
    u1MCAGC;			 manual CAGC value 
    u4Bound;			 	CAGC bound (MID_B/MID_A/TARGET_B/TARGET_A)
    u1L_Step;			 CAGC L Step 
    u1S_Step;			 CAGC S Step 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 *      _rTvd3dCAGCInfo.MCAGC_EN = (UINT8) rCAGCParam.u1MCAGC_EN; //manual CAGC enable bit
 *      _rTvd3dCAGCInfo.MCAGC = (UINT8) rCAGCParam.u1MCAGC;  //manual CAGC gain value
 *      _rTvd3dCAGCInfo.Bound = (UINT32)rCAGCParam.u4Bound;   //auto CAGC control target
 *      _rTvd3dCAGCInfo.L_Step = (UINT8) rCAGCParam.u1L_Step;   //auto CAGC coarse step control gain
 *      _rTvd3dCAGCInfo.S_Step = (UINT8) rCAGCParam.u1S_Step;  //auto CAGC fine step control gain
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetCAGC(MTVDECEX_CAGC_PRM_T *prPrm);

/**
 * @Set TVD SCAN Parameter
 * @param prPrm    MTVDECEX_SCAN_INFO_T    
    u1VpresGain : vpres onoff gain
    u1VlockRatio :vsync lock ratio
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetScanadjInfo(MTVDECEX_SCANADJ_INFO_T *prInfo);

/**
 * @Get TVD SCAN Parameter
 * @param prPrm    MTVDECEX_SCAN_INFO_T    
   u1VpresGain : vpres onoff gain
   u1VlockRatio :vsync lock ratio
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetScanadjInfo(MTVDECEX_SCANADJ_INFO_T *prInfo);

/**
 * @Set TVD YDelay, UVDelay
 * @param u1YDelay                TVD YDelay    range 0- 3
 * @param u1UVDelay               TVD UVDelay   range 0- 3
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 *  TheMTVDECEX_TVD_SetUVDelay is setting the CVBD active data delay. it control Y and UV delay separately.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetUVDelay(UINT8 u1YDelay, UINT8 u1UVDelay);

/**
 * @Set TVD PGA offset
 * @param eChannelSel          TVD ADC channel
 * @param u4Value                0 (manual) 1 (agc/follow chA)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_Set2AGCMode(MTVDEC_TVD_CHANNEL_T eChannelSel, UINT32 u4Value);

/**
 * @Get TVD Status
 * @param eType       
     MTVDECEX_TVD_VPRES = 0,
     MTVDECEX_TVD_VLOCK,
     MTVDECEX_TVD_HLOCK,
     MTVDECEX_TVD_LLOCK,
     MTVDECEX_TVD_NRLVL,
     MTVDECEX_TVD_NASTA,
     MTVDECEX_TVD_CHSCAN_LOCK,
     MTVDECEX_TVD_VIDEO_STABLE
   @param pu1Value                  status
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetStatus(MTVDECEX_TVD_STATUS_T eType,UINT8 *pu1Value);

/**
 * @Set TVD Anti-Alias Filter
 * @param u1OnOff     
 * @param u1Value     
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetAAF(UINT8 u1OnOff,UINT8 u1Value);

/**
 * @Set TVD Secam Setting (directly access SECAM register)
 * @param prPrm SECAM settings     
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetSecamSetting(MTVDECEX_TVD_SECAM_T *prPrm);

/**
 * @Set Analog Auto Search flag
 * @param u1OnOff     
      0 (leave analog auto search mode) 1 (enter analog auto search mode)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetAutoSearch(UINT8 u1OnOff);

/**
 * Trigger Auto Color state machine (CVBS). When auto color process finish, driver will call back to AP.
 * @param VOID
 * @retval MTR_OK                    Begin to execute auto color process.
 * @retval MTR_NOT_OK            Cannot execute auto color process.
 */
EXTERN MT_RESULT_T MTVDECEX_StartCVBSAutoColor(VOID);

/**
 * @Set Hold Mode for channel change. If hold mode is enabled, driver will not trigger mode change done callback
 * @param u1OnOff     
      0 (disable HoldMode) 1 (enable Hold Mode)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_HoldMode(UINT8 u1OnOff);

/**
 * @Set Pedestal Enable
 * @param u1OnOff     
      0 (disable pedestal) 1 (enable pedestal)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_AGCPedEn(UINT8 u1OnOff);

/**
 * Get Default Video Position (according to each color system SPEC.)  
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param ePorchType 
 	MTVDECEX_HPORCH_CURRENT,
	MTVDECEX_HPORCH_DEFAULT,
	MTVDECEX_HPORCH_MIN,
	MTVDECEX_HPORCH_MAX,
	MTVDECEX_VPORCH_CURRENT,
	MTVDECEX_VPORCH_DEFAULT,
	MTVDECEX_VPORCH_MIN,
	MTVDECEX_VPORCH_MAX
   @param u2Value The porch value
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetDefaultPorch(MTVDO_PATH_T ePath, MTVDECEX_PORCH_TYPE_T ePorchType, UINT16 *pu2Value);

/**
 * Notify driver the start of ATV channel change  
 *
 * @param none
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetChannelChange(VOID);


/**
 * Set enabled color system in ATV  
 *
 * @param u4ColSys
    if bit0 is 1, MTVDECEX_CS_PAL_N is enabled
    if bit1 is 1, MTVDECEX_CS_PAL is enabled
    if bit2 is 1, MTVDECEX_CS_PAL_M is enabled
    if bit3 is 1, MTVDECEX_CS_NTSC358 is enabled
    if bit4 is 1, MTVDECEX_CS_SECAM is enabled
    if bit5 is 1, MTVDECEX_CS_PAL_60 is enabled
    if bit7 is 1, MTVDECEX_CS_NTSC443 is enabled
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetEnabledColorSystem(UINT32 u4ColSys);

/**
 * @Set Videp Present(VPres) OnOff Gain
 * @param u1OffGain If sync is not detected, VPres counter will be decreased by u1OffGain. 
 * @param u1OnGain If sync is detected, VPres counter will be increased by u1OnGain.
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetVPresOnOffGain(UINT8 u1OffGain, UINT8 u1OnGain);

/**
 * @Set sync detection sensitivity for tuning
 * @param fgLowSens True is for lower sensitivity, false is for higher sensitivity
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetSyncDetForTuning(BOOL fgLowSens);

/**
 * @Set H-PLL gain manually
 * @param u1KPGain HPLL KP gain
 * @param u1KIGain HPLL KI gain
 * @param eColSys color system (reserved)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_SetHPLL(UINT8 u1KPGain, UINT8 u1KIGain, MTVDECEX_CS_T eColSys);


/**
 * Get video signal strength
 *
 * @param eType 
 * @param pu1Value
    1. eType = 0 :100 -((_swTVDNRavg1*100)>>7);
    2. eType = 2 : mapping from (20dB ~ 80dB) to (0 ~100)
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetSignalStrengthLevel(UINT8 u1Type, UINT8 *pu1Level);

EXTERN MT_RESULT_T MTVDECEX_HDMI_SetCallBack(MTVDECEX_HDMI_CB hdmiEventCallback);
EXTERN MT_RESULT_T MTVDECEX_HDMI_UnSetCallBack(void);

/**
 * Select TV color system
 *
 * @param eColSys Select the color system. MTVDECEX_CS_AUTO / MTVDECEX_CS_PAL / MTVDECEX_CS_PAL_M
 * / MTVDECEX_CS_PAL_N / MTVDECEX_CS_NTSC358 / MTVDECEX_CS_NTSC443 / MTVDECEX_CS_SECAM
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 * only for CVBS input source.
 */
EXTERN MT_RESULT_T MTVDECEX_SetColorSystem(MTVDECEX_CS_T eColSys);

/**
 * Get Current TV color system
 *
 * @param peColSys Current Color System. MTVDECEX_CS_AUTO / MTVDECEX_CS_PAL / MTVDECEX_CS_PAL_M
 * / MTVDECEX_CS_PAL_N / MTVDECEX_CS_NTSC358 / MTVDECEX_CS_NTSC443 / MTVDECEX_CS_SECAM
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 * only for CVBS input source.
 */
EXTERN MT_RESULT_T MTVDECEX_GetColorSystem(MTVDECEX_CS_T *peColSys);

/**
 * @Get TVD Analog Contents Protect Status
 * @param ePath: video path main or sub       
 * @param pu1Psp: pointer of pseudo sync status       
     0 : no
     1:  yes
 * @param pu1CStripe: pointer of color stripe status       
     0 : no
     1:  yes
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetAnalogCopyProtect(MTVDO_PATH_T ePath, UINT8 *pu1Psp, UINT8 *pu1CStripe);

/**
 * @Get previous stable TVD active width and height, used when no signal      
 * @param pu2Width: pointer of width       
 * @param pu2Height: pointer of height   
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetPreWidthHeight(UINT16 *pu2Width,UINT16 *pu2Height);

EXTERN MT_RESULT_T MTVDECEX_HDMI_GetMhlPortId(UINT8 *u1Port);

#ifdef __cplusplus
}
#endif

#endif //MT_VDECEX_H

