
#ifndef FLD1D_H
#define FLD1D_H

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define BOUNDSCHECK

// ----------------------------------------------------------------------
// struct fld1d

struct fld1d {
  double *vals;
  int ib; // starting index of local part
  int ie; // end index (+1) of local part
};

#ifdef BOUNDSCHECK
#define F1(v, i) (*({							\
	assert((i) >= (v)->ib && (i) < (v)->ie);			\
	&((v)->vals[(i) - (v)->ib]);					\
      })) 
#else
#define F1(v, i) ((v)->vals[(i) - (v)->ib])
#endif

struct fld1d *fld1d_create(int N, int sw);
void fld1d_destroy(struct fld1d *v);

#endif
