// C. Dijkstra?
// spfa too slow lol

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
typedef long long ll;

const int MM = 1e5 + 3;
int n, m, par[MM];
ll dis[MM];
vector<pii> adj[MM];
bool inque[MM];
deque<int> q;
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
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;

    dis[n] = 0;
    par[n] = -1;
    q.push_back(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (const pii &nxt : adj[cur]) {
            if (dis[cur] + nxt.second < dis[nxt.first]) {
                dis[nxt.first] = dis[cur] + nxt.second;
                par[nxt.first] = cur;
                if (!inque[nxt.first]) {
                    inque[nxt.first] = true;
                    q.push_back(nxt.first);
                }
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