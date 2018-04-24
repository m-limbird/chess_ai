cmake_minimum_required(VERSION 2.6)
project(chess)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../executables)

# Use C++ 11
add_definitions(-std=c++11)

################################
# GTest
################################

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory( ${CMAKE_BINARY_DIR}/../devel/googletest-src
                  ${CMAKE_BINARY_DIR}/../devel/googletest-build
                  EXCLUDE_FROM_ALL )

################################
# Chess executable
################################
add_executable( chessboard
                src/chessboard.cpp
                src/robotic_chess_ai.cpp )

################################
# Unit Tests
################################
# Add test cpp file
add_executable( chessboard_unit_tests
                test/chessboard_test.cpp
                src/chessboard.cpp )

# Link test executable against gtest & gtest_main
target_link_libraries( chessboard_unit_tests 
                       gtest 
                       gtest_main )
add_dependencies( chessboard_unit_tests chessboard )

add_test( chessboard_unit_tests 
          chessboard_unit_tests )


