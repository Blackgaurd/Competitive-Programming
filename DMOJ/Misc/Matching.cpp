// Matching

#include<stdio.h>
#include<string.h>

const int MOD = 1e9+7;
int n, arr[21], dp[21][1<<21];
int solve(int cur, int mask){
    if (cur == n) return 1;
    if (dp[cur][mask] != -1) return dp[cur][mask];
    int &ret = dp[cur][mask];
    ret = 0;
    for (int i=0; i<n; i++){
        // cout << (!(mask & (1 << i))) << (arr[cur] & (1 << i)) << '\n';
        if ((mask & (1 << i)) == 0 && (arr[cur] & (1 << i))){
            ret += solve(cur + 1, mask | (1 << i));
            ret %= MOD;
        }
    }
    return ret;
}
int main(){
    scanf("%d\n", &n);
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i] <<= 1;
            arr[i] |= (getchar() == '1');
            getchar();
        }
    }
    printf("%d\n", solve(0, 0));

    return 0;
}