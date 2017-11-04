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

/** @file mtvss.h
 *  This header file declares exported APIs of VSS module.
 */
#ifndef MT_VSS_H
#define MT_VSS_H

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
/** VSS color space
*/
typedef enum
{
    MTVSS_CID_BT709 = 0,            ///< BT709
    MTVSS_CID_BT601 = 1,            ///< BT601
	MTVSS_CID_MAX
} MTVSS_COLOR_SPACE_T;

/** Input source type
*/
typedef enum
{
	MTVSS_INPUT_TYPE_HDMI = 0,      ///< HDMI
    MTVSS_INPUT_TYPE_COMPOSITE = 1, ///< CVBS
    MTVSS_INPUT_TYPE_COMPONENT = 2, ///< Component YPbPr
    MTVSS_INPUT_TYPE_COAXIAL   = 3, ///< Coaxial
    MTVSS_INPUT_TYPE_SVIDEO    = 4, ///< S-video
    MTVSS_INPUT_TYPE_VGA       = 5, ///< VGA
	MTVSS_INPUT_TYPE_MAX
} MTVSS_INPUT_TYPE_T;

/** Screen capture mode
*/
typedef enum
{
    MTVSS_SCREEN_CAPTURE_NOT_SUPPORTED = 0, ///< Not supported
	MTVSS_SCREEN_CAPTURE_FROM_OMUX = 1, ///< From OMUX
    MTVSS_SCREEN_CAPTURE_FROM_OSTG = 2, ///< From output Stage
	MTVSS_SCREEN_CAPTURE_MAX
} MTVSS_SCREEN_CAPTURE_MODE_T;

/** GFX dump Path
*/
typedef enum {
  MTVSS_MAIN,
  MTVSS_SUB,
  MTVSS_MAIN_MIB,
  MTVSS_SUB_MIB,
  MTVSS_MAIN_PREPROC,
  MTVSS_SUB_PREPROC,
  MTVSS_MON_OUT,
  MTVSS_MAX
} MTVSS_PATH_T;

/** Platform information
*/
typedef struct
{
    CHAR *make;                     ///< Make
    CHAR *model_id;                 ///< Model ID
    CHAR *model_description;        ///< Model description
    CHAR *firmware_version;         ///< Firmware version
} platform_info_t;


typedef struct
{
    UINT16 ui2_width;
    UINT16 ui2_height;

    /*  Time stamp */
    UINT32          ui4_seconds;  /* Seconds */
    UINT32          ui4_micros;   /* Microseconds */

    /* Dump format */
    UINT8 ui1_dump_fmt;
} FRAME_BUFFER_INFO_T;

typedef enum
{
	_RGBA8888,
	_RGB565,
	_RGBA2101010,
	_YUVA2101010,
	_YUV422,
	_RGBA1010102,
	_FORMAT_NONE = 0xff

} MTVSS_DUMP_FORMAT;


//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
/**VSS Initialization
*@param void                        void.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_Init(void);

/**VSS Set color format
*@param ColorFmt                    Color format.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_SetColorFormat(UINT32 ColorFmt);
EXTERN MT_RESULT_T MTVSS_SetDumpFormat(UINT32 DumpFmt);

/**VSS Connect
*@param eVdpId                      Video plane id.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_Connect(MTVDO_PATH_T eVdpId);
EXTERN MT_RESULT_T MTVSS_ConnectEx(MTVSS_PATH_T eVdpId);
EXTERN MT_RESULT_T MTVSS_ConnectAll(MTVSS_PATH_T eVdpId);

 /**VSS Disconnect
 *@param eVdpId                     Video plane id.
 *@retval MTR_OK                    Success.
 *@retval MTR_NOT_OK                Fail.
 */
EXTERN MT_RESULT_T MTVSS_Disconnect(MTVDO_PATH_T eVdpId);
EXTERN MT_RESULT_T MTVSS_DisconnectEx(MTVSS_PATH_T eVdpId);
EXTERN MT_RESULT_T MTVSS_DisconnectAll(MTVSS_PATH_T eVdpId);

/**VSS Get video information
*@param width                       Width
*@param height                      Height
*@param color                       Color
*@param source                      Source
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetVideoInfo(UINT16 *width, UINT16 *height, UINT16 *color, UINT16 *source);

/**VSS Mapping physical to user space address
*@param u4Addr                      Physical address
*@param u4VirtAddr                  Virtual address
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_Phy2Virt(UINT32 u4Addr, UINT32 *u4VirtAddr);

/**VSS Mapping physical to user space address
*@param Base0                       Pointer of base address 0
*@param Base1                       Pointer of base address 1
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetAddrBase(UINT32 *Base0, UINT32 *Base1);

/**VSS Get platform information
*@param info                        Platform information.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetPlatformInfo(platform_info_t *info);

/**VSS Get frame buffer
*@param roi_x                       ROI X offset
*@param roi_y                       ROI Y offset
*@param roi_width                   ROI width
*@param roi_height                  ROI height
*@param buffer                      ROI buffer
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetFrameBuffer(UINT16 roi_x, UINT16 roi_y, UINT16 roi_width, UINT16 roi_height, UINT8 *buffer);


/**VSS Get frame buffer
*@param roi_x                       ROI X offset
*@param roi_y                       ROI Y offset
*@param roi_width                   ROI width
*@param roi_height                  ROI height
*@param buffer                      ROI buffer
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetFrameBufferEx(UINT16 roi_x, UINT16 roi_y, UINT16 roi_width, UINT16 roi_height, UINT8 *buffer);



/**VSS Get screen capture mode
*@param pu4Mode                     Pointer of capture mode
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetScreenCaptureMode(MTVSS_SCREEN_CAPTURE_MODE_T *peMode);

/**VSS Set frame callback function
*@param newframe                    New frame
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_SetFrameCallback(void (*newframe)(void));

/**VSS Set trigger function
*@param void                        void.
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_SetTrigger(void);

/**VSS Get frame index function
*@param index                       Frame index
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetFrameBufferIndex(UINT8 *index);

/**VSS Get Capture buffer
*@param u1ImgRzId                  u1ImgRzId
*@param u1SrcType                  u1SrcType
*@param buffer                     buffer
*@param u4Width                    u4Width
*@param u4Height                   u4Height
*@param u4Pitch                    u4Pitch
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVSS_GetCaptureBuffer(UINT8 u1ImgRzId, UINT8 u1SrcType, UINT8 *pu1Buffer, UINT32 *pu4Width, UINT32 *pu4Height, UINT32 *pu4Pitch);
/**VSS Set frame index function
*@param index                       Frame index
*@retval MTR_OK                     Success.
*@retval MTR_NOT_OK                 Fail.
*/
EXTERN MT_RESULT_T MTVSS_SetFrameBufferIndex(UINT8 index);

#ifdef __cplusplus
}
#endif

#endif
