// Trivial Printing

#include<stdio.h>

unsigned long long a, b;
int main(){
    for (scanf("%llu%llu", &a, &b); a<b; a++){
        printf("%llu\n", a);
    }
    printf("%llu\n", a);

    return 0;
}