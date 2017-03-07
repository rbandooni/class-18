
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = \
	test_vector_dot \
	test_vector_add \
	test_matrix_vector_mul \
	test_matrix_matrix_mul \
	test_data_layout \
	test_data_layout_fortran \
	large_matrix_vector_mul \
	test_average

test_data_layout_SOURCES = test_data_layout.c print_matrix_fortran.F
test_data_layout_fortran_SOURCES = test_data_layout_fortran.F print_matrix_fortran.F

LDADD = liblinalg.a

lib_LIBRARIES = liblinalg.a

liblinalg_a_SOURCES = \
	vector.c \
	vector_dot.c \
	vector_add.c \
	matrix.c \
	matrix_vector_mul.c \
	matrix_matrix_mul.c \
	matrix_vector_mul_f.F

TESTS = \
	test_vector_dot \
	test_vector_add \
	test_matrix_vector_mul \
	test_matrix_matrix_mul \
	test_average.sh



