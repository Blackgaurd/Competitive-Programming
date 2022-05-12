// G. White-Black Balanced Subtrees

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 4003;
int t, n, cnt;
vector<int> adj[MM];
string colours;
pii is_balanced(int cur) {
    pii ret = {0, 0};
    if (colours[cur - 1] == 'W')
        ret.first++;
    else
        ret.second++;
    for (int nxt : adj[cur]) {
        auto [w, b] = is_balanced(nxt);
        ret.first += w;
        ret.second += b;
    }
    if (ret.first == ret.second) cnt++;
    return ret;
}
void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        adj[a].push_back(i);
    }
    cin >> colours;
    cnt = 0;
    is_balanced(1);
    cout << cnt << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}