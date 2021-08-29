cmake_minimum_required(VERSION 3.16)
project(stdmap_mem_db)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../rocksdb_interface.cmake)
file(GLOB LIB_ART_MEM *.cc)
message(STATUS ${ROCKSDB_INTERFACE})
add_library(${PROJECT_NAME} SHARED ${ROCKSDB_INTERFACE} ${LIB_ART_MEM})
target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
