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
 * $RCSfile: mtswdmx.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtswdmx.h
 *  This header file declares exported APIs of Software Demux (SWDMX) module,
 *  which is used to control SWDMX to demux A&V data of all MM container.
 */

#ifndef MT_SWDMX_H
#define MT_SWDMX_H

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

#define ES_ID_0     0                       ///< Instance ID 0
#define ES_ID_1     1                       ///< Instance ID 1

#define MTSWDMX_ES_ID_MAX   5               ///< How many SWDMX instances are supported

#define MTSWDMX_PRIMARY_SOURCE      0x00    ///< The 1st SWDMX ID
#define MTSWDMX_SECONDARY_SOURCE    0x01    ///< The 2nd SWDMX ID
#define MTSWDMX_THIRD_SOURCE        0x02    ///< The 3rd SWDMX ID
#define MTSWDMX_4th_SOURCE          0x03    ///< The 4th SWDMX ID
#define MTSWDMX_5th_SOURCE          0x04    ///< The 5th SWDMX ID
#define MTSWDMX_UNKNOWN_SOURCE      0xFF    ///< Unknown SWDMX ID


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/**The container type of MM file
*/
typedef enum
{
    MTSWDMX_FMT_UNKNOWN,                ///< Container type is UNKNOWN
    MTSWDMX_FMT_AVI,                    ///< Container type is DAT
    MTSWDMX_FMT_MPEG1_DAT,              ///< Container type is MEPG2_PS
    MTSWDMX_FMT_MPEG2_PS,               ///< Container type is MPEG2_TS
    MTSWDMX_FMT_MPEG2_TS,               ///< Container type is MPEG2_TS (188 ts)
    MTSWDMX_FMT_MPEG2_TS_192,           ///< Container type is MPEG2_TS (192 ts, time case)
    MTSWDMX_FMT_MPEG2_TS_ZERO_192,      ///< Container type is MPEG2_TS (4 byte 192 ts)
    MTSWDMX_FMT_MPEG2_TS_ENCRYPT_192,   ///< Container type is MPEG2_TS (encrypted)
    MTSWDMX_FMT_MPEG2_TS_130,           ///< Container type RVU 130 
    MTSWDMX_FMT_MPEG2_TS_134,           ///< Container type RVU 134 
	MTSWDMX_FMT_MPEG2_TS_204,
    MTSWDMX_FMT_MPEG2_TS_TIME_SHIFT,    ///< Container type is MPEG2_TS (time shift 192 ts)
    MTSWDMX_FMT_VC1_ES,                 ///< Container type is VC1 video ES
    MTSWDMX_FMT_MPEG2_VIDEO_ES,         ///< Container type is MPEG2 video ES
    MTSWDMX_FMT_MPEG4_VIDEO_ES,         ///< Container type is MPEG4 video ES
    MTSWDMX_FMT_H264_VIDEO_ES,          ///< Container type is H264 video ES
    MTSWDMX_FMT_AVS_VIDEO_ES,           ///< Container type is AVS video ES
    MTSWDMX_FMT_RAW_AUDIO_ES,           ///< Container type is RAW audio (last one for ES, should not change this order)
    MTSWDMX_FMT_MP3_AUDIO_ES,           ///< Container type is MP3
    MTSWDMX_FMT_VC1_WMV,                ///< Container type is WMV
    MTSWDMX_FMT_WMA_AUDIO_ES,           ///< Container type is WMA
    MTSWDMX_FMT_MP4,                    ///< Container type is MP4
    MTSWDMX_FMT_M4A,                    ///< Container type is M4A
    MTSWDMX_FMT_MKV,                    ///< Container type is MKV
    MTSWDMX_FMT_RM,                     ///< Container type is RM
    MTSWDMX_FMT_FLV,                    ///< Container type is FLV
    MTSWDMX_FMT_CMPB,                   ///< Container type is MTK private container for CMPB
    MTSWDMX_FMT_ES_WITH_PTS,            ///< Container type is elementary stream with PTS
    MTSWDMX_FMT_OGM,                    ///< Container type is OGM
    MTSWDMX_FMT_OGG_AUDIO_ES,           ///< Container type is OGG
    MTSWDMX_FMT_APE_AUDIO_ES,           ///< Container type is APE
    MTSWDMX_FMT_H265_VIDEO_ES           ///< Container type is H265 video ES
}   ENUM_MTSWDMX_FMT_T;



/**Used in pre-buffer threshold setting.
When set pre-buffer threshold to indicate buffer full, the threshold can be BYTE or TIME.
So we also must tell SWDMX the current buffer mode is BYTE or TIME.
*/
typedef enum
{
    MTSWDMX_BUF_MODE_DEFAULT,   ///< Pre-buffer mode is not enabled
    MTSWDMX_BUF_MODE_TIME,      ///< Pre-buffer mode is TIME
    MTSWDMX_BUF_MODE_BYTE,      ///< Pre-buffer mode is BYTE
    MTSWDMX_BUF_MODE_MAX        ///< Invalide mode
} ENUM_MTSWDMX_BUFFER_TYPE_T;



/**The video codec format*/
typedef enum{
    ENUM_MTSWDMX_VDEC_UNKNOWN,          ///< Unknown codec
    ENUM_MTSWDMX_VDEC_MPEG1_MPEG2,      ///< MPEG1/MPEG2 codec
    ENUM_MTSWDMX_VDEC_DX311,            ///< DivX311 codec
    ENUM_MTSWDMX_VDEC_MPEG4,            ///< MPEG4 codec
    ENUM_MTSWDMX_VDEC_H264,             ///< H264 codec
    ENUM_MTSWDMX_VDEC_MVC,              ///< MVC codec
    ENUM_MTSWDMX_VDEC_VC1,              ///< VC1 codec
    ENUM_MTSWDMX_VDEC_WMV7,             ///< WMV7 codec
    ENUM_MTSWDMX_VDEC_WMV8,             ///< WMV8 codec
    ENUM_MTSWDMX_VDEC_WMV9,             ///< WMV9 codec
    ENUM_MTSWDMX_VDEC_MJPEG,            ///< Motion JPEG codec
    ENUM_MTSWDMX_VDEC_RV,               ///< RV codec
    ENUM_MTSWDMX_VDEC_H263,             ///< H263codec
    ENUM_MTSWDMX_VDEC_VP6,              ///< VP6 codec
    ENUM_MTSWDMX_VDEC_VP8,              ///< VP8 codec
    ENUM_MTSWDMX_VDEC_RAW_NV12,         ///< RAW codec
    ENUM_MTSWDMX_VDEC_AVS,              ///< AVS codec
    ENUM_MTSWDMX_VDEC_MULTITRACK,       ///< Multi-Track codec
    ENUM_MTSWDMX_VDEC_H265,
    ENUM_MTSWDMX_VDEC_MAX
}ENUM_MTSWDMX_VDEC_T;



/**Audio decoder format.*/
typedef enum{
    ENUM_MTSWDMX_ADEC_UNKNOWN = 0,      ///< Unknown codec
    ENUM_MTSWDMX_ADEC_MPEG,             ///< MPEG codec
    ENUM_MTSWDMX_ADEC_AC3,              ///< AC3 codec
    ENUM_MTSWDMX_ADEC_PCM,              ///< PCM codec
    ENUM_MTSWDMX_ADEC_MP3,              ///< MP3 codec
    ENUM_MTSWDMX_ADEC_AAC,              ///< AAC codec
    ENUM_MTSWDMX_ADEC_DTS,              ///< DTS codec
    ENUM_MTSWDMX_ADEC_WMA,              ///< WMA codec
    ENUM_MTSWDMX_ADEC_RA,               ///< RA codec
    ENUM_MTSWDMX_ADEC_HDCD,             ///< HDCD codec
    ENUM_MTSWDMX_ADEC_MLP,              ///< MLP codec
    ENUM_MTSWDMX_ADEC_MTS,              ///< MTS codec
    ENUM_MTSWDMX_ADEC_A2,               ///< A2 codec
    ENUM_MTSWDMX_ADEC_PAL,              ///< PAL codec
    ENUM_MTSWDMX_ADEC_FMFM,             ///< FM codec
    ENUM_MTSWDMX_ADEC_NICAM,            ///< NICAM codec
    ENUM_MTSWDMX_ADEC_TTXAAC,           ///< TTXAAC codec
    ENUM_MTSWDMX_ADEC_DETECTOR,         ///< Detector codec
    ENUM_MTSWDMX_ADEC_VORBIS,           ///< Vorbis codec
    ENUM_MTSWDMX_ADEC_MINER             ///< Miner codec
}ENUM_MTSWDMX_ADEC_T;



/**Set/Get information to/from SWDMX.*/
typedef enum _MTSWDMX_SET_DECODER_TYPE
{
    MTSWDMX_SET_VIDSEQHEADER,           ///< Set video sequence header data
    MTSWDMX_SET_VIDEOTYPE,              ///< Set video codec
    MTSWDMX_SET_SUBVIDEOTYPE,           ///< Set sub-video codec (for 3D multi-track case)
    MTSWDMX_SET_VIDEO2TYPE,
    MTSWDMX_SET_AUDIOTYPE,              ///< Set audio codec
    MTSWDMX_SET_SYSTEMINFO,
    MTSWDMX_ENABLE_STREAM,              ///< Enable the assigned video or audio track
    MTSWDMX_DISABLE_STREAM,             ///< Disable the assigned video or audio track
    MTSWDMX_SET_RANGECALLBACK,          
    MTSWDMX_SET_RANGECALLBACKEX,        ///< Set callback function of RangeNotification
    MTSWDMX_SET_CHK_PSI_BUF_SIZE,       ///< If TRUE, tells SWDMX to send PSI data only when PSI buffer is not full
    MTSWDMX_TOTAL_DURATION,
    MTSWDMX_SET_FEEDER_TEST_FUNCTION,
    MTSWDMX_SET_SUBTITLECALLBACK,
    MTSWDMX_GET_CURRENT_POSITION,       ///< Get SWDMX current parsed file offset
    MTSWDMX_GET_FILE_OFFSET,
    MTSWDMX_GET_IS_TRICK,               ///< Get if the file is trickable or not
    MTSWDMX_CONTAINER_TYPE,             ///< Get container type
    MTSWDMX_GET_INTERNAL_INFO,
    MTSWDMX_SET_REC_BUF_RANGE,          ///< Set time-shift recorder buffer range
    MTSWDMX_PRINT_REC_BUF_STATUS,
    MTSWDMX_PRINT_INTERNAL_STATUS,
    MTSWDMX_SET_MONITOF_LBA,            ///< Set monitor LBA for time-shift record, if current playback LBA matches, it will call range-callback to notify MW
    MTSWDMX_GET_CURRENT_TICK,           ///< Get current tick num
    MTSWDMX_GET_CURRENT_LBA,            ///< Get current LBA of time-shift record
    MTSWDMX_SET_NETFLIX_STREAM_ID,
    MTSWDMX_SET_NETFLIX_EOS,
    MTSWDMX_GET_CURRENT_TIME,
    MTSWDMX_PID_INDEX_START,            ///< Set PID index start
    MTSWDMX_SET_TPT_VIDSEQHEADER,       ///< Set video sequence header data for divx plus
    MTSWDMX_SET_AOUT_ENABLE,
    MTSWDMX_SET_EOS,
    MTSWDMX_SET_VIDEO_DECRYPT,          ///< Tells SWDMX how to decrypt the video data
    MTSWDMX_SET_AUDIO_DECRYPT,          ///< Tells SWDMX how to decrypt the audio data
    MTSWDMX_SET_AUDIO2_DECRYPT,
    MTSWDMX_SET_AUDIO3_DECRYPT,
    MTSWDMX_SET_VID_PID_IDX,
    MTSWDMX_SET_AUD_PID_IDX,
    MTSWDMX_SET_PCR_PID_IDX,
    MTSWDMX_GET_STC_OFFSET,             ///< Get the PTS of first packet
    MTSWDMX_SET_VDEC_ID,                ///< Set which VDEC id belongs to this SWDMX
    MTSWDMX_SET_VDEC2_ID,               ///< Set which VDEC id belongs to this SWDMX (for 3D dual stream)
    MTSWDMX_SET_ADEC_ID,                ///< Set which ADEC id belongs to this SWDMX
    MTSWDMX_SET_STC_ID,                 ///< Set which STC id belongs to this SWDMX
    MTSWDMX_SET_B2R_ID,                 ///< Set which B2R id belongs to this SWDMX
    MTSWDMX_SET_DMX_ID,                 ///< Set which DMX id belongs to this SWDMX
    MTSWDMX_SET_SRC_TYPE,               ///< Set which buffer is used according to this track
    MTSWDMX_GET_INTERNAL_BUF,
    MTSWDMX_SET_PLAYBACK_THRESHOLD,     ///< Set pre-buffer threshold
    MTSWDMX_GET_PLAYBACK_THRESHOLD,
    MTSWDMX_GET_TIME_TO_BYTES_INFO,     ///< Translate from time to byte
    MTSWDMX_SET_VID_SCRAMBLE_NFY,       ///< Set callback to indicate the video data is scrambled
    MTSWDMX_SET_AUD_SCRAMBLE_NFY,       ///< Set callback to indicate the audio data is scrambled
    MTSWDMX_SET_SYSTEM_B,
    MTSWDMX_GET_AUDIO_ACTIVE_PIDX,
    MTSWDMX_GET_VIDEO_PIDX,             ///< Get current active video pidx
    MTSWDMX_GET_AUDIO_PIDX,             ///< Get current active audio pidx
    MTSWDMX_SET_BAD_INTERLEAVED_INFO,   ///< Tells SWDMX if this file is bad-interleave or not
    MTSWDMX_GET_BAD_INTERLEAVED_INFO,   ///< Get if this file is bad-interleaved or not
    MTSWDMX_SET_HDMVC_INFO,             ///< Tells SWDMX if this file is HDMVC or not
    MTSWDMX_GET_HDMVC_INFO,             ///< Get if this file is HDMVC or not
    MTSWDMX_SET_DBGINFO,
    MTSWDMX_GET_DBGINFO,
    MTSWDMX_SET_MM_DECRYPT,             ///< If data is encrypted by MLN or PDCF, tells SWDMX how to decrypt it
    MTSWDMX_GET_MM_SRC_TYPE,            ///< Get source type (defined in MM_SRC_TYPE_T)
    MTSWDMX_SET_VID_CHG_CALLBACK,       ///< register video stream id change callback
    MTSWDMX_SET_AUD_CHG_CALLBACK,       ///< register audio stream id change callback
    MTSWDMX_SET_TYPE_VID_PID_CHG_DONE,  ///< mw notify video stream id change done
    MTSWDMX_SET_TYPE_AUD_PID_CHG_DONE,  ///< mw notify audio stream id change done
    MTSWDMX_SET_TYPE_VID_CODEC_CHG_DONE,///< mw notify video codec change done
    MTSWDMX_SET_TYPE_AUD_CODEC_CHG_DONE,///< mw notify audio codec change done    
    MTSWDMX_SET_FLUSHFEEDER,            ///< flush
    MTSWDMX_SET_DURATION,               ///< Set file duration to swdmx
    MTSWDMX_SET_FILE_SZ_UPDATE,
    MTSWDMX_SET_TYPE_PUSH_CHANGE_AUDIO,
    MTSWDMX_SET_MAX
} MTSWDMX_SET_DECODER_TYPE;



/**Stream type of current track.*/
typedef enum
{
    MTSWDMX_STRM_TYPE_UNKNOWN,
    MTSWDMX_STRM_TYPE_VID,              ///< Track if video
    MTSWDMX_STRM_TYPE_VID2,             ///< 2nd video track of dual stream
    MTSWDMX_STRM_TYPE_AUD,              ///< Track if audio
    MTSWDMX_STRM_TYPE_AUD2,             ///< 2nd audio track of dual stream
    MTSWDMX_STRM_TYPE_AUD3,
    MTSWDMX_STRM_TYPE_SUBTITLE,         ///< Track is subtitle
    MTSWDMX_STRM_TYPE_PCR,              ///< Track is PCR
    MTSWDMX_STRM_TYPE_MAX
} ENUM_MTSWDMX_STRM_TYPE_T;



/**Information of current range.*/
typedef struct MTSWDMX_RANGE_INFO
{
    UINT32 u4CurRangeID;                ///< Current range ID
    UINT64 u8CurRangePTS;               ///< Current range PTS
    UINT32 u4QRangeID;                  ///< Queued range ID
    UINT64 u8QRangePTS;                 ///< Ququed range PTS
} MTSWDMX_RANGE_INFO_T;



/**Indicate which condition it is from SWDMX callback*/
typedef enum
{
    MTSWDMX_COND_ERROR = -1,
    MTSWDMX_COND_CTRL_DONE,             ///< PAUSE or STOP cmd is done
    MTSWDMX_COND_SUBTITLE
}   MTSWDMX_COND_T;



/**Playback mode*/
typedef enum
{
   MTSWDMX_PLAY_MODE_NORMAL,            ///< SWDMX will handle all I/P/B frames
   MTSWDMX_PLAY_MODE_IFRAME             ///< SWDMX will only handle I frames
} MTSWDMX_PLAY_MODE_T;



/**Range status which SWDMX will report to MW*/
typedef enum
{
    MTSWDMX_RANGE_DONE = 1,             ///< Finished parsing the range
    MTSWDMX_RANGE_ABORT,                ///< Stop this range
#ifdef TIME_SHIFT_SUPPORT
    MTSWDMX_MONITOR_LBA_ARRIVAL,        ///< Current playback position reaches monitored LBA (pass the monitor LBA by ui4_data_1)
    MTSWDMX_OUT_OF_SAFE_RANGE_START,    ///< Current playback position is outside the safe start (pass the current LBA by ui4_data_1)
    MTSWDMX_OUT_OF_SAFE_RANGE_END,      ///< Current playback position is outside the safe end (pass the current LBA by ui4_data_1)
    MTSWDMX_REACH_VALID_RANGE_START,    ///< Current playback position reaches range start (pass the current LBA by ui4_data_1)
    MTSWDMX_REACH_VALID_RANGE_END,      ///< Current playback position reaches range end (pass the current LBA by ui4_data_1)
    MTSWDMX_SIGNAL_Y_TO_N,              ///< Pass the 1st tick number of section w/o signal
    MTSWDMX_SIGNAL_N_TO_Y,              ///< Pass the 1st tick number of section with signal
    MTSWDMX_BAD_TICK_Y_TO_N,            ///< Storage ERROR
    MTSWDMX_BAD_TICK_N_TO_Y,            ///< Storage OK
    MTSWDMX_DATA_READ_ERROR,            ///< Request input data failed
    MTSWDMX_INTERNAL_ERROR,             ///< Internal flow control error
#endif /* TIME_SHIFT_SUPPORT */
    MTSWDMX_RANGE_SEEK_DONE,            ///< Seek is done
    MTSWDMX_RANGE_SEEK_ERROR,           ///< Error occurs during seek
    MTSWDMX_RANGE_SEEK_NO_DATA,         ///< No data during seek/ step
    MTSWDMX_RANGE_BUFF_READY,           ///< Buffer data is underflow
    MTSWDMX_RANGE_BUFF_UNDERFLOW,       ///< Buffer is underflow
#ifndef DRV_NO_PRE_PARSING
    MTSWDMX_RANGE_PARSING_MODE,
    MTSWDMX_RANGE_PARSING_MODE_DONE,
#endif
    MTSWDMX_RANGE_MAX /* last one */
} MTSWDMX_RANGE_COND_T;



/**Function prototype that SWDMX will use to report flow control status to MW*/
typedef void (*PFN_MTSWDMX_NFY_FCT) (
    void*               pvNfyTag,
    MTSWDMX_COND_T      eNfyCond,
    UINT32              u4Data1,
    UINT32              u4Data2
);



/**Function prototype that SWDMX will use to report flow control status to MW*/
typedef struct
{
    void*  pvTag;
    PFN_MTSWDMX_NFY_FCT  pfSwdmxNfy;
} MTSWDMX_NFY_INFO_T;



/**Function prototype that SWDMX will use to report data scramble to DMX*/
typedef void (*PFN_MTDMX_NFY_FCT) (
    UINT8                   u1Pidx,
    MTDMX_NOTIFY_CODE_T     eCode,
    UINT32                  u4Data,
    const void*             pvNotifyTag
);



/**Function prototype that SWDMX will use to report range status to MW*/
typedef BOOL (*PFN_MTSWDMX_RANGE_EX_NFY_FCT)(
    VOID*            pv_nfy_tag,
    MTSWDMX_RANGE_COND_T  e_nfy_cond,
    UINT32           ui4_data_1,
    UINT32           ui4_data_2,
    UINT32           ui4_data_3
);

typedef struct 
{
    UINT32                          ui4_strm_pid;  //video/audio stream id
}MTSWDMX_MM_PID_CHG_T;

/**Function prototype that SWDMX will use to notify mw pid change*/
typedef BOOL (*PFN_MTDMX_PID_CHG_NFY_FCT) (VOID*  pv_nfy_tag,
                                           UINT32  ui4_data_1,
                                           UINT32  ui4_data_2,
                                           UINT32  ui4_data_3
                                           );

/**sturct that SWDMX will use it to notify mw pid change*/
typedef struct 
{
    VOID*  pv_tag;
    PFN_MTDMX_PID_CHG_NFY_FCT  pf_swdemux_pid_chg_nfy;
} MTSWDEMUX_PID_CHG_NFY_INFO_T;
/* enum type for stream type */
typedef enum
{
    MTST_UNKNOWN = -1,  /* Must be set to '-1' else I loose an entry in the bit mask. */
    MTST_AUDIO,
    MTST_VIDEO,
    MTST_CLOSED_CAPTION,
    MTST_ISDB_CAPTION,
    MTST_ISDB_TEXT,
    MTST_TELETEXT,
    MTST_SUBTITLE,
    MTST_DATA,
    MTST_BYPASS,
    MTST_MM_SUBTITLE,
    MTST_RCRD_STRM,
    MTST_GINGA_STOP_AUDIO,
    MTST_GINGA_STOP_VIDEO
}   MTSTREAM_TYPE_T;

typedef  UINT8  MTVID_ENC_T;    /**< Video Encoding type. */
typedef  UINT8  MTAUD_ENC_T;    /**< Audio Encoding type. */

typedef struct
{
    UINT32             ui4_aud_strm_id;       ///< PID
    UINT32             ui4_vid_strm_id;       ///< PID    
    MTVID_ENC_T        e_vid_enc;             // video type
    MTAUD_ENC_T        e_aud_enc;             // audio type
} MTBUF_AGT_CTRL_IBC_PARAM_STRM_INFO_T;                                           
//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Set verious information to SWDMX, we can pass at most 3 parameters to SWDMX at the same time.
Please see MTSWDMX_SET_DECODER_TYPE for the detail of each information.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - What kind of information we are passing to SWDMX.
                    The _SET_ field defined in MTSWDMX_SET_DECODER_TYPE.
*@param u4Param1    - The 1st parameter of the information. If it's not used in your information, you can just pass 0.
*@param u4Param2    - The 2nd parameter of the information. If it's not used in your information, you can just pass 0.
*@param u4Param3    - The 3rd parameter of the information. If it's not used in your information, you can just pass 0.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see MTSWDMX_SET_DECODER_TYPE
*/
EXTERN MT_RESULT_T MTSWDMX_SetInfo(UINT8 u1SrcId, UINT8 u1Type,UINT32 u4Para1,UINT32 u4Para2,UINT32 u4Para3);



/**Get verious information to SWDMX, we can get at most 3 parameters from SWDMX at the same time.
Please see MTSWDMX_SET_DECODER_TYPE for the detail of each information.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - What kind of information we are going to get from SWDMX.
                    The _GET_ field defined in MTSWDMX_SET_DECODER_TYPE.
*@param pu4Para1    - The 1st parameter of the information. If it's not used in your information, you can just pass NULL.
*@param pu4Para2    - The 2nd parameter of the information. If it's not used in your information, you can just pass NULL.
*@param pu4Para3    - The 3rd parameter of the information. If it's not used in your information, you can just pass NULL.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see MTSWDMX_SET_DECODER_TYPE
*/
EXTERN MT_RESULT_T MTSWDMX_GetInfo(UINT8 u1SrcId, UINT8 u1Type,UINT32* pu4Para1,UINT32* pu4Para2,UINT32* pu4Para3);



/**This will PAUSE the execution of SWDMX, that means SWDMX won't parse/demux A/V data to VDEC any more.
When MTSWDMX_Play() is called, SWDMX will resume execution.
This is an Async API, that is the API will immediately return when the PAUSE cmd is sent to SWDMX.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_Pause(UINT8 u1SrcId);



/**This will PAUSE the execution of SWDMX, that means SWDMX won't parse/demux A/V data to VDEC any more.
When MTSWDMX_Play() is called, SWDMX will resume execution.
This is a Sync API, that is the API will wait for at most u4WaitTime millisecond until the PAUSE cmd complete.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u4WaitTime  - millisecond. The API will wait for at most u4WaitTime millisecond until the PAUSE cmd complete.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Something wrong during PAUSE or timeout.
*/
EXTERN MT_RESULT_T MTSWDMX_WaitForPause(UINT8 u1SrcId, UINT32 u4WaitTime);



/**Register a notification callback function to SWDMX, such that when async PAUSE(MTSWDMX_Pause) or STOP(MTSWDMX_Stop) cmd is done by SWDMX,
it will call this callback function to notify APP.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param prSwdmxNfyInfo  - Function pointer, which will be called when async Pause/ Stop cmd is done.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see MTSWDMX_NFY_INFO_T
*/
EXTERN MT_RESULT_T MTSWDMX_SetDmxNfy(UINT8 u1SrcId, const MTSWDMX_NFY_INFO_T* prSwdmxNfyInfo);



/**Tells SWDMX what is the container type of input MM file, such that SWDMX will be initialized using correct container type.
The supported container type is defined in ENUM_MTSWDMX_FMT_T.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param eContainerType  - Container type of the input MM file.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see ENUM_MTSWDMX_FMT_T
*/
EXTERN MT_RESULT_T MTSWDMX_SetContainerType(UINT8 u1SrcId, ENUM_MTSWDMX_FMT_T eContainerType);



/**When fastforward or backward, set the speed to SWDMX.
We can trick between BW 1024x ~ FF 1024x
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param i4Speed     - Speed.
                    - If FF 1x, the speed is 1000; FF2x => speed 2000 ... etc
                    - IF BW 1x, the speed is -1000; BW 2x => speed -2000 ... etc
                    - The speed range is between -1024000 ~ 1024000, that is we can trick between BW 1024x ~ FF 1024x.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SetSpeed(UINT8 u1SrcId, INT32 i4Speed);



/**Start execution of SWDMX. It will get data from MM file, and send to ADEC/VDEC after demux.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_Play(UINT8 u1SrcId);



/**This API will flush VDEC fifo, ADEC fifo, and SWDMX.
It is called when trick play is triggered, such as repeatAB, seek, change speed ... etc.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_Flush(UINT8 u1SrcId);



/**A range describes the playback period (start, end), and current PTS.
For most containers, there is only one range. But for some special containers, there are 2 ranges (1 active, 1 pre-parsed).
AP can use this range info to get current PTS, in order to calculate seek target.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param prRangeInfo - Pointer to the range structure.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see MTSWDMX_RANGE_INFO_T
*/
EXTERN MT_RESULT_T MTSWDMX_QueryRangeInfo(UINT8 u1SrcId, MTSWDMX_RANGE_INFO_T* prRangeInfo);



/**SWDMX will seek to u4SeekTime (90K base). The state will keep previous state, if previous state is playing, it will continue to play after seek;
if previous state is stop, it will keep stop after seek.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u4SeekTime  - Seek time, 90K base.
*@param pu8FilePos  - Driver will fill this field as the file offset of the seek time
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SeekTime(UINT8 u1SrcId, UINT32 u4SeekTime, UINT64* pu8FilePos);



/**SWDMX will seek to u8SeekPos (byte-base). The state will keep previous state, if previous state is playing, it will continue to play after seek;
if previous state is stop, it will keep stop after seek. u8SeekPos and u8SeekPosI should both set to the same value.
This API is used for MPEG2 TimeShift and Raw audio ES.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u8SeekPos   - Seek to the file offset, byte-base.
*@param u8SeekPosI  - Seek to the file offset, byte-base. This value should be the same as u8SeekPos
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SeekPos(UINT8 u1SrcId, UINT64 u8SeekPos, UINT64 u8SeekPosI);



/**prPosition points to the data structure of START_POS_INFO_T, and its member ui8_i_frame_position means the i-frame file offset,
and member ui8_pts_info means we should start display from which PTS.
This API will start decodign from ui8_i_frame_position, and will only start display when PTS is larger than ui8_pts_info.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param prPosition  - points to the data structure of START_POS_INFO_T.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_RenderFromPos(UINT8 u1SrcId, VOID *prPosition);



/**prPosition points to the data structure of START_POS_INFO_T, and its member ui8_i_frame_position means the i-frame file offset.
SWDMX will seek to ui8_i_frame_position. The state will keep previous state, if previous state is playing, it will continue to play after seek;
if previous state is stop, it will keep stop after seek.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param prPosition  - points to the data structure of START_POS_INFO_T.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SeekOffset(UINT8 u1SrcId, VOID *prPosition);



/**Add playback range of current file.
A range describes the playback segment of the file (also includes index table if it exists).
Usually it contains the whole file duration; but for some case, like repeat AB, it will only contain a small period of the file.
For most cases, there is only one active range; but for some special container (like .MP4), it needs current range and next range,
to do playback jobs.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param pvRangeInfo - points to the data structure of MM_RANGE_INFO_T.
*@param u4TagID     - The ID of the tag.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_AddRange(UINT8 u1SrcId, VOID* pvRangeInfo, UINT32 u4TagID);



/**Delete playback range of u4TagID of current file.
A range describes the playback segment of the file, usually it contains the whole file duration;
but for some case, like repeat AB, it will only contain a small period of the file.
For most cases, there is only one active range; but for some special container (like .MP4), it needs current range and next range,
to do playback jobs.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param pvRangeInfo - points to the data structure of MM_RANGE_INFO_T.
*@param u4TagID     - The ID of the tag.
*@param fgDelAllRange   - If this value is TRUE, it will delete all ranges.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_DelRange(UINT8 u1SrcId, VOID* pvRangeInfo, UINT32 u4TagID, BOOL fgDelAllRange);



/**Free all the range info memory allocated in driver.
When MTSWDMX_AddRange is called, it will allocate some memory to keep these info.
When MTSWDMX_DelRange is called, the memory will be freed.
And we add one more protection, when playback is finished, MTSWDMX_DelRangeList must be called to ensure all the info memory are freed.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_DelRangeList(UINT8 u1SrcId);



/**Set stream ID of each track (including eStrmType).
For most containers, each track has a unique ID, and each track also has its stream type.
During driver demux the file, it knows the ID of current parsed packet, and use above information to mapping to its stream type.
For 3D multi-track (dual-stream) case, we must set stream ID of the 2 track to driver.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u4StrmID    - The ID of 1st track of eStrmType.
*@param u4StrmSubID - The ID of 2nd track of eStrmType (3D multi-track case)
*@param eStrmType   - Stream type of current track, defined in ENUM_MTSWDMX_STRM_TYPE_T
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see ENUM_MTSWDMX_STRM_TYPE_T
*/
EXTERN MT_RESULT_T MTSWDMX_SetStrmID(UINT8 u1SrcId, UINT32 u4StrmID, UINT32 u4StrmSubID, ENUM_MTSWDMX_STRM_TYPE_T eStrmType);



/**Stop execution of SWDMX.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see ENUM_MTSWDMX_STRM_TYPE_T
*/
EXTERN MT_RESULT_T MTSWDMX_Stop(UINT8 u1SrcId);



/**Lock valid SWDMX instance before use it.
Since we support 2 instance of SWDMX, you must lock one valid instance first before use it, in order to prevent resource conflict.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see ENUM_MTSWDMX_STRM_TYPE_T
*/
EXTERN MT_RESULT_T MTSWDMX_LockValidSrc(UINT8 u1SrcId);



/**Unlock valid SWDMX instance when it is no longer used.
Since we support 2 instance of SWDMX, you must unlock the instance when no longer used, in order to release the resource.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see ENUM_MTSWDMX_STRM_TYPE_T
*/
EXTERN MT_RESULT_T MTSWDMX_UnlockSrc(UINT8 u1SrcId);



/**Tells SWDMX to parse all video frames, or only parse I frames.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param ePlayMode   - All frames or I frames only, defined in MTSWDMX_PLAY_MODE_T
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*@see MTSWDMX_PLAY_MODE_T
*/
EXTERN MT_RESULT_T MTSWDMX_SetPlayMode(UINT8 u1SrcId, MTSWDMX_PLAY_MODE_T ePlayMode);



/**Initialization of SWDMX module, it must be called before use SWDMX.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_Init(VOID);

/**MW notify to swdmx pid change done.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - video | audio type
*@param u4Para1      - 
*@param u4Para2      - 
*@param u4Para3      - 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_PidChgDone(UINT8 u1SrcId, UINT8 u1Type,UINT32 u4Para1,UINT32 u4Para2,UINT32 u4Para3);
/**MW notify to swdmx codec change done.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - video | audio type
*@param u4Para1      - 
*@param u4Para2      - 
*@param u4Para3      - 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_CodecChgDone(UINT8 u1SrcId, UINT8 u1Type,UINT32 u4Para1,UINT32 u4Para2,UINT32 u4Para3);
/**MW register pid change callback to swdmx.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - video | audio type
*@param u4Para1      - 
*@param u4Para2      - 
*@param u4Para3      - 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_RegPidChgCallback(UINT8 u1SrcId, UINT8 u1Type,UINT32 u4Para1,UINT32 u4Para2,UINT32 u4Para3);

/** Call swdmx flush data (feeder & dmx & fifo & fb)
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 
*@param u1Type      - video | audio type
*@param u4Para1      - 
*@param u4Para2      - 
*@param u4Para3      - 
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SetFlushFeederInfo(UINT8 u1SrcId, UINT8 u1Type, UINT32 u4Para1, UINT32 u4Para2, UINT32 u4Para3);
/** set all audio stream id using change audio for ts .
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 

*@param u4Para1     --struct addr.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SetGnrcStreamInfo(UINT8 u1SrcId,UINT32 u4Para1);

/** set hdcp key for wifi display function.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 

*@param u4Para1     --struct addr.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/
EXTERN MT_RESULT_T MTSWDMX_SetHdcpKey(UINT8 u1SrcId,UINT32 u4Para1);
/** enable hdcp key for wifi display function.
*@param u1SrcId     - The instance ID of SWDMX.
                    Since SWDMX supports multi-instance, we should tell the API which instance we are going to control. 

*@param u4Para1     --video or audio type.
*@retval MTR_OK     - Success.
*@retval MTR_NOT_OK - Fail.
*/

EXTERN MT_RESULT_T MTSWDMX_EnableHdcpKey(UINT8 u1SrcId,UINT16 u2Type);



#ifdef __cplusplus
}
#endif

#endif //MT_SWDMX_H
