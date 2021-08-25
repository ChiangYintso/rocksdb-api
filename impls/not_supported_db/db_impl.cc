#include "db_impl.h"

namespace ROCKSDB_NAMESPACE {
Status NotSupportDBImpl::Put(const WriteOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, const Slice &value) {
  return Status::NotSupported();
}

Status NotSupportDBImpl::Delete(const WriteOptions &options,
                                ColumnFamilyHandle *column_family,
                                const Slice &key) {
  return Status::NotSupported();
}

Status NotSupportDBImpl::SingleDelete(const WriteOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice &key) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::Merge(const WriteOptions &options,
                               ColumnFamilyHandle *column_family,
                               const Slice &key, const Slice &value) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::Write(const WriteOptions &options,
                               WriteBatch *updates) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::Get(const ReadOptions &options,
                             ColumnFamilyHandle *column_family,
                             const Slice &key, PinnableSlice *value) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetMergeOperands(
    const ReadOptions &options, ColumnFamilyHandle *column_family,
    const Slice &key, PinnableSlice *merge_operands,
    GetMergeOperandsOptions *get_merge_operands_options,
    int *number_of_operands) {
  return Status::NotSupported();
}
std::vector<Status> NotSupportDBImpl::MultiGet(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_family,
    const std::vector<Slice> &keys, std::vector<std::string> *values) {
  return std::vector<Status>();
}
Iterator *NotSupportDBImpl::NewIterator(const ReadOptions &options,
                                        ColumnFamilyHandle *column_family) {
  return nullptr;
}
Status NotSupportDBImpl::NewIterators(
    const ReadOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families,
    std::vector<Iterator *> *iterators) {
  return Status::NotSupported();
}
const Snapshot *NotSupportDBImpl::GetSnapshot() { return nullptr; }
void NotSupportDBImpl::ReleaseSnapshot(const Snapshot *snapshot) {}
bool NotSupportDBImpl::GetProperty(ColumnFamilyHandle *column_family,
                                   const Slice &property, std::string *value) {
  return false;
}
bool NotSupportDBImpl::GetMapProperty(
    ColumnFamilyHandle *column_family, const Slice &property,
    std::map<std::string, std::string> *value) {
  return false;
}
bool NotSupportDBImpl::GetIntProperty(ColumnFamilyHandle *column_family,
                                      const Slice &property, uint64_t *value) {
  return false;
}
bool NotSupportDBImpl::GetAggregatedIntProperty(const Slice &property,
                                                uint64_t *value) {
  return false;
}
Status NotSupportDBImpl::GetApproximateSizes(
    const SizeApproximationOptions &options, ColumnFamilyHandle *column_family,
    const Range *ranges, int n, uint64_t *sizes) {
  return Status::NotSupported();
}
void NotSupportDBImpl::GetApproximateMemTableStats(
    ColumnFamilyHandle *column_family, const Range &range,
    uint64_t *const count, uint64_t *const size) {}
Status NotSupportDBImpl::CompactRange(const CompactRangeOptions &options,
                                      ColumnFamilyHandle *column_family,
                                      const Slice *begin, const Slice *end) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::SetDBOptions(
    const std::unordered_map<std::string, std::string> &new_options) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::CompactFiles(
    const CompactionOptions &compact_options, ColumnFamilyHandle *column_family,
    const std::vector<std::string> &input_file_names, const int output_level,
    const int output_path_id, std::vector<std::string> *const output_file_names,
    CompactionJobInfo *compaction_job_info) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::PauseBackgroundWork() {
  return Status::NotSupported();
}
Status NotSupportDBImpl::ContinueBackgroundWork() {
  return Status::NotSupported();
}
Status NotSupportDBImpl::EnableAutoCompaction(
    const std::vector<ColumnFamilyHandle *> &column_family_handles) {
  return Status::NotSupported();
}
void NotSupportDBImpl::DisableManualCompaction() {}
void NotSupportDBImpl::EnableManualCompaction() {}
int NotSupportDBImpl::NumberLevels(ColumnFamilyHandle *column_family) {
  return 0;
}
int NotSupportDBImpl::MaxMemCompactionLevel(ColumnFamilyHandle *column_family) {
  return 0;
}
int NotSupportDBImpl::Level0StopWriteTrigger(
    ColumnFamilyHandle *column_family) {
  return 0;
}

const std::string &NotSupportDBImpl::GetName() const { return dbname_; }

Env *NotSupportDBImpl::GetEnv() const { return nullptr; }
Options NotSupportDBImpl::GetOptions(ColumnFamilyHandle *column_family) const {
  return Options();
}
DBOptions NotSupportDBImpl::GetDBOptions() const { return DBOptions(); }
Status NotSupportDBImpl::Flush(const FlushOptions &options,
                               ColumnFamilyHandle *column_family) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::Flush(
    const FlushOptions &options,
    const std::vector<ColumnFamilyHandle *> &column_families) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::SyncWAL() { return Status::NotSupported(); }
SequenceNumber NotSupportDBImpl::GetLatestSequenceNumber() const { return 0; }
bool NotSupportDBImpl::SetPreserveDeletesSequenceNumber(SequenceNumber seqnum) {
  return false;
}
Status NotSupportDBImpl::DisableFileDeletions() {
  return Status::NotSupported();
}
Status NotSupportDBImpl::EnableFileDeletions(bool force) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetLiveFiles(std::vector<std::string> &vector,
                                      uint64_t *manifest_file_size,
                                      bool flush_memtable) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetSortedWalFiles(VectorLogPtr &files) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetCurrentWalFile(
    std::unique_ptr<LogFile> *current_log_file) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetCreationTimeOfOldestFile(uint64_t *creation_time) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetUpdatesSince(
    SequenceNumber seq_number, std::unique_ptr<TransactionLogIterator> *iter,
    const TransactionLogIterator::ReadOptions &read_options) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::DeleteFile(std::string name) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetLiveFilesChecksumInfo(
    FileChecksumList *checksum_list) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::IngestExternalFile(
    ColumnFamilyHandle *column_family,
    const std::vector<std::string> &external_files,
    const IngestExternalFileOptions &options) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::IngestExternalFiles(
    const std::vector<IngestExternalFileArg> &args) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::CreateColumnFamilyWithImport(
    const ColumnFamilyOptions &options, const std::string &column_family_name,
    const ImportColumnFamilyOptions &import_options,
    const ExportImportFilesMetaData &metadata, ColumnFamilyHandle **handle) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::VerifyChecksum(const ReadOptions &read_options) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetDbIdentity(std::string &identity) const {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetDbSessionId(std::string &session_id) const {
  return Status::NotSupported();
}
ColumnFamilyHandle *NotSupportDBImpl::DefaultColumnFamily() const {
  return nullptr;
}
Status NotSupportDBImpl::GetPropertiesOfAllTables(
    ColumnFamilyHandle *column_family, TablePropertiesCollection *props) {
  return Status::NotSupported();
}
Status NotSupportDBImpl::GetPropertiesOfTablesInRange(
    ColumnFamilyHandle *column_family, const Range *range, std::size_t n,
    TablePropertiesCollection *props) {
  return Status::NotSupported();
}

}  // namespace ROCKSDB_NAMESPACE
