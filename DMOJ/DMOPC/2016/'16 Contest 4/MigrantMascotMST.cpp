// DMOPC '16 Contest 4 P5 - Migrant Mascot

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MM = 2e5 + 5;
struct E {
    int u, v, w;
} e[MM];
int n, m, p[MM], dis[MM];
vector<pii> adj[MM];
bool comp(E x, E y) { return x.w > y.w; }
int flead(int x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
void dfs(int u, int par) {
    for (auto e : adj[u]) {
        int v = e.first, w = e.second;
        if (v != par) {
            dis[v] = min(dis[u], w);
            dfs(v, u);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m, comp);
    for (int i = 1; i <= n; i++) p[i] = i;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (flead(u) != flead(v)) {
            p[flead(u)] = flead(v);
            cnt++;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        if (cnt == n - 1) break;
    }
    dis[1] = INT_MAX;
    dfs(1, 0);
    dis[1] = 0;
    for (int i = 1; i <= n; i++) cout << dis[i] << '\n';

    return 0;
}
