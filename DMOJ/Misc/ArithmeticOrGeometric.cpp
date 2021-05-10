// Arithmetic Or Geometric

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int md = 1e9+7;
int t, a, b, c, n;

ll pow(int base, int exp){
    if (exp==0) return 1;
    ll tmp = pow(base, exp/2);
    tmp%=md;
    tmp*=tmp;
    tmp%=md;
    if (exp%2==0) return tmp;
    return tmp*base%md;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> a >> b >> c >> n;
        if (a-b == b-c){
            cout << (a+(n-1)*(b-a))%md << "\n";
        } else{
            ll ans = a*pow(b/a,n-1)%md;
            cout << ans << "\n";
        }
    }

    return 0;
}