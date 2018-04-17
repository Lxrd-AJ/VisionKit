cmake_minimum_required( VERSION 2.8 )

project( Vision )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake )

# ---------------------- Find Packages ---------------------------------------

find_package(OpenCV REQUIRED)

# ---------------------- Build Settings ---------------------------------------
set(CMAKE_CXX_STANDARD 11)

# ---------------------- Walk the subdirectories ---------------------------------------
add_subdirectory(src)
add_subdirectory(examples)
if( BUILD_TESTING )
    add_subdirectory( test )
endif()

# -------------------- Package ------------------------------------

if( APPLE )
  set( CPACK_SYSTEM_NAME "Mac" )
elseif( UNIX )
  set( CPACK_SYSTEM_NAME "Linux" )
  if ( NOT LINK_STATIC )
    execute_process(COMMAND lsb_release -is OUTPUT_VARIABLE LSB_ID)
    execute_process(COMMAND lsb_release -rs OUTPUT_VARIABLE LSB_RELEASE)
    if( LSB_ID AND LSB_RELEASE )
      string(STRIP "${LSB_ID}" LSB_ID)
      string(STRIP "${LSB_RELEASE}" LSB_RELEASE)
      set( CPACK_SYSTEM_NAME "${CPACK_SYSTEM_NAME}-${LSB_ID}-${LSB_RELEASE}")
    elseif( EXISTS "/etc/debian_version")
      file( READ /etc/debian_version DEBIAN_VERSION )
      set( CPACK_SYSTEM_NAME "${CPACK_SYSTEM_NAME}-${DEBIAN_VERSION}")
    elseif( EXISTS "/etc/redhat-release")
      set( CPACK_SYSTEM_NAME "${CPACK_SYSTEM_NAME}-Redhat")
    endif()
  endif()
elseif( WIN32)
  set( CPACK_SYSTEM_NAME "Windows" )
endif()
if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
  set( CPACK_SYSTEM_NAME "${CPACK_SYSTEM_NAME}-64bit" )
else()
  set( CPACK_SYSTEM_NAME "${CPACK_SYSTEM_NAME}-32bit" )
endif()
set( CPACK_PACKAGE_VERSION "${AMPNET_VERSION}" )

if( MSVC )
  set( BUILD_CONFIG "\${CPACK_BUILD_CONFIG}")
else()
  set( BUILD_CONFIG ${CMAKE_BUILD_TYPE})
endif()

set( CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_SYSTEM_NAME}-${BUILD_CONFIG}" )
set( CPACK_OUTPUT_FILE_PREFIX "dist")
set( CPACK_SOURCE_GENERATOR "ZIP" )
if( WIN32 )
  set( CPACK_GENERATOR "7Z" )
else()
  set( CPACK_GENERATOR "TXZ" )
endif()
include( CPack )