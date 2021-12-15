// ICHB Selection Contest '17 Problem 3 - Parallel Universe

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
#define int long long

const int MM = 1e5 + 3;
int n, q;
struct node {
    int l, r, val;
} tree[MM * 3];
int func(int a, int b) {
    return a & b;
}
void pushup(int ind) {
    tree[ind].val = func(tree[ind * 2].val, tree[ind * 2 + 1].val);
}
void build(int l, int r, int ind) {
    tree[ind].l = l;
    tree[ind].r = r;
    if (l == r) {
        su(tree[ind].val);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    pushup(ind);
}
void update(int pos, int val, int ind) {
    if (tree[ind].l == tree[ind].r) {
        tree[ind].val = val;
        return;
    }
    int mid = (tree[ind].l + tree[ind].r) / 2;
    if (pos <= mid)
        update(pos, val, ind * 2);
    else
        update(pos, val, ind * 2 + 1);
    pushup(ind);
}
int query(int l, int r, int ind) {
    if (tree[ind].l == l && tree[ind].r == r) {
        return tree[ind].val;
    }
    int mid = (tree[ind].l + tree[ind].r) / 2;
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    else
        return func(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    build(1, n, 1);
    while (q--) {
        char c;
        sc(c);
        if (c == 'Q') {
            int x, y, val;
            su(x);
            su(y);
            su(val);
            printf("%lld\n", func(query(x, y, 1), val));
        } else {
            int x, val;
            su(x);
            su(val);
            update(x, val, 1);
        }
    }
}