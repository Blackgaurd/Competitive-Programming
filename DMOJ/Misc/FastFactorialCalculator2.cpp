// Fast Factorial Calculator 2

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

const ll p = 4294967291;
int n;
ll qpow(ll a, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * a % p;
        a = a * a % p;
        exp >>= 1;
    }
    return ret;
}
ll fact(ll m) {
    if (m >= p) return 0;
    ll res = 1;
    if (m <= p << 1) {
        for (ll i = 2; i <= m; i++) {
            res = res * i % p;
        }
        return res;
    }
    for (ll i = m + 1; i < p; i++) {
        res = res * i % p;
    }
    res = qpow(res, p - 2);
    res = p - res;
    return res % p;
}
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        ll m;
        su(m);
        printf("%lld\n", fact(m));
    }
}