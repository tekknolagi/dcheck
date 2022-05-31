#include "dcheck.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void some_function() {
  // TODO(TaskId): As soon as Brian finishes the hoozywhatsit, write this
  // function
  UNIMPLEMENTED("needs Brian's feature");
}

bool is_even(int val) {
  switch (val) {
  case 0:
  case 2:
  case 4:
    return true;
  case 1:
  case 3:
  case 5:
    return false;
  }
  UNREACHABLE("unexpected number %d", val);
}

// ./a.out ind age month should_call val
// Try: ./a.out 2 4 8 false 3
// ...then try making ind bigger than 3
// ...then try making age bigger than 5
// ...then try making month bigger than 12 or less than 0
// ...then try making should_call true
// ...then try making val bigger than 5
int main(int argc, char **argv) {
  CHECK(argc == 6, "Got the wrong number of args (%d)", argc);

  long ind = atol(argv[1]);
  long age = atol(argv[2]);
  long month = atol(argv[3]);
  bool should_call = strcmp(argv[4], "false") == 0 ? false : true;
  long val = atol(argv[5]);

  int arr[3];
  // Array index won't crash
  CHECK_INDEX(ind, 3);

  // Still can order off the kids menu
  CHECK_BOUND(age, 5);

  // Month is valid
  CHECK_RANGE(month, 1, 12);

  if (should_call) {
    some_function();
  }

  is_even(val);
}
