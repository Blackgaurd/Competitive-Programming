// DMOPC '15 Contest 3 P3 - Dimethylbenzene

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

int n, m;
vi adj[21];
bool vis[21];
bool cycle = false;

void dfs(int cur, int start, int len) {
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (nxt == start && len == 6) {
            cycle = true;
            return;
        }
        if (!vis[nxt]) dfs(nxt, start, len + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, i, 1);
        ms(vis, false, 21);
    }
    if (cycle)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}