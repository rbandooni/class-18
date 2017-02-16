
#include "factorial.h"

#include <assert.h>

int
main(int argc, char **argv)
{
  assert(factorial(4) == 24);
  assert(factorial(1) == 1);
  assert(factorial(0) == 1);
  // we don't have a good way to handle negative arguments, so we don't.
  // Hence it doesn't make sense to test these case, either. FIXME

  return 0;
}

