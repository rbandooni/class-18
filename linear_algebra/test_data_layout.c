
#include <stdio.h>

#define N 3
#define M 4

void
print_matrix(double A[N][M])
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf(" %02g", A[i][j]);
    }
    printf("\n");
  }
}

int
main(int argc, char **argv)
{
  double A[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      A[i][j] = i * 10 + j;
    }
  }

  printf("print_matrix:\n");
  print_matrix(A);
  printf("\n");

  return 0;
}
