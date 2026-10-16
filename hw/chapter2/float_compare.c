#include <assert.h>
#include <stdint.h>
#include <stdio.h>

uint32_t
f2u (float x)
{
  return *(uint32_t *)&x;
}

int
float_le (float x, float y)
{
  unsigned ux = f2u (x);
  unsigned uy = f2u (y);
  /* Get the sign bits */
  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;

  /* Give an expression using only ux, uy, sx, and sy */

  return !(ux << 1 || uy << 1) || ((sx || sy) && (ux >= uy))
         || (!(sx || sy) && ux <= uy);
}

int
main (int argc, char *argv[])
{
  assert (float_le (-0.0f, 0.0f));
  assert (float_le (0.0f, -0.0f));
  assert (float_le (0.0f, 3.0f));
  assert (float_le (-4.0f, -0.0f));
  assert (float_le (-4.0f, 4.0f));
  assert (float_le (4.0f, 4.0f));
  assert (float_le (-4.0f, -4.0f));
  assert (float_le (-0.0f, -0.0f));
  assert (float_le (4.0f, -4.0f));
  return 0;
}
