cmake_minimum_required(VERSION 3.22)
project(Heli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sub-directories
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glad)

# Executables
add_executable(${PROJECT_NAME} main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw glad)

