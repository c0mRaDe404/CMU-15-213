
/*
 * 	typedef __int128 int128_t;
 * 	
 * 	void store_prod(int128_t *dest, int64_t x, int64_t y) {
 * 	*dest = x * (int128_t) y;
 * 	}
 */


store_prod:
  ; %rdi = x 
  ; %rsi = y 
  ; %rdx = dest

	movq	%rdi, %rax ; %rax = x 
	movq	%rdx, %rdi ; %rdi = dest
	movq	%rsi, %r9  ; %r9 = y
	sarq	$63, %r9   ; %r9 = (y >> 63) 
	movq	%rax, %r11 ; %rax, %r11 = x
	sarq	$63, %r11  ; %r11 = (x >> 63)

  # trying to get the upper bits of x and y

	movq	%r11, %rcx ; %rcx = (x >> 63)
	imulq	%rsi, %rcx ; %rcx = %rcx * y  (either 0 or -y)

	movq	%r9, %rdx  ; %rdx = (y >> 63)
	imulq	%rax, %rdx ; %rdx = %rdx * x;  (either 0 or -x)

	addq	%rdx, %rcx ; (adding the upper bits the product)

	mulq	%rsi          ; (x * y)
	addq	%rcx, %rdx    ;(adding the upper bits to the unsigned product's upper bits)
	movq	%rax, (%rdi)  ; low order bits 
	movq	%rdx, 8(%rdi) ; high order bits
	ret



