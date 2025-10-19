; File: 100-hello_world.asm
; Purpose: Print "Hello, World" followed by newline using only syscall
; Author: Omar Caguazango
; Assembled with: nasm -f elf64 100-hello_world.asm && gcc -no-pie -std=gnu89 100-hello_world.o -o hello

section .data
    msg db "Hello, World", 10  ; 10 is ASCII for newline '\n'
    len equ $ - msg            ; Calculate length of string

section .text
    global _start

_start:
    ; syscall: write(int fd, const void *buf, size_t count)
    ; syscall number for write: 1
    ; fd = 1 (stdout)
    ; buf = pointer to msg
    ; count = len

    mov     rax, 1      ; syscall number for write
    mov     rdi, 1      ; file descriptor: stdout
    mov     rsi, msg    ; buffer to write
    mov     rdx, len    ; length of message
    syscall             ; invoke system call

    ; syscall: exit(int status)
    ; syscall number: 60
    ; status: 0

    mov     rax, 60     ; syscall number for exit
    xor     rdi, rdi    ; status 0
    syscall             ; invoke system call
