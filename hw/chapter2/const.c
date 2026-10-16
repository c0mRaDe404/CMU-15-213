#include <assert.h>
#include <stdio.h>

// 64 - 4
int
mul60 (int x)
{
  return (x << 6) - (x << 2);
}

// 16 + 1
int
mul17 (int x)
{
  return (x << 4) + x;
}

int
smul7 (int x)
{
  return (x - (x << 3));
}

int
smul112 (int x)
{
  return ((x << 4) - (x << 7));
}

void
test_them (int start, int stop)
{
  for (int i = start; i < stop; i++)
    {
      assert (mul60 (i) == i * 60);
      assert (mul17 (i) == i * 17);
      assert (smul7 (i) == i * -7);
      assert (smul112 (i) == i * -112);
    }
}

int
main (void)
{
  printf ("%d\n", mul60 (2));
  printf ("%d\n", mul17 (2));
  printf ("%d\n", smul7 (10));
  printf ("%d\n", smul112 (10));
  test_them (2, 100);
  return 0;
}
