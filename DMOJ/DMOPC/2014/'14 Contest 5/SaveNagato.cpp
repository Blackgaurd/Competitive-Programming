// DMOPC '14 Contest 5 P6 - Save Nagato!

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

const int MM = 5e5 + 3;
int n, dis[2][MM];
vector<int> adj[MM];
void dfs(int cur, int par, int d) {
    dis[d][cur] = dis[d][par] + 1;
    for (int nxt : adj[cur])
        if (nxt != par)
            dfs(nxt, cur, d);
}
int mx_dis(int d) {
    int end = -1, mx = -1;
    for (int i = 1; i <= n; i++) {
        if (dis[0][i] > mx) {
            mx = dis[0][i];
            end = i;
        }
    }
    return end;
}
int main() {
    su(n);
    for (int i = 1, a, b; i < n; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfs(mx_dis(0), 0, 0);
    dfs(mx_dis(0), 0, 1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", max(dis[0][i], dis[1][i]));
    }
}