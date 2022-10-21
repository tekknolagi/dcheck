# [dcheck](https://github.com/tekknolagi/dcheck)

This very small assert library provides `assert`-like macros for checking
conditions at runtime. It works with C and C++.

Improvements over raw `assert`:

* Semantic checks for indices, bounds, ranges, unimplemented features, and
  unreachable states
* Includes `printf`-compatible error message formatting
* `NDEBUG` and always-on variants
* Bounds/index checking built-in
* File/function/line number and symbolized condition code in error message
* Still checks code for compiler errors if DCHECK is turned off

Here is some sample code:

```c
#include "dcheck.h"

int main() {
  // ...

  CHECK(true, "thank goodness");

  int arr[3];
  // Array index won't crash
  CHECK_INDEX(ind, 3);

  // Still can order off the kids menu
  CHECK_BOUND(age, 5);

  // Month is valid
  CHECK_RANGE(month, 1, 12);

  if (needs_feature) {
    UNIMPLEMENTED("needs Brian's feature");
  }

  if (val == 4) {
    UNREACHABLE("unexpected number %d", val);
  }

  // ...
}
```

Add `D` before `CHECK`, `CHECK_INDEX`, `CHECK_BOUND`, and `CHECK_RANGE` if you
want the check to go away in `NDEBUG` mode. Like `DCHECK_INDEX` and so forth.

Happy hacking.

## Use in CMake projects

```cmake
include(FetchContent)
FetchContent_Declare(
  dcheck
  GIT_REPOSITORY https://github.com/tekknolagi/dcheck
  GIT_TAG        trunk
)
FetchContent_MakeAvailable(dcheck)
target_include_directories(your_target_name_here PRIVATE ${dcheck_SOURCE_DIR})
```
