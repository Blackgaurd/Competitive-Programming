// Shortest Routes II

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

const int MM = 503;
int n, m, q;
ll dis[MM][MM];
int main() {
    su(n);
    su(m);
    su(q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = LLONG_MAX / 2;
        }
    }
    for (int i = 0, a, b, c; i < m; i++) {
        su(a);
        su(b);
        su(c);
        dis[a][b] = dis[b][a] = c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        int a, b;
        su(a);
        su(b);
        printf("%lld\n", dis[a][b] == LLONG_MAX / 2 ? -1 : dis[a][b]);
    }

    return 0;
}