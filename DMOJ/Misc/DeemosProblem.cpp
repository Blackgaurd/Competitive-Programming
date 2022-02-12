// Deemo's Problem

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
struct range {
    int l, r;
} rg[MM * 3];
int n, m, ans, t[MM * 3], arr[MM], dp[MM];
void push_up(int ind) {
    t[ind] = max(t[ind * 2], t[ind * 2 + 1]);
}
void build(int l, int r, int ind) {
    rg[ind] = {l, r};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
}
void update(int pos, int val, int ind) {
    if (rg[ind].l == rg[ind].r) {
        t[ind] += val;
        return;
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    update(pos, val, ind * 2 + (pos > mid));
    push_up(ind);
}
int main() {
#ifdef PC
    freopen("DeemosProblem.in", "r", stdin);
    freopen("DeemosProblem.out", "w", stdout);
#endif
    su(n);
    su(m);
    build(1, m, 1);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        update(arr[i], 1, 1);
        if (i >= m) {
            if (i > m) {
                update(arr[i - m], -1, 1);
            }
            if (t[1] == 1) dp[i] = dp[i - m] + 1;
            ans += dp[i];
            // printf("%d\n", dp[i]);
        }
    }
    printf("%d\n", ans);
}

// WA
// 4 2
// 1 1 2 2