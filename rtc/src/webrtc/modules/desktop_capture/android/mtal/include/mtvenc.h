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
 * $RCSfile: mtvenc.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtvenc.h
 *  This header file declares exported APIs of MTAL Video Encoder (VENC) module,
 *  which inclued H.264(AVC)
 */

#ifndef MT_VENC_H
#define MT_VENC_H

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

#define MTVENC_NULL_HANDLE  ((VOID*)0 )          ///< NULL value of MTVENC_HANDLE

// for buffer manager
#define MTVENC_BUFMGR_WAIT        1              ///< blocking wait buffer
#define MTVENC_BUFMGR_NOWAIT      2              ///< non-blocking wait buffer

#define MTVENC_BUFMGR_OK          0              ///< buffer ok
#define MTVENC_BUFMGR_EMPTY       1              ///< buffer empty
#define MTVENC_BUFMGR_FULL        2              ///< buffer full
#define MTVENC_BUFMGR_INV_ARG     3              ///< buffer invalid argument
#define MTVENC_BUFMGR_FAIL        4              ///< buffer fail

//-----------------------------------------------------------------------------
// Macro definitions
//-----------------------------------------------------------------------------

#define MTVENC_ALIGN_MASK(VAL, MSK) (((VAL) + (MSK)) & (~(MSK))) ///< align mask macro


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** MTVENC_HANDLE
 * handle of MTVENC
 */
typedef VOID * MTVENC_HANDLE;                    ///< MTVENC handle


/** MTVENC_ABILITY_T
 * encoder ability
 * mainly for TVQQ
 */
typedef struct _MTVENC_ABILITY_T
{
    UINT32 u4MaxWidth;                           ///< Max width
    UINT32 u4MaxHeight;                          ///< Max height
    UINT32 u4Ability320;                         ///< Max # of frame to encode 320x240     
    UINT32 u4MaxFps;                             ///< Max framerate
} MTVENC_ABILITY_T;


/** MTVENC_H264_PIC_TYPE
 * h.264 NALU type
 */
typedef enum _MTVENC_H264_PIC_TYPE
{
    MTVENC_H264_PIC_TYPE_SPS = 0x01,             ///< h.264 pic type sps
    MTVENC_H264_PIC_TYPE_PPS = 0x02,             ///< h.264 pic type pps
    MTVENC_H264_PIC_TYPE_SEI = 0x04,             ///< h.264 pic type sei
    MTVENC_H264_PIC_TYPE_IDR = 0x10,             ///< h.264 pic type IDR
    MTVENC_H264_PIC_TYPE_I   = 0x20,             ///< h.264 pic type I
    MTVENC_H264_PIC_TYPE_P   = 0x30,             ///< h.264 pic type P
    MTVENC_H264_PIC_TYPE_B   = 0x40,             ///< h.264 pic type B
    MTVENC_H264_PIC_TYPE_MAX                     ///< h.264 pic type Unknown
} MTVENC_H264_PIC_TYPE;


/** MTVENC_PRAM_T
 * type of parameter
 */
typedef enum _MTVENC_PRAM_T
{
    MTVENC_PRAM_FRAMERATE,                       ///< parameter framerate
    MTVENC_PRAM_BITRATE,                         ///< parameter bitrate
    MTVENC_PRAM_RESOLUTION,                      ///< parameter resolution
    MTVENC_PRAM_PROFILE_LEVEL,
	MTVENC_PRAM_ASPECTRATIOIDC,
    MTVENC_PRAM_MAX                              ///< parameter unknown
} MTVENC_PRAM_T;


/** MTVENC_CTRL_T
 * type of control
 */
typedef enum _MTVENC_CTRL_T
{
    MTVENC_CTRL_SYNC_MODE,                       ///< ctrl sync mode
    MTVENC_CTRL_PIX_FMT,                         ///< ctrl pixel format
    MTVENC_CTRL_GET_THUMBNAIL,                   ///< ctrl get thumbnail
    MTVENC_CTRL_MAX                              ///< ctrl unknown
} MTVENC_CTRL_T;


/** MTVENC_PIX_FMT_T
 * type of pixel format
 */
typedef enum _MTVENC_PIX_FMT_T
{
    MTVENC_PIX_FMT_NV12,                         ///< pixel format NV12, 420 with two planes, the Y plane is first. ex.emulation
    MTVENC_PIX_FMT_MAX                           ///< pixel format unknown
} MTVENC_PIX_FMT_T;


/** MTVENC_SMODE_T
 * for MTVENC_CTRL_SYNC_MODE
 */
typedef enum _MTVENC_SMODE_T
{
    MTVENC_SMODE_SYNC,                           /// sync mode sync, only sync api is work.
    MTVENC_SMODE_ASYNC,                          /// sync mode async, only async api is work.
    MTVENC_SMODE_DUAL,                           /// sync mode dual, both sync api and async api are work.
    MTVENC_SMODE_MAX                             /// sync mode unknown
} MTVENC_SMODE_T;


/** MTVENC_CTRL_PIXFMT_T
 * for MTVENC_CTRL_PIX_FMT
 */
typedef struct _MTVENC_CTRL_PIXFMT_T
{
    MTVENC_PIX_FMT_T ePixFmt;                    ///< pixel format
    UINT32           u4Pitch;                    ///< pitch
} MTVENC_CTRL_PIXFMT_T;


/** MTVENC_CTRL_THUMBNAIL_T
 * for MTVENC_CTRL_GET_THUMBNAIL
 */
typedef struct
{
    UINT32 u4Width;                              ///< thumbnail width
    UINT32 u4Height;                             ///< thumbnail height
} MTVENC_CTRL_THUMBNAIL_T;


/** MTVENC_IN_PIC_T
 * input picture info
 */
typedef struct _MTVENC_IN_PIC_T
{
    UINT32 u4YAddr;                              ///< input luma address
    UINT32 u4CAddr;                              ///< input chroma address
    UINT32 u4Pts;                                ///< input pts
} MTVENC_IN_PIC_T;


/** MTVENC_OUT_PIC_T
 * output coded picture info
 */
typedef struct _MTVENC_OUT_PIC_T
{
    MTVENC_H264_PIC_TYPE eType;                  ///< output picture type
    UINT32               u4Pts;                  ///< output pts
    UINT32               u4Addr;                 ///< output address
    UINT32               u4Size;                 ///< output size
    UINT32               u4RStart;               ///< output buffer start
    UINT32               u4REnd;                 ///< output buffer end
} MTVENC_OUT_PIC_T;


/** MTVENC_NFY_COND_T
 * notification conditions
 */
typedef enum _MTVENC_NFY_COND_T
{
    MTVENC_COND_ERROR    = -2,                   ///< Error
    MTVENC_COND_OVERFLOW = -1,                   ///< Buffer Overflow
    MTVENC_COND_DATA     =  0,                   ///< Buffer Data Available
    MTVENC_COND_THUMBNAIL =  1,                  ///< Thumbnail callback
} MTVENC_NFY_COND_T;


/** mtvenc_nfy_fct
 * prototype of notify function
 */
typedef BOOL (*mtvenc_nfy_fct)(VOID*              pvTag,
                               MTVENC_NFY_COND_T  eNfyCond,
                               UINT32             u4Data );


/** MTVENC_NFY_INFO_T
 * notify info
 */
typedef struct _MTVENC_NFY_INFO_T
{
    VOID*               pvTag;                   ///< tag of notify function
    mtvenc_nfy_fct      pfNfy;                   ///< pointer of notify function
} MTVENC_NFY_INFO_T;

typedef enum MTVENC_STATUS_T
{
    MTVENC_STATUS_UNINIT,
    MTVENC_STATUS_STOP,
    MTVENC_STATUS_WAITSIGNAL,
    MTVENC_STATUS_START, 
    MTVENC_STATUS_RUN
} MTVENC_STATUS_T;
/** callback structure
 */
typedef struct _MTVENC_CB_T
{
    MTVENC_NFY_COND_T eCond;                     ///< notify condition
    union
    {
        MTVENC_OUT_PIC_T tOut;                   ///< output picture
        UINT32 u4ThumbnailPhyAddr;               ///< thumbnail addresss
    }u;                                          ///< union alias
    MTVENC_STATUS_T tStatus;
} MTVENC_CB_T;

#if 1 // mwif over mtal support

/** MTVENC_COMP_ID_T
 * VENC Component ID
 */
typedef enum _MTVENC_COMP_ID_T
{
    MTVENC_COMP_1,                               ///< COMP_1
    MTVENC_COMP_NS                               ///< COMP_NS
} MTVENC_COMP_ID_T;


/** MTVENC_SET_TYPE_T
 * set type
 */
typedef enum _MTVENC_SET_TYPE_T
{
    MTVENC_SET_TYPE_CONNECT_SRC,                 ///< set connect
    MTVENC_SET_TYPE_DISCONNECT_SRC,              ///< set disconnect
    MTVENC_SET_TYPE_CTRL,                        ///< set ctrl
    MTVENC_SET_TYPE_SETTINGS,                    ///< set settings
    MTVENC_SET_TYPE_FRAME_RESOLUTION,            ///< set resolution
    MTVENC_SET_TYPE_FRAME_RATE,                  ///< set framerate
    MTVENC_SET_TYPE_BITRATE,                     ///< set bitrate
    /*MTVENC_SET_TYPE_PROFILE,                   ///< set profile
    MTVENC_SET_TYPE_LEVEL,*/                     ///< set level
    MTVENC_SET_TYPE_APP_TYPE,                    ///< set ap type
    MTVENC_SET_TYPE_RESTART,                     ///< set restart
    MTVENC_SET_TYPE_INSERT_KEYFRAME,             ///< set insert keyframe
    MTVENC_SET_TYPE_ENCODE_OSD,                  ///< set encode osd
    MTVENC_SET_TYPE_MSI_OSTG,                    ///< set encode Output Stage
    MTVENC_SET_TYPE_ENC_FLD,                 ///< set encode Fld
    MTVENC_SET_TYPE_ENC_INPUT,                   ///< set encode monitor out input mux
    MTVENC_SET_TYPE_ENC_MODULE,
} MTVENC_SET_TYPE_T;

/** MTVENC_SRC_TYPE_T
 * source type
 */
typedef enum
{
    MTVENC_ENC_BOTH_FLD = 0,                   ///< encode top and bottom
    MTVENC_ENC_TOP_FLD,                        ///< encode top field
    MTVENC_ENC_BOTTOM_FLD,                     ///< encode bottom field
    MTVENC_ENC_DINTERLACE,                     /// < encoder p timing
    MTVENC_ENC_PROGRESSIVE,                     /// < encoder p timing
} MTVENC_ENC_FLD_TYPE_T;

/** MTVENC_SRC_TYPE_T
 *  set the record input point
 */
typedef enum
{
    MTVENC_ENC_MIXER =  0,
    MTVENC_ENC_MAIN_FSC_OUT,                   ///< encoder before MAIN scaler
    MTVENC_ENC_SUB_FSC_OUT,                    ///< encoder before SUB scaler
    MTVENC_ENC_MAIN_MIB_OUT,                   ///< encoder before MAIN  DI
    MTVENC_ENC_SUB_MIB_OUT,                    ///< encoder before SUB DI
    MTVENC_ENC_MAIN_BEFORE_PRED,               ///< encoder before MAIN predown
    MTVENC_ENC_SUB_BEFORE_PRED,                ///< encoder before SUB predown
    MTVENC_ENC_OSTG     ,                      ///< encode output stage
    MTVENC_ENC_OSTG_OSD    ,                   ///< encode output stage + OSD
    MTVENC_ENC_NOT_SELECTED,                   ///< encode input is not selected
}MTVENC_ENC_INPUT;

/** MTVENC_SRC_TYPE_T
 *  set the recording module
 */
typedef enum
{
    MTVENC_ENC_MAIN_SCALER = 0,                    ///< using main scaler to encode
    MTVENC_ENC_SUB_SCALER  = 1,                    ///< using sub scaler to encode
    MTVENC_ENC_MONITOR_OUT = 2,                    ///< using Monitor out to encode
    MTVENC_ENC_SUB_DI      = 3,                    ///< using sub DI to encode
} MTVENC_ENC_VDP_MODULE;

/** MTVENC_GET_TYPE_T
 * get type
 */
typedef enum _MTVENC_GET_TYPE_T
{
    MTVENC_GET_TYPE_CTRL,
	MTVENC_GET_TYPE_VENCBUF,
    MTVENC_GET_TYPE_SIGNALREADY,
    MTVENC_GET_TYPE_FRAMERATE,
    MTVENC_GET_TYPE_WIDTH,
    MTVENC_GET_TYPE_HEIGHT,
    MTVENC_GET_TYPE_NUM
} MTVENC_GET_TYPE_T;


/** MTVENC_SRC_TYPE_T
 * source type
 */
typedef enum
{
    MTVENC_SRC_TYPE_UNKNOWN = 0,                 ///< source unknown
    MTVENC_SRC_TYPE_VDEC,                        ///< source vdec
    MTVENC_SRC_TYPE_VDP                          ///< source vdp
} MTVENC_SRC_TYPE_T;


/*for MTVENC_SET_TYPE_APP_TYPE*/
typedef enum _MTVENC_AP_TYPE_T
{
    MTVENC_AP_TYPE_UNKNOWN = 0,
    MTVENC_AP_TYPE_SKYPE,
    MTVENC_AP_TYPE_ATVPVR,
    MTVENC_AP_TYPE_BGPVR,
    MTVENC_AP_TYPE_MSI, // multi-screen interaction
    MTVENC_AP_TYPE_QQ,
    MTVENC_AP_TYPE_CUST
} MTVENC_AP_TYPE_T;
typedef enum _MTVENC_FMT_TYPE_T
{
    MTVENC_FMT_UNKNOWN = 0,
    MTVENC_FMT_H264
    /* Others */
} MTVENC_FMT_TYPE_T;
#if 0
/** MTVENC_PROFILE_T
 * profile
 */
typedef enum
{
    /* H264 */
    MTVENC_H264_PROFILE_BASELINE = 0,            ///< h.264 baseline profile
    MTVENC_H264_PROFILE_MAIN                     ///< h.264 main profile
    /* Others */
} MTVENC_PROFILE_T;


/** MTVENC_LEVEL_T
 * level
 */
typedef enum
{
    /* H264 */
    MTVENC_H264_LEVEL_21 = 0,                    ///< level 2.1
    MTVENC_H264_LEVEL_31,                        ///< level 3.1
    MTVENC_H264_LEVEL_41                         ///< level 4.1
    /* Others */
} MTVENC_LEVEL_T;
#endif

typedef enum
{
    MTVENC_PROFILE_BASE = 0,
    MTVENC_PROFILE_MAIN,
    MTVENC_PROFILE_EXT,
    MTVENC_PROFILE_HIGH
    /* Others */
} MTVENC_PROFILE_T;

typedef enum
{
    /* H264 */
    MTVENC_PORFILELEVEL_30 = 0,
    MTVENC_PORFILELEVEL_31,
    MTVENC_PORFILELEVEL_40,
    MTVENC_PORFILELEVEL_41
    /* Others */
} MTVENC_LEVEL_T;
/* for MTVENC_SET_TYPE_FRAME_RESOLUTION */
typedef struct _MTVENC_FRAME_RESOLUTION_T
{
    UINT32              u4Width;      /* Resolution: Width */
    UINT32              u4Height;     /* Resolution: Height */
} MTVENC_FRAME_RESOLUTION_T;


typedef struct _MTVENC_COMMON_INFO_T
{
    MTVENC_FRAME_RESOLUTION_T  tResolution;      ///< Resolution
    UINT32                     u4Fps;            ///< Frame Rate
    UINT32                     u4Bps;            ///< Bitrate
} MTVENC_COMMON_INFO_T;


/** MTVENC_H264_INFO_T
 * h.264 info
 */
typedef struct _MTVENC_H264_INFO_T
{
    MTVENC_COMMON_INFO_T  tCmmInfo;              ///< common info
/*    MTVENC_PROFILE_T      e_profile;
    MTVENC_LEVEL_T        e_level;*/
} MTVENC_H264_INFO_T;

typedef struct 
{
   long msgType;
   MTVENC_CB_T rMsgInfo;
}VENC_MSG,*PVENC_MSG;

typedef struct _MTVENC_PROFILE_LEVEL_T
{
    MTVENC_PROFILE_T      e_profile;
    MTVENC_LEVEL_T        e_level;
} MTVENC_PROFILE_LEVEL_T;

typedef struct _MTVENC_SETTINGS_T
{
    MTVENC_SRC_TYPE_T       eSrcType;            ///< Source Type
    MTVENC_FMT_TYPE_T       eEncFmt;             ///< Encode Format Type
    union
    {
        MTVENC_H264_INFO_T  tFmtH264;            ///< fmt h.264
    }uFmt;                                       ///< Encoding Setting according to eEncFmt
} MTVENC_SETTINGS_T;
#endif // mwif over mtal support

typedef struct _MTVENC_SAR_INFO_T
{
    UINT32 u4SarIdc;
    UINT32 u4SarWidth;
    UINT32 u4SarHeight;
} MTVENC_SAR_INFO_T;

typedef struct _MTVENC_OUTVIDEO_INFO_T
{
    MTVENC_AP_TYPE_T eProfile;
    MTVENC_FMT_TYPE_T encFmt; 
    BOOL                   fgInterlace;     /**< interlace or progress mode */
    BOOL                   fgAddAud;
    MTVENC_COMMON_INFO_T tCommonInfo; /*Resolution, Frame rate,bit rate*/
    MTVENC_SRC_TYPE_T srcType;
    MTVENC_PROFILE_LEVEL_T tProfileLevel;
    MTVENC_SAR_INFO_T tSarInfo;
}MTVENC_OUTVIDEO_INFO_T;
/** MTVENC_VDP_INFO_T
 *  set the vdp setting information
 */
typedef struct _MTVENC_VDP_INFO_T
{
    MTVENC_ENC_INPUT         eEncInput;
    MTVENC_ENC_FLD_TYPE_T    eEncFldType; 
    MTVENC_ENC_VDP_MODULE    eEncModule;
    UINT8                    u1SetSubPath;
    UINT32                   u4EncInWidth;
    UINT32                   u4EncInHeight;
}MTVENC_VDP_INFO_T;



typedef struct _VIDEO_INFO {
    UINT16            width;
    UINT16            height;
    UINT16            frame_rate;   // fps    
    UINT16            AcrPath;
    UINT8          fgInterlace;
	UINT8             u1Drop_N_M;
	UINT8          u1Reserve_0;
	UINT8          u1Reserve_1;
} VIDEO_INFO;


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**
 * Map physical address to user virtual address.
 * @param[in]  u4Addr physical address.
 * @param[in]  u4Size size to map.
 * @return user virtual address of u4Addr
 */
EXTERN UINT8 * MTVENC_Phy2Virt(UINT32 u4Addr, UINT32 u4Size);

/**
 * Initial MTVENC.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Init(VOID);

EXTERN MT_RESULT_T MTVENC_Init_v(VOID);


/**
 * Terminate MTVENC.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Termint(VOID);

/**
 * Reset MTVENC of component u2CompId.
 * @param[in]  u2CompId The component ID.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Reset(UINT16 u2CompId);

/**
 * Wrapper of _VEncMwSet.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eSetType set type.
 * @param[in]  pvData pointer to set data.
 * @param[in]  u4Size size of set data.
 * @return MT_RESULT_T The set results
 */

EXTERN MT_RESULT_T MTVENC_Set(
                                    UINT16             u2CompId,
                                    MTVENC_SET_TYPE_T  eSetType,
                                    const VOID*        pvData,
                                    UINT32             u4Size );

/**
 * Wrapper of MTVENC_SetEx.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eSetType set type.
 * @param[in]  pvData pointer to set data.
 * @param[in]  u4Size size of set data.
 * @return MT_RESULT_T The set results
 */

EXTERN MTVENC_HANDLE MTVENC_SetEx(
                                    UINT16             u2CompId,
                                    MTVENC_SET_TYPE_T  eSetType,
                                    const VOID*        pvData,
                                    UINT32             u4Size );


/**
 * Wrapper of _VEncMwGet.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eGetType get type.
 * @param[out] pvData pointer to get data.
 * @param[out] pu4Size size of get data.
 * @return MT_RESULT_T The get results
 */
EXTERN  MT_RESULT_T MTVENC_Get(
                                    UINT16              u2CompId,
                                    MTVENC_GET_TYPE_T   eGetType,
                                    VOID*               pvData,
                                    UINT32*             pu4Size );

/**
 * Get MTVENC handle.
 * @param[out] phVenc pointer of MTVENC handle.
 * @param[in]  eEncFmt encode format.
 * @param[in]  eProfile application profile.
 * @param[in]  fgInterlace interlace flag.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Open(
                                    MTVENC_HANDLE*    phVenc,
                                    MTVENC_FMT_TYPE_T eEncFmt,
                                    MTVENC_AP_TYPE_T  eProfile,
                                    BOOL              fgInterlace);

/**
 * Set MTVENC parameter.
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  u4Type set type.
 * @param[in]  pvArg pointer of set data.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_SetParam(
                                    MTVENC_HANDLE hEnc,
                                    UINT32 u4Type,
                                    VOID *pvArg);

/**
 * Set MTVENC control.
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  u4Type set type.
 * @param[in]  pvArg pointer of set data.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_SetCtrl(
                                    MTVENC_HANDLE hEnc,
                                    UINT32 u4Type,
                                    VOID *pvArg);

/**
 * Initial VENC driver.
 * @param[in]  hEnc MTVENC handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_DrvInit(MTVENC_HANDLE hEnc);

/**
 * start VENC driver.
 * @param[in]  hEnc MTVENC handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Run(MTVENC_HANDLE hEnc);

/**
 * stop VENC driver.
 * @param[in]  hEnc MTVENC handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Stop(MTVENC_HANDLE hEnc);

/**
 * release MTVENC handle.
 * @param[in]  hEnc MTVENC handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_Close(MTVENC_HANDLE hEnc);

/**
 * synchronously encode a frame.
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  ptIn info of input frame.
 * @param[out] ptOut info of output coded picture.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_EncFrameSync(
                                    MTVENC_HANDLE hEnc,
                                    MTVENC_IN_PIC_T *ptIn,
                                    MTVENC_OUT_PIC_T *ptOut);

/**
 * Asynchronously encode a frame.
 * encode result will notify through function pointer set by MTVENC_RegCb
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  ptIn info of input frame.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_EncFrameAsync(
                                    MTVENC_HANDLE hEnc,
                                    MTVENC_IN_PIC_T *ptIn);

/**
 * Get encoder ability
 * @param[in]  ptAbility pointer to ability.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_GetAbility(MTVENC_ABILITY_T *ptAbility);

/**
 * Get handle of buffer manager
 * which used to get frame buffer from kernel
 * @param[in]  hEnc MTVENC handle.
 * @param[out] phFrmBuffMgr pointer to buffer manager handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_CreateBuffMgr(
                                    MTVENC_HANDLE hEnc,
                                    MTVENC_HANDLE *phFrmBuffMgr);

/**
 * Release handle of buffer manager
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  hFrmBuffMgr buffer manager handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_DeleteBuffMgr(
                                    MTVENC_HANDLE hEnc,
                                    MTVENC_HANDLE hFrmBuffMgr);

/**
 * get frame buffer from buffer manager
 * @param[in]  hFrmBuffMgr buffer manager handle.
 * @param[in]  ptData pointer to buffer data.
 * @param[in]  u4Option the way to get buffer.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_BUFMGR_OBJ_Get(
                                    MTVENC_HANDLE hFrmBuffMgr,
                                    MTVENC_IN_PIC_T *ptData,
                                    UINT32 u4Option);

/**
 * release frame buffer to buffer manager
 * @param[in]  hFrmBuffMgr buffer manager handle.
 * @param[in]  ptData pointer to buffer data.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_BUFMGR_OBJ_Free(
                                    MTVENC_HANDLE hFrmBuffMgr,
                                    MTVENC_IN_PIC_T *ptData);

/**
 * flush cache of the range of frame buffer
 * @param[in]  u4YAddr address of luma buffer.
 * @param[in]  u4CAddr address of chroma buffer.
 * @param[in]  u4FrmSz size of frame buffer.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_FlushFb(
                                    UINT32 u4YAddr,
                                    UINT32 u4CAddr,
                                    UINT32 u4FrmSz);

/**
 * Insert a keyframe.
 * @param[in]  hEnc MTVENC handle.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_InsertKeyframe(MTVENC_HANDLE hEnc);

/**
 * register notify function
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  NfyInfo pointer of notify info.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_RegCb(
                                    MTVENC_HANDLE hEnc,
                                    MTVENC_NFY_INFO_T *NfyInfo);

/**
 * release output coded picture buffer
 * @param[in]  hEnc MTVENC handle.
 * @param[in]  u4Addr pointer of output coded picture buffer.
 * @param[in]  u4Size size of output coded picture buffer.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTVENC_UnlockBuf(
                                    MTVENC_HANDLE hEnc,
                                    UINT32 u4Addr,
                                    UINT32 u4Size);

MT_RESULT_T MTVENC_CopyData(UINT8 uPort,UINT32 u4FromAddr,
    UINT32 u4ToAddr,UINT32 u4Size,
    UINT32 u4StartAddr,
    UINT32 u4EndAddr);


#ifdef __cplusplus
}
#endif

#endif //MT_VENC_H

