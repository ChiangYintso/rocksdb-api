#include "db_impl.h"


namespace ROCKSDB_NAMESPACE {
Status StdMapMemDBImpl::Put(const WriteOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, const Slice &value) {

  auto [iterator, inserted] = map_.insert_or_assign(key, value);
  return inserted ? Status::OK() : Status::OkOverwritten();
}

Status StdMapMemDBImpl::Delete(const WriteOptions &options,
                                ColumnFamilyHandle *column_family,
                                const Slice &key) {
  map_.erase(key);
  return Status::OK();
}

Status StdMapMemDBImpl::SingleDelete(const WriteOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice &key) {
  return Status::NotSupported();
}

Status StdMapMemDBImpl::Merge(const WriteOptions &options,
                               ColumnFamilyHandle *column_family,
                               const Slice &key, const Slice &value) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::Write(const WriteOptions &options,
                               WriteBatch *updates) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::Get(const ReadOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, PinnableSlice *value) {
  auto it = map_.find(key);
  if (it == map_.end()) {
    return Status::NotFound();
  }

  value->GetSelf()->assign(it->second.data(), it->second.size());
  return Status::OK();
}

Status StdMapMemDBImpl::GetMergeOperands(
    const ReadOptions &options, ColumnFamilyHandle *column_family,
    const Slice &key, PinnableSlice *merge_operands,
    GetMergeOperandsOptions *get_merge_operands_options,
    int *number_of_operands) {
  return Status::NotSupported();
}

std::vector<Status> StdMapMemDBImpl::MultiGet(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_family,
    const std::vector<Slice> &keys, std::vector<std::string> *values) {
  return std::vector<Status>();
}
Iterator *StdMapMemDBImpl::NewIterator(const ReadOptions &options,
                                        ColumnFamilyHandle *column_family) {
  return nullptr;
}
Status StdMapMemDBImpl::NewIterators(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families,
    std::vector<Iterator *> *iterators) {
  return Status::NotSupported();
}
const Snapshot *StdMapMemDBImpl::GetSnapshot() { return nullptr; }
void StdMapMemDBImpl::ReleaseSnapshot(const Snapshot *snapshot) {}
bool StdMapMemDBImpl::GetProperty(ColumnFamilyHandle *column_family,
                                   const Slice &property, std::string *value) {
  return false;
}
bool StdMapMemDBImpl::GetMapProperty(
    ColumnFamilyHandle *column_family, const Slice &property,
    std::map<std::string, std::string> *value) {
  return false;
}
bool StdMapMemDBImpl::GetIntProperty(ColumnFamilyHandle *column_family,
                                      const Slice &property, uint64_t *value) {
  return false;
}
bool StdMapMemDBImpl::GetAggregatedIntProperty(const Slice &property,
                                                uint64_t *value) {
  return false;
}
Status StdMapMemDBImpl::GetApproximateSizes(
    const SizeApproximationOptions &options, ColumnFamilyHandle *column_family,
    const Range *ranges, int n, uint64_t *sizes) {
  return Status::NotSupported();
}
void StdMapMemDBImpl::GetApproximateMemTableStats(
    ColumnFamilyHandle *column_family, const Range &range,
    uint64_t *const count, uint64_t *const size) {}
Status StdMapMemDBImpl::CompactRange(const CompactRangeOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice *begin, const Slice *end) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::SetDBOptions(
    const std::unordered_map<std::string, std::string> &new_options) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::CompactFiles(
    const CompactionOptions &compact_options, ColumnFamilyHandle *column_family,
    const std::vector<std::string> &input_file_names, const int output_level,
    const int output_path_id, std::vector<std::string> *const output_file_names,
    CompactionJobInfo *compaction_job_info) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::PauseBackgroundWork() {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::ContinueBackgroundWork() {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::EnableAutoCompaction(
    const std::vector<ColumnFamilyHandle *> &column_family_handles) {
  return Status::NotSupported();
}
void StdMapMemDBImpl::DisableManualCompaction() {}
void StdMapMemDBImpl::EnableManualCompaction() {}
int StdMapMemDBImpl::NumberLevels(ColumnFamilyHandle *column_family) {
  return 0;
}
int StdMapMemDBImpl::MaxMemCompactionLevel(ColumnFamilyHandle *column_family) {
  return 0;
}
int StdMapMemDBImpl::Level0StopWriteTrigger(
    ColumnFamilyHandle *column_family) {
  return 0;
}

const std::string &StdMapMemDBImpl::GetName() const { return dbname_; }

Env *StdMapMemDBImpl::GetEnv() const { return nullptr; }
Options StdMapMemDBImpl::GetOptions(ColumnFamilyHandle *column_family) const {
  return Options();
}
DBOptions StdMapMemDBImpl::GetDBOptions() const { return DBOptions(); }
Status StdMapMemDBImpl::Flush(const FlushOptions &options,
                               ColumnFamilyHandle *column_family) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::Flush(
    const FlushOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::SyncWAL() { return Status::NotSupported(); }
SequenceNumber StdMapMemDBImpl::GetLatestSequenceNumber() const { return 0; }
bool StdMapMemDBImpl::SetPreserveDeletesSequenceNumber(SequenceNumber seqnum) {
  return false;
}
Status StdMapMemDBImpl::DisableFileDeletions() {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::EnableFileDeletions(bool force) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetLiveFiles(std::vector<std::string> &vector,
                                      uint64_t *manifest_file_size,
                                      bool flush_memtable) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetSortedWalFiles(VectorLogPtr &files) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetCurrentWalFile(
    std::unique_ptr<LogFile> *current_log_file) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetCreationTimeOfOldestFile(uint64_t *creation_time) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetUpdatesSince(
    SequenceNumber seq_number, std::unique_ptr<TransactionLogIterator> *iter,
    const TransactionLogIterator::ReadOptions &read_options) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::DeleteFile(std::string name) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetLiveFilesChecksumInfo(
    FileChecksumList *checksum_list) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::IngestExternalFile(
    ColumnFamilyHandle *column_family,
    const std::vector<std::string> &external_files,
    const IngestExternalFileOptions &options) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::IngestExternalFiles(
    const std::vector<IngestExternalFileArg> &args) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::CreateColumnFamilyWithImport(
    const ColumnFamilyOptions &options, const std::string &column_family_name,
    const ImportColumnFamilyOptions &import_options,
    const ExportImportFilesMetaData &metadata, ColumnFamilyHandle **handle) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::VerifyChecksum(const ReadOptions &read_options) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetDbIdentity(std::string &identity) const {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetDbSessionId(std::string &session_id) const {
  return Status::NotSupported();
}
ColumnFamilyHandle *StdMapMemDBImpl::DefaultColumnFamily() const {
  return nullptr;
}
Status StdMapMemDBImpl::GetPropertiesOfAllTables(
    ColumnFamilyHandle *column_family, TablePropertiesCollection *props) {
  return Status::NotSupported();
}
Status StdMapMemDBImpl::GetPropertiesOfTablesInRange(
    ColumnFamilyHandle *column_family, const Range *range, std::size_t n,
    TablePropertiesCollection *props) {
  return Status::NotSupported();
}

}  // namespace ROCKSDB_NAMESPACE
