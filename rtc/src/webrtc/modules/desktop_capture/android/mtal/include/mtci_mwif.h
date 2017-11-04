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
 * $RCSfile: mtci.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 *
 * Description: Peripherals, such as NOR/NAND/SIF/RTC/PWM/GPIO (and others), are centralized in
 *                   this file
 *---------------------------------------------------------------------------*/

/** @file mtci_mwif.h
 *  This header file declares exported APIs of CI module for MTK MW.
 */

#ifndef _MTCI_MWIF_H_
#define _MTCI_MWIF_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mtci.h"

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------



///////////////////////////////////////////////////////////////////////////////
///////////   MTAL For MTK MW    
//-----------------------------------------------------------------------------
/** MTCI0_Init(VOID)  Common Interface Initialization Fucntion
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_Init(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_DetectCard()  Common Interface Card Detection Function
 *  @retval TRUE card inserted ,FALSE No Card 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_DetectCard(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_DetectPodActive()  Detect Pod Active
 *  @param 
 *  @retval MTR_POD_CI_ACTIVE:CI function enabled, MTR_OK:CI function disabled.
 */
//-----------------------------------------------------------------------------
EXTERN BOOL MTCI0_DetectPodActive(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_TestCardReady()  Test Card Ready
 *  @param void
 *  @retval TRUE : Card Ready, FALSE : Card not ready
 */
//-----------------------------------------------------------------------------
EXTERN BOOL MTCI0_TestCardReady(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_SetPodCiAccessMode()  Set access mode
 *  @param eAccessMode, POD_DATA_CHANNEL
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTCI0_SetPodCiAccessMode(INT32 eAccessMode);

//-----------------------------------------------------------------------------
/** MTCI0_PcmciaToPod()  Change mode between PCMCIA and POD
 *  @param fgPcmciaToPod, TRUE:To POD , FALSE:To PCMCIA
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------

EXTERN INT32 MTCI0_PcmciaToPod(BOOL fgPcmciaToPod);

//-----------------------------------------------------------------------------
/** MTCI0_Read()  (Not Implemented)
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN INT32 MTCI0_Read(INT32 eIoState, UINT8* pu1Data, UINT16* pu2DataLen);

//-----------------------------------------------------------------------------
/** MTCI0_Write()  (Not Implemented)
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_Write(INT32 eIoState, const UINT8* pu1Data, UINT16 u2DataLen);

//-----------------------------------------------------------------------------
/** MTCI0_ReadReg()  Read Register
 *  @param eIoState, IO access state SDA or DMA 
 *  @param u4RegAddr, Register Address 
 *  @param pu1Data, Buffer pointer [IN]
 *  @param pu2DataLen, Buffer size [IN]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_ReadReg(INT32 eIoState, UINT32 u4RegAddr, UINT8* pu1Data, UINT16 pu2DataLen);

//-----------------------------------------------------------------------------
/** MTCI0_WriteReg()  Write Register
 *  @param eIoState, IO access state SDA or DMA 
 *  @param u4RegAddr, Register Address 
 *  @param pu1Data, Buffer pointer [IN]
 *  @param u2DataLen, Buffer size [IN]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_WriteReg(INT32 eIoState, UINT32 u4RegAddr, const UINT8* pu1Data, UINT16 u2DataLen);

//-----------------------------------------------------------------------------
/** MTCI0_ReadCor()  Read COR(Configuration Option Register)
 *  @param Cor Address
 *  @retval Cor Value
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_ReadCor(UINT16 u2CorAddress);

//-----------------------------------------------------------------------------
/** MTCI0_WriteCor()  Write COR(Configuration Option Register) data into COR
 *  address. (Set u2CorAddress=0xFFFF and u1CorValue=0xFF to use values gather 
 *  from MTCI_CheckCIS().)
 *  @param u2CorAddress, Size beginning from u4Addr
 *  @param u1CorValue, Memory buffer storing check sum value
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_WriteCor(UINT16 u2CorAddress, UINT8 u1CorValue);

//-----------------------------------------------------------------------------
/** MTCI0_EnableIsr()  Enable driver ISR
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_EnableIsr(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_PcmciaEnableTS()  PCMCIA Enable TS
 *  @param fgPcmciaEnableTS, TRUE:Enable TS, FALSE:Disable TS
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_PcmciaEnableTS(BOOL fgPcmciaEnableTS);

//-----------------------------------------------------------------------------
/** MTCI0_GetTsType()  (Not Implemented)
 *  @retval 
 */
//-----------------------------------------------------------------------------

EXTERN UINT32 MTCI0_GetTsType(VOID);
//-----------------------------------------------------------------------------
/** MTCI0_AutoSetTsRoutingPath()  PCMCIA set TS routing
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_AutoSetTsRoutingPath(VOID);

//-----------------------------------------------------------------------------
/** MTCI0_Reset()  Resets CI Device (PCMCIA reset), also called card/CAM reset
 *  @param fgReset, TRUE:Pull-high reset pin, FALSE:pull-down reset pin.
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_Reset(BOOL fgReset);
//-----------------------------------------------------------------------------
/** MTCI_ResetCam()  Reset CAM (Pull-high reset pin and then pull-low it again.)
 *  @param 
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_ResetCam(VOID);
//-----------------------------------------------------------------------------
/** MTCI0_RegIsr()  Register Isr for IREQ interrupt 
 *  @param u2IntNo, Interrupt number
 *  @param pfnIsr,    callback function
 *  @param ppfnOld,  NULL
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_RegIsr(UINT16 u2IntNo, void* pfnIsr, void *ppfnOld);

//-----------------------------------------------------------------------------
/** MTCI0_CiCamWorkaround()  CAM workaroud function for mw to call
 *  @param eCiCamWorkaround, workaround type
 *  @param vParam,                    date to use for each workaroud type
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_CiCamWorkaround(INT32 eCiCamWorkaround, void* vParam);

//-----------------------------------------------------------------------------
/** MTCI0_SetBypass() Set Bypass Mode
 *  @param fgBypass, TRUE:Enable TS bypass, FALSE:Disable TS bypass.
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_SetBypass(BOOL fgBypass);

//-----------------------------------------------------------------------------
/** MTCI0_SetBypassTsRouting()  set Ts routing according to bypass mode(only for external CI)
 *  @param fgBypass, TRUE:Enable TS bypass, FALSE:Disable TS bypass.
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI0_SetBypassTsRouting(BOOL fgBypass);


#ifdef __cplusplus
}
#endif

#endif //_MTCI_MWIF_H_
