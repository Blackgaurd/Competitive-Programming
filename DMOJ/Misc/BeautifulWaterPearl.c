// Beautiful Water Pearl

#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a - b == c) printf("%d\n", 1 << __builtin_popcount(c));
    else printf("0\n");
}
