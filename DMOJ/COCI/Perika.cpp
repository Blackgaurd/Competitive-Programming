// COCI '15 Contest 5 #3 Perica

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

const int MM = 1e5 + 3, MOD = 1e9 + 7;
int n, k, arr[MM];
ll ans = 0, fact[MM], invfact[MM];
ll qpow(ll __a, ll __exp) {
    ll __ret = 1;
    while (__exp > 0) {
        if (__exp & 1) __ret = __ret * __a % MOD;
        __a = __a * __a % MOD;
        __exp >>= 1;
    }
    return __ret;
}
ll nck(int a, int b) {
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}
int main() {
    su(n);
    su(k);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = qpow(fact[i], MOD - 2);
    }
    sort(arr + 1, arr + n + 1);
    for (int i = k; i <= n; i++) {
        ans += nck(i - 1, k - 1) * arr[i];
        if (ans > MOD) ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}