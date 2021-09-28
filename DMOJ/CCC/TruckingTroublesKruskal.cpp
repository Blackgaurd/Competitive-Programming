// CCC '03 S5 - Trucking Troubles

#include <algorithm>
#include <cstdio>
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

const int MM = 1e4 + 3;
struct edge {
    int u, v, w;
    bool operator<(edge const& other) { return w > other.w; }
} adj[MM * 100];
int c, r, d, p[MM * 100], ans = MM * 10;
bool cities[MM];
int flead(int x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
int main() {
    su(c);
    su(r);
    su(d);
    for (int i = 1; i <= r; i++) {
        int a, b, w;
        su(a);
        su(b);
        su(w);
        adj[i] = {a, b, w};
        p[i] = i;
    }
    for (int i = 0; i < d; i++) {
        int a;
        su(a);
        cities[a] = true;
    }
    sort(adj, adj + r);
    for (int i = 0; i < r; i++) {
        if (flead(adj[i].u) != flead(adj[i].v)) {
            ans = min(ans, adj[i].w);
            p[flead(adj[i].u)] = adj[i].v;
            if (cities[adj[i].u]) {
                cities[adj[i].u] = false;
                d--;
            }
            if (cities[adj[i].v]) {
                cities[adj[i].v] = false;
                d--;
            }
        }
        if (!d) {
            printf("%d\n", ans);
            return 0;
        }
    }

    return 0;
}