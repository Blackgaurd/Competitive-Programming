//

#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m, dp[1003][1003];
char a[1003], b[1003];
int main(){
    scanf("%d%d %s %s", &n, &m, a+1, b+1);
    for (int i=0; i<max(n, m); i++){
        dp[0][i] = dp[i][0] = (i+2)/3;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + 1;
            for (int k=1; k<=3; k++){
                if (i>=k) dp[i][j] = min(dp[i][j], dp[i-k][j] + 1);
                if (j>=k) dp[i][j] = min(dp[i][j], dp[i][j-k] + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);

    return 0;
}