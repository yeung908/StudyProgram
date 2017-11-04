/*
 * Marlin IPTV-ES Client SDK version 3.1
 *
 * Any code and mechanism in this module must not be used
 * in any form without permissions.
 *
 * Copyright 2006,2007,2008 Sony Corporation
 */
#ifndef MTAL_SDI_API_H
#define MTAL_SDI_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================*/
/**
 * @file
 * Secure Data Interface
 *
 * require: certmng, cache, crypto, time, base
 */
/*==========================================================================*/

/*============================================================================
 * Macro Definitions
 *==========================================================================*/

/*============================================================================
 * Type Definitions
 *==========================================================================*/

/*============================================================================
 * Error Codes
 *==========================================================================*/
#define RET_SDI_RODATA_CORRUPTED        (RET_SDI_BASE|1)
#define RET_SDI_LOAD_ERROR              (RET_SDI_BASE|2)
#define RET_SDI_SAVE_ERROR              (RET_SDI_BASE|3)
#define RET_SDI_REMOVE_ERROR            (RET_SDI_BASE|4)
#define RET_SDI_CERT_VERIFY_FAILED      (RET_SDI_BASE|5)
#define RET_SDI_CERT_VALIDITY_ERROR     (RET_SDI_BASE|6)
#define RET_SDI_CERT_REVOKED            (RET_SDI_BASE|7)
#define RET_SDI_CRL_VERIFY_FAILED       (RET_SDI_BASE|8)
#define RET_SDI_SIG_VERIFY_FAILED       (RET_SDI_BASE|9)

/*============================================================================
 * APIs
 *==========================================================================*/
/**
 * Initialize Secure Layer (not MT-safe)
 *
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_UNSUPPORTED              There are no cietificate hierarchy in NVS
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SDI_RODATA_CORRUPTED     Fail to load read-only NVS
 * @retval RET_SDI_LOAD_ERROR           Fail to load read-write NVS
 * @retval RET_SDI_CERT_VERIFY_FAILED   Stored TA or Device Pkipath is corrupted
 * @retval RET_SDI_CRL_VERIFY_FAILED    Stored CRL is corrupted
 */
extern ret_t
mtal_iptv_sdi_Init(void);
#define  sdi_Init  mtal_iptv_sdi_Init

/**
 * Finalize Secure Layer (not MT-safe)
 *
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SDI_SAVE_ERROR           Fail to save read-write NVS
 */
extern ret_t
mtal_iptv_sdi_Fin(void);
#define  sdi_Fin mtal_iptv_sdi_Fin

/**
 * Remove Read-Write NVS (not MT-safe)
 *
 * @retval RET_OK                       Success
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SDI_REMOVE_ERROR         Fail to remove read-write NVS
 */
extern ret_t
mtal_iptv_sdi_CleanupNVS(void);
#define  sdi_CleanupNVS   mtal_iptv_sdi_CleanupNVS

/**
 * Get device id
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [out]    out_devid            Device ID
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 */
extern ret_t
mtal_iptv_sdi_GetDeviceID(int               in_thid,
                u_int8_t                out_devid[PO_DEVICE_ID_LEN]);
#define   sdi_GetDeviceID  mtal_iptv_sdi_GetDeviceID

/**
 * Verify service meta data
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_msg               Message
 * @param [in]     in_msg_len           Message length
 * @param [in]     in_pkipath           Service pkipath
 * @param [in]     in_pkipath_len       Service pkipath length
 * @param [in]     in_sig               Signature
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SDI_CERT_VERIFY_FAILED   @p in_pkipath is invalid
 * @retval RET_SDI_CERT_VALIDITY_ERROR  @p in_pkipath is expired
 * @retval RET_SDI_CERT_REVOKED         @p in_pkipath is revoked by CRL
 * @retval RET_SDI_CRL_VERIFY_FAILED    Stored CRL is invalid
 * @retval RET_SDI_SIG_VERIFY_FAILED    @p in_sig is not the signature for @p in_msg
 */
extern ret_t
mtal_iptv_sdi_VerifyServiceMetaData(int       in_thid,
                          const u_int8_t *in_msg,
                          u_int32_t       in_msg_len,
                          const u_int8_t *in_pkipath,
                          u_int32_t       in_pkipath_len,
                          const u_int8_t *in_sig);
#define  sdi_VerifyServiceMetaData  mtal_iptv_sdi_VerifyServiceMetaData

/**
 * Judge CRL should be updated or not
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [out]    out_is_requested     Whether CRL update is requested or not
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 */
extern ret_t
mtal_iptv_sdi_JudgeCRLUpdate(int            in_thid,
                   bool_t              *out_is_requested);
#define  sdi_JudgeCRLUpdate  mtal_iptv_sdi_JudgeCRLUpdate

/**
 * Get CRL distribution point
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [out]    out_crl_dp           CRL distribution point (NULL terminated)
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 */
extern ret_t
mtal_iptv_sdi_GetCRLDstPoint(int            in_thid,
                   char                 out_crl_dp[PO_MAX_CRL_DP_LEN]);

#define  sdi_GetCRLDstPoint mtal_iptv_sdi_GetCRLDstPoint
/**
 * Set CRL
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_crl               CRL
 * @param [in]     in_crl_len           CRL length
 * @param [out]    out_is_updated       Whether CRL is updated or not
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SDI_SAVE_ERROR           Fail to save read-write NVS
 * @retval RET_SDI_CRL_VERIFY_FAILED    @p in_crl is invalid
 */
extern ret_t
mtal_iptv_sdi_SetCRL(int                    in_thid,
           const u_int8_t              *in_crl,
           u_int32_t                    in_crl_len,
           bool_t                      *out_is_updated);
#define  sdi_SetCRL mtal_iptv_sdi_SetCRL

/**
 * Check trusted time is valid or not
 *
 * @param [out]    out_is_valid         Whether TT is valid or not
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 */
extern ret_t
mtal_iptv_sdi_CheckTrustedTime(bool_t            *out_is_valid);

#define  sdi_CheckTrustedTime mtal_iptv_sdi_CheckTrustedTime



extern ret_t
mtal_iptv_time_SetTrustedTime(u_int32_t           in_tt);

#define  time_SetTrustedTime mtal_iptv_time_SetTrustedTime



extern ret_t
mtal_iptv_time_GetTrustedTime(u_int32_t          *out_tt);

#define  time_GetTrustedTime mtal_iptv_time_GetTrustedTime





#ifdef __cplusplus
}
#endif

#endif /* MTAL_SDI_API_H */
