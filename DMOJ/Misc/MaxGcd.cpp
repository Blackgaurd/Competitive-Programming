// Max GCD

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

const int MM = 1e5 + 3;
int n, arr[MM], pre[MM], suf[MM], ans = 0;
int main() {
    su(n);
    for (int i = 1; i <= n; i++) su(arr[i]);
    for (int i = 1; i <= n; i++) {
        int j = n - i + 1;
        pre[i] = __gcd(arr[i], pre[i - 1]);
        suf[j] = __gcd(arr[j], suf[j + 1]);
    }
    for (int i = 0; i + 1 <= n; i++) {
        ans = max(ans, __gcd(pre[i], suf[i + 2]));
    }
    printf("%d\n", ans);

    return 0;
}