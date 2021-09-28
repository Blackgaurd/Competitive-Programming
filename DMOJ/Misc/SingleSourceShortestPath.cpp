// Single Source Shortest Path

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m, dis[1003];
bool vis[1003];
vector<pii> adj[1003];
priority_queue<pii, vector<pii>, greater<pii>> q;
// {weight, node}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    memset(dis, 0x3f, sizeof(dis));
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty()) {
        int d = q.top().first, cur = q.top().second;
        q.pop();
        if (d > dis[cur]) continue;
        vis[cur] = true;
        for (auto e : adj[cur]) {
            int w = e.first, nxt = e.second;
            if (dis[nxt] > (dis[cur] + w)) {
                dis[nxt] = dis[cur] + w;
                q.push({dis[nxt], nxt});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << (vis[i] ? dis[i] : -1) << '\n';

    return 0;
}