// DMOPC '20 Contest 5 P2 - On The Clock

#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;

    if (n == m) {  // slope = 1
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d %d\n", i, i);
        }
    } else {  // slope not 1
        int gcd = __gcd(n, m), cpn = n, cpm = m;
        if (gcd != 1) {
            n /= gcd;
            m /= gcd;
        }
        vector<pair<int, int>> squares;
        int curx = 0, cury = 0;
        double x = (n - 1) / 2.0, y = (m - 1) / 2.0;
        while (true) {
            int move = (1 + 2 * x) * m - (1 + 2 * y) * n;
            if (move <= 0) {
                curx++;
                x++;
            }
            if (move >= 0) {
                cury++;
                y++;
            }
            if (curx > n || cury > m) break;
            squares.push_back({curx, cury});
        }
        if (gcd == 1) {
            cout << squares.size() << '\n';
            for (auto sq : squares) {
                cout << sq.first << ' ' << sq.second << '\n';
            }
        } else {
            cout << squares.size() * gcd << '\n';
            for (int i = 0; i < gcd; i++) {
                for (auto sq : squares) {
                    cout << sq.first + i * n << ' ' << sq.second + i * m
                         << '\n';
                }
            }
        }
    }

    return 0;
}