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

/** @file mtdmx.h
 *  This header file declares exported APIs of DMX module.
 */

#ifndef MT_DMX_H
#define MT_DMX_H

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


#if defined(CC_MT5399) 
#define MTDMX_NUM_PID_INDEX				  64
#define MTDMX_NUM_FILTER_INDEX            48
#define MTDMX_KEY_MAX_NUM                 32
#elif defined(CC_MT5890)
#define MTDMX_NUM_PID_INDEX				  96
#define MTDMX_NUM_FILTER_INDEX            192
#define MTDMX_KEY_MAX_NUM                 32
#else
#define MTDMX_NUM_PID_INDEX				  80
#define MTDMX_NUM_FILTER_INDEX            96
#define MTDMX_KEY_MAX_NUM                 8
#endif
#define MTDMX_NUM_TS_INDEX                4

#define MTDMX_TS_INDEX_0                  0
#define MTDMX_TS_INDEX_1                  1
#define MTDMX_TS_INDEX_2                  2
#define MTDMX_TS_INDEX_PVR                2
#define MTDMX_TS_INDEX_3                  3

#define MTDMX_KEY_INDEX_0                 MTDMX_TS_INDEX_0
#define MTDMX_KEY_INDEX_1                 MTDMX_TS_INDEX_1
#define MTDMX_KEY_INDEX_2                 MTDMX_TS_INDEX_2
#define MTDMX_KEY_INDEX_PVR               MTDMX_TS_INDEX_PVR
#define MTDMX_KEY_INDEX_3                 MTDMX_TS_INDEX_3

/* STC ID */
#define STC_1                             0
#define STC_2                             1
#define STC_NS                            2

//-------------------------------
// section bitmap
//-------------------------------

#define MTSEC_CNT ((MTDMX_NUM_FILTER_INDEX + 31)/ 32)

#define MTSEC_NUM(filteridx)         \
	(((filteridx) >= 64)? 2 :((filteridx) >= 32)? 1 :0)

#define MTFILTERINDEX(filteridx)         \
		(((filteridx) >= 64)? ((filteridx)-64) :((filteridx) >= 32)? ((filteridx)-32) : (filteridx))


/// Function bitmap of PID operations
#define MTDMX_PID_FLAG_VALID              0x00000001  ///< Enabled or not
#define MTDMX_PID_FLAG_PID                0x00000002  ///< PID value
#define MTDMX_PID_FLAG_BUFFER             0x00000004  ///< Buffer control
#define MTDMX_PID_FLAG_CALLBACK           0x00000008  ///< Callback handler
#define MTDMX_PID_FLAG_SCRAMBLE_STATE     0x00000010  ///< Scrambling state
#define MTDMX_PID_FLAG_DEVICE_ID          0x00000200  ///< Device (decoder) ID
#define MTDMX_PID_FLAG_DISABLE_OUTPUT     0x00020000  ///< Disable FIFO output
#define MTDMX_PID_FLAG_IGNORE_CC_CHECK    0x00800000  ///< Ignore CC check
#define MTDMX_PID_FLAG_LOCAL_TSINDEX      0x00080000  ///< input ts: for ci+1.4 remux ts local index.
#define MTDMX_PID_FLAG_NONE               0           ///< None
#define MTDMX_PID_FLAG_ALL                (0xFFFFFFFF & ~MTDMX_PID_FLAG_DISABLE_OUTPUT)

/// Function bitmap of filter operations
#define MTDMX_FILTER_FLAG_VALID           0x00000001  ///< Enabled or not
#define MTDMX_FILTER_FLAG_PIDX            0x00000002  ///< PID index
#define MTDMX_FILTER_FLAG_OFFSET          0x00000004  ///< Offset
#define MTDMX_FILTER_FLAG_CRC             0x00000008  ///< Check CRC or not
#define MTDMX_FILTER_FLAG_PATTERN         0x00000010  ///< Pattern and mask
#define MTDMX_FILTER_FLAG_NONE            0           ///< None
#define MTDMX_FILTER_FLAG_ALL             0xffffffff  ///< All

/// DRM
#define DMX_MM_DRM_FLAG_OFFSET              0x00000001
#define DMX_MM_DRM_FLAG_ENCRYLEN            0x00000002
#define DMX_MM_DRM_FLAG_CBC                 0x00000004
#define DMX_MM_DRM_FLAG_KEY                 0x00000008
#define DMX_MM_DRM_FLAG_NONE                0x00000000
#define DMX_MM_DRM_FLAG_ALL                 0xFFFFFFFF

#define MTDMX_AES_CMD_SID             (0x2 << 8)
#define MTDMX_MISC_CMD_SID            (0x8 << 8)
#define MTDMX_GCPU_FIFO_ALIGNMENT     (32)
//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
typedef enum
{
#if defined(CC_MT5365)||defined(CC_MT5395)
    MTDMX_FE_EXT_SERIAL0,
    MTDMX_FE_EXT_SERIAL1,
    MTDMX_FE_EXT_PARALLEL,
    MTDMX_FE_EXT_TWOBIT0,
    MTDMX_FE_EXT_TWOBIT1,
    MTDMX_FE_DVB_DEMOD,       // avoid compile error
    MTDMX_FE_ATSC_DEMOD
#elif defined(CC_MT5399)
    MTDMX_FE_INTERNAL = 0,
    //MTDMX_FE_EXTERNAL = 1,
    MTDMX_FE_DDI = 2,
    MTDMX_FE_TSOUT = 3,
    MTDMX_FE_CI = 4,
    MTDMX_FE_EXT_S = 0x10,
    MTDMX_FE_EXT_P = 0x11,
    MTDMX_FE_EXT_2BIT = 0x12,
    MTDMX_FE_EXT2_0_S = 0x20,
    MTDMX_FE_EXT2_0_P = 0x21,
    MTDMX_FE_EXT2_0_2BIT = 0x22,
    MTDMX_FE_EXT2_1_S = 0x30,
    MTDMX_FE_EXT2_2_S = 0x40,
    MTDMX_FE_EXT2_3_S = 0x50,
    MTDMX_FE_EXT2_4_S = 0x60,
    MTDMX_FE_EXT3_0_S = 0x70,
    MTDMX_FE_EXT3_1_S = 0x80,
    MTDMX_FE_EXT4_S = 0x90,
    MTDMX_FE_EXT5_S = 0xA0,
    MTDMX_FE_EXT5_P = 0xA1,
    MTDMX_FE_EXT5_2BIT = 0xA2,

    MTDMX_FE_EXT_LEGACY_P = 0x51,

    MTDMX_FE_NO_TSVALID = 0xE0,
    // following avoid compile error
    MTDMX_FE_EXT_SERIAL0 = 0xF0,
    MTDMX_FE_EXT_SERIAL1 = 0xF1,
    MTDMX_FE_EXT_PARALLEL = 0xF2,
    MTDMX_FE_EXT_TWOBIT0 = 0xF3,
    MTDMX_FE_EXT_TWOBIT1 = 0xF4,
    MTDMX_FE_DVB_DEMOD = 0xF5,
    MTDMX_FE_ATSC_DEMOD = 0xF6,
    MTDMX_FE_NULL = 0xFF
#elif defined(CC_MT5890)
    MTDMX_FE_INTERNAL = 0,
    //MTDMX_FE_EXTERNAL = 1,
    MTDMX_FE_DDI = 2,
    MTDMX_FE_TSOUT = 3,
    MTDMX_FE_CI = 4,
    MTDMX_FE_EXT_S = 0x10,
    MTDMX_FE_EXT_P = 0x11,
    MTDMX_FE_EXT_2BIT = 0x12,
    MTDMX_FE_EXT2_0_S = 0x20,
    MTDMX_FE_EXT2_0_P = 0x21,
    MTDMX_FE_EXT2_0_2BIT = 0x22,
    MTDMX_FE_EXT2_1_S = 0x30,
    MTDMX_FE_EXT2_2_S = 0x40,
    MTDMX_FE_EXT2_3_S = 0x50,
    MTDMX_FE_EXT2_4_S = 0x60,
    MTDMX_FE_EXT3_0_S = 0x70,
    MTDMX_FE_EXT3_1_S = 0x80,
    MTDMX_FE_EXT4_S = 0x90,
    MTDMX_FE_EXT5_S = 0xA0,
    MTDMX_FE_EXT5_P = 0xA1,
    MTDMX_FE_EXT5_2BIT = 0xA2,

    MTDMX_FE_EXT_LEGACY_P = 0x51,

    MTDMX_FE_NO_TSVALID = 0xE0,
    // following avoid compile error
    MTDMX_FE_EXT_SERIAL0 = 0xF0,
    MTDMX_FE_EXT_SERIAL1 = 0xF1,
    MTDMX_FE_EXT_PARALLEL = 0xF2,
    MTDMX_FE_EXT_TWOBIT0 = 0xF3,
    MTDMX_FE_EXT_TWOBIT1 = 0xF4,
    MTDMX_FE_DVB_DEMOD = 0xF5,
    MTDMX_FE_ATSC_DEMOD = 0xF6,
    MTDMX_FE_NULL = 0xFF
#elif defined(CC_MT5398)
    MTDMX_FE_INTERNAL = 0,
    //MTDMX_FE_EXTERNAL = 1,
    MTDMX_FE_DDI = 2,
    MTDMX_FE_TSOUT = 3,
    MTDMX_FE_CI = 4,
    MTDMX_FE_EXT_S = 0x10,
    MTDMX_FE_EXT_P = 0x11,
    MTDMX_FE_EXT_2BIT = 0x12,
    MTDMX_FE_EXT2_0_S = 0x20,
    MTDMX_FE_EXT2_0_P = 0x21,
    MTDMX_FE_EXT2_0_2BIT = 0x22,
    MTDMX_FE_EXT2_1_S = 0x30,
    MTDMX_FE_EXT2_1_P = 0x31,       // Ext2_1 no parallel, test
    MTDMX_FE_EXT2_1_2BIT = 0x32,
    MTDMX_FE_EXT2_2_S = 0x60,        // Serial
    MTDMX_FE_EXT2_2_P = 0x61,        // Parallel, no parallel, test
    MTDMX_FE_EXT3_S = 0x40,
    MTDMX_FE_EXT3_P = 0x41,
    MTDMX_FE_EXT3_2BIT = 0x42,
    MTDMX_FE_EXT_LEGACY_P = 0x51,

    MTDMX_FE_NO_TSVALID = 0xE0,
    // following avoid compile error
    MTDMX_FE_EXT_SERIAL0 = 0xF0,
    MTDMX_FE_EXT_SERIAL1 = 0xF1,
    MTDMX_FE_EXT_PARALLEL = 0xF2,
    MTDMX_FE_EXT_TWOBIT0 = 0xF3,
    MTDMX_FE_EXT_TWOBIT1 = 0xF4,
    MTDMX_FE_DVB_DEMOD = 0xF5,
    MTDMX_FE_ATSC_DEMOD = 0xF6,
    MTDMX_FE_NULL = 0xFF
#elif defined(CC_MT5396)
    MTDMX_FE_INTERNAL = 0,
    //DMX_FE_EXTERNAL = 1,
    MTDMX_FE_DDI = 2,
    MTDMX_FE_TSOUT = 3,
    MTDMX_FE_CI = 4,
    MTDMX_FE_EXT_S = 0x10,
    MTDMX_FE_EXT_P = 0x11,
    MTDMX_FE_EXT_2BIT = 0x12,
    MTDMX_FE_EXT2_0_S = 0x20,
    MTDMX_FE_EXT2_0_P = 0x21,
    MTDMX_FE_EXT2_0_2BIT = 0x22,
    MTDMX_FE_EXT2_1_S = 0x30,
    MTDMX_FE_EXT2_1_P = 0x31,       // Ext2_1 no parallel, test
    MTDMX_FE_EXT2_1_2BIT = 0x32,
    MTDMX_FE_EXT3_S = 0x40,
    MTDMX_FE_EXT3_P = 0x41,
    MTDMX_FE_EXT3_2BIT = 0x42,
    MTDMX_FE_EXT_LEGACY_P = 0x51,
    MTDMX_FE_NO_TSVALID = 0x60,

    // following avoid compile error
    MTDMX_FE_EXT_SERIAL0 = 0xF0,
    MTDMX_FE_EXT_SERIAL1 = 0xF1,
    MTDMX_FE_EXT_PARALLEL = 0xF2,
    MTDMX_FE_EXT_TWOBIT0 = 0xF3,
    MTDMX_FE_EXT_TWOBIT1 = 0xF4,
    MTDMX_FE_DVB_DEMOD = 0xF5,
    MTDMX_FE_ATSC_DEMOD = 0xF6,
    MTDMX_FE_NULL = 0xFF
#elif defined(CC_MT5880)
    MTDMX_FE_INTERNAL = 0,
    //MTDMX_FE_EXTERNAL = 1,
    MTDMX_FE_DDI = 2,
    MTDMX_FE_TSOUT = 3,
    MTDMX_FE_CI = 4,
    MTDMX_FE_EXT_S = 0x10,
    MTDMX_FE_EXT_P = 0x11,
    MTDMX_FE_EXT_2BIT = 0x12,
    MTDMX_FE_EXT_1_S = 0x20,
    MTDMX_FE_EXT_1_P = 0x21,
    MTDMX_FE_EXT_1_2BIT = 0x22,
    MTDMX_FE_EXT_2_S = 0x30,
    MTDMX_FE_EXT_2_P = 0x31,
    MTDMX_FE_EXT_2_2BIT = 0x32,
    MTDMX_FE_EXT2_0_S = 0x40,
    MTDMX_FE_EXT2_0_P = 0x41,
    MTDMX_FE_EXT2_0_2BIT = 0x42,
    MTDMX_FE_EXT3_S = 0x50,

    MTDMX_FE_NO_TSVALID = 0xE0,
#else
    MTDMX_FE_INTERNAL = 0,
    MTDMX_FE_ATSC_DEMOD,
    MTDMX_FE_DVB_DEMOD,
    MTDMX_FE_EXT_PARALLEL,
    MTDMX_FE_EXT_SERIAL
#endif
} MTDMX_FRONTEND_T;

typedef enum
{
    MTDMX_SOURCE_DTV0 = 0,
    MTDMX_SOURCE_DTV1,
    MTDMX_SOURCE_TSFILE0,         // TS file
    MTDMX_SOURCE_TSFILE1,         // TS file
    MTDMX_SOURCE_DRAM0,           // AVI, MKV, ES...
    MTDMX_SOURCE_NUM
} MTDMX_SOURCE_T;

/// PID types
typedef enum
{
    MTDMX_PID_TYPE_NONE = 0,      ///< None
    MTDMX_PID_TYPE_PSI,           ///< PSI
    MTDMX_PID_TYPE_PES,           ///< PES
    MTDMX_PID_TYPE_PES_TIME,      ///< PES with time information
    MTDMX_PID_TYPE_ES_VIDEO,      ///< Video ES
    MTDMX_PID_TYPE_ES_AUDIO,      ///< Audio ES
    MTDMX_PID_TYPE_ES_VIDEOCLIP,  ///< Video clip ES
    MTDMX_PID_TYPE_ES_OTHER,       ///< Other ES
    MTDMX_PID_TYPE_ES_DTCP,
    MTDMX_PID_TYPE_TS_RAW,
    MTDMX_PID_TYPE_PES_AUDIO,
    MTDMX_PID_TYPE_AV_PES
} MTDMX_PID_TYPE_T;

typedef enum
{
    MTDMX_EIT_SET_SECTION = 0,
    MTDMX_EIT_SET_TABLE,
    MTDMX_EIT_SET_CHANNEL,
    MTDMX_EIT_SET_ALL_CHANNEL
}MTDMX_EIT_SET_TYPE_T;

typedef struct 
{
  UINT16 ui2_onid;
  UINT16 ui2_tsid;
  UINT16 ui2_svcid;
}MTDMX_CHANNEL_EIT_KEY_T;

typedef struct 
{
  MTDMX_CHANNEL_EIT_KEY_T e_key;
  UINT8  ui1_tableid; //talbe id 
  UINT8  ui1_version; //talbe version
  UINT8  ui1_secnum; //section number.
}MTDMX_SECTION_KEY_T;

typedef struct
{
  MTDMX_SECTION_KEY_T tSecKey;
  MTDMX_EIT_SET_TYPE_T eSetType;
  BOOL fgSet;
}MTDMX_SECTION_KEY_SET_T;


enum
{
    MTDMX_GCPU_AES_D = MTDMX_AES_CMD_SID,
    MTDMX_GCPU_AES_E,
    MTDMX_GCPU_AESPK_D,
    MTDMX_GCPU_AES_G,
    MTDMX_GCPU_AES_DPAK,
    MTDMX_GCPU_AES_CMAC,
    MTDMX_GCPU_AESPK_DPAK,
    MTDMX_GCPU_AES_EPAK,
    MTDMX_GCPU_AES_D_CMP,
    MTDMX_GCPU_AESPK_E,
    MTDMX_GCPU_AESEK_E,
    MTDMX_GCPU_AESPK_EPAK,
    MTDMX_GCPU_AESPK_DCBC,
    MTDMX_GCPU_AESPK_ECBC,
    MTDMX_GCPU_AESEK_D,
    MTDMX_GCPU_AES_DCBC,
    MTDMX_GCPU_AES_ECBC,
    MTDMX_GCPU_AESPK_EK_D,
    MTDMX_GCPU_AESPK_EK_E,
    MTDMX_GCPU_AESPK_EK_DCBC,
    MTDMX_GCPU_AES_H,
    MTDMX_GCPU_AES_CTR,
    MTDMX_GCPU_AES_OFB,
    MTDMX_GCPU_AES_WRAPD,
    MTDMX_GCPU_AES_WRAPE,
    MTDMX_GCPU_AES,
};

enum
{
    MTDMX_GCPU_MEMCPY = MTDMX_MISC_CMD_SID,
    MTDMX_GCPU_DMA,
    MTDMX_GCPU_SHA_1,
    MTDMX_GCPU_SHA_256,
    MTDMX_GCPU_MD5,
    MTDMX_GCPU_SHA_224,
    MTDMX_GCPU_MEM_XOR,
    MTDMX_GCPU_RNG,
    MTDMX_GCPU_RC4_KSA,
    MTDMX_GCPU_RC4,
    MTDMX_GCPU_ROM_BIST,
    MTDMX_GCPU_PTX,
    MTDMX_GCPU_TSDESC,
    MTDMX_GCPU_TSSCRM
};

typedef enum
{
    MTDMX_CRYPTO_KEY_SECURE_PVR_AES_0 = 0x30,  ///< secure key
    MTDMX_CRYPTO_KEY_SECURE_PVR_AES_IV_0,
    MTDMX_CRYPTO_KEY_MAX
} MTDMX_CRYPTO_KEY_TYPE_T;

typedef enum
{
    MTDMX_TSDESC_188_PACKET_FORM,
    MTDMX_TSDESC_192_PACKET_FORM,
} MTDMX_TSDESC_PACKET_FORM;

typedef enum
{
    MTDMX_TSDESC_FIRST_PACKET_MODE,
    MTDMX_TSDESC_SUCCESSIVE_PACKET_MODE,
} MTDMX_TSDESC_PACKET_MODE;

typedef enum
{
    MTDMX_TSDESC_CIPHER_CLEAR = 0x0,
    MTDMX_TSDESC_CIPHER_ECB,
    MTDMX_TSDESC_CIPHER_CBC,
    MTDMX_TSDESC_CIPHER_CBC_SCTE52,     ///< only in decryption
    MTDMX_TSDESC_CIPHER_CTR             ///< only in decryption
} MTDMX_TSDESC_CIPHER_MODE;

/// Notification code
typedef enum
{
    MTDMX_NOTIFY_CODE_PSI,                  ///< PSI notification
    MTDMX_NOTIFY_CODE_ES,                   ///< ES notification
    MTDMX_NOTIFY_CODE_PES,                  ///< PES notification
    MTDMX_NOTIFY_CODE_PES_TIME,             ///< PES notification with time information
    MTDMX_NOTIFY_CODE_SCRAMBLE_STATE,       ///< Scramble state change notification
    MTDMX_NOTIFY_CODE_OVERFLOW,             ///< Overflow notification
    MTDMX_NOTIFY_CODE_STREAM_ID,            ///< Report pre-parsed Stream IDs
    MTDMX_NOTIFY_CODE_RAW_TS,               ///< Rwa TS notification
    MTDMX_NOTIFY_CODE_SWITCH_COMPLETE,
    MTDMX_NOTIFY_CODE_AV_PES,
    MTDMX_NOTIFY_CODE_RAW_SCRAMBLE_STATE    ///< Raw scramble state change notification
} MTDMX_NOTIFY_CODE_T;

/// Demux notification callback function
typedef MT_RESULT_T (*PFN_MTDMX_NOTIFY)(UINT8 u1Pidx,
                                        MTDMX_NOTIFY_CODE_T eCode,
                                        UINT32 u4Data,
                                        const void* pvNotifyTag);

/// PID data structure
typedef struct
{
    BOOL fgEnable;                  ///< Enable or disable
    BOOL fgAllocateBuffer;          ///< Allocate buffer
    UINT16 u2Pid;                   ///< PID
    UINT32 u4BufAddr;               ///< Buffer address, kernel address
    UINT32 u4BufSize;               ///< Buffer size
    MTDMX_PID_TYPE_T ePidType;      ///< PID type
    PFN_MTDMX_NOTIFY pfnNotify;     ///< Callback function
    void* pvNotifyTag;              ///< Tag value of callback function
    PFN_MTDMX_NOTIFY pfnScramble;   ///< Callback function of scramble state
    void* pvScrambleTag;            ///< Tag value of scramble callback function
    UINT8 u1DeviceId;               ///< Decoder ID
    UINT8 u1ChannelId;              ///< Channel ID
    UINT8 u1TsIndex;                ///< TS index
    UINT8 u1LocalTsIndex;           //local tsindex for ci+1.4
    BOOL fgDisableOutput;           ///< No output
    UINT8 u1ContainAD;              ///< Audio description (0: no-AD, 1: AD, 2: decided by driver) 
    BOOL fgIgnoreCC;                ///< Ignore CC check
} MTDMX_PID_T;


/// Filter structure
typedef struct
{
    BOOL fgEnable;                  ///< Enable or disable
    BOOL fgCheckCrc;                ///< Check CRC or not
    UINT8 u1Pidx;                   ///< PID index, 0 ~ 31
    UINT8 u1Offset;                 ///< Offset
    UINT8 au1Data[16];              ///< Pattern
    UINT8 au1Mask[16];              ///< Mask
} MTDMX_FILTER_T;

/// Filter structure
typedef struct
{
    BOOL fgEnable;                  ///< Enable or disable
    BOOL fgCheckCrc;                ///< Check CRC or not
    UINT8 u1Pidx;                   ///< PID index, 0 ~ 31
    UINT8 u1Offset;                 ///< Offset
    UINT8 au1Data[16];              ///< Pattern
    UINT8 au1Mask[16];              ///< Mask
    UINT8 au1PosNeg[16];            ///< Positive or negative
} MTDMX_GENERIC_FILTER_T;

/// PID counters
typedef struct
{
    UINT32 u4PesCount;              ///< PES counter
    UINT32 u4PicCount;              ///< Picture counter
    UINT32 u4SecCount;              ///< Section counter
} MTDMX_PID_COUNTERS_T;

typedef struct
{
    UINT8 u1TableID;                ///< Table ID
    UINT16 u2SecLen;                ///< Section length
    UINT8 u1VerNum;                 ///< Version number
    UINT32 u4CRC;                   ///< CRC value
} MTDMX_SECTION_HEADER_T;

/// Scrambling state
typedef enum
{
    MTDMX_SCRAMBLE_STATE_CLEAR,           ///< Clear data
    MTDMX_SCRAMBLE_STATE_SCRAMBLED,       ///< Scrambled data
    MTDMX_SCRAMBLE_STATE_UNKNOWN          ///< Unknown data
} MTDMX_SCRAMBLE_STATE_T;

/// Notify info of PSI
typedef struct
{
    UINT32 u4SecAddr;                   ///< Section address, kernel address
    UINT32 u4SecLen;                    ///< Section length
    UINT8 u1SerialNumber;               ///< Serial number
    UINT32 au4MatchBitmap[MTSEC_CNT];               ///< Match section filter bitmap
} MTDMX_NOTIFY_INFO_PSI_T;

/// Notify info of PES data
typedef struct
{
    UINT32 u4DataAddr;                  ///< Data address, kernel address
    UINT32 u4DataSize;                  ///< Data size
    UINT8 u1SerialNumber;               ///< Serial number
} MTDMX_NOTIFY_INFO_PES_T;

/// Notify info of PES TIME data
typedef struct
{
    UINT32 u4DataAddr;                  ///< Data address, kernel address
    UINT32 u4DataSize;                  ///< Data size
    UINT32 u4Pts;
    UINT32 u4Dts;
    UINT8 u1SerialNumber;               ///< Serial number
} MTDMX_NOTIFY_INFO_PES_TIME_T;

/// Notify info of raw TS data
typedef struct
{
    UINT32 u4DataAddr;                  ///< Data address
    UINT32 u4DataSize;                  ///< Data size
    UINT8 u1SerialNumber;
} MTDMX_NOTIFY_INFO_RAW_TS_T;

typedef enum
{
    MTDMX_VIDEO_MPEG,
    MTDMX_VIDEO_H264,
    MTDMX_VIDEO_AVS,
    MTDMX_VIDEO_VC1,
    MTDMX_VIDEO_MPEG4
} MTDMX_VIDEO_TYPE_T;

/// Descrambling schemes
typedef enum
{
    MTDMX_DESC_MODE_NONE = 0,             ///< None
    MTDMX_DESC_MODE_DES_ECB,              ///< DES ECB
    MTDMX_DESC_MODE_DES_CBC,              ///< DES CBC
    MTDMX_DESC_MODE_3DES_ECB,             ///< 3DES ECB
    MTDMX_DESC_MODE_3DES_CBC,             ///< 3DES CBC
    MTDMX_DESC_MODE_DVB,                  ///< DVB
    MTDMX_DESC_MODE_DVB_CONF,             ///< DVB conformance
    MTDMX_DESC_MODE_MULTI2_BIG,           ///< Multi-2 big-endian
    MTDMX_DESC_MODE_MULTI2_LITTLE,        ///< Multi-2 little-endian
    MTDMX_DESC_MODE_AES_ECB,              ///< AES ECB
    MTDMX_DESC_MODE_AES_CBC               ///< AES CBC
} MTDMX_DESC_MODE_T;

/// Descrambling residual termination block(RTB)
typedef enum
{
    MTDMX_DESC_RTB_MODE_CLEAR = 0,        ///< leave clear
    MTDMX_DESC_RTB_MODE_CTS,              ///< CTS
    MTDMX_DESC_RTB_MODE_SCTE52,           ///< SCTE-52
    MTDMX_DESC_RTB_MODE_MAX,              ///< END
} MTDMX_DESC_RTB_MODE_T;

typedef enum
{
    MTDMX_KEY_BIT_LEN_40 = 40,
    MTDMX_KEY_BIT_LEN_64 = 64,
    MTDMX_KEY_BIT_LEN_128 = 128,
    MTDMX_KEY_BIT_LEN_192 = 192,
    MTDMX_KEY_BIT_LEN_256 = 256,
} MTDMX_KEY_BIT_LEN;

typedef enum
{
    MTDMX_BLOCK_CIPHER_MODE_ECB,
    MTDMX_BLOCK_CIPHER_MODE_CBC,
    MTDMX_BLOCK_CIPHER_MODE_OFB,
    MTDMX_BLOCK_CIPHER_MODE_CTR,
} MTDMX_BLOCK_CIPHER_MODE;

typedef enum
{
    MTDMX_TSOUT_PATH_INTERNAL,
    MTDMX_TSOUT_PATH_EXTERNAL,
    MTDMX_TSOUT_PATH_DISABLE,
    MTDMX_TSOUT_STEER_DBM,
    MTDMX_TSOUT_STEER_TSOUT,
    MTDMX_TSOUT_PATH_UNKNOWN
} MTDMX_TSOUT_PATH_T;

typedef struct
{
    BOOL fgCBC;
    BOOL fgEncrypt;
    UINT8 au1IV[16];
    UINT32 u4KeyBitLen;
    UINT8 au1Key[32];
    UINT32 u4Offset;
    UINT32 u4EncryLen;
} MTDMX_DRM_AES_T;

typedef struct
{
    UINT32 u4SrcStartAddr;
    UINT32 u4SrcBufStart;
    UINT32 u4SrcBufEnd;
    UINT32 u4DstStartAddr;
    UINT32 u4DstBufStart;
    UINT32 u4DstBufEnd;
    UINT32 u4DatLen;
    UINT8 au1Key[32];
    UINT8 au1Iv[16];
    MTDMX_KEY_BIT_LEN eKeyBitLen;
    MTDMX_BLOCK_CIPHER_MODE eMode;
    BOOL fgEncrypt;
} MTDMX_AES_PARAM_T;

typedef struct
{
    UINT32 u4Size;
    UINT32 u4SrcAddr;
    UINT32 u4DstAddr;
} MTDMX_DRM_AES_BLKDATA_T;

typedef enum
{
    MTDMX_PID_INSRC_DTV,                    // PID from NIM
    MTDMX_PID_INSRC_TIMESHIFT_PLAY,         // PID from time-shift play
    MTDMX_PID_INSRC_MM,                     // PID from multimedia (USB or network)
} MTDMX_PID_INSRC_T;

typedef struct
{
    UINT32 u4SrcStartAddr;
    UINT32 u4SrcBufStart;
    UINT32 u4SrcBufEnd;
    UINT32 u4DstStartAddr;
    UINT32 u4DstBufStart;
    UINT32 u4DstBufEnd;
    UINT32 u4DatLen;
    MTDMX_TSDESC_PACKET_FORM eForm;
    MTDMX_TSDESC_PACKET_MODE eMode;
    MTDMX_TSDESC_CIPHER_MODE eCipher;
    MTDMX_KEY_BIT_LEN eKeyBitLen;
    BOOL fgEncryptByEvenKey;
    UINT32 u4TsState[4];
    UINT8 au1Key[2][16];
    UINT8 au1Iv[2][16];
} MTDMX_GCPU_TSDESC_PARAM_T;

typedef struct
{
    UINT32 u4SrcStartAddr;
    UINT32 u4SrcBufStart;
    UINT32 u4SrcBufEnd;
    UINT32 u4DatLen;
    UINT64 u8BitCnt;
    UINT8 au1Hash[32];
    BOOL fgFirstPacket;
    BOOL fgLastPacket;
} MTDMX_GCPU_MD_PARAM_T;

typedef enum
{
    MTDMX_CONN_TYPE_TUNER_0 = 0,
    MTDMX_CONN_TYPE_TUNER_1,
    MTDMX_CONN_TYPE_TUNER_2,
    MTDMX_CONN_TYPE_TUNER_MAX,
    MTDMX_CONN_TYPE_BUFAGENT_0,
    MTDMX_CONN_TYPE_BUFAGENT_1,
    MTDMX_CONN_TYPE_BUFAGENT_2,
    MTDMX_CONN_TYPE_BUFAGENT_3,
    MTDMX_CONN_TYPE_BUFAGENT_4,
    MTDMX_CONN_TYPE_BUFAGENT_MAX,
    MTDMX_CONN_TYPE_NONE,
} MTDMX_CONN_TYPE_T;


typedef struct
{
    BOOL fgValid;
    MTDMX_CONN_TYPE_T eConType;
} MTDMX_PID_INFO_T;

typedef struct
{
    MTDMX_DESC_MODE_T eMode;
    UINT8 u1Index;
    BOOL fgEven;
    UINT8 *pu1UniqueKey;
    BOOL fgWrappedKey;
    UINT8 *pu1Key;
    UINT8 u1KeyLen;
    BOOL fgWarppedIV;
    UINT8 *pu1IV;
    UINT8 u1IvLen;
    MTDMX_DESC_RTB_MODE_T eRtbMode;
} MTDMX_VUDU_KEY_T;

typedef struct
{
    UINT8 u1PbPidFilterNum;
    UINT8 u1RecPidFilterNum;
    UINT8 u1PbSecFilterNum;
    UINT8 u1FramerNum;
    UINT8 u1CaKeyNum;
    UINT8 u1StcNum;
}MTDMX_HW_INFO_T;

//-----------------------------------------------------------------------------
// Macro definitions
//-----------------------------------------------------------------------------
#define MTDMX_GCPU_LINER_BUFFER_START(u4Addr) (((u4Addr) % MTDMX_GCPU_FIFO_ALIGNMENT) == 0)?(u4Addr): \
                                    (u4Addr) - ((u4Addr) % MTDMX_GCPU_FIFO_ALIGNMENT)

#define MTDMX_GCPU_LINER_BUFFER_END(u4Addr) (((u4Addr) % MTDMX_GCPU_FIFO_ALIGNMENT) == 0)?(u4Addr): \
                                    (u4Addr) + (MTDMX_GCPU_FIFO_ALIGNMENT - ((u4Addr) % MTDMX_GCPU_FIFO_ALIGNMENT))

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/** MTDMX_Init
 *  Init demux driver
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_Init(void);

//-----------------------------------------------------------------------------
/** MTDMX_RegCbFunc
 *  register callback for  demux driver
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_RegCbFunc(void);


//-----------------------------------------------------------------------------
/** MTDMX_Reset
 *  Reset demux driver
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_Reset(void) ;

//-----------------------------------------------------------------------------
/** MTDMX_SetFrontEnd
 *  Select a front end type, this is a deprecated function, please use MTDMX_SetFrontEnd instead.
 *  @param eFE                         Front end type
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetFrontEnd (MTDMX_FRONTEND_T eFE);

//-----------------------------------------------------------------------------
/** MTDMX_SetFrontEndEx
 *  Select a front end type for a TS path
 *  @param u1TsIdx                     TS index, 0 ~ (MTDMX_NUM_TS_INDEX - 1)
 *  @param eFE                         Front end type
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetFrontEndEx (UINT8 u1TsIdx, MTDMX_FRONTEND_T eFE);

//-----------------------------------------------------------------------------
/** MTDMX_SetVideoType
 *  Select a video type
 *  @param eType                       Video type
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetVideoType (MTDMX_VIDEO_TYPE_T eType);


//-----------------------------------------------------------------------------
/** MTDMX_SetVideoTypeEx
 *  Select a video type by ts_idx.
 *  @param eType                      u1TsIdx, Video type
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetVideoTypeEx (UINT8 u1TsIdx,MTDMX_VIDEO_TYPE_T eType);

EXTERN MT_RESULT_T MTDMX_SetVideoTypeByPidx (UINT8 u1Pidx,MTDMX_VIDEO_TYPE_T eType);


EXTERN MT_RESULT_T MTDMX_SetFramerPacketSize(UINT8 u1TsIdx,UINT8 u1Size);

//-----------------------------------------------------------------------------
/** MTDMX_Start
 *  Start demux
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_Start (void);

//-----------------------------------------------------------------------------
/** MTDMX_Stop
 *  Stop demux
 *  @retval MTR_OK                     Success.
 *  @retval MTR_NOT_OK                 Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_Stop (void);

//-----------------------------------------------------------------------------
/** MTDMX_SetPid
 *  Set a PID
 *
 *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
 *  @param  u4Flags         Function flags
 *  @param  prPid           The PID structure of the PES
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPid (UINT8 u1Pidx, UINT32 u4Flags, const MTDMX_PID_T *prPid);

//-----------------------------------------------------------------------------
/** MTDMX_SetFilePid
 *  Set a file PID, this is for TS file PID
 *
 *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
 *  @param  u4Flags         Function flags
 *  @param  prPid           The PID structure of the PES
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetFilePid (UINT8 u1Pidx, UINT32 u4Flags, const MTDMX_PID_T *prPid);

//-----------------------------------------------------------------------------
/** MTDMX_GetPid
 *  Get a PID
 *
 *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
 *  @param  u4Flags         Function flags
 *  @param  prPid           The PID structure of the PES
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetPid (UINT8 u1Pidx, UINT32 u4Flags, MTDMX_PID_T *prPid);

//-----------------------------------------------------------------------------
/** MTDMX_FreePid
 *  Free a PID
 *
 *  @param  u1Pidx          PID index, 0 ~ (MTDMX_NUM_PID_INDEX - 1)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_FreePid (UINT8 u1Pidx);

//-----------------------------------------------------------------------------
/** MTDMX_GetPidIndex
 *  Find PID index for a given PID value
 *
 *  @param  u2Pid           PID
 *  @param  pu1PidIndex [out]
 *                          The PID index if found
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetPidIndex (UINT16 u2Pid, UINT8 *pu1PidIndex);

//-----------------------------------------------------------------------------
/** MTDMX_GetEsFifo
 *  Get Es fifo data size accord gaving pidx.
 *
 *  @param  u1Pidx
 *  @param  pu4Size [out]
 *                          The size base on pidx
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_GetEsFifo (UINT8 u1Pidx, UINT32 *pu4Size);

//-----------------------------------------------------------------------------
/**
 *  MTDMX_GetPacketStatus
 *  Get recived and drop packet counnt in a special moninter interval
 *
 *  @param  u1Tsidx         TS index, 0 ~ (MTDMX_NUM_TS_INDEX - 1)
 *  @param  u4MsTime        monitor interval
 *  @param  pu4RcvCount [out]
 *                          The count of recieved packet
 *  @param  pu4DropCount [out]
 *                          The count of dropped packet
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_GetPacketStatus(UINT8 u1Tsidx , UINT32 u4MsTime, UINT32 *pu4RcvCount, UINT32 *pu4DropCount);

//-----------------------------------------------------------------------------
/** MTDMX_SetVideoPid
 *  Set a Video Pid
 *
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  u2PidNum		Video PID number
 *  @param  fgEnable		Enable video pid or not
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetVideoPid (UINT8 u1Pidx, UINT16 u2PidNum, BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTDMX_SetAudioPid
 *  Set a Audio Pid
 *
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  u2PidNum		Audio PID number
 *  @param  fgEnable		Enable audio pid or not
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAudioPid (UINT8 u1Pidx, UINT16 u2PidNum, BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTDMX_SetAudioDescriptPid
 *  Set a audio decription Pid
 *
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  u2PidNum		Audio PID number
 *  @param  fgEnable		Enable audio pid or not
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAudioDescriptPid (UINT8 u1Pidx, UINT16 u2PidNum, BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTDMX_SetPcrPid
 *  Set a PCR Pid to one PID index
 *
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  u2PcrPid		PCR PID number
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPcrPid (UINT8 u1Pidx, UINT16 u2PcrPid);

//-----------------------------------------------------------------------------
/** MTDMX_SetPcrPidEx
 *  Set a PCR Pid to one PID index
 *
 *  @param  u1TsIdx         TS index (0 - 3)
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  u1StcSet        Stc set (0 - 1)
 *  @param  u2PcrPid        PCR PID number
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPcrPidEx (UINT8 u1TsIdx, UINT8 u1Pidx, UINT8 u1StcSet, UINT16 u2PcrPid);

//-----------------------------------------------------------------------------
/** MTDMX_SetPcr
 *  Enable or disable a PCR PID
 *
 *  @param  u1PidIndex      PID index (0 - 31)
 *  @param  fgEnable        Enable PCR of the PID or not
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPcr (UINT8 u1Pidx, BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTDMX_SetFilter
 *  Setup a section filter
 *
 *  @param  u1FilterIndex   Filter index,  0 ~ (MTDMX_NUM_FILTER_INDEX - 1)
 *  @param  u4Flags         Function flags
 *  @param  prFilter        Filter structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetFilter (UINT8 u1FilterIndex,
                                    UINT32 u4Flags,
                                    const MTDMX_FILTER_T *prFilter);

//-----------------------------------------------------------------------------
/** MTDMX_GetFilter
 *  Get a section filter
 *
 *  @param  u1FilterIndex   Filter index,  0 ~ (MTDMX_NUM_FILTER_INDEX - 1)
 *  @param  u4Flags         Function flags
 *  @param  prFilter        Filter structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetFilter (UINT8 u1FilterIndex,
                                    UINT32 u4Flags,
                                    MTDMX_FILTER_T *prFilter);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_AllocateBuffer
 *  Allocate section buffer pool
 *
 *  @param  u4Size          Buffer size
 *  @param  pu4Addr         Return kernel address
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_AllocateBuffer (UINT32 u4Size, UINT32 *pu4Addr);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_FreeBuffer
 *  Free a section buffer pool
 *  @param  u4Addr          Buffer address
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_FreeBuffer (UINT32 u4Addr);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_GetBuffer
 *  Copy data from a section buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4FrameAddr     Frame address (Kernel address)
 *  @param  u4SkipSize      Skip size before copying
 *  @param  u4CopySize      Data size to copy
 *  @param  pu1Dest         Destination buffer (User address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_GetBuffer(UINT8 u1Pidx,
                                       UINT8 u1SerialNumber,
                                       UINT32 u4FrameAddr,
                                       UINT32 u4SkipSize,
                                       UINT32 u4CopySize,
                                       UCHAR* pu1Dest);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_UnlockBuffer
 *  Unlock a section buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4Size          Unlocked data size
 *  @param  u4FrameAddr     Original frame address (Kernel address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_UnlockBuffer(UINT8 u1Pidx,
                                          UINT8 u1SerialNumber,
                                          UINT32 u4Size,
                                          UINT32 u4FrameAddr);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_FlushBuffer
 *  Flush a section buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_FlushBuffer (UINT8 u1Pidx);

//-----------------------------------------------------------------------------
/** MTDMX_PSI_GetBufferSectionHeader
 *  Get section header and CRC
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4SkipSize      Skip size before copying
 *  @param  u4SecSize       Section size
 *  @param  prHeaderCRC     Section header/CRC structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PSI_GetBufferSectionHeader(UINT8 u1Pidx,
                                             UINT8 u1SerialNumber,
                                             UINT32 u4FrameAddr,
                                             UINT32 u4SkipSize,
                                             UINT32 u4SecSize,
                                             MTDMX_SECTION_HEADER_T *prHeader);

//-----------------------------------------------------------------------------
/** MTDMX_PES_AllocateBuffer
 *  Allocate PES buffer pool
 *
 *  @param  u4Size          Buffer size
 *  @param  pu4Addr         Return allocated buffer address (Kernel address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PES_AllocateBuffer (UINT32 u4Size, UINT32 *pu4Addr);

//-----------------------------------------------------------------------------
/** MTDMX_PES_FreeBuffer
 *  Free a PES buffer pool
 *  @param  u4Addr          Buffer address
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PES_FreeBuffer (UINT32 u4Addr);


//-----------------------------------------------------------------------------
/** MTDMX_PES_UnlockBuffer
 *  Unlock a PES buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4Size          Unlocked data size
 *  @param  u4FrameAddr     Original frame address (Kernel address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PES_UnlockBuffer (UINT8 u1Pidx,
                                           UINT8 u1SerialNumber,
                                           UINT32 u4Size,
                                           UINT32 u4FrameAddr);

//-----------------------------------------------------------------------------
/** MTDMX_PES_FlushBuffer
 *  Flush a PES buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PES_FlushBuffer (UINT8 u1Pidx);

//-----------------------------------------------------------------------------
/** MTDMX_PES_GetBuffer
 *  Copy data from a PES buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4FrameAddr     Frame address (Kernel mode address)
 *  @param  u4SkipSize      Skip size before copying
 *  @param  u4CopySize      Data size to copy
 *  @param  pu1Dest         Destination buffer (User mode address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_PES_GetBuffer (UINT8 u1Pidx,
                                        UINT8 u1SerialNumber,
                                        UINT32 u4FrameAddr,
                                        UINT32 u4SkipSize,
                                        UINT32 u4CopySize,
                                        UCHAR *pu1Dest);

//-----------------------------------------------------------------------------
/** MTDMX_RawTs_GetBuffer
 *  Copy data from a raw TS buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4FrameAddr     Frame address (Kernel mode address)
 *  @param  u4SkipSize      Skip size before copying
 *  @param  u4CopySize      Data size to copy
 *  @param  pu1Dest         Destination buffer (User mode address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_RawTs_GetBuffer (UINT8 u1Pidx,
                                        UINT8 u1SerialNumber,
                                        UINT32 u4FrameAddr,
                                        UINT32 u4SkipSize,
                                        UINT32 u4CopySize,
                                        UCHAR *pu1Dest);

//-----------------------------------------------------------------------------
/** MTDMX_RawTs_UnlockBuffer
 *  Unlock a PES buffer
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  u1SerialNumber  The serial number
 *  @param  u4Size          Unlocked data size
 *  @param  u4FrameAddr     Original frame address (Kernel address)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
MT_RESULT_T MTDMX_RawTs_UnlockBuffer (UINT8 u1Pidx,
                                           UINT8 u1SerialNumber,
                                           UINT32 u4Size,
                                           UINT32 u4FrameAddr);

//-----------------------------------------------------------------------------
/** MTDMX_GetPidCounters
 *  Get the counter structure of a given pid index
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  prCounters [output]
 *                          Pointer to the PID counter structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetPidCounters (UINT8 u1Pidx,
                             MTDMX_PID_COUNTERS_T *const prCounters);

//-----------------------------------------------------------------------------
/** MTDMX_ResetPidCounters
 *  Reset counters of a given pid index
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_ResetPidCounters (UINT8 u1Pidx);

//-----------------------------------------------------------------------------
/** MTDMX_GetLockStateEx
 *  Get lock state
 *  @param  u1TsIdx          TS index, 0 ~ 3
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetLockStateEx (UINT8 u1TsIdx, BOOL *pfgLock);


//-----------------------------------------------------------------------------
/** MTDMX_GetLockState
 *  Get lock State  - only for ts index 0
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetLockState (BOOL *pfgLock);


//-----------------------------------------------------------------------------
/** MTDMX_GetScrambleState
 *  Get scramble state
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  peScramble_Sstate    the pointer of  scramble state
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetScrambleState(UINT8 u1Pidx,MTDMX_SCRAMBLE_STATE_T* peScramble_State);

//-----------------------------------------------------------------------------
/** MTDMX_GetScrambleState
 *  Get scramble state
 *
 *  @param  u1Pidx          PID index, 0 ~ 31
 *  @param  peScramble_Sstate    the pointer of  scramble state
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetRawScrambleState(UINT8 u1Pidx,MTDMX_SCRAMBLE_STATE_T* peScramble_State);

//-----------------------------------------------------------------------------
/** MTDMX_GetCurSTC
 *  Get STC value, this function will get STC 0 value, if you like to get STC 1 value, please use MTDMX_GetCurSTCEx()
 *  @param  pu4StcHi        High half of the STC value
 *  @param  pu4StcLo        Low half of the STC value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetCurSTC(UINT32 *pu4StcHi, UINT32 *pu4StcLo);

//-----------------------------------------------------------------------------
/** MTDMX_GetCurSTCEx
 *  Get STC value
 *  @param  u1StcSet        STC index, 0 ~ 1
 *  @param  pu4StcHi        High half of the STC value
 *  @param  pu4StcLo        Low half of the STC value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetCurSTCEx(UINT8 u1StcSet, UINT32 *pu4StcHi, UINT32 *pu4StcLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetGenericFilter
 *  Setup a generic section filter (including postive / negative match)
 *
 *  @param  u1FilterIndex   Filter index (0 - 31)
 *  @param  u4Flags         Function flags
 *  @param  prFilter        Filter structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetGenericFilter (UINT8 u1FilterIndex,
                                    UINT32 u4Flags,
                                    const MTDMX_GENERIC_FILTER_T *prFilter);

//-----------------------------------------------------------------------------
/** MTDMX_GetGenericFilter
 *  Get generic section filter setting
 *
 *  @param  u1FilterIndex   Filter index (0 - 31)
 *  @param  u4Flags         Function flags
 *  @param  prFilter        Filter structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetGenericFilter (UINT8 u1FilterIndex,
                                    UINT32 u4Flags,
                                    MTDMX_GENERIC_FILTER_T *prFilter);

//-----------------------------------------------------------------------------
/** MTDMX_SetDesKey
 *  Set DES desrambler key
 *
 *  @param  u1Index         The key index
 *  @param  fg3Des          TRUE: 3DES, FALSE: DES
 *  @param  fgEven          TRUE: even key, FALSE: odd key
 *  @param  au4Key          The key
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDesKey(UINT8 u1Index, BOOL fg3Des, BOOL fgEven, const UINT32 au4Key[6]);

//-----------------------------------------------------------------------------
/** MTDMX_SetDesIV
 *  Set the initial vector of DES, a deprecated function, please use MTDMX_SetDesEvenOddIVEx() instead
 *
 *  @param  u4IvHi          The high word of the initial vector
 *  @param  u4IvLo          The low word of the initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDesIV(UINT32 u4IvHi, UINT32 u4IvLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetDesEvenOddIVEx
 *  Set the even/odd initial vector of DES
 *
 *  @param  u1Index         The key index
 *  @param  fgEven          Even or odd
 *  @param  u4IvHi          The high word of the initial vector
 *  @param  u4IvLo          The low word of the initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDesEvenOddIVEx(UINT8 u1Index, BOOL fgEven, UINT32 u4IvHi, UINT32 u4IvLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetRtbMode
 *  Set RTB mode - select a residual termniation block handling algorithm
 *
 *  @param  u1Index         The key index
 *  @param  eMode           MTDMX_DESC_RTB_MODE_T
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetRtbMode(UINT8 u1Index, MTDMX_DESC_RTB_MODE_T eMode);

//-----------------------------------------------------------------------------
/** MTDMX_SetDesRtbMode
 *  Set RTB mode of DES
 *
 *  @param  eMode           MTDMX_DESC_RTB_MODE_T
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDesRtbMode(MTDMX_DESC_RTB_MODE_T eMode);

//-----------------------------------------------------------------------------
/** MTDMX_SetDesRtbModeEx
 *  Set RTB mode of DES
 *
 *  @param  u1Index         The key index
 *  @param  eMode           MTDMX_DESC_RTB_MODE_T
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDesRtbModeEx(UINT8 u1Index, MTDMX_DESC_RTB_MODE_T eMode);

//-----------------------------------------------------------------------------
/** MTDMX_SetAesKeyLen
 *  Set AES key len, this is a deprecated function, please use MTDMX_SetAesKeyLenEx() instead.
 *
 *  @param  u4KeyLen        The key length
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesKeyLen(UINT32 u4KeyLen);

//-----------------------------------------------------------------------------
/** MTDMX_SetAesKeyLenEx
 *  Set AES key len
 *
 *  @param  u1Index         The key index
 *  @param  u4KeyLen        The key length
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesKeyLenEx(UINT8 u1Index, UINT32 u4KeyLen);

//-----------------------------------------------------------------------------
/** MTDMX_SetAesKey
 *  Set AES key
 *
 *  @param  u1Index         The key index
 *  @param  fgEven          If fgEven=TRUE means set even key
 *  @param  au4Key          The key value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesKey(UINT8 u1Index, BOOL fgEven, const UINT32 au4Key[8]);

//-----------------------------------------------------------------------------
/** Set the initial vector of AES
 *
 *  @param  au4Iv           The initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesIV(const UINT32 au4Iv[4]);

//-----------------------------------------------------------------------------
/** Set the even/odd initial vector of AES
 *
 *  @param  eType           Initial vector type
 *  @param  au4Iv           The initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesEvenOddIV(BOOL fgEven, const UINT32 au4Iv[4]);

//-----------------------------------------------------------------------------
/** Set the even/odd initial vector of AES
 *
 *  @param  u1Index         The key index
 *  @param  eType           Initial vector type
 *  @param  au4Iv           The initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesEvenOddIVEx(UINT8 u1Index, BOOL fgEven, const UINT32 au4Iv[4]);

//-----------------------------------------------------------------------------
/** Set RTB mode of AES
 *
 *  @param  eMode           MTDMX_DESC_RTB_MODE_T
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesRtbMode(MTDMX_DESC_RTB_MODE_T eMode);


//-----------------------------------------------------------------------------
/** Set RTB mode of AES
 *
 *  @param  u1Index         The key index
 *  @param  eMode           MTDMX_DESC_RTB_MODE_T
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesRtbModeEx(UINT8 u1Index, MTDMX_DESC_RTB_MODE_T eMode);

//-----------------------------------------------------------------------------
/** Set AES on off
 *
 *  @param  fgAesOn         Enable or disable
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetAesOn(BOOL fgAesOn);

//-----------------------------------------------------------------------------
/** MTDMX_SetDVBKey
 *
 *  @param  u1Index         The key index
 *  @param  fgEven          If fgEven=TRUE means set even key
 *  @param  au4Key          The key value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDVBKey(UINT8 u1Index, BOOL fgEven, UINT32 au4Key[2]);

//-----------------------------------------------------------------------------
/** MTDMX_SetDVBIV
 *
 *  @param  u1Index         The key index
 *  @param  fgEven          If fgEven=TRUE means set even key
 *  @param  u4IvHi          The initial vector
 *  @param  u4IvLo          The initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDVBIV(UINT8 u1Index, BOOL fgEven, UINT32 u4IvHi, UINT32 u4IvLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetCryptoKey
 *  Set crypto key
 *
 *  @param  u1KeyIdx        The key index
 *  @param  fgEven          If fgEven=TRUE means set even key
 *  @param  eKeyType        The key type 
 *  @param  pu1Key          Pointer to the key value
 *  @param  u4KeyLen        The key length 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetCryptoKey(UINT8 u1KeyIdx, BOOL fgEven, MTDMX_CRYPTO_KEY_TYPE_T eKeyType,
                                    const UINT8 *pu1Key, UINT32 u4KeyLen);

//-----------------------------------------------------------------------------
/** Set the descramble mode and key index to the specific DTV PID
 *
 *  @param  u1Pidx          PID index value
 *  @param  eDescMode       Descramble mode
 *  @param  u1KyeIndex      Key index value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetDescramblPid(UINT8 u1Pidx, MTDMX_DESC_MODE_T eDescMode, UINT8 u1KeyIndex);

//-----------------------------------------------------------------------------
/** Set the descramble mode and key index to the specific MM PID
 *
 *  @param  u1Pidx          PID index value
 *  @param  eDescMode       Descramble mode
 *  @param  u1KyeIndex      Key index value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetFileDescramblPid(UINT8 u1Pidx, MTDMX_DESC_MODE_T eDescMode, UINT8 u1KeyIndex);

//-----------------------------------------------------------------------------
/**
 *  Setup AES decryption engine
 *
 *  @param  u4Flags         Function flags
 *  @param  prDRM           AES structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_SetDecryptInfo(UINT32 u4Flags, const MTDMX_DRM_AES_T *prDRM);

//-----------------------------------------------------------------------------
/**
 *  Use AES decryption engine to decrypt data
 *
 *  @param  prBlkData       AES block structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_MoveBlockData(const MTDMX_DRM_AES_BLKDATA_T *prBlkData);

//-----------------------------------------------------------------------------
/**
 *  Allocate an AES decryption engine - extension version
 *
 *  @param  u1Idx           engine index (0 - 31)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_AllocEngine(UINT8 *pu1Idx);

//-----------------------------------------------------------------------------
/**
 *  Free an AES decryption engine - extension version
 *
 *  @param  u1Idx           engine index (0 - 31)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_FreeEngine(UINT8 u1Idx);

//-----------------------------------------------------------------------------
/**
 *  Setup AES decryption engine - extension version
 *
 *  @param  u1Idx           engine index (0 - 31)
 *  @param  u4Flags         Function flags
 *  @param  prDRM           AES structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_SetDecryptInfoEx(UINT8 u1Idx, UINT32 u4Flags, const MTDMX_DRM_AES_T *prDRM);

//-----------------------------------------------------------------------------
/**
 *  Use AES decryption engine to decrypt data - extension version
 *
 *  @param  u1Idx           engine index (0 - 31)
 *  @param  prBlkData       AES block structure
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_AES_MoveBlockDataEx(UINT8 u1Idx, const MTDMX_DRM_AES_BLKDATA_T *prBlkData);
//-----------------------------------------------------------------------------
/**
 *  Send GCPU command
 *
 *  @param  u4Handle        GCPU Handle
 *  @param  u4Cmd           Command
 *  @param  pvParam         Parameter pointer
 *  @param  u4ParamSize     Parameter size
 *  @param  fgIommu         Use IOMMU
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GCPU_Cmd(UINT32 u4Handle, UINT32 u4Cmd, void *pvParam, UINT32 u4ParamSize, BOOL fgIommu);

//-----------------------------------------------------------------------------
/**
 *  Query DRM buffer
 *
 *  @param  pVA             Virtual address of DRM buffer
 *  @param  pPA             Physical address of DRM buffer
 *  @param  pu4Size         Size of DRM buffer
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_GetDRMBuffer(UINT32 *pu4VA, UINT32 *pu4PA, UINT32 *pu4Size);

//-----------------------------------------------------------------------------
/**
 *  Release DRM buffer
 *
 *  @param  pVA             Virtual address of DRM buffer
 *  @param  pu4Size         Size of DRM buffer
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_ReleaseDRMBuffer(UINT32 u4VA, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** Set PID input source type
 *
 *  @param  u1Pidx          PID index value
 *  @param  eType           PID input source type
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPidInputSource(UINT8 u1Pidx, MTDMX_PID_INSRC_T eType);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2Config
 *
 *  @param  u1Index         Key index
 *  @param  fgOfbFreeRun    Configuration value, usually use TRUE
 *  @param  u2Iteration     Configuration value, usually use 0x120
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2Config(UINT8 u1Index, BOOL fgOfbFreeRun, UINT16 u2Iteration);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2Key
 *
 *  @param  u1Index         Key index
 *  @param  fgOfbFreeRun    Configuration value, usually use TRUE
 *  @param  u2Iteration     Configuration value, usually use 0x120
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2Key(UINT8 u1Index, BOOL fgEven, UINT32 au4Key[2]);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2KeyEx
 *
 *  @param  u1Index         Key index
 *  @param  fgEven          Even key or Odd key
 *  @param  pu1Key          key values
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2KeyEx(UINT8 u1Index, BOOL fgEven, UINT8 *pu1Key);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2SysKey
 *
 *  @param  u1Index         Key index
 *  @param  au4Key          key values
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2SysKey(UINT8 u1Index, UINT32 au4Key[8]);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2SysKeyEx
 *
 *  @param  u1Index         Key index
 *  @param  pu1SysKey       key values
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2SysKeyEx(UINT8 u1Index, UINT8 *pu1SysKey);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2CbcIV
 *
 *  @param  u1Index         Key index
 *  @param  u4IvHi          Initial vector
 *  @param  u4IvLo          Initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2CbcIV(UINT8 u1Index, UINT32 u4IvHi, UINT32 u4IvLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2CbcIV
 *
 *  @param  u1Index         Key index
 *  @param  pu1CBC          Initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2CbcIVEx(UINT8 u1Index, UINT8 *pu1CBC);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2OfbIV
 *
 *  @param  u1Index         Key index
 *  @param  u4IvHi          Initial vector
 *  @param  u4IvLo          Initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2OfbIV(UINT8 u1Index, UINT32 u4IvHi, UINT32 u4IvLo);

//-----------------------------------------------------------------------------
/** MTDMX_SetMulti2OfbIVEx
 *
 *  @param  u1Index         Key index
 *  @param  pu1OFB          Initial vector
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetMulti2OfbIVEx(UINT8 u1Index, UINT8 *pu1OFB);

//-----------------------------------------------------------------------------
/** MTDRM_BIM_GetDeviceData
 *  Get device data
 *
 *  @param  pu1Buf          Buffer pointer
 *  @param  u4Size          Buffer size
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRM_BIM_GetDeviceData(UINT8 *pu1Buf, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** MTDRM_BIM_GetDmKey
 *  Get DM key
 *
 *  @param  pu1Buf          Buffer pointer
 *  @param  u4Size          Buffer size
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRM_BIM_GetDmKey(UINT8 *pu1Buf, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** MTDRM_BIM_GetULPK
 *  Get ULPK key
 *
 *  @param  pu1Buf          Buffer pointer
 *  @param  u4Size          Buffer size
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRM_BIM_GetULPK(UINT8 *pu1Buf, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** MTDRM_BIM_GetRomKey
 *  Get rom key
 *
 *  @param  pu1Buf          Buffer pointer
 *  @param  u4Size          Buffer size
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRM_BIM_GetRomKey(UINT8 *pu1Buf, UINT32 u4Offset, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** Read DivX DRM HW Secret key
 *
 *  @param  pu1KeyBuf       Output key buffer
 *  @param  pu4OutSize      Output size pointer
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_DivX_GetHWSecretKeyEx(UINT8 *pu1KeyBuf, UINT32 *pu4OutSize);

//-----------------------------------------------------------------------------
/** Set TS out configuration
 *
 *  @param  u1TsIdx         The TS index,
                            if ePath is MTDMX_TSOUT_PATH_EXTERNAL, we don't care about this value
 *  @param  eMode           ePath
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetTsOut(UINT8 u1TsIdx, MTDMX_TSOUT_PATH_T ePath);

//-----------------------------------------------------------------------------
/** Set PTS drift
 *
 *  @param  ucStcId         The STC Id
 *  @param  i4Drift         The PTS drift
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDMX_SetPTSDrift(UCHAR ucStcId, INT32 i4Drift);

//-----------------------------------------------------------------------------
/** MTDMX_ConnectInfo
 *  Allocate a PID index via PID information, this is used for multi-instance mechanisam
 *
 *  @param  u1VirtualPidx   The PID index
 *  @param  prPidInfo       The PID information
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_ConnectInfo(UINT8 u1VirtualPidx, const MTDMX_PID_INFO_T  *prPidInfo);

//-----------------------------------------------------------------------------
/** MTDMX_DisconnectInfo
 *  Free a PID index
 *
 *  @param  u1VirtualPidx   The PID index
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_DisconnectInfo(UINT8 u1VirtualPidx);

//-----------------------------------------------------------------------------

/** MTDMX_GetHwInfo
 *  Get Hardware information
 *
 *  @param  prHwInfo   pointer to hardware info struct
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_GetHwInfo(MTDMX_HW_INFO_T *prHwInfo);

//-----------------------------------------------------------------------------
/** MTDRM_DIVX_GetHwSecretKey0
 *  Get Divx HW secret key 0
 *
 *  @param  p1Buf           buffer pointer for key, and the buffer size must be 32
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDRM_DIVX_GetHwSecretKey0(UINT8 *p1Buf);

//-----------------------------------------------------------------------------
/** MTDRM_DIVX_GetHwSecretKey1
 *  Get Divx HW secret key 1
 *
 *  @param  p1Buf           buffer pointer for key, and the buffer size must be 32
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDRM_DIVX_GetHwSecretKey1(UINT8 *p1Buf);

//-----------------------------------------------------------------------------
/** MTDMX_SetEITSection
 *  Set EIT section filter
 *
 *  @param prEitSection    pointer for set data struct
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTDMX_SetEITSection(MTDMX_SECTION_KEY_SET_T *prEitSection);

#ifdef __cplusplus
}
#endif

#endif //MT_DMX_H

