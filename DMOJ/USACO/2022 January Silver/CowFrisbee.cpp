#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 3e5 + 3;
int n, a, ans, psa[MM], last[MM];
deque<pii> q = {{0, INT_MAX}};
vector<int> arr = {INT_MAX};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (q.back().second <= a) q.pop_back();
        arr.push_back(q.back().first);
        q.push_back({i, a});
        if (i == 1) continue;
        int cur = arr.back(), pre = arr[arr.size() - 2];
        if (cur == pre) {
            if (pre == 0) {
                ans += 1;
            } else {
                ans += 1;            // previous
                ans += i - cur + 1;  // tallest one
            }
        } else if (cur > pre) {
            ans += 1;  // previous
        } else {
            
        }
        if (pre < cur) psa[i]++;
        psa[i] += psa[i - 1];
        last[cur] = i;
    }

    return 0;
}