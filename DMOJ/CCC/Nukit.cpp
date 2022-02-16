// CCC '08 S5 - Nukit

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
// clang-format on

const int MM = 31;
int n, dp[MM][MM][MM][MM];
bool solve(int a, int b, int c, int d) {
    if (a < 0 || b < 0 || c < 0 || d < 0) {
        return true;
    }
    int &ret = dp[a][b][c][d];
    if (ret != -1) return ret;
    ret = false;

    // AABDD
    ret |= !solve(a - 2, b - 1, c, d - 2);
    // ABCD
    ret |= !solve(a - 1, b - 1, c - 1, d - 1);
    // CCD
    ret |= !solve(a, b, c - 2, d - 1);
    // BBB
    ret |= !solve(a, b - 3, c, d);
    // AD
    ret |= !solve(a - 1, b, c, d - 1);

    return ret;
}
int main() {
#ifdef PC
    freopen("Nukit.in", "r", stdin);
    freopen("Nukit.out", "w", stdout);
#endif
    su(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0, a, b, c, d; i < n; i++) {
        su(a);
        su(b);
        su(c);
        su(d);
        cout << (solve(a, b, c, d) ? "Patrick" : "Roland") << '\n';
    }
}