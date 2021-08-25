cmake_minimum_required(VERSION 3.16)
project(not_supported_db)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../rocksdb_interface.cmake)
file(GLOB LIB_NOT_SUPPORTED_DB *.cc)
message(STATUS ${ROCKSDB_INTERFACE})
add_library(not_supported_db SHARED ${ROCKSDB_INTERFACE} ${LIB_NOT_SUPPORTED_DB})
target_include_directories(not_supported_db PUBLIC ../../include)
target_include_directories(not_supported_db PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
