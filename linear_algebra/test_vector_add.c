
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vec_add() function

int
main(int argc, char **argv)
{
  struct vector *x = vector_create_and_set(3, (double[3]) { 1., 2., 3. });
  struct vector *y = vector_create_and_set(3, (double[3]) { 2., 3., 4. });
  struct vector *z = vector_create(3);

  vector_add(x, y, z);

  printf("sum vector is z = [%g, %g, %g]\n", VEC(z, 0), VEC(z, 1), VEC(z, 2));
  assert(VEC(z, 0) == 3.);
  assert(VEC(z, 1) == 5.);
  assert(VEC(z, 2) == 7.);

  return 0;
}
