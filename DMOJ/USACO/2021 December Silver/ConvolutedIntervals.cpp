// USACO 2021 December Silver P3 - Convoluted Intervals

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

const int MM = 5e3 + 3;
int n, m;
ll a[MM], b[MM], psa[MM * 2];
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    su(n);
    su(m);
    for (ll i = 0, ai, bi; i < n; i++) {
        su(ai);
        su(bi);
        a[ai]++;
        b[bi]++;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            psa[i + j + 1] += a[i] * a[j];
            psa[i + j + 2] -= b[i] * b[j];
        }
    }
    for (int i = 1; i <= 2 * m + 1; i++) {
        psa[i] += psa[i - 1];
        printf("%lld\n", psa[i]);
    }

    return 0;
}