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
  ./src/StoryIO.cpp
  ./tests/testStoryIO.cpp
  
  ./tests/itemTests.cpp
  ./src/Key.cpp
  ./src/Weapon.cpp
  ./src/Item.cpp
  ./src/Consumable.cpp

  ./tests/testStory.cpp
  ./src/Story.cpp
  
  ./src/Level.cpp 
  ./tests/testLevel.cpp
  
  ./src/Container.cpp  
  ./tests/testContainer.cpp

  ./src/Entity.cpp
  
  ./tests/roomTests.cpp
  ./src/Room.cpp
  ./src/lockedRoom.cpp

  ./src/Enemy.cpp
  ./src/Rat.cpp
  ./src/Spider.cpp
  ./src/Zombie.cpp
  ./tests/testEnemy.cpp
  
  ./src/Player.cpp
  ./tests/testPlayerClass.cpp

)

target_link_libraries(runAllTests gmock gtest gtest_main)
