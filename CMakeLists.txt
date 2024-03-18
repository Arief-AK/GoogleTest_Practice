cmake_minimum_required(VERSION 3.14)
project(GoogleTestProject VERSION 0.1.0 LANGUAGES C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(CTest)
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(include)
add_executable(GoogleTestProject main.cpp include/MathFunctions.cpp tests/basic_tests.cpp)
target_link_libraries(GoogleTestProject PUBLIC GTest::gtest_main MathLib DataStruct)

include(GoogleTest)
gtest_discover_tests(GoogleTestProject)