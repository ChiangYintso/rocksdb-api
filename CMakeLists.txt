cmake_minimum_required(VERSION 3.16)
project(rocksdb-interface)

add_subdirectory(impls/not_supported_db)
add_subdirectory(impls/stdmap_mem_db)
add_subdirectory(impls/art_mem_db)
add_subdirectory(examples)