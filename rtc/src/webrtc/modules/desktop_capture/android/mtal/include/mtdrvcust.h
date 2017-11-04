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
 *---------------------------------------------------------------------------*/

/** @file mtdrvcust.h
 *  This header file declares exported APIs of Driver customization folder.
 */
#ifndef MT_DRVCUST_H
#define MT_DRVCUST_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"

#include "drvcust_if.h"
  
#include "u_common.h"
#include "x_rm.h"
#include "u_rm_dev_types.h"
#include "u_drv_cust.h"
  
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
typedef enum
{
    MTCHIP_SPEC_MHEG5,
    MTCHIP_SPEC_CIPLUS,
    MTCHIP_SPEC_TCON,
    MTCHIP_SPEC_CHINATV,
    MTCHIP_SPEC_MHEGHD,
    MTCHIP_SPEC_OPERA,
    MTCHIP_SPEC_JVM,
    MTCHIP_SPEC_ARIB,
    MTCHIP_SPEC_GINGA,
    MTCHIP_SPEC_MHP,
    MTCHIP_SPEC_DMBT,
    MTCHIP_SPEC_ATSC,
    MTCHIP_SPEC_BRAZIL,
    MTCHIP_SPEC_DVB,
    MTCHIP_SPEC_HBBTV,
    MTCHIP_SPEC_ANDROID,
    MTCHIP_SPEC_CINEMA,
    MTCHIP_SPEC_QJY,
    MTCHIP_SPEC_IPTV,
    MTCHIP_SPEC_PLAYRDY,
    MTCHIP_SPEC_MSS
} MTCHIP_SPEC_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/** Driver customization interface function.
 *  This function is driver module to get different setting of PCB at boot stage.
 *
 *  @param  eQryType        The query type definition.
 *  @param  pu4Data         The pointer points to the setting data of the type.
 *  @retval 0               Succeed
 *  @retval otherwise       Fail. There is no setting.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRVCUST_InitQuery(QUERY_TYPE_T eQryType, UINT32 *pu4Data);

//-----------------------------------------------------------------------------
/** Driver customization interface function.
 *  This function is driver module to get different setting of PCB at boot stage.
 *
 *  @param  eQryType        The query type definition.
 *  @retval The value of the query type setting data.
 */
//-----------------------------------------------------------------------------
EXTERN UINT32 MTDRVCUST_InitGet(QUERY_TYPE_T eQryType);

//-----------------------------------------------------------------------------
/** Driver customization interface function.
 *  This function is driver module to get different setting of PCB.
 *
 *  @param  eQryType        The query type definition.
 *  @param  pu4Data         The pointer points to the setting data of the type.
 *  @retval 0               Succeed
 *  @retval otherwise       Fail. There is no setting.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDRVCUST_OptQuery(QUERY_TYPE_T eQryType, UINT32 *pu4Data);

//-----------------------------------------------------------------------------
/** Driver customization interface function.
 *  This function is driver module to get different setting of PCB.
 *
 *  @param  eQryType        The query type definition.
 *  @retval The value of the query type setting data.
 */
//-----------------------------------------------------------------------------
EXTERN UINT32 MTDRVCUST_OptGet(QUERY_TYPE_T eQryType);

EXTERN BOOL MTDRVCUST_IsSupport(MTCHIP_SPEC_T eSpec);
//-----------------------------------------------------------------------------
/** Get Country Setting
 *  This function is driver module to get country setting
 *
 *  @param  u4Country	The country type
 *  @retval MTR_OK                    Success.
 *  @retval MTR_NOT_OK                Fail.
 */
//-----------------------------------------------------------------------------
EXTERN UINT32 MTDRVCUST_GetCountry(void);

EXTERN UINT32 MTDRVCUST_GetCountryMask(UINT32 u4Mask);

//-----------------------------------------------------------------------------
/** Set Country Setting
 *  This function is driver module to set country setting
 *
 *  @param  u4Country	The set country type
 *  @retval MTR_OK                    Success.
 *  @retval MTR_NOT_OK                Fail.
 */
//-----------------------------------------------------------------------------
EXTERN UINT32 MTDRVCUST_SetCountry(UINT32 u4Country);


EXTERN INT32 MTDRVCUST_dcustom_tuner_set(
    DRV_CUSTOM_TUNER_TYPE_T         e_tuner_type,
    DRV_CUSTOM_TUNER_SET_TYPE_T     e_tuner_set_type,
    VOID*                           pv_set_info,
    SIZE_T                          z_size);

EXTERN INT32 MTDRVCUST_dcustom_tuner_get (
    DRV_CUSTOM_TUNER_TYPE_T         e_tuner_type,
    DRV_CUSTOM_TUNER_GET_TYPE_T     e_tuner_get_type,
    VOID*                           pv_get_info,
    SIZE_T*                         pz_size);

EXTERN INT32 MTDRVCUST_dcustom_vid_set(DRV_CUSTOM_VID_TYPE_T e_vid_type,
                              VOID * pv_set_info, SIZE_T z_size, BOOL b_store);

EXTERN INT32 MTDRVCUST_dcustom_vid_get(DRV_CUSTOM_VID_TYPE_T e_vid_type,
                       DRV_CUSTOM_VID_INP_T e_vid_inp,
                       VOID * pv_get_info, SIZE_T * pz_size);

EXTERN INT32 MTDRVCUST_dcustom_extmjc_set(
    DRV_CUSTOM_EXTMJC_TYPE_T    e_extmjc_type,
    VOID*                       pv_set_info,
    SIZE_T                      z_size,
    BOOL                        b_store);

EXTERN INT32 MTDRVCUST_dcustom_vid_get_gamma(GAMMA_INFO_T * pu1GammaTbl);

EXTERN INT32 MTDRVCUST_dcustom_vid_get_min_max(DRV_CUSTOM_VID_TYPE_T e_vid_type,
                                      DRV_CUSTOM_VID_INP_T e_vid_inp,
                                      UINT16 * pui2_min, UINT16 * pui2_max);

EXTERN INT32 MTDRVCUST_dcustom_extmjc_get (
    DRV_CUSTOM_EXTMJC_TYPE_T    e_extmjc_type,
    VOID*                       pv_get_info,
    SIZE_T*                     pz_size);

EXTERN void MTDRVCUST_SetDrvInit(UINT32 u4Flag);

EXTERN INT32 MTDRVCUST_dcustom_misc_set (
    DRV_CUSTOM_MISC_TYPE_T    e_misc_type,
    VOID*                     pv_set_info,
    SIZE_T                    z_size,
    BOOL                      b_store );

EXTERN INT32 MTDRVCUST_dcustom_misc_get (
    DRV_CUSTOM_MISC_TYPE_T    e_misc_type,
    VOID*                     pv_get_info,
    SIZE_T*                   pz_size );

EXTERN INT32 MTDRVCUST_dcustom_misc_get_min_max (
    DRV_CUSTOM_MISC_TYPE_T    e_misc_type,
    UINT16 * pui2_min, UINT16 * pui2_max);


EXTERN INT32 MTDRVCUST_dcustom_cust_spec_set (
    DRV_CUSTOM_CUST_SPEC_TYPE_T    e_cust_spec_type,
    VOID*                          pv_set_info,
    SIZE_T                         z_size,
    BOOL                           b_store);

EXTERN INT32 MTDRVCUST_dcustom_cust_spec_get(
    DRV_CUSTOM_CUST_SPEC_TYPE_T    e_cust_spec_type,
    VOID*                          pv_get_info,
    SIZE_T*                        pz_size);

EXTERN void MTDRVCUST_BootupCheck(void);

#ifdef __cplusplus
}
#endif

#endif

