//

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                 \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

const ll MOD = 4294967296;

ll quick_pow(ll x, ll exp) {
    if (exp == 0) return 1;
    ll tmp = quick_pow(x, exp / 2);
    tmp = tmp * tmp % MOD;
    if (exp % 2 == 0) return tmp;
    return tmp * x % MOD;
}

ll fact(ull x) {
    if (x >= MOD) return 0;
    ull sol = 1;
    for (int i = 2; i <= x; i++) sol = (sol * i) % MOD;
    return sol;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ull ans = 1;
    ull N = 1000;        // your input n
    ull M = 7000000000;  // your input m
    for (int i = 2; i <= N; i++) {
        ans = ((i % M) * (ans % M)) % M;
    }
    printf("answer: %lld\n", ans);

    return 0;
}