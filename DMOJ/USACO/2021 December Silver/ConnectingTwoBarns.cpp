#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5 + 3;
int t;
int n, m, p[MM];
int flead(int x) {
    if (p[x] != x) {
        p[x] = flead(p[x]);
    }
    return p[x];
}
void print(vector<int> &v) {
    for (int i : v) cout << i << ' ';
    cout << '\n';
}
ll min_diff(vector<int> &a, vector<int> &b) {
    ll ret = LLONG_MAX;
    int pa = 0, pb = 0;
    int asz = a.size(), bsz = b.size();
    while (pa < asz && pb < bsz) {
        ret = min(ret, abs(ll(a[pa]) - b[pb]));
        if (a[pa] < b[pb])
            pa++;
        else
            pb++;
    }
    return ret * ret;
}
ll solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (flead(a) != flead(b)) {
            p[flead(a)] = flead(b);
        }
    }
    int p1 = flead(1), pn = flead(n);
    if (p1 == pn) return 0;
    unordered_map<int, vector<int>> sets;
    for (int i = 1; i <= n; i++) {
        int pi = flead(i);
        if (pi == p1)
            sets[1].push_back(i);
        else if (pi == pn)
            sets[n].push_back(i);
        else
            sets[flead(i)].push_back(i);
    }
    vector<int> &start = sets[1], &end = sets[n];
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    ll ret = min_diff(start, end);
    for (auto &p : sets) {
        int ind = p.first;
        auto &arr = p.second;
        if (ind == 1 || ind == n) continue;
        sort(arr.begin(), arr.end());
        ll dis = min_diff(start, arr) + min_diff(arr, end);
        ret = min(ret, dis);
    }
    return ret;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        printf("%lld\n", solve());
    }
}