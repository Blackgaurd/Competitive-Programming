// Segment Tree Test
// Recursive build function

#include <bits/stdc++.h>
using namespace std;
#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
#define si(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 45)                                           \
            ;                                                                  \
        _sign = x == 45;                                                       \
        if (_sign)                                                             \
            while ((x = getchar()) < 48)                                       \
                ;                                                              \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
        x = _sign ? -x : x;                                                    \
    } while (0)
char _;
bool _sign;
#define ll long long

const int MM = 1e5 + 3;
int n, m, arr[MM], seg[4 * MM];
bool marked[MM];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}
ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) return;
    if (l == tl && tr == r) {
        cout << "setting " << v << '\n';
        seg[v] = new_val;
        marked[v] = true;
    } else {
        if (marked[v]) {
            seg[v * 2] = seg[v * 2 + 1] = seg[v];
            marked[v * 2] = marked[v * 2 + 1] = true;
            marked[v] = false;
        }
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), new_val);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}
int gcd(int v, int tl, int tr, int l, int t) { return 0; }
int main() {
    su(n);  // su(m);
    for (int i = 1; i <= n; i++) su(arr[i]);
    build(1, 1, n);
    cout << "done build\n";
    for (int i = 1; i <= 7; i++) cout << seg[i] << ' ';
    cout << '\n';
    cout << sum(1, 1, n, 2, 3) << '\n';
    update(1, 1, n, 1, 1, 10);
    for (int i = 1; i <= 7; i++) cout << seg[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= 7; i++) cout << marked[i] << ' ';

    return 0;
}