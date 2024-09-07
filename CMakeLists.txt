cmake_minimum_required(VERSION 3.10)
project(BigMathToolkit)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB LIB_SOURCES src/bint/*.cxx)

SET(LIBRARY_NAME bmt)
SET(LIBRARY_ALIAS bwd::bmt)

# Library target
add_library(${LIBRARY_NAME} ${LIB_SOURCES})
add_library(${LIBRARY_ALIAS} ALIAS ${LIBRARY_NAME})

# Include directories
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(test)