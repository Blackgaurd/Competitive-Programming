// VMSS '15 #4 - Frank and Roads

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 2005;
int t, n, m, g, dis[MM], ans = 0;
vector<pair<int, int>> adj[MM];
vector<int> fb;
int main(){
    sc(t); sc(n); sc(m); sc(g);
    for (int i=0; i<g; i++){
        int a; sc(a);
        fb.push_back(a);
    }
    for (int i=0; i<m; i++){
        int a, b, w; sc(a); sc(b); sc(w);
        adj[a].push_back({w, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push({0, 0}); dis[0] = 0;
    while (!q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (weight>dis[cur]) continue;
        for (auto e: adj[cur]){
            int w = e.first, nxt = e.second;
            if (dis[nxt]>dis[cur]+w){
                dis[nxt] = dis[cur]+w;
                q.push({dis[nxt], nxt});
            }
        }
    }
    for (auto store: fb){
        if (dis[store]<=t) ans++;
    }
    printf("%d\n", ans);

    return 0;
}   
