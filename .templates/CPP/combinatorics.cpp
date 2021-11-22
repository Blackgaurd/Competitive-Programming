#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1, MOD = 1;
ll n, fact[MM], invfact[MM];
ll mul_mod(ll __a, ll __b) {
    ll __ret = 0;
    while (__a > 0) {
        if (__a & 1)
            if ((__ret += __b) > MOD) __ret %= MOD;
        __a >>= 1;
        if ((__b <<= 1) > MOD) __b %= MOD;
    }
    return __ret;
}
ll qpow(ll __a, ll __exp) {
    ll __ret = 1;
    while (__exp > 0) {
        if (__exp & 1) __ret = mul_mod(__ret, __a);
        __a = mul_mod(__a, __a);
        __exp >>= 1;
    }
    return __ret;
}
void fermat() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = qpow(fact[i], MOD - 2);
    }
}
ll nck(int a, int b) {
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}