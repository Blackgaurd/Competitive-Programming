// CCC '07 J5 - Keep on Truckin'

#include <bits/stdc++.h>
using namespace std;

int a, b, n;
vector<int> h = {0,    990,  1010, 1970, 2030, 2940, 3060,
                 3930, 4060, 4970, 5030, 5990, 6010, 7000};
long long dp[40];
int main() {
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        h.push_back(m);
    }
    sort(h.begin(), h.end());
    dp[0] = 1;
    for (int i = 1; i < h.size(); i++) {
        for (int j = 0; j < i; j++) {
            int dis = h[i] - h[j];
            if (dis >= a && dis <= b) dp[i] += dp[j];
        }
    }
    cout << dp[h.size() - 1] << '\n';

    return 0;
}