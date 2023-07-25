# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(FMapper)

# C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add source and tests subdirectories 
add_subdirectory(src)
add_subdirectory(tests)
set(CTEST_INCLUDE_PATH "${CMAKE_CURRENT_BINARY_DIR}/tests")  
include(CTest)


add_executable(main main.cpp)

target_link_libraries(main 
  operations
  expressions
)

target_include_directories(main PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)