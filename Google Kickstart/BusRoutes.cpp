// Bus Routes

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e3 + 3;
int t, n;
ll d, arr[MM];
void solve(int case_num){
    cin >> n >> d;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=n; i>=1; i--){
        d = (d / arr[i]) * arr[i];
    }
    cout << "Case #" << case_num << ": " << d << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++){
        solve(i);
    }

    return 0;
}