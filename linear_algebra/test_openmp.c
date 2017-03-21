
#include <omp.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
#pragma omp parallel
  printf("Hi, I'm thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
  return 0;
}
