// USACO 2019 February Silver P2 - Painting the Barn

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

const int MM = 1003;
int n, k, psa[MM][MM], ans = 0;
int main() {
    su(n);
    su(k);
    for (int i = 0, a, b, c, d; i < n; i++) {
        su(a);
        su(b);
        su(c);
        su(d);
        a++;
        b++;
        c++;
        d++;
        psa[a][b]++;
        psa[c][d]++;
        psa[a][d]--;
        psa[c][b]--;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
            ans += (psa[i][j] == k);
        }
    }
    printf("%d\n", ans);

    return 0;
}
