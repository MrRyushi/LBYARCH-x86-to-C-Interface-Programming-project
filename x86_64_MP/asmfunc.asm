section .data
    vectorA dq 0
    vectorB dq 0
    length dq 0
    msg db 'Dot product result: %f', 0

section .text
    global dotproduct
    extern printf

dotproduct:
    ; Input: rcx = address of vectorA, rdx = address of vectorB, r8 = length
    ; Output: xmm0 = dot product result

    xorps xmm0, xmm0          ; Initialize xmm0 to 0 (for accumulating the result)
    mov r9, r8                ; Store the original length in r9          

dot_loop:
    movss xmm1, [rcx]         ; Load float from vectorA
    movss xmm2, [rdx]         ; Load float from vectorB
    mulss xmm1, xmm2          ; Multiply vectorA[i] by vectorB[i]
    addss xmm0, xmm1          ; Accumulate the result
    add rcx, 4
    add rdx, 4
    dec r9                    ; Decrement the loop counter
    jnz dot_loop              ; Repeat until all elements are processed

    ret