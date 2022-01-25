// Grid Paths

#include <cstdio>
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
#define max(a, b) (a > b ? a : b)

const int MM = 1e3 + 3, MOD = 1e9 + 7;
int n, dp[MM][MM];
int main() {
    su(n);
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            sc(c);
            dp[i][j] = -1;
            if (c != '*') {
                dp[i][j] = max(dp[i - 1][j], 0) + max(dp[i][j - 1], 0);
                dp[i][j] %= MOD;
            }
        }
    }
    printf("%d\n", dp[n][n] == -1 ? 0 : dp[n][n]);
}