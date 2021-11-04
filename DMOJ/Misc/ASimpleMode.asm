; libc
; we <3 gcc

global main
extern __isoc99_scanf
extern printf

.LC0:
        db "%d", 0
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 832
        lea     rdx, [rbp-816]
        mov     eax, 0
        mov     ecx, 100
        mov     rdi, rdx
        rep stosq
        mov     rdx, rdi
        mov     DWORD [rdx], eax
        add     rdx, 4
        lea     rax, [rbp-820]
        mov     rsi, rax
        mov     edi, .LC0
        mov     eax, 0
        call    __isoc99_scanf
.L3:
        mov     eax, DWORD [rbp-820]
        lea     edx, [rax-1]
        mov     DWORD [rbp-820], edx
        test    eax, eax
        setne   al
        test    al, al
        je      .L2
        lea     rax, [rbp-824]
        mov     rsi, rax
        mov     edi, .LC0
        mov     eax, 0
        call    __isoc99_scanf
        mov     eax, DWORD [rbp-824]
        add     eax, 100
        movsx   rdx, eax
        mov     edx, DWORD [rbp-816+rdx*4]
        add     edx, 1
        cdqe
        mov     DWORD [rbp-816+rax*4], edx
        jmp     .L3
.L2:
        mov     DWORD [rbp-4], 0
        mov     DWORD [rbp-8], 0
        mov     DWORD [rbp-12], 0
.L6:
        cmp     DWORD [rbp-12], 200
        jg      .L4
        mov     eax, DWORD [rbp-12]
        cdqe
        mov     eax, DWORD [rbp-816+rax*4]
        cmp     DWORD [rbp-4], eax
        jge     .L5
        mov     eax, DWORD [rbp-12]
        cdqe
        mov     eax, DWORD [rbp-816+rax*4]
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-12]
        sub     eax, 100
        mov     DWORD [rbp-8], eax
.L5:
        add     DWORD [rbp-12], 1
        jmp     .L6
.L4:
        mov     eax, DWORD [rbp-8]
        mov     esi, eax
        mov     edi, .LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret