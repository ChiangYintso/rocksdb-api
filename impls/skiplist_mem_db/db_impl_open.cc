#include "db_impl.h"
#include "rocksdb/db.h"
#include "rocksdb/status2.h"

namespace ROCKSDB_NAMESPACE {
Status DB::Open(const Options& options, const std::string& name, DB** dbptr) {
  auto* impl = new NotSupportDBImpl(name);
  *dbptr = impl;
  return Status::OK();
}

}  // namespace ROCKSDB_NAMESPACE