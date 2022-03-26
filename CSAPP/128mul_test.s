	.file	"128mul_test.c"
	.text
	.globl	store_prod
	.def	store_prod;	.scl	2;	.type	32;	.endef
	.seh_proc	store_prod
store_prod:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r12
	.seh_pushreg	%r12
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 24(%rbp)
	movq	%rdx, 32(%rbp)
	movq	%r8, 40(%rbp)
	movq	32(%rbp), %rax
	movq	%rax, %r11
	sarq	$63, %rax
	movq	%rax, %r12
	movq	40(%rbp), %rax
	movq	%rax, %r9
	sarq	$63, %rax
	movq	%rax, %r10
	movq	%r12, %rdx
	imulq	%r9, %rdx
	movq	%r10, %rax
	imulq	%r11, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r11, %rax
	mulq	%r9
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movq	24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	nop
	popq	%r12
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 7.1.0"
