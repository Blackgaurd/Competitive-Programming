// CCC '02 S2 - Fraction Action

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

int n, d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> d;
    if (n%d==0) cout << n/d;
    else{
        int w = n/d, f = n%d, gcd = __gcd(f, d);
        if (w) cout << w << " ";
        cout << f/gcd << "/" << d/gcd;
    }

    return 0;
}