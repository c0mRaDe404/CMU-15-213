#include <stdio.h>

long decode2(long x, long y, long z);

/*
 *	decode2:	
 *	subq	%rdx, %rsi
 *	imulq	%rsi, %rdi
 *	movq	%rsi, %rax
 *	salq	$63, %rax
 *	sarq	$63, %rax
 *	xorq	%rdi, %rax
 *	ret	
 */

int main(void) {
  printf("Hello, World!\n");
  return 0;
}

long decode2(long x, long y, long z) {
    y -= z;
    x *= y;
    y <<= 63;
    y >>= 63;
    y ^= x;
    return y;
}
