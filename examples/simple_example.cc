#include <cstdio>

#include "rocksdb/db.h"

int main() {
  puts("hello");
  using namespace rocksdb;
  Options options;
  DB* db = nullptr;
  Status s = DB::Open(options, "hello", &db);
  if (s.ok()) {
    puts(db->GetName().c_str());
  }
  return 0;
}