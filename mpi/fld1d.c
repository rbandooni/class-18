
#include "fld1d.h"

// ----------------------------------------------------------------------
// fld1d_create
//
// allocates and initializes a fld1d, setting all elements to zero

struct fld1d *
fld1d_create(int ib, int ie)
{
  // allocate fld1d struct
  struct fld1d *v = calloc(1, sizeof(*v));

  v->ib = ib;
  v->ie = ie;
  v->vals = calloc(v->ie - v->ib, sizeof(v->vals[0]));

  return v;
}

// ----------------------------------------------------------------------
// fld1d_destroy
//
// this function is called when we're done using a fld1d

void
fld1d_destroy(struct fld1d *v)
{
  free(v->vals);
  // not strictly needed, but will make sure that we crash if we
  // access the fld1d after we called fld1d_destroy()
  v->vals = NULL;
  free(v);
}

