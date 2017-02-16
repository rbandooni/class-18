
#include "linear_algebra.h"

#include <stdio.h>

// ----------------------------------------------------------------------
// main
//
// test the vec_add() function

int
main(int argc, char **argv)
{
  double x[N] = { 1., 2., 3. };
  double y[N] = { 2., 3., 4. };
  double z[N];

  vector_add(x, y, z);

  printf("sum vector is z = [%g, %g, %g]\n", z[0], z[1], z[2]);

  return 0;
}
