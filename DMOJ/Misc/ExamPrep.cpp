// Exam Prep

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

const int MM = 1e6 + 3;
int n, q, p[MM], cnt[MM];
ll ai[MM];
int flead(int __x) {
    if (p[__x] != __x) {
        p[__x] = flead(p[__x]);
        ai[__x] = ai[p[__x]];
        cnt[__x] = cnt[p[__x]];
    }
    return p[__x];
}
int main() {
    su(n);
    su(q);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
        su(ai[i]);
    }
    while (q--) {
        char c;
        sc(c);
        if (c == '1') {
            int a, b;
            su(a);
            su(b);
            int fa = flead(a), fb = flead(b);
            if (fa != fb) {
                p[fa] = fb;
                cnt[fb] += cnt[fa];
                ai[fb] += ai[fa];
            }
        } else if (c == '2') {
            int a;
            su(a);
            flead(a);
            printf("%d\n", cnt[a]);
        } else {
            int a;
            su(a);
            flead(a);
            printf("%lld\n", ai[a]);
        }
    }

    return 0;
}