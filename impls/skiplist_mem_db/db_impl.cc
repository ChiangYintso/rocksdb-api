#include "db_impl.h"

namespace ROCKSDB_NAMESPACE {
Status SkiplistMemDBImpl::Put(const WriteOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, const Slice &value) {
  return Status::NotSupported();
}

Status SkiplistMemDBImpl::Delete(const WriteOptions &options,
                                ColumnFamilyHandle *column_family,
                                const Slice &key) {
  return Status::NotSupported();
}

Status SkiplistMemDBImpl::SingleDelete(const WriteOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice &key) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::Merge(const WriteOptions &options,
                               ColumnFamilyHandle *column_family,
                               const Slice &key, const Slice &value) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::Write(const WriteOptions &options,
                               WriteBatch *updates) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::Get(const ReadOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, PinnableSlice *value) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetMergeOperands(
    const ReadOptions &options, ColumnFamilyHandle *column_family,
    const Slice &key, PinnableSlice *merge_operands,
    GetMergeOperandsOptions *get_merge_operands_options,
    int *number_of_operands) {
  return Status::NotSupported();
}
std::vector<Status> SkiplistMemDBImpl::MultiGet(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_family,
    const std::vector<Slice> &keys, std::vector<std::string> *values) {
  return std::vector<Status>();
}
Iterator *SkiplistMemDBImpl::NewIterator(const ReadOptions &options,
                                        ColumnFamilyHandle *column_family) {
  return nullptr;
}
Status SkiplistMemDBImpl::NewIterators(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families,
    std::vector<Iterator *> *iterators) {
  return Status::NotSupported();
}
const Snapshot *SkiplistMemDBImpl::GetSnapshot() { return nullptr; }
void SkiplistMemDBImpl::ReleaseSnapshot(const Snapshot *snapshot) {}
bool SkiplistMemDBImpl::GetProperty(ColumnFamilyHandle *column_family,
                                   const Slice &property, std::string *value) {
  return false;
}
bool SkiplistMemDBImpl::GetMapProperty(
    ColumnFamilyHandle *column_family, const Slice &property,
    std::map<std::string, std::string> *value) {
  return false;
}
bool SkiplistMemDBImpl::GetIntProperty(ColumnFamilyHandle *column_family,
                                      const Slice &property, uint64_t *value) {
  return false;
}
bool SkiplistMemDBImpl::GetAggregatedIntProperty(const Slice &property,
                                                uint64_t *value) {
  return false;
}
Status SkiplistMemDBImpl::GetApproximateSizes(
    const SizeApproximationOptions &options, ColumnFamilyHandle *column_family,
    const Range *ranges, int n, uint64_t *sizes) {
  return Status::NotSupported();
}
void SkiplistMemDBImpl::GetApproximateMemTableStats(
    ColumnFamilyHandle *column_family, const Range &range,
    uint64_t *const count, uint64_t *const size) {}
Status SkiplistMemDBImpl::CompactRange(const CompactRangeOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice *begin, const Slice *end) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::SetDBOptions(
    const std::unordered_map<std::string, std::string> &new_options) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::CompactFiles(
    const CompactionOptions &compact_options, ColumnFamilyHandle *column_family,
    const std::vector<std::string> &input_file_names, const int output_level,
    const int output_path_id, std::vector<std::string> *const output_file_names,
    CompactionJobInfo *compaction_job_info) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::PauseBackgroundWork() {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::ContinueBackgroundWork() {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::EnableAutoCompaction(
    const std::vector<ColumnFamilyHandle *> &column_family_handles) {
  return Status::NotSupported();
}
void SkiplistMemDBImpl::DisableManualCompaction() {}
void SkiplistMemDBImpl::EnableManualCompaction() {}
int SkiplistMemDBImpl::NumberLevels(ColumnFamilyHandle *column_family) {
  return 0;
}
int SkiplistMemDBImpl::MaxMemCompactionLevel(ColumnFamilyHandle *column_family) {
  return 0;
}
int SkiplistMemDBImpl::Level0StopWriteTrigger(
    ColumnFamilyHandle *column_family) {
  return 0;
}

const std::string &SkiplistMemDBImpl::GetName() const { return dbname_; }

Env *SkiplistMemDBImpl::GetEnv() const { return nullptr; }
Options SkiplistMemDBImpl::GetOptions(ColumnFamilyHandle *column_family) const {
  return Options();
}
DBOptions SkiplistMemDBImpl::GetDBOptions() const { return DBOptions(); }
Status SkiplistMemDBImpl::Flush(const FlushOptions &options,
                               ColumnFamilyHandle *column_family) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::Flush(
    const FlushOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::SyncWAL() { return Status::NotSupported(); }
SequenceNumber SkiplistMemDBImpl::GetLatestSequenceNumber() const { return 0; }
bool SkiplistMemDBImpl::SetPreserveDeletesSequenceNumber(SequenceNumber seqnum) {
  return false;
}
Status SkiplistMemDBImpl::DisableFileDeletions() {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::EnableFileDeletions(bool force) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetLiveFiles(std::vector<std::string> &vector,
                                      uint64_t *manifest_file_size,
                                      bool flush_memtable) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetSortedWalFiles(VectorLogPtr &files) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetCurrentWalFile(
    std::unique_ptr<LogFile> *current_log_file) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetCreationTimeOfOldestFile(uint64_t *creation_time) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetUpdatesSince(
    SequenceNumber seq_number, std::unique_ptr<TransactionLogIterator> *iter,
    const TransactionLogIterator::ReadOptions &read_options) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::DeleteFile(std::string name) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetLiveFilesChecksumInfo(
    FileChecksumList *checksum_list) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::IngestExternalFile(
    ColumnFamilyHandle *column_family,
    const std::vector<std::string> &external_files,
    const IngestExternalFileOptions &options) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::IngestExternalFiles(
    const std::vector<IngestExternalFileArg> &args) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::CreateColumnFamilyWithImport(
    const ColumnFamilyOptions &options, const std::string &column_family_name,
    const ImportColumnFamilyOptions &import_options,
    const ExportImportFilesMetaData &metadata, ColumnFamilyHandle **handle) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::VerifyChecksum(const ReadOptions &read_options) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetDbIdentity(std::string &identity) const {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetDbSessionId(std::string &session_id) const {
  return Status::NotSupported();
}
ColumnFamilyHandle *SkiplistMemDBImpl::DefaultColumnFamily() const {
  return nullptr;
}
Status SkiplistMemDBImpl::GetPropertiesOfAllTables(
    ColumnFamilyHandle *column_family, TablePropertiesCollection *props) {
  return Status::NotSupported();
}
Status SkiplistMemDBImpl::GetPropertiesOfTablesInRange(
    ColumnFamilyHandle *column_family, const Range *range, std::size_t n,
    TablePropertiesCollection *props) {
  return Status::NotSupported();
}

}  // namespace ROCKSDB_NAMESPACE
