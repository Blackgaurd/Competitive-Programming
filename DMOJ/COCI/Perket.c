// COCI '08 Contest 2 #3 Perket

#include <limits.h>
#include <stdio.h>
// clang-format off
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; int _sign;
// clang-format on
typedef long long ll;

int n, arr[10][2];
ll abs(ll x) { return x < 0 ? -x : x; }
ll min(ll a, ll b) { return a < b ? a : b; }
ll solve(int ind, ll sour, ll bitter, int cnt) {
    if (ind >= n) {
        if (cnt == 0) return LLONG_MAX;
        return abs(sour - bitter);
    }
    ll ans = LLONG_MAX;
    ans = min(ans, solve(ind + 1, sour, bitter, cnt));
    ans = min(
        ans, solve(ind + 1, sour * arr[ind][0], bitter + arr[ind][1], cnt + 1));
    return ans;
}
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        su(arr[i][0]);
        su(arr[i][1]);
    }
    printf("%lld\n", solve(0, 1, 0, 0));

    return 0;
}