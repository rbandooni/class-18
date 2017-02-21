
ACLOCAL_AMFLAGS = -I m4

check_PROGRAMS = \
	test_vector_dot \
	test_vector_add \
	test_matrix_vector_mul \
	test_matrix_matrix_mul

LDADD = liblinalg.a

lib_LIBRARIES = liblinalg.a

liblinalg_a_SOURCES = \
	vector.c \
	vector_dot.c \
	vector_add.c \
	matrix.c \
	matrix_vector_mul.c \
	matrix_matrix_mul.c

TESTS = \
	test_vector_dot \
	test_vector_add \
	test_matrix_vector_mul \
	test_matrix_matrix_mul
