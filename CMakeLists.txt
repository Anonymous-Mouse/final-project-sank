project(protject-sank)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_subdirectory(${CMAKE_SOURCE_DIR}/tests/googletest)

include_directories(
  ${CMAKE_SOURCE_DIR}/tests/googletest/googletest/include/
  ${CMAKE_SOURCE_DIR}/tests/googletest/googlemock/include/
  ${CMAKE_SOURCE_DIR}/header
)



add_executable(runAllTests
  ./src/enemy.cpp
  ./src/rat.cpp
  ./src/spider.cpp
  ./src/zombie.cpp
  ./tests/testEnemy.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)