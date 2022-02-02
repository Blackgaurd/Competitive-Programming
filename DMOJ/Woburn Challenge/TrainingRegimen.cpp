// WC '16 Contest 3 S2 - Training Regimen

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

const int MM = 2e5 + 3;
int n, m;
ll ans;
vector<pii> adj[MM];
vector<int> t;
vector<bool> vis;
struct trp {
    // weight, train time, node num
    int first, second, third;
    bool operator>(const trp &other) const {
        return first > other.first || (first == other.first && second > other.second);
    }
};
priority_queue<trp, vector<trp>, greater<trp>> q;
int main() {
#ifdef PC
    freopen("TrainingRegimen.in", "r", stdin);
    freopen("TrainingRegimen.out", "w", stdout);
#endif
    su(n);
    su(m);
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) su(t[i]);
    for (int i = 0, a, b, w; i < m; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    int min_train = INT_MAX, level = 1;
    vis.assign(n + 1, false);
    q.push({1, t[1], 1});
    while (!q.empty()) {
        auto [w, train, cur] = q.top();
        q.pop();
        if (!vis[cur]) {
            vis[cur] = true;
            if (level < w) {
                ans += ll(min_train) * (w - level);
                level = w;
            }
            min_train = min(min_train, train);
            for (auto [nxt, nw] : adj[cur]) {
                if (vis[nxt]) continue;
                q.push({nw, t[nxt], nxt});
            }
        }
        if (cur == n) break;
    }
    if (!vis[n])
        printf("-1\n");
    else
        printf("%lld\n", ans);
}