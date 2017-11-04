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
 * $RCSfile: mtosd.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtosd.h
 *  This header file declares exported APIs of OSD module.
 */

#ifndef MT_OSD_H
#define MT_OSD_H

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
/**OSD plane enum,plane1 generally used to show video,plane2 and plane3 generally used to show UI.
*/
#ifdef DEBUG_OSD_BY_XY
typedef enum
{
    MTOSD_PLANE_1,
    MTOSD_PLANE_2,
    //#ifdef CC_MT5363
    MTOSD_PLANE_3,
    //#endif
    MTOSD_PLANE_MAX_NUM
} MTOSD_PLANE_T;


/** OSD scaler enum,MTOSD_SCALER_2 correspons plane2,MTOSD_SCALER_3 correspons plane3.
 */
typedef enum
{
    MTOSD_SCALER_2,
    //#ifdef CC_MT5363
    MTOSD_SCALER_3,
    //#endif
    #ifdef CC_MT5396
    MTOSD_SCALER_1,
    #endif
    MTOSD_SCALER_MAX_NUM
} MTOSD_SCALER_T;
#else
#define MTOSD_PLANE_1 1
#define MTOSD_PLANE_2 2
#define MTOSD_PLANE_3 0
#define MTOSD_PLANE_MAX_NUM	3
#define MTOSD_SCALER_1 0
#define MTOSD_SCALER_2 1
#define MTOSD_SCALER_3 2
#endif
//-----------------------------------------------------------------------------
// marco definitions
//-----------------------------------------------------------------------------
#define OSD_DMA_ALIGN(X)  (((X) + OSD_DMA_ALIGN_SIZE) & (~OSD_DMA_ALIGN_SIZE))

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** OSD color mode.
*/
typedef enum
{
    MTOSD_CM_YCBCR_CLUT2,                  //YCbCr 2-bit palette mode
    MTOSD_CM_YCBCR_CLUT4,                  //YCbCr 4-bit palette mode
    MTOSD_CM_YCBCR_CLUT8,                  //YCbCr 8-bit palette mode
    MTOSD_CM_RESERVED_0,         
    MTOSD_CM_CBYCRY422_DIRECT16,           //CbCrY 16-bit 4:2:2 format direct mode
    MTOSD_CM_YCBYCR422_DIRECT16,           //YCbCr 16-bit 4:2:2 format direct mode
    MTOSD_CM_AYCBCR8888_DIRECT32,          //AYCbCr 32-bit 8888 format direct mode
    MTOSD_CM_RESERVED_1,
    MTOSD_CM_RGB_CLUT2,                    //RGB 2-bit palette mode
    MTOSD_CM_RGB_CLUT4,                    //RGB 4-bit palette mode
    MTOSD_CM_RGB_CLUT8,                    //RGB 8-bit palette mode
    MTOSD_CM_RGB565_DIRECT16,              //RGB 16-bit 565 format direct mode
    MTOSD_CM_ARGB1555_DIRECT16,            //ARGB 16-bit 1555 format direct mode
    MTOSD_CM_ARGB4444_DIRECT16,            //ARGB 16-bit 4444 format direct mode
    MTOSD_CM_ARGB8888_DIRECT32,            //ARGB 32-bit 8888 format direct mode
    MTOSD_CM_ALPHA_BIT
} MTOSD_COLOR_MODE_T;


/** OSD blending mode.
 */
typedef enum
{
    MTOSD_BM_PIXEL = 1,
    MTOSD_BM_REGION,
    MTOSD_BM_PLANE
} MTOSD_BLEND_MODE_T;


#if defined(GAL_DDI_SUPPORT)
typedef enum
{
	MTGAL_PIXEL_FORMAT_ARGB = 0,	/**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
	MTGAL_PIXEL_FORMAT_LUT8, 		/**< 8 bit LUT (8 bit color and alpha lookup from palette) */
	MTGAL_PIXEL_FORMAT_ARGB1555, 	/**< 16 bit ARGB (2 byte, alpha 1\@15, red 5\@10, green 5\@5, blue 5\@0) */
	MTGAL_PIXEL_FORMAT_RGB16, 	/**< 16 bit RGB (2 byte, red 5\@11, green 6\@5, blue 5\@0) */
	MTGAL_PIXEL_FORMAT_ARGB4444, 	/**< 16 bit ARGB (2 byte, alpha 4\@12, red 4\@8, green 4\@4, blue 4\@0) */
	MTGAL_PIXEL_FORMAT_A8, 		/**< 8 bit A (1 byte, alpha 8\@0) */
	MTGAL_PIXEL_FORMAT_MAX		/**< Maximum number of MTGAL_PIXEL_FORMAT_T */
} MTGAL_PIXEL_FORMAT_T;

typedef struct
{
	UINT32	*pPalette;	/**< point to the palette arry */
	UINT32	length;		/**< size of palette (max: 256) */
} MTGAL_PALETTE_INFO_T;


typedef struct
{
	UINT32					offset;				/**< bytes offset from the start of graphic memory */
	UINT32					virtualAddress;   /**< virtual address of surface */
	UINT32					physicalAddress;  /**< physical address of surface */
	UINT16					pitch;				/**< pitch: length of horizontal line */
	UINT16					bpp;				/**< bits per pixel */
	UINT16					width;				/**< width of surface */
	UINT16					height;				/**< height of surface */
	MTGAL_PIXEL_FORMAT_T	pixelFormat;		/**< pixel format of surface */
	MTGAL_PALETTE_INFO_T	paletteInfo;		/**< palette information, this field is used when the surface's pixel format is based on indexed color. */
	signed int					id;					/**< surface identifier */
	signed int 					pid;				/**< request process id */
	UINT32					property;			/**< reserved for future use */
} MTGAL_SURFACE_INFO_T;

typedef struct 
{
	UINT32	gfxMemTotalSize;
	UINT32	allocatedMemTotalSize;
	UINT32	freeMemTotalSize;
	UINT32	largestFreeMemSize;
} MTOSD_GRAPHIC_MEM_INFO_T;

#endif
/** OSD region cmd.
 */
typedef enum
{
    MTOSD_RGN_PREV = 1,           // previous region id
    MTOSD_RGN_NEXT,               // next region id
    MTOSD_RGN_POS_X = 4,          // horizontal position (unit:pixel)
    MTOSD_RGN_POS_Y,              // vertical position (unit:pixel)
    MTOSD_RGN_BMP_W,              // source bitmap width (unit:pixel)
    MTOSD_RGN_BMP_H,              // source bitmap height (unit:pixel)
    MTOSD_RGN_DISP_W,             // output width (unit:pixel)
    MTOSD_RGN_DISP_H,             // output height (unit:pixel)
    MTOSD_RGN_OUT_W,		      // output width (unit:pixel)
    MTOSD_RGN_OUT_H,		      // output height (unit:pixel)
    MTOSD_RGN_COLOR_MODE = 12,    // output height (unit:pixel)
    MTOSD_RGN_ALPHA = 13,         // alpha value (0~255)
    MTOSD_RGN_BMP_ADDR,           // bitmap address (must align with 16byte)
    MTOSD_RGN_BMP_PITCH,          // bitmap width * byte per pixel
    MTOSD_RGN_CLIP_V,             // vertical clip width (unit:pixel)
    MTOSD_RGN_CLIP_H,             // horizontal clip width (unit:pixel)
    MTOSD_RGN_V_FLIP,             // vertical flip on/off
    MTOSD_RGN_H_MIRROR,           // horizontal flip on/off
    MTOSD_RGN_PAL_ADDR = 21,      // palette address (must align with 16byte)
    MTOSD_RGN_PAL_LEN =22,
    MTOSD_RGN_STEP_V = 23,        // V step 
    MTOSD_RGN_STEP_H = 24,        // H step
    MTOSD_RGN_COLOR_KEY = 25,     // color key (32bit/index)
    MTOSD_RGN_COLOR_KEY_EN,       // color key on/off
    MTOSD_RGN_MIX_SEL,            // alpha blending mode(1:pixel alpha, 2:region alpha, 3:plane alpha)
    MTOSD_RGN_BIG_ENDIAN,         // big/little endian
    MTOSD_RGN_NEXT_HDR_ADDR = 34, //next header address
    MTOSD_RGN_DEC_MODE = 42,	  // compression mode
    MTOSD_RGN_DEC_LINE,			  //compression line enable
    MTOSD_RGN_DEC_EN			  //compress enable
} MTOSD_RGN_CMD_T;

/**The structure keep Set framebuffer property operation information
*/
typedef struct
{
    UINT32 u4OsdPla;
    UINT32 u4FrontBufferAddr;
    UINT32 u4BackBufferAddr;
    UINT32 u4Width;
    UINT32 u4Height;
} MTOSD_FRAMEBUFFER_PROPERTY_T;

typedef struct
{
    UINT32 u4BmpWidth;
	UINT32 u4BmpHeight;
	UINT32 u4BmpPitch;
	UINT32 u4ColorMode;
}MTOSD_PLANE_PROPERTY_T;

typedef enum
{
	MTGAL_PLANE_ATTRIBUTE_NULL,
	MTGAL_PLANE_ATTRIBUTE_RECT_IN,   /* x, y, w, h */
	MTGAL_PLANE_ATTRIBUTE_RECT_OUT,  /* x, y, w, h */
	MTGAL_PLANE_ATTRIBUTE_STEREO,    /* on/off, mode */
	MTGAL_PLANE_ATTRIBUTE_FORMAT,	 /* plane format, not surface format */
	MTGAL_PLANE_ATTRIBUTE_SURFACE,
	MTGAL_PLANE_ATTRIBUTE_RUN,
	MTGAL_PLANE_ATTRIBUTE_MAX
} MTGAL_PLANE_ATTRIBUTE_T;

typedef struct
{
    UINT32 u4Width;
	UINT32 u4Height;
	UINT32 u4Pitch;
	UINT32 u4ColorMode;
	UINT32 u4CaptureBuffer;
}MTOSD_PLANE_CAPTURE_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** reset osd driver and hardware status
 *  @param  VOID
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTOSD_Reset(VOID);


/** set osd plane position
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  u4X                     x position(0~512)
 *  @param  u4Y                     y position(0~512)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_BASE_SetOsdPosition(UINT32 u4Plane, UINT32 u4X, UINT32 u4Y);


/** get osd plane position
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  pu4X                    x position pointer
 *  @param  pu4Y                    y position pointer
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_BASE_GetOsdPosition(UINT32 u4Plane, UINT32* pu4X,
                                             UINT32* pu4Y);


/** enable/disable osd plane, it will also disable scaler when disable plane
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Enable(UINT32 u4Plane, BOOL fgEnable);

#if defined(GAL_DDI_SUPPORT)
/** enable/disable osd planes, it will also disable scaler when disable plane
 *  @param  pu4Planes               plane id pointer
 *  @param  pfgEnables              enable flag pointer =TRUE/disable=FALSE
 *  @param	u4Num					the number of planes
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Enables(UINT32 * pu4Planes, BOOL * pfgEnables, UINT32 u4Num);
#endif

/** enable/disable osd plane, it will also disable scaler when disable plane
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Global_Enable(UINT32 u4Plane, BOOL fgEnable);

/** attach a specific list to osd plane
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  u4RgnList               list id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 *  @retval MTR_OSD_INV_LIST        Invalid list
 */
EXTERN MT_RESULT_T MTOSD_PLA_FlipTo(UINT32 u4Plane, UINT32 u4RgnList);


/** get osd plane alpha level
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  pu1BlendLevel           aplha level pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_GetBlendLevel(UINT32 u4Plane, UINT8* pu1BlendLevel);


/** set osd plane alpha level
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  u1BlendLevel            aplha level(0~255)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_SetBlendLevel(UINT32 u4Plane, UINT8 u1BlendLevel);


/** get osd plane fading value
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  pu1Fading               fading value pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_GetFading(UINT32 u4Plane, UINT8* pu1Fading);


/** set osd plane fading value
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  u1Fading                fading value{0~255}
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_SetFading(UINT32 u4Plane, UINT8 u1Fading);

/** get osd plane first regionlist
 *@param u4Plane                    plane id,1-plane2,2-plane3
 *@param pu4RegionListId            first regionlist id
 *@retval MTR_OK                    Success
 *@retval MTR_OSD_INV_PLANE         Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_GetFirstRegionList(UINT32 u4Plane, UINT32* pu4RegionListId);

/** print osd debug info on console
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Dump(UINT32 u4Plane);


/** get the first region id of osd plane
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  pu4RegionId             region id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_NO_REGION       No region attach to OSD plane
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_GetFirstRegion(UINT32 u4Plane, UINT32* pu4RegionId);


/** get the first region address of osd plane
 *  @param  u4Plane                 plane id,1-plane2,2-plane3
 *  @param  pu4Address              region address
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_NO_REGION       No region attach
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_GetFirstRegionAddress(UINT32 u4Plane, UINT32* pu4Address);


/** create an osd list
 *  @param pu4RgnList               list id pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTOSD_RGN_LIST_Create(UINT32 * pu4RgnList);


/** delete an osd list
 *  @param  u4RgnList               list id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_LIST        Invalid list
 */
EXTERN MT_RESULT_T MTOSD_RGN_LIST_Delete(UINT32 u4RgnList);


/** get first region id of list
 *  @param  u4RgnList               list id
 *  @param  pu4RegionId             region id pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_LIST        Invalid list
 *  @retval MTR_OSD_NO_REGION       No region attach
 */
EXTERN MT_RESULT_T MTOSD_RGN_LIST_GetHead(UINT32 u4RgnList, INT32 * pu4RegionId);


/** get osd region attribute
 *  @param  u4Region                region id
 *  @param  i4Cmd                   attribute name, refer to MTOSD_RGN_CMD_T
 *  @param  pu4Value                attribute value pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 *  @retval MTR_OSD_INV_ATTRIBUTE   Invalid region attribute value
 */
EXTERN MT_RESULT_T MTOSD_RGN_Get(UINT32 u4Region, MTOSD_RGN_CMD_T eCmd, UINT32 * pu4Value);


/** set osd region attribute
 *  @param  u4Region                region id
 *  @param  i4Cmd                   attribute name, refer to MTOSD_RGN_CMD_T
 *  @param  u4Value                 attribute value
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 *  @retval MTR_OSD_INV_ATTRIBUTE   Invalid region attribute value
 */
EXTERN MT_RESULT_T MTOSD_RGN_Set(UINT32 u4Region, MTOSD_RGN_CMD_T eCmd, UINT32 u4Value);


/** create an osd region
 *  @param  pu4Region               region id pointer
 *  @param  u4BmpWidth              source bitmap width
 *  @param  u4BmpHeight             source bitmap height
 *  @param  pvBitmap                source bitmap address, align with 16bytes
 *  @param  u4ColorMode             color mode, refer to MTOSD_COLOR_MODE_T
 *  @param  u4BmpPitch              bytes per line, align with 16bytes
 *  @param  u4DispX                 region x position
 *  @param  u4DispY                 region y position
 *  @param  u4DispW                 output width
 *  @param  u4DispH                 output height
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_ATTRIBUTE   Invalid region attribute value
 */
EXTERN MT_RESULT_T MTOSD_RGN_Create(UINT32 * pu4Region, UINT32 u4BmpWidth,
                             UINT32 u4BmpHeight, VOID * pvBitmap,
                             MTOSD_COLOR_MODE_T eColorMode, UINT32 u4BmpPitch,
                             UINT32 u4DispX, UINT32 u4DispY,
                             UINT32 u4DispW, UINT32 u4DispH);


/** delete an osd region
 *  @param  u4Region                region id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 */
EXTERN MT_RESULT_T MTOSD_RGN_Delete(UINT32 u4Region);


/** attach region to list
 *  @param  u4Region                region id
 *  @param  u4RgnList               list id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 *  @retval MTR_OSD_INV_LIST        Invalid list
 */
EXTERN MT_RESULT_T MTOSD_RGN_Insert(UINT32 u4Region, UINT32 u4RgnList);


/** dettach region from list
 *  @param  u4Region                region id
 *  @param  u4RgnList               list id
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 *  @retval MTR_OSD_INV_LIST        Invalid list
 */
EXTERN MT_RESULT_T MTOSD_RGN_Detach(UINT32 u4Region, UINT32 u4RgnList);


/** cinfugure osd scaler
 *  @param  u4Scaler                scaler id,0-plane2,1-plane3,2-plane1
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @param  u4SrcWidth              osd input width
 *  @param  u4SrcHeight             osd input height
 *  @param  u4DstWidth              osd output width
 *  @param  u4DstHeight             osd output height
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_SCALER      Invalid scaler
 */
EXTERN MT_RESULT_T MTOSD_SC_Scale(UINT32 u4Scaler, UINT32 u4Enable,
                           UINT32 u4SrcWidth, UINT32 u4SrcHeight,
                           UINT32 u4DstWidth, UINT32 u4DstHeight);


/** get osd scaler infomation
 *  @param  u4Scaler                scaler id,0-plane2,1-plane3,2-plane1
 *  @param  pu4Enable               enable pointer
 *  @param  pu4SrcW                 osd input width pointer
 *  @param  pu4SrcH                 osd input height pointer
 *  @param  pu4DstW                 osd output width pointer
 *  @param  pu4DstH                 osd output height pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_SCALER      Invalid scaler
 */
EXTERN MT_RESULT_T MTOSD_SC_GetScalerInfo(UINT32 u4Scaler, UINT32* pu4Enable,
                                   UINT32* pu4SrcW, UINT32* pu4SrcH,
                                   UINT32* pu4DstW, UINT32* pu4DstH, UINT32* pu4Is16Bpp);


/** enable low pass filter
 *  @param  u4Scaler                scaler id,0-plane2,1-plane3,2-plane1
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_SCALER      Invalid scaler
 */
EXTERN MT_RESULT_T MTOSD_SC_SetLpf(UINT32 u4Scaler, UINT32 u4Enable);

/** get region list of frame buffer
 *  @param  pu4RgnList              region list value pointer
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_ERR_INV             Invalid Arguement
 */
EXTERN MT_RESULT_T MTOSD_GetFBRegionList(UINT32* pu4RgnList);

/** get resolution of frame buffer
 *  @param  pu4Width                frame buffer width
 *  @param  pu4Height               frame buffer height
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTOSD_GetFBResolution(UINT32* pu4Width,UINT32* pu4Height);

/** Initial osd driver and hardware
 *  @param  VOID
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTOSD_Init(VOID);

#if 0
/** set 3D osd L/R address
 *  @param  u4Plane                 plane id
 *  @param  pu4L_Address        L address
 *  @param  pu4R_Address        R address
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_PLANE       Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Set3DAddress(UINT32 u4Plane, UINT32* pu4L_Address, UINT32* pu4R_Address);
#endif

/** set osd scroll information
 *  @param  u4Rgn                  region id
 *  @param  u4BaseAddr             base address
 *  @param  u4Pitch                region pitch
 *  @param  u4Step                 scroll step
 *
 *  @retval MTR_OK                 Success
 *  @retval MTR_NOT_OK             Fail
 */
EXTERN MT_RESULT_T MTOSD_RGN_SetScrollInfo(UINT32 u4Rgn, UINT32 u4BaseAddr, UINT32 u4Pitch, UINT32 u4Step);

/** set osd scroll mode
 *  @param  u1ScrollMode           1: Scroll on; 0:Scroll off
 *  @retval MTR_OK                 Success
 */
EXTERN MT_RESULT_T MTOSD_SetScrollMode(UINT8 u1ScrollMode);

/** set 3D osd mode
 *  @param  u4Plane                plane id,1-plane2,2-plane3,3-plane4,4-plane5
 *  @param  u13DMode               1: 3D on; 0:3D off
 *  @retval MTR_OK                 Success
 */
EXTERN MT_RESULT_T MTOSD_PLA_Set3DMode(UINT32 u4Plane, UINT8 u13DMode);

/** Set 3D osd L/R region
 *  @param  u4Plane                plane id,1-plane2,2-plane3,3-plane4,4-plane5
 *  @param  u4LeftRegion           L region
 *  @param  u4RightRegion          R region
 *  @retval MTR_OK                 Success
 *  @retval MTR_NOT_OK             Fail
 *  @retval MTR_OSD_INV_PLANE      Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_PLA_Set3DRegion(UINT32 u4Plane, UINT32 u4LeftRegion, UINT32 u4RightRegion);


/** Enable OSD L/R frame auto selection.
 *  @param  u4Enable               OSD L/R frame auto selection.  0: disable,  1: enable 
 *  @retval MTR_OK                 Success
 *  @retval MTR_NOT_OK             Fail
 *  @retval MTR_OSD_INV_PLANE      Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_EnableAutoLR(UINT32 u4Enable);

/** Get OSD L/R frame status.
 *  @param  pu4Status              L/R frame status. 0: Left, 1:Right
 *  @retval MTR_OK                 Success
 *  @retval MTR_NOT_OK             Fail
 *  @retval MTR_OSD_INV_PLANE      Invalid plane
 */
EXTERN MT_RESULT_T MTOSD_GetLRStatus (UINT32* pu4Status);

/**Set OSD 3D shift flag
*@param u4Plane                    plane id,1-plane2,2-plane3,3-plane4,4-plane5
*@param fgEnable                   the flag of shift status
*@param i4ShiftValue               shift value
*@retval MTR_OK                    Success.
*@retval MTR_OSD_INV_PLANE         Invalid plane.
*/
EXTERN MT_RESULT_T MTOSD_PLA_SetLineShift(UINT32 u4Plane, BOOL fgEnable, INT32 i4ShiftValue);

/** no usefull now
*/
EXTERN MT_RESULT_T MTOSD_SetFramebufferProperty(MTOSD_FRAMEBUFFER_PROPERTY_T rFbProp);

/** Get Cursor Mode for MTAL_SetCursorPosition
*@param u4Rgn                    region id
*@param x                        position of x
*@param y                        position of y
*@param u4UIWidth                ui width
*@param u4UIHeight               ui height
*@param u4CusWidth               cursor width
*@param u4CurHeight              cursor height
*@param u4Type                   set chip status
*@param u4ClipH                  clip horizontal
*@param u4ClipV                  clip vertical
*@retval MTR_OK                  Success.
*@retval MTR_NOT_OK              Fail
*/
EXTERN MT_RESULT_T MTAL_SetRegionPosition(UINT32 u4Rgn, UINT16 x, UINT16 y, UINT32  u4UIWidth,  UINT32 u4UIHeight,
	        UINT32 u4CusWidth, UINT32 u4CurHeight, UINT32 u4Type, UINT32 u4ClipH,  UINT32 u4ClipV );

/** Set Cursor position
*@param u4Rgn                    region id
*@param x                        position of x
*@param y                        position of y
*@param u4UIWidth                ui width
*@param u4UIHeight               ui height
*@param u4CusWidth               cursor width
*@param u4CurHeight              cursor height
*@param u4Type                   cursor mode
*@param u4ClipH                  clip horizontal
*@param u4ClipV                  clip vertical
*@retval MTR_OK                  Success.
*@retval MTR_NOT_OK              Fail
*/
EXTERN MT_RESULT_T MTAL_SetCursorPosition(UINT32 u4Rgn, UINT16 x, UINT16 y, UINT32  u4UIWidth,  UINT32 u4UIHeight,
	        UINT32 u4CusWidth, UINT32 u4CurHeight, UINT32 u4Type, UINT32 u4ClipH,  UINT32 u4ClipV );

/**OSD set flip and mirror operation
*@param fgMirrorEn               mirror flag,1/enable,0/disable
*@param fgFlipEn                 flip flag,1/enable,0/disable
*@retval MTR_OK                  Success.
*/
EXTERN MT_RESULT_T MTOSD_SetFlipMirror(BOOL fgMirrorEn, BOOL fgFlipEn);

/**OSD set region rect
*@param u4Plane                  plane id,1-plane2,2-plane3
*@param u4Rgn                    current region id
*@param u4SrcX                   source x postion
*@param u4SrcY                   source y postion
*@param u4SrcWidth               source width
*@param u4SrcHeight              source height
*@param u4DstX                   Dst x position 
*@param u4DstY                   Dst y position
*@param u4DstWidth               Dst width
*@param u4DstHeight              Dst height
*@retval MTR_OK                  Success.
*/
EXTERN MT_RESULT_T MTAL_PLA_SetViewRect(UINT32 u4Plane, UINT32 u4Rgn, UINT32 u4SrcX, UINT32 u4SrcY, UINT32  u4SrcWidth,  UINT32 u4SrcHeight,
														UINT32 u4DstX, UINT32 u4DstY, UINT32 u4DstWidth, UINT32 u4DstHeight);

/**OSD set region rect
*@param u4Plane                  plane id,1-plane2,2-plane3
*@param u4Rgn                    current region id
*@param u4SrcX                   source x postion
*@param u4SrcY                   source y postion
*@param u4SrcWidth               source width
*@param u4SrcHeight              source height
*@param u4DstX                   Dst x position 
*@param u4DstY                   Dst y position
*@param u4DstWidth               Dst width
*@param u4DstHeight              Dst height
*@param fgDstEnabel              scale flag 
*@retval MTR_OK                  Success.
*/
EXTERN MT_RESULT_T MTAL_PLA_SetRect(UINT32 u4Plane, UINT32 u4Rgn, UINT32 u4SrcX, UINT32 u4SrcY, UINT32  u4SrcWidth,  UINT32 u4SrcHeight,
														UINT32 u4DstX, UINT32 u4DstY, UINT32 u4DstWidth, UINT32 u4DstHeight, BOOL fgDstEnabel);
/**Get all region,not usefull now.
*@param u4Plane                 plane id,1-plane2,2-plane3
*@param pu4Value                no usefull
*@param pu4Value2               no usefull
*@retval MTR_OK                 Success.
*/
EXTERN MT_RESULT_T MTOSD_PLA_GetAllRegion(UINT32 u4Plane, UINT32 * pu4Value, UINT32 * pu4Value2);

/**Get source content region,not userfull now.
*@param u4Plane                 plane id,1-plane2,2-plane3
*@param pu4Value                pu4Value
*@param pu4Value2               pu4Value2
*@retval MTR_OK                 Success.
*/
EXTERN MT_RESULT_T MTOSD_PLA_GetSrcContentRegion(UINT32 u4Plane, UINT32 * pu4Value, UINT32 * pu4Value2);

/**Get source width and height.
*@param u4Plane                  plane id,1-plane2,2-plane3
*@param pu4Width                 keep width information
*@param pu4Height                keep heigth information
*@retval MTR_OK                  Success
*@retval MTR_OSD_INV_REGION      Invalid region
*@retval MTR_ERR_INV             Invalid argument passed
*/
EXTERN MT_RESULT_T MTOSD_PLA_GetSrcContentSize(UINT32 u4Plane, UINT32 * pu4Width, UINT32 * pu4Height);

/**Set region VStep.
*@param u4Plane                  plane id,1-plane2,2-plane3
*@param u4Value                  1 or 0
*@retval MTR_OK                  Success
*/
EXTERN MT_RESULT_T MTAL_PLA_SetRgnVStep(UINT32 u4Plane,UINT32 u4Value);

/**Get Plane enable state
*@param u4Plane                  plane id,1-plane2,2-plane3
*@param pu1Enable                keep state information
*@retval MTR_OK                  success
*/
EXTERN MT_RESULT_T MTOSD_PLA_GetEnableState(UINT32 u4Plane, UINT8* pu1Enable);

/** Wait LVDS output Vsync
 *  @param  u4_wait                 Wait LVDS output Vsync times
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_OSD_INV_REGION      Invalid region
 *  @retval MTR_OSD_INV_ATTRIBUTE   Invalid region attribute value
 */
EXTERN MT_RESULT_T MTOSD_BASE_Wait_Vsync(UINT32 u4_wait);

#if defined(GAL_DDI_SUPPORT)
EXTERN MT_RESULT_T MTOSD_GPU_DlmemInit(void* base, int size);

EXTERN MT_RESULT_T MTOSD_GPU_Dlmalloc(UINT32 * puaddr, int size);

EXTERN MT_RESULT_T MTOSD_GPU_Dlcalloc(UINT32 * puaddr,int nmemb, int size);

EXTERN MT_RESULT_T MTOSD_GPU_Dlresize_alloc(UINT32 * puaddr,void * alloc_ptr,int newsize, int * puoldsize);

EXTERN MT_RESULT_T MTOSD_GPU_Dlrealloc(UINT32 * puaddr,void * ptr,int size);

EXTERN MT_RESULT_T MTOSD_GPU_Dlfree(void * ptr);

EXTERN MT_RESULT_T MTOSD_GPU_Dlmem_GetStatus(int flags, MTOSD_GRAPHIC_MEM_INFO_T * pustatus);

EXTERN MT_RESULT_T MTOSD_GPU_Add_SurfaceIndex(void);

EXTERN MT_RESULT_T MTOSD_GPU_Get_SurfaceIndex(int * u4index);

EXTERN MT_RESULT_T MTOSD_GPU_Set_SURFACEPOOL(INT32 u4Surfacepool);

EXTERN MT_RESULT_T MTOSD_GPU_CreateSurface(UINT16 width, UINT16 height, int pixelFormat, MTGAL_SURFACE_INFO_T *pSurfaceInfo);

EXTERN MT_RESULT_T MTOSD_GPU_DestroySurface(MTGAL_SURFACE_INFO_T *pSurfaceInfo);

EXTERN MT_RESULT_T MTOSD_GPU_SetFrameSurface(UINT32 u4Plane, void *pSurfaceInfo);

EXTERN MT_RESULT_T MTOSD_GPU_InitSurfaceSema(void);

EXTERN MT_RESULT_T MTOSD_GPU_GetSurfaceFromOffset(INT32 offset, MTGAL_SURFACE_INFO_T *pSurfaceInfo);

EXTERN MT_RESULT_T MTOSD_GPU_SyncSurfaceToKernel(MTGAL_SURFACE_INFO_T *pSurfaceInfo);

EXTERN MT_RESULT_T MTOSD_GPU_GalInit(UINT32 u4PhyAddr, UINT32 u4VirAddr, UINT32 u4Size);

EXTERN MT_RESULT_T MTOSD_GPU_GetTempSurface(MTGAL_SURFACE_INFO_T *pSurfaceInfo, MTGAL_SURFACE_INFO_T *pSurfaceInfo2);

EXTERN MT_RESULT_T MTOSD_GPU_MultiProcLock(void);

EXTERN MT_RESULT_T MTOSD_GPU_MultiProcUnLock(void);

EXTERN MT_RESULT_T MTOSD_GPU_MallocToOffset(UINT32 u4Length, UINT32 * offset);
EXTERN MT_RESULT_T MTOSD_GPU_Set3DMode(UINT32 u4Plane, UINT32 u4Enable, UINT32 u4Mode);
EXTERN MT_RESULT_T MTOSD_PLA_GetProperty(UINT32 u4Plane, MTOSD_PLANE_PROPERTY_T *prProperty);
EXTERN MT_RESULT_T MTOSD_PLA_Capture(UINT32 u4Plane, MTOSD_PLANE_CAPTURE_T *prCaptureInfo);
#endif
#ifdef __cplusplus
}
#endif

#endif //MT_OSD_H
