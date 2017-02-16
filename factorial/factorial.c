
int
factorial(int n)
{
  int res;

  if (n == 0) {
    res = 1;
  } else {
    res = n * factorial(n-1);
  }
  return res;
}
