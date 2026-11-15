#include <stdio.h> 
#include <stdlib.h>

#define MAX_BUF_SIZE (8)

int my_echo(void) {
  char ch;
  while((ch = fgetc(stdin)) != '\n') {
      if (ch == EOF) 
        break;
      fprintf(stdout, "%c", ch);
  }
  putc('\n', stdout);
  return EXIT_SUCCESS;
}

int main(void) {
  return my_echo();
}
