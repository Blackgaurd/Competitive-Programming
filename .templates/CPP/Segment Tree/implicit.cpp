// for arbituarily large ranges
// do not store a node for each index
// rather, only store the nodes that are needed as pointers

// aims to support:
// point update
// range query
// TODO: add lazy prop

struct node {
    int val, l, r;
    node *lc, *rc;
    node(int l, int r) : val(0), l(l), r(r){};
};
#define func(a, b) a + b
void pushup(node *cur) {
    int l = cur->lc == nullptr ? 0 : cur->lc->val;
    int r = cur->rc == nullptr ? 0 : cur->rc->val;
    cur->val = func(l, r);
}
void update(int pos, int val, node *cur) {  // call by using cur=root
    if (cur->l == cur->r) {
        cur->val = val;
        return;
    }
    int mid = (cur->l + cur->r) / 2;
    if (pos <= mid) {
        if (cur->lc == nullptr) {
            cur->lc = new node(cur->l, mid);
        }
        update(pos, val, cur->lc);
    } else {
        if (cur->rc == nullptr) {
            cur->rc = new node(mid + 1, cur->r);
        }
        update(pos, val, cur->rc);
    }
    pushup(cur);
}
int query(int l, int r, node* cur){
    if (cur == nullptr) {
        return 0;
    }
    if (cur->l == l && cur->r == r) {
        return cur->val;
    }
    int mid = (cur->l + cur->r) / 2;
    if (r <= mid) {
        return query(l, r, cur->lc);
    } else if (l > mid) {
        return query(l, r, cur->rc);
    }
    return func(query(l, mid, cur->lc), query(mid + 1, r, cur->rc));
}
int main() {
    int n = 20;
    node *root = new node(1, n);
    update(4, 5, root);
    query(2, 10, root);
}
