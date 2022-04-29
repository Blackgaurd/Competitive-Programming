// Message Route

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
int n, m, dis[MM], par[MM];
vector<int> adj[MM];
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i < n; i++) dis[i] = INT_MAX;
    deque<int> q = {n};
    while (!q.empty()) {
        for (int nxt : adj[q.front()]) {
            if (dis[nxt] == INT_MAX) {
                dis[nxt] = dis[q.front()] + 1;
                par[nxt] = q.front();
                q.push_back(nxt);
            }
        }
        q.pop_front();
    }
    if (dis[1] == INT_MAX) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d\n", dis[1] + 1);
        for (int p = 1; p; p = par[p]) printf("%d ", p);
    }
}