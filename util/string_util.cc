//  Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
//

#include "util/string_util.h"

#include <cstring>
#include <string>
#include "rocksdb/rocksdb_namespace.h"

#ifndef __has_cpp_attribute
#define ROCKSDB_HAS_CPP_ATTRIBUTE(x) 0
#else
#define ROCKSDB_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#endif

#if ROCKSDB_HAS_CPP_ATTRIBUTE(maybe_unused) && __cplusplus >= 201703L
#define ROCKSDB_MAYBE_UNUSED [[maybe_unused]]
#elif ROCKSDB_HAS_CPP_ATTRIBUTE(gnu::unused) || __GNUC__
#define ROCKSDB_MAYBE_UNUSED [[gnu::unused]]
#else
#define ROCKSDB_MAYBE_UNUSED
#endif

namespace ROCKSDB_NAMESPACE {

// Copied from folly/string.cpp:
// https://github.com/facebook/folly/blob/0deef031cb8aab76dc7e736f8b7c22d701d5f36b/folly/String.cpp#L457
// There are two variants of `strerror_r` function, one returns
// `int`, and another returns `char*`. Selecting proper version using
// preprocessor macros portably is extremely hard.
//
// For example, on Android function signature depends on `__USE_GNU` and
// `__ANDROID_API__` macros (https://git.io/fjBBE).
//
// So we are using C++ overloading trick: we pass a pointer of
// `strerror_r` to `invoke_strerror_r` function, and C++ compiler
// selects proper function.

#if !(defined(_WIN32) && (defined(__MINGW32__) || defined(_MSC_VER)))
ROCKSDB_MAYBE_UNUSED
static std::string invoke_strerror_r(int (*strerror_r)(int, char*, size_t),
                                     int err, char* buf, size_t buflen) {
  // Using XSI-compatible strerror_r
  int r = strerror_r(err, buf, buflen);

  // OSX/FreeBSD use EINVAL and Linux uses -1 so just check for non-zero
  if (r != 0) {
    snprintf(buf, buflen, "Unknown error %d (strerror_r failed with error %d)",
             err, errno);
  }
  return buf;
}

ROCKSDB_MAYBE_UNUSED
static std::string invoke_strerror_r(char* (*strerror_r)(int, char*, size_t),
                                     int err, char* buf, size_t buflen) {
  // Using GNU strerror_r
  return strerror_r(err, buf, buflen);
}
#endif  // !(defined(_WIN32) && (defined(__MINGW32__) || defined(_MSC_VER)))

std::string errnoStr(int err) {
  char buf[1024];
  buf[0] = '\0';

  std::string result;

  // https://developer.apple.com/library/mac/documentation/Darwin/Reference/ManPages/man3/strerror_r.3.html
  // http://www.kernel.org/doc/man-pages/online/pages/man3/strerror.3.html
#if defined(_WIN32) && (defined(__MINGW32__) || defined(_MSC_VER))
  // mingw64 has no strerror_r, but Windows has strerror_s, which C11 added
  // as well. So maybe we should use this across all platforms (together
  // with strerrorlen_s). Note strerror_r and _s have swapped args.
  int r = strerror_s(buf, sizeof(buf), err);
  if (r != 0) {
    snprintf(buf, sizeof(buf),
             "Unknown error %d (strerror_r failed with error %d)", err, errno);
  }
  result.assign(buf);
#else
  // Using any strerror_r
  result.assign(invoke_strerror_r(strerror_r, err, buf, sizeof(buf)));
#endif

  return result;
}
}