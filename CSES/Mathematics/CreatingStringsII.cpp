// Creating Strings II

#include <cstdio>
typedef long long ll;

const int MM = 1e6 + 3, MOD = 1e9 + 7;
int cnt[26], len;
ll fact[MM], invfact[MM], ans = 1;
ll qpow(ll a, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        exp >>= 1;
    }
    return ret;
}
void fermat() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MM; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = qpow(fact[i], MOD - 2);
    }
}
ll nck(int a, int b) {
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}
int main() {
    char c;
    while ((c = getchar()) != '\n') {
        cnt[c - 'a']++;
        len++;
    }
    fermat();
    for (int i = 0; i < 26; i++) {
        ans = (ans * nck(len, cnt[i])) % MOD;
        len -= cnt[i];
    }
    printf("%lld\n", ans);
}
