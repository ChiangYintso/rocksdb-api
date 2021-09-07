#include "db_impl.h"
#include "rocksdb/db.h"
#include "rocksdb/status.h"

namespace ROCKSDB_NAMESPACE {
Status DB::Open(const Options& options, const std::string& name, DB** dbptr) {
  auto* impl = new ARTMemDBImpl(name);
  *dbptr = impl;
  return Status::OK();
}

}  // namespace ROCKSDB_NAMESPACE