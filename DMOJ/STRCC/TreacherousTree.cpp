// St Robert Coding Competition S4 - Treacherous Tree

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef long long ll;

const int MM = 2e5 + 3;
int n, k, val[MM];
vector<int> adj[MM];
bool vis[MM];
ll ncr(int n) {  // n choose 2
    return n * (n - 1) / 2;
}
int dfs(int cur, int par) {
    int ret = 1;
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            ret += dfs(nxt, cur);
        }
    }
    return ret;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(k);
    for (int i = 1; i <= n; i++) su(val[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        su(a);
        su(b);
        if (val[a] > k || val[b] > k) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = dfs(i, -1);
        ans += ncr(cur);
    }
    printf("%lld\n", ans);

    return 0;
}