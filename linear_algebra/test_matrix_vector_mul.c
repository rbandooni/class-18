
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the mat_vec_mult() function

int
main(int argc, char **argv)
{
  double A[N][N] = { { 1., 0., 0. },
		     { 0., 2., 0. },
		     { 0., 0., 3. }, };
  double x[N] = { 1., 2., 3. };
  double y[N];
  
  matrix_vector_mul(A, x, y);

  printf("result vector is y = [%g, %g, %g]\n", y[0], y[1], y[2]);
  assert(y[0] == 1.);
  assert(y[1] == 4.);
  assert(y[2] == 9.);

  return 0;
}
