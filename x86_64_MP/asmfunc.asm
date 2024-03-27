; assembly part using x86-64
section .data
length dq 0.0

section .text
bits 64
default rel ; to handle address releocation

global dotproduct
extern printf

dotproduct:
sub rsp, 8*7
	mov rax, [var6]
	mov [rsp+48],rax ; 7th parameter
	mov rax, [var5]
	mov [rsp+40],rax ; 6th parameter
	mov rax, [var4]
	mov [rsp+32],rax ; 5th parameter
	mov r9, [var3] ; 4th parameter
	mov r8, [var2] ; 3rd parameter
	mov rdx, [var1] ; 2nd parameter
	mov rcx, msg1 ; 1st parameter
	call printf
add rsp, 8*7

ret