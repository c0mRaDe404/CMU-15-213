/* 
	long sum_col(long n, long A[NR(n)][NC(n)], long j) {
	long i;
	long result = 0;
	for (i = 0; i < NR(n); i++)
		result += A[i][j];
	return result;
}

*/

#define NR(n) (3 * n)
#define NC(n) ((4 * n) + 1)

sum_col:
  leaq	1(,%rdi,4), %r8         ; %r8 = 4n + 1
  leaq	(%rdi,%rdi,2), %rax     ; %rax = 3n

  movq	%rax, %rdi              ; %rdi = 3n

  testq	%rax, %rax              ; zero (or) negative 
  jle	.L4                       ; terminate

  /* loop initilization */
  salq	$3, %r8                 ; 8(4n + 1)
  leaq	(%rsi,%rdx,8), %rcx     ; %rcx = %rsi + (8 * j)
  movl	$0, %eax                ; clear %eax
  movl	$0, %edx                ; clear %edx
.L3:
  addq	(%rcx), %rax            ; result += A[i][j]
  addq	$1, %rdx                ; i++
  addq	%r8, %rcx               ; %rcx = [%rsi + (8 * j)] + [8(4n + 1)]
  cmpq	%rdi, %rdx              ; i < 3n
  jne	.L3                       ; loop until i != 3n
  rep	ret

.L4:
  movl	$0, %eax
  ret
