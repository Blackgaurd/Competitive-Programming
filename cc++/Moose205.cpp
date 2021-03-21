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
using qi = deque<int>;

int n, minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0;
vector<pair<int, int>> p;
vector<int> r;
bool points[305][305];

bool within(int x, int y, pair<int, int> c, int r){
    return (hypot(x-c.first, y-c.second)<=r)?1:0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0, a, b, c; i<n; i++){
        cin >> a >> b >> c;
        minx = min(a-c, minx);
        miny = min(b-c, miny);
        maxx = max(a+c, maxx);
        maxy = max(b+c, maxy);
        p.push_back({a,b});
        r.pb(c);
    }

    

    return 0;
}