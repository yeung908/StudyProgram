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
 * $RCSfile: mtauddec.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/*! \file mtauddec.h
 *  \brief This header file declares exported APIs of audio decoder module.
 */

#ifndef MT_AUDDEC_H
#define MT_AUDDEC_H

#ifdef __cplusplus
extern "C"
{
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"

#include "x_aud_dec.h"
#include "x_rm.h"           //middleware/res_mngr
#include "u_drv_cust.h"     //middleware/res_mngr/drv
#ifdef LINUX_TURNKEY_SOLUTION
#include "u_rm_dev_types.h" //middleware/res_mngr
#endif

/*! \addtogroup mtauddec MTAL audio decoder modules
 *  \brief MTAL audio decoder models
 *  @{
 */

//-----------------------------------------------------------------------------
// Configurations
//-----------------------------------------------------------------------------

/*! \addtogroup mtauddec_constants Constants
 *  \brief Definitions of Constants.
 *  @{
 */

/*! \def MIXSOUND_MEMPLAY_USER_SPACE_BUFFER
 *  \brief Active/Deactivate the user space buffer of mixsound for memory play
 */
#define MIXSOUND_MEMPLAY_USER_SPACE_BUFFER 1

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

/*! \addtogroup auddecid Audio Decoder ID
 *  \brief Definition of Audio decoder ID.
 * @{
 */

 /*! \def MT_AUD_DEC_MAIN
  *  \brief main audio decoder id for non-EU model
  */
#define MT_AUD_DEC_MAIN    (0)

/*! \def MT_AUD_DEC_AUX
  *  \brief aux audio decoder id for non-EU model
  */
#define MT_AUD_DEC_AUX     (1)

/*! \def MT_AUD_DEC_THIRD
  *  \brief third audio decoder id
  */
#define MT_AUD_DEC_THIRD    (2)

/*! \def MT_AUD_DEC_THIRD
  *  \brief fourth audio decoder id
  */
#define MT_AUD_DEC_FOURTH    (3)

// Decoder define for EU model

/*! \def MT_AUD_DEC_EU_MAIN
  *  \brief main audio decoder id for EU model
  */
#define MT_AUD_DEC_EU_MAIN                 (0)

/*! \def MT_AUD_DEC_EU_SCART
  *  \brief aux audio decoder id for EU model
  */
#define MT_AUD_DEC_EU_SCART                (1)

/*! \def MT_AUD_DEC_EU_AUDIO_DESCRIPTION
  *  \brief third audio decoder id for EU model
  */
#define MT_AUD_DEC_EU_AUDIO_DESCRIPTION    (2)

/*! \def MT_AUD_DEC_EU_NUM
  *  \brief number of audio decoders for EU model
  */
#define MT_AUD_DEC_EU_NUM                  (3)

/*! @} */

// Copyright constant

/*!\addtogroup copyright Copyright
 *  \brief Copyright
 *  @{
 */

/*! \def MT_CGMS_COPY_FREELY
 *  \brief Copy Freely
 */
#define MT_CGMS_COPY_FREELY                (0x00)

/*! \def MT_CGMS_COPY_NO_MORE
 *  \brief No More Copy
 */
#define MT_CGMS_COPY_NO_MORE               (0x01)

/*! \def MT_CGMS_COPY_ONCE
 *  \brief Copy Once
 */
#define MT_CGMS_COPY_ONCE                  (0x02)

/*! \def MT_CGMS_COPY_NEVER
 *  \brief Never Copy
 */
#define MT_CGMS_COPY_NEVER                 (0x03)

/*! @} */

// IEC category code

/*! \addtogroup ieccatcode IEC Category Code
 *  \brief IEC Category Code
 * @{
 */

/*! \def MT_IEC_ORIGINAL_GENERAL
 *  \brief Original General
 */
#define MT_IEC_ORIGINAL_GENERAL            (0x0)

/*! \def MT_IEC_ORIGINAL_BROAD_CAST
 *  \brief Original Broadcast
 */
#define MT_IEC_ORIGINAL_BROAD_CAST         (0x64)

/*! \def MT_IEC_NON_ORIGINAL_BROAD_CAST
 *  \brief Original non-Broadcast
 */
#define MT_IEC_NON_ORIGINAL_BROAD_CAST     (0xe4)

/*! @} */

/*! @} */

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

/*! \addtogroup mtauddec_typedefs Type Definitions
 *  \brief Type deifinitions
 *  @{
 */

/*! \enum MTAUDDEC_INPUT_ID_T
 *  \brief Line-in mux selection.
 */
typedef enum
{
    MTAUDDEC_INPUT_ID_COMP_VID_0 = 0,
    MTAUDDEC_INPUT_ID_COMP_VID_1,
    MTAUDDEC_INPUT_ID_COMP_VID_2,
    MTAUDDEC_INPUT_ID_COMP_VID_3,
    MTAUDDEC_INPUT_ID_S_VID_0,
    MTAUDDEC_INPUT_ID_S_VID_1,
    MTAUDDEC_INPUT_ID_S_VID_2,
    MTAUDDEC_INPUT_ID_YPBPR_0,
    MTAUDDEC_INPUT_ID_YPBPR_1,
    MTAUDDEC_INPUT_ID_YPBPR_2,
    MTAUDDEC_INPUT_ID_VGA_0,
    MTAUDDEC_INPUT_ID_VGA_1,
    MTAUDDEC_INPUT_ID_HDMI_0,
    MTAUDDEC_INPUT_ID_HDMI_1,
    MTAUDDEC_INPUT_ID_HDMI_2,
    MTAUDDEC_INPUT_ID_HDMI_3,
    MTAUDDEC_INPUT_ID_HDMI_4,
    MTAUDDEC_INPUT_ID_DVI_0,
    MTAUDDEC_INPUT_ID_DVI_1,
    MTAUDDEC_INPUT_ID_DVI_2,
    MTAUDDEC_INPUT_ID_DVI_3,
    MTAUDDEC_INPUT_ID_DVI_4,
    MTAUDDEC_INPUT_ID_SCART_0,
    MTAUDDEC_INPUT_ID_SCART_1,
    MTAUDDEC_INPUT_ID_SCART_2,
    MTAUDDEC_INPUT_ID_SCART_3,
    MTAUDDEC_INPUT_ID_AUXIN_0,
    MTAUDDEC_INPUT_ID_AUXIN_1,
    MTAUDDEC_INPUT_ID_MAX
}MTAUDDEC_INPUT_ID_T;

/*! \enum MTAUDDEC_DEC_STREAM_FROM_T
 *  \brief Audio stream source selection.
 */
typedef enum
{
    MTAUDDEC_STREAM_FROM_OTHERS = 0,         ///< ex. Pink Noise Generator
    MTAUDDEC_STREAM_FROM_DIGITAL_TUNER,      ///< Digital tuner. TS
    MTAUDDEC_STREAM_FROM_ANALOG_TUNER,       ///< ex. Analog tuner. SIF/AF
    MTAUDDEC_STREAM_FROM_SPDIF,              ///< SPDIF-in
    MTAUDDEC_STREAM_FROM_LINE_IN,            ///< Line in
    MTAUDDEC_STREAM_FROM_HDMI,               ///< HDMI in
    MTAUDDEC_STREAM_FROM_MEMORY,             ///< Memory, ex. memory clip
    MTAUDDEC_STREAM_FROM_MPLAYER,            ///< Media Player
    MTAUDDEC_STREAM_FROM_INTERNAL_BUF,       ///< Internal buffer
    MTAUDDEC_STREAM_FROM_MULTI_MEDIA,        /// < Multi-Media    
    MTAUDDEC_STREAM_FROM_LINE_IN_2 = 10,          ///< Line in2
    MTAUDDEC_STREAM_FROM_LINE_IN_3 = 11,          ///< Line in3 for Echo Cancel & BT.    
    MTAUDDEC_STREAM_FROM_NUM                 ///< Number of stream source
}MTAUDDEC_DEC_STREAM_FROM_T;


/*!\enum MTAUDDEC_AC3_DOWNMIX_MODE
 *  \brief AC3 downmix mode.
 */
typedef enum
{
    MTAUDDEC_AC3_DOWNMIX_LTRT = 0,         ///< Lt/Rt downmix
    MTAUDDEC_AC3_DOWNMIX_LORO,             ///< LoRo downmix
    MTAUDDEC_AC3_DOWNMIX_AUTO_LTRT,        ///< Auto Surround downmix
    MTAUDDEC_AC3_DOWNMIX_AUTO_LORO,        ///< Auto Stereo downmix
    MTAUDDEC_AC3_DOWNMIX_NUM
}MTAUDDEC_AC3_DOWNMIX_MODE;

/*! \enum MTAUDDEC_AC3_COMP_MODE_T
 *  \brief AC3 compression mode.
 */
typedef enum
{
    MTAUDDEC_AC3_COMP_CUSTOM_0 = 0,         ///< Customer 0
    MTAUDDEC_AC3_COMP_CUSTOM_1,             ///< Customer 1
    MTAUDDEC_AC3_COMP_LINE,                 ///< LINE mode
    MTAUDDEC_AC3_COMP_RF,                   ///< RF mode
    MTAUDDEC_AC3_COMP_NUM,
}MTAUDDEC_AC3_COMP_MODE_T;

/*! \enum MTAUDDEC_AC3_DUALMONO_MODE
 *  \brief AC3 dual mono mode.
 */
typedef enum
{
    MTAUDDEC_AC3_DUALMONO_STEREO = 0,       ///< Both channel as stereo
    MTAUDDEC_AC3_DUALMONO_MONO_L,           ///< Channel L only
    MTAUDDEC_AC3_DUALMONO_MONO_R,           ///< Channel R only
    MTAUDDEC_AC3_DUALMONO_MIX_MONO,         ///< Both channel mix together
    MTAUDDEC_AC3_DUALMONO_NUM,
}MTAUDDEC_AC3_DUALMONO_MODE;

/*! \enum MTAUDDEC_ATV_DETECT_MODE_T
 *  \brief Analog TV detect mode.
 */
typedef enum
{
    MTAUDDEC_ATV_DETECT_UNKOWN = 0,     ///< Unkown
    MTAUDDEC_ATV_DETECT_MONO,           ///< MTS/A2/EIAJ/FM-Mono mono
    MTAUDDEC_ATV_DETECT_STEREO,         ///< MTS/A2/EIAJ  stereo
    MTAUDDEC_ATV_DETECT_STEREO_SAP,     ///< MTS stereo + SAP
    MTAUDDEC_ATV_DETECT_SAP,            ///< MTS SAP
    MTAUDDEC_ATV_DETECT_DUAL,           ///< A2/EIAJ  dual
    MTAUDDEC_ATV_DETECT_NICAM_MONO,     ///< NICAM mono (with FM/AM mono)
    MTAUDDEC_ATV_DETECT_NICAM_STEREO,   ///< NICAM stereo (with FM/AM mono)
    MTAUDDEC_ATV_DETECT_NICAM_DUAL,     ///< NICAM dual (with FM/AM mono)
    MTAUDDEC_ATV_DETECT_MODE_NUM        ///< Number of atv detect mode
}MTAUDDEC_ATV_DETECT_MODE_T;

/*!\enum MTAUDDEC_SOUND_MODE_T
 *  \brief Analog TV output mode.
 */
typedef enum
{
    MTAUDDEC_SOUND_MODE_UNKNOWN = 0,    ///< Unkown
    MTAUDDEC_SOUND_MODE_MONO,           ///< MTS/A2/EIAJ/FM-Mono/AM-Mono mono
    MTAUDDEC_SOUND_MODE_STEREO,         ///< MTS/A2/EIAJ stereo
    MTAUDDEC_SOUND_MODE_SAP,            ///< MTS SAP
    MTAUDDEC_SOUND_MODE_DUAL1,          ///< A2/EIAJ dual 1
    MTAUDDEC_SOUND_MODE_DUAL2,          ///< A2/EIAJ dual 2
    MTAUDDEC_SOUND_MODE_NICAM_MONO,     ///< NICAM mono
    MTAUDDEC_SOUND_MODE_NICAM_STEREO,   ///< NICAM stereo
    MTAUDDEC_SOUND_MODE_NICAM_DUAL1,    ///< NICAM L:dual 1, R: dual 1
    MTAUDDEC_SOUND_MODE_NICAM_DUAL2,    ///< NICAM L:dual 2, R: dual 2
    MTAUDDEC_SOUND_MODE_A2_DUAL1_DUAL2, ///< A2/EIAJ L:dual 1, R: dual 2
    MTAUDDEC_SOUND_MODE_NICAM_DUAL1_DUAL2, ///< NICAM L:dual 1, R: dual 2
    MTAUDDEC_SOUND_MODE_NUM             ///< Number of sound mode
}MTAUDDEC_SOUND_MODE_T;


/*! \enum MTAUDDEC_SIF_STANDARD_T
 *  \brief SIF standard.
 * Should set to audio decoder before issue playback at EU/KOREA/EIAJ model.
 */
typedef enum
{
    MTAUDDEC_SIF_UNKNOWN = 0,
    MTAUDDEC_SIF_BG,           ///< TV-Sys: B/G, Audio Modulation: FM-Mono/NICAM
    MTAUDDEC_SIF_BG_A2,        ///< TV-Sys: B/G, Audio Modulation: FM-A2
    MTAUDDEC_SIF_I,            ///< TV-Sys: I,   Audio Modulation: FM-Mono/NICAM
    MTAUDDEC_SIF_DK,           ///< TV-Sys: D/K, Audio Modulation: FM-Mono/NICAM (D/K)
    MTAUDDEC_SIF_DK1_A2,       ///< TV-Sys: D/K, Audio Modulation: FM-A2 (D/K1)
    MTAUDDEC_SIF_DK2_A2,       ///< TV-Sys: D/K, Audio Modulation: FM-A2 (D/K2)
    MTAUDDEC_SIF_DK3_A2,       ///< TV-Sys: D/K, Audio Modulation: FM-A2 (D/K3)
    MTAUDDEC_SIF_L,            ///< TV-Sys: L,   Audio Modulation: AM-Mono/NICAM
    MTAUDDEC_SIF_A2_KOREA,     ///< TV-Sys: M/N, Audio Modulation: FM-Stereo
    MTAUDDEC_SIF_BTSC,         ///< TV-Sys: M/N, Audio Modulation: BTSC-Stereo + SAP
    MTAUDDEC_SIF_EIAJ,         ///< TV-Sys: M/N, Audio Modulation: FM-FM (EIAJ)
    MTAUDDEC_SIF_NUM
}MTAUDDEC_SIF_STANDARD_T;

/*! \enum MTAUDDEC_MODE_T
 *  \brief Digital audio type.
 */
typedef enum
{
    MTAUDDEC_MODE_UNKNOWN = 0,
    MTAUDDEC_MODE_MONO,                 ///< 1/0
    MTAUDDEC_MODE_MONO_SUB,             ///< 1+sub-language
    MTAUDDEC_MODE_DUAL_MONO,            ///< 1+1
    MTAUDDEC_MODE_STEREO,               ///< 2/0
    MTAUDDEC_MODE_STEREO_SUB,           ///< 2+sub-language
    MTAUDDEC_MODE_STEREO_DOLBY_SURROUND,///< 2/0, dolby surround
    MTAUDDEC_MODE_SURROUND_2CH,         ///< 2/1
    MTAUDDEC_MODE_SURROUND,             ///< 3/1
    MTAUDDEC_MODE_3_0,                  ///< 3/0
    MTAUDDEC_MODE_4_0,                  ///< 2/2
    MTAUDDEC_MODE_5_1,                  ///< 3/2
    MTAUDDEC_MODE_NUM                   ///< Number of decode type in AC3
}MTAUDDEC_MODE_T;

/*! \enum MTAUDDEC_CH_T
 *  \brief Individual audio channels
 */
typedef enum
{
    MTAUDDEC_CH_FRONT_LEFT = 0,
    MTAUDDEC_CH_FRONT_RIGHT,
    MTAUDDEC_CH_REAR_LEFT,
    MTAUDDEC_CH_REAR_RIGHT,
    MTAUDDEC_CH_CENTER,
    MTAUDDEC_CH_SUB_WOOFER,
    MTAUDDEC_CH_BYPASS_LEFT,
    MTAUDDEC_CH_BYPASS_RIGHT,
    MTAUDDEC_CH_DMX_LEFT,
    MTAUDDEC_CH_DMX_RIGHT,
    MTAUDDEC_CH_AUX_FRONT_LEFT,
    MTAUDDEC_CH_AUX_FRONT_RIGHT,
    MTAUDDEC_CH_INPUT_SRC,              ///< For input source volume control
    MTAUDDEC_CH_ALL,                    ///< For master volume control
    MTAUDDEC_CH_LFE,
    MTAUDDEC_CH_NUM
}MTAUDDEC_CH_T;

/*! \enum MTAUDDEC_IEC_T
*  \brief IEC format.
 */
typedef enum
{
    MTAUDDEC_IEC_CFG_PCM = 0,
    MTAUDDEC_IEC_CFG_RAW
}MTAUDDEC_IEC_T;

/*! \enum MTAUDDEC_SKP_OUTPUT_MODE_T
 *  \brief Speaker output mode.
 */
typedef enum
{
    MTAUDDEC_SPK_MODE_LR = 0,
    MTAUDDEC_SPK_MODE_LL,
    MTAUDDEC_SPK_MODE_RR,
    MTAUDDEC_SPK_MODE_MIX
}MTAUDDEC_SKP_OUTPUT_MODE_T;

/*! \enum MTAUDDEC_SAMPLE_FREQ_T
 *  \brief PCM sampling rate. Used in audio clip playback.
 */
typedef enum
{
    MTAUDDEC_FS_8K = 0,
    MTAUDDEC_FS_11K,
    MTAUDDEC_FS_12K,
    MTAUDDEC_FS_16K,
    MTAUDDEC_FS_22K,
    MTAUDDEC_FS_24K,
    MTAUDDEC_FS_32K,
    MTAUDDEC_FS_44K,
    MTAUDDEC_FS_48K,
    MTAUDDEC_FS_64K,
    MTAUDDEC_FS_88K,
    MTAUDDEC_FS_96K,
    MTAUDDEC_FS_176K,
    MTAUDDEC_FS_192K,
    MTAUDDEC_FS_NUM
}MTAUDDEC_SAMPLE_FREQ_T;

/*! \enum MTAUDDEC_PCM_INPUT_TYPE_T
 *  \brief PCM data format. Used in audio clip playback.
 */
typedef enum
{
    MTAUDDEC_PCM_24_BITS = 0,           ///< 24 bits (only support big endian)
    MTAUDDEC_PCM_16_BITS_BIG_ENDIAN,    ///< 16 bits with big endian
    MTAUDDEC_PCM_16_BITS_LITTLE_ENDIAN, ///< 16 bits with little endian
    MTAUDDEC_PCM_NUM
}MTAUDDEC_PCM_INPUT_TYPE_T;

/*! \enum MTAUDDEC_VSURR_CFG_TYPE_T
 *  \brief MTK surround parameters setup
 */
typedef enum
{
    MTAUDDEC_SUR_CLARITY = 0,
    MTAUDDEC_SUR_WIDTH,
    MTAUDDEC_SUR_LRGAIN,
    MTAUDDEC_SUR_XTALK,
    MTAUDDEC_SUR_OUTPUT_GAIN,
    MTAUDDEC_SUR_BASS_GAIN,
    MTAUDDEC_SUR_FO,
    MTAUDDEC_SUR_MAX
}   MTAUDDEC_VSURR_CFG_TYPE_T;
typedef enum
{
     MTAUDDEC_AUD_STREAM_FROM_OTHERS = 0,         ///< ex. Pink Noise Generator
     MTAUDDEC_AUD_STREAM_FROM_DIGITAL_TUNER,      ///< Digital tuner. TS
     MTAUDDEC_AUD_STREAM_FROM_ANALOG_TUNER,       ///< ex. Analog tuner. SIF/AF
     MTAUDDEC_AUD_STREAM_FROM_SPDIF,              ///< SPDIF-in
     MTAUDDEC_AUD_STREAM_FROM_LINE_IN,            ///< Line in
    MTAUDDEC_AUD_STREAM_FROM_HDMI,               ///< HDMI in
     MTAUDDEC_AUD_STREAM_FROM_MEMORY,             ///< Memory
     MTAUDDEC_AUD_STREAM_FROM_BUF_AGT,            ///< Buffer agent
     MTAUDDEC_AUD_STREAM_FROM_FEEDER,             ///< Feeder
    MTAUDDEC_AUD_STREAM_FROM_MULTI_MEDIA,        /// < Multi-Media
#ifdef KARAOKE_MIC_LINE_IN2
     MTAUDDEC_AUD_STREAM_FROM_LINE_IN_2,          ///< Line in2
#endif
#ifdef CC_ENABLE_AOMX
     MTAUDDEC_AUD_STREAM_FROM_GST,                    /// Gstreamer
#endif
#ifdef CC_AUD_I2S_IN
     MTAUDDEC_AUD_STREAM_FROM_I2S,                ///<I2S in
#endif
     MTAUDDEC_AUD_STREAM_FROM_NUM                 ///< Number of stream source
}    MTAUDDEC_AUD_DEC_STREAM_FROM_T;

/*! \enum MTAUDDEC_AVC_CFG_TYPE_T
 *  \brief AVC parameters setup.
 */
typedef enum
{
    MTAUDDEC_AVC_TARGET_LEVEL = 0,
    MTAUDDEC_AVC_MAX_GAIN_UP,
    MTAUDDEC_AVC_ATTACK_RATE,
    MTAUDDEC_AVC_RELEASE_RATE,
    MTAUDDEC_AVC_FC,
    MTAUDDEC_AVC_MAX
}   MTAUDDEC_AVC_CFG_TYPE_T;

/*! \enum MTAUDDEC_BE_PARAM_TYPE_T
 *  \brief Bass enhancer parameters setup.
 */
typedef enum
{
    MTAUDDEC_BE_OUTPUT_GAIN = 0,
    MTAUDDEC_BE_BASS_GAIN,
    MTAUDDEC_BE_PARAM3,
    MTAUDDEC_BE_PARAM4,
    MTAUDDEC_BE_PARAM5,
    MTAUDDEC_BE_PARAM6,
    MTAUDDEC_BE_MAX
}   MTAUDDEC_BE_PARAM_TYPE_T;

/*! \enum MTAUDDEC_PEQ_Q_TYPE_T
 *  \brief PEQ Q value.
 */
typedef enum
{
    MTAUDDEC_PEQ_Q_0_33 = 0,
    MTAUDDEC_PEQ_Q_0_43,
    MTAUDDEC_PEQ_Q_0_56,
    MTAUDDEC_PEQ_Q_0_75,
    MTAUDDEC_PEQ_Q_1_00,
    MTAUDDEC_PEQ_Q_1_20,
    MTAUDDEC_PEQ_Q_1_50,
    MTAUDDEC_PEQ_Q_1_80,
    MTAUDDEC_PEQ_Q_2_20,
    MTAUDDEC_PEQ_Q_2_27,
    MTAUDDEC_PEQ_Q_3_30,
    MTAUDDEC_PEQ_Q_3_39,
    MTAUDDEC_PEQ_Q_4_70,
    MTAUDDEC_PEQ_Q_5_60,
    MTAUDDEC_PEQ_Q_6_80,
    MTAUDDEC_PEQ_Q_8_20,
    MTAUDDEC_PEQ_Q_MAX
}   MTAUDDEC_PEQ_Q_TYPE_T;
	/* Audio EQ table.*/
   typedef enum
  {
	MTAUDDEC_EQ_OFF = 0,
	MTAUDDEC_EQ_ROCK,
	MTAUDDEC_EQ_POP,
	MTAUDDEC_EQ_LIVE,
	MTAUDDEC_EQ_DANCE,
	MTAUDDEC_EQ_TECHNO,
	MTAUDDEC_EQ_CLASSIC,
	MTAUDDEC_EQ_SOFT,
	MTAUDDEC_EQ_CUST1,
	MTAUDDEC_EQ_CUST2,
	MTAUDDEC_EQ_CUST3,
	MTAUDDEC_EQ_CUST4,
	MTAUDDEC_EQ_CUST5,
	MTAUDDEC_EQ_CUST6,
	MTAUDDEC_EQ_CUST7,
	MTAUDDEC_EQ_CUST8,
	MTAUDDEC_EQ_BBE_TV,
	MTAUDDEC_EQ_BBE_AV,
	MTAUDDEC_EQ_SBASS,
	MTAUDDEC_EQ_NUM
  }   MTAUDDEC_EQ_TYPE_T;

/*! \struct MTAUDDEC_PCM_SETTING_T mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief PCM setting. Used in audio clip playback.
 *  \var MTAUDDEC_PCM_SETTING_T::eSampleFreq
 *  Member 'eSampleFreq' contains Sample Rate information
 *  \var MTAUDDEC_PCM_SETTING_T::ePcmDataInfo
 *  Member 'ePcmDataInfo' contains data infomation
 */
typedef struct
{
    MTAUDDEC_SAMPLE_FREQ_T      eSampleFreq;  ///< PCM Sampling Rate.
    MTAUDDEC_PCM_INPUT_TYPE_T   ePcmDataInfo; ///< PCM data information
}MTAUDDEC_PCM_SETTING_T;

typedef enum
{
	MTAUDDEC_LPCM_NORAML = 0,
	MTAUDDEC_LPCM_MS_ADPCM = 1,
	MTAUDDEC_LPCM_IMA_ADPCM = 2,
	MTAUDDEC_LPCM_A_LAW = 3,
	MTAUDDEC_LPCM_U_LAW = 4
} MTAUDDEC_LPCM_TYPE_T;

typedef struct
{
	MTAUDDEC_LPCM_TYPE_T  eLPcmType;
	UINT32			   ui4_sample_rate; 
	UINT16			   ui2_num_ch;
	UINT16			   ui2_block_align;
	UINT16			   ui2_bits_per_sample;
	BOOL			   b_big_endian;
	BOOL			   b_info_not_specific; /*pcm info from dmx*/
	BOOL			   b_signed_data;
} MTAUDDEC_LPCM_INFO_T;

/*! MTAUDDEC_CB_FUNC_ID_T
 *  \brief Audio decoder notification function type id.
 */
typedef enum
{
    MTAUDDEC_CB_FUNC_MODE_CHG_ID = 0,   ///< Audio mode change
    MTAUDDEC_CB_FUNC_MP3_ERROR_ID,  ///< MP3 Error
    MTAUDDEC_CB_FUNC_MIXSOUND_CTRL_ID,
    MTAUDDEC_CB_FUNC_CLIP_DONE_ID,
    MTAUDDEC_CB_FUNC_COMMAND_DONE_ID,
    MTAUDDEC_CB_FUNC_STREAM_FORMAT_CHANGE_ID,
    MTAUDDEC_CB_FUNC_MUTE_STATE_CHANGE_ID,
    MTAUDDEC_CB_FUNC_DEC_STATE_CHANGE_ID,
    MTAUDDEC_CB_FUNC_MEM_STATE_CHANGE_ID,
    MTAUDDEC_CB_FUNC_NFY_ID,
    MTAUDDEC_CB_FUNC_ID_MAX
}MTAUDDEC_CB_FUNC_ID_T;

/*! \enum MTAUDDEC_AUD_MW_CB_FUNC_ID_T
 *  \brief Audio decoder notification function type id.
*/
typedef enum
{
    MTAUDDEC_AUD_MW_CB_FUNC_NFY = 0,
    MTAUDDEC_AUD_MW_CB_FUNC_HEADPHONE_DETECT_NFY,
    MTAUDDEC_AUD_MW_CB_FUNC_UPLOAD_DATA_NFY,
    MTAUDDEC_AUD_MW_CB_FUNC_DMX_NFY,
    MTAUDDEC_AUD_MW_CB_FUNC_DMX_AUDSETCTRL,
    MTAUDDEC_AUD_MW_CB_FUNC_ID_MAX
}MTAUDDEC_AUD_MW_CB_FUNC_ID_T;    

/*! \enum MTAUDDEC_MP3_ERROR_T
 *  \brief Mp3 error type.
 */
typedef enum
{
    MTAUDDEC_MP3_ERROR_HEADER,     ///< Header error
    MTAUDDEC_MP3_ERROR_CRC,        ///< CRC Error
    MTAUDDEC_MP3_ERROR_FIELD_SIZE, ///< Field size Error
    MTAUDDEC_MP3_ERROR_MAX
}MTAUDDEC_MP3_ERROR_T;

/*! \enum MTAUDDEC_NFY_TAG_T
 *  \brief notification
 */
typedef enum
{
    MTAUDDEC_NFY_STREAM = 0, ///< notification of stream
    MTAUDDEC_NFY_HP ///< notification of HeadPhone
}   MTAUDDEC_NFY_TAG_T;

/*! \enum MTAUDDEC_COND_NFY_T
 *  \brief Notification
 */
typedef enum
{
    MTAUDDEC_COND_ERROR = -1,
    MTAUDDEC_COND_CTRL_DONE,
    MTAUDDEC_COND_AUD_CLIP_DONE,
    MTAUDDEC_COND_MEM_BUFFER_DONE,
    MTAUDDEC_COND_FLUSH_DONE,
    MTAUDDEC_COND_FEED_ME_ON,
    MTAUDDEC_COND_FEED_ME_OFF,
    MTAUDDEC_COND_AUD_INFO_CHG,
    MTAUDDEC_COND_TV_SYS_DETECTED,
    MTAUDDEC_COND_AUD_DECODE_STATUS_CHG,
    MTAUDDEC_COND_MM_EOS,
    MTAUDDEC_COND_FM_RADIO_DET_DONE,
    MTAUDDEC_COND_PROTECT_INFO,
    MTAUDDEC_COND_UPLOAD_INFO_CHG,
    MTAUDDEC_COND_BLUETOOTH_INFO_CHG,
    MTAUDDEC_COND_AUD_CLIP_PLAY_DONE,
    MTAUDDEC_COND_AUD_CODEC_CHG,      //audio codec change notify
    MTAUDDEC_COND_AUD_BIT_RATE_CHG,
    MTAUDDEC_COND_STREAM_FORMAT_CHG,
    MTAUDDEC_COND_MUTE_STATE_CHG,
    MTAUDDEC_COND_AUD_MEM_STATE_CHG,
    MTAUDDEC_COND_INPUT_SOURCE_STATE_CHG,
}   MTAUDDEC_COND_NFY_T;

typedef struct _MTAUDDEC_COND_INFO_T
{
    VOID *pvTag;
    UINT8 u1Device;
    MTAUDDEC_COND_NFY_T eNfyId;
    UINT32 u4Param1;
    UINT32 u4Param2;
} MTAUDDEC_COND_INFO_T;

/*! \enum MTAUDDEC_DECODE_STATUS_T
 *  \brief Decode Status
 */
typedef enum
{
    MTAUDDEC_DECODE_UNKNOWN = -1,   ///< initial value; the decode status should be initialized to this value after connect/disconnect or AUD_DEC_CTRL_STOP
    MTAUDDEC_DECODE_NO_DATA,        ///< audio decoder found no audio data in stream. there will be a timer threashold value for decoder to change the decode status from NORMAL/ERROR to NO_DATA
    MTAUDDEC_DECODE_NORMAL,         ///< audio decoder decode the first audio frame data successfully after AUD_DEC_CTRL_PLAY
    MTAUDDEC_DECODE_ERROR,          ///< audio decoder decode the audio data abnormally (e.g. unsupported format)
    MTAUDDEC_DECODE_NOT_SUPPORT,	///< unsupported format for WMA decoder
    MTAUDDEC_DECODE_FMT_CONFLICT
}   MTAUDDEC_DECODE_STATUS_T;

typedef enum
{
	MTAUDDEC_DEC_PLAYING = 0,
	MTAUDDEC_DEC_PLAY,
	MTAUDDEC_DEC_PAUSING,
	MTAUDDEC_DEC_PAUSE,
	MTAUDDEC_DEC_RESUMING,
	MTAUDDEC_DEC_RESUME,
	MTAUDDEC_DEC_STOPPING,
	MTAUDDEC_DEC_STOP,
	MTAUDDEC_DEC_ERROR,
}MTAUDDEC_DEC_STATE_T;

typedef enum
{
	MTAUDDEC_MEM_DECODE_UNKNOWN = -1,
	MTAUDDEC_MEM_DECODE_DONE,
	MTAUDDEC_MEM_ENDOF_DATA,
	MTAUDDEC_MEM_NO_DATA,
	MTAUDDEC_MEM_NORMAL,
	MTAUDDEC_MEM_ERROR,
	MTAUDDEC_MEM_NOT_SUPPORT
}MTAUDDEC_MEM_STATE_T;

typedef enum
{
    MTAUDDEC_SOURCE_UNKOWN = -1,
    MTAUDDEC_SOURCE_NO_SIGNAL,
    MTAUDDEC_SOURCE_STABLE,
    MTAUDDEC_SOURCE_UNSTABLE,
} MTAUDDEC_SOURCE_STATE_T;

typedef enum
{
	MTAUDDEC_CMD_PLAY       = 0,
    MTAUDDEC_CMD_STOP       = 1,
    MTAUDDEC_CMD_RESET      = 2,
    MTAUDDEC_CMD_PAUSE      = 3,
    MTAUDDEC_CMD_AVSYNC     = 4,
    MTAUDDEC_CMD_LOADCODE   = 5,
    MTAUDDEC_CMD_RESUME  = 6,
    MTAUDDEC_CMD_CHANGE_FORMAT = 7,
    MTAUDDEC_CMD_STOPSTREAM = 8,
    MTAUDDEC_CMD_UNMUTE     = 9,
}MTAUDDEC_CMD_T;

/*! \enum MTAUDDEC_MIXSOUND_CTRL_T
 *  \brief Mixsound ctrl type.
 */
typedef enum
{
    MTAUDDEC_MIXSOUND_CTRL_PLAY_DONE,
    MTAUDDEC_MIXSOUND_CTRL_MAX
}MTAUDDEC_MIXSOUND_CTRL_T;

/*! \enum MTAUDDEC_ENCODING_FORMAT_T
 *  \brief Format of Encoder.
 */
typedef enum
{
	MTAUDENC_ENCODE_MP3 ,	//Encode MP3 format
	MTAUDENC_ENCODE_AAC	,	//Encode AAC format
	MTAUDENC_ENCODE_PCM		//Encode PCM format	
}MTAUDDEC_ENCODING_FORMAT_T;

/*! \enum MTAUD_OUT_PORT_T
 *  \brief Out port
 */
typedef enum
{
	MTAUD_SPEAKER = 0,
	MTAUD_HEADPHONE,
	MTAUD_SPDIF,
	MTAUD_AV_OUT,
	MTAUD_MONITOR_SCART,
	MTAUD_TV_SCART,
	MTAUD_BLUETOOTH,
	MTAUD_OUT_PORT_NUM
}MTAUD_OUT_PORT_T;

typedef enum _MTAUDDEC_STATE_T
{
    MTAUDDEC_AUD_DEC_STOP = 0,
    MTAUDDEC_AUD_DEC_PLAYING,
    MTAUDDEC_AUD_DEC_PAUSE,
    MTAUDDEC_AUD_DEC_INIT
}   MTAUDDEC_STATE_T;

/*
Audio query idx.
*/
typedef enum
{
	MTAUDDEC_QUERY_PACKET_COUNT = 0,
	MTAUDDEC_QUERY_FRAME_COUNT,
	MTAUDDEC_QUERY_DECODER_STATUS,
	MTAUDDEC_QUERY_STREAM_TYPE,
	MTAUDDEC_QUERY_LEFT_VOL,
	MTAUDDEC_QUERY_RIGHT_VOL,
	MTAUDDEC_QUERY_IS_MUTE,
	MTAUDDEC_QUERY_SAMPLE_RATE,
	MTAUDDEC_QUERY_BIT_WIDTH,
	MTAUDDEC_QUERY_SOURCE_TYPE,
	MTAUDDEC_QUERY_PES_BUFFER_SIZE,
	MTAUDDEC_QUERY_PES_BUFFER_FREE_SIZE,
	MTAUDDEC_QUERY_ES_BUFFER_SIZE,
	MTAUDDEC_QUERY_ES_BUFFER_FREE_SIZE,
	MTAUDDEC_QUERY_STC,
	MTAUDDEC_QUERY_PTS,
	MTAUDDEC_QUERY_FIRST_PTS,
	MTAUDDEC_QUERY_PID,
	MTAUDDEC_QUERY_END
}MTAUDDEC_DEC_QUERY_IDX_T;
/*
Audio Info
*/
typedef struct MTAUDDEC_AUDIO_INFO
{
	UINT32 u4PacketCount;
	UINT32 u4FrameCount;
	MTAUDDEC_STATE_T DecoderStatus;
	MTAUDDEC_FMT_T StreamType;
	UINT32 u4LeftVol;
	UINT32 u4RightVol;
	UINT32 u4IsMute;
	UINT32 u4SampleRate;
	UINT32 u4BitWidth;
	MTAUDDEC_DEC_STREAM_FROM_T SourceType;
	UINT32 u4PesBufferSize;
	UINT32 u4PesBufferFreeSize;
	UINT32 u4EsBufferSize;
	UINT32 u4EsBufferFreeSize;
	UINT32 u4Stc;
	UINT32 u4Pts;
	UINT32 u4FirstPts;
	UINT32 u4Pid;
}MTAUDDEC_AUDIO_INFO_T;
/*! \typedef MTAUDDEC_MODE_CHG 
 *  \brief Audio mode change notify function type
 */
typedef void (*MTAUDDEC_MODE_CHG)(
        UINT8  u1DecId,
    MTAUDDEC_MODE_T eMode,
    MTAUDDEC_SAMPLE_FREQ_T eSamFreq
    );

/*! \typedef MTAUDDEC_MP3_ERROR
 *  \brief Mp3 error function type
 */
typedef void (*MTAUDDEC_MP3_ERROR)(
        UINT8  u1DecId,
    MTAUDDEC_MP3_ERROR_T eErrorType
    );

/*! \typedef MTAUDDEC_MIXSOUND_CTRL
 *  \brief Mixsound ctrl function type
 */
    typedef void (*MTAUDDEC_MIXSOUND_CTRL)(
    MTAUDDEC_MIXSOUND_CTRL_T eCtrlType
    );

/*!\if LGSE 
 *  \typedef MTAUDDEC_CLIP_DONE_CTRL
 *  \brief Clip done ctrl function type
 *  \endif
 */
    typedef void (*MTAUDDEC_CLIP_DONE_CTRL)(
        void
    );

    typedef void (*MTAUDDEC_COND_NTY_CTRL)(
        VOID *,
        UINT8,
        MTAUDDEC_COND_NFY_T,
        UINT32,
        UINT32
    );
	
/*! \typedef MTAUDDEC_COMMAND_DONE_CTRL
 *  \brief Command done ctrl function type
 */
typedef void (*MTAUDDEC_COMMAND_DONE_CTRL)(
	UINT8 u1DecId, 
	MTAUDDEC_CMD_T eCmd, 
	BOOL fgResult);

/*! \typedef MTAUDDEC_STREAM_FORMAT_CHANGE_CTRL
 *  \brief Stream format change function type
 */
typedef void (*MTAUDDEC_STREAM_FORMAT_CHANGE_CTRL)(
    UINT8 u1DecId,
    MTAUDDEC_DEC_STREAM_FROM_T eStream,
    MTAUDDEC_FMT_T eFmt);

/*! \typedef MTAUDDEC_MUTE_STATE_CHANGE_CTRL
 *  \brief Mute state change function type
 */
typedef void (*MTAUDDEC_MUTE_STATE_CHANGE_CTRL)(
    MTAUD_OUT_PORT_T ePort,
    BOOL fgMute);

/*! \typedef MTAUDDEC_DEC_STATE_CHANGE_CTRL
 *  \brief Decode state change function type
 */
typedef void (*MTAUDDEC_DEC_STATE_CHANGE_CTRL)(
    UINT8 u1DecId,
    MTAUDDEC_DECODE_STATUS_T eDecStatus);

/*! \typedef MTAUDDEC_MEM_STATE_CHANGE_CTRL
 *  \brief Memory play state change function type
 */
typedef void (*MTAUDDEC_MEM_STATE_CHANGE_CTRL)(
    UINT8 u1DecId,
    MTAUDDEC_MEM_STATE_T eMemStatus);

/*! \enum _AUD_FMT_T
 *  \brief Audio Format
 */
typedef enum
{
    _AUD_FMT_UNKNOWN = 0,
    _AUD_FMT_MPEG,
    _AUD_FMT_AC3,
    _AUD_FMT_PCM,
    _AUD_FMT_MP3,
    _AUD_FMT_AAC,
    _AUD_FMT_DTS,
    _AUD_FMT_WMA,
    _AUD_FMT_RA,
    _AUD_FMT_HDCD,
    _AUD_FMT_MLP,     // 10
    _AUD_FMT_MTS,
    _AUD_FMT_EU_CANAL_PLUS,
    _AUD_FMT_PAL,
    _AUD_FMT_A2,
    _AUD_FMT_FMFM,
    _AUD_FMT_NICAM,
    _AUD_FMT_TTXAAC,
    _AUD_FMT_DETECTOR,
    _AUD_FMT_MINER,
    _AUD_FMT_LPCM,       // 20
    _AUD_FMT_FMRDO,
    _AUD_FMT_FMRDO_DET,
    _AUD_FMT_SBCDEC,
    _AUD_FMT_SBCENC,     // 24, 
    _AUD_FMT_MP3ENC,     // 25, MP3ENC_SUPPORT
    _AUD_FMT_G711DEC,    // 26
    _AUD_FMT_G711ENC,    // 27
    _AUD_FMT_DRA,        // 28
    _AUD_FMT_COOK,        // 29
    _AUD_FMT_G729DEC,     // 30
    _AUD_FMT_VORBISDEC,   //31, CC_VORBIS_SUPPORT, please sync number with middleware\res_mngr\drv\x_aud_dec.h
    _AUD_FMT_WMAPRO,    //32  please sync number with middleware\res_mngr\drv\x_aud_dec.h
    _AUD_FMT_WMA10LOSSLESS,  //33, reserved for future development
    _AUD_FMT_WMA10SPEECH, //34, reserved for future development
    _AUD_FMT_AMR,        //35 amr-nb run in DSP
    _AUD_FMT_AWB,        //36 amr-wb run in DSP
    _AUD_FMT_APE,        //37 //ian APE decoder

    _AUD_FMT_OMX_MSADPCM = 0x80,
    _AUD_FMT_OMX_IMAADPCM = 0x81,
    _AUD_FMT_OMX_ALAW = 0x82,
    _AUD_FMT_OMX_ULAW = 0x83,
}   _AUD_FMT_T;

/*!\enum _AUD_TYPE_T
 *  \brief Audio Type
 */
typedef enum
{
    _AUD_TYPE_UNKNOWN = 0,
    _AUD_TYPE_MONO,                  ///< 1/0 
    _AUD_TYPE_MONO_SUB,              ///< 1+sub-language 
    _AUD_TYPE_DUAL_MONO,             ///< 1+1 
    _AUD_TYPE_STEREO,                ///< 2/0 
    _AUD_TYPE_STEREO_SUB,            ///< 2+sub-language 
    _AUD_TYPE_STEREO_DOLBY_SURROUND, ///< 2/0, dolby surround 
    _AUD_TYPE_SURROUND_2CH,          ///< 2/1 
    _AUD_TYPE_SURROUND,              ///< 3/1 
    _AUD_TYPE_3_0,                   ///< 3/0 
    _AUD_TYPE_4_0,                   ///< 2/2 
    _AUD_TYPE_5_1,                   ///< 3/2 +SW 
    _AUD_TYPE_7_1,                   ///< 5/2 
    _AUD_TYPE_FM_MONO_NICAM_MONO,
    _AUD_TYPE_FM_MONO_NICAM_STEREO,
    _AUD_TYPE_FM_MONO_NICAM_DUAL,
    _AUD_TYPE_OTHERS,
    _AUD_TYPE_5_0,                    ///< 3/2 
    _AUD_TYPE_JOINT_STEREO,
    _AUD_TYPE_FMRDO_MONO,
    _AUD_TYPE_FMRDO_STEREO,
    
    _AUD_TYPE_MONO_LFE,                 ///< 1/0.L 
    _AUD_TYPE_DUAL_MONO_LFE,            ///< 1+1.L 
    _AUD_TYPE_STEREO_LFE,               ///< 2/0.L 
    _AUD_TYPE_SURROUND_2CH_LFE,         ///< 2/1.L 
    _AUD_TYPE_SURROUND_LFE,             ///< 3/1.L 
    _AUD_TYPE_3_1,                  ///< 3/0.L 
    _AUD_TYPE_4_1                  ///< 2/2.L 
} _AUD_TYPE_T;

/*! \enum _AUD_DECODE_TYPE_T
 *  \brief audio decod types.
 */
typedef enum
{
    _AUD_DECODE_TYPE_UNKNOWN = 0,
    _AUD_DECODE_TYPE_AC3, ///< AC3
    _AUD_DECODE_TYPE_EAC3, ///<  EAC3
    _AUD_DECODE_TYPE_FLAC, ///<paul_flac
} _AUD_DECODE_TYPE_T;

/*! \struct _AUD_DEC_INFO_T mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief Audio Decoder Information
 *  \var _AUD_DEC_INFO_T::e_aud_fmt
 *  Member 'e_aud_fmt' contains audio format information
 *  \var _AUD_DEC_INFO_T::e_aud_type
 *  Member 'e_aud_type' contains audio coding mode information
 *  \var _AUD_DEC_INFO_T::ui4_sample_rate
 *  Member 'ui4_sample_rate' contains audio sample rate information
 *  \var _AUD_DEC_INFO_T::ui4_data_rate
 *  Member 'ui4_data_rate' contains audio data rate information
 *  \var _AUD_DEC_INFO_T::ui1_bit_depth
 *  Member 'ui1_bit_depth' contains audio bit depth information
 *  \var _AUD_DEC_INFO_T::e_dec_type
 *  Member 'e_dec_type' contains audio decoder type information
 */
typedef struct
{
    _AUD_FMT_T   e_aud_fmt; ///< audio format
    _AUD_TYPE_T  e_aud_type; ///< audio type
    UINT32      ui4_sample_rate; ///< sample rate
    UINT32      ui4_data_rate; ///< data rate
    UINT8       ui1_bit_depth; ///< bit depth
    _AUD_DECODE_TYPE_T    e_dec_type; ///< decoder type
} _AUD_DEC_INFO_T;

/*! \struct MTAUDDEC_CB_T mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief Audio callback structure
 *  \var MTAUDDEC_CB_T::u4Arg1
 *  Member 'u4Arg1' argument 1
 *  \var MTAUDDEC_CB_T::u4Arg2
 *  Member 'u4Arg2' argument 2
 *  \var MTAUDDEC_CB_T::u4Arg3
 *  Member 'u4Arg3' argument 3
 *  \var MTAUDDEC_CB_T::u4Arg4
 *  Member 'u4Arg4' argument 4
 *  \var MTAUDDEC_CB_T::u4Arg5
 *  Member 'u4Arg5' argument 5
 *  \var MTAUDDEC_CB_T::u4Arg6
 *  Member 'u4Arg6' argument 6
 *  \var MTAUDDEC_CB_T::u4Arg7
 *  Member 'u4Arg7' argument 7
 *  \var MTAUDDEC_CB_T::u4Arg8
 *  Member 'u4Arg8' argument 8
 *  \var MTAUDDEC_CB_T::rAudDecInfo
 *  Member 'rAudDecInfo' contains audio decoder information
 */
    typedef struct
    {
        UINT32 u4Arg1;
        UINT32 u4Arg2;
        UINT32 u4Arg3;
        UINT32 u4Arg4;
        UINT32 u4Arg5;
        UINT32 u4Arg6;
        UINT32 u4Arg7;
        UINT32 u4Arg8;
        _AUD_DEC_INFO_T rAudDecInfo; ///< audio decoder information
}MTAUDDEC_CB_T;

/*! \if LGSE
 *  \struct MTAUDDEC_AC3_ES_INFO mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief AC3 ES Info
 *  \var MTAUDDEC_AC3_ES_INFO::bitRate
 *  Member 'bitRate' contains bit Rate information.
 *  \var MTAUDDEC_AC3_ES_INFO::sampleRate
 *  Member 'bitRate' contains sample Rate information.
 *  \var MTAUDDEC_AC3_ES_INFO::channelNum
 *  Member 'bitRate' contains channel Number information(mono=0x0,Lo/Ro= 0x1,L/R/=0x2,L/R/LS/RS =0x3).
 *  \var MTAUDDEC_AC3_ES_INFO::EAC3
 *  Member 'bitRate' contains AC3 decode type(AC3 0x0, EAC3 0x1).
 *  \endif
 */
 /*!\if LGSE 
  *  \typedef MTAUDDEC_AC3_ES_INFO_T
  *  \brief Create a type name for MTAUDDEC_AC3_ES_INFO
  *  \endif
  */
 typedef struct MTAUDDEC_AC3_ES_INFO
 {
     UINT8 bitRate; ///< bit rate
     UINT8 sampleRate; ///< sample rate
     UINT8 channelNum;///< it is not fixed yet depend on mstar definition mono=0x0,Lo/Ro= 0x1,L/R/=0x2,L/R/LS/RS =0x3
     UINT8  EAC3;       ///< AC3 0x0, EAC3 0x1
}MTAUDDEC_AC3_ES_INFO_T;

/*!\if LGSE 
 *  \struct MTAUDDEC_MPEG_ES_INFO mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief MPEG ES Info
 *  \var MTAUDDEC_MPEG_ES_INFO::bitRate
 *  Member 'bitRate' contains bit Rate information.
 *  \var MTAUDDEC_MPEG_ES_INFO::sampleRate
 *  Member 'bitRate' contains sample Rate information.
 *  \var MTAUDDEC_MPEG_ES_INFO::layer
 *  Member 'layer' contains layer information.
 *  \var MTAUDDEC_MPEG_ES_INFO::channelNum
 *  Member 'channelNum' contains channel Number information(mono =0x0,stereo=0x1,multi-channel =0x2).
 *  \endif
 */
 /*! \if LGSE
  *  \typedef MTAUDDEC_MPEG_ES_INFO_T
  *  \brief Create a type name for MTAUDDEC_MPEG_ES_INFO
  *  \endif
  */
typedef struct MTAUDDEC_MPEG_ES_INFO
{
     UINT8 bitRate; ///< bit rate
     UINT8 sampleRate; ///< sample rate
     UINT8 layer; ///< layer no.
     UINT8  channelNum; ///< mono =0x0,stereo=0x1,multi-channel =0x2
}MTAUDDEC_MPEG_ES_INFO_T;

/*! \if LGSE
 *  \struct MTAUDDEC_HEAAC_ES_INFO mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief HE-AAC ES Info
 *  \var MTAUDDEC_HEAAC_ES_INFO::version
 *  Member 'version' contains version information(AAC 0x0  HE-AACv1= 0x1,HE-AACv2=0x2).
 *  \var MTAUDDEC_HEAAC_ES_INFO::transmissionformat
 *  Member 'transmissionformat' contains transmission format(LOAS/LATM =0x0 , ADTS=0x1).
 *  \var MTAUDDEC_HEAAC_ES_INFO::channelNum
 *  Member 'channelNum' contains channel Number information.
 *  \endif
 */
  /*! \if LGSE
  *  \typedef MTAUDDEC_HEAAC_ES_INFO_T
  *  \brief Create a type name for MTAUDDEC_HEAAC_ES_INFO
  *  \endif
  */
typedef struct MTAUDDEC_HEAAC_ES_INFO
{
     UINT8 version;    		  ///< AAC 0x0  HE-AACv1= 0x1,HE-AACv2=0x2 
     UINT8 transmissionformat;     ///< LOAS/LATM =0x0 , ADTS=0x1
     UINT8 channelNum; ///< channel number
}MTAUDDEC_HEAAC_ES_INFO_T;

/*! \if LGSE
 *  \struct MTAUDDEC_HDMI_SCMS_INFO mtauddec.h ".../mtal/mtal_inc/mtauddec.h"
 *  \brief HDMI SCMS Info
 *  \var MTAUDDEC_HDMI_SCMS_INFO::CopyRight
 *  Member 'CopyRight' contains CopyRight information.
 *  \var MTAUDDEC_HDMI_SCMS_INFO::Category_code_0_2
 *  Member 'Category_code_0_2' contains category code bit0 ~ bit2.
 *  \var MTAUDDEC_HDMI_SCMS_INFO::Category_code_0_6
 *  Member 'Category_code_0_6' contains category code bit0 ~ bit6.
 *  \var MTAUDDEC_HDMI_SCMS_INFO::Category_code_3
 *  Member 'Category_code_3' contains category code bit3.
 *  \var MTAUDDEC_HDMI_SCMS_INFO::LBit
 *  Member 'LBit' contains category code bit7.
 *  \endif
 */
 /*!\if LGSE 
  *  \typedef MTAUDDEC_HDMI_SCMS_INFO_T
  *  \brief Create a type name for MTAUDDEC_HDMI_SCMS_INFO
  *  \endif
  */
typedef struct MTAUDDEC_HDMI_SCMS_INFO
{
     UINT8 CopyRight; ///< Copyright
     UINT8 Category_code_0_2;  ///< category code bit0 ~ bit2
     UINT8 Category_code_0_6;  ///< category code bit0 ~ bit6
     UINT8 Category_code_3;	  ///< category code bit3
     UINT8 LBit; 			  ///< category code bit7
}MTAUDDEC_HDMI_SCMS_INFO_T;

/*! @} */

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/*! \addtogroup mtauddec_apis APIs
 *  \brief APIs of Audio Decoder Modules for MTAL
 * @{
 */

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_Init (void)
 *  \brief Initialize Auio Decoder module.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_Init (void);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetDecType (UINT8 u1DecId,
 *                          MTAUDDEC_DEC_STREAM_FROM_T *peStreamFrom,
 *                          MTAUDDEC_FMT_T *prDecType)
 *  \brief Get audio decoder type and stream source configuration.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peStreamFrom Stream source.
 *  \param [out] prDecType Decoder format.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetDecType (UINT8 u1DecId,
            MTAUDDEC_DEC_STREAM_FROM_T *peStreamFrom,
            MTAUDDEC_FMT_T *prDecType);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetDecType (UINT8 u1DecId,
 *                          MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom,
 *                          MTAUDDEC_FMT_T eDecFmt)
 *
 *  \brief Set audio decoder type and stream source.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eStreamFrom                Stream source.
 *  \param [in] eDecFmt                    Decoder format.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetDecType (UINT8 u1DecId,
            MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom,
            MTAUDDEC_FMT_T eDecFmt);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_Play (UINT8 u1DecId)
 *  \brief Audio decoder playback.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_Play (UINT8 u1DecId);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_Resume (UINT8 u1DecId)
 *  \brief Resume audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_Resume (UINT8 u1DecId);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_Pause (UINT8 u1DecId)
 *  \brief Pause audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_Pause (UINT8 u1DecId);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_Stop (UINT8 u1DecId)
*  \brief Stop audio decoder.
*  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*  \return a MTAL error code.
*  \retval MTR_OK Success.
*  \retval MTR_NOT_OK Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_Stop (UINT8 u1DecId);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_StopAll (UINT8 u1DecId,UINT8 u1Dec2Id)
 *  \brief currently no functionality (remove in the future?!)
 */
EXTERN MT_RESULT_T  MTAUDDEC_StopAll (UINT8 u1DecId,UINT8 u1Dec2Id);

/*!\fn EXTERN MT_RESULT_T  MTAUDDEC_SetHDevModeEnable (BOOL fgEnable)
*  \brief Setup High Deveation mode
*  \param[in]  fgEnable High Deveation mode enable true/false.
*  \return a MTAL error code.
*  \retval MTR_OK Success.
*  \retval MTR_NOT_OK Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_SetHDevModeEnable (BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_RegCbFunc(MTAUDDEC_CB_FUNC_ID_T eFuncType, UINT32 u4FuncPtr,
 *                         UINT32 u4Arg1, UINT32 u4Arg2)
 *  \brief Audio decoder call back function registeration.
 *  \param [in] eFuncType The call back function type.
 *  \param [in] u4FuncPtr The call back function pointer.
 *  \param [in] u4Arg1 input argument 1
 *  \param [in] u4Arg2 input argument 2
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_RegCbFunc(MTAUDDEC_CB_FUNC_ID_T eFuncType, UINT32 u4FuncPtr,
                               UINT32 u4Arg1, UINT32 u4Arg2);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetDecOnPlayingStatus (UINT8 u1DecId,
 *                          BOOL* pfgOnPlay)
 *  \brief Query if audio decoder is On Playing Staus.
 *
 *  Since in some case, even application issue play to decoder, but if the
 *  bitstream is not feed to decoder, the audio decoder is not on playing status yet.
 *  This function indicates the status that if the decoding is correctly getting
 *  bistream and successfully decoded.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pfgOnPlay Is decoder real play
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetDecOnPlayingStatus (UINT8 u1DecId,
            BOOL* pfgOnPlay);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetDecOnPlayingStatusReal (UINT8 u1DecId, BOOL* pfgPlay)
 *  \brief Query if there is audio output.
 *
 *  Since in some case, even application issue play to decoder, but if the
 *  bitstream is not feed to decoder, there is no audio output yet.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pfgPlay Is decoder real play
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetDecOnPlayingStatusReal (UINT8 u1DecId, BOOL* pfgPlay);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSourceFrom (UINT8 u1DecId,
 *                          MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom)
 *  \brief Set the stream source of audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] eStreamFrom Stream Source
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSourceFrom (UINT8 u1DecId,
                                  MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom);

/*!\if LGSE 
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_GetAudioPTS(UINT8 u1DecId, UINT32 *pPts)
 *  \brief Get audio decoder pts.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pPts pts.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_GetAudioPTS(UINT8 u1DecId, UINT32 *pPts);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAvSynMode (UINT8 u1DecId,
  *                         MTAV_SYNC_MODE_T eSynMode)
 *  \brief Set AV synchronization mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eSynMode AV sync mode or just free run in DTV playback.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAvSynMode (UINT8 u1DecId,
            MTAV_SYNC_MODE_T eSynMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAc3CompMode (UINT8 u1DecId,
 *                          MTAUDDEC_AC3_COMP_MODE_T eCompMode)
 *  \brief Setup AC3 compression mode.
 *
 *  Default setting for EU model is RF mode;
 *  Default setting for US model is LINE mode.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eCompMode Compression mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAc3CompMode (UINT8 u1DecId,
            MTAUDDEC_AC3_COMP_MODE_T eCompMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DownmixMode (UINT8 u1DecId,
 *                          MTAUDDEC_AC3_DOWNMIX_MODE eDownmixMode)
 *  \brief Setup AC3 downmix mode.
 *
 *  Default setting is LtRt. 
 *  LtRt: Surround;
 *  LoRo: Stereo;
 *  Auto LoRo: Auto Downmix with LoRo.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eDownmixMode Downmix mode(0: LtRt, 1: LoRo, 3: Auto-LoRo).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DownmixMode (UINT8 u1DecId,
            MTAUDDEC_AC3_DOWNMIX_MODE eDownmixMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAc3DownmixMode (UINT8 u1DecId,
            MTAUDDEC_AC3_DOWNMIX_MODE * peDownmixMode)
 *  \brief Get AC3 downmix mode.
 *
 *  LtRt: Surround;
 *  LoRo: Stereo;
 *  Auto LoRo: Auto Downmix with LoRo.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peDownmixMode Downmix mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetAc3DownmixMode (UINT8 u1DecId,
            MTAUDDEC_AC3_DOWNMIX_MODE * peDownmixMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAc3Mode (UINT8 u1DecId,
 *                          MTAUDDEC_MODE_T * peMode)
 *  \brief Get Audio Coding Mode for AC3.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peMode AC3 audio coding mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetAc3Mode (UINT8 u1DecId,
            MTAUDDEC_MODE_T * peMode);

/*!\if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_GetAC3ESInfo(UINT8 u1DecId, MTAUDDEC_AC3_ES_INFO_T *pAC3ESInfo)
 *  \brief Get ES information of AC3 audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pAC3ESInfo audio es info.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_GetAC3ESInfo(UINT8 u1DecId, MTAUDDEC_AC3_ES_INFO_T *pAC3ESInfo);

/*!\if LGSE 
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_GetMPEGESInfo(UINT8 u1DecId, MTAUDDEC_MPEG_ES_INFO_T *pMPEGESInfo)
 *  \brief Get ES information of MPEG audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pMPEGESInfo audio es info.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_GetMPEGESInfo(UINT8 u1DecId, MTAUDDEC_MPEG_ES_INFO_T *pMPEGESInfo);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_GetHEAACESInfo(UINT8 u1DecId, MTAUDDEC_HEAAC_ES_INFO_T *pHEAACESInfo)
 *  \brief Get ES information of HE-AAC audio decoder.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pHEAACESInfo audio es info.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_GetHEAACESInfo(UINT8 u1DecId, MTAUDDEC_HEAAC_ES_INFO_T *pHEAACESInfo);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetSamplingRate (UINT8 u1DecId,
 *                          MTAUDDEC_SAMPLE_FREQ_T * pSmpRate)
 *  \brief Get audio sampling rate.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pSmpRate audio Sampling rate.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetSamplingRate (UINT8 u1DecId,
            MTAUDDEC_SAMPLE_FREQ_T * pSmpRate);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DrcRange (UINT8 u1DecId, UINT8 u1DrcLevel)
 *  \brief Setup range for dynamix range control of AC3.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1DrcLevel DRC range.
 *              0 ~ 8 (step size is 0.125), ex: 
 *              0 -> 0.0;
 *              1 -> 0.125;
 *              8 -> 1.0.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DrcRange (UINT8 u1DecId, UINT8 u1DrcLevel);

/*!\if LGSE 
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DrcRange100(UINT8 u1DecId, UINT8 u1DrcLevel)
 *  \brief Setup 0~100 range for dynamic range control of AC3.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1DrcLevel DRC range (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DrcRange100(UINT8 u1DecId, UINT8 u1DrcLevel);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DualMono (UINT8 u1DecId,
 *                          MTAUDDEC_AC3_DUALMONO_MODE eDualMonoMode)
 *  \brief Setup AC3 dual mono mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eDualMonoMode Dual mono mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAc3DualMono (UINT8 u1DecId,
            MTAUDDEC_AC3_DUALMONO_MODE eDualMonoMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAc3DualMono (UINT8 u1DecId,
 *                          MTAUDDEC_AC3_DUALMONO_MODE * peDualMonoMode)
 *  \brief Get AC3 dual mono mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peDualMonoMode Dual mono mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetAc3DualMono (UINT8 u1DecId,
            MTAUDDEC_AC3_DUALMONO_MODE * peDualMonoMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetIsESExist (UINT8 u1DecId,
 *			                BOOL * isEsExist)
 *  \brief Check if ES Exists.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] isEsExist True/False
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetIsESExist (UINT8 u1DecId,
										                      BOOL * isEsExist);
/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAtvDetectMode (UINT8 u1DecId,
 *                          MTAUDDEC_ATV_DETECT_MODE_T *peATVMode)
 *  \brief Get the analog TV stereo mode of current channel.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peATVMode Detected mode.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success
 *  \retval MTR_NOT_OK Fail.
 */										  
EXTERN MT_RESULT_T  MTAUDDEC_GetAtvDetectMode (UINT8 u1DecId,
            MTAUDDEC_ATV_DETECT_MODE_T *peATVMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAtvOutputMode (UINT8 u1DecId,
 *                          MTAUDDEC_SOUND_MODE_T eSoundMode)
 *  \brief Setup analog TV output mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eSoundMode ATV sound mode.
 *                                (UNKNOWN = 0,
 *                                  MONO,
 *                                  STEREO,
 *                                  SAP,
 *                                  DUAL1,
 *                                  DUAL2,
 *                                  NICAM_MONO,
 *                                  NICAM_STEREO,
 *                                  NICAM_DUAL1,
 *                                  NICAM_DUAL2,
 *                                  A2_DUAL1,
 *                                  A2_DUAL2).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAtvOutputMode (UINT8 u1DecId,
            MTAUDDEC_SOUND_MODE_T eSoundMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSIFMode (UINT8 u1DecId,
*                           MTAUDDEC_SIF_STANDARD_T eSIFMode)
*  \brief Setup SIF input mode
*
*  DVB EU model specific function
*  Should set to audio decoder before issue playback at EU/KOREA/EIAJ model.
*
*  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*  \param [in] eSIFMode SIF Mode
*                                 (NICAM BG,
*                                  FM BG,
*                                  A2 BG,
*                                  NICAM I,
*                                  FM I,
*                                  NICAM DK,
*                                  FM DK,
*                                  A2 DK1,
*                                  A2 DK3,
*                                  NICAM L,
*                                  AM L,
*                                  A2 KOREA,
*                                  BTSC,
*                                  EIAJ)
*  \return a MTAL error code.
*  \retval MTR_OK Success.
*  \retval MTR_NOT_OK Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_SetSIFMode (UINT8 u1DecId,
            MTAUDDEC_SIF_STANDARD_T eSIFMode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetDetectSIFMode (UINT8 u1DecId,
 *                          MTAUDDEC_SIF_STANDARD_T eSIFMode,
 *                          MTAUDDEC_SIF_STANDARD_T* peSIFMode)
 *  \brief Get detected SIF mode
 *
 *  DVB EU model specific function
 *  Issue decoder to do SIF mode detection. It may take some time for the detection.
 *  Notes that application should stop decoder before invoking this function.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eSIFMode FM DK or AM L
 *                                  Since audio decoder cannot distinguish from
 *                                  FM DK and AM L, so application should set this
 *                                  information to audio decoder at first before
 *                                  issue decoder to do detection.
 *  \param [out] peSIFMode Detection result
 *                                 (MODE_DETECT = 0,
 *                                  NICAM BG,
 *                                  FM BG,
 *                                  A2 BG,
 *                                  NICAM I,
 *                                  FM I,
 *                                  NICAM DK,
 *                                  FM DK,
 *                                  A2 DK1,
 *                                  A2 DK3,
 *                                  NICAM L,
 *                                  AM L,
 *                                  A2 KOREA,
 *                                  BTSC,
 *                                  EIAJ)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetDetectSIFMode (UINT8 u1DecId,
            MTAUDDEC_SIF_STANDARD_T eSIFMode,
            MTAUDDEC_SIF_STANDARD_T* peSIFMode);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAtvSoundSystem (UINT8 u1DecId,
 *                          MTAUDDEC_SIF_STANDARD_T *peATVSoundSys)
 *  \brief Get the analog TV sound system of current channel.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peATVSoundSys Sound system
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetAtvSoundSystem (UINT8 u1DecId,
            MTAUDDEC_SIF_STANDARD_T *peATVSoundSys);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetAtvSoundSystemStrength ( MTAUDDEC_SIF_STANDARD_T eATVSoundSys, UINT32 *peStrength)
 *  \brief Get the analog TV sound system strength of current channel.
 *  \param [in] eATVSoundSys Sound system
 *  \param [out] peStrength ATV Sound system Stength
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetAtvSoundSystemStrength ( MTAUDDEC_SIF_STANDARD_T eATVSoundSys, UINT32 *peStrength);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetPcmInfo (UINT8 u1DecId,
 *                          MTAUDDEC_PCM_SETTING_T* prPcmSetting)
 *  \brief Setup PCM information.
 *
 *  Used in audio clip playback.
 *
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] prPcmSetting PCM setting
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetPcmInfo (UINT8 u1DecId, MTAUDDEC_LPCM_INFO_T* prLPcmInfo);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_IsSIFExist(UINT8* fgIsSIFExist)
 *  \brief Check If SIF exists.
 *  \param [out] fgIsSIFExist true or false
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_IsSIFExist(UINT8* fgIsSIFExist);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBtscA2ThresholdLevel (UINT16 thrLevel)
 *  \brief Set the BTSC/A2 Threshold
 *  \param [in] thrLevel Threshold
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBtscA2ThresholdLevel (UINT16 thrLevel);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetBtscA2ThresholdLevel (UINT16 *pLevel)
 *  \brief Get BTSC A2 threshold
 *  \param [out] pLevel     Threshold
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetBtscA2ThresholdLevel (UINT16 *pLevel);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetNicamThresholdLevel (UINT8 u1DecId, UINT16 *pLevel)
 *  \brief Get Nicam threshold
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pLevel Threshold
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetNicamThresholdLevel (UINT8 u1DecId, UINT16 *pLevel);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetNicamThresholdLevel (UINT16 thrLevel)
 *  \brief Set Nicam threshold
 *  \param [in] thrLevel Threshold
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetNicamThresholdLevel (UINT16 thrLevel);
#if 1
/*! \fn EXTERN MT_RESULT_T	MTAUDDEC_LoadAudioClip(UINT8 u1DecId, UINT32 u1bufSize, UINT32 *u1ClipBufferPointer, MTAUDDEC_FMT_T u1DecFormat,UINT32 u1repeatNumber)
 *  \brief Load Audio Clip.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1bufSize Buffer size
 *  \param [out] u1ClipBufferPointer Buffer pointer
 *  \param [in] u1DecFormat decoder format
 *  \param [in] u1repeatNumber repeat number
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T	MTAUDDEC_LoadAudioClip(UINT8 u1DecId, UINT32 u1bufSize, UINT32 *u1ClipBufferPointer, MTAUDDEC_FMT_T u1DecFormat,UINT32 u1repeatNumber);

#else
/* LoadAudioClip.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param u1bufSize                 u1bufSize
 *  \param u1ClipBufferPointer   u1ClipBufferPointer
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
//EXTERN MT_RESULT_T MTAUDDEC_LoadAudioClip(UINT8 u1DecId, UINT32 u1bufSize, UINT32 *u1ClipBufferPointer);
#endif

/* PlayAudioClip.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param u1ReaptNumber         clip ReaptNumber
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_PlayAudioClip(UINT8 u1DecId, UINT32 u1ReaptNumber);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_StopAudioClip (UINT8 u1DecId)
 * \brief Stop audio clip.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_StopAudioClip (UINT8 u1DecId);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_DeleteAudioClip(void)
 *  \brief Delete audio clip.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_DeleteAudioClip(void);

#if 1//def CC_AUD_MULTI_BUFFER_MEMORY_PLAY
EXTERN MT_RESULT_T MTAUDDEC_MultiBuffSetMode(UINT8 u1DecId, BOOL fgMultiBuff);
EXTERN MT_RESULT_T MTAUDDEC_MultiBuffAddData(UINT8 u1DecId, UINT32 u4Addr, UINT32 u4Size, BOOL fgEnd);
EXTERN MT_RESULT_T MTAUDDEC_MultiBuffGetMaxBuffNum(UINT8 u1DecId, UINT32 *pu4Num);
EXTERN MT_RESULT_T MTAUDDEC_MultiBuffGetRemainingBuffNum(UINT8 u1DecId, UINT32 *pu4Num);
#endif

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelDelay (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
 *                          INT16 u2Delay)
 *  \brief Setup individual channel delay
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChIndex Individual channel.
 *  \param [in] u2Delay Delay (0~300 ms with 1 ms/step).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelDelay (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
            INT16 u2Delay);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelDelayNoUop (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
 *                          UINT16 u2Delay)
 *  \brief Setup individual channel delay without uop
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChIndex Individual channel.
 *  \param [in] u2Delay Delay (0~300 ms with 1 ms/step).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelDelayNoUop (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
            UINT16 u2Delay);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_GetChannelDelay (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
 *                          UINT16 *u2Delay)
 *  \brief Get individual channel delay
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChIndex Individual channel.
 *  \param [out] u2Delay Delay (0~300 ms with 1 ms/step).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetChannelDelay (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex,
            UINT16 *u2Delay);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolume (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
 *                          UINT8 u1Value)
 *  \brief Setup individual channel volume.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [in] u1Value Channel Volumn (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolume (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
            UINT8 u1Value);

/**Get channel volume.
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param eChIndex                   Individual channel.
*@param u1Value                    0~100.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetChannelVolume (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
                                        UINT8 * u1Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeNew (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
*                           UINT8 u1Value,UINT8 u1Value1)
*  \brief Setup individual channel volume (New).
*  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*  \param [in] eChannel Individual channel.
*  \param [in] u1Value 0~157.
*  \param [in] u1Value1 0~15.
*  \return a MTAL error code.
*  \retval MTR_OK Success.
*  \retval MTR_NOT_OK Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeNew (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
											UINT8 u1Value,UINT8 u1Value1);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetDolbyDRCMode(UINT8 u1DecId, UINT8 drcMode)
 *  \brief Setuop DRC mode for DD/DDP/DP.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] drcMode DRC mode (0: Line, 1: RF).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetDolbyDRCMode(UINT8 u1DecId, UINT8 drcMode);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetDownMixMode(UINT8 u1DecId, UINT8 downmixMode)
 *  \brief Setuop DownMix mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] downmixMode DownMix mode (0: LtRt, 1: LoRo).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetDownMixMode(UINT8 u1DecId, UINT8 downmixMode);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeNoUop (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
 *                          UINT8 u1Value)
 *  \brief Setup individual channel volume without uop.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [in] u1Value Channel Volumn (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeNoUop (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
            UINT8 u1Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeInDB (UINT8 u1DecId,
 *                          MTAUDDEC_CH_T eChannel, INT16 i2Value)
 *  \brief Setup individual channel volume in DB scale.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [in] i2Value Volume value in 0.25dB/step.
 *  \n                                Range: 80 ~ -512 (+20dB ~ -128dB).
 *  \n                               (80   ->  +20   dB
 *  \n                                79   ->  +19.75dB
 *  \n                                78   ->  +19.5 dB
 *  \n                                77   ->  +19.25dB
 *  \n                                76   ->  +19   dB
 *  \n                                 :        :       :
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                                -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :       :
 *  \n                                -512 ->  -128  dB)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolumeInDB (UINT8 u1DecId,
            MTAUDDEC_CH_T eChannel, INT16 i2Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelMute (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
 *                          BOOL fgMute)
 *  \brief Mute individual channel
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [in] fgMute Mute or not.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelMute (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
            BOOL fgMute);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetChannelMuteStatus (UINT8 u1DecId,
 *                          MTAUDDEC_CH_T eChannel, BOOL * pfgMute)
 *  \brief Get individual channel mute status
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [out] pfgMute Mute or not. (TRUE: Mute, FALSE: Un-Mute)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetChannelMuteStatus (UINT8 u1DecId,
            MTAUDDEC_CH_T eChannel, BOOL * pfgMute);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_GetSpeakerOutMode (MTAUDDEC_SKP_OUTPUT_MODE_T *peSpeakeroutmode)
 *  \brief Get speaker output mode
 *  \param [out] peSpeakeroutmode LR/LL/RR/MIX
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetSpeakerOutMode (MTAUDDEC_SKP_OUTPUT_MODE_T *peSpeakeroutmode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolGain (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
 *                          INT32 i4Value)
 *  \brief Setup extra gain for individual channel.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel  Individual channel.
 *  \param [in] i4Value -256~96. (-128 ~ 48 dB with 0.5 dB/step)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetChannelVolGain (UINT8 u1DecId, MTAUDDEC_CH_T eChannel,
            INT32 i4Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBalance (UINT8 u1DecId, UINT8 u1Balance)
 *  \brief Setup volume balance.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Balance Balance value (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBalance (UINT8 u1DecId, UINT8 u1Balance);

/**Get volume balance.
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param u1Volume                   Balance value (0~100).
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetBalance (UINT8 u1DecId, UINT8 * u1Balance);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBalanceInDB (UINT8 u1DecId, INT16 i2LeftDB,
 *                          INT16 i2RightDB)
 *  \brief Setup balance value in dB scale.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2LeftDB Volume value in 0.25dB/step.
 *  \param [in] i2RightDB Volume value in 0.25dB/step.
 *  \n                               (Range: 0 ~ -512
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                                -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :
 *  \n                                -512 ->  -128  dB) 
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBalanceInDB (UINT8 u1DecId, INT16 i2LeftDB,
            INT16 i2RightDB);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolume (UINT8 u1DecId, UINT8 u1Volume)
 *  \brief Setup master volume.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Volume Volume value (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolume (UINT8 u1DecId, UINT8 u1Volume);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_GetMasterVolume (UINT8 u1DecId, UINT8 * u1Volume)
 *  \brief Get master volume.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Volume Volume value (0~100).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetMasterVolume (UINT8 u1DecId, UINT8 * u1Volume);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSourceVolume (UINT8 u1DecId,  MTAUDDEC_DEC_STREAM_FROM_T InPutSrc)
 *  \brief Setup source volume.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] InPutSrc Stream Source
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSourceVolume (UINT8 u1DecId,  MTAUDDEC_DEC_STREAM_FROM_T InPutSrc);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolumeInDB (UINT8 u1DecId, INT16 i2Volume)
 *  \brief Setup master volume in dB.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Volume Volume value in 0.25dB/step.
 *  \n                               (Range: 0 ~ -512
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                               -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :
 *  \n                                -512 ->  -128  dB)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolumeInDB (UINT8 u1DecId, INT16 i2Volume);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolumeForBypassChannelInDB (UINT8 u1DecId,
 *                          INT16 i2Volume)
 *  \brief Setup master volume for bypass channel in dB.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Volume Volume value in 0.25dB/step.
 *  \n                               (Range: 0 ~ -512
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                               -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :
 *  \n                                -512 ->  -128  dB)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVolumeForBypassChannelInDB (UINT8 u1DecId,
            INT16 i2Volume);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetClipperThresholdInDB (UINT8 u1DecId,
 *                          MTAUDDEC_CH_T eChannel, INT16 i2Value)
 *  \brief Setup clipper threshold in dB.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eChannel Individual channel.
 *  \param i2Value Threshold value in 0.25dB/step.
 *  \n                               (Range: 0 ~ -512
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                               -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :
 *  \n                                -512 ->  -128  dB)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetClipperThresholdInDB (UINT8 u1DecId,
            MTAUDDEC_CH_T eChannel, INT16 i2Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetPreGainInDB (UINT8 u1DecId, INT16 i2Value)
 *  \brief Setup pre-gain in dB.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Value Pre-Gain value in 0.25dB/step.
 *  \n                               (Range: 0 ~ -512
 *  \n                                0    ->  0     dB
 *  \n                                -1   ->  -0.25 dB
 *  \n                                -2   ->  -0.5  dB
 *  \n                               -3   ->  -0.75 dB
 *  \n                                -4   ->  -1    dB
 *  \n                                 :       :
 *  \n                                -512 ->  -128  dB)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetPreGainInDB (UINT8 u1DecId, INT16 i2Value);
EXTERN MT_RESULT_T  MTAUDDEC_SetPreGainChannelInDB (UINT8 u1DecId, MTAUDDEC_AUD_DEC_STREAM_FROM_T u4Dec,INT16 i2Value);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAvc(UINT8 u1DecId, BOOL fgEnable);
 *  \brief Setup Auto volume control (AVC).
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAvc(UINT8 u1DecId, BOOL fgEnable);

/**Get Auto volume control (AVC).
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param fgEnable                   on/off.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetAvc(UINT8 u1DecId, BOOL * fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetAvcCfg(UINT8 u1DecId,
 *                          MTAUDDEC_AVC_CFG_TYPE_T eAVCCfgType, INT32 i4Parameter);
 *  \brief Setup AVC parameters
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eAVCCfgType AVC Configuration type
 *  \param [in] i4Parameter Parameter value
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetAvcCfg(UINT8 u1DecId,
                                          MTAUDDEC_AVC_CFG_TYPE_T eAVCCfgType, INT32 i4Parameter);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_Set2BandAvcCfg(UINT8 u1DecId, UINT8 u1Band,
 *                          MTAUDDEC_AVC_CFG_TYPE_T eAVCCfgType, INT32 i4Parameter)
 *  \brief Setup 2 band AVC parameters
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Band Band number (0: Low band, 1: High band)
 *  \param [in] eAVCCfgType AVC Configuration type
 *  \param [in] i4Parameter Parameter value
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_Set2BandAvcCfg(UINT8 u1DecId, UINT8 u1Band,
            MTAUDDEC_AVC_CFG_TYPE_T eAVCCfgType, INT32 i4Parameter);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBBE(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup BBE mode
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBBE(UINT8 u1DecId, BOOL fgEnable);

/**Get BBE
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param fgEnable                   on/off.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetBBE(UINT8 u1DecId, BOOL * fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSRS(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup SRS
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSRS(UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetADChannelMode(UINT8 u1DecId, UINT16 u2Mode)
 *  \brief Setup AD Channel Mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u2Mode AD Mode (0:CH9/10,1:L/R, 2:CH9/10 & L/R).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetADChannelMode(UINT8 u1DecId, UINT16 u2Mode);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_ADEnable(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Enable/Disable Audio Description.
 *  \param [in] u1DecId (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable True/False.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_ADEnable(UINT8 u1DecId, BOOL fgEnable);

/*!\if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_LGSEFN000(UINT8 fNo, UINT32 *pParams, UINT16 noParam, UINT8 dataOption, UINT8 varOption)
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_LGSEFN000(UINT8 fNo, UINT32 *pParams, UINT16 noParam, UINT8 dataOption, UINT8 varOption);

/*!\if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_LGSEFN010_Read(UINT32 *pParams)
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_LGSEFN010_Read(UINT32 *pParams);

/*!\if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetClearVoice(UINT8 u1DecId, BOOL fgEnable)
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetClearVoice(UINT8 u1DecId, BOOL fgEnable);

/*!\if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetCVParameter (UINT32 *u4Parameter, UINT8 u1Size)
 *  \endif
 */
 EXTERN MT_RESULT_T  MTAUDDEC_SetCVParameter (UINT32 *u4Parameter, UINT8 u1Size);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetVirtualSurround(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup virtural surround
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetVirtualSurround(UINT8 u1DecId, BOOL fgEnable);

/**Get virtural surround
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param fgEnable                   on/off.
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetVirtualSurround(UINT8 u1DecId, BOOL * fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetVirtualSurroundCfg(UINT8 u1DecId,
 *                          MTAUDDEC_VSURR_CFG_TYPE_T eVSCfgType, UINT32 u4Parameter)
 *  \brief Setup virtural surround parameters
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eVSCfgType Configuration Parameter type
 *  \param [in] u4Parameter Parameter value
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetVirtualSurroundCfg(UINT8 u1DecId,
            MTAUDDEC_VSURR_CFG_TYPE_T eVSCfgType, UINT32 u4Parameter);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBassBoost (UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup bass boost.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBassBoost (UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBass (UINT8 u1DecId, INT16 i2Bass)
 *  \brief Setup bass
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Bass bass value  ( +-14 steps, with 0.5 dB/step)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBass (UINT8 u1DecId, INT16 i2Bass);

/**Get bass.
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param u1Volume                   bass value ( +-14 steps, with 0.5 dB/step)
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetBass (UINT8 u1DecId, INT16 * i2Bass);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetTrebleBoost(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup treble boost.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetTrebleBoost(UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetTreble (UINT8 u1DecId, INT16 i2Treble)
 *  \brief Setup Treble
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Treble Treble value ( +-14 steps, with 0.5 dB/step)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetTreble (UINT8 u1DecId, INT16 i2Treble);

/**Get treble.
*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
*@param u1Volume                   treble value ( +-14 steps, with 0.5 dB/step)
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/
EXTERN MT_RESULT_T  MTAUDDEC_GetTreble (UINT8 u1DecId, INT16 * i2Treble);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetEqualizer(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup Equalizer.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetEqualizer(UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetEqualizerBandConfig(UINT8 u1DecId, INT16 i2Band0,
 *                          INT16 i2Band1, INT16 i2Band2, INT16 i2Band3,
 *                          INT16 i2Band4, INT16 i2Band5, INT16 i2Band6)
 *  \brief Setup EQ band configuration.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] i2Band0 band 0 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band1 band 1 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band2 band 2 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band3 band 3 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band4 band 4 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band5 band 5 setup ( +-28, with 0.5 dB/step)
 *  \param [in] i2Band6 band 6 setup ( +-28, with 0.5 dB/step)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetEqualizerBandConfig(UINT8 u1DecId, INT16 i2Band0,
            INT16 i2Band1, INT16 i2Band2, INT16 i2Band3,
            INT16 i2Band4, INT16 i2Band5, INT16 i2Band6);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAvInputMuxSel (MTAUDDEC_INPUT_ID_T eInputId)
 *  \brief Setup line-in input mux
 *  \param  [in] eInputId Input mux id.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAvInputMuxSel (MTAUDDEC_INPUT_ID_T eInputId);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAvInputMuxByADC(UINT8 eADNum)
 *  \brief Setup line-in input mux by ADC
 *  \param  [in] eADNum Input mux id.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAvInputMuxByADC(UINT8 eADNum);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetIecConfig (UINT8 u1DecId, MTAUDDEC_IEC_T eIecCfg,
 *                          BOOL fgEnable)
 *  \brief Setup IEC configuration.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eIecCfg IEC format.
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetIecConfig (UINT8 u1DecId, MTAUDDEC_IEC_T eIecCfg,
            BOOL fgEnable);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAACByPass(BOOL fgEnable)
 *  \brief Enable/Disable DDCO (Output AC3 to Bypass channel for AAC).
 *  \param [in] fgEnable True/False.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAACByPass(BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetIecConfig (UINT8 u1DecId, MTAUDDEC_IEC_T * peIecCfg,
 *                          BOOL * pfgEnable)
 *  \brief Get IEC configuration.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] peIecCfg IEC format.
 *  \param [out] pfgEnable on/off. (TRUE: ON, FALSE: OFF)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetIecConfig (UINT8 u1DecId, MTAUDDEC_IEC_T * peIecCfg,
            BOOL * pfgEnable);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSPDIFMute (BOOL fgMute)
 *  \brief Setup SPDIF mute.
 *  \param [in] fgMute on/off. (TRUE: mute, FALSE: unmute)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSPDIFMute (BOOL fgMute);
    

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetIecChannel (MTAUDDEC_PCM_CH_T eChannel)
 *  \brief Setup IEC refer to which channel.
 *  \param [in] eChannel Channel number.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetIecChannel (MTAUDDEC_PCM_CH_T eChannel);
    
/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetIecCopyright(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup IEC copyright.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetIecCopyright(UINT8 u1DecId, BOOL fgEnable);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSpdifScms(UINT8 spdif_ctrl)
 *  \brief Setup SPDIF scms
 *  \param [in] spdif_ctrl spdif control
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSpdifScms(UINT8 spdif_ctrl);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetIecCopyright(UINT8 u1DecId, BOOL * pfgEnable)
 *  \brief Get IEC copyright.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pfgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetIecCopyright(UINT8 u1DecId, BOOL * pfgEnable);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetIecCategoryCode(UINT8 u1DecId, UINT8 u1CategoryCode)
 *  \brief Setup IEC category code
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1CategoryCode Category code.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetIecCategoryCode(UINT8 u1DecId, UINT8 u1CategoryCode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetIecCategoryCode(UINT8 u1DecId, UINT8 * pu1CategoryCode)
 *  \brief Get IEC category code
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pu1CategoryCode Category code.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetIecCategoryCode(UINT8 u1DecId, UINT8 * pu1CategoryCode);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetIecWordLength(UINT8 u1DecId, UINT8 u1WordLength)
 *  \brief Setup IEC category code
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1WordLength Word length.(in bits, range: 16/24)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetIecWordLength(UINT8 u1DecId, UINT8 u1WordLength);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_GetIecWordLength(UINT8 u1DecId, UINT8 * pu1WordLength)
 *  \brief Get IEC category code
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pu1WordLength Word length.(in bits, range: 16/24)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_GetIecWordLength(UINT8 u1DecId, UINT8 * pu1WordLength);

/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetSpeakerOutMode (UINT8 u1DecId,
 *           MTAUDDEC_SKP_OUTPUT_MODE_T eOutputMode)
 *  \brief Setup Speaker output mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eOutputMode Speaker output mode
 *  \n                               (L+R = 0,
 *  \n                                L+L,
 *  \n                                R+R,
 *  \n                                MIX)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetSpeakerOutMode (UINT8 u1DecId,
            MTAUDDEC_SKP_OUTPUT_MODE_T eOutputMode);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetAudioOutMode (UINT8 u1DecId,
 *           MTAUDDEC_MODE_T eOutputMode)
 *  \brief Setup audio output mode.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eOutputMode audio output mode
 *   (MTAUDDEC_MODE_MONO,                 ///< 1/0
 *   MTAUDDEC_MODE_STEREO,               ///< 2/0
 *   MTAUDDEC_MODE_STEREO_DOLBY_SURROUND,///< 2/0, dolby surround
 *   MTAUDDEC_MODE_SURROUND_2CH,         ///< 2/1
 *   MTAUDDEC_MODE_SURROUND,             ///< 3/1
 *   MTAUDDEC_MODE_3_0,                  ///< 3/0
 *   MTAUDDEC_MODE_4_0,                  ///< 2/2
 *   MTAUDDEC_MODE_5_1)                  ///< 3/2
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetAudioOutMode (UINT8 u1DecId,
            MTAUDDEC_MODE_T eOutputMode);


/*! \fn EXTERN MT_RESULT_T  MTAUDDEC_SetBassEnhancer (UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup bass enhancer switch
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetBassEnhancer (UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetBassEnhancerCfg(UINT8 u1DecId,
 *                          MTAUDDEC_BE_PARAM_TYPE_T eBassEnhancerType, UINT32 u4Parameter)
 *  \brief Setup bass enhancer parameers
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] eBassEnhancerType Bass enhance type
 *  \param [in] u4Parameter Parameter value
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetBassEnhancerCfg(UINT8 u1DecId,
            MTAUDDEC_BE_PARAM_TYPE_T eBassEnhancerType, UINT32 u4Parameter);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetPEQ(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup PEQ switch on/off
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetPEQ(UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetPEQCfg(UINT8 u1DecId, UINT8 u1Set,
 *                          UINT32 u4Frequency, MTAUDDEC_PEQ_Q_TYPE_T eQValue, INT16 i2Gain)
 *  \brief Setup PEQ parameters
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Set PEQ set (0 ~ 7)
 *  \param [in] u4Frequency Frequency
 *  \param [in] eQValue Q
 *  \param [in] i2Gain Gain (+-12dB) with 0.5dB/step
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetPEQCfg(UINT8 u1DecId, UINT8 u1Set,
                                          UINT32 u4Frequency, MTAUDDEC_PEQ_Q_TYPE_T eQValue, INT16 i2Gain);


/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetLimiter(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup Limiter switch on/off
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable on/off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetLimiter(UINT8 u1DecId, BOOL fgEnable);


/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetLimiterCfg(UINT8 u1DecId, UINT8 u1Mode,
 *                          UINT16 u2Flag, UINT32 u4Thresh)
 *  \brief Setup Limiter configuration
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1Mode limiter mode
 *  \n                                (0: off, 1: adaptive mode, 2: fixed mode).
 *  \param [in] u2Flag limiter flag (0: off, 1: on)
 *  \n                                bit 0: vol
 *  \n                                bit 1: vsurr
 *  \n                                bit 2: sbass
 *  \n                                bit 3: EQ
 *  \n                                bit 4: reverb
 *  \n                                bit 5: virtual bass
 *  \param [in] u4Thresh limiter threshold (0x0 ~ 0x7fffff)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetLimiterCfg(UINT8 u1DecId, UINT8 u1Mode,
            UINT16 u2Flag, UINT32 u4Thresh);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetHPF(UINT8 u1DecId, BOOL fgEnable)
 *  \brief Setup HPF
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] fgEnable On/Off
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetHPF(UINT8 u1DecId, BOOL fgEnable);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_SetHPFFc(UINT8 u1DecId, UINT16 u2Fc)
 *  \brief Setup HPF Fc
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u2Fc Frequency (50 ~ 300 Hz)
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_SetHPFFc(UINT8 u1DecId, UINT16 u2Fc);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_MixSoundPlay(UINT32 u4Addr, UINT32 u4Len, UINT32 u4Gain, UINT32 u2Config)
 *  \brief Play MixSound
 *  \param [in] u4Addr Address
 *  \param [in] u4Len Length
 *  \param [in] u4Gain 0x20000 means 0dB
 *  \param [in] u2Config bit  0:3  samplerate  0: 48k   1: 44.1k 2: 32k 3: 24k 4:16k 5:12k
 *  \n                            bit  4: source mode : 0->mono, 1->stereo
 *  \n                            bit  5: 0: 8bit, 1 16bits
 *  \n                            bit  6: 0: bigendian  1:littleendian
 *  \n                            bit  7: 0: no repeat   1:repeat
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_MixSoundPlay(UINT32 u4Addr, UINT32 u4Len, UINT32 u4Gain, UINT32 u2Config);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_MixSoundStop(void)
 *  \brief Mixsound Stop
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_MixSoundStop(void);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_MixSoundPause(void)
 *  \brief Mixsound Pause
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_MixSoundPause(void);

/*! \fn EXTERN MT_RESULT_T MTAUDDEC_MixSoundResume(void)
 *  \brief Mixsound Resume
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 */
EXTERN MT_RESULT_T MTAUDDEC_MixSoundResume(void);
/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_SetMainSpeakerOnOff(BOOL fgOnOff)
 *  \brief Mute Main Speaker.
 *  \param [in] fgOnOff True/Off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_SetMainSpeakerOnOff(BOOL fgOnOff);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_SetHDMIArcOnOff(BOOL fgOnOff)
 *  \brief Enable/Disable HDMI ARC output.
 *  \param [in] fgOnOff True/Off.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_SetHDMIArcOnOff(BOOL fgOnOff);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_SetDspSpeedMode(UINT32 u1Mode)
 *  \brief set DSP speed
 *  \param [in] u1Mode step is 0.1, 10: normal speed; 5: 0.5X speed ; 20: 2X speed
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_SetDspSpeedMode(UINT32 u1Mode);

    //MTK specific tool for 3rd party
#if 1
/*! \if Android
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_open(void)
 *  \brief Open Audo Recoder.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_open(void);

/*! \if Android
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_read(UINT32 u4BufAddr, UINT32 u4BufSize, UINT32* u4ReadSize, BOOL fgBlockRead)
 *  \brief Read Recoded Audio Data.
 *  \param [in] u4BufAddr Buffer Address.
 *  \param [in] u4BufSize Buffer Size.
 *  \param [out] u4ReadSize Actually Read Size.
 *  \param [in] fgBlockRead Block or not Block Read.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_read(UINT32 u4BufAddr, UINT32 u4BufSize, UINT32* u4ReadSize, BOOL fgBlockRead);

/*! \if Android
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_close(void)
 *  \brief Close Audio Recoder.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_RecordPCM_close(void);    

EXTERN int getAudioSamplingRate(void);
EXTERN int getAudioChannel(void);
EXTERN int getAudioData(int msec, char *pBuff, int *pLen);
#else
EXTERN MT_RESULT_T MTAUDDEC_RecordPCM(UINT32 u4ClipBufferPointer, UINT32 u4BufSize);
EXTERN MT_RESULT_T MTAUDDEC_DownloadDram(UINT32 u4BufPtr, UINT32 u4Addr, UINT32 u4Size);
EXTERN MT_RESULT_T MTAUDDEC_UploadDram(UINT32 u4BufPtr, UINT32 u4Addr, UINT32 u4Size);
#endif    
/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_GetHDMIScms(UINT8 u1DecId, MTAUDDEC_HDMI_SCMS_INFO_T *pHDMIScmsInfo)
 *  \brief Get HDMI Scms Infomation.
 *  \param [in] u1DecId Audio Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pHDMIScmsInfo HDMI Scms Informatio.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_GetHDMIScms(UINT8 u1DecId, MTAUDDEC_HDMI_SCMS_INFO_T *pHDMIScmsInfo);
#ifdef CC_ENABLE_AOMX    
EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_open(INT32* pi4StreamId);
EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_close(INT32 i4StreamId);
EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_ioctl(INT32 i4StreamId, UINT32 u4SampleRate, UINT8 u1StereoOnOff, UINT8 u1BitDepth, UINT32 u4BufferSize);
EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_write(INT32 i4StreamId, UINT32 u4BufPtr, UINT32 u4BufSize);
/*
 * EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_query(INT32 i4StreamId, UINT32* pu4RenderSize, UINT32* pu4BufferLevel, UINT32* pu4DataConsumed)
 *  \brief Query mixsound path status.
 *  \param [in] i4StreamId : mixsound path ID.
 *  \param [out] pu4RenderSize: Total size rendered.
 *  \param [out] pu4BufferLevel : data size in Buffer.
 *  \param [out] pu4DataConsumed : data size consumed.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_PlayPCM_query(INT32 i4StreamId, UINT32* pu4RenderSize, UINT32* pu4BufferLevel, UINT32* pu4DataConsumed);
EXTERN MT_RESULT_T  MTAUDDEC_SetPcmVolume (UINT8 u1DecId, UINT8 u1Volume);

EXTERN MT_RESULT_T MTAOMX_GetGstDbgMsk(UINT32 u4Index,UINT32* pu4DbgMsk);
EXTERN MT_RESULT_T MTAOMX_SetGstDbgMsk(UINT32 u4Index,UINT32 u4DbgMsk);
EXTERN MT_RESULT_T MTAOMX_TrigRender(void);
EXTERN MT_RESULT_T MTAOMX_GetCurPts(INT64* i8Pts);
EXTERN MT_RESULT_T MTAOMX_GetLastPts(INT64* i8Pts);
#endif
EXTERN MT_RESULT_T MTAUDDEC_QueryAudioInfo (UINT8 u1DecId, MTAUDDEC_DEC_QUERY_IDX_T u1Idx, MTAUDDEC_AUDIO_INFO_T * pInfo);
/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUD_OpenPCM(UINT8 u1DecId, MTAUDDEC_FMT_T u1DecFormat, UINT32 u4SampleRate)
 *  \brief Open PCM.
 *  \param [in] u1DecId Audio Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u1DecFormat Audio Decoder Format.
 *  \param [in] u4SampleRate Sampling Rate.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
//kevin zhu 2014-6-27
EXTERN MT_RESULT_T MTAUDDEC_BT_Mute_Speaker(BOOL fgOnOff);
EXTERN MT_RESULT_T MTAUD_OpenPCM(UINT8 u1DecId, MTAUDDEC_FMT_T u1DecFormat, UINT32 u4SampleRate);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUD_ClosePCM(int u1DecId)
 *  \brief Close PCM.
 *  \param [in] u1DecId Audio Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUD_ClosePCM(int u1DecId);  

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T MTAUD_GetPCMDelay(UINT8 u1DecId, unsigned int *pdelay)
 *  \brief Get PCM Delay (wp-rp).
 *  \param [in] u1DecId Audio Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pdelay PCM Delay.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUD_GetPCMDelay(UINT8 u1DecId, unsigned int *pdelay);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T	MTAUD_FillPCMBuffer(UINT8 u1DecId, void *lpBuffer, unsigned int size)
 *  \brief Fill PCM Buffer.
 *  \param [in] u1DecId Audio Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] lpBuffer PCM Buffer.
 *  \param [in] size Size of Buffer.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T	MTAUD_FillPCMBuffer(UINT8 u1DecId, void *lpBuffer, unsigned int size);

/*! \if LGSE
 *  \fn EXTERN MT_RESULT_T  MTAUDDEC_SetCarrierMute (BOOL fgEnable)
 *  \brief Set Carrier Mute/UnMute for ATV.
 *  \param [in] fgEnable Carrier mute function on/off
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDDEC_SetCarrierMute (BOOL fgEnable);

/**RM alloc hw adec resource
*@param u1DecId                    Virtual Decoder Id used by RM
*@param u1IsFree                   Is alloce ok?
*@param u1DecToKick             If NG, which Dec to keck
*@retval MTR_OK                    Success.
*@retval MTR_NOT_OK                Fail.
*/

MT_RESULT_T MTAUDDEC_ResAlloc(UINT8 u1DecId, BOOL *bIsFree, UINT8 *u1NumCandidateToKick, UINT8 *u1DecToKick);



/*! @} */

/*!\if mw_if2
  *  \addtogroup mw_if2 MW_IF2 over MTAL
  *  \brief MW_IF2 over MTAL for Audio Decoder Modules
  *  \endif  
  *  @{
  */

//The following is for MW_IF2

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_MW_AUD_Init(void)
 *  \brief Initialize audio decoder
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_MW_AUD_Init(void);

// 3
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_get_min_max (
 *                          DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
 *                          INT16*                    pui2_min,
 *                          INT16*                    pui2_max)
 *  \brief get min/max value for different audio type
 *  \param [in] e_aud_type audio type.
 *  \param [out] pui2_min corresponding minimum value.
 *  \param [out] pui2_max corresponding maximum value.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_get_min_max (
                    DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
                    INT16*                    pui2_min,
                    INT16*                    pui2_max);

// 4 
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_get (
 *                          DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
 *                          VOID*                     pv_get_type,
 *                          SIZE_T*                   pz_size,
 *                          INT32*                    peResult)
 *  \brief get information of different audio type
 *  \param [in] e_aud_type audio type
 *  \param [out] pv_get_type audio type
 *  \param [out] pz_size size
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_get (
                    DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
                    VOID*                     pv_get_type,
                    SIZE_T*                   pz_size,
                    INT32*                    peResult);

// 4
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_set (
 *                          DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
 *                          VOID*                     pv_set_type,
 *                          SIZE_T                    z_size,
 *                          INT32*                    peResult)
 *  \brief set audio type
 *  \param [in] e_aud_type audio type
 *  \param [out] pv_set_type audio type
 *  \param [in] z_size size
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_d_custom_aud_set (
                    DRV_CUSTOM_AUD_TYPE_T     e_aud_type,
                    VOID*                     pv_set_type,
                    SIZE_T                    z_size,
                    INT32*                    peResult);

// 5
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AudSet(DRV_COMP_ID_T* pt_comp_id,
 *                          DRV_SET_TYPE_T  e_set_type,
 *                          const VOID*     pv_set_info,
 *                          SIZE_T          z_set_info_len,
 *                          INT32*          peResult)
 *  \brief Set Audio
 *  \param [out] pt_comp_id compnent id
 *  \param [in] e_set_type audio type
 *  \param [out] pv_set_info audio type
 *  \param [in] z_set_info_len size
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AudSet(DRV_COMP_ID_T* pt_comp_id,
                    DRV_SET_TYPE_T  e_set_type,
                    const VOID*     pv_set_info,
                    SIZE_T          z_set_info_len,
                    INT32*          peResult);

// 5
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AudGet(DRV_COMP_ID_T* pt_comp_id,
 *                          DRV_GET_TYPE_T  e_get_type,
 *                          VOID*           pv_get_info,
 *                          SIZE_T*         pz_get_info_len,
 *                          INT32*          peResult)
 *  \brief Get information of audio
 *  \param [out] pt_comp_id compnent id
 *  \param [in] e_get_type audio type
 *  \param [out] pv_get_info audio infomation
 *  \param [out] pz_get_info_len length of audio information
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AudGet(DRV_COMP_ID_T* pt_comp_id,
                    DRV_GET_TYPE_T  e_get_type,
                    VOID*           pv_get_info,
                    SIZE_T*         pz_get_info_len,
                    INT32*          peResult);

// 4
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AudDisconnect(DRV_COMP_ID_T* pt_comp_id,
 *                          DRV_DISC_TYPE_T  e_disc_type,
 *                          const VOID*      pv_disc_info,
 *                          INT32*           peResult)
 *  \brief Disconnet audio
 *  \param [out] pt_comp_id compnent id
 *  \param [in] e_disc_type disconnect audio type
 *  \param [out] pv_disc_info disconnect audio infomation
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AudDisconnect(DRV_COMP_ID_T* pt_comp_id,
                    DRV_DISC_TYPE_T  e_disc_type,
                    const VOID*      pv_disc_info,
                    INT32*           peResult);

// 4
/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AudConnect(DRV_COMP_ID_T*  pt_comp_id,
 *                          DRV_CONN_TYPE_T  e_conn_type,
 *                          const VOID*      pv_conn_info,
 *                          UINT8            u1SwdmxSrcId,
 *                          INT32*           peResult)
 *  \brief Connect audio
 *  \param [out] pt_comp_id compnent id
 *  \param [in] e_conn_type connect audio type
 *  \param [out] pv_conn_info connect audio infomation
 *  \param [in] u1SwdmxSrcId SWDMX Source Id
 *  \param [out] peResult result
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AudConnect(DRV_COMP_ID_T*  pt_comp_id,
                    DRV_CONN_TYPE_T  e_conn_type,
                    const VOID*      pv_conn_info,
                    UINT8            u1SwdmxSrcId,
                    INT32*           peResult);


EXTERN MT_RESULT_T MTAUDDEC_AUD_GetDecoderState(UINT8 u1DecId, MTAUDDEC_DEC_STATE_T *prDecState);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_IsDecoderRealPlay(UINT8 u1DecId, BOOL* pfgIsPlay)
 *  \brief Check if audio decoder really play out
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [out] pfgIsPlay true/false
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_IsDecoderRealPlay(UINT8 u1DecId, BOOL* pfgIsPlay);                    

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_DSPCmdPlay(UINT8 u1DecId)
 *  \brief Play audio decoder
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_DSPCmdPlay(UINT8 u1DecId);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_Read32ByteID(UINT8 *u1ID_p,
 *                          UINT32 u4Num)
 *  \brief read 32-bytes id
 *  \param [out] u1ID_p id
 *  \param [in] u4Num number of bytes
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_Read32ByteID(UINT8 *u1ID_p,
                    UINT32 u4Num);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_IsHeadphoneExist (BOOL* pfgExist)
 *  \brief Check if headphone exists
 *  \param [out] pfgExist true/false
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_IsHeadphoneExist (BOOL* pfgExist);                    

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_PlaySetupMelody(UINT8 u1DecId, UINT32 u4Channel, UINT32 u4RepeatCount)
 *  \brief Play Melody
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \param [in] u4Channel Channel
 *  \param [in] u4RepeatCount Repeat Counts
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_PlaySetupMelody(UINT8 u1DecId, UINT32 u4Channel, UINT32 u4RepeatCount);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_AUD_MW_RegCbFunc(MTAUDDEC_AUD_MW_CB_FUNC_ID_T eFuncType, UINT32 u4FuncPtr, UINT8 u1DecId)
 *  \brief Register CallBack Function
 *  \param [in] eFuncType CB Function type.
 *  \param [in] u4FuncPtr CB Function pointer.
 *  \param [in] u1DecId Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_AUD_MW_RegCbFunc(MTAUDDEC_AUD_MW_CB_FUNC_ID_T eFuncType, UINT32 u4FuncPtr, UINT8 u1DecId);

#ifdef CC_AUD_SUPPORT_ENC

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_Set (UINT8 u1DecId, MTAUDDEC_ENCODING_FORMAT_T rEncType);
 *  \brief Set Audio Encoder Parameters
 *  \param [in] u1DecId Source decoder for encoder.
 *  \param [in] rEncType Encoder type.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_Set (UINT8 u1DecId, MTAUDDEC_ENCODING_FORMAT_T rEncType);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_Get (UINT8 *pu1DecId, MTAUDDEC_ENCODING_FORMAT_T *prEncType, UINT8 *pu1Enable);
 *  \brief Get Audio Encoder Parameters
 *  \param [out] pu1DecId Source decoder for encoder.
 *  \param [out] prEncType Encoder type.
 *  \param [out] pu1Enable Is Encoder Enabled.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_Get (UINT8 *pu1DecId, MTAUDDEC_ENCODING_FORMAT_T *prEncType, UINT8 *pu1Enable);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T MTAUDDEC_RegAencCbFunc(void *pfnCbFct)
 *  \brief Register Audio Encoder Callback Function
 *  \param [in] pfnCbFct callback function pointer.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T MTAUDDEC_RegAencCbFunc(void *pfnCbFct);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_Enable(UINT8 fgEnable);
 *  \brief Trigger Audio Encoder Start/Stop
 *  \param [in] fgEnable true/false. 
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_Enable(UINT8 fgEnable);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_Play (UINT8 u1DecId, MTAUDDEC_ENCODING_FORMAT_T rEncType)
 *  \brief Play Encoder
 *  \param [in] u1DecId Decoder Id.
 *  \param [in] rEncType Encoder Format.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_Play (UINT8 u1DecId, MTAUDDEC_ENCODING_FORMAT_T rEncType);

/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_Stop (UINT8 u1DecId)
 *  \brief Play Encoder
 *  \param [in] u1DecId Decoder Id.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_Stop (UINT8 u1DecId);
#endif

#ifdef CC_AUD_DDI


/*! \if mw_if2
 *  \fn EXTERN MT_RESULT_T  MTAUDENC_SetEncSourceFrom (UINT8 u1DecId,MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom)
 *  \brief Play Encoder
 *  \param [in] u1DecId Decoder Id.
 *  \param [in] eStreamFrom Stream From.
 *  \return a MTAL error code.
 *  \retval MTR_OK Success.
 *  \retval MTR_NOT_OK Fail.
 *  \endif
 */
EXTERN MT_RESULT_T  MTAUDENC_SetEncSourceFrom (UINT8 u1DecId,MTAUDDEC_DEC_STREAM_FROM_T eStreamFrom);

EXTERN MT_RESULT_T  MTAUDDEC_DualModeEnable (BOOL fgEnable);

EXTERN MT_RESULT_T  MTAUDDEC_TriModeEnable (BOOL fgEnable);
#endif
//kevin zhu 2014-6-27
EXTERN MT_RESULT_T MTAUDDEC_GetSpectrum(UINT8 u1DecId, UINT32* pu4Spectrum);

/*! @} */

/*! @} */

	/**Get AQ Version.
	*@param AqVersion                  AQ version
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDENC_GetAQVersion (CHAR* AqVersion);
	

	/**Setup press key sound flag.
	*@param fgEnable                   on/off.
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetMixSoundEnable(BOOL fgEnable);
	
	
	/**Setup press key sound volume.
	*@param u1MixSoundVolume		   mixsound volume[0-100].
	*@retval MTR_OK 				   Success.
	*@retval MTR_NOT_OK 			   Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetMixSoundVol(UINT8 u1MixSoundVolume);
	

	/**Setup press power on flag.
	*@param fgEnable                   on/off.
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetPowerOnMusic(BOOL fgEnable);
	
	/**get power on flag.
	*@param fgEnable				   on/off.
	*@retval MTR_OK 				   Success.
	*@retval MTR_NOT_OK 			   Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_GetPowerOnMusic(BOOL * pfgEnable);

	/**Setup MIC PHONE TYPE.
	*@param u1micphonetype             mic phone type[RF/USB dongle].
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetMicPhoneType(UINT8 u1micphonetype);

	
	/**get spectrum info
	*@param u1DecId 				   Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@param pu4Data 				   get data.
	*@retval MTR_OK 				   Success.
	*@retval MTR_NOT_OK 			   Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_GetSpectrumInfo(UINT8 u1DecId,UINT32* pu4Data);

	/**Setup EQ band configuration.
	*@param u1DecId 				   Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@param u1BandIdx				   0-6.
	*@param i2BandVal				   band value.
	*@retval MTR_OK 				   Success.
	*@retval MTR_NOT_OK 			   Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetBandCfg(UINT8 u1DecId,UINT8 u1BandIdx,INT16 i2BandVal);
	
	/**Setup EQ band configuration.
	*@param u1DecId 				   Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@param eQType					   EQ mode.
	*@param eqValue 				   band value array.
	*@param u2DataLen				   band length.
	*@retval MTR_OK 				   Success.
	*@retval MTR_NOT_OK 			   Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_SetAudEqualizerEffect(UINT8 u1DecId,MTAUDDEC_EQ_TYPE_T eQType,INT16* eqValue,UINT8 u2DataLen);

	/**Get individual channel delay
	*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@param eChIndex                   Individual channel.
	*@param u2Delay                    Delay (0~300 ms with 1 ms/step).
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_GetChannelDefautDelay (UINT8 u1DecId, MTAUDDEC_CH_T eChIndex, UINT16 *u2Delay);

	 /**Get use define EQ cfg 
	*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@@param                              u1BandIdx  0~4.
	*@rparam                                pi1BandValue (-28 ~ +28)
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T  MTAUDDEC_GetUserDefineEqCfg (UINT8 u1DecId, UINT8 u1BandIndex,INT8 *i1BandValue);

	/**Setup MTAUDDEC_SetDrvCfgEqualizer.
	*@param u1DecId                    Decoder Id (AUD_DEC_MAIN or AUD_DEC_AUX).
	*@param eQType                 EQ type.
	*@retval MTR_OK                    Success.
	*@retval MTR_NOT_OK                Fail.
	*/
	EXTERN MT_RESULT_T   MTAUDDEC_SetDrvCfgEqualizer(UINT8 u1DecId,MTAUDDEC_EQ_TYPE_T eQType);

    //Setting PEQ
    EXTERN MT_RESULT_T MTAUDDEC_AUD_DspSetPEQCfg2(UINT8 u1DecId, UINT8 u1PEQSet, UINT32 u4Frequency,
                            UINT32 eQValue, INT16 i2Gain);
    
    EXTERN MT_RESULT_T MTAUDDEC_AUD_DspGetPEQCfg2(UINT8 u1DecId, UINT8 u1PEQSet, UINT32 *u4Frequency,
                            UINT32 *eQValue, INT16 *i2Gain);

	EXTERN MT_RESULT_T  MTAUDDEC_SetVolumeCurve (UINT32 *u4Parameter,UINT8 u1DataSize);
	EXTERN MT_RESULT_T  MTAUDDEC_SetMasterVol_RegData (UINT8 u1DecId,UINT32 u4RegData);
	EXTERN MT_RESULT_T  MTAUDDEC_SetExternalVol_RegData (UINT8 u1DecId,MTAUDDEC_CH_T eChIndex,UINT32 u4RegData);

	EXTERN MT_RESULT_T   MTAUDDEC_SetMixSoundMute(BOOL fgEnable);
	EXTERN MT_RESULT_T MTAUDDEC_AUD_SetAoutGain(UINT8 u1AoutVolume);
#ifdef __cplusplus
}
#endif

#endif //MT_AUDDEC_H

