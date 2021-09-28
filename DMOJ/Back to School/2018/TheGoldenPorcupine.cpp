// Back To School '18: The Golden Porcupine

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

const int MM = 1e5 + 3;
int n, t, l, r, a, b, c;
ll dif2[MM], dif1[MM], dif0[MM];
int main() {
    su(n);
    su(t);
    while (n--) {
        su(l);
        su(r);
        si(a);
        si(b);
        si(c);
        dif2[l] += a;
        dif2[r + 1] -= a;
        ll val = -2 * l * a + b;
        dif1[l] += val;
        dif1[r + 1] -= val;
        val = a * l * l - b * l + c;
        dif0[l] += val;
        dif0[r + 1] -= val;
    }
    for (int i = 1; i <= t; i++) {
        dif2[i] += dif2[i - 1];
        dif1[i] += dif1[i - 1];
        dif0[i] += dif0[i - 1];
        ll ans = dif2[i] * i * i + dif1[i] * i + dif0[i];
        printf("%lld ", ans);
    }
    printf("\n");

    return 0;
}
