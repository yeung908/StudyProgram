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
 * $RCSfile: mtvdec.h,v $
 * $Revision: #2 $
 *---------------------------------------------------------------------------*/ 

/** @file mtvdec.h
 *  This header file declares exported APIs of Video Decoder (VDEC) module,
 *  which inclued MPEG 1/2/4, H.264(AVC), and VC-1
 */

#ifndef MT_VDEC_H
#define MT_VDEC_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
#include "mtdmx.h"

   
//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
#define ES_ID_0     0             ///< VDEC Instance ID 0
#define ES_ID_1     1             ///< VDEC Instance ID 1
#define ES_ID_2     2             ///< VDEC Instance ID 1
#define ES_ID_3     3             ///< VDEC Instance ID 1
#define MTVDEC_ES_ID_MAX   4      ///< Maximum VDEC Instnace
#define DECODER_OUTPUT_OFFSET 3*1024*1024    ///< Decoder Output offset for HD Frame
// #define MTVDEC_VIDEO_ES_INPUT_SUPPORT
//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/**vdec frame rate define
*/
typedef enum
{
    MTVDEC_FRAME_RATE_24_ =1,     ///< VDEC Frame rate 23.97
    MTVDEC_FRAME_RATE_24,         ///< VDEC Frame rate 24 
    MTVDEC_FRAME_RATE_25,         ///< VDEC Frame rate 25
    MTVDEC_FRAME_RATE_30_,        ///< VDEC Frame rate 29.97
    MTVDEC_FRAME_RATE_30,         ///< VDEC Frame rate 30
    MTVDEC_FRAME_RATE_50,         ///< VDEC Frame rate 50
    MTVDEC_FRAME_RATE_60_,        ///< VDEC Frame rate 59.97
    MTVDEC_FRAME_RATE_60,         ///< VDEC Frame rate 60
    MTVDEC_FRAME_RATE_UNKNOWN     ///< Unknow value
}MTVDEC_FRAME_RATE_T;

/**The aspect ratio of video source.
   Should be same with VDEC_ASPECT_xxx exactly.
*/
typedef enum
{
    MTVDEC_ASPECT_RATIO_NONE = 0, ///< Aspect Ration default
    MTVDEC_ASPECT_RATIO_1_1,   ///< Pixel Aspect ratio 1:1
    MTVDEC_ASPECT_RATIO_4_3,   ///< Display Aspect ratio 4:3
    MTVDEC_ASPECT_RATIO_16_9,  ///< Display Aspect ratio 16:9
    MTVDEC_ASPECT_RATIO_221_1, ///< Display Aspect ratio 2.21:1
    MTVDEC_ASPECT_RATIO_10_11, ///< Pixel Aspect ratio 10:11
    MTVDEC_ASPECT_RATIO_40_33, ///< Pixel Aspect ratio 40:33
    MTVDEC_ASPECT_RATIO_16_11, ///< Pixel Aspect ratio 16:11
    MTVDEC_ASPECT_RATIO_12_11, ///< Pixel Aspect ratio 12:11
    MTVDEC_ASPECT_RATIO_3_2,   ///< Pixel Aspect ratio 3:2
    MTVDEC_ASPECT_RATIO_24_11, ///< Pixel Aspect ratio 24:11
    MTVDEC_ASPECT_RATIO_20_11, ///< Pixel Aspect ratio 20:11
    MTVDEC_ASPECT_RATIO_32_11, ///< Pixel Aspect ratio 32:11
    MTVDEC_ASPECT_RATIO_80_33, ///< Pixel Aspect ratio 80:33
    MTVDEC_ASPECT_RATIO_18_11, ///< Pixel Aspect ratio 18:11
    MTVDEC_ASPECT_RATIO_15_11, ///< Pixel Aspect ratio 15:11
    MTVDEC_ASPECT_RATIO_64_33, ///< Pixel Aspect ratio 64:33
    MTVDEC_ASPECT_RATIO_160_99, ///< Pixel Aspect ratio 160:99
    MTVDEC_ASPECT_RATIO_TRANSMIT, ///< Pixel Aspect ratio User define
    MTVDEC_ASPECT_RATIO_2_1,
    MTVDEC_ASPECT_RATIO_MAX
}MTVDEC_ASPECT_RATIO_T;

/**The profile of video source.
   Should be same with ENUM_VDEC_PROFILE_T exactly
*/
typedef enum
{
	MTVDEC_PROFILE_UNKNOWN = 0,
	MTVDEC_PROFILE_SIMPLE,
	MTVDEC_PROFILE_MAIN,
	MTVDEC_PROFILE_SNR_SCALABLE,
	MTVDEC_PROFILE_SPATIAL_SCALABLE,
	MTVDEC_PROFILE_HIGH,
	MTVDEC_PROFILE_MULTIVIEW,
	MTVDEC_PROFILE_4_2_2,
	//MPEG4
	MTVDEC_PROFILE_ADVANCED_CODING_EFFICIENCY,
	MTVDEC_PROFILE_SIMPLE_STUDIO,
	MTVDEC_PROFILE_CORE_STUDIO,
	MTVDEC_PROFILE_FINE_GRANULARITY_SCALABLE,
	MTVDEC_PROFILE_SIMPLE_FACE_ANIMATION,
	MTVDEC_PROFILE_SIMPLE_FBA,
	MTVDEC_PROFILE_BASIC_ANIMATED_TEXTURE,
	MTVDEC_PROFILE_SCALABLE_TEXTURE,
	MTVDEC_PROFILE_ADVANCED_SCALABLE_TEXTURE,
	MTVDEC_PROFILE_HYBRID,
	MTVDEC_PROFILE_SIMPLE_SCALABLE,
	MTVDEC_PROFILE_ADVANCED_SIMPLE,
	MTVDEC_PROFILE_CORE,
	MTVDEC_PROFILE_CORE_SCALABLE,
	MTVDEC_PROFILE_ADVANCED_CORE,
	MTVDEC_PROFILE_N_BIT,
	MTVDEC_PROFILE_REAL_TIME_SIMPLE,
	//H264
	MTVDEC_PROFILE_BASELINE,
	MTVDEC_PROFILE_EXTENDED,
	MTVDEC_PROFILE_HIGH_10,
	MTVDEC_PROFILE_HIGH_4_2_2,
	MTVDEC_PROFILE_HIGH_4_4_4,
	//VC1
	MTVDEC_PROFILE_ADVANCED,	
	//wmv
	MTVDEC_PROFILE_PC
}	MTVDEC_PROFILE_T;

/**The level of video source.
   Should be same with ENUM_VDEC_LEVEL_T exactly
*/
typedef enum
{
	MTVDEC_LEVEL_UNKNOWN = 0,
	MTVDEC_LEVEL_MAIN,
	MTVDEC_LEVEL_LOW,
	MTVDEC_LEVEL_HIGH,
	MTVDEC_LEVEL_HIGH_1440,
	MTVDEC_LEVEL_0,
	MTVDEC_LEVEL_1,
	MTVDEC_LEVEL_2,
	MTVDEC_LEVEL_3,
	MTVDEC_LEVEL_4,
	MTVDEC_LEVEL_5,
	MTVDEC_LEVEL_1_B,
	MTVDEC_LEVEL_1_1,
	MTVDEC_LEVEL_1_2,
	MTVDEC_LEVEL_1_3,
	MTVDEC_LEVEL_2_1,
	MTVDEC_LEVEL_2_2,
	MTVDEC_LEVEL_3_1,
	MTVDEC_LEVEL_3_2,
	MTVDEC_LEVEL_4_1,
	MTVDEC_LEVEL_4_2,
	MTVDEC_LEVEL_5_1,
	MTVDEC_LEVEL_LL,
	MTVDEC_LEVEL_ML,
	MTVDEC_LEVEL_HL,
	MTVDEC_LEVEL_L_0,
	MTVDEC_LEVEL_L_1,
	MTVDEC_LEVEL_L_2,
	MTVDEC_LEVEL_L_3,
	MTVDEC_LEVEL_L_4
}	MTVDEC_LEVEL_T;

/**Thumbnail Color mode 
*/
typedef enum
{
    MTVDEC_COLORMODE_AYUV_CLUT2     = 0, ///< Color Mode AYUV CLUT2
    MTVDEC_COLORMODE_AYUV_CLUT4     = 1, ///< Color Mode AYUV CLUT3
    MTVDEC_COLORMODE_AYUV_CLUT8     = 2, ///< Color Mode AYUV CLUT8
    MTVDEC_COLORMODE_UYVY_16        = 3, ///< Color Mode UYVY 16
    MTVDEC_COLORMODE_YUYV_16        = 4, ///< Color Mode YUYV 16
    MTVDEC_COLORMODE_AYUV_D8888     = 5, ///< Color Mode AYUV D8888
    MTVDEC_COLORMODE_ARGB_CLUT2     = 6, ///< Color Mode ARGB CLUT2
    MTVDEC_COLORMODE_ARGB_CLUT4     = 7, ///< Color Mode ARGB CLUT4
    MTVDEC_COLORMODE_ARGB_CLUT8     = 8, ///< Color Mode ARGB CLUT8
    MTVDEC_COLORMODE_RGB_D565       = 9, ///< Color Mode RGB D565
    MTVDEC_COLORMODE_ARGB_D1555     = 10, ///< Color Mode ARGB D1555
    MTVDEC_COLORMODE_ARGB_D4444     = 11, ///< Color Mode ARGB D4444
    MTVDEC_COLORMODE_ARGB_D8888     = 12, ///< Color Mode ARGB D8888
    MTVDEC_COLORMODE_YUV_420_BLK    = 13, ///< Color Mode YUV 420 Block Mode
    MTVDEC_COLORMODE_YUV_420_RS     = 14, ///< Color Mode YUV 420 Raster Mode
    MTVDEC_COLORMODE_YUV_422_BLK    = 15, ///< Color Mode YUV 422 Block Mode
    MTVDEC_COLORMODE_YUV_422_RS     = 16, ///< Color Mode YUV 422 Raster Mode
    MTVDEC_COLORMODE_YUV_444_BLK    = 17, ///< Color Mode YUV 444 Block Mode
    MTVDEC_COLORMODE_YUV_444_RS     = 18  ///< Color Mode YUV 444 Raster Mode
}MTVDEC_COLORMODE_T;

/**Thumbnail Info 
*/
typedef struct
{
    UCHAR*                    pucCanvasBuffer;   ///< Canvas Buffer Data
    MTVDEC_COLORMODE_T        eCanvasColormode;  ///< Color Mode
    UINT32                    u4CanvasWidth;     ///< Canvas Width
    UINT32                    u4CanvasHeight;    ///< Canvas Height
    UINT32                    u4CanvasPitch;     ///< Canvas Pitch

    UINT32                    u4ThumbnailX;      ///< Thumbnail X 
    UINT32                    u4ThumbnailY;      ///< Thumbnail Y 
    UINT32                    u4ThumbnailWidth;  ///< Thumbnail Width
    UINT32                    u4ThumbnailHeight; ///< Thumbnail Height
}MTVDEC_THUMBNAIL_INFO_T;

/* Thumbnail cap Info */
typedef struct
{
    BOOL    fgUFOOn;
    UINT32 u4UFOType;
    UINT32 u4AddrY;
    UINT32 u4AddrC;
    UINT32 u4AddrYLen;
    UINT32 u4AddrCLen;
    UINT32 u4DstY;
    UINT32 u4DstC;
    UINT32 u4MemHSize;
    UINT32 u4MemVSize;
    UINT32 u4HSize;
    UINT32 u4VSize;
    UINT32 u4RRMode;
    UINT32 u4IsRsIn;
    UINT32 u4SrcSwap;
} MTVDEC_CAPTURE_INTO_T;



/**vdec frame rate define
*/
typedef enum
{
    MTVDEC_SET_INST_PRIORITY,       ///< VDEC Set Inst priority
    MTVDEC_SET_INST_KICKDONE,       ///< VDEC Set the KickDone Inst 
    MTVDEC_SET_IS_VDP_RENDER,       ///< VDEC Set USE VDP/B2R or not.
    MTVDEC_SET_IMGRZ_ID,            ///< VDEC Set USE VDP/B2R or not.
    MTVDEC_SET_TEXTURE_MODE,        ///< VDEC Set texture mode:  for capture background.
    MTVDEC_SET_UNKNOWN              ///< Unknow value
}MTVDEC_SET_T;

/**Decoding speed of video decoder
 */
typedef enum
{
    MTVDEC_DEC_SPEED_PAUSE  =    0,    ///< VDEC PAUSE 
    MTVDEC_DEC_SPEED_SLOW   =  500,    ///< VDEC SLOW (with speed 0.5x)
    MTVDEC_DEC_SPEED_NORMAL = 1000,    ///< VDEC Speed normal 
}MTVDEC_DEC_SPEED_T;

/**Decoding Callback Type (ChangHong)
*/
typedef enum
{
  MTVDEC_DEC_CB_ERR,
  MTVDEC_DEC_CB_STATUS,
  MTVDEC_DEC_CB_FRAME,
  MTVDEC_DEC_CB_PICINFO,
  MTVDEC_DEC_CB_USERDATA
}MTVDEC_DEC_CB_TYPE;

/**Decoding mode of video decoder
 */
typedef enum
{
    MTVDEC_DEC_ALL,     ///< VDEC Decode all frame
    MTVDEC_DEC_IP,      ///< VDEC Decode I & P frame
    MTVDEC_DEC_I        ///< VDEC Decode I frame only
}MTVDEC_DEC_MODE_T;

/**Decoder callback type.
*/
typedef enum
{
   MTVDEC_CB_TYPE_ERR,                           ///< decoder error callback.
   MTVDEC_CB_TYPE_STATUS,                        ///< decoder status callback.
   MTVDEC_CB_TYPE_FRAME,                         ///< decoder each frame type callback.
   MTVDEC_CB_TYPE_PICINFO,                       ///< decoder picture information callback.
   MTVDEC_CB_TYPE_USERDATA                       ///< decoder user data callback.
}MTVDEC_CB_TYPE_T;

/**Picture header information for user data callback.
*/
typedef struct 
{
    UINT32 u4Pts;                       ///< Presentation Time Stamps (90KHz) -> CC & Video synchonization
    UINT16 u2TemporalRef;               ///< Temporal Reference (MPEG picture header) -> debug only
    UCHAR ucPicType;                    ///< I/P/B type -> debug only
    UCHAR ucPicStruct;                  ///< frame/field encode picture -> debug only
    UCHAR ucRepFirstFld;                ///< repeat first field -> debug only
    UCHAR ucTopFldFirst;                ///< top field first -> debug only
    UCHAR ucEsId;                       ///< decoder ID = ES_ID_0
    BOOL fgProgressiveFrame;            ///< progressice frame  
}MTVDEC_USERDATA_CB_T;

/**Decoding mode of video decoder
 */
typedef enum
{
    MTVDEC_RM_ALLOC_OK,     ///< VDEC Decode RM alloc HW OK
    MTVDEC_RM_ALLOC_NG,     ///< VDEC Decode RM alloc HW Fail
    MTVDEC_RM_ALLOC_CFT,    ///< VDEC Decode RM alloc HW conflict
    MTVDEC_RM_UNKNOWN  ,    ///< VDEC Decode MSG Unknown
}MTVDEC_RM_COND_T;

typedef struct
{
    unsigned char u1EsId;
    MTVDEC_RM_COND_T eCond;
    union 
    {
        unsigned char aucCftEsId[MTVDEC_ES_ID_MAX-1]; //eCond == MTVDEC_RM_ALLOC_CFT
        
    }u;
}MTVDEC_RM_CB_T;

/**Video information in bitstream header.
*/
typedef struct 
{
    BOOL fgHdrInvalid;                  ///<is header invalid?
    BOOL fgProgressiveSeq;              ///<progressice_sequence in Sequence extension
    BOOL fgConstrainedParameterFlag;    ///<constrained_parameters_flag in Sequence Header
    BOOL fgLowDelay;                    ///<low_delay in Sequence extension
    BOOL fgMPEG2;                       ///<True if sequence extension present
    BOOL fgSeqDispExternValid;          ///<True if display extension present
    BOOL fgColorDescription;            ///<colour_description in Sequence display extension
    BOOL fgNoOverScan;                  ///<overscan info in SPS
    BOOL fgPixelAspectRatio;            ///<Is PAR or not
    BOOL fgIsVC1;                        ///Is VC1 or not
    UCHAR ucAfd;                        ///<AFD in Picture user data
    UCHAR ucVideoFmt;                   ///<video_format in Sequence display extension   
    UCHAR ucProfileLevelIndication;     ///<profile_and_level_indication in Sequence extension
    UCHAR ucColorPrimaries;             ///<colour_primaries in Sequence display extension
    UCHAR ucTransferCharacteristics;    ///<transfer_characteristics in Sequence display extension
    UCHAR ucMatrixCoefficients;         ///<matrix_coefficients in Sequence display extension
    UINT16 u2Height;                    ///<vertical_size_value in Sequence Header 
    UINT16 u2Width;                     ///<horizontal_size_value in Sequence Header 
    INT16 i2DHS;                        ///<display_horizontal_size in Sequence display extension 
    INT16 i2DVS;                        ///<display_vertical_size in Sequence display extension 
    UINT16 u2FrmRate;                   ///<frame_rate_code in Sequence header
    UINT32 u4BitRate;                   ///<bit_rate_value in Sequence header
    UINT32 u4VbvBufSize;                ///<vbv_buffer_size_extension in Sequence extension
    UINT32 u4ChromaFormat;              ///<chroma_format in Sequence extension
    MTVDEC_ASPECT_RATIO_T eAspectRatio; ///<apsect ratio enum
    UINT32 u4DarWidth;                  ///<Display aspect ratio width
    UINT32 u4DarHeight;                 ///<Display aspect ratio height
    UINT32 u4ParWidth;                  ///<Pixel aspect ratio width
    UINT32 u4ParHeight;                 ///<Pixel aspect ratio height
    UINT32 u4H264IdcInfo;               ///<H264 Idc Infomation
    UINT32 u4DropFrameCnt;
    //cropping info
    BOOL fgCropping;                    ///<Is Corpping or not?
    UINT32 u4CropX;                     ///<Crop X coordinate
    UINT32 u4CropY;                     ///<Crop Y coordinate
    UINT32 u4CropWidth;                 ///<Crop X width
    UINT32 u4CropHeight;                ///<Crop Y height
    //sony seamless info
    UINT16                     u2SourceHeight;
    UINT16                     u2SourceWidth;
    UINT32                     u4SourcePixelAspectRatioWidth;
    UINT32                     u4SourcePixelAspectRatioHeight;
    MTVDEC_ASPECT_RATIO_T      eSrcASP;	
    MTVDEC_PROFILE_T eProfile;
    MTVDEC_LEVEL_T eLevel;
    BOOL                       fgDisplayASP;
    BOOL                       fgResized;
    BOOL                       fgOrigDisplayASP;
    //for Freeview HD subtitle sync
    UINT32 u4DelayTime;
} MTVDEC_HDR_INFO_T;

/**Video wfd error info.
*/
typedef struct
{
    INT32 i4TimeoutCnt;
    INT32 i4LackSeqHeaderCnt;
    INT32 i4OutOfSpecCnt;
}MTVDEC_WFD_DECODE_ERROR_T;

/**Frame/field deblocking information in bitstream.
*/
typedef struct 
{
    BOOL fgDeblocking;                   ///is deblocking?
    UINT32 u4Dbk1PixelCnt;               ///Strong deblocking method Pixel count
    UINT32 u4Dbk2PixelCnt;               ///Middle deblocking method Pixel count
    UINT32 u4Dbk3PixelCnt;               ///Weak deblocking method Pixel count
} MTVDEC_DBK_INFO_T;

/**Video decoder status.
* fgLock = TRUE, when the 1st picture decode ready.
* scramble channel (CQAM)  =>  fgLock = FALSE
* non scramble =>  fgLock = TRUE
* u4DecOkNs <= u4ReceiveNs
* When signal is weak, u4DecOkNs < u4ReceiveNs.
* picture type => ucPicType
* top field first => fgTopFldFirst
* repeat first field => fgRepFirstFld
* progressive frame => fgProgressiveFrm
* picture struct => ucPicStruture
* temporal reference => ucTemporalRef
*/
typedef struct 
{
    BOOL fgLock;                        ///<video decoder is lock.
    BOOL fgIsDisplaying;                ///<video start displaying
    BOOL fgTopFldFirst;                 ///<top field first
    BOOL fgRepFirstFld;                 ///<repeat first field
    BOOL fgProgressiveFrm;              ///<progressive frame
    UCHAR ucPicType;                    ///<picture type decoded ok by video decoder.
    UCHAR ucPicStruture;                ///<picture struct
    UINT32 ucTemporalRef;               ///<temporal reference
    UINT32 u4ReceiveNs;                 ///<picture count received by video decoder.
    UINT32 u4DecOkNs;                   ///<picture count decoded ok by video decoder.
    UINT32 u4CurPTS;                     ///<current displaying frame PTS
    UINT32 u4ESBufDataSize;             ///<current es buffer data size in bytes
    UINT32 u4DisplayQNum;               ///<current decoded frame number
    UINT32 u4DecodingPTS;               ///<current decoded frame pts
    BOOL   fgDisplayStatus;              ///<does this picture display normally or need to skip or drop
    BOOL   fgDecodeError;                ///<does this picture occurred any decode error
    UINT32 u4Status;                     ///<current decode status, ex. MTVDEC_STATUS_NORMAL
    UINT32 u4ESBufSize;                ///Vdec FIFO size
    UINT32 u4BufFreeSize;             ///Vdec FIFO Free Size
    UINT32 u4FirstDisplayPTS;       ///Vdec first Display frame PTS
}MTVDEC_DEC_STATUS_T;

/** Notify conditions 
*/
typedef enum
{
    MTVDEC_COND_ERROR = -1,   ///<Notify Error
    MTVDEC_COND_CTRL_DONE,    ///<Notify control done
    MTVDEC_COND_RESOLUTION_CHG,  ///<Notify resolution change
    MTVDEC_COND_I_FRAME_SET_BUFF_DONE,  ///<Notify I frame set buffer success
    MTVDEC_COND_I_FRAME_DECODE_DONE, ///<Notify I frame decode success
    MTVDEC_COND_DECODE_STATUS_CHG,   ///<Notify Decode status
    MTVDEC_COND_SPEED_CHG,           ///<Notify VDEC speed change
    MTVDEC_COND_THUMBNAIL_DONE,      ///<Notify thumbnail decode done
    MTVDEC_COND_THUMBNAIL_FAIL,      ///<Notify thumbnail decode Fail
    MTVDEC_COND_BIT_RATE,            ///<Notify Error
    MTVDEC_COND_PLAY_DONE,           ///<Notify MM/AP can trick, pause
    MTVDEC_COND_FRAMERATE_NOT_SUPPORT,    ///<Notify Framerate no support
    MTVDEC_COND_THUMBNAIL_PLAY_EOS,
    MTVDEC_COND_VPUSH_IO_DONE,
#ifdef MULTIMEDIA_AUTOTEST_SUPPORT
    MTVDEC_COND_CRC_CHECK_DONE,
    MTVDEC_COND_CRC_GET_DONE,
#endif
    MTVDEC_COND_FRAME_COMING,         ///Notiry frame is Normal decoding
    MTVDEC_COND_ESQ_UNDERFLOW,     ///Notify Vfifo is underflow
    MTVDEC_COND_ESQ_OVERFLOW,        /// Notify Vfifo is overflow
    MTVDEC_COND_SOURCE_CHANGE        ///Source change,such as,width height framerate
}   MTVDEC_COND_T;

/*
YUV to YCbCr Color convert
*/
typedef struct
{
    UINT32 u4SrcAddr;
    UINT32 u4TgtYAddr;
    UINT32 u4TgtCAddr;
    UINT32 u4PWidth;
    UINT32 u4PHeight;
    UINT32 u4YPitchSize;
    UINT32 u4UVPitchSize;
} MTVDEC_FB_INFO_T;

/** Playback Info 
*/
typedef struct
{
    BOOL fgMMPlayback;   ///<is mm playback ?
    BOOL fgIFrame;       ///<is play I-Frame?
} MTVDEC_PLAYBACK_INTO_T;

/**This structure contains I frame buffer addr and size.
*/
typedef struct 
{
    UCHAR*  pucIFrameBufAddr;   ///<I frame buffer addr
    UINT32  u4Size;             ///<I frame size
} MTVDEC_DEC_I_FRAME_BUFF_T;

typedef struct
{
    unsigned int  u4Pts;
    unsigned char u1PicType;
    unsigned char u1EsId;
} FRAME_T;

typedef struct
{
	UINT8			ch; 
	UINT16			nFramerate;

	/* MPEG2 aspect_ratio_information in sequence header */
	UINT16			aspect_ratio;
	UINT16			nHSize;
	UINT16			nVSize;
	UINT32			nBitrate;
	UINT8			afd;
	UINT8			bProgressiveSeq; 
	UINT8			bProgressiveFrame;
	UINT16			nActiveX;
	UINT16			nActiveY;
	UINT16			nActiveW;
	UINT16			nActiveH;
	UINT16			display_horizontal_size;
	UINT16			display_vertical_size;

	/* H264 aspect_ratio_idc in vdu_parameters() */
	UINT8			aspect_ratio_idc;
	UINT32			sar_width;
	UINT32			sar_height;
	UINT8           info3D;
}PICINFO_T;

/**Digital user data callback function.
*@param MTVDEC_USERDATA_CB_T       User data structure
*@param pu1UserData                User data pointer 
*@param pu1UserData                User data length
*/
typedef VOID (*MTVDEC_PFN_USERDATA_CB)
(
    MTVDEC_USERDATA_CB_T* prUserDataInfo, UINT8* pu1UserData, UINT16 u2DataLen
);


/**Decode error notify function.
*@param ucEsId                     ES id.
*@param u4DecErrNs                 Decode error picture count.       
*/
typedef VOID (*MTVDEC_PFN_DECERR_CB)
(
    UCHAR ucEsId, UINT32 u4DecErrNs
);


/**Decode picture notify notify function.
*@param ucEsId                     ES id.
*@param ucPicType                  Decode picture type.       
*@param u4Pts                      This picture presentation time stamp
*/
typedef VOID (*MTVDEC_PFN_FRAME_CB)(FRAME_T* prFrameInfo);

typedef VOID (*MTVDEC_PFN_PICINFO_CB)(PICINFO_T* prPicInfo);

/**Step Done notify notify function.
*@param u4Pts                      This picture presentation time stamp
*/
typedef VOID (*MTVDEC_PFN_STEP_FIN_CB)
(
    UINT32 u4Pts
);

/**Decode picture status notify function.
*@param ucEsId                     ES id.
*@param u4Status                   Decode status.       
*/
typedef VOID (*MTVDEC_PFN_STATUS_CB)
(
    UCHAR ucEsId, UINT32 u4Status
);

/**Resource manager notify function.
*@param ucEsId                     ES id.
*@param ucCond                    Cond.       
*@param u4Data                    Data.       
*@param u4Tag                      Tag set from server
*/
typedef VOID (*MTVDEC_PFN_RM_CB)
(
    UCHAR ucEsId, MTVDEC_RM_COND_T eCond, void *pVData
);

/**Decode general notify function.
*@param u4Tag                     Tag id.
*@param u4Condition               Condition type.   
*@param u4Data1                   u4Data1.   
*@param u4Data2                   u4Data2.       
*/
typedef VOID (*MTVDEC_PFN_GENERAL_CB)
(
    UINT32 u4Tag, UINT32 u4Condition, UINT32 u4Data1, UINT32 u4Data2
);

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Initialize VDEC module.
*@param VOID
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Init(VOID);

/**Terminate VDEC module.
*@param VOID
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Termint(VOID);

/** Reset VDEC module.
*@param VOID
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Reset(VOID);

/**Change VDEC to PLAY mode.
*@param ucEsId                     ES id.
*@param u4Fmt                      Video codec format.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Play(UCHAR ucEsId, MTVDEC_FMT_T eVdecFmt);

/**Decode still-picture(I-Frame),when decode finish,the frame will be displayed
*@param ucEsId                     ES id.
*@param eVdecFmt                      Video codec format.
*@param pucData                    input data address
*@param u4Size                     input data size(in byte)
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PlayIFrame(UCHAR ucEsId, MTVDEC_FMT_T eVdecFmt, UINT8* pucData, UINT32 u4Size);

/**Decode still-picture(I-Frame),when decode finish,the frame will not be displayed and return decoded data to user
*@param ucEsId                     ES id.
*@param eVdecFmt                      Video codec format.
*@param pucData                    input data address
*@param u4Size                     input data size(in byte)
*@param ppucDestData                outoput data address
*@param pu4DestSize                outoput data size
*@param pu4Width                   outoput picture width
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_DecodeIFrame(UCHAR ucEsId, MTVDEC_FMT_T eVdecFmt, UINT8* pucData, UINT32 u4Size,
                                       UINT8** ppucDestData, UINT32 *pu4DestSize,UINT32 *pu4Width);

/**Change VDEC to PAUSE mode.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Pause(UCHAR ucEsId);

EXTERN MT_RESULT_T MTVDEC_ResetWFDInfo(UCHAR ucEsId);

/**Change VDEC to STOP mode.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Stop(UCHAR ucEsId);

/**Change VDEC to STOP mode and free resource,it is matched with function MTVDEC_DecodeIFrame.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_StopIFrame(UCHAR ucEsId);


/**VDEC Rm Set Info
*@param ucEsId                     ES id.
*@param eVdecSetType         set type.
*@param pvSetInfo                Set Info.
*@param zSetInfoSize            Set Info struct size.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RmSet(UCHAR ucEsId, MTVDEC_SET_T eVdecSetType, VOID *pvSetInfo, UINT16 zSetInfoSize);

/**Get video resolution and information.
*@param ucEsId                     ES id.
*@param prVdecInfo                 Bitstream header information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetInfo(UCHAR ucEsId, MTVDEC_HDR_INFO_T* prVdecInfo);

EXTERN MT_RESULT_T MTVDEC_GetDelayTime(UCHAR ucEsId, MTVDEC_HDR_INFO_T* prVdecInfo);

EXTERN MT_RESULT_T MTVDEC_GetWFDErrInfo(UCHAR ucEsId, MTVDEC_WFD_DECODE_ERROR_T* prWFDErrInfo);

/**Get deblocking information.
*@param ucEsId                     ES id.
*@param prDbkInfo                  Frame/field deblocking information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetDbkInfo(UCHAR ucEsId, MTVDEC_DBK_INFO_T* prDbkInfo);
    
/**Set AV sync mode
*@param ucEsId                     ES id.
*@param ucMode                     AV sync mode.
*@param ucStcId                     STC id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetAvSynMode(UCHAR ucEsId, MTAV_SYNC_MODE_T eMode);
    
/**Set AV sync mode and STC id.
*@param ucEsId                     ES id.
*@param ucMode                     AV sync mode.
*@param ucStcId                     STC id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetAvSynMode2(UCHAR ucEsId, MTAV_SYNC_MODE_T eMode, UCHAR ucStcId);

/**Get STC value.
*@param ucEsId                     ES id.
*@param pu8Stc                     Stc value.(90K)
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetStc(UCHAR ucEsId, UINT64 *pu8Stc);

/** Check VDEC decode status.
*@param ucEsId                     ES id.
*@param prDecStatus                Video decoder status.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetDecStatus(UCHAR ucEsId, MTVDEC_DEC_STATUS_T *prDecStatus);


/**Register VDEC resource manager callback function,
*@param MTVDEC_PFN_RM_CB pfRmCb: callback function
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/

EXTERN MT_RESULT_T MTVDEC_RegRmCb(MTVDEC_PFN_RM_CB pfRmCb);


/**Register VDEC decode error callback function,
*    when the time of continuous decode error larger than u4Duration,it will trigger the callback function
*@param pfDecErrCb                 Decode error callback function.
*@param u4Duration                 Duration of continuous decode error (ms).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegDecErrCb(MTVDEC_PFN_DECERR_CB pfDecErrCb, UINT32 u4Duration);

/**Register VDEC frame type callback function,it is only for DTV codec(MPEG1/2,H264,AVS)
*    when VDEC parsed the frame type,it will trigger the callback function
*@param pfPicTypeCb                 Decode picture type callback function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegFrameCb(MTVDEC_PFN_FRAME_CB pfFrameCb);


/**Register VDEC pictrue information callback function.
*@param pfPicInfoCb                 Decode picture information callback function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegPicInfoCb(MTVDEC_PFN_PICINFO_CB pfPicInfoCb);



/**Register VDEC status callback function.
*@param pfStatusCb                 Decode status callback function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegStatusCb(MTVDEC_PFN_STATUS_CB pfStatusCb);

/**Register digital user data callback function.
*@param pfUserDataCb               Digital user data callback function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegUserDataCb(MTVDEC_PFN_USERDATA_CB pfUserDataCb);

/**Unregister callback function.
*@param eCbType               Unregister callback type
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_UnRegCb(MTVDEC_DEC_CB_TYPE eCbType);


/**Enable digital user data.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_StartUserData(UCHAR ucEsId);

/**Disable digital user data.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_StopUserData(UCHAR ucEsId);

/**Set decoding speed,it used together with MTAL PVR,it could not used alone
*@param ucEsId                     ES id.
*@param eSpeed                     speed
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
MT_RESULT_T MTVDEC_SetSpeed(UCHAR ucEsId, MTVDEC_DEC_SPEED_T eSpeed);

/**It used together with MTAL PVR,it could not used alone
* Frame advance is a feature to single-step decoding frame by frame.
* It means that 1 frame forward mode(1 frame decoding and stop).
* It is dependend on the video decoder HW performance.
*@param ucEsId                     ES id.
*@param fgSetFrameAdvance          Is advance a frame or not?
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
MT_RESULT_T MTVDEC_SetFrameAdvance(UCHAR ucEsId, BOOL fgSetFrameAdvance);

/**Flush ES data,it used together with MTAL PVR,it could not used alone
* Reset video decoder. It flushes the video decoder.
* Flush the video ES data buffer in video digital decoder.
*@param ucEsId                     ES id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
MT_RESULT_T MTVDEC_SetFlushEsData(UCHAR ucEsId);

/**Set Decode Mode,usually used for fast forward.It used together with MTAL PVR,it could not used alone
*@param ucEsId                     ES id.
*@param eMode                      Decode mode.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
MT_RESULT_T MTVDEC_SetDecodeMode(UCHAR ucEsId, MTVDEC_DEC_MODE_T eMode);

#ifdef CC_ITIMING_ALWAYS
/**Display by Interlaced
*@param ucEsId                     ES id.
*@param fgIsInterlace              Display by interlace or not
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetFixFHDDisplay(UCHAR ucEsId, BOOL fgIsInterlace);
#endif

/**Set IPTV mode
*@param ucEsId                     ES id.
*@param fgIPTVMode                 IPTV mode.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
MT_RESULT_T MTVDEC_SetIPTVMode(UCHAR ucEsId, BOOL fgIPTVMode);
EXTERN MT_RESULT_T  MTVDEC_TryLockValidSrc(UCHAR *pucEsId);
EXTERN MT_RESULT_T  MTVDEC_UnlockValidSrc(UCHAR ucEsId);

/** Send CLI command to driver
*@param pCmdStr                    command string
*@param u4StrLen                   command lenght
*/
EXTERN MT_RESULT_T MTVDEC_SendCliCommand(UCHAR *pCmdStr,UINT32 u4StrLen);

/**MTVDEC_SetFreeze
*@param ucEsId                     ES id.
*@param eMode                      Decode mode.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetFreeze(UCHAR ucEsId);


EXTERN MT_RESULT_T MTHEVC_ChgYUV2YCbCr(MTVDEC_FB_INFO_T *pFBInfo);

/**Set VDEC Play MM mode or not (VDEC has MM and DTV modes)
*@param  ucEsId                    Es id.
*@param  fgPlayMM                  MM or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PlayMM(UCHAR ucEsId, BOOL fgPlayMM);

/**Register callback to VDEC module for general info callback.
*@param  ucEsId                    Es id.
*@param  u4Tag                     tag.
*@param  pfGeneralCb               callback function address.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegGeneralCb(UCHAR ucEsId, UINT32 u4Tag, MTVDEC_PFN_GENERAL_CB pfGeneralCb);

#ifdef MTVDEC_VIDEO_ES_INPUT_SUPPORT
/** Init a DMX device to  parse and move ES data to VFIFO
*@param  ucEsId                    Es id.
*@param  pu1DmxId                  return the inited DMX id
*@param  pu1VideoPidx              return the related video PIdx
*@retval MTR_OK                    Success.
*@retval other                     Fail.
*/
EXTERN MT_RESULT_T MTVDEC_AllocInput(UCHAR ucEsId, UINT8 *pu1DmxId, UINT8 *pu1VideoPidx);

/** release a DMX device that opened for parsing and moving ES data to VFIFO
*@param  ucEsId                    Es id.
*@param  u1DmxId                   DMX instance
*@param  u1VideoPidx               related video PIDX
*@retval MTR_OK                    Success.
*@retval others                    fali.
*/
EXTERN MT_RESULT_T MTVDEC_ReleaseInput(UCHAR ucEsId, UINT8 u1DmxId, UINT8 u1VideoPidx);

/** Get the avaliad Input buffer
*@param  ucEsId                    Es id.
*@param  pu1Addr                   return the WP
*@param  pu4Size                   return the avaliable size
*@parm   pu4TotalSize              return the input buffer's max size
*@retval MTR_OK                    Success
*@retval others                    Fail
*/
EXTERN MT_RESULT_T MTVDEC_GetInputBuf(UCHAR ucEsId, UINT8 **pu1Addr, UINT32 *pu4Size, UINT32 *pu4TotalSize);

/** put data 
*@param  ucEsId                    Es id.
*@param  pu1Addr                   data addr
*@param  u4Size                    data size
*@retval MTR_OK                    Success.
*@retval other                     Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PutInputBuf(UCHAR ucEsId, UINT8 *pu1Addr, UINT32 u4Size, BOOL fgEof);
#endif // MTVDEC_VIDEO_ES_INPUT_SUPPORT

/**Set VDEC Play but not display this frame
*@param  ucEsId                    Es id.
*@param  fgNotDisplay              display or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PlayNotDisplay(UCHAR ucEsId, BOOL fgNotDisplay);

/**Play VDEC module for MWIF.
*@param  ucEsId                    Es id.
*@param  eVdecFmt                  Codec.
*@param  prPlayInfo                MM or DTV.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_Play2(UCHAR ucEsId, MTVDEC_FMT_T eVdecFmt, MTVDEC_PLAYBACK_INTO_T *prPlayInfo);

/**Allocate Play-I Frame buffer in VDEC.
*@param  ucEsId                    Es id.
*@param  prIFrameBuf               Buffer info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_AllocIFrameBuf(UCHAR ucEsId, MTVDEC_DEC_I_FRAME_BUFF_T* prIFrameBuf);
/**Free Play-I Frame buffer in VDEC.
*@param  ucEsId                    Es id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_FreeIFrameBuf(UCHAR ucEsId);
/**Put I frmae data into VDEC.
*@param  ucEsId                    Es id.
*@param  prIFrameBuf               Buffer info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetIFrameBuf(UCHAR ucEsId, MTVDEC_DEC_I_FRAME_BUFF_T* prIFrameBuf);

/**Trigger VDEC Decode I Frame .
*@param  ucEsId                    Es id.
*@param  prIFrameBuf               Buffer info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetIFrameDec(UCHAR ucEsId, MTVDEC_DEC_I_FRAME_BUFF_T* prIFrameBuf);

/*
 NOTE: This function is not a prefect one (I'm a lazy guy!). To use this function (Must use with other Iframe process functions) rightly, you should do it as below:
 1. Before calling this function, a Cb handler must be registered by AP. You can call MTVDEC_RegGeneralCb to do it
 2. Fill the MTVDEC_THUMBNAIL_INFO_T currectly, you can leave MTVDEC_THUMBNAIL_INFO_T.pucCanvasBuffer un-setted
 3. Call this function
 4. This function will return direclty after send cmd to Driver, so we can not make sure that the scaling action has done after the returning of this function
 5. This function will return a scaled data start address (stored in MTVDEC_THUMBNAIL_INFO_T.pucCanvasBuffer), 
    AP must waiting the thumbnail done event (or, if failed, the thumbnail error event), and then copy the result from MTVDEC_THUMBNAIL_INFO_T.pucCanvasBuffer to you destination buffer
    the data size can be got by u4ThumbnailHeight*u4ThumbnailWidth*4
 */
/** After decoded a I frame (by MTVDEC_SetIFrameDec), calling this function to scaling it 
*@param  ucEsId                    Es id.
*@param  u2SrcId                   The AP's Id
*@retval prDstInfo                 Scaling parameter (Please read the note carefully before use it).
*@retval return                    ... ...
*/
MT_RESULT_T MTVDEC_GetIFrameScaledData(UCHAR ucEsId, UINT16 u2SrcId, MTVDEC_THUMBNAIL_INFO_T *prDstInfo);

/**Get Decoder count .
*@param pu4DecNun                  decoder count return value
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetDecoderNum(UINT32* pu4DecNun);

#ifdef SYS_DTV_FRZ_CHG_SUPPORT
EXTERN void vRegPicInfoCallback(VOID);
#endif

#ifdef __cplusplus
}
#endif

#endif //MT_VDEC_H
