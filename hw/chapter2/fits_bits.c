#include <stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */

int
fit_bits (int x, int n)
{

  int result = (unsigned)x << (32 - n);
  result = result >> (32 - n);

  return !(x ^ result);
}

int
main (void)
{
  int result = fit_bits (9, 4);
  return 0;
}
