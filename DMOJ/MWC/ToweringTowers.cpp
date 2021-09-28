// MWC '15 #2 P2: Towering Towers

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, a;
deque<pii> q = {{1, INT_MAX}};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (q.back().second <= a) q.pop_back();
        cout << i - q.back().first << ' ';
        q.push_back({i, a});
    }

    return 0;
}