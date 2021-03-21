// Pick It

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while (true){
        int n; scan(n);
        vi arr, sum;
        if (n==0) break;
        for (int i=0; i<n; i++){int a; scan(a); arr.pb(a);}
        sum.pb(arr[0]+arr[1]);
        for (int i=1; i<n-1; i++){
            sum.pb(arr[i-1]+arr[i]+arr[i+1]);
        }
        sum.pb(arr[n-1]+arr[n-2]);
    }

    return 0;
}