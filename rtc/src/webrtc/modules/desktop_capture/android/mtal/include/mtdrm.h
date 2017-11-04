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
 * $RCSfile: mtdrm.h,v $
 * $Revision: #2 $
 * $Date: 2014/11/25 $
 * $Author: yongchao.lee $
 *
 * Description: drm
 *---------------------------------------------------------------------------*/

/** @file mtdrm.h
 *  This header file declares exported APIs of CI module.
 */

#ifndef _MTDRM_H_
#define _MTDRM_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#ifndef TEE_USE_MTDRM_H
#include "mttype.h"
#endif

#include "drv_common.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
// HDCP2 key
#ifdef HDCP_A2_KEY_STRUCTURE
    #define MTDRM_HDCP2_KEYLEN_ENC 900
#else
    #define MTDRM_HDCP2_KEYLEN_ENC 864             // Key length before AES encryption is 862, and become 864 after AES enryption
#endif


#define MTDRM_HDCP2_KEYSET_LEN_MAX 1019


#define MTDRM_HDCP2_KEYLEN_ENCLC128 16

#define MTDRM_HDCP2_CERT_RX     (522)
#define MTDRM_HDCP2_KEYLEN_RXID (5)                  // Receiver ID 40 bit Low Secure Storage
#define MTDRM_HDCP2_KEYLEN_PUBLIC (128 + 3)     // Device Public Key 1024 + 24 bit Low Secure Storage
#define MTDRM_HDCP2_KEYLEN_RESERVED (2)          // RESERVED
#define MTDRM_HDCP2_KEYLEN_ROOTSIGN (384)      // Root Signature 3072 bit Low Secure Storage
#define MTDRM_HDCP2_KEYLEN_CERT (522) 

#define MTDRM_HDCP2_KEYLEN_EKPUB_KM 128
#define MTDRM_HDCP2_KEYLEN_RTX 8
#define MTDRM_HDCP2_KEYLEN_RRX 8
#define MTDRM_HDCP2_KEYLEN_REPEATER 1
#define MTDRM_HDCP2_KEYLEN_RRN 8
#define MTDRM_HDCP2_KEYLEN_HPRIME 32
#define MTDRM_HDCP2_KEYLEN_LPRIME 32
#define MTDRM_HDCP2_KEYLEN_RIV 8
#define MTDRM_HDCP2_KEYLEN_KS 16
#define MTDRM_HDCP2_KEYLEN_LC128 16

// For HDCP2 TX
#define MTDRM_HDCP2_KEYLEN_MASKED_DB 99
#define MTDRM_HDCP2_KEYLEN_DB 95
#define MTDRM_HDCP2_KEYLEN_DBMASK 95
#define MTDRM_HDCP2_KEYLEN_KM 16
#define MTDRM_HDCP2_KEYLEN_ENCKM (16+64)

// AKE_Sotred_km
#define MTDRM_HDCP2_KEYLEN_EKH_KM 16
#define MTDRM_HDCP2_KEYLEN_M 16
/* sync from lgwebos*/
#define MTDRM_HDCP2_HMAC_SHA256_OUT_LEN 32

#define MTDRM_HDCP2X_RX_NORMAL_ENC_KEY_SET_SIZE 		(880)

// key layout: 	(912 + 36)	// 18 + 18 + 862 + PADDING +36bytes secure storage padding


#define MTDRM_HDCP2X_RX_PHILIPS_2K14_ENC_KEY_SET_SIZE		(912 + 36)


enum
{
    MTDRM_HDCP2_KEY_SET_TYPE_NORMAL = 0,
	MTDRM_HDCP2_KEY_SET_TYPE_SONY_2K14,
    MTDRM_HDCP2_KEY_SET_TYPE_PHILIPS_2K13,
    MTDRM_HDCP2_KEY_SET_TYPE_PHILIPS_2K14,
    MTDRM_HDCP2_KEY_SET_TYPE_KM,
    MTDRM_HDCP2_KEY_SET_TYPE_MAX
};




//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------


/**
 * Hdcp2 key.
 *
*/
typedef struct
{
    unsigned char au1EncKey[MTDRM_HDCP2_KEYLEN_ENCLC128];
}MTDRM_HDCP2_ENCLC128_T;


typedef struct
{
    unsigned char au1EncKey[MTDRM_HDCP2_KEYLEN_ENC];
}MTDRM_HDCP2_KEYENC_T;



typedef struct
{
    unsigned char au1EncKeySet[MTDRM_HDCP2_KEYSET_LEN_MAX];
	unsigned char au1KeyType;
	unsigned int au1KeySize;
	
}MTDRM_HDCP2_KEYSET_ENC_T;


typedef struct
{
    unsigned char au1RxID[MTDRM_HDCP2_KEYLEN_RXID];
    unsigned char au1Public[MTDRM_HDCP2_KEYLEN_PUBLIC];
    unsigned char au1ProtocolDescripter;
    unsigned char au1Reserved;
    unsigned char au1RootSign[MTDRM_HDCP2_KEYLEN_ROOTSIGN];
}MTDRM_HDCP2_KEYCERT_T;


typedef struct
{
    unsigned char au1Ekpubkm[MTDRM_HDCP2_KEYLEN_EKPUB_KM];
}MTDRM_HDCP2_EKPUBKM_T;

typedef struct
{
    unsigned char au1rTx[MTDRM_HDCP2_KEYLEN_RTX];
}MTDRM_HDCP2_RTX_T;

typedef struct
{
    unsigned char au1rRx[MTDRM_HDCP2_KEYLEN_RRX];
}MTDRM_HDCP2_RRX_T;


typedef struct
{
    unsigned char au1rHprime[MTDRM_HDCP2_KEYLEN_HPRIME];
    unsigned char u1Repeater;
    unsigned char au1rTx[MTDRM_HDCP2_KEYLEN_RTX];

	unsigned char  rx_version;
	unsigned char  rx_cap_mask[2];
	unsigned char  tx_version;
	unsigned char  tx_cap_mask[2];

}MTDRM_HDCP2_CALHPRIME_T;


typedef struct
{
    unsigned char au1rLprime[MTDRM_HDCP2_KEYLEN_LPRIME];
    unsigned char au1rRn[MTDRM_HDCP2_KEYLEN_RRN];
    unsigned char au1rRx[MTDRM_HDCP2_KEYLEN_RRX];
}MTDRM_HDCP2_CALLPRIME_T;

typedef struct
{
    unsigned char au1Riv[MTDRM_HDCP2_KEYLEN_RIV];
}MTDRM_HDCP2_RIV_T;

typedef struct
{
    unsigned char au1Ks[16];
}MTDRM_HDCP2_KEYKS_T;

typedef struct
{
    unsigned char block_dev[64]; // the name of snapshot partition
    unsigned int img_size; // the size of snapshot image
    unsigned int sig_offet; // the offset of signature
} MTDRM_SNAPSHOT_SIGN_T;


// For Converter
#define MTDRM_HDCP2_KEYLEN_VPRIME 32
#define MTDRM_HDCP2_MAX_DEVICE    31
#define MTDRM_HDCP2_KEYLEN_MPRIME 32

/* for HMAC SHA256: sync from lgwebos*/
typedef struct
{
    unsigned char output[MTDRM_HDCP2_HMAC_SHA256_OUT_LEN];
    unsigned char *au1rKey;
	unsigned int  au1rKeyLen;
    unsigned char *input;
	unsigned int  intputLen;
}MTDRM_HDCP2_CAL_HMAC_SHA256_T;

typedef struct
{
    unsigned char au1rVprime[MTDRM_HDCP2_KEYLEN_VPRIME];
	unsigned char *id_list;
	unsigned char DEPTH;
	unsigned char DEVICE_COUNT;
	unsigned char MAX_DEVS_EXCEEDED;
	unsigned char MAX_CASCADE_EXCEEDED;

}MTDRM_HDCP2_0_CALVPRIME_T;



typedef struct
{
    unsigned char au1rVprime[MTDRM_HDCP2_KEYLEN_VPRIME];
	unsigned char *id_list;
	unsigned char DEPTH;
	unsigned char DEVICE_COUNT;
	unsigned char MAX_DEVS_EXCEEDED;
	unsigned char MAX_CASCADE_EXCEEDED;
	unsigned char HDCP2_0_REPEATER_DOWNSTREAM;
	unsigned char HDCP1_DEVICE_DOWNSTREAM;
	unsigned int  seq_num_V;

}MTDRM_HDCP2_2_CALVPRIME_T;





typedef struct
{
    unsigned char  au1rMprime[MTDRM_HDCP2_KEYLEN_MPRIME];
	unsigned char *STREAMID_TYPE;
	unsigned char  seq_num_M[3];
	unsigned int   STREAMID_TYPE_LEN;	

}MTDRM_HDCP2_2_CALMPRIME_T;















//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/* hdcp 2.0*/
/** Set the encrypted LC128 to driver
 *  @param pEncLc128Key LC128
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_SetEncLc128Key (MTDRM_HDCP2_ENCLC128_T *pEncLc128Key);

/** Set encrypted HDCP key
 *  @param pEncKey Encrypted HDCP KEY
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_SetEncDcp2Key (MTDRM_HDCP2_KEYENC_T *pEncKey);

/** Read the certification information form secure store and write these to each buffer
 *  @param pDcp2Cert ReceiverID, PubKey and RootSign
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_GetCertInfo (MTDRM_HDCP2_KEYCERT_T *pDcp2Cert);

/** Decrypt the km and store the decrypted km to the secure store
 *  @param pEkpub_km Encrypted Km value 
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_DecryptRSAESOAEP (unsigned char *pEkpub_km);

/** Derived kd value in the secure world
 *  @param pRtx Received random value form HDCP 2.0 TX
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_KdKeyDerivation (unsigned char *pRtx);

/** Compute and get H prime
 *  @param pCalHprime Hprime, repeater and rTx
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_ComputeHprime  (MTDRM_HDCP2_CALHPRIME_T *pCalHprime);

/** Compute and get L prime
 *  @param pCalLprime Lprime, rRn and rRx
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_ComputeLprime  (MTDRM_HDCP2_CALLPRIME_T *pCalLprime);

/** Compute Kh and store it to secure DRAM 
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_ComputeKh (void);

/** Encrypt Km value using kh key by AES mechanism
 *  @param pEkh_km encrypted Km value using kh key by AES mechanism
 *  @param pM Input message of AES crypto engine (128bit)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_EncryptKmUsingKh (unsigned char *pEkh_km, unsigned char *pM);

/** AES Decrypt ekh_km which is received from HDCP 2.0 TX
 *  @param pM Input message of AES crypto engine (128bit)
 *  @param ekh_km Encrypted Km value from HDCP 2.0 TX
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_DecryptKmUsingKh (unsigned char *pM, unsigned char *ekh_km);

/** Decrypt ks using XOR operation with (dkey2 XOR rrx), Ks= eks XOR (dkey2 XOR rrx)
 *  @param pEks Received session key from HDCP 2.0 TX
 *  @param pRtx Received random value form HDCP 2.0 TX
 *  @param pRrx Random value generated from HDCP 2.0 RX (64bit)
 *  @param pRn Received random value form HDCP 2.0 TX
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_DecryptEKs (unsigned char *pEks, unsigned char *pRtx, unsigned char *pRrx, unsigned char *pRn);

/** Do XOR operation ks with lc128 and the results is stored in secure DRAM.
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_KsXorLC128 (void);

/** MTDRM_HDCP2_DataDecrypt
 *  Data decryption by Key KsXorLC128
 *
 *  @param  pOutputbuf      Output buffer
 *  @param  pInputbuf       Input buffer
 *  @param  length          Processing size
 *  @param  pCounter        Counter value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_DataDecrypt (unsigned char *pOutputbuf, unsigned char *pInputbuf, int length, unsigned char *pCounter);

/** MTDRM_HDCP2_DataEncrypt
 *  Data encryption by Key KsXorLC128
 *
 *  @param  pOutputbuf      Output buffer
 *  @param  pInputbuf       Input buffer
 *  @param  length          Processing size
 *  @param  pCounter        Counter value
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_DataEncrypt (unsigned char *pOutputbuf, unsigned char *pInputbuf, int length, unsigned char *pCounter);

/** Set Riv and Pidx of the encrypted stream to driver for data decryption
 *  @param pRiv Received 64-bit pseudo-random number Riv from HDCP 2.0 TX during SKE.
 *  @param pid The Pidx of the stream that need to be decrypted
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_SetRiv_Pid (unsigned char *pRiv, unsigned short pid);

/** Set ks and LC128 manually for testing
 *  @param ks session key
 *  @param lc128 128-bit secret global constant lc128
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_PresetKsLC128(unsigned char *ks, unsigned char *lc128);

/** Generate Km
 *  @param pMaskedDB [out]99 bytes - XOR DB and DB mask, and adding 4bytes zero padding
 *  @param pDB       [in]95 bytes - Temp DB value for RSA encryption  
 *  @param pDBmask   [in]95 bytes - calculated DB mask for RSA encryption
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_Generate_Km (unsigned char *pMaskedDB, unsigned char *pDB, unsigned char *pDBmask);

/** Generate Ks
 *  @param pEks    [out]Encrypted Ks using dkey2
 *  @param pRrx     [in]8 byte value
 *  @param pRtx     [in]8 byte value
 *  @param pRn      [in]8 byte random number
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_Generate_Ks (unsigned char *pEks, unsigned char *pRrx, unsigned char *pRtx, unsigned char *pRn);

/** Set the Km with the values previously got from GetEncryptedKm API
 *  @param Km_cipherText    the encrypted Km values (the array size should be MTDRM_HDCP2_KEYLEN_ENCKM)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_SetEncryptedKm(unsigned char *Km_cipherText);

/** Get the Km encrypted values
 *  @param Km_cipherText    the encrypted Km values (the array size should be MTDRM_HDCP2_KEYLEN_ENCKM)
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_HDCP2_GetEncryptedKm(unsigned char *Km_cipherText);

/** MTDRM_SIGN_SNAPSHOT_IMAGE
 *  Calculate snapshot value and store it
 *
 *  @param  blkdev          Block device name
 *  @param  imgSize         Image size
 *  @param  snapOffset      Snap Offset 
 *  @retval MTR_OK          Success.
 *  @retval MTR_NOT_OK      Fail.
 */
int MTDRM_SIGN_SNAPSHOT_IMAGE (const char* blkdev, unsigned int imgSize, unsigned int snapOffset);


/*
	for HDCP 2.2
*/


int MTDRM_HDCP2_2_KdKeyDerivation (unsigned char *pRtx, unsigned char *pRrx);
int MTDRM_HDCP2_2_ComputeHprime (MTDRM_HDCP2_CALHPRIME_T *pCalHprime);
int MTDRM_HDCP2_2_ComputeLprime  (MTDRM_HDCP2_CALLPRIME_T *pCalLprime);


/*
	for HDCP2.X ALIGN

*/

int MTDRM_HDCP2_Set_EncKeySet_into_TZ (MTDRM_HDCP2_KEYSET_ENC_T *pEncKeySet);
int MTDRM_HDCP2_UseTestKey_InKernel(int flag);

/*
	for HDCP TX
*/
int MTDRM_HDCP2_GenerateKmForTx(unsigned char *pEpub_km);
int MTDRM_HDCP2_RetrvEkh_km(unsigned char *pEkh_km, unsigned char *m, unsigned char *id);
int MTDRM_HDCP2_EncryptRSAESOAEP(unsigned char *pEkm, unsigned char *pKm, unsigned char *pKpub);
int MTDRM_HDCP2_PairingInfo(unsigned char *ID, unsigned char *pEkh_km,unsigned char *m);
int MTDRM_HDCP2_EncryptKs(unsigned char *pKs, unsigned char *pRtx, unsigned char *pRrx, unsigned char *pRn);
int MTDRM_HDCP2_CheckRxID(unsigned char *id);
int MTDRM_HDCP2_2_ComputeMprime (MTDRM_HDCP2_2_CALMPRIME_T *pCalMprime);
int MTDRM_HDCP2_0_ComputeVprime(MTDRM_HDCP2_0_CALVPRIME_T * pCalVprime);
int MTDRM_HDCP2_2_ComputeVprime (MTDRM_HDCP2_2_CALVPRIME_T *pCalVprime);
int MTDRM_HDCP2_VerifySignature(unsigned char *pKpub, unsigned char *sig);
int MTDRM_HDCP2_ResetPairingInfo(unsigned char *rx_id);

int MTDRM_HDCP2_SetTxCap(int cap);
int MTDRM_HDCP2_if_TZ_Key(int *flag);

//===================================
// Secure Buffer Allocation 
//===================================

typedef unsigned int SECURE_BUF_HANDLE;

typedef struct SecureAllocArg{
    SECURE_BUF_HANDLE *handle; 
    size_t  size;
}SecureAllocArg;

int MTDRM_ALLOC_SECURE_BUF(SECURE_BUF_HANDLE *handle , size_t size);

int MTDRM_FREE_SECURE_BUF(SECURE_BUF_HANDLE handle);

int MTDRM_DIVX_GetHwSecretKey0(unsigned char *p1Buf);
int MTDRM_DIVX_GetHwSecretKey1(unsigned char *p1Buf);



/* for sony iptves*/

/* sac */
typedef struct
{
	int in_thid;
	
	unsigned int  reg_num;

	unsigned int req_list_size;
	unsigned char *req_list;
	
	char *out_handle;
	
}MTDRM_IPTV_sac_Construct_T;




typedef struct
{
	char *handle;
	unsigned int *out_success_num;
	unsigned int *out_trans_flags_status;

}MTDRM_IPTV_sac_Destruct_T;




typedef struct
{
	char *handle;
	unsigned char *out_msg;
	unsigned int *io_msg_len;
	int *out_last_req_flag;

}MTDRM_IPTV_sac_MakeMessage_T;




typedef struct
{
	char *handle;
	unsigned char *in_msg;
	unsigned int in_msg_len;
	int *out_end_flag;

}MTDRM_IPTV_sac_ProcessMessage_T;




/* nvs */

typedef struct
{
	const unsigned char 	  *in_ro;
	unsigned int 	  		   in_ro_len;
	unsigned char       	  *in_rw;
	unsigned int 	  		   in_rw_len;

}MTDRM_IPTV_nvs_Init_T;







typedef struct
{
	unsigned char *out_rw;
	int out_rw_len;
	
}MTDRM_IPTV_nvs_Fin_T;





/* sdi */
typedef struct
{
   int current_time_secs;
   int gmtoff;


}MTDRM_IPTV_sdi_Init_T;



typedef struct
{
	
	//unsigned char out_devid[PO_DEVICE_ID_LEN];
	unsigned char out_devid[8];

	int in_thid;

}MTDRM_IPTV_sdi_GetDeviceID_T;



typedef struct
{
	int		         		   in_thid;
	const unsigned char 	  *in_msg;
	unsigned int 	  		   in_msg_len;
	const unsigned char       *in_pkipath;
	unsigned int 	  		   in_pkipath_len;
	const unsigned char       *in_sig;

}MTDRM_IPTV_sdi_VerifyServiceMetaData_T;


typedef struct
{
	int			 in_thid;
	int		    *out_is_requested;


}MTDRM_IPTV_sdi_JudgeCRLUpdate_T;





typedef struct
{
	
	//char 		 out_crl_dp[PO_MAX_CRL_DP_LEN];
	char		 out_crl_dp[256];
	int 		 in_thid;

}MTDRM_IPTV_sdi_GetCRLDstPoint_T;




typedef struct
{
	int 				   in_thid;
	const unsigned char	  *in_crl;
	unsigned int		   in_crl_len;
	int					  *out_is_updated;

}MTDRM_IPTV_sdi_SetCRL_T;


typedef struct
{
	int			  *out_is_valid;

}MTDRM_IPTV_sdi_CheckTrustedTime_T;






/* ecm */
typedef struct
{
	int		            in_thid;
	unsigned int		in_rend_id;
	
	//unsigned char	    in_ecm[PO_ECM_LEN];
	unsigned char		*in_ecm; //[98];
	unsigned int		 in_ecm_len;  // should be 98

}MTDRM_IPTV_ecm_ExtractScrambleKey_T;




typedef struct
{
	int			      in_thid;
	//unsigned char	  in_ecm[PO_ECM_LEN];
	unsigned char	  *in_ecm;// [98];
	unsigned int	   in_ecm_len;
	
	unsigned char 	 *out_skey_even;
	unsigned int      out_skey_even_len;
	
	unsigned char 	 *out_skey_odd;
	unsigned int	  out_skey_odd_Len;

}MTDRM_IPTV_ecm_GetScrambleKey_T;




/* drm */

typedef struct
{
	int				in_thid;
	unsigned int 	in_rend_id;
	
	char /* po_key_ref_t */	*in_key_ref;
	unsigned int    in_key_ref_len;


}MTDRM_IPTV_drm_ExtractContentKey_T;


typedef struct
{
	int					in_thid;
	char /* po_key_ref_t */	   *in_key_ref;
	unsigned int	in_key_ref_len;

}MTDRM_IPTV_drm_DelContentKey_T;




typedef struct
{
	int				 in_thid;
	char /* po_key_ref_t */	*in_key_ref;
	unsigned int	in_key_ref_len;


}MTDRM_IPTV_drm_DelUncommittedKey_T;



typedef struct
{
	int					    in_thid;
	char /* po_key_ref_t */  *in_key_ref;
	unsigned int            in_key_ref_len;
	
	char /*po_key_info_t */  *out_key_info;
	unsigned int            out_key_info_len;

}MTDRM_IPTV_drm_GetKeyInfo_T;



typedef struct
{
	int						 in_thid;
 	unsigned char			 in_action_id;
	unsigned int 			*out_num;


}MTDRM_IPTV_drm_GetKeyNum_T;



typedef struct
{
	int					    in_thid;
	unsigned char			in_action_id;
	unsigned int 		   *io_num;
	
	char /* po_key_ref_t */  *out_key_ref_lst;
	unsigned int			out_key_ref_lst_len;
	


}MTDRM_IPTV_drm_GetKeyRefList_T;



typedef struct
{
	int					   in_thid;
	
	char /* po_key_ref_t */ *in_key_ref;
	unsigned int           in_key_ref_len;
	
	//unsigned char		  out_ckey[PO_CKEY_LEN];
	unsigned char		  *out_ckey;// [16];
	unsigned int          out_ckey_len;
	

}MTDRM_IPTV_drm_GetContentKey_T;






typedef struct
{
	unsigned int	in_tt;

}MTDRM_IPTV_time_SetTrustedTime_T;



typedef struct
{
	unsigned int	*out_tt;

}MTDRM_IPTV_time_GetTrustedTime_T;





#ifdef __cplusplus
}
#endif

#endif //_MTDRM_H_
