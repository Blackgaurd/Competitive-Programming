#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

string mask = "", fin = "";
unordered_map<string, ll> mp;
set<string> vals;
unsigned long long sum = 0;

ll qpow(ll base, ll exp){
    if (exp==0) return 1;
    ll tmp = qpow(base, exp/2);
    tmp = tmp*tmp;
    if (exp%2==0) return tmp;
    return tmp*base;
}
string to_bin(ll x){
    string b = "";
    while (x) {b=(x&1?"1":"0")+b; x=x>>1;}
    while (b.size()!=36) b="0"+b;
    return b;
}
ll to_dec(string x){
    ll n = 0, bin = stoi(x);
    ll tmp = bin, base = 1;
    while (tmp){
        ll l=tmp%10;
        tmp/=10;
        n+=l*base;
        base=base<<1;
    }
    return n;
} 
ll app_mask(int x){
    string bin = to_bin(x);
    for (int i=35; i>=0; i--){
        if (mask[i]=='X') continue;
        bin[i] = mask[i];
    }
    return to_dec(bin);
}
int main(){
    while (true){
        string t; getline(cin, t);
        if (t=="0") break;
        if (t[1]=='a'){
            mask = t.substr(7, 36);
        }
        else if (t[1]=='e'){
            vector<ll> nums;
            for (int i=4; i<t.size(); i++){
                ll n = 0;
                if (t[i]=='0'){
                    nums.push_back(0);
                    continue;
                }
                while (isdigit(t[i])){
                    n = n*10+t[i]-'0';
                    i++;
                }
                if (n){
                    nums.push_back(n); i--;
                }
                
            }
            //cout << nums[0] << " " << app_mask(nums[1]) << nl;
            fin+=to_string(nums[0])+" "+to_string(app_mask(nums[1]))+"\n";
            //mp.insert(pair<string, ll> (to_string(nums[0]), app_mask(nums[1])));
            //if (!mp[nums[0]]) mp[nums[0]] = 0;
            //mp[nums[0]] = app_mask(nums[1]);
            //vals.insert(to_string(nums[0]));
        }
    }
    //for (auto i: vals) {cout << i << ": " << mp[i] << nl; sum+=mp[i];}
    //cout << sum << nl;
    cout << fin << nl;
    
}