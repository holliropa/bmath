cmake_minimum_required(VERSION 3.10)
project(bmath LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB BINT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/internal/*.cpp
)

SET(LIBRARY_NAME bmath)
SET(LIBRARY_ALIAS bw::bmath)

# Library target
add_library(${LIBRARY_NAME} ${BINT_SOURCES})
add_library(${LIBRARY_ALIAS} ALIAS ${LIBRARY_NAME})

# Include directories
target_include_directories(${LIBRARY_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>   # Public headers
        $<INSTALL_INTERFACE:include>                            # Installed location
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>      # Explicitly require internal prefix
)

# Optionally enable warnings (recommended)
target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_subdirectory(tests)
