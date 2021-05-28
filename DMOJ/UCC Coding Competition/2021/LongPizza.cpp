// UCC Coding Competition '21 P3 - Long Pizza

#include<bits/stdc++.h>
using namespace std;

int n, r, x, y;
long long ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x >> y >> r;
    if (y > n) y = n;
    if (x < 1) x = 1;
    while (r--){
        int a, b; cin >> a >> b;
        if ((a < x && b < x) || (a > y && b > y)) continue;
        if (a <= x){
            if (b >= y) ans += (y-x+1);
            else ans += (b-x+1);
        }
        else {
            if (b >= y) ans += (y-a+1);
            else ans += (b-a+1);
        }
    }
    cout << ans << '\n';

    return 0;
}