
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ----------------------------------------------------------------------
// set_sine
//
// initializes the array x with the sine function

static void
set_sine(double *x, int N)
{
  double dx = 2. * M_PI / N;

  for (int i = 0; i < N; i++) {
    double xx = i * dx;
    x[i] = sin(xx);
  }
}

// ----------------------------------------------------------------------
// write
//
// writes the array to disk

static void
write(double *x, int N, const char *filename)
{
  double dx = 2. * M_PI / N;
  FILE *f = fopen(filename, "w");

  for (int i = 0; i < N; i++) {
    double xx = i * dx;
    fprintf(f, "%g %g\n", xx, x[i]);
  }

  fclose(f);
}

// ----------------------------------------------------------------------
// calc_derivative
//
// calculates a 2nd order centered difference approximation to the derivative

static void
calc_derivative(double *d, double *x, int N)
{
  double dx = 2. * M_PI / N;

  for (int i = 1; i < N - 1; i++) {
    d[i] = (x[i+1] - x[i-1]) / (2. * dx);
  }
}


// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  const int N = 50;

  double *x = calloc(N, sizeof(*x));
  double *d = calloc(N, sizeof(*x));

  set_sine(x, N);
  write(x, N, "x.asc");

  calc_derivative(d, x, N);
  write(d, N, "d.asc");

  free(d);
  free(x);
  
  return 0;
}
