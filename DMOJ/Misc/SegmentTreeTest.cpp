// Segment Tree Test

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

const int MM = 1e5 + 3;
int n, m;
struct range {
    int l, r;
} ranges[MM * 3];
struct node {
    int g, cnt;
} gcd_tree[MM * 3];
int min_tree[MM * 3];
node combine(node left, node right) {
    if (left.g == right.g) {
        return {left.g, left.cnt + right.cnt};
    } else {
        int _gcd = gcd(left.g, right.g);
        if (_gcd == left.g) {
            return {_gcd, left.cnt};
        }
        if (_gcd == right.g) {
            return {_gcd, right.cnt};
        }
        return {_gcd, 0};
    }
}
void pushup(int ind) {
    min_tree[ind] = min(min_tree[ind * 2], min_tree[ind * 2 + 1]);
    gcd_tree[ind] = combine(gcd_tree[ind * 2], gcd_tree[ind * 2 + 1]);
}
void build(int l, int r, int ind) {
    ranges[ind].l = l;
    ranges[ind].r = r;
    if (l == r) {
        su(min_tree[ind]);
        gcd_tree[ind] = {min_tree[ind], 1};
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    pushup(ind);
}
void update(int pos, int val, int ind) {
    if (ranges[ind].l == ranges[ind].r) {
        min_tree[ind] = val;
        gcd_tree[ind] = {val, 1};
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
int query_min(int l, int r, int ind) {
    if (ranges[ind].l == l && ranges[ind].r == r) {
        return min_tree[ind];
    }
    int mid = (ranges[ind].l + ranges[ind].r) / 2;
    if (r <= mid)
        return query_min(l, r, ind * 2);
    else if (l > mid)
        return query_min(l, r, ind * 2 + 1);
    return min(query_min(l, mid, ind * 2), query_min(mid + 1, r, ind * 2 + 1));
}
node query_gcd(int l, int r, int ind) {
    if (ranges[ind].l == l && ranges[ind].r == r) {
        return gcd_tree[ind];
    }
    int mid = (ranges[ind].l + ranges[ind].r) / 2;
    if (r <= mid)
        return query_gcd(l, r, ind * 2);
    else if (l > mid)
        return query_gcd(l, r, ind * 2 + 1);
    return combine(query_gcd(l, mid, ind * 2), query_gcd(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("SegmentTreeTest.in", "r", stdin);
    freopen("SegmentTreeTest.out", "w", stdout);
#endif

    su(n);
    su(m);
    build(1, n, 1);
    while (m--) {
        char c;
        int a, b;
        sc(c);
        su(a);
        su(b);
        switch (c) {
            case 'C':
                update(a, b, 1);
                break;
            case 'M':
                printf("%d\n", query_min(a, b, 1));
                break;
            case 'G':
                printf("%d\n", query_gcd(a, b, 1).g);
                break;
            case 'Q':
                printf("%d\n", query_gcd(a, b, 1).cnt);
                break;
        }
    }
}