/*
 * Marlin IPTV-ES Client SDK version 3.1
 *
 * Any code and mechanism in this module must not be used
 * in any form without permissions.
 *
 * Copyright 2006,2007,2008 Sony Corporation
 */
#ifndef MTAL_ECM_API_H
#define MTAL_ECM_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================*/
/**
 * @file
 * ECM API
 *
 * require: keymng, time, crypto, rend, base
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
#define RET_ECM_PARSE_ERR_PROTOCOL_VER  (RET_ECM_BASE|1)
#define RET_ECM_CHECK_ERR_FMT_DATETIME  (RET_ECM_BASE|2)
#define RET_ECM_CHECK_ERR_FMT_TIERBITS  (RET_ECM_BASE|3)
#define RET_ECM_CHECK_ERR_FMT_RO        (RET_ECM_BASE|4)
#define RET_ECM_WKEY_ERR_NOTBEFORE      (RET_ECM_BASE|5)
#define RET_ECM_WKEY_ERR_NOTAFTER       (RET_ECM_BASE|6)
#define RET_ECM_WKEY_ERR_TIERBITS       (RET_ECM_BASE|7)
#define RET_ECM_WKEY_NOT_FOUND          (RET_ECM_BASE|8)
#define RET_ECM_TT_ERROR                (RET_ECM_BASE|9)
#define RET_ECM_REND_ERROR              (RET_ECM_BASE|10)

/*============================================================================
 * APIs
 *==========================================================================*/
/**
 * Extract scramble key to decryptor
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_rend_id           Renderer Id
 * @param [in]     in_ecm               ECM
 * @retval RET_OK                               Success
 * @retval RET_ILLEGALARGS                      Illegal arguments are passed to this API
 * @retval RET_ECM_PARSE_ERR_PROTOCOL_VER       Protocol Version is illegal
 * @retval RET_ECM_CHECK_ERR_FMT_DATETIME       Format error of datetime
 * @retval RET_ECM_CHECK_ERR_FMT_TIERBITS       Format error of tierbits
 * @retval RET_ECM_CHECK_ERR_FMT_RO             Format error of rendering obligation
 * @retval RET_ECM_WKEY_ERR_NOTBEFORE           The key which encrypts @p in_ecm is expired
 * @retval RET_ECM_WKEY_ERR_NOTAFTER            The key which encrypts @p in_ecm is expired
 * @retval RET_ECM_WKEY_ERR_TIERBITS            The key which encrypts @p in_ecm does not have proper tierbits
 * @retval RET_ECM_WKEY_NOT_FOUND               The key which encrypts @p in_ecm is not found
 * @retval RET_ECM_TT_ERROR                     Trusted time is not adjusted
 * @retval RET_ECM_REND_ERROR                   Fail to extract scramble key to renderer
 */
extern ret_t
mtal_iptv_ecm_ExtractScrambleKey(po_thid_t        in_thid,
                       u_int32_t        in_rend_id,
                       const u_int8_t   in_ecm[PO_ECM_LEN]);

#define  ecm_ExtractScrambleKey  mtal_iptv_ecm_ExtractScrambleKey

#if !defined(IPTVES_PUBLISH_BUILD)
/*----------------------------------------------------------------------------
 * Functions for Test/Tools
 *--------------------------------------------------------------------------*/
/**
 * Get scramble key (for debug)
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_ecm               ECM
 * @param [out]    out_skey_even        Scramble key (even)
 * @param [out]    out_skey_odd         Scramble key (odd)
 * @retval RET_OK                               Success
 * @retval RET_ILLEGALARGS                      Illegal arguments are passed to this API
 * @retval RET_ECM_PARSE_ERR_PROTOCOL_VER       Protocol Version is illegal
 * @retval RET_ECM_CHECK_ERR_FMT_DATETIME       Format error of datetime
 * @retval RET_ECM_CHECK_ERR_FMT_TIERBITS       Format error of tierbits
 * @retval RET_ECM_CHECK_ERR_FMT_RO             Format error of rendering obligation
 * @retval RET_ECM_WKEY_ERR_NOTBEFORE           The key which encrypts @p in_ecm is expired
 * @retval RET_ECM_WKEY_ERR_NOTAFTER            The key which encrypts @p in_ecm is expired
 * @retval RET_ECM_WKEY_ERR_TIERBITS            The key which encrypts @p in_ecm does not have proper tierbits
 * @retval RET_ECM_WKEY_NOT_FOUND               The key which encrypts @p in_ecm is not found
 * @retval RET_ECM_TT_ERROR                     Trusted time is not adjusted
 */
extern ret_t
mtal_iptv_ecm_GetScrambleKey(po_thid_t            in_thid,
                   const u_int8_t       in_ecm[PO_ECM_LEN],
                   u_int8_t            *out_skey_even,
                   u_int8_t            *out_skey_odd);


#define  ecm_GetScrambleKey mtal_iptv_ecm_GetScrambleKey

#endif /* !IPTVES_PUBLISH_BUILD */

#ifdef __cplusplus
}
#endif

#endif /* MTAL_ECM_API_H */
