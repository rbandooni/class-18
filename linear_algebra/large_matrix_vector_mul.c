
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// setup_test_vectors

static void
setup_test_vectors(struct vector *x, struct vector *y_ref)
{
  for (int i = 0; i < x->n; i++) {
    VEC(x, i) = i;
  }

  for (int i = 0; i < y_ref->n; i++) {
    VEC(y_ref, i) = i * (i + 1);
  }
}

// ----------------------------------------------------------------------
// setup_test_matrix

static void
setup_test_matrix(struct matrix *A)
{
  // This test matrix is diagonal, which isn't really great,
  // a more general case would be better.
  // Then again, at least it makes finding the reference result easy
  for (int i = 0; i < A->m; i++) {
    for (int j = 0; j < A->n; j++) {
      if (i == j) {
        MAT(A, i, j) = i + 1;
      } else {
        MAT(A, i, j) = 0;
      }
    }
  }
}

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int
main(int argc, char **argv)
{
  const int N = 20000;
  double tbeg, tend;

  // set up matrix / vectors 
  tbeg = WTime(); 

  struct matrix *A = matrix_create(N, N);
  setup_test_matrix(A);

  struct vector *x = vector_create(N);
  struct vector *y = vector_create(N);
  struct vector *y_ref = vector_create(N);
  setup_test_vectors(x, y_ref);

  tend = WTime(); 
  printf("setup took %g sec\n", tend - tbeg); 

  // calculate y = Ax
  tbeg = WTime();
  matrix_vector_mul(A, x, y);
  tend = WTime(); 
  printf("matrix_vector_mul() took %g sec\n", tend - tbeg); 

  // check result against reference result
  tbeg = WTime();
  assert(vector_is_equal(y, y_ref));
  tend = WTime(); 
  printf("checking result took %g sec\n", tend - tbeg); 

  return 0;
}
