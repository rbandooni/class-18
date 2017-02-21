
#include "linear_algebra.h"

#include <stdlib.h>

// ----------------------------------------------------------------------
// vector_create
//
// create a new vector of length "n"

struct vector *
vector_create(int n)
{
  struct vector *v = malloc(sizeof(*v));
  v->n = n;
  v->vals = calloc(n, sizeof(*v->vals));

  return v;
}

// ----------------------------------------------------------------------
// vector_create_and_set
//
// create a new vector of length "n", and set the values from "vals"

struct vector *
vector_create_and_set(int n, const double *vals)
{
  struct vector *v = vector_create(n);

  for (int i = 0; i < v->n; i++) {
    VEC(v, i) = vals[i];
  }

  return v;
}

// ----------------------------------------------------------------------
// vector_destroy
//
// destroys (deallocates) the vector "v"

void
vector_destroy(struct vector *v)
{
  free(v->vals);
  free(v);
}
