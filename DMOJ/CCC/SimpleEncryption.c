// CCC '04 J4 - Simple Encryption

#include<stdio.h>

char key[7], msg[61];
int len = 0;
char shift(char a, char b){
    a += b - 'A';
    if (a > 'Z') a -= 26;
    return a;
}
int main(){
    for (int ptr=0;;){
        if ((key[ptr++] = getchar()) == '\n'){
            key[ptr-1] = 0;
            break;
        }
        len++;
    }
    for (int ptr=0;;){
        if ((msg[ptr] = getchar()) == '\n'){
            msg[ptr] = 0;
            break;
        }
        if (msg[ptr] >= 'A' && msg[ptr] <= 'Z') ptr++;
    }
    for (int i=0; i<=60; i++){
        if (!msg[i]) break;
        putchar(shift(msg[i], key[i%len]));
    }
    putchar('\n');

    return 0;
}
