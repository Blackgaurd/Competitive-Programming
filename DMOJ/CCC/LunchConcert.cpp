// CCC '21 S3 - Lunch Concert

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

const int MM = 2e5 + 3;
int n, lo = INT_MAX, hi = 0;
struct person {
    int p, w, d;
} arr[MM];
ll ans = LLONG_MAX;
ll get_dis(int c) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].p < c) {
            if (c - arr[i].d > arr[i].p) {
                ret += (ll)(c - arr[i].d - arr[i].p) * arr[i].w;
            }
        } else if (arr[i].p > c) {
            if (c + arr[i].d < arr[i].p) {
                ret += (ll)(arr[i].p - (c + arr[i].d)) * arr[i].w;
            }
        }
    }
    return ret;
}
void solve_partial() {
    for (int c = lo; c <= hi; c++) {
        ans = min(ans, get_dis(c));
    }
}
void solve_full() {
    while (lo <= hi) {
        int mid = (ll(lo) + hi) / 2;
        ll left = get_dis(mid), right = get_dis(mid + 1);
        ans = min(ans, min(left, right));
        if (left < right) {
            hi = mid - 1;
        } else if (left > right) {
            lo = mid + 2;
        } else
            break;
    }
}
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        su(arr[i].p);
        su(arr[i].w);
        su(arr[i].d);
        hi = max(hi, arr[i].p);
        lo = min(lo, arr[i].p);
    }
    solve_full();
    printf("%lld\n", ans);

    return 0;
}