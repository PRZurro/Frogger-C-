
cmake_minimum_required(VERSION 3.4.1)

set ( BOX2D_CODE_PATH ${CMAKE_CURRENT_LIST_DIR}/code )


include_directories ( ${BOX2D_CODE_PATH} )

file (
    GLOB_RECURSE
    BOX2D_SOURCES
    ${BOX2D_CODE_PATH}/*.cpp
)

add_library (
    box2d
    STATIC
    ${BOX2D_SOURCES}
)
