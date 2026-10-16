
#include <stdio.h>

typedef unsigned packed_t;

/*
 * Extract byte from word. Return as signed integer.
 * Assume bytenum is between 0 and 3.
 */
int
xbyte (packed_t word, int bytenum)
{
  int byte = word << ((3 - bytenum) << 3);
  byte >>= 24;
  return byte;
}

int
main (void)
{
  packed_t word = 0x80FF017F;

  printf ("%d\n", xbyte (word, 0));
  printf ("%d\n", xbyte (word, 1));
  printf ("%d\n", xbyte (word, 2));
  printf ("%d\n", xbyte (word, 3));

  return 0;
}
