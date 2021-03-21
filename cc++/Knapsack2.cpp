// Knapsack 2

#include<bits/stdc++.h>
using namespace std;

int N, W;
long long dp[100003];
int main(){
    scanf("%d%d", &N, &W);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<N; i++){
        long long wt, val; scanf("%lld%lld", &wt, &val);
        for (int j=100000; j>=val; j--){
            dp[j] = min(dp[j], dp[j-val]+wt);
        }
    }
    for (int i=100000; i>=0; i--)
        if (dp[i]<=W) {printf("%d", i); break;}

    return 0;
}