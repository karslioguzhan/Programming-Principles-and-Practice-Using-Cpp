cmake_minimum_required(VERSION 3.30)

# Project Definition
project(
    Programming-Principles-and-Practice-Using-Cpp
    VERSION 1.0
    LANGUAGES CXX
)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Get all subdirectories (excluding hidden and non-directories)
file(GLOB CHILD_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */)

# Get all subdirectories (excluding hidden and non-directories)
file(GLOB CHILD_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */)

# Find all CMakeLists.txt files in subdirectories (recursive)
file(GLOB_RECURSE SUBDIR_CMAKELISTS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)

foreach(cmakelists ${SUBDIR_CMAKELISTS})
    # Get the parent directory (relative path)
    get_filename_component(subdir ${cmakelists} DIRECTORY)

    # Skip self if needed
    if("${subdir}" STREQUAL ".")
        continue()
    endif()

    message(STATUS "Adding subdirectory: ${subdir}")
    add_subdirectory(${subdir})
endforeach()
