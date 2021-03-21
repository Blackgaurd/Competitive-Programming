// CCO '15 P2 - Artskjid
// brute force approach because i cant think of a better way

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
using pii = pair<int, int>;

const int MM = 18;
int n, m, ans = 0, dis = 0, vis[MM];
vector<pii> adj[MM];
void dfs(int cur){
    for (auto e: adj[cur]){
        if (!vis[e.second]){
            vis[e.second] = 1;
            dis+=e.first;
            ans = max(ans, dis);
            dfs(e.second);
            dis-=e.first;
            vis[e.second] = 0;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({w, b});
    }
    vis[0] = 1;
    dfs(0);
    printf("%d\n", ans);
    
    return 0;
}
