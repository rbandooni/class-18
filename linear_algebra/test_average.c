
#include "linear_algebra.h"

#include <math.h>

// ----------------------------------------------------------------------
// vector_average
//
// calculates a cell-centered representation from a node-centered
// representation by averaging adjacent values

static void
vector_average(struct vector *x_cc, struct vector *x_nc)
{
  assert(x_nc->n == x_cc->n + 1);
#pragma omp parallel for
  for (int i = 0; i < x_cc->n; i++) {
    VEC(x_cc, i) = .5 * (VEC(x_nc, i) + VEC(x_nc, i+1));
  }
}

// ----------------------------------------------------------------------
// vector_init_sines

static void
vector_init_sines(struct vector *crd, struct vector *v)
{
  for (int i = 0; i < v->n; i++) {
    float x = VEC(crd, i);
    VEC(v, i) = sin(x+1) + 1./3. * sin(3. * (x+1));
  }
}

// ----------------------------------------------------------------------
// main

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

  double tbeg = WTime();
  for (int i = 0; i < 1; i++) {
    vector_average(x_cc, x_nc);
  }
  double tend = WTime();
  printf("1 vector_average took %g s\n", tend - tbeg);


  vector_write(crd_cc, x_cc, "x_cc.asc");
}
