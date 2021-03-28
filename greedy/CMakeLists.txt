cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME greedy)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/greedy)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/greedy SOURCES)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

add_definitions(-g)