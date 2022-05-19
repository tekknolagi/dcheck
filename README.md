# [DCHECK](https://github.com/tekknolagi/dcheck)

This very small assert library provides assert-like macros for checking
conditions at runtime.

Improvements over raw `assert`:

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

Happy hacking.
