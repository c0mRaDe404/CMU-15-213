#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int
threeforths (int x)
{
  int isneg = x & INT_MIN;
  (isneg && (x = -x));
  int lowbits = x & 3;

  int q = x >> 2;

  int result = (q << 1) + q;
  lowbits = (lowbits << 1) + lowbits;
  lowbits >>= 2;
  result = result + lowbits;
  ((isneg && (x ^ INT_MIN)) && (result = -result));
  return result;
}

int
main (void)
{
  printf ("%d\n", threeforths (31));
  printf ("%d\n", threeforths (INT_MAX));
  printf ("%d\n", threeforths (-INT_MAX));
  printf ("%d\n", threeforths (INT_MIN));

  printf ("%d\n", threeforths (-8));

  assert (threeforths (8) == 6);
  assert (threeforths (9) == 6);
  assert (threeforths (10) == 7);
  assert (threeforths (11) == 8);
  assert (threeforths (12) == 9);

  assert (threeforths (-8) == -6);
  assert (threeforths (-9) == -6);
  assert (threeforths (-10) == -7);
  assert (threeforths (-11) == -8);
  assert (threeforths (-12) == -9);
  return 0;
}
