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
 * $RCSfile: mtphoto4k.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtphoto4l.h
 *  This header file declares exported APIs of scaler dram buffer for UD photo.
 */

#ifndef MT_PHOTO4K_H
#define MT_PHOTO4K_H

#ifdef __cplusplus
extern "C"
{
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

typedef enum {
    RGB_TYPE_RGBA8888,
    RGB_TYPE_ARGB8888,
    RGB_TYPE_ABGR8888,
    RGB_TYPE_RGB888,
    RGB_TYPE_ARGB4444,
    RGB_TYPE_RGB565,
    YUV_422_SEP,
    RGB_TYPE_END
}MTPHOTO4K_RGB_TYPE_T;

typedef enum{
    MTPHOTO4K_ROTATION_CLOCKWS_0,
    MTPHOTO4K_ROTATION_CLOCKWS_0_WITH_FLIP,
    MTPHOTO4K_ROTATION_CLOCKWS_90,
    MTPHOTO4K_ROTATION_CLOCKWS_90_WITH_FLIP,
    MTPHOTO4K_ROTATION_CLOCKWS_180,
    MTPHOTO4K_ROTATION_CLOCKWS_180_WITH_FLIP,
    MTPHOTO4K_ROTATION_CLOCKWS_270,
    MTPHOTO4K_ROTATION_CLOCKWS_270_WITH_FLIP
}MTPHOTO4K_ROTATION_T;
typedef struct {
    UINT32  u4x;
    UINT32  u4y;
    UINT32  u4Width;
    UINT32  u4Height;
}MTPHOTO4K_DISPLAY_REGION_T;    

typedef struct {
    MTPHOTO4K_RGB_TYPE_T            eType; 
    UINT32                          u4DataAddr;
    UINT32                          u4DataSize;
    MTPHOTO4K_DISPLAY_REGION_T      rDispRegion;
}MTPHOTO4K_DISPLAY_INFO_T;


typedef struct {
    MTPHOTO4K_RGB_TYPE_T            eType; 
    UINT32                          u4DataAddr;
    UINT32                          u4DataSize;
    UINT32                          u4DataPitch;
    MTPHOTO4K_DISPLAY_REGION_T      rDispRegion;
    MTPHOTO4K_DISPLAY_REGION_T      rSrcRegion;
    INT32                           u4VideoPath;
    MTPHOTO4K_ROTATION_T            eRotate;
}MTPHOTO4K_DISPLAY_INFO_EX_T;


typedef enum{
    MTPHOTO4K_FADE_TYPE_IN,
    MTPHOTO4K_FADE_TYPE_OUT,    
}MTPHOTO4K_FADE_TYPE_T;

typedef enum{
    MTPHOTO4K_FADE_BGCOLOR_BLACK,
    MTPHOTO4K_FADE_BGCOLOR_WHITE,
}MTPHOTO4K_FADE_BGCOLOR_T;

typedef struct{
    INT8                        videoPath;
    UINT32                      photoData;
    UINT32                      photoDataSize;
    UINT32                      photoDataPitch;
    MTPHOTO4K_DISPLAY_REGION_T  srcRect;
    MTPHOTO4K_DISPLAY_REGION_T  dstRect;
    MTPHOTO4K_FADE_TYPE_T       fadeType;
    UINT32                      duration;
    MTPHOTO4K_FADE_BGCOLOR_T    fadeBgColor;
    MTPHOTO4K_ROTATION_T        eRotate;
}MTPHOTO4K_FADE_T;
typedef enum{
    MTPHOTO4K_SCROLL_L2R,
    MTPHOTO4K_SCROLL_R2L,
    MTPHOTO4K_SCROLL_T2B,
    MTPHOTO4K_SCROLL_B2T
}MTPHOTO4K_SCROLL_DIRECTION;

typedef struct{
    INT8                        videoPath;
    UINT32                      photoData;
    UINT32                      photoDataSize;
    UINT32                      photoDataPitch;
    MTPHOTO4K_DISPLAY_REGION_T  srcRect;
    MTPHOTO4K_DISPLAY_REGION_T  dstRect;
    UINT32                      duration;
    MTPHOTO4K_SCROLL_DIRECTION  direction;
    MTPHOTO4K_ROTATION_T        eRotate;
}MTPHOTO4K_PANORAMA_T;
typedef enum
{
    MTPHOTO4K_CALLBACK_TYPE_FADE_COMPLETE,
    MTPHOTO4K_CALLBACK_TYPE_FADE_PAUSED,
    MTPHOTO4K_CALLBACK_TYPE_FADE_FAIL,
    MTPHOTO4K_CALLBACK_TYPE_SCROLL_COMPLETE = 100,
    MTPHOTO4K_CALLBACK_TYPE_SCROLL_PAUSED,
    MTPHOTO4K_CALLBACK_TYPE_SCROLL_FAIL,
}MTPHOTO4K_CALLBACK_TYPE_T;

typedef struct
{
    MTPHOTO4K_CALLBACK_TYPE_T       u4Condition;           ///< Callback condition
    UINT32                          u4Param;               ///< Callback paramter    
} MTPHOTO4K_CALLBACK_INFO_T;
typedef struct{
    INT8                        videoPath;
    MTPHOTO4K_FADE_TYPE_T       fadeType;
    UINT32                      fadeFrame;
    MTPHOTO4K_FADE_BGCOLOR_T    fadeBgColor;
    UINT32                      fadeFrameIdx;
}MTPHOTO4K_FADE_B2R_CALLBACK_TAG_T;
typedef struct{
    INT8                        videoPath;
    UINT32                      stepNum;
    MTPHOTO4K_SCROLL_DIRECTION  direction;
    UINT32                      displayWidth;
    UINT32                      displayHeight;
    UINT32                      stepIdx;
}MTPHOTO4K_SCROLL_B2R_CALLBACK_TAG_T;
typedef struct _MTPHOTO4K_STRETCH_BLIT_T
{
    UINT32 src_buffer_Y_addr;
    UINT32 src_buffer_C_addr;
    UINT32 src_buffer_Y_width;
    UINT32 src_buffer_Y_height;
    UINT32 src_buffer_Y_pitch;
    UINT32 dest_buffer_Y_addr;
    UINT32 dest_buffer_C_addr;
    UINT32 dest_buffer_Y_width;
    UINT32 dest_buffer_Y_height;
    UINT32 dest_buffer_Y_pitch;
    
    UINT32 src_clip_x;
    UINT32 src_clip_y;
    UINT32 src_clip_w;
    UINT32 src_clip_h;

    UINT32 dest_clip_x;
    UINT32 dest_clip_y;
    UINT32 dest_clip_w;
    UINT32 dest_clip_h;
} MTPHOTO4K_STRETCH_BLIT_T;
typedef struct
{
    UINT32 u4Src;
    UINT32 u4SrcCbCrOffset;
    UINT32 eSrcCm;
    UINT32 u4SrcPitch;
    UINT32 u4SrcX;
    UINT32 u4SrcY;
    
    UINT32 u4Dst;
    UINT32 u4DstCbCrOffset;
    UINT32 eDstCm;
    UINT32 u4DstPitch;
    UINT32 u4DstX;
    UINT32 u4DstY;
    
    UINT32 u4Width;
    UINT32 u4Height;
    
    UINT32 u4RotateOp;
}MTPHOTO4K_VDP_ROTATE_T;
typedef struct
{
    UINT32 u4Src;
    UINT32 u4SrcCbCrOffset;
    UINT32 eSrcCm;
    UINT32 u4SrcPitch;
    UINT32 u4SrcX;
    UINT32 u4SrcY;
    UINT32 u4SrcWidth;
    UINT32 u4SrcHeight;
    
    UINT32 u4Dst;
    UINT32 u4DstCbCrOffset;
    UINT32 eDstCm;
    UINT32 u4DstPitch;
    UINT32 u4DstX;
    UINT32 u4DstY;
    UINT32 u4DstWidth;
    UINT32 u4DstHeight;
    
    MTPHOTO4K_ROTATION_T eRotate;
}MTPHOTO4K_VDP_ROTATE_EX_T;
#define VDP_ROTATE_90       1 
#define VDP_ROTATE_270      2
#define VDP_ROTATE_180      4
#define VDP_ROTATE_FLIP     8
typedef VOID (*MTPHOTO4K_CALLBACK)(MTPHOTO4K_CALLBACK_TYPE_T eCallbackType, UINT32 u4Param, VOID* pv_tag);
//-----------------------------------------------------------------------------
/**Initialize Scaler buffer for UD Photo
*@param void
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPHOTO4K_Init (VOID);

EXTERN MT_RESULT_T  MTPHOTO4K_Init_Ex (UINT8 u1VideoPath);

//-----------------------------------------------------------------------------
/**Set Display region info Scaler buffer for UD Photo   
*@param stDispInfo             Set display info of photo    
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPHOTO4K_SetDisplayInfo (MTPHOTO4K_DISPLAY_INFO_T stDispInfo);
EXTERN MT_RESULT_T  MTPHOTO4K_SetDisplayInfo_Ex (MTPHOTO4K_DISPLAY_INFO_EX_T stDispInfo);


//-----------------------------------------------------------------------------
/**Show photo 
*@param u1BufNum               buf num
*@param bShow                     Show or hide (TRUE /FALSE)
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPHOTO4K_Show(UINT8 u1BufNum, BOOL bShow);

EXTERN MT_RESULT_T MTPHOTO4K_RegCbFunc(MTPHOTO4K_CALLBACK pf_callback, VOID* pv_tag);

EXTERN MT_RESULT_T MTPHOTO4K_PreparePhoto(MTPHOTO4K_FADE_T tFadeInfo);

EXTERN MT_RESULT_T MTPHOTO4K_StartFadeEffect(MTPHOTO4K_FADE_T tFadeInfo);

EXTERN MT_RESULT_T MTPHOTO4K_PauseFadeEffect(VOID);
EXTERN MT_RESULT_T MTPHOTO4K_RestartFadeEffect(VOID);
EXTERN MT_RESULT_T MTPHOTO4K_StartPanoramaScroll(MTPHOTO4K_PANORAMA_T tScrollInfo);
EXTERN MT_RESULT_T MTPHOTO4K_PausePanoramaScroll(VOID);
EXTERN MT_RESULT_T MTPHOTO4K_RestartPanoramaScroll(VOID);
//-----------------------------------------------------------------------------
/**De-initialize Scaler buffer for UD Photo
*@param void
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPHOTO4K_DeInit (VOID);

EXTERN MT_RESULT_T MTPHOTO4K_Is4KPanel(BOOL* pbIs4KPanel);
#ifdef __cplusplus
}
#endif 
#endif


