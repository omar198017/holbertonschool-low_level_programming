; File: 100-hello_world.asm
; Purpose: Print "Hello, World" followed by newline using only syscall
; Author: Omar Caguazango

global main

section .text
main:
    mov     rax, 1          ; syscall: write
    mov     rdi, 1          ; stdout
    mov     rsi, message    ; pointer to message
    mov     rdx, 13         ; message length
    syscall

    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; return 0
    syscall

section .data
message: db "Hello, World", 10    ; 10 = newline \n
