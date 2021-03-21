// CCC '16 S5 - Circle of Life

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll n, t, len = 0;
string circle;
vector<string> pattern;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(t); cin >> circle;
    pattern.pb(circle);
    for (len; len<t; len++){
        string copy = circle;
        for (int j=1; j<n-1; j++){
            copy[j] = (circle[j-1]^circle[j+1]? '1':'0');
        }
        copy[0] = (circle[1]^circle[n-1]? '1':'0');
        copy[n-1] = (circle[0]^circle[n-2]? '1':'0');
        if (copy==pattern[0] || copy==pattern[len-1]){
            break;
        }
        circle = copy;
        pattern.pb(circle);
    }
    for (auto i: pattern) cout << i << nl;


    return 0;
}
