// Bob's Challenge

#include<stdio.h>
#define MOD 1000000007

int n, dp[1000003];
int main(){
    scanf("%d", &n);
    dp[0] = 1;
    for (int k=1; k<=n; k*=2){
        for (int i=k; i<=n; i++){
            dp[i] += dp[i - k];
            dp[i] %= MOD;
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
