#!/bin/sh

curl -OL https://pd.zwc365.com/seturl/https://github.com/facebook/rocksdb/archive/refs/tags/v6.22.1.tar.gz
tar -xvf v6.22.1.tar.gz rocksdb-6.22.1/include/rocksdb --strip-components 1