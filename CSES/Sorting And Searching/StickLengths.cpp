// Stick Lengths

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
vector<int> arr;
ll check(int x) {
    ll ret = 0;
    for (int i : arr) {
        ret += abs(x - i);
    }
    return ret;
}
int main() {
    su(n);
    int lo = INT_MAX, hi = 0;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        lo = min(lo, arr[i]);
        hi = max(hi, arr[i]);
    }
    ll ans = LLONG_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ll l = check(mid - 1), r = check(mid);
        ans = min({ans, l, r});
        if (l < r)
            hi = mid - 2;
        else if (l > r)
            lo = mid + 1;
        else
            break;
    }
    printf("%lld\n", ans);
}