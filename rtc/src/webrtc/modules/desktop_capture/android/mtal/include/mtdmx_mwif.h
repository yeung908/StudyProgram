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
 * $RCSfile: mtdmx.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtdmx_mwif.h
 *  This header file declares exported APIs of DMX module.
 *  All functions are used by mw_if2 only
 */

#ifndef MT_DMX_MWIF_H
#define MT_DMX_MWIF_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"


//-----------------------------------------------------------------------------
// MTAL Constant definitions
//-----------------------------------------------------------------------------
#define MTDMX_NUM_FVR_PID			    (64)
/// Multi-media
#define MTDMX_MM_FLAG_NONE              0x00000000
#define MTDMX_MM_FLAG_VALID             0x00000001
#define MTDMX_MM_FLAG_TYPE              0x00000002
#define MTDMX_MM_FLAG_BUF               0x00000004
#define MTDMX_MM_FLAG_SEARCH_START_CODE 0x00000008
#define MTDMX_MM_FLAG_NOTIFY            0x00000020
#define MTDMX_MM_FLAG_DEVICE_ID         0x00000040
#define MTDMX_MM_FLAG_INSTANCE_TAG      0x00008000  /* DMX_PID_FLAG_INSTANCE_TAG */
#define MTDMX_MM_FLAG_ALL               0xFFFFFFFF


#define MTFVR_GBL_FLAG_BUFFER           0x00000001
#define MTFVR_GBL_FLAG_TARGET_PKT       0x00000002
#define MTFVR_GBL_FLAG_NOTIFY           0x00000004
#define MTFVR_GBL_FLAG_TIME_INFO        0x00000008
#define MTFVR_GBL_FLAG_NONE             0x00000000
#define MTFVR_GBL_FLAG_ALL              0xFFFFFFFF

#define MTFVR_PID_FLAG_ENABLE           0x00000001
#define MTFVR_PID_FLAG_TSINDEX          0x00000002
#define MTFVR_PID_FLAG_PID              0x00000004
#define MTFVR_PID_FLAG_PICSEARCH        0x00000008
#define MTFVR_PID_FLAG_PKTSWAP          0x00000010
#define MTFVR_PID_FLAG_SCRAMBLE_ENABLE  0x00000020
#define MTFVR_PID_FLAG_CBC_MODE         0x00000040
#define MTFVR_PID_FLAG_KEY_TYPE         0x00000080
#define MTFVR_PID_FLAG_KEY_LEN          0x00000100
#define MTFVR_PID_FLAG_KEY_INDEX        0x00000200
#define MTFVR_PID_FLAG_DETECT_SCRAMBLE  0x00000400
#define MTFVR_PID_FLAG_FREEZE           0x00000800
#define MTFVR_PID_FLAG_SOURCE           0x00001000
#define MTFVR_PID_FLAG_DESC             0x00010000
#define MTFVR_PID_FLAG_LOCAL_TSINDEX    0x00020000 //input ts: for ci+1.4 remux ts local index.
#define MTFVR_PID_FLAG_NONE             0x00000000
#define MTFVR_PID_FLAG_ALL              0xFFFFFFFF


//-----------------------------------------------------------------------------
// MTAL Type definitions
//-----------------------------------------------------------------------------
    typedef enum
    {
        MTFVR_VIDEO_NONE,
        MTFVR_VIDEO_MPEG,
        MTFVR_VIDEO_H264
    } MTFVR_VIDEO_TYPE_T;

typedef enum
{
    MTFVR_GBL_NFY_TIME,
    MTFVR_GBL_NFY_PKTCOUNT,
    MTFVR_GBL_NFY_SCRAMBLE,
    MTFVR_GBL_NFY_OVERFLOW,
    MTFVR_GBL_NFY_OTHER,            // this share the same callback function for FVR PID
    MTFVR_GBL_NFY_RAW_SCRAMBLE
} MTFVR_GBL_NOTIFY_CODE_T;

    typedef enum
    {
        MTFVR_KEY_EVEN,
        MTFVR_KEY_ODD,
        MTFVR_KEY_BOTH
    } MTFVR_KEY_TYPE_T;

    typedef enum
    {
        MTFVR_CRYPTO_KEY_SECURE_PVR_AES_0 = 0x30,  ///< secure key
        MTFVR_CRYPTO_KEY_SECURE_PVR_AES_IV_0,
        MTFVR_CRYPTO_KEY_MAX
    } MTFVR_CRYPTO_KEY_TYPE_T;

/// Scrambling state
    typedef enum
    {
        MTFVR_SCRAMBLE_STATE_CLEAR,           ///< Clear data
        MTFVR_SCRAMBLE_STATE_SCRAMBLED,       ///< Scrambled data
        MTFVR_SCRAMBLE_STATE_UNKNOWN          ///< Unknown data
    } MTFVR_SCRAMBLE_STATE_T;

/// PCR mode
    typedef enum
    {
        MTDMX_PCR_MODE_NONE = 0,              ///< None
        MTDMX_PCR_MODE_OLD,                   ///< Old mode (5371 type)
        MTDMX_PCR_MODE_NEW                    ///< New mode
    } MTDMX_PCR_MODE_T;

    typedef enum
    {
        MTDMX_IN_NONE         = 0,
        MTDMX_IN_DIAG         = 1,
        MTDMX_IN_BROADCAST_TS = 0x10,
        MTDMX_IN_PLAYBACK_TS  = 0x100,
        MTDMX_IN_PLAYBACK_PS  = 0x200,
        MTDMX_IN_PLAYBACK_MM  = 0x300,
        MTDMX_IN_PVR_TS       = 0x400,
        MTDMX_IN_PLAYBACK_ES  = 0x500
    } MTDMX_INPUT_TYPE_T;


    typedef struct
    {
        BOOL fgEnable;

        BOOL fgSearchStartCode;
        MTDMX_PID_TYPE_T ePidType;
        PFN_MTDMX_NOTIFY pfnCallback;

        BOOL fgAllocBuf;
        UINT32 u4BufAddr;
        UINT32 u4BufSize;
        UINT32 u4Rp;
        UINT32 u4Wp;
        void *pvInstanceTag;    // Tag for supporting multiple instances (used only by v-dec)
        UINT8 u1ChannelId;
        UINT8 u1DeviceId;
    } MTDMX_MM_T;


/// Demux notification callback function
    typedef void (*PFN_MTFVR_GBL_NOTIFY)(MTFVR_GBL_NOTIFY_CODE_T eCode,
                                         UINT32 u4Data, const void* pvTag);

    typedef void (*PFN_MTFVR_PID_PKTSWAP)(UINT8 u1Pidx, UINT32 u4Addr);

    typedef void (*PFN_MTFVR_PID_PICSEARCH)(UINT8 u1Pidx, UINT8 u1Type, UINT32 u4PktCount,
                                            const void* pvTag);

    typedef BOOL (*PFN_MTFVR_PID_DETECTSCRAMBLE)(UINT8 u1Pidx, MTFVR_SCRAMBLE_STATE_T eState);

    typedef struct
    {
        UINT16 u2TargetPktCount;
        BOOL fgAllocateBuffer;
        UINT32 u4BufStart;
        UINT32 u4BufSize;
        UINT32 u4Wp;
        UINT32 u4Rp;

        BOOL fgSetAlign;
        UINT32 u4BufAlign;

        PFN_MTFVR_GBL_NOTIFY pfnNotifyFunc;
        void* pvNotifyTag;

        UINT32 u4TimeToNotify;
        /*the following item used for ciplus1.4 record.*/
        UINT32 u4SyncPattern; /*ts3 bit[31:24], ts2 bit[23:16], ts1 bit[15:8], ts0bit[7:0]*/
        UINT8  u1CiTsidx; /*for ci input ts index settings*/
        UINT8  u1SyncMask; /*use bit[3:0] */
    }MTFVR_GBL_T;

    typedef struct
    {
        BOOL fgEnable;
        UINT8 u1TsIndex;
    	UINT8 u1LocalTsIndex;
        UINT16 u2Pid;

        BOOL fgPktSwap;
        PFN_MTFVR_PID_PKTSWAP pfnSwapNotify;
        void *pvSwapNotifyTag;
        BOOL fgPktSwapOnce;

        BOOL fgPicSearch;
        UINT8 u1PicSearchMask;
        PFN_MTFVR_PID_PICSEARCH pfnPicSearchNotify;
        void *pvPicSearchNotifyTag;

        BOOL fgScramble;
        BOOL fgCBCMode;

        MTFVR_KEY_TYPE_T eKeyType;
        UINT8 u1KeyIdx;
        UINT32 u4KeyLen;

        BOOL fgDetectScramble;
        PFN_MTFVR_PID_DETECTSCRAMBLE pfnDetectScrambleNotify;
        PFN_MTFVR_PID_DETECTSCRAMBLE pfnDetectRawScrambleNotify;

        BOOL fgFreeze;
        MTDMX_SOURCE_T eSource;     // Logical channel: DTV0, DTV1
        MTDMX_PID_TYPE_T ePidType;

        //----------------------------------
        // Below is for section filter
        BOOL fgDoSFilter;
        BOOL fgAllocateBuffer;      // Allocate buffer or not
        UINT32 u4BufAddr;          // Buffer start
        UINT32 u4BufSize;            // Buffer length
        UINT32 u4Rp;                // Read pointer
        UINT32 u4SectionRp;         // Section read pointer
        UINT32 u4Wp;                // Write pointer
        PFN_MTDMX_NOTIFY pfnNotify;   // Demux callback function
        void* pvNotifyTag;          // Tag value of callback function
        void *pvInstanceTag;
        //----------------------------------

        BOOL  fgDesc;               // Decrypt TS (CI+, multi-2)
        UINT8 u1DescKeyidx;           // Decrypt TS (CI+, multi-2)
        MTDMX_DESC_MODE_T eDescMode;  // Descramble mode
    } MTFVR_PID_T;

    typedef struct
    {
        UINT8 u1TsIdx;
        UINT32 u4Addr;
        UINT32 u4Size;
        UINT32 u4PktCount;
    } MTFVR_GBL_TIMENOTIFY_INFO_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
    /** MTDMX_MWIF_Init
     *  Init demux driver for mw_if2
     *  @retval MTR_OK                     Success.
     *  @retval MTR_NOT_OK                 Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MWIF_Init(void);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_FreePidx
     *  Multiple instance maanger for free PID index
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_FreePidx(UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_SetPidxInstance
     *  Multiple instance maanger for linking instance id with PID index
     *
     *  @param  u1Inst          Instance ID
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_SetPidxInstance(UINT8 u1Inst, UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_GetAvailableInst
     *  Multiple instance maanger for allocating a free instance ID
     *
     *  @param  eConnType       Connection type for querying instance ID
     *  @param  pu1Inst         Instance ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_GetAvailableInst(MTDMX_CONN_TYPE_T eConnType, UINT8 *pu1Inst);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_FreeInst
     *  Multiple instance maanger for freeing an instance ID
     *
     *  @param u1Inst           Instance ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_FreeInst(UINT8 u1Inst);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_GetPidxInstId
     *  Multiple instance maanger for querying the instance ID via PID index
     *
     *  @param u1Inst           Instance ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_GetPidxInstId(UINT8 u1Pidx, UINT8 *pu1Inst);

//-----------------------------------------------------------------------------
    /** MTDMX_MUL_GetAvailableInst
     *  Multiple instance maanger for freeing an instance ID
     *
     *  @param u1Inst           Instance ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MUL_SetSubtitlePidx(UINT8 u1Inst, UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_Set
     *  Multimedia playback function for setting a MM PID
     *
     *  @param u1Idx            PID index
     *  @param u4Flags          Function flags
     *  @param prMMStruct       The MM structure of the PES
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_Set(UINT8 u1Idx, UINT32 u4Flags, MTDMX_MM_T *prMMStruct);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_Set
     *  Multimedia playback function for getting a MM PID
     *
     *  @param u1Idx            PID index
     *  @param u4Flags          Function flags
     *  @param prMMStruct       The MM structure of the PES
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_Get(UINT8 u1Idx, UINT32 u4Flags, MTDMX_MM_T *prMMStruct);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_Free
     *  Multimedia playback function for freeing a MM PID
     *
     *  @param u1Idx            PID index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_Free(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_UnlockBuffer
     *  Multimedia playback function for unlocking a ES buffer
     *
     *  @param u1Idx            PID index
     *  @param u1SerialNumber   Current serial number for the PID index
     *  @param u4Size           ES buffer size
     *  @param u4FrameAddr      ES buffer address
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_UnlockBuffer(UINT8 u1Idx, UINT8 u1SerialNumber, UINT32 u4Size,
            UINT32 u4FrameAddr);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_UnlockBuffer
     *  Multimedia playback function for copying a ES buffer
     *
     *  @param u1Idx            PID index
     *  @param u1SerialNumber   Current serial number for the PID index
     *  @param u4FrameAddr      ES buffer address
     *  @param u4SkipSize       Skip buffer size
     *  @param u4CopySize       Copy buffer size
     *  @param pu1Dest          Destination buffer pointer for storing ES data
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_GetBuffer(UINT8 u1Idx, UINT8 u1SerialNumber, UINT32 u4FrameAddr,
                                          UINT32 u4SkipSize, UINT32 u4CopySize, UCHAR* pu1Dest);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_FlushBuffer
     *  Multimedia playback function for clearing a ES buffer
     *
     *  @param u1Idx            PID index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_FlushBuffer(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_FlushBuffer
     *  Multimedia playback function for allocating a buffer
     *
     *  @param u1Idx            PID index
     *  @param u4Size           Allocation size
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_AllocateBuffer(UINT8 u1Idx, UINT32 u4Size);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_FreeBuffer
     *  Multimedia playback function for freeing a buffer
     *
     *  @param u1Idx            PID index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_MM_FreeBuffer(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTDMX_MM_FreeBuffer
     *  Program stream playback function for setting filter stream ID and substream ID
     *
     *  @param u1Idx            PID index
     *  @param u1StreamId       Stream ID
     *  @param u1SubStreamId    Sub stream ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_PS_SetStreamId(UINT8 u1Idx, UINT8 u1StreamId, UINT8 u1SubStreamId);

//-----------------------------------------------------------------------------
    /** MTDMX_GetVideoChannel
     *  Query video channel ID of specific PID index
     *
     *  @param u1Idx            PID index
     *  @param pu1Channel       channel ID
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_GetVideoChannel(UINT8 u1Pidx, UINT8* pu1Channel);

//-----------------------------------------------------------------------------
    /** MTFVR_GetVideoType
     *  Query video type of specific TS index
     *
     *  @param u1TsIdx          TS index
     *  @param peType           video type
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_GetVideoType(UINT8 u1TsIdx, MTFVR_VIDEO_TYPE_T* peType);

//-----------------------------------------------------------------------------
    /** MTFVR_SetPid
     *  Set recording PID
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @param  u4Flags         Function flags
     *  @param  prPid           The PID structure for recording
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SetPid(UINT8 u1Pidx, UINT32 u4Flags, MTFVR_PID_T* prPid);

//-----------------------------------------------------------------------------
    /** MTFVR_SetPid
     *  Get recording PID
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @param  u4Flags         Function flags
     *  @param  prPid           The PID structure for recording
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_GetPid(UINT8 u1Pidx, UINT32 u4Flags, MTFVR_PID_T* prPid);

//-----------------------------------------------------------------------------
    /** MTFVR_SwapFreePattern
     *  Free swap PID pattern
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SwapFreePattern(UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTFVR_SwapFreePattern
     *  set null pattern to swap PID
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SwapSetNullPattern(UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTFVR_SwapSetPattern
     *  set a pattern to swap PID
     *
     *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
     *  @param  pu1Pattern      Pattern buffer pointer
     *  @param  u2Len           Pattern buffer length
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SwapSetPattern(UINT8 u1Pidx, UINT8* pu1Pattern, UINT16 u2Len);

//-----------------------------------------------------------------------------
    /** MTFVR_SetAesKey
     *  set AES encryption key for recorded data
     *
     *  @param  u1KeyIdx        Key index
     *  @param  fgEven          If even key
     *  @param  pu1Key          Key value
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SetAesKey(UINT8 u1KeyIdx, BOOL fgEven, UINT8 *pu1Key);

//-----------------------------------------------------------------------------
    /** MTFVR_SetCryptoKey
     *  set crypto key for recorded data
     *
     *  @param  u1KeyIdx        Key index
     *  @param  fgEven          If even key
     *  @param  eKeyType        eKeyType
     *  @param  pu1Key          Key value
     *  @param  u4KeyLen        Key length
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SetCryptoKey(UINT8 u1KeyIdx, BOOL fgEven, MTFVR_CRYPTO_KEY_TYPE_T eKeyType,
                                        const UINT8 *pu1Key, UINT32 u4KeyLen);

//-----------------------------------------------------------------------------
    /** MTFVR_GetGBL
     *  get global recording setting
     *
     *  @param  u1TsIdx         TS index
     *  @param  u4Flags         Function flags
     *  @param  prGBL           Global recording structure
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_GetGBL(UINT8 u1TsIdx, UINT32 u4Flags, MTFVR_GBL_T* prGBL);

//-----------------------------------------------------------------------------
    /** MTFVR_SetGBL
     *  set global recording setting
     *
     *  @param  u1TsIdx         TS index
     *  @param  u4Flags         Function flags
     *  @param  prGBL           Global recording structure
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_SetGBL(UINT8 u1TsIdx, UINT32 u4Flags, MTFVR_GBL_T* prGBL);

//-----------------------------------------------------------------------------
    /** MTFVR_Init
     *  Recording initialization
     *
     *  @param  u1Idx           Recording TS index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_Init(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTFVR_Start
     *  Start to record
     *
     *  @param  u1Idx           Recording TS index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_Start(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTFVR_Stop
     *  Stop recording
     *
     *  @param  u1Idx           Recording TS index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_Stop(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTFVR_IsRecording
     *  Query if it is recording
     *
     *  @param  u1Idx           Recording TS index
     *  @param  fgIsRecording   If it is Recording
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_IsRecording(UINT8 u1Idx, BOOL *fgIsRecording);

//-----------------------------------------------------------------------------
    /** MTFVR_UnlockBuffer
     *  Unlock recording buffer
     *
     *  @param  u1TsIdx         TS index
     *  @param  u4Addr          Recorded buffer address
     *  @param  u4Size          Recorded buffer size
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_UnlockBuffer(UINT8 u1TsIdx, UINT32 u4Addr, UINT32 u4Size);

//-----------------------------------------------------------------------------
    /** MTFVR_FlushBuffer
     *  Clear recording buffer
     *
     *  @param  u1Idx           Recording TS index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_FlushBuffer(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTFVR_FreePid
     *  Free recording PID
     *
     *  @param  u1Pidx          PID index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_FreePid(UINT8 u1Pidx);

//-----------------------------------------------------------------------------
    /** MTFVR_FreeGBL
     *  Free global recording setting
     *
     *  @param  u1Idx           Recording TS index
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTFVR_FreeGBL(UINT8 u1Idx);

//-----------------------------------------------------------------------------
    /** MTDMX_SetPacketSize
     *  Setup processing packet size
     *
     *  @param  u1Size          Packet size
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_SetPacketSize(UINT8 u1Size);

//-----------------------------------------------------------------------------
    /** MTDMX_SetCustFrontEnd
     *  Setup default front end via querying drv_cust setting
     *
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_SetCustFrontEnd(void);



//-----------------------------------------------------------------------------
    /** MTDMX_PES_FreeBufferEx
     *  Free a PES buffer pool
     *  @param  u1Pidx          PID index, 0 ~ 31
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_PES_FreeBufferEx (UINT8 u1Pidx);


//-----------------------------------------------------------------------------
    /** MTDMX_PSI_FreeBufferEx
     *  Free a PES buffer pool
     *  @param  u1Pidx          PID index, 0 ~ 31
     *  @retval MTR_OK          Success.
     *  @retval MTR_NOT_OK      Fail.
     */
//-----------------------------------------------------------------------------
    EXTERN MT_RESULT_T MTDMX_PSI_FreeBufferEx (UINT8 u1Pidx);

//-----------------------------------------------------------------------------
// Private MW_IF Constant definitions
//-----------------------------------------------------------------------------
#define MTDMX_MWIF_MUL_FREEPID_ID               (0)
#define MTDMX_MWIF_MUL_SETPIDXINSTANCE_ID       (1)
#define MTDMX_MWIF_MUL_GETAVAILINST_ID          (2)
#define MTDMX_MWIF_MUL_FREEINST_ID              (3)
#define MTDMX_MWIF_MUL_GETPIDXINSTID_ID         (4)
#define MTDMX_MWIF_MUL_SETSUBTITLEPIDX_ID       (5)

#define MTDMX_MWIF_MM_SET_ID                    (10)
#define MTDMX_MWIF_MM_GET_ID                    (11)
#define MTDMX_MWIF_MM_FREE_ID                   (12)
#define MTDMX_MWIF_MM_FLUSHBUFFER_ID            (13)
#define MTDMX_MWIF_MM_ALLOCATEBUFFER_ID         (14)
#define MTDMX_MWIF_MM_FREEBUFFER_ID             (15)

#define MTDMX_MWIF_PS_SETSTREAM_ID              (20)

#define MTDMX_MWIF_GETVIDEOCHANNEL_ID           (30)

#define MTDMX_MWIF_FVR_GETVIDEOTYPE_ID          (40)
#define MTDMX_MWIF_FVR_SETPID_ID                (41)
#define MTDMX_MWIF_FVR_GETPID_ID                (42)
#define MTDMX_MWIF_FVR_SWAPFREE_ID              (43)
#define MTDMX_MWIF_FVR_SWAPSETNULL_ID           (44)
#define MTDMX_MWIF_FVR_SWAPSET_ID               (45)
#define MTDMX_MWIF_FVR_SETAESKEY_ID             (46)
#define MTDMX_MWIF_FVR_GETGBL_ID                (47)
#define MTDMX_MWIF_FVR_SETGBL_ID                (48)
#define MTDMX_MWIF_FVR_INIT_ID                  (49)
#define MTDMX_MWIF_FVR_START_ID                 (50)
#define MTDMX_MWIF_FVR_STOP_ID                  (51)
#define MTDMX_MWIF_FVR_ISREC_ID                 (52)
#define MTDMX_MWIF_FVR_UNLOCK_BUFFER_ID         (53)
#define MTDMX_MWIF_FVR_FLUSH_BUFFER_ID          (54)
#define MTDMX_MWIF_FVR_FREEPID_ID               (55)
#define MTDMX_MWIF_FVR_FREEGBL_ID               (56)
#define MTDMX_MWIF_FVR_SETCRYPTOKEY_ID          (57)

#define MTDMX_MWIF_SETPACKETSIZE_ID             (60)
#define MTDMX_MWIF_SETCUSTFRONTEND_ID           (61)
#define MTDMX_MWIF_PES_FREEBFR                  (62)
#define MTDMX_MWIF_PSI_FREEBFR                  (63)




//-----------------------------------------------------------------------------
//  Private MW_IF Type definitions
//-----------------------------------------------------------------------------
/// PID data structure
    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Inst;
        UINT8 u1Pidx;
        MTDMX_CONN_TYPE_T eConnType;
    } MTDMX_MWIF_MUL_PID_T;

/// MM data structure
    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Pidx;
        UINT32 u4Flags;
        MTDMX_MM_T *prMMStruct;
        UINT32 u4Size; // for buffer size allocation
    } MTDMX_MWIF_MM_T;

/// PS data structure
    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Pidx;
        UINT8 u1StreamId;
        UINT8 u1SubStreamId;
    } MTDMX_MWIF_PS_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Pidx;
        UINT8 *pu1ChannelId;
    } MTDMX_MWIF_VIDEO_CHANNEL_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        MTFVR_VIDEO_TYPE_T* peType;
        UINT8 u1Pidx;
        UINT32 u4Flags;
        MTFVR_PID_T* prPid;
        UINT8 *pu1Pattern;
        UINT16 u2Len;
        UINT8 u1TsIdx;
    } MTDMX_MWIF_FVR_PID_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1KeyIdx;
        BOOL fgEven;
        UINT8 *pu1Key;
    } MTDMX_MWIF_FVR_KEY_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1KeyIdx;
        BOOL fgEven;
        MTFVR_CRYPTO_KEY_TYPE_T eKeyType;
        const UINT8 *pu1Key;
        UINT32 u4KeyLen;
    } MTDMX_MWIF_FVR_CRYPTO_KEY_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
	    UINT8 u1TsIdx;
        UINT32 u4Flags;
        MTFVR_GBL_T* prGBL;
    } MTDMX_MWIF_FVR_GBL_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Idx;
        UINT32 fgIsRecording;
    } MTDMX_MWIF_FVR_OP_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
		UINT8 u1TsIdx;
        UINT32 u4KernelAddr;
        UINT32 u4Size;
    } MTDMX_MWIF_FVR_BUFFER_T;

    typedef struct
    {
        UINT32 u4InterfaceId;
        UINT8 u1Size;
    } MTDMX_MWIF_SIZE_T;

#ifdef __cplusplus
}
#endif

#endif //MT_DMX_MWIF_H

