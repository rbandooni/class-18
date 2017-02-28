
#include "config.h"

#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_vector_mul_fortran

#define matrix_vector_mul_F77 F77_FUNC_(matrix_vector_mul,MATRIX_VECTOR_MUL)

void matrix_vector_mul_F77(int *m, int *n, double *A, double *x, double *y);

void
matrix_vector_mul_fortran(const struct matrix *A, const struct vector *x, struct vector *y)
{
#ifndef MATRIX_FORTRAN_ORDER
  fprintf(stderr, "ERROR: matrix_vector_mul_fortran can only be used if matrices\n"
	  "are stored in Fortran order\n");
  assert(0);
#endif

  int m = A->m, n = A->n;
  matrix_vector_mul_F77(&m, &n, A->vals, x->vals, y->vals);
}

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
