// Mock CCO '18 Contest 3 Problem 4 - Roger Solves A Classic Rage Tree Problem

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
// clang-format on
char _;
bool _sign;

const int MM = 5e4 + 3;
int n, q, arr[MM], smin[MM][15], smax[MM][25];
int qlog2(int x) { return 31 - __builtin_clz(x); }
int query(int l, int r) {
    int j = qlog2(r - l + 1);
    int mx = max(smax[l][j], smax[r - (1 << j) + 1][j]);
    int mn = min(smin[l][j], smin[r - (1 << j) + 1][j]);
    return mx - mn;
}
int main() {
    su(n);
    su(q);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        smin[i][0] = smax[i][0] = arr[i];
    }
    for (int j = 1; j <= qlog2(n); j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            smin[i][j] = min(smin[i][j - 1], smin[i + (1 << (j - 1))][j - 1]);
            smax[i][j] = max(smax[i][j - 1], smax[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--) {
        int l, r;
        su(l);
        su(r);
        printf("%d\n", query(l - 1, r - 1));
    }

    return 0;
}