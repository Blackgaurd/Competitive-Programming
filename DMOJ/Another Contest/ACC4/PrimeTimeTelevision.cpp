// Another Contest 4 Problem 5 - Prime Time Television

#include <random>

typedef long long ll;
ll qpow(int a, int n, int m) {
    ll r = 1;
    while (n > 0) {
        if (n & 1) r = r * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return r;
}
bool composite(int n, int a, int d, int p) {
    ll x = qpow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int i = 1; i < p; i++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}
bool f(int n) {
    if (n <= 4) return n == 2 || n == 3;
    if (!(n & 1)) return n == 2;
    int p = 0, d = n - 1, conf = 2;
    while (!(d & 1)) {
        d >>= 1;
        p++;
    }
    while (conf--) {
        int a = 2 + rand() % (n - 3);
        if (composite(n, a, d, p)) return false;
    }
    return true;
}
