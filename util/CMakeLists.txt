INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_SOURCE_DIR}/rtc/src
					${CMAKE_SOURCE_DIR}/thirdparty/disruptor/include)
					
LIST(APPEND UTIL_SOURCES 
			inc/AtomicWrapper.h
			inc/CmdLineParser.h
			inc/RingBuffer.h
			inc/RtcLoggerWrapper.h
			inc/SerializableObject.h
			src/RingBuffer.cxx
			src/RtcLoggerWrapper.cxx
)

ADD_LIBRARY(util STATIC ${UTIL_SOURCES})

SET_TARGET_PROPERTIES(util PROPERTIES FOLDER "common")						
