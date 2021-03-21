// Jason's Theorem

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

//(2^n-1)*8+3
//2^(n+3)-5
const int mod = 1e9+7;

ull mul_mod(ull a, ull b, ull m) {
    ull r = 0;
    while (a > 0) {
        if (a & 1)
            if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull qpow(ull a, ull n, ull m) {
    ull r = 1;
    while (n > 0) {
        if (n & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ull n; cin >> n;
    n = qpow(2, n, mod);
    n--;
    n*=8;
    n%=mod;
    n+=3;
    cout << n;

    return 0;
}