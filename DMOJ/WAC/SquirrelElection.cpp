// Wesley's Anger Contest 4 Problem 2 - Squirrel Election

#include<stdio.h>
#define max(a, b) (a>b? a:b)

const int MM = 5003;
int n, val[MM], wt[MM], maxW = 0, maxV = 0, dp[MM * MM / 2];
int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d%d", &val[i], &wt[i]);
        val[i] = val[i] / 2 + 1;
        maxW += wt[i];
        maxV += val[i];
    }
    int maj = (maxW&1 ? maxW / 2 : maxW / 2 - 1);
    for (int i=0; i<n; i++){
        for (int j=maj; j>=wt[i]; j--){
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    printf("%d\n", maxV - dp[maj]);

    return 0;
}
