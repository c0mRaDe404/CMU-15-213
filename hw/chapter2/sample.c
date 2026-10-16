#include <limits.h>
#include <stdio.h>

int
main (void)
{
  int x = 1;
  int y = INT_MIN;

  unsigned ux = x;
  unsigned uy = y;

  printf ("%d\n", (ux - uy) == -(unsigned)(y - x));
}
