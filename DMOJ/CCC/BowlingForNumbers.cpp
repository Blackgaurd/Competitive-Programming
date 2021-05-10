// CCC '07 S5 - Bowling for Numbers

#include<iostream>
#define max(a, b) (a>b? a:b)

int t, n, k, w, psa[30003], dp[503][30003];
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d%d%d", &n, &k, &w);
        for (int i=1; i<=n; i++){
            int a; scanf("%d", &a);
            psa[i] = psa[i-1] + a;
        }
        for (int i=1; i<=k; i++){
            for (int j=1; j<=n; j++){
                if (j<=w) dp[i][j] = psa[j];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j-w] + psa[j] - psa[j-w]);
            }
        }
        printf("%d\n", dp[k][n]);
    }

    return 0;
}