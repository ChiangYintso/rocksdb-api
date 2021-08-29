#!/bin/sh

if [ ! -e "v6.22.1.tar.gz" ]; then
  curl -OL https://github.com/facebook/rocksdb/archive/refs/tags/v6.22.1.tar.gz
fi
tar -xvf v6.22.1.tar.gz rocksdb-6.22.1/include/rocksdb \
                        rocksdb-6.22.1/util/comparator.cc \
                        rocksdb-6.22.1/util/status.cc \
                        rocksdb-6.22.1/util/string_util.h \
                        --wildcards rocksdb-6.22.1/port \
                        --strip-components 1