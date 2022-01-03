// Building Roads

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

int n, m;
vector<int> p;
int flead(int x) {
    if (p[x] != x)
        p[x] = flead(p[x]);
    return p[x];
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0, a, b; i < m; i++) {
        su(a);
        su(b);
        int fa = flead(a), fb = flead(b);
        if (fa != fb) p[fa] = fb;
    }
    for (int i = 1; i <= n; i++) flead(i);
    sort(p.begin(), p.end());
    int connect = p[1];
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; i++) {
        if (p[i] != p[i - 1]) {
            ans.emplace_back(connect, p[i]);
        }
    }
    printf("%d\n", int(ans.size()));
    for (auto [a, b] : ans) {
        printf("%d %d\n", a, b);
    }

    return 0;
}
