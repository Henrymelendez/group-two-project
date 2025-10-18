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
add_executable(${PROJECT_NAME} ${SRC_FILES}
        src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

if(ENABLE_TESTING)
    enable_testing()

    # Check if test directory exists
    if(EXISTS ${TEST_DIR})
        message(STATUS "Testing enabled - test directory found")

        # Add individual test files if they exist
        file(GLOB TEST_FILES "${TEST_DIR}/*.cpp")

        foreach(TEST_FILE ${TEST_FILES})
            get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
            add_executable(${TEST_NAME} ${TEST_FILE})
            target_include_directories(${TEST_NAME} PRIVATE ${INCLUDE_DIR})
            target_compile_options(${TEST_NAME} PRIVATE ${COMMON_WARNINGS})
            add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
            message(STATUS "  Added test: ${TEST_NAME}")
        endforeach()
    else()
        message(STATUS "Testing enabled but no test directory found")
    endif()
endif ()
