// String Matching

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int base = 131, MOD = 1e9 + 7;
int n, m;
string a, b;
ll p[int(1e6) + 3], h[int(1e6) + 3];
int main() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    if (m > n) {
        printf("0\n");
        return 0;
    }
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * base % MOD;
    }
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * base + a[i - 1]) % MOD;
    }
}