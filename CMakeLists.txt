cmake_minimum_required(VERSION 3.22)
project(Heli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Sub-directories
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glad)
add_subdirectory(vendors/glm)

# Headers
include_directories(${PROJECT_SOURCE_DIR}/heli/include)

# Executables
add_executable(${PROJECT_NAME} main.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/graphics.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/camera.cpp 
    )
 
# Link libraries
target_link_libraries(${PROJECT_NAME} glfw glad glm)

