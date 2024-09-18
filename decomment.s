	.arch armv8-a
	.file	"decomment.c"
	.text
	.align	2
	.global	normal
	.type	normal, %function
normal:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 34
	bne	.L2
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 1
	b	.L3
.L2:
	ldr	w0, [sp, 28]
	cmp	w0, 39
	bne	.L4
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 2
	b	.L3
.L4:
	ldr	w0, [sp, 28]
	cmp	w0, 47
	bne	.L5
	mov	w0, 6
	b	.L3
.L5:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
.L3:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	normal, .-normal
	.align	2
	.global	quote
	.type	quote, %function
quote:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 92
	bne	.L7
	mov	w0, 4
	b	.L8
.L7:
	ldr	w0, [sp, 28]
	cmp	w0, 34
	bne	.L9
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
	b	.L8
.L9:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 1
.L8:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	quote, .-quote
	.align	2
	.global	charlit
	.type	charlit, %function
charlit:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 92
	bne	.L11
	mov	w0, 5
	b	.L12
.L11:
	ldr	w0, [sp, 28]
	cmp	w0, 39
	bne	.L13
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 0
	b	.L12
.L13:
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 2
.L12:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	charlit, .-charlit
	.align	2
	.global	comment
	.type	comment, %function
comment:
.LFB3:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 42
	bne	.L15
	mov	w0, 7
	b	.L16
.L15:
	ldr	w0, [sp, 28]
	cmp	w0, 10
	bne	.L17
	mov	w0, 10
	bl	putchar
	mov	w0, 3
	b	.L16
.L17:
	mov	w0, 3
.L16:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	comment, .-comment
	.align	2
	.global	qspchar
	.type	qspchar, %function
qspchar:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	mov	w0, 92
	bl	putchar
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 1
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE4:
	.size	qspchar, .-qspchar
	.align	2
	.global	cspchar
	.type	cspchar, %function
cspchar:
.LFB5:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	mov	w0, 92
	bl	putchar
	ldr	w0, [sp, 28]
	bl	putchar
	mov	w0, 2
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE5:
	.size	cspchar, .-cspchar
	.align	2
	.global	inslash
	.type	inslash, %function
inslash:
.LFB6:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 42
	bne	.L23
	mov	w0, 32
	bl	putchar
	mov	w0, 3
	b	.L24
.L23:
	mov	w0, 47
	bl	putchar
	ldr	w0, [sp, 28]
	bl	normal
.L24:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	inslash, .-inslash
	.align	2
	.global	outasterisk
	.type	outasterisk, %function
outasterisk:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	w0, [sp, 28]
	ldr	w0, [sp, 28]
	cmp	w0, 47
	bne	.L26
	mov	w0, 0
	b	.L27
.L26:
	ldr	w0, [sp, 28]
	bl	comment
.L27:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	outasterisk, .-outasterisk
	.section	.rodata
	.align	3
.LC0:
	.string	"Error: line %d: unterminated comment\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB8:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	mov	w0, 1
	str	w0, [sp, 24]
	str	wzr, [sp, 20]
	b	.L29
.L40:
	ldr	w0, [sp, 16]
	cmp	w0, 10
	bne	.L30
	ldr	w0, [sp, 24]
	add	w0, w0, 1
	str	w0, [sp, 24]
.L30:
	ldr	w0, [sp, 20]
	cmp	w0, 7
	beq	.L31
	ldr	w0, [sp, 20]
	cmp	w0, 7
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 6
	beq	.L32
	ldr	w0, [sp, 20]
	cmp	w0, 6
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 5
	beq	.L33
	ldr	w0, [sp, 20]
	cmp	w0, 5
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 4
	beq	.L34
	ldr	w0, [sp, 20]
	cmp	w0, 4
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 3
	beq	.L35
	ldr	w0, [sp, 20]
	cmp	w0, 3
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 2
	beq	.L36
	ldr	w0, [sp, 20]
	cmp	w0, 2
	bhi	.L29
	ldr	w0, [sp, 20]
	cmp	w0, 0
	beq	.L37
	ldr	w0, [sp, 20]
	cmp	w0, 1
	beq	.L38
	b	.L29
.L37:
	ldr	w0, [sp, 16]
	bl	normal
	str	w0, [sp, 20]
	b	.L29
.L38:
	ldr	w0, [sp, 16]
	bl	quote
	str	w0, [sp, 20]
	b	.L29
.L36:
	ldr	w0, [sp, 16]
	bl	charlit
	str	w0, [sp, 20]
	b	.L29
.L35:
	ldr	w0, [sp, 16]
	bl	comment
	str	w0, [sp, 20]
	b	.L29
.L34:
	ldr	w0, [sp, 16]
	bl	qspchar
	str	w0, [sp, 20]
	b	.L29
.L33:
	ldr	w0, [sp, 16]
	bl	cspchar
	str	w0, [sp, 20]
	b	.L29
.L32:
	ldr	w0, [sp, 16]
	bl	inslash
	str	w0, [sp, 20]
	ldr	w0, [sp, 20]
	cmp	w0, 3
	bne	.L29
	ldr	w0, [sp, 24]
	str	w0, [sp, 28]
	b	.L29
.L31:
	ldr	w0, [sp, 16]
	bl	outasterisk
	str	w0, [sp, 20]
	nop
.L29:
	bl	getchar
	str	w0, [sp, 16]
	ldr	w0, [sp, 16]
	cmn	w0, #1
	bne	.L40
	ldr	w0, [sp, 20]
	cmp	w0, 3
	beq	.L41
	ldr	w0, [sp, 20]
	cmp	w0, 7
	bne	.L42
.L41:
	adrp	x0, stderr
	add	x0, x0, :lo12:stderr
	ldr	x3, [x0]
	ldr	w2, [sp, 28]
	adrp	x0, .LC0
	add	x1, x0, :lo12:.LC0
	mov	x0, x3
	bl	fprintf
	mov	w0, 1
	b	.L43
.L42:
	ldr	w0, [sp, 20]
	cmp	w0, 6
	bne	.L44
	mov	w0, 47
	bl	putchar
	b	.L45
.L44:
	ldr	w0, [sp, 20]
	cmp	w0, 4
	beq	.L46
	ldr	w0, [sp, 20]
	cmp	w0, 5
	bne	.L45
.L46:
	mov	w0, 92
	bl	putchar
.L45:
	mov	w0, 0
.L43:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.4.1 20231218 (Red Hat 11.4.1-3)"
	.section	.note.GNU-stack,"",@progbits
