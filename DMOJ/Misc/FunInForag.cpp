// Fun in Föràg
// bin search

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
#define INF 0x3f3f3f3f
#define ll long long
using pii = pair<ll, int>;

struct edge {
    int u, w, p;
    edge(int uu, int ww, int pp) {
        u = uu;
        w = ww;
        p = pp;
    }
};
const int MM = 1e5 + 3;
int n, m, a, b;
ll c, dis[MM];
vector<edge> adj[MM];
bool check_dijkstra(int x) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, INF, sizeof(dis));
    q.push({0, a});
    dis[a] = 0;
    while (!q.empty()) {
        ll cur = q.top().second, w = q.top().first;
        q.pop();
        if (w > dis[cur]) continue;
        for (edge& e : adj[cur]) {
            ll nxt = e.u, nxtw = e.w, ticket = e.p;
            if (ticket <= x && dis[cur] + nxtw < dis[nxt]) {
                dis[nxt] = dis[cur] + nxtw;
                q.push({dis[nxt], nxt});
            }
        }
    }
    return dis[b] <= c;
}
bool check_spfa(int x) {
    memset(dis, INF, sizeof(dis));
    deque<int> q;
    bool inque[MM];
    memset(inque, false, sizeof(inque));
    dis[a] = 0;
    q.push_back(a);
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (edge& e : adj[cur]) {
            ll nxt = e.u, nxtw = e.w, ticket = e.p;
            if (ticket > x) continue;
            if (dis[cur] + nxtw < dis[nxt]) {
                dis[nxt] = dis[cur] + nxtw;
                if (!inque[nxt]) {
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
        /*
        if (q.back()<cur){
            q.push_front(q.back());
            q.pop_back();
        }
        */
    }
    return dis[b] <= c;
}
int main() {
    su(n);
    su(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        su(u);
        su(v);
        su(w);
        adj[u].push_back(edge(v, w, i));
        adj[v].push_back(edge(u, w, i));
    }
    su(a);
    su(b);
    su(c);

    int hi = m, lo = 1, ans = 0;
    while (hi >= lo) {
        int mid = (hi + lo) / 2;
        if (check_spfa(mid)) {
            hi = mid - 1;
            ans = mid;
        } else
            lo = mid + 1;
    }
    if (!ans) ans = -1;
    printf("%d\n", ans);

    return 0;
}