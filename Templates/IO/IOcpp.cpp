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
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

#define gc getchar_unlocked()
template<typename T> void sc2(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T, typename...A> void sc2(T&t, A&...a){sc2(t);sc2(a...);}

#define ms(arr, val) memset(arr, val, sizeof(arr))
#define watch(x) cout << (#x) << ": " << (x) << '\n'

#define iosync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef deque<int> qi;

#define nl '\n'
#define ll long long
#define ull unsigned long long

ull mul_mod(ull __a, ull __b, ull __mod=ULLONG_MAX) { // __a * __b % __mod
    ull __ret = 0;
    while (__a > 0) {
        if (__a & 1)
            if((__ret += __b) > __mod) __ret %=__mod;
        __a >>= 1;
        if ((__b <<= 1) > __mod) __b %= __mod;
    }
    return __ret;
}

ull qpow(ull __a, ull __exp, ull __mod=ULLONG_MAX) { // (__a ^ __exp) % __mod
    if (!__exp) return 1;
    ull __ret = 1;
    while (__exp > 0) {
        if (__exp & 1)
            __ret = mul_mod(__ret, __a, __mod);
        __a = mul_mod(__a, __a, __mod);
        __exp >>= 1;
    }
    return __ret;
}

int p[1];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
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
