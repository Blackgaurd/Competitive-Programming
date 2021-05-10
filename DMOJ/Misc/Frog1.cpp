// Frog 1

#include<cstdio>
#include<algorithm>

int n, h[(int)1e5+3], dp[(int)1e5+3];
int main(){
    scanf("%d", &n);
    scanf("%d%d", &h[1], &h[2]);
    dp[2] = abs(h[2] - h[1]);
    for (int i=3; i<=n; i++){
        scanf("%d", &h[i]);
        dp[i] = std::min(abs(h[i] - h[i-1]) + dp[i-1], abs(h[i] - h[i-2]) + dp[i-2]);
    }
    printf("%d\n", dp[n]);

    return 0;
}