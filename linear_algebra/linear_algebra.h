
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// vector length (fixed)
#define N (3)

double vector_dot(double *x, double *y);
void vector_add(double *x, double *y, double *z);
void matrix_vector_mul(double A[N][N], double *x, double *y);

#endif
