// Facebook Hacker Cup 2015 Round 2

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

int t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    scan(t);
    while (t--){
        int n, mx, mn; scan(n);
        vi arr;
        for (int i=0, a; i<n; i++){
            scan(a); arr.pb(a);
        }
        mx = mn = arr[0];
        bool solve = true;
        for (int i=1; i<n; i++){
            if (arr[i]<=mn){
                mn = arr[i];
                continue;
            }
            if (arr[i]>=mx){
                mx = arr[i];
                continue;
            }
            solve = false;
        }
        cout << (solve?"Yes":"No") << nl;
    }

    return 0;
}