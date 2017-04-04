
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
// main

int
main(int argc, char **argv)
{
  const int N = 50;

  double *x = calloc(N, sizeof(*x));

  set_sine(x, N);
  write(x, N, "x.asc");

  free(x);
  
  return 0;
}
