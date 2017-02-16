
#include "linear_algebra.h"

#include <stdio.h>

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

  return 0;
}
