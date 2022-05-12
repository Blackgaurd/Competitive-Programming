// D. X-Sum

#include <bits/stdc++.h>
using namespace std;

const int MM = 203;
int t;
int arr[MM][MM];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ttl = 0;
            for (int a = i, b = j; a >= 0 && b >= 0; a--, b--) {
                ttl += arr[a][b];
            }
            for (int a = i, b = j; a >= 0 && b < m; a--, b++) {
                ttl += arr[a][b];
            }
            for (int a = i, b = j; a < n && b < m; a++, b++) {
                ttl += arr[a][b];
            }
            for (int a = i, b = j; a < n && b >= 0; a++, b--) {
                ttl += arr[a][b];
            }
            ttl -= arr[i][j] * 3;
            ret = max(ret, ttl);
        }
    }
    cout << ret << '\n';
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}