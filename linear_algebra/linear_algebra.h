
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>
#include <assert.h>

#define BOUNDS_CHECK

// ----------------------------------------------------------------------
// struct vector

struct vector {
  double *vals;
  int n;
};

#ifdef BOUNDS_CHECK
#define VEC(v, i) (*({				\
	assert((i) >= 0 && (i) < (v)->n);	\
	&((v)->vals[(i)]);			\
      }))
#else
#define VEC(v, i) ((v)->vals[i])
#endif

struct vector *vector_create(int n);
struct vector *vector_create_and_set(int n, const double *vals);
void vector_destroy(struct vector *v);
double vector_dot(const struct vector *x, const struct vector *y);
void vector_add(const struct vector *x, const struct vector *y, struct vector *z);
bool vector_is_equal(const struct vector *x, const struct vector *y);
void matrix_vector_mul(int n, const double A[][n], const double *x, double *y);

#endif
