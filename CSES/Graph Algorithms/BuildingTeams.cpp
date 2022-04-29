// Building Teams

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
int n, m, team[MM];
vector<int> adj[MM];
bool bfs(int start) {
    deque<int> q = {start};
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int nxt : adj[cur]) {
            if (team[nxt]) {
                if (team[nxt] == team[cur])
                    return false;
                continue;
            }
            team[nxt] = team[cur] == 1 ? 2 : 1;
            q.push_back(nxt);
        }
    }
    return true;
}
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            team[i] = 1;
            if (!bfs(i)) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", team[i]);
    }
}