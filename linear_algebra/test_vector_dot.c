
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int
main(int argc, char **argv)
{
  double x_vals[3] = { 1., 2., 3. };
  double y_vals[3] = { 2., 3., 4. };
  struct vector x = { .n = 3, .vals = x_vals };
  struct vector y = { .n = 3, .vals = y_vals };

  printf("dot product is %g\n", vector_dot(3, x.vals, y.vals));
  assert(vector_dot(3, x.vals, y.vals) == 20.);

  return 0;
}
