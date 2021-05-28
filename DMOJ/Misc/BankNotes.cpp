// Bank Notes
// Coin change but with more elements
// Compress to logN elements

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, k, dp[20003];
vector<int> vals;
vector<pii> arr; // {wt, val}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        vals.push_back(a);
    }
    for (int i=0; i<n; i++){
        int a; cin >> a;
        for (int cnt=1; cnt<=a; cnt <<= 1)
            arr.push_back({cnt * vals[i], cnt});
    }
    cin >> k; // max W
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (pii p: arr){
        int v = p.second, w = p.first;
        for (int j=k; j>=w; j--)
            dp[j] = min(dp[j], dp[j-w]+v);
    }
    cout << dp[k] << '\n';

    return 0;
}