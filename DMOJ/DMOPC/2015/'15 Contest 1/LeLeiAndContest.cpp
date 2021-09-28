// DMOPC '15 Contest 1 P6 - Lelei and Contest

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 2e5;
int n, q, m;
ll arr[MM], seg[4 * MM];
void build(int cur, int tl, int tr) {
    if (tl == tr)
        seg[cur] = arr[cur];
    else {
        int tm = (tl + tr) / 2;
        build(cur * 2, tl, tm);
        build(cur * 2 + 1, tm + 1, tr);
        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}
void update(int cur, int tl, int tr, int l, int r, int add) {
    if (l > r) return;
    if (l == tl && r == tr)
        seg[cur] += add;
    else {
        int tm = (tl + tr) / 2;
        update(cur * 2, tl, tm, l, min(r, tm), add);
        update(cur * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}
ll sum(int cur, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) return seg[cur];
    int tm = (tl + tr) / 2;
    if (l > tm) return sum(2 * cur + 1, tm + 1, tr, l, r);
    if (r <= tm) return sum(2 * cur, tl, tm, l, r);
    return sum(2 * cur, tl, tm, l, tm) +
           sum(2 * cur + 1, tm + 1, tr, tm + 1, r);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> q;
    watch(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0, c; i < q; i++) {
        cin >> c;
        if (c == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            // update(1, 0, n-1, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            // watch(r);
            ll ans = sum(1, 0, n - 1, l - 1, r - 1);
            printf("%lld\n", ans);
        }
    }

    return 0;
}