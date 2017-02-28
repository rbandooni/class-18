
c     ----------------------------------------------------------------------
      subroutine matrix_vector_mul(m, n, A, x, y)
c     ----------------------------------------------------------------------
      implicit none

      integer m, n
      real*8 A(m, n)
      real*8 x(n)
      real*8 y(m)
      integer i, j

      do i = 1, m
         y(i) = 0
         do j = 1, n
            y(i) = y(i) + A(i, j) * x(j)
         end do
      end do
      
      end subroutine

