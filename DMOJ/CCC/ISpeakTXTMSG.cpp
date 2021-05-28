// CCC '07 J2 - I Speak TXTMSG

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

unordered_map<string, string> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    mp["CU"]="see you";
    mp[":-)"]="I'm happy";
    mp[":-("]="I'm unhappy";
    mp[";-)"]="wink";
    mp[":-P"]="stick out my tongue";
    mp["(~.~))"]="sleepy";
    mp["TA"]="totally awesome";
    mp["CCC"]="Canadian Computing Competition";
    mp["CUZ"]="because";
    mp["TY"]="thank-you";
    mp["YW"]="you're welcome";
    mp["TTYL"]="talk to you later";
    while (true){
        string t; cin >> t;
        cout << ((mp[t].size())? mp[t]:t) << nl;
        if (t=="TTYL") break;
    }

    return 0;
}