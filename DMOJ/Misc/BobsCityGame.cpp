// Bob's City Game
// 40% partials

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

const int MM = 503;
int h, w, n, arr[MM][MM], ans = INT_MAX;
int main() {
    su(h);
    su(w);
    su(n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            su(arr[i][j]);
        }
    }

    for (int i1 = 0; i1 <= h - n; i1++) {
        for (int j1 = 0; j1 <= w - n; j1++) {
            int mx = 0, mn = INT_MAX;
            for (int i2 = 0; i2 < n; i2++) {
                for (int j2 = 0; j2 < n; j2++) {
                    mx = max(mx, arr[i1 + i2][j1 + j2]);
                    mn = min(mn, arr[i1 + i2][j1 + j2]);
                }
            }
            ans = min(ans, mx - mn);
        }
    }
    printf("%d\n", ans);

    return 0;
}