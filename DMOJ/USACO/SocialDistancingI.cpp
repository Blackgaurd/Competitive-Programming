// USACO 2020 Open Bronze P1 - Social Distancing I

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cows;
bool check(int x) {
    vector<int> copy = cows;
    int cnt = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char a;
        cin >> a;
        if (a == '1') cows.push_back(i);
    }

    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}