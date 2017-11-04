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
 * $RCSfile: ioctl_param.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 * $CCRevision: /main/DTV_X_HQ_int/DTV_X_ATSC/10 $
 * $SWAuthor: ywang $
 * $MD5HEX: aa9505887b10174037bab343688f2980 $
 *
 * Description:
 *---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    include files
 ----------------------------------------------------------------------------*/

#ifndef IOCTL_PARAM_H_
#define IOCTL_PARAM_H_

#define IOCTL_ADPT_START    0x40
typedef enum
{
    CB_SET_CALLBACK_ADPT = IOCTL_ADPT_START,
    CB_GET_CALLBACK_ADPT,
    CB_FIN_CALLBACK_ADPT,
    IOCTRL_SET_DRV_NFY_PARAM_BUFFER,
    IOCTL_ADPT_END
}HF_IOCTL_PARAM_T;

#define IOCTL_RM_START      0x200
typedef enum
{
    IOCTRL_SET_USER_VIRT_START = IOCTL_RM_START,
    IOCTRL_MALLOC_SHM,
    IOCTL_HANDLE_GET_INFO,
    IOCTL_HANDLE_GET_TAG,
    IOCTL_HANDLE_GET_TYPE,
    IOCTL_HANDLE_SET_TAG,
    IOCTL_HANDLE_VALID,
    IOCTL_TMS_INIT,
    IOCTL_TMS_BEGIN,
    IOCTL_TMS_END,
    IOCTL_TMS_DIFF,
    IOCTL_TMS_SPOT,
    IOCTL_TMS_DUMP,
    IOCTL_TMS_DUMP_DETAIL,
    IOCTL_TMS_CLEAN,
    IOCTL_TMS_GET_LEVEL_FLAG,
    IOCTL_TMS_GET_COMMON_LEVEL,
    IOCTL_TMS_SET_COMMON_LEVEL,
    IOCTL_TMS_SET_TMS_SEL,
    IOCTL_TMS_GET_TMS_SEL,
    IOCTL_TMS_SET_FLAG,
    IOCTL_TMS_GET_FLAG,
    IOCTL_TTX_MAP_ADDR,
    IOCTRL_MALLOC_SHM2,
    IOCTRL_FREE_SHM2,   
    IOCTL_RM_END
}MW_RM_IOCTL_PARAM_T;


#define IOCTL_DIRECT_START  0x400
typedef enum
{
    IOCTL_GET_DRV_TICK = IOCTL_DIRECT_START,
    IOCTL_GET_TICK_PERIOD,
    IOCTL_GET_FINE_TICK,
    IOCTRL_HW_TICK,
    IOCTL_RESET_GAMMA,
    IOCTL_D_CUSTOM_AUD_SET,
    IOCTL_D_CUSTOM_AUD_GET,
    IOCTL_D_CUSTOM_AUD_GET_MIN_MAX,
    IOCTL_D_CUSTOM_TUNER_SET,
    IOCTL_D_CUSTOM_TUNER_GET,
    IOCTL_VDP_SETOUTREGION,
    IOCTL_OSD_GET_ORDER,
    IOCTL_OSD_SET_ORDER,
    IOCTL_TEST_SURF,
    IOCTL_THREAD_END,
    IOCTL_VDP_CheckDisplayMode,
    /* MHF Linux - Basara */
    IOCTL_SET_AGT_REQ_ACK_FNT, 
    IOCTL_AGT_REQ_ACK,
    /* MHF Linux - Chun Jiang for FBM mmap*/
    IOCTL_GET_FBM_SIZE,
    IOCTL_GET_FBM_PHY_ADDR,
    /* Flash bulk write */
    IOCTL_PART_BULK_WRITE,
    IOCTL_SET_TIMESTAMP,
    /* ---TEST COMMAND ----*/
    IOCTL_TEST_COMMAND
}DIRECT_IOCTL_PARAM_T;


#define _MARJO              229
#define CLI_MARJO           254
#define MC_NFY_MAX          5
#define DEV_NAME            "/dev/rmmgr"
#define CLI_DEV_NAME        "/dev/cli"
#endif /*IOCTL_PARAM_H_*/
