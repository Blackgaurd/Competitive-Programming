// COCI '07 Contest 2 #2 Crne

#include<stdio.h>

int n;
int main(){
    scanf("%d", &n);
    int l = n / 2, w = n - l;
    printf("%d\n", (l + 1) * (w + 1));

    return 0;
}