#include <stdio.h>

int
div16 (int x)
{
  int divisor = 4;
  // no negative, no problem
  // negative, problem

  int s = (unsigned)x >> 31;
  return (s ? x + (1 << divisor) - 1 : x) >> divisor;
}

int
main (void)
{
  printf ("%d\n", div16 (-12340));
  return 0;
}
