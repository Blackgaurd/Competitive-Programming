// Dan's Power Attack

#include <bits/stdc++.h>
using namespace std;

int n, d, k;
long long ans = 0;
vector<int> h;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        h.push_back(a);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < n - k; i++) {
        int hits = h[i] / d;
        if (hits * d < h[i]) hits++;
        ans += hits;
    }
    cout << ans << '\n';

    return 0;
}
