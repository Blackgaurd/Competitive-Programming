// USACO 2019 December Silver P3 - Milk Visits

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
int n, m, group[MM], cnt = 1;
bool vis[MM];
char breed[MM];
vector<int> adj[MM];
void dfs(int cur) {
    if (vis[cur]) return;
    group[cur] = cnt;
    vis[cur] = true;
    for (int nxt : adj[cur])
        if (breed[cur] == breed[nxt])
            dfs(nxt);
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    for (int i = 1; i <= n; i++) sc(breed[i]);
    for (int i = 1, a, b; i < n; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    while (m--) {
        int a, b;
        char c;
        su(a);
        su(b);
        sc(c);
        printf("%d", (group[a] != group[b] || c == breed[a]));
    }

    return 0;
}