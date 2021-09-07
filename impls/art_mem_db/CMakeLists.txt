cmake_minimum_required(VERSION 3.16)
project(art_mem_db)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../rocksdb_interface.cmake)

include(FetchContent)

FetchContent_Declare(
        ART
        GIT_REPOSITORY ${GIT_REPO_PREFIX}/ChiangYintso/ART.git
        GIT_TAG main
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(ART)


file(GLOB LIB_NOT_SUPPORTED_DB *.cc)
message(STATUS ${ROCKSDB_INTERFACE})
add_library(${PROJECT_NAME} SHARED ${ROCKSDB_INTERFACE} ${LIB_NOT_SUPPORTED_DB})
target_link_libraries(${PROJECT_NAME} ART)
target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
