// Road Network

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                 \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;
using pdi = pair<double, int>;

const int MM = 1002;
int n, m, x[MM], y[MM];
double adj[MM][MM], dis[MM], ans;
bool vis[MM];
priority_queue<pdi, vector<pdi>, greater<pdi>> q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // input
    scan(n);
    scan(m);
    for (int i = 1; i <= n; i++) {
        scan(x[i]);
        scan(y[i]);
        for (int j = 1; j < i; j++) {
            // lengths of each road
            adj[i][j] = adj[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
        }
    }
    // mark existing roads as 0
    for (int i = 1, u, v; i <= m; i++) {
        scan(u);
        scan(v);
        adj[u][v] = adj[v][u] = 0;
    }
    fill(dis, dis + MM, 1e9);
    dis[1] = 0;
    q.push({0, 1});
    // use priority queue
    while (!q.empty()) {
        double d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d > dis[u]) continue;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && adj[u][v] < dis[v]) {
                dis[v] = adj[u][v];
                q.push({dis[v], v});
            }
        }
    }
    // naive approach
    /*for (int k=1; k<=n; k++){
        double mi = 1e9;
        int u = -1;
        for (int i=1; i<=n; i++){
            if (!vis[i] && dis[i]<mi){
                mi = dis[i];
                u = i;
            }
        }
        if (u==-1) break;
        vis[u] = true;
        for (int v=1; v<=n; v++){
            if (!vis[v] && adj[u][v]<dis[v]) dis[v] = adj[u][v];
        }
    }*/
    for (int i = 1; i <= n; i++) ans += dis[i];
    cout << fixed << setprecision(2) << ans;

    return 0;
}