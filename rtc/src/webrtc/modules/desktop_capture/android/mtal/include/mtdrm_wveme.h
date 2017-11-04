/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#ifndef _MTDRMX_WV_H_
#define _MTDRMX_WV_H_
#include "drv_common.h"

/*-----------------------------------------------------------------------------
                    macros, typedefs, enums
 ----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"{
#endif

#define kPssSaltLength  20
#define KEY_CONTROL_SIZE  16
#define DEVICE_KEY_LENGTH  16
#define KEY_DATA_LENGTH  72
#define DEVICE_ID_LENGTH  32
#define CNT_KEY_DATA_LENGTH  32

#define MAX_SESSION_KEYPAIR  50
#define MACKEY_LEN  32
#define ENCKEY_LEN  16
#define SESSKEY_LEN  32
#define KEY_SIZE  16
//for the nonce table
#define kTableSize  16
#define KEY_ID_LENGTH  16
#define KEY_IV_SIZE  16
#define MAC_KEY_SIZE  32

#define RSA_KEY_LEN 256
#define SHA256_DIGEST_LENGTH 32
#define SHA_DIGEST_LENGTH 20
#define AES_BLOCK_SIZE 16
#define AES_FUN_BLK_LEN      (16)

//typedef unsigned int size_t;
//typedef unsigned char uint8_t;
//typedef unsigned int  uint32_t;

typedef uint32_t SessionId;

typedef uint8_t KeyData[CNT_KEY_DATA_LENGTH];
typedef uint8_t KeyId[KEY_ID_LENGTH];

#if 1
typedef struct Rsa_key {
    /** Type of key, PK_PRIVATE or PK_PUBLIC */
    int type;
    /** The public exponent */
    void *e; 
    /** The private exponent */
    void *d; 
    /** The modulus */
    void *N; 
    /** The p factor of N */
    void *p; 
    /** The q factor of N */
    void *q; 
    /** The 1/q mod p CRT param */
    void *qP; 
    /** The d mod (p - 1) CRT param */
    void *dP; 
    /** The d mod (q - 1) CRT param */
    void *dQ;
} rsa_key;
#endif

typedef enum OEMCryptoResult {
    OEMCrypto_SUCCESS                            = 0,
    OEMCrypto_ERROR_INIT_FAILED                  = 1,
    OEMCrypto_ERROR_TERMINATE_FAILED             = 2,
    OEMCrypto_ERROR_OPEN_FAILURE                 = 3,
    OEMCrypto_ERROR_CLOSE_FAILURE                = 4,
    OEMCrypto_ERROR_ENTER_SECURE_PLAYBACK_FAILED = 5,
    OEMCrypto_ERROR_EXIT_SECURE_PLAYBACK_FAILED  = 6,
    OEMCrypto_ERROR_SHORT_BUFFER                 = 7,
    OEMCrypto_ERROR_NO_DEVICE_KEY                = 8,
    OEMCrypto_ERROR_NO_ASSET_KEY                 = 9,
    OEMCrypto_ERROR_KEYBOX_INVALID               = 10,
    OEMCrypto_ERROR_NO_KEYDATA                   = 11,
    OEMCrypto_ERROR_NO_CW                        = 12,
    OEMCrypto_ERROR_DECRYPT_FAILED               = 13,
    OEMCrypto_ERROR_WRITE_KEYBOX                 = 14,
    OEMCrypto_ERROR_WRAP_KEYBOX                  = 15,
    OEMCrypto_ERROR_BAD_MAGIC                    = 16,
    OEMCrypto_ERROR_BAD_CRC                      = 17,
    OEMCrypto_ERROR_NO_DEVICEID                  = 18,
    OEMCrypto_ERROR_RNG_FAILED                   = 19,
    OEMCrypto_ERROR_RNG_NOT_SUPPORTED            = 20,
    OEMCrypto_ERROR_SETUP                        = 21,
    OEMCrypto_ERROR_OPEN_SESSION_FAILED          = 22,
    OEMCrypto_ERROR_CLOSE_SESSION_FAILED         = 23,
    OEMCrypto_ERROR_INVALID_SESSION              = 24,
    OEMCrypto_ERROR_NOT_IMPLEMENTED              = 25,
    OEMCrypto_ERROR_NO_CONTENT_KEY               = 26,
    OEMCrypto_ERROR_CONTROL_INVALID              = 27,
    OEMCrypto_ERROR_UNKNOWN_FAILURE              = 28,
    OEMCrypto_ERROR_INVALID_CONTEXT              = 29,
    OEMCrypto_ERROR_SIGNATURE_FAILURE            = 30,
    OEMCrypto_ERROR_TOO_MANY_SESSIONS            = 31,
    OEMCrypto_ERROR_INVALID_NONCE                = 32,
    OEMCrypto_ERROR_TOO_MANY_KEYS                = 33,
    OEMCrypto_ERROR_DEVICE_NOT_RSA_PROVISIONED   = 34,
    OEMCrypto_ERROR_INVALID_RSA_KEY              = 35,
} OEMCryptoResult;


typedef enum BufferType
{
	kBufferTypeClear,
	kBufferTypeSecure,
	kBufferTypeDirect
}BufferType;


typedef enum E_KeyboxError
{
	NO_ERROR,
	BAD_CRC,
	BAD_MAGIC,
	OTHER_ERROR
}E_KeyboxError;

typedef struct
{
	uint8_t signature[MAC_KEY_SIZE];
	uint8_t context[MAC_KEY_SIZE];
	uint8_t iv[KEY_IV_SIZE];
	uint8_t enc_rsa_key[];
} WrappedRSAKey;


typedef enum KeyType
{
    KEYTYPE_UNKNOWN,
    KEYTYPE_PREPROV,
    KEYTYPE_ROOT,
    KEYTYPE_DEVICE,
    KEYTYPE_CONTENT,
    KEYTYPE_CONTENT_AUDIO,
    KEYTYPE_CONTENT_VIDEO,
    KEYTYPE_MAX
}KeyType;

typedef struct KeyControlBlock
{
    uint32_t verification_;
    uint32_t duration_;
    uint32_t nonce_;
    uint32_t control_bits_;
    BOOL 	 valid_;
}KeyControlBlock;

// AES-128 crypto key
typedef struct Key
{
    BOOL    valid_;
    KeyType type_;
    KeyData keyvalue_;
    int     keydatalen_;
    BOOL    has_control_;
    KeyControlBlock control_;
}Key;

typedef struct Keypair
{
    KeyId   keyid;
    Key     keycontent;
    BOOL    is_valid;
}Keypair;

typedef enum E_NonceTableState
{
    e_kNTStateInvalid,
    e_kNTStateValid,
    e_kNTStateFlushPending
}E_NonceTableState;

typedef struct NonceTable
{
    E_NonceTableState state_[kTableSize];
    uint32_t age_[kTableSize];
    uint32_t nonces_[kTableSize];
}NonceTable;

typedef struct SessionContext
{
    BOOL valid_;
    BOOL has_mac_key;
    uint8_t mac_key_server_[MACKEY_LEN];

    uint8_t mac_key_client_[MACKEY_LEN];
    uint8_t encryption_key_[ENCKEY_LEN];
    size_t  encryp_key_len_;
    uint8_t session_key_[SESSKEY_LEN];

    const Key* current_content_key_;
    Keypair session_keys_[MAX_SESSION_KEYPAIR];
    NonceTable nonce_table_;
    rsa_key* rsa_key_;    //liufen del for build
}SessionContext;

/*
 * OEMCrypto_Algorithm
 * This is a list of valid algorithms for OEMCrypto_Generic_* functions.
 * Some are valid for encryption/decryption, and some for signing/verifying.
 */
typedef enum OEMCrypto_Algorithm
{
	OEMCrypto_AES_CBC_128_NO_PADDING = 0,
	OEMCrypto_HMAC_SHA256			 = 1,
} OEMCrypto_Algorithm;

// This is the format of a Widevine keybox.
typedef struct     // 128 bytes total.
{
    // C character string identifying the device.  Null terminated.
    uint8_t device_id_[32];
    // 128 bit AES key assigned to device.  Generated by Widevine.
    uint8_t device_key_[16];
    // WvKey Data.  Encrypted data.
    uint8_t data_[72];
    // Constant code used to recognize a valid keybox "kbox" = 0x6b626f78.
    uint8_t magic_[4];
    // The CRC checksum of the first 124 bytes of the keybox.
    uint8_t crc_[4];
} WidevineKeybox;

const static uint32_t kControlObserveDataPath = (1<<31);
const static uint32_t kControlObserveHDCP     = (1<<30);
const static uint32_t kControlObserveCGMS     = (1<<29);
const static uint32_t kControlAllowEncrypt    = (1<<8);
const static uint32_t kControlAllowDecrypt    = (1<<7);
const static uint32_t kControlAllowSign       = (1<<6);
const static uint32_t kControlAllowVerify     = (1<<5);
const static uint32_t kControlDataPathSecure  = (1<<4);
const static uint32_t kControlNonceEnabled    = (1<<3);
const static uint32_t kControlHDCPRequired    = (1<<2);
const static uint32_t kControlCGMSMask        = (0x03);
const static uint32_t kControlCGMSCopyFreely  = (0x00);
const static uint32_t kControlCGMSCopyOnce    = (0x02);
const static uint32_t kControlCGMSCopyNever   = (0x03);

MT_RESULT_T MTDRM_WV_CreatSession(SessionContext *sesscnt);
MT_RESULT_T MTDRM_WV_DestroySession(SessionContext *sesscnt);
MT_RESULT_T MTDRM_WV_ValidateKeybox(uint32_t *result);
MT_RESULT_T MTDRM_WV_GenerateNonceSess(SessionContext * sesscnt, uint32_t * nonce);
MT_RESULT_T MTDRM_WV_GenerateDeriveKeys(SessionContext * sesscnt,const uint8_t * master_key, size_t mst_cnt_len,
                           const uint8_t* mac_context, size_t mac_cnt_len,
                           const uint8_t* enc_context,size_t enc_cnt_len);
MT_RESULT_T  MTDRM_WV_GenerateSignature(SessionContext *sesscnt,
                                  const uint8_t* message,
                                  size_t message_length,
                                  uint8_t* signature,
                                  size_t* signature_length)  ;
MT_RESULT_T  MTDRM_WV_ValidateMessage(SessionContext *sesscnt,
                                const uint8_t* given_message,
                                size_t message_length,
                                const uint8_t* given_signature,
                                size_t signature_length);
MT_RESULT_T  MTDRM_WV_InstallKey(SessionContext * sesscnt,const uint8_t* key_id, size_t key_id_len,
                           const uint8_t* key_data,size_t key_data_len_len,
                           const uint8_t* key_data_iv,size_t key_data_iv_len,
                           const uint8_t* key_control,size_t key_control_len,
                           const uint8_t* key_control_iv,size_t key_control_iv_len);

MT_RESULT_T  MTDRM_WV_FlushNoncesSess(SessionContext * sesscnt);
MT_RESULT_T  MTDRM_WV_UpdateMacKeys(SessionContext * sesscnt,const uint8_t* mac_keys, size_t mac_key_len,
                              const uint8_t* iv, size_t iv_len);
MT_RESULT_T  MTDRM_WV_RefreshKey(SessionContext * sesscnt,const uint8_t* key_id, size_t keyid_len,
                           uint8_t* key_control,size_t key_cnt_len,
                           const uint8_t* key_control_iv, size_t key_cnt_iv_len);
MT_RESULT_T  MTDRM_WV_SelectContentKey(SessionContext * sesscnt,const KeyId key_id ,int key_id_len);
MT_RESULT_T  MTDRM_WV_DecryptCTR(SessionContext* session,
                           const uint8_t* iv,
                           size_t block_offset,
                           const uint8_t* cipher_data,
                           size_t cipher_data_length,
                           BOOL is_encrypted,
                           void* clear_data,
                           BufferType buffer_type,uint32_t curtime);
MT_RESULT_T  MTDRM_WV_InstallKeybox(const uint8_t* buffer, size_t keyBoxLength);
MT_RESULT_T MTDRM_WV_SaveKeybox(UINT8* pu1keybox, UINT32 u4Size);

MT_RESULT_T  MTDRM_WV_GetRandomNum(uint8_t  *randomData, size_t dataLength);


MT_RESULT_T  MTDRM_WV_Generic_Encrypt(SessionContext *sesscnt, const uint8_t* in_buffer,
                                size_t buffer_length,
                                const uint8_t* iv,
                                OEMCrypto_Algorithm algorithm,
                                uint8_t* out_buffer, uint32_t curtime);
MT_RESULT_T  MTDRM_WV_Generic_Decrypt(SessionContext *sesscnt, const uint8_t* in_buffer,
                                size_t buffer_length,
                                const uint8_t* iv,
                                OEMCrypto_Algorithm algorithm,
                                uint8_t* out_buffer, uint32_t curtime);
MT_RESULT_T  MTDRM_WV_Generic_Sign(SessionContext *sesscnt, const uint8_t* in_buffer,
                             size_t buffer_length,
                             OEMCrypto_Algorithm algorithm,
                             uint8_t* signature,
                             size_t* signature_length, uint32_t curtime);


MT_RESULT_T  MTDRM_WV_Generic_Verify(SessionContext *sesscnt, const uint8_t* in_buffer,
                               size_t buffer_length,
                               OEMCrypto_Algorithm algorithm,
                               const uint8_t* signature,
                               size_t signature_length, uint32_t curtime);
MT_RESULT_T  MTDRM_WV_RewrapDeviceRSAKeySess(SessionContext* session_ctx,
                                      const uint8_t* message,
                                      size_t message_length,
                                      const uint8_t* signature,
                                      size_t signature_length,
                                      const uint32_t* nonce,
                                      const uint8_t* enc_rsa_key,
                                      size_t enc_rsa_key_length,
                                      const uint8_t* enc_rsa_key_iv,
                                      uint8_t* wrapped_rsa_key,
                                      size_t*  wrapped_rsa_key_length,
                                      uint32_t *result);
MT_RESULT_T  MTDRM_WV_LoadDeviceRSAKeySessCtx(SessionContext* session_ctx,
                                       const uint8_t* wrapped_rsa_key,
                                       size_t wrapped_rsa_key_length,
                                       uint32_t *result);
MT_RESULT_T  MTDRM_WV_GenerateRSASignature(SessionContext *sesscnt,
                                     const uint8_t* message,
                                     size_t message_length,
                                     uint8_t* signature,
                                     size_t* signature_length);
MT_RESULT_T  MTDRM_WV_RSADeriveKeys(SessionContext * sesscnt,const uint8_t* enc_session_key, size_t enc_sesskey_len,
                              const uint8_t* mac_context,size_t mac_cnt_len,
                              const uint8_t* enc_context, size_t enc_cnt_len);

#ifdef __cplusplus
}
#endif


#endif //_MTDRM_WV_H_

