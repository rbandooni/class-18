
#include "linear_algebra.h"

#define N (3)

// ----------------------------------------------------------------------
// vector_dot
//
// returns the dot product of the two vectors
// x: first vector
// y: second vector

double
vector_dot(int n, double *x, double *y)
{
  double sum = 0.f;
  for (int i = 0; i < n; i++) {
    sum += x[i] * y[i];
  }
  return sum;
}

