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
 * $RCSfile: MTIMAGE.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 
/** @file mtimage_l.h
 *  This header file declares exported APIs and data structures of Media Player Module.
 */

#ifndef MT_IMAGE_H
#define MT_IMAGE_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************
  INCLUDE FILES
********************************************************************/

#include "mttype.h"
#include "mtvdo.h"

/********************************************************************
  MACRO CONSTANT DEFINITIONS
********************************************************************/
#define MTIMAGE_B2RDEVICE             "/dev/b2r"        ///< b2r device node
#define MTIMAGE_IMGDEVICE             "/dev/jpg"        ///< jpg device node
#define MTIMAGE_IMGBUFDEVICE       "/dev/feeder"        ///< feeder device node
#define MTIMAGE_PNGDEVICE       "/dev/fbm_png"        	///< fbm_png device node
#define MTIMAGE_SOF0                  0xc0              ///< SOF0 marker
#define MTIMAGE_SOF2                  0xc2              ///< SOF2 marker
#define MTIMAGE_APP1                  0xe1              ///< APP1 marker
#define MTIMAGE_APP2                  0xe2              ///< APP2 marker
#define MTIMAGE_EOI                   0xd9              ///< EOI marker
#define MTIMAGE_SOI                   0xd8              ///< SOI marker
#define MTIMAGE_SOS                   0xda              ///< SOS marker
#define MTIMAGE_EXIF_MAKE_TAG         0x010f            ///< EXIF info marker, maker
#define MTIMAGE_EXIF_MODEL_TAG        0x0110            ///< EXIF info marker, model
#define MTIMAGE_EXIF_ORIENTATION_TAG  0x0112            ///< EXIF info marker, orientation
#define MTIMAGE_EXIF_DATE_TAG         0x0132            ///< EXIF info marker, date
#define MTIMAGE_EXIF_INTERCHANGE      0x0201            ///< EXIF info marker, interchange
#define MTIMAGE_EXIF_INTERCHANGELEN   0x0202            ///< EXIF info marker, interchangelen
#define MTIMAGE_EXIF_SUBIFD_OFFSET    0x8769            ///< EXIF info marker, subifd offset

#define MTIMAGE_PARSING_BUFFER_SIZE   (3 *1024 * 1024)	///< Jpg, png Header parsing size
#define MTIMAGE_WEBP_HEADER_PARSING_SIZE (30)		    ///< Webp Header parsing size
#define MPF_MAX_IMAGE 4								    ///< MPF max page number

#define MTIMAGE_MAX_PANEL_RES_W 1920				    ///< Max panel resolution, width
#define MTIMAGE_MAX_PANEL_RES_H 1080				    ///< Max panel resolution, height
#define MTIMAGE_ENLARGE_SOURCE_RES_W 1920				///< Enlarge source resolution, width
#define MTIMAGE_ENLARGE_SOURCE_RES_H 1080				///< Enlarge source resolution, height
#define MTIMAGE_ENLARGE_OUTPUT_RES_W 1920				///< Enlarge ourput resolution, width
#define MTIMAGE_ENLARGE_OUTPUT_RES_H 1080				///< Enlarge ourput resolution, height

#define MTIMAGE_JPG_SPEC_MAX_WIDTH 15360				///< Jpg spec max resolution, width
#define MTIMAGE_JPG_SPEC_MAX_HEIGHT 8640				///< Jpg spec max resolution, height
#define MTIMAGE_JPG_SPEC_MIN_WIDTH 64				    ///< Jpg spec min resolution, width
#define MTIMAGE_JPG_SPEC_MIN_HEIGHT 64				    ///< Jpg spec min resolution, height
#define MTIMAGE_JPG_SPEC_MIN_WIDTH_THUMBNAIL 16		    ///< Jpg spec min thumbnail resolution, width
#define MTIMAGE_JPG_SPEC_MIN_HEIGHT_THUMBNAIL 16		///< Jpg spec min thumbnail resolution, height

#define MTIMAGE_PROGRESSIVE_JPG_SPEC_MAX_WIDTH 1920     ///< Progressive jpg spec max resolution, width
#define MTIMAGE_PROGRESSIVE_JPG_SPEC_MAX_HEIGHT 1440    ///< Progressive jpg spec max resolution, height
#define MTIMAGE_PROGRESSIVE_JPG_SPEC_MIN_WIDTH 64       ///< Progressive jpg spec min resolution, width
#define MTIMAGE_PROGRESSIVE_JPG_SPEC_MIN_HEIGHT 64      ///< Progressive jpg spec min resolution, height

/********************************************************************
  MACRO FUNCTION DEFINITIONS
********************************************************************/
/// Debug log function
#define MTIMAGE_LOG(ENABLE, MOD, fmt...) \
    do \
    {\
        if((ENABLE)) \
        { \
            printf("["MOD"]:%s\n" , __FUNCTION__); \
            printf(fmt); \
        } \
									} while (0)

#define MTIMAGE_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)	           ///< Debug log for general usage

#define MTIMAGE_METADATA_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)    ///< Debug log for metadata parsing usage

#define MTIMAGE_KERNEL_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)	   ///< Debug log for kernel usage

#define MTIMAGE_SLIDESHOW_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)   ///< Debug log for slideshow usage

#define MTIMAGE_MPO_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)         ///< Debug log for mpo usage

#define MTIMAGE_FBM_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)         ///< Debug log for fbm usage

#define MTIMAGE_GPU_DEBUG(fmt...)       MTIMAGE_LOG(FALSE, "MTIMAGE", fmt)         ///< Debug log for gpu usage

//#define MAIN_SUB_UT_TEST
#define MTIMAGE_DECODER_ID    (rImageInfo->video_id)                               ///< Image decoder id
#define MTIMAGE_VIDEO_ID    (rImageUsrInfo->video_id)                              ///< Image video id

/**Image path
It is used for distinguishing image video path.
*/
typedef enum
{
    MT_IMAGE_MAIN_PATH = 0,    ///< Image video path, main
    MT_IMAGE_SUB_PATH  = 1,    ///< Image video path, sub
}MT_IMAGE_PATH;

/********************************************************************
  TYPE DEFINITION
********************************************************************/
/**MTIMAGE handle.
It is a pointer to VOID, which is used as the handle type for MTIMAGE.  
After an MTIMAGE instance has been opened, a handle is returned.  This 
handle will be used by most MTIMAGE APIs to identify the MTIMAGE instance.
*/
typedef VOID* MTIMAGE_HANDLE;

/**Error Type.
It is used for describing the error type when a callback from kernel is an 
error callback which needs to pass an error code to user space.  Possible 
errors include file open error, video decoding error, audio decoding error, 
DRM (for DivX) error, image decoding error and JPEG color format error.
*/
typedef enum
{
    MT_IMAGE_FILE_ERROR,               ///< Fail in opening File 
    MT_IMAGE_IMG_ERROR,                ///< Fail in decoding image
    MT_IMAGE_JPEG_COLOR_FORMAT_ERROR,  ///< Fail in color format
    MT_IMAGE_ERROR_MAX,                ///< Max boundary
} MTIMAGE_ERROR_TYPE_T;


/**Call back type.
When some event occurs during the playback of a multimedia file, a 
corresponding callback could be called to pass information to the upper 
layer.  This callback type is used for identifying the type of callback.  
Useful callback types are ERROR, FINISH and ELAPSEDTIME.  Other types are 
reserved for internal usage or non multimedia related.
*/
typedef enum
{
    MT_IMAGE_CALLBACK_NEEDDATA,        ///< Notification of copy buffer
    MT_IMAGE_CALLBACK_ERROR,           ///< Notification of play error
    MT_IMAGE_CALLBACK_FINISH,          ///< Notification of file end   
    MT_IMAGE_CALLBACK_MAX              ///< Max boundary
} MTIMAGE_CALLBACK_TYPE_T;

/**Image format.
It is used for distinguishing image file format.
*/
typedef enum
{
    MT_IMAGE_JPEG_NEW,				///< Image format, JPEG
    MT_IMAGE_PNG_NEW,               ///< Image format, PNG
    MT_IMAGE_WEBP_NEW,              ///< Image format, WEBP
    MT_IMAGE_MPO_NEW,               ///< Image format, MPO 
    MT_IMAGE_PROGRESSIVE_NEW,       ///< Image format, PROGRESSIVE JPEG 	    
    MT_IMAGE_MAX_NEW                ///< Max boundary
} MTIMAGE_IMG_FORMAT;

/**Output Color format.
It is used for distinguishing decoder output format.
*/
typedef enum
{
    MT_IMAGE_COLOR_FORMAT_AYCBCR8888,         ///< AYCbCr display mode, 32 bit per pixel, for OSD
	MT_IMAGE_COLOR_FORMAT_LUT8, 	  		 ///<for PNG LUT8 display mode    
    MT_IMAGE_COLOR_FORMAT_ARGB8888,           ///< ARGB8888
    MT_IMAGE_COLOR_FORMAT_ARGB1555,           ///< ARGB1555
    MT_IMAGE_COLOR_FORMAT_ARGB565,            ///< ARGB565
    MT_IMAGE_COLOR_FORMAT_ARGB4444,           ///< ARGB4444       
	MT_IMAGE_COLOR_FORMAT_Y_CBCR422,		  ///< Y/CbCr separate 422 display mode, 16 bit per pixel, for video plane    
    MT_IMAGE_COLOR_FORMAT_MAX,                ///< Max boundary
} MTIMAGE_IMGCOLORFORMAT_T;

/**Output pixel format.
It is used for distinguishing pixel output format.
*/
typedef enum
{
    MT_IMAGE_PIX_FORMAT_UYVY,         ///< UYVY
    MT_IMAGE_PIX_FORMAT_VYUY,         ///< VYUY
    MT_IMAGE_PIX_FORMAT_1555,         ///< 1555
    MT_IMAGE_PIX_FORMAT_565,          ///< 565
    MT_IMAGE_PIX_FORMAT_4444,         ///< 4444
    MT_IMAGE_PIX_FORMAT_8888,         ///< 8888
    MT_IMAGE_PIX_FORMAT_MAX,          ///< Max boundary
} MTIMAGE_PIXFORMAT_T;

/**Rotation Option.
*/
typedef enum
{
    MT_IMAGE_ROTATE_0,                     ///< No rotation
    MT_IMAGE_ROTATE_90,                    ///< Clockwise 90 degrees
    MT_IMAGE_ROTATE_180,                   ///< Clockwise 180 degrees
    MT_IMAGE_ROTATE_270,                   ///< Clockwise 270 degrees
    MT_IMAGE_ROTATE_0_FLIP,                ///< No rotation with flip
    MT_IMAGE_ROTATE_90_FLIP,               ///< Cclockwise 90 degrees with flip
    MT_IMAGE_ROTATE_180_FLIP,              ///< Clockwise 180 degrees with flip
    MT_IMAGE_ROTATE_270_FLIP,              ///< Clockwise 270 degrees with flip
    MT_IMAGE_ROTATE_MAX                    ///< Max boundary
} MTIMAGE_ROTATE_T;

/**Exif Orientation Option.
*/
typedef enum
{
    MT_IMAGE_EXIF_ORIENTATION_0,    ///< Exif orientation 0
    MT_IMAGE_EXIF_ORIENTATION_1,    ///< Should be nothing
    MT_IMAGE_EXIF_ORIENTATION_2,    ///< Exif orientation 2         
    MT_IMAGE_EXIF_ORIENTATION_3,    ///< Should be set to MT_IMAGE_ROTATE_180              
    MT_IMAGE_EXIF_ORIENTATION_4,    ///< Exif orientation 4           
    MT_IMAGE_EXIF_ORIENTATION_5,    ///< Exif orientation 5            
    MT_IMAGE_EXIF_ORIENTATION_6,    ///< Should be set to MT_IMAGE_ROTATE_270
    MT_IMAGE_EXIF_ORIENTATION_7,    ///< Exif orientation 7
    MT_IMAGE_EXIF_ORIENTATION_8,    ///< Should be set to MT_IMAGE_ROTATE_90
    MT_IMAGE_EXIF_ORIENTATION_MAX   ///< Max boundary
} MT_IMAGE_EXIF_ORIENTATION_T;

/**Transition effect type.
*/
typedef enum
{
    MT_IMAGE_EFFECT_NORMAL,                        ///< effect 0
//#if (ENABLE_PHOTO_TRANS_EFFECT_BLOCKS)
    MT_IMAGE_EFFECT_HORZ_BLOCKS_TOPLEFT,           ///< effect 1
    MT_IMAGE_EFFECT_HORZ_BLOCKS_TOPRIGHT,          ///< effect 2
    MT_IMAGE_EFFECT_HORZ_BLOCKS_BOTTOMLEFT,        ///< effect 3
    MT_IMAGE_EFFECT_HORZ_BLOCKS_BOTTOMRIGHT,       ///< effect 4
    MT_IMAGE_EFFECT_VERT_BLOCKS_TOPLEFT,           ///< effect 5
    MT_IMAGE_EFFECT_VERT_BLOCKS_TOPRIGHT,          ///< effect 6
    MT_IMAGE_EFFECT_VERT_BLOCKS_BOTTOMLEFT,        ///< effect 7
    MT_IMAGE_EFFECT_VERT_BLOCKS_BOTTOMRIGHT,       ///< effect 8
    MT_IMAGE_EFFECT_HORZ_ZIGZAG_BLOCKS_TOPLEFT,    ///< effect 9
    MT_IMAGE_EFFECT_HORZ_ZIGZAG_BLOCKS_TOPRIGHT,   ///< effect 10
    MT_IMAGE_EFFECT_HORZ_ZIGZAG_BLOCKS_BOTTOMLEFT, ///< effect 11
    MT_IMAGE_EFFECT_HORZ_ZIGZAG_BLOCKS_BOTTOMRIGHT,///< effect 12
    MT_IMAGE_EFFECT_VERT_ZIGZAG_BLOCKS_TOPLEFT,    ///< effect 13
    MT_IMAGE_EFFECT_VERT_ZIGZAG_BLOCKS_TOPRIGHT,   ///< effect 14
    MT_IMAGE_EFFECT_VERT_ZIGZAG_BLOCKS_BOTTOMLEFT, ///< effect 15
    MT_IMAGE_EFFECT_VERT_ZIGZAG_BLOCKS_BOTTOMRIGHT,///< effect 16
    MT_IMAGE_EFFECT_BLOCKS_RANDOM,                 ///< effect 17
//#endif
//#if (ENABLE_PHOTO_TRANS_EFFECT_DIAGONAL_BLOCKS)
    MT_IMAGE_EFFECT_DIAGONAL_BLOCKS_TOPLEFT,       ///< effect 18
    MT_IMAGE_EFFECT_DIAGONAL_BLOCKS_TOPRIGHT,      ///< effect 19
    MT_IMAGE_EFFECT_DIAGONAL_BLOCKS_BOTTOMLEFT,    ///< effect 20
    MT_IMAGE_EFFECT_DIAGONAL_BLOCKS_BOTTOMRIGHT,   ///< effect 21
//#endif
//#if (ENABLE_PHOTO_TRANS_EFFECT_WIPE)
    MT_IMAGE_EFFECT_BARWIPE_LEFT2RIGHT,            ///< effect 22
    MT_IMAGE_EFFECT_BARWIPE_RIGHT2LEFT,            ///< effect 23
    MT_IMAGE_EFFECT_BARWIPE_TOP2BOTTOM,            ///< effect 24
    MT_IMAGE_EFFECT_BARWIPE_BOTTOM2TOP,            ///< effect 25
    MT_IMAGE_EFFECT_BOXWIPE_TOPLEFT,               ///< effect 26
    MT_IMAGE_EFFECT_BOXWIPE_TOPRIGHT,              ///< effect 27
    MT_IMAGE_EFFECT_BOXWIPE_BOTTOMLEFT,            ///< effect 28
    MT_IMAGE_EFFECT_BOXWIPE_BOTTOMRIGHT,           ///< effect 29
    MT_IMAGE_EFFECT_BARNDOORWIPE_HORIZONTAL_OPEN,  ///< effect 30              
    MT_IMAGE_EFFECT_BARNDOORWIPE_HORIZONTAL_CLOSE, ///< effect 31   
    MT_IMAGE_EFFECT_BARNDOORWIPE_VERTICAL_OPEN,    ///< effect 32
    MT_IMAGE_EFFECT_BARNDOORWIPE_VERTICAL_CLOSE,   ///< effect 33                   
    MT_IMAGE_EFFECT_BOXWIPE_TOPCENTER,             ///< effect 34
    MT_IMAGE_EFFECT_BOXWIPE_RIGHTCENTER,           ///< effect 35
    MT_IMAGE_EFFECT_BOXWIPE_BOTTOMCENTER,          ///< effect 36
    MT_IMAGE_EFFECT_BOXWIPE_LEFTCENTER,            ///< effect 37
    MT_IMAGE_EFFECT_IRISWIPE_CENTER,               ///< effect 38
    MT_IMAGE_EFFECT_IRISWIPE_OUTER,                ///< effect 39
    MT_IMAGE_EFFECT_4BARWIPE_HORIZONTAL_FROM_TOP,  ///< effect 40
    MT_IMAGE_EFFECT_4BARWIPE_HORIZONTAL_FROM_BOTTOM,///< effect 41
    MT_IMAGE_EFFECT_4BARWIPE_VERTICAL_FROM_LEFT,    ///< effect 42
    MT_IMAGE_EFFECT_4BARWIPE_VERTICAL_FROM_RIGHT,   ///< effect 43
//#endif
//#if (ENABLE_PHOTO_TRANS_EFFECT_SLIDE)
    MT_IMAGE_EFFECT_BARSLIDE_LEFT2RIGHT,            ///< effect 44
    MT_IMAGE_EFFECT_BARSLIDE_RIGHT2LEFT,            ///< effect 45
    MT_IMAGE_EFFECT_BARSLIDE_TOP2BOTTOM,            ///< effect 46
    MT_IMAGE_EFFECT_BARSLIDE_BOTTOM2TOP,            ///< effect 47
    MT_IMAGE_EFFECT_BOXSLIDE_TOPLEFT,               ///< effect 48
    MT_IMAGE_EFFECT_BOXSLIDE_TOPRIGHT,              ///< effect 49
    MT_IMAGE_EFFECT_BOXSLIDE_BOTTOMLEFT,            ///< effect 50
    MT_IMAGE_EFFECT_BOXSLIDE_BOTTOMRIGHT,           ///< effect 51
    MT_IMAGE_EFFECT_BARNDOORSLIDE_HORIZONTAL_OPEN,  ///< effect 52
    MT_IMAGE_EFFECT_BARNDOORSLIDE_HORIZONTAL_CLOSE, ///< effect 53
    MT_IMAGE_EFFECT_BARNDOORSLIDE_VERTICAL_OPEN,    ///< effect 54
    MT_IMAGE_EFFECT_BARNDOORSLIDE_VERTICAL_CLOSE,   ///< effect 55
    MT_IMAGE_EFFECT_4BARSLIDE_HORIZONTAL_FROM_TOP,  ///< effect 56
    MT_IMAGE_EFFECT_4BARSLIDE_HORIZONTAL_FROM_BOTTOM, ///< effect 57
    MT_IMAGE_EFFECT_4BARSLIDE_VERTICAL_FROM_LEFT,     ///< effect 58
    MT_IMAGE_EFFECT_4BARSLIDE_VERTICAL_FROM_RIGHT,    ///< effect 59
//#endif
//#if (ENABLE_PHOTO_TRANS_EFFECT_FADE_IN)
    MT_IMAGE_EFFECT_FADE_IN,                          ///< effect 60
	MT_IMAGE_EFFECT_SLIDE_LEFT2RIGHT,                 ///< effect 61
	MT_IMAGE_EFFECT_SLIDE_RIGHT2LEFT,                 ///< effect 62
//#endif
    MT_IMAGE_EFFECT_CLOSE,                            ///< effect 63
    MT_IMAGE_EFFECT_MAX                               ///< Max boundary
} MTIMAGE_SLIDETYPE;

/**Meta data type.
It is used for distinguishing metadata type
*/
typedef enum
{
    MTIMAGE_METADATA_TITLE,             ///< Metadata type, title
    MTIMAGE_METADATA_ALBUM,             ///< Metadata type, album
    MTIMAGE_METADATA_ARTIST,            ///< Metadata type, artist
    MTIMAGE_METADATA_GENRE,             ///< Metadata type, genre
    MTIMAGE_METADATA_SAMPL_FREQ,        ///< Metadata type, sampl freq
    MTIMAGE_METADATA_BITRATE,           ///< Metadata type, bitrate
    MTIMAGE_METADATA_FRAMESIZE,         ///< Metadata type, framesize
    MTIMAGE_METADATA_PLAYTIME,          ///< Metadata type, playtime
    MTIMAGE_METADATA_FRAMERATE,         ///< Metadata type, framerate
    MTIMAGE_METADATA_CAM_MAKER,         ///< Metadata type, cam maker
    MTIMAGE_METADATA_CAM_MODEL,         ///< Metadata type, cam model
    MTIMAGE_METADATA_CREATION_DATE,     ///< Metadata type, creation date
    MTIMAGE_METADATA_HRES,              ///< Metadata type, horizontal resolution
    MTIMAGE_METADATA_VRES,              ///< Metadata type, vertical resolution
    MTIMAGE_METADATA_BPP,               ///< Metadata type, bpp
    MTIMAGE_METADATA_IMAGETYPE,         ///< Metadata type, image type
    MTIMAGE_METADATA_PAR_WIDTH,         ///< Metadata type, par width
    MTIMAGE_METADATA_PAR_HEIGHT,        ///< Metadata type, par height
    MTIMAGE_METADATA_VIDEO_CODEC,       ///< Metadata type, video codec
    MTIMAGE_METADATA_AUDIO_CODEC,       ///< Metadata type, audio codec
    MTIMAGE_METADATA_ERR_CODEC_INFO,    ///< Metadata type, error correction codec information
    MTIMAGE_METADATA_INDEX_EXISTED,     ///< Metadata type, index existed
	MTIMAGE_METADATA_LIVEFLAG,          ///< Metadata type, live flag
    MTIMAGE_METADATA_VBR,               ///< Metadata type, variable bitrate
    MTIMAGE_METADATA_MTIMAGE_FIFODEPTH, ///< Metadata type, mtimage fifo depth
	MTIMAGE_METADATA_MTIMAGE_FIFOSIZE,  ///< Metadata type, mtimage fifo size
    MTIMAGE_METADATA_VDEC_FIFODEPTH,    ///< Metadata type, vdec fifo depth
    MTIMAGE_METADATA_VDEC_FIFOSIZE,     ///< Metadata type, vdec fifo size
    MTIMAGE_METADATA_JPEG_DISPLAY_W,    ///< Metadata type, jpeg display width
    MTIMAGE_METADATA_JPEG_DISPLAY_H,    ///< Metadata type, jpeg display height
    MTIMAGE_METADATA_ISDIVXPLUSHD,      ///< Metadata type, divxplus hd flag
    MTIMAGE_METADATA_VIDEO_CSC_FORMAT,  ///< Metadata type, video csc format
} MTIMAGE_METADATA_T;

/**Decoder capability.
It is used for getting decoder capability.
*/
typedef enum
{
    MT_IMAGE_CAP_IMAGE_FORMAT     = 0x01,    ///< Supporting file format
    MT_IMAGE_CAP_MAX_RESOLUTION   = 0x02,    ///< Supporting maz resolution
    MT_IMAGE_CAP_MIN_RESOLUTION   = 0x04,    ///< Supporting min resolution
    MT_IMAGE_CAP_COLOR_FORMAT     = 0x08,    ///< Supporting color format
    MT_IMAGE_CAP_MAX,                        ///< Max boundary
} MTIMAGE_CAP_T;

/**Picture enlargement ratio.
It is used for distinguishing picture enlargement ratio.
*/
typedef enum
{
	MTIMAGE_PICTURE_ENLARGEMENT_10X = 0,    ///< Picture enlargement ratio, 1.0
    MTIMAGE_PICTURE_ENLARGEMENT_12X,        ///< Picture enlargement ratio, 1.2
    MTIMAGE_PICTURE_ENLARGEMENT_14X,        ///< Picture enlargement ratio, 1.4
    MTIMAGE_PICTURE_ENLARGEMENT_16X,        ///< Picture enlargement ratio, 1.6
    MTIMAGE_PICTURE_ENLARGEMENT_18X,        ///< Picture enlargement ratio, 1.8
    MTIMAGE_PICTURE_ENLARGEMENT_20X,        ///< Picture enlargement ratio, 2.0
    MTIMAGE_PICTURE_ENLARGEMENT_MAX_NUM,    ///< Max boundary
} MTIMAGE_PICTURE_ENLARGEMENT_RATIO_T; 

/**MP type of MPF file.
It is used for distinguishing MP type.
*/
typedef enum
{
    MP_TYPE_BASELINE_PRIMARY_IMAGE,      ///< MP type baseline primary
    MP_TYPE_LARGE_THUMBNAIL_CLASS1,      ///< MP type large thumbnail class1
    MP_TYPE_LARGE_THUMBNAIL_CLASS2,      ///< MP type large thumbnail class2
    MP_TYPE_MULTI_FRAME_IMAGE_PANORAMA,  ///< MP type multi frame image panorama
    MP_TYPE_MULTI_FRAME_IMAGE_DISPARITY, ///< MP type multi frame image disparity
    MP_TYPE_MULTI_FRAME_IMAGE_MULTIANGLE,///< MP type multi frame image multiangle
    MP_TYPE_MAX                          ///< MP type Max boundary
}MP_TYPE;

/**thumbnail type
a. keep aspect ration thumbnail.
b. fill with box thumbnail.
*/
typedef enum
{
    MT_IMAGE_NOT_THUMBNAIL,            ///< Not thumbnail
    MT_IMAGE_ASPECT_RATIO_THUMBNAIL,   ///< Aspect ratio thumbnail   
    MT_IMAGE_FILL_WITH_BOX_THUMBNAIL,  ///< Fill with box thumbnail
} MTIMAGE_THUMBNAIL_TYPE_T;

/**Buffer filled. 
It is used for feeding data.
*/
typedef struct
{
    UINT32 u4_trsn_id;         ///< Ttransaction id 
    INT32 i4_ret;              ///< MW buffer-filling return codes
    UINT32 u4_filled_len;      ///< Filled length 
} MTIMAGE_BUF_FILLED_T;


/**Parameters of image display.
It is used for displaying image.
*/
typedef struct 
{
    MTVDO_REGION_T rDstRegion;              ///< Destination region
    MTIMAGE_ROTATE_T eRotation;             ///< Rotation phase for display
    UINT32 u1PlaneId;                       ///< The id of the OSD/Video plane for display (image only)
    BOOL fgClean;                           ///< Frame buffer clean or not
    BOOL fgDisplay;                         ///< Frame buffer display or not
    BOOL fgIsSlideShow;                     ///< Slide show or not
} MTIMAGE_PARAM_T;

/**Parameters of MP Entry.
*/
typedef struct
{
    UINT32 u4ImgAttr;        ///< MPEntry, image attribution
	UINT32 u4ImgSize;        ///< MPEntry, image size
	UINT32 u4ImgDataOft;     ///< MPEntry, image data offset
	UINT16 u4ImgEntryNo1;    ///< MPEntry, image entry NO 1
	UINT16 u4ImgEntryNo2;	 ///< MPEntry, image entry NO 2
}MTIMAGE_MPEntry;

/**Parameters of image meta data.
It is used for keeping image meta data.
*/
typedef struct
{
    UINT32 u4Width;              ///< image width
    UINT32 u4Height;             ///< image height
    UINT32 u4ThumbnailWidth;     ///< image thumbnail width
    UINT32 u4ThumbnailHeight;    ///< image thumbnail height 
    UINT32 u4BPP;                ///< image bytes per pixel
    UINT32 u4ThumbnailLength;    ///< image thumbnail length
    UINT32 u4Orientation;        ///< image orientation
    UINT32 u4APP1Length;         ///< image APP1 length
    UINT32 u4APP2Length;         ///< image APP2 length
    UINT8 au1Maker[20];          ///< image Maker
    UINT8 au1Model[30];          ///< image Model
    UINT8 au1Date[30];           ///< image Date
    UINT8 *pu1Thumbnail;         ///< image thumbnail data pointer
    UINT8 *pu1APP0;              ///< image APP0 pointer
    UINT8 *pu1APP1;              ///< image APP1 pointer
    UINT8 *pu1APP2;              ///< image APP2 pointer
    BOOL fgProgressive;          ///< image progressive or not
    BOOL fgIsMPF;                ///< image MPF or not
    BOOL fgSOF;                  ///< image SOF parsed or not
    BOOL fgIsMetaInfoParsed;     ///< image MetaInfo parsed or not
    UINT32 u4NumOfImages;        ///< image number
	MTIMAGE_MPEntry	rMPFMPEntry[MPF_MAX_IMAGE];	///< image MPFMPEntry
} MTIMAGE_IMGMETA_T;

/**MW_IF set output color format.
It is used for setting output color format.
*/
typedef struct
{
    MTIMAGE_IMGCOLORFORMAT_T eColorFormat;  ///< Desired output color format (image only)
} MTIMAGE_SETTING_T;

/**Getting decoder info
*/
typedef struct
{
    UINT32 u4CurImageAddrOffset;       ///< get Current Image address offset
} MTIMAGE_STATUS_T;


/**MTIMAGE callback function prototype.
It is the callback prototype used by MTIMAGE's callback mechanism.  The 
first argument is callback type.  The second one is a pointer to a data 
structure of callback parameters.  The last one is an additional parameter 
which is assigned when registering a specific callback function.
*/
typedef VOID (*MTIMAGE_CALLBACK)(MTIMAGE_CALLBACK_TYPE_T eCallbackType, 
                                     UINT32 u4Param);


/********************************************************************
  EXTERN VARIABLES & FUNCTION PROTOTYPES DECLARATIONS
********************************************************************/

/**This API opens an MTIMAGE instance.
*@param ucImgId           - image id.
*@param phHandle          - Pointer to the handle for holding the returning 
                                         instance handle.
*@param pucFileName      - File name of the multimedia file to be played back 
                                         by this MTIMAGE instance.
                                       - Set NULL for push mode.
                                       - File instance when MTIMAGE_SRCTYPE is 
                                          MTIMAGE_SRCTYPE_TIME_SHIFT
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Open(UCHAR ucImgId,MTIMAGE_HANDLE* phHandle, CHAR* pucFileName);

/**This API closes an MTIMAGE instance.
*@param ucImgId      - image id.
*@param hHandle       - Instance handle.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Close(UCHAR ucImgId,MTIMAGE_HANDLE hHandle);

/**This API sets playback parameters.
*@param hHandle        - Instance handle.
*@param prSettings     - Pointer to the data structure that holds the playback 
                                     parameters to be set.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Set(MTIMAGE_HANDLE hHandle, 
                                     MTIMAGE_SETTING_T* prSettings);

/**This API retrieves the current playback settings.
*@param hHandle       - Instance handle.
*@param prSettings    - Pointer to the data structure for holding the 
                                    returning playback settings.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Get(MTIMAGE_HANDLE hHandle, 
                                     MTIMAGE_SETTING_T* prSettings);

/**This API set which path to display the image.
*@param ucImgId           - image id.
*@param pathId              - path id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetDisplayPath(UCHAR ucImgId, MT_IMAGE_PATH pathId);

/**This API starts the playback.
*@param ucImgId       - image id
*@param hHandle        - Instance handle.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Start(UCHAR ucImgId,MTIMAGE_HANDLE hHandle);

/**This API stops the playback.
*@param ucImgId     - image id
*@param hHandle      - Instance handle.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Stop(UCHAR ucImgId,MTIMAGE_HANDLE hHandle);

/**Get the buffer address and size of the input local buffer
*@param hHandle             - Instance handle.
*@param ppi1Buffer          - Avaiable buffer pointer.
*@param pu4Size              - Size of avaiable buffer.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTIMAGE_GetBuffer(MTIMAGE_HANDLE hHandle,
                            INT8** ppi1Buffer, UINT32* pu4Size);

/**This API retrieves the current playback status.
*@param ucImgId   - image id.
*@param region      - Pointer to region.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_GetInfo(UCHAR ucImgId, MTVDO_REGION_T *region);

/**This API registers a callback function.
IMAGE can uses the registered callback function to notify the upper layer. 
*@param ucImgId      - image id.
*@param hHandle       - Instance handle.
*@param fnCallback    - Callback function body.
*@param u4Param      - Additional parameter to be passed when calling the 
                        callback.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_RegCb(UCHAR ucImgId,MTIMAGE_HANDLE hHandle,
                                     MTIMAGE_CALLBACK fnCallback, 
                                     UINT32 u4Param);

/**Set image parameters for display.
*@param ucImgId          - image id.
*@param hHandle           - Instance handle.
*@param prImgSetting    - Image setting for display.
*@param fgPartial           - Partial flag.
*@param prRegion          - Pointer to region.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Display(UCHAR ucImgId,MTIMAGE_HANDLE hHandle,
                                     MTIMAGE_PARAM_T *prImgSetting, 
                                     BOOL fgPartial, MTVDO_REGION_T *prRegion);
									 
/**Push bitstream to kernel.
*@param hHandle                   - Instance handle.
*@param pu1Buf                    - Buffer address of bitstream data.
*@param u4Size                     - Size of the buffer.
*@param fgEof                        - Whether last data of the file/bitstream.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_PushData(UCHAR ucImgId,MTIMAGE_HANDLE hHandle, UINT8 *pu1Buf,
                                                UINT32 u4Size, BOOL fgEof);

/**Get result image from kernel.
*@param ucImgId                         - image id.
*@param hHandle                          - Instance handle.
*@param pu4Buf                           - Buffer address of jpeg output (virtual).
*@param pu4PhyBuf                      - Buffer address of jpeg output (physical).
*@param pu4CbCrOffset                - CbCr address offset (physical)
*@param prRegion                         - Pointer to region 
*@param fgGetARGBThumbail         - Flag of ARGB thumbail or not
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_GetImg(UCHAR ucImgId,MTIMAGE_HANDLE hHandle,
                           UINT32 *pu4Buf, UINT32 *pu4PhyBuf, UINT32* pu4CbCrOffset, MTVDO_REGION_T *prRegion, BOOL fgGetARGBThumbail, MTIMAGE_ROTATE_T eRotation);

/**Get meida type.
*@param ucImgId            - image id.
*@param hHandle             - Instance handle.
*@param fgPush               - Flag of push or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetDataMode(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, BOOL fgPush);

/**This API set feed data mode
*@param ucImgId   	  	          - image id.
*@param hHandle            		   - Instance handle.
*@param eType         		   	   - Transition effect type.
*@param slidetime                         - Slide time interval.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
//EXTERN MT_RESULT_T MTIMAGE_SlideShow(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, MTIMAGE_SLIDETYPE eType);
EXTERN MT_RESULT_T MTIMAGE_SlideShow(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, MTIMAGE_SLIDETYPE eType, UINT32 slidetime); 

/**This API clean framebuffer data
*@param hHandle            		   - Instance handle.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_CleanFrameBuffer(MTIMAGE_HANDLE  hHandle);

/**This API set decoding resolution
*@param ucImgId   	  	         - image id.
*@param hHandle            		   - Instance handle.
*@param u4W            		   	   - image destination width.
*@param u4H            		          - image destination height.
*@param u4Pitch            		   - image destination u4Pitch.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetDecResolution(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, UINT32 u4W, UINT32 u4H, UINT32 u4Pitch);

/**This API wait decoding finish by semaphore
*@param ucImgId   	  			   - image id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_WaitDecFinish(UCHAR ucImgId);

/**This API set connection to decoder
*@param ucImgId   	  	         - image id.
*@param fgConnect   	  		   - connect or not.
*@param eColorFMT   	  		   - output color format.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_Connect(UCHAR ucImgId,BOOL fgConnect, UINT32 eColorFMT);

/**This API set data from buffer mode(bitstream source is buffer not file)
*@param ucImgId   	             - image id
*@param phHandle            	      - Instance handle.
*@param pu1Buf   	  		      - bitstream buffer address.
*@param u4Size            	       - image file size.
*@param format            	       - image format is jpeg or png.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_DataFromBuffer(UCHAR ucImgId,MTIMAGE_HANDLE* phHandle, UINT8 *pu1Buf, UINT32 u4Size, UINT32 format);

/**This API set destination address
*@param ucImgId   	  	         - image id.
*@param hHandle            		   - Instance handle.
*@param u4DecAddr   	  		   - decoder output address
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetDecAddr(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, UINT32 u4DecAddr);

/**This API gets the image meta info.
*@param hHandle   - Instance handle.
*@param type  	  - Metadata type.
*@param buf       - Metadata return buffer.
*@param bufsize   - Metadata buffer size.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_GetImgMetaInfo(MTIMAGE_HANDLE hHandle, MTIMAGE_METADATA_T type, UINT32 *buf, UINT8	bufsize);

/**This API set enlargement ratio.
*@param hHandle   - Instance handle.
*@param ratio  	  - enlargement ratio selection.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetEnlargement(MTIMAGE_HANDLE hHandle, MTIMAGE_PICTURE_ENLARGEMENT_RATIO_T ratio);

/**This API set picture move position.
*@param hHandle       - Instance handle.
*@param x_offset  	  - Picture destination x offset.
*@param y_offset  	  - Picture destination y offset.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetPictureMovePosition(MTIMAGE_HANDLE hHandle, UINT16 x_offset, UINT16 y_offset);

/**This API check MPO file or not.
*@param ucImgId   	  			   - image id.
*@param pMediaPath                 - Pointer to media path.
*@param isMpoFile                  - Whether the file is Mpo file or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_isMPOFile(UCHAR ucImgId, CHAR *pMediaPath, UINT8 *isMpoFile);

/**This API set thumbnail display type.
*@param ucImgId   	  			   - image id.
*@param type                       - display thumbnail type.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_ThumbnailSetDisplayType(UCHAR ucImgId, MTIMAGE_THUMBNAIL_TYPE_T type);

/**This API set panel resolution.
*@param ucImgId     		   - image id.
*@param u4PanelW                   - panel width.
*@param u4PanelH                   - panel height.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_SetPanelResolution(UCHAR ucImgId, UINT32 u4PanelW, UINT32 u4PanelH);

EXTERN MT_RESULT_T MTIMAGE_GetPngLUT8PaletteData(UINT32 au4palette[256], UINT32 paletteLength);
EXTERN MT_RESULT_T MTIMAGE_SetDecRatio(UCHAR ucImgId,MTIMAGE_HANDLE  hHandle, UINT16 u2DecRatio);
EXTERN MT_RESULT_T MTIMAGE_DumpData(UINT32 *pAddress, UINT32 u4Width, UINT32 u4Height, UINT32 u4Pitch, CHAR *pDataOutPath);
//==========================================================================================
//mw_if below

/**Image type information.
*/
typedef enum
{
    MT_IMAGE_TYPE_PROGRESS,	   ///< Type progress
    MT_IMAGE_TYPE_LIMITATION   ///< Type limitation
} MTIMAGE_IMG_INFO_TYPE;

/**Image state notification type.
*/
typedef enum
{
    MT_IMAGE_NFY_FILL_BUF,        ///< Notify fill buffer state
    MT_IMAGE_NFY_FINISHED,        ///< Notify finished state
    MT_IMAGE_NFY_ERROR,           ///< Notify error state
    MT_IMAGE_NFY_STOP_DONE,       ///< Notify stop done state
    MT_IMAGE_NFY_ALREADY_STOPPED, ///< Notify already stopped state
    MT_IMAGE_NFY_DRV_STOPED       ///< Notify driver stop state 
} MTIMAGE_NFY_STATE_T;

/**feed data structure
It is used for feeding data
*/
typedef struct
{
    UINT32          ui4_trsn_id;        ///<  transaction id 
    VOID            *pv_start_add;      ///< starting address 
    UINT32          ui4_required_len;   ///< required length 
    BOOL            b_reset_pos;        ///< position-resetting flag 
    UINT32          ui4_position;       ///< the position to be resettd 
} MTIMAGE_FILL_BUF_T;

/**MW_IF notify function type
It is used for feeding data
*/
typedef VOID (*MTIMAGE_NFY_FCT_T)
(
    UINT32          	ui4_img_id,         ///< the image id which causes this notification 
    VOID            	*pv_tag,            ///< tag passed to the callback function 
    VOID            	*pv_data,           ///< data passed with this notification 
    MTIMAGE_NFY_STATE_T e_state);           ///< notification state 

/**MW_IF notify parameters 
*/
typedef struct _MTIMAGE_SET_NFY_PARM{
UINT32          	ui4_img_id;         ///< the image id which causes this notification 
VOID            	*pv_tag;            ///< tag passed to the callback function 
VOID            	*pv_data;           ///< data passed with this notification 
MTIMAGE_NFY_STATE_T	 e_state;           ///< notification state 

//MTIMAGE_FILL_BUF_T t_attach_buf;             ///< Optional, Only use for JPG_HW_NFY_FILL_BUF 
UINT32          ui4_trsn_id;           ///< transaction id 
VOID            *pv_start_add;         ///< starting address 
UINT32          ui4_required_len;      ///< required length 
BOOL            b_reset_pos;           ///< position-resetting flag 
UINT32          ui4_position;          ///< the position to be resettd 

MTIMAGE_NFY_FCT_T   pf_nfy;            ///< notify function
UINT32 u4JpgInputBufBase;              ///< input buffer base
} MTIMAGE_SET_NFY_PARM;

/**MW_IF notify parameters 
*/
typedef struct _MTIMAGE_SET_NFY_MW_PARM{
UINT32          	ui4_img_id;         ///< the image id which causes this notification 
VOID            	*pv_tag;            ///< tag passed to the callback function 
VOID            	*pv_data;           ///< data passed with this notification 
MTIMAGE_NFY_STATE_T	 e_state;           ///< notification state 
MTIMAGE_FILL_BUF_T t_attach_buf;        ///< Optional, Only use for JPG_HW_NFY_FILL_BUF 
MTIMAGE_NFY_FCT_T   pf_nfy;             ///< notify function
} MTIMAGE_SET_NFY_MW_PARM;


/* *MW_IF data passed with IMG_SET_TYPE_FRM_START 
*/
typedef struct
{
    UINT32          ui4_img_id;         ///< the image id decoded 
    VOID            *pv_img_buf;        ///< image data 
    UINT32          ui4_img_size;       ///< image size 
    VOID            *pv_aux_cache;      ///< auxiliary cache data 
    MTIMAGE_NFY_FCT_T   pf_func;        ///< callback function 
    VOID            *pv_tag;            ///< tag passed to the callback function 
} MTIMAGE_FRM_START_T;

/** MW_IF decoder out parameters
*/
typedef struct
{
	UINT8* pu1Addr;								///< [IN] start address
	UINT32 u4CbCrOffset;					    ///< [IN] address offset for Y/CbCr seperate mode
	UINT32 u4Depth;								///< [IN] number of bits per pixel  for Y component.	
	UINT32 u4Pitch;								///< [IN] pitch
	UINT32 u4TotalLine;							///< [IN] total height
	UINT32 u4StartX;							///< [IN] start point X
	UINT32 u4StartY;							///< [IN] start point Y
	UINT32 u4Width;								///< [IN] region width
	UINT32 u4Height;							///< [IN] region height
    UCHAR  ucPicStruct;                         ///< 1, TOP_FLD_PIC   2,BTM_FLD_PIC  3,FRM_PIC
    UINT32 u4DecRatio;                          ///< decoder ratio 
}MTIMG_MW_REGION_T;

/** MW_IF get framebuffer rleated info
*/
typedef struct
{
    UCHAR ucFbgId;          ///< fbg id
    UINT32 u4RingOffset;    ///< ring buffer offset
}MTIMG_MW_VDEC_T;

/** MW_IF source region fields
*/
typedef struct
{
    UINT32 u4SrcStartX;								///< [IN] start point X
    UINT32 u4SrcStartY;								///< [IN] start point Y
    UINT32 u4SrcWidth;								///< [IN] region width
    UINT32 u4SrcHeight;								///< [IN] region height
}MTIMG_MW_SRC_REGION_T;

/**MW_IF Output Color format.
It is used for distinguishing decoder output format.
*/
typedef enum
{
    MTIMG_MW_AYCBCR8888_DIRECT32,						///< AYCbCr display mode, 32 bit per pixel, for OSD
    MTIMG_MW_ARGB8888_DIRECT32,                         ///< ARGB8888
    MTIMG_MW_Y_CBCR420_SEP16,							///< Y/CbCr seperate 420 display mode, 16 bit per pixel, for video plane
    MTIMG_MW_Y_CBCR422_SEP16,							///< Y/CbCr separate 422 display mode, 16 bit per pixel, for video plane
    MTIMG_MW_Y_CBCR444_YCSEP24,                         ///< Y/CbCr separate 444 display mode, 16 bit per pixel, for video plane
    MTIMG_MW_ARGB4444_DIRECT16,                         ///< ARGB4444
    MTIMG_MW_ARGB1555_DIRECT16,                         ///< ARGB1555
    MTIMG_MW_RGB565_DIRECT16,                           ///< RGB565
    MTIMG_MW_COLOR_MODE_MAX                             ///< Max boundary
}MTIMG_MW_DISP_COLOR_MODE;

/**MW_IF Rotation Option.
*/
typedef enum
{
	MTIMG_MW_CLOCKWISE_0			 	= 0,    ///< no rotation
	MTIMG_MW_CLOCKWISE_0_WITH_FLIP	 	= 1,    ///< no rotation + flip
	MTIMG_MW_CLOCKWISE_180			 	= 2,    ///< clockwise 180 degrees
	MTIMG_MW_CLOCKWISE_180_WITH_FLIP 	= 3,    ///< clockwise 180 degrees with flip
	MTIMG_MW_CLOCKWISE_270_WITH_FLIP 	= 4,    ///< clockwise 270 degrees with flip
	MTIMG_MW_CLOCKWISE_90			 	= 5,    ///< clockwise 90 degrees
	MTIMG_MW_CLOCKWISE_90_WITH_FLIP  	= 6,    ///< clockwise 90 degrees with flip
	MTIMG_MW_CLOCKWISE_270			 	= 7,    ///< clockwise 270 degrees
	MTIMG_MW_PHASE_MAX                          ///< Max boundary
} MTIMG_MW_ROTATE_T;

/**MW_IF Input compressed image and output destination information.
 */
typedef struct {
	MTIMAGE_IMG_FORMAT eFormat;					///< [IN] Format of Image.
	UINT8* pu1InBuffer;							///< [IN] compressed data start pointer.Null for using buffer notify mechanism
	UINT64 u8BufSize;							///< [IN] the size of the compressed data. 0 for using buffer notify mechanism	
	MTIMG_MW_REGION_T rDstRegion;				///< [IN] destination information, use internal buffer if pu1Addr == NULL, use default w,h if w,h=0
	BOOL bKeepRatio;							///< [IN] TRUE: keep original image ratio, FALSE: fit u4DstW, u4DstH
	MTIMG_MW_DISP_COLOR_MODE eDispColorMode;	///< [IN] destination color mode
	MTIMG_MW_ROTATE_T eRotateDegree;		    ///< [IN] rotate degree	
	MTIMG_MW_REGION_T* prDecOut;				///< [IN/OUT] the decompressed image info. Valid: !=NULL, prepare by middleware		
	MTIMG_MW_VDEC_T rMjpg;                      ///< used for getting working buffer from MPEG (MJPEG only)
    MTIMG_MW_SRC_REGION_T rSrcRegion;           ///< [IN] source region field
    UINT32 u4DecColorMode;                      ///< [IN] decoder color mode
    BOOL fgThumbnailDec;                        ///< [IN] decode thumbnail or full image	
#ifdef CC_FUJI3D_SUPPORT
    BOOL fgMPFParsing;                          ///< [IN] parsing MPF header
#endif    
	BOOL   bIsVitualOutputAddr;                    ///[OUT]imgrz output address is virtual or physical,this value is from mw
} MTIMG_MW_PARAM_T;

/**MTIMAGE callback function prototype.
It is the callback prototype used by MTIMAGE's callback mechanism.  The 
first argument is callback type.  The second one is a pointer to a data 
structure of callback parameters.  The last one is an additional parameter 
which is assigned when registering a specific callback function.
*/

/**MW_IF API show callback function prototype for MW
*@param u4Param  		   	- callback function additional parameter 
*/
typedef VOID (*MTIMAGE_MW_CALLBACK)(void *u4Param);

/**MW_IF API retrieves the current playback status.
*@param hHandle   - Instance handle.
*@param type   	  - Get info type.
*@param prStatus  - Pointer to the data structure for holding the returning 
                    playback status.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_GetInfo(MTIMAGE_HANDLE hHandle, MTIMAGE_IMG_INFO_TYPE type,
                                     void *prStatus);

/**MW_IF API set feed data info
*@param hHandle   	- Instance handle.
*@param type   	  	- Get info type.
*@param prBufInfo  	- set feed data info to kernel
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_SetBufFilled(UCHAR ucImgId, MTIMAGE_HANDLE	hHandle, void *prBufInfo);

/**MW_IF API set cmd to trigger decode.
*@param ucImgId     - image id
*@param hHandle   	- Instance handle.
*@param prInfo   	- deocding info cmd structure
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_SetDecode(UCHAR ucImgId, MTIMAGE_HANDLE hHandle, MTIMG_MW_PARAM_T* prInfo);

/**MW_IF API set cmd to trigger decode.
*@param ucImgId     - image id
*@param hHandle   	- Instance handle.
*@param format   	- image file format
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_ConfigImageDecoder(UCHAR ucImgId, MTIMAGE_HANDLE hHandle, MTIMAGE_IMG_FORMAT format);

/**MW_IF API set init decode.
*@param ucImgId     - image id
*@param hHandle   	- Instance handle.
*@param prInfo   	- Info sturcture to init decoder 
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_SetInit(UCHAR ucImgId, MTIMAGE_HANDLE hHandle, void* prInfo);

/**MW_IF API connect to decoder
*@param ucImgId     - image id
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_Connect(UCHAR ucImgId);

/**MW_IF API register callback function for MW
*@param ucImgId     - image id
*@param fnCallback  - callback function for MW
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_MW_RegCb(MTIMAGE_HANDLE hHandle, MTIMAGE_MW_CALLBACK fnCallback);

/**MW_IF API get image file format for MW
*@param ucImgId     - image id
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MTIMAGE_IMG_FORMAT MTIMG_GetImageType(UCHAR ucImgId);	

/**This API init semaphore for multi-process protection
*@param ucImgId     - image id
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_InitHwResource(UCHAR ucImgId);

/**This API lock semaphore for multi-process protection
*@param ucImgId     - image id
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_LockHwResource(UCHAR ucImgId);

/**This API unlock semaphore for multi-process protection
*@param ucImgId     - image id
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTIMAGE_UnLockHwResource(UCHAR ucImgId);

/**This API get hw decoder status for multi-process protection
*@param ucImgId     - image id
*retval MT_IMAGE_CALLBACK_NEEDDATA, 	   Notification of copy buffer
*retval MT_IMAGE_CALLBACK_ERROR,		   Notification of play error
*retval MT_IMAGE_CALLBACK_FINISH,		    Notification of file end   
*/
EXTERN MTIMAGE_CALLBACK_TYPE_T MTIMAGE_GetHwDecodeStatus(UCHAR ucImgId);

#ifdef __cplusplus
}
#endif

#endif // MT_IMAGE_H

