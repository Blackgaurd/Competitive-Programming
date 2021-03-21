// Another Contest 1 Problem 2 - Graphs

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define nl '\n'

const int MM = 1e5+3;
int n, m, q, root, leader[MM], dis[MM];
vector<int> adj[MM];
bool vis[MM];
// calculate distance:
// calculate all distances from a single root
// access from dis array, add nums

// see if connected
// use disjoint set
// see if two nodes have same leader
int find_leader(int v){
    if (leader[v]!=v) leader[v] = find_leader(leader[v]);
    return leader[v];
}
void bfs(int a, int b){
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof (dis));
    deque<int> q;
    q.pb(a);
    vis[a] = true;
    while (!q.empty()){
        int cur = q.front();
        if (cur==b) break;
        for (auto nxt: adj[cur]){
            if (!vis[nxt]){
                vis[nxt] = true;
                q.pb(nxt);
                dis[nxt] = dis[cur]+1;
            }
        }
        q.pop_front();
    }
    cout << dis[b] << nl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i=0; i<m; i++){
        int a, b; scan(a); scan(b);
        adj[a].pb(b); adj[b].pb(a);
        int fa = find_leader(a), fb = find_leader(b);
        if (fa!=fb) leader[fa] = fb; 
    }
    for (int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        if (find_leader(a)==find_leader(b)){
            bfs(a, b);
        }
        else cout << -1 << nl;
    }

    return 0;
}
