enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing

# Test executable
add_executable(add_test add_test.cpp)


# Link libraries
target_link_libraries(add_test 
  GTest::gtest_main
  operations)

target_include_directories(add_test PRIVATE 
  ${CMAKE_SOURCE_DIR}/include
)


add_executable(expressions_test expressions_test.cpp)

target_link_libraries(expressions_test 
  GTest::gtest_main
  operations
  expressions
)

target_include_directories(expressions_test PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)
# Discover tests  
include(GoogleTest)
gtest_discover_tests(add_test)
gtest_discover_tests(expressions_test)