// DMOPC '21 Contest 6 P4 - Colourful Paths

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
#define key {min(a, b), max(a, b)}
// clang-format on
typedef pair<int, int> pii;

const int MM = 2e5 + 3;
int n, m, par[MM], A, B, C, D, clr = 2;
bool vis[MM];
vector<int> adj[MM];
vector<pii> roads;
map<pii, int> colour;
void bfs(int start, int end, bool flag) {
    deque<int> q = {start};
    vis[start] = true;
    par[start] = -1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        if (cur == end) break;
        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                if (flag && cur == start && nxt == end) continue;
                vis[nxt] = true;
                q.push_back(nxt);
                par[nxt] = cur;
            }
        }
    }
}
void reset() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
}
int main() {
    su(n);
    su(m);
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        colour[key] = -1;
        roads.push_back(key);
    }
    su(A);
    su(B);
    su(C);
    su(D);
    pii tmp = {min(C, D), max(C, D)};
    for (auto &p: roads){
        if (p == tmp){
            printf("-1\n");
            return 0;
        }
    }

    // find shortest path from A->B
    vector<int> path_AB;
    bfs(A, B, false);
    for (int a = par[B], b = B; a != -1; a = par[a], b = par[b]) {
        colour[key] = 1;
        if (b != B)
            path_AB.push_back(b);
    }

    // find shortest path from C->D of length > 1
    reset();
    bfs(C, D, true);
    if (!vis[D]) {
        printf("-1\n");
        return 0;
    }
    for (int a = par[D], b = D; a != -1; a = par[a], b = par[b]) {
        if (colour[key] != -1) continue;
        colour[key] = clr++;
    }
    if (clr == 2) {
        printf("-1\n");
        return 0;
    }

    // output
    for (auto p : roads) {
        // printf("%d %d ", p.first, p.second);
        if (colour[p] == -1)
            colour[p] = clr++;
    }

    printf("%d\n", clr - 1);
    for (auto p : roads) {
        // printf("%d %d ", p.first, p.second);
        printf("%d\n", colour[p]);
    }
}
