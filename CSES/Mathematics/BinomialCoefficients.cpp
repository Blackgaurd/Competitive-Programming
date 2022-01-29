// Binomial Coefficients

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

const int MM = 1e6 + 3, MOD = 1e9 + 7;
ll fact[MM], invfact[MM];
ll qpow(ll a, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        exp >>= 1;
    }
    return ret;
}
void fermat() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MM; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = qpow(fact[i], MOD - 2);
    }
}
ll nck(int a, int b) {
    return (fact[a] * (invfact[b] * invfact[a - b] % MOD)) % MOD;
}
int main(){
    fermat();
    int n;
    su(n);
    while (n--){
        int a, b;
        su(a); su(b);
        printf("%lld\n", nck(a, b));
    }
}