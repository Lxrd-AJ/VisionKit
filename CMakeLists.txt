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