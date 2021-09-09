// DMOPC '20 Contest 2 P2 - Lousy Christmas Presents

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

const int MM = 1e6+5;
int n, m, lo[MM], hi[MM], ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n); scan(m);
    for (int i=1; i<=n; i++){
        int a; scan(a);
        if (!lo[a]) lo[a] = hi[a] = i;
        else hi[a] = i;
    }
    for (int i=0; i<m; i++){
        int a, b; scan(a); scan(b);
        //cout << "a: " << lo[a] << " " << hi[a] << nl;
        //cout << "b: " << lo[b] << " " << hi[b] << nl;
        if (!lo[a] || !lo[b]) continue;
        ans = max(ans, hi[b]-lo[a]+1);
    }
    cout << ans << nl;


    return 0;
}