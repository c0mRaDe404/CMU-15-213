#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

float
u2f (unsigned x)
{
  return *(float *)&x;
}

float
fpwr2 (int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;
  int8_t bias = 127;

  if (x < -bias - 23 + 1)
    {
      /* Too small. Return 0.0 */
      exp = 0;
      frac = 0;
    }
  else if (x < 1 - bias)
    {
      /* Denormalized result */
      exp = 0;
      frac = (1 << 22) >> -(bias + x);
    }
  else if (x < bias + 1)
    {
      /* Normalized result. */
      exp = x + 127;
      frac = 0;
    }
  else
    {
      /* Too big. Return +oo */
      exp = 0xFF;
      frac = 0;
    }
  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f (u);
}

int
main (void)
{
  assert (fpwr2 (0) == powf (2, 0));
  assert (fpwr2 (100) == powf (2, 100));
  assert (fpwr2 (-100) == powf (2, -100));
  float x = fpwr2 (10000);
  float y = powf (2, 10000);
  assert (fpwr2 (10000) == powf (2, 10000));
  assert (fpwr2 (-10000) == powf (2, -10000));
  return 0;
}
