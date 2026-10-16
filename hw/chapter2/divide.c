#include <assert.h>
#include <stdio.h>

int
divide_power2 (int x, int k)
{

  int isneg = (unsigned)x >> 31;
  (isneg && (x = (x + (1 << k) - 1)));
  return x >> k;
}

int
main (void)
{
  int x = 0x80000007;
  assert (divide_power2 (x, 1) == x / 2);
  assert (divide_power2 (x, 2) == x / 4);
  return 0;
}
