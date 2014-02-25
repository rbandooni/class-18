
#define N 3
#define M 4

c     ----------------------------------------------------------------------
      subroutine print_matrix(A)
c     ----------------------------------------------------------------------
      implicit none
      
      real*8 A(N, M)
      integer i, j

      do i = 1, N 
         do j = 1, M
            write(*, ' (F4.0)', advance='no') A(i, j) ! this is Fortran90
         end do
         write(*, *)
      end do
      
      end subroutine

