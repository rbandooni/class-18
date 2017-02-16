
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_vector_mul
//
// calculate y = Ax,
// where x and y are vectors, and A is a matrix

void
matrix_vector_mul(double A[N][N], double *x, double *y)
{
  for (int i = 0; i < N; i++) {
    y[i] = 0.;
    for (int j = 0; j < N; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
}
