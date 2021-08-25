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
    assert(s.IsNotSupported());
  }
  return 0;
}