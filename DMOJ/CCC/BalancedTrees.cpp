// CCC '18 S4 - Balanced Trees
// top down dp

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
unordered_map<int, ll> dp;
ll solve(int cur) {
    if (dp.find(cur) != dp.end()) {
        return dp[cur];
    }
    ll ret = 0;
    for (int k = 2; k <= cur;) {
        int w = cur / k;
        // k subtrees each of weight w
        int pre = k;
        k = cur / w + 1;
        ret += solve(w) * (k - pre);
    }
    return dp[cur] = ret;
}
int main() {
    cin >> n;
    dp[1] = 1;
    cout << solve(n) << '\n';
}