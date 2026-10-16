#include <inttypes.h>
#include <stdint.h>

int
main (void)
{
  int8_t x = -100;
  int8_t y = 10;
  int8_t result = x * y;

  uint8_t xx = -100;
  uint8_t yy = 10;
  uint8_t r = xx * yy;

  int16_t u = (int16_t)x * y;
  uint16_t s = (uint16_t)xx * yy;
  return 0;
}
