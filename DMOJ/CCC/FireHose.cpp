// CCC '10 S3 - Firehose

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

const int MM = 1e6;
int h, houses[MM], k;

int check(int x){
    int sol = h;
    for (int start = 0; houses[start]<=houses[0]+x*2 && start<h; start++){
        int cnt = 1;
        for (int nxt = start+1, last = houses[start]; nxt<h && houses[nxt]+x*2-MM<houses[start]; nxt++){
            if (houses[nxt]>last) {last = houses[nxt]+x*2; cnt++;}
        }
        sol = min(sol, cnt);
    }
    return sol;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(h);
    for (int i=0; i<h; i++) scan(houses[i]);
    sort(houses, houses+h);
    scan(k);
    int lo = 0, hi = MM, ans = 0;
    while (lo<=hi){
        int mid = (lo+hi)/2;
        if (check(mid)<=k) {hi = mid-1; ans = mid;}
        else lo = mid+1;
    }
    cout << ans << nl;

    return 0;
}