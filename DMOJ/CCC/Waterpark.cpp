// CCC '07 S4 - Waterpark

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

int n, paths[100000];
vector<int> adj[10000];
int dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (!paths[nxt]) dfs(nxt);
        paths[cur] += paths[nxt];
    }
}
int main() {
    sc(n);
    while (true) {
        int a, b;
        sc(a);
        sc(b);
        if (!a) break;
        adj[a].push_back(b);
    }
    paths[n] = 1;
    dfs(1);
    cout << paths[1] << '\n';

    return 0;
}