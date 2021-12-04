// D. Social Network

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

const int MM = 1e3 + 3;
int n, d, p[MM], dep[MM], saved = 0;
int flead(int x) {
    if (p[x] != x) {
        p[x] = flead(p[x]);
        dep[x] = dep[p[x]];
    }
    return p[x];
}
pii get_max(bool arg) {
    pii ret = {0, 0};
    pii ind = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (dep[i] >= ret.first && flead(i) != flead(ind.first)) {
            ret.second = ret.first;
            ret.first = dep[i];
            ind.second = ind.first;
            ind.first = i;
        } else if (dep[i] > ret.second && flead(i) != flead(ind.second)) {
            ret.second = dep[i];
            ind.second = i;
        }
    }
    return arg ? ind : ret;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(d);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        dep[i] = 1;
    }
    for (int i = 1, a, b; i <= d; i++) {
        su(a);
        su(b);
        int pa = flead(a), pb = flead(b);
        if (pa != pb) {
            p[pa] = pb;
            dep[pb] += dep[pa];
            int tmp = saved;
            while (tmp--) {
                pii mx = get_max(true);
                int pf = flead(mx.first), ps = flead(mx.second);
                p[pf] = ps;
                dep[ps] += dep[pf];
                flead(mx.first);
            }
        } else {
            saved++;
        }
        printf("%d\n", get_max(false).first + saved - 1);
        for (int i = 1; i <= n; i++) cout << dep[i] << ' ';
        cout << '\n';
    }

    return 0;
}