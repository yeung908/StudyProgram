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
 * $RCSfile: mtfeeder.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtfeeder.h
 *  This header file declares exported APIs of Feeder module.
 */

#ifndef MT_FEEDER_H
#define MT_FEEDER_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"
#include "x_buf_agt.h"

//-----------------------------------------------------------------------------
// Configurations
//-----------------------------------------------------------------------------

#define FEEDER_FIVE_INSTANCE  		///< five instance for skype
#define FEEDER_MULTI_INSTANCE 		///< multi instance function


//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

#define FEEDER_E_OK             (INT32)(0)          ///< Success
#define FEEDER_E_FAIL           (INT32)(-1)         ///< IO error
#define FEEDER_E_INVALID_PARAM  (INT32)(-2)         ///< Get the invalid param
#define FEEDER_E_MEMORY_ALLOC   (INT32)(-3)         ///< Memory allocation fail
#define FEEDER_E_BUFFER_FULL    (INT32)(-4)         ///< Memory buffer is full
#define FEEDER_E_STOP           (INT32)(-5)         ///< Feeder stops


#define FEEDER_MIN_BUF_SIZE             (500*1024)   			///<Feeder buffer min size

#define FEEDER_RESERVED_SIZE            (64 * 1024)   			///<Feeder buffer reserved  size

#define FEEDER_PROGRAM_BUF_START        FEEDER_RESERVED_SIZE   			///<Program source type real buffer offset size

#if defined(FEEDER_FIVE_INSTANCE)
#define FEEDER_MAX_DEFAULT_BUF_SIZE  	(2256*1024) 											///<Feeder max default buffer size
#define FEEDER_DEFAULT_BUF_SIZE         (1128*1024) 											///< Feeder default buffer size ,192, 188 alignment
#define FEEDER_PARSING_BUF_START        (FEEDER_PROGRAM_BUF_START + FEEDER_DEFAULT_BUF_SIZE) 	///<Parsing source real buffer offset size
#define FEEDER_PARSING_BUF_SIZE         (344 * 1024)  											///<Feeder parsing source buffer size

#define FEEDER_PROGRAM_SOURCE_2_BUF_START   (FEEDER_PARSING_BUF_START+FEEDER_PARSING_BUF_SIZE+FEEDER_RESERVED_SIZE) ///<Program source 2, real buffer offset size 
#define FEEDER_PROGRAM_SOURCE_2_BUF_SIZE    (1128*1024)   ///<Program source type 2 buffer size
#define FEEDER_PARSING_SOURCE_2_START      (FEEDER_PROGRAM_SOURCE_2_BUF_START+FEEDER_PROGRAM_SOURCE_2_BUF_SIZE) ///<Parsing source type 2, real buffer offset size 
#define FEEDER_PARSING_SOURCE_2_SIZE       (344 * 1024) ///<Parsing source type 2 buffer size

#define FEEDER_AUDIO_BUF_START          (FEEDER_PARSING_SOURCE_2_START+FEEDER_PARSING_SOURCE_2_SIZE+FEEDER_RESERVED_SIZE) ///<Audio source type, real buffer offset size
#define FEEDER_AUDIO_BUF_SIZE           (512*1024) ///<Audio source type buffer size
#define FEEDER_PARSING_AUD_BUF_START    (FEEDER_AUDIO_BUF_START + FEEDER_AUDIO_BUF_SIZE) ///<Parsing audio source type, real buffer offset size
#define FEEDER_PARSING_AUD_BUF_SIZE     (344 * 1024)   ///<Parsing audio source type buffer size

#define FEEDER_AUDIO_BUF_2_START          (FEEDER_PARSING_AUD_BUF_START+FEEDER_PARSING_AUD_BUF_SIZE+FEEDER_RESERVED_SIZE)   ///<Audio source type 2, real buffer offset size
#define FEEDER_AUDIO_BUF_2_SIZE           (512*1024)  ///<Audio source type 2 buffer size
#define FEEDER_PARSING_AUD_BUF_2_START    (FEEDER_AUDIO_BUF_2_START + FEEDER_AUDIO_BUF_2_SIZE) ///<Parsing audio source type 2 , real buffer offset size
#define FEEDER_PARSING_AUD_BUF_2_SIZE     (344 * 1024)   ///<Parsing audio source type 2 buffer size

#define FEEDER_AUDIO_BUF_3_START          (FEEDER_PARSING_AUD_BUF_2_START+FEEDER_PARSING_AUD_BUF_2_SIZE+FEEDER_RESERVED_SIZE)   ///<Audio source type 3, real buffer offset size
#define FEEDER_AUDIO_BUF_3_SIZE           (512*1024)    ///<Parsing audio source type 3 buffer size
#define FEEDER_PARSING_AUD_BUF_3_START    (FEEDER_AUDIO_BUF_3_START + FEEDER_AUDIO_BUF_3_SIZE)   ///<Parsing audio source type 3, real buffer offset size
#define FEEDER_PARSING_AUD_BUF_3_SIZE     (344 * 1024)  ///<Parsing audio source type 3 buffer size

#elif defined(FEEDER_THREE_INSTANCE)
#define FEEDER_MAX_DEFAULT_BUF_SIZE  	(2256*1024)  ///<Feeder three max default buffer size
#define FEEDER_DEFAULT_BUF_SIZE         (1128*1024) ///< 192, 188 alignment
#define FEEDER_PARSING_BUF_START        (FEEDER_PROGRAM_BUF_START + FEEDER_DEFAULT_BUF_SIZE) ///<Feeder three Parsing source type real buffer offset size
#define FEEDER_PARSING_BUF_SIZE         (0 * 1024)    ///<Feeder three Parsing source type buffer size
#define FEEDER_PARSING_AUD_BUF_START    (FEEDER_PARSING_BUF_START + FEEDER_PARSING_BUF_SIZE)   ///<Feeder three Parsing audio source type real buffer offset size
#define FEEDER_PARSING_AUD_BUF_SIZE     (0 * 1024) ///<Feeder three Parsing audio source type buffer size
#define FEEDER_THIRD_STREAM_BUF_START   (FEEDER_PARSING_AUD_BUF_START+FEEDER_PARSING_AUD_BUF_SIZE+FEEDER_RESERVED_SIZE) ///<Third strem source buffer offset size
#define FEEDER_THIRD_STREAM_BUF_SIZE    (1128*1024) ///< Third stream source  buffer size
#define FEEDER_THIRD_PARSING_START      (FEEDER_THIRD_STREAM_BUF_START+FEEDER_THIRD_STREAM_BUF_SIZE) ///<Third parsing source type real buffer offset size
#define FEEDER_THIRD_PARSING_SIZE       (0 * 1024) ///<Third parsing source buffer size
#define FEEDER_AUDIO_BUF_START          (FEEDER_THIRD_PARSING_START+FEEDER_THIRD_PARSING_SIZE+FEEDER_RESERVED_SIZE) ///<Audio source buffer offset
#define FEEDER_AUDIO_BUF_SIZE           (512*1024)  ///<Audio source buffer size
#elif defined(CC_FBM_TWO_FBP)
#define FEEDER_MAX_DEFAULT_BUF_SIZE  	(2256*1024)  ///<Max default buffer size
#define FEEDER_DEFAULT_BUF_SIZE         (1128*1024) ///< 192, 188 alignment
#define FEEDER_PARSING_BUF_START        (FEEDER_PROGRAM_BUF_START + FEEDER_DEFAULT_BUF_SIZE) ///<Parsing source buffer offset
#define FEEDER_PARSING_BUF_SIZE         (344 * 1024) ///<Parsing source buffer size
#define FEEDER_PARSING_AUD_BUF_START    (FEEDER_PARSING_BUF_START + FEEDER_PARSING_BUF_SIZE) ///<Parsing audio source buffer offset
#define FEEDER_PARSING_AUD_BUF_SIZE     (344*1024) ///<Parsing audio source buffer size
#define FEEDER_AUDIO_BUF_START          (FEEDER_PARSING_AUD_BUF_START+FEEDER_PARSING_AUD_BUF_SIZE+FEEDER_RESERVED_SIZE) ///<Audio source feeder buffer offset
#define FEEDER_AUDIO_BUF_SIZE           (1128*1024) ///<Audio source buffer size
#else
#define FEEDER_MAX_DEFAULT_BUF_SIZE  	(2256*1024)   ///<Max default buffer size
#define FEEDER_DEFAULT_BUF_SIZE         (2256*1024)   ///<Default buffer size
#define FEEDER_PARSING_BUF_START        (FEEDER_PROGRAM_BUF_START + FEEDER_DEFAULT_BUF_SIZE) ///<Parsing data source buffer offset
#define FEEDER_PARSING_BUF_SIZE         (512 * 1024)  ///<Parsing data source buffer size
#define FEEDER_PARSING_AUD_BUF_START    (FEEDER_PARSING_BUF_START + FEEDER_PARSING_BUF_SIZE)  ///<Parsing audio data source offset
#define FEEDER_PARSING_AUD_BUF_SIZE     (0)   ///<buffer size
#define FEEDER_AUDIO_BUF_START          (FEEDER_PROGRAM_BUF_START)  ///<Audio source data buffer offset
#define FEEDER_AUDIO_BUF_SIZE           (FEEDER_DEFAULT_BUF_SIZE)   ///<Audio source data buffer size
#endif

#if 0
#ifdef CC_FBM_TWO_FBP
#define FEEDER_DEFAULT_BUF_SIZE         (1128*1024) // 192, 188 alignment
#else
#define FEEDER_DEFAULT_BUF_SIZE         (2256*1024)
#endif
#define FEEDER_PARSING_BUF_START        (FEEDER_PROGRAM_BUF_START + FEEDER_DEFAULT_BUF_SIZE)
#ifdef CC_FBM_TWO_FBP
#define FEEDER_PARSING_BUF_SIZE         ( 344 * 1024)
#else
#define FEEDER_PARSING_BUF_SIZE         ( 512 * 1024)
#endif
#define FEEDER_PARSING_AUD_BUF_START    (FEEDER_PARSING_BUF_START + FEEDER_PARSING_BUF_SIZE)
#ifdef CC_FBM_TWO_FBP
#define FEEDER_PARSING_AUD_BUF_SIZE     (344*1024)
#else
#define FEEDER_PARSING_AUD_BUF_SIZE     (0)
#endif

#ifdef CC_FBM_TWO_FBP
#define FEEDER_AUDIO_BUF_START          (FEEDER_PARSING_AUD_BUF_START+FEEDER_PARSING_AUD_BUF_SIZE+FEEDER_RESERVED_SIZE)
#define FEEDER_AUDIO_BUF_SIZE           (1128*1024)
#else
#define FEEDER_AUDIO_BUF_START          (FEEDER_PROGRAM_BUF_START)
#define FEEDER_AUDIO_BUF_SIZE           (FEEDER_DEFAULT_BUF_SIZE)
#endif
#endif  // 0


//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
#ifdef TIME_MEASUREMENT
typedef enum
{
	FEEDER_PRINT_TMS_UNKNOWN = 0,
	FEEDER_PRINT_TMS_PRINT,
	FEEDER_PRINT_TMS_NOT_PRINT
}MTFeederPrintTMS;
#endif

typedef enum
{
	FEEDER_OFFSET_SEEK = 0,
	FEEDER_TIME_SEEK
}MTFeederRequestType;

typedef enum
{
    MTFEEDER_COND_ERROR = -1, 		///< Notify error happened
    MTFEEDER_COND_CTRL_DONE,		///< Notify ctrl done 
    MTFEEDER_COND_SUBTITLE			///< Notify subtitle condition
}   MTFEEDER_COND_T;

typedef enum
{
    FEEDER_NOTIFY_NEEDDATA,   			///< notification of copy buffer
    FEEDER_NOTIFY_ERROR,      			///< notification of play error
    FEEDER_NOTIFY_FILEEND,     			///< notification of file end
    FEEDER_NOTIFY_CAPTION,    			///< notification of caption
    FEEDER_NOTIFY_FILEBEGIN,           	///< notification of fileplay begin
    FEEDER_NOTIFY_DATA_REQ_DONE,      	///<for async reading
    FEEDER_NOTIFY_BUFFULL,				///< notification of buffer full
    FEEDER_NOTIFY_ELAPSEDTIME, 			///< notification of timer
    FEEDER_NOTIFY_TOTALTIME,   			///< notification of updated total time
    FEEDER_NOTIFY_PROFILE_CHANGE,		///< notification of profile change
    FEEDER_NOTIFY_SEEK_END,     		///< notification of seek end
    FEEDER_NOTIFY_ABORT_DONE,     		///< notification of abort end
    FEEDER_NOTIFY_TIME_OUT,     		///< notification of time out
    FEEDER_NOTIFY_ELAPSEDBYTE,     		///< notification of comsumed byte
    FEEDER_NOTIFY_DRAWSUBTITLE,			///< notification of draw subtitle
    FEEDER_NOTIFY_DRAW_EXT_SUBTITLE,	///< notification of draw external subtitle
    FEEDER_NOTIFY_PACKET_SIZE,    		///<notification of netflix packet size
    FEEDER_NOTIFY_DATA_EXHAUSTED, 		///<notification fo netflix data exhausted info
    FEEDER_NOTIFY_PVR_RANGE_NOTIFY,  	///< only correspond to user space
    FEEDER_NOTIFY_ACCESS_DIVX_DRM,  	///<notification of access divx drm
    FEEDER_NOTIFY_MAX					///max boundry 
} MTFEEDER_NOTIFY_COND;


/// Information of a callback function
typedef struct
{
    UINT8 u1SwdmxId;						///< Swdmx id
    UINT8 u1PlaymgrId;						///< Play manager ID
    UINT32 u4SrcType;                       ///< Callback source
    UINT32 u4Condition;                     ///< Callback condition
    UINT32 u4Param;                         ///< Callback paramter
} MTMM_NOTIFY_INFO_T;

/// File info type
typedef struct _MTMM_FILE_OPS_T
{
    UINT64  u8Offset;                       ///< Request data file offset 
    UINT32  u4QueryID;					    ///< Request data id
    UINT8   u1Whence;						///< offset base
} MTMM_FILE_OPS_T;

///Callback function of Feeder module
typedef void (*MTFEEDER_CALBACK)(MTMM_NOTIFY_INFO_T *prNfyInfo, UINT32 u4Param);

/// Feeder notify info  type
typedef void (*PFN_MTFEEDER_NFY_FCT) (
    void*               pvNfyTag,   			///< Feeder callback notify tag
    MTFEEDER_COND_T      eNfyCond,				///< Feeder callback condition
    UINT32              u4Data1,				///< Feeder callback data1
    UINT32              u4Data2					///< Feeder callback data2
);

/// Feeder notify info
typedef struct
{
    void*  pvTag;								///< Feeder notify info tag
    PFN_MTFEEDER_NFY_FCT  pfFeederNfy;			///< Feeder notify info
} MTFEEDER_NFY_INFO_T;


/// Feeder buffer information
typedef struct _MTFEEDER_BUF_INFO_T
{
    UINT32  u4StartAddr;						///< Feeder buff start addr
    UINT32  u4EndAddr;							///< Feeder buffer end addr
    UINT32  u4ReadAddr;							///< Feeder buffer read addr 
    UINT32  u4WriteAddr;						///< Feeder buffer write addr
    UINT32  u4LastReadAddr;						///< Feeder buffer last read addr 
    UINT32  u4LastReadSize;						///< Feeder buffer last read size
    UINT32  u4FreeSize;							///< Feeder buffer free size
    UINT32  u4BytesInBuf;						///< Data size in feeder buffer
    UINT32  u4Size;								///< Feeder buffer size
	UINT32  u4UnAckNum;  						///< Feeder unACK number
	UINT32  FeederDeviceId;						///< Feeder device id
	UINT32  u4PhysicalAddr;						///< Feeder physical addr
	UINT32  u4PhysicalAddrOffset;				///< Feeder physical addr offset
    BOOL    fgRingBuf;							///< Feeder is ring buffer or not
} MTFEEDER_BUF_INFO_T;


/// Data query mode
typedef enum
{
    FEEDER_AUDIO_SOURCE = 0,   	 	///< Audio data
    FEEDER_VIDEO_SOURCE,        	///< Video data
    FEEDER_PROGRAM_SOURCE,      	///< Mpeg data
    FEEDER_PARSING_SOURCE,      	///< Hdr data
    FEEDER_PARSING_AUDIO,			///< Audio hdr data
 #ifdef FEEDER_FIVE_INSTANCE
    FEEDER_PROGRAM_SOURCE_2,      	///< 2nd video instance
    FEEDER_PARSING_SOURCE_2,    	///< 2nd video hdr data
    FEEDER_AUDIO_SOURCE_2,    		///< 2nd audio instance
    FEEDER_PARSING_AUDIO_2,    		///< 2nd audio hdr data
    FEEDER_AUDIO_SOURCE_3, 		   ///< 3rd audio instance
    FEEDER_PARSING_AUDIO_3,			///< 3id audio hdr data
 #endif    
#ifdef CC_FBM_FOUR_INST_SUPPORT
    FEEDER_PARSING_SOURCE_3,
    FEEDER_SOURCE_3,
    FEEDER_PARSING_SOURCE_4,
    FEEDER_SOURCE_4,
#endif
    FEEDER_SOURCE_TOTAL,         	///< Total support data type
    FEEDER_SOURCE_INVALID			///< Invalid source
} MTFeederSourceType;


// IBC information
typedef enum
{
    FEEDER_IBC_NONE = 0,				///< Feeder not IBC 
    FEEDER_IBC_DMX_VUDU_KEY,			///< Feeder IBC type 
    FEEDER_IBC_CMPB_MTK,             ///<Feerder CMPB MTK TYPE
    FEEDER_IBC_SEQHEADER,
    FEEDER_IBC_PDCF,
    FEEDER_IBC_CENC,
    FEEDER_IBC_PARAM_STRM_INFO, //Feeder stream info
    FEEDER_IBC_DASH_SET_INFO,
    FEEDER_IBC_HDD_CONTENT_KEY,
    FEEDER_IBC_DTCP_IP_KEY,
    FEEDER_IBC_PUSH_CHANGE_AUDIO,
    FEEDER_IBC_MAX						///< max boundry 
} MTFeederIBCType;

// Feeder mmap device type

typedef enum
{
  FEEDER_FBM_FEEDER = 0,				///< Feeder default FBM type
  FEEDER_FBM_MMP,						///< Feeder mmp FBM type
  FEEDER_FBM_FEEDER2,					///< Feeder second FBM type
  FEEDER_FBM_FEEDER3,
  FEEDER_FBM_FEEDER4,
  FEEDER_FBM_MAX
}MTFeederFbmType;

// Feeder request data info
typedef struct
{    
    MTFeederSourceType eDataType;			///< Feeder source type 
    UINT32 u4Id;							///< Request data id
    UINT32 u4ReadSize;						///< Request size
    UINT32 u4WriteAddr;						///< Feeder write addr
    UINT32 u4AlignOffset;					///< Request align 	
    UINT64 u8FilePos;						///< Request data from file position 
    BOOL   fgPartial;						///< Partial or not
    BOOL fgEof;    							///< File EOF
    MTFeederIBCType eFeederIBC;				///< Feeder IBC info type
    BUF_AGT_CTRL_MTK_ENCRYPT_INFO_T *prMtkEncryptInfo;   ///<Feeder CMPB MTK info
    BUF_AGT_CTRL_STREAM_TYPE_T eFeederStrmType;

    union
    {
        BUF_AGT_CTRL_IBC_VIDEO_SEQHEADER_INFO t_vid_seqheader_info;
        BUF_AGT_CTRL_IBC_AUDIO_SEQHEADER_INFO t_aud_seqheader_info;
    }u;

    BUF_AGT_MM_PDCF_CRYPT_INFO_T *pt_pdcf_crypt;
    BUF_AGT_AES_CTR_ENCRYPT *pt_aes_crt_crypt;
    BUF_AGT_CTRL_IBC_DASH_SET_INFO_T *pt_dash_set_info;
    BUF_AGT_CTRL_HDD_DTCP_IP_INFO_T  *pt_hdd_dtcp_ip_info;
#ifdef TIME_MEASUREMENT
	MTFeederPrintTMS eFeederPrintTMS;
#endif
    MTFeederRequestType eFeederReqType;
    UINT64                              ui8_vid_pts;//for wfd debug
    UINT64                              ui8_push_time;//ms,for wfd debug
} MTFEEDER_REQ_DATA_T;


/// Feeder data transmit condition
typedef struct _MTFEEDER_TRANSMIT_COND_T
{
    INT32  i4TransmitResult;    ///< Transmit result
    UINT32 u4TransmitSize;      ///< Size of transmitted data 
    UINT32 u4BufAddr;           ///< The start address of the transmitted data
} MTFEEDER_TRANSMIT_COND;

// Feeder set info type struct
typedef enum
{
    FEEDER_SWDMX_FILESIZE,					///< Swdmx file size
    FEEDER_SWDMX_UNDERFLOW_CB,				///< Swdmx underflow callback
    FEEDER_SWDMX_READY_CB,					///< Buffer ready callback
    FEEDER_SWDMX_SRC_TYPE,					///< Feeder source type
    FEEDER_SWDMX_THRESHOLD,					///< Feeder threshold
    FEEDER_SWDMX_INSTANCE,					///< Swdmx instance		
    FEEDER_SWDMX_EOS,						///< Swdmx EOS
    FEEDER_SWDMX_STATUS_CB,					///< Swdmx status callback
    FEEDER_MM_USE,							///< Feeder use async read 
    FEEDER_SWDMX_CACHESIZE    				///< Feeder cache size
} MTFeederSetInfoType;


/// Data query mode
typedef enum
{
    FEEDER_PUSH_MODE = 0,       ///< Feeder push data to Application/Receiver
    FEEDER_PULL_MODE            ///< Application/Receiver send the data request
} MTFeederQueryMode;

// Feeder buffer info
typedef struct
{
  UINT32 u4Counter;					///< Feeder FBM Buffer counter		
  UINT32 u4FeederVirAddr;			///< Feeder vir addr
  UINT32 u4FeederBufSz;				///< Feeder buffer size
  UINT32 u4FeederMMpVirAddr;		///< Feeder device mmp vir addr
  UINT32 u4FeederMMpBufSz;			///< Feeder device buffer size
#if defined (FEEDER_MULTI_INSTANCE) || defined(CC_FBM_TWO_FBP) || defined(CC_FBM_FOUR_INST_SUPPORT)	
  UINT32 u4Feeder2VirAddr;			///< Feeder2 device mmp vir addr
  UINT32 u4Feeder2BufSz;			///< Feeder2 device buffer size
#endif
#ifdef CC_FBM_FOUR_INST_SUPPORT
  UINT32 u4Feeder3VirAddr;
  UINT32 u4Feeder3BufSz;
  UINT32 u4Feeder4VirAddr;
  UINT32 u4Feeder4BufSz;
#endif
}MTFeederMemInfo;


/// Callbalck function if Feeder retrieves the data
#ifdef FEEDER_MULTI_INSTANCE
typedef UINT32 (*MTFEEDER_QUERY_CALLBACK)(UINT8 u1AttachedSrcId,
                                          MTFeederSourceType eSrcType,
                                          MTFEEDER_BUF_INFO_T *pQryBufInfo,
                                          MTFEEDER_REQ_DATA_T *pReqData);
#else
typedef UINT32 (*MTFEEDER_QUERY_CALLBACK)(MTFeederSourceType eSrcType,
                                          MTFEEDER_BUF_INFO_T *pQryBufInfo,
                                          MTFEEDER_REQ_DATA_T *pReqData);
#endif


/// Callbalck function if Feeder consumes the data
typedef UINT32 (*MTFEEDER_CONSUME_CALLBACK)(MTFeederSourceType eSrcType, 
                                            MTFEEDER_BUF_INFO_T *pQryBufInfo,
                                            UINT32 u4NewRPtr);

typedef UINT32 (*MTFEEDER_FLUSH_CALLBACK)(MTFeederSourceType eSrcType);

/// Callbalck function if Feeder buffer is overflow
typedef VOID (*MTFEEDER_OVERFLOW_CALLBACK)(MTFeederSourceType eSrcType);


/// Callbalck function if Feeder buffer is underflow
typedef VOID (*MTFEEDER_UNDERFLOW_CALLBACK)(MTFeederSourceType eSrcType);

/// Seek file position handle function 
#ifdef FEEDER_MULTI_INSTANCE
typedef INT64 (*MTFEEDER_SEEKFILEPOS_HANDLER)(UINT8 u1AttachedSrcId, MTFeederSourceType eSrcType, MTMM_FILE_OPS_T *prFileInfo);
#else
typedef INT64 (*MTFEEDER_SEEKFILEPOS_HANDLER)(MTFeederSourceType eSrcType, MTMM_FILE_OPS_T *prFileInfo);
#endif


/// Application register its data transmit callback to the feeder
typedef struct _MTFEEDER_QUERY_DATA_T
{
    UINT8 u1PlaymgrAttachedId;
    UINT8 u1SwdmxAttachedId;
    UINT32                  u4QuerySize;    ///< Query data size
    MTFeederSourceType      eDataType;      ///< Query data type
    MTFEEDER_QUERY_CALLBACK   pfnSource;      ///< Callback function
    MTFEEDER_SEEKFILEPOS_HANDLER pfnSeekPos;    ///< Callback function
    MTFEEDER_CONSUME_CALLBACK pfnConsume;     ///< Callback function
    MTFEEDER_OVERFLOW_CALLBACK pfnOverflow;   ///< Callback function, for URI mode
    MTFEEDER_UNDERFLOW_CALLBACK pfnUnderflow; ///< Callback function, for URI mode
    MTFEEDER_FLUSH_CALLBACK pfFlush;          /// <Callback  flush data ,for PUSH mode
} MTFEEDER_QUERY_DATA;


/**MW_IF feeder request data callback function type
*/
typedef struct
{
	UINT8 u1AttachedSrcId;    					///< Attached source id 
    MTFeederSourceType eSrcType;				///< Data source type(audio, video, ..)
    MTFEEDER_BUF_INFO_T *pQryBufInfo;			///< Feeder buffer info 
    MTFEEDER_REQ_DATA_T* pt_ReqData;			///< Request data info 
}MTFEEDER_CALLBACK_INFO_T_QueryFeeder;

/**MW_IF feeder seek callback function type
*/
typedef struct 
{
	UINT8 u1AttachedSrcId;						///< Attached source id
	MTFeederSourceType eSrcType;				///< Feeder source type
	MTMM_FILE_OPS_T *prFileInfo;				///< Seek file info
}MTFEEDER_CALLBACK_INFO_T_Seek;

/**MW_IF feeder consume callback function type
*/
typedef struct 
{
	MTFeederSourceType eSrcType;				///< Feeder source type
	MTFEEDER_BUF_INFO_T *pQryBufInfo;			///< Feeder buffer info
	UINT32 u4NewRPtr;							///< Feeder latest read pointer
}MTFEEDER_CALLBACK_INFO_T_Consume;

/**MW_IF feeder push consume callback function type
*/
typedef struct 
{
	MTFeederSourceType eSrcType;				///< Feeder source type
	MTFEEDER_BUF_INFO_T *pQryBufInfo;			///< Feeder buffer info
	UINT32 u4NewRPtr;							///< Feeder latest read pointer
}MTFEEDER_CALLBACK_INFO_T_Push_Consume;

/**MW_IF feeder overflow callback function type
*/
typedef struct 
{
	MTFeederSourceType eSrcType;				///< Feeder source type
}MTFEEDER_CALLBACK_INFO_T_Overflow;

/**MW_IF feeder underflow callback function type
*/
typedef struct 	
{
	MTFeederSourceType eSrcType;				///< Feeder source type
}MTFEEDER_CALLBACK_INFO_T_Underflow;

typedef struct 
{
	MTFeederSourceType eSrcType;
}MTFEEDER_CALLBACK_INFO_T_Flush;
//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/** Set feeder relative infos, such as underflow callback function, feeder source type and so on .
 *
 *  @param u1SrcId		Feeder source id
 *  @param  u1Type            Data type (audio, video..)
 *  @param  u4Para1
 *  @param  u4Para2
 *  @param  u4Para3
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFEEDER_SetInfo(UINT8 u1SrcId, UINT8 u1Type,UINT32 u4Para1,UINT32 u4Para2,UINT32 u4Para3);

//-----------------------------------------------------------------------------
/** Init Feeder when system boot up, open feeder  device and set mmap read/write vir addr.
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTFEEDER_Init(VOID);


//-----------------------------------------------------------------------------
/** Init feeder param when system boot up.
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederInit(void);

//-----------------------------------------------------------------------------
/** Allot the receiver-related hardware resources
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederOpen(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Release the allotted resources
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederClose(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Initialize the variables which are required to transmit the data to the
 *  local buffer of the receiver
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederStart(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Initialize the local buffer by NULL
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederStop(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Pause the data transmit to the audio decoder
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederPause(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Resume the data transmit to the audio decoder
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederResume(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Get the free size of feeder local buffer
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *
 *  @retval the size of the feeder buffer
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederGetBufferSize(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Get the information of feeder local buffer
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  prBuffInfo      Pointers of the buffer
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederGetBufferInfo(MTFeederSourceType eDataType, 
                                 MTFEEDER_BUF_INFO_T *prBuffInfo);

//-----------------------------------------------------------------------------
/** Update the write pointer of the feeder local buffer
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  u4WriteSize     Write data size
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederUpdateWritePointer(MTFeederSourceType eDataType,
                                      UINT32 u4WriteSize);
//-----------------------------------------------------------------------------
/** Reset the write pointer of the feeder local buffer
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  u4WritePointer     WritePointer
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetWritePointer(MTFeederSourceType eDataType,UINT32 u4WritePointer);

//-----------------------------------------------------------------------------
/** Reallocate the feeder local buffer with user-specific size
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  u4Size          Memory buffer size
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetBufferSize(MTFeederSourceType eDataType, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** Transmit the data inside buffer as getting the data of Application 
 *  through the pBuffer
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  puiBuffer       Data buffer trasmitted by application
 *  @param  u4Size          Data size
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSubmitData(MTFeederSourceType eDataType, 
                              const UINT8 *puiBuffer, UINT32 u4Size);

//-----------------------------------------------------------------------------
/** Application set its data query function for the feeder
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  prSetQuery      Query setting
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederRegisterPullDataFunc(MTFeederSourceType eDataType, 
                                        const MTFEEDER_QUERY_DATA *prSetQuery);

//-----------------------------------------------------------------------------
/** Set the transmit parameters to the receiver
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  fEnable         Enable / Disable data transmit to the receiver
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetTransmit(MTFeederSourceType eDataType, BOOL fEnable);

//-----------------------------------------------------------------------------
/** Wait the event if there is more buffer space free
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 *  @retval FEEDER_E_STOP   Feeder stops
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederWaitFreeBufferSpace(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Wait the event if the buffer is empty
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 *  @retval FEEDER_E_STOP   Feeder stops
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederWaitBufferEmpty(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Set the transmit decode target
 *
 *  @param  u4VideoFmt      video decode format
 *  @param  u4AudioFmt      audio decode format
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetDecodeFmt(UINT32 u4VideoFmt, UINT32 u4AudioFmt);

//-----------------------------------------------------------------------------
/** Get the transmit decode target format
 *
 *  @param  pu4VideoFmt     video decode format
 *  @param  pu4AudioFmt     audio decode format
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederGetDecodeFmt(UINT32 *pu4VideoFmt, UINT32 *pu4AudioFmt);


//#ifndef __KERNEL__
//-----------------------------------------------------------------------------
/** Register the callback function of Feeder module
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  eCallbackType   Context parameter
 *  @param  pfnCallback     Callback function pointer
 *  @param  u4Param         
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederInstallCallback(MTFeederSourceType eDataType,
                                   MTFEEDER_NOTIFY_COND eCallbackType,
                                   MTFEEDER_CALBACK pfnCallback, UINT32 u4Param);

//-----------------------------------------------------------------------------
/** Release the callback function of Feeder module
 *
 *  @param  eDataType       Tramsmit data type (audio, video or program)
 *  @param  eCallbackType   Context parameter
 *  @param  pfnCallback     Callback function pointer
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederUnInstallCallback(MTFeederSourceType eDataType,
                                     MTFEEDER_NOTIFY_COND eCallbackType,
                                     MTFEEDER_CALBACK pfnCallback);
//#endif

//-----------------------------------------------------------------------------
/** Set the request parameters to the receiver
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  u4QrySize       Query data size
 *  @param  u8Offset        Query offset from file head
 *  @param  pResult           Feeder data transmit condition
 *  @param  u4ReqID         Reqest ID
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 *  @retval FEEDER_E_STOP   Feeder stops
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetRequest(MTFeederSourceType eDataType, UINT32 u4QrySize, UINT64 u8Offset,
                             MTFEEDER_TRANSMIT_COND *pResult, UINT32 u4ReqID);

//-----------------------------------------------------------------------------
/** notify handle of the driver
 *
 *  @param  eSrcType       Data type (audio, video..)
 *  @param  eCondition      Notify condition
 *  @param  u4Param
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 *  @retval FEEDER_E_STOP   Feeder stops
 */
//-----------------------------------------------------------------------------
extern BOOL MTFeederNotifyHandle(MTFeederSourceType eSrcType, 
                         MTFEEDER_NOTIFY_COND eCondition, UINT32 u4Param);


#ifdef FEEDER_MULTI_INSTANCE
//-----------------------------------------------------------------------------
/** Set buffer agent info to feeder 
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  u4Align          Buffer agent align limit
 *  @param  u4BlockSize   Read bolck size
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetBagtInfo(MTFeederSourceType eDataType, UINT32 u4Align, UINT32 u4BlockSize);

//-----------------------------------------------------------------------------
/** Set underflow threshold to feeder 
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  u4Threshold   Underflow threshold value
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetUnderFlowThreshold(MTFeederSourceType eDataType, UINT32 u4Threshold);

//-----------------------------------------------------------------------------
/** Set buffer ready threshold to feeder 
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  u4Threshold   Buffer ready threshold value
 *  @retval none
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetReadyThreshold(MTFeederSourceType eDataType, UINT32 u4Threshold);

//-----------------------------------------------------------------------------
/** Flush feeder buffer  
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @retval none
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetFlush(MTFeederSourceType eDataType);


//-----------------------------------------------------------------------------
/** Reset feeder flush 
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederResetFlushId(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Set feeder info when multi feeder instance
 *
 *  @param  eDataType       Data type (audio, video..)
 *  @param  eType   Info type
 *  @param  u4Para  Info parameters 
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetInfo(MTFeederSourceType eDataType, MTFeederSetInfoType eType,UINT32 u4Para);

//-----------------------------------------------------------------------------
/**Ignore feeder buffer ready
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederIgnoreReady(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/**Get feeder buffer align size
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern UINT32 MTFeederGetAlignSize(MTFeederSourceType eDataType);
#else
//-----------------------------------------------------------------------------
/** Set buffer agent info to feeder 
 *
 *  @param  u4Align          Buffer agent align limit
 *  @param  u4BlockSize   Read bolck size
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetBagtInfo(UINT32 u4Align, UINT32 u4BlockSize);

//-----------------------------------------------------------------------------
/** Set underflow threshold to feeder 
 *
 *  @param  u4Threshold   Underflow threshold value
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetUnderFlowThreshold(UINT32 u4Threshold);

//-----------------------------------------------------------------------------
/** Set buffer ready threshold to feeder 
 *
 *  @param  u4Threshold   Buffer ready threshold value
 *  @retval none
 */
//----------------------------------------------------------------------------
extern VOID MTFeederSetReadyThreshold(UINT32 u4Threshold);

//-----------------------------------------------------------------------------
/** Flush feeder buffer  
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetFlush(VOID);

//-----------------------------------------------------------------------------
/** Set feeder info when multi instance
 *
 *  @param  eType   Info type
 *  @param  u4Para  Info parameters 
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetInfo(MTFeederSetInfoType eType,UINT32 u4Para);

//-----------------------------------------------------------------------------
/**Ignore feeder buffer ready
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederIgnoreReady(VOID);

//-----------------------------------------------------------------------------
/**Get feeder buffer align size
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern UINT32 MTFeederGetAlignSize(void);
#endif


//-----------------------------------------------------------------------------
/** Set feeder mode to uri mode
 *
 *  @param  eType       Data type (audio, video..)
 *  @param  u4BufSize    Data buffer size
 *  @param  u4KeepBufThres    Feeder buffer threshold value
 *  @param  u4RebufThres       Nearly buffer threshold value
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetUriMode(MTFeederSourceType eType, UINT32 u4BufSize, UINT32 u4KeepBufThres, UINT32 u4RebufThres);


//-----------------------------------------------------------------------------
/** Set feeder skype source flag
 *
 *  @param  isSkype       Skype source type enable or disable
 *
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetSkypeSourceFlag(BOOL isSkype);

//-----------------------------------------------------------------------------
/** Get feeder skype source flag
 *
 *  @param  isSkype       Skype source type
 *
 */
//-----------------------------------------------------------------------------
extern BOOL MTFeederGetSkypeSourceFlag(void);

//-----------------------------------------------------------------------------
/** Get feeder buffer status : Data bytes in buffer and percent
 *
 *  @param  eType       Data type (audio, video..)
 *  @param  pu4Len     Data bytes in buffer
 *  @param  pu4Percent   Data percent
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederGetBufferFullness(MTFeederSourceType eType, UINT32 *pu4Len, UINT32 *pu4Percent);

//-----------------------------------------------------------------------------
/** Set feeder pre-load status 
 *
 *  @param  eType       Data type (audio, video..)
 *  @param  u4WriteSize      The pre-loaded size
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederSetPreLoadDone(MTFeederSourceType eType, UINT32 u4WriteSize);

//-----------------------------------------------------------------------------
/** Set feeder to use mmp device for mmap 
 *
 *  @param  eType       Data type (audio, video..)
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------

extern INT32 MTFeederSetMMP(MTFeederSourceType eDataType);

//-----------------------------------------------------------------------------
/** Set feeder  status to pre-loading 
 *
 *  @param  eType       Data type (audio, video..)
 *  @param  pu4Addr     Feeder buffer start addr
 *  @param  pu4Size     Pre-load size
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederInitPreLoad(MTFeederSourceType eType, UINT32 *pu4Addr, UINT32 *pu4Size);


//-----------------------------------------------------------------------------
/**Set current application to pull mode
 *
 *  @param  eDataType   Data type (audio, video..)
 *  @param  eQueryMode    Pull mode
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetAppQueryMode(MTFeederSourceType eDataType, MTFeederQueryMode eQueryMode);


//-----------------------------------------------------------------------------
/**  Set feeder buffer to use ring buf or single buf
 *
 *  @param  eDataType    Data type (audio, video..)
 *  @param  fgRing  	Enable ring or disable ring buffer
 *
 *  @retval 
 */
//-----------------------------------------------------------------------------
extern VOID MTFeederSetRing(MTFeederSourceType eDataType, BOOL fgRing);

//-----------------------------------------------------------------------------
/** Get user space start mmap vir addr
 *
 *  @param  eDataType       Data type (audio, video..)
 *
 *  @retval addr  value
 */
//-----------------------------------------------------------------------------
extern UINT32 MTFeederGetUserStartVAddr(UINT32 FeederDeviceId);

//-----------------------------------------------------------------------------
/** Get feeder memory info
 *
 *  @param  pMemInfo      Memory info struct
 *
 *  @retval FEEDER_E_OK     Succeed
 *  @retval FEEDER_E_FAIL   Fail
 */
//-----------------------------------------------------------------------------
extern INT32 MTFeederGetMemInfo(MTFeederMemInfo*pMemInfo);


#ifdef __cplusplus
}
#endif

#endif //MT_FEEDER_H
