// Distance Queries

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

const int MM = 2e5 + 3, LOGM = 19;
int n, q, sparse[LOGM][MM * 2], first[MM], ptr;
vector<int> adj[MM];
void euler(int cur, int par, int val) {
    sparse[0][ptr++] = val;
    if (first[cur] == 0) first[cur] = ptr - 1;
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            euler(nxt, cur, val + 1);
            sparse[0][ptr++] = val;
        }
    }
}
void build() {
    for (int j = 1; j <= LOGM; j++)
        for (int i = 0; i + (1 << j) <= 2 * MM; i++)
            sparse[j][i] = min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
}
int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
int query(int l, int r) {
    int j = qlog2(r - l + 1);
    return min(sparse[j][l], sparse[j][r - (1 << j) + 1]);
}
int main() {
#ifdef PC
    freopen("DistanceQueries.in", "r", stdin);
    freopen("DistanceQueries.out", "w", stdout);
#endif
    su(n);
    su(q);
    for (int i = 1, a, b; i < n; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    euler(1, 0, 0);
    build();
    for (int i = 0, a, b; i < q; i++) {
        su(a);
        su(b);
        a = first[a], b = first[b];
        if (a > b) swap(a, b);
        int lca = query(a, b);
        int ans = sparse[0][a] + sparse[0][b] - 2 * lca;
        printf("%d\n", ans);
    }
}