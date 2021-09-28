// ECOO '16 R3 P3 - CamelCase
// Optimized

#include <bits/stdc++.h>
using namespace std;

const int MM = 2003;
int n, dp[MM];
set<string> dict[26];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        dict[t[0] - 'a'].insert(t);
    }
    for (int e = 0; e < 10; e++) {
        string t;
        cin >> t;
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= t.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                string word = t.substr(j, i - j);
                if (dict[word[0] - 'a'].count(word)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        cout << dp[t.length()] - 1 << '\n';
    }

    return 0;
}