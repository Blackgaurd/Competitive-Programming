// Another Contest 7 Problem 3 - Network Connections

#include <algorithm>
#include <cstdio>
#include <vector>
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
struct edge {
    int u, v, w;
    bool operator<(edge const& other) { return w < other.w; }
};

const int MM = 1e5 + 5;
int n, m, f[MM], p[MM], ans = 0;
vector<edge> adj;
bool vis[MM];
int flead(int x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
int main() {
    scan(n);
    scan(m);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        scan(f[i]);
        if (i != 1) adj.push_back({i, i - 1, f[i] - f[i - 1]});
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        scan(a);
        scan(b);
        if (flead(a) != flead(b)) p[flead(a)] = flead(b);
    }

    sort(adj.begin(), adj.end());

    for (edge cur : adj) {
        if (flead(cur.u) != flead(cur.v)) {
            ans += cur.w;
            p[flead(cur.u)] = flead(cur.v);
        }
    }

    printf("%d\n", ans);

    return 0;
}