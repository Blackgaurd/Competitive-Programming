// DMOPC '16 Contest 4 P2 - Systests

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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    map<pii, int> mp;
    int ttl = 0;
    int b; scan(b);
    for (int i=0; i<b; i++){
        int f, e, p; scan(f); scan(e); scan(p);
        mp.insert(make_pair(make_pair(f, e), p));
        ttl+=p;
    }
    int f; scan(f);
    for (int i=0; i<f; i++){
        int t; scan(t);
        for (const auto &p: mp){
            pii cur = p.first;
            if (cur.first<=t && t<=cur.second){
                ttl-=p.second;
                mp[p.first] = 0;
            }
        }
    }
    cout << ttl;

    return 0;
}