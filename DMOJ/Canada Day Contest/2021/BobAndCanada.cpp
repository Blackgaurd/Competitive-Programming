// Canada Day Contest 2021 - Bob and Canada

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 75e4+3;
int t, n, r[MM], w[MM];
int main(){
    su(t);
    while (t--){
        su(n);
        int ans = INT_MAX, mina = INT_MAX;
        for (int i=1; i<=n; i++){
            char c; sc(c);
            r[i] = r[i-1] + (c == 'R');
            w[i] = w[i-1] + (c == 'W');
        }
        for (int b=2; b<n; b++){
            mina = min(mina, w[b-1] - r[b-1]);
            ans = min(ans, w[n] - w[b] + r[b] + mina);
        }
        printf("%d\n", ans);
    }

    return 0;
}