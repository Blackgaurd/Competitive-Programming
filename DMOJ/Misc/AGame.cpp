// A Game

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define watch(a) cout << (#a) << ": " << a << '\n'

const int MM = 1003;
int n, arr[MM];
ll dp[MM][MM];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1){ // algorithm doesn't work for n==1 for some reason
        int a; cin >> a;
        cout << a << '\n';
        return 0;
    }

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for (int i=1; i<n; i++){
        dp[i][i] = arr[i];
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }
    for (int l=3; l<=n; l++){
        for (int i=1; i<=n-l+1; i++){
            int j = i+l-1;
            ll left = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
            ll right = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
            dp[i][j] = max(left, right);
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
