// Finding A Centroid

#include <bits/stdc++.h>
using namespace std;
#define TESTING 1

const int MM = 2e5 + 3;
int n, ans = -1;
vector<int> adj[MM];
int dfs(int cur, int par) {
    int dep = 1;
    int mx = 0;
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            int nxtdep = dfs(nxt, cur);
            dep += nxtdep;
            mx = max(mx, nxtdep);
        }
    }
    if (mx <= n / 2){
        ans = cur;
        cout << "FOUND: " << ans <<  ' ' << mx << '\n';
    }
    return dep;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef TESTING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << '\n';

    return 0;
}