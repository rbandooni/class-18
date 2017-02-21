
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// vector_add
//
// calculate z = x + y, for the vectors x, y, z

void
vector_add(const struct vector *x, const struct vector *y, struct vector *z)
{
  for (int i = 0; i < x->n; i++) {
    VEC(z, i) = VEC(x, i) + VEC(y, i);
  }
}
