
#include "linear_algebra.h"

#include <math.h>

static void
vector_init_sines(struct vector *crd, struct vector *v)
{
  for (int i = 0; i < v->n; i++) {
    float x = VEC(crd, i);
    VEC(v, i) = sin(x) + 1./3. * sin(3. * x);
  }
}

int
main(int argc, char **argv)
{
  const int N = 100;

  // node-centered coordinates
  struct vector *crd_nc = vector_create_crd_nc(N + 1, 2. * M_PI);

  // a sample function on the node-centered grid
  struct vector *x_nc = vector_create(N + 1);
  vector_init_sines(crd_nc, x_nc);
  vector_write(crd_nc, x_nc, "x_nc.asc");

  // cell-centered coordinates
  // There's one less cell center than there are nodes (N+1 -> N);
  struct vector *crd_cc = vector_create_crd_cc(N, 2. * M_PI);

  // the vector for our averaged-to-cell-centers result
  struct vector *x_cc = vector_create(N);

  vector_write(crd_cc, x_cc, "x_cc.asc");
}
