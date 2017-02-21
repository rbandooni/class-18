
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
  struct vector *x = vector_create_and_set(3, x_vals);
  struct vector *y = vector_create_and_set(3, y_vals);

  printf("dot product is %g\n", vector_dot(x, y));
  assert(vector_dot(x, y) == 20.);

  vector_destroy(x);
  vector_destroy(y);

  return 0;
}
