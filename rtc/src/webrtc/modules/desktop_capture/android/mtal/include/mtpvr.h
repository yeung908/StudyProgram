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
 * $RCSfile: mtpvr.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtpvr.h
 *  This header file declares exported APIs of PVR module.
 */

#ifndef MT_PVR_H
#define MT_PVR_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
#include "mtdmx.h"
   
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

#define MTPVR_THUMBOUTOFST    (0)          ///<pvr thumbnail offset
#define MTPVR_THUMBOUTSIZE     (256*1024)  ///<pvr thumbnail size
#define MTPVR_THUMBWORKOFST   (MTPVR_THUMBOUTOFST + MTPVR_THUMBOUTSIZE)   ///<pvr thumbnail working buffer offset
#define MTPVR_THUMBWORKSIZE   (256*1024)   ///<pvr thumbnail working buffer size
#define MTPVR_PVRDATAOFST     (MTPVR_THUMBWORKOFST + MTPVR_THUMBWORKSIZE)   ///<pvr thumbnail data offset
#define MTPVR_PVRDATASIZE     (2256*1024)   ///<pvr thumbnail buffer size 2.25 MB currently

#define MTPVR_THUMBNAIL_PID_INDEX       (MTDMX_NUM_PID_INDEX - 1)
//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

typedef struct 
{
    UINT32 u4Width;       ///<thumbnail width
    UINT32 u4Height;      ///<thumbnail height
    UINT32 u4Pitch;       ///<thumbnail pitch
    UINT8 *pucAddr;       ///<thumbnail address
    UINT32 u4ComsumeTime; ///<time from receive a I/IDR frame to extract a thumbnail
}MTPVR_THUMBNAIL_T;

typedef enum
{
    E_MTPVR_THUMBNAIL_RESULT_DONE,          // Get thumbnail done
    E_MTPVR_THUMBNAIL_RESULT_FAIL,          // Get thumbnail fail
    E_MTPVR_THUMBNAIL_RESULT_NO_DATA,       // Get thumbnail fail dual to no I frame
    E_MTPVR_THUMBNAIL_RESULT_MAX            // not used
} MTPVR_THUMBNAIL_RESULT_T;

/** Thumbnail notify information
*/
typedef struct 
{
    BOOL fgOK;    ///<Thumnail Ok or Not Currently useless
    UINT32 u4Id;  ///<Thumnail Id
    UINT32 u4DeltaMs;   ///<time spent on this thumbnail 
    MTPVR_THUMBNAIL_RESULT_T eResult;
}MTPVR_THUMBNAIL_CB_T;

typedef struct 
{
    UINT32 u4Width;         // Width of the picture
    UINT32 u4Height;        // Heigth of the picture
    UINT8 *pucAddr;         // Picture Data address
} MTPVR_THUMBNAIL_ARGB_T;

typedef struct
{
    UCHAR   *pucAddr;           // Address of metadata
    UINT32  u4Size;             // Size of metadata
} MTPVR_THUMBNAIL_DATA_T;

typedef struct
{
    MTDMX_DESC_MODE_T   eDescMode;
    BOOL                fgEven;
    UINT32              u4KeyBitLen;
    UINT32              au4Iv[4];
    UINT32              au4Key[8];
} MTPVR_DESC_KEY_T;

typedef struct
{
    UCHAR                   ucVdecId;
    UINT32                  u4VidPid;       // The dest video id
    MTVDEC_FMT_T            eVdecFmt;       // Dest video format
    MTPVR_DESC_KEY_T        *prDescKey;     // Pvr key
} MTPVR_THUMBNAIL_PARAM_T;

typedef enum
{
    PVR_API_MT5396_3D_NONE,   ///<No 3D
    PVR_API_MT5396_3D_2DTO3D,   ///<2D to 3D
    PVR_API_MT5396_3D_LR_HALF,  ///<3D LR
    PVR_API_MT5396_3D_TB_HALF,  ///<3D TB
    PVR_API_MT5396_3D_MAX       ///<no define
}MTPVR_DIRECT_PLAY_3D_T;

typedef enum
{
    ENUM_MTPVR_SET_DMX_ID,
    ENUM_MTPVR_SET_VDEC_ID,
    ENUM_MTPVR_SET_AUD_ID,
    ENUM_MTPVR_SET_STC_ID,
    ENUM_MTPVR_SET_B2R_ID,
    ENUM_MTPVR_SET_TS_IDX,
} ENUM_MTPVR_SET_INST_ID_T;

typedef enum
{
    ENUM_MTPVR_PLAYMODE_188_SYSMASTER = 0,        // 188 + sys master (DTMB dongle)
    ENUM_MTPVR_PLAYMODE_188_AUDIO_MASTER = 1,     // 188 + aud master (esplayer for 188)
    ENUM_MTPVR_PLAYMODE_192_SYSMASTER = 2,        // 192 + sys master (same as ENUM_MTPVR_PLAYMODE_192), not use
    ENUM_MTPVR_PLAYMODE_192_AUDIO_MASTER = 3,     // 192 + aud master (esplayer for 188)
    ENUM_MTPVR_PLAYMODE_H264_ES = 4,              // Video ES, for network ES playback
    ENUM_MTPVR_PLAYMODE_204 = 5,                  // 204 + aud master

    ENUM_MTPVR_PLAYMODE_188 = 188,                // Keep orignal code, for LGE MHEG5 ; (audio master, 188 ts playback)
    ENUM_MTPVR_PLAYMODE_192 = 192,                // Keep orignal code, for LGE PVR/TimeShift(system master, 192 ts playback)
} ENUM_MTPVR_PLAYMODE_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Initialize PVR module.
*@param VOID
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_Init(void);

/**Start PVR module.
*@param ucPvrId                    PVR id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_Start(UCHAR ucPvrId);

/**Stop PVR module.
*@param ucPvrId                    PVR id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_Stop(UCHAR ucPvrId);

/**Get PVR buffer.
*@param ucPvrId                    PVR id.
*@param pu4Size                    buffer size.
*@param pu4Addr                    buffer address.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_GetBuffer(UCHAR ucPvrId, UINT8 **ppu4Addr, UINT32 *pu4Size);

/**Put PVR module.
*@param ucPvrId                    PVR id.
*@param u4Size                     buffer size.
*@param pu4Addr                    buffer address.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_PutBuffer(UCHAR ucPvrId, UINT8 *pucAddr, UINT32 u4Size);

/**Get Thumbnail.
*@param ucPvrId                    PVR id.
*@param prThumbnail                Thumbnail data.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_GetThumbnail(UCHAR ucPvrId, MTPVR_THUMBNAIL_T *prThumbnail);

/**Stop thumbnail extraction
*@param ucPvrId                    PVR id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_StopThumbnail(UCHAR ucPvrId);

/**Reset PVR module.
*@param ucPvrId                    PVR id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_ResetBuffer(UCHAR ucPvrId);

/**Set PVR speed.
*@param ucPvrId                    PVR id.
*@param u4Speed                    speed
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_SetSpeed(UCHAR ucPvrId, UINT32 u4Speed);

/**Set PVR mode
*@param eMode                      Playback mode (192, 192_EX or 188).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_SetMode(UCHAR ucPvrId, ENUM_MTPVR_PLAYMODE_T ePlayMode);

/**Get PVR Buffer Status
*@retval MTR_OK                    Success.
*@retval MTR_BUFFER_FULL           Fail.
*/
EXTERN MT_RESULT_T MTPVR_GetPvrBufferStatus(void);

/**Put data to PVR module 
*@param u4Addr                     data address.
*@param u4Size                     data size.
*@retval MTR_OK                    Success.
*@retval MTR_BUFFER_FULL           Fail.
*/
EXTERN MT_RESULT_T MTPVR_PutDataChData(UINT32 u4Addr, UINT32 u4Size);

/** Direct MTAL Playback Init.
*@param ucEsId                     Vdec id.
*@param ucPvrId                    PVR id.
*@param eVdecFmt                   Codec
*@param e3DFmt                     3D type
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_InitDirectPlay(UCHAR ucEsId, UCHAR ucPvrId, MTVDEC_FMT_T eVdecFmt, MTPVR_DIRECT_PLAY_3D_T e3DFmt);


/** Direct MTAL Playback.
*@param ucPvrId                    PVR id.
*@param pucData                    data buffer chunck
*@param u4FrameSize                data buffer size
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_Play_ES(UCHAR ucPvrId, INT8 *pucData, UINT32 u4FrameSize);

/** Direct MTAL Playback UnInit.
*@param ucEsId                     Vdec id.
*@param ucPvrId                    PVR id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTPVR_CloseDirectPlay(UCHAR ucEsId,UCHAR ucPvrId);

EXTERN MT_RESULT_T MTPVR_DeliverEOS(UCHAR ucPvrId);

EXTERN MT_RESULT_T MTPVR_ExtractThumbnail ( UCHAR ucPvrId,
                                     MTPVR_THUMBNAIL_DATA_T  *prDataInfo,
                                     MTPVR_THUMBNAIL_PARAM_T *prParamInfo,
                                     MTPVR_THUMBNAIL_ARGB_T *prThumbData,
                                     MTPVR_THUMBNAIL_RESULT_T *peResult);


EXTERN MT_RESULT_T MTPVR_TerminateExtractThumbnail(UCHAR ucPvrId);

EXTERN MT_RESULT_T MTPVR_SetInstID(UCHAR ucPvrId, ENUM_MTPVR_SET_INST_ID_T eType, UCHAR ucInst);

#ifdef __cplusplus
}
#endif

#endif //MT_PVR_H
