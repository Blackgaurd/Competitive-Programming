// Bob's Difference Sum

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

const int MM = 2e5;
int n, arr[MM];
ll ans = 0;
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        si(arr[i]);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        ans += ll(arr[i]) * (i + i + 1 - n);
    }
    printf("%lld\n", ans);

    return 0;
}