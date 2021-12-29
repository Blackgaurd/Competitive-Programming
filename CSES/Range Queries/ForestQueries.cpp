// Forest Queries

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

const int MM = 1e3 + 3;
int n, q, psa[MM][MM];
int main() {
    su(n);
    su(q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            sc(c);
            psa[i][j] = c == '*';
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    while (q--) {
        int a, b, c, d;
        su(a);
        su(b);
        su(c);
        su(d);
        printf("%d\n", psa[c][d] - psa[a - 1][d] - psa[c][b - 1] + psa[a - 1][b - 1]);
    }

    return 0;
}