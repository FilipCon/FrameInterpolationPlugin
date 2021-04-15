cmake_minimum_required(VERSION 3.2)
project(FrameInterpolation)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

# compilation database (completion)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -g")

set(DATA_DIR "${PROJECT_SOURCE_DIR}/data")
configure_file("${PROJECT_SOURCE_DIR}/Settings.h.in"
  "${PROJECT_SOURCE_DIR}/Settings.h")
set(CMAKE_EXTRA_INCLUDE_FILES)

# include directories
include_directories(.)
include_directories(${OpenCV_INCLUDE_DIRS})

# library files
file(GLOB includes *.h)
file(GLOB sources FrameInterpolation.cpp)

# create library
set(target FrameInterpolation)
add_library(
  ${target} SHARED
  ${sources}
  ${includes}
  )

# add tests
set(test testFrameInterpolation)
add_executable(${test} main.cpp)
target_link_libraries(${test} ${target} ${OpenCV_LIBS})
