	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	leaq	-8(%rbp), %rsi
	leaq	-12(%rbp), %rdx
	leaq	-16(%rbp), %rcx
	movl	%eax, -20(%rbp)                 ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	-8(%rbp), %r8d
	cmpl	-12(%rbp), %r8d
	jge	LBB0_2
## %bb.1:
	movl	-8(%rbp), %eax
	movl	%eax, -24(%rbp)                 ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	movl	-12(%rbp), %eax
	movl	%eax, -24(%rbp)                 ## 4-byte Spill
LBB0_3:
	movl	-24(%rbp), %eax                 ## 4-byte Reload
	cmpl	-16(%rbp), %eax
	jge	LBB0_8
## %bb.4:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB0_6
## %bb.5:
	movl	-8(%rbp), %eax
	movl	%eax, -28(%rbp)                 ## 4-byte Spill
	jmp	LBB0_7
LBB0_6:
	movl	-12(%rbp), %eax
	movl	%eax, -28(%rbp)                 ## 4-byte Spill
LBB0_7:
	movl	-28(%rbp), %eax                 ## 4-byte Reload
	movl	%eax, -32(%rbp)                 ## 4-byte Spill
	jmp	LBB0_9
LBB0_8:
	movl	-16(%rbp), %eax
	movl	%eax, -32(%rbp)                 ## 4-byte Spill
LBB0_9:
	movl	-32(%rbp), %eax                 ## 4-byte Reload
	leaq	L_.str.4(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -36(%rbp)                 ## 4-byte Spill
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Usage: min a b c\t// a, b, c are integers\n"

	.section	__DATA,__data
	.globl	_msg1                           ## @msg1
	.p2align	3
_msg1:
	.quad	L_.str

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	" The smallest is: "

	.section	__DATA,__data
	.globl	_msg2                           ## @msg2
	.p2align	3
_msg2:
	.quad	L_.str.1

	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"Input three integers: "

L_.str.3:                               ## @.str.3
	.asciz	"%d %d %d"

L_.str.4:                               ## @.str.4
	.asciz	"The minial of the three: %d\n"

.subsections_via_symbols
