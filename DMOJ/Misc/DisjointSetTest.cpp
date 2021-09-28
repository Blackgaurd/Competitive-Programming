// Disjoint Set Test

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

const int MM = 1e5 + 5;
int n, m;
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[MM];
vi ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    scan(n);
    scan(m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scan(a);
        scan(b);
        adj[a].pb(make_pair(i, b));
        adj[b].pb(make_pair(i, a));
    }
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (!vis[cur]) {
            // cout << cur << nl;
            n--;
            vis[cur] = true;
            ans.pb(weight);
            for (auto nxt : adj[cur]) {
                q.push(nxt);
            }
        }
    }
    if (n)
        cout << "Disconnected Graph" << nl;
    else
        for (int i = 1; i < ans.size(); i++) cout << ans[i] << nl;

    return 0;
}