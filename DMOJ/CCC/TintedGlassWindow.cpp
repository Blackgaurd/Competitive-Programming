// CCC '14 S4 - Tinted Glass Window

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
#define watch(x) cout << (#x) << ": " << x << '\n'
// clang-format on
using ll = long long;

int n;
ll t, ans;
struct rect {
    int x1, y1, x2, y2, tint;
};
vector<rect> arr;
vector<vector<ll>> psa;
vector<int> cx, cy, revx, revy;
unordered_map<int, int> mpx, mpy;
int main() {
#ifdef PC
    freopen("TintedGlassWindow.in", "r", stdin);
    freopen("TintedGlassWindow.out", "w", stdout);
#endif

    // input
    su(n);
    su(t);
    arr.resize(n);
    cx.resize(n * 2);
    cy.resize(n * 2);
    for (int i = 0; i < n; i++) {
        su(arr[i].y1);
        su(arr[i].x1);
        su(arr[i].y2);
        su(arr[i].x2);
        su(arr[i].tint);
        cx[i] = arr[i].x1;
        cy[i] = arr[i].y1;
        cx[i + n] = arr[i].x2;
        cy[i + n] = arr[i].y2;
    }

    // coord compress
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    int indx = 1, indy = 1;
    for (int i = 0; i < cx.size(); i++) {
        if (i > 0) {
            if (cx[i] != cx[i - 1]) indx++;
            if (cy[i] != cy[i - 1]) indy++;
        }
        mpx[cx[i]] = indx;
        mpy[cy[i]] = indy;
    }
    revx.resize(mpx.size() + 2);
    revy.resize(mpy.size() + 2);
    for (auto [a, b] : mpx) revx[b] = a;
    for (auto [a, b] : mpy) revy[b] = a;

    // psa
    psa.assign(indx + 2, vector<ll>(indy + 2, 0));
    for (auto [x1, y1, x2, y2, tint] : arr) {
        x1 = mpx[x1];
        x2 = mpx[x2];
        y1 = mpy[y1];
        y2 = mpy[y2];
        psa[x1][y1] += tint;
        psa[x1][y2] -= tint;
        psa[x2][y1] -= tint;
        psa[x2][y2] += tint;
    }
    for (int i = 1; i < psa.size(); i++) {
        for (int j = 1; j < psa[0].size(); j++) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1];
            psa[i][j] -= psa[i - 1][j - 1];
            if (psa[i][j] >= t) {
                ll l = revx[i + 1] - revx[i], w = revy[j + 1] - revy[j];
                ans += l * w;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}