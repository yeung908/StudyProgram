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
 * $RCSfile: mthdcp2.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mthdcp2.h
 *  This header file declares exported APIs of hdcp2 module.
 */

#ifndef MT_HDCP2_H
#define MT_HDCP2_H

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

//#include "mttype.h"
//#ifdef __KERNEL__
#include "x_os.h"
//#include <linux/types.h>
//#endif

//-----------------------------------------------------------------------------
// MTAL Constant definitions
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// MTAL Type definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Private MW_IF Constant definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Private MW_IF Type definitions
//-----------------------------------------------------------------------------
/** 
 * MTDRM_TZIF_HDCP2_SET_ENC_LC128_T : Encrypted HDCP LC128
 */
typedef struct
{
   unsigned char *pEncKey;  /**< encypted HDCP LC128 */
   UINT32 u4Length;         /**< encypted HDCP LC128 length */
   int rRet;                /**< return value for setting encypted LC128 */
}MTDRM_TZIF_HDCP2_SET_ENC_LC128_T;
/** 
 * MTDRM_TZIF_HDCP2_SET_ENC_LC128_T : Encrypted HDCP Key
 */
typedef struct
{
   unsigned char *pEncKey;  /**< encypted HDCP key */
   UINT32 u4length;         /**< encypted HDCP key length */
   int rRet;                /**< return value for setting encrypted HDCP key */
}MTDRM_TZIF_HDCP2_SET_ENC_KEY;
/** 
 * MTDRM_TZIF_HDCP2_GET_CERT_INFO : HDCP certificate information
 */
typedef struct
{
   unsigned char *pData;    /**< HDCP certificate */
   UINT32 u4length;         /**< HDCP certificate length */
   int rRet;                /**< return value for getting HDCP certificate */
}MTDRM_TZIF_HDCP2_GET_CERT_INFO;
/** 
 * MTDRM_TZIF_HDCP2_DECRYPT_RSAESOAEP : Encrypted km with kpubrx to be decrypted by RSAESOAEP
 */
typedef struct
{
   unsigned char *pEkpub_km;    /**< Encrypted km with kpubrx */
   UINT32 u4length;         /**< HDCP Ekm length */   
   int rRet;                    /**< return value for RSAESOAEP decryption */
}MTDRM_TZIF_HDCP2_DECRYPT_RSAESOAEP;
/** 
 * MTDRM_TZIF_HDCP2_KD_KEY_DERIVATION : pRtx to derive Kd
 */
typedef struct
{
   unsigned char *pRtx; /**< Received random value form HDCP 2.0 TX */
   UINT32 u4length;     /**< Length of pRtx */
   int rRet;            /**< return value for Kd derivation */
}MTDRM_TZIF_HDCP2_KD_KEY_DERIVATION;
/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_H_PRIME : Repeater, pRtx to derive H prime.
 */
typedef struct
{
   unsigned char *pH_prime; /**< H prime */
   unsigned char Repeater;  /**< Repeater flag (1byte) (0x00 or 0x01) */
   unsigned char *pRtx;     /**< Received random value form HDCP 2.0 TX */
   int rRet;                /**< return value for computing H prime */
}MTDRM_TZIF_HDCP2_COMPUTE_H_PRIME;
/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_L_PRIME : pRn and pRrx to derive L prime.
 */
typedef struct
{
   unsigned char *pL_prime; /**< L prime */
   unsigned char *pRn;      /**< Received random value form HDCP 2.0 TX */
   unsigned char *pRrx;     /**< Random value generated from HDCP 2.0 RX */
   int rRet;                /**< return value for computing L prime */
}MTDRM_TZIF_HDCP2_COMPUTE_L_PRIME;
/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_KH : Return value for computing Kh
 */
typedef struct
{
   int rRet;    /**< return value for computing Kh */
}MTDRM_TZIF_HDCP2_COMPUTE_KH;
/** 
 * MTDRM_TZIF_HDCP2_ENCRYPT_KM_USING_KH : Encrypted Km and input message pM
 */
typedef struct
{
   unsigned char *pEkh_km;  /**< Encrypted Km value using kh key by AES mechanis */
   unsigned char *pM;       /**< Input message of AES crypto engine */
   int rRet;                /**< return value for encrypting Km */
}MTDRM_TZIF_HDCP2_ENCRYPT_KM_USING_KH;
/** 
 * MTDRM_TZIF_HDCP2_DECRYPT_KM_USING_KH : Encrypted Km and input message pM
 */
typedef struct
{
   unsigned char *pM;       /**< Input message of AES crypto engine */
   unsigned char *ekh_km;   /**< Encrypted Km value from HDCP 2.0 TX */
   int rRet;                /**< return value for decrypting Km */
}MTDRM_TZIF_HDCP2_DECRYPT_KM_USING_KH;
/** 
 * MTDRM_TZIF_HDCP2_DECRYPT_EKS : pRtx, pRrx and pRn for decrypting eKs
 */
typedef struct
{
   unsigned char *pEks;     /**< Received session key from HDCP 2.0 TX */
   unsigned char *pRtx;     /**< Received random value form HDCP 2.0 TX */
   unsigned char *pRrx;     /**< Random value generated from HDCP 2.0 RX (64bit) */
   unsigned char *pRn;      /**< Received random value form HDCP 2.0 TX */
   int rRet;                /**< return value for decrypting eKs */
}MTDRM_TZIF_HDCP2_DECRYPT_EKS;
/** 
 * MTDRM_TZIF_HDCP2_KS_XOR_LC128 : Return value of doing Ks xor LC128
 */
typedef struct
{
   int rRet;    /**< return value for doing Ks xor LC128 */
}MTDRM_TZIF_HDCP2_KS_XOR_LC128;
/** 
 * MTDRM_TZIF_HDCP2_SetRiv_Pid : Riv and Pidx of the encrypted stream to driver for data decryption
 */
typedef struct
{
   unsigned char *pRiv;     /**< Received 64-bit pseudo-random number Riv from HDCP 2.0 TX during SKE. */
   UINT32 pid;              /**< The Pidx of the stream that need to be decrypted */
   int rRet;                /**< return value for decrypting eKs */
}MTDRM_TZIF_HDCP2_SetRiv_Pid;
/** 
 * MTDRM_TZIF_HDCP2_PresetKsLC128 : pKs and LC128
 */
typedef struct
{
   unsigned char *pKs;      /**< session key */
   unsigned char *pLC128;   /**< 128-bit secret global constant */
   int rRet;                /**< return value for preseting Ks and LC128 */
}MTDRM_TZIF_HDCP2_PresetKsLC128;
/**
 * MTDRM_TZIF_HDCP2_GENERATE_KM :
 */
typedef struct
{
   unsigned char *pMaskedDB; /**< XOR DB and DB mask, and adding 4bytes zero padding, 99 bytes */
   unsigned char *pDB;       /**< Temp DB value for RSA encryption, 95 bytes */
   unsigned char *pDBmask;   /**< calculated DB mask for RSA encryption, 95 bytes */
   int rRet;                 /**< return value for generating Km */
}MTDRM_TZIF_HDCP2_GENERATE_KM;
/**
 * MTDRM_TZIF_HDCP2_GENERATE_KS :
 */
typedef struct
{
   unsigned char* pEks;      /**< Encrypted Ks using dkey2 */
   unsigned char* pRrx;      /**< Rrx 8 byte value */
   unsigned char* pRtx;      /**< Rtx 8 byte value */
   unsigned char* pRn;       /**< Rn 8 byte random number */
   int rRet;
}MTDRM_TZIF_HDCP2_GENERATE_KS;
/**
 * MTDRM_TZIF_HDCP2_ENC_KM : the encrypted Km
 */
typedef struct
{
   unsigned char *pEncKm;    /**< encrypted Km  */
   int rRet;                 /**< return value for getting/setting encrypted Km */
}MTDRM_TZIF_HDCP2_ENC_KM;




/*for HDCP 2.2 */


/** 
 * MTDRM_TZIF_HDCP2_KD_KEY_DERIVATION : pRtx to derive Kd
 */
typedef struct
{
   unsigned char *pRtx; /**< Received random value form HDCP 2.2 TX */
   unsigned char *pRrx; /**< Received random value form HDCP 2.2 RX */   
   UINT32 u4length;     /**< Length of pRtx */
   int rRet;            /**< return value for Kd derivation */
}MTDRM_TZIF_HDCP2_2_KD_KEY_DERIVATION;


/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_H_PRIME : Repeater, pRtx to derive H prime.
 */
typedef struct
{
   unsigned char *pH_prime; /**< H prime */
   unsigned char Repeater;  /**< Repeater flag (1byte) (0x00 or 0x01) */
   unsigned char *pRtx;     /**< Received random value form HDCP 2.2 TX */

   unsigned char   rx_version;
   unsigned short  rx_cap_mask;
   unsigned char   tx_version;
   unsigned short  tx_cap_mask;
   
   int rRet;                /**< return value for computing H prime */


   
}MTDRM_TZIF_HDCP2_2_COMPUTE_H_PRIME;
/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_L_PRIME : pRn and pRrx to derive L prime.
 */
typedef struct
{
   unsigned char *pL_prime; /**< L prime */
   unsigned char *pRn;      /**< Received random value form HDCP 2.0 TX */
   unsigned char *pRrx;     /**< Random value generated from HDCP 2.0 RX */
   int rRet;                /**< return value for computing L prime */
}MTDRM_TZIF_HDCP2_2_COMPUTE_L_PRIME;




typedef struct
{
   int key_type;      
   int rRet;                
}MTDRM_TZIF_HDCP2_Set_Key_Type;

typedef struct
{
   unsigned char *pKeySet;  /**< encypted HDCP key set */
   UINT32 u4length;         /**< encypted HDCP key length */
   int rRet;                /**< return value for setting encrypted HDCP key */
}MTDRM_TZIF_HDCP2_SET_ENC_KEY_SET;


/* for HMAC SHA256: sync from lgwebos*/
typedef struct
{
    unsigned char *output;
    unsigned char *au1rKey;
    unsigned char *input;
	unsigned int  au1rKeyLen;	
	unsigned int  intputLen;
	int rRet;
}MTDRM_TZIF_HDCP2_HMAC_SHA256;

/* for HDCP TX */

/**
 * MTDRM_TZIF_HDCP2_RETRV_EKH_KM :
 */
typedef struct
{
   unsigned char *pEkh_km; 	/**< return value or ekhkm **/
   unsigned char *pm;       	/**< return value of m **/
   unsigned char *pRX_ID;   	/**< RX ID **/
   int rRet;                /**< return value for retrv ekh_km*/
}MTDRM_TZIF_HDCP2_RETRV_EKH_KM;




/**
 * MTDRM_TZIF_HDCP2_SaveRxPairingInfo :
 */
typedef struct
{
   unsigned char *pRX_ID; 	/**< Received   RX ID    **/
   unsigned char *pEkh_km;  /**< Received   ekh_km  **/
   unsigned char *pm;       /**< Recieved   m **/   
   int rRet;                /**< return value for SaveRxPairingInfo*/
}MTDRM_TZIF_HDCP2_SaveRxPairingInfo;






/**
 * MTDRM_TZIF_HDCP2_CheckRxID :
 */
typedef struct
{
   unsigned char *pRX_ID;	/**< Received	RX ID	 **/
   int rRet;				/**< return value for SaveRxPairingInfo*/
}MTDRM_TZIF_HDCP2_CheckRxID;





/** 
 * MTDRM_TZIF_HDCP2_COMPUTE_M_PRIME : Repeater, pRtx to derive H prime.
 */
typedef struct
{
   unsigned char *pM_prime; 		/**< M prime */
   unsigned char *STREAMID_TYPE;    /**< Received stream type */
   unsigned char *seq_num_M;        /**< Received random value form HDCP  TX */
   int STREAMID_TYPE_LEN;           /**< Received stream type len */
   int rRet;                        /**< return value for computing M prime */
}MTDRM_TZIF_HDCP2_COMPUTE_M_PRIME;





typedef struct
{
    unsigned char *pV_prime;
	unsigned char *id_list;
	unsigned char DEPTH;
	unsigned char DEVICE_COUNT;
	unsigned char MAX_DEVS_EXCEEDED;
	unsigned char MAX_CASCADE_EXCEEDED;
	int rRet;

}MTDRM_TZIF_HDCP2_0_CALVPRIME_T;





typedef struct
{
    unsigned char *pV_prime;
	unsigned char *id_list;
	unsigned char DEPTH;
	unsigned char DEVICE_COUNT;
	unsigned char MAX_DEVS_EXCEEDED;
	unsigned char MAX_CASCADE_EXCEEDED;
	unsigned char HDCP2_0_REPEATER_DOWNSTREAM;
	unsigned char HDCP1_DEVICE_DOWNSTREAM;
	unsigned int  seq_num_V;
	int rRet;

}MTDRM_TZIF_HDCP2_2_CALVPRIME_T;



/**
 * MTDRM_TZIF_HDCP2_VERIFY_SIGNATURE :
 */
typedef struct
{
   unsigned char *pKpub; 	
   unsigned char *pCert;      
   int rRet;               
}MTDRM_TZIF_HDCP2_VERIFY_SIGNATURE;




typedef struct
{
   unsigned char *pEkpub_km;    /**< Encrypted km with kpubrx */
   int rRet;                    /**< return value for RSAESOAEP decryption */
}MTDRM_TZIF_HDCP2_Generate_EKm;






/* SONY IPTVES */

#define MTAL_PO_URR_LEN			    16
#define MTAL_PO_CKEY_ID_LEN		    6
#define MTAL_PO_TIERBITS_LEN	    8
#define MTAL_PO_EXPORT_INFO_MAX_LEN	16
#define MTAL_PO_ECM_LEN				98
#define MTAL_PO_MAX_CRL_DP_LEN      256
#define MTAL_PO_CKEY_LEN 			16
#define MTAL_PO_DEVICE_ID_LEN 		8
#define MTAL_PO_SIG_LEN				56


typedef struct {
    unsigned char     urr[MTAL_PO_URR_LEN];
    unsigned char     urr_len;
    unsigned char     action_id;
    unsigned char     action_param;
} po_key_ref_t;


typedef struct {
    u_int8_t     flags;
    u_int8_t     ckey_id[MTAL_PO_CKEY_ID_LEN];
    u_int16_t    priv_data;
    u_int8_t     tierbits[MTAL_PO_TIERBITS_LEN];
    u_int16_t    oci;
    u_int8_t     export_info[MTAL_PO_EXPORT_INFO_MAX_LEN];
    u_int16_t    export_info_len;
    u_int32_t    not_before;
    u_int32_t    not_after;
    u_int8_t     num;
    u_int8_t     num_in_use;
} po_key_info_t;




/* sac */
typedef struct
{
	int id;

	int req_num;

	char *req_lst;
	unsigned int req_list_size;

	int out_handle;

	int rRet;                
   
}MTDRM_TZIF_IPTVES_SAC_CONSTRUCT;



typedef struct
{
	int in_handle;

	unsigned int out_success_num;
	
	unsigned int out_trans_flag_status;

	int rRet;                
   
}MTDRM_TZIF_IPTVES_SAC_DESTRUCT;



typedef struct
{
	int in_handle;

	unsigned char *out_msg;
	
	unsigned int io_msg_len;

	int out_last_req_flag;

	int rRet;               
   
}MTDRM_TZIF_IPTVES_SAC_MakeMSG;




typedef struct
{
	int in_handle;

	unsigned char *in_msg;
	
	unsigned int in_msg_len;

	int out_end_flag;

	int rRet;               
                   
   
}MTDRM_TZIF_IPTVES_SAC_ProcessMSG;




/* nvs */
typedef struct
{
	unsigned char 	  *in_ro;
	unsigned int 	  		   in_ro_len;
	unsigned char       	  *in_rw;
	unsigned int 	  		   in_rw_len;

	int rRet; 

}MTDRM_TZIF_IPTVES_nvs_Init_T;




typedef struct
{

	unsigned char       	  *out_rw;
	unsigned int 	  		   out_rw_len;

	int rRet; 

}MTDRM_TZIF_IPTVES_nvs_Fin_T;



typedef struct
{
	unsigned int 	  		   out_rw_len;

	int rRet; 

}MTDRM_TZIF_IPTVES_nvs_GetRWLen_T;





/* sdi */



typedef struct
{
   int current_time_secs;
   int gmtoff;

   int rRet;    /**< return value for sdi_Init  */
}MTDRM_TZIF_IPTVES_sdi_Init_T;



typedef struct
{
   int rRet;    /**< return value for computing sdi_Fin */
}MTDRM_TZIF_IPTVES_sdi_Fin_T;



typedef struct
{
   int rRet;    /**< return value for computing sdi_CleanupNVS */
}MTDRM_TZIF_IPTVES_sdi_CleanupNVS_T;





typedef struct
{
	int in_thid;
	unsigned char *out_devid;//[MTAL_PO_DEVICE_ID_LEN];
	int out_devid_len;
	//unsigned char out_devid[8];

    int rRet;
	
}MTDRM_TZIF_IPTVES_sdi_GetDeviceID_T;



typedef struct
{
	int		         		   in_thid;
	const unsigned char 	  *in_msg;
	unsigned int 	  		   in_msg_len;
	const unsigned char       *in_pkipath;
	unsigned int 	  		   in_pkipath_len;
	const unsigned char       *in_sig;
	unsigned int			   in_sig_len;

    int rRet;
	
}MTDRM_TZIF_IPTVES_sdi_VerifyServiceMetaData_T;


typedef struct
{
	int			 in_thid;
	int		     out_is_requested;

    int rRet;
	
}MTDRM_TZIF_IPTVES_sdi_JudgeCRLUpdate_T;





typedef struct
{
	int			 in_thid;
	char 		 *out_crl_dp;//[MTAL_PO_MAX_CRL_DP_LEN];
	int			out_crl_dp_len;
	//char		 out_crl_dp[256];

	int rRet;

}MTDRM_TZIF_IPTVES_sdi_GetCRLDstPoint_T;




typedef struct
{
	int 				   in_thid;
	const unsigned char	  *in_crl;
	unsigned int		   in_crl_len;
	int					   out_is_updated;

    int rRet;
	
}MTDRM_TZIF_IPTVES_sdi_SetCRL_T;


typedef struct
{
	int			  out_is_valid;

    int rRet;
	
}MTDRM_TZIF_IPTVES_sdi_CheckTrustedTime_T;






/* ecm :*/
typedef struct
{
	int		            in_thid;
	unsigned int		in_rend_id;
	unsigned char	   *in_ecm;//[MTAL_PO_ECM_LEN];
	unsigned int        in_ecm_len; 
	//unsigned char		in_ecm[98];


    int rRet;
	
}MTDRM_TZIF_IPTVES_ecm_ExtractScrambleKey_T;




typedef struct
{
	int 			  in_thid;
	//unsigned char   in_ecm[PO_ECM_LEN];
	unsigned char	  *in_ecm;// [98];
	unsigned int	   in_ecm_len;
	
	unsigned char	 *out_skey_even;
	unsigned int	  out_skey_even_len;
	
	unsigned char	 *out_skey_odd;
	unsigned int	 out_skey_odd_len;
	

    int rRet;
	
}MTDRM_TZIF_IPTVES_ecm_GetScrambleKey_T;










/* drm */

typedef struct
{
	int				in_thid;
	unsigned int 	in_rend_id;
	
	po_key_ref_t  	*in_key_ref;
	unsigned int     in_key_ref_len;

    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_ExtractContentKey_T;


typedef struct
{
	int					in_thid;
	po_key_ref_t  	   *in_key_ref;
	unsigned int	    in_key_ref_len;

    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_DelContentKey_T;




typedef struct
{
	int				 in_thid;
	po_key_ref_t  	*in_key_ref;
	unsigned int	 in_key_ref_len;


    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_DelUncommittedKey_T;



typedef struct
{
	int					    in_thid;
	po_key_ref_t  		   *in_key_ref;
	unsigned int	        in_key_ref_len;

	
	po_key_info_t 		   *out_key_info;
	unsigned int	        out_key_info_len;

	

    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_GetKeyInfo_T;



typedef struct
{
	int						 in_thid;
 	unsigned char			 in_action_id;
	
	unsigned int 			 out_num;


    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_GetKeyNum_T;



typedef struct
{
	int					    in_thid;
	unsigned char			in_action_id;
	
	unsigned int 		    *io_num;
	unsigned int 	        io_num_len;
	
	po_key_ref_t  		   *out_key_ref_lst;
	unsigned int			out_key_ref_lst_len;



    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_GetKeyRefList_T;



typedef struct
{
	int					  in_thid;
	
	po_key_ref_t  		 *in_key_ref;
	unsigned int		  in_key_ref_len;

	
	unsigned char		  *out_ckey;//[MTAL_PO_CKEY_LEN];
	unsigned int		  out_ckey_len;
	//unsigned char		  out_ckey[16];

    int rRet;
	
}MTDRM_TZIF_IPTVES_drm_GetContentKey_T;








typedef struct
{
	unsigned int	in_tt;

	int rRet;

}MTDRM_TZIF_IPTVES_time_SetTrustedTime_T;



typedef struct
{
	unsigned int	out_tt;

	int rRet;

}MTDRM_TZIF_IPTVES_time_GetTrustedTime_T;






#endif //MT_HDCP2_H


