#include <stdio.h>
#include "did_it_in_c/looping.h"
#include "did_it_in_c/macros.h"

void looping(void) {
  int nums[] = {1, 1, 2, 3, 5, 8};

  // The above ARRAY_SIZE macro uses sizeof. The sizeof function returns a
  // size_t integer which is defined as being an unsigned integer type. So we
  // can safely and portably assign it to an unsigned int.
  for (unsigned int i = 0; i < ARRAY_SIZE(nums); ++i) {
    // The u placeholder causes printf to expect an unsigned int.  Another
    // option would be to declare i as a size_t type integer and use %zd to
    // specifically expect a size_t integer, but the z modifier is not supported
    // by all compilers.
    printf("%u ", nums[i]);
  }
  printf("\n");
}
