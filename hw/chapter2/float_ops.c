#include <assert.h>
#include <stdio.h>

#include <math.h>

typedef unsigned int float_bits;

int
isNan (float_bits f)
{
  return ((f & 0x7F800000) == 0x7F800000) && (f << 9);
}

float_bits
float_negate (float_bits f)
{
  float_bits exponent = f >> 23 & 0xFF;
  float_bits mantissa = f & 0x7FFFFF;
  if (!(~exponent) && (mantissa))
    return f;
  return f ^ 0x80000000;
}

float_bits
isdenorm (float_bits f)
{
  return !((f & 0x7F800000));
}

float_bits
float_absval (float_bits f)
{
  float_bits exponent = f >> 23 & 0xFF;
  float_bits mantissa = f & 0x7FFFFF;
  if (!(~exponent) && (mantissa))
    return f;
  return f ^ (f & 0x80000000);
}

float_bits
float_twice (float_bits f)
{
  if (isNan (f))
    return f;
  if (isdenorm (f))
    return (f & 0x7FFFFF) << 1 | (f & ~0x7FFFFF);
  float_bits exponent = ((f >> 23 & 0xFF) + 1);
  if (exponent == 0xFF)
    {
      return f & 1u << 31 | exponent << 23;
    }
  return f & 1u << 31 | f & ((1 << 23) - 1) | (exponent << 23);
}

float_bits
f2u (float value)
{
  return *(float_bits *)&value;
}

float
u2f (float_bits value)
{
  return *(float *)&value;
}

float_bits
float_half (float_bits f)
{
  float_bits sign = f >> 31;
  float_bits exponent = (f >> 23 & 0xFF);
  float_bits mantissa = f & ((1 << 23) - 1);

  if (isNan (f))
    return f;
  if (isdenorm (f))
    return (f & 0x7FFFFFFF) >> 1 | (f & ~0x7FFFFF);
  if (exponent == 0xFF)
    {
      return sign << 31 | exponent << 23;
    }
  if (exponent == 1)
    {
      return sign << 31 | (exponent << 22) | mantissa >> 1;
    }
  return sign << 31 | (exponent - 1) << 23 | mantissa;
}

#include <limits.h>

/*
 * exponent should be >= 0 and <= 31
 * only 23 mantissa bits
 */
int
float_f2i (float_bits f)
{

  float_bits sign = f >> 31;
  float_bits exponent = (f >> 23 & 0xFF);
  float_bits mantissa = f & ((1 << 23) - 1);
  float_bits bias = 0x7F;

  if (exponent < bias)
    {
      return 0;
    }
  else if (exponent <= bias + 31)
    {
      float_bits ube = exponent - bias;
      float_bits result = 1 << ube;
      mantissa <<= 8;
      result |= mantissa;
      result = result >> (31 - ube);

      switch (sign)
        {
        case 0:
          if (result <= INT_MAX)
            return result;
          break;
        case 1:
          if (result <= INT_MIN)
            return ~result + 1;
          break;
        }
    }

  return INT_MIN;
}

/*
 * For argument i, this function computes the
 * bit-level representation of (float) i.
 */

int
float_i2f (int i)
{
  return 0;
}

int
main (void)
{
  printf ("%d\n", float_f2i (f2u ((float)(1u << 31))));

  printf ("%d\n", float_f2i (f2u (-(float)(1u << 31))));

  printf ("%d\n", float_f2i (f2u (-(float)(1u << 31 | 1u << 30))));

  printf ("%d\n", float_f2i (f2u (0.5f)));

  return 0;
}
