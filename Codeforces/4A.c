// A. Watermelon

#include<stdio.h>

int n;
int main(){
    scanf("%d", &n);
    if (n&1 || n == 2) printf("NO\n");
    else printf("YES\n");
}