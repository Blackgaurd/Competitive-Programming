// An Animal Contest 4 P2 - Lavish Lights
// int overflow :weary:

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
#define watch(x) cout << (#x) << ": " << x << '\n'
typedef long long ll;

const int MM = 2e5 + 3;
int n, q;
ll psa[MM];  // first k lights will all be on at times multiples of lcm(arr[1..k])
ll lcm(ll a, ll b) {
    __uint128_t tmp = __uint128_t(a) * __uint128_t(b);
    if (tmp > LLONG_MAX) return LLONG_MAX;
    return a * b / gcd(a, b);
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    psa[0] = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        su(psa[i]);
        if (i != 1) psa[i] = lcm(psa[i], psa[i - 1]);
    }
    while (q--) {
        ll t;
        su(t);
        /* if (t == 0) {
            printf("-1\n");
            continue;
        } */
        int lo = 1, hi = n, ans = -100;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (t % psa[mid] == 0) {
                lo = mid + 1;
                ans = mid;
            } else
                hi = mid - 1;
        }
        if (ans == n)
            ans = -2;
        else if (ans == -100)
            ans = 0;
        printf("%d\n", ans + 1);
    }

    return 0;
}