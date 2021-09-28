// UTS Open '21 P1 - COVID Party

#include <bits/stdc++.h>
using namespace std;

int n, m = 0, cnt = -1, p = 1;
int main() {
    scanf("%d", &n);
    if (n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    while (true) {
        // cout << m << ' ' << p << '\n';
        m += p;
        cnt++;
        if (m >= n) {
            cout << cnt << '\n';
            return 0;
        }
        m += p;
        cnt++;
        if (m >= n) {
            cout << cnt << '\n';
            return 0;
        }
        p += 2;
    }

    return 0;
}