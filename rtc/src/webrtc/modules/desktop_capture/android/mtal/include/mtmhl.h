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

#ifndef _MTMHL_H_
#define _MTMHL_H_

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
  UINT8 MscMsg;
  UINT8 Opcode;
  UINT8 u1Port;
  UINT8 offset;
  UINT8 Size;
  UINT8 Data[16];
  void * arg;
} MT_CBUS_MSG_DESCRIPTION;

typedef struct{
    UINT8 opcode;
    UINT8 data;
	UINT8 u1Port;
} MT_CBUS_MSC_MSG_COMMAND;


typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3;
    UINT32 u4Arg4;
    UINT32 u4Arg5;
    UINT32 u4Arg6;
    UINT32 u4Arg7;    
}MTMHL_CB_T;
typedef struct
{
    UINT32 port;
    UINT32 flag;
    UINT32 on;   
}MTMHL_SET_OPTION_T;
/* Notify function */
typedef void (*MTMHL_MSC_SUBCOMMAND_PFN_CB) (UINT8 u1Port, UINT8 opcode,UINT8 data, void * arg);
typedef void (*MTMHL_SCRATCHPAD_DATA_PFN_CB)(MT_CBUS_MSG_DESCRIPTION *arMsg);
typedef void (*MTMHL_HOT_PLUG_PFN_CB)(UINT8 u1Switch, BOOL b5VStatus, void * arg);
typedef void (*MTMHL_CBUS_MODE_PFN_CB)(UINT8 u1Port,UINT8 mode, void *arg);
typedef void (*MTMHL_VBUS_OVERCURRENT_PFN_CB)(UINT8 u1Port,UINT8 ocStatus,void *arg);

/**cec call back function type id.
*/
typedef enum
{
    MTCEC_CB_FUNC_MSC_SUBCOMMAND,   
    MTCEC_CB_FUNC_SCRATCHPAD_DATA,  
    MTCEC_CB_FUNC_HOT_PLUG,
 	MTCEC_CB_FUNC_CBUS_MODE,
	MTCEC_CB_FUNC_VBUS_OVERCURRENT
}MTMHL_CB_FUNC_ENUM_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** MTCEC_Init()  Common Interface Initialization Fucntion
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------


/**
* @brief Register cec callback function
* @param eFuncType call back function type
* @param u4FuncPtr pointer to call back function
* @param u4Arg1
* @retval MTR_OK          Success.
* @retval MTR_NOT_OK  Fail.
*/
EXTERN MT_RESULT_T MTMHL_RegCbFunc(MTMHL_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);
#ifdef SYS_MHL_SUPPORT
EXTERN MT_RESULT_T  MTMhl_Init(void);
EXTERN MT_RESULT_T _MTMHL_GetOCPStatus(unsigned long arg);

#ifdef SYS_ANDROID_TV_TIF_SUPPORT
EXTERN MT_RESULT_T MTMHL_SendMscSubCommand(MT_CBUS_MSC_MSG_COMMAND* msg);
EXTERN MT_RESULT_T  MTMHL_SendScratchPadData(MT_CBUS_MSG_DESCRIPTION *msg);

EXTERN MT_RESULT_T MTMHL_GetPeerMhlVersion(int *version);
EXTERN MT_RESULT_T MTMHL_SetOption(MTMHL_SET_OPTION_T *pMhlSetOption);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif //_MTCEC_H_
