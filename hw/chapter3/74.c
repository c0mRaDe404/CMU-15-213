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
    asm (
      "movq $1, %%rsi \n\t"
      "movq $2, %%rcx \n\t"
      "movq $3, %%rdx \n\t"
      "movq $0, %%r8\n\t"
      "vucomiss %[y], %[x] \n\t"
      "cmovbq %%rsi, %%rax \n\t"
      "cmovaq %%rcx, %%rax \n\t"
      "cmoveq %%rdx, %%rax \n\t"
      "cmovpq %%r8, %%rax \n\t"
      "movl %%eax, %[cond]"
      : [x] "+x" (x), [y] "+x" (y), [cond] "=r" (cond) 
      :
      : "%rax", "%rcx", "%rdx", "%r8"
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
