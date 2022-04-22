// DMOPC '18 Contest 3 P4 - Bob and English Class

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
typedef pair<int, int> pii;
typedef long long ll;

const int MM = 2e5 + 3;
int n, k, sz[MM], zone[MM];
vector<pii> adj[MM];
ll ans;
int centroid(int total) {
    function<void(int, int)> dfs1 = [&](int cur, int par) {
        sz[cur] = zone[cur];
        for (auto [nxt, w] : adj[cur]) {
            if (nxt == par) continue;
            dfs1(nxt, cur);
            sz[cur] += sz[nxt];
        }
    };
    function<int(int, int)> dfs2 = [&](int cur, int par) {
        for (auto [nxt, w] : adj[cur]) {
            if (nxt == par) continue;
            if (sz[nxt] * 2 > total) return dfs2(nxt, cur);
        }
        return cur;
    };
    dfs1(1, 0);
    return dfs2(1, 0);
}
void dfs(int cur, int par, int dis) {
    ans += (ll)zone[cur] * dis;
    for (auto [nxt, w]:adj[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, dis + w);
    }
}
int main() {
    su(k);
    su(n);
    for (int i = 0, a; i < k; i++) {
        su(a);
        zone[a]++;
    }
    for (int i = 0, a, b, w; i < n - 1; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    dfs(centroid(k), 0, 0);
    printf("%lld\n", ans);
}