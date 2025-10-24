cmake_minimum_required(VERSION 3.15)

project(group-two-project VERSION 1.0 DESCRIPTION "Binary Data Analysis with search and Statistics" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)


option(ENABLE_TESTING "Enable testing" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
        ${SRC_DIR}/*.cpp
        ${SRC_DIR}/*.cxx)

# Exclude the program's main.cpp from the library so tests don't pick up main()
set(MAIN_SRC ${PROJECT_SOURCE_DIR}/src/main.cpp)
list(REMOVE_ITEM SRC_FILES ${MAIN_SRC})

file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
        ${INCLUDE_DIR}/*.hpp
        ${INCLUDE_DIR}/*.h)
file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp)

message(STATUS "FOUND SOURCE FILES: ${SRC_FILES}")
message(STATUS "FOUND HEADER FILES: ${HEADER_FILES}")
message(STATUS "FOUND TEST FILES: ${TEST_FILES}")
foreach (SOURCE_FILE ${SOURCES})
    message(STATUS " Source file: ${SOURCE_FILE}")
endforeach()

# Build a library from the project sources so tests can link against the implementations
add_library(group_two_lib STATIC ${SRC_FILES})
target_include_directories(group_two_lib PUBLIC ${INCLUDE_DIR})


# Build the main executable and link with the library
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE group_two_lib)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

if(ENABLE_TESTING)
    enable_testing()

    # Check if test directory exists
    if(EXISTS ${TEST_DIR})
        message(STATUS "Testing enabled - test directory found")
        set(TEST_TARGETS "")

        # Add individual test files if they exist
        file(GLOB TEST_FILES "${TEST_DIR}/*.cpp")

        foreach(TEST_FILE ${TEST_FILES})
            get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
            add_executable(${TEST_NAME} ${TEST_FILE})
            target_include_directories(${TEST_NAME} PRIVATE ${INCLUDE_DIR})
            target_compile_options(${TEST_NAME} PRIVATE ${COMMON_WARNINGS})
            # Link test executables with the project library so they resolve implementations
            target_link_libraries(${TEST_NAME} PRIVATE group_two_lib)
            add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
            message(STATUS "  Added test: ${TEST_NAME}")
            list(APPEND TEST_TARGETS ${TEST_NAME})
        endforeach()
        if(TEST_TARGETS)
            add_custom_target(RunTests
                    COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --output-on-failure
                    DEPENDS ${TEST_TARGETS}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )
            add_dependencies(${PROJECT_NAME} RunTests)
            message(STATUS "Main target '${PROJECT_NAME}' will now run tests before linking.")
        endif()
    else()
        message(STATUS "Testing enabled but no test directory found")
    endif()
endif ()
