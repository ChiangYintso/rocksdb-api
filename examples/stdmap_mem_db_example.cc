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
    Status s = db->Put(WriteOptions(), "foo", "bar");
    assert(s.ok());
    s = db->Put(WriteOptions(), "foo", "bbbb");
    assert(s.IsOkOverwritten());

    std::string buf;
    s = db->Get(ReadOptions(), "abc", &buf);
    assert(s.IsNotFound());

    s = db->Get(ReadOptions(), "foo", &buf);
    assert(s.ok());
    assert(buf.size() == 4);

    s = db->Delete(WriteOptions(), "foo");
    assert(s.ok());

    s = db->Get(ReadOptions(), "foo", &buf);
    assert(s.IsNotFound());

  }
  return 0;
}
