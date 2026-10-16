#include <stdio.h>

unsigned int
pattern1 (int k)
{
  unsigned int bits = ~0;
  return bits << k;
}

unsigned int
pattern2 (int j, int k)
{
  unsigned int bitsj = ~0u << j;
  unsigned int bitsw = ~0u << (k + j);
  return bitsj ^ bitsw;
}

int
main (void)
{
  unsigned int x = pattern1 (10);
  unsigned int y = pattern2 (5, 10);
  return 0;
}
