// CCO '13 P3 - LHC

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
typedef long long ll;

const int MM = 4e5 + 5;
int n, dis[MM], cnt[MM], dia;
ll num;
vector<int> adj[MM];
void dfs(int cur, int par) {
    dis[cur] = 0;
    cnt[cur] = 1;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);

        if (dis[cur] + dis[nxt] + 1 > dia) {
            dia = dis[cur] + dis[nxt] + 1;
            num = (ll)cnt[cur] * cnt[nxt];
        } else if (dis[cur] + dis[nxt] + 1 == dia) {
            num += (ll)cnt[cur] * cnt[nxt];
        }

        if (dis[nxt] + 1 > dis[cur]) {
            dis[cur] = dis[nxt] + 1;
            cnt[cur] = cnt[nxt];
        } else if (dis[nxt] + 1 == dis[cur]) {
            cnt[cur] += cnt[nxt];
        }
    }
}
int main() {
    su(n);
    for (int i = 0, a, b; i < n - 1; i++) {
        su(a);
        su(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    printf("%d %lld\n", dia + 1, num);
}