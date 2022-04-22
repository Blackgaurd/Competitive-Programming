// Common Divisors

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

int n, x, ans = 1;
bool fac[int(1e6) + 1];
int main() {
    su(n);
    while (n--) {
        su(x);
        for (int i = 1; i * i <= x; i++) {
            if (x % i != 0) continue;
            if (!fac[i]) {
                fac[i] = true;
            } else {
                ans = max(ans, i);
            }
            int f = x / i;
            if (f != i) {
                if (!fac[f]) {
                    fac[f] = true;
                } else {
                    ans = max(ans, f);
                }
            }
        }
    }
    printf("%d\n", ans);
}
