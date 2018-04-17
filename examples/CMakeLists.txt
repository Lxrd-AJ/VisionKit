set( CPP_SAMPLE_SOURCES
    how_to_use.cpp 
)

set( VISION_INCLUDE_FOLDERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_BINARY_DIR}/../src
    ${OpenCV_INCLUDE_DIR}
)

include_directories( ${VISION_INCLUDE_FOLDERS} ${CMAKE_CURRENT_SOURCE_DIR})

foreach( file ${CPP_SAMPLE_SOURCES} )

    get_filename_component( sample_name ${file} NAME_WE)
    add_executable( ${sample_name} ${file} )
    target_link_libraries( ${sample_name} Vision )
    
endforeach( )
