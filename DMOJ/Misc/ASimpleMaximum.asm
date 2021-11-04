; libc
; another shoutout to gcc

global main

extern __isoc99_scanf
extern printf

.LC0:
        db "%d", 0
.LC1:
        db "%d %d", 0
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD [rbp-4], 0
        mov     DWORD [rbp-8], 105
        lea     rax, [rbp-12]
        mov     rsi, rax
        mov     edi, .LC0
        mov     eax, 0
        call    __isoc99_scanf
.L7:
        mov     eax, DWORD [rbp-12]
        lea     edx, [rax-1]
        mov     DWORD [rbp-12], edx
        test    eax, eax
        setne   al
        test    al, al
        je      .L2
        lea     rax, [rbp-16]
        mov     rsi, rax
        mov     edi, .LC0
        mov     eax, 0
        call    __isoc99_scanf
        mov     eax, DWORD [rbp-16]
        cmp     DWORD [rbp-4], eax
        jle     .L3
        mov     eax, DWORD [rbp-4]
        jmp     .L4
.L3:
        mov     eax, DWORD [rbp-16]
.L4:
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-16]
        cmp     DWORD [rbp-8], eax
        jge     .L5
        mov     eax, DWORD [rbp-8]
        jmp     .L6
.L5:
        mov     eax, DWORD [rbp-16]
.L6:
        mov     DWORD [rbp-8], eax
        jmp     .L7
.L2:
        mov     edx, DWORD [rbp-4]
        mov     eax, DWORD [rbp-8]
        mov     esi, eax
        lea     edi, .LC1
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret