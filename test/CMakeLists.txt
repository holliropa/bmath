# Define the BM_CreateTest function
function(BM_CreateTest NAME MAIN_SOURCE OTHER_SOURCES)
    # Convert OTHER_SOURCES to a list
    set(BM_OTHER_SOURCE_LIST ${OTHER_SOURCE})

    # Define the test executable name
    set(BM_TEST_NAME test-${NAME})

    # Create the executable target
    add_executable(${BM_TEST_NAME} ${MAIN_SOURCE})

    # Add all source files to the executable
    target_sources(${BM_TEST_NAME} PRIVATE ${BM_OTHER_SOURCE_LIST})

    # Add the test with the same name as the executable
    add_test(
            NAME ${BM_TEST_NAME}
            COMMAND $<TARGET_FILE:${BM_TEST_NAME}>
    )

    # Link the executable to the necessary libraries
    target_link_libraries(${BM_TEST_NAME} PRIVATE ${LIBRARY_ALIAS})
endfunction()

add_subdirectory(bint)