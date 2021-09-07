// Copyright (c) 2021, Jiang Yinzuo. All rights reserved.

#include <algorithm>
#include "db_iter.h"

rocksdb::StdMapDBIter::StdMapDBIter(
    const std::shared_ptr<std::map<Slice, Slice, stdmap_mem_db::SliceComparator>>& m)
    : map_(m) {
  iterator_ = m->begin();
}

bool rocksdb::StdMapDBIter::Valid() const { return iterator_ != map_->end(); }

void rocksdb::StdMapDBIter::SeekToFirst() {
  iterator_ = map_->begin();
}

void rocksdb::StdMapDBIter::SeekToLast() {
  iterator_ = --map_->end();
}

void rocksdb::StdMapDBIter::Seek(const rocksdb::Slice& target) {
  iterator_ = map_->lower_bound(target);
}

void rocksdb::StdMapDBIter::SeekForPrev(const rocksdb::Slice& target) {
  iterator_ = map_->upper_bound(target);
}

void rocksdb::StdMapDBIter::Next() {
  ++iterator_;
}

void rocksdb::StdMapDBIter::Prev() {
  --iterator_;
}

rocksdb::Slice rocksdb::StdMapDBIter::key() const { return iterator_->first; }

rocksdb::Slice rocksdb::StdMapDBIter::value() const { return iterator_->second; }

rocksdb::Status rocksdb::StdMapDBIter::status() const { return Status::OK(); }
