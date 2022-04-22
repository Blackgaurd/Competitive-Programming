// Finding A Centroid

#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5 + 3;
int n, sz[MM];
vector<int> adj[MM];
int centroid(int total) {
    function<void(int, int)> dfs1 = [&](int cur, int par) {
        sz[cur] = 1;
        for (int nxt : adj[cur]) {
            if (nxt == par) continue;
            dfs1(nxt, cur);
            sz[cur] += sz[nxt];
        }
    };
    function<int(int, int)> dfs2 = [&](int cur, int par) {
        for (int nxt : adj[cur]) {
            if (nxt == par) continue;
            if (sz[nxt] * 2 > total) return dfs2(nxt, cur);
        }
        return cur;
    };
    dfs1(1, 0);
    return dfs2(1, 0);
}
int main() {
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << centroid(n) << '\n';

    return 0;
}