// Pair of Multiples

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

const int MM = 5e5 + 3;
int n, mx, cnt[MM], ans;
int main() {
    su(n);
    for (int i = 0, a; i < n; i++) {
        su(a);
        mx = max(mx, a);
        cnt[a]++;
    }
    ans = cnt[1] * (n - 1);
    for (int i = 2; i <= mx; i++) {
        if (cnt[i] == 0) continue;
        int muls = cnt[i] - 1;
        for (int j = i + i; j <= mx; j += i) {
            muls += cnt[j];
        }
        ans += muls * cnt[i];
    }
    printf("%d\n", ans);
}