# NOTE: FetchContent is available in 3.11+
# NOTE: FetchContent at version 3.14 checks for local copies of dependent libraries

cmake_minimum_required(VERSION 3.14)
project(maze)

# Default build type to "Release"
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build" FORCE)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

# External libraries:
# -- Raylib ---------------------------------------------------
set(RAYLIB_VERSION 6.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)

if (NOT raylib_FOUND)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_MakeAvailable(raylib) # can check if locally available.
endif()

# -- Raygui ---------------------------------------------------
set(RAYGUI_VERSION 4.0)
FetchContent_Declare(
  raygui
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL https://github.com/raysan5/raygui/archive/refs/tags/${RAYGUI_VERSION}.tar.gz
)
FetchContent_MakeAvailable(raygui)
# ---------------------------------------------------------------

# Executable configuration
add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/grid.cpp
  src/generator.cpp
  src/renderer.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(
  ${PROJECT_NAME} PRIVATE 
  ${raygui_SOURCE_DIR}/src
  include
)