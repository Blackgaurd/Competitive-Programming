// The Mirror

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

int n;
bool p[505];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    p[1] = true;
    for (int i=4; i<=500; i+=2) p[i] = true;
    for (int i=3; i<=500; i+=2){
        for (int j=i+i; j<=500; j+=i) p[j] = true;
    }
    cin >> n;
    while (n--){
        int a, b, cnt=0; cin >> a >> b;
        for (int i=a; i<b; i++){
            if (!p[i]) cnt++;
        }
        cout << cnt << nl;
    }

    return 0;
}