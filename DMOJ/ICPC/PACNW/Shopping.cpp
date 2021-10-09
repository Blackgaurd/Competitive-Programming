// ICPC PACNW 2016 J - Shopping

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
#define watch(x) cout << (#x) << ": " << x << '\n'
// clang-format on
typedef long long ll;

const int MM = 2e5 + 3, LOGM = 18;
int n, q;
ll sparse[MM][LOGM];
int qlog2(int x) { return 31 - __builtin_clz(x); }
ll query(int l, int r) {  // inclusive
    // if (l > r) return LLONG_MAX;
    int j = qlog2(r - l + 1);
    return max(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}
int main() {
    su(n);
    su(q);
    for (int i = 0; i < n; i++) su(sparse[i][0]);
    for (int j = 1; j <= qlog2(n); j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            sparse[i][j] =
                max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
    while (q--) {
        ll v;
        int l, r;
        su(v);
        su(l);
        su(r);
        l--;
        r--;
        while (true) {
            int mid, h = r;
            while (l <= h) {
                mid = (l + h) / 2;
                if (query(l, mid - 1) <= v) {
                    h = mid - 1;
                } else if (query(mid, h) <= v) {
                    l = mid;
                } else
                    break;
            }
            ll mod = sparse[mid][0];
            if (mod > v) break;
            v %= mod;
            if (v == 0) break;
            // watch(mid);
            // watch(mod);
            // watch(v);
            l = mid + 1;
            // watch(l);
            cout << "";  // why,,,
        }
        printf("%lld\n", v);
    }

    return 0;
}