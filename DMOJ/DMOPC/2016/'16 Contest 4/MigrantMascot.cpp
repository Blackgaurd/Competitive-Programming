// DMOPC '16 Contest 4 P5 - Migrant Mascot

#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using pii = pair<int, int>;

const int MM = 2e5+5;
int n, m, dis[MM], ans = INT_MAX;
vector<pii> adj[MM];
priority_queue<pii, vector<pii>> q;
int main(){
    scan(n); scan(m);
    for (int i=0; i<m; i++){
        int a, b, w; scan(a); scan(b); scan(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    memset(dis, -1, sizeof(dis));
    q.push({ans, 1});
    while (!q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (dis[cur]==-1){
            ans = min(ans, weight);
            dis[cur] = ans;
            for (auto nxt: adj[cur]) q.push(nxt);
        }
    }
    dis[1] = 0;
    for (int i=1; i<=n; i++) cout << dis[i] << '\n';

    return 0;
}