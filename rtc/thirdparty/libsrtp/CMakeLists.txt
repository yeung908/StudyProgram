INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}
					${CMAKE_CURRENT_SOURCE_DIR}/config
					${CMAKE_CURRENT_SOURCE_DIR}/include
					${CMAKE_CURRENT_SOURCE_DIR}/crypto/include
)

LIST(APPEND SRTP_SOURCES
			${CMAKE_CURRENT_SOURCE_DIR}/include/ekt.h
			${CMAKE_CURRENT_SOURCE_DIR}/include/rtp.h
			${CMAKE_CURRENT_SOURCE_DIR}/include/srtp.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/aes.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/aes_gcm_ossl.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/aes_icm.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/aes_icm_ossl.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/alloc.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/auth.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/cipher.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/crypto_kernel.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/crypto_types.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/datatypes.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/err.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/integers.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/key.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/null_auth.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/null_cipher.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/rdb.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/rdbx.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/include/stat.h
			${CMAKE_CURRENT_SOURCE_DIR}/include/rtp_priv.h
			${CMAKE_CURRENT_SOURCE_DIR}/include/srtp_priv.h
			${CMAKE_CURRENT_SOURCE_DIR}/include/ut_sim.h
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/cipher/aes_gcm_ossl.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/cipher/aes_icm_ossl.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/cipher/cipher.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/cipher/null_cipher.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/hash/auth.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/hash/hmac_ossl.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/hash/null_auth.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/kernel/alloc.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/kernel/crypto_kernel.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/kernel/err.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/kernel/key.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/math/datatypes.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/math/stat.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/replay/rdb.c
			${CMAKE_CURRENT_SOURCE_DIR}/crypto/replay/rdbx.c
			${CMAKE_CURRENT_SOURCE_DIR}/srtp/ekt.c
			${CMAKE_CURRENT_SOURCE_DIR}/srtp/srtp.c
)

ADD_DEFINITIONS(-DPACKAGE_STRING="libsrtp2 2.0.0-pre"
				-DPACKAGE_VERSION="2.0.0-pre"
				-DHAVE_CONFIG_H
				-DOPENSSL
				-DHAVE_STDLIB_H
				-DHAVE_STRING_H
				-DHAVE_STDINT_H
				-DHAVE_INTTYPES_H
				-DHAVE_INT16_T
				-DHAVE_INT32_T
				-DHAVE_INT8_T
				-DHAVE_UINT16_T
				-DHAVE_UINT32_T
				-DHAVE_UINT64_T
				-DHAVE_UINT8_T
)

IF(WIN32)
ADD_DEFINITIONS(-DHAVE_WINSOCK2_H /wd4018)
ELSE()
ADD_DEFINITIONS(-DHAVE_ARPA_INET_H
				-DHAVE_NETINET_IN_H
				-DHAVE_SYS_TYPES_H
				-DHAVE_UNISTD_H
)
ENDIF()

ADD_LIBRARY(srtp STATIC ${SRTP_SOURCES})