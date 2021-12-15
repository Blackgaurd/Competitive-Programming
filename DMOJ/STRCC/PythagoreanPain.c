// St Robert Coding Competition J2 - Pythagorean Pain

#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a * a + b * b == c * c) printf("True");
    else printf("False");
}