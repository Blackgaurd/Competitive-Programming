//TreatsCollection

#include <algorithm>
#include <cstdio>
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;
// clang-format on
typedef long long ll;

const int MM = 1e5;
int n, k;
ll arr[MM], ans = 3e18;
ll check(ll a, ll b) {
    if (a < 0 && b < 0) return -a;
    if (a > 0 && b > 0) return b;
    return std::min(2LL * -a + b, 2LL * b - a);
}
int main() {
    su(n);
    su(k);
    for (int i = 0; i < n; i++) si(arr[i]);
    std::sort(arr, arr + n);
    for (int i = k - 1; i < n; i++) {
        ans = std::min(ans, check(arr[i - k + 1], arr[i]));
    }
    printf("%lld\n", ans);
}