// Shortest Routes I
// only works with all optimizations

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
ll dis[MM], q_sum;
deque<int> q;
bool inque[MM];
int main() {
    su(n);
    su(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        su(a);
        su(b);
        su(c);
        adj[a].emplace_back(b, c);
    }
    q.push_back(1);
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        q_sum -= dis[cur];
        for (auto [nxt, w] : adj[cur]) {
            if (dis[cur] + w < dis[nxt]) {
                dis[nxt] = dis[cur] + w;
                if (!inque[nxt]) {
                    inque[nxt] = true;
                    q.push_back(nxt);
                    q_sum += dis[nxt];
                }
            }
        }
        // SLF
        if (q.back() < cur) {
            q.push_front(q.back());
            q.pop_back();
        }
        // LLL
        if (q.empty()) continue;
        ll avg = q_sum / q.size();
        while (dis[q.front()] > avg){
            q.push_back(q.front());
            q.pop_front();
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dis[i]);
    }

    return 0;
}