// DMPG '17 G2 - Holy Grail War

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
int n, q, arr[MM];
ll kadane(int l, int r) {
    ll ret = arr[l], cur = arr[l];
    for (int i = l; i <= r; i++) {
        cur = max({cur, cur + arr[i], (ll)arr[i]});
        ret = max(ret, cur);
    }
    return ret;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    for (int i = 1; i <= n; i++) si(arr[i]);
    while (q--) {
        char c;
        int a, b;
        sc(c);
        su(a);
        si(b);
        if (c == 'S') {
            arr[a] = b;
        } else {
            printf("%lld\n", kadane(a, b));
        }
    }
}
