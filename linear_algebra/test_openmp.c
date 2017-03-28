
#include <omp.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  printf("Hi, just starting\n");

#pragma omp parallel
  printf("Hi, I'm thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());

  printf("I'm about to be done.\n");
  return 0;
}
