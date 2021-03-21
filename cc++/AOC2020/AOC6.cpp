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

set<char> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while (1){
        string t;
        getline(cin, t);
        if (t=="0") break;
        if (t=="\n"){
            cout << s.size() << nl;
            s.clear();
            continue;
        }
        for (auto ch: t) s.insert(ch);
    }

    return 0;
}