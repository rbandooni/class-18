
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
  struct vector *z_ref = vector_create_and_set(3, (double[3]) { 3., 5., 7. });

  vector_add(x, y, z);

  printf("sum vector is z = ");
  vector_print(z);
  printf("\n");

  // check result agains reference result
  assert(vector_is_equal(z, z_ref));

  return 0;
}
