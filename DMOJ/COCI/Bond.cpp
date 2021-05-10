// COCI '06 Contest 1 #5 Bond

#include<bits/stdc++.h>
using namespace std;

int n;
double arr[20][20], dp[1<<20];
double solve(int bond, int mask){
    if (dp[mask] != -1) return dp[mask];
    if (bond >= n) return 1.0;
    double ret = 0.0;
    for (int i=0; i<n; i++){
        if (!(mask & (1 << i))){
            ret = max(ret, arr[bond][i] * solve(bond+1, mask | 1 << i));
        }
    }
    return dp[mask] = ret;
}
int main(){
    fill(dp, dp+(1<<20), -1);
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%lf", &arr[i][j]);
            arr[i][j] /= 100.0;
        }
    }
    printf("%.7f\n", solve(0, 0)*100.0);

    return 0;
}