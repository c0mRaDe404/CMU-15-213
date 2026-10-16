#include <limits.h>
#include <stdio.h>

int
D (double dx, double dy, double dz)
{

  printf ("%g\n", (dx * dy) * dz);
  printf ("%g\n", dx * (dy * dz));
  return (dx * dy) * dz == dx * (dy * dz);
}

int
main (void)
{
  printf ("%d", D ());
}
