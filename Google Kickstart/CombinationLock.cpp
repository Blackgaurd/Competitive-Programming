// Combation Lock

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
int t, w, n, arr[MM];
ll check(int x) {
    ll ret = 0;
    for (int i = 0; i < w; i++) {
        ret += min(abs(x - arr[i]), abs(n - arr[i] + x));
    }
    return ret;
}
ll solve() {
    su(w);
    su(n);
    for (int i = 0; i < w; i++) su(arr[i]);
    int lo = 1, hi = n;
    ll mn = LLONG_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        cout << "mid: " << mid << '\n';
        ll left = check(mid), right = check(mid + 1);
        mn = min({mn, left, right});
        if (left < right) {
            hi = mid - 1;
        } else if (left > right) {
            lo = mid + 2;
        } else
            break;
    }
    return mn;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %lld\n", i, solve());
        if (i == 2){
            for (int j=1; j<=n; j++){
                printf("%d ", check(j));
            }
            printf("\n");
        }
    }

    return 0;
}