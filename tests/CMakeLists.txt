cmake_minimum_required(VERSION 3.10)
project(BMT-Tests)

set(CMAKE_EXE_LINKER_FLAGS "-static")

# Create a test executable
add_executable(${PROJECT_NAME} tests.cpp)

# Ensure the test depends on the library
add_dependencies(${PROJECT_NAME} bw::bmath)

# Link the library to the test executable
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        bw::bmath
)

# Add the test to CTest
add_test(
        NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME}
)
