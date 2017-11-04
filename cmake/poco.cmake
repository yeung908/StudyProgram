IF(CMAKE_SYSTEM_NAME MATCHES "Windows") 
ADD_DEFINITIONS(/DPOCO_STATIC)
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/Foundation/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/Util/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/JSON/include
	${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/Net/include
)

SET_TARGET_PROPERTIES(Foundation PROPERTIES FOLDER "thirdparty/Poco")
SET_TARGET_PROPERTIES(XML PROPERTIES FOLDER "thirdparty/Poco")
SET_TARGET_PROPERTIES(JSON PROPERTIES FOLDER "thirdparty/Poco")
SET_TARGET_PROPERTIES(Util PROPERTIES FOLDER "thirdparty/Poco")
SET_TARGET_PROPERTIES(Net PROPERTIES FOLDER "thirdparty/Poco")
SET_TARGET_PROPERTIES(uninstall PROPERTIES FOLDER "thirdparty/Poco")
find_package(OpenSSL)
IF(OPENSSL_FOUND)
	SET_TARGET_PROPERTIES(NetSSL PROPERTIES FOLDER "thirdparty/Poco")
	#SET_TARGET_PROPERTIES(Crypto PROPERTIES FOLDER "thirdparty/Poco")
ENDIF(OPENSSL_FOUND)

ELSE() 

ADD_DEFINITIONS(-DPOCO_STATIC)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-gnu/Foundation/include
					${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-gnu/Util/include
					${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-gnu/JSON/include
					${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-gnu/Net/include
)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
