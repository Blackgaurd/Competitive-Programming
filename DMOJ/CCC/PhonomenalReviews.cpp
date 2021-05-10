// CCC '16 S3 - Phonomenal Reviews

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl '\n'
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 1e5+1;
int n, m, dis[MM];
set<int> pho;
vector<int> adj[MM];
bool vis[MM], removed[MM];
bool dfs(int cur){
    vis[cur] = true;
    bool sol = pho.count(cur);
    for (auto nxt: adj[cur]){
        if (!vis[nxt]){
            if (dfs(nxt)) sol = true;
        }
    }
    removed[cur] = !sol;
    //cout << cur << ": " << !sol << nl; 
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n); scan(m);
    int a;
    for (int i=0; i<m; i++){
        scan(a);
        pho.insert(a);
    }
    for (int i=0; i<n-1; i++){
        int a, b; scan(a); scan(b);
        adj[a].pb(b); adj[b].pb(a);
    }
    // remove nodes that are not needed
    dfs(a);
    // find diameter of remaining tree
    int dia = 0, nodes = 0;
    deque<int> q; q.pb(a);
    memset(vis, false, sizeof(vis)); vis[a] = true;
    while (!q.empty()){
        nodes++;
        if (dis[q.front()]>dia){
            a = q.front();
            dia = dis[q.front()];
        }
        for (auto nxt: adj[q.front()]){
            if (!vis[nxt] && !removed[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[q.front()]+1;
                q.pb(nxt);
            }
        }
        q.pop_front();
    }
    memset(vis, false, sizeof(vis)); vis[a] = true;
    memset(dis, 0, sizeof(dis));
    q.pb(a);
    while (!q.empty()){
        if (dis[q.front()]>dia){
            a = q.front();
            dia = dis[q.front()];
        }
        for (auto nxt: adj[q.front()]){
            if (!vis[nxt] && !removed[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[q.front()]+1;
                q.pb(nxt);
            }
        }
        q.pop_front();
    }
    // could I have simplified diameter finding? yes
    // do I want to? no
    
    int ans = 2*(nodes-1)-dia;
    cout << ans << nl;

    return 0;
}