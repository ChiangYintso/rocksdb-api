#pragma once

#include "rocksdb/db.h"

namespace stdmap_mem_db {
struct SliceComparator {
  bool operator()(const ROCKSDB_NAMESPACE::Slice &s1,
                  const ROCKSDB_NAMESPACE::Slice &s2) const {
    int result = s1.compare(s2);
    return result < 0;
  }
};
}  // namespace stdmap_mem_db

namespace ROCKSDB_NAMESPACE {
class StdMapMemDBImpl : public DB {
 public:
  explicit StdMapMemDBImpl(const std::string &dbname) : dbname_(dbname) {}

  ~StdMapMemDBImpl() override = default;

  Status Put(const WriteOptions &options, ColumnFamilyHandle *column_family,
             const Slice &key, const Slice &value) override;

  Status Delete(const WriteOptions &options, ColumnFamilyHandle *column_family,
                const Slice &key) override;

  Status SingleDelete(const WriteOptions &options,
                      ColumnFamilyHandle *column_family,
                      const Slice &key) override;

  Status Merge(const WriteOptions &options, ColumnFamilyHandle *column_family,
               const Slice &key, const Slice &value) override;
  Status Write(const WriteOptions &options, WriteBatch *updates) override;
  Status Get(const ReadOptions &options, ColumnFamilyHandle *column_family,
             const Slice &key, PinnableSlice *value) override;
  Status GetMergeOperands(const ReadOptions &options,
                          ColumnFamilyHandle *column_family, const Slice &key,
                          PinnableSlice *merge_operands,
                          GetMergeOperandsOptions *get_merge_operands_options,
                          int *number_of_operands) override;
  std::vector<Status> MultiGet(
      const ReadOptions &options,
      const std::vector<ColumnFamilyHandle *> &column_family,
      const std::vector<Slice> &keys,
      std::vector<std::string> *values) override;
  Iterator *NewIterator(const ReadOptions &options,
                        ColumnFamilyHandle *column_family) override;
  Status NewIterators(const ReadOptions &options,
                      const std::vector<ColumnFamilyHandle *> &column_families,
                      std::vector<Iterator *> *iterators) override;
  const Snapshot *GetSnapshot() override;
  void ReleaseSnapshot(const Snapshot *snapshot) override;
  bool GetProperty(ColumnFamilyHandle *column_family, const Slice &property,
                   std::string *value) override;
  bool GetMapProperty(ColumnFamilyHandle *column_family, const Slice &property,
                      std::map<std::string, std::string> *value) override;
  bool GetIntProperty(ColumnFamilyHandle *column_family, const Slice &property,
                      uint64_t *value) override;
  bool GetAggregatedIntProperty(const Slice &property,
                                uint64_t *value) override;
  Status GetApproximateSizes(const SizeApproximationOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Range *ranges, int n,
                             uint64_t *sizes) override;
  void GetApproximateMemTableStats(ColumnFamilyHandle *column_family,
                                   const Range &range, uint64_t *const count,
                                   uint64_t *const size) override;
  Status CompactRange(const CompactRangeOptions &options,
                      ColumnFamilyHandle *column_family, const Slice *begin,
                      const Slice *end) override;
  Status SetDBOptions(
      const std::unordered_map<std::string, std::string> &new_options) override;
  Status CompactFiles(const CompactionOptions &compact_options,
                      ColumnFamilyHandle *column_family,
                      const std::vector<std::string> &input_file_names,
                      const int output_level, const int output_path_id,
                      std::vector<std::string> *const output_file_names,
                      CompactionJobInfo *compaction_job_info) override;
  Status PauseBackgroundWork() override;
  Status ContinueBackgroundWork() override;
  Status EnableAutoCompaction(
      const std::vector<ColumnFamilyHandle *> &column_family_handles) override;
  void DisableManualCompaction() override;
  void EnableManualCompaction() override;
  int NumberLevels(ColumnFamilyHandle *column_family) override;
  int MaxMemCompactionLevel(ColumnFamilyHandle *column_family) override;
  int Level0StopWriteTrigger(ColumnFamilyHandle *column_family) override;
  const std::string &GetName() const override;
  Env *GetEnv() const override;
  Options GetOptions(ColumnFamilyHandle *column_family) const override;
  DBOptions GetDBOptions() const override;
  Status Flush(const FlushOptions &options,
               ColumnFamilyHandle *column_family) override;
  Status Flush(
      const FlushOptions &options,
      const std::vector<ColumnFamilyHandle *> &column_families) override;
  Status SyncWAL() override;
  SequenceNumber GetLatestSequenceNumber() const override;
  bool SetPreserveDeletesSequenceNumber(SequenceNumber seqnum) override;
  Status DisableFileDeletions() override;
  Status EnableFileDeletions(bool force) override;
  Status GetLiveFiles(std::vector<std::string> &vector,
                      uint64_t *manifest_file_size,
                      bool flush_memtable) override;
  Status GetSortedWalFiles(VectorLogPtr &files) override;
  Status GetCurrentWalFile(std::unique_ptr<LogFile> *current_log_file) override;
  Status GetCreationTimeOfOldestFile(uint64_t *creation_time) override;
  Status GetUpdatesSince(
      SequenceNumber seq_number, std::unique_ptr<TransactionLogIterator> *iter,
      const TransactionLogIterator::ReadOptions &read_options) override;
  Status DeleteFile(std::string name) override;
  Status GetLiveFilesChecksumInfo(FileChecksumList *checksum_list) override;
  Status IngestExternalFile(ColumnFamilyHandle *column_family,
                            const std::vector<std::string> &external_files,
                            const IngestExternalFileOptions &options) override;
  Status IngestExternalFiles(
      const std::vector<IngestExternalFileArg> &args) override;
  Status CreateColumnFamilyWithImport(
      const ColumnFamilyOptions &options, const std::string &column_family_name,
      const ImportColumnFamilyOptions &import_options,
      const ExportImportFilesMetaData &metadata,
      ColumnFamilyHandle **handle) override;
  Status VerifyChecksum(const ReadOptions &read_options) override;
  Status GetDbIdentity(std::string &identity) const override;
  Status GetDbSessionId(std::string &session_id) const override;
  ColumnFamilyHandle *DefaultColumnFamily() const override;
  Status GetPropertiesOfAllTables(ColumnFamilyHandle *column_family,
                                  TablePropertiesCollection *props) override;
  Status GetPropertiesOfTablesInRange(
      ColumnFamilyHandle *column_family, const Range *range, std::size_t n,
      TablePropertiesCollection *props) override;

 protected:
  const std::string dbname_;

 private:
  std::map<Slice, Slice, stdmap_mem_db::SliceComparator> map_;
};

}  // namespace ROCKSDB_NAMESPACE