#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 50;

    // axis-aligned triangles
    int ttl = n * n * 3;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == n && j == n) continue;

            int _gcd = gcd(i, j), rise = i / _gcd, run = j / _gcd;
            // try going top left
            ttl += min(i / run, (n - j) / rise);
            // try going bot right
            ttl += min((n - i) / run, j / rise);
        }
    }
    printf("%d\n", ttl);
}