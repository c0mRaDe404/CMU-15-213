#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

int
main (void)
{
  unsigned x = 0xFFFFFFFF;
  unsigned y = x + x;
}
