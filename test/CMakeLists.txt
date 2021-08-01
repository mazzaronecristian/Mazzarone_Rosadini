cmake_minimum_required(VERSION 3.5)
add_subdirectory(./lib/googletest/)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TileTest.cpp Player1Test.cpp BulletTest.cpp)
add_executable(runAllGameTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllGameTests gtest gtest_main ../core sfml-graphics sfml-window sfml-system)