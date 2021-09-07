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
    std::string foo("foo"), bar("bar");
    Status s1 = db->Put(WriteOptions(), foo.c_str(), bar.c_str());
    std::string buf;
    Status s2 = db->Get(ReadOptions(), foo.c_str(), &buf);
    assert(s1.ok());
    assert(s2.ok());
    assert(buf == bar);
  }
  return 0;
}
