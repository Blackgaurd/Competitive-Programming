// DWITE '07 R5 #3 - Parity bit

#include <stdio.h>
// clang-format off
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; int _sign;
// clang-format on

int check(int x) {
    int ret = 0;
    while (x) {
        x &= (x - 1);
        ret ^= 1;
    }
    return ret;
}
int main() {
    for (int i = 0; i < 5; i++) {
        int a;
        su(a);
        printf("%d\n", check(a));
    }

    return 0;
}