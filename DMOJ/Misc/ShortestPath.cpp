// Shortest Path

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

const int MM = 1003;
int n, m, dis[MM];
vector<pii> adj[MM];
deque<int> q;
bool inque[MM];
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b, w; i < m; i++) {
        su(a);
        su(b);
        si(w);
        adj[a].emplace_back(b, w);
    }
    q.push_back(1);
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (pii p : adj[cur]) {
            int nxt = p.first, w = p.second;
            if (dis[cur] + w < dis[nxt]) {
                dis[nxt] = dis[cur] + w;
                if (!inque[nxt]) {
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
    }
    printf("%d\n", dis[n]);

    return 0;
}