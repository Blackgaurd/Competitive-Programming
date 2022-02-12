// CCC '14 S5 - Lazy Fox

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
typedef pair<int, pii> pi_ii;
typedef pair<pii, int> pii_i;

const int MM = 2003;
int n, ans;
vector<pii> points;
struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(pair<T1, T2> const &pair) const {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
unordered_map<pii, vector<pi_ii>, pair_hash> adj;
unordered_set<pii, pair_hash> vis;
unordered_map<pii, int, pair_hash> best;
int get_len(pii a, pii b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
void dfs(pii cur, int len, int dis) {
    vis.insert(cur);
    ans = max(ans, dis);
    for (auto [nxt_len, nxt] : adj[cur]) {
        if (len > nxt_len && vis.find(nxt) == vis.end()) {
            dfs(nxt, nxt_len, dis + 1);
        }
    }
    vis.erase(cur);
}
int main() {
#ifdef PC
    freopen("LazyFox.in", "r", stdin);
    freopen("LazyFox.out", "w", stdout);
#endif
    su(n);
    points.resize(n + 1);
    points[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        su(points[i].first);
        su(points[i].second);
        for (int j = 0; j < i; j++) {
            int len = get_len(points[i], points[j]);
            adj[points[j]].push_back({len, points[i]});
            if (j != 0) adj[points[i]].push_back({len, points[j]});
        }
    }
    dfs(points[0], INT_MAX, 1);
    printf("%d\n", ans);
}