// DMOPC '14 Contest 3 P5 - Not Enough Servers!

#include <stdio.h>
#include <string.h>
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1 << 20;
int n, m, res, dp[MM], cases[50], pre[MM],
    key[MM];  // cases = weights in knapsack
char c;
int main() {
    su(n);
    su(m);
    for (int i = 0; i < n; i++) {
        res <<= 1;
        for (int j = 0; j < m; j++) {
            sc(c);
            res |= (c == 'X');
            cases[j] <<= 1;
            cases[j] |= (c == 'X');
        }
    }
    if (!res)
        printf("1\n1\n");
    else {
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int mask = j | cases[i];
                if (dp[mask] > dp[j] + 1) {
                    dp[mask] = dp[j] + 1;
                    key[mask] = i + 1;
                    pre[mask] = j;
                }
            }
        }
        printf("%d\n", dp[res]);
        for (int cur = res; cur != 0; cur = pre[cur]) printf("%d ", key[cur]);
        printf("\n");
    }

    return 0;
}