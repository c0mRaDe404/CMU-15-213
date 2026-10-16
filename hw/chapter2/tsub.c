#include <stdio.h>

/* different signs
 * TMAX, -TMAX
 * TMAX + TMAX
 * -2
 */

#define INTMAX (0x7FFFFFFF)
#define INTMIN (-INTMAX - 1)

int
tsub_ok (int x, int y)
{
  unsigned sy = (unsigned)y >> 31;

  unsigned ux = x;
  unsigned uy = y;

  uy = -uy;

  unsigned sux = ux >> 31;
  unsigned suy = uy >> 31;

  unsigned result = ux + uy;

  return !(sy && suy) && ((sux ^ suy) || !((result >> 31) ^ suy));
}

int
main (void)
{

  printf ("%d\n", tsub_ok (0, 0));                    // 1
  printf ("%d\n", tsub_ok (10, 3));                   // 1
  printf ("%d\n", tsub_ok (5, -1));                   // 1
  printf ("%d\n", tsub_ok (-5, 10));                  // 1
  printf ("%d\n", tsub_ok (-5, -10));                 // 1
  printf ("%d\n", tsub_ok (2147483647, 1));           // 1
  printf ("%d\n", tsub_ok (-2147483648, 1));          // 0
  printf ("%d\n", tsub_ok (2147483647, -1));          // 0
  printf ("%d\n", tsub_ok (-2147483648, -1));         // 1
  printf ("%d\n", tsub_ok (1, -2147483648));          // 0
  printf ("%d\n", tsub_ok (-1, -2147483648));         // 1
  printf ("%d\n", tsub_ok (-2147483648, 0));          // 1
  printf ("%d\n", tsub_ok (2147483647, 0));           // 1
  printf ("%d\n", tsub_ok (0, -2147483648));          // 0
  printf ("%d\n", tsub_ok (-2147483648, 2147483647)); // 0
  printf ("%d\n", tsub_ok (2147483647, -2147483648)); // 0
  printf ("%d\n", tsub_ok (100, 200));                // 1
  printf ("%d\n", tsub_ok (-100, -200));              // 1
  printf ("%d\n", tsub_ok (100, -200));               // 1
  printf ("%d\n", tsub_ok (-100, 200));               // 1
  return 0;
}
