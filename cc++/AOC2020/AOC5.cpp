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
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;


int m = 0;
bool arr[128][8];

int check(string s){
    int hi = 127, lo = 0;
    for (int i=0; i<7; i++){
        if (s[i]=='F'){
            hi = (hi+lo)/2;
        } else{
            lo = (hi+lo)/2+1;
        }
    }
    int l = 0, r = 7;
    for (int i=7; i<10; i++){
        if (s[i]=='R'){
            l = (r+l)/2+1;
        } else{
            r = (r+l)/2;
        }
    }
    arr[lo][l] = true;
    return lo*8+l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while (true){
        string t; cin >> t;
        if (t=="0") break;
        //cout << check(t) << nl;
        m = max(m, check(t));
    }
    //cout << m << nl;
    for (int i=0; i<128; i++){
        for (int j=0; j<8; j++) {
            if (i!=0 && i<120 && !arr[i][j]) m = i*8+j;
        }
        cout << nl;
    }
    cout << m << nl;

    return 0;
}