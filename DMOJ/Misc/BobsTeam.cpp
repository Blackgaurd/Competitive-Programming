// Bob's Team
// lower_bound

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

int n;
vector<int> a, b, c;
vector<ll> psa;
ll ans = 0;
int main() {
    su(n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    psa.resize(n);
    for (int i = 0; i < n; i++) su(a[i]);
    for (int i = 0; i < n; i++) su(b[i]);
    for (int i = 0; i < n; i++) su(c[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        psa[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (i != 0) psa[i] += psa[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        if (ind == 0)
            ans += 0;
        else
            ans += psa[ind - 1];
    }
    printf("%lld\n", ans);
}