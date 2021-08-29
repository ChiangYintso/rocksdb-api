// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <cstdio>

#include "rocksdb/db.h"

int main() {
  using namespace rocksdb;
  Options options;
  DB* db = nullptr;
  Status s = DB::Open(options, "hello", &db);
  if (s.ok()) {
    puts(db->GetName().c_str());
    Status s1 = db->Put(WriteOptions(), "foo", "bar");
    std::string buf;
    Status s2 = db->Get(ReadOptions(), "abc", &buf);
    assert(s1.IsNotSupported());
    assert(s2.IsNotSupported());
  }
  return 0;
}