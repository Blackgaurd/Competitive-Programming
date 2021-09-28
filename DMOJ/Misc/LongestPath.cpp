// Longest Path

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define sc(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

const int MM = 1e5 + 5;
int n, m, dp[MM], ans = 0;
vector<int> adj[MM];
bool vis[MM];
void dfs(int cur) {
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (!vis[nxt]) dfs(nxt);
        dp[cur] = max(dp[cur], dp[nxt] + 1);
    }
}
int main() {
    sc(n);
    sc(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        sc(a);
        sc(b);
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);

    return 0;
}