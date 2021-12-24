// A Range Max Query Problem

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

const int MM = 2e5 + 3;
struct node {
    int l, r, val;
} tree[3 * MM];
int q, p, ptr = 0, ans = 0;
void pushup(int ind) {
    tree[ind].val = max(tree[ind * 2].val, tree[ind * 2 + 1].val);
}
void build(int l, int r, int ind) {
    tree[ind].l = l;
    tree[ind].r = r;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
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
        return max(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    su(q);
    su(p);
    build(0, q, 1);
    while (q--) {
        char c;
        sc(c);
        int a;
        su(a);
        a ^= ans;
        if (c == 'A') {
            update(ptr, a, 1);
            ptr++;
        } else {
            ans = query(ptr - a, ptr - 1, 1);
            printf("%d\n", ans);
        }
    }
}