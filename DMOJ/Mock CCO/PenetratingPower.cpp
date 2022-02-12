// Mock CCO '17 Problem 2 - Penetrating Power

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
struct range {
    int l, r;
} rg[MM * 3];
ll n, k, q, t[MM * 3], lz[MM * 3];
void push_down(int ind) {
    t[ind * 2] += lz[ind];
    t[ind * 2 + 1] += lz[ind];
    lz[ind * 2] += lz[ind];
    lz[ind * 2 + 1] += lz[ind];
    lz[ind] = 0;
}
void push_up(int ind) {
    t[ind] = max(t[ind * 2], t[ind * 2 + 1]);
}
void build(int l = 1, int r = n, int ind = 1) {
    rg[ind] = {l, r};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
}
void update(int l, int r, int val, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        t[ind] += val;
        lz[ind] += val;
        return;
    }
    push_down(ind);
    int mid = (rg[ind].l + rg[ind].r) / 2;
    if (r <= mid)
        update(l, r, val, ind * 2);
    else if (l > mid)
        update(l, r, val, ind * 2 + 1);
    else {
        update(l, mid, val, ind * 2);
        update(mid + 1, r, val, ind * 2 + 1);
    }
    push_up(ind);
}
ll query(int l, int r, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        return t[ind];
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    push_down(ind);
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    return max(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("PenetratingPower.in", "r", stdin);
    freopen("PenetratingPower.out", "w", stdout);
#endif
    su(n);
    su(k);
    su(q);
    build(0, 2e5, 1);
    while (q--) {
        int a, b, c;
        su(a);
        su(b);
        su(c);
        if (a == 0) {
            update(max(b - k + 1, 0LL), b, c, 1);
        } else {
            printf("%lld\n", query(b, c, 1));
        }
    }
}