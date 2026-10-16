#include <stdio.h>

int
lower_one_mask (int n)
{
  return ~0u >> (32 - n);
}

int
main (void)
{
  return 0;
}
