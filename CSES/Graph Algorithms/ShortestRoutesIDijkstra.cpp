// Shortest Routes I
// tle

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
int n, m;
vector<pii> adj[MM];
ll dis[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b, c; i < m; i++) {
        su(a);
        su(b);
        su(c);
        adj[a].emplace_back(c, b);
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        auto [_, cur] = q.top();
        q.pop();
        for (auto [w, nxt] : adj[cur]) {
            if (dis[cur] + w < dis[nxt]) {
                dis[nxt] = dis[cur] + w;
                q.push({dis[nxt], nxt});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dis[i]);
    }

    return 0;
}