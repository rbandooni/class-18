
#include "mpi_debug.h"

#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

static double
f(double x)
{
  return sqrt(1. - x*x);
}

int
main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  const int N = 1000;
  double dx = 1. / N;

  assert(N % size == 0);
  int n = N / size;
  int ib = rank * n, ie = (rank + 1) * n;

  double sum = 0.;
  for (int i = ib; i < ie; i++) {
    double x0 = i * dx;
    double x1 = (i+1) * dx;
    sum += .5 * (f(x0) + f(x1)) * dx;
  }
  mprintf("sum = %g\n", sum);

  MPI_Finalize();
  return 0;
}
