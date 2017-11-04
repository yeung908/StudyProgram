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
 * $RCSfile: mtvdo_mwif.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtvdo_mwif.h
 *  This header file declares exported APIs of Video (VDO) module.
 */

#ifndef MT_VDO_MWIF_H
#define MT_VDO_MWIF_H

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mttype.h"
#include "mtvdo.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
/**Video information after video source change
*/
typedef struct
{
    UINT32 u4SrcWidth;              ///< new source width
    UINT32 u4SrcHeight;  	        ///< new source height
    UINT32 u4OutWidth; 	            ///< new output width
    UINT32 u4OutHeight; 	        ///< new output height  
    UINT32 u4FrameRate;             ///< new frame rate
    UINT32 u4Interlace;             ///< new scan mode
} MTVDO_SOURCE_CHG_INFO_T;

/**Function type of MW source change notification.
*/
typedef void (*MTVDO_SRC_CHG_MW_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    MTVDO_SOURCE_CHG_INFO_T rSrcInfo
);

/**Function type of display mode notification.
*/
typedef void (*MTVDO_DISPMODE_NOTIFY)
(
    MTVDO_PATH_T eVdpId, 
    UINT32 u4Status
);

/**Function type of source range change notification.
*/
typedef void (*MTVDO_SRC_RANGE_CHG_NOTIFY)
(
    MTVDO_PATH_T eVdpId,
    UINT32 u4X,
    UINT32 u4Y,
    UINT32 u4Width,
    UINT32 u4Height
);

/**Function type of output range change notificatoon.
*/
typedef void (*MTVDO_OUT_RANGE_CHG_NOTIFY)
(
    MTVDO_PATH_T eVdpId,
    UINT32 u4X,
    UINT32 u4Y,
    UINT32 u4Width,
    UINT32 u4Height
);

/**Function type of MM condition notification.
*/
typedef void (*MTVDO_MM_EOS_NOTIFY)
(
    UINT32 u4VdpId, 
    UINT32 eCond, 
    BOOL fgFastForward,
    UINT32 u4AttachedSrcId
);

/**Function type of MM step done notification.
*/
typedef void (*MTVDO_MM_STEP_DONE_NOTIFY)
(
    UINT32 u4VdpId, 
    UINT32 u4PTS, 
    UINT32 u4Ret, 
    UINT32 u4AttachedId
);

/**Function type of MM seek done notification
*/
typedef void (*MTVDO_MM_SEEK_DONE_NOTIFY)
(
    UINT32 u4SwdmxSrcId, 
    UINT32 u4VdpId, 
    UINT32 u4PTS, 
    UINT32 u4Ret
);

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
/**Get 3D navigation mode.
*@param pu4Enable                   UINT32 pointer of 3D navigation mode.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Get3DNavMode(UINT32 *pu4Enable);

/**Get 3D image safety level.
*@param pu4Level                    UINT32 pointer of 3D image safety level.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Get3DImgSafetyLvl(UINT32 *pu4Level);

/**Set PE_UI_VQ_MIN_MAX_DFT parameters.
*@param u1SrcType                   Source type.
*@param eArgType                    Argument type.
*@param prUIParam                   MTVDO_UI_RANGE_T pointer of UI parameters.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/    
EXTERN MT_RESULT_T MTVDO_SetPeUiRangeParam(UINT8 u1SrcType, MTVDO_ARG_TYPE_T eArgType, const MTVDO_UI_RANGE_T *prUIParam);

/**Get PE_UI_VQ_MIN_MAX_DFT Parameters.
*@param eVdpId                      Video plane ID.
*@param eArgType                    Argument type.
*@param prUIParam                   MTVDO_UI_RANGE_T pointer of UI parameters.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/    
EXTERN MT_RESULT_T MTVDO_GetPeUiRangeParam(MTVDO_PATH_T eVdpId, MTVDO_ARG_TYPE_T eArgType, MTVDO_UI_RANGE_T *prUIParam);

/**Set down bandwidth enable.
*@param eVdpId                      Video plane ID.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetDownBwMode(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**Set conditional force unmute.
*@param eVdpId                      Video plane ID.
*@param eUnmuteType				    Force unmute type.
*@param fgEnable                    Enable/Disable.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetCondForceUnmute(MTVDO_PATH_T eVdpId, MTVDO_FORCE_UNMUTE_T eUnmuteType, BOOL fgEnable);

/**Get video capability.
*@param eVdpId                      Video plane ID.
*@param eCapType				    Capability type.
*@param pucIsSupport                Support or not.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetCapability(MTVDO_PATH_T eVdpId, MTVDO_CAPABILITY_T eCapType, UCHAR *pucIsSupport);

/**Enable/Disable letterbox.
*@param eVdpId                      Video plane ID.
*@param pucEnable				    Pointer of enable/disable parameter.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLBoxEnable(MTVDO_PATH_T eVdpId, BOOL fgEnable);

/**Get letterbox status.
*@param eVdpId                      Video plane ID.
*@param pucEnable				    Pointer of letterbox enable status.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetLBoxEnable(MTVDO_PATH_T eVdpId, UCHAR *pucEnable);

/**Configure letterbox.
*@param eVdpId                      Video plane ID.
*@param u4DetPeriod				    Detection period.
*@param u4Ratio					    Ratio.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetLBoxConfig(MTVDO_PATH_T eVdpId, UINT32 u4DetectPeriod, UINT32 u4Ratio);

/**Set SRM Mode
*@param eVdpId                      Video plane ID.
*@param eSrmMode				    SRM Mode
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetSrmMode(MTVDO_PATH_T eVdpId, MTVDO_SRM_MODE_T eSrmMode);

/**Update Command Delay.
*@param eVdpId                      Video plane ID.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_UpdateCmdDelay(MTVDO_PATH_T eVdpId);

/**Get Command Delay.
*@param eVdpId                      Video plane ID.
*@param pu4CmdDelay				    Command delay.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetCmdDelay(MTVDO_PATH_T eVdpId, UINT32 *pu4CmdDelay);

/**Set video mute.
*@param eVdpId                      Video plane ID.
*@param eMuteType				    Mute type.
*@param u4UnMuteDelay			    Unmute delay.
*@param bReplaceByLongerDelay	    Enable/Disable replacement by longer delay
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetVideoMute(MTVDO_PATH_T eVdpId, MTVDO_MUTE_T eMuteType, UINT32 u4UnMuteDelay, BOOL bReplaceByLongerDelay);

/**Set dynamic scale.
*@param eVdpId                      Video plane ID.
*@param u4Delay					    Delay
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetDynamicScale(MTVDO_PATH_T eVdpId, UINT32 u4Delay);

/**Get Dynamic scale setting.
*@param eVdpId                      Video plane ID.
*@param pu4Delay				    Delay
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetDynamicScale(MTVDO_PATH_T eVdpId, UINT32 *pu4Delay);

/**Get DRAM information.
*@param eVdpId                      Video plane ID.
*@param prDramInfo				    DRAM information.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetDramInfo(MTVDO_PATH_T eVdpId, MTVDO_DRAM_INFO_T *prDramInfo);

/**Get Scaler display mode
*@param pucEanble				   TRUE/FALSE.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetScalerDispMode(UCHAR *pucEnable);

/**Get minimum width of source region.
*@param u4MinVal				   Minimum value.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMinSrcRegionWidth(UINT32 *pu4MinVal);

/**Get minimum height of source region.
*@param u4MinVal				   Minimum value.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMinSrcRegionHeight(UINT32 *pu4MinVal);

/**Get mirror and flip status.
*@param u4MirrorFlip		        1: query mirror status; 0(ENUM_MIRROR_TYPE): query flip status(ENUM_FLIP_TYPE)
*@param pu4Status			        Returned status of mirror/flip
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_GetMirrorFlip(UINT32 u4MirrorFlip, UINT32 *pu4Status);

/**Set mirror and flip. 
*@param u4MirrorFlip		        1: query mirror status; 0(ENUM_MIRROR_TYPE): query flip status(ENUM_FLIP_TYPE)
*@param u4OnOff			            Mirror/flip on/off.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_SetMirrorFlip(UINT32 u4MirrorFlip, UINT32 u4OnOff);

/**Set 3D image safety level
*@param u4Level			            3D image safety level
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Set3DImgSafetyLvl(UINT32 u4Level);

/**Get 3D format capability
*@param eVdpId                      Video plane ID.
*@param pu4Cap			            capability pointer
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Get3DFmtCap(MTVDO_PATH_T eVdpId, UINT32 *pu4Cap);

/**Get 3D control capability
*@param eVdpId                      Video plane ID.
*@param pu4Cap			            Capability pointer.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_Get3DCtrlCap(MTVDO_PATH_T eVdpId, UINT32 *pu4Cap);

/**Initialize extmjc module.
*@param void                        None.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVDO_ExtmjcInit(void);

#endif //MT_VDO_MWIF_H
