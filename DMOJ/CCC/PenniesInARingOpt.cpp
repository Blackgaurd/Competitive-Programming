// CCC '08 S2 - Pennies in the Ring

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        int cnt = 0, x = 1;
        for (int y = n; y >= 1;) {
            if (y * y + x * x <= n * n) {
                cnt += y;
                x++;
            } else
                y--;
        }
        cout << cnt * 4 + n * 4 + 1 << '\n';
    }
}