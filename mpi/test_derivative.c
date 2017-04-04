
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fld1d.h"

// ----------------------------------------------------------------------
// set_sine
//
// initializes the array x with the sine function

static void
set_sine(struct fld1d *x, int N)
{
  double dx = 2. * M_PI / N;

  for (int i = 0; i < N; i++) {
    double xx = i * dx;
    F1(x, i) = sin(xx);
  }
}

// ----------------------------------------------------------------------
// write
//
// writes the array to disk

static void
write(struct fld1d *x, int N, const char *filename)
{
  double dx = 2. * M_PI / N;
  FILE *f = fopen(filename, "w");

  for (int i = 0; i < N; i++) {
    double xx = i * dx;
    fprintf(f, "%g %g\n", xx, F1(x, i));
  }

  fclose(f);
}

// ----------------------------------------------------------------------
// fill_ghosts
//
// fills the ghost cells at either end of x

static void
fill_ghosts(struct fld1d *x, int N)
{
  F1(x, -1) = F1(x, N-1);
  F1(x,  N) = F1(x, 0  );
}

// ----------------------------------------------------------------------
// calc_derivative
//
// calculates a 2nd order centered difference approximation to the derivative

static void
calc_derivative(struct fld1d *d, struct fld1d *x, int N)
{
  fill_ghosts(x, N);

  double dx = 2. * M_PI / N;

  for (int i = 0; i < N; i++) {
    F1(d, i) = (F1(x, i+1) - F1(x, i-1)) / (2. * dx);
  }
}


// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  const int N = 50;

  struct fld1d *x = fld1d_create(-1, N + 1);
  struct fld1d *d = fld1d_create(0, N);

  set_sine(x, N);
  write(x, N, "x.asc");

  calc_derivative(d, x, N);
  write(d, N, "d.asc");

  fld1d_destroy(d);
  fld1d_destroy(x);

  return 0;
}
