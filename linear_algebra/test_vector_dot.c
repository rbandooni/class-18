
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
  double x[3] = { 1., 2., 3. };
  double y[3] = { 2., 3., 4. };

  printf("dot product is %g\n", vector_dot(3, x, y));
  assert(vector_dot(3, x, y) == 20.);

  return 0;
}
