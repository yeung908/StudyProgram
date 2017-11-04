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
 * $RCSfile: mtcec.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 *
 * Description: video, such as hdmi (and others), are centralized in
 *                   this file
 *---------------------------------------------------------------------------*/

/** @file mtcec.h
 *  This header file declares exported APIs of CEC module.
 */

#ifndef _MTCEC_H_
#define _MTCEC_H_

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
// Type definitions
//-----------------------------------------------------------------------------
// *********************************************************************
// struct
// *********************************************************************
typedef struct
{
	UINT8 destination : 4;
	UINT8 initiator   : 4;
} MT_CEC_HEADER_BLOCK;

typedef struct
{
	MT_CEC_HEADER_BLOCK header;
	UINT8 opcode;
	UINT8 operand[16];
} MT_CEC_FRAME_BLOCK;

typedef struct
{
	UINT8 size; // Actual frame block size.
	UINT8 sendidx;
	UINT8 reTXcnt;
	void* txtag;
	MT_CEC_FRAME_BLOCK blocks;
} MT_CEC_FRAME_DESCRIPTION;
#ifdef LG_CEC
typedef struct
{
    UINT8 ui1_txResult;
    MT_CEC_FRAME_DESCRIPTION tFrame;
}MT_CEC_TX_RESULT;
#endif
typedef struct 
{
    BOOL         fgActSrcReved;
    MT_CEC_FRAME_DESCRIPTION eFrameDescription;
}MT_CEC_PHILIPS_FRAME_ACTSRCREVED;
typedef struct 
{
    BOOL         fgActSrcReved;
    UINT8        u1PhyAddr[2];
}MT_CEC_FRAME_ACTSRCREVED;
typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3;
    UINT32 u4Arg4;
    UINT32 u4Arg5;
    UINT32 u4Arg6;
    UINT32 u4Arg7;    
}MTCEC_CB_T;

/* Notify function */
#ifdef SYS_ANDROID_TV_TIF_SUPPORT
typedef void (*MTCEC_TX_RESULT_PFN_CB) (UINT8 u1Result, UINT8* pOpcode, void * arg);
#else
typedef void (*MTCEC_TX_RESULT_PFN_CB) (UINT8 u1Result, void* pTxtag);
#endif
typedef void (*MTCEC_RX_RESULT_PFN_CB)(MT_CEC_FRAME_DESCRIPTION* pFrame);
#ifdef CECNFY5VSTATUS
#ifdef SYS_ANDROID_TV_TIF_SUPPORT
	typedef void (*MTCEC_5V_STATUS_PFN_CB)(UINT8 u1Switch, BOOL b5VStatus, void * arg);
#else
	typedef void (*MTCEC_5V_STATUS_PFN_CB)(UINT8 u1Switch, BOOL b5VStatus);
#endif
#endif

typedef void (*MTCEC_PHILIPS_5V_STATUS_PFN_CB)(UINT8 u1HdmiChangeType,UINT8 u1Switch, BOOL b5VStatus);
typedef void (*MTCEC_TX_HEADER_RESULT_PFN_CB) (UINT8 u1Result, UINT8* pOpcode, void * arg);

/**cec call back function type id.
*/
typedef enum
{
    MTCEC_CB_FUNC_RX_RESULT,   
    MTCEC_CB_FUNC_TX_RESULT,
#ifdef CECNFY5VSTATUS    
    MTCEC_CB_FUNC_5V_STATUS,
 #endif  
	MTCEC_CB_FUNC_PHILIPS_5V_STATUS,
	MTCEC_CB_FUNC_TX_HEADER_RESULT,
}MTCEC_CB_FUNC_ENUM_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** MTCEC_Init()  Common Interface Initialization Fucntion
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_Init (void);

/**
* @brief Register cec callback function
* @param eFuncType call back function type
* @param u4FuncPtr pointer to call back function
* @param u4Arg1
* @retval MTR_OK          Success.
* @retval MTR_NOT_OK  Fail.
*/
EXTERN MT_RESULT_T MTCEC_RegCbFunc(MTCEC_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);

//-----------------------------------------------------------------------------
/** MTCEC_SetMWReady()  Set fgCecMwReady when cec middleware is ready
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_SetMWReady(void);

//-----------------------------------------------------------------------------
/** MTCEC_SetLogicAddress()  Set logical address for TV
 *  @param u1LogicalAddr, logical address to be set for TV
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_SetLogicAddress(UINT8 u1LogicalAddr);

EXTERN MT_RESULT_T MTCEC_ClearLogicAddress(void);

EXTERN MT_RESULT_T  MTCEC_SendStandby(UINT8 u1Standby);

EXTERN MT_RESULT_T  MTCEC_SetWakeUp(UINT8 u1WakeUp);

EXTERN MT_RESULT_T  MTCEC_StandardCmd(UINT8 u1StandardCmdr);
EXTERN MT_RESULT_T  MTCEC_SysCECCtrl(UINT8 u1SysCtrl);


//-----------------------------------------------------------------------------
/** MTCEC_SetEnable()  Enable&disable cec function
 *  @param bEnable, enable | disable cec function
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_SetEnable(BOOL bEnable);

//-----------------------------------------------------------------------------
/** MTCEC_GetLogicalAddr()  Get logical address for TV
 *  @param pu1LogicalAddr, pointer to cec logical address
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_GetLogicalAddr(UINT8 *pu1LogicalAddr);

//-----------------------------------------------------------------------------
/** MTCEC_CheckActiveSource()  Check if active source op code has been received
 *  @param pActiveSrc : pointer to active source information
 *  @retval TRUE DA=1 (data avaliable), FALSE DA=0 (Not avaliable)
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_CheckActiveSource(MT_CEC_FRAME_ACTSRCREVED *pActiveSrc);

//-----------------------------------------------------------------------------
/** MTCEC_EnqueueTx()  put tx frame to be sent in tx queue 
 *  @param pFrame, pointer to tx frame 
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCEC_EnqueueTx(MT_CEC_FRAME_DESCRIPTION* pFrame);
#ifdef LG_CEC
//-----------------------------------------------------------------------------
/** MTCEC_ReadRxCommand()  Get rx frame that tv received
 *  @param pt_frame, pointer to received frame from device
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
//eggy for LG_CEC
EXTERN MT_RESULT_T  MTCEC_ReadRxCommand(MT_CEC_FRAME_DESCRIPTION *pt_frame);

//-----------------------------------------------------------------------------
/** MTCEC_ReadTxResult()  get the result of the frame tv send to device:
           pt_txResult->ui1_txResult == 0 means success, that tv get ack for the frame it send
           pt_txResult->ui1_txResult == 1 means fail, that tv do not get ack for the frame it send
 *  @param pt_txResult : pointer to the result of tx frame
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_ReadTxResult(MT_CEC_TX_RESULT *pt_txResult);

//-----------------------------------------------------------------------------
/** MTCEC_ReadResponse() The value of pui2_cecResponse tells that whether a tx result arrived or a frame is received
                                         pui2_cecResponse = 0xA2: RX frame received
                                         pui2_cecResponse = 0xA3: TX result arrived
 *  @param pui2_cecResponse, pointer to the response tv get 
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCEC_ReadResponse(UINT16 *pui2_cecResponse);
#endif

//-----------------------------------------------------------------------------
/** MTCEC_SetArcEnable()  Enable&disable cec arc out
 *  @param bEnable, enable | disable cec arc  out
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCEC_SetArcEnable(BOOL bEnable);
EXTERN MT_RESULT_T  MTCEC_GetConnected(int port,UINT8 *u1Connect);

#ifdef __cplusplus
}
#endif

#endif //_MTCEC_H_
