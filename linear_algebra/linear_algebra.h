
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

double vector_dot(int n, const double *x, const double *y);
void vector_add(int n, const double *x, const double *y, double *z);
void matrix_vector_mul(int n, const double A[][n], const double *x, double *y);

#endif
