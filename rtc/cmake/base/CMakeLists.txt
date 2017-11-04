INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}
					${webrtc_SOURCE_DIR}/thirdparty/boringssl/src/include)

SET(BASE_DIR ${webrtc_SOURCE_DIR}/src/webrtc/base)

LIST(APPEND RTC_BASE_APPROVED_SOURCES
			${BASE_DIR}/array_view.h
			${BASE_DIR}/arraysize.h
			${BASE_DIR}/atomicops.h
			${BASE_DIR}/base64.cc
			${BASE_DIR}/base64.h
			${BASE_DIR}/basictypes.h
			${BASE_DIR}/bind.h
			${BASE_DIR}/bitbuffer.cc
			${BASE_DIR}/bitbuffer.h
			${BASE_DIR}/buffer.h
			${BASE_DIR}/bufferqueue.cc
			${BASE_DIR}/bufferqueue.h
			${BASE_DIR}/bytebuffer.cc
			${BASE_DIR}/bytebuffer.h
			${BASE_DIR}/byteorder.h
			${BASE_DIR}/checks.cc
			${BASE_DIR}/checks.h
			${BASE_DIR}/constructormagic.h
			${BASE_DIR}/copyonwritebuffer.cc
			${BASE_DIR}/copyonwritebuffer.h
			${BASE_DIR}/criticalsection.cc
			${BASE_DIR}/criticalsection.h
			${BASE_DIR}/deprecation.h
			${BASE_DIR}/event.cc
			${BASE_DIR}/event.h
			${BASE_DIR}/event_tracer.cc
			${BASE_DIR}/event_tracer.h
			${BASE_DIR}/file.cc
			${BASE_DIR}/file.h
			${BASE_DIR}/flags.cc
			${BASE_DIR}/flags.h
			${BASE_DIR}/format_macros.h
			${BASE_DIR}/function_view.h
			${BASE_DIR}/ignore_wundef.h
			${BASE_DIR}/location.cc
			${BASE_DIR}/location.h
			${BASE_DIR}/md5.cc
			${BASE_DIR}/md5.h
			${BASE_DIR}/md5digest.cc
			${BASE_DIR}/md5digest.h
			${BASE_DIR}/mod_ops.h
			${BASE_DIR}/onetimeevent.h
			${BASE_DIR}/optional.cc
			${BASE_DIR}/optional.h
			${BASE_DIR}/pathutils.cc
			${BASE_DIR}/pathutils.h
			${BASE_DIR}/platform_file.cc
			${BASE_DIR}/platform_file.h
			${BASE_DIR}/platform_thread.cc
			${BASE_DIR}/platform_thread.h
			${BASE_DIR}/platform_thread_types.h
			${BASE_DIR}/race_checker.cc
			${BASE_DIR}/race_checker.h
			${BASE_DIR}/random.cc
			${BASE_DIR}/random.h
			${BASE_DIR}/rate_limiter.cc
			${BASE_DIR}/rate_limiter.h
			${BASE_DIR}/rate_statistics.cc
			${BASE_DIR}/rate_statistics.h
			${BASE_DIR}/ratetracker.cc
			${BASE_DIR}/ratetracker.h
			${BASE_DIR}/refcount.h
			${BASE_DIR}/refcountedobject.h
			${BASE_DIR}/safe_compare.h
			${BASE_DIR}/safe_conversions.h
			${BASE_DIR}/safe_conversions_impl.h
			${BASE_DIR}/sanitizer.h
			${BASE_DIR}/scoped_ref_ptr.h
			${BASE_DIR}/stringencode.cc
			${BASE_DIR}/stringencode.h
			${BASE_DIR}/stringutils.cc
			${BASE_DIR}/stringutils.h
			${BASE_DIR}/swap_queue.h
			${BASE_DIR}/template_util.h
			${BASE_DIR}/thread_annotations.h
			${BASE_DIR}/thread_checker.h
			${BASE_DIR}/thread_checker_impl.cc
			${BASE_DIR}/thread_checker_impl.h
			${BASE_DIR}/timestampaligner.cc
			${BASE_DIR}/timestampaligner.h
			${BASE_DIR}/timeutils.cc
			${BASE_DIR}/timeutils.h
			${BASE_DIR}/trace_event.h
			${BASE_DIR}/type_traits.h
			${BASE_DIR}/logging.cc
			${BASE_DIR}/logging.h
)

LIST(APPEND RTC_TASK_QUEUE_SOURCES
			${BASE_DIR}/task_queue.h
			${BASE_DIR}/task_queue_posix.h
			${BASE_DIR}/sequenced_task_checker.h
			${BASE_DIR}/sequenced_task_checker_impl.cc
			${BASE_DIR}/sequenced_task_checker_impl.h
			${BASE_DIR}/weak_ptr.cc
			${BASE_DIR}/weak_ptr.h
)

LIST(APPEND RTC_NUMERICS_SOURCES 
			${BASE_DIR}/numerics/exp_filter.cc
			${BASE_DIR}/numerics/exp_filter.h
			${BASE_DIR}/numerics/percentile_filter.h
)

LIST(APPEND RTC_JSON_SOURCES
			${BASE_DIR}/json.cc
			${BASE_DIR}/json.h
)

LIST(APPEND RTC_BASE_SOURCES
			${BASE_DIR}/asyncinvoker-inl.h
			${BASE_DIR}/asyncinvoker.cc
			${BASE_DIR}/asyncinvoker.h
			${BASE_DIR}/asyncpacketsocket.cc
			${BASE_DIR}/asyncpacketsocket.h
			${BASE_DIR}/asyncresolverinterface.cc
			${BASE_DIR}/asyncresolverinterface.h
			${BASE_DIR}/asyncsocket.cc
			${BASE_DIR}/asyncsocket.h
			${BASE_DIR}/asynctcpsocket.cc
			${BASE_DIR}/asynctcpsocket.h
			${BASE_DIR}/asyncudpsocket.cc
			${BASE_DIR}/asyncudpsocket.h
			${BASE_DIR}/common.cc
			${BASE_DIR}/crc32.cc
			${BASE_DIR}/crc32.h
			${BASE_DIR}/cryptstring.cc
			${BASE_DIR}/cryptstring.h
			${BASE_DIR}/filerotatingstream.cc
			${BASE_DIR}/filerotatingstream.h
			${BASE_DIR}/fileutils.cc
			${BASE_DIR}/fileutils.h
			${BASE_DIR}/gunit_prod.h
			${BASE_DIR}/helpers.cc
			${BASE_DIR}/helpers.h
			${BASE_DIR}/httpbase.cc
			${BASE_DIR}/httpbase.h
			${BASE_DIR}/httpcommon-inl.h
			${BASE_DIR}/httpcommon.cc
			${BASE_DIR}/httpcommon.h
			${BASE_DIR}/ipaddress.cc
			${BASE_DIR}/ipaddress.h
			${BASE_DIR}/messagedigest.cc
			${BASE_DIR}/messagedigest.h
			${BASE_DIR}/messagehandler.cc
			${BASE_DIR}/messagehandler.h
			${BASE_DIR}/messagequeue.cc
			${BASE_DIR}/messagequeue.h
			${BASE_DIR}/nethelpers.cc
			${BASE_DIR}/nethelpers.h
			${BASE_DIR}/network.cc
			${BASE_DIR}/network.h
			${BASE_DIR}/networkmonitor.cc
			${BASE_DIR}/networkmonitor.h
			${BASE_DIR}/nullsocketserver.cc
			${BASE_DIR}/nullsocketserver.h
			${BASE_DIR}/openssl.h
			${BASE_DIR}/openssladapter.cc
			${BASE_DIR}/openssladapter.h
			${BASE_DIR}/openssldigest.cc
			${BASE_DIR}/openssldigest.h
			${BASE_DIR}/opensslidentity.cc
			${BASE_DIR}/opensslidentity.h
			${BASE_DIR}/opensslstreamadapter.cc
			${BASE_DIR}/opensslstreamadapter.h
			${BASE_DIR}/physicalsocketserver.cc
			${BASE_DIR}/physicalsocketserver.h
			${BASE_DIR}/proxyinfo.cc
			${BASE_DIR}/proxyinfo.h
			${BASE_DIR}/ratelimiter.cc
			${BASE_DIR}/ratelimiter.h
			${BASE_DIR}/rtccertificate.cc
			${BASE_DIR}/rtccertificate.h
			${BASE_DIR}/rtccertificategenerator.cc
			${BASE_DIR}/rtccertificategenerator.h
			${BASE_DIR}/sha1.cc
			${BASE_DIR}/sha1.h
			${BASE_DIR}/sha1digest.cc
			${BASE_DIR}/sha1digest.h
			${BASE_DIR}/sharedexclusivelock.cc
			${BASE_DIR}/sharedexclusivelock.h
			${BASE_DIR}/signalthread.cc
			${BASE_DIR}/signalthread.h
			${BASE_DIR}/sigslot.cc
			${BASE_DIR}/sigslot.h
			${BASE_DIR}/sigslotrepeater.h
			${BASE_DIR}/socket.h
			${BASE_DIR}/socketadapters.cc
			${BASE_DIR}/socketadapters.h
			${BASE_DIR}/socketaddress.cc
			${BASE_DIR}/socketaddress.h
			${BASE_DIR}/socketaddresspair.cc
			${BASE_DIR}/socketaddresspair.h
			${BASE_DIR}/socketfactory.h
			${BASE_DIR}/socketserver.h
			${BASE_DIR}/socketstream.cc
			${BASE_DIR}/socketstream.h
			${BASE_DIR}/ssladapter.cc
			${BASE_DIR}/ssladapter.h
			${BASE_DIR}/sslfingerprint.cc
			${BASE_DIR}/sslfingerprint.h
			${BASE_DIR}/sslidentity.cc
			${BASE_DIR}/sslidentity.h
			${BASE_DIR}/sslstreamadapter.cc
			${BASE_DIR}/sslstreamadapter.h
			${BASE_DIR}/stream.cc
			${BASE_DIR}/stream.h
			${BASE_DIR}/thread.cc
			${BASE_DIR}/thread.h
			${BASE_DIR}/virtualsocketserver.cc
			${BASE_DIR}/virtualsocketserver.h
			${BASE_DIR}/callback.h
			${BASE_DIR}/logsinks.cc
			${BASE_DIR}/logsinks.h
			${BASE_DIR}/mathutils.h
			${BASE_DIR}/optionsfile.cc
			${BASE_DIR}/optionsfile.h
			${BASE_DIR}/rollingaccumulator.h
			${BASE_DIR}/sslroots.h
			${BASE_DIR}/testbase64.h
			${BASE_DIR}/testclient.cc
			${BASE_DIR}/testclient.h
			${BASE_DIR}/transformadapter.cc
			${BASE_DIR}/transformadapter.h
			${BASE_DIR}/window.h
)

LIST(APPEND RTC_BASE_TEST_UTILS_SOURCES
			${BASE_DIR}/fakeclock.cc
			${BASE_DIR}/fakeclock.h
			${BASE_DIR}/fakenetwork.h
			${BASE_DIR}/fakesslidentity.h
			${BASE_DIR}/firewallsocketserver.cc
			${BASE_DIR}/firewallsocketserver.h
			${BASE_DIR}/gunit.h
			${BASE_DIR}/natserver.cc
			${BASE_DIR}/natserver.h
			${BASE_DIR}/natsocketfactory.cc
			${BASE_DIR}/natsocketfactory.h
			${BASE_DIR}/nattypes.cc
			${BASE_DIR}/nattypes.h
			${BASE_DIR}/sigslottester.h
			${BASE_DIR}/sigslottester.h.pump
			${BASE_DIR}/testbase64.h
			${BASE_DIR}/testechoserver.h
			${BASE_DIR}/testutils.h
			${BASE_DIR}/timedelta.h
)

IF(WIN32)
	LIST(APPEND RTC_BASE_APPROVED_SOURCES ${BASE_DIR}/file_win.cc)
	LIST(APPEND RTC_TASK_QUEUE_SOURCES ${BASE_DIR}/task_queue_win.cc)
	LIST(APPEND RTC_BASE_SOURCES
				${BASE_DIR}/win32socketinit.cc
				${BASE_DIR}/win32socketinit.h
				${BASE_DIR}/win32socketserver.cc
				${BASE_DIR}/win32socketserver.h
				${BASE_DIR}/win32.cc
				${BASE_DIR}/win32.h
				${BASE_DIR}/win32filesystem.cc
				${BASE_DIR}/win32filesystem.h
				${BASE_DIR}/win32securityerrors.cc
				${BASE_DIR}/win32window.cc
				${BASE_DIR}/win32window.h
				${BASE_DIR}/winping.cc
				${BASE_DIR}/winping.h
	)
	
	ADD_DEFINITIONS(/wd4005 /wd4703)
ELSE()
	LIST(APPEND RTC_BASE_APPROVED_SOURCES 	${BASE_DIR}/file_posix.cc)
	LIST(APPEND RTC_BASE_SOURCES
				${BASE_DIR}/ifaddrs_converter.cc
				${BASE_DIR}/ifaddrs_converter.h
				${BASE_DIR}/unixfilesystem.cc
				${BASE_DIR}/unixfilesystem.h
	)
	
	IF(APPLE)
		LIST(APPEND RTC_TASK_QUEUE_SOURCES ${BASE_DIR}/task_queue_gcd.cc ${BASE_DIR}/task_queue_posix.cc)
		LIST(APPEND RTC_BASE_SOURCES
					${BASE_DIR}/macifaddrs_converter.cc
					${BASE_DIR}/thread_darwin.mm
					${BASE_DIR}/applefilesystem.mm
					${BASE_DIR}/logging_mac.mm
		)
		IF(WEBRTC_MAC)
			LIST(APPEND RTC_BASE_SOURCES
					${BASE_DIR}/macutils.cc
					${BASE_DIR}/macutils.h	
			)	
		ENDIF()
		
	ENDIF(APPLE)
	
	IF(ANDROID)
		LIST(APPEND RTC_BASE_SOURCES
					${BASE_DIR}/ifaddrs-android.h
					${BASE_DIR}/ifaddrs-android.cc
		)
	ENDIF(ANDROID)

	IF(CMAKE_SYSTEM_NAME MATCHES "Linux" OR ANDROID)
		LIST(APPEND RTC_TASK_QUEUE_SOURCES ${BASE_DIR}/task_queue_libevent.cc ${BASE_DIR}/task_queue_posix.cc)
	ENDIF()
ENDIF()


LIST(APPEND RTC_BASE_ALL_SOURCES ${RTC_BASE_APPROVED_SOURCES} ${RTC_BASE_SOURCES} ${RTC_BASE_TEST_UTILS_SOURCES} ${RTC_NUMERICS_SOURCES} ${RTC_TASK_QUEUE_SOURCES})

ADD_LIBRARY(rtc_base STATIC ${RTC_BASE_ALL_SOURCES})

SET_TARGET_PROPERTIES(rtc_base PROPERTIES FOLDER "webrtc")