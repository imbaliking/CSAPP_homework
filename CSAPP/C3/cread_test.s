	.file	"cread_test.c"
	.text
	.p2align 4,,15
	.globl	cread
	.def	cread;	.scl	2;	.type	32;	.endef
	.seh_proc	cread
cread:
	.seh_endprologue
	leaq	tmp.1808(%rip), %rax
	testq	%rcx, %rcx
	cmove	%rax, %rcx
	movl	(%rcx), %eax
	ret
	.seh_endproc
.lcomm tmp.1808,4,4
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 7.1.0"
