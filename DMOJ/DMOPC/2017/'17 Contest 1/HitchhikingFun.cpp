// DMOPC '17 Contest 1 P3 - Hitchhiking Fun

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define sc(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;
#define INF 0x3f3f3f3f

const int MM = 1e5 + 5;
int n, m, dis[MM], hitch[MM];
bool inque[MM];
deque<int> q;
vector<pii> adj[MM];
int main() {
    sc(n);
    sc(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        sc(a);
        sc(b);
        sc(w);
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    q.push_back(1);
    memset(hitch, INF, sizeof(hitch));
    memset(dis, INF, sizeof(dis));
    hitch[1] = 0;
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (pii e : adj[cur]) {
            int nxt = e.second, w = e.first;
            if (hitch[nxt] > hitch[cur] + w) {
                hitch[nxt] = hitch[cur] + w;
                dis[nxt] = dis[cur] + 1;
                if (!inque[nxt]) {
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            } else if (hitch[nxt] == hitch[cur] + w) {
                dis[nxt] = min(dis[nxt], dis[cur] + 1);
            }
        }
    }
    if (dis[n] == INF)
        cout << -1 << '\n';
    else
        cout << hitch[n] << " " << dis[n] << '\n';

    return 0;
}