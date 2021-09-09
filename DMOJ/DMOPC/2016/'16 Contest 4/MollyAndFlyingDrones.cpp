// DMOPC '16 Contest 4 P6 - Molly and Flying Drones

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e6+3;
int n, q, h[MM];
long long ans[MM];
stack<int> stk;
int main(){
    su(n); su(q);
    h[0] = -1;
    stk.push(0);
    for (int i=1; i<=n+1; i++){
        if (i <= n) su(h[i]);
        else h[i] = -1;
        while (h[stk.top()] > h[i]){
            int p = stk.top();
            stk.pop();
            int lft = p - stk.top(), rit = i - p;
            ans[h[p]] += (long long)lft * rit;
        }
        stk.push(i);
    }
    for (int i=1; i<MM; i++) ans[i] += ans[i-1];
    while (q--){
        int x, y;
        su(x); su(y);
        printf("%lld\n", ans[y] - ans[x-1]);
    }

    return 0;
}