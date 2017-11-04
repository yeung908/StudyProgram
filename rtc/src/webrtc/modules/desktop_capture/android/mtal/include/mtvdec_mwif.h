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
 * $RCSfile: mtvdec_mwif.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/ 

/** @file mtvdec_mwif.h
 *  This header file declares exported APIs of Video Decoder (VDEC) module,
 *  which inclued MPEG 1/2/4, H.264(AVC), and VC-1
 */

#ifndef MT_VDEC_MWIF_H
#define MT_VDEC_MWIF_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mtvdec.h"

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/** MM parameter
*/
typedef enum
{
    MTVDEC_MM_PLAY_SPEED = 0,  ///<MM Speed setting
    MTVDEC_MM_FRAME_RATE,      ///<MM Frame rate setting
    MTVDEC_MM_CONTAINER_TYPE,  ///<MM Container Type Setting , such as TS, PS, AVI etc..
    MTVDEC_MM_SEQ_INFO,        ///<MM SEQ info valid or not , for MP4 , 264
    MTVDEC_MM_SRC_TYPE,        ///<MM Src type, for SKYPE, WIFI-Display, Direct HW Play applications
    MTVDEC_MM_TPT_SEQ_INFO,    ///<MM Trick play track, for divx plus
    MTVDEC_MM_RV_RPR_INFO,     ///<MM RV seamless setting
    MTVDEC_MM_3D_INFO,         ///<MM VDEC 3D type setting
    MTVDEC_MM_3D_TRICK_TYPE,   ///<MM VDEC 3D trick type
    MTVDEC_MM_DIVX4_SIGNAL,    ///<MM DIVX4 
    MTVDEC_MM_XVID_SIGNAL,
    MTVDEC_MM_MAX
} MTVDEC_MM_PARAM_T;

/** 3D type in container header.
*/
typedef enum
{
    MTVDEC_3D_NONE,    ///<none 3D
    MTVDEC_3D_SBS_LF, ///<side by side, left image first
    MTVDEC_3D_SBS_RF, ///<side by side, right image first
    MTVDEC_3D_TB_LF,   ///<top bottom, left image first
    MTVDEC_3D_TB_RF,   ///<top bottom, right image first
    MTVDEC_3D_DUAL_STREAM,   ///<top bottom, right image first
    MTVDEC_3D_MULTI_STREAM,  ///<obsolete
    MTVDEC_3D_MVC,           ///<3D MVC
    MTVDEC_3D_REALD_DUAL_STREAM,   ///<obsolete
    MTVDEC_3D_CHECKER_BOARD,    ///<obsolete
    MTVDEC_3D_MAX
} MTVDEC_3D_TYPE_T;

/** Query Frame buffer pool types 
*/
typedef enum
{
    USR_FBM_POOL_TYPE_DMX,
    USR_FBM_POOL_TYPE_MPEG,
    USR_FBM_POOL_TYPE_FEEDER,
    USR_FBM_POOL_TYPE_FEEDER_MMP,
    USR_FBM_POOL_TYPE_DSP,
    USR_FBM_POOL_TYPE_B2R,
    USR_FBM_POOL_TYPE_JPEG,
    USR_FBM_POOL_TYPE_JPEG_OSD1,
    USR_FBM_POOL_TYPE_JPEG_OSD2,
    USR_FBM_POOL_TYPE_JPEG_OSD3,
    USR_FBM_POOL_TYPE_JPEG_OSD4,
    USR_FBM_POOL_TYPE_SWDMX,
    USR_FBM_POOL_TYPE_MPEG_FREE,
    USR_FBM_POOL_TYPE_FEEDER2,
    USR_FBM_POOL_TYPE_DMX2,
    USR_FBM_POOL_TYPE_MPEG2,
    USR_FBM_POOL_TYPE_PVR,
    USR_FBM_POOL_TYPE_PVR2,
    USR_FBM_POOL_TYPE_JPG_VDP,
    USR_FBM_POOL_TYPE_PNG,
    USR_FBM_POOL_TYPE_DMXPID,
    USR_FBM_POOL_TYPE_IMGRZ_3D_KR,
    USR_FBM_POOL_TYPE_TOTAL2,
    USR_FBM_POOL_TYPE_TOTAL,
    USR_FBM_POOL_TYPE_NS
} USR_FBM_POOL_TYPE_T;

typedef struct 
{
    UINT32 u4InfoMask;                  ///<info mask. ex. MTVDEC_SETINFO_SUPERFREEZE
    BOOL fgSuperFreeze;                 ///<super freeze on/off
}MTVDEC_SETINFO_T;

/** This structure is used on get type VID_DEC_GET_TYPE_CC_DATA, which contains the CC data and related information.
*/
typedef struct
{
    UCHAR*     pucCcData;   ///<this buffer is a share memory address.kernel module can access it directly.
    UINT32     u4Size;      ///<data buffer size
    UINT64     u8Pts;       ///<data pts
    BOOL       fgIsScte;    ///<is Scte ? (MPEG2)
    BOOL       fgBottomFirst; ///<record interlace type
} MTVDEC_CC_DATA_T;

/** Set/Get deblocking infomation 2
*/
typedef struct
{
    BOOL fgDeblocking;                   ///<is deblocking
    UINT16 u2X;                          ///<X position in 16 pixel unit
    UINT16 u2Y;                          ///<Y position in 16 pixel unit
    UINT16 u2W;                          ///<Width in 16 pixel unit
    UINT16 u2H;                          ///<Height in 16 pixel unit
} MTVDEC_DBK_INFO2_T;

/** Get Logo info
*/
typedef struct
{
    BOOL     fgDefault;      ///<enable default boot logo 
    BOOL     fgDefault_exist; ///<is default boot logo exist
    BOOL     fgOnoff;        ///<on/off the vdec boot logo
    UINT8    u1Data_Select;  ///<select the number for boot
    UINT8    u1_Slot_Num;     ///<slot number
    UINT32   u4Valid;       ///<valid for each vdec boot logo address
    UINT32   u4Flash_Addr;  ///<flash start address
    UINT32   u4Flash_Size;  ///<flash size
} MTVDEC_BOOT_LOGO_GET_T;

/** Get Logo address
*/
typedef struct
{
    UINT8    u1Data_Type;       ///<data type, one of VID_DEC_CODEC_T
    UINT32   u4Data_Size;       ///<data size
    UINT32   u4Data_Addr;       ///<the address of this vdec boot logo
} MTVDEC_BOOT_LOGO_ADDR_GET_T;

typedef struct
{
    BOOL    fgDefault;      ///<enable default boot logo
    BOOL    fgOnoff;        ///<on/off the vdec boot logo
    UINT8   u1Data_Select;  ///<select the number for boot
    UINT32  u4Valid;        ///<valid for each vdec boot logo address
} MTVDEC_BOOT_LOGO_SET_T;

typedef struct
{
    UINT8   u1Data_Type;          ///<data type, one of VID_DEC_CODEC_T
    UINT32  u4Data_Size;          ///<data size
    UINT32  u4Data_Addr;          ///<the address of this vdec boot logo
} MTVDEC_BOOT_LOGO_ADDR_SET_T;

/**
 *  VDEC position information, used for AB repeat
 */
typedef struct
{
    UINT64 u8PtsI;
    UINT64 u8Pts;
    
    UINT64 u8AudPts;
    UINT64 u8AudOffset;
    
    UINT64 u8OffsetI;
    UINT64 u8Offset;
    UINT64 u8OffsetDisp;
    INT32  i4TemporalRef;
    UINT16 u2DecodingOrder;
} MTVDEC_POS_INFO_T;

/**
 *  VDP AB position information
 */
typedef struct
{
    BOOL fgValid;      ///<is valid or not
    BOOL fgPosition;   ///<use position or pts.
    MTVDEC_POS_INFO_T rA;  ///<position A
    MTVDEC_POS_INFO_T rB;  ///<position B
} MTVDEC_AB_INFO_T;

/**Decode cc notify function.
*@param u4Tag                     Tag id.
*@param u4Condition               Condition type.   
*@param u4Data1                   u4Data1.
*/
typedef VOID (*MTVDEC_PFN_CC_CB)
(
    UINT32 u4Tag, UINT32 u4Condition, UINT32 u4Data1
);

/**Auto test notify function.
*@param u4Tag                     Tag id.
*@param u4Condition               Condition type.   
*@param u4Data1                   u4Data1.   
*@param u4Data2                   u4Data2.       
*/
typedef VOID (*MTVDEC_PFN_AUTOTEST_CB)
(
    UINT32 u4Tag, UINT32 u4Condition, UINT32 u4Data1, UINT32 u4Data2
);

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
#define VDEC_STC_ID_0     0       ///< STC ID 0
#define VDEC_STC_ID_1     1       ///< STC ID 1
#define VDEC_STC_ID_MAX   2       ///< Maximum STC Instnace

#define MTVDEC_STATUS_NORMAL       ((UINT32) 0)   ///< VDEC Decode Status Normal
#define MTVDEC_STATUS_DROP        ((UINT32) (1<<0))   ///< VDEC Decode Status Drop Frame
#define MTVDEC_STATUS_SKIP        ((UINT32) (1<<1))   ///< VDEC Decode Status Skip Frame
#define MTVDEC_STATUS_TIMEOUT     ((UINT32) (1<<2))   ///< VDEC Decode Status Decode Timeout

#define MTVDEC_SETINFO_SUPERFREEZE          ((UINT32) (1<<0))  ///< for timeshift super freeze
#define MTVDEC_SETINFO_MAX                  ((UINT32) (1<<31))

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/**Get Video thumbnail.
*@param ucEsId                     ES id.
*@param u2CompId                   Comp id.
*@param bIsOnePass                  Is one pass.
*@param prDstInfo                  destination information.
*@param prSrcInfo                  source information.
*@param fgKeepRation                     keep aspect ratio or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetVideoThumbnail(UCHAR ucEsId, UINT16 u2CompId, BOOL bIsOnePass, 
    MTVDEC_THUMBNAIL_INFO_T* prDstInfo, MTVDEC_CAPTURE_INTO_T* prSrcInfo, BOOL fgKeepRation);

/**Get dispaly frame buffer address from VDEC module.
*@param ucEsId                     ES id.
*@param prCapInfo                  address info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetDisplayFrameBufferAddr(UCHAR ucEsId, VOID *prCapInfo);

/** Enable/Disable VDEC skip mode (RVU)
*@param ucEsId                     ES id.
*@param fgSkipMode                 Enable & disable
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetSkipMode(UCHAR ucEsId, BOOL fgSkipMode);
/**Register callback to VDEC module for general info callback.
*@param  ucEsId                    Es id.
*@param  u4Tag                     tag.
*@param  pfGeneralCb               callback function address.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegGeneralCb(UCHAR ucEsId, UINT32 u4Tag, MTVDEC_PFN_GENERAL_CB pfGeneralCb);
/**Set MM related parameter to  VDEC module.
*@param  ucEsId                    Es id.
*@param  u4Type                    Type of MM parameter.
*@param  u4Param1                  Parameter 1.
*@param  u4Param2                  Parameter 2.
*@param  u4Param3                  Parameter 3.
*@param  pfGeneralCb               callback function address.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetMMParam(UCHAR ucEsId, UINT32 u4Type, UINT32 u4Param1,UINT32 u4Param2, UINT32 u4Param3);
/**Clear MM parameter of VDEC module.
*@param  ucEsId                    Es id.
*@param  u4Type                    Type of MM parameter.
*/
EXTERN VOID MTVDEC_ClrMMParam(UCHAR ucEsId, UINT32 u4Type);
/**Query VDEC module Codec capability 
*@param  ucEsId                    Es id.
*@param  u4Type                    Type of MM parameter.
*@retval TRUE                      Support.
*@retval FALSE                     Not Support.
*/
EXTERN BOOL MTVDEC_ChkCodecCap(UCHAR ucEsId, MTVDEC_FMT_T eVdecFmt);

/**Set VDEC Info for Timeshift.
*@param  ucEsId                    Es id.
*@param  prSetInfo                 needed info for timeshift.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetInfo(UCHAR ucEsId, MTVDEC_SETINFO_T* prSetInfo);
/**Play CC data.
*@param  ucEsId                    Es id.
*@param  u4Tag                     tag.
*@param  pfCcCb                    cc data callback function.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PlayCc(UCHAR ucEsId, UINT32 u4Tag, MTVDEC_PFN_CC_CB pfCcCb);
/**Stop CC data.
*@param  ucEsId                    Es id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_StopCc(UCHAR ucEsId);
/**Allocate CC data buffer in VDEC.
*@param  ucEsId                    Es id.
*@param  u4CcBufSize               buffer size.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_AllocCcBuf(UCHAR ucEsId, UINT32 u4CcBufSize);
/**Free CC buffer in VDEC.
*@param  ucEsId                    Es id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_FreeCcBuf(UCHAR ucEsId);
/**Flush CC buffer in VDEC.
*@param  ucEsId                    Es id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_FlushCcBuf(UCHAR ucEsId);
/**Get CC data from VDEC.
*@param  ucEsId                    Es id.
*@param  prCcData                  cc data structure.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetCc(UCHAR ucEsId, MTVDEC_CC_DATA_T* prCcData);
/**Get MPEG-2 Deblocking info VDEC.
*@param  ucEsId                    Es id.
*@param  prDbkInfo                 Deblocking information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetDbkInfo2(UCHAR ucEsId, MTVDEC_DBK_INFO2_T* prDbkInfo);
/**Set MPEG-2 Deblocking info VDEC.
*@param  ucEsId                    Es id.
*@param  prDbkInfo                 Deblocking information.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetDbkInfo2(UCHAR ucEsId, MTVDEC_DBK_INFO2_T* prDbkInfo);

#ifdef MULTIMEDIA_AUTOTEST_SUPPORT
/**VDEC AUTO Test.
*@param  ucEsId                    Es id.
*@param  uCrcGolden                CRC.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetCrcGolden(UCHAR ucEsId, UINT32 uCrcGolden);
/**VDEC AUTO Test.
*@param  ucEsId                    Es id.
*@param  u4Tag                     Tag.
*@param  pfAutotestCb              Auto test callback.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RegAutotestCb(UCHAR ucEsId, UINT32 u4Tag, MTVDEC_PFN_AUTOTEST_CB pfAutotestCb);
#ifdef VDEC_TIME_PROFILE
/**Set VDEC AUTO Test file directory.
*@param  ucEsId                    Es id.
*@param  ucAutoPlayCurFileDir      auto test file directory.
*@param  u4Size                    string size
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetAutoTestCurFileDir(UCHAR ucEsId, CHAR *ucAutoPlayCurFileDir, UINT32 u4Size);
/**Set VDEC AUTO Test file name.
*@param  ucEsId                    Es id.
*@param  ucAutoPlayCurFileName     file name.
*@param  u4Size                    string size.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetAutoTestCurFileName(UCHAR ucEsId, CHAR *ucAutoPlayCurFileName, UINT32 u4Size);
#endif
#endif
/**Set VDEC AUTO Test file name.
*@param  ucEsId                    Es id.
*@param  ucAutoPlayCurFileName     file name.
*@param  u4Size                    string size.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_ChkDivXBonding(UCHAR ucEsId, BOOL *pfgValue);
/**Set VDEC repeat A-B info
*@param  ucEsId                    Es id.
*@param  prABInfo                  A-B Info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetABInfo(UCHAR ucEsId, MTVDEC_AB_INFO_T *prABInfo);
/**Set VDEC swdmx src
*@param  ucEsId                    Es id.
*@param  u1SwdmxInstId             SWDMX ID (AVI, MKV etc..).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetSrcId(UCHAR ucEsId, UINT8 u1SwdmxInstId );
/**Set VDEC Play MM mode or not (VDEC has MM and DTV modes)
*@param  ucEsId                    Es id.
*@param  fgPlayMM                  MM or not.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_PlayMM(UCHAR ucEsId, BOOL fgPlayMM);

/**Free VDEC Play I-Frame buffer
*@param  ucEsId                    Es id.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_RePlayVdec(UCHAR ucEsId);
#ifdef CC_BOOT_VDEC_LOGO
/**Get boot logo info
*@param  prLogoInfo                bootlogo info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetBootLogo(MTVDEC_BOOT_LOGO_GET_T* prLogoInfo);
/**Get boot logo info address
*@param  prLogoInfo                bootlogo address info.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_GetBootLogo_Addr(MTVDEC_BOOT_LOGO_ADDR_GET_T* prLogoInfo);
/**Set boot logo info 
*@param  prLogoInfo                bootlogo info.
*@param  fgStore                   store it into eeeprom or not
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetBootLogo(MTVDEC_BOOT_LOGO_SET_T* prLogoInfo, BOOL fgStore);
/**Set boot logo info 
*@param  prLogoAddr                bootlogo address info.
*@param  ucDataType                Eeeprom data type
*@param  fgStore                   store it into eeeprom or not
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T MTVDEC_SetBootLogo_Addr(MTVDEC_BOOT_LOGO_ADDR_SET_T* prLogoAddr, UCHAR ucDataType, BOOL fgStore);
#endif
/**Set super freeze onoff
*@param  ucEsId                    Es id.
*@param  fgSuperFreeze             super freeze on or off.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTVDEC_SetSuperFreeze(UCHAR ucEsId, BOOL fgSuperFreeze);

#ifdef __cplusplus
}
#endif

#endif //MT_VDEC_MWIF_H
