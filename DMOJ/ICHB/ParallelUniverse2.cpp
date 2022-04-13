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

struct node {
    uint val, l, r;
    node *lc, *rc;
    node(int l, int r) : val(0), l(l), r(r){};
};
#define func(a, b) a &b
void pushup(node *cur) {
    uint l = cur->lc == nullptr ? 0 : cur->lc->val;
    uint r = cur->rc == nullptr ? 0 : cur->rc->val;
    cur->val = func(l, r);
}
void update(uint pos, uint val, node *cur) {  // call by using cur=root
    if (cur->l == cur->r) {
        cur->val = val;
        return;
    }
    uint mid = (cur->l + cur->r) / 2;
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
uint query(uint l, uint r, node *cur) {
    if (cur == nullptr) {
        return 0;
    }
    if (cur->l == l && cur->r == r) {
        return cur->val;
    }
    uint mid = (cur->l + cur->r) / 2;
    if (r <= mid) {
        return query(l, r, cur->lc);
    } else if (l > mid) {
        return query(l, r, cur->rc);
    }
    return func(query(l, mid, cur->lc), query(mid + 1, r, cur->rc));
}
int n, q;
int main() {
    su(n);
    su(q);
    node *root = new node(1, n);
    for (int i = 1; i <= n; i++) {
        uint a;
        su(a);
        update(i, a, root);
    }
    while (q--) {
        char c;
        sc(c);
        uint x, y, val;
        if (c == 'Q') {
            su(x);
            su(y);
            su(val);
            printf("%u\n", query(x, y, root) & val);
        } else {
            su(x);
            su(val);
            update(x, val, root);
        }
    }
}