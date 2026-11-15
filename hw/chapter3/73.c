#include <stdio.h>
#include <assert.h>

typedef enum {
  OTHER,
  NEG, 
  POS,
  ZERO
} range_t;


range_t find_range(float x) {
    float y = 0;
    range_t cond;  
    __asm__ (
      "vucomiss %[y], %[x] \n\t"
      "jp .P \n\t"
      "ja .A\n\t"
      "jb .B\n\t"
      "je .E\n\t"
      ".E: \n\t" 
      "movl $3, %[cond] \n\t"
      "jmp done\n\t"
      ".B: \n\t" 
      "movl $1, %[cond] \n\t"
      "jmp done\n\t"
      ".A: \n\t" 
      "movl $2, %[cond] \n\t"
      "jmp done\n\t"
      ".P: \n\t" 
      "movl $0, %[cond] \n\t"
      "done:"
      : [x] "+x" (x), [y] "+x" (y), [cond] "=r" (cond) 
    );
    

    return cond;
}



int main(int argc, char* argv[]) {
  range_t n = NEG, z = ZERO, p = POS, o = OTHER;
  assert(o == find_range(0.0/0.0));
  assert(n == find_range(-2.3));
  assert(z == find_range(0.0));
  assert(p == find_range(3.33));
  return 0;
}
