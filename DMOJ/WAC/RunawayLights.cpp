// Wesley's Anger Contest 6 Problem 4 - Runway Lights
// please have mercy

#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const ll mod = 998244353;
ll n, k, cnt = 0, loops;
ll w = 0, a = 0, c = 0,
wa = 0, wac = 0,
aw = 0, awc = 0,
ac = 0, acw = 0,
ca = 0, caw = 0, 
cw = 0, cwa = 0,
wc = 0, wca = 0;
ll initw = 0, inita = 0, initc = 0;
string t = "";
ll mul_mod(ll a, ll b, ll m=mod) { // a*b%m
    if (!a || !b) return 0;
    ll r = 0;
    while (a > 0) {
        if (a & 1)
            if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}
ll choose(int x){
    ll ans = mul_mod(x, x-1);
    ans = mul_mod(ans, x-2);
    ans/=6;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; i++){
        char ch; cin >> ch;
        if (ch=='W'){
            initw++;
            t+=ch;
        }
        else if (ch=='A'){
            inita++;
            t+=ch;
        }
        else if (ch=='C'){
            initc++;
            t+=ch;
        }
    }
    if (!initw || !inita || !initc){
        cout << 0 << '\n';
        return 0;
    }
    for (char x: t){
        if (x=='W'){
            w++;
            aw+=a;
            cw+=c;
            acw+=ac;
            caw+=ca;
        }
        else if (x=='A'){
            a++;
            wa+=w;
            ca+=c;
            wca+=wc;
            cwa+=cw;
        }
        else if (x=='C'){
            c++;
            wc+=w;
            ac+=a;
            awc+=aw;
            wac+=wa;
        }
        w%=mod;
        a%=mod;
        c%=mod;
        aw%=mod;
        cw%=mod;
        acw%=mod;
        caw%=mod;
        wa%=mod;
        ca%=mod;
        wca%=mod;
        cwa%=mod;
        wc%=mod;
        ac%=mod;
        awc%=mod;
        wac%=mod;
    }
    cnt+=mul_mod(choose(k+2), wac%mod);
    cnt%=mod;
    cnt+=mul_mod(choose(k), caw%mod);
    cnt%=mod;
    cnt+=mul_mod(choose(k+1), acw%mod);
    cnt%=mod;
    cnt+=mul_mod(choose(k+1), wca%mod);
    cnt%=mod;
    cnt+=mul_mod(choose(k+1), cwa%mod);
    cnt%=mod;
    cnt+=mul_mod(choose(k+1), awc%mod);
    cnt%=mod;
    cout << cnt << '\n';
    
    return 0;
}