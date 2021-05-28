// Coin Change

#include<cstdio>
#include<algorithm>
#include<string.h>

int x, n, dp[10003];
int main(){
    scanf("%d%d", &x, &n);
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<n; i++){
        int w; scanf("%d", &w);
        for (int j=w; j<=x; j++)
            dp[j] = std::min(dp[j], dp[j-w]+1);
    }
    printf("%d\n", dp[x]);
    return 0;
}