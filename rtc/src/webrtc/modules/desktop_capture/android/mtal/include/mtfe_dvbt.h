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
 * $RCSfile: mtfe_dvbt.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtfe_dvbt.h
 *  This header file declares exported APIs of DVBT module.
 */

#ifndef MT_FE_DVBT_H
#define MT_FE_DVBT_H

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

typedef enum
{
    MTFE_DVBT_FFT_2K = 0,
    MTFE_DVBT_FFT_8K,
    MTFE_DVBT_FFT_4K,
    MTFE_DVBT_FFT_RESERVED
}MTFE_DVBT_FFT_MODE_T;

typedef enum
{
    MTFE_DVBT_QPSK = 0,
    MTFE_DVBT_16QAM,
    MTFE_DVBT_64QAM,
    MTFE_DVBT_CONS_RESERVED
}MTFE_DVBT_CONSTELLATION_T;

typedef enum
{
    MTFE_DVBT_CR_1_2 = 0,
    MTFE_DVBT_CR_2_3,
    MTFE_DVBT_CR_3_4,
    MTFE_DVBT_CR_5_6,
    MTFE_DVBT_CR_7_8,
    MTFE_DVBT_CR_RESERVED
}MTFE_DVBT_CODE_RATE_T;

typedef enum
{
    MTFE_DVBT_GI_1_32 = 0,
    MTFE_DVBT_GI_1_16,
    MTFE_DVBT_GI_1_8,
    MTFE_DVBT_GI_1_4
}MTFE_DVBT_GUARD_INTERVAL_T;


/**This structure contains the dvbt demod parameter for hierarchical transmission.
*/
typedef enum
{
    HIR_DVBT_NONE = 0,
    HIR_DVBT_ALPHA_1,
    HIR_DVBT_ALPHA_2,
    HIR_DVBT_ALPHA_4
}MTFE_DVBT_HIERARCHY_MODE_T;

typedef enum
{
    HIR_DVBT_PRIORITY_UNKNOWN = 0,
    HIR_DVBT_PRIORITY_NONE,
    HIR_DVBT_PRIORITY_HIGH,
    HIR_DVBT_PRIORITY_LOW
}MTFE_DVBT_HIERARCHY_T;

typedef enum
{
    MTFE_DVBT_HPLP_HP = 0,
    MTFE_DVBT_HPLP_LP,
}MTFE_DVBT_HPLP_T;

typedef enum
{
    MTFE_DVBT_BW_6M = 0,
    MTFE_DVBT_BW_7M,
    MTFE_DVBT_BW_8M,
    MTFE_DVBT_BW_5M,
}MTFE_DVBT_BW_T;



/**This structure contains the dvbt demod parameter for connection.
*/
typedef struct
{
    UINT32                      u4Freq;             // RF center frequency in KHz
    //UINT32                      u4IF; 				//IF  frequency in KHz

	MTFE_DVBT_BW_T         eBandwidth;     // Bandwidth
    //MTFE_BW_T                   eBandwidth;         // Bandwidth
    MTFE_SURF_MOD_T             eSurfMode;          // Surf mode
    MTFE_DVBT_HIERARCHY_T       eHierarchy;         // Hierarchical mode
    //UINT8					 m_aucPara[30];
	MTFE_DTV_STATUS_T           rLockStatus;        // Lock status
    BOOL                   fgReceiveConnectCmd;     // protection in MonitorProcess and Connect/GetSync
}MTFE_DVBT_PARAMETER_T;

/**This structure contains the dvbt TPS parameters.
*/
typedef struct
{
    MTFE_DVBT_FFT_MODE_T        eFftMode;           // FFT mode
    MTFE_DVBT_CONSTELLATION_T   eConstellation;     // constellation
    MTFE_DVBT_GUARD_INTERVAL_T  eGuardInterval;     // guard interval
    MTFE_DVBT_CODE_RATE_T       eCodeRateHp;        // HP code rate
    MTFE_DVBT_CODE_RATE_T       eCodeRateLp;        // LP code rate
    MTFE_DVBT_HIERARCHY_MODE_T  eHierMode;          // Hierarchical mode
    UINT16                      u2CellId;           // cell ID
	MTFE_DVBT_HPLP_T            eHpLp;              //Hplp
	MTFE_DVBT_BW_T              eBW;                //BW
    MTFE_DVBT_CODE_RATE_T       eCR;                //Code rate

	//use the enum type instead of UINT8;
	//UINT8                             u1HpLp;
    //UINT8                             u1Bw;
    //UINT8                             u1Mod;// the same with eConstellation
    //UINT8                             u1CR;    
}MTFE_DVBT_TPS_PARAM_T;

/**This callback function for dvbt demod module.
*/
typedef VOID (*MTFE_DVBT_PFN_CB) (UINT8 u1CbId, VOID* pvArg);

/**This structure contains the dvbt demod parameter for connection.
*/
typedef struct
{
    UINT16  u2IF_Freq;
    UINT8   u1IFAGCLevelMax;
    UINT8   u1IFAGCLevelMin;
    UINT8   u1IFAGC_SLP;
    UINT8   u1IFAGC_INT;
    UINT8   u1IFAGC_MAX;
    UINT8   u1IFAGC_MIN;
    UINT8   fgRFTuner;
//    UINT8   u1IFAGCTargetLevel;
    UINT8   uSLD_DefaultPGAIndex; //default fixed PGA gain index for tuner matching, only fixed for legacy. lei110715

}MTFE_DVBT_TUNER_CONFIG_T;


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** Initialize front end DVB-T demod module.
*@param VOID
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Open(VOID);

/** Terminate front end DVB-T demod module.
*@param VOID
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Close(VOID);

/** Start demod module to acquire to specified frequency and bandwidth...
*@param  rParameter         Acquisition parameter (RF freq , bandwidth,..).
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Connect(MTFE_DVBT_PARAMETER_T *prParameter);

/**Stop acquisition and put Demod into sleep mode.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_DisConnect(VOID);

/** Get demod lock status.
*@param	 pi2LockStatus      Lock / unlock.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetSync(MTFE_DVBT_PARAMETER_T* prStatus);


/** Get Signal power level in percentage.
*@param pi2SigLevel         Signal power level in percentage.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetSignalLevel(INT16 *pi2SigLevel); 

/**Get packet error rate.
*@param pu4TotalPkt         Received total packets.
*@param pu4ErrPkt           Received error packets.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetPER(UINT32 *pu4TotalPkt, UINT32 *pu4ErrPkt);

/**Get SNR in dB.
*@param u2SignalSNR         Signal SNR
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetSNR(UINT16 *pu2SignalSNR);


/**Get SQI in %
*@param u4SQI         Signal Quality Indicator
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetSQI(UINT32 *pu4SQI);


/**Get IF AGC Voltage in mV.
*@param  pu2IfAgcVol        IF AGC voltage in mV.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetIfAgcVol(UINT16 *pu2IfAgcVol);

/**Get Post Viterbi BER and Pre Viterbi BER.
*@param  pi4PostVBer        Post Viterbi BER * 10^5.
*@param  pi4PreVBer         Pre  Viterbi BER * 10^5.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetBER(INT32 *pi4PostVBer, INT32 *pi4PreVBer);

/**Get TPS parameters.
*@param  tps                ---.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetTPS(MTFE_DVBT_TPS_PARAM_T *tps);

/**Get  total error  and error count.
*@param  BerWindow        
*@param  BerCount         
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetErrParam(INT32 *BerWindow, INT32 *BerCount);

/**Get frequency offset.
*@param  offset             ---.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetFreqOffset(UINT32* offset);

/** Check demod software version.
*@param  u1Version          Software Version.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetVer(UCHAR *pszVersion);


/**Register demod callback function.
*@param  CbId               Callback function ID.
*@param  pfCb               Callback function.
*@param  vArg               The argument of callback function.
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
//EXTERN MT_RESULT_T MTFE_DVBT_RegCb(UINT8 u1CbId, MTFE_DVBT_PFN_CB pfCb, VOID* pvArg);

EXTERN MT_RESULT_T MTFE_DVBT_RegCb(MTFE_CB_FCT pfCb);

/** Setup tuner confiuration to demod.
*@param  pTunerConfig       Config of Tuner
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Tuner_Config(MTFE_DVBT_TUNER_CONFIG_T *pTunerConfig);


/**set demod TS out mode.
*@param  fgParallel         TRUE:Parallel;   FALSE:serial
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
//MT_RESULT_T MTFE_DVBC_RegCb(UINT8 u1CbId, MTFE_DVBC_PFN_CB pfCb, VOID* pvArg)
EXTERN MT_RESULT_T MTFE_DVBT_SetTSInterface(BOOL *fgParallel);


/**set demod TS Path.
*@param  fgEnable            TRUE:Enable;   FALSE:Disable
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/

EXTERN MT_RESULT_T MTFE_DVBT_SetTSPath(BOOL *fgEnable);

/**set demod TS PAD.
*@param  puTsPadCtrl			Ts pad control word
							bit0: Ts clk pad enable/disable
							bit1: Ts sync/valid pad enabel/disable
							bit2: Ts Data pad enable/disable
*@retval MT_OK				Success.
*@retval MT_NOT_OK			Fail.
*/

EXTERN MT_RESULT_T MTFE_DVBT_SetTSPAD(UINT8 *puTsPadCtrl);

/**set demod TS Ctrl.
*@param  puTsCtrl			 Ts control word
					        bit0: Ts clock gated or continues
					        bit1: Ts sync active low or high
					        bit2: Ts error active low or high
*@retval MT_OK				Success.
*@retval MT_NOT_OK			Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_SetTSCtrl(UINT8 *puTsCtrl);

/**get demod TS format.
*@param  pu1TsFmt			 Ts format
                                                  bit0: data valida at posttive or negative edge
                                                  bit1: clk gated or non gated
                                                  bit2: serial or parralle
                                                  bit3: Ts error indicator changed or not changed
                                                  bit4: sync active high or low
                                                  bit5: error active high or low
                                                  bit6: valid active high or low
*@retval MT_OK				Success.
*@retval MT_NOT_OK			Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_GetTsFormat(UINT8 *pu1TsFmt);

/**set demod TS format.
*@param  pu1TsFmt			 Ts format
                                                  bit0: data valida at posttive or negative edge
                                                  bit1: clk gated or non gated
                                                  bit2: serial or parralle
                                                  bit3: Ts error indicator changed or not changed
                                                  bit4: sync active high or low
                                                  bit5: error active high or low
                                                  bit6: valid active high or low

*@retval MT_OK				Success.
*@retval MT_NOT_OK			Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_SetTsFormat(UINT8 *pu1TsFmt);

/** Suspend front end DVB-T demod module.
*@param VOID
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Suspend(VOID);

/** Resume front end DVB-T demod module.
*@param VOID
*@retval MT_OK              Success.
*@retval MT_NOT_OK          Fail.
*/
EXTERN MT_RESULT_T MTFE_DVBT_Resume(VOID);


#ifdef __cplusplus
}
#endif

#endif //MT_FE_DVBT_H
