#include "rocksdb/memtablerep.h"
#include "rocksdb/rocksdb_namespace.h"

namespace ROCKSDB_NAMESPACE {
MemTableRep* SkipListFactory::CreateMemTableRep(
    const MemTableRep::KeyComparator& compare, Allocator* allocator,
    const SliceTransform* transform, Logger* /*logger*/) {
  return nullptr;
}
}  // namespace ROCKSDB_NAMESPACE