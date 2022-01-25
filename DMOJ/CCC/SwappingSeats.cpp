// CCC '20 S4 - Swapping Seats

#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
vector<int> psaa, psab, psac;
void fun(vector<int> &x, vector<int> &y, int i) {
    int nx = x[n], ny = y[n];
    int sum = ny - (y[i] - y[i - ny]) + nx - (x[i - ny] - x[i - nx - ny]);
    int inter = min(y[i - ny] - y[i - ny - nx], x[i] - x[i - ny]);
    ans = min(ans, sum - inter);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t;
    cin >> t;
    n = t.size();
    psaa.resize(n + 1);
    psab.resize(n + 1);
    psac.resize(n + 1);
    for (int i = 0; i < n; i++) {
        psaa[i + 1] = psaa[i] + (t[i] == 'A');
        psab[i + 1] = psab[i] + (t[i] == 'B');
        psac[i + 1] = psac[i] + (t[i] == 'C');
    }
    int na = psaa[n], nb = psab[n], nc = psac[n];
    for (int i = 1; i <= n; i++) {
        if (i >= na + nb) {
            fun(psaa, psab, i);
            fun(psab, psaa, i);
        }
        if (i >= na + nc) {
            fun(psaa, psac, i);
            fun(psac, psaa, i);
        }
        if (i >= nc + nb) {
            fun(psac, psab, i);
            fun(psab, psac, i);
        }
    }
    cout << ans << '\n';
}