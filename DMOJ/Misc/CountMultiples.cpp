// Count Multiples

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

int gcd(int m, int n) {
    if (m % n == 0) return n;
    gcd(n, m % n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll lcm = a * b / gcd(a, b);
    cout << (y / a + y / b - y / lcm) -
                ((x - 1) / a + (x - 1) / b - (x - 1) / lcm);

    return 0;
}