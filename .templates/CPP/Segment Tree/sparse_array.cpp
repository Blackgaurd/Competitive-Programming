// store nodes in array rather than pointers

#include <bits/stdc++.h>
using namespace std;

const int MM = 1; // MM = log(N) * Q
struct node {
    int val, lc, rc;
    node() : val(-1), lc(-1), rc(-1){};
} arr[MM];
int ptr = 0;
int add_node() {
    arr[ptr] = node();
    return ptr++;
}
void pushup(int ind) {
    int l = arr[ind].lc == -1 ? 0 : arr[arr[ind].lc].val;
    int r = arr[ind].rc == -1 ? 0 : arr[arr[ind].rc].val;
    arr[ind].val = l + r;
}
void update(int pos, int val, int tl, int tr, int ind) {
    if (tl == tr) {
        arr[ind].val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        if (arr[ind].lc == -1) {
            arr[ind].lc = add_node();
        }
        update(pos, val, tl, tm, arr[ind].lc);
    } else {
        if (arr[ind].rc == -1) {
            arr[ind].rc = add_node();
        }
        update(pos, val, tm + 1, tr, arr[ind].rc);
    }
    pushup(ind);
}
int query(int l, int r, int tl, int tr, int ind) {
    if (ind == -1 || l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return arr[ind].val;
    }
    int tm = (tl + tr) / 2;
    return query(l, min(r, tm), tl, tm, arr[ind].lc) + query(max(l, tm + 1), r, tm + 1, tr, arr[ind].rc);
}