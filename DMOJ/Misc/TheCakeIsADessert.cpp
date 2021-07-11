// The Cake is a Dessert

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ll;

const int MM = 5e3+3;
int n, m, k, q, a, b, c, d;
ll psa[MM][MM];
int main(){
    su(n); su(m); su(k);
    while (k--){
        su(a); su(b); su(c); su(d);
        c++; d++;
        psa[a][b]++;
        psa[a][d]--;
        psa[c][b]--;
        psa[c][d]++;
    }
    for (int e=2; e; e--){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            }
        }
    }
    su(q);
    while (q--){
        su(a); su(b); su(c); su(d);
        a--; b--;
        ll ans = psa[c][d] - psa[a][d] - psa[c][b] + psa[a][b];
        printf("%lld\n", ans);
    }

    return 0;
}