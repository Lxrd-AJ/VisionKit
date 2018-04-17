include(CMakeToolsHelpers OPTIONAL)

set( SOURCES 
    common/fake_blur.cpp
)

set( HEADERS
    vision.h 
    common/fake_blur.h
)

set( VISION_INCLUDE_FOLDERS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${OpenCV_INCLUDE_DIR}
)

include_directories( ${VISION_INCLUDE_FOLDERS} )
add_library( Vision STATIC ${SOURCES} ${HEADERS} )

set( VISION_LINK_LIBRARIES
    ${CMAKE_THREAD_LIBS_INIT}
    ${OpenCV_LIBRARIES}
)

target_link_libraries( Vision ${VISION_LINK_LIBRARIES})

install( TARGETS Vision
         LIBRARY DESTINATION lib 
         ARCHIVE DESTINATION lib/static
)       

install( DIRECTORY . DESTINATION include/vision
        FILES_MATCHING PATTERN "*.h"
)
