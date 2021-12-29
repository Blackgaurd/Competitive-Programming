// Subordinates

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

const int MM = 2e5 + 3;
int n, ans[MM];
vector<int> adj[MM];
int dfs(int cur) {
    int sum = 0;
    for (int nxt : adj[cur]) {
        sum += dfs(nxt);
    }
    return (ans[cur] = sum) + 1;
}
int main() {
    su(n);
    for (int i = 2, a; i <= n; i++) {
        su(a);
        adj[a].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}