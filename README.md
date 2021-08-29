# RocksDB Interface

[![CircleCI](https://circleci.com/gh/ChiangYintso/rocksdb-interface/tree/main.svg?style=svg)](https://circleci.com/gh/ChiangYintso/rocksdb-interface/tree/main)

This repository contains public interface of [RocksDB 6.22.1](https://github.com/facebook/rocksdb/releases/tag/v6.22.1).
The project structure is as the same as RocksDB.  

`impls` directory contains two implementation of RocksDB's interface.

## Build Steps

1. download rocksdb's source code
```shell
./fetch_rocksdb_src.sh
```
2. build with [CMake](https://cmake.org/)
```shell
mkdir build && cd build
cmake ..
cmake --build .
```

3. run example executable
```shell
./examples/stdmap_mem_db_example
```
