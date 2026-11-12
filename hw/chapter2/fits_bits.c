#include <stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */

int
fit_bits (int x, int n)
{

  int w = sizeof(int) << 3; 
  int result = (unsigned)x << (w - n);
  result = result >> (w - n);

  return !(x ^ result);
}

int
main (void)
{
  int result = fit_bits (9, 4);
  return 0;
}
