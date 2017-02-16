
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// vector_add
//
// calculate z = x + y, for the vectors x, y, z

void
vector_add(double *x, double *y, double *z)
{
  for (int i = 0; i < N; i++) {
    z[i] = x[i] + y[i];
  }
}
