#include <stdio.h>

// 000001100101
// 111110011010

// you are a loser obviously...
int
leftmost_one (unsigned x)
{
  unsigned y = (~x >> 1);

  return (int)y;
}

int
main (void)
{
  return 0;
}
