// CCC '05 S2 - Mouse Move

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

int r, c, x = 0, y = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> c >> r;
    while (true){
        int a, b; cin >> a >> b;
        if (a==0 && b==0) break;
        x+=a; y+=b;
        if (x<0) x = 0;
        else if (x>c) x = r;
        if (y<0) y = 0;
        else if (y>r) y = r;
        cout << x << " " << y << nl;
    }

    return 0;
}