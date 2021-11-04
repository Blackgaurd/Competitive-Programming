; libc
; shoutout to gcc

global main

extern __isoc99_scanf
extern printf

.LC0:
        db "%d%d%d", 0
.LC1:
        db "%d", 0
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rcx, [rbp-12]
        lea     rdx, [rbp-8]
        lea     rax, [rbp-4]
        mov     rsi, rax
        lea     edi, .LC0
        mov     eax, 0
        call    __isoc99_scanf
        mov     edx, DWORD [rbp-4]
        mov     eax, DWORD [rbp-8]
        add     edx, eax
        mov     eax, DWORD [rbp-12]
        add     eax, edx
        movsx   rdx, eax
        imul    rdx, rdx, 1431655766
        shr     rdx, 32
        sar     eax, 31
        mov     ecx, eax
        mov     eax, edx
        sub     eax, ecx
        mov     esi, eax
        lea     edi, .LC1
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret