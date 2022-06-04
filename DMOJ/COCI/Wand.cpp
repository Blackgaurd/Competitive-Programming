// COCI '18 Contest 4 #2 Wand

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1e5 + 3;
int n, m;
vector<int> adj[MM];
bool vis[MM];
void dfs(int cur) {
    vis[cur] = true;
    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        adj[b].push_back(a);
    }
    if (adj[1].empty()) vis[1] = true;
    for (int start : adj[1]) dfs(start);
    for (int i = 1; i <= n; i++) {
        cout << vis[i];
    }
}