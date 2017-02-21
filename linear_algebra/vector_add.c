
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// vector_add
//
// calculate z = x + y, for the vectors x, y, z

void
vector_add(int n, const double *x, const double *y, double *z)
{
  for (int i = 0; i < n; i++) {
    z[i] = x[i] + y[i];
  }
}
