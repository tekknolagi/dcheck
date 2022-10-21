cmake_minimum_required(VERSION 3.9)
project(dcheck VERSION 0.1 DESCRIPTION "assert library")
add_library(dcheck SHARED dcheck.c)
set_target_properties(dcheck PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER dcheck.h
)
target_include_directories(dcheck PRIVATE ${CMAKE_SOURCE_DIR})
