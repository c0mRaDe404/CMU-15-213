#define R 7
#define S 5 
#define T 13

long A[R][S][T]; 


// A) A + 4((i * S * T) + (j * T) + k)
// B) R = 7, S = 5, T = 13
long store_ele(long i, long j, long k, long *dest)
{
	*dest = A[i][j][k];
	return sizeof(A);
}



/*
*store_ele:
*  leaq	(%rsi,%rsi,2), %rax  ; 3j
*  leaq	(%rsi,%rax,4), %rax  ; 13j
*
*  movq	%rdi, %rsi    ; i
*  salq	$6, %rsi      ; i * 64
*  addq	%rsi, %rdi    ; (i*64) + i = 65i
*
*  addq	%rax, %rdi    ; 13j + 65i
*  addq	%rdi, %rdx    ; 13j + 65i + k
*
*  movq	A(,%rdx,8), %rax   ; 8(13j + 65i + k) 
*  movq	%rax, (%rcx)       
*  movl	$3640, %eax
*  ret
*
*/
