// Exponentiation

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef long long ll;

ll qpow(ll a, ll exp, ll mod = 1e9+7) {  // (a ^ exp) % mod
    if (!exp) return 1;
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * a % mod;
        a = a * a % mod;
        exp >>= 1;
    }
    return ret;
}
int main(){
    int n;
    su(n);
    while (n--){
        int a, b; su(a); su(b);
        printf("%lld\n", qpow(a, b));
    }
}
