add_library(Library STATIC)
target_sources(Library
    PRIVATE
        src/point.cpp
        src/point.cpp 
        src/fractalDimension.cpp
)

target_include_directories(Library 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)