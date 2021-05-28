//

#include<bits/stdc++.h>
using namespace std;

int D, I, R, dp[1003][1003];
string A, B;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> D >> I >> R >> A >> B;
    A = ' ' + A; B = ' ' + B;
    int n = A.length(), m = B.length();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!i && !j) continue;
            else if (!i) dp[i][j] = I * j;
            else if(!j) dp[i][j] = D * i;
            else {
                if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1] + i, min(dp[i-1][j] + D, dp[i-1][j-1] + R));
            }
        }
    }
    cout << dp[n-1][m-1] << '\n';

    return 0;
}