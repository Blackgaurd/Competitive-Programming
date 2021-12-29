// An Animal Contest 4 P1 - Dasher's Digits

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6 + 3;
int n, m;
string t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    int mx = 0, ind = -1;
    for (int i = 1, a; i <= m; i++) {
        cin >> a;
        if (a >= mx) {
            mx = a;
            ind = i;
        }
    }
    int cnt = 0;
    for (char c : t) {
        if (c == '0') {
            cnt++;
        } else if (cnt >= ind)
            cout << c;
    }
    cnt = 0;
    for (char c : t) {
        if (c == '0') {
            cnt++;
        } else if (cnt >= ind)
            break;
        else
            cout << c;
    }
    cout << '\n';
}
