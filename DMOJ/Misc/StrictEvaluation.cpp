// Strict Evaluation
// addition on segments
// assignment on segments
// query for minimum

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
struct range {
    int l, r;
} rg[MM * 3];
ll n, q, tree[MM * 3], lazy[MM * 3];
bool marked[MM * 3];
void push_down(int ind) {
    // addition
    tree[ind * 2] += lazy[ind];
    tree[ind * 2 + 1] += lazy[ind];
    lazy[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind] = 0;

    // assignment
    if (marked[ind]) {
        tree[ind * 2] = tree[ind * 2 + 1] = tree[ind];
        marked[ind * 2] = marked[ind * 2 + 1] = true;
        marked[ind] = false;
    }
}
void push_up(int ind) {
    tree[ind] = min(tree[ind * 2], tree[ind * 2 + 1]);
}
void build(int l, int r, int ind) {
    rg[ind].l = l;
    rg[ind].r = r;
    if (l == r) {
        su(tree[ind]);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    push_up(ind);
}
void update_add(int l, int r, int val, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        tree[ind] += val;
        lazy[ind] += val;
        return;
    }
    push_down(ind);
    int mid = (rg[ind].l + rg[ind].r) / 2;
    if (r <= mid)
        update_add(l, r, val, ind * 2);
    else if (l > mid)
        update_add(l, r, val, ind * 2 + 1);
    else {
        update_add(l, mid, val, ind * 2);
        update_add(mid + 1, r, val, ind * 2 + 1);
    }
    push_up(ind);
}
void update_assign(int l, int r, int val, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        tree[ind] = val;
        marked[ind] = true;
        return;
    }
    push_down(ind);
    int mid = (rg[ind].l + rg[ind].r) / 2;
    if (r <= mid)
        update_assign(l, r, val, ind * 2);
    else if (l > mid)
        update_assign(l, r, val, ind * 2 + 1);
    else {
        update_assign(l, mid, val, ind * 2);
        update_assign(mid + 1, r, val, ind * 2 + 1);
    }
    push_up(ind);
}
ll query(int l, int r, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        return tree[ind];
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    push_down(ind);
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    return min(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("StrictEvaluation.in", "r", stdin);
    freopen("StrictEvaluation.out", "w", stdout);
#endif
    su(n);
    su(q);
    build(1, n, 1);
    while (q--) {
        int c, l, r, v;
        su(c);
        su(l);
        su(r);
        if (c == 1) {
            su(v);
            update_add(l, r, v, 1);
        } else if (c == 2) {
            su(v);
            update_assign(l, r, v, 1);
        } else {
            printf("%lld\n", query(l, r, 1));
        }
    }
}