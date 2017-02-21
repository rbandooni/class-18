
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
  struct vector *x = vector_create_and_set(2, (double[2]) { 1., 2. });
  struct vector *y = vector_create_and_set(2, (double[2]) { 2., 3. });
  struct vector *z = vector_create(2);
  struct vector *z_ref = vector_create_and_set(2, (double[2]) { 3., 5. });

  vector_add(x, y, z);

  printf("sum vector is z = [%g, %g, %g]\n", VEC(z, 0), VEC(z, 1), VEC(z, 2));

  // check result agains reference result
  assert(vector_is_equal(z, z_ref));

  return 0;
}
