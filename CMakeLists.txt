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
include_directories(${PROJECT_SOURCE_DIR}/vendors/stb)

# Executables
add_executable(${PROJECT_NAME} main.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/graphics.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/quad.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/camera.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/circle.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/rectangle.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/shapes.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/texture.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/resources.cpp 
    ${PROJECT_SOURCE_DIR}/heli/src/graphics/sprite.cpp 

    ${PROJECT_SOURCE_DIR}/heli/src/core/event_manager.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/core/game.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/core/game_object.cpp

    ${PROJECT_SOURCE_DIR}/heli/src/physics/collider.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/physics/collider_manager.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/physics/rectangle_collider.cpp
    ${PROJECT_SOURCE_DIR}/heli/src/physics/circle_collider.cpp
    )
 
# Link libraries
target_link_libraries(${PROJECT_NAME} glfw glad glm)

