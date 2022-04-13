// 1-dimensional segment tree with range updates
// using lazy prop

#include <bits/stdc++.h>
using namespace std;

const int MM = 100;
struct range {
    int l, r;
} rg[MM * 3];
int n, t[MM * 3], lz[MM * 3], arr[MM];
#define func(a, b) a + b
void push_down(int ind) {
    t[ind * 2] += lz[ind];
    t[ind * 2 + 1] += lz[ind];
    lz[ind * 2] += lz[ind];
    lz[ind * 2 + 1] += lz[ind];
    lz[ind] = 0;
}
void push_up(int ind) {
    t[ind] = func(t[ind * 2], t[ind * 2 + 1]);  // change this
}
void build(int l = 1, int r = n, int ind = 1) {
    rg[ind] = {l, r};
    if (l == r) {
        t[ind] = arr[l];  // can also read input directly here
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    push_up(ind);
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
int query(int l, int r, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        return t[ind];
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    push_down(ind);
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    return func(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}