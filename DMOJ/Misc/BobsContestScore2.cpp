// Bob's Contest Score 2

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

const int MM = 1001;
int n, ans = 0;
bool dp[MM][15 * MM];
int main() {
    su(n);
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        int a;
        su(a);
        for (int j = 1; j < 15 * MM; j++) {
            dp[i][j] |= dp[i - 1][j];
            if (j >= a) {
                dp[i][j] |= dp[i - 1][j - a];
            }
        }
    }

    for (int i = 0; i < 15 * MM; i++) {
        ans += dp[n][i];
    }
    printf("%d\n", ans);
}
