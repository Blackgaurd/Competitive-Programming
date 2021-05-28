// DMOPC '18 Contest 6 P3 - Wish Upon a Star

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

const int MM = 2e5+5;
int n, m, p[MM], extra = 0;
int find_leader(int x){
    if (p[x]!=x) p[x] = find_leader(p[x]);
    return p[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    scan(n); scan(m);
    for (int i=1; i<=n; i++) p[i] = i;
    for (int i=0; i<m; i++){
        int a, b; scan(a); scan(b);
        int fa = find_leader(a), fb = find_leader(b);
        if (fa!=fb) p[fa] = fb;
        else extra++;
    }
    cout << (extra>1? "NO":"YES") << nl;

    return 0;
}