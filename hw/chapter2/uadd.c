#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int
uadd_ok (uint8_t x, uint8_t y)
{
  uint8_t result = x + y;
  return !(result < x && result < y);
}

int
negate (unsigned int num)
{
  unsigned int x = ~0;
  return x - num + 1;
}

int
main (void)
{
  uint8_t x = 1;
  uint8_t y = 129;
  printf ("%d\n", uadd_ok (x, y));

  printf ("%d\n", 1 << 31);            // tmin
  printf ("%d\n", negate ((1 << 31))); // tmin
  return EXIT_SUCCESS;
}
