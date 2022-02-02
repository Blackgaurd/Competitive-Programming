// DMPG '17 G2 - Holy Grail War
// probably a smarter way than having 2 structs but whatever
// must take at least one sword

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
int n, q;
struct range {
    int l, r;
} ranges[MM * 3];
struct node {
    ll sum, pref, suff, ans;
} tree[MM * 3];
node combine(node left, node right) {
    node ret;
    ret.sum = left.sum + right.sum;
    ret.pref = max(left.pref, left.sum + right.pref);
    ret.suff = max(right.suff, right.sum + left.suff);
    ret.ans = max(max(left.ans, right.ans), left.suff + right.pref);
    return ret;
}
node make(ll val) {
    node ret;
    ret.sum = val;
    ret.pref = ret.suff = ret.ans = val;
    return ret;
}
void pushup(int ind) {
    tree[ind] = combine(tree[ind * 2], tree[ind * 2 + 1]);
}
void build(int l, int r, int ind) {
    ranges[ind].l = l;
    ranges[ind].r = r;
    if (l == r) {
        ll val;
        si(val);
        tree[ind] = make(val);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    pushup(ind);
}
void update(int pos, int val, int ind) {
    if (ranges[ind].l == ranges[ind].r) {
        tree[ind] = make(val);
        return;
    }
    int mid = (ranges[ind].l + ranges[ind].r) / 2;
    if (pos <= mid) {
        update(pos, val, ind * 2);
    } else {
        update(pos, val, ind * 2 + 1);
    }
    pushup(ind);
}
node query(int l, int r, int ind) {
    if (ranges[ind].l == l && ranges[ind].r == r) {
        return tree[ind];
    }
    int mid = (ranges[ind].l + ranges[ind].r) / 2;
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    else
        return combine(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("HolyGrailWar.in", "r", stdin);
    freopen("HolyGrailWar.out", "w", stdout);
#endif
    su(n);
    su(q);
    build(1, n, 1);
    while (q--) {
        char c;
        int a, b;
        sc(c);
        su(a);
        si(b);
        if (c == 'S') {
            update(a, b, 1);
        } else {
            printf("%lld\n", query(a, b, 1).ans);
        }
    }
}
