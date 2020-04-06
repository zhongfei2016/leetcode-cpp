cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME leetcode-cpp)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/tree)
include_directories(${CMAKE_CURRENT_LIST_DIR}/list)
include_directories(${CMAKE_CURRENT_LIST_DIR}/dfs)
include_directories(${CMAKE_CURRENT_LIST_DIR}/bfs)
include_directories(${CMAKE_CURRENT_LIST_DIR}/LRU)
include_directories(${CMAKE_CURRENT_LIST_DIR}/dp)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/tree SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/list SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/dfs SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/bfs SOURCES)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/dp SOURCES)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

add_definitions(-g)