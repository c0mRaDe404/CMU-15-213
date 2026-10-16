#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int
divide_power2 (int x, int k)
{
  int is_neg = x & INT_MIN;
  (is_neg && (x = x + (1 << k) - 1));
  return x >> k;
}

int
mul3div4 (int x)
{
  int mul3 = (x << 1) + x;
  return divide_power2 (mul3, 2);
}

int
main (int argc, char *argv[])
{
  return EXIT_SUCCESS;
}
