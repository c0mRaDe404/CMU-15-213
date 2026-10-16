#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int
tadd_ok (int x, int y)
{
  int result = x + y;
  if (x > 0 && y > 0)
    {
      return result > 0;
    }
  else if (x < 0 && y < 0)
    {
      return result <= 0;
    }
  else
    {
      return 1;
    }
}

int
main (void)
{
  printf ("%d\n", tadd_ok (10, 10));
  printf ("%d\n", tadd_ok (1 << 31, 0));
  return EXIT_SUCCESS;
}
