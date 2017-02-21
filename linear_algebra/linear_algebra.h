
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

double vector_dot(int n, double *x, double *y);
void vector_add(int n, double *x, double *y, double *z);
void matrix_vector_mul(int n, double A[][n], double *x, double *y);

#endif
