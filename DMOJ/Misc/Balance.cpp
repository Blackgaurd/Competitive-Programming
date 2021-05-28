// Balance

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"

int n, arr[10], pre[11], sum = 0, sol = INT_MAX;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    pre[0] = 0;
    for (int i=0; i<n; i++){
        pre[i+1] = pre[i]+arr[i];
        sum+=arr[i];
    }
    for (int i=0; i<=n; i++)
        sol = min(sol, abs(pre[i]*2-sum));
    cout << sol << nl;

    return 0;
}