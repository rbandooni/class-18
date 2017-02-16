#include <stdio.h>

// vector length (fixed)

#define N (3)

// ----------------------------------------------------------------------
// vector_dot
//
// returns the dot product of the two vectors
// x: first vector
// y: second vector

double
vector_dot(double *x, double *y)
{
  double sum = 0.f;
  for (int i = 0; i < N; i++) {
    sum += x[i] * y[i];
  }
  return sum;
}

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int
main(int argc, char **argv)
{
  double x[N] = { 1., 2., 3. };
  double y[N] = { 2., 3., 4. };

  printf("dot product is %g\n", vector_dot(x, y));

  return 0;
}
