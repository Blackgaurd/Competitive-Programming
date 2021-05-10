// UCC Coding Competition '21 P2 - Emerald Exchange

#include<bits/stdc++.h>
using namespace std;

int n, a, ans = 0, mx = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        cin >> a;
        if (a&1){mx = max(mx, ans); ans = 0;}
        else ans += a;
    }
    cout << max(ans, mx) << '\n';

    return 0;
}