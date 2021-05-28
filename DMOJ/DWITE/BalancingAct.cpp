// DWITE '10 R5 #3 - Balancing Act

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int ttl){
    int n = arr.size();
    vector<vector<bool>> dp(2, vector<bool> (ttl + 3, false));
    for (int i=0; i<=n; i++){
        for (int j=0; j<=ttl; j++){
            if (!j) dp[i&1][0] = true;
            else if (!i) dp[i&1][j] = false;
            else if (arr[i - 1] <= j) dp[i&1][j] = dp[(i+1)&1][j] || dp[(i+1)&1][j - arr[i - 1]];
            else dp[i&1][j] = dp[(i+1)&1][j];
        }
    }
    return dp[n&1][ttl];
}
int main(){
    int e = 5;
    while (e--){
        int n, sum = 0; scanf("%d", &n);
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        int ans = 0;
        for (int i=sum/2; i>=1; i--){
            if (check(arr, i)){
                ans = i;
                break;
            }
        }
        printf("%d\n", abs(2 * ans - sum));

    }

    return 0;
}