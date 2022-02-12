// 1-dimensional segment tree with range assignment

const int MM = 1;
struct range {
    int l, r;
} rg[MM * 3];
int n, t[MM * 3], arr[MM];
bool marked[MM * 3];
#define func(a, b) a + b
void push_down(int ind) {
    if (marked[ind]) {
        t[ind * 2] = t[ind * 2 + 1] = t[ind];
        marked[ind * 2] = marked[ind * 2 + 1] = true;
        marked[ind] = false;
    }
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
        t[ind] = val;
        marked[ind] = true;
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