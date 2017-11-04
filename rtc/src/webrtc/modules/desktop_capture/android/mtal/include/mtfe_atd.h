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
 * $RCSfile: MTFE_ATD.h $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file MTFE_ATD.h
 *  This header file declares exported APIs of front-end NTSC module.
 */

#ifndef MTFE_ATD_H
#define MTFE_ATD_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mtfe_common.h"

/**MTFE_ATD_Open
* Initialize demod device
*@param VOID
*@retval MT_OK                  demod initalize successfully
*@retval MT_NOT_OK          demod initalize fail.
*/
EXTERN MT_RESULT_T MTFE_ATD_Open(VOID);
/**MTFE_ATD_Connect
* resume analogue demod since it will be sleep mode when connect to DTV or other source  
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_ATD_Connect(VOID);
/**MTFE_ATD_DisConnect
* Set demod as sleep mode.It shoud be invoked when switch from ATV to other source(except AV) 
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_ATD_DisConnect(VOID);
/** MTFE_ATD_Acquire
 *  Set demod to start to acquire signal
 *  @param  u1Chscan      To indicate now if it is channel scan(TRUE)
*   @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL).
                                         or demod acquire signal fail(demod work abnormal)
 *  @retval  MT_OK          successul to acquire signal
 */
EXTERN MT_RESULT_T MTFE_ATD_Acquire(UINT8 u1Chscan);
//-----------------------------------------------------------------------------
/** MTFE_ATD_GetAFTWinSts
 *  Check if there is  norminal VIF is in the range of AFT window(+-1.5MHz)
 *  @param  u1AFTWSts      The AFT window lock status to return to user space(0:No VIF in +-1.5MHz;1:norminal VIF in +-1.5MHz)
*   @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL).
                                         or user space data access fail
 *  @retval  MT_OK          successul to get AFT window lock status
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_GetAFTWinSts(UINT8 * u1AFTWSts);
//-----------------------------------------------------------------------------
/** MTFE_ATD_GetCFOKHz
 *  Get the picture carrier offset(KHz) between current tuner LO with norminal picture carrier.
   It should be called after _MTFE_ATD_GetAFTWinSts is TRUE,otherwise,the estimated CFO value will be invalid 
 *  @param  i4CFOKHz      The CFO to return to user space(unit is KHz)
*   @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL).
                                         or user space data access fail
 *  @retval  MT_OK          successul to get current CFO
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_GetCFOKHz(INT32 * i4CFOKHz);
//-----------------------------------------------------------------------------
/** MTFE_ATD_LoadEQ
 *  To load the atd eq script with specified CVBS response
 *  @param  pu1EqBuff        the  pointer to eq script array,please refer the "EQMN[]"  of ut_mtfe_atd.c,which is diffirent from the system
 *  @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK          successul to load the eq script to demod register 
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_LoadEQ(UINT8 * pu1EqBuff);
//-----------------------------------------------------------------------------
/** MTFE_ATD_SetSystem
 *  To load the ATD default register setting with specified sub system
 *  @param  u1SubSysIdx        sub sys index,please refer to fe_common_if.h
 *  @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK          successul to config tuner IF frequency
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_SetSystem(UINT8 u1SubSysIdx);
//-----------------------------------------------------------------------------
/** MTFE_ATD_SetIF
 *  Set demod IF frequency, it should be called after get tuner IF freqency, and the IF freqency of demod must be the same as tuner.
 *  @param  u2TunerIF        the  IF frequency(KHz) tuner output
 *  @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK          successul to config tuner IF frequency
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_SetIF(UINT16 u2TunerIF);
 //-----------------------------------------------------------------------------
/** MTFE_ATD_SetReg
 *  To set the tuner relative registers such as PRA parameters to ATD register 
 *  @param  u2RegAddr        The register address
 *  @param  pu1Buff        The data buffer to set
 *  @param u1DataCnt        The data count to set
 *  @retval  MT_NOT_OK  set operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK          successul to set the register
 *  @retval  MT_PARAMETER_ERROR     The parameter from MW/AP is wrong
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_SetReg(UINT16 u2RegAddr,UINT8 * pu1Buff,UINT8 u1DataCnt);
//-----------------------------------------------------------------------------
/** MTFE_ATD_Patch
 *  To monitor current signal status and load corresponding register setting into demod.It should be invoked continuously after signal is stable
 *  @param  VOID        
 *  @retval  MT_NOT_OK  operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK           successul to Patch demod 
 */
 //---------------------------------------------------------------------------- 
EXTERN MT_RESULT_T MTFE_ATD_Patch(VOID);
//-----------------------------------------------------------------------------
/** _MTFE_ATD_IsAlive
 *  Check if ATD is being used now 
 *  @param  pu1IsAlive      The ATD runing status pointer return to use space (TRUE:internal ATD is alive.FALSE:internal ATD is not used)
*   @retval  MT_NOT_OK   operation fail
 *  @retval  MT_OK          successul to get ATD runing status
 */
 //----------------------------------------------------------------------------
EXTERN  MT_RESULT_T MTFE_ATD_IsAlive(UINT8 *pu1IsAlive);
//-----------------------------------------------------------------------------
/** _MTFE_ATD_SetSnowMode
 *  To set  TVD snow mode when channel scan or there is not signal
 *  @param  arg           0 close TVD snow mode, 1 open TVD snow mode        
 *  @retval  MT_NOT_OK  operation request  fail due to demod device is not initialized or initialized fail(then the pointer will be NULL)
 *  @retval  MT_OK           successul to set snow mode
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_SetSnowMode(UINT8 fgSnowOn);
//-----------------------------------------------------------------------------
/** MTFE_ATD_GetVer
 *  Get the ATD driver version string(the string length is 8)
 *  @param  VOID        
 *  @retval  MTR_NOT_OK   fail to get driver version
 *  @retval  MTR_OK           successul to get driver version
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_GetVer(CHAR * pzVerStr);
//-----------------------------------------------------------------------------
/** MTFE_ATD_SetA2MMode
 *  To notify driver if now it is A2M mode(A2 Korea) 
 *  @param  fgIsA2MMode   to indicate if now is A2M mode        
 *  @retval  MTR_NOT_OK  fail
 *  @retval  MTR_OK           successul to set A2 mode
 */
 //----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFE_ATD_SetA2MMode(BOOL fgIsA2MMode);

EXTERN MT_RESULT_T MTFE_ATD_SifBypass(UINT8 u1SubSysIdx);

#ifdef __cplusplus
}
#endif

#endif //MTFE_ATD_H
