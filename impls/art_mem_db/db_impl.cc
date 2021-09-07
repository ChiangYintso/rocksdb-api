#include "db_impl.h"

namespace ROCKSDB_NAMESPACE {
Status ARTMemDBImpl::Put(const WriteOptions &options,
                         ColumnFamilyHandle *column_family, const Slice &key,
                         const Slice &value) {
  art_insert(&art_, (const unsigned char *)key.data(), key.size(),
             (void *)value.data());
  return Status::OK();
}

Status ARTMemDBImpl::Delete(const WriteOptions &options,
                            ColumnFamilyHandle *column_family,
                            const Slice &key) {
  art_delete(&art_, (const unsigned char *)key.data(), key.size());
  return Status::OK();
}

Status ARTMemDBImpl::SingleDelete(const WriteOptions &options,
                                  ColumnFamilyHandle *column_family,
                                  const Slice &key) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::Merge(const WriteOptions &options,
                           ColumnFamilyHandle *column_family, const Slice &key,
                           const Slice &value) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::Write(const WriteOptions &options, WriteBatch *updates) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::Get(const ReadOptions &options,
                         ColumnFamilyHandle *column_family, const Slice &key,
                         PinnableSlice *value) {
  void *v = art_get(&art_, reinterpret_cast<const unsigned char *>(key.data()),
                    key.size());
  value->GetSelf()->assign((const char *)v);
  return Status::OK();
}

Status ARTMemDBImpl::GetMergeOperands(
    const ReadOptions &options, ColumnFamilyHandle *column_family,
    const Slice &key, PinnableSlice *merge_operands,
    GetMergeOperandsOptions *get_merge_operands_options,
    int *number_of_operands) {
  return Status::NotSupported();
}
std::vector<Status> ARTMemDBImpl::MultiGet(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_family,
    const std::vector<Slice> &keys, std::vector<std::string> *values) {
  return std::vector<Status>();
}

Iterator *ARTMemDBImpl::NewIterator(const ReadOptions &options,
                                    ColumnFamilyHandle *column_family) {
  return nullptr;
}

Status ARTMemDBImpl::NewIterators(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families,
    std::vector<Iterator *> *iterators) {
  return Status::NotSupported();
}
const Snapshot *ARTMemDBImpl::GetSnapshot() { return nullptr; }
void ARTMemDBImpl::ReleaseSnapshot(const Snapshot *snapshot) {}
bool ARTMemDBImpl::GetProperty(ColumnFamilyHandle *column_family,
                               const Slice &property, std::string *value) {
  return false;
}
bool ARTMemDBImpl::GetMapProperty(ColumnFamilyHandle *column_family,
                                  const Slice &property,
                                  std::map<std::string, std::string> *value) {
  return false;
}
bool ARTMemDBImpl::GetIntProperty(ColumnFamilyHandle *column_family,
                                  const Slice &property, uint64_t *value) {
  return false;
}
bool ARTMemDBImpl::GetAggregatedIntProperty(const Slice &property,
                                            uint64_t *value) {
  return false;
}
Status ARTMemDBImpl::GetApproximateSizes(
    const SizeApproximationOptions &options, ColumnFamilyHandle *column_family,
    const Range *ranges, int n, uint64_t *sizes) {
  return Status::NotSupported();
}
void ARTMemDBImpl::GetApproximateMemTableStats(
    ColumnFamilyHandle *column_family, const Range &range,
    uint64_t *const count, uint64_t *const size) {}
Status ARTMemDBImpl::CompactRange(const CompactRangeOptions &options,
                                  ColumnFamilyHandle *column_family,
                                  const Slice *begin, const Slice *end) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::SetDBOptions(
    const std::unordered_map<std::string, std::string> &new_options) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::CompactFiles(
    const CompactionOptions &compact_options, ColumnFamilyHandle *column_family,
    const std::vector<std::string> &input_file_names, const int output_level,
    const int output_path_id, std::vector<std::string> *const output_file_names,
    CompactionJobInfo *compaction_job_info) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::PauseBackgroundWork() { return Status::NotSupported(); }
Status ARTMemDBImpl::ContinueBackgroundWork() { return Status::NotSupported(); }
Status ARTMemDBImpl::EnableAutoCompaction(
    const std::vector<ColumnFamilyHandle *> &column_family_handles) {
  return Status::NotSupported();
}
void ARTMemDBImpl::DisableManualCompaction() {}
void ARTMemDBImpl::EnableManualCompaction() {}
int ARTMemDBImpl::NumberLevels(ColumnFamilyHandle *column_family) { return 0; }
int ARTMemDBImpl::MaxMemCompactionLevel(ColumnFamilyHandle *column_family) {
  return 0;
}
int ARTMemDBImpl::Level0StopWriteTrigger(ColumnFamilyHandle *column_family) {
  return 0;
}

const std::string &ARTMemDBImpl::GetName() const { return dbname_; }

Env *ARTMemDBImpl::GetEnv() const { return nullptr; }
Options ARTMemDBImpl::GetOptions(ColumnFamilyHandle *column_family) const {
  return Options();
}
DBOptions ARTMemDBImpl::GetDBOptions() const { return DBOptions(); }
Status ARTMemDBImpl::Flush(const FlushOptions &options,
                           ColumnFamilyHandle *column_family) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::Flush(
    const FlushOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::SyncWAL() { return Status::NotSupported(); }
SequenceNumber ARTMemDBImpl::GetLatestSequenceNumber() const { return 0; }
bool ARTMemDBImpl::SetPreserveDeletesSequenceNumber(SequenceNumber seqnum) {
  return false;
}
Status ARTMemDBImpl::DisableFileDeletions() { return Status::NotSupported(); }
Status ARTMemDBImpl::EnableFileDeletions(bool force) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::GetLiveFiles(std::vector<std::string> &vector,
                                  uint64_t *manifest_file_size,
                                  bool flush_memtable) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::GetSortedWalFiles(VectorLogPtr &files) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::GetCurrentWalFile(
    std::unique_ptr<LogFile> *current_log_file) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::GetCreationTimeOfOldestFile(uint64_t *creation_time) {
  return Status::NotSupported();
}
Status ARTMemDBImpl::GetUpdatesSince(
    SequenceNumber seq_number, std::unique_ptr<TransactionLogIterator> *iter,
    const TransactionLogIterator::ReadOptions &read_options) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::DeleteFile(std::string name) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::GetLiveFilesChecksumInfo(FileChecksumList *checksum_list) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::IngestExternalFile(
    ColumnFamilyHandle *column_family,
    const std::vector<std::string> &external_files,
    const IngestExternalFileOptions &options) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::IngestExternalFiles(
    const std::vector<IngestExternalFileArg> &args) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::CreateColumnFamilyWithImport(
    const ColumnFamilyOptions &options, const std::string &column_family_name,
    const ImportColumnFamilyOptions &import_options,
    const ExportImportFilesMetaData &metadata, ColumnFamilyHandle **handle) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::VerifyChecksum(const ReadOptions &read_options) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::GetDbIdentity(std::string &identity) const {
  return Status::NotSupported();
}

Status ARTMemDBImpl::GetDbSessionId(std::string &session_id) const {
  return Status::NotSupported();
}

ColumnFamilyHandle *ARTMemDBImpl::DefaultColumnFamily() const {
  return nullptr;
}

Status ARTMemDBImpl::GetPropertiesOfAllTables(
    ColumnFamilyHandle *column_family, TablePropertiesCollection *props) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::GetPropertiesOfTablesInRange(
    ColumnFamilyHandle *column_family, const Range *range, std::size_t n,
    TablePropertiesCollection *props) {
  return Status::NotSupported();
}

Status ARTMemDBImpl::IterValue(art_iter_value_callback cb, void *data) {
  art_iter_value(&art_, cb, data);
  return Status::OK();
}

}  // namespace ROCKSDB_NAMESPACE
