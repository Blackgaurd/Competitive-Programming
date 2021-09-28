// Mock CCC14S4 - Roadtrip Tracking

#include <bits/stdc++.h>
using namespace std;
#define sc(x)                                   \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;

const int MM = 4e4 + 4;
int n, m, cnt = 0;
bool vis[MM];
vector<int> adj[MM];
set<int> path;
void dfs(int cur) {
    vis[cur] = true;
    path.insert(cur);
    if (cur == n) cnt++;
    if (cnt == 2) return;
    for (auto nxt : adj[cur]) {
        if (!vis[nxt])
            dfs(nxt);
        else if (path.count(nxt) == 0) {
            cnt++;
        }
    }
    vis[cur] = false;
    path.erase(cur);
}
int main() {
    sc(n);
    sc(m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        sc(a);
        sc(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    printf(cnt >= 2 ? "Yes\n" : "No\n");

    return 0;
}