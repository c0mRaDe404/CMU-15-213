#include <stdio.h>

/**
  Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8
– 1 (most significant). Write code for the following C function, which will
retur an unsigned value in which byte i of argument x has been replaced by byte
b
**/

unsigned
replace_byte (unsigned x, int i, unsigned char b)
{
  unsigned temp = x ^ (b << i * 8);

  return temp ^ (x & (0xFFu << i * 8));
}

int
main (void)
{
  unsigned x = replace_byte (0x12345678, 2, 0xAB);
  unsigned y = replace_byte (0x12345678, 0, 0xAB);
  return 0;
}
