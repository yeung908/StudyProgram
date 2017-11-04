/*
 * Marlin IPTV-ES Client SDK version 3.1
 *
 * Any code and mechanism in this module must not be used
 * in any form without permissions.
 *
 * Copyright 2006,2007,2008,2009 Sony Corporation
 */
#ifndef MTAL_DRM_API_H
#define MTAL_DRM_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================*/
/**
 * @file
 * DRM (Digital Rights Management) API
 *
 * require: keymng, cache, time, rend, base
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
#define RET_DRM_KEY_NOT_FOUND                   (RET_DRM_BASE|1)
#define RET_DRM_KEY_INVALID                     (RET_DRM_BASE|2)
#define RET_DRM_TT_INVALID                      (RET_DRM_BASE|3)
#define RET_DRM_SAVE_ERROR                      (RET_DRM_BASE|4)
#define RET_DRM_REND_ERROR                      (RET_DRM_BASE|5)
#define RET_DRM_BUFFER_SHORT                    (RET_DRM_BASE|6)
#define RET_DRM_KEY_IN_USE                      (RET_DRM_BASE|7)

/*============================================================================
 * APIs
 *==========================================================================*/
/**
 * Extract content key to decryptor
 * If VOD key is extracted, it is automatically deleted from NVS.
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_rend_id           Renderer Id
 * @param [in]     in_key_ref           Key reference
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_KEY_NOT_FOUND        The key specified by @p in_key_ref is not found
 * @retval RET_DRM_KEY_INVALID          The key specified by @p in_key_ref is expired
 * @retval RET_DRM_TT_INVALID           Trusted time is not adjusted
 * @retval RET_DRM_SAVE_ERROR           Fail to save read-write NVS
 * @retval RET_DRM_REND_ERROR           Fail to extract content key to renderer
 * @retval RET_DRM_KEY_IN_USE           All keys and licenses are already extracted to renderer
 */
extern ret_t
mtal_iptv_drm_ExtractContentKey(po_thid_t                 in_thid,
                      u_int32_t                 in_rend_id,
                      const po_key_ref_t       *in_key_ref);


/**
 * Delete content key
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_key_ref           Key reference
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_SAVE_ERROR           Fail to save read-write NVS
 * @retval RET_DRM_KEY_IN_USE           All keys and licenses are currently used by renderer
 */
extern ret_t
mtal_iptv_drm_DelContentKey(po_thid_t                     in_thid,
                  const po_key_ref_t           *in_key_ref);

/**
 * Delete uncommitted key
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_key_ref           Key reference
 * @retval RET_OK                       Success
 * @retval RET_NOMEM                    Fail to allocate memory
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_SAVE_ERROR           Fail to save read-write NVS
 */
extern ret_t
mtal_iptv_drm_DelUncommittedKey(po_thid_t                  in_thid,
                      const po_key_ref_t        *in_key_ref);

/**
 * Get key information
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_key_ref           Key reference
 * @param [out]    out_key_info         Key information
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_KEY_NOT_FOUND        The key specified by @p in_key_ref is not found
 */
extern ret_t
mtal_iptv_drm_GetKeyInfo(po_thid_t                        in_thid,
               const po_key_ref_t              *in_key_ref,
               po_key_info_t                   *out_key_info);

/**
 * Get key number
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_action_id         Action ID
 * @param [out]    out_num              Key number
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 */
extern ret_t
mtal_iptv_drm_GetKeyNum(po_thid_t                         in_thid,
              u_int8_t                          in_action_id,
              u_int32_t                        *out_num);

/**
 * Get key information list
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_action_id         Action ID
 * @param [in,out] io_num               Key number
 * @param [out]    out_key_ref_lst      Key reference list
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_BUFFER_SHORT         @p io_num is not enough to get key reference list
 */
extern ret_t
mtal_iptv_drm_GetKeyRefList(po_thid_t                     in_thid,
                  u_int8_t                      in_action_id,
                  u_int32_t                    *io_num,
                  po_key_ref_t                 *out_key_ref_lst);

#if !defined(IPTVES_PUBLISH_BUILD)
/*----------------------------------------------------------------------------
 * Functions for Test/Tools
 *--------------------------------------------------------------------------*/
/**
 * Get content key
 * Even if VOD key is extracted, it is not deleted from NVS.
 *
 * @param [in]     in_thid              Trust Hierarchy ID
 * @param [in]     in_key_ref           Key reference
 * @param [out]    out_ckey             Content key
 * @retval RET_OK                       Success
 * @retval RET_ILLEGALARGS              Illegal arguments are passed to this API
 * @retval RET_INTERNALERROR            An unexpected error has occurred
 * @retval RET_DRM_KEY_NOT_FOUND        The key specified by @p in_key_ref is not found
 * @retval RET_DRM_KEY_INVALID          The key specified by @p in_key_ref is expired
 * @retval RET_DRM_TT_INVALID           Fail to get trusted time
 * @retval RET_DRM_KEY_IN_USE           All keys and licenses are currently used by renderer
 */
extern ret_t
mtal_iptv_drm_GetContentKey(po_thid_t                     in_thid,
                  const po_key_ref_t           *in_key_ref,
                  u_int8_t                      out_ckey[PO_CKEY_LEN]);

#endif /* !IPTVES_PUBLISH_BUILD */



#define drm_ExtractContentKey mtal_iptv_drm_ExtractContentKey
#define drm_DelContentKey     mtal_iptv_drm_DelContentKey           
#define drm_DelUncommittedKey mtal_iptv_drm_DelUncommittedKey       
#define drm_GetKeyInfo        mtal_iptv_drm_GetKeyInfo              
#define drm_GetKeyNum         mtal_iptv_drm_GetKeyNum               
#define drm_GetKeyRefList     mtal_iptv_drm_GetKeyRefList           
#define drm_GetContentKey     mtal_iptv_drm_GetContentKey




#ifdef __cplusplus
}
#endif

#endif /* MTAL_DRM_API_H */
