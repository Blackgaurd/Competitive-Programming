// CCO '15 P2 - Artskjid

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, dp[20][1<<18];
vector<pii> adj[20];
int solve(int cur, int mask){
    if (dp[cur][mask] >= 0) return dp[cur][mask];
    if (cur == n-1) return dp[cur][mask] = 0;
    for (pii p: adj[cur]){
        int nxt = p.second, wt = p.first;
        if (!(mask & (1 << nxt)))
            dp[cur][mask] = max(dp[cur][mask], wt + solve(nxt, mask | 1 << nxt));
    }
    return dp[cur][mask];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i=0, a, b, w; i<m; i++){
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    cout << solve(0, 1) << '\n';

    return 0;
}