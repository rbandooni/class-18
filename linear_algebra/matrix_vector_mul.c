
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_vector_mul
//
// calculate y = Ax,
// where x and y are vectors, and A is a matrix

void
matrix_vector_mul(const struct matrix *A, const struct vector *x, struct vector *y)
{
  for (int i = 0; i < A->m; i++) {
    VEC(y, i) = 0.;
    for (int j = 0; j < A->n; j++) {
      VEC(y, i) += MAT(A, i, j) * VEC(x, j);
    }
  }
}
