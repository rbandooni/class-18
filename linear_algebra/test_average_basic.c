
#include "linear_algebra.h"

#include <math.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// calculate vector average (nc -> cc)

void
vector_average(float *cc, float *nc, int n)
{
#pragma omp parallel for
  for (int i = 0; i < n; i++) {
    cc[i] = .5 * (nc[i] + nc[i+1]);
  }
}

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  int N = 100;
  float x_nc[N+1];
  
  float dx = 2. * M_PI / N;
  for (int i = 0; i <= N; i++) {
    float x = i * dx;
    x_nc[i] = sin(x+1) + 1./3. * sin(3.*(x+1));
  }

  FILE *file = fopen("x_nc.asc", "w");
  for (int i = 0; i <= N; i++) {
    float x = i * dx;
    fprintf(file, "%g %g\n", x, x_nc[i]);
  }
  fclose(file);

  float x_cc[N];

  double tbeg = WTime();
  for (int i = 0; i < 1; i++) {
    vector_average(x_cc, x_nc, N);
  }
  double tend = WTime();
  printf("1x vector_average took %g s\n", tend - tbeg);

  file = fopen("x_cc.asc", "w");
  for (int i = 0; i < N; i++) {
    float x = (i + .5) * dx;
    fprintf(file, "%g %g\n", x, x_cc[i]);
  }
  fclose(file);
}
