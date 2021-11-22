// C. Bubble Strike

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MM = 1003, MOD = 1e9 + 7;
int n;
ull fact[MM], invfact[MM];
double p;
ull mul_mod(ull __a, ull __b) {
    ull __ret = 0;
    while (__a > 0) {
        if (__a & 1)
            if ((__ret += __b) > MOD) __ret %= MOD;
        __a >>= 1;
        if ((__b <<= 1) > MOD) __b %= MOD;
    }
    return __ret;
}
ull qpow(ull __a, ull __exp) {
    int __ret = 1;
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
int nck(int a, int b) {
    if (a < b) return 0;
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}
int main() {
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> p;
    fermat();
    for (int s = 0; s <= n; s++) {
        double total = (double)nck(s, 3) + (double)nck(n - s, 2) * 0.5 * (double)s + (double)(n - s) * (double)nck(s, 2);
        total /= (double)nck(n, 3);
        if (total >= p){
            cout << s << '\n';
            break;
        }
    }

    return 0;
}