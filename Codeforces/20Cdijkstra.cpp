// C. Dijkstra?
// dijkstra

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
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

const int MM = 1e5 + 3;
int n, m, par[MM];
long long dis[MM];
vector<pii> adj[MM];
priority_queue<pli, vector<pli>, greater<pli>> q;
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    for (int i = 0, a, b, w; i < m; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(w, b);
        adj[b].emplace_back(w, a);
    }
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;

    dis[n] = 0;
    par[n] = -1;
    q.push({0, n});
    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();
        for (const pii &e : adj[cur]) {
            int nw = e.first, nxt = e.second;
            if (dis[cur] + nw < dis[nxt]) {
                dis[nxt] = dis[cur] + nw;
                par[nxt] = cur;
                q.push({dis[nxt], nxt});
            }
        }
    }
    if (dis[1] == LLONG_MAX) {
        printf("-1\n");
        return 0;
    }
    for (int cur = 1; cur != -1; cur = par[cur]) {
        printf("%d ", cur);
    }
    printf("\n");

    return 0;
}