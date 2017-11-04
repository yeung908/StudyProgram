include (CMakeParseArguments)

set (GenerateProductVersionCurrentDir ${CMAKE_CURRENT_LIST_DIR})

function(generate_linux_product_version outfiles)
    set (options)
    set (oneValueArgs
        NAME
        BUNDLE
        ICON
        VERSION_MAJOR
        VERSION_MINOR
        VERSION_PATCH
        VERSION_REVISION)
    set (multiValueArgs)
    cmake_parse_arguments(PRODUCT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
	
    if (NOT PRODUCT_BUNDLE OR "${PRODUCT_BUNDLE}" STREQUAL "")
        set(PRODUCT_BUNDLE "${PRODUCT_NAME}")
    endif()
    if (NOT PRODUCT_ICON OR "${PRODUCT_ICON}" STREQUAL "")
        set(PRODUCT_ICON "")
    endif()

    if (NOT PRODUCT_VERSION_MAJOR OR "${PRODUCT_VERSION_MAJOR}" STREQUAL "")
        set(PRODUCT_VERSION_MAJOR 1)
    endif()
    if (NOT PRODUCT_VERSION_MINOR OR "${PRODUCT_VERSION_MINOR}" STREQUAL "")
        set(PRODUCT_VERSION_MINOR 0)
    endif()
    if (NOT PRODUCT_VERSION_PATCH OR "${PRODUCT_VERSION_PATCH}" STREQUAL "")
        set(PRODUCT_VERSION_PATCH 0)
    endif()
    if (NOT PRODUCT_VERSION_REVISION OR "${PRODUCT_VERSION_REVISION}" STREQUAL "")
        set(PRODUCT_VERSION_REVISION 0)
    endif()

    if (NOT PRODUCT_COMPANY_COPYRIGHT OR "${PRODUCT_COMPANY_COPYRIGHT}" STREQUAL "")
        string(TIMESTAMP PRODUCT_CURRENT_YEAR "%Y")
        set(PRODUCT_COMPANY_COPYRIGHT "${PRODUCT_COMPANY_NAME} (C) Copyright ${PRODUCT_CURRENT_YEAR} MAXHUB")
    endif()
    if (NOT PRODUCT_COMMENTS OR "${PRODUCT_COMMENTS}" STREQUAL "")
        set(PRODUCT_COMMENTS "${PRODUCT_NAME} v${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}")
    endif()
    if (NOT PRODUCT_ORIGINAL_FILENAME OR "${PRODUCT_ORIGINAL_FILENAME}" STREQUAL "")
        set(PRODUCT_ORIGINAL_FILENAME "${PRODUCT_NAME}")
    endif()
    if (NOT PRODUCT_INTERNAL_NAME OR "${PRODUCT_INTERNAL_NAME}" STREQUAL "")
        set(PRODUCT_INTERNAL_NAME "${PRODUCT_NAME}")
    endif()
    if (NOT PRODUCT_FILE_DESCRIPTION OR "${PRODUCT_FILE_DESCRIPTION}" STREQUAL "")
        set(PRODUCT_FILE_DESCRIPTION "${PRODUCT_NAME}")
    endif()
	
    set (_VersionInfoFile ${CMAKE_CURRENT_SOURCE_DIR}/inc/version_info.h)
    configure_file(
        ${GenerateProductVersionCurrentDir}/version_info_linux.in
        ${_VersionInfoFile}
        @ONLY)
    list(APPEND ${outfiles} ${_VersionInfoFile})
    set (${outfiles} ${${outfiles}} PARENT_SCOPE)
endfunction()