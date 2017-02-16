
#include "linear_algebra.h"

#include <stdio.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int
main(int argc, char **argv)
{
  double x[N] = { 1., 2., 3. };
  double y[N] = { 2., 3., 4. };

  printf("dot product is %g\n", vector_dot(x, y));

  return 0;
}
