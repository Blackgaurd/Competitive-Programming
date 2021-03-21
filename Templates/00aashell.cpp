// 

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

// sb = bool (1, 0), su = unsigned integer type, si = signed integer type
#define sb(x) do{while((_=getchar())<48); x=(_-48);}while(0)
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;

#define gc getchar_unlocked()
template<typename T> void sc2(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T, typename...A> void sc2(T&t, A&...a){sc2(t);sc2(a...);}

#define ms(arr, val) memset(arr, val, sizeof(arr))
#define watchd(x) cout << (#x) << ": " << (x) << '\n'
template<typename T, typename...A> void watch(T&t, A&...a) {watchd(t); watchd(a...);}
#define ull unsigned long long

#define iosync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define nl '\n'
#define ll long long
#define ull unsigned long long

ull mul_mod(ull a, ull b, ull m=ULLONG_MAX) { // a*b%m
    ull r = 0;
    while (a > 0) {
        if (a & 1)
            if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull qpow(ull a, ull n, ull m=ULLONG_MAX) { // (a^n)%m
    ull r = 1;
    while (n > 0) {
        if (n & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}

int p[1];
int flead(int x){
    if (p[x]!=x) p[x] = flead(p[x]);
    return p[x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cout << INT_MIN << nl;

    return 0;
}
