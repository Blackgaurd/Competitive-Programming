// CCC '09 S5 - Wireless

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

const int MM = 30005, MN = 1005;
int n, m, k, x, y, r, b;
int arr[MM][MN];
int main() {
#ifdef PC
    freopen("Wireless.in", "r", stdin);
    freopen("Wireless.out", "w", stdout);
#endif
    su(n);
    su(m);
    su(k);
    while (k--) {
        su(x);
        su(y);
        su(r);
        su(b);
        for (int i = max(1, y - r); i <= min(MM - 1, y + r); i++) {
            int t = i - y;
            int j = sqrt(r * r - t * t);
            arr[i][max(1, x - j)] += b;
            arr[i][min(MN - 2, x + j) + 1] -= b;
        }
    }
    int mx = -1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] += arr[i][j - 1];
            if (arr[i][j] > mx) {
                mx = arr[i][j];
                cnt = 1;
            } else if (arr[i][j] == mx)
                cnt++;
        }
    }
    printf("%d\n%d\n", mx, cnt);

    return 0;
}
