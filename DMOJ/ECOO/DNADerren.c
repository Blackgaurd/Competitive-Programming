// ECOO '21 P2 - DNA Derren

#include<stdio.h>
#define vow(a) (a=='A')
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

int main(){
    char cur, pre = getchar();
    while ((cur = getchar()) != '\n'){
        if (vow(cur)){
            putchar(pre);
            if (vow(pre))
                putchar(' ');
        }
        else {
            putchar(pre);
            if (!vow(pre))
                putchar(' ');
        }
        pre = cur;
    }
    putchar(pre);

    return 0;
}