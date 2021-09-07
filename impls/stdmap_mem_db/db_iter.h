// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#pragma once

#include <map>
#include <memory>

#include "db_impl.h"
#include "rocksdb/iterator.h"

namespace ROCKSDB_NAMESPACE {
class StdMapDBIter final : public Iterator {
 public:
  explicit StdMapDBIter(
      const std::shared_ptr<std::map<Slice, Slice, stdmap_mem_db::SliceComparator>>&
          m);
  bool Valid() const override;
  void SeekToFirst() override;
  void SeekToLast() override;
  void Seek(const Slice& target) override;
  void SeekForPrev(const Slice& target) override;
  void Next() override;
  void Prev() override;
  Slice key() const override;
  Slice value() const override;
  Status status() const override;

 private:
  std::shared_ptr<std::map<Slice, Slice, stdmap_mem_db::SliceComparator>> map_;
  std::_Rb_tree_iterator<std::pair<const Slice, Slice>> iterator_;
};
}  // namespace ROCKSDB_NAMESPACE