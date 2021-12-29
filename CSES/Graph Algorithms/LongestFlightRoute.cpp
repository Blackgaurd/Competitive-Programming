// Longest Flight Route

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

const int MM = 1e5 + 3;
int n, m, dis[MM], par[MM];
vector<int> adj[MM];
bool inque[MM];
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        adj[b].push_back(a);
    }
    deque<int> q = {n};
    memset(par, -1, sizeof(par));
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        inque[cur] = false;
        for (int nxt : adj[cur]) {
            if (dis[cur] + 1 > dis[nxt]) {
                dis[nxt] = dis[cur] + 1;
                par[nxt] = cur;
                if (!inque[nxt]) {
                    inque[nxt] = true;
                    q.push_back(nxt);
                }
            }
        }
        if (q.back() > cur) {
            q.push_front(q.back());
            q.pop_back();
        }
    }
    if (dis[1] == 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i != -1; i = par[i]) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i != -1; i = par[i]) printf("%d ", i);
    printf("\n");

    return 0;
}