/*
 * Marlin IPTV-ES Client SDK version 3.1
 *
 * Any code and mechanism in this module must not be used
 * in any form without permissions.
 *
 * Copyright 2006,2007,2008,2009 Sony Corporation
 */
#ifndef MTAL_SAC_API_H
#define MTAL_SAC_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================*/
/**
 * @file
 * SAC processing library
 *
 * require: sp, certmng, keymng, cache, crypto, base
 */
/*==========================================================================*/

/*============================================================================
 * Macro Definitions
 *==========================================================================*/
/**
 * contination status
 */
#define SAC_TRANS_FLAG_UNPROCESSED      0xFFFFFFFF
#define SAC_TRANS_FLAG_TRUE             0x00000001
#define SAC_TRANS_FLAG_FALSE            0x00000000

/*============================================================================
 * Type Definitions
 *==========================================================================*/
/**
 * handle
 */
typedef void * mtal_iptv_sac_handle_t;
#define sac_handle_t mtal_iptv_sac_handle_t

/*============================================================================
 * Error Codes
 *==========================================================================*/
#define RET_SAC_TOO_LONG_REQUEST                (RET_SAC_BASE|1)
#define RET_SAC_TOO_MANY_SEQUENCE               (RET_SAC_BASE|2)
#define RET_SAC_ILLEGAL_REQUEST                 (RET_SAC_BASE|3)
#define RET_SAC_VERIFICATION_FAILURE            (RET_SAC_BASE|4)
#define RET_SAC_CERT_VERIFICATION_FAILED        (RET_SAC_BASE|5)
#define RET_SAC_CERT_VALIDITY_ERR               (RET_SAC_BASE|6)
#define RET_SAC_CERT_REVOKED                    (RET_SAC_BASE|7)
#define RET_SAC_MSG_SIG_VERIFICATION_FAILED     (RET_SAC_BASE|8)
#define RET_SAC_REQUEST_DENIED                  (RET_SAC_BASE|9)
#define RET_SAC_RWDATA_CORRUPTED                (RET_SAC_BASE|10)
#define RET_SAC_TOO_MANY_LICENSES               (RET_SAC_BASE|11)
#define RET_SAC_STATUS_OTHERS                   (RET_SAC_BASE|0x8001)
#define RET_SAC_STATUS_MSG_ERR                  (RET_SAC_BASE|0x8002)
#define RET_SAC_STATUS_AUTH_ERR                 (RET_SAC_BASE|0x8003)
#define RET_SAC_STATUS_REVOKED                  (RET_SAC_BASE|0x8004)
#define RET_SAC_STATUS_CERT_ISSR_ERR            (RET_SAC_BASE|0x8005)

/*============================================================================
 * APIs
 *==========================================================================*/
/**
 * Initialize SAC handle
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_req_num           Request number
 * @param [in]     in_req_lst           Request list
 * @param [out]    out_handle           SAC handle
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_SAC_ILLEGAL_REQUEST      @p in_req_lst has illegal requests or packed pattern
 */
extern ret_t
mtal_iptv_sac_Construct(po_thid_t                 in_thid,
              u_int32_t                 in_req_num,
              const po_req_t           *in_req_lst,
              mtal_iptv_sac_handle_t             *out_handle);
#define  sac_Construct mtal_iptv_sac_Construct

/**
 * Finalize SAC handle
 *
 * @param [in,out] io_handle                    SAC handle
 * @param [out]    out_success_num              Success number
 * @param [out]    out_trans_flag_status        Indicates whether the transaction flag has been stored
 * @retval RET_OK                               Success
 * @retval RET_ILLEGALARGS                      Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR                    An unexpected error has occurred
 */
extern ret_t
mtal_iptv_sac_Destruct(mtal_iptv_sac_handle_t               io_handle,
             u_int32_t                 *out_success_num,
             u_int32_t                 *out_trans_flag_status);
#define  sac_Destruct  mtal_iptv_sac_Destruct

/**
 * Make SAC message
 *
 * @param [in,out] io_handle            SAC handle
 * @param [out]    out_msg              Output message
 * @param [in,out] io_msg_len           Output message buffer/Output message length
 * @param [out]    out_last_req_flag    Last request flag
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALHANDLE            Illegal handle is passed to this API
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SAC_TOO_LONG_REQUEST     @p out_msg length is not enough
 * @retval RET_SAC_TOO_MANY_SEQUENCE    Sequence number is beyond the max number
 */
extern ret_t
mtal_iptv_sac_MakeMessage(mtal_iptv_sac_handle_t            io_handle,
                u_int8_t               *out_msg,
                u_int32_t              *io_msg_len,
                bool_t                 *out_last_req_flag);
#define  sac_MakeMessage  mtal_iptv_sac_MakeMessage

/**
 * Process SAC message
 *
 * @param [in,out] io_handle            SAC handle
 * @param [in]     in_msg               Input message
 * @param [in]     in_msg_len           Input message length
 * @param [out]    out_end_flag         End flag
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALHANDLE            Illegal handle is passed to this API
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_UNSUPPORTED              An unsupported @p in_thid is passed to thie API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_SAC_VERIFICATION_FAILURE         Unexpected payload type recieved
 * @retval RET_SAC_CERT_VERIFICATION_FAILED     Fail to parse pkipath
 * @retval RET_SAC_CERT_VALIDITY_ERR            The pkipath included in @p in_msg is expired
 * @retval RET_SAC_CERT_REVOKED                 The pkipath included in @p in_msg is revoked
 * @retval RET_SAC_MSG_SIG_VERIFICATION_FAILED  Fail to verify signature
 * @retval RET_SAC_REQUEST_DENIED               DRM server has denied the request
 */
extern ret_t
mtal_iptv_sac_ProcessMessage(mtal_iptv_sac_handle_t         io_handle,
                   u_int8_t            *in_msg,
                   u_int32_t            in_msg_len,
                   bool_t              *out_end_flag);
#define  sac_ProcessMessage mtal_iptv_sac_ProcessMessage

#ifdef __cplusplus
}
#endif

#endif /* MTAL_SAC_API_H */
