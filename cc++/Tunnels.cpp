// THICC '17 P6 - Tunnels

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 2e5+5;
int n, t, ttl = 0, dis1[MM], dis2[MM];
vector<pii> adj[MM];
int bfs(int start){
    int ans = start, mx = 0;
    deque<int> qq;
    memset(dis1, -1, sizeof(dis1));
    qq.push_back(start); dis1[start] = 0;
    while (!qq.empty()){
        int cur = qq.front(); qq.pop_front();
        if (dis1[cur]>mx){
            mx = dis1[cur];
            ans = cur;
        }
        for (auto node: adj[cur]){
            int w = node.first, nxt = node.second;
            if (dis1[nxt]==-1){
                dis1[nxt] = dis1[cur]+w;
                qq.push_back(nxt);
            }
        }
    }
    return ans;
}
int main(){
    sc(n); sc(t);
    for (int i=0; i<n-1; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
        ttl+=w;
    }
    int dia = bfs(bfs(1));

    deque<int> qq;
    memset(dis2, -1, sizeof(dis2));
    qq.push_back(dia); dis2[dia] = 0;
    while (!qq.empty()){
        int cur = qq.front(); qq.pop_front();
        for (auto node: adj[cur]){
            int w = node.first, nxt = node.second;
            if (dis2[nxt]==-1){
                dis2[nxt] = dis2[cur]+w;
                qq.push_back(nxt);
            }
        }
    }
    
    // shortest path = 2*(all weights) - longest from node
    for (int i=1; i<=n; i++){
        if (adj[i].size()==t){
            printf("%d %d\n", i, 2*ttl-max(dis1[i], dis2[i]));
        }
    }
    
    return 0;
}