// DMOPC '20 Contest 4 P1 - Missing Numbers

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define wt(x) cout << (#x) << ": " << (x) << '\n'

ll t, n, s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> s;
        ll sum = ((n+1) * n) / 2 - s;
        // wt(sum);
        // make sum using 2 numbers from  1...n
        if (sum - 1 <= n){
            cout << (sum - 1) / 2 << '\n';
        }
        else {
            ll bot = sum - n;
            cout << (n - bot + 1) / 2 << '\n';
        }
    }

    return 0;
}