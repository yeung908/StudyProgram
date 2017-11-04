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
 * $RCSfile: mtb2r_mwif.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtb2r_mwif.h
 *  This header file declares exported APIs of B2R (Block to Raster) module.
 */

#ifndef MT_B2R_MWIF_H
#define MT_B2R_MWIF_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mtb2r.h"

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

#define MTB2R_3D_NONE                   (0)         ///< B2R 3D type, none
#define MTB2R_3D_FRAME_SEQUENTIAL       (1)         ///< B2R 3D type, frame sequential
#define MTB2R_3D_SIDE_BY_SIDE_REAL_D    (2)         ///< B2R 3D type, real-d
#define MTB2R_3D_SIDE_BY_SIDE           (3)         ///< B2R 3D type, side-by-side
#define MTB2R_3D_TOP_N_BOTTOM           (4)         ///< B2R 3D type, top-and-bottom

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Function type of MM aud start to play notification
*/
typedef void (*MTB2R_MM_COMM_NOTIFY)
( 
    UINT32 u4VdpId, 
    UINT32 u4Data,
    UINT32 u4Tag
);

/** B2R Chapter information
 */
typedef struct
{
    UINT64      u8StartPts;         ///< Start PTS of chapter
    UINT64      u8EndPts;           ///< End PTS of chapter
    BOOL        fgIsPending;        ///< Need pending or not if end of chapter.
    BOOL        fgIsSetEndPts;      ///< Check chapter end pts is reach or not.
    BOOL        fgPending;          ///< Chapter done, and pending for next chapter
    BOOL        fgFirstSetChapter;  ///< Is first chapter of playback
} MTB2R_CHAPTER_T;

/** Get display frame buffer information (in display queue, but not display yet)
 *@param ucVdpId                    Vdp Id
 *@param prCaptureInfo              Returned capture information, including buffer address
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_GetDisplayFrameBufferAddr(UCHAR ucVdpId,MTB2R_CAPTURE_INFO_T* prCaptureInfo);

/** Set up 3D type to B2R
 *@param ucVdpId                    Vdp Id
 *@param u13DType                   3D type
 *@param fg3DEnable                 3D enable/disable
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_Set3DInfo(UCHAR ucVdpId,UINT8 u13DType,BOOL fg3DEnable);

/** Set chapter information to B2R
 *@param ucVdpId                    Vdp Id
 *@param prChapter                  Chapter information to be set
 *@retval MTR_OK                    Success
 *@retval MTR_NOT_OK                Fail
 */
EXTERN MT_RESULT_T MTB2R_SetChpterEnable(UCHAR ucVdpId, MTB2R_CHAPTER_T *prChapter);

#ifdef __cplusplus
}
#endif

#endif //MT_B2R_MWIF_H

