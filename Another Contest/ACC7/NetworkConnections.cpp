//

#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
using pii = pair<int, int>;
using vi = vector<int>;

const int MM = 1e5+5;
int n, m, f[MM], ans = 0;
vector<pii> adj[MM];
unordered_map<int, set<int>> ctd;
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    scan(n); scan(m);
    for (int i=1; i<=n; i++) scan(f[i]);

    for (int i=1; i<=m; i++){
        int a, b; scan(a); scan(b);
        adj[a].pb(make_pair(0, b));
        adj[b].pb(make_pair(0, a));
        ctd[a].insert(b); ctd[b].insert(a);
    }

    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (ctd[i].count(j) == 0){
                adj[i].pb(make_pair(abs(f[i]-f[j]), j));
                adj[j].pb(make_pair(abs(f[i]-f[j]), i));
            }
        }
    }
    q.push(make_pair(0, 1));
    while (m <= n && !q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (!vis[cur]){
            //cout << cur << nl;
            vis[cur] = true;
            ans += weight;
            m++;
            for (auto nxt: adj[cur]){
                q.push(nxt);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}