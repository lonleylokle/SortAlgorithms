cmake_minimum_required(VERSION 3.14)
project(SortAlgorithms)

if (WIN32)
    project(${PROJECT_NAME} LANGUAGES CXX)
elseif(UNIX)
    project(${PROJECT_NAME})
endif()

# Flags
set(CMAKE_CONFIGURATION_TYPES "Release")

# Directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

# Files
file(GLOB_RECURSE SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/*.inl"
)

# Executable
if (WIN32) 
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(${PROJECT_NAME} ${SOURCES})
endif()
 
