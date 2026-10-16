#include <stdint.h>
#include <stdio.h>

int
signed_high_prod (int x, int y)
{
  int64_t x64 = x;
  int64_t y64 = y;
  int64_t result = (int64_t)x * y;
  return result >> 32;
}

int
main (void)
{
  int result = signed_high_prod (1u << 31, 2);
  return 0;
}
