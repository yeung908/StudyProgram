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

/** @file mtstc.h
 *  This header file declares exported APIs of STC module.
 */

#ifndef MT_STC_H
#define MT_STC_H

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

#define MTSTC_AV_SYNC_MODE_NONE             0   ///< None (free run)
#define MTSTC_AV_SYNC_MODE_AUDIO_MASTER     1   ///< Audio master
#define MTSTC_AV_SYNC_MODE_VIDEO_MASTER     2   ///< Video master
#define MTSTC_AV_SYNC_MODE_SYSTEM_MASTER    3   ///< System master
#define MTSTC_AV_SYNC_MODE_NS               4   ///< Invalid

#define MTSTC_VID_SYNC_MODE_NONE            0   ///< None (free run)
#define MTSTC_VID_SYNC_MODE_SLAVE           1   ///< Slave (=system master)
#define MTSTC_VID_SYNC_MODE_MASTER          2   ///< Master (=video master)
#define MTSTC_VID_SYNC_MODE_SLAVE_MM        3   ///< SlaveMM (=audio master)
#define MTSTC_VID_SYNC_MODE_NS              4   ///< Invalid

#define MTSTC_AV_SYNC_TARGET_AUD            0   ///< Audio device as sync target
#define MTSTC_AV_SYNC_TARGET_VDO            1   ///< Video device as sync target
#define MTSTC_AV_SYNC_TARGET_NS             2   ///< Invalid

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** STC clock value
 */
typedef struct
{
    UCHAR           ucBaseHi;               ///< STC base, highest bit (1 bit)
    UINT16          u2Ext;                  ///< STC extension, 9 bits
    UINT32          u4Base;                 ///< STC base, 32 bits
} MTSTC_CLOCK;

/** STC speed (for MM)
 */
typedef enum
{
    MTSTC_SPEED_TYPE_FORWARD_1X,            ///< Forward 1x
    MTSTC_SPEED_TYPE_FORWARD_2X,            ///< Fast forward 2x
    MTSTC_SPEED_TYPE_FORWARD_3X,            ///< Fast forward 3x
    MTSTC_SPEED_TYPE_FORWARD_4X,            ///< Fast forward 4x
    MTSTC_SPEED_TYPE_FORWARD_8X,            ///< Fast forward 8x
    MTSTC_SPEED_TYPE_FORWARD_16X,           ///< Fast forward 16x
    MTSTC_SPEED_TYPE_FORWARD_32X,           ///< Fast forward 32x
    MTSTC_SPEED_TYPE_FORWARD_64X,           ///< Fast forward 64x
    MTSTC_SPEED_TYPE_FORWARD_128X,          ///< Fast forward 128x
    MTSTC_SPEED_TYPE_FORWARD_256X,          ///< Fast forward 256x
    MTSTC_SPEED_TYPE_FORWARD_512X,          ///< Fast forward 512x
    MTSTC_SPEED_TYPE_FORWARD_1024X,         ///< Fast forward 1024x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_2X,      ///< Slow forward 1/2x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_3X,      ///< Slow forward 1/3x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_4X,      ///< Slow forward 1/4x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_8X,      ///< Slow forward 1/8x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_16X,     ///< Slow forward 1/16x
    MTSTC_SPEED_TYPE_FORWARD_1_DIV_32X,     ///< Slow forward 1/32x
    MTSTC_SPEED_TYPE_FORWARD_0_DOT_6X,      ///< Slow forward 0.6x
    MTSTC_SPEED_TYPE_FORWARD_0_DOT_7X,      ///< Slow forward 0.7x
    MTSTC_SPEED_TYPE_FORWARD_0_DOT_8X,      ///< Slow forward 0.8x
    MTSTC_SPEED_TYPE_FORWARD_0_DOT_9X,      ///< Slow forward 0.9x
    MTSTC_SPEED_TYPE_FORWARD_1_DOT_1X,      ///< Fast forward 1.1x
    MTSTC_SPEED_TYPE_FORWARD_1_DOT_2X,      ///< Fast forward 1.2x
    MTSTC_SPEED_TYPE_FORWARD_1_DOT_3X,      ///< Fast forward 1.3x
    MTSTC_SPEED_TYPE_FORWARD_1_DOT_4X,      ///< Fast forward 1.4x
    MTSTC_SPEED_TYPE_FORWARD_1_DOT_5X,      ///< Fast forward 1.5x
    MTSTC_SPEED_TYPE_REWIND_1X,             ///< Backward 1x
    MTSTC_SPEED_TYPE_REWIND_2X,             ///< Backward 2x
    MTSTC_SPEED_TYPE_REWIND_3X,             ///< Backward 3x
    MTSTC_SPEED_TYPE_REWIND_4X,             ///< Backward 4x
    MTSTC_SPEED_TYPE_REWIND_8X,             ///< Backward 8x
    MTSTC_SPEED_TYPE_REWIND_16X,            ///< Backward 16x
    MTSTC_SPEED_TYPE_REWIND_32X,            ///< Backward 32x
    MTSTC_SPEED_TYPE_REWIND_64X,            ///< Backward 64x
    MTSTC_SPEED_TYPE_REWIND_128X,           ///< Backward 128x
    MTSTC_SPEED_TYPE_REWIND_256X,           ///< Backward 256x
    MTSTC_SPEED_TYPE_REWIND_512X,           ///< Backward 512x
    MTSTC_SPEED_TYPE_REWIND_1024X,          ///< Backward 1024x
    MTSTC_SPEED_TYPE_REWIND_1_DIV_2X,       ///<Slow backward 1/2X
    MTSTC_SPEED_TYPE_REWIND_1_DIV_4X,       ///<Slow backward 1/4X
    MTSTC_SPEED_TYPE_REWIND_1_DIV_8X,       ///<Slow backward 1/8X
    MTSTC_SPEED_TYPE_REWIND_1_DIV_16X,       ///<Slow backward 1/16X    
    MTSTC_SPEED_TYPE_REWIND_1_DIV_32X,       ///<Slow backward 1/32X    
    MTSTC_SPEED_TYPE_NS                     ///< Max boundary
}MTSTC_SPEED_TYPE_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** Set STC value
 *@param ucStcId                    STC Id
 *@param u4Stc                      STC value to be set (32bits, 90k based)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_SetStcValue(UINT8 ucStcId, UINT32 u4Stc);

/** Get STC value
 *@param ucStcId                    STC Id
 *@param pu4StcValue                Returned STC value (32bits, 90k based)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_GetStcValue(UCHAR ucStcId, UINT32* pu4StcValue);

/** Start STC
 *@param ucStcId                    STC Id
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_StartStc(UCHAR ucStcId);

/** Set avsync mode to stc, adec and vdec
 *@param ucStcId                    STC Id
 *@param ucAdecId                   Adec Id
 *@param ucVdecId                   Vdec Id
 *@param u4SyncMode                 AV sync mode (MTSTC_AV_SYNC_MODE_NONE, MTSTC_AV_SYNC_MODE_AUDIO_MASTER ...)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_SetSyncMode(UINT8 ucStcId, UINT8 ucAdecId, UINT8 ucVdecId, UINT32 u4SyncMode);

/** Stop STC
 *@param ucStcId                    STC Id
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_StopStc(UCHAR ucStcId);

/** Get complete STC source value
 *@param ucStcId                    STC Id
 *@param prStc                      Returned STC value (40bits, 90k based)
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTSTC_GetSrc(UCHAR ucStcId,MTSTC_CLOCK* prStc);


#ifdef __cplusplus
}
#endif

#endif //MT_STC_H

