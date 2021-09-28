// CCC '08 S2 - Pennies in the Ring

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = queue<int>;
using qpii = queue<pii>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (true) {
        int n, count = 0;
        cin >> n;
        if (!n) break;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (i * i + j * j <= n * n)
                    count++;
                else
                    break;
            }
        }
        cout << count * 4 + n * 4 + 1 << nl;
    }
    return 0;
}