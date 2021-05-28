// VM7WC '16 #3 Gold - Hello, Officer.

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef pair<int, int> pii;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

const int MM = 2e3+5;
int n, m, b, qq, dis[MM];
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
    scan(n); scan(m); scan(b); scan(qq);
    for (int i=0; i<m; i++){
        int a, b, w; scan(a); scan(b); scan(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    q.push({0, b});
    fill(dis, dis+MM, 1e8);
    dis[b] = 0;
    while (!q.empty()){
        int weight = q.top().first, cur = q.top().second;
        q.pop();
        if (weight>dis[cur]) continue;
        for (auto e: adj[cur]){
            int w = e.first, nxt = e.second;
            if (dis[cur]+w<dis[nxt]){
                dis[nxt] = dis[cur]+w;
                q.push({dis[nxt], nxt});
            }
        }
    }
    for (int i=0; i<qq; i++){
        int a; scan(a);
        cout << (dis[a]==1e8? -1:dis[a]) << nl;
    }

    return 0;
}