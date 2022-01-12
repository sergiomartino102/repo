cmake_minimum_required(VERSION 3.20)

# Definitions
set(PROJECT_NAME_STR project)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/target")

# Project title and define versioning
project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

# Include paths
set(PROJECT_INCLUDES ${PROJECT_INCLUDES} ${PROJECT_SOURCE_DIR}/src/)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Unit tests
add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS} ${PROJECT_INCLUDES})

# Build
set(SOURCE_FILES runner.cpp ${INC_FILES} ${SRC_FILES})
add_executable(${PROJECT_NAME_STR} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME_STR} ${Boost_LIBRARIES})
