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
 * $RCSfile: mtb2r.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtb2r.h
 *  This header file declares exported APIs of B2R (Block to Raster) module.
 */

#ifndef MT_B2R_H
#define MT_B2R_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
#include "mtstc.h"
#include "mtvdec.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

#define MTB2R_DEVICE_NODE              "/dev/b2r"

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
#define MTB2R_SEEK_STEP_OK              0
#define MTB2R_SEEK_STEP_NO_DATA         1

#define MTB2R_B2R_NS                    2           ///< B2R NS
#define MTB2R_B2R_1                     0           ///< B2R1
#define MTB2R_B2R_2                     1           ///< B2R2
#define MTB2R_B2R_INVALID               0xFF        ///< B2R invalid id

#define MTB2R_VDP_1                     0    	    ///< VDP1
#define MTB2R_VDP_2                     1    	    ///< VDP2
#define MTB2R_VDP_3                     2    	    ///< OSD1, obsolete
#define MTB2R_VDP_4                     3    	    ///< OSD2, obsolete
#define MTB2R_VDP_5                     4    	    ///< OSD3, obsolete

#define MTB2R_PLAY_NORMAL               0           ///< Normal Play
#define MTB2R_PLAY_TRICK                1           ///< Trick Play
#define MTB2R_PLAY_STEP_FORWARD         2           ///< Step Forward
#define MTB2R_PLAY_SLOW_FORWARD         3           ///< Slow Forward

#define MTB2R_SET_DISP_SYNC             (1 << 0)    ///< Synchronous display
#define MTB2R_MULTI_VIEW                (1 << 1)    ///< multi view mode for 3D

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** B2R notify condition for multimedia playback
 */
typedef enum
{
    MTB2R_COND_ERROR = -1,          ///< Notify error happened
    MTB2R_COND_EOS,                 ///< Notify EOS reached
    MTB2R_COND_SYNC_POINT,          ///< Notify sync point reached
    MTB2R_COND_RANGE_AB_DONE,       ///< Notify AB repeat done
} MTB2R_COND_T;

/** B2R color mode
 */
typedef enum
{
    MTB2R_CM_420 = 0,               ///< 420
    MTB2R_CM_422,                   ///< 422
    MTB2R_CM_444,                   ///< 444
    MTB2R_CM_ARGB8888,              ///< ARGB888
    MTB2R_CM_MAX                    ///< Max boundary
} MTB2R_DISPLAY_FORMAT_T;

/** B2R address mode
 */
typedef enum
{
    MTB2R_BLOCK1_MODE = 0,          ///< Block 1 ordered
    MTB2R_BLOCK4_MODE,              ///< Block 4 ordered
    MTB2R_RASTER_MODE,              ///< Raster ordered
    MTB2R_ADDR_MODE_MAX             ///< Max boundary
} MTB2R_ADDR_MODE_T;

/** FBG play mode
 */
typedef enum
{
    MTB2R_FBG_DTV_MODE =0,          ///< DTV
    MTB2R_FBG_MM_MODE,              ///< MM
    MTB2R_FBG_MODE_NS               ///< Max boundary
} MTB2R_FBG_MODE_T;

/**B2R call back function type id.
*/
typedef enum
{
    MTB2R_CB_FUNC_TRIG_AUD_TO_PLAY,
    MTB2R_CB_FUNC_EOS,
    MTB2R_CB_FUNC_NS
}MTB2R_CB_FUNC_ENUM_T;

typedef struct _MTB2R_CB_AUD_TRIG_DATA_T
{
    VOID*   pfFunc;
} MTB2R_CB_AUD_TRIG_DATA_T;

typedef struct _MTB2R_CB_EOS_DATA_T
{
    VOID*   pv_tag;
} MTB2R_CB_EOS_DATA_T;

typedef struct _MTB2R_CB_INFO_T
{
    union
    {
        MTB2R_CB_AUD_TRIG_DATA_T t_aud_trig_data;
        MTB2R_CB_EOS_DATA_T t_eos_data;
    }u;
} MTB2R_CB_INFO_T;

typedef struct _MTB2R_REG_CB_OBJ_T
{
    VOID*           pfCb;
    MTB2R_CB_INFO_T rCbInfo;
} MTB2R_REG_CB_OBJ_T;

/** B2R position information
 */
typedef struct
{
    UINT64 u8PtsI;                  ///< PTS of last I frame
    UINT64 u8Pts;                   ///< Video PTS
    UINT64 u8Stc;                   ///< STC
    UINT64 u8AudPts;                ///< Audio PTS
    UINT64 u8AudOffset;             ///< Data offset of audio
    UINT64 u8OffsetI;               ///< Data offset of last video I frame 
    UINT64 u8Offset;                ///< Data offset of video
    UINT64 u8OffsetDisp;
    INT32  i4TemporalRef;           ///< Temporal reference number
    UINT32 u4Timestap;
    UINT16 u2DecodingOrder;         ///< Decodeing order or display order
} MTB2R_POS_INFO_T;

/** B2R picture information for MM
 */
typedef struct
{
    UCHAR ucHours;                  ///< Hours (in MPEG2 GOP header)
    UCHAR ucMinutes;                ///< Minutes (in MPEG2 GOP header)
    UCHAR ucSeconds;                ///< Seconds (in MPEG2 GOP header)
    UCHAR ucPictures;               ///< Picture number (in MPEG2 GOP header)
    UINT32 u4Pts;                   ///< PTS of current display frame
    UINT32 u4TotlaTimeOffset;
    UINT32 u4TickNum;               ///< Tick number
    UINT64 u8Offset;                ///< File offset
    UINT64 u8OffsetDisp;            ///< File offset for display
} MTB2R_PIC_INFO_T;

/** B2R AB position information
 */
typedef struct
{
    BOOL fgValid;                   ///< Enable AB position info
    BOOL fgPosition;                ///< Use position or pts
    MTB2R_POS_INFO_T rA;            ///< A position info
    MTB2R_POS_INFO_T rB;            ///< B position info
} MTB2R_AB_INFO_T;

/** B2R video capture picture information
 */
typedef struct
{
    BOOL    fgUFOOn;
    UINT32 u4UFOType;
    UINT32 u4AddrY;                 ///< Start address of Luma data
    UINT32 u4AddrC;                 ///< Start address of Chroma data
    UINT32 u4AddrYLen;
    UINT32 u4AddrCLen;
    UINT32 u4DstY;
    UINT32 u4DstC;   
    UINT32 u4MemHSize;              ///< Frame buffer width (according to color mode)
    UINT32 u4MemVSize;              ///< Frame buffer height (according to color mode)
    UINT32 u4HSize;                 ///< Video width
    UINT32 u4VSize;                 ///< Video height
    UINT32 u4RRMode;                ///< Reduce reference mode
    UINT32 u4IsRsIn;                ///< Is raster ordered or block ordered
    UINT32 u4SrcSwap;  
} MTB2R_CAPTURE_INFO_T;

/** B2R picture header information
 */
typedef struct
{  
    UINT8 u1FbgId;                  ///< FBG id in FBM
    UINT8 u1FbId;                   ///< FB id in FBM
    UINT32 u4YAddr;                 ///< Start address of luma
    UINT32 u4CAddr;                 ///< Start address of chroma
    UINT32 u4YAddrOffset;           ///< Start address (offset format) of luma
    UINT32 u4CAddrOffset;           ///< Start address (offset format) of chroma
    UINT32 u4Pts;                   ///< Frame pts
    UINT32 u4Flag;                  ///< Property
    UINT8 u1FbgIdR;
    UINT8 u1FbIdR;
} MTB2R_PIC_HDR_T;

/** B2R sequence header information
 */
typedef struct
{
    UINT32 u4FrameWidth;            ///< Video width
    UINT32 u4FrameHeight;           ///< Video height
    UINT32 u4LineSize;              ///< Video line size (pitch)
    BOOL fgProgressiveSeq;          ///< Progressive or interlace
    MTVDEC_FRAME_RATE_T eFrameRate; ///< Frame rate
    MTB2R_ADDR_MODE_T eAddrMode;    ///< Address mode
} MTB2R_SEQ_HDR_T;
//#ifdef CC_B2R_RM_SUPPORT
/* B2R rm*/
typedef enum
{
    MTB2R_RM_ALLOC_OK,     ///< B2R RM alloc HW OK
    MTB2R_RM_ALLOC_NG,     ///< B2R RM alloc HW Fail
    MTB2R_RM_ALLOC_CFT,    ///< B2R RM alloc HW conflict
    MTB2R_RM_UNKNOWN  ,    ///< B2R MSG Unknown
}MTB2R_RM_COND_T;

typedef struct
{
    unsigned char u1ConflictVdpId;
    unsigned char u1CurrentVdpId;
    MTB2R_RM_COND_T eCond;
    
}MTB2R_RM_CB_T;

typedef struct _MTB2R_TRIG_AUD_INFO_T
{
    BOOL    b_aud_auto_en;
    UINT32  u4AdecId;
} MTB2R_TRIG_AUD_INFO_T;

typedef struct _MTB2R_TRIG_AUD_CFG_T
{
    BOOL    fgEnable;
    UINT32  u4Pts;
    MTB2R_TRIG_AUD_INFO_T  rAudInfo;
    VOID*                  prTrgAudCbInfo;
} MTB2R_TRIG_AUD_CFG_T;

/**B2R callback structure
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
}MTB2R_CB_T;

#define VDP_ID_0     0             ///< VDP Instance ID 0
#define VDP_ID_1     1             ///< VDP Instance ID 1
//#define VDP_ID_2     2             ///< VDP Instance ID 1
//#define VDP_ID_3     3             ///< VDP Instance ID 1
#define MTVDP_ID_MAX   2      ///< Maximum VDP Instnace


typedef VOID (*MTB2R_PFN_RM_CB)
(
    UCHAR ucCurrentVdpId, MTB2R_RM_COND_T eCond,UCHAR ucConflictVdpId
);
EXTERN MT_RESULT_T MTB2R_Set_Kickdone(UCHAR ucvdpId,BOOL fgSuccess);
EXTERN MT_RESULT_T MTB2R_RM_Cb_Init(void);
EXTERN MT_RESULT_T MTB2R_RegRmCb(MTB2R_PFN_RM_CB pfRmCb);

//#endif
/** B2R display frame message
 */
typedef struct
{
    UINT32 u4VdpId;                 ///< Vdp id
    UINT32 u4Flag;                  ///< Property flag
} MTB2R_CHG_FRAME_MSG;

/** Get PTS of current display frame
 *@param ucVdpId                    Vdp Id
 *@param pu4PtsValue                Returned PTS value (90K based)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetPts(UCHAR ucVdpId,UINT32* pu4PtsValue);

/** Get B2R step forward status
 *@param ucVdpId                    Vdp Id
 *@param pu1StepFroward             Returned step forward (MTB2R_PLAY_NORMAL, MTB2R_PLAY_TRICK, MTB2R_PLAY_STEP_FORWARD, MTB2R_PLAY_SLOW_FORWARD)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetStepForward(UCHAR ucVdpId,UINT8* pu1StepFroward);

/** Get video position info currently displaying
 *@param ucVdpId                    Vdp Id
 *@param prPosInfo                  Returned position info structure
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetPosInfo(UCHAR ucVdpId,MTB2R_POS_INFO_T* prPosInfo);

/** Get video picture info currently displaying
 *@param ucVdpId                    Vdp Id
 *@param prPicInfo                  Returned picture info structure
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetPicInfo(UCHAR ucVdpId,MTB2R_PIC_INFO_T* prPicInfo);      

/** Get play mode
 *@param ucVdpId                    Vdp Id
 *@param pu1PlayMode                Returned play mode (0 for DTV, 1 for MM, 2 for NotDisplaying, 3 for NS)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetPlayMode(UCHAR ucVdpId,UINT8* pu1PlayMode);  

/** Get B2R slow forward status
 *@param ucVdpId                    Vdp Id
 *@param pu1SlowForward             Returned slow forward (MTB2R_PLAY_NORMAL, MTB2R_PLAY_TRICK, MTB2R_PLAY_STEP_FORWARD, MTB2R_PLAY_SLOW_FORWARD)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetSlowForward(UCHAR ucVdpId,UINT8* pu1SlowForward);

/** Set AB repeat information
 *@param ucVdpId                    Vdp Id
 *@param prABInfo                   AB position information to be set
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetABInfo(UCHAR ucVdpId,MTB2R_AB_INFO_T* prABInfo);

/** Set thumbnail mode to B2R
 *@param ucVdpId                    Vdp Id
 *@param fgThumbnailMode            Enable/disable thumbnail mode (TRUE for enable, FALSE for disable)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetThumbnailMode(UCHAR ucVdpId,BOOL fgThumbnailMode);

/** Set seeking operation to B2R
 *@param ucVdpId                    Vdp Id
 *@param fgSet                      Set/unset (TRUE for set, FALSE for unset)
 *@param u4Pts                      Seek PTS
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetSeek(UCHAR ucVdpId,BOOL fgSet,UINT32 u4Pts);

/** Set MM playback pause to B2R
 *@param ucVdpId                    Vdp Id
 *@param fgPause                    Enable/disable pause (TRUE for enable, FALSE for disable)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetPauseMM(UCHAR ucVdpId,BOOL fgPause);        

/** Set B2R step forward
 *@param ucVdpId                    Vdp Id
 *@param u1StepForward              Step forward (MTB2R_PLAY_NORMAL, MTB2R_PLAY_TRICK, MTB2R_PLAY_STEP_FORWARD, MTB2R_PLAY_SLOW_FORWARD)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetStepForward(UCHAR ucVdpId,UINT8 u1StepForward);

/** Set no timeout when VDEC query empty frame buffer
 *@param ucVdpId                    Vdp Id
 *@param fgFBNoTimeout              Enable/disable no timeout (TRUE for enable, FALSE for disable)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetFBNoTimeout(UCHAR ucVdpId,BOOL fgFBNoTimeout);

/** Set trick mode speed to B2R
 *@param ucVdpId                    Vdp Id
 *@param eSpeed                     Speed (Refer to enum MTSTC_SPEED_TYPE_T)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetSpeed(UCHAR ucVdpId,MTSTC_SPEED_TYPE_T eSpeed);

/** Set trick mode enable/disable to B2R
 *@param ucVdpId                    Vdp Id
 *@param fgTrickMode                Enable/disable trick mode (TRUE for enable, FALSE for disable)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetTrickMode(UCHAR ucVdpId,BOOL fgTrickMode);

/** Set trick mode enable/disable to B2R
 *@param ucVdpId                    Vdp Id
 *@param ucEsId                     EsId (VDEC id)
 *@param ucPort                     Port number of Vdp
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetInput(UCHAR ucVdpId,UCHAR ucEsId,UCHAR ucPort);

/** Set B2R slow forward
 *@param ucVdpId                    Vdp Id
 *@param fgSlowForward              Slow forward (MTB2R_PLAY_NORMAL, MTB2R_PLAY_TRICK, MTB2R_PLAY_STEP_FORWARD, MTB2R_PLAY_SLOW_FORWARD)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetSlowForward(UCHAR ucVdpId,BOOL fgSlowForward);

/** Set attached swdmx id to B2R, it is used when special callback happened
 *@param ucVdpId                    Vdp Id
 *@param u1SrcId                    Swdmx id
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetCbAttachedSrcId(UCHAR ucVdpId,UINT8 u1SrcId);

/** Get locked frame buffer information (currently displaying)
 *@param ucVdpId                    Vdp Id
 *@param prCaptureInfo              Returned capture information, including buffer address
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetLockFrameBufferAddr(UCHAR ucVdpId,MTB2R_CAPTURE_INFO_T* prCaptureInfo);



EXTERN MT_RESULT_T MTB2R_SetGameMode(UCHAR ucVdpId,UINT8 pu1GameMode);

/** Create virtual fbg
 *@param pu1FbgId                   Returned virtual fbg id
 *@param u1EsId                     Input EsId
 *@param u4FrameWidth               Video frame width
 *@param u4FrameHeight              Video frame height
 *@param eFrameFormat               Video color format
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SelectGroupType(UINT8* pu1FbgId,UINT8 u1EsId,UINT32 u4FrameWidth,UINT32 u4FrameHeight,MTB2R_DISPLAY_FORMAT_T eFrameFormat);

/** Set sequence header to the virtual fbg
 *@param u1FbgId                    Virtual fbg id
 *@param prFrameHdrInfo             Sequence header structure to be set
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetSeqHdr(UINT8 u1FbgId,MTB2R_SEQ_HDR_T* prFrameHdrInfo);

/** Get an empty frame buffer from virtual fbg
 *@param u1FbgId                    Virtual fbg id
 *@param prFrameInfo                Returned frame info that represent the empty buffer
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetEmptyFrameBuffer(UINT8 u1FbgId,MTB2R_PIC_HDR_T* prFrameInfo);

/** Set a frame buffer to display
 *@param u1FbgId                    Virtual fbg id
 *@param prFrameInfo                The frame info that represent the display buffer
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetDisplayFrame(UINT8 u1FbgId,MTB2R_PIC_HDR_T* prFrameInfo);

/** Flush frame buffers that are queued for display
 *@param u1FbgId                    Virtual fbg id
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_FlushFrame(UINT8 u1FbgId);

/** Release the virtual fbg
 *@param u1FbgId                    Virtual fbg id
 *@param u1EsId                     Input EsId
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_ReleaseFbg(UINT8 u1FbgId,UINT8 u1EsId);

/** Release the frame buffer
 *@param u1FbgId                    Virtual fbg id
 *@param prFrameInfo                The frame info that represent the release buffer
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_FreeFrameBuffer(UINT8 u1FbgId,MTB2R_PIC_HDR_T* prFrameInfo);

/** Get display driver is stable or not
 *@param ucVdpId                    Vdp Id
 *@param pu1DispStable              Returned driver stable information (0 for not stable, non-0 for stable)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetDispDrvStable(UCHAR ucVdpId,UINT8* pu1DispStable);
EXTERN MT_RESULT_T MTB2R_SetSyncMode2(UINT8 ucStcId, UINT8 ucAdecId, UINT8 ucAdec2Id, UINT8 ucVdecId, UINT32 u4SyncMode);
EXTERN MT_RESULT_T MTB2R_SetMirror(UCHAR ucVdpId, BOOL fgOn); 
EXTERN MT_RESULT_T MTB2R_Init(VOID);

EXTERN MT_RESULT_T MTB2R_AudTriggerMonitor(UCHAR ucVdpId, MTB2R_TRIG_AUD_CFG_T* prAud_trigger);

EXTERN MT_RESULT_T MTB2R_RegCbFunc(MTB2R_CB_FUNC_ENUM_T eFuncType, MTB2R_REG_CB_OBJ_T* prCbObj);

#ifdef __cplusplus
}
#endif

#endif //MT_B2R_H

