// Copyright (c) Facebook, Inc. and its affiliates. (http://www.facebook.com)
#include "dcheck.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void checkFailed(const char *file, int line, const char *func, const char *expr,
                 ...) {
  std::fprintf(stderr, "%s:%d %s: %s: ", file, line, func, expr);
  va_list args;
  ::va_start(args, expr);
  const char *fmt = va_arg(args, const char *);
  std::vfprintf(stderr, fmt, args);
  ::va_end(args);
  std::fputc('\n', stderr);
  std::abort();
}

void checkIndexFailed(const char *file, int line, const char *func, word index,
                      word high) {
  std::fprintf(stderr, "%s:%d %s: index out of range, %ld not in [0..%ld) : \n",
               file, line, func, index, high);
  std::abort();
}

void checkBoundFailed(const char *file, int line, const char *func, word value,
                      word low, word high) {
  std::fprintf(stderr, "%s:%d %s: bounds violation, %ld not in [%ld..%ld] : \n",
               file, line, func, value, low, high);
  std::abort();
}
