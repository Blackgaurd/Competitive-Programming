// Selection 2
// 50% partials

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
typedef pair<ll, ll> pii;

const int MM = 5003;
int n;
ll ans = 0;
pii arr[MM];
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i].first);
        su(arr[i].second);
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i].second += arr[i - 1].second;
    }
    for (int r = 1; r <= n; r++) {
        ll mx = arr[r].first;
        for (int l = 1; l <= r; l++) {
            ll mn = arr[l].first;
            ll sum = arr[r].second - arr[l - 1].second;
            ans = max(ans, sum - (mx - mn));
        }
    }
    printf("%lld\n", ans);

    return 0;
}