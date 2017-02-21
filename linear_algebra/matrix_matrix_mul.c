
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_matrix_mul
//
// performs the matrix-matrix multiplication C = A B
// A: 1st input matrix (m x k matrix)
// B: 2nd input matrix (k x n matrix)
// C: result (m x n matrix)

void
matrix_matrix_mul(const struct matrix *A, const struct matrix *B, struct matrix *C)
{
  for (int i = 0; i < C->m; i++) {
    for (int j = 0; j < C->n; j++) {
      MAT(C, i, j) = 0.;
      for (int k = 0; k < C->m; k++) {
	MAT(C, i, j) += MAT(A, i, k) * MAT(B, k, j);
      }
    }
  }
}

