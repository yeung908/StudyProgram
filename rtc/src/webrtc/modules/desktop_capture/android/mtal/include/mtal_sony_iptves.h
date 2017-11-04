/*
 * Marlin IPTV-ES Client SDK version 3.1
 *
 * Any code and mechanism in this module must not be used
 * in any form without permissions.
 *
 * Copyright 2006,2007,2008,2009 Sony Corporation
 */
#ifndef MTAL_SONY_HBTV_H
#define MTAL_SONY_HBTV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>




/*
 * type: bool_t
 */
typedef int             bool_t;

/*
 * type: po_size_t
 */
typedef u_int32_t       po_size_t;

/*
 * type: time_unix_t
 */
typedef unsigned int    time_unix_t;





/*============================================================================
 * Macro Definitions
 *==========================================================================*/
/**
 * def: Configuarable Values
 */
#define PO_MAX_CONNECTION       4
#define PO_MAX_CERT_LEN         (1024 * 2)
#define PO_MAX_CRL_LEN          (1024 * 5)
#define PO_MAX_REQ_LEN          (1024 * 3)
#define PO_MAX_RES_LEN          (1024 * 3)
#define PO_MAX_CRL_DP_LEN       256

/*============================================================================
 * Type Definitions
 *==========================================================================*/
/**
 * def: error code
 */
typedef int               ret_t;

/*============================================================================
 * Error Codes
 *==========================================================================*/
/*============================================================================
 * ERROR MAP
 *
 *     3322 2222 2222 1111 1111 1100 0000 0000
 *     1098 7654 3210 9876 5432 1098 7654 3210
 *    |    |    |         |
 *     A   B    C         D
 *
 *    A: Layer          (4bit  : 0 - 15)
 *    B: Module         (4bit  : 0 - 15)
 *    C: Component      (8bit  : 0 - 255)
 *    D: Error          (16bit : 0 - 65535)
 *===========================================================================*/

/*--------- SHIFT SIZE ------------------------------------------------------*/
#define RET_LYR_SFT             28
#define RET_MOD_SFT             24
#define RET_CMP_SFT             16

/*--------- ERROR MASK ------------------------------------------------------*/
#define RET_LYR_MASK            0xF0000000
#define RET_MOD_MASK            0x0F000000
#define RET_CMP_MASK            0x00FF0000
#define RET_BASE_MASK           0xFFFF0000

#define RET_LYR(err)            ((err) & RET_LYR_MASK)
#define RET_MOD(err)            ((err) & RET_MOD_MASK)
#define RET_BASE(err)           ((err) & RET_BASE_MASK)

/*--------- ERROR LAYER -----------------------------------------------------*/
#define RET_LYR_CMN             (1<<RET_LYR_SFT)
#define RET_LYR_OUTSIDE         (2<<RET_LYR_SFT)
#define RET_LYR_SEC             (3<<RET_LYR_SFT)
#define RET_LYR_NSEC            (4<<RET_LYR_SFT)

/*--------- ERROR MODULE ----------------------------------------------------*/

/*--------- ERROR COMPONENT -------------------------------------------------*/
/*----- CMN -----*/
#define RET_CMP_FIO             (1<<RET_CMP_SFT)
#define RET_CMP_STRM            (2<<RET_CMP_SFT)
/*----- OUTSIDE -----*/
#define RET_CMP_HTTP            (1<<RET_CMP_SFT)
#define RET_CMP_CRYPTO          (2<<RET_CMP_SFT)
#define RET_CMP_TIME            (3<<RET_CMP_SFT)
#define RET_CMP_REND            (4<<RET_CMP_SFT)
/*----- SEC ----*/
#define RET_CMP_ASN             (1<<RET_CMP_SFT)
#define RET_CMP_CERT            (2<<RET_CMP_SFT)
#define RET_CMP_NVS             (3<<RET_CMP_SFT)
#define RET_CMP_CACHE           (4<<RET_CMP_SFT)
#define RET_CMP_KEYMNG          (5<<RET_CMP_SFT)
#define RET_CMP_CERTMNG         (6<<RET_CMP_SFT)
#define RET_CMP_ECM             (7<<RET_CMP_SFT)
#define RET_CMP_DRM             (8<<RET_CMP_SFT)
#define RET_CMP_SDI             (9<<RET_CMP_SFT)
#define RET_CMP_SP              (10<<RET_CMP_SFT)
#define RET_CMP_SAC             (11<<RET_CMP_SFT)

/*--------- ERROR BASE -----------------------------------------------------*/
/*
 * Cmn
 */
#define RET_FIO_BASE            (RET_LYR_CMN|RET_CMP_FIO)
#define RET_STRM_BASE           (RET_LYR_CMN|RET_CMP_STRM)

/*
 * outside
 */
#define RET_HTTP_BASE           (RET_LYR_OUTSIDE|RET_CMP_HTTP)
#define RET_CRYPTO_BASE         (RET_LYR_OUTSIDE|RET_CMP_CRYPTO)
#define RET_TIME_BASE           (RET_LYR_OUTSIDE|RET_CMP_TIME)
#define RET_REND_BASE           (RET_LYR_OUTSIDE|RET_CMP_REND)

/*
 * sec
 */
#define RET_ASN_BASE            (RET_LYR_SEC|RET_CMP_ASN)
#define RET_CERT_BASE           (RET_LYR_SEC|RET_CMP_CERT)
#define RET_NVS_BASE            (RET_LYR_SEC|RET_CMP_NVS)
#define RET_CACHE_BASE          (RET_LYR_SEC|RET_CMP_CACHE)
#define RET_KEYMNG_BASE         (RET_LYR_SEC|RET_CMP_KEYMNG)
#define RET_CERTMNG_BASE        (RET_LYR_SEC|RET_CMP_CERTMNG)
#define RET_ECM_BASE            (RET_LYR_SEC|RET_CMP_ECM)
#define RET_DRM_BASE            (RET_LYR_SEC|RET_CMP_DRM)
#define RET_SDI_BASE            (RET_LYR_SEC|RET_CMP_SDI)
#define RET_SP_BASE             (RET_LYR_SEC|RET_CMP_SP)
#define RET_SAC_BASE            (RET_LYR_SEC|RET_CMP_SAC)

/*--------- ERROR BASIC ----------------------------------------------------*/

#define RET_OK                  0
#define RET_NG                  1
#define RET_NOMEM               2
#define RET_ILLEGALARGS         3
#define RET_ILLEGALHANDLE       4
#define RET_UNSUPPORTED         5
#define RET_INTERNALERROR       6










/**
 * macro: data length
 */
#define PO_URR_LEN              16
#define PO_CKEY_ID_LEN          6
#define PO_TIERBITS_LEN         8
#define PO_CKEY_LEN             16
#define PO_ECM_LEN              98
#define PO_DEVICE_ID_LEN        8
#define PO_EXPORT_INFO_MAX_LEN  16

/**
 * macro: action id (for po_key_ref_t)
 */
#define PO_ACTION_ID_EXTRACT_VOD    0x01
#define PO_ACTION_ID_EXTRACT_IPMC   0x02
#define PO_ACTION_ID_EXTRACT_DL     0x03
#define PO_ACTION_ID_EXPORT_CP_DL   0x10
#define PO_ACTION_ID_EXPORT_MV_DL   0x11
#define PO_ACTION_ID_EXPORT_IPMC    0x12
#define PO_ACTION_ID_RECORD         0x20
#define PO_ACTION_ID_ALL            0xFF

/**
 * macro: action parameter (for po_key_ref_t)
 */
#define PO_ACTION_PARAM_EXTRACT                             0xFF
#define PO_ACTION_PARAM_EXPORT_DTCP                         0x00
#define PO_ACTION_PARAM_EXPORT_CPRM_DVD                     0x01
#define PO_ACTION_PARAM_EXPORT_CPRM_SDV                     0x02
#define PO_ACTION_PARAM_EXPORT_CPRM_SDA                     0x03
#define PO_ACTION_PARAM_EXPORT_MGR_SVR_MEMSTICKPRO          0x04
#define PO_ACTION_PARAM_EXPORT_MGR_SAR_MEMSTICK_MEMSTICKPRO 0x05
#define PO_ACTION_PARAM_EXPORT_VCPS                         0x06
#define PO_ACTION_PARAM_EXPORT_MGR_SVR_EMPR                 0x07
#define PO_ACTION_PARAM_EXPORT_MGR_SAR_ATRAC                0x08
#define PO_ACTION_PARAM_EXPORT_SAFIA_IVDR_TV_REC            0x09
#define PO_ACTION_PARAM_EXPORT_SAFIA_IVDR_AUDIO_REC         0x0A
#define PO_ACTION_PARAM_EXPORT_AACS_BLURAY_BDR_RE           0x0B
#define PO_ACTION_PARAM_EXPORT_AACS_BLURAY_RED_LASER        0x0C
#define PO_ACTION_PARAM_RECORD_ARIB                         0x01

/**
 * macro: key flag (for po_key_info_t)
 */
#define PO_KEY_FLAG_CKEY_ID             (0x01<<0)
#define PO_KEY_FLAG_PRIV_DATA           (0x01<<1)
#define PO_KEY_FLAG_TIERBITS            (0x01<<2)
#define PO_KEY_FLAG_OCI                 (0x01<<3)
#define PO_KEY_FLAG_EXPORT_INFO         (0x01<<4)
#define PO_KEY_FLAG_NOT_BEFORE_AFTER    (0x01<<5)

/**
 * macro: request type (for po_req_t)
 */
#define PO_REQ_TYPE_GETPERM     0
#define PO_REQ_TYPE_GETTT       1


#define PO_MAX_CONNECTION       4
#define PO_MAX_CERT_LEN         (1024 * 2)
#define PO_MAX_CRL_LEN          (1024 * 5)
#define PO_MAX_REQ_LEN          (1024 * 3)
#define PO_MAX_RES_LEN          (1024 * 3)
#define PO_MAX_CRL_DP_LEN       256



/*============================================================================
 * Type Definitions
 *==========================================================================*/
/**
 * type: return code
 */

/**
 * type: key reference
 */

typedef struct {
    u_int8_t     urr[PO_URR_LEN];
    u_int8_t     urr_len;
    u_int8_t     action_id;
    u_int8_t     action_param;
} po_key_ref_t;

/**
 * type: key information
 */

typedef struct {
    u_int8_t     flags;
    u_int8_t     ckey_id[PO_CKEY_ID_LEN];
    u_int16_t    priv_data;
    u_int8_t     tierbits[PO_TIERBITS_LEN];
    u_int16_t    oci;
    u_int8_t     export_info[PO_EXPORT_INFO_MAX_LEN];
    u_int16_t    export_info_len;
    u_int32_t    not_before;
    u_int32_t    not_after;
    u_int8_t     num;
    u_int8_t     num_in_use;
} po_key_info_t;

/**
 * type: request
 */

typedef struct {
    u_int8_t     type;
    u_int8_t     num;
    po_key_ref_t key_ref;
} po_req_t;


typedef enum {
    PO_THID_COMMON = 0,
    PO_THID_RTDB,
    PO_THID_MAX,
} po_thid_t;


//typedef int               ret_t;


typedef u_int32_t po_ret_t;





//typedef void * mtal_iptv_sac_handle_t;

extern int mtal_iptv_sp_SetManufacturerForCTS(void);
#define   sp_SetManufacturerForCTS  mtal_iptv_sp_SetManufacturerForCTS

#include "drm_api_mtal.h"
#include "ecm_api_mtal.h"
#include "sac_api_mtal.h"
#include "sdi_api_mtal.h"




#ifdef __cplusplus
}
#endif

#endif /* MTAL_SONY_HBTV_H */
