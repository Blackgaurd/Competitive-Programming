// B. Special Numbers

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
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
int t, n, k;
ull mul_mod(ull __a, ull __b, ull __mod = MOD) {  // __a * __b % __mod
    ull __ret = 0;
    while (__a > 0) {
        if (__a & 1)
            if ((__ret += __b) > __mod) __ret %= __mod;
        __a >>= 1;
        if ((__b <<= 1) > __mod) __b %= __mod;
    }
    return __ret;
}
ull qpow(ull __a, ull __exp, ull __mod = MOD) {  // (__a ^ __exp) % __mod
    if (!__exp) return 1;
    ull __ret = 1;
    while (__exp > 0) {
        if (__exp & 1) __ret = mul_mod(__ret, __a, __mod);
        __a = mul_mod(__a, __a, __mod);
        __exp >>= 1;
    }
    return __ret;
}
int main() {
    su(t);
    while (t--) {
        su(n);
        su(k);
        long long ans = 0;
        for (int i = 0; i < 32; i++) {
            if (k & (1 << i)) {
                ans += qpow(n, i);
                ans %= MOD;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}