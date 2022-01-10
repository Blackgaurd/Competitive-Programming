// CCC '21 S4 - Daily Commute
// multiset screwing me

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
#define ttl_dis(x) walk[arr[x]] + sub[arr[x]]

const int MM = 2e5 + 3;
int n, w, d, arr[MM], sub[MM], walk[MM];  // sub = subway
vector<int> adj[MM];
map<int, int> min_dis;
void bfs() {
    deque<int> q = {n};
    memset(walk, -1, sizeof(walk));
    walk[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int nxt : adj[cur]) {
            if (walk[nxt] == -1) {
                walk[nxt] = walk[cur] + 1;
                q.push_back(nxt);
            }
        }
    }
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(w);
    su(d);
    for (int i = 0, a, b; i < w; i++) {
        su(a);
        su(b);
        adj[b].push_back(a);
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        sub[arr[i]] = i - 1;
        if (walk[arr[i]] == -1) walk[arr[i]] = 1e9;
        min_dis[ttl_dis(i)]++;
    }
    for (int i = 0, x, y; i < d; i++) {
        su(x);
        su(y);

        // remove old distances
        if (--min_dis[ttl_dis(x)] == 0){
            min_dis.erase(min_dis.find(ttl_dis(x)));
        }
        if (--min_dis[ttl_dis(y)] == 0){
            min_dis.erase(min_dis.find(ttl_dis(y)));
        }

        // swap
        swap(sub[arr[x]], sub[arr[y]]);
        swap(arr[x], arr[y]);

        // add new distances
        min_dis[ttl_dis(x)]++;
        min_dis[ttl_dis(y)]++;

        printf("%d\n", min_dis.begin()->first);
    }

    return 0;
}