# Add operations library
add_library(operations INTERFACE)
add_library(expressions INTERFACE)
# Header-only types library 
add_library(types INTERFACE)
target_include_directories(types INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)  

# # Executable
# add_executable(expressions expressions.cpp)

# Link libraries
# target_link_libraries(expressions
#   operations
#   types)

# Include headers
# target_include_directories(expressions PRIVATE 
#   ${CMAKE_CURRENT_SOURCE_DIR}/include)