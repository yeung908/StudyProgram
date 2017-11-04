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
 * $RCSfile: mtmx.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtmx.h
 *  This header file declares exported APIs of MTAL Multiplexer (MX) module,
 *  which inclued TS, ES and MTK Private format(CMPB)
 */

#ifndef MT_MX_H
#define MT_MX_H

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


//-----------------------------------------------------------------------------
// Macro definitions
//-----------------------------------------------------------------------------

/** Check set paramter
 */
#define MTMX_SET_VALIDATE(TYPE)                    \
do {                                               \
    if (NULL == pvData || u4Size != sizeof(TYPE))  \
    {                                              \
        return MTR_NOT_OK;                         \
    }                                              \
} while(0)


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** MTMX_COMP_ID_T
 * Muxer Component ID
 */
typedef enum _MTMX_COMP_ID_T
{
    MTMX_COMP_1 = 0,                             ///< COMP_1
    MTMX_COMP_2,                                 ///< COMP_2
    MTMX_COMP_3,                                 ///< COMP_3
    MTMX_COMP_NS                                 ///< COMP_NS
} MTMX_COMP_ID_T;


/** MTMX_VENC_T
*   The video codec format.
*/
typedef enum
{
    MTMX_VENC_UNKNOWN,                           ///< Video Encode Unkown
    MTMX_VENC_MPEG1,                             ///< Video Encode MPEG1
    MTMX_VENC_MPEG2,                             ///< Video Encode MPEG2
    MTMX_VENC_H264,                              ///< Video Encode H264     
    MTMX_VENC_MAX                                ///< Video Encode MAX
} MTMX_VENC_T;

/** MTMX_AENC_T
*   The Audio codec format.
*/
typedef enum
{
    MTMX_AENC_UNKNOWN = 0,                       ///< Audio Encode Unkown
    MTMX_AENC_MPEG,                              ///< Audio Encode MPEG
    MTMX_AENC_AC3,                               ///< Audio Encode AC3
    MTMX_AENC_PCM,                               ///< Audio Encode PCM
    MTMX_AENC_MP3,                               ///< Audio Encode MP3
    MTMX_AENC_AAC,                               ///< Audio Encode AAC
    MTMX_AENC_MAX                                ///< Audio Encode MAX
} MTMX_AENC_T;
/** MTMX_SET_TYPE_T
 * set type
 */
typedef enum _MTMX_SET_TYPE_T
{
    MTMX_SET_TYPE_CONNECT_SRC,                   ///< set connect
    MTMX_SET_TYPE_DISCONNECT_SRC,                ///< set disconnect
    MTMX_SET_TYPE_NFY_FCT,                       ///< set notify function
    MTMX_SET_TYPE_CTRL,                          ///< set control
    MTMX_SET_TYPE_BUFFER_SETTING,                ///< set buffer setting
    MTMX_SET_TYPE_BUFFER_ALLOC,                  ///< alloc buffer setting
    MTMX_SET_TYPE_UNLOCK_BUFFER,                 ///< set unlock buffer
    MTMX_SET_TYPE_FLUSH_BUFFER,                  ///< set flush buffer
    MTMX_SET_TYPE_ENCRYPT_KEY,                   ///< set encrypt key
    MTMX_SET_TYPE_ENCRYPT_CTRL,                  ///< set encrypt control
    /*MTMX_SET_TYPE_MUX_TYPE*/
} MTMX_SET_TYPE_T;


/** MTMX_GET_TYPE_T
 * get type
 */
typedef enum _MTMX_GET_TYPE_T
{
    MTMX_GET_TYPE_CTRL                           ///< get control
} MTMX_GET_TYPE_T;


/** MTMX_NFY_COND_T
 * notification conditions
 */
typedef enum _MTMX_NFY_COND_T
{
    MTMX_COND_ERROR    = -2,                     ///< Notify Condition: Error
    MTMX_COND_OVERFLOW = -1,                     ///< Notify Condition: Buffer Overflow
    MTMX_COND_DATA     =  0,                     ///< Notify Condition: Buffer Data Available
} MTMX_NFY_COND_T;


/** MTMX_OVERFLOW_REASON_T
 * Overflow reasons ((*mtmux_nfy_fct)(e_nfy_cond == MTMX_COND_OVERFLOW,  u4_data => overflow reason) )
 */
typedef enum _MTMX_OVERFLOW_REASON_T
{
    MTMX_OVERFLOW_REASON_RING_BUF_FULL     = 1,  ///< Overflow reason: ring buffer full
    MTMX_OVERFLOW_REASON_METADATA_BUF_FULL = 2,  ///< Overflow reason: metadata buffer full
    MTMX_OVERFLOW_REASON_UNKNOWN = 3,            ///< Overflow reason: unknow
} MTMX_OVERFLOW_REASON_T;


/** MTMX_ERROR_REASON_T
 * Error reasons ((*mtmux_nfy_fct)(e_nfy_cond == MTMX_COND_ERROR,  u4_data => error reason) )
 */
typedef enum _MTMX_ERROR_REASON_T
{
    MTMX_ERROR_REASON_INTERNAL    = 1            ///< Error reason: internal
} MTMX_ERROR_REASON_T;


/** mtmux_nfy_fct
 * prototype of notify function
 * for MTMX_SET_TYPE_NFY_FCT
 */
typedef BOOL (*mtmux_nfy_fct)( VOID*            pvTag,
                               MTMX_NFY_COND_T  eNfyCond,
                               UINT32           u4Data );


/** MTMX_BUF_TYPE_T
 * mux format
 */
typedef enum _MTMX_BUF_TYPE_T
{
    MTMX_DATA_TYPE_MTK,                          ///< format CMPB
    MTMX_DATA_TYPE_TS,                           ///< format 188 TS
    MTMX_DATA_TYPE_TS_192,                       ///< format 192 TS
    MTMX_DATA_TYPE_VIDEO_ES,                     ///< format Video ES
    MTMX_DATA_TYPE_AUDIO_ES                      ///< format Audio ES
} MTMX_BUF_TYPE_T;


/** MTMX_SRC_TYPE_T
 * source type
 */
typedef enum _MTMX_SRC_TYPE_T
{
    MTMX_SRC_TYPE_VENC = 0,                      ///< source type video encoder
    MTMX_SRC_TYPE_AENC,                          ///< source type audio encoder
    MTMX_SRC_TYPE_VBI,                           ///< source type VBI
    MTMX_SRC_TYPE_AV,
    MTMX_SRC_TYPE_MAX                            ///< source type unknown
} MTMX_SRC_TYPE_T;


/** MTMX_SRC_INFO_T
 * for  MTMX_SET_TYPE_CONNECT_SRC/MTMX_SET_TYPE_DISCONNECT_SRC
 */
typedef struct _MTMX_SRC_INFO_T
{
    MTMX_SRC_TYPE_T  eSrcType;                   ///< source type
    UINT16           u2CompId;                   ///< component id
} MTMX_SRC_INFO_T;


/** MTMX_BUF_DATA_T
 * for MTMX_COND_DATA condition: notify data to mw
 */
typedef struct _MTMX_BUF_DATA_T
{
    UINT8*          pui1BufPhy;                  ///< data start kernel space physical address
    UINT32          u4Size;                      ///< data size
    UINT32          u4Flag;                      ///< for x_mm_common.h PVR_TICK_INDEX_FLAG
    UINT64          u8Pts;                       ///< pts
} MTMX_BUF_DATA_T;


/** MTMX_UNLOCK_BUFFER_INFO_T
 * for MTMX_SET_TYPE_UNLOCK_BUFFER
 */
typedef struct _MTMX_UNLOCK_BUFFER_INFO_T
{
    UINT8*      pui1DataAddr;                    ///< free data start kernel space physical address
    UINT32      u4DataLen;                       ///< free range size
} MTMX_UNLOCK_BUFFER_INFO_T;


/** MTMX_BUF_MTK_T
 * buffer info of CMPB
 */
typedef struct _MTMX_BUF_MTK_T
{
    UINT32              u4TickPeriod;            ///< tick to notify data, unit: ms, 0 for notify anytime
    UINT32              u4BufSize;               ///< buffer size
    VOID*               pvBufPhy;                ///< buffer start kernel space physical address
} MTMX_BUF_MTK_T;


/** MTMX_BUF_TS_T
 * buffer info of TS
 */
typedef struct _MTMX_BUF_TS_T
{
    UINT32              u4TickPeriod;            ///< tick to notify data, unit: ms, 0 for notify anytime
    UINT32              u4BufSize;               ///< buffer size
    VOID*               pvBufPhy;                ///< buffer start kernel space physical address
} MTMX_BUF_TS_T;


/** MTMX_BUF_VID_ES_T
 * buffer info of Video ES
 */
typedef struct _MTMX_BUF_VID_ES_T
{
    UINT32              u4TickPeriod;            ///< tick to notify data, unit: ms, 0 for notify anytime
    UINT32              u4BufSize;               ///< buffer size
    VOID*               pvBufPhy;                ///< buffer start kernel space physical address
} MTMX_BUF_VID_ES_T;


/** MTMX_BUF_AUD_ES_T
 * buffer info of Audio ES
 */
typedef struct _MTMX_BUF_AUD_ES_T
{
    UINT32              u4TickPeriod;            ///< tick to notify data, unit: ms, 0 for notify anytime
    UINT32              u4BufSize;               ///< buffer size
    VOID*               pvBufPhy;                ///< buffer start kernel space physical address
} MTMX_BUF_AUD_ES_T;


/** MTMX_BUF_SETTING_T
 * for MTMX_SET_TYPE_BUFFER_SETTING operation
 */
typedef struct _MTMX_BUF_SETTING_T
{
    MTMX_BUF_TYPE_T          eType;              ///< mux format
    union
    {
        MTMX_BUF_MTK_T       tBufMtk;            ///< format CMPB
        MTMX_BUF_TS_T        tBufTs;             ///< format TS
        MTMX_BUF_VID_ES_T    tBufVid;            ///< format Video ES
        MTMX_BUF_AUD_ES_T    tBufAud;            ///< format Audio ES
    }u;                                          ///< union alias
} MTMX_BUF_SETTING_T;


/** MTMX_NFY_INFO_T
 * set notify function
 */
typedef struct _MTMX_NFY_INFO_T
{
    VOID*               pvTag;                   ///< tag of notify function
    mtmux_nfy_fct       pfNfy;                   ///< pointer of notify function
} MTMX_NFY_INFO_T;


/** MTMX_CB_T
 * callback structure
 */
typedef struct _MTMX_CB_T
{
    MTMX_NFY_COND_T eCond;                       ///< notify condition
    UINT32 u4Id;                                 ///< instance id
    union
    {
        MTMX_BUF_DATA_T      tBufData;           ///< data ready
        MTMX_OVERFLOW_REASON_T eOverflowReason;  ///< overflow reason
        MTMX_ERROR_REASON_T eErrorReason;        ///< error reason
    }u;                                          ///< union alias
} MTMX_CB_T;


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Initialize MTMX.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTMX_Init(VOID);


/**
 * Terminate MTMX.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTMX_Termint(VOID);


/**
 * Reset MTMX of component u2CompId.
 * @param[in]  u2CompId The component ID.
 * @return MT_RESULT_T
 */
EXTERN MT_RESULT_T MTMX_Reset(UINT16 u2CompId);


/**
 * Wrapper of _muxer_set.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eSetType set type.
 * @param[in]  pvData pointer to set data.
 * @param[in]  u4Size size of set data.
 * @return MT_RESULT_T The set results
 */
EXTERN MT_RESULT_T MTMX_Set(
                                    UINT16           u2CompId,
                                    MTMX_SET_TYPE_T  eSetType,
                                    const VOID*      pvData,
                                    UINT32           u4Size );


/**
 * Wrapper of _muxer_get.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eGetType get type.
 * @param[out] pvData pointer to get data.
 * @param[out] pu4Size size of get data.
 * @return MT_RESULT_T The get results
 */
EXTERN MT_RESULT_T MTMX_Get(
                                    UINT16            u2CompId,
                                    MTMX_GET_TYPE_T   eGetType,
                                    VOID*             pvData,
                                    UINT32*           pu4Size );


/**
 * Wrapper of MTMX_SetCodec.
 * @param[in]  u2CompId The component ID.
 * @param[in]  eSrcType is audio or video.
 * @param[in]  eVenc is what video codec.
 * @param[in]  eAenc is what audio codec.
 * @return MT_RESULT_T The get results
 */
MT_RESULT_T MTMX_SetCodec(
                                    UINT16 u2CompId,
                                    MTMX_SRC_TYPE_T eSrcType, 
                                    MTMX_VENC_T eVenc, 
                                    MTMX_AENC_T eAenc);

/**
 * Wrapper of MTMX_CopyData.
 * @param[in]  u2CompId The component ID.
 * @param[in]  u4FromAddr is source address.
 * @param[in]  u4ToAddr is dest address.
 * @param[in]  u4Size is data size.
 * @return MT_RESULT_T The get results
 */
MT_RESULT_T MTMX_CopyData(
                                    UINT16 u2CompId,
                                    UINT32 u4FromAddr,
                                    UINT32 u4ToAddr,
                                    UINT32 u4Size);

#ifdef __cplusplus
}
#endif

#endif //MT_MX_H

