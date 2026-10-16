#include <stdio.h>

int any_one (int);
int any_zero (int);

int
get_msb (int x)
{
  int shift_val = (sizeof (int) - 1) << 3;
  int xright = x >> shift_val;
  int msb = xright & 0xFF;
  return msb;
}

int
get_lsb (int x)
{
  return x & 0xFF;
}

int
lsb_one (int x)
{
  return any_one (get_lsb (x));
}

int
msb_zero (int x)
{
  return any_zero (get_msb (x));
}

int
any_one (int x)
{
  return !!x;
}

int
any_zero (int x)
{
  return !!~x;
}

int
main (void)
{

  printf ("%d", any_one (1232));
  return 0;
}
