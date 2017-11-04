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
 * $RCSfile: mtfe_tuner.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtfe_tuner.h
 *  This header file declares exported APIs of DVBC module.
 */

#ifndef MT_FE_TUNER_H
#define MT_FE_TUNER_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mtfe_common.h"
//#include "mtfe_pal.h"
   
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
typedef enum
{
    MTFE_TUNER_MOD_TYPE_BEGIN = 0,
    MTFE_TUNER_MOD_ATSC_8VSB = MTFE_TUNER_MOD_TYPE_BEGIN,
    MTFE_TUNER_MOD_J83B_64QAM,
    MTFE_TUNER_MOD_J83B_256QAM,
    MTFE_TUNER_MOD_J83B_AUTO_QAM,
    MTFE_TUNER_MOD_DVBT,
	MTFE_TUNER_MOD_DVBT2,      
    MTFE_TUNER_MOD_ISDBT,
    MTFE_TUNER_MOD_DVBC,
	MTFE_TUNER_MOD_DTMB,
    MTFE_TUNER_MOD_TYPE_END,
    MTFE_TUNER_MOD_ANA_TYPE_BEGIN,
    MTFE_TUNER_MOD_PAL_BG = MTFE_TUNER_MOD_ANA_TYPE_BEGIN,
    MTFE_TUNER_MOD_PAL_DK,
    MTFE_TUNER_MOD_PAL_I,
    MTFE_TUNER_MOD_SECAM_L,
    MTFE_TUNER_MOD_SECAM_L1,
    MTFE_TUNER_MOD_NTSC_M,
    MTFE_TUNER_MOD_TYPE_UNKNOWN,
    MTFE_TUNER_MOD_ANA_TERR,
    MTFE_TUNER_MOD_ANA_CABLE,
    MTFE_TUNER_MOD_ANA_TYPE_END
}MTFE_TUNER_MOD_TYPE_T;

typedef enum
{
	MTFE_TUNER_SAW_BW_6M = 0,
	MTFE_TUNER_SAW_BW_7M,
	MTFE_TUNER_SAW_BW_8M,
	MTFE_TUNER_SAW_BW_5M
}MTFE_TUNER_SAW_BW_T;

typedef enum
{
    ATV_CONN_MODE_CHAN_CHANGE = 0,
    ATV_CONN_MODE_CHAN_SCAN,
    ATV_CONN_MODE_FINE_TUNE,
    ATV_CONN_MODE_NUM
}MTFE_TUNER_CONN_MODE_T;


typedef struct
{
	UINT32 u4FrequencyInKhz;
	MTFE_TUNER_MOD_TYPE_T eMod;
	MTFE_TUNER_SAW_BW_T eBandWidth;
	MTFE_TUNER_CONN_MODE_T fgAutoSearch;
}MTFE_TUNER_TUNE_PARAMETER_T;

typedef enum
{
    MTFE_itSetSawBw,		
    MTFE_itSetIfDemod,		
    MTFE_itGetStatus,		
    MTFE_itGetVer,			
    MTFEitGetSignalLevel,
    MTFE_itGetEqScriptNormal,
    MTFE_itGetEqScriptWeak,
    MTFE_itGetEqScriptStrongChroma,
    MTFE_itSetLNA,
    MTFE_itGetLNA,
    MTFE_itSetIFAMP,
    MTFE_itSetLNABYADC,
    MTFE_itSetTop,
    MTFE_itSetReg,
    MTFE_itGetReg,
    MTFE_itSetIfMin,
    MTFE_itSetIfMax,
    MTFE_itSetSSICond,
    MTFE_itGetSSIIndex,
    MTFE_itGetSSIIndex_T2,
    MTFE_itMonitorLNA,
    MTFE_itGetTHC,
    MTFE_itSetAntIn,
    MTFE_itSetInCableMode,       
    MTFE_itGetAnaFreqBound,
    MTFE_itIFAGCTreshold,
	MTFE_itGetTop,
	MTFE_itSetIF,
	MTFE_itSetLNAUI,
	MTFE_itGetTunerRelReg,
	MTFE_itGet3TapEQRelReg,
	MTFE_itTunerRead,
	MTFE_itTunerWrite,
	MTFE_itGetTunerAFCKhz,
	MTFE_itGetCNDTMBTunerRelReg,
	MTFE_itGetCNDVBCTunerRelReg,
	MTFE_itGetDelayLine,
	MTFE_itSetDelayLine,
	MTFE_itSetFineRF,
	MTFE_itGetPGAIdx,
	MTFE_itGetTunerRxPower,
	MTFE_itGetTunerAgcLock,
	MTFE_itSetAgcMode,
	MTFE_itSetIfPath,
	MTFE_itSetIfGain,
	MTFE_itSetIfSpecInvert,
	MTFE_itDumpTunerReg,
	MTFE_itSetTrapThresold,
	MTFE_itGetRSSI,
	MTFE_itSetSSIAdjust
}MTFE_TUNEROP_T;

typedef struct
{
	MTFE_TUNEROP_T   eOP;
    UINT8  u1SetValue;
    INT32  i4GetValue;
}MTFE_OP_PAREMETER_T;
//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**tuner init.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNER_Init(VOID);

/**set tuner frequency.
*@param  ptTunePara       Pointer to Tune_Parameter struct
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_TUNER_SetFreq(MTFE_TUNER_TUNE_PARAMETER_T *ptTunePara);

EXTERN MT_RESULT_T MTFE_TUNER_GetRssi(INT16 *ptRssi);
#ifdef __cplusplus
}
#endif

#endif //MT_FE_TUNER_H
