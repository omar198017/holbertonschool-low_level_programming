; File: 100-hello_world.asm
; Purpose: Print "Hello, World" followed by newline using only syscall
; Author: Omar Caguazango
; Assembled with: nasm -f elf64 100-hello_world.asm && gcc -no-pie -std=gnu89 100-hello_world.o -o hello

	global	main

	section	.text
main:	mov	rax, 1
	mov	rdi, 1
	mov	rsi, message
	mov	rdx, 17
	syscall
	mov	rax, 60
	xor	rdi, rdi
	syscall

	section	.data
message:db	"Hello, World", 12
