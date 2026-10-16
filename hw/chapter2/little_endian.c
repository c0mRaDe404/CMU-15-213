#include <stddef.h>

int
main (void)
{
  unsigned short x = 1;
  return (*(unsigned char *)&x);
}
