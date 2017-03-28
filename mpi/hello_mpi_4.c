
#include <mpi.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
  printf("Hi, just starting\n");
  
  MPI_Init(&argc, &argv);
  
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  printf("Hi, I'm process %d of %d!\n", rank, size);

  MPI_Finalize();

  printf("I'm about to be done.\n");
  return 0;
}


