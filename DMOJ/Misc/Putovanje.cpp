// COCI '19 Contest 5 #4 Putovanje

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

const int MM = 2e5 + 3, LOGM = 19;
int n, diff[MM], first[MM], ptr;
vector<pair<int, pii>> adj[MM];
pii price[MM], sparse[LOGM][MM * 2];
void euler(int cur, int par, int val) {
    sparse[0][ptr++] = {val, cur};
    if (first[cur] == 0) first[cur] = ptr - 1;
    for (auto [nxt, p] : adj[cur]) {
        if (nxt != par) {
            price[nxt] = p;
            euler(nxt, cur, val + 1);
            sparse[0][ptr++] = {val, cur};
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
pii query(int l, int r) {
    if (l > r) swap(l, r);
    int j = qlog2(r - l + 1);
    return min(sparse[j][l], sparse[j][r - (1 << j) + 1]);
}
int dfs(int cur, int par) {
    // reconstruct the difference array
    // to get how many times each edge
    // was visited
    for (auto [nxt, _] : adj[cur]) {
        if (nxt == par) continue;
        diff[cur] += dfs(nxt, cur);
    }
    return diff[cur];
}
int main() {
    su(n);
    for (int i = 0, a, b, p1, p2; i < n - 1; i++) {
        su(a);
        su(b);
        su(p1);
        su(p2);
        adj[a].push_back({b, {p1, p2}});
        adj[b].push_back({a, {p1, p2}});
    }
    euler(1, 0, 0);
    build();
    for (int i = 2; i <= n; i++) {
        // add one to each of the endpoints
        // subtract 2 from the LCA node
        diff[i - 1]++;
        diff[i]++;
        int lca = query(first[i - 1], first[i]).second;
        diff[lca] -= 2;
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += min((ll)price[i].first * diff[i], (ll)price[i].second);
    }
    printf("%lld\n", ans);
}