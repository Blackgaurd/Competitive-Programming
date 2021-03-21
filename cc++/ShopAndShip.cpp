// CCC '09 S4 - Shop and Ship

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using pii = pair<int, int>;

const int MM = 5e5+5;
int n, t, k, d, dis[MM], ans = INT_MAX;
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
unordered_map<int, int> pencils;
int main(){
    scan(n); scan(t);
    for (int i=0; i<t; i++){
        int a, b, w; scan(a); scan(b); scan(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    scan(k);
    for (int i=0; i<k; i++){
        int a, c; scan(a); scan(c);
        pencils.insert({a, c});
    }
    scan(d);
    memset(dis, 0x3f, sizeof(dis));
    q.push({0, d}); dis[d] = 0;
    while (!q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (weight>dis[cur]) continue;
        for (auto p: adj[cur]){
            int w = p.first, nxt = p.second;
            if (dis[nxt]>dis[cur]+w){
                dis[nxt] = dis[cur]+w;
                q.push({dis[nxt], nxt});
            }
        }
        if (pencils[cur]){
            ans = min(ans, dis[cur]+pencils[cur]);
        }
    }
    printf("%d\n", ans);

    return 0;
}


