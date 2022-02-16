// SAC '22 Code Challenge 3 P4 - Finding Friends
// no way offline queries + dsu + lca
// is 10p

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

const int MM = 1e5 + 3, LOGM = 17;
int n, q, ind, p[MM], first[MM], sparse[LOGM][MM * 2];
vector<int> adj[MM];
set<pii> edges;
struct qry {
    int t, u, v, ans;
};
vector<qry> queries;
void euler(int cur, int par, int val) {
    // euler tour with dfs
    // val = depth respective to root
    sparse[0][ind++] = val;
    if (first[cur] == -1) {
        first[cur] = ind - 1;
    }
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        euler(nxt, cur, val + 1);
        sparse[0][ind++] = val;
    }
}
int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
void build() {
    // build sparse table
    for (int j = 1; j <= qlog2(ind); j++)
        for (int i = 0; i + (1 << j) <= ind; i++)
            sparse[j][i] = min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
}
int query(int l, int r) {
    // query lca of two nodes
    if (l > r) swap(l, r);
    int j = qlog2(r - l + 1);
    return min(sparse[j][l], sparse[j][r - (1 << j) + 1]);
}
pii mp(int a, int b) {
    if (a > b) swap(a, b);
    return {a, b};
}
int flead(int x) {
    if (x != p[x]) p[x] = flead(p[x]);
    return p[x];
}
int main() {
#ifdef PC
    freopen("FindingFriends.in", "r", stdin);
    freopen("FindingFriends.out", "w", stdout);
#endif
    // input
    su(n);
    su(q);
    for (int i = 1, a, b; i < n; i++) {
        su(a);
        su(b);
        edges.insert(mp(a, b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0, t, u, v; i < q; i++) {
        su(t);
        su(u);
        su(v);
        queries.push_back({t, u, v, -1});
        if (t == 2) {
            edges.erase(mp(u, v));
        }
    }

    // build lca sparse table
    memset(first, -1, sizeof(first));
    euler(1, 0, 0);
    build();

    // build dsu from remaining edges
    for (int i = 1; i <= n; i++) p[i] = i;
    for (auto [a, b] : edges) {
        int pa = flead(a), pb = flead(b);
        if (pa != pb) {
            p[pa] = pb;
        }
    }

    // offline queries starting from back
    for (int i = q - 1; i >= 0; i--) {
        auto &[t, a, b, ans] = queries[i];
        if (t == 1) {
            if (flead(a) == flead(b)) {
                // calculate distance
                int lca = query(first[a], first[b]);
                ans = sparse[0][first[a]] + sparse[0][first[b]] - 2 * lca;
            }
        } else {
            // connect two nodes
            int pa = flead(a), pb = flead(b);
            if (pa != pb) {
                p[pa] = pb;
            }
        }
    }

    // output
    for (auto [t, a, b, ans] : queries) {
        if (t == 1) printf("%d\n", ans);
    }
}