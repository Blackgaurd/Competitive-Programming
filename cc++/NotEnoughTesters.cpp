// DMOPC '14 Contest 3 P4 - Not Enough Testers!

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
using qi = deque<int>;

const int MM = 1e5;
int t, factors[MM+5];
bool p[MM+5];
unordered_map<int, vector<int>> mp;
int facs(int x){
    int ttl = 1, cnt = 1;
    if (p[x]) return 2;
    while (x%2==0){x/=2; ttl++;}
    for (int i=3; i<=x; i+=2){
        if (p[i]){
            while (x%i==0){x/=i; cnt++;}
            ttl*=cnt; cnt=1;
        }
    }
    return ttl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ms(p, true, MM+1);
    p[1] = false;
    for (int i=4; i<=MM; i+=2) p[i] = false;
    for (int i=3; i<=MM; i+=2){
        for (int j=i+i; j<=MM; j+=i) p[j] = false;
    }
    for (int i=1; i<=MM; i++){
        if (p[i]) factors[i]=2;
        else factors[i]=facs(i);
    }
    for (auto i: factors) cout << i << " ";
    /*scan(t);
    while (t--){
        int k, a, b, cnt=0;
        scan(k); scan(a); scan(b);
        for (int i=a; i<=b; i++){
            if (factors[i]==k) cnt++;
        }
        cout << cnt << nl;
    }*/

    return 0;
}