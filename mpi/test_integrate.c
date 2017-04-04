
#include <stdio.h>
#include <math.h>

static double
f(double x)
{
  return sqrt(1. - x*x);
}

int
main(int argc, char **argv)
{
  const int N = 1000;
  double dx = 1. / N;

  double sum = 0.;
  for (int i = 0; i < N; i++) {
    double x0 = i * dx;
    double x1 = (i+1) * dx;
    sum += .5 * (f(x0) + f(x1)) * dx;
  }
  printf("sum = %g\n", sum);

  return 0;
}
