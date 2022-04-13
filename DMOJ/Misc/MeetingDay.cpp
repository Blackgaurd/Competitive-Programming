// Meeting Day

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

const int MM = 1e5 + 3;
int n, m, x, dis[MM], revdis[MM];
vector<pii> adj[MM], revadj[MM];
bool inque[MM];
int main() {
    su(n);
    su(m);
    su(x);
    for (int i = 1, a, b, w; i <= m; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(b, w);
        revadj[b].emplace_back(a, w);
    }

    deque<int> q;
    // normal spfa
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    q.push_back(x);
    dis[x] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (auto [nxt, w] : adj[cur]) {
            if (dis[nxt] > dis[cur] + w) {
                dis[nxt] = dis[cur] + w;
                if (!inque[nxt]) {
                    q.push_back(nxt);
                    inque[nxt] = true;
                }
            }
        }
        if (q.back() > cur) {
            q.push_front(q.back());
            q.pop_back();
        }
    }

    // reverse
    memset(revdis, 0x3f3f3f3f, sizeof(revdis));
    q.push_back(x);
    revdis[x] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (auto [nxt, w] : revadj[cur]) {
            if (revdis[nxt] > revdis[cur] + w) {
                revdis[nxt] = revdis[cur] + w;
                if (!inque[nxt]) {
                    q.push_back(nxt);
                    inque[nxt] = true;
                }
            }
        }
        if (q.back() > cur) {
            q.push_front(q.back());
            q.pop_back();
        }
    }

    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dis[i] + revdis[i]);
    }
    printf("%d\n", mx);
}