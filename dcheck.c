// Copyright (c) Facebook, Inc. and its affiliates. (http://www.facebook.com)
#include "dcheck.h"

#include <execinfo.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void checkFailed(const char *file, int line, const char *func, const char *expr,
                 ...) {
#define BACKTRACE_MAX 10
  void *buffer[BACKTRACE_MAX];
  int nptrs = backtrace(buffer, BACKTRACE_MAX);
  char **symbols = backtrace_symbols(buffer, nptrs);
  if (symbols != NULL) {
    for (int i = nptrs-1; i >= 0; i--) {
      fprintf(stderr, "%s\n", symbols[i]);
    }
    fprintf(stderr, "(most recent call last)\n");
  }
  free(symbols);
#undef BACKTRACE_MAX
  fprintf(stderr, "%s:%d %s: %s: ", file, line, func, expr);
  va_list args;
  va_start(args, expr);
  const char *fmt = va_arg(args, const char *);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fputc('\n', stderr);
  abort();
}

void checkIndexFailed(const char *file, int line, const char *func, intptr_t index,
                      intptr_t high) {
  fprintf(stderr, "%s:%d %s: index out of range, %ld not in [0..%ld) : \n",
          file, line, func, index, high);
  abort();
}

void checkBoundFailed(const char *file, int line, const char *func, intptr_t value,
                      intptr_t low, intptr_t high) {
  fprintf(stderr, "%s:%d %s: bounds violation, %ld not in [%ld..%ld] : \n",
          file, line, func, value, low, high);
  abort();
}
