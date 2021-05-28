// The Odd Number

#include<stdio.h>
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; int _sign;

int n, ans = 0;
int main(){
    su(n);
    while (n--){
        int a; si(a);
        ans ^= a;
    }
    printf("%d\n", ans);
}