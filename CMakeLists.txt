cmake_minimum_required(VERSION 3.9)
project(dcheck VERSION 0.1 DESCRIPTION "assert library")
add_library(dcheck OBJECT dcheck.c)
set_target_properties(dcheck PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/dcheck.h
)
target_include_directories(dcheck PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(dcheck
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
