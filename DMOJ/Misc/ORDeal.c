// OR-deal

#include<stdio.h>

long long n;
int main(){
    scanf("%lld", &n);
    do{putchar('1');}while(n>>=1);
    putchar('\n');
}