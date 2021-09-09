// Trivial Printing

#include<stdio.h>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

unsigned long long a, b;
int main(){
    su(a); su(b);
    for (; a<b; a++)
        printf("%llu\n", a);
    printf("%llu\n", a);

    return 0;
}