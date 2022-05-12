// C. Most Similar Words

#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int diff(string &a, string &b) {
    int m = a.size();
    int ret = 0;
    for (int i = 0; i < m; i++) {
        int mn = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++) {
            int ttl = 0;
            for (string word : {a, b}) {
                ttl += abs(c - word[i]);
            }
            mn = min(mn, ttl);
        }
        ret += mn;
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    int ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ret = min(ret, diff(arr[i], arr[j]));
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