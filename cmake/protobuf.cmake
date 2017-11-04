IF(WIN32)
	SET(PROTOC_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR}/protoc.exe)
	SET(GRPC_CPP_PLUGIN ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR}/grpc_cpp_plugin.exe)
ELSEIF(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	SET(PROTOC_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/protoc)
	SET(GRPC_CPP_PLUGIN ${CMAKE_BINARY_DIR}/bin/grpc_cpp_plugin)
ELSE()
	SET(EXECUTABLE_POSTFIX "")
	IF(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
		SET(EXECUTABLE_POSTFIX ".exe")
	ENDIF()
	SET(PROTOC_EXECUTABLE "${CMAKE_SOURCE_DIR}/cmake/tools/${CMAKE_HOST_SYSTEM_NAME}/protoc${EXECUTABLE_POSTFIX}")
	SET(GRPC_CPP_PLUGIN "${CMAKE_SOURCE_DIR}/cmake/tools/${CMAKE_HOST_SYSTEM_NAME}/grpc_cpp_plugin${EXECUTABLE_POSTFIX}")
ENDIF()

#  protoc_gen_grpc_cpp
#  --------------------------
#
#   Add custom commands to process ``.proto`` files to C++ using protoc and
#   GRPC plugin::
#
#     protobuf_generate_grpc_cpp OUTPUT_DIR [<ARGN>...]
#
#   ``ARGN``
#     ``.proto`` files
#
function(protoc_gen_grpc_cpp OUTPUT_DIR)
  if(NOT ARGN)
    message(SEND_ERROR "Error: PROTOBUF_GENERATE_GRPC_CPP() called without any proto files")
    return()
  endif()

  set(_protobuf_include_path -I . -I ${CMAKE_SOURCE_DIR}/rtc/src/webrtc/logging/rtc_event_log
							 -I ${CMAKE_SOURCE_DIR}/protos/audiomixer -I ${CMAKE_SOURCE_DIR}/protos/videorelay
							 -I ${CMAKE_SOURCE_DIR}/protos/dataserver -I ${CMAKE_SOURCE_DIR}/protos/confservice
							 -I ${CMAKE_SOURCE_DIR}/protos/mindlink -I ${CMAKE_SOURCE_DIR}/monitor_protos)
  
if(ANDROID OR IOS)
  foreach(FIL ${ARGN})
    get_filename_component(FIL_WE ${FIL} NAME_WE)
	
    add_custom_command(
      OUTPUT "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"
             "${OUTPUT_DIR}/${FIL_WE}.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.pb.h"
      COMMAND ${PROTOC_EXECUTABLE}
      ARGS --grpc_out=${OUTPUT_DIR}
           --cpp_out=${OUTPUT_DIR}
           --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
           ${_protobuf_include_path}
           ${FIL}
		DEPENDS ${FIL}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Running gRPC C++ protocol buffer compiler on ${FIL}"
      VERBATIM)
	  
	  MESSAGE(STATUS ${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc)

      set_source_files_properties("${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc" "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"  "${OUTPUT_DIR}/${FIL_WE}_mock.grpc.pb.h" "${OUTPUT_DIR}/${FIL_WE}.pb.cc" "${_gRPC_PROTO_GENS_DIR}/${FIL_WE}.pb.h" PROPERTIES GENERATED TRUE)
  endforeach()
else ()
	foreach(FIL ${ARGN})
    get_filename_component(FIL_WE ${FIL} NAME_WE)
	
    add_custom_command(
      OUTPUT "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"
             "${OUTPUT_DIR}/${FIL_WE}.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.pb.h"
      COMMAND ${PROTOC_EXECUTABLE}
      ARGS --grpc_out=${OUTPUT_DIR}
           --cpp_out=${OUTPUT_DIR}
           --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
           ${_protobuf_include_path}
           ${FIL}
	  DEPENDS ${FIL} protoc grpc_cpp_plugin
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Running gRPC C++ protocol buffer compiler on ${FIL}"
      VERBATIM)
	  
	  MESSAGE(STATUS ${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc)

      set_source_files_properties("${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc" "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"  "${OUTPUT_DIR}/${FIL_WE}_mock.grpc.pb.h" "${OUTPUT_DIR}/${FIL_WE}.pb.cc" "${_gRPC_PROTO_GENS_DIR}/${FIL_WE}.pb.h" PROPERTIES GENERATED TRUE)
  endforeach()
endif()
endfunction()

function(protoc_gen_cpp OUTPUT_DIR)
  if(NOT ARGN)
    message(SEND_ERROR "Error: PROTOBUF_GENERATE_GRPC_CPP() called without any proto files")
    return()
  endif()

  set(_protobuf_include_path -I . -I ${CMAKE_SOURCE_DIR}/rtc/src/webrtc/logging/rtc_event_log
							 -I ${CMAKE_SOURCE_DIR}/protos/audiomixer -I ${CMAKE_SOURCE_DIR}/protos/videorelay
							 -I ${CMAKE_SOURCE_DIR}/protos/dataserver -I ${CMAKE_SOURCE_DIR}/protos/confservice
							 -I ${CMAKE_SOURCE_DIR}/protos/mindlink)
if(ANDROID OR IOS)
  foreach(FIL ${ARGN})
    get_filename_component(FIL_WE ${FIL} NAME_WE)	
    add_custom_command(
      OUTPUT "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"
             "${OUTPUT_DIR}/${FIL_WE}.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.pb.h"
      COMMAND ${PROTOC_EXECUTABLE}
      ARGS --cpp_out=${OUTPUT_DIR}
           ${_protobuf_include_path}
           ${FIL}
	  DEPENDS ${FIL}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Running gRPC C++ protocol buffer compiler on ${FIL}"
      VERBATIM)
      set_source_files_properties("${OUTPUT_DIR}/${FIL_WE}.pb.cc" "${_gRPC_PROTO_GENS_DIR}/${FIL_WE}.pb.h" PROPERTIES GENERATED TRUE)
  endforeach()
else ()
	foreach(FIL ${ARGN})
    get_filename_component(FIL_WE ${FIL} NAME_WE)	
    add_custom_command(
      OUTPUT "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.grpc.pb.h"
             "${OUTPUT_DIR}/${FIL_WE}.pb.cc"
             "${OUTPUT_DIR}/${FIL_WE}.pb.h"
      COMMAND ${PROTOC_EXECUTABLE}
      ARGS --cpp_out=${OUTPUT_DIR}
           ${_protobuf_include_path}
           ${FIL}
	  DEPENDS ${FIL} protoc
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Running gRPC C++ protocol buffer compiler on ${FIL}"
      VERBATIM)
      set_source_files_properties("${OUTPUT_DIR}/${FIL_WE}.pb.cc" "${_gRPC_PROTO_GENS_DIR}/${FIL_WE}.pb.h" PROPERTIES GENERATED TRUE)
  endforeach()
endif()
endfunction()