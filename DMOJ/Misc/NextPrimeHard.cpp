// Next Prime (Hard)

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull mul_mod(ull a, ull b, ull m) {
    if (m == 0) return a * b;
    ull r = 0;
    while (a > 0) {
        if (a & 1)
            if ((r += b) > m) r %= m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull qpow(ull a, ull n, ull m = 0) {
    ull r = 1;
    while (n > 0) {
        if (n & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}

bool checkComposite(ull n, ull a, ull d, int p) {
    ull x = qpow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int i = 1; i < p; i++) {
        x = mul_mod(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

const int conf = 2;
bool millerRabin(ull n) {
    // if (!(n&1)) return false;
    if (n <= 4) return n == 2 || n == 3;
    // p = largest power of 2 that is a divisor of d = n-1
    int p = 0;
    ull d = n - 1;
    while (!(d & 1)) {
        d >>= 1;
        p++;
    }
    for (int i = 0; i < conf; i++) {
        int a = 2 + rand() % (n - 3);
        if (checkComposite(n, a, d, p)) return false;
    }
    return true;
}

ull n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    if (n <= 2) {
        cout << 2 << '\n';
        return 0;
    }
    if (!(n & 1)) n++;
    if (n == 3 || n == 5) {
        cout << n << '\n';
        return 0;
    }
    while (true) {
        if (!millerRabin(n))
            n += 2;
        else {
            cout << n << '\n';
            break;
        }
    }

    return 0;
}