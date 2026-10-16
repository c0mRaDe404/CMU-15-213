#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>

typedef uint32_t float_bits;

float_bits
leftmost_bits (float_bits f)
{
  f |= f >> 1;
  f |= f >> 2;
  f |= f >> 4;
  f |= f >> 8;
  f |= f >> 16;
  return (f >> 1) + 1;
}

float_bits
log2u (float_bits bits)
{
  int i;
  for (i = 0; bits != 1; i++)
    bits >>= 1;
  return i;
}

float_bits
float_i2f (int i)
{

  if (!i)
    return i;

  /* signed to unsigned */
  float_bits u = i;

  /* isolates sign bit */
  float_bits sign = i & 0x80000000;

  float_bits bits = (i < 0) ? ~u + 1 : u;

  /* isolates the left most bit */
  float_bits l = leftmost_bits (bits);

  /* gives the position of the leftmost bit */
  float_bits exp = log2u (l);

  /* bias = 127 */
  float_bits bias = 0x7F;

  float_bits value = bits << (31 - exp) << 1;

#define msb_mask (~0x1FF)
#define lsb_mask (~msb_mask)

  float_bits ebits = value & lsb_mask;
  value >>= 9;
  if (ebits)
    {
      if (ebits > 0x100)
        {
          value += 1;
          if (!(value & 0x7FFFFF))
            {
              value = 0;
              exp += 1;
            }
        }
      else if (ebits == 0x100)
        {
          float_bits round = ((value & 1) == 1) ? 1 : 0;

          value += round;
          if (round && !(value & 0x7FFFFF))
            {
              value = 0;
              exp += 1;
            }
        }
    }

  float_bits E = exp + bias;

  return (value & 0x7FFFFF) | sign | (exp + bias) << 23;
}

int
main (void)
{

  for (int i = -1000000; i <= 1000000; i++)
    {
      float_bits mine = float_i2f (i);
      float_bits hw;
      float f = (float)i;
      memcpy (&hw, &f, 4);
      assert (mine == hw);
    }
  return 0;
}
