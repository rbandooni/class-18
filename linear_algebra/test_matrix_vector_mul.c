
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
  double A[3][3] = { { 1., 0., 0. },
		     { 0., 2., 0. },
		     { 0., 0., 3. }, };
  struct vector *x = vector_create_and_set(3, (double[3]) { 1., 2., 3. });
  struct vector *y = vector_create(3);
  
  matrix_vector_mul(3, A, x->vals, y->vals);

  printf("result vector is y = [%g, %g, %g]\n", VEC(y, 0), VEC(y, 1), VEC(y, 2));
  assert(VEC(y, 0) == 1.);
  assert(VEC(y, 1) == 4.);
  assert(VEC(y, 2) == 9.);

  return 0;
}
