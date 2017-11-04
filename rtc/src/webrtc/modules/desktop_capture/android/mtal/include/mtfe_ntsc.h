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
 * $RCSfile: mtfe_ntsc.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtfe_ntsc.h
 *  This header file declares exported APIs of front-end NTSC module.
 */

#ifndef MTFE_NTSC_H
#define MTFE_NTSC_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mtfe_common.h"

   
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
/**This structure contains the search nearby result parameter.
*/
typedef struct
{
    UINT32                  u4VFreqInKHz;            //RF visual frequency in KHz
    INT16                   i2LockStatus;            //Lock Status
}MTFE_NTSC_SEARCH_PARAMETER_T;

/**This structure contains the ntsc module parameter.
*/
typedef struct
{
    UINT32                          u4DesireVFreqInKHz;     // Desire RF visual frequency in KHz
    MTFE_RF_MOD_T                   rRfMode;                // RF mode
    MTFE_SURF_MOD_T                 rSurfMode;              // Surf mode
    MTFE_NTSC_SEARCH_PARAMETER_T      rStatus;                // Search result
}MTFE_NTSC_PARAMETER_T;

/**The ntsc module callback function.
*/
typedef int (*MTFE_NTSC_PFN_CB)(VOID* pvArg);


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** Initialize frond end ntsc module.
*@param VOID
*@retval MT_OK                  Success.
*@retval MT_NOT_OK              Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_Open(VOID);

/** Terminate frond end ntsc module.
*@param VOID
*@retval MT_OK                  Success.
*@retval MT_NOT_OK              Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_Close(VOID);

/** Connect NTSC module.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_Connect(VOID); 

/** Disconnet NTSC module.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_DisConnect(VOID); 

/**Set visual carrier frequency.
*@param  rParameter             The input paramter (Visual carrier freq...)
*@retval MT_OK                  Success.
*@retval MT_NOT_OK              Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_TunerSetFreq(MTFE_NTSC_PARAMETER_T *prParameter); 

/**Search visual carrier frequency. 
* Registration a notify function (ID = MTFE_NTSC_CB_ID_SEARCH_NEARBY_NFY) before using this API.
*@param  rParameter             The input paramter (Visual carrier freq...)
*@retval MT_OK                  Success.
*@retval MT_NOT_OK              Fail.
*/
EXTERN MT_RESULT_T  MTFE_NTSC_StartSearchNearbyFreq(MTFE_NTSC_PARAMETER_T* prParameter);

/**Break the search visual carrier frequency process.
*@retval MT_OK                  Success.
*@retval MT_NOT_OK              Fail.
*/
EXTERN MT_RESULT_T  MTFE_NTSC_BreakSearchNearbyFreq(VOID);

/** Get lock status.
*@param	 prStatus           Report demod status.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_GetSync(MTFE_NTSC_PARAMETER_T* prStatus);

/** Check analog tuner driver software version.
*@param  u1Version          Software Version.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_GetVer(UINT8 *pu1Version);

/**Register ntsc module callback function.
*@param  pfCb               Callback function.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_NTSC_RegCb(MTFE_NTSC_PFN_CB pfCb);

#ifdef __cplusplus
}
#endif

#endif //MTFE_NTSC_H