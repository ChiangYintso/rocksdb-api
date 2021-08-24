cmake_minimum_required(VERSION 3.16)
project(not_supported_db)

set(CMAKE_CXX_STANDARD 20)

file(GLOB LIB_NOT_SUPPORTED_DB *.cc)
add_library(not_supported_db SHARED ${LIB_NOT_SUPPORTED_DB})
target_include_directories(not_supported_db PUBLIC ../../include)
