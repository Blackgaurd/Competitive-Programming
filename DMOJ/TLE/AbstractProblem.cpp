// TLE '16 Contest 7 P4 - Abstract Problem

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define nl "\n"
using ull = unsigned long long;

int t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        int cnt = 0;
        ull x;
        cin >> x;
        while (true) {
            if (x == 1) break;
            if (x % 2 == 0)
                x /= 2;
            else if (x == 3)
                x--;
            else
                ((x + 1) % 4) ? x-- : x++;
            cnt++;
        }
        cout << cnt + 1 << nl;
    }

    return 0;
}