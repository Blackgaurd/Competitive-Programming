// DWITE '12 R5 #3 - Triangle Count

#include<bits/stdc++.h>
using namespace std;

const int MM = 260;
int n, dp[MM][MM], ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int e=0; e<5; e++){
        cin >> n;
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                char c; cin >> c;
                if (c=='#') dp[i][j] = 1;
            }
        }
        for (int i=n; i>=1; i--){
            for (int j=1; j<=n; j++){
                if (dp[i][j]){
                    dp[i][j] = min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1])) + 1;
                    ans += dp[i][j];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}