
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_vector_mul
//
// calculate y = Ax,
// where x and y are vectors, and A is a matrix

void
matrix_vector_mul(int n, double A[][n], double *x, double *y)
{
  for (int i = 0; i < n; i++) {
    y[i] = 0.;
    for (int j = 0; j < n; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
}
