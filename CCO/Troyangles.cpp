// CCO '14 P1 - Troyangles

#include<iostream>
using namespace std;
#define min(a, b) (a<b? a:b)

const int MM = 2003;
int n, dp[MM][MM], cnt = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c; cin >> c;
            dp[i][j] = (c == '#');
        }
    }
    for (int i=n; i>=1; i--){
        for (int j=1; j<=n; j++){
            if (dp[i][j]){
                dp[i][j] = 1 + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
                cnt += dp[i][j];
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}