#include <stdio.h>

#define TYPE short
int
int_size_is_32 ()
{

  unsigned TYPE i16 = 1 << 15;
  i16 <<= 1;

  return i16 && (i16 << 15) && !(i16 << 16);
}

int
main (void)
{
  printf ("%d", int_size_is_32 ());
  return 0;
}
