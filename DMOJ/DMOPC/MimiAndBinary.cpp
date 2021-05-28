// DMOPC '17 Contest 5 P2 - Mimi and Binary

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

string t;
int q, one[200003], zero[200003];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    one[0] = 0; zero[0] = 0;
    for (int i=0; i<t.size(); i++){
        zero[i+1] = zero[i];
        one[i+1] = one[i];
        if (t[i]=='0') zero[i+1]++;
        else if (t[i]=='1') one[i+1]++;
    }
    scan(q);
    while (q--){
        int x, y, z;
        scan(x); scan(y); scan(z);
        

    }

    return 0;
}