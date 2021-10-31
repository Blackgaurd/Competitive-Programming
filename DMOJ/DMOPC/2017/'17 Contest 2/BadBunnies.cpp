// DMOPC '17 Contest 2 P3 - Bad Bunnies

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
int n, r, x, y, ans = INT_MAX, dis[MM], par[MM];
vector<int> adj[MM];
deque<int> q;
int main() {
    su(n);
    su(r);
    for (int i = 0, a, b; i < n - 1; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis, -1, sizeof(dis));
    for (int i = 0, a; i < r; i++) {
        su(a);
        dis[a] = 0;
        q.push_back(a);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int nxt : adj[cur]) {
            if (dis[nxt] == -1) {
                dis[nxt] = dis[cur] + 1;
                q.push_back(nxt);
            }
        }
    }
    su(x);
    su(y);
    q.push_back(x);
    par[x] = -1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int nxt : adj[cur]) {
            if (par[nxt] == 0) {
                par[nxt] = cur;
                q.push_back(nxt);
            }
        }
    }
    for (; y != -1; y = par[y]) {
        ans = min(ans, dis[y]);
    }
    printf("%d\n", ans);

    return 0;
}
