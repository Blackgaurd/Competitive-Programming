// 

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

const int MM = 1e9+1;
int n;
void solve(ll n, int dep){
    //cout << n << nl;
    if (n>1e12 || dep>1000) {cout << "INFINITY" << nl; return;}
    ll sum = 1;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0) {
            sum+=i; 
            if (i!=sqrt(n)) sum+=n/i;
        }
    }
    if (sum==1) {cout << n << " " << dep << nl; return;}
    solve(sum, dep+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n;
    for (int i=0; i<n; i++){
        ll a; cin >> a;
        solve(a, 0);
        //cout << nl;
    }

    return 0;
}