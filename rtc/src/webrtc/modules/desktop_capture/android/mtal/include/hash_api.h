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
 * $RCSfile: hash_api.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 * $CCRevision: /main/DTV_X/DTV_X_HQ_int/DTV_X_ATSC/1 $
 * $SWAuthor: Iolo Tsai $
 * $MD5HEX: f7efe048c2e8f3c5fa23b17b959b62d2 $
 *
 * Description: 
 *         This header file contains Stream Manager's hash utility.
 *---------------------------------------------------------------------------*/

#ifndef _HASH_API_H_
#define _HASH_API_H_


/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "x_common.h"
#include "x_handle.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/

typedef VOID (*hash_obj_free_fct)( VOID* pv_obj );

typedef INT32 (*hash_parse_fct)( 
    HANDLE_T          h_hash,
    UINT32            ui4_counter,
    VOID*             pv_obj,
    VOID*             pv_parse_tag );

typedef BOOL (*hash_cond_fct)( 
    const INT8*       pi1_key,
    SIZE_T            z_key_size,
    VOID*             pv_obj,
    VOID*             pv_tag );


/* Hash return values */
#define HASH_OK                       ((INT32)  0)
#define HASH_INV_ARG                  ((INT32)  -1)
#define HASH_INV_HANDLE               ((INT32)  -2)
#define HASH_INTERNAL_ERROR           ((INT32)  -3)
#define HASH_OUT_OF_MEMORY            ((INT32)  -4)
#define HASH_PARSE_BREAK              ((INT32)  -5)
#define HASH_NOT_EXIST                ((INT32)  -6)
#define HASH_OUT_OF_HANDLES           ((INT32)  -7)

/*-----------------------------------------------------------------------------
                    functions declarations
-----------------------------------------------------------------------------*/

extern INT32 hash_create( SIZE_T                 z_hash_tbl_size,
                          HANDLE_T*              ph_hash );

extern VOID hash_delete( HANDLE_T                h_hash, 
                         hash_obj_free_fct       pf_obj_free_fct );
                            
extern INT32 hash_add_obj( HANDLE_T              h_hash,
                           const INT8*           pi1_key,
                           SIZE_T                z_key_size,
                           VOID*                 pv_obj,
                           VOID**                ppv_old_obj );    /* OUT */

extern BOOL hash_is_key_exist( HANDLE_T          h_hash,
                               const INT8*       pi1_key,
                               SIZE_T            z_key_size );

extern INT32 hash_remove_obj( HANDLE_T           h_hash,
                              const INT8*        pi1_key,
                              SIZE_T             z_key_size,
                              VOID**             ppv_obj );        /* OUT */

extern INT32 hash_get_obj( HANDLE_T              h_hash,
                           const INT8*           pi1_key,
                           SIZE_T                z_key_size,
                           VOID**                ppv_obj );        /* OUT */

extern INT32 hash_get_size( HANDLE_T             h_hash, 
                            SIZE_T*              pz_size );        /* OUT */

extern INT32 hash_parse( HANDLE_T                h_hash,
                         hash_parse_fct          pf_parse_fct,
                         VOID*                   pv_parse_tag );

extern INT32 hash_del_obj_on_cond( 
    HANDLE_T                h_hash,
    hash_cond_fct           pf_cond_fct,
    hash_obj_free_fct       pf_obj_free_fct,
    VOID*                   pv_tag );

extern INT32 hash_lock( HANDLE_T                 h_hash );

extern INT32 hash_unlock( HANDLE_T               h_hash );

#endif /* _HASH_API_H_ */
