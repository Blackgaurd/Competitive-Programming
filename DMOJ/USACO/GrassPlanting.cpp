// USACO 2019 January Silver P1 - Grass Planting

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
int n, val[MM];
vector<int> adj[MM];
void dfs(int cur, int par) {
    int nxt_val = 1;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        while (nxt_val == val[cur] || nxt_val == val[par]) nxt_val++;
        val[nxt] = nxt_val++;
        dfs(nxt, cur);
    }
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    for (int i = 1, a, b; i < n; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    val[1] = 1;
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, val[i]);
    printf("%d\n", ans);

    return 0;
}
