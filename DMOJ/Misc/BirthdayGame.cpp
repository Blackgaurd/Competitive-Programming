// Birthday Game
// n nodes, n edges
// therefore there is at least 1 cycle
// find length of shortest cycle

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

const int MM = 2e5 + 3;
int n, adj[MM], dis[MM], group[MM], cur_group, ans = INT_MAX;
void dfs(int cur, int par) {
    dis[cur] = dis[par] + 1;
    group[cur] = cur_group;
    int nxt = adj[cur];
    if (dis[nxt] == INT_MAX)
        dfs(nxt, cur);
    else if (group[nxt] == cur_group)
        ans = min(ans, dis[cur] - dis[nxt] + 1);
}
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        su(adj[i]);
        dis[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INT_MAX) {
            cur_group = i;
            dfs(i, 0);
        }
    }
    printf("%d\n", ans);
}