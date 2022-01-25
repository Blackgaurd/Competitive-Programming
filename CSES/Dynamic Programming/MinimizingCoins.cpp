// Minimizing Coins
// unlimited knapsack

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

int n, x;
int main() {
    su(n);
    su(x);
    vector<int> dp(x + 1, INT_MAX / 2);
    dp[0] = 0;
    for (int i = 0, c; i < n; i++) {
        su(c);
        for (int j = c; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    printf("%d\n", dp[x] == INT_MAX / 2 ? -1 : dp[x]);
}