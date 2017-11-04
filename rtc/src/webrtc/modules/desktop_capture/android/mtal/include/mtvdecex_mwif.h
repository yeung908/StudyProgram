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
 * $RCSfile: mtvdecex.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 
/** @file MTVDECEX.h
 *  This header file declares exported APIs of external VDEC module.
 */

#ifndef MT_VDECEX_MWIF_H
#define MT_VDECEX_MWIF_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
#include "mtvdecex.h"

//-----------------------------------------------------------------------------
// Video
//-----------------------------------------------------------------------------
   
/**
 * Trigger the action to select video input source.
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_SUB)
 * @param eSrc Select the video input source.
 * @return The exit status of this api.
 * @retval MTR_OK       Success
 * @retval MTR_NOT_OK   Fail
 */
EXTERN MT_RESULT_T MTVDECEX_SetMonitorSrc(MTVDO_PATH_T ePath, MTVDECEX_SRC_T eSrc);

/**
 * Set Porch Tune Type
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param eTuneType 
 	MTVDECEX_PORCHTUNE_DEC,
 	MTVDECEX_PORCHTUNE_SCPOS,
 	MTVDECEX_PORCHTUNE_MIXED
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetPorchTune(MTVDO_PATH_T ePath, MTVDECEX_PORCHTUNE_TYPE_T eTuneType);

/**
 * Get Porch Tune Type
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param peTuneType 
 	MTVDECEX_PORCHTUNE_DEC,
 	MTVDECEX_PORCHTUNE_SCPOS,
 	MTVDECEX_PORCHTUNE_MIXED
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetPorchTune(MTVDO_PATH_T ePath, MTVDECEX_PORCHTUNE_TYPE_T *peTuneType);

/**
 * Get video signal status
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param eSignalStatus
	MTVDECEX_VDO_NOSIGNAL		
	MTVDECEX_VDO_NOSUPPORT
	MTVDECEX_VDO_UNKNOWN
	MTVDECEX_VDO_STABLE
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoStatus(MTVDO_PATH_T ePath, MTVDECEX_SIG_STATUS *peSignalStatus);

/**
 * Get video signal status
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param pSrcType source type
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoSrcType(MTVDO_PATH_T ePath, UINT8 *pSrcType);

EXTERN MT_RESULT_T MTVDECEX_GetVideoSrc(MTVDO_PATH_T ePath, MTVDECEX_SRC_T *eSrc);

/**
 * Get video signal status
 *
 * @param eType query type
 * @retval TRUE/FALSE
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoDefStatus(MTVDO_DEF_TYPE_T eType, UINT8 *pStatus);

/**
 * Get video decoder type
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param eDecType
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoDecType(MTVDO_PATH_T ePath, MTVDO_DEC_TYPE_T *peDecType);

/**
 * Set Scpos Porch.
 *
 * @param ePath main/sub path (MTVDO_MAIN, / MTVDO_PIP)
 * @param ePorchType 
 	MTVDECEX_HPORCH_CURRENT,
	MTVDECEX_HPORCH_DEFAULT,
	MTVDECEX_HPORCH_MIN,
	MTVDECEX_HPORCH_MAX,
	MTVDECEX_VPORCH_CURRENT,
	MTVDECEX_VPORCH_DEFAULT,
	MTVDECEX_VPORCH_MIN,
	MTVDECEX_VPORCH_MAX
   @param u2Value The porch value
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetScposPorch(MTVDO_PATH_T ePath, MTVDECEX_PORCH_TYPE_T ePorchType, UINT16 u2Value);

/**
 * Check the video source is interlace timing or not
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value the video source is interlace timing or not
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_IsVideoSrcInterlace(MTVDO_PATH_T ePath, UINT8 *pu1Value);

/**
 * Get VGA polarity
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value polarity result 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoInputPolarity(MTVDO_PATH_T ePath, UINT8 *pu1Value);

/**
 * Get video input timing index
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param pu2Value video input timing index 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoInputTimingID(MTVDO_PATH_T ePath, UINT8 *pu1Value);

/**
 * Get video decoder type of specified path
 *
 * @param ePath MTVDO_MAIN/MTVDO_SUB
 * @param peDecType video decoder type 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_GetVideoInternalDec(MTVDO_PATH_T ePath, MTVDO_DEC_TYPE_T *peDecType);



//-----------------------------------------------------------------------------
// HDTV
//-----------------------------------------------------------------------------

#if 0
/**
 * Get number of items of ambiguous VGA in current VGA timing group
 *
 * @param NONE
 * @return If current timing is not ambiguous, the return value will be 1. Otherwise, it will be the total number of current ambiguous VGA timing. 
 */
//EXTERN UINT8 MTVDECEX_VGA_GetAmbiguousTimingNum(VOID);

//fix return type
EXTERN MT_RESULT_T MTVDECEX_VGA_MWIFGetAmbiguousTimingNum(UINT8 * pu1AmbiguousTimingNum);

/**
 * Query certain or current VGA timing details.
 *
 * @param pt_ambig_vga_timing_info structure pointer of struct type "MTVDECEX_AMBIG_VGA_TIMING_T"
 * @return NONE. It will return 1. index in current group, 2. V freq, 3. H resolution, 4. V resolution
 *@retval MTR_OK          Success.
 *@retval MTR_NOT_OK  Fail.
 */
 EXTERN MT_RESULT_T MTVDECEX_VGA_MWIFQueryAmbiguousTiming(UINT8 u1OptionIdx, MTVDECEX_VGA_AMBIG_TIMING_T* prAmbigVgaTimingInfo, UINT8 u1TimingNum);

/**
 * Set VGA timing according to input ambiguous timing index.
 *
 * @param u1OptionIdx Set ambiguous timging decision.
 *@param fgSetDefault Set u1OptionIdx timing as default. 
 *@retval MTR_OK          Success.
 *@retval MTR_NOT_OK  Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_MWIFSetAmbiguousIndex(UINT8 u1OptionIdx, BOOL fgSetDefault);

/**
 * Enable/Disable to set the ambiguous vga mode with the previous user select
 * mode
 *
 * @param fgUserSel SV_FALSE to disable, otherwise to enable
 * @return none
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_MWIFSetAmbiguousUserSel(BOOL fgUserSel);

#endif

/**
 * Trigger Auto state machine entry,auto phase, auto clock and auto position. When YPbPr auto process finish, driver will call back to AP.
 * @param VOID
 * @retval MTR_OK                    Begin to execute YPbPr auto.
 * @retval MTR_NOT_OK            Cannot execute YPbPr auto.
 */
EXTERN MT_RESULT_T MTVDECEX_StartYPbPrAuto(VOID);

/**
 * Reset VGA Ambiguous timing data in EEPROM.
 *
 * @param none
 * @retval MTR_OK       Success.
 * @retval MTR_NOT_OK   Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_VGA_MWIFResetAmbiguousTimingEEPROM(VOID);




//-----------------------------------------------------------------------------
// TVD
//-----------------------------------------------------------------------------


/**
 * Get noise level of composite signal
 *
 * @param pu1Value noise level 
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_TVD_GetNRLevel(UINT16 *pu1Value);

/**
 * @Signal Booster function : if signal is weak, it will turn on LNA
 * @param  u1OnOff enable/disable
 * @retval MTR_OK                    Success.
 * @retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVDECEX_SetSignalBooster(UINT8 u1OnOff);


#ifdef __cplusplus
}
#endif

#endif //MT_VDECEX_H

