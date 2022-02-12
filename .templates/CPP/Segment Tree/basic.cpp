// simple 1 dimensional segment tree template

const int MM = 100;
struct range {
    int l, r;
} rg[MM * 3];
int n, t[MM * 3], arr[MM];
#define func(a, b) a + b
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
void update(int pos, int val, int ind = 1) {
    if (rg[ind].l == rg[ind].r) {
        t[ind] = val;
        return;
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    update(pos, val, ind * 2 + (pos > mid));
    push_up(ind);
}
int query(int l, int r, int ind) {
    if (rg[ind].l == l && rg[ind].r == r) {
        return t[ind];
    }
    int mid = (rg[ind].l + rg[ind].r) / 2;
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    return func(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
