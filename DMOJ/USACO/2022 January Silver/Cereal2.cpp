#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
struct trp {
    int first, second, ind;
};
vector<trp> arr;
vector<pii> cnt;
vector<bool> taken;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n);
    cnt.resize(m + 1);
    int ind = 1;
    for (auto &[a, b, c] : arr) {
        cin >> a >> b;
        cnt[a].first++;
        cnt[b].second++;
        c = ind++;
    }
    auto cmp = [](trp &a, trp &b) {
        if (cnt[a.first].first == cnt[b.first].first) {
            return cnt[a.second].second < cnt[b.second].second;
        }
        return cnt[a.first].first > cnt[b.first].first;
    };
    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;
    taken.resize(m + 1);
    for (auto [a, b, c] : arr) {
        if (!taken[a])
            taken[a] = true;
        else if (!taken[b])
            taken[b] = true;
        else
            ans++;
    }
    cout << ans << '\n';
    for (auto [a, b, c] : arr) {
        cout << c << '\n';
    }
}
