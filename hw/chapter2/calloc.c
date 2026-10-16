#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *
my_calloc (size_t nmemb, size_t size)
{
  if (nmemb && size)
    {
      size_t total_bytes = nmemb * size;

      if (!(nmemb != 0 && total_bytes / nmemb == size))
        {
          return NULL;
        }

      void *ptr = malloc (nmemb * size);
      memset (ptr, 1, nmemb * size);
      return ptr;
    }
  return NULL;
}

int
main (void)
{
  void *ptr = my_calloc (10, 10);
  ptr = my_calloc (-1, 10);
  return 0;
}
