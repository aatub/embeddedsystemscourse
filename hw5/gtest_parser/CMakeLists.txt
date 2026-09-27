cmake_minimum_required(VERSION 3.14)
project(TimeParserTestProject)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  TimeParserTest
  TimeParser.cpp
  test_cases/TimeParserTest.cpp
)

target_link_libraries(
  TimeParserTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TimeParserTest)
