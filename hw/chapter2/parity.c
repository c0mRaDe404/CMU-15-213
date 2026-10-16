#include <stdio.h>

int
odd_ones (unsigned x)
{
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  x ^= (x >> 1);
  return x & 1;
}

int
main (void)
{

  for (int i = 0; i < 16; i++)
    {
      printf ("%d\n", odd_ones (i));
    }

  return 0;
}
