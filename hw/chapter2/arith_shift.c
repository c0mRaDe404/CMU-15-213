#include <stdio.h>

int
int_shifts_are_arithmetic ()
{
  int x = -1;
  int y = x;
  return !((x >> 1) ^ y);
}

int
main (void)
{
  return int_shifts_are_arithmetic ();
}
