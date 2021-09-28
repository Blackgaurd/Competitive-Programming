// Wesley's Anger Contest 6 Problem 2 - Cheap Christmas Lights

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 2e5 + 3;
int n, m, on = 0;
bool state[MM] = {false};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> state[i];
        if (state[i]) on++;
    }
    int ans = 1000000;
    if (!on)
        ans = 0;
    else {
        for (int i = 1; i <= m; i++) {
            int cur;
            cin >> cur;
            state[cur] = !state[cur];
            if (state[cur])
                on++;
            else
                on--;
            if (on <= i) {
                // possible
                ans = i;
                break;
            }
        }
    }
    if (ans == 1000000) ans = max(m, on);
    cout << ans << '\n';

    return 0;
}