// A. String Task

#include<stdio.h>

char c;
int main(){
    while ((c = getchar()) != '\n'){
        if (c < 94) c += 32;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') continue;
        putchar('.');
        putchar(c);
    }
    putchar('\n');

    return 0;
}