cmake_minimum_required(VERSION 3.14)
project(CppSampleTest1)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Your include directory for test.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#  Add your sample program
add_library(SampleProgram
    ${CMAKE_CURRENT_SOURCE_DIR}/SampleProgram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pch.cpp
)

#  Add your test target
add_executable(UnitTests
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

#  Link test target with GoogleTest AND include directories
target_link_libraries(UnitTests
    SampleProgram
    gtest
    gtest_main
)

target_include_directories(UnitTests PRIVATE
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

#  Discover tests
include(GoogleTest)
gtest_discover_tests(UnitTests)
