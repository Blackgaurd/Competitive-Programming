// RTE '16 S3 - School Traversal
// LCA

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

const int MM = 6000, LOGM = 14;
int n, q, t_ind = 0, first[MM];
ll sparse[LOGM][2 * MM];
vector<pii> adj[MM];
void dfs(int cur, ll val, int par) {
    sparse[0][t_ind++] = val;
    if (first[cur] == -1) {
        first[cur] = t_ind - 1;
    }
    for (pii nxt : adj[cur]) {
        if (nxt.first == par) continue;
        dfs(nxt.first, val + nxt.second, cur);
        sparse[0][t_ind++] = val;
    }
}
int qlog2(int x) { return 31 - __builtin_clz(x); }
ll query(int l, int r) {
    if (l > r) swap(l, r);
    int j = qlog2(r - l + 1);
    return min(sparse[j][l], sparse[j][r - (1 << j) + 1]);
}
signed main() {
    su(n);
    for (int i = 1, a, b, w; i < n; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    memset(first, -1, sizeof(first));
    dfs(0, 0, -1);
    for (int j = 1; j <= qlog2(t_ind); j++) {
        for (int i = 0; i + (1 << j) <= t_ind; i++) {
            sparse[j][i] =
                min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
        }
    }
    su(q);
    while (q--) {
        int a, b;
        su(a);
        su(b);
        ll lca = query(first[a], first[b]);
        ll ans = sparse[0][first[a]] - lca + sparse[0][first[b]] - lca;
        printf("%lld\n", ans);
    }

    return 0;
}