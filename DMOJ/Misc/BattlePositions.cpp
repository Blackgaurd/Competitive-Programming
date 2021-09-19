// Battle Positions

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e5+3;
int i, n, j, psa[MM], ans = 0;
int main(){
    su(i); su(n); su(j);
    while (j--){
        int a, b, c;
        su(a); su(b); su(c);
        psa[a] += c;
        psa[b + 1] -= c;
    }
    for (int a=1; a<=i; a++){
        psa[a] += psa[a - 1];
        ans += (psa[a] < n);
    }
    printf("%d\n", ans);

    return 0;
}