// Claire Elstein

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e5+3, MOD = 1e9+7;
long long n, m, dp[MM], cnt[MM], ans = 0, in[MM];
vector<int> adj[MM];
int main(){
    su(n); su(m);
    for (int i=0; i<m; i++){
        int a, b; su(a); su(b);
        adj[a].emplace_back(b);
        in[b]++;
    }
    deque<int> q;
    for (int i=1; i<=n; i++){
        if (!in[i]){
            q.push_back(i);
            cnt[i] = 1;
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        for (int nxt: adj[cur]){
            dp[nxt] += dp[cur] + cnt[cur];
            cnt[nxt] += cnt[cur];
            if (dp[nxt] > MOD) dp[nxt] = (dp[nxt] + MOD) % MOD;
            if (cnt[nxt] > MOD) cnt[nxt] = (cnt[nxt] + MOD) % MOD;
            in[nxt]--;
            if (!in[nxt]) q.push_back(nxt);
        }
    }
    for (int i=1; i<=n; i++){
        if (adj[i].empty()){ ans += dp[i]; ans %= MOD; }
    }
    printf("%lld\n", ans);

    return 0;
}