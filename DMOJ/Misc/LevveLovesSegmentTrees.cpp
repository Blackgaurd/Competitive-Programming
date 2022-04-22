// Levve Loves Segment Trees

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 35 * 5e5;
struct node {
    int mx, lc, rc;
    node() : mx(-1), lc(-1), rc(-1){};
} arr[MM];
ll sum[MM];
int ptr = 0;
int add_node() {
    arr[ptr] = node();
    return ptr++;
}
void pushup(int ind) {
    ll l = arr[ind].lc == -1 ? 0 : sum[arr[ind].lc];
    ll r = arr[ind].rc == -1 ? 0 : sum[arr[ind].rc];
    sum[ind] = l + r;

    l = arr[ind].lc == -1 ? 0 : arr[arr[ind].lc].mx;
    r = arr[ind].rc == -1 ? 0 : arr[arr[ind].rc].mx;
    arr[ind].mx = max(l, r);
}
void update(ll pos, int val, ll tl, ll tr, int ind) {
    if (tl == tr) {
        sum[ind] = val;
        arr[ind].mx = val;
        return;
    }
    ll tm = (tl + tr) / 2;
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
ll query_sum(ll l, ll r, ll tl, ll tr, int ind) {
    if (ind == -1 || l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return sum[ind];
    }
    ll tm = (tl + tr) / 2;
    return query_sum(l, min(r, tm), tl, tm, arr[ind].lc) + query_sum(max(l, tm + 1), r, tm + 1, tr, arr[ind].rc);
}
int query_max(ll l, ll r, ll tl, ll tr, int ind) {
    if (ind == -1 || l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return arr[ind].mx;
    }
    ll tm = (tl + tr) / 2;
    return max(query_max(l, min(r, tm), tl, tm, arr[ind].lc), query_max(max(l, tm + 1), r, tm + 1, tr, arr[ind].rc));
}
ll n, q, last_ans, a, b;
char c;
int main() {
    su(n);
    su(q);
    add_node();
    while (q--) {
        sc(c);
        su(a);
        su(b);
        a ^= last_ans;
        b ^= last_ans;
        if (c == 'C') {
            update(a, b, 1, n, 0);
        } else if (c == 'S') {
            last_ans = query_sum(a, b, 1, n, 0);
            printf("%lld\n", last_ans);
        } else {
            last_ans = query_max(a, b, 1, n, 0);
            printf("%lld\n", last_ans);
        }
    }
}