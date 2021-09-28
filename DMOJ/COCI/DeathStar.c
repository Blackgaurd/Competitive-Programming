// COCI '15 Contest 4 #3 Deathstar
// is faster in cpp for some reason

#include <stdio.h>
// clang-format off
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; int _sign;
// clang-format on

int main() {
    int n;
    su(n);
    for (int i = 0; i < n; i++) {
        int a = 0;
        for (int j = 0, x; j < n; j++) {
            su(x);
            a |= x;
        }
        printf("%d ", a);
    }

    return 0;
}