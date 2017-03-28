
#include <mpi.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  int test = 0; 

  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  if (rank == 0) { 
    test = 99; 
  } 

  printf("Hello %d/%d test = %d\n", rank, size, test);

  MPI_Finalize();
  return 0;
}
  
