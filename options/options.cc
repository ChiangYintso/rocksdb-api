//  Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
//
// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "rocksdb/db.h"

namespace ROCKSDB_NAMESPACE {
AdvancedColumnFamilyOptions::AdvancedColumnFamilyOptions() {
  assert(memtable_factory.get() != nullptr);
}

DBOptions::DBOptions() {}
DBOptions::DBOptions(const Options& options)
    : DBOptions(*static_cast<const DBOptions*>(&options)) {}

ColumnFamilyOptions::ColumnFamilyOptions()
    : compression(kNoCompression),
      table_factory(std::shared_ptr<TableFactory>(nullptr)) {}

ReadOptions::ReadOptions()
    : snapshot(nullptr),
      iterate_lower_bound(nullptr),
      iterate_upper_bound(nullptr),
      readahead_size(0),
      max_skippable_internal_keys(0),
      read_tier(kReadAllTier),
      verify_checksums(true),
      fill_cache(true),
      tailing(false),
      managed(false),
      total_order_seek(false),
      auto_prefix_mode(false),
      prefix_same_as_start(false),
      pin_data(false),
      background_purge_on_iterator_cleanup(false),
      ignore_range_deletions(false),
      iter_start_seqnum(0),
      timestamp(nullptr),
      iter_start_ts(nullptr),
      deadline(std::chrono::microseconds::zero()),
      io_timeout(std::chrono::microseconds::zero()),
      value_size_soft_limit(std::numeric_limits<uint64_t>::max()) {}

}  // namespace ROCKSDB_NAMESPACE