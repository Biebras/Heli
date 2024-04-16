cmake_minimum_required(VERSION 3.22)
project(Glad)

set(CMAKE_CXX_STANDARD 20)

# Specify the source files
set(GLAD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c")

# Specify the include directories
set(GLAD_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Add the library
add_library(glad STATIC ${GLAD_SOURCES})

# Specify the include directories for this library
target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIRS})
