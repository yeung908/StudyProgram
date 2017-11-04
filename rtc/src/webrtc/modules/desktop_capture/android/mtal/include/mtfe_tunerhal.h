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

#ifndef MT_FE_TUNERHAL_H
#define MT_FE_TUNERHAL_H

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
#define TUNERHAL_DBG_ENABLE 0
#if (TUNERHAL_DBG_ENABLE == 1)
#define TUNERHAL_MSG(fmt,args...) printf("[%s:%d]: " fmt "\n",__FUNCTION__,__LINE__,##args)
#else
#define TUNERHAL_MSG(fmt,args...) {}
#endif

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** The callback structure of MTAL_FE_NFY_TUNER_CALLBACK_INFO_T
*/
typedef struct
{
    UINT32   pt_comp_id;
    UINT32   e_nfy_cond;
    UINT32   pv_tag;
    UINT32   ui4_data;
} MTAL_FE_NFY_TUNER_CALLBACK_INFO_T;

/** This callback function for notify
*/
typedef INT32 (*MTFE_NFY_PFN_CB) (MTAL_FE_NFY_TUNER_CALLBACK_INFO_T* pvArg);

/** This callback function for TunerHAL
*/
typedef int (*MTFE_TUNERHAL_PFN_CB)(VOID* pvArg);

/** This callback function for TunerHAL register RM component
*/
typedef void (*MTFE_TUNERHAL_PFN_INI_THREAD_CB)(
    UINT16 TunerID,
    UINT16 DrvType
);

/** This callback function for TunerHAL register RM exec list
*/
typedef void (*MTFE_TUNERHAL_PFN_TUNER_PROC_CB)(
    UINT16 TunerID1,
    UINT16 DrvType1,
    UINT16 TunerID2,
    UINT16 DrvType2
);

/** The callback structure of MTFE_TUNERHAL_CB_T
*/
typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3;
    UINT32 u4Arg4;
    UINT32 u4Arg5;
    UINT32 u4Arg6;
    UINT32 u4Arg7;    
}MTFE_TUNERHAL_CB_T;

/** The enum of TunerHAL register callback function
*/
typedef enum
{
    MTFE_TUNERHAL_CB_FUNC_INI_THREAD,    
    MTFE_TUNERHAL_CB_FUNC_TUNER_PROC,
}MTFE_TUNERHAL_CB_FUNC_ENUM_T;


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** Initialize TunerHAL module only for Turnkey.
*@param VOID
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNERHAL_Init(VOID);

/** Register TunerHAL callback function.
*@param MTFE_TUNERHAL_CB_FUNC_ENUM_T eFuncType, MTFE_TUNERHAL_CB_FUNC_INI_THREAD or MTFE_TUNERHAL_CB_FUNC_TUNER_PROC
*@param UINT32 u4FuncPtr, The callback function pointer
*@param UINT32 u4Arg1, The parameters
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNERHAL_RegCb(MTFE_TUNERHAL_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);

/** Register TunerHAL notify callback.
*@param MTFE_NFY_PFN_CB pfCb, The callback function of notify
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNERHAL_NFY_RegCb(MTFE_NFY_PFN_CB pfCb);

/** Get Component name from driver for register RM.
*@param char *pucBuf,       The buffer that receive component name
*@param UINT16 TunerID,     The TunerID that register to RM
*@param UINT16 DrvType,     The DrvType that register to RM
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNERHAL_GetCompNameForMW(char *pucBuf, UINT16 TunerID, UINT16 DrvType);

#ifdef __cplusplus
}
#endif

#endif //MT_FE_TUNERHAL_H
