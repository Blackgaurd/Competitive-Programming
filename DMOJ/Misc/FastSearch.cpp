// Fast Search

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

const int MM = 1e6 + 3;
int n, q, k, ans, arr[MM * 3];
void pushup(int ind) {
    arr[ind] = min(arr[ind * 2], arr[ind * 2 + 1]);
}
void build(int l, int r, int ind = 1) {
    if (l == r) {
        su(arr[ind]);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    pushup(ind);
}
void update(int pos, int val, int l = 1, int r = n, int ind = 1) {
    if (l == r) {
        arr[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(pos, val, l, mid, 2 * ind);
    else
        update(pos, val, mid + 1, r, ind * 2 + 1);
    pushup(ind);
}
int query(int ql, int qr, int l = 1, int r = n, int ind = 1) {
    if (l == r) {
        return arr[ind] < k ? r : -1;
    }
    if (arr[ind] >= k) return -1;
    int mid = (l + r) / 2;
    if (qr <= mid) return query(ql, qr, l, mid, ind * 2);
    if (ql > mid) return query(ql, qr, mid + 1, r, ind * 2 + 1);
    int left_query = query(ql, mid, l, mid, ind * 2);
    return left_query == -1 ? query(mid + 1, qr, mid + 1, r, ind * 2 + 1) : left_query;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    build(1, n);
    while (q--) {
        int a;
        su(a);
        if (a == 1) {
            int p, x;
            su(p);
            su(x);
            p ^= ans;
            x ^= ans;
            update(p, x);
        } else {
            int l, r;
            su(l);
            su(r);
            su(k);
            l ^= ans;
            r ^= ans;
            k ^= ans;
            printf("%d\n", (ans = query(l, r)));
        }
    }
}